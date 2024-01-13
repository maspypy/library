#include "geo/base.hpp"
#include "random/shuffle.hpp"
#include "geo/outcircle.hpp"

// randomize を利用した expected O(N) アルゴリズム
// https://codeforces.com/problemset/problem/119/E
// 使う頂点のインデックスをかえす {0} or {i,j,-1} or {i,j,k}
// Computational Geometry, Section 4.7
template <typename T>
tuple<int, int, int> minimum_enclosing_circle(vc<Point<T>> points) {
  const int n = len(points);
  assert(n >= 1);
  if (n == 1) return {0, -1, -1};
  vc<int> I(n);
  FOR(i, n) I[i] = i;
  shuffle(I);

  points = rearrange(points, I);

  tuple<int, int, int> c = {0, -1, -1};
  auto contain = [&](Point<T> p) -> bool {
    auto [i, j, k] = c;
    if (j == -1) { return p == points[i]; }
    if (k == -1) { return (points[i] - p).dot(points[j] - p) <= 0; }
    return outcircle_side(points[i], points[j], points[k], p) >= 0;
  };

  FOR(i, 1, n) {
    if (contain(points[i])) continue;
    c = {0, i, -1};
    FOR(j, 1, i) {
      if (contain(points[j])) continue;
      c = {i, j, -1};
      FOR(k, j) {
        if (contain(points[k])) continue;
        c = {i, j, k};
      }
    }
  }
  auto [i, j, k] = c;
  if (i != -1) i = I[i];
  if (j != -1) j = I[j];
  if (k != -1) k = I[k];
  return {i, j, k};
}