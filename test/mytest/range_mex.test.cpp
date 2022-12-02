#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"

#include "ds/offline_query/range_mex_query.hpp"

pair<vc<int>, vc<pi>> gen(int N, int LIM, int Q) {
  vc<int> A(N);
  FOR(i, N) { A[i] = RNG(0, LIM); }
  vc<pi> query;
  FOR(q, Q) {
    int l = RNG(0, N);
    int r = RNG(l, N + 1);
    query.eb(l, r);
  }
  return {A, query};
}

vc<int> naive(vc<int> A, vc<pi> query, int begin) {
  vc<int> ANS;
  for (auto&& [l, r]: query) {
    int mex = begin;
    while (1) {
      bool ok = 1;
      FOR(i, l, r) if (A[i] == mex) ok = 0;
      if (ok) break;
      ++mex;
    }
    ANS.eb(mex);
  }
  return ANS;
}

void test_0() {
  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q, 1, 20) {
    auto [A, query] = gen(N, LIM, Q);
    RangeMexQuery<0, int> X(A);
    for (auto&& [l, r]: query) X.add(l, r);
    assert(naive(A, query, 0) == X.calc());
  }
}

void test_1() {
  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q, 1, 20) {
    auto [A, query] = gen(N, LIM, Q);
    for (auto&& x: A) ++x;
    RangeMexQuery<1, int> X(A);
    for (auto&& [l, r]: query) X.add(l, r);
    assert(naive(A, query, 1) == X.calc());
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test_0();
  test_1();
  solve();

  return 0;
}
