#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "convex/non_adjecent_selection.hpp"
#include "random/base.hpp"

void test() {
  FOR(100) {
    FOR(N, 10) {
      vi A(N);
      FOR(i, N) A[i] = RNG(0, 1000000000);

      Non_Adjacent_Selection<ll, true> MI(A);
      Non_Adjacent_Selection<ll, false> MA(A);
      FOR(cnt, ceil<int>(N, 2) + 1) {
        ll mi = infty<ll>, ma = -infty<ll>;
        FOR(s, 1 << N) {
          if (s & (s >> 1)) continue;
          if (popcnt(s) != cnt) continue;
          ll sm = 0;
          FOR(i, N) if (s >> i & 1) sm += A[i];
          chmin(mi, sm), chmax(ma, sm);
        }
        assert(MI.ANS[cnt] == mi);
        assert(MA.ANS[cnt] == ma);

        {
          vc<int> I = MI.restore(cnt);
          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);
          ll sm = 0;
          for (auto& i: I) sm += A[i];
          assert(mi == sm);
        }
        {
          vc<int> I = MA.restore(cnt);
          FOR(k, len(I) - 1) assert(I[k + 1] >= I[k] + 2);
          ll sm = 0;
          for (auto& i: I) sm += A[i];
          assert(ma == sm);
        }
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}