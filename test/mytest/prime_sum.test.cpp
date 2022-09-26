#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/primesum.hpp"
#include "nt/primetable.hpp"
#include "mod/modint.hpp"

void test_count() {
  vc<int> A(1000);
  for (auto&& p: primetable(1000)) { A[p]++; }
  A = cumsum<int>(A, 0);

  FOR(N, 1000) {
    PrimeSum<int> X(N);
    X.calc_count();
    FOR(K, 1, N + 10) { assert(X[N / K] == A[N / K]); }
  }

  vc<ll> TEN(13);
  TEN[0] = 1;
  FOR(i, 12) TEN[i + 1] = TEN[i] * 10;

  ll N = TEN[12];
  PrimeSum<ll> X(N);
  X.calc_count();
  assert(X[TEN[0]] == 0);
  assert(X[TEN[1]] == 4);
  assert(X[TEN[2]] == 25);
  assert(X[TEN[3]] == 168);
  assert(X[TEN[4]] == 1229);
  assert(X[TEN[5]] == 9592);
  assert(X[TEN[6]] == 78498);
  assert(X[TEN[7]] == 664579);
  assert(X[TEN[8]] == 5761455);
  assert(X[TEN[9]] == 50847534);
  assert(X[TEN[10]] == 455052511);
  assert(X[TEN[11]] == 4118054813);
  assert(X[TEN[12]] == 37607912018);
}

void test_sum() {
  vc<int> A(1000);
  for (auto&& p: primetable(1000)) { A[p] += p; }
  A = cumsum<int>(A, 0);

  FOR(N, 1000) {
    PrimeSum<int> X(N);
    X.calc_sum();
    FOR(K, 1, N + 10) { assert(X[N / K] == A[N / K]); }
  }

  vc<ll> TEN(13);
  TEN[0] = 1;
  FOR(i, 12) TEN[i + 1] = TEN[i] * 10;

  using mint = modint998;
  ll N = TEN[12];
  PrimeSum<mint> X(N);
  X.calc_sum();

  auto f = [&](string S) -> mint {
    mint x = 0;
    for (auto&& s: S) { x = x * mint(10) + mint(s - '0'); }
    return x;
  };

  assert(X[TEN[0]] == f("0"));
  assert(X[TEN[1]] == f("17"));
  assert(X[TEN[2]] == f("1060"));
  assert(X[TEN[3]] == f("76127"));
  assert(X[TEN[4]] == f("5736396"));
  assert(X[TEN[5]] == f("454396537"));
  assert(X[TEN[6]] == f("37550402023"));
  assert(X[TEN[7]] == f("3203324994356"));
  assert(X[TEN[8]] == f("279209790387276"));
  assert(X[TEN[9]] == f("24739512092254535"));
  assert(X[TEN[10]] == f("2220822432581729238"));
  assert(X[TEN[11]] == f("201467077743744681014"));
  assert(X[TEN[12]] == f("18435588552550705911377"));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test_count();
  test_sum();
  solve();

  return 0;
}
