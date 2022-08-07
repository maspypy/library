#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/random.hpp"

#include "mod/modint.hpp"
#include "mod/all_inverse.hpp"

void test() {
  using mint = modint998;
  vc<int> ns = {1, 2, 3, 4, 5, 100000};

  RandomNumberGenerator RNG;
  for (auto&& N: ns) {
    vc<mint> X(N);
    FOR(i, N) { X[i] = RNG(1, mint::get_mod()); }
    auto Y = all_inverse(X);
    FOR(i, N) assert(X[i] * Y[i] == mint(1));
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
