#pragma once

template <typename Lazy, int NODES = 1'000'000>
struct Persistent_LazySegTree {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;

  struct Node {
    Node *l, *r;
    X x;
    A a;
    bool propagated;
  };

  const int n;
  Node *pool;
  int pid;

  Persistent_LazySegTree(int n) : n(n), pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].a = Monoid_A::unit();
    pool[pid].propagated = 1;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    assert(len(dat) == n);
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      int m = (l + r) / 2;
      Node *l_root = dfs(dfs, l, m);
      Node *r_root = dfs(dfs, m, r);
      X x = Monoid_X::op(l_root->x, r_root->x);
      Node *root = new_node(x);
      root->l = l_root, root->r = r_root;
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(Node *root, int l, int r) {
    assert(0 <= l && l < r && r <= n);
    X x = Monoid_X::unit();
    prod_rec(root, 0, n, l, r, x);
    return x;
  }

  Node *set(Node *root, int i, const X &x) {
    assert(0 <= i && i < n);
    return set_rec(root, 0, n, i, x);
  }

  Node *apply(Node *root, int l, int r, const A &a) {
    assert(0 <= l && l < r && r <= n);
    return apply_rec(root, 0, n, l, r, a);
  }

  vc<X> restore(Node *root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, Node *c, int node_l, int node_r) -> void {
      if (node_r - node_l == 1) {
        res.eb(c->x);
        return;
      }
      int node_m = (node_l + node_r) / 2;
      prop(c);
      dfs(dfs, c->l, node_l, node_m);
      dfs(dfs, c->r, node_m, node_r);
    };
    dfs(dfs, root, 0, n);
    return res;
  }

  void reset() { pid = 0; }

private:
  Node *copy_node(Node *n) {
    if (!n) return nullptr;
    pool[pid].l = n->l;
    pool[pid].r = n->r;
    pool[pid].x = n->x;
    pool[pid].a = n->a;
    return &(pool[pid++]);
  }

  void prop(Node *c) {
    assert(c->l && c->r);
    if (!c->propagated) {
      c->l = copy_node(c->l);
      c->l->x = Lazy::act(c->l->x, c->a);
      c->l->a = Monoid_A::op(c->l->a, c->a);
      c->l->propagated = 0;

      c->r = copy_node(c->r);
      c->r->x = Lazy::act(c->r->x, c->a);
      c->r->a = Monoid_A::op(c->r->a, c->a);
      c->r->propagated = 0;

      c->a = Monoid_A::unit();
      c->propagated = 1;
    }
  }

  Node *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {
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