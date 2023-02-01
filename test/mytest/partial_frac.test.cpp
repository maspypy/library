#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "poly/sum_of_rationals.hpp"
#include "poly/partial_frac_decomposition.hpp"

using mint = modint998;
using poly = vc<mint>;

vc<mint> gen(int n) {
  vc<mint> f(n);
  set<mint> ss;
  FOR(i, n) {
    while (1) {
      mint x = RNG(-100, 100);
      if (ss.count(x)) continue;
      ss.insert(x);
      f[i] = x;
      break;
    }
  }
  return f;
}

void check(poly f, vc<mint> A) {
  int m = len(A);
  auto B = partial_frac_decomposition<mint>(f, A);
  assert(len(B) == m);
  vc<pair<poly, poly>> dat;
  FOR(i, m) {
    poly F = {B[i]};
    poly G = {-A[i], mint(1)};
    dat.eb(F, G);
  }
  auto [p, q] = sum_of_rationals<mint>(dat);
  while (len(p) && p.back() == mint(0)) p.pop_back();
  while (len(f) && f.back() == mint(0)) f.pop_back();
  assert(p == f);
}

void test() {
  FOR(n, 50) FOR(m, n, 50) {
    poly f = gen(n), A = gen(m);
    check(f, A);
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