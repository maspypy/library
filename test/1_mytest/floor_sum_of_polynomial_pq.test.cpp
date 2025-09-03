#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "mod/floor_sum_of_linear_polynomial_pq.hpp"

using mint = modint998;

template <int K1, int K2>
void test_1() {
  FOR(p, 1, 4) FOR(q, 1, 4) {
    FOR(M, 1, 5) {
      FOR(a, 10) FOR(b, 10) {
        array<array<mint, K2 + 1>, K1 + 1> dp{};
        FOR(N, 10) {
          array<array<mint, K2 + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial_nonnegative_pq<mint, K1, K2, u64>(p, q, N, a, b, M);
          assert(dp == ans);
          ll y = floor(a * N + b, M);
          FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] += mint(p).pow(N) * mint(q).pow(y) * mint(N).pow(i) * mint(y).pow(j);
        }
      }
    }
  }
}

template <int K1, int K2>
void test_2() {
  FOR(p, 1, 4) FOR(q, 1, 4) {
    FOR(M, 1, 5) {
      FOR(a, -5, 6) FOR(b, -5, 6) {
        FOR(L, -5, 6) {
          array<array<mint, K2 + 1>, K1 + 1> dp{};
          FOR(R, L, 6) {
            array<array<mint, K2 + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial_pq<mint, K1, K2, ll>(p, q, L, R, a, b, M);
            assert(dp == ans);
            ll y = floor(a * R + b, M);
            FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] += mint(p).pow(R) * mint(q).pow(y) * mint(R).pow(i) * mint(y).pow(j);
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
  test_1<4, 4>();

  test_2<0, 0>();
  test_2<0, 1>();
  test_2<0, 2>();
  test_2<1, 0>();
  test_2<1, 1>();
  test_2<1, 2>();
  test_2<2, 0>();
  test_2<2, 1>();
  test_2<2, 2>();
  test_2<4, 4>();

  solve();
  return 0;
}