#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/group_add.hpp"
#include "graph/lazytreemonoid.hpp"
#include "alg/lazy_cntsum_add.hpp"

void solve() {
  LL(N);
  Graph G(N);
  FOR(v, N) {
    LL(k);
    FOR_(k) {
      LL(to);
      G.add(v, to);
    }
  }
  G.build();
  HLD hld(G);
  vc<pi> seg_raw(N - 1, {1, 0});
  LazyTreeMonoid<decltype(hld), Lazy_CntSum_Add<ll>, 1> TM(hld, seg_raw);
  LL(Q);
  FOR_(Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      TM.apply_path(0, v, x);
      // TM.apply_path(hld.parent[v], v, x);
    } else {
      LL(v);
      print(TM.prod_path(0, v).se);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
