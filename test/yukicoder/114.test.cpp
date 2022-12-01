#define PROBLEM "https://yukicoder.me/problems/no/114"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/steiner_tree.hpp"

void solve() {
  LL(N, M, K);
  Graph<int> G(N);
  G.read_graph(M, 1);
  VEC(int, terminal, K);
  for (auto&& v: terminal) --v;

  const int INF = 1LL << 29;

  if (K <= 15) return print(steiner_tree<int>(G, terminal, INF));

  set<int> ss(all(terminal));
  vc<int> other;
  FOR(v, N) if (!ss.count(v)) other.eb(v);

  UnionFind uf(N);
  ll LIM = 100;

  auto edges = G.edges;
  sort(all(edges), [](auto& x, auto& y) { return x.cost < y.cost; });

  auto f = [&](ll s) -> int {
    uf.reset();
    int mst = 0, merge = 0;
    for (auto&& e: edges) {
      int i = e.frm, j = e.to;
      if ((s >> i & 1) && (s >> j & 1)) {
        if (uf.merge(i, j)) {
          ++merge;
          mst += e.cost;
        }
      }
    }
    if (merge == popcnt(s) - 1) return mst;
    return INF;
  };

  int ANS = INF;
  ll t = 0;
  for (auto&& x: terminal) t |= 1LL << x;

  FOR(s, 1 << len(other)) {
    ll u = t;
    FOR(i, len(other)) if (s & 1 << i) u |= 1LL << other[i];
    chmin(ANS, f(u));
  }
  print(ANS);
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
