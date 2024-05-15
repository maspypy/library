#define PROBLEM "https://judge.yosupo.jp/problem/convex_layers"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/convex_layers.hpp"

using P = Point<ll>;
void solve() {
  LL(N);
  vc<P> A(N);
  FOR(i, N) read(A[i]);
  auto layer = convex_layers(A);
  vc<int> ANS(N);
  FOR(i, len(layer)) {
    for (auto& j: layer[i]) ANS[j] = 1 + i;
    vc<P> X = rearrange(A, layer[i]);
    if (len(X) <= 2) continue;
    FOR(a, len(X)) {
      int b = (a + 1) % len(X);
      int c = (b + 1) % len(X);
      assert(ccw(X[a], X[b], X[c]) >= 0);
    }
  }
  for (auto& x: ANS) print(x);
}

signed main() {
  solve();

  return 0;
}
