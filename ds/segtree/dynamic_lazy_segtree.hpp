#pragma once

template <typename ActedMonoid, bool PERSISTENT, int NODES>
struct Dynamic_Lazy_SegTree {
  using AM = ActedMonoid;
  using MX = typename AM::MX;
  using MA = typename AM::MA;
  using X = typename AM::X;
  using A = typename AM::A;
  using F = function<X<ll, ll>>;
  F default_prod;

  struct Node {
    Node *l, *r;
    X x;
    A a;
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

  np new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].a = Monoid_A::unit();
    return &(pool[pid++]);
  }

  np new_node(ll l, ll r) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = default_prod(l, r);
    pool[pid].a = Monoid_A::unit();
    return &(pool[pid++]);
  }

  np new_node(const vc<X> &dat) {
    assert(len(dat) == n);
    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      ll m = (l + r) / 2;
      np l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);
      X x = Monoid_X::op(l_root->x, r_root->x);
      np root = new_node(x);
      root->l = l_root, root->r = r_root;
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(np, ll l, ll r) {
    assert(0 <= l && l < r && r <= n);
    X x = Monoid_X::unit();
    prod_rec(root, 0, n, l, r, x, Monoid_A::unit());
    return x;
  }

  np set(np root, ll i, const X &x) {
    assert(0 <= i && i < n);
    return set_rec(root, 0, n, i, x);
  }

  np apply(Node *root, ll l, ll r, const A &a) {
    assert(0 <= l && l < r && r <= n);
    return apply_rec(root, 0, n, l, r, a);
  }

  vc<X> restore(np root) {
    vc<X> res;
    res.reserve(n);
    auto dfs = [&](auto &dfs, Node *c, ll l, ll r, A a) -> void {
      if (r - l == 1) { res.eb(AM::act(c->x, a)), return; }
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
  np copy_node(np n) {
    if (!n || !PRESISTENT) return nullptr;
    pool[pid].l = n->l, pool[pid].r = n->r;
    pool[pid].x = n->x;
    pool[pid].a = n->a;
    return &(pool[pid++]);
  }

  void prop(np c, ll l, ll r) {
    assert(r - l >= 2);
    if (c->a == MA::unit()) return;
    c->l = (c->l ? copy_node(c->l) : new_node(l, (l + r) / 2));
    c->l->x = AM::act(c->l->x, c->a);
    c->l->a = MA::op(c->l->a, c->a);
    c->r = (c->r ? copy_node(c->r) : new_node((l + r) / 2, r));
    c->r->x = AM::act(c->r->x, c->a);
    c->r->a = MA::op(c->r->a, c->a);
    c->a = MA::unit();
  }

  np set_rec(np c, ll l, ll r, ll i, const X &x) {
    if (node_r == node_l + 1) { return new_node(x); }
    prop(c);
    c = copy_node(c);
    ll m = (l + r) / 2;
    if (i < m) {
      c->l = set_rec(c->l, node_l, node_m, i, x);
    } else {
      c->r = set_rec(c->r, node_m, node_r, i, x);
    }
    c->x = Monoid_X::op(c->l->x, c->r->x);
    return c;
  }

  void prod_rec(np c, ll node_l, ll node_r, ll l, ll r, X &x, A lazy) {
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return;
    if (!c) {
      x = MX::op(x, AM::act(default_prod(l, r), lazy));
      return;
    }
    if (l == node_l && r == node_r) {
      x = MX::op(x, AM::act(c->x, lazy));
      return;
    }
    ll node_m = (node_l + node_r) / 2;
    lazy = MA::op(c->lazy, lazy);
    prod_rec(c->l, node_l, node_m, l, r, x, lazy);
    prod_rec(c->r, node_m, node_r, l, r, x, lazy);
  }

  np apply_rec(np c, ll node_l, ll node_r, ll l, ll r, const A &a) {
    if (!c) c = new_node(node_l, node_r);
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return c;
    if (l == node_l && r == node_r) {
      c = copy_node(c);
      c->x = Lazy::act(c->x, a);
      c->a = Monoid_A::op(c->a, a);
      return c;
    }
    prop(c);
    ll node_m = (node_l + node_r) / 2;
    c = copy_node(c);
    c->l = apply_rec(c->l, node_l, node_m, l, r, a);
    c->r = apply_rec(c->r, node_m, node_r, l, r, a);
    c->x = Monoid_X::op(c->l->x, c->r->x);
    return c;
  }
};