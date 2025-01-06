#include "geo/convex_hull.hpp"

// 1 次関数の max を [L,R,a,b] の列として出力
// https://qoj.ac/contest/1576/problem/8505
template <typename Re, typename T>
vc<tuple<Re, Re, Re, Re>> line_min_function_real(vc<pair<T, T>> LINE) {
  assert(!LINE.empty());
  using P = Point<T>;
  vc<P> point;
  for (auto& [x, y]: LINE) point.eb(P(x, y));
  auto I = ConvexHull(point, "lower");
  point = rearrange(point, I);
  int N = len(point);
  if (N >= 2 && point[N - 1].x == point[N - 2].x) { POP(point), --N; }
  reverse(all(point)); // 傾きは大きい方から
  Re l = -infty<Re>;
  vc<tuple<Re, Re, Re, Re>> ANS;
  FOR(i, N) {
    Re r = infty<Re>;
    auto [a, b] = point[i];
    if (i + 1 < N) {
      auto [c, d] = point[i + 1];
      if (a == c) continue;
      assert(a > c);
      r = Re(d - b) / (a - c);
      chmax(r, l), chmin(r, infty<Re>);
    }
    if (l < r) ANS.eb(l, r, a, b), l = r;
  }
  return ANS;
}

// 1 次関数の max を [L,R,a,b] の列として出力
template <typename Re, typename T>
vc<tuple<Re, Re, Re, Re>> line_max_function_real(vc<pair<T, T>> LINE) {
  assert(!LINE.empty());
  for (auto& [a, b]: LINE) a = -a, b = -b;
  auto ANS = line_min_function_real<Re, T>(LINE);
  for (auto& [l, r, a, b]: ANS) a = -a, b = -b;
  return ANS;
}

// LINE(a,b,c): y=(ax+b)/c, 評価点は整数
// 1 次関数の min を [L,R,a,b,c] の列として出力
// オーバーフロー安全
vc<tuple<ll, ll, ll, ll, ll>> line_min_function_rational(vc<tuple<ll, ll, ll>> LINE, ll L, ll R) {
  // 傾き降順
  sort(all(LINE), [&](auto& L, auto& R) -> bool {
    auto& [a1, b1, c1] = L;
    auto& [a2, b2, c2] = R;
    return i128(a1) * c2 > i128(a2) * c1;
  });
  vc<tuple<ll, ll, ll, ll, ll>> ANS;
  for (auto& [a2, b2, c2]: LINE) {
    while (1) {
      if (ANS.empty()) {
        ANS.eb(L, R, a2, b2, c2);
        break;
      }
      auto& [L1, R1, a1, b1, c1] = ANS.back();
      i128 s = i128(c2) * a1 - i128(a2) * c1; // >= 0
      i128 t = i128(b2) * c1 - i128(b1) * c2;
      if (s == 0) {
        // 平行なので小さい方だけを残す
        if (t >= 0) break;
        ANS.pop_back();
        if (len(ANS)) get<1>(ANS.back()) = R;
        continue;
      }
      i128 x = ceil<i128>(t, s);
      // x 以上で 2 の方が下に来る
      if (x <= L1) {
        ANS.pop_back();
        continue;
      }
      if (x < R) {
        R1 = x;
        ANS.eb(x, R, a2, b2, c2);
        break;
      } else {
        break;
      }
    }
  }
  return ANS;
}

// LINE(a,b,c): y=(ax+b)/c, 評価点は整数
// 1 次関数の max を [L,R,a,b,c] の列として出力
// オーバーフロー安全
vc<tuple<ll, ll, ll, ll, ll>> line_max_function_rational(vc<tuple<ll, ll, ll>> LINE, ll L, ll R) {
  for (auto& [a, b, c]: LINE) a = -a, b = -b;
  auto ANS = line_min_function_rational(LINE, L, R);
  for (auto& [L, R, a, b, c]: ANS) a = -a, b = -b;
  return ANS;
}

