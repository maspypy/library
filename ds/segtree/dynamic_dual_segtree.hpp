
// Q*2logN 程度必要
// https://qoj.ac/contest/1516/problem/8240
template <typename Monoid, bool PERSISTENT>
struct Dynamic_Dual_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;

  struct Node {
    Node *l, *r;
    X x;
  };

  const int NODES;
  const ll L0, R0;
  Node *pool;
  int pid;
  using np = Node *;

  Dynamic_Dual_SegTree(int NODES, ll L0, ll R0) : NODES(NODES), L0(L0), R0(R0), pid(0) { pool = new Node[NODES]; }
  ~Dynamic_Dual_SegTree() { delete[] pool; }

  np new_root() { return new_node(MX::unit()); }

  np new_node(const X x = MX::unit()) {
    assert(pid < NODES);
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    return &(pool[pid++]);
  }

  np new_node(const vc<X> &dat) {
    assert(L0 == 0 && R0 == len(dat));
    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      ll m = (l + r) / 2;
      np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);
      X x = MX::op(l_root->x, r_root->x);
      np root = new_node();
      root->l = l_root, root->r = r_root;
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  X get(np root, ll i) {
    if (!root) return MX::unit();
    X x = MX::unit();
    get_rec(root, L0, R0, i, x);
    return x;
  }

  np apply(np root, ll l, ll r, const X &x) {
    if (l == r) return root;
    assert(pid && L0 <= l && l < r && r <= R0);
    root = copy_node(root);
    apply_rec(root, L0, R0, l, r, x);
    return root;
  }

  // root[l:r) を other[l:r)*x で上書きしたものを返す
  np copy_interval(np root, np other, ll l, ll r, X x) {
    if (root == other) return root;
    root = copy_node(root);
    copy_interval_rec(root, other, L0, R0, l, r, x);
    return root;
  }

  void reset() { pid = 0; }

  vc<X> get_all(np root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, np c, ll L, ll R, X x) -> void {
      if (!c) {
        FOR(R - L) res.eb(x);
        return;
      }
      x = MX::op(c->x, x);
      if (R == L + 1) {
        res.eb(x);
        return;
      }
      ll M = (L + R) / 2;
      dfs(dfs, c->l, L, M, x);
      dfs(dfs, c->r, M, R, x);
    };
    dfs(dfs, root, L0, R0, MX::unit());
    return res;
  }

private:
  np copy_node(np c) {
    if (!c || !PERSISTENT) return c;
    pool[pid].l = c->l, pool[pid].r = c->r;
    pool[pid].x = c->x;
    return &(pool[pid++]);
  }

  void apply_rec(np c, ll l, ll r, ll ql, ll qr, const X &a) {
    // もう c は新しくしてある
    assert(c);
    chmax(ql, l), chmin(qr, r);
    if (a == MX::unit() || ql >= qr) return;
    if (l == ql && r == qr) {
      c->x = MX::op(c->x, a);
      return;
    }
    // push
    c->l = (c->l ? copy_node(c->l) : new_node());
    c->r = (c->r ? copy_node(c->r) : new_node());
    c->l->x = MX::op(c->l->x, c->x);
    c->r->x = MX::op(c->r->x, c->x);
    c->x = MX::unit();
    ll m = (l + r) / 2;
    apply_rec(c->l, l, m, ql, qr, a), apply_rec(c->r, m, r, ql, qr, a);
    return;
  }

  void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, X x) {
    // c[ql,qr) <- d[ql,qr) * x
    // もう c は新しくしてある
    assert(c);
    chmax(ql, l), chmin(qr, r);
    if (ql >= qr) return;
    if (l == ql && r == qr) {
      if (d)
        c->x = MX::op(d->x, x), c->l = d->l, c->r = d->r;
      else
        c->x = x, c->l = nullptr, c->r = nullptr;
      return;
    }
    // push
    c->l = (c->l ? copy_node(c->l) : new_node());
    c->r = (c->r ? copy_node(c->r) : new_node());
    c->l->x = MX::op(c->l->x, c->x);
    c->r->x = MX::op(c->r->x, c->x);
    c->x = MX::unit();
    ll m = (l + r) / 2;
    if (d) x = MX::op(d->x, x);
    copy_interval_rec(c->l, (d && d->l ? d->l : nullptr), l, m, ql, qr, x);
    copy_interval_rec(c->r, (d && d->r ? d->r : nullptr), m, r, ql, qr, x);
    return;
  }

  void get_rec(np c, ll l, ll r, ll i, X &x) {
    if (!c) return;
    x = MX::op(c->x, x);
    if (r == l + 1) { return; }
    ll m = (l + r) / 2;
    if (i < m) return get_rec(c->l, l, m, i, x);
    return get_rec(c->r, m, r, i, x);
  }
};
