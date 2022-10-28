#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/min_cost_matching_on_line.hpp"

void test() {
  // https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h
  vi A = {3, 1}, B = {1, 5};
  assert(min_cost_matching_on_line_1(A, B) == 2);
  A = {3, 3, 1, 1, 1}, B = {1, 2, 3, 4, 5};
  assert(min_cost_matching_on_line_1(A, B) == 6);
  A = {10, 2, 5, 6, 2, 6, 3,  2, 2,  5, 3, 11, 13, 2,
       2,  7, 7, 3, 9, 5, 13, 4, 17, 2, 2, 2,  4},
  B = {46, 3, 4, 2, 10, 2, 5, 2, 6, 7,  20, 13, 9, 49,
       3,  8, 4, 3, 19, 9, 3, 5, 4, 13, 9,  5,  7};
  assert(min_cost_matching_on_line_1(A, B) == 48);
  A = {1236501, 770807,  4003004, 131688,  1965412, 266841,
       3980782, 565060,  816313,  192940,  541896,  250801,
       217586,  3806049, 1220252, 1161079, 31168,   2008961},
  B = {3878348, 423911,  8031742, 1035156, 24256,    10344593,
       19379,   3867285, 4481365, 1475384, 1959412,  1383457,
       164869,  4633165, 6674637, 9732852, 10459147, 2810788};
  assert(min_cost_matching_on_line_1(A, B) == 6302172);
  A = {1234567891, 1}, B = {1, 99999999999};
  assert(min_cost_matching_on_line_1(A, B) == 1234567890);
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
