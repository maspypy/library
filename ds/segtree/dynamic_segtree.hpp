#pragma once

template <typename Monoid, bool PERSISTENT, int NODES>
struct Dynamic_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  using F = function<X(ll, ll)>;
  F default_prod;

  struct Node {
    Node *l, *r;
    X x;
  };

  const ll L0, R0;
  Node *pool;
  int pid;
  using np = Node *;

  Dynamic_SegTree(
      ll L0, ll R0, F default_prod = [](ll l, ll r) -> X { return MX::unit(); })
      : default_prod(default_prod), L0(L0), R0(R0), pid(0) {
    pool = new Node[NODES];
  }

  np new_node(const X x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    return &(pool[pid++]);
  }

  np new_node(ll l, ll r) { return new_node(default_prod(l, r)); }
  np new_node() { return new_node(L0, R0); }

  np new_node(const vc<X> &dat) {
    assert(L0 == 0 && R0 == len(dat));
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
    assert(L0 <= l && l < r && r <= R0);
    X x = MX::unit();
    prod_rec(root, L0, R0, l, r, x);
    return x;
  }

  np set(np root, ll i, const X &x) {
    assert(L0 <= i && i < R0);
    return set_rec(root, L0, R0, i, x);
  }

  np multiply(np root, ll i, const X &x) {
    assert(L0 <= i && i < R0);
    return multiply_rec(root, L0, R0, i, x);
  }

  template <typename F>
  ll max_right(np root, F check, ll L) {
    assert(L0 <= L && L <= R0 && check(MX::unit()));
    X x = MX::unit();
    return max_right_rec(root, check, L0, R0, L, x);
  }

  template <typename F>
  ll min_left(np root, F check, ll R) {
    assert(L0 <= R && R <= R0 && check(MX::unit()));
    X x = MX::unit();
    return min_left_rec(root, check, L0, R0, R, x);
  }

  vc<X> get_all(np root) {
    vc<X> res;
    res.reserve(R0 - L0);
    auto dfs = [&](auto &dfs, np c, ll l, ll r) -> void {
      if (!c) c = new_node(l, r);
      if (r - l == 1) {
        res.eb(c->x);
        return;
      }
      ll m = (l + r) / 2;
      dfs(dfs, c->l, l, m);
      dfs(dfs, c->r, m, r);
    };
    dfs(dfs, root, L0, R0);
    return res;
  }

  void reset() { pid = 0; }

private:
  np copy_node(np c) {
    if (!c || !PERSISTENT) return c;
    pool[pid].l = c->l, pool[pid].r = c->r;
    pool[pid].x = c->x;
    return &(pool[pid++]);
  }

  np set_rec(np c, ll l, ll r, ll i, const X &x) {
    if (r == l + 1) {
      c = copy_node(c);
      c->x = x;
      return c;
    }
    ll m = (l + r) / 2;

    c = copy_node(c);
    if (i < m) {
      if (!c->l) c->l = new_node(l, m);
      c->l = set_rec(c->l, l, m, i, x);
    } else {
      if (!c->r) c->r = new_node(m, r);
      c->r = set_rec(c->r, m, r, i, x);
    }
    X xl = (c->l ? c->l->x : default_prod(l, m));
    X xr = (c->r ? c->r->x : default_prod(m, r));
    c->x = MX::op(xl, xr);
    return c;
  }

  np multiply_rec(np c, ll l, ll r, ll i, const X &x) {
    if (r == l + 1) {
      c = copy_node(c);
      c->x = MX::op(c->x, x);
      return c;
    }
    ll m = (l + r) / 2;
    c = copy_node(c);

    if (i < m) {
      if (!c->l) c->l = new_node(l, m);
      c->l = multiply_rec(c->l, l, m, i, x);
    } else {
      if (!c->r) c->r = new_node(m, r);
      c->r = multiply_rec(c->r, m, r, i, x);
    }
    X xl = (c->l ? c->l->x : default_prod(l, m));
    X xr = (c->r ? c->r->x : default_prod(m, r));
    c->x = MX::op(xl, xr);
    return c;
  }

  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {
    chmax(ql, l);
    chmin(qr, r);
    if (ql >= qr) return;
    if (!c) {
      x = MX::op(x, default_prod(ql, qr));
      return;
    }
    if (l == ql && r == qr) {
      x = MX::op(x, c->x);
      return;
    }
    ll m = (l + r) / 2;
    prod_rec(c->l, l, m, ql, qr, x);
    prod_rec(c->r, m, r, ql, qr, x);
  }

  template <typename F>
  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {
    if (r <= ql) return R0;
    if (ql <= l && check(MX::op(x, c->x))) {
      x = MX::op(x, c->x);
      return R0;
    }
    if (r == l + 1) return l;
    ll m = (l + r) / 2;
    if (!c->l) c->l = new_node(l, m);
    ll k = max_right_rec(c->l, check, l, m, ql, x);
    if (k != R0) return k;
    if (!c->r) c->r = new_node(m, r);
    return max_right_rec(c->r, check, m, r, ql, x);
  }

  template <typename F>
  ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {
    if (qr <= l) return L0;
    if (r <= qr && check(MX::op(c->x, x))) {
      x = MX::op(x, c->x);
      return L0;
    }
    if (r == l + 1) return r;
    ll m = (l + r) / 2;
    if (!c->r) c->r = new_node(m, r);
    ll k = min_left_rec(c->r, check, m, r, qr, x);
    if (k != L0) return k;
    if (!c->l) c->l = new_node(l, m);
    return min_left_rec(c->l, check, l, m, qr, x);
  }
};