#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "nt/coprime_factorization.hpp"

void test() {
  FOR(N, 0, 100) {
    vc<ll> dat(N);
    FOR(i, N) dat[i] = RNG(1, infty<ll>);
    auto [basis, pfs] = coprime_factorization(dat);
    FOR(j, N) FOR(i, j) { assert(gcd(basis[i], basis[j]) == 1); }
    FOR(i, N) {
      ll x = 1;
      for (auto&& [pid, exp]: pfs[i]) { FOR(exp) x *= basis[pid]; }
      assert(x == dat[i]);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}