// LINE(a,b): y=ax+b, 評価点は整数
// 1 次関数の min を [L,R,a,b] の列として出力
// オーバーフロー安全
vc<tuple<ll, ll, ll, ll>> line_min_function_integer(vc<pair<ll, ll>> LINE, ll L, ll R) {
  // 傾き降順
  sort(all(LINE), [&](auto& L, auto& R) -> bool {
    auto& [a1, b1] = L;
    auto& [a2, b2] = R;
    return a1 > a2;
  });
  vc<tuple<ll, ll, ll, ll>> ANS;
  for (auto& [a2, b2]: LINE) {
    while (1) {
      if (ANS.empty()) {
        ANS.eb(L, R, a2, b2);
        break;
      }
      auto& [L1, R1, a1, b1] = ANS.back();
      if (a1 == a2) {
        if (b1 <= b2) break;
        ANS.pop_back();
        if (len(ANS)) get<1>(ANS.back()) = R;
        continue;
      }
      ll x = ceil<ll>(b2 - b1, a1 - a2);
      // x 以上で 2 の方が下に来る
      if (x <= L1) {
        ANS.pop_back();
        continue;
      }
      if (x < R) {
        R1 = x;
        ANS.eb(x, R, a2, b2);
        break;
      } else {
        break;
      }
    }
  }
  return ANS;
}

// LINE(a,b,c): y=(ax+b)/c, 評価点は整数
// 1 次関数の min を [L,R,a,b,c] の列として出力
// c>0, (ax+b)c がオーバーフローしない,
vc<tuple<ll, ll, ll, ll>> line_max_function_integer(vc<pair<ll, ll>> LINE, ll L, ll R) {
  for (auto& [a, b]: LINE) a = -a, b = -b;
  auto ANS = line_min_function_integer(LINE, L, R);
  for (auto& [L, R, a, b]: ANS) a = -a, b = -b;
  return ANS;
}

// (L,R,func) の下側と上側をマージするときなどに使う用
template <typename T>
vc<tuple<T, T, T, T, T, T>> merge_46(vc<tuple<T, T, T, T>> A, vc<tuple<T, T, T, T>> B) {
  vc<tuple<T, T, T, T, T, T>> ANS;
  reverse(all(A));
  reverse(all(B));
  while (len(A) && len(B)) {
    auto& [l1, r1, a1, b1] = A.back();
    auto& [l2, r2, a2, b2] = B.back();
    assert(l1 == l2);
    T r = min(r1, r2);
    ANS.eb(l1, r, a1, b1, a2, b2);
    l1 = r, l2 = r;
    if (r1 == r) POP(A);
    if (r2 == r) POP(B);
  };
  return ANS;
}

// (L,R,func) の下側と上側をマージするときなどに使う用
// f(L,R,a1,b1,a2,b2)
template <typename T, typename F>
void merge_46(const vc<tuple<T, T, T, T>>& A, const vc<tuple<T, T, T, T>>& B, F f) {
  int i = 0, j = 0;
  while (i < len(A) && j < len(B)) {
    auto& [l1, r1, a1, b1] = A[i];
    auto& [l2, r2, a2, b2] = B[j];
    T l = max(l1, l2), r = min(r1, r2);
    if (l < r) f(l, r, a1, b1, a2, b2);
    (r1 < r2 ? i : j)++;
  }
}

// (L,R,func) の下側と上側をマージするときなどに使う用
// f(L,R,a1,b1,a2,b2)
template <typename T, typename F>
void merge_58(const vc<tuple<T, T, T, T, T>>& A, const vc<tuple<T, T, T, T, T>>& B, F f) {
  int i = 0, j = 0;
  while (i < len(A) && j < len(B)) {
    auto& [l1, r1, a1, b1, c1] = A[i];
    auto& [l2, r2, a2, b2, c2] = B[j];
    T l = max(l1, l2), r = min(r1, r2);
    if (l < r) f(l, r, a1, b1, c1, a2, b2, c2);
    (r1 < r2 ? i : j)++;
  }
}
