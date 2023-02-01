#define PROBLEM "https://yukicoder.me/problems/no/529"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/two_edge_component.hpp"
#include "graph/ds/tree_monoid.hpp"
#include "alg/monoid/max_idx.hpp"

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

  Tree tree(G);
  vc<pq<ll>> wts(C);
  vc<pair<ll, int>> dat(C);
  FOR(i, C) dat[i] = {-infty<ll>, i};
  Tree_Monoid<decltype(tree), Mono> TM(tree, dat);

  FOR(Q) {
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
      if (x == -infty<ll>) {
        print(-1);
      } else {
        print(x);
        wts[c].pop();
        x = (wts[c].empty() ? -infty<ll> : wts[c].top());
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
