#include "graph/base.hpp"

// return : (match size, match)
// match[v] : マッチング相手 OR 0
// O(N^3)
// 「組合せ最適化」第2版, アルゴリズム 10.2
template <typename GT>
pair<int, vc<int>> maximum_matching(const GT& G) {
  const int N = G.N;
  vc<int> mu(N), phi(N), rho(N);
  vc<bool> scanned(N);
  FOR(v, N) mu[v] = v;
  ll ans = 0;
  vc<bool> on_path(N);

  auto odd = [&](int x) -> bool {
    return mu[x] != x && phi[mu[x]] == mu[x] && mu[x] != x;
  };
  auto out_of_forest = [&](int x) -> bool {
    return mu[x] != x && phi[mu[x]] == mu[x] && phi[x] == x;
  };
  auto P = [&](int x) -> vc<int> {
    vc<int> P;
    P.eb(x);
    while (mu[x] != x) {
      P.eb(mu[x]);
      P.eb(phi[mu[x]]);
      x = phi[mu[x]];
    }
    return P;
  };

  while (1) {
    FOR(v, N) phi[v] = rho[v] = v, scanned[v] = 0;
    bool aug = 0;
    while (1) {
      bool upd = 0;
      FOR(x, N) {
        if (upd) break;
        if (scanned[x] || odd(x)) continue;
        for (auto&& e: G[x]) {
          int y = e.to;
          if (out_of_forest(y)) {
            upd = 1;
            // grow
            phi[y] = x;
          }
          elif (rho[y] != rho[x] && !odd(y)) {
            vc<int> F;
            FOR(v, N) if (!out_of_forest(v)) F.eb(v);
            upd = 1;
            // augument OR shrink
            vc<int> Px = P(x);
            vc<int> Py = P(y);
            if (Px.back() != Py.back()) {
              aug = 1;
              // augument
              FOR(2) {
                swap(Px, Py);
                for (int i = 1; i < len(Px); i += 2) {
                  int v = Px[i];
                  mu[phi[v]] = v, mu[v] = phi[v];
                }
              }
              mu[x] = y, mu[y] = x, ++ans;
              break;
            } else {
              // shrink
              int r = -1;
              int Nx = len(Px), Ny = len(Py);
              for (int i = 0; i < Nx; i += 2) {
                int v = Px[i];
                int j = i + Ny - Nx;
                if (0 <= j && j < Ny && Py[j] == v && rho[v] == v) {
                  r = v;
                  break;
                }
              }
              while (Px.back() != r) Px.pop_back();
              while (Py.back() != r) Py.pop_back();
              vc<int> change;
              FOR(2) {
                swap(Px, Py);
                for (int i = 1; i < len(Px); i += 2) {
                  int v = Px[i];
                  if (rho[phi[v]] != r) change.eb(v);
                }
              }
              for (auto&& v: change) phi[phi[v]] = v;

              if (rho[x] != r) phi[x] = y;
              if (rho[y] != r) phi[y] = x;
              for (auto&& v: Px) on_path[v] = 1;
              for (auto&& v: Py) on_path[v] = 1;
              FOR(v, N) if (on_path[rho[v]]) { rho[v] = r; }
              fill(all(on_path), 0);
            }
          }
        }
        scanned[x] = 1;
      }
      if (!upd || aug) break;
    }
    if (!aug) break;
  }
  FOR(v, N) if (mu[v] == v) mu[v] = -1;
  return {ans, mu};
}