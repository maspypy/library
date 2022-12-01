#define PROBLEM "https://yukicoder.me/problems/no/1502"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/unionfind/weightedunionfind.hpp"
#include "alg/monoid/affine.hpp"

using mint = modint107;

void solve() {
  LL(N, M, K);
  using T = tuple<int, int, int>;
  VEC(T, dat, M);
  for (auto&& [a, b, c]: dat) --a, --b;

  using GRP = Monoid_Affine<ll>;

  WeightedUnionFind<GRP> uf(N);
  for (auto&& [a, b, c]: dat) {
    if (uf[a].fi == uf[b].fi) continue;
    uf.merge(a, b, {-1, c});
  }

  auto solve = [&](ll K) -> mint {
    vi lo(N, 1), hi(N, K);
    FOR(v, N) {
      auto [r, f] = uf.get(v);
      auto [a, b] = f;
      // 1 <= ax + b <= K
      if (a == 1) {
        chmax(lo[r], 1 - b);
        chmin(hi[r], K - b);
      }
      if (a == -1) {
        // 1 <= -x+b <= K
        chmax(lo[r], b - K);
        chmin(hi[r], b - 1);
      }
    }
    for (auto&& [a, b, c]: dat) {
      auto [ra, fa] = uf[a];
      auto [rb, fb] = uf[b];
      assert(ra == rb);
      auto [pa, qa] = fa;
      auto [pb, qb] = fb;
      // pax+qa+pbx+qb==c
      // (pa+pb)x==(c-qa-qb)
      ll l = pa + pb, r = c - qa - qb;
      if (l == 0 && r == 0) continue;
      if (l == 0 && r != 0) return 0;
      ll x = r / l;
      if (l * x != r) return 0;
      if (x < 0 || x > K) return 0;
      chmax(lo[ra], x);
      chmin(hi[ra], x);
    }
    mint res = 1;
    FOR(v, N) if (uf[v].fi == v) {
      ll cnt = max(0LL, hi[v] - lo[v] + 1);
      res *= mint(cnt);
    }
    return res;
  };

  mint ANS = solve(K) - solve(K - 1);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
