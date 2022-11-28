template <typename Monoid, int NODES = 1'000'000>
struct RBST_Monoid {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r;
    X x, prod, rev_prod; // rev 反映済
    u32 size;
    bool rev;
  };

  Node *pool;
  int pid;
  using np = Node *;

  RBST_Monoid() : pid(0) { pool = new Node[NODES]; }

  void reset() { pid = 0; }

  np new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
    pool[pid].rev_prod = x;
    pool[pid].size = 1;
    pool[pid].rev = 0;
    return &(pool[pid++]);
  }

  np new_node(const vc<X> &dat) {
    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      u32 m = (l + r) / 2;
      np root = new_node(dat[m]);
      root->l = dfs(dfs, l, m), root->r = dfs(dfs, m + 1, r);
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
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

  X prod(np root, u32 l, u32 r) {
    if (l == r) return Monoid::unit();
    return prod_rec(root, l, r);
  }

  np reverse(np root, u32 l, u32 r) {
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return root;
    auto [nl, nm, nr] = split3(root, l, r);
    nm->rev ^= 1;
    swap(nm->prod, nm->rev_prod);
    swap(nm->l, nm->r);
    return merge3(nl, nm, nr);
  }

  np set(np root, u32 k, const X &x) { return set_rec(root, k, x); }
  np multiply(np root, u32 k, const X &x) { return multiply_rec(root, k, x); }
  X get(np root, u32 k) { return get_rec(root, k); }

  vc<X> get_all(np root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, np root, bool rev) -> void {
      if (!root) return;
      dfs(dfs, (rev ? root->r : root->l), root->rev ^ rev);
      res.eb(root->x);
      dfs(dfs, (rev ? root->l : root->r), root->rev ^ rev);
    };
    dfs(dfs, root, 0);
    return res;
  }

  template <typename F>
  u32 max_right(np root, const F check, u32 L) {
    assert(check(Monoid::unit()));
    X x = Monoid::unit();
    return max_right_rec(root, check, L, x);
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

  void push(np c) {
    if (c->rev) {
      if (c->l) {
        c->l->rev ^= 1;
        swap(c->l->prod, c->l->rev_prod);
        swap(c->l->l, c->l->r);
      }
      if (c->r) {
        c->r->rev ^= 1;
        swap(c->r->prod, c->r->rev_prod);
        swap(c->r->l, c->r->r);
      }
      c->rev = 0;
    }
  }

  void update(np c) {
    c->size = 1;
    c->prod = c->rev_prod = c->x;
    if (c->l) {
      c->size += c->l->size;
      c->prod = Monoid::op(c->l->prod, c->prod);
      c->rev_prod = Monoid::op(c->rev_prod, c->l->rev_prod);
    }
    if (c->r) {
      c->size += c->r->size;
      c->prod = Monoid::op(c->prod, c->r->prod);
      c->rev_prod = Monoid::op(c->r->rev_prod, c->rev_prod);
    }
  }

  np merge_rec(np l_root, np r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    u32 sl = l_root->size, sr = r_root->size;
    if (xor128() % (sl + sr) < sl) {
      push(l_root);
      l_root->r = merge_rec(l_root->r, r_root);
      update(l_root);
      return l_root;
    }
    push(r_root);
    r_root->l = merge_rec(l_root, r_root->l);
    update(r_root);
    return r_root;
  }

  pair<np, np> split_rec(np root, u32 k) {
    if (!root) return {nullptr, nullptr};
    push(root);
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

  np set_rec(np root, u32 k, const X &x) {
    if (!root) return root;
    push(root);
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

  np multiply_rec(np root, u32 k, const X &x) {
    if (!root) return root;
    push(root);
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

  X prod_rec(np root, u32 l, u32 r) {
    push(root);
    if (l == 0 && r == root->size) return root->prod;
    u32 sl = (root->l ? root->l->size : 0);
    X res = Monoid::unit();
    if (l < sl) { res = Monoid::op(res, prod_rec(root->l, l, min(r, sl))); }
    if (l <= sl && sl < r) res = Monoid::op(res, root->x);
    u32 k = 1 + sl;
    if (k < r) res = Monoid::op(res, prod_rec(root->r, max(k, l) - k, r - k));
    return res;
  }

  X get_rec(np root, u32 k) {
    push(root);
    u32 sl = (root->l ? root->l->size : 0);
    if (k < sl) return get_rec(root->l, k);
    if (k == sl) return root->x;
    return get_rec(root->r, k - (1 + sl));
  }

  template <typename F>
  u32 max_right_rec(np n, const F check, u32 L, X &x) {
    if (!n) return 0;
    push(n);
    if (L == 0) {
      X y = Monoid::op(x, n->prod);
      if (check(y)) {
        x = y;
        return n->size;
      }
    }
    u32 sl = (n->l ? n->l->size : 0);
    if (L < sl) {
      u32 k = max_right_rec(n->l, check, L, x);
      if (k < sl) return k;
    }
    if (L <= sl) {
      X y = Monoid::op(x, n->x);
      if (!check(y)) { return sl; }
      x = y;
    }
    L = (L > sl ? L - (1 + sl) : 0);
    return (1 + sl) + max_right_rec(n->r, check, L, x);
  }
};
