#include "ds/splay/splaytree.hpp"

namespace SplayTreeNodes {
template <typename Monoid>
struct Node_Monoid {
  using X = typename Monoid::value_type;
  using value_type = X;
  using operator_type = int; // 定義だけしておく
  using np = Node_Monoid *;

  np p, l, r;
  X x, prod, rev_prod;
  u32 size;
  bool rev;

  static void new_node(np n, const X &x) {
    n->p = n->l = n->r = nullptr;
    n->x = n->prod = n->rev_prod = x;
    n->size = 1;
    n->rev = 0;
  }

  void update() {
    size = 1;
    prod = rev_prod = x;
    if (l) {
      size += l->size;
      prod = Monoid::op(l->prod, prod);
      rev_prod = Monoid::op(rev_prod, l->rev_prod);
    }
    if (r) {
      size += r->size;
      prod = Monoid::op(prod, r->prod);
      rev_prod = Monoid::op(r->rev_prod, rev_prod);
    }
  }

  void prop() {
    if (rev) {
      if (l) {
        l->rev ^= 1;
        swap(l->l, l->r);
        swap(l->prod, l->rev_prod);
      }
      if (r) {
        r->rev ^= 1;
        swap(r->l, r->r);
        swap(r->prod, r->rev_prod);
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
    swap(prod, rev_prod);
    swap(l, r);
    rev ^= 1;
  }
};
template <typename Monoid, int NODES>
using SplayTree_Monoid = SplayTree<Node_Monoid<Monoid>, NODES>;
} // namespace SplayTreeNodes

using SplayTreeNodes::SplayTree_Monoid;