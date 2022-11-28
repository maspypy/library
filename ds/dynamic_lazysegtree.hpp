#pragma once

/*
コンストラクタに渡すもの
・L, R：最大の範囲（root node の表す範囲）
・function<X(ll,ll)> defulat_fn(l,r)：初期値での [l,r) 積の計算
*/
template <class Lazy, int NODES = 5'000'000>
struct Dynamic_LazySegTree {
  using Monoid_X = typename Lazy::Monoid_X;
  using Monoid_A = typename Lazy::Monoid_A;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;

  struct Node {
    X x;
    A a;
    Node *l, *r;
    Node() {}
    Node(const X &x) : x(x), a(Monoid_A::unit()), l(nullptr), r(nullptr) {}
    X get() { return Lazy::act(x, a); }
  };

  Node *pool;
  int pid;
  ll L, R;
  Node *root;
  function<X(ll, ll)> default_fn;

  Dynamic_LazySegTree(ll L, ll R, function<X(ll, ll)> f)
      : pid(0), L(L), R(R), default_fn(f) {
    pool = new Node[NODES];
    root = new_node(L, R);
  }

  void reset() {
    pid = 0;
    root = new_node(L, R);
  }

  void set(ll i, const X &x) {
    assert(L <= i && i < R);
    set_rec(root, L, R, i, x);
  }

  void apply(ll l, ll r, const A &a) {
    assert(L <= l && l <= r && r <= R);
    apply_rec(root, L, R, l, r, a);
  }

  X prod(ll l, ll r) {
    assert(L <= l && l <= r && r <= R);
    return prod_rec(root, L, R, l, r);
  }

  X prod_all() { return root->get(); }

  template <class F>
  ll max_right(const F &check, ll s) {
    assert(L <= s && s <= R && check(Monoid_X::unit()));
    X p = Monoid_X::unit();
    return max_right_rec(root, L, R, check, s, p);
  }

  template <class F>
  ll min_left(const F &check, ll t) {
    assert(L <= t && t <= R && check(Monoid_X::unit()));
    X p = Monoid_X::unit();
    return min_left_rec(root, L, R, check, t, p);
  }

  void debug() {
    auto dfs = [&](auto &dfs, Node *n, ll l, ll r) -> void {
      print("lr", l, r, "x", n->x, "a", n->a);
      ll m = (l + r) / 2;
      if (n->l) dfs(dfs, n->l, l, m);
      if (n->r) dfs(dfs, n->r, m, r);
    };
    dfs(dfs, root, L, R);
  }

private:
  Node *new_node(ll node_l, ll node_r) {
    pool[pid].x = default_fn(node_l, node_r);
    pool[pid].a = Monoid_A::unit();
    pool[pid].l = pool[pid].r = nullptr;
    return &(pool[pid++]);
  }

  void prop(Node *n, ll node_l, ll node_r) {
    if (n->a == Monoid_A::unit()) return;
    ll node_m = (node_l + node_r) / 2;
    if (!n->l) n->l = new_node(node_l, node_m);
    if (!n->r) n->r = new_node(node_m, node_r);
    (n->l)->a = Monoid_A::op((n->l)->a, n->a);
    (n->r)->a = Monoid_A::op((n->r)->a, n->a);
    n->x = Lazy::act(n->x, n->a);
    n->a = Monoid_A::unit();
  }

  void set_rec(Node *n, ll node_l, ll node_r, ll idx, const X &x) {
    if (node_r - node_l == 1) {
      n->x = x;
      n->a = Monoid_A::unit();
      return;
    }
    ll node_m = (node_l + node_r) / 2;
    prop(n, node_l, node_r);

    if (idx < node_m) {
      if (!(n->l)) n->l = new_node(node_l, node_m);
      set_rec(n->l, node_l, node_m, idx, x);
    } else {
      if (!(n->r)) n->r = new_node(node_m, node_r);
      set_rec(n->r, node_m, node_r, idx, x);
    }
    X xl = (n->l ? (n->l)->get() : Monoid_X::unit());
    X xr = (n->r ? (n->r)->get() : Monoid_X::unit());
    n->x = Monoid_X::op(xl, xr);
  }

  void apply_rec(Node *n, ll node_l, ll node_r, ll l, ll r, const A &a) {
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return;
    if (l == node_l && r == node_r) {
      n->a = Monoid_A::op(n->a, a);
      return;
    }
    ll node_m = (node_l + node_r) / 2;
    prop(n, node_l, node_r);
    if (!(n->l)) n->l = new_node(node_l, node_m);
    if (!(n->r)) n->r = new_node(node_m, node_r);
    apply_rec(n->l, node_l, node_m, l, r, a);
    apply_rec(n->r, node_m, node_r, l, r, a);
    n->x = Monoid_X::op((n->l)->get(), (n->r)->get());
  }

  X prod_rec(Node *n, ll node_l, ll node_r, ll l, ll r) {
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return Monoid_X::unit();
    if (l == node_l && r == node_r) return n->get();
    ll node_m = (node_l + node_r) / 2;
    prop(n, node_l, node_r);
    X xl = (n->l ? prod_rec(n->l, node_l, node_m, l, r) : Monoid_X::unit());
    X xr = (n->r ? prod_rec(n->r, node_m, node_r, l, r) : Monoid_X::unit());
    return Monoid_X::op(xl, xr);
  }

  template <typename F>
  ll max_right_rec(Node *n, ll node_l, ll node_r, const F &check, ll s, X &p) {
    if (node_r <= s) return R;
    if (s <= node_l) {
      X x = Monoid_X::op(p, n->get());
      if (check(x)) {
        p = x;
        return R;
      }
    }
    if (node_r - node_l == 1) return node_l;
    ll node_m = (node_l + node_r) / 2;
    if (!(n->l)) n->l = new_node(node_l, node_m);
    if (!(n->r)) n->r = new_node(node_m, node_r);
    prop(n, node_l, node_r);
    ll res = max_right_rec(n->l, node_l, node_m, check, s, p);
    if (res != R) return res;
    return max_right_rec(n->r, node_m, node_r, check, s, p);
  }

  template <typename F>
  ll min_left_rec(Node *n, ll node_l, ll node_r, const F &check, ll t, X &p) {
    if (t <= node_l) return L;
    if (node_r <= t) {
      X x = Monoid_X::op(n->get(), p);
      if (check(x)) {
        p = x;
        return L;
      }
    }
    if (node_r - node_l == 1) return node_r;
    ll node_m = (node_l + node_r) / 2;
    if (!(n->l)) n->l = new_node(node_l, node_m);
    if (!(n->r)) n->r = new_node(node_m, node_r);
    prop(n, node_l, node_r);
    ll res = min_left_rec(n->r, node_m, node_r, check, t, p);
    if (res != L) return res;
    return min_left_rec(n->l, node_l, node_m, check, t, p);
  }
};
