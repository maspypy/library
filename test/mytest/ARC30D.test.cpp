#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/acted_monoid/cntsum_add.hpp"
#include "ds/bbst/rbst_acted_monoid.hpp"

void test_ARC30D_case1() {
  using AM = ActedMonoid_CntSum_Add<ll>;
  const int MAX = 1000;

  const int N = 5;
  const int Q = 5;
  vi A = {1, 2, 3, 4, 5};

  vc<pi> dat(N);
  FOR(i, N) dat[i] = {1, A[i]};
  RBST_ActedMonoid<AM, true, MAX> RBST;
  auto root = RBST.new_node(dat);

  auto query_1 = [&](int L, int R, int x) -> void {
    root = RBST.apply(root, --L, R, x);
  };
  auto query_2 = [&](int a, int b, int c, int d) -> void {
    auto [xl, xm, xr] = RBST.split3(root, --a, b);
    auto [yl, ym, yr] = RBST.split3(root, --c, d);
    root = RBST.merge3(xl, ym, xr);
  };
  auto query_3 = [&](int L, int R, int ANS) -> void {
    assert(RBST.prod(root, --L, R).se == ANS);
  };

  query_3(1, 5, 15);
  query_1(1, 3, 1);
  query_3(1, 3, 9);
  query_2(1, 3, 2, 4);
  query_3(1, 5, 20);
}

void test_ARC30D_case2() {
  using AM = ActedMonoid_CntSum_Add<ll>;
  const int MAX = 1000;

  const int N = 10;
  const int Q = 30;
  vi A = {-5, -5, -2, -1, 2, -2, 0, -4, 2, 5};

  vc<pi> dat(N);
  FOR(i, N) dat[i] = {1, A[i]};
  RBST_ActedMonoid<AM, true, MAX> RBST;
  auto root = RBST.new_node(dat);

  auto query_1 = [&](int L, int R, int x) -> void {
    root = RBST.apply(root, --L, R, x);
  };
  auto query_2 = [&](int a, int b, int c, int d) -> void {
    auto [xl, xm, xr] = RBST.split3(root, --a, b);
    auto [yl, ym, yr] = RBST.split3(root, --c, d);
    root = RBST.merge3(xl, ym, xr);
  };
  auto query_3 = [&](int L, int R, int ANS) -> void {
    assert(RBST.prod(root, --L, R).se == ANS);
  };

  query_2(9, 10, 9, 10);
  query_2(3, 5, 2, 4);
  query_1(2, 10, -1);
  query_2(1, 7, 1, 7);
  query_3(1, 4, -20);

  query_2(1, 6, 2, 7);
  query_2(5, 8, 6, 9);
  query_3(4, 8, -8);
  query_3(1, 10, -18);
  query_3(9, 9, 1);

  query_1(3, 8, -1);
  query_2(4, 9, 1, 6);
  query_3(2, 7, -29);
  query_1(9, 10, -4);
  query_1(6, 9, -5);

  query_1(4, 6, -7);
  query_3(2, 5, -36);
  query_2(10, 10, 7, 7);
  query_1(3, 4, -10);
  query_3(4, 9, -78);

  query_3(8, 9, -18);
  query_2(6, 7, 8, 9);
  query_3(3, 5, -50);
  query_3(3, 9, -86);
  query_1(2, 10, -10);

  query_2(4, 6, 4, 6);
  query_2(4, 9, 5, 10);
  query_1(2, 6, 7);
  query_3(7, 8, -38);
  query_1(3, 6, 3);
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test_ARC30D_case1();
  test_ARC30D_case2();

  solve();

  return 0;
}
