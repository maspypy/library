#include "string/suffix_array.hpp"

// https://qoj.ac/contest/1803/problem/9406
template <bool USE_SPARSE_TABLE>
struct Many_String_Compare {
  int n;
  string ALL;
  vc<int> pos;
  Suffix_Array<USE_SPARSE_TABLE> X;

  template <typename F>
  Many_String_Compare(int n, F f) : n(n) {
    pos = {0};
    FOR(i, n) {
      ALL += f(i);
      pos.eb(len(ALL));
    }
    X = Suffix_Array<USE_SPARSE_TABLE>(ALL);
  }

  // S[a][la:lb), S[b][lb:rb)
  int lcp(int a, int la, int ra, int b, int lb, int rb) {
    assert(0 <= a && a < n && 0 <= b && b < n);
    assert(0 <= la && la <= ra && ra <= length(a));
    assert(0 <= lb && lb <= rb && rb <= length(b));
    int n = X.lcp(pos[a] + la, pos[b] + lb);
    return min({n, ra - la, rb - lb});
  }

  // [<]-1, [=]0, [>]1
  int comp3(int a, int la, int ra, int b, int lb, int rb) {
    int na = ra - la, nb = rb - lb;
    if (na > nb) return -comp3(b, lb, rb, a, la, ra);
    int n = lcp(a, la, ra, b, lb, rb);
    if (n == na) { return (na == nb ? 0 : -1); }
    return (ALL[pos[a] + la + n] < ALL[pos[b] + lb + n] ? -1 : 1);
  }

  // [<]-1, [=]0, [>]1, (S+T) vs (T+S)
  int ST_TS_comp3(int a, int la, int ra, int b, int lb, int rb) {
    int na = ra - la, nb = rb - lb;
    if (na > nb) return -ST_TS_comp3(b, lb, rb, a, la, ra);
    int k = comp3(a, la, la + na, b, lb, lb + na);
    if (k != 0) return k;
    k = comp3(b, lb, lb + nb - na, b, lb + na, rb);
    if (k != 0) return k;
    return comp3(b, lb + nb - na, rb, a, la, ra);
  }

  // [<]-1, [=]0, [>]1, vc of {idx, l, r}
  int comp3(vc<tuple<int, int, int>> A, vc<tuple<int, int, int>> B) {
    reverse(all(A));
    reverse(all(B));
    while (1) {
      while (!A.empty()) {
        auto [i, l, r] = A.back();
        if (l < r) break;
        POP(A);
      }
      while (!B.empty()) {
        auto [i, l, r] = B.back();
        if (l < r) break;
        POP(B);
      }
      if (A.empty() && B.empty()) return 0;
      if (A.empty()) return -1;
      if (B.empty()) return 1;
      auto &[a, la, ra] = A.back();
      auto &[b, lb, rb] = B.back();
      int k = lcp(a, la, ra, b, lb, rb);
      if (k == 0) return (ALL[pos[a] + la] < ALL[pos[b] + lb] ? -1 : 1);
      la += k, lb += k;
    }
    return 0;
  }

  int length(int a) { return pos[a + 1] - pos[a]; }
};
