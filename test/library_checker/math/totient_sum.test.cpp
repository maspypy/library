#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/primesum.hpp"
#include "nt/multiplicative_sum.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  PrimeSum<mint> A(N), B(N);
  A.calc_sum();
  B.calc_count();

  auto f_pe = [&](ll p, ll e) -> mint {
    mint x = p - 1;
    FOR(e - 1) x *= mint(p);
    return x;
  };
  auto f_psum = [&](ll x) -> mint { return A[x] - B[x]; };
  print(multiplicative_sum<mint>(N, f_pe, f_psum));
}

signed main() {
  solve();

  return 0;
}
