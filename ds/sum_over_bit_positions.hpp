#include "ds/my_bitset.hpp"

// https://qoj.ac/contest/1784/problem/9244
// sum bitset[i]*wt[i]
// T は 11bit sum がおさまれば ok
// (N=Q=100000:0.9 sec)
template <typename T, int MAXSIZE>
struct Sum_Over_Bit_Positions {
  int N;
  vc<T> base;
  static T table[MAXSIZE / 64 * 6 + 10][1 << 11];

  template <typename F>
  Sum_Over_Bit_Positions(int N, F f) : N(N) {
    base.resize(N);
    assert(0 <= N && N <= MAXSIZE);
    int NB = (N + 63) / 64;
    FOR(block, NB) {
      FOR(k, 6) {
        int b = 6 * block + k;
        FOR(i, 11) {
          int idx = 64 * block + 11 * k + i;
          T x = 0;
          if ((k < 5 || i < 9) && idx < N) x = base[idx] = f(idx);
          FOR(s, 1 << i) { table[b][s | 1 << i] = table[b][s] + x; }
        }
      }
    }
  }

  // bitset の [l,r) 部分
  template <typename SUM_TYPE>
  SUM_TYPE query(My_Bitset &x, int l, int r) {
    SUM_TYPE ANS = 0;
    while (l < r && (l & 63)) {
      if (x[l]) ANS += base[l];
      l++;
    }
    while (l < r && (r & 63)) {
      --r;
      if (x[r]) ANS += base[r];
    }
    if (l == r) return ANS;
    l /= 64, r /= 64;
    FOR(b, l, r) {
      u64 s = x.dat[b];
      ANS += table[b * 6 + 0][s >> 0 & 2047];
      ANS += table[b * 6 + 1][s >> 11 & 2047];
      ANS += table[b * 6 + 2][s >> 22 & 2047];
      ANS += table[b * 6 + 3][s >> 33 & 2047];
      ANS += table[b * 6 + 4][s >> 44 & 2047];
      ANS += table[b * 6 + 5][s >> 55 & 2047];
    }
    return ANS;
  }
};
template <typename T, int MAXSIZE>
T Sum_Over_Bit_Positions<T, MAXSIZE>::table[MAXSIZE / 64 * 6 + 10][1 << 11];
