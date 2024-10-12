#define PROBLEM "https://yukicoder.me/problems/no/1796"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/centroid_decomposition.hpp"
#include "mod/modint.hpp"
#include "poly/middle_product.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, A, N);
  Graph<int, 0> G(N);
  G.read_tree();

  vc<mint> ANS(N);
  // 距離 0
  FOR(v, N) ANS[v] += A[v];

  auto F = [&](vc<int>& par, vc<int> vs, int L1, int R1, int L2, int R2) -> void {
    int n = len(par);
    vc<int> dist(n);
    FOR(i, 1, n) dist[i] = dist[par[i]] + 1;
    auto f = [&](int L1, int R1, int L2, int R2) -> void {
      int n1 = *max_element(dist.begin() + L1, dist.begin() + R1);
      int n2 = *max_element(dist.begin() + L2, dist.begin() + R2);
      vc<mint> a(n1 + n2 + 1), b(n2 + 1);
      FOR(i, n1 + n2 + 1) a[i] = inv<mint>(1 + i) * inv<mint>(1 + i);
      FOR(i, L2, R2) { b[dist[i]] += A[vs[i]]; }
      vc<mint> c = middle_product(a, b);
      assert(len(c) == n1 + 1);
      FOR(i, L1, R1) ANS[vs[i]] += c[dist[i]];
    };
    f(L1, R1, L2, R2);
    f(L2, R2, L1, R1);
  };
  centroid_decomposition<1>(G, F);

  mint k0 = fact<mint>(N);
  k0 *= k0;
  for (auto&& x: ANS) x *= k0;
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}