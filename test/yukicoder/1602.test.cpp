#define PROBLEM "https://yukicoder.me/problems/no/1602"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/xor.hpp"
#include "graph/shortest_path/nonzero_group_product_shortest_path.hpp"

void solve() {
  INT(N, M, K);
  Graph<int, 0> G(N);
  vc<u32> label(M);
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    STR(X);
    u32 v = 0;
    FOR(j, K) if (X[j] == '1') v |= u32(1) << j;
    G.add(a, b, c);
    label[i] = v;
  }
  G.build();

  using Mono = Monoid_Xor<u32>;
  auto ANS = nonzero_group_product_shortest_path<ll, Mono>(G, label, N - 1);
  FOR(v, N - 1) {
    ll ans = ANS[v];
    if (ans == infty<ll>) ans = -1;
    print(ans);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
