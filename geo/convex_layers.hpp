#include "geo/dynamicupperhull.hpp"

// https://codeforces.com/contest/1599/problem/D
// 出力は反時計回りである
vvc<int> convex_layers(vc<Point<ll>> points) {
  int N = len(points);
  DynamicUpperHull<Point<ll>> DUH(points, 1);
  FOR(i, N) points[i] = -points[i];
  DynamicUpperHull<Point<ll>> DLH(points, 1);
  vvc<int> ANS;
  int done = 0;
  int k = 0;
  while (done < N) {
    ++k;
    auto A = DLH.get();
    auto B = DUH.get();
    if (len(A) >= 2) {
      POP(A), POP(B);
      A.insert(A.end(), all(B));
      reverse(all(A));
    }
    ANS.eb(A);
    for (auto&& i: A) {
      ++done;
      DUH.erase(i);
      DLH.erase(i);
    }
  }
  return ANS;
}