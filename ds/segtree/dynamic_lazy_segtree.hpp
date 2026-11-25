// Source: https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree.hpp
#include "ds/node_pool.hpp"

template <typename AM>
struct Dynamic_Lazy_SegTree_Default_Prod {
  using MX = typename AM::Monoid_X;
  using X = typename AM::X;
  X operator()(ll, ll) const { return MX::id(); }
};

// set, multiply: 2H nodes 程度
// apply: 4H nodes 程度
template <typename ActedMonoid, bool PERSISTENT,
    typename DefaultProd = Dynamic_Lazy_SegTree_Default_Prod<ActedMonoid>>
struct Dynamic_Lazy_SegTree {
  using AM = ActedMonoid;
  using MX = typename AM::Monoid_X;
  using MA = typename AM::Monoid_A;
  using X = typename AM::X;
  using A = typename AM::A;
  using F = DefaultProd;
  F default_prod;

  struct Node {
    Node *l, *r;
    X x;
    A lazy;
  };

  Node_Pool<Node> pool;
  const ll L0, R0;
  using np = Node *;

  Dynamic_Lazy_SegTree(ll L0, ll R0, F default_prod = F{})
      : default_prod(std::move(default_prod)), L0(L0), R0(R0) {}

  np new_root() { return new_node(); }

  np new_node(const X x) {
    np c = pool.create();
    c->l = c->r = nullptr;
    c->x = x, c->lazy = MA::id();
    return c;
  }

  np new_node(ll l, ll r) {
    assert(l < r);
    return new_node(default_prod(l, r));
  }
  np new_node() { return L0 == R0 ? nullptr : new_node(L0, R0); }

  np new_node(const vc<X> &dat) {
    assert(L0 == 0 && R0 == len(dat));
    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {
      if (l == r) return nullptr;
      if (r - l == 1) return new_node(dat[l]);
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
    if (l == r || !root) return MX::id();
    assert(L0 <= l && l < r && r <= R0);
    X x = MX::id();
    prod_rec(root, L0, R0, l, r, x, MA::id());
    return x;
  }

  X prod_all(np root) { return prod(root, L0, R0); }

  np set(np root, ll i, const X &x) {
    assert(root && L0 <= i && i < R0);
    root = clone(root);
    set_rec(root, L0, R0, i, x);
    return root;
  }

  np multiply(np root, ll i, const X &x) {
    assert(root && L0 <= i && i < R0);
    root = clone(root);
    multiply_rec(root, L0, R0, i, x);
    return root;
  }

  np apply(np root, ll l, ll r, const A &a) {
    if (l == r) return root;
    assert(root && L0 <= l && l < r && r <= R0);
    root = clone(root);
    apply_rec(root, L0, R0, l, r, a);
    return root;
  }

  template <typename F>
  ll max_right(np root, F check, ll L) {
    assert(L0 <= L && L <= R0 && check(MX::id()));
    if (L == R0) return R0;
    assert(root);
    X x = MX::id();
    return max_right_rec(root, check, L0, R0, L, x, MA::id());
  }

  template <typename F>
  ll min_left(np root, F check, ll R) {
    assert(L0 <= R && R <= R0 && check(MX::id()));
    if (R == L0) return L0;
    assert(root);
    X x = MX::id();
    return min_left_rec(root, check, L0, R0, R, x, MA::id());
  }

  // 生成済みの葉について f(idx, val, end) を呼ぶ
  template <typename F>
  void enumerate(np root, F f) {
    bool end = false;
    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {
      if (!c) return;
      if (r - l == 1) {
        f(l, AM::act(c->x, a, 1), end);
        return;
      }
      ll m = (l + r) / 2;
      a = MA::op(c->lazy, a);
      dfs(dfs, c->l, l, m, a);
      if (end) return;
      dfs(dfs, c->r, m, r, a);
      if (end) return;
    };
    dfs(dfs, root, L0, R0, MA::id());
  }

  void reset() { pool.reset(); }

  // root[l:r) を apply(other[l:r),a) で上書きしたものを返す
  np copy_interval(np root, np other, ll l, ll r, A a) {
    static_assert(PERSISTENT);
    assert(L0 <= l && l <= r && r <= R0);
    if (l == r) return root;
    assert(root);
    if (root == other) return apply(root, l, r, a);
    root = clone(root);
    copy_interval_rec(root, other, L0, R0, l, r, a);
    return root;
  }

 private:
  np clone(np c) {
    if (!c || !PERSISTENT) return c;
    return pool.clone(c);
  }

  np own(np c, ll l, ll r) { return c ? clone(c) : new_node(l, r); }

  X value(np c, ll l, ll r) { return c ? c->x : default_prod(l, r); }

  void tag(np c, const A &a, ll len) {
    c->x = AM::act(c->x, a, len);
    c->lazy = MA::op(c->lazy, a);
  }

  // c は書き換え可能。左右の子も書き換え可能になったかを返す
  bool push(np c, ll l, ll m, ll r) {
    assert(r - l >= 2);
    if (c->lazy == MA::id()) return false;
    c->l = own(c->l, l, m);
    c->r = own(c->r, m, r);
    tag(c->l, c->lazy, m - l);
    tag(c->r, c->lazy, r - m);
    c->lazy = MA::id();
    return true;
  }

  void pull(np c, ll l, ll m, ll r) {
    c->x = MX::op(value(c->l, l, m), value(c->r, m, r));
  }

  void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, A a) {
    // c[ql,qr) <- apply(d[ql,qr),a)
    // c はすでに新しくしてある
    if (ql <= l && r <= qr) {
      if (d) {
        c->x = d->x;
        c->lazy = d->lazy;
        c->l = d->l, c->r = d->r;
      } else {
        c->x = default_prod(l, r);
        c->lazy = MA::id();
        c->l = c->r = nullptr;
      }
      tag(c, a, r - l);
      return;
    }
    ll m = (l + r) / 2;
    bool pushed = push(c, l, m, r);
    if (d) a = MA::op(d->lazy, a);
    if (ql < m) {
      if (!pushed) c->l = own(c->l, l, m);
      copy_interval_rec(c->l, d ? d->l : nullptr, l, m, ql, qr, a);
    }
    if (m < qr) {
      if (!pushed) c->r = own(c->r, m, r);
      copy_interval_rec(c->r, d ? d->r : nullptr, m, r, ql, qr, a);
    }
    pull(c, l, m, r);
  }

