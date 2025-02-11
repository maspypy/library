#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "seq/geometric_sequence_sum_formula.hpp"

using mint = modint998;

void test(int K) {
  FOR(r, 1000) {
    if (r == 1) continue;
    auto [c, f] = geometic_sequence_sum_formula<mint>(r, K);
    mint god = 0;
    FOR(N, 1000) {
      mint ans = 0;
      FOR(i, len(f)) ans += f[i] * mint(N).pow(i);
      ans *= mint(r).pow(N);
      ans += c;
      assert(god == ans);
      god += mint(r).pow(N) * mint(N).pow(K);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(K, 10) test(K);
  solve();
}