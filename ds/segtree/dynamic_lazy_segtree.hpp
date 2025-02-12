#pragma once

// Q*4logN 程度必要? apply で 4logN ノード作っていると思う
template <typename ActedMonoid, bool PERSISTENT>
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

  const int NODES;
  const ll L0, R0;
  Node *pool;
  int pid;
  using np = Node *;

  Dynamic_Lazy_SegTree(
      int NODES, ll L0, ll R0, F default_prod = [](ll, ll) -> X { return MX::unit(); })
      : default_prod(default_prod), NODES(NODES), L0(L0), R0(R0), pid(0) {
    pool = new Node[NODES];
  }
  ~Dynamic_Lazy_SegTree() { delete[] pool; }

  np new_root() { return new_node(L0, R0); }

  np new_node(const X x) {
    assert(pid < NODES);
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].lazy = MA::unit();
    return &(pool[pid++]);
  }

  np new_node(ll l, ll r) {
    assert(l < r);
    return new_node(default_prod(l, r));
  }
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
    if (l == r || !root) return MX::unit();
    assert(pid && L0 <= l && l < r && r <= R0);
    X x = MX::unit();
    prod_rec(root, L0, R0, l, r, x, MA::unit());
    return x;
  }

  X prod_all(np root) { return prod(root, L0, R0); }

  np set(np root, ll i, const X &x) {
    assert(pid && L0 <= i && i < R0);
    return set_rec(root, L0, R0, i, x);
  }

  np multiply(np root, ll i, const X &x) {
    assert(pid && L0 <= i && i < R0);
    return multiply_rec(root, L0, R0, i, x);
  }

  np apply(np root, ll l, ll r, const A &a) {
    if (l == r) return root;
    assert(pid && L0 <= l && l < r && r <= R0);
    return apply_rec(root, L0, R0, l, r, a);
  }

  template <typename F>
  ll max_right(np root, F check, ll L) {
    assert(pid && L0 <= L && L <= R0 && check(MX::unit()));
    X x = MX::unit();
    return max_right_rec(root, check, L0, R0, L, x);
  }

  template <typename F>
  ll min_left(np root, F check, ll R) {
    assert(pid && L0 <= R && R <= R0 && check(MX::unit()));
    X x = MX::unit();
    return min_left_rec(root, check, L0, R0, R, x);
  }

  // f(idx, val)
  template <typename F>
  void enumerate(np root, F f) {
    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {
      if (!c) return;
      if (r - l == 1) {
        f(l, AM::act(c->x, a, 1));
        return;
      }
      ll m = (l + r) / 2;
      a = MA::op(c->lazy, a);
      dfs(dfs, c->l, l, m, a);
      dfs(dfs, c->r, m, r, a);
    };
    dfs(dfs, root, L0, R0, MA::unit());
  }

  void reset() { pid = 0; }

  // root[l:r) を apply(other[l:r),a) で上書きしたものを返す
  np copy_interval(np root, np other, ll l, ll r, A a) {
    if (root == other) return root;
    root = copy_node(root);
    copy_interval_rec(root, other, L0, R0, l, r, a);
    return root;
  }

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

  void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, A a) {
    // c[ql,qr) <- apply(d[ql,qr),a)
    // もう c は新しくしてある
    assert(c);
    chmax(ql, l), chmin(qr, r);
    if (ql >= qr) return;
    if (l == ql && r == qr) {
      if (d) {
        c->x = AM::act(d->x, a, r - l), c->lazy = MA::op(d->lazy, a);
        c->l = d->l, c->r = d->r;
      } else {
        c->x = AM::act(default_prod(l, r), a, r - l), c->lazy = a;
        c->l = nullptr, c->r = nullptr;
      }
      return;
    }
    // push
    ll m = (l + r) / 2;
    c->l = (c->l ? copy_node(c->l) : new_node(m - l));
    c->r = (c->r ? copy_node(c->r) : new_node(r - m));
    c->l->x = AM::act(c->l->x, c->lazy, m - l);
    c->l->lazy = MA::op(c->l->lazy, c->lazy);
    c->r->x = AM::act(c->r->x, c->lazy, r - m);
    c->r->lazy = MA::op(c->r->lazy, c->lazy);
    c->lazy = MA::unit();
    if (d) a = MA::op(d->lazy, a);
    copy_interval_rec(c->l, (d && d->l ? d->l : nullptr), l, m, ql, qr, a);
    copy_interval_rec(c->r, (d && d->r ? d->r : nullptr), m, r, ql, qr, a);
    c->x = MX::op(c->l->x, c->r->x);
    return;
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
      c->l = multiply_rec(c->l, l, m, i, x);
    } else {
      c->r = multiply_rec(c->r, m, r, i, x);
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

  template <typename F>
  ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {
    if (qr <= l) return l;
    if (!c) c = new_node(l, r);
    chmin(qr, r);
    if (r == qr && check(MX::op(c->x, x))) {
      x = MX::op(c->x, x);
      return l;
    }
    if (r == l + 1) return r;
    prop(c, l, r);
    ll m = (l + r) / 2;
    ll k = min_left_rec(c->r, check, m, r, qr, x);
    if (m < k) return k;
    return min_left_rec(c->l, check, l, m, qr, x);
  }
};