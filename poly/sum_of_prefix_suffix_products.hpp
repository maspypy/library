#include "poly/convolution.hpp"

/*
多項式の列 f0, f1, ..., f{N-1} および g0, g1, ..., g{N-1} を与える。
f0f1f2f3 + f0f1f2g3 + f0f1g2g3 + f0g1g2g3 + g0g1g2g3
のような総和を求める。分割統治で O(Nlog^2N)。N は次数の総和。
https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_p
*/
template <typename mint>
vc<mint> sum_of_prefix_suffix_products(vvc<mint> F, vvc<mint> G) {
  int n = len(F);
  using poly = vc<mint>;
  auto add = [&](poly f, poly g) -> poly {
    poly h(max(len(f), len(g)));
    FOR(i, len(f)) h[i] += f[i];
    FOR(i, len(g)) h[i] += g[i];
    return h;
  };

  auto dfs = [&](auto& dfs, int l, int r) -> tuple<poly, poly, poly> {
    if (r == l + 1) { return {add(F[l], G[l]), F[l], G[l]}; }
    int m = (l + r) / 2;
    auto [pl, fl, gl] = dfs(dfs, l, m);
    auto [pr, fr, gr] = dfs(dfs, m, r);
    poly p = convolution(pl, gr);
    FOR(i, len(gr)) pr[i] -= gr[i];
    p = add(p, convolution(fl, pr));
    return {p, convolution(fl, fr), convolution(gl, gr)};
  };
  auto [p, f, g] = dfs(dfs, 0, n);
  return p;
}