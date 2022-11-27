template <typename XSet, int NODES = 1'000'000>
struct RBST_Dual {
  using Mono = typename XSet::Monoid;
  using X = typename XSet::operator_type;
  using S = typename XSet::element_type;

  struct Node {
    Node *l, *r;
    X lazy;
    S val; // lazy はそのノードには反映済
    u32 size;
    bool rev;
  };

  Node *pool;
  int pid;

  RBST_Dual() : pid(0) { pool = new Node[NODES]; }

  Node *new_node(const S &val) {
    assert(pid < NODES);
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].lazy = Mono::unit();
    pool[pid].val = val;
    pool[pid].size = 1;
    pool[pid].rev = 0;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<S> &dat) {
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      if (l == r) return nullptr;
      int m = (l + r) / 2;
      Node *root = new_node(dat[m]);
      root->l = dfs(dfs, l, m);
      root->r = dfs(dfs, m + 1, r);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  Node *merge(Node *root, Node *r_root) { return merge_rec(root, r_root); }
  Node *merge3(Node *a, Node *b, Node *c) { return merge(merge(a, b), c); }

  pair<Node *, Node *> split(Node *root, u32 k) {
    if (!root) assert(k == 0);
    if (root) assert(0 <= k && k <= root->size);
    return split_rec(root, k);
  }
  tuple<Node *, Node *, Node *> split3(Node *root, u32 l, u32 r) {
    auto nr = split(root, r);
    auto nm = split(root, l);
    return {root, nm, nr};
  }

  Node *reverse(Node *root, u32 l, u32 r) {
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm->rev ^= 1;
    prop(nm);
    update(nm);
    root = merge3(nl, nm, nr);
    return root;
  }

  Node *apply(Node *root, u32 l, u32 r, const X &a) {
    assert(0 <= l && l <= r && r <= root->size);
    if (l == r) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm->lazy = Mono::op(nm->lazy, a);
    nm->val = XSet::act(nm->val, a);
    prop(nm);
    update(nm);
    return merge3(nl, nm, nr);
  }

  Node *apply_all(Node *root, const X &a) {
    if (!root) return root;
    root->lazy = Mono::op(root->lazy, a);
    root->val = XSet::act(root->val, a);
    return root;
  }

  vc<S> get_all(Node *root) {
    vc<S> res;
    auto dfs = [&](auto &dfs, Node *n, X lazy) -> void {
      if (!n) return;
      S me = XSet::act(n->val, lazy);
      lazy = Mono::op(n->lazy, lazy);
      dfs(dfs, n->l, lazy);
      res.eb(me);
      dfs(dfs, n->r, lazy);
    };
    dfs(dfs, root, Mono::unit());
    return res;
  }

  S get(Node *root, u32 idx) { return get_rec(root, idx); }

  // ok 側と ng 側に分割して split する
  template <typename F>
  pair<Node *, Node *> binary_search(Node *root, F check, bool ok_is_left) {
    return binary_search_rec(root, check, ok_is_left);
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
      print(s, "size", "val", n->val, "lazy", n->lazy);
      s += "r";
      dfs(dfs, n->r);
      s.pop_back();
    };
    dfs(dfs, root);
  }

private:
  inline u32 xor128() {
    static u32 x = 123456789;
    static u32 y = 362436069;
    static u32 z = 521288629;
    static u32 w = 88675123;
    int t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  void prop(Node *c) {
    if (c->lazy != Mono::unit()) {
      if (c->l) {
        c->l->val = XSet::act(c->l->val, c->lazy);
        c->l->lazy = Mono::op(c->l->lazy, c->lazy);
      }
      if (c->r) {
        c->r->val = XSet::act(c->r->val, c->lazy);
        c->r->lazy = Mono::op(c->r->lazy, c->lazy);
      }
      c->lazy = Mono::unit();
    }
    if (c->rev) {
      swap(c->l, c->r);
      if (c->l) c->l->rev ^= 1;
      if (c->r) c->r->rev ^= 1;
      c->rev = 0;
    }
  }

  void update(Node *c) {
    c->size = 1;
    if (c->l) { c->size += c->l->size; }
    if (c->r) { c->size += c->r->size; }
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
    u32 ls = (root->l ? root->l->size : 0);
    if (k <= ls) {
      auto [nl, nr] = split_rec(root->l, k);
      root->l = nr;
      update(root);
      return {nl, root};
    }
    auto [nl, nr] = split_rec(root->r, k - (1 + ls));
    root->r = nl;
    update(root);
    return {root, nr};
  }

  S get_rec(Node *root, u32 idx) {
    u32 ls = (root->l ? root->l->size : 0);
    if (idx < ls) return Mono::op(get_rec(root->l, idx), root->lazy);
    if (idx == ls) return root->val;
    return Mono::op(get_rec(root->r, idx - 1 - ls), root->lazy);
  }

  template <typename F>
  pair<Node *, Node *> binary_search_rec(Node *root, const F &check,
                                         bool ok_is_left) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    if (check(root) == ok_is_left) {
      auto [n1, n2] = binary_search_rec(root->r, check, ok_is_left);
      root->r = n1;
      update(root);
      return {root, n2};
    } else {
      auto [n1, n2] = binary_search_rec(root->l, check, ok_is_left);
      root->l = n2;
      update(root);
      return {n1, root};
    }
    return {nullptr, nullptr};
  }
};
