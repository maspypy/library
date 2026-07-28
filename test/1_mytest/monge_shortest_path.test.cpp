#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/random_monge.hpp"
#include "convex/monge/monge_shortest_path.hpp"

void test() {
  FOR(N, 1, 100) {
    FOR(1000) {
      auto A = random_monge_matrix(N + 1, N + 1);

      auto f = [&](int l, int r) -> ll {
        assert(l < r);
        return A[l][r];
      };

      FOR(minimize_cnt, 2) {
        Monge_Shortest_Path<ll> solver;
        solver.solve(N, f, minimize_cnt);

        vc<ll> dp2(N + 1, infty<ll>);
        vc<int> cnt2(N + 1, infty<int>);
        dp2[0] = 0;
        cnt2[0] = 0;

        FOR(r, 1, N + 1) {
          FOR(l, r) {
            ll x = dp2[l] + f(l, r);
            int c = cnt2[l] + 1;
            bool tie = minimize_cnt ? c < cnt2[r] : c > cnt2[r];
            if (dp2[r] > x || (dp2[r] == x && tie)) {
              dp2[r] = x;
              cnt2[r] = c;
            }
          }
        }

        assert(solver.dp == dp2);
        assert(solver.cnt[N] == cnt2[N]);
      }
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}
