#include "ds/splaytree/splaytree.hpp"

namespace SplayTreeNodes {
template <typename Monoid>
struct Node_CM {
  using X = typename Monoid::value_type;
  using value_type = X;
  using operator_type = int; // 定義だけしておく
  using np = Node_CM *;

  np p, l, r;
  X x, prod;
  u32 size;
  bool rev;

  static void new_node(np n, const X &x) {
    n->p = n->l = n->r = nullptr;
    n->x = n->prod = x;
    n->size = 1;
    n->rev = 0;
  }

  void update() {
    size = 1;
    prod = x;
    if (l) {
      size += l->size;
      prod = Monoid::op(l->prod, prod);
    }
    if (r) {
      size += r->size;
      prod = Monoid::op(prod, r->prod);
    }
  }

  void prop() {
    if (rev) {
      if (l) {
        l->rev ^= 1;
        swap(l->l, l->r);
      }
      if (r) {
        r->rev ^= 1;
        swap(r->l, r->r);
      }
      rev = 0;
    }
  }

  // update, prop 以外で呼ばれるものは、splay 後であることが想定されている。
  // したがってその時点で update, prop 済であることを仮定してよい。
  X get() { return x; }
  void set(const X &xx) {
    x = xx;
    update();
  }
  void multiply(const X &xx) {
    x = Monoid::op(x, xx);
    update();
  }
  void reverse() {
    swap(l, r);
    rev ^= 1;
  }
};
template <typename Monoid, int NODES>
using SplayTree_Commutative_Monoid = SplayTree<Node_CM<Monoid>, NODES>;
} // namespace SplayTreeNodes

using SplayTreeNodes::SplayTree_Commutative_Monoid;