  // c はすでに新しくしてある
  void set_rec(np c, ll l, ll r, ll i, const X &x) {
    if (r - l == 1) {
      c->x = x;
      c->lazy = MA::id();
      return;
    }
    ll m = (l + r) / 2;
    bool pushed = push(c, l, m, r);
    if (i < m) {
      if (!pushed) c->l = own(c->l, l, m);
      set_rec(c->l, l, m, i, x);
    } else {
      if (!pushed) c->r = own(c->r, m, r);
      set_rec(c->r, m, r, i, x);
    }
    pull(c, l, m, r);
  }

  void multiply_rec(np c, ll l, ll r, ll i, const X &x) {
    if (r - l == 1) {
      c->x = MX::op(c->x, x);
      c->lazy = MA::id();
      return;
    }
    ll m = (l + r) / 2;
    bool pushed = push(c, l, m, r);
    if (i < m) {
      if (!pushed) c->l = own(c->l, l, m);
      multiply_rec(c->l, l, m, i, x);
    } else {
      if (!pushed) c->r = own(c->r, m, r);
      multiply_rec(c->r, m, r, i, x);
    }
    pull(c, l, m, r);
  }

  void apply_rec(np c, ll l, ll r, ll ql, ll qr, const A &a) {
    if (ql <= l && r <= qr) {
      tag(c, a, r - l);
      return;
    }
    ll m = (l + r) / 2;
    bool pushed = push(c, l, m, r);
    if (ql < m) {
      if (!pushed) c->l = own(c->l, l, m);
      apply_rec(c->l, l, m, ql, qr, a);
    }
    if (m < qr) {
      if (!pushed) c->r = own(c->r, m, r);
      apply_rec(c->r, m, r, ql, qr, a);
    }
    pull(c, l, m, r);
  }

  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A a) {
    if (!c) {
      ll L = max(l, ql), R = min(r, qr);
      x = MX::op(x, AM::act(default_prod(L, R), a, R - L));
      return;
    }
    if (ql <= l && r <= qr) {
      x = MX::op(x, AM::act(c->x, a, r - l));
      return;
    }
    ll m = (l + r) / 2;
    a = MA::op(c->lazy, a);
    if (ql < m) prod_rec(c->l, l, m, ql, qr, x, a);
    if (m < qr) prod_rec(c->r, m, r, ql, qr, x, a);
  }

  template <typename F>
  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x, A a) {
    if (r <= ql) return r;
    if (ql <= l) {
      X y = MX::op(x, AM::act(value(c, l, r), a, r - l));
      if (check(y)) {
        x = y;
        return r;
      }
    }
    if (r - l == 1) return l;
    ll m = (l + r) / 2;
    if (c) a = MA::op(c->lazy, a);
    if (ql < m) {
      ll k = max_right_rec(c ? c->l : nullptr, check, l, m, ql, x, a);
      if (k < m) return k;
    }
    return max_right_rec(c ? c->r : nullptr, check, m, r, ql, x, a);
  }

  template <typename F>
  ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x, A a) {
    if (qr <= l) return l;
    if (r <= qr) {
      X y = MX::op(AM::act(value(c, l, r), a, r - l), x);
      if (check(y)) {
        x = y;
        return l;
      }
    }
    if (r - l == 1) return r;
    ll m = (l + r) / 2;
    if (c) a = MA::op(c->lazy, a);
    if (m < qr) {
      ll k = min_left_rec(c ? c->r : nullptr, check, m, r, qr, x, a);
      if (m < k) return k;
    }
    return min_left_rec(c ? c->l : nullptr, check, l, m, qr, x, a);
  }
};
