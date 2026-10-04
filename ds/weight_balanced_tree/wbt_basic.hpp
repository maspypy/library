#pragma once
#include "ds/node_pool.hpp"
#include "ds/weight_balanced_tree/wbt_base.hpp"

template <typename S>
struct WBT_Basic_Node {
  WBT_Basic_Node *l, *r;
  S s;
  u32 size;
  bool rev;
};

template <typename S, bool PERSISTENT>
struct WBT_Basic : WBT_Sequence_Base<WBT_Basic<S, PERSISTENT>,
                       WBT_Basic_Node<S>, PERSISTENT> {
  using Node = WBT_Basic_Node<S>;
  using Base = WBT_Sequence_Base<WBT_Basic, Node, PERSISTENT>;
  using np = Node*;
  Node_Pool<Node> pool;
  void reset() { pool.reset(); }
  np new_root() { return nullptr; }
  np new_node(const S& s) {
    np t = pool.create();
    t->l = t->r = nullptr, t->s = s, t->size = 1, t->rev = 0;
    return t;
  }
  np new_node(const vc<S>& a) {
    auto f = [&](auto&& f, u32 l, u32 r) -> np {
      if (l == r) return nullptr;
      u32 m = (l + r) >> 1;
      np t = new_node(a[m]);
      t->l = f(f, l, m), t->r = f(f, m + 1, r);
      pull(t);
      return t;
    };
    return f(f, 0, a.size());
  }
  np clone(np t) { return (!t || !PERSISTENT) ? t : pool.clone(t); }
  void pull(np t) {
    t->size = 1 + (t->l ? t->l->size : 0) + (t->r ? t->r->size : 0);
  }
  void push(np t) {
    if (!t->rev) return;
    if (t->l) {
      t->l = clone(t->l);
      t->l->rev ^= 1;
      swap(t->l->l, t->l->r);
    }
    if (t->r) {
      t->r = clone(t->r);
      t->r->rev ^= 1;
      swap(t->r->l, t->r->r);
    }
    t->rev = 0;
  }
  np reverse(np t, u32 l, u32 r) {
    assert(l <= r && r <= t->size);
    if (r - l <= 1) return t;
    auto [a, b, c] = this->split3(t, l, r);
    b = clone(b);
    b->rev ^= 1;
    swap(b->l, b->r);
    return this->merge3(a, b, c);
  }
  np set(np t, u32 k, const S& x) {
    auto [a, b, c] = this->split3(t, k, k + 1);
    b = clone(b);
    b->s = x;
    pull(b);
    return this->merge3(a, b, c);
  }
  S get(np t, u32 k) {
    bool z = 0;
    while (1) {
      np l = z ? t->r : t->l, r = z ? t->l : t->r;
      u32 s = l ? l->size : 0;
      if (k == s) return t->s;
      z ^= t->rev;
      if (k < s)
        t = l;
      else {
        k -= s + 1;
        t = r;
      }
    }
  }
  vc<S> get_all(np t) {
    vc<S> a;
    auto f = [&](auto&& f, np x, bool z) -> void {
      if (!x) return;
      f(f, z ? x->r : x->l, z ^ x->rev);
      a.eb(x->s);
      f(f, z ? x->l : x->r, z ^ x->rev);
    };
    f(f, t, 0);
    return a;
  }

  template <class F>
  pair<np, np> split_max_right(np t, const F& check) {
    return split_max_right_rec(t, check);
  }

  void free_subtree(np t) {
    if (!t) return;
    free_subtree(t->l);
    free_subtree(t->r);
    pool.destroy(t);
  }

 private:
  template <class F>
  pair<np, np> split_max_right_rec(np t, const F& check) {
    if (!t) return {nullptr, nullptr};
    t = clone(t);  // Must precede push() when PERSISTENT=true.
    push(t);
    np l = t->l, r = t->r;
    t->l = t->r = nullptr;
    pull(t);  // t is the singleton x required by join().
    if (check(t->s)) {
      auto [a, b] = split_max_right_rec(r, check);
      return {this->join(l, t, a), b};
    }
    auto [a, b] = split_max_right_rec(l, check);
    return {a, this->join(b, t, r)};
  }
};
