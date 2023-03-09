#define PROBLEM "https://yukicoder.me/problems/no/1170"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/implicit_graph/unionfind.hpp"

void solve() {
  LL(N, A, B);
  VEC(ll, X, N);
  set<pi> ss;
  FOR(i, N) ss.insert({X[i], i});

  auto set_used = [&](int v) -> void { ss.erase({X[v], v}); };
  auto find_unused = [&](int v) -> int {
    auto it = ss.lower_bound({X[v] + A, -1});
    if (it != ss.end()) {
      auto [x, idx] = *it;
      if (x <= X[v] + B) return idx;
    }
    it = ss.lower_bound({X[v] - A + 1, -1});
    if (it != ss.begin()) {
      --it;
      auto [x, idx] = *it;
      if (x >= X[v] - B) return idx;
    }
    return -1;
  };
  auto uf = implicit_graph_unionfind(N, set_used, find_unused);
  FOR(v, N) print(uf.size(uf[v]));
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
