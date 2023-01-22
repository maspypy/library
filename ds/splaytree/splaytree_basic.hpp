#include "ds/splaytree/splaytree.hpp"

namespace SplayTreeNodes {
template <typename S>
struct Node_Basic {
  using value_type = S;
  using operator_type = int;
  using np = Node_Basic *;

  np p, l, r;
  S x;
  u32 size;

  static void new_node(np n, const S &x) {
    n->p = n->l = n->r = nullptr;
    n->x = x;
    n->size = 1;
  }

  void update() {
    size = 1;
    if (l) { size += l->size; }
    if (r) { size += r->size; }
  }

  void prop() {}

  // update, prop 以外で呼ばれるものは、splay 後であることが想定されている。
  // したがってその時点で update, prop 済であることを仮定してよい。
  S get() { return x; }
  void set(const S &xx) {
    x = xx;
    update();
  }
};
template <typename S, int NODES>
using SplayTree_Basic = SplayTree<Node_Basic<S>, NODES>;
} // namespace SplayTreeNodes

using SplayTreeNodes::SplayTree_Basic;
