#include "poly/convolution.hpp"
#include "poly/middle_product.hpp"
#include "poly/fps_div.hpp"

// P(x)/Q(x) の [N, N+d] 部分を計算
// https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b
template <typename mint>
vc<mint> slice_rational_fps(vc<mint> P, vc<mint> Q, ll N) {
  assert(N >= 0 && Q[0] == mint(1) && len(P) < len(Q));
  const int d = len(Q) - 1;
  if (d == 0) { return vc<mint>(); }
  P.resize(len(Q) - 1);

  auto dfs = [&](auto& dfs, ll N, vc<mint> Q) -> vc<mint> {
    // 1/Q の [N-d+1, N]
    if (N == 0) {
      vc<mint> f(d);
      f[d - 1] = 1;
      return f;
    }
    vc<mint> R = Q;
    FOR(i, d + 1) if (i & 1) R[i] = -R[i];
    vc<mint> V = convolution(Q, R);
    FOR(i, d + 1) V[i] = V[2 * i];
    V.resize(d + 1);
    vc<mint> W = dfs(dfs, N / 2, V);
    vc<mint> S(d + d);
    if (N % 2 == 0) FOR(i, d) S[2 * i + 1] = W[i];
    if (N % 2 == 1) FOR(i, d) S[2 * i] = W[i];
    reverse(all(R));
    return middle_product(S, R);
  };
  vc<mint> A = dfs(dfs, N, Q);
  vc<mint> f = convolution(A, Q);
  f = {f.begin() + d, f.end() - 1};
  f = fps_div(f, Q);
  for (auto&& x: f) x = -x;
  A.insert(A.end(), all(f));
  reverse(all(P));
  return middle_product(A, P);
}