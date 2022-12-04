#include "ds/persistent_array.hpp"

struct Persistent_UnionFind {
  using PA = Persistent_Array<int>;
  int n;
  PA data; // root OR (-size)
  using np = PA::np;

  Persistent_UnionFind(int n) : n(n) {}
  np init() {
    np t = data.get_root();
    FOR(i, n) data.destructive_set(t, i, -1);
    return t;
  }

  pair<bool, np> merge(np t, int x, int y) {
    x = root(t, x), y = root(t, y);
    if (x == y) return {0, t};
    if (data.get(t, x) > data.get(t, y)) swap(x, y);
    int new_sz = data.get(t, x) + data.get(t, y);
    np set_x_sz = data.set(t, x, new_sz);
    np set_y_par = data.set(set_x_sz, y, x);
    return {1, set_y_par};
  }

  int root(np t, int x) {
    int par_or_sz = data.get(t, x);
    if (par_or_sz < 0) return x;
    return root(t, par_or_sz);
  }

  bool same(np t, int x, int y) { return root(t, x) == root(t, y); }
  int size(np t, int x) { return -data.get(t, root(t, x)); }
};
