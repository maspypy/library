#define PROBLEM "https://yukicoder.me/problems/no/1303"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "linalg/det.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "linalg/det_A_plus_xB.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  UnionFind uf(N);
  vv(int, G, N, N);
  FOR(M) {
    LL(a, b);
    --a, --b;
    G[a][b] -= 1;
    G[b][a] -= 1;
    G[a][a] += 1;
    G[b][b] += 1;
    uf.merge(a, b);
  }

  if (uf.n_comp >= 2) {
    // 成分の大きさ、木の個数
    vvc<int> comp(N);
    vc<mint> tree(N);
    FOR(v, N) comp[uf[v]].eb(v);
    FOR(v, N) if (uf[v] == v) {
      int n = len(comp[v]);
      vv(mint, A, n, n);
      FOR(i, n) FOR(j, n) {
        int a = comp[v][i];
        int b = comp[v][j];
        A[i][j] = G[a][b];
      }
      A.resize(n - 1);
      FOR(i, n - 1) A[i].pop_back();
      tree[v] = det(A);
    }
    mint ANS = 1;
    FOR(v, N) if (uf[v] == v) ANS *= tree[v];
    ll best = -1;
    mint cf = 1;
    FOR(a, N) FOR(b, a) {
      if (uf[a] != a) continue;
      if (uf[b] != b) continue;
      ll x = len(comp[a]) * len(comp[b]);
      if (chmax(best, x)) cf = 0;
      if (best == x) cf += len(comp[a]) * len(comp[b]);
    }
    ll ans = 0;
    FOR(v, N) ans += N - len(comp[uf[v]]);
    ans -= 2 * best;
    print(ans);
    print(cf * ANS);
    return;
  }

  // 全体が連結のとき
  vv(mint, A, N, N);
  vv(mint, B, N, N);
  FOR(i, N) FOR(j, N) A[i][j] = G[i][j];
  FOR(i, N) FOR(j, i) if (G[i][j] == 0) {
    B[i][j] = -1;
    B[j][i] = -1;
    B[i][i] += 1;
    B[j][j] += 1;
  }
  A.resize(N - 1), B.resize(N - 1);
  FOR(i, N - 1) A[i].resize(N - 1), B[i].resize(N - 1);
  auto f = det_A_plus_xB<mint>(A, B);
  print(0);
  print(f[0] + f[1]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
