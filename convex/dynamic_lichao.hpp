#include "alg/monoid/min_idx.hpp"

// x 座標は long long に限定している。
// 直線の係数 T は double や i128 も可能。
template <typename T, int NODES>
struct Dynamic_LiChaoTree {
  using Mono = Monoid_Min_Idx<T>;
  struct Line {
    int idx;
    T a, b;
    Line(int idx, T a, T b) : idx(idx), a(a), b(b) {}
    Line() : Line(-1, 0, infty<T>) {}
    pair<T, int> operator()(T x) const { return {a * x + b, idx}; }
  };

  struct Node {
    Line f;
    Node *l, *r;
  };

  Node *pool;
  int pid;
  ll L, R;
  Node *root;

  Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R), root(nullptr) {
    pool = new Node[NODES];
  }

  Node *new_node() {
    pool[pid].f = Line();
    return &(pool[pid++]);
  }

  void add_segment(ll xl, ll xr, T a, T b, int idx = -1) {
    if (a != 0) {
      ll xlim = (infty<T> - abs(b)) / abs(a);
      assert(abs(xl) < xlim);
      assert(abs(xr) < xlim);
    }
    assert(L <= xl && xl < xr && xr <= R);
    Line f(idx, a, b);
    if (!root) root = new_node();
    add_segment_rec(root, xl, xr, f, L, R);
  }

  void add_line(T a, T b, int idx = -1) { add_segment(L, R, a, b, idx); }

  pair<T, int> query(ll x) {
    assert(L <= x && x < R);
    if (!root) return Mono::unit();
    return query_rec(root, x, L, R);
  }

private:
  void add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,
                       ll node_r) {
    chmax(xl, node_l);
    chmin(xr, node_r);
    if (xl >= xr) return;
    if (node_l < xl || xr < node_r) {
      ll node_m = (node_l + node_r) / 2;
      if (!c->l) c->l = new_node();
      if (!c->r) c->r = new_node();
      add_segment_rec(c->l, xl, xr, f, node_l, node_m);
      add_segment_rec(c->r, xl, xr, f, node_m, node_r);
      return;
    }
    add_line_rec(c, f, node_l, node_r);
  }

  void add_line_rec(Node *c, const Line &f, ll node_l, ll node_r) {
    auto fl = f(node_l), fr = f(node_r - 1);
    Line g = c->f;
    auto gl = g(node_l), gr = g(node_r - 1);
    bool bl = Mono::is_small(fl, gl);
    bool br = Mono::is_small(fr, gr);
    if (bl && br) {
      c->f = f;
      return;
    }
    if (!bl && !br) { return; }
    ll node_m = (node_l + node_r) / 2;
    auto fm = f(node_m), gm = g(node_m);
    bool bm = Mono::is_small(fm, gm);
    if (bm) {
      c->f = f;
      if (bl) {
        if (!c->r) c->r = new_node();
        add_line_rec(c->r, g, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        add_line_rec(c->l, g, node_l, node_m);
      }
    } else {
      if (!bl) {
        if (!c->r) c->r = new_node();
        add_line_rec(c->r, f, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        add_line_rec(c->l, f, node_l, node_m);
      }
    }
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