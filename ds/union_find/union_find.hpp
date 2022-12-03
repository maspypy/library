#pragma once

struct Union_Find {
  int n;
  int n_comp;
  vector<int> dat; // par or (-size)
  Union_Find(int n) : n(n), n_comp(n), dat(n, -1) {}

  int operator[](int x) {
    while (dat[x] >= 0) {
      int pp = dat[dat[x]];
      if (pp < 0) { return dat[x]; }
      x = dat[x] = pp;
    }
    return x;
  }

  int size(int x) {
    assert(dat[x] < 0);
    return -dat[x];
  }

  bool merge(int x, int y) {
    x = (*this)[x];
    y = (*this)[y];
    if (x == y) { return false; }
    n_comp--;
    if (-dat[x] < -dat[y]) swap(x, y);
    dat[x] += dat[y], dat[y] = x;
    return true;
  }

  vector<int> get_all() {
    vector<int> A(n);
    for (int i = 0; i < n; ++i) A[i] = (*this)[i];
    return A;
  }
};
