#include "ds/piecewise_constant/piecewise_constant.hpp"

namespace SplayTreeNodes {
template <typename Y>
struct Node_Piecewise_Constant_Basic {
  struct S {
    ll x1, x2;  // y on [x1,x2)
    Y y;
    Border_Type c1, c2;
  };
  using value_type = S;
  using operator_type = int;
  using Y_type = Y;
  using np = Node_Piecewise_Constant_Basic*;

  np p, l, r;
  bool rev;
  S x;
  u32 size;
  ll& x1() { return x.x1; }
  ll& x2() { return x.x2; }
  Border_Type& c1() { return x.c1; }
  Border_Type& c2() { return x.c2; }
  Y& y() { return x.y; }

  int lsize() { return (l ? l->size : 0); }
  int rsize() { return (r ? r->size : 0); }

  static void new_node(np n, const S& x) {
    n->p = n->l = n->r = nullptr;
    n->x = x, n->size = 1, n->rev = 0;
  }

  void update() { size = 1 + lsize() + rsize(); }

  void push() {
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
template <typename Y>
using Piecewise_Constant_Basic =
    Piecewise_Constant<Node_Piecewise_Constant_Basic<Y>>;
}  // namespace SplayTreeNodes

using SplayTreeNodes::Piecewise_Constant_Basic;
