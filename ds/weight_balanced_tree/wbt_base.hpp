#pragma once

// Adams' weight balanced trees (JFP 1993), with weight(t)=size(t)+1,
// DELTA=3 and RATIO=2.  All rebalancing is done by join(L,x,R).
template <class Derived, class Node, bool PERSISTENT>
struct WBT_Sequence_Base {
  using np = Node*;
  static constexpr u32 DELTA = 3, RATIO = 2;

 protected:
  Derived& self() { return static_cast<Derived&>(*this); }
  u32 sz(np t) const { return t ? t->size : 0; }
  u64 wt(np t) const { return u64(sz(t)) + 1; }

  np join(np l, np x, np r) {
    assert(x && !x->l && !x->r);
    if (u64(DELTA) * wt(l) < wt(r)) {
      r = self().clone(r);
      self().push(r);
      r->l = join(l, x, r->l);
      self().pull(r);
      return balance(r);
    }
    if (u64(DELTA) * wt(r) < wt(l)) {
      l = self().clone(l);
      self().push(l);
      l->r = join(l->r, x, r);
      self().pull(l);
      return balance(l);
    }
    x->l = l, x->r = r;
    self().pull(x);
    return x;
  }

  np balance(np t) {
    if (u64(DELTA) * wt(t->r) < wt(t->l)) return rotate_right(t);
    if (u64(DELTA) * wt(t->l) < wt(t->r)) return rotate_left(t);
    return t;
  }

  np rotate_right(np t) {
    np l = self().clone(t->l);
    self().push(l);
    if (wt(l->r) < u64(RATIO) * wt(l->l)) {
      t->l = l->r;
      l->r = t;
      self().pull(t), self().pull(l);
      return l;
    }
    np m = self().clone(l->r);
    self().push(m);
    l->r = m->l, t->l = m->r;
    m->l = l, m->r = t;
    self().pull(l), self().pull(t), self().pull(m);
    return m;
  }

  np rotate_left(np t) {
    np r = self().clone(t->r);
    self().push(r);
    if (wt(r->l) < u64(RATIO) * wt(r->r)) {
      t->r = r->l;
      r->l = t;
      self().pull(t), self().pull(r);
      return r;
    }
    np m = self().clone(r->l);
    self().push(m);
    r->l = m->r, t->r = m->l;
    m->r = r, m->l = t;
    self().pull(t), self().pull(r), self().pull(m);
    return m;
  }

  pair<np, np> extract_min(np t) {
    t = self().clone(t);
    self().push(t);
    if (!t->l) {
      np rest = t->r;
      t->r = nullptr;
      self().pull(t);
      return {t, rest};
    }
    auto [x, nl] = extract_min(t->l);
    np r = t->r;
    t->l = t->r = nullptr;
    self().pull(t);
    return {x, join(nl, t, r)};
  }

 public:
  np merge(np a, np b) {
    if (!a) return b;
    if (!b) return a;
    auto [x, b1] = extract_min(b);
    return join(a, x, b1);
  }
  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }
  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d); }

  pair<np, np> split(np t, u32 k) {
    assert(k <= sz(t));
    if (!t) return {nullptr, nullptr};
    t = self().clone(t);
    self().push(t);
    u32 sl = sz(t->l);
    np l = t->l, r = t->r;
    t->l = t->r = nullptr;
    self().pull(t);
    if (k <= sl) {
      auto [a, b] = split(l, k);
      return {a, join(b, t, r)};
    }
    auto [a, b] = split(r, k - sl - 1);
    return {join(l, t, a), b};
  }
  tuple<np, np, np> split3(np t, u32 l, u32 r) {
    assert(l <= r && r <= sz(t));
    auto [a, bc] = split(t, l);
    auto [b, c] = split(bc, r - l);
    return {a, b, c};
  }
  tuple<np, np, np, np> split4(np t, u32 i, u32 j, u32 k) {
    auto [a, bcd] = split(t, i);
    auto [b, cd] = split(bcd, j - i);
    auto [c, d] = split(cd, k - j);
    return {a, b, c, d};
  }
};
