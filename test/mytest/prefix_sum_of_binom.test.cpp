#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "mod/prefix_sum_of_binom.hpp"

using mint = modint998;

void test() {
  FOR(LIM, 0, 500) {
    Prefix_Sum_Of_Binom<mint> X(LIM);
    FOR(N, LIM + 1) {
      mint sm = 0;
      FOR(k, N + 10) {
        assert(sm == X.query(N, k));
        sm += C<mint>(N, k);
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
  test();
  solve();
  return 0;
}
