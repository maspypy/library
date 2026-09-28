#include "ds/unionfind/unionfind.hpp"

// amortized linear
// MoFR なしだと FastSet より遅かった
struct Decremental_FastSet {
  struct Decremental_Neighbor_UF {
    int n;
    UnionFind uf;
    vc<int> L, R;
    Decremental_Neighbor_UF(int n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {
      FOR(i, n + 2) L[i] = i, R[i] = i;
    }
    void erase(int i) {
      assert(0 <= i && i < n);
      ++i;
      int l = L[uf[i - 1]], r = R[uf[i]];
      uf.merge(i, i - 1);
      L[uf[i]] = l, R[uf[i]] = r;
    }
    int prev(int i) {
      assert(-1 <= i);
      chmin(i, n - 1);
      return L[uf[i + 1]] - 1;
    }
    int next(int i) {
      assert(i <= n);
      chmax(i, 0);
      return R[uf[i]];
    }
  };
  int N, n;
  vc<u64> dat;
  Decremental_Neighbor_UF X;
  Decremental_FastSet(int N) : N(N), n((N + 63) / 64), X(n) {
    dat.assign(n, u64(-1));
    if (n) dat.back() = u64(-1) >> (64 * n - N);
  }

  bool operator[](int i) { return (dat[i / 64] >> (i & 63) & 1); }

  void erase(int i) {
    int a = i / 64, b = i & 63;
    if (!(dat[a] >> b & 1)) return;
    dat[a] &= ~(u64(1) << b);
    if (dat[a] == 0) {
      X.erase(a);
    }
  }
  int prev(int i) {
    assert(-1 <= i);
    chmin(i, N - 1);
    if (i == -1) return -1;
    int a = i / 64, b = i & 63;
    u64 x = dat[a] & (u64(-1) >> (63 - b));
    if (x != 0) return 64 * a + topbit(x);
    a = X.prev(a - 1);
    return (a == -1 ? -1 : 64 * a + topbit(dat[a]));
  }
  int next(int i) {
    assert(i <= N);
    chmax(i, 0);
    if (i == N) return N;
    int a = i / 64, b = i & 63;
    u64 x = dat[a] >> b;
    if (x != 0) return 64 * a + b + lowbit(x);
    a = X.next(a + 1);
    return (a == n ? N : 64 * a + lowbit(dat[a]));
  }

  // [l, r)
  template <typename F>
  void enumerate(int l, int r, F&& f) {
    for (int x = next(l); x < r; x = next(x + 1)) f(x);
  }

  string to_string() {
    string S(N, '.');
    FOR(i, N) S[i] = '0' + (dat[i / 64] >> (i & 63) & 1);
    return S;
  }
};
