#include "ds/dynamic_array.hpp"

template <bool PERSISTENT, int NODES>
struct Dynamic_UnionFind {
  Dynamic_Array<int, PERSISTENT, NODES> PA;
  using np = typename decltype(PA)::np;

  Dynamic_UnionFind() : PA(-1) {}

  np new_node() { return PA.new_node(); }

  int root(np c, int x) {
    // 経路圧縮なしで
    while (1) {
      int p = PA.get(c, x);
      if (p < 0) break;
      x = p;
    }
    return x;
  }

  pair<bool, np> merge(np c, int x, int y) {
    x = root(c, x), y = root(c, y);
    if (x == y) return {false, c};
    if (-PA.get(c, x) < -PA.get(c, y)) swap(x, y);
    int new_sz = PA.get(c, x) + PA.get(c, y);
    c = PA.set(c, x, new_sz);
    c = PA.set(c, y, x);
    return {true, c};
  }

  int size(np c, int x) { return -data.get(c, root(c, x)); }
};
