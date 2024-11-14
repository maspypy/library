#include "ds/unionfind/unionfind.hpp"

// prefix add / 末尾追加 / 全体 max
// https://qoj.ac/contest/1472/problem/7905
struct Prefix_Add_Append_Get_Max {
  int n;
  UnionFind uf;
  vc<pair<int, int>> range;
  vi dat;
  ll max;
  Prefix_Add_Append_Get_Max(int max_n) : n(max_n), uf(max_n), range(max_n), max(-infty<ll>) {}

  void append(int i, ll x) {
    assert(i == len(dat) && i < n);
    range[i] = {i, i + 1};
    if (i == 0) {
      max = x;
      dat.eb(x);
      return;
    }
    if (x > max) {
      dat.eb(x - max);
      max = x;
      return;
    }
    dat.eb(0);
    merge(i);
    return;
  }

  void merge(int i) {
    int a = uf[i - 1], b = uf[i];
    assert(a != b);
    uf.merge(a, b);
    int c = uf[a];
    range[c].fi = range[a].fi, range[c].se = range[b].se;
  }

  // [0,i), +x
  void prefix_add(int i, ll x) {
    if (i == 0) return;
    assert(i <= len(dat) && x >= 0);
    dat[0] += x, max += x;
    while (x > 0) {
      auto [l, r] = range[uf[i]];
      int p = (l == i ? l : r);
      if (p == len(dat)) return;
      ll y = dat[p];
      ll z = min(x, y);
      dat[p] -= z, x -= z, max -= z;
      if (dat[p] == 0) {
        merge(p);
        continue;
      }
    }
  }

  ll get_max() { return max; }
};