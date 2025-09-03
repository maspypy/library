#define PROBLEM "https://yukicoder.me/problems/no/2507"
#include "my_template.hpp"
#include "other/io.hpp"

#include "setfunc/subset_convolution.hpp"
#include "setfunc/sps_exp.hpp"
#include "graph/count/count_cycle.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);

  vc<u64> dp = count_cycle<u64>(G);
  FOR(v, N) dp[1 << v] += 1;
  for (auto& e: G.edges) {
    int a = e.frm, b = e.to;
    vc<u64> A(1 << N), B(1 << N);
    FOR(s, 1 << N) {
      if (s >> a & 1) A[s] += dp[s];
      if (s >> b & 1) B[s] += dp[s];
    }
    A = subset_convolution<u64, 13>(A, B);
    FOR(s, 1 << N) { dp[s] += A[s]; }
  }

  dp = sps_exp<u64, 13>(dp);
  print(dp.back());
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
