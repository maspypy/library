#define PROBLEM "https://yukicoder.me/problems/no/2498"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/dual_segtree.hpp"
#include "mod/modint.hpp"
#include "alg/monoid/bitwise_function.hpp"

using mint = modint998;

void solve() {
  LL(N, Q);
  VEC(u32, A, N);
  using Mono = Bitwise_Function<u32>;
  Dual_SegTree<Mono> seg(N);
  FOR(Q) {
    STR(S);
    INT(L, R, x);
    --L;
    if (S == "o") { seg.apply(L, R, Mono::func_or(x)); }
    if (S == "x") { seg.apply(L, R, Mono::func_xor(x)); }
  }

  auto F = seg.get_all();

  // 各項の popcnt ごとの数え
  const int K = 30;
  array<mint, K + 1> DP{};
  DP[0] = 1;

  FOR(i, N) {
    auto [F0, F1] = F[i];
    // [0, A[i]]
    struct Data {
      u64 lo = 0, eq = 0;
    };
    vc<Data> dp(K + 1);
    dp[0].eq = 1;
    FOR_R(k, K) {
      int x0 = F0 >> k & 1;
      int x1 = F1 >> k & 1;
      vc<Data> newdp(K + 1);
      FOR(n, K) {
        if (A[i] >> k & 1) {
          newdp[n + x0].lo += dp[n].lo + dp[n].eq;
          newdp[n + x1].lo += dp[n].lo;
          newdp[n + x1].eq += dp[n].eq;
        } else {
          newdp[n + x0].lo += dp[n].lo;
          newdp[n + x0].eq += dp[n].eq;
          newdp[n + x1].lo += dp[n].lo;
        }
      }
      swap(dp, newdp);
    }
    array<mint, K + 1> newDP{};
    FOR(a, K + 1) FOR(b, K + 1) {
      newDP[max(a, b)] += DP[a] * mint(dp[b].lo + dp[b].eq);
    }
    swap(DP, newDP);
  }

  mint ANS = 0;
  FOR(k, K + 1) ANS += mint(k) * DP[k];
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
