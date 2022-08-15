#include "mod/min_of_linear_segments.hpp"

/*
ax + b (x>=0) が最小となるところの情報を返す。
prefix max を更新する x 全体が、等差数列の和集合。次を返す。
・等差数列の境界となる x_0, x_1, ..., x_n
・各境界の間での交差 dx_0, ..., dx_{n-1}
*/
pair<vc<int>, vc<int>> max_of_linear_segments(int a, int b, int mod) {
  a = (a == 0 ? 0 : mod - a);
  b = mod - 1 - b;
  return min_of_linear_segments(a, b, mod);
}
