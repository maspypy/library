#define PROBLEM "https://atcoder.jp/contests/arc130/tasks/arc130_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "convex/fenchel.hpp"
#include "convex/cht_monotone.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(ll, A, N);
  vc<Point<ll>> XY(N);
  FOR(i, N) XY[i] = {i, A[i]};

  CHT_monotone<ll, false> cht;
  for (auto&& [L, R, a, b]: Fenchel(XY, "lower", true)) {
    if (L != -infty<ll>) { cht.add(L, b - a * L); }
    if (R != infty<ll>) { cht.add(R - 1, b - a * (R - 1)); }
  }

  FOR(i, N) A[i] = cht.query_monotone_inc(i);
  print(SUM<ll>(A));
}

signed main() {
  solve();
  return 0;
}
