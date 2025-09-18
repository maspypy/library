#include "ds/piecewise_constant/piecewise_constant.hpp"

// https://codeforces.com/contest/1023/problem/G
template <typename AS>
struct Node_Piecewise_Constant_Acted {
  using Y_type = typename AS::S;
  using A = typename AS::A;
  using Monoid_A = typename AS::Monoid_A;
  struct S {
    ll x1, x2;  // y on [x1,x2)
    Y_type y;
    Border_Type c1, c2;
  };
  using value_type = S;
  using operator_type = int;
  using np = Node_Piecewise_Constant_Acted*;

  np p, l, r;
  bool rev;
  S x;
  A lazy;
  u32 size;
  ll& x1() { return x.x1; }
  ll& x2() { return x.x2; }
  Border_Type& c1() { return x.c1; }
  Border_Type& c2() { return x.c2; }
  Y_type& y() { return x.y; }

  int lsize() { return (l ? l->size : 0); }
  int rsize() { return (r ? r->size : 0); }

  static void new_node(np n, const S& x) {
    n->p = n->l = n->r = nullptr;
    n->x = x, n->size = 1, n->rev = 0;
  }

  void update() { size = 1 + lsize() + rsize(); }
  void apply(const A& a) {
    x.y = AS::act(x.y, a);
    lazy = AS::Monoid_A::op(lazy, a);
  }
  void push() {
    if (lazy != Monoid_A::unit()) {
      if (l) {
        l->apply(lazy);
      }
      if (r) {
        r->apply(lazy);
      }
      lazy = Monoid_A::unit();
    }
    if (rev) {
      if (l) {
        l->rev ^= 1, swap(l->l, l->r);
      }
      if (r) {
        r->rev ^= 1, swap(r->l, r->r);
      }
      rev = 0;
    }
  }

  // update, push 以外で呼ばれるものは、splay 後であることが想定されている。
  // したがってその時点で update, push 済であることを仮定してよい。
  S get() { return x; }
  void set(const S& xx) {
    x = xx;
    update();
  }
  void reverse() {
    swap(l, r);
    rev ^= 1;
  }
};
