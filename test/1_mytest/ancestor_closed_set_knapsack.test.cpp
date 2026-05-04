#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "random/random_graph.hpp"
#include "knapsack/ancestor_closed_set_knapsack.hpp"

void test(int N) {
  FOR(1000) {
    auto E = random_tree(N);
    Graph<int, 0> G(N);
    for (auto& [a, b] : E) G.add(a, b);
    G.build();
    Tree<decltype(G)> tree(G);
    vc<int> weight, val;
    FOR(N) {
      weight.eb(RNG(1, 10));
      val.eb(RNG(1, 10));
    }
    int LIM = RNG(1, 100);
    auto ANS = ancestor_closed_set_knapsack(tree, weight, val, LIM);
    vc<int> god(LIM + 1, -infty<int>);
    FOR(s, 1 << N) {
      bool ok = 1;
      FOR(v, 1, N) {
        if (has_kth_bit(s, v) && !has_kth_bit(s, tree.parent[v])) ok = 0;
      }
      if (!ok) continue;
      int a = 0, b = 0;
      FOR(v, N) if (s >> v & 1) a += weight[v], b += val[v];
      if (a <= LIM) chmax(god[a], b);
    }
    assert(god == ANS);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

int main() {
  FOR(N, 1, 11) test(N);
  solve();
  return 0;
}