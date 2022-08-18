#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/primesum.hpp"
#include "nt/primetable.hpp"

    template <typename T>
    struct PrimeSum_Mod_4 {
  ll N;
  ll sqN;

  PrimeSum<T> A, B;
  PrimeSum_Mod_4(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}

  pair<T, T> operator[](ll x) {
    T a = A[x], b = B[x];
    return {(a + b) / T(2), (a - b) / T(2)};
  }

  void calc_count() {
    A.calc([](ll x) -> T { return (x + 1) / 2; });
    B.calc([](ll x) -> T { return ((x + 3) % 4 <= 1 ? 1 : 0); });
  }

  void calc_sum() {
    A.calc([](ll x) -> T {
      ll n = (x + 1) / 2;
      return T(n) * T(n);
    });
    B.calc([](ll x) -> T {
      ll n = (x + 1) / 2;
      return (n % 2 == 0 ? T(-n) : T(n));
    });
  }
};

void test_count() {
  ll LIM = 10000;
  vc<int> A1(LIM), A3(LIM);
  for (auto&& p: primetable(LIM))
    if (p % 4 == 1) { A1[p]++; }
  for (auto&& p: primetable(LIM))
    if (p % 4 == 3) { A3[p]++; }
  A1 = cumsum(A1, 0);
  A3 = cumsum(A3, 0);

  FOR(N, LIM) {
    PrimeSum_Mod_4<int> X(N);
    X.calc_count();
    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A3[N / K])); }
  }
}

void test_sum() {
  ll LIM = 10000;
  vc<int> A1(LIM), A3(LIM);
  for (auto&& p: primetable(LIM))
    if (p % 4 == 1) { A1[p] += p; }
  for (auto&& p: primetable(LIM))
    if (p % 4 == 3) { A3[p] += p; }
  A1 = cumsum(A1, 0);
  A3 = cumsum(A3, 0);

  FOR(N, LIM) {
    PrimeSum_Mod_4<int> X(N);
    X.calc_sum();
    FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A3[N / K])); }
  }
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
