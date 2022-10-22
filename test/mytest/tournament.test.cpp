#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "graph/tournament.hpp"

void test() {
  auto gen = [&](int N) -> vvc<bool> {
    vv(bool, mat, N, N);
    FOR(i, N) FOR(j, i) {
      bool b = RNG(0, 2);
      if (b) mat[i][j] = 1;
      if (!b) mat[j][i] = 1;
    }
    return mat;
  };

  FOR(10) {
    FOR(N, 1, 20) {
      auto G = gen(N);
      auto check = [&](int i, int j) -> bool { return G[i][j]; };
      auto P = hamiltonian_path_in_tournament(N, check);
      vc<bool> use(N);
      for (auto&& x: P) use[x] = 1;
      assert(len(P) == N);
      assert(SUM<int>(use) == N);
      FOR(i, N - 1) {
        ll a = P[i], b = P[i + 1];
        assert(G[a][b]);
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}