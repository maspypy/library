#pragma once
#include "ds/node_pool.hpp"
#include "ds/weight_balanced_tree/wbt_base.hpp"
template <class X, class A>
struct WBT_Acted_Node {
  WBT_Acted_Node *l, *r;
  X x, prod, rev_prod;
  A lazy;
  u32 size;
  bool rev;
};
template <class ActedMonoid, bool PERSISTENT>
struct WBT_ActedMonoid
    : WBT_Sequence_Base<WBT_ActedMonoid<ActedMonoid, PERSISTENT>,
          WBT_Acted_Node<typename ActedMonoid::Monoid_X::value_type,
              typename ActedMonoid::Monoid_A::value_type>,
          PERSISTENT> {
  using MX = typename ActedMonoid::Monoid_X;
  using MA = typename ActedMonoid::Monoid_A;
  using X = typename MX::value_type;
  using A = typename MA::value_type;
  using Node = WBT_Acted_Node<X, A>;
  using np = Node *;
  Node_Pool<Node> pool;
  void reset() { pool.reset(); }
  np new_root() { return nullptr; }
  np new_node(const X &x) {
    np t = pool.create();
    t->l = t->r = nullptr;
    t->x = t->prod = t->rev_prod = x;
    t->lazy = MA::id();
    t->size = 1;
    t->rev = 0;
    return t;
  }
  np new_node(const vc<X> &a) {
    auto f = [&](auto &&f, u32 l, u32 r) -> np {
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
      t->prod = MX::op(t->l->prod, t->prod);
      t->rev_prod = MX::op(t->rev_prod, t->l->rev_prod);
    }
    if (t->r) {
      t->size += t->r->size;
      t->prod = MX::op(t->prod, t->r->prod);
      t->rev_prod = MX::op(t->r->rev_prod, t->rev_prod);
    }
  }
  void all_apply(np t, const A &a) {
    t->x = ActedMonoid::act(t->x, a, 1);
    t->prod = ActedMonoid::act(t->prod, a, t->size);
    t->rev_prod = ActedMonoid::act(t->rev_prod, a, t->size);
    t->lazy = MA::op(t->lazy, a);
  }
  void push(np t) {
    if (t->lazy != MA::id())
      for (np *q : {&t->l, &t->r})
        if (*q) {
          *q = clone(*q);
          all_apply(*q, t->lazy);
        }
    t->lazy = MA::id();
    if (t->rev)
      for (np *q : {&t->l, &t->r})
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
  np apply(np t, const A &a) {
    if (!t) return t;
    t = clone(t);
    all_apply(t, a);
    return t;
  }
  np apply(np t, u32 l, u32 r, const A &a) {
    auto [x, y, z] = this->split3(t, l, r);
    y = apply(y, a);
    return this->merge3(x, y, z);
  }
  np set(np t, u32 k, const X &x) {
    auto [a, b, c] = this->split3(t, k, k + 1);
    b = clone(b);
    push(b);
    b->x = x;
    pull(b);
    return this->merge3(a, b, c);
  }
  np multiply(np t, u32 k, const X &x) {
    return set(t, k, MX::op(get(t, k), x));
  }
  X prod(np t) { return t ? t->prod : MX::id(); }
  X prod(np t, u32 l, u32 r) {
    assert(l <= r && r <= t->size);
    return prod_rec(t, l, r, 0, MA::id());
  }
  X get(np t, u32 k) {
    bool z = 0;
    A a = MA::id();
    while (1) {
      np l = z ? t->r : t->l, r = z ? t->l : t->r;
      u32 s = l ? l->size : 0;
      if (k == s) return ActedMonoid::act(t->x, a, 1);
      a = MA::op(t->lazy, a);
      z ^= t->rev;
      if (k < s)
        t = l;
      else
        k -= s + 1, t = r;
    }
  }
  vc<X> get_all(np t) {
    vc<X> a;
    auto f = [&](auto &&f, np q, bool z, A b) -> void {
      if (!q) return;
      f(f, z ? q->r : q->l, z ^ q->rev, MA::op(q->lazy, b));
      a.eb(ActedMonoid::act(q->x, b, 1));
      f(f, z ? q->l : q->r, z ^ q->rev, MA::op(q->lazy, b));
    };
    f(f, t, 0, MA::id());
    return a;
  }
  template <class F>
  pair<np, np> split_max_right(np t, const F &f) {
    assert(f(MX::id()));
    X x = MX::id();
    u32 k = 0;
    for (auto &&y : get_all(t)) {
      if (!f(MX::op(x, y))) break;
      x = MX::op(x, y);
      ++k;
    }
    return this->split(t, k);
  }
  template <class F>
  pair<np, np> split_max_right_prod(np t, const F &f) {
    return split_max_right(t, f);
  }
  void free_subtree(np t) {
    if (!t) return;
    free_subtree(t->l);
    free_subtree(t->r);
    pool.destroy(t);
  }

 private:
  X prod_rec(np t, u32 l, u32 r, bool z, A a) {
    if (l == 0 && r == t->size)
      return ActedMonoid::act(z ? t->rev_prod : t->prod, a, t->size);
    np q = z ? t->r : t->l, w = z ? t->l : t->r;
    u32 s = q ? q->size : 0;
    A b = MA::op(t->lazy, a);
    X x = MX::id();
    if (l < s) x = MX::op(x, prod_rec(q, l, min(r, s), z ^ t->rev, b));
    if (l <= s && s < r) x = MX::op(x, ActedMonoid::act(t->x, a, 1));
    if (s + 1 < r)
      x = MX::op(
          x, prod_rec(w, max(l, s + 1) - s - 1, r - s - 1, z ^ t->rev, b));
    return x;
  }
};
