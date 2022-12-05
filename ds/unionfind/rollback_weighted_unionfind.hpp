#include "ds/pds/rollback_array.hpp"

template <typename Group>
struct Rollback_Weighted_UnionFind {
  using E = typename Group::value_type;
  using P = pair<int, E>;
  Rollback_Array<P> dat; // parent or size

  Rollback_Weighted_UnionFind(int n) : dat(vc<P>(n, P(-1, Group::unit()))) {}

  P get(int v) {
    // 経路圧縮はしないように
    E val = Group::unit();
    while (1) {
      auto [p, x] = dat.get(v);
      if (p < 0) { break; }
      val = Group::op(x, val);
      v = p;
    }
    return {v, val};
  }

  int time() { return dat.time(); }
  void rollback(int t) { dat.rollback(t); }

  bool merge(int a, int b, E x) {
    auto [v1, x1] = get(a);
    auto [v2, x2] = get(b);
    if (v1 == v2) return false;
    int s1 = -dat.get(v1).fi;
    int s2 = -dat.get(v2).fi;
    if (s1 < s2) {
      swap(s1, s2), swap(v1, v2), swap(x1, x2);
      x = Group::inverse(x);
    }
    // v1 <- v2
    x = Group::op(x1, x);
    x = Group::op(x, Group::inverse(x2));
    dat.set(v2, P({v1, x}));
    dat.set(v1, P({-(s1 + s2), Group::unit()}));
    return true;
  }
};
