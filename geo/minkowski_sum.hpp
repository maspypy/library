#include "geo/angle_sort.hpp"

// https://codeforces.com/contest/87/problem/E
// https://atcoder.jp/contests/stpc2025_1/tasks/stpc2025_1_l
// 入力は ccw 凸多角形であることを仮定.
// return は strict (180度なし)
template <typename T>
vc<Point<T>> minkowski_sum(vc<Point<T>> A, vc<Point<T>> B) {
  using P = Point<T>;
  rotate(A.begin(), min_element(all(A)), A.end());
  rotate(B.begin(), min_element(all(B)), B.end());
  if (len(A) > len(B)) swap(A, B);
  if (len(A) == 1) {
    for (auto &p : B) {
      p += A[0];
    }
    return B;
  }

  P p0 = A[0] + B[0];
  int NA = len(A), NB = len(B);
  A.eb(A[0]), B.eb(B[0]);
  vc<P> DA(NA), DB(NB);
  FOR(i, NA) DA[i] = A[i + 1] - A[i];
  FOR(i, NB) DB[i] = B[i + 1] - B[i];
  POP(A), POP(B);

  auto comp = [&](P L, P R) -> bool {
    int a = lower_or_upper(L), b = lower_or_upper(R);
    if (a != b) return a < b;
    return L.det(R) > 0;
  };
  rotate(DA.begin(), min_element(all(DA), comp), DA.end());
  rotate(DB.begin(), min_element(all(DB), comp), DB.end());

  int a = 0, b = 0;
  vc<P> C(NA + NB + 1);
  FOR(i, NA + NB) {
    if (a == NA || (b < NB && comp(DB[b], DA[a]))) {
      C[i + 1] = C[i] + DB[b++];
    } else {
      C[i + 1] = C[i] + DA[a++];
    }
  }
  assert(C[NA + NB] == P(0, 0));
  POP(C);
  rotate(C.begin(), min_element(all(C)), C.end());

  P add = p0 - C[0];
  for (auto &x : C) x += add;

  C.eb(C[0]);
  vc<P> ANS;
  for (P p : C) {
    while (len(ANS) >= 2) {
      P a = ANS[len(ANS) - 2];
      P b = ANS[len(ANS) - 1];
      if ((b - a).det(p - a) != 0) break;
      if ((b - a).dot(p - b) < 0) break;
      ANS.pop_back();
    }
    ANS.eb(p);
  }
  assert(ANS[0] == ANS.back());
  ANS.pop_back();
  return ANS;
}