#pragma once

template <typename ActedMonoid, bool PERSISTENT, int NODES>
struct Dynamic_LazySegTree {
  using AM = ActedMonoid;
  using MX = typename AM::MX;
  using MA = typename AM::MA;
  using X = typename AM::X;
  using A = typename AM::A;

  struct Node {
    Node *l, *r;
    X x;
    A a;
  };

  const ll n;
  Node *pool;
  int pid;
  using np = Node *;

  Persistent_LazySegTree(int n) : n(n), pid(0) { pool = new Node[NODES]; }

  np new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
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
    prod_rec(root, 0, n, l, r, x);
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

  void prop(np c) {
    if (c->a == MA::unit()) return;
    if (c->l) {
      c->l = copy_node(c->l);
      c->l->x = AM::act(c->l->x, c->a);
      c->l->a = MA::op(c->l->a, c->a);
    }
    if (c->r) {
      c->r = copy_node(c->r);
      c->r->x = AM::act(c->r->x, c->a);
      c->r->a = MA::op(c->r->a, c->a);
    }
    c->a = MA::unit();
  }

  np set_rec(np c, ll l, ll r, ll i, const X &x) {
    if (node_r == node_l + 1) { return new_node(x); }
    c = copy_node(c);
    prop(c);
    int node_m = (node_l + node_r) / 2;
    if (i < node_m) {
      c->l = set_rec(c->l, node_l, node_m, i, x);
    } else {
      c->r = set_rec(c->r, node_m, node_r, i, x);
    }
    c->x = Monoid_X::op(c->l->x, c->r->x);
    return c;
  }

  void prod_rec(Node *c, int node_l, int node_r, int l, int r, X &x) {
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return;
    if (l == node_l && r == node_r) {
      x = Monoid_X::op(x, c->x);
      return;
    }
    prop(c);
    int node_m = (node_l + node_r) / 2;
    prod_rec(c->l, node_l, node_m, l, r, x);
    prod_rec(c->r, node_m, node_r, l, r, x);
  }

  Node *apply_rec(Node *c, int node_l, int node_r, int l, int r, const A &a) {
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return c;
    if (l == node_l && r == node_r) {
      c = copy_node(c);
      c->x = Lazy::act(c->x, a);
      c->a = Monoid_A::op(c->a, a);
      return c;
    }
    c = copy_node(c);
    prop(c);
    int node_m = (node_l + node_r) / 2;
    c->l = apply_rec(c->l, node_l, node_m, l, r, a);
    c->r = apply_rec(c->r, node_m, node_r, l, r, a);
    c->x = Monoid_X::op(c->l->x, c->r->x);
    return c;
  }
};