#define PROBLEM "https://yukicoder.me/problems/no/310"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/implicit_matrix/det.hpp"
#include "mod/modint.hpp"
using mint = modint107;

void solve() {
  LL(N, M);
  vv(bool, G, N, N, 1);
  VEC(pi, AB, M);
  for (auto&& [a, b]: AB) --a, --b;
  for (auto&& [a, b]: AB) { G[a][b] = 0; }
  {
    // 入次数、出次数ともに N の点は除外して座圧
    vc<int> deg(N);
    FOR(v, N) FOR(w, N) {
      if (G[v][w]) deg[v]++, deg[w]++;
    }
    vc<int> X;
    FOR(v, N) if (deg[v] > 0) X.eb(v);
    vc<pi> tmp;
    for (auto&& [a, b]: AB) {
      if (deg[a] == 0 || deg[b] == 0) continue;
      a = LB(X, a);
      b = LB(X, b);
      tmp.eb(a, b);
    }
    N = len(X);
    swap(AB, tmp);
  }
  if (N == 0) return print(1);

  // indeg - outdeg
  vc<int> indeg(N, N), outdeg(N, N);
  for (auto&& [a, b]: AB) { outdeg[a]--, indeg[b]--; }
  FOR(v, N) if (abs(indeg[v] - outdeg[v]) >= 2) return print(0);
  vc<int> S, T;
  FOR(v, N) if (indeg[v] > outdeg[v]) T.eb(v);
  FOR(v, N) if (indeg[v] < outdeg[v]) S.eb(v);
  if (len(S) > 1 || len(T) > 1) return print(0);

  pi ADD = {-1, -1};

  mint cf = 1;
  if (len(S) == 0 && len(T) == 0) cf = mint(N * N - len(AB));
  if (len(S)) {
    ADD = {T[0], S[0]};
    indeg[S[0]]++, outdeg[T[0]]++;
  }

  auto f = [&](vc<mint> v) -> vc<mint> {
    v.resize(N);
    vc<mint> w(N, -SUM<mint>(v));
    FOR(i, N) w[i] += mint(N) * v[i];
    for (auto&& [a, b]: AB) {
      w[b] += v[a];
      w[b] -= v[b];
    }
    auto [s, t] = ADD;
    if (s != -1) {
      w[t] -= v[s];
      w[t] += v[t];
    }
    v.resize(N - 1);
    w.resize(N - 1);
    return w;
  };
  mint det = implicit_matrix_det<mint>(N - 1, f);
  for (auto&& x: indeg) cf *= fact<mint>(x - 1);
  print(cf * det);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
