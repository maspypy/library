#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "mod/floor_sum_of_linear_polynomial.hpp"

using mint = modint998;

template <int K1, int K2>
void test_1() {
  FOR(M, 1, 10) {
    FOR(a, 10) {
      FOR(b, 10) {
        array<array<mint, K2 + 1>, K1 + 1> dp{};
        FOR(N, 10) {
          array<array<mint, K2 + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial_nonnegative<mint, K1, K2, u64>(N, a, b, M);
          assert(dp == ans);
          mint y = floor(a * N + b, M);
          FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] += mint(N).pow(i) * y.pow(j);
        }
      }
    }
  }
}

template <int K1, int K2>
void test_2() {
  FOR(M, 1, 10) {
    FOR(a, -5, 6) {
      FOR(b, -5, 6) {
        FOR(L, -5, 6) {
          array<array<mint, K2 + 1>, K1 + 1> dp{};
          FOR(R, L, 6) {
            array<array<mint, K2 + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial<mint, K1, K2, ll>(L, R, a, b, M);
            assert(dp == ans);
            mint y = floor(a * R + b, M);
            FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] += mint(R).pow(i) * y.pow(j);
          }
        }
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_1<0, 0>();
  test_1<0, 1>();
  test_1<0, 2>();
  test_1<1, 0>();
  test_1<1, 1>();
  test_1<1, 2>();
  test_1<2, 0>();
  test_1<2, 1>();
  test_1<2, 2>();
  test_1<10, 10>();

  test_2<0, 0>();
  test_2<0, 1>();
  test_2<0, 2>();
  test_2<1, 0>();
  test_2<1, 1>();
  test_2<1, 2>();
  test_2<2, 0>();
  test_2<2, 1>();
  test_2<2, 2>();
  test_2<10, 10>();

  solve();
  return 0;
}