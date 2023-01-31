#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "linalg/xor/transpose.hpp"

template <typename UINT>
vc<UINT> naive(int n, int m, vc<UINT> mat) {
  vc<UINT> after(m);
  FOR(i, n) FOR(j, m) if (mat[i] >> j & 1) after[j] |= UINT(1) << i;
  return after;
}

void test_32() {
  FOR(100) {
    FOR(n, 33) FOR(m, 33) {
      vc<u32> A(n);
      FOR(i, n) FOR(j, m) {
        u32 x = RNG(2);
        A[i] |= x << j;
      }
      assert(transpose<u32>(n, m, A) == naive<u32>(n, m, A));
    }
  }
}

void test_64() {
  FOR(100) {
    FOR(n, 65) FOR(m, 65) {
      vc<u64> A(n);
      FOR(i, n) FOR(j, m) {
        u64 x = RNG(2);
        A[i] |= x << j;
      }
      assert(transpose<u64>(n, m, A) == naive<u64>(n, m, A));
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_32();
  solve();
  return 0;
}