#pragma once
#include "ds/node_pool.hpp"
#include "ds/weight_balanced_tree/wbt_base.hpp"

template <class X>
struct WBT_Monoid_Node {
  WBT_Monoid_Node *l, *r;
  X x, prod, rev_prod;
  u32 size;
  bool rev;
};
template <class Monoid, bool PERSISTENT>
struct WBT_Monoid
    : WBT_Sequence_Base<WBT_Monoid<Monoid, PERSISTENT>,
          WBT_Monoid_Node<typename Monoid::value_type>, PERSISTENT> {
  using X = typename Monoid::value_type;
  using Node = WBT_Monoid_Node<X>;
  using np = Node*;
  using Base = WBT_Sequence_Base<WBT_Monoid, Node, PERSISTENT>;
  Node_Pool<Node> pool;
  void reset() { pool.reset(); }
  np new_root() { return nullptr; }
  np new_node(const X& x) {
    np t = pool.create();
    t->l = t->r = nullptr;
    t->x = t->prod = t->rev_prod = x;
    t->size = 1;
    t->rev = 0;
    return t;
  }
  np new_node(const vc<X>& a) {
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
    t->size = 1;
    t->prod = t->rev_prod = t->x;
    if (t->l) {
      t->size += t->l->size;
      t->prod = Monoid::op(t->l->prod, t->prod);
      t->rev_prod = Monoid::op(t->rev_prod, t->l->rev_prod);
    }
    if (t->r) {
      t->size += t->r->size;
      t->prod = Monoid::op(t->prod, t->r->prod);
      t->rev_prod = Monoid::op(t->r->rev_prod, t->rev_prod);
    }
  }
  void push(np t) {
    if (!t->rev) return;
    for (np* q : {&t->l, &t->r})
      if (*q) {
        *q = clone(*q);
        (*q)->rev ^= 1;
        swap((*q)->l, (*q)->r);
        swap((*q)->prod, (*q)->rev_prod);
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
    swap(b->prod, b->rev_prod);
    return this->merge3(a, b, c);
  }
  np set(np t, u32 k, const X& x) {
    auto [a, b, c] = this->split3(t, k, k + 1);
    b = clone(b);
    b->x = x;
    pull(b);
    return this->merge3(a, b, c);
  }
  np multiply(np t, u32 k, const X& x) {
    return set(t, k, Monoid::op(get(t, k), x));
  }
  X prod(np t) { return t ? t->prod : Monoid::id(); }
  X prod(np t, u32 l, u32 r) {
    assert(l <= r && r <= t->size);
    return prod_rec(t, l, r, 0);
  }
  X get(np t, u32 k) {
    bool z = 0;
    while (1) {
      np l = z ? t->r : t->l, r = z ? t->l : t->r;
      u32 s = l ? l->size : 0;
      if (k == s) return t->x;
      z ^= t->rev;
      if (k < s)
        t = l;
      else
        k -= s + 1, t = r;
    }
  }
  vc<X> get_all(np t) {
    vc<X> a;
    auto f = [&](auto&& f, np q, bool z) -> void {
      if (!q) return;
      f(f, z ? q->r : q->l, z ^ q->rev);
      a.eb(q->x);
      f(f, z ? q->l : q->r, z ^ q->rev);
    };
    f(f, t, 0);
    return a;
  }
  template <class F>
  pair<np, np> split_max_right(np t, const F& check) {
    assert(check(Monoid::id()));
    X x = Monoid::id();
    return split_max_right_rec(t, check, x);
  }
  template <class F>
  pair<np, np> split_max_right_prod(np t, const F& f) {
    return split_max_right(t, f);
  }

  void free_subtree(np t) {
    if (!t) return;
    free_subtree(t->l);
    free_subtree(t->r);
    pool.destroy(t);
  }

 private:
  X prod_rec(np t, u32 l, u32 r, bool z) {
    if (l == 0 && r == t->size) return z ? t->rev_prod : t->prod;
    np a = z ? t->r : t->l, b = z ? t->l : t->r;
    u32 s = a ? a->size : 0;
    X x = Monoid::id();
    if (l < s) x = Monoid::op(x, prod_rec(a, l, min(r, s), z ^ t->rev));
    if (l <= s && s < r) x = Monoid::op(x, t->x);
    if (s + 1 < r)
      x = Monoid::op(
          x, prod_rec(b, max(l, s + 1) - s - 1, r - s - 1, z ^ t->rev));
    return x;
  }

  // Add under private: in WBT_Monoid.
  template <class F>
  pair<np, np> split_max_right_rec(np t, const F& check, X& x) {
    if (!t) return {nullptr, nullptr};
    X y = Monoid::op(x, t->prod);
    if (check(y)) {
      x = y;
      return {t, nullptr};
    }
    t = clone(t);  // Must precede push() when PERSISTENT=true.
    push(t);
    np l = t->l, r = t->r;
    if (l) {
      y = Monoid::op(x, l->prod);
      if (!check(y)) {
        auto [a, b] = split_max_right_rec(l, check, x);
        t->l = b;
        pull(t);
        return {a, t};
      }
      x = y;
    }
    y = Monoid::op(x, t->x);
    if (!check(y)) {
      t->l = nullptr;
      pull(t);
      return {l, t};
    }
    x = y;
    auto [a, b] = split_max_right_rec(r, check, x);
    t->r = a;
    pull(t);
    return {t, b};
  }
};
