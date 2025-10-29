#include "ds/piecewise_constant/piecewise_constant.hpp"

// Y_type に作用する，作用が順序を保つとする
// 区間での y の min,max をとれる
// https://codeforces.com/problemset/problem/1852/F
template <typename AS>
struct Node_Piecewise_Constant_Acted_RMQ {
  using Y_type = typename AS::S;
  using A = typename AS::A;
  using Monoid_A = typename AS::Monoid_A;
  struct S {
    ll x1, x2;  // y on [x1,x2)
    Y_type y;
    Y_type y_min, y_max;
    Border_Type c1, c2;
    S(ll x1, ll x2, Y_type y, Border_Type c1, Border_Type c2)
        : x1(x1), x2(x2), y(y), y_min(y), y_max(y), c1(c1), c2(c2) {}
    S() = default;
  };
  using value_type = S;
  using operator_type = int;
  using np = Node_Piecewise_Constant_Acted_RMQ*;

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

  void update() {
    size = 1 + lsize() + rsize();
    x.y_min = x.y, x.y_max = x.y;
    if (l) {
      x.y_min = min(x.y_min, l->x.y_min), x.y_max = max(x.y_max, l->x.y_max);
    }
    if (r) {
      x.y_min = min(x.y_min, r->x.y_min), x.y_max = max(x.y_max, r->x.y_max);
    }
  }
  void apply(const A& a) {
    x.y = AS::act(x.y, a);
    x.y_min = AS::act(x.y_min, a);
    x.y_max = AS::act(x.y_max, a);
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
