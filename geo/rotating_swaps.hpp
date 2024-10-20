#include "geo/angle_sort.hpp"

/*
return : {init, events}
init: 方向ベクトル (-1,-eps) 方向についてソートしたときの順序
events: i,j の順位が入れ替わる (i<j から j<i)というイベントの列
360度分ある, 最後には init に戻ってくる
https://atcoder.jp/contests/tupc2023/tasks/tupc2023_m
*/
template <typename T>
pair<vc<int>, vc<pair<int, int>>> rotating_swaps(vc<Point<T>> point) {
  using P = Point<T>;
  /*
  角度 t におけるタイブレイクについて
  角度 t-eps のときのソート順を p1,...,pk とする
  これらが一斉にタイになったあと reverse されるということになる
  (i,j) をペア辞書順に swap すればよい

  同一座標の点について
  同じ座標であるものは常にもとのインデックス順であるとする
  (..i1,...,i2) (...,j1,...,j2)
  j は小さいもの, i は大きいものを優先する
  */
  for (auto &p: point) p = -p;
  auto I = argsort(point);
  for (auto &p: point) p = -p;
  point = rearrange(point, I);
  int N = len(point);
  vc<pair<int, int>> pairs;
  pairs.reserve(N * (N - 1));

  FOR(i, N) FOR(j, N) {
    if (point[i] != point[j]) pairs.eb(i, j);
  }

  sort(all(pairs), [&](auto &L, auto &R) -> bool {
    if (L == R) return 0;
    auto [i1, j1] = L;
    auto [i2, j2] = R;
    P p1 = (point[j1] - point[i1]).rot90(true);
    P p2 = (point[j2] - point[i2]).rot90(true);
    int c = angle_comp_3(p1, p2);
    if (c != 0) return c == -1;
    // p1,p2 は平行
    if (point[i1].dot(p1) != point[i2].dot(p1)) { return point[i1].dot(p1) < point[i2].dot(p1); }
    // p1 - eps のときの dot の pair の辞書順で比べる
    P d = p1.rot90(false);
    pair<T, T> s1 = {point[j1].dot(d), point[i1].dot(d)};
    pair<T, T> s2 = {point[j2].dot(d), point[i2].dot(d)};
    if (s1 != s2) return s1 < s2;
    // ここに来た時点で座標の組が完全一致している
    assert(point[i1] == point[i2] && point[j1] == point[j2]);
    if (i1 != i2) return i1 > i2;
    return j1 < j2;
  });
  for (auto &[i, j]: pairs) { i = I[i], j = I[j]; }
  return {I, pairs};
}
