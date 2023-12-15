#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/tree_walk_generating_function.hpp"
#include "poly/fps_div.hpp"

using mint = modint998;

template <bool ALLOW_LOOP>
void test() {
  FOR(N, 1, 30) {
    FOR(50) {
      Graph<int, 0> G(N);
      vv(mint, mat, N, N);
      for (auto& [a, b]: random_tree(N)) {
        G.add(a, b);
        mat[a][b] = RNG(0, mint::get_mod());
        mat[b][a] = RNG(0, mint::get_mod());
      }
      G.build();
      if (ALLOW_LOOP) { FOR(v, N) mat[v][v] = RNG(mint::get_mod()); }
      int s = RNG(0, N), t = RNG(0, N);
      int LIM = 200;
      vc<mint> ANS(LIM + 1);
      vc<mint> dp(N);
      dp[s] = 1;
      FOR(k, LIM) {
        ANS[k] = dp[t];
        vc<mint> newdp(N);
        FOR(a, N) FOR(b, N) newdp[b] += dp[a] * mat[a][b];
        swap(dp, newdp);
        ANS[k + 1] = dp[t];
      }
      auto [f, g] = tree_walk_generating_function<ALLOW_LOOP, mint>(
          G, s, t, [&](int i, int j) -> mint { return mat[i][j]; });
      f.resize(LIM + 1);
      g.resize(LIM + 1);
      f = fps_div(f, g);
      assert(f == ANS);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}

signed main() {
  test<0>();
  test<1>();
  solve();
  return 0;
}
