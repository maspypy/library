#include "ds/splaytree/splaytree.hpp"

namespace SplayTreeNodes {
template <typename ActedMonoid>
struct Node_AM {
  using Monoid_A = typename ActedMonoid::Monoid_A;
  using Monoid_X = typename ActedMonoid::Monoid_X;
  using A = typename Monoid_A::value_type;
  using X = typename Monoid_X::value_type;
  using value_type = X;
  using operator_type = A;
  using np = Node_AM *;

  np p, l, r;
  X x, prod;
  A lazy;
  u32 size;
  bool rev;

  static void new_node(np n, const X &x) {
    n->p = n->l = n->r = nullptr;
    n->x = n->prod = x;
    n->lazy = Monoid_A::unit();
    n->size = 1;
    n->rev = 0;
  }

  void update() {
    size = 1;
    prod = x;
    if (l) {
      size += l->size;
      prod = Monoid_X::op(l->prod, prod);
    }
    if (r) {
      size += r->size;
      prod = Monoid_X::op(prod, r->prod);
    }
  }

  void prop() {
    if (lazy != Monoid_A::unit()) {
      if (l) { l->apply(lazy); }
      if (r) { r->apply(lazy); }
      lazy = Monoid_A::unit();
    }
    if (rev) {
      if (l) { l->reverse(); }
      if (r) { r->reverse(); }
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
    x = Monoid_X::op(x, xx);
    update();
  }
  void apply(const A &a) {
    x = ActedMonoid::act(x, a, 1);
    prod = ActedMonoid::act(prod, a, size);
    lazy = Monoid_A::op(lazy, a);
  }
  void reverse() {
    swap(l, r);
    rev ^= 1;
  }
};
template <typename ActedMonoid, int NODES>
using SplayTree_ActedMonoid = SplayTree<Node_AM<ActedMonoid>, NODES>;
} // namespace SplayTreeNodes

using SplayTreeNodes::SplayTree_ActedMonoid;