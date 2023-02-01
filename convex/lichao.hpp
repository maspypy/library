
#include "alg/monoid/min_idx.hpp"

// 関数は (long long) -> T
// evaluate を書き変えると、totally monotone な関数群にも使える
template <typename T, bool PERSISTENT, int NODES>
struct Persistent_Dynamic_LiChaoTree {
  using FUNC = pair<T, T>;
  vc<FUNC> funcs;

  static inline T evaluate(int i, ll x) {
    auto [a, b] = funcs[i];
    return a * x + b;
  }

  struct Node {
    int fid;
    Node *l, *r;
  };

  Node *pool;
  int pid;
  ll L, R;

  using np = Node *;

  Persistent_Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R) {
    pool = new Node[NODES];
  }

  Node *new_node() {
    pool[pid].fid = -1;
    pool[pid].l = nullptr;
    pool[pid].r = nullptr;
    return &(pool[pid++]);
  }

  np add_segment(np root, ll xl, ll xr, FUNC f) {
    if (a != 0) {
      ll xlim = (infty<T> - abs(b)) / abs(a);
      assert(abs(xl) < xlim);
      assert(abs(xr) < xlim);
    }
    assert(L <= xl && xl < xr && xr <= R);
    Line f(idx, a, b);
    if (!root) root = new_node();
    return add_segment_rec(root, xl, xr, f, L, R);
  }

  np add_line(np root, T a, T b, int idx = -1) {
    return add_segment(root, L, R, a, b, idx);
  }

  pair<T, int> query(np root, ll x) {
    assert(L <= x && x < R);
    if (!root) return Mono::unit();
    return query_rec(root, x, L, R);
  }

private:
  np copy_node(Node *c) {
    np nc = new_node();
    nc->f = c->f;
    nc->l = c->l;
    nc->r = c->r;
    return nc;
  }

  np add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,
                     ll node_r) {
    chmax(xl, node_l);
    chmin(xr, node_r);
    if (xl >= xr) return c;
    if (node_l < xl || xr < node_r) {
      c = copy_node(c);
      ll node_m = (node_l + node_r) / 2;
      if (!c->l) c->l = new_node();
      if (!c->r) c->r = new_node();
      c->l = add_segment_rec(c->l, xl, xr, f, node_l, node_m);
      c->r = add_segment_rec(c->r, xl, xr, f, node_m, node_r);
      return c;
    }
    return add_line_rec(c, f, node_l, node_r);
  }

  np add_line_rec(Node *c, const Line &f, ll node_l, ll node_r) {
    auto fl = f(node_l), fr = f(node_r - 1);
    Line g = c->f;
    auto gl = g(node_l), gr = g(node_r - 1);
    bool bl = Mono::is_small(fl, gl);
    bool br = Mono::is_small(fr, gr);
    if (bl && br) {
      c = copy_node(c);
      c->f = f;
      return c;
    }
    if (!bl && !br) { return c; }

    c = copy_node(c);
    ll node_m = (node_l + node_r) / 2;
    auto fm = f(node_m), gm = g(node_m);
    bool bm = Mono::is_small(fm, gm);
    if (bm) {
      c->f = f;
      if (bl) {
        if (!c->r) c->r = new_node();
        c->r = add_line_rec(c->r, g, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        c->l = add_line_rec(c->l, g, node_l, node_m);
      }
    } else {
      if (!bl) {
        if (!c->r) c->r = new_node();
        c->r = add_line_rec(c->r, f, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        c->l = add_line_rec(c->l, f, node_l, node_m);
      }
    }
    return c;
  }

  pair<T, int> query_rec(Node *c, ll x, ll node_l, ll node_r) {
    pair<T, int> res = c->f(x);
    ll node_m = (node_l + node_r) / 2;
    if (x < node_m && c->l)
      res = Mono::op(res, query_rec(c->l, x, node_l, node_m));
    if (x >= node_m && c->r)
      res = Mono::op(res, query_rec(c->r, x, node_m, node_r));
    return res;
  }
};