#define PROBLEM "https://yukicoder.me/problems/no/1911"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/bipartite_vertex_coloring.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);
  VV(ll, A, 2, N);

  ll ANS = 0;
  {
    auto C = bipartite_vertex_coloring(G);
    if (!C.empty()) {
      ll a = 0, b = 0;
      FOR(v, N) {
        if (C[v] == 0) a += A[0][v], b += A[1][v];
        if (C[v] == 1) b += A[0][v], a += A[1][v];
      }
      return print(max(a, b));
    }
  }
  // 全部良い方の色でとった場合からのロス
  ll sm = 0;
  vv(ll, loss, 2, N);
  FOR(v, N) {
    ll x = max(A[0][v], A[1][v]);
    loss[0][v] = x - A[0][v];
    loss[1][v] = x - A[1][v];
    sm += x;
  }

  // ロス最小の交互サイクルを探す
  FOR(S, N) {
    FOR(Sc, 2) {
      vv(ll, dist, 2, N, infty<ll>);
      pqg<tuple<ll, int, int>> que;
      auto add = [&](ll c, ll v, ll d) -> void {
        if (chmin(dist[c][v], d)) que.emplace(d, c, v);
      };
      add(Sc, S, loss[Sc][S]);
      while (len(que)) {
        auto [d, c, v] = POP(que);
        if (d != dist[c][v]) continue;
        for (auto&& e: G[v]) {
          add(1 - c, e.to, dist[c][v] + loss[1 - c][e.to]);
        }
      }
      chmax(ANS, sm - dist[1 - Sc][S] + loss[1 - Sc][S]);
    }
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
