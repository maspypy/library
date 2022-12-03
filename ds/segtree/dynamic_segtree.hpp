#pragma once

/*
コンストラクタに渡すもの
・L, R：最大の範囲（root node の表す範囲）
・function<X(ll,ll)> defulat_fn(l,r)：初期値での [l,r) 積の計算
*/
template <class Monoid, int NODES = 5'000'000>
struct Dynamic_SegTree {
  using X = typename Monoid::value_type;
  struct Node {
    X x;
    Node *l, *r;
  };

  Node *pool;
  int pid;
  using np = Node *;

  ll L, R;
  function<X(ll, ll)> default_fn;

  Dynamic_SegTree(ll L, ll R)
      : Dynamic_SegTree(L, R, [](ll L, ll R) { return Monoid::unit(); }) {}
  Dynamic_SegTree(ll L, ll R, function<X(ll, ll)> f)
      : pid(0), L(L), R(R), default_fn(f) {
    pool = new Node[NODES];
  }
  np set(np root, ll i, const X &x) {
    assert(L <= i && i < R);
    return set_rec(root, L, R, i, x);
  }
  np multiply(np root, ll i, const X &x) {
    assert(L <= i && i < R);
    return multiply_rec(root, L, R, i, x);
  }
  X prod(np root, ll l, ll r) {
    assert(L <= l && l <= r && r <= R);
    return prod_rec(root, L, R, l, r);
  }
  X prod_all(np root) { return root->x; }

  template <class F>
  ll max_right(np root, const F &check, ll s) {
    assert(L <= s && s <= R && check(Monoid::unit()));
    X p = Monoid::unit();
    return max_right_rec(root, L, R, check, s, p);
  }

  template <class F>
  ll min_left(np root, const F &check, ll t) {
    assert(L <= t && t <= R && check(Monoid::unit()));
    X p = Monoid::unit();
    return min_left_rec(root, L, R, check, t, p);
  }

private:
  np new_node(ll node_l, ll node_r) {
    pool[pid].x = default_fn(node_l, node_r);
    pool[pid].l = pool[pid].r = nullptr;
    return &(pool[pid++]);
  }

  void set_rec(Node *n, ll node_l, ll node_r, ll idx, const X &x) {
    if (node_r - node_l == 1) {
      n->x = x;
      return;
    }
    ll node_m = (node_l + node_r) / 2;

    if (idx < node_m) {
      if (!(n->l)) n->l = new_node(node_l, node_m);
      set_rec(n->l, node_l, node_m, idx, x);
    } else {
      if (!(n->r)) n->r = new_node(node_m, node_r);
      set_rec(n->r, node_m, node_r, idx, x);
    }
    X xl = (n->l ? (n->l)->x : Monoid::unit());
    X xr = (n->r ? (n->r)->x : Monoid::unit());
    n->x = Monoid::op(xl, xr);
  }

  void multiply_rec(Node *n, ll node_l, ll node_r, ll idx, const X &x) {
    if (node_r - node_l == 1) {
      n->x = Monoid::op(n->x, x);
      return;
    }
    ll node_m = (node_l + node_r) / 2;

    if (idx < node_m) {
      if (!(n->l)) n->l = new_node(node_l, node_m);
      multiply_rec(n->l, node_l, node_m, idx, x);
    } else {
      if (!(n->r)) n->r = new_node(node_m, node_r);
      multiply_rec(n->r, node_m, node_r, idx, x);
    }
    X xl = (n->l ? (n->l)->x : Monoid::unit());
    X xr = (n->r ? (n->r)->x : Monoid::unit());
    n->x = Monoid::op(xl, xr);
  }

  X prod_rec(Node *n, ll node_l, ll node_r, ll l, ll r) {
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return Monoid::unit();
    if (l == node_l && r == node_r) return n->x;
    ll node_m = (node_l + node_r) / 2;
    X xl = (n->l ? prod_rec(n->l, node_l, node_m, l, r) : Monoid::unit());
    X xr = (n->r ? prod_rec(n->r, node_m, node_r, l, r) : Monoid::unit());
    return Monoid::op(xl, xr);
  }

  template <typename F>
  ll max_right_rec(Node *n, ll node_l, ll node_r, const F &check, ll s, X &p) {
    if (node_r <= s) return R;
    if (s <= node_l) {
      X x = Monoid::op(p, n->x);
      if (check(x)) {
        p = x;
        return R;
      }
    }
    if (node_r - node_l == 1) return node_l;
    ll node_m = (node_l + node_r) / 2;
    if (!(n->l)) n->l = new_node(node_l, node_m);
    ll res = max_right_rec(n->l, node_l, node_m, check, s, p);
    if (res != R) return res;
    if (!(n->r)) n->r = new_node(node_m, node_r);
    return max_right_rec(n->r, node_m, node_r, check, s, p);
  }

  template <typename F>
  ll min_left_rec(Node *n, ll node_l, ll node_r, const F &check, ll t, X &p) {
    if (t <= node_l) return L;
    if (node_r <= t) {
      X x = Monoid::op(n->x, p);
      if (check(x)) {
        p = x;
        return L;
      }
    }
    if (node_r - node_l == 1) return node_r;
    ll node_m = (node_l + node_r) / 2;
    if (!(n->r)) n->r = new_node(node_m, node_r);
    ll res = min_left_rec(n->r, node_m, node_r, check, t, p);
    if (res != L) return res;
    if (!(n->l)) n->l = new_node(node_l, node_m);
    return min_left_rec(n->l, node_l, node_m, check, t, p);
  }
};
