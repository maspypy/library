#define PROBLEM "https://yukicoder.me/problems/no/529"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/two_edge_component.hpp"
#include "graph/treemonoid.hpp"
#include "alg/monoid_max_idx.hpp"

void solve() {
  LL(N, M, Q);
  Graph G0(N);
  G0.read_graph(M);
  auto [C, comp] = two_edge_component(G0);

  Graph G(C);
  for (auto&& e: G0.edges) {
    ll a = e.frm, b = e.to;
    if (comp[a] == comp[b]) continue;
    G.add(comp[a], comp[b]);
  }
  G.build();

  using Mono = Monoid_Max_Idx<ll>;

  const ll INF = 1LL << 60;

  HLD hld(G);
  vc<pq<ll>> wts(C);
  vc<pair<ll, int>> dat(C);
  FOR(i, C) dat[i] = {-INF, i};
  TreeMonoid<decltype(hld), Mono> TM(hld, dat);

  FOR_(Q) {
    LL(t);
    if (t == 1) {
      LL(v, x);
      --v;
      ll c = comp[v];
      wts[c].push(x);
      TM.set(c, {wts[c].top(), c});
    }
    if (t == 2) {
      LL(a, b);
      --a, --b;
      a = comp[a], b = comp[b];
      auto [x, c] = TM.prod_path(a, b);
      if (x == -INF) {
        print(-1);
      } else {
        print(x);
        wts[c].pop();
        x = (wts[c].empty() ? -INF : wts[c].top());
        TM.set(c, {x, c});
      }
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
