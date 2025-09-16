
#include "ds/node_pool.hpp"

// Lazy だけでもいいような気がしたが,
// 加算が定義されていない型で使うかもしれないから残してある
template <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>
struct Meldable_Heap {
  struct Node {
    Node *l, *r;
    VAL x;
    u32 size, dist;  // dist: leaf までの距離
  };
  Node_Pool<Node> pool;
  int pid;
  using np = Node *;

  np new_root() { return nullptr; }
  np new_node(const VAL &x) {
    np c = pool.create();
    c->l = c->r = nullptr;
    c->x = x, c->size = 1, c->dist = 1;
    return c;
  }
  np clone(np a) {
    if (!a || !PERSISTENT) return a;
    return pool.clone(a);
  }
  np meld(np a, np b) {
    if (!a) return b;
    if (!b) return a;
    a = clone(a);
    b = clone(b);
    if constexpr (TOP_IS_MIN) {
      if ((a->x) > (b->x)) swap(a, b);
    } else {
      if ((a->x) < (b->x)) swap(a, b);
    }
    a->r = meld(a->r, b);
    if (!(a->l) || (a->l->dist < a->r->dist)) swap(a->l, a->r);
    a->dist = (a->r ? a->r->dist : 0) + 1;
    a->size = 1;
    if (a->l) a->size += a->l->size;
    if (a->r) a->size += a->r->size;
    return a;
  }
  np push(np a, VAL x) { return meld(a, new_node(x)); }
  np pop(np a) { return meld(a->l, a->r); }
  VAL top(np a) { return a->x; }
  vc<VAL> get_all(np a) {
    vc<VAL> A;
    auto dfs = [&](auto &dfs, np a) -> void {
      if (!a) return;
      A.eb(a->x), dfs(dfs, a->l), dfs(dfs, a->r);
    };
    dfs(dfs, a);
    sort(all(A));
    if (!TOP_IS_MIN) reverse(all(A));
    return A;
  }
};

// 全体加算ができるようにする
// path sum が実際の値となるようにすれば追加フィールドなしに実現できる
// https://qoj.ac/contest/1699/problem/8518
template <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>
struct Lazy_Meldable_Heap {
  struct Node {
    Node *l, *r;
    VAL x;
    u32 size, dist;
  };
  Node_Pool<Node> pool;
  using np = Node *;

  np new_root() { return nullptr; }
  np new_node(const VAL &x) {
    np c = pool.create();
    c->l = c->r = nullptr;
    c->x = x, c->size = 1, c->dist = 1;
    return c;
  }
  np clone(np a) {
    if (!a || !PERSISTENT) return a;
    np b = new_node(a->x);
    b->l = a->l, b->r = a->r;
    b->size = a->size, b->dist = a->dist;
    return b;
  }
  np apply(np a, VAL x) {
    if (!a) return a;
    a = clone(a);
    a->x += x;
    return a;
  }
  np meld(np a, np b, VAL add_a = 0, VAL add_b = 0) {
    if (!a) {
      return (add_b == 0 ? b : apply(b, add_b));
    }
    if (!b) {
      return (add_a == 0 ? a : apply(a, add_a));
    }
    if constexpr (TOP_IS_MIN) {
      if ((a->x + add_a) > (b->x + add_b)) swap(a, b), swap(add_a, add_b);
    } else {
      if ((a->x + add_a) < (b->x + add_b)) swap(a, b), swap(add_a, add_b);
    }
    a = clone(a);
    a->x += add_a;
    a->r = meld(a->r, b, 0, -a->x + add_b);
    if (!(a->l) || (a->l->dist < a->r->dist)) swap(a->l, a->r);
    a->dist = (a->r ? a->r->dist : 0) + 1;
    a->size = 1;
    if (a->l) a->size += a->l->size;
    if (a->r) a->size += a->r->size;
    return a;
  }

  np push(np a, VAL x) { return meld(a, new_node(x)); }
  np pop(np a) { return meld(a->l, a->r, a->x, a->x); }
  VAL top(np a) { return a->x; }
  vc<VAL> get_all(np a) {
    vc<VAL> A;
    auto dfs = [&](auto &dfs, np a, VAL lazy) -> void {
      if (!a) return;
      A.eb(a->x + lazy);
      lazy += a->x;
      dfs(dfs, a->l, lazy), dfs(dfs, a->r, lazy);
    };
    dfs(dfs, a, 0);
    sort(all(A));
    if (!TOP_IS_MIN) reverse(all(A));
    return A;
  }
};