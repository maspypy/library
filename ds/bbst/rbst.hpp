// 単に S の元の列を管理する
template <typename S, bool PERSISTENT, int NODES>
struct RBST {
  struct Node {
    Node *l, *r;
    S s;
    u32 size;
    bool rev;
  };

  Node *pool;
  int pid;
  using np = Node *;

  RBST() : pid(0) { pool = new Node[NODES]; }

  void reset() { pid = 0; }

  np new_node(const S &s) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].s = s;
    pool[pid].size = 1;
    pool[pid].rev = 0;
    return &(pool[pid++]);
  }

  np new_node(const vc<S> &dat) {
    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      u32 m = (l + r) / 2;
      np l_root = dfs(dfs, l, m);
      np r_root = dfs(dfs, m + 1, r);
      np root = new_node(dat[m]);
      root->l = l_root, root->r = r_root;
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  np copy_node(np &n) {
    if (!n || !PERSISTENT) return n;
    pool[pid].l = n->l, pool[pid].r = n->r;
    pool[pid].s = n->s;
    pool[pid].size = n->size;
    pool[pid].rev = n->rev;
    return &(pool[pid++]);
  }

  np merge(np l_root, np r_root) { return merge_rec(l_root, r_root); }
  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }
  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d); }
  pair<np, np> split(np root, u32 k) {
    if (!root) {
      assert(k == 0);
      return {nullptr, nullptr};
    }
    assert(0 <= k && k <= root->size);
    return split_rec(root, k);
  }
  tuple<np, np, np> split3(np root, u32 l, u32 r) {
    np nm, nr;
    tie(root, nr) = split(root, r);
    tie(root, nm) = split(root, l);
    return {root, nm, nr};
  }
  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {
    np d;
    tie(root, d) = split(root, k);
    auto [a, b, c] = split3(root, i, j);
    return {a, b, c, d};
  }

  np reverse(np root, u32 l, u32 r) {
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm->rev ^= 1;
    swap(nm->l, nm->r);
    return merge3(nl, nm, nr);
  }

  np set(np root, u32 k, const S &s) { return set_rec(root, k, s); }
  S get(np root, u32 k) { return get_rec(root, k, false); }

  vc<S> get_all(np root) {
    vc<S> res;
    auto dfs = [&](auto &dfs, np root, bool rev) -> void {
      if (!root) return;
      dfs(dfs, (rev ? root->r : root->l), rev ^ root->rev);
      res.eb(root->s);
      dfs(dfs, (rev ? root->l : root->r), rev ^ root->rev);
    };
    dfs(dfs, root, 0);
    return res;
  }

  // 最後に check(s) が成り立つところまでを左として split
  template <typename F>
  pair<np, np> split_max_right(np root, const F check) {
    return split_max_right_rec(root, check);
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

  void prop(np c) {
    // 自身をコピーする必要はない。
    // 子をコピーする必要がある。複数の親を持つ可能性があるため。
    if (c->rev) {
      if (c->l) {
        c->l = copy_node(c->l);
        c->l->rev ^= 1;
        swap(c->l->l, c->l->r);
      }
      if (c->r) {
        c->l = copy_node(c->l);
        c->r->rev ^= 1;
        swap(c->r->l, c->r->r);
      }
      c->rev = 0;
    }
  }

  void update(np c) {
    // データを保ったまま正常化するだけなので、コピー不要
    c->size = 1;
    if (c->l) { c->size += c->l->size; }
    if (c->r) { c->size += c->r->size; }
  }

  np merge_rec(np l_root, np r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    u32 sl = l_root->size, sr = r_root->size;
    if (xor128() % (sl + sr) < sl) {
      prop(l_root);
      l_root = copy_node(l_root);
      l_root->r = merge_rec(l_root->r, r_root);
      update(l_root);
      return l_root;
    }
    prop(r_root);
    r_root = copy_node(r_root);
    r_root->l = merge_rec(l_root, r_root->l);
    update(r_root);
    return r_root;
  }

  pair<np, np> split_rec(np root, u32 k) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k <= sl) {
      auto [nl, nr] = split_rec(root->l, k);
      root = copy_node(root);
      root->l = nr;
      update(root);
      return {nl, root};
    }
    auto [nl, nr] = split_rec(root->r, k - (1 + sl));
    root = copy_node(root);
    root->r = nl;
    update(root);
    return {root, nr};
  }

  np set_rec(np root, u32 k, const S &s) {
    if (!root) return root;
    prop(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) {
      root = copy_node(root);
      root->l = set_rec(root->l, k, s);
      update(root);
      return root;
    }
    if (k == sl) {
      root = copy_node(root);
      root->s = s;
      update(root);
      return root;
    }
    root = copy_node(root);
    root->r = set_rec(root->r, k - (1 + sl), s);
    update(root);
    return root;
  }

  S get_rec(np root, u32 k, bool rev) {
    np left = (rev ? root->r : root->l);
    np right = (rev ? root->l : root->r);
    u32 sl = (left ? left->size : 0);
    if (k == sl) return root->s;
    rev ^= root->rev;
    if (k < sl) return get_rec(left, k, rev);
    return get_rec(right, k - (1 + sl), rev);
  }

  template <typename F>
  pair<np, np> split_max_right_rec(np root, const F &check) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    root = copy_node(root);
    if (check(root->s)) {
      auto [n1, n2] = split_max_right_rec(root->r, check);
      root->r = n1;
      update(root);
      return {root, n2};
    }
    auto [n1, n2] = split_max_right_rec(root->l, check);
    root->l = n2;
    update(root);
    return {n1, root};
  }
};
