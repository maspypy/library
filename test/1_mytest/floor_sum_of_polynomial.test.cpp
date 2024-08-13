#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "mod/floor_sum_of_linear_polynomial.hpp"

using mint = modint998;

template <int K>
void test() {
  FOR(M, 1, 20) {
    FOR(a, 20) {
      FOR(b, 20) {
        array<mint, K + 1> dp{};
        FOR(N, 20) {
          array<mint, K + 1> ans
              = floor_sum_of_linear_polynomial<mint, K, u64>(N, a, b, M);
          // print(dp);
          // print(ans);
          assert(dp == ans);
          mint y = floor(a * N + b, M);
          FOR(k, K + 1) dp[k] += y * mint(N).pow(k);
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
  test<0>();
  test<1>();
  test<2>();
  test<10>();
  solve();
  return 0;
}