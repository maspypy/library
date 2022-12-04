#pragma once

template <typename ActedMonoid, bool PERSISTENT, int NODES>
struct Dynamic_Lazy_SegTree {
  using AM = ActedMonoid;
  using MX = typename AM::Monoid_X;
  using MA = typename AM::Monoid_A;
  using X = typename AM::X;
  using A = typename AM::A;
  using F = function<X(ll, ll)>;
  F default_prod;

  struct Node {
    Node *l, *r;
    X x;
    A lazy;
  };

  const ll n;
  Node *pool;
  int pid;
  using np = Node *;

  Dynamic_Lazy_SegTree(
      ll n, F default_prod = [](ll l, ll r) -> X { return MX::unit(); })
      : default_prod(default_prod), n(n), pid(0) {
    pool = new Node[NODES];
  }

  np new_node(const X x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].lazy = MA::unit();
    return &(pool[pid++]);
  }

  np new_node(ll l, ll r) { return new_node(default_prod(l, r)); }

  np new_node(const vc<X> &dat) {
    assert(len(dat) == n);
    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      ll m = (l + r) / 2;
      np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);
      X x = MX::op(l_root->x, r_root->x);
      np root = new_node(x);
      root->l = l_root, root->r = r_root;
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(np root, ll l, ll r) {
    assert(0 <= l && l < r && r <= n);
    X x = MX::unit();
    prod_rec(root, 0, n, l, r, x, MA::unit());
    return x;
  }

  np set(np root, ll i, const X &x) {
    assert(0 <= i && i < n);
    return set_rec(root, 0, n, i, x);
  }

  np multiply(np root, ll i, const X &x) {
    assert(0 <= i && i < n);
    return multiply_rec(root, 0, n, i, x);
  }

  np apply(np root, ll l, ll r, const A &a) {
    assert(0 <= l && l < r && r <= n);
    return apply_rec(root, 0, n, l, r, a);
  }

  template <typename F>
  ll max_right(np root, F check, ll L) {
    assert(0 <= L && L < n && check(MX::unit()));
    X x = MX::unit();
    return max_right_rec(root, check, 0, n, L, x);
  }

  vc<X> restore(np root) {
    vc<X> res;
    res.reserve(n);
    auto dfs = [&](auto &dfs, Node *c, ll l, ll r, A a) -> void {
      if (r - l == 1) {
        res.eb(AM::act(c->x, a, 1));
        return;
      }
      ll m = (l + r) / 2;
      a = MA::op(c->a, a);
      dfs(dfs, c->l, l, m, a);
      dfs(dfs, c->r, m, r, a);
    };
    dfs(dfs, root, 0, n, MA::unit());
    return res;
  }

  void reset() { pid = 0; }

private:
  np copy_node(np c) {
    if (!c || !PERSISTENT) return c;
    pool[pid].l = c->l, pool[pid].r = c->r;
    pool[pid].x = c->x;
    pool[pid].lazy = c->lazy;
    return &(pool[pid++]);
  }

  void prop(np c, ll l, ll r) {
    assert(r - l >= 2);
    ll m = (l + r) / 2;
    if (c->lazy == MA::unit()) return;
    c->l = (c->l ? copy_node(c->l) : new_node(l, m));
    c->l->x = AM::act(c->l->x, c->lazy, m - l);
    c->l->lazy = MA::op(c->l->lazy, c->lazy);
    c->r = (c->r ? copy_node(c->r) : new_node(m, r));
    c->r->x = AM::act(c->r->x, c->lazy, r - m);
    c->r->lazy = MA::op(c->r->lazy, c->lazy);
    c->lazy = MA::unit();
  }

  np set_rec(np c, ll l, ll r, ll i, const X &x) {
    if (r == l + 1) {
      c = copy_node(c);
      c->x = x;
      c->lazy = MA::unit();
      return c;
    }
    prop(c, l, r);
    ll m = (l + r) / 2;
    if (!c->l) c->l = new_node(l, m);
    if (!c->r) c->r = new_node(m, r);

    c = copy_node(c);
    if (i < m) {
      c->l = set_rec(c->l, l, m, i, x);
    } else {
      c->r = set_rec(c->r, m, r, i, x);
    }
    c->x = MX::op(c->l->x, c->r->x);
    return c;
  }

  np multiply_rec(np c, ll l, ll r, ll i, const X &x) {
    if (r == l + 1) {
      c = copy_node(c);
      c->x = MX::op(c->x, x);
      c->lazy = MA::unit();
      return c;
    }
    prop(c, l, r);
    ll m = (l + r) / 2;
    if (!c->l) c->l = new_node(l, m);
    if (!c->r) c->r = new_node(m, r);

    c = copy_node(c);
    if (i < m) {
      c->l = set_rec(c->l, l, m, i, x);
    } else {
      c->r = set_rec(c->r, m, r, i, x);
    }
    c->x = MX::op(c->l->x, c->r->x);
    return c;
  }

  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A lazy) {
    chmax(ql, l);
    chmin(qr, r);
    if (ql >= qr) return;
    if (!c) {
      x = MX::op(x, AM::act(default_prod(ql, qr), lazy, qr - ql));
      return;
    }
    if (l == ql && r == qr) {
      x = MX::op(x, AM::act(c->x, lazy, r - l));
      return;
    }
    ll m = (l + r) / 2;
    lazy = MA::op(c->lazy, lazy);
    prod_rec(c->l, l, m, ql, qr, x, lazy);
    prod_rec(c->r, m, r, ql, qr, x, lazy);
  }

  np apply_rec(np c, ll l, ll r, ll ql, ll qr, const A &a) {
    if (!c) c = new_node(l, r);
    chmax(ql, l);
    chmin(qr, r);
    if (ql >= qr) return c;
    if (l == ql && r == qr) {
      c = copy_node(c);
      c->x = AM::act(c->x, a, r - l);
      c->lazy = MA::op(c->lazy, a);
      return c;
    }
    prop(c, l, r);
    ll m = (l + r) / 2;
    c = copy_node(c);
    c->l = apply_rec(c->l, l, m, ql, qr, a);
    c->r = apply_rec(c->r, m, r, ql, qr, a);
    c->x = MX::op(c->l->x, c->r->x);
    return c;
  }

  template <typename F>
  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {
    if (r <= ql) return r;
    if (!c) c = new_node(l, r);
    chmax(ql, l);
    if (l == ql && check(MX::op(x, c->x))) {
      x = MX::op(x, c->x);
      return r;
    }
    if (r == l + 1) return l;
    prop(c, l, r);
    ll m = (l + r) / 2;
    ll k = max_right_rec(c->l, check, l, m, ql, x);
    if (k < m) return k;
    return max_right_rec(c->r, check, m, r, ql, x);
  }
};