#pragma once

struct UnionFind {
  int n;
  int comp;
  std::vector<int> size, par;
  UnionFind(int n) : n(n), comp(n), size(n, 1), par(n) {
    std::iota(par.begin(), par.end(), 0);
  }
  int find(int x) {
    assert(0 <= x && x < n);
    while (par[x] != x) {
      par[x] = par[par[x]];
      x = par[x];
    }
    return x;
  }

  int operator[](int x) { return find(x); }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) { return false; }
    comp--;
    if (size[x] < size[y]) std::swap(x, y);
    size[x] += size[y];
    size[y] = 0;
    par[y] = x;
    return true;
  }

  std::vector<int> find_all() {
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) A[i] = find(i);
    return A;
  }

  void reset() {
    comp = n;
    size.assign(n, 1);
    std::iota(par.begin(), par.end(), 0);
  }
};
