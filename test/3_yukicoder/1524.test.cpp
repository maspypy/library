#define PROBLEM "https://yukicoder.me/problems/no/1524"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"
#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/add_chmax.hpp"

using Mono = Monoid_Add_Chmax<ll>;

void solve() {
  LL(N);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    LL(p);
    G.add(--p, v);
  }
  G.build();
  Tree<decltype(G)> tree(G);
  auto& head = tree.head;

  VEC(ll, A, N);
  for (auto&& x: A) --x;
  VEC(ll, B, N);

  vc<Dual_SegTree<Mono>> dp(N);
  vvc<int> keys(N);
  FOR(v, N) if (head[v] == v) {
    FOR(i, tree.LID[v], tree.RID[v]) { keys[v].eb(A[tree.V[i]]); }
    sort(all(keys[v]));
  }

  FOR(v, N) dp[v].build(len(keys[v]));
  // FOR(v, N) print(v, ",", keys[v]);

  auto eval_all = [&](Dual_SegTree<Mono>& seg) -> vi {
    auto tmp = seg.get_all();
    vi X(len(tmp));
    FOR(k, len(X)) X[k] = Mono::eval(tmp[k], 0);
    return X;
  };

  FOR_R(v, N) {
    auto& seg = dp[head[v]];
    auto& key = keys[head[v]];

    for (auto&& e: G[v]) {
      int to = e.to;
      if (head[to] == head[v]) continue;
      vc<int> X = keys[to];
      vi Y = eval_all(dp[to]);
      ll p = 0;
      FOR(k, len(X)) {
        int idx = LB(key, X[k]);
        seg.apply(p, idx + 1, Mono::add(Y[k]));
        p = idx + 1;
      }
    }
    int idx = LB(key, A[v]);
    ll x = Mono::eval(seg.get(idx), 0) + B[v];
    seg.apply(0, idx + 1, Mono::chmax(x));
  }

  vi Y = eval_all(dp[0]);
  print(MAX(Y));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
