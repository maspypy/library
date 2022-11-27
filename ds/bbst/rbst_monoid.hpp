// reverse はとりあえず、Monoid の可換性を仮定している！
template <typename Monoid, int NODES = 1'000'000>
struct RBST_Monoid {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r;
    X x, prod;
    u32 size;
    bool rev;
  };

  Node *pool;
  int pid;

  RBST_Monoid() : pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
    pool[pid].size = 1;
    pool[pid].rev = 0;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    auto dfs = [&](auto &dfs, u32 l, u32 r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      u32 m = (l + r) / 2;
      Node *l_root = dfs(dfs, l, m);
      Node *r_root = dfs(dfs, m + 1, r);
      Node *root = new_node(dat[m]);
      root->l = l_root, root->r = r_root;
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  Node *merge(Node *root, Node *r_root) { return merge_rec(root, r_root); }
  Node *merge3(Node *a, Node *b, Node *c) { return merge(merge(a, b), c); }
  pair<Node *, Node *> split(Node *root, u32 k) {
    if (!root) {
      assert(k == 0);
      return {nullptr, nullptr};
    }
    assert(0 <= k && k <= root->size);
    return split_rec(root, k);
  }
  tuple<Node *, Node *, Node *> split3(Node *root, u32 l, u32 r) {
    Node *nm, *nr;
    tie(root, nr) = split(root, r);
    tie(root, nm) = split(root, l);
    return {root, nm, nr};
  }

  X prod(Node *root, u32 l, u32 r) {
    if (l == r) return Monoid::unit();
    return prod_rec(root, l, r);
  }

  Node *reverse(Node *root, u32 l, u32 r) {
    assert(Monoid::commute);
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm->rev ^= 1;
    prop(nm), update(nm);
    return merge3(nl, nm, nr);
  }

  Node *set(Node *root, u32 k, const X &x) { return set_rec(root, k, x); }
  Node *multiply(Node *root, u32 k, const X &x) {
    return multiply_rec(root, k, x);
  }
  X get(Node *root, u32 k) { return get_rec(root, k); }

  vc<X> get_all(Node *root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, Node *root) -> void {
      if (!root) return;
      prop(root);
      dfs(dfs, root->l);
      res.eb(root->x);
      dfs(dfs, root->r);
    };
    dfs(dfs, root);
    return res;
  }

private:
  inline u32 xor128() {
    static u32 x = 123456789;
    static u32 y = 362436069;
    static u32 z = 521288629;
    static u32 w = 88675123;
    u32 t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  void prop(Node *c) {
    if (c->rev) {
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
      c->prod = Monoid::op(c->l->prod, c->prod);
    }
    if (c->r) {
      c->size += c->r->size;
      c->prod = Monoid::op(c->prod, c->r->prod);
    }
  }

  Node *merge_rec(Node *l_root, Node *r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    u32 sl = l_root->size, sr = r_root->size;
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

  pair<Node *, Node *> split_rec(Node *root, u32 k) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k <= sl) {
      auto [nl, nr] = split_rec(root->l, k);
      root->l = nr;
      update(root);
      return {nl, root};
    }
    auto [nl, nr] = split_rec(root->r, k - (1 + sl));
    root->r = nl;
    update(root);
    return {root, nr};
  }

  Node *set_rec(Node *root, u32 k, const X &x) {
    if (!root) return root;
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) {
      root->l = set_rec(root->l, k, x);
      update(root);
      return root;
    }
    if (k == sl) {
      root->x = x;
      update(root);
      return root;
    }
    root->r = set_rec(root->r, k - (1 + sl), x);
    update(root);
    return root;
  }

  Node *multiply_rec(Node *root, u32 k, const X &x) {
    if (!root) return root;
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) {
      root->l = multiply_rec(root->l, k, x);
      update(root);
      return root;
    }
    if (k == sl) {
      root->x = Monoid::op(root->x, x);
      update(root);
      return root;
    }
    root->r = multiply_rec(root->r, k - (1 + sl), x);
    update(root);
    return root;
  }

  X prod_rec(Node *root, u32 l, u32 r) {
    prop(root);
    if (l == 0 && r == root->size) return root->prod;
    u32 sl = (root->l ? root->l->size : 0);
    X res = Monoid::unit();
    if (l < sl) { res = Monoid::op(res, prod_rec(root->l, l, min(r, sl))); }
    if (l <= sl && sl < r) res = Monoid::op(res, root->x);
    u32 k = 1 + sl;
    if (k < r) res = Monoid::op(res, prod_rec(root->r, max(k, l) - k, r - k));
    return res;
  }

  X get_rec(Node *root, u32 k) {
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) return get_rec(root->l, k);
    if (k == sl) return root->x;
    return get_rec(root->r, k - (1 + sl));
  }
};
