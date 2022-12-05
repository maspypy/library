#pragma once

// 常にほとんどの要素が unit であることが保証されるような動的セグ木
// したがって、default_prod の類は持たせられず、acted monoid も一般には扱えない
// 永続化しない場合のノード数を O(N) に抑えることができるのが利点
// 密なものを永続化するときはかえって遅くなる可能性がある
template <typename Monoid, bool PERSISTENT, int NODES>
struct Dynamic_SegTree_Sparse {
  using MX = Monoid;
  using X = typename MX::value_type;

  struct Node {
    ll idx;
    Node *l, *r;
    X prod, x;
  };

  const ll L0, R0;
  Node *pool;
  int pid;
  using np = Node *;

  Dynamic_SegTree_Sparse(ll L0, ll R0) : L0(L0), R0(R0), pid(0) {
    pool = new Node[NODES];
  }

  np new_node(ll idx, const X x) {
    pool[pid].idx = idx;
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = pool[pid].prod = x;
    return &(pool[pid++]);
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

  void reset() { pid = 0; }

  vc<pair<ll, X>> get_all(np root) {
    vc<pair<ll, X>> res;
    auto dfs = [&](auto &dfs, np c) -> void {
      if (!c) return;
      dfs(dfs, c->l);
      res.eb(c->idx, c->x);
      dfs(dfs, c->r);
    };
    dfs(dfs, root);
    return res;
  }

private:
  void update(np c) {
    c->prod = c->x;
    if (c->l) c->prod = MX::op(c->l->prod, c->prod);
    if (c->r) c->prod = MX::op(c->prod, c->r->prod);
  }

  np copy_node(np c) {
    if (!c || !PERSISTENT) return c;
    pool[pid].idx = c->idx;
    pool[pid].l = c->l;
    pool[pid].r = c->r;
    pool[pid].x = c->x;
    pool[pid].prod = c->prod;
    return &(pool[pid++]);
  }

  np set_rec(np c, ll l, ll r, ll i, X x) {
    if (!c) {
      c = new_node(i, x);
      return c;
    }
    c = copy_node(c);
    if (c->idx == i) {
      c->x = x;
      update(c);
      return c;
    }
    ll m = (l + r) / 2;
    if (i < m) {
      if (c->idx < i) swap(c->idx, i), swap(c->x, x);
      c->l = set_rec(c->l, l, m, i, x);
    }
    if (m <= i) {
      if (i < c->idx) swap(c->idx, i), swap(c->x, x);
      c->r = set_rec(c->r, m, r, i, x);
    }
    update(c);
    return c;
  }

  np multiply_rec(np c, ll l, ll r, ll i, X x) {
    if (!c) {
      c = new_node(i, x);
      return c;
    }
    c = copy_node(c);
    if (c->idx == i) {
      c->x = MX::op(c->x, x);
      update(c);
      return c;
    }
    ll m = (l + r) / 2;
    if (i < m) {
      if (c->idx < i) swap(c->idx, i), swap(c->x, x);
      c->l = multiply_rec(c->l, l, m, i, x);
    }
    if (m <= i) {
      if (i < c->idx) swap(c->idx, i), swap(c->x, x);
      c->r = multiply_rec(c->r, m, r, i, x);
    }
    update(c);
    return c;
  }

  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {
    chmax(ql, l);
    chmin(qr, r);
    if (ql >= qr || !c) return;
    if (l == ql && r == qr) {
      x = MX::op(x, c->prod);
      return;
    }
    ll m = (l + r) / 2;
    prod_rec(c->l, l, m, ql, qr, x);
    if (ql <= (c->idx) && (c->idx) < qr) x = MX::op(x, c->x);
    prod_rec(c->r, m, r, ql, qr, x);
  }

  template <typename F>
  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {
    if (!c || r <= ql) return R0;
    if (check(MX::op(x, c->prod))) {
      x = MX::op(x, c->prod);
      return R0;
    }
    ll m = (l + r) / 2;
    ll k = max_right_rec(c->l, check, l, m, ql, x);
    if (k != R0) return k;
    if (ql <= (c->idx)) {
      x = MX::op(x, c->x);
      if (!check(x)) return c->idx;
    }
    return max_right_rec(c->r, check, m, r, ql, x);
  }

  template <typename F>
  ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {
    if (!c || qr <= l) return L0;
    if (check(MX::op(c->prod, x))) {
      x = MX::op(c->prod, x);
      return L0;
    }
    ll m = (l + r) / 2;
    ll k = min_left_rec(c->r, check, m, r, qr, x);
    if (k != L0) return k;
    if (c->idx < qr) {
      x = MX::op(c->x, x);
      if (!check(x)) return c->idx + 1;
    }
    return min_left_rec(c->l, check, l, m, qr, x);
  }
};