#define PROBLEM "https://judge.yosupo.jp/problem/convex_layers"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/dynamicupperhull.hpp"

void solve() {
  LL(N);
  vc<Point<ll>> pts(N);
  FOR(i, N) read(pts[i].x), read(pts[i].y);
  DynamicUpperHull DUH(pts, 1);
  FOR(i, N) pts[i] = -pts[i];
  DynamicUpperHull DLH(pts, 1);
  vc<int> ANS(N, -1);
  int done = 0;
  int k = 0;
  while (done < N) {
    ++k;
    auto A = DUH.get();
    auto B = DLH.get();
    A.insert(A.end(), all(B));
    for (auto&& i: A)
      if (ANS[i] == -1) {
        ++done;
        ANS[i] = k;
        DUH.erase(i);
        DLH.erase(i);
      }
  }
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();

  return 0;
}
