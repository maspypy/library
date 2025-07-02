#include "ds/my_bitset.hpp"
#include "nt/lpf_table.hpp"
#include "nt/factor.hpp"

// A[i] と互いに素な A[j] を検出 / A[i] の削除
// N=1e5,A=1e7 連結成分分解 1030ms
// https://codeforces.com/contest/1148/problem/G
template <int thresh = 200>
struct Find_Coprime_Pair {
  // thresh 以上ある素数を bitset 管理
  using BS = My_Bitset;
  int N;
  vc<int> A;
  vc<int> lpf;
  vc<int> S;
  vc<int> ptr;
  vc<int> bidx;
  vc<BS> dat;
  BS remain;
  // 20 以下の素数の積
  const int prod = 9699690;

  Find_Coprime_Pair(vc<int> A) : A(A) {
    N = len(A);
    int ma = MAX(A);
    lpf = lpf_table(ma);
    vc<int> ptr1(ma + 1);
    vc<int> ids(N);
    for (auto& x : A) ptr1[x]++;
    ptr1 = cumsum<int>(ptr1);
    FOR(i, N) { ids[ptr1[A[i]]++] = i; }
    FOR_R(i, len(ptr1) - 1) ptr1[i + 1] = ptr1[i];

    ptr.resize(ma + 2);
    FOR(p, 23, ma + 1) {
      if (lpf[p] != p) continue;
      ptr[p] = len(S);
      for (int n = p; n <= ma; n += p) {
        FOR(k, ptr1[n], ptr1[n + 1]) S.eb(ids[k]);
      }
      ptr[p + 1] = len(S);
    }

    bidx.assign(ma + 1, -1);
    {
      vc<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};
      vc<BS> tmp(1 << 8);
      tmp[0] = BS(N, 1);
      FOR(i, 8) {
        BS bs(N, 1);
        FOR(j, N) if (A[j] % prime[i] == 0) bs[j] = 0;
        FOR(s, 1 << i) tmp[s | 1 << i] = tmp[s] & bs;
      }
      FOR(s, 1 << 8) {
        int prd = 1;
        FOR(i, 8) if (s >> i & 1) prd *= prime[i];
        if (prd <= ma) {
          bidx[prd] = len(dat);
          dat.eb(tmp[s]);
        }
      }
    }

    FOR(p, 23, ma + 1) {
      if (lpf[p] != p) continue;
      int cnt = ptr[p + 1] - ptr[p];
      if (cnt < thresh) continue;
      BS bs(N, 1);
      FOR(i, ptr[p], ptr[p + 1]) bs[S[i]] = 0;
      bidx[p] = len(dat);
      dat.eb(bs);
    }
    remain = BS(N, 1);
  }

  void remove(int i) { remain[i] = 0; }

  // 自分自身は除いて
  template <typename F>
  void enumerate_all(int i, F f) {
    int d = gcd(A[i], prod);
    BS x = remain & dat[bidx[d]];
    for (auto& [p, e] : factor_by_lpf(A[i], lpf)) {
      if (p < 20) continue;
      if (bidx[p] == -1) {
        FOR(k, ptr[p], ptr[p + 1]) { x[S[k]] = 0; }
      } else {
        x &= dat[bidx[p]];
      }
    }
    x.enumerate(0, N, f);
  }
};
