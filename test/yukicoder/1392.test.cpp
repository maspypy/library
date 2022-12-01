#define PROBLEM "https://yukicoder.me/problems/no/1392"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "mod/modint.hpp"
#include "poly/convolution_all.hpp"
#include "seq/famous/stirling_number_2.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  UnionFind uf(N);
  FOR(v, N) {
    LL(x);
    --x;
    uf.merge(x, v);
  }

  // 包除ルールを選ぶならば係数 -1 をつける
  // できた連結成分数 → 重みの和

  vvc<mint> polys;
  FOR(root, N) if (uf[root] == root) {
    int n = uf.size[root];
    vc<mint> f(n + 1);
    FOR(k, n + 1) {
      mint cf = (k % 2 == 0 ? 1 : -1);
      int comp = max<int>(1, n - k);
      f[comp] += cf * C<mint>(n, k);
    }
    polys.eb(f);
  }
  auto f = convolution_all<mint>(polys);
  auto g = stirling_number_2_k<mint>(M, N);

  mint ANS = 0;
  FOR(n, N + 1) ANS += f[n] * g[n];
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
