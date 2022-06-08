// reverse はとりあえず、Monoid_X の可換性を仮定している！
template <typename Lazy, int NODES = 1'000'000>
struct Persistent_RBST_Lazy {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;

  struct Node {
    Node *l, *r;
    X x, prod;
    A a;
    int size;
    bool rev;
    bool propagated;
  };

  Node *pool;
  int pid;

  Persistent_RBST_Lazy() : pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
    pool[pid].a = Monoid_A::unit();
    pool[pid].size = 1;
    pool[pid].rev = 0;
    pool[pid].propagated = 1;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      int m = (l + r) / 2;
      Node *l_root = dfs(dfs, l, m);
      Node *r_root = dfs(dfs, m + 1, r);
      Node *root = new_node(dat[m]);
      root->l = l_root, root->r = r_root;
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  Node *merge(Node *root, Node *r_root) {
    root = merge_rec(root, r_root);
    return root;
  }

  Node *merge3(Node *a, Node *b, Node *c) { return merge(merge(a, b), c); }

  tuple<Node *, Node *, Node *> split3(Node *root, int l, int r) {
    auto [nlm, nr] = split(root, r);
    auto [nl, nm] = split(nlm, l);
    return {nl, nm, nr};
  }

  // 左右に分けて、root を左側に変更。右側を return する。
  pair<Node *, Node *> split(Node *root, int k) {
    if (!root) assert(k == 0);
    if (root) assert(0 <= k && k <= root->size);
    return split_rec(root, k);
  }

  X prod(Node *root, int l, int r) {
    assert(0 <= l && l <= r && r <= root->size);
    if (l == r) return Monoid_X::unit();
    auto [nl, nm, nr] = split3(root, l, r);
    return nm->prod;
  }

  Node *reverse(Node *root, int l, int r) {
    assert(Monoid_X::commute);
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm = copy_node(nm);
    nm->rev ^= 1;
    prop(nm);
    update(nm);
    root = merge3(nl, nm, nr);
    return root;
  }

  Node *apply(Node *root, int l, int r, const A &a) {
    assert(0 <= l && l <= r && r <= root->size);
    if (l == r) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm = copy_node(nm);
    nm->x = Lazy::act(nm->x, a);
    nm->prod = Lazy::act(nm->prod, a);
    nm->a = Monoid_A::op(nm->a, a);
    nm->propagated = 0;
    prop(nm);
    update(nm);
    return merge3(nl, nm, nr);
  }

  // root の k 番目に n を挿入する
  Node *insert(Node *root, int k, Node *n) {
    if (!root) {
      assert(k == 0);
      return n;
    }
    assert(0 <= k && k <= root->size);
    auto [nl, nr] = split(root, k);
    return merge3(nl, n, nr);
  }

  Node *insert(Node *root, int k, const X &x) {
    return insert(root, k, new_node(x));
  }

  pair<Node *, Node *> erase(Node *root, int k) {
    assert(0 <= k && k < root->size);
    auto [nl, nm, nr] = split(root, k, k + 1);
    root = merge(nl, nr);
    return {root, nm};
  }

  vc<X> restore(Node *root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, Node *n) -> void {
      if (!n) return;
      prop(n);
      dfs(dfs, n->l);
      res.eb(n->x);
      dfs(dfs, n->r);
    };
    dfs(dfs, root);
    return res;
  }

  void reset() { pid = 0; }

  void debug(Node *root) {
    print("RBST");
    string s;
    auto dfs = [&](auto &dfs, Node *n) -> void {
      if (!n) return;
      s += "l";
      dfs(dfs, n->l);
      s.pop_back();
      print(s, "size", n->size, "x", n->x, "prod", n->prod, "apply", n->a);
      s += "r";
      dfs(dfs, n->r);
      s.pop_back();
    };
    dfs(dfs, root);
  }

private:
  Node *copy_node(Node *n) {
    if (!n) return nullptr;
    pool[pid].l = n->l;
    pool[pid].r = n->r;
    pool[pid].x = n->x;
    pool[pid].prod = n->prod;
    pool[pid].a = n->a;
    pool[pid].size = n->size;
    pool[pid].rev = n->rev;
    pool[pid].propagated = n->propagated;
    return &(pool[pid++]);
  }

  inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  void prop(Node *c) {
    if (!c->propagated) {
      if (c->l) {
        c->l = copy_node(c->l);
        c->l->x = Lazy::act(c->l->x, c->a);
        c->l->prod = Lazy::act(c->l->prod, c->a);
        c->l->a = Monoid_A::op(c->l->a, c->a);
        c->l->propagated = 0;
      }
      if (c->r) {
        c->r = copy_node(c->r);
        c->r->x = Lazy::act(c->r->x, c->a);
        c->r->prod = Lazy::act(c->r->prod, c->a);
        c->r->a = Monoid_A::op(c->r->a, c->a);
        c->r->propagated = 0;
      }
      c->a = Monoid_A::unit();
      c->propagated = 1;
    }
    if (c->rev) {
      c->l = copy_node(c->l);
      c->r = copy_node(c->r);
      swap(c->l, c->r);
      if (c->l) c->l->rev ^= 1;
      if (c->r) c->r->rev ^= 1;
      c->rev = 0;
    }
  }

  void update(Node *c) {
    c->size = 1;
    c->prod = c->x;
    if (c->l) {
      c->size += c->l->size;
      c->prod = Monoid_X::op(c->l->prod, c->prod);
    }
    if (c->r) {
      c->size += c->r->size;
      c->prod = Monoid_X::op(c->prod, c->r->prod);
    }
  }

  Node *merge_rec(Node *l_root, Node *r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    int sl = l_root->size, sr = r_root->size;
    if (xor128() % (sl + sr) < sl) {
      prop(l_root);
      l_root->r = merge_rec(l_root->r, r_root);
      update(l_root);
      return l_root;
    }
    prop(r_root);
    r_root->l = merge_rec(l_root, r_root->l);
    update(r_root);
    return r_root;
  }

  pair<Node *, Node *> split_rec(Node *root, int k) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    int ls = (root->l ? root->l->size : 0);
    if (k <= ls) {
      auto [nl, nr] = split_rec(root->l, k);
      root = copy_node(root);
      root->l = nr;
      update(root);
      return {nl, root};
    }
    auto [nl, nr] = split_rec(root->r, k - (1 + ls));
    root = copy_node(root);
    root->r = nl;
    update(root);
    return {root, nr};
  }
};
