#include "ds/splaytree/splaytree.hpp"

namespace SplayTreeNodes {
template <typename ActedSet>
struct Node_AS {
  using Monoid_A = typename ActedSet::Monoid_A;
  using A = typename ActedSet::A;
  using S = typename ActedSet::S;
  using value_type = S;
  using operator_type = A;
  using np = Node_AS *;

  np p, l, r;
  S x;
  A lazy;
  u32 size;
  bool rev;

  static void new_node(np n, const S &x) {
    n->p = n->l = n->r = nullptr;
    n->x = x;
    n->lazy = Monoid_A::unit();
    n->size = 1;
    n->rev = 0;
  }

  void update() {
    size = 1;
    if (l) { size += l->size; }
    if (r) { size += r->size; }
  }

  void prop() {
    if (lazy != Monoid_A::unit()) {
      if (l) {
        l->x = ActedSet::act(l->x, lazy);
        l->lazy = Monoid_A::op(l->lazy, lazy);
      }
      if (r) {
        r->x = ActedSet::act(r->x, lazy);
        r->lazy = Monoid_A::op(r->lazy, lazy);
      }
      lazy = Monoid_A::unit();
    }
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
  S get() { return x; }
  void set(const S &xx) {
    x = xx;
    update();
  }
  void apply(const A &a) {
    x = ActedSet::act(x, a);
    lazy = Monoid_A::op(lazy, a);
  }
  void reverse() {
    swap(l, r);
    rev ^= 1;
  }
};
template <typename ActedSet, int NODES>
using SplayTree_ActedSet = SplayTree<Node_AS<ActedSet>, NODES>;
} // namespace SplayTreeNodes

using SplayTreeNodes::SplayTree_ActedSet;