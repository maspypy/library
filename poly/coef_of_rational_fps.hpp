#include "poly/fps_div.hpp"
#include "poly/ntt_doubling.hpp"

template <typename mint>
mint coef_of_rational_fps_small(vector<mint> P, vector<mint> Q, ll N) {
  assert(len(Q) <= 16);
  int m = len(Q) - 1;
  assert(len(P) == m);
  if (m == 0) return mint(0);
  vc<u32> Q32(m + 1);
  FOR(i, m + 1) Q32[i] = (-Q[i]).val;

  using poly = vc<u64>;
  auto dfs = [&](auto& dfs, const ll N) -> poly {
    // x^N mod G
    if (N == 0) return {1};
    poly f = dfs(dfs, N / 2);
    poly g(len(f) * 2 - 1 + (N & 1));
    FOR(i, len(f)) FOR(j, len(f)) { g[i + j + (N & 1)] += f[i] * f[j]; }
    FOR(i, len(g)) g[i] = mint(g[i]).val;
    FOR_R(i, len(g)) {
      g[i] = mint(g[i]).val;
      if (i >= m) FOR(j, 1, len(Q)) g[i - j] += Q32[j] * g[i];
    }
    g.resize(m);
    return g;
  };
  poly f = dfs(dfs, N);
  FOR(i, m) { FOR(j, 1, i + 1) P[i] -= Q[j] * P[i - j]; }
  u64 res = 0;
  FOR(i, m) res += f[i] * P[i].val;
  return res;
}

template <typename mint>
mint coef_of_rational_fps_ntt(vector<mint> P, vector<mint> Q, ll N) {
  mint base = 0;
  if (len(P) >= len(Q)) {
    auto [f, g] = poly_divmod(P, Q);
    if (N < len(f)) base += f[N];
    swap(P, g);
  }
  assert(len(P) < len(Q));

  int n = 1;
  while (n < len(Q)) n += n;

  vc<mint> W(n);
  {
    vc<int> btr(n);
    int log = topbit(n);
    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }
    int t = mint::ntt_info().fi;
    mint r = mint::ntt_info().se;
    mint dw = r.inverse().pow((1 << t) / (2 * n));
    mint w = inv<mint>(2);
    for (auto& i: btr) { W[i] = w, w *= dw; }
  }

  P.resize(2 * n), Q.resize(2 * n);
  ntt(P, 0), ntt(Q, 0);

  while (N >= n) {
    if (N % 2 == 0) {
      FOR(i, n) {
        P[i] = (P[2 * i] * Q[2 * i + 1] + P[2 * i + 1] * Q[2 * i])
               * inv<mint>(2);
      }
    } else {
      FOR(i, n) {
        P[i] = (P[2 * i] * Q[2 * i + 1] - P[2 * i + 1] * Q[2 * i]) * W[i];
      }
    }
    FOR(i, n) Q[i] = Q[2 * i] * Q[2 * i + 1];
    P.resize(n), Q.resize(n);
    N /= 2;
    if (N < n) break;
    ntt_doubling(P), ntt_doubling(Q);
  }
  ntt(P, 1), ntt(Q, 1);
  Q = fps_inv<mint>(Q);
  mint ans = 0;
  FOR(i, N + 1) ans += P[i] * Q[N - i];
  return base + ans;
}

template <typename mint>
mint coef_of_rational_fps_convolution(vector<mint> P, vector<mint> Q, ll N) {
  P.resize(len(Q) - 1);
  if (len(P) == 0) return 0;
  while (N >= len(P)) {
    vc<mint> Q1 = Q;
    FOR(i, len(Q1)) if (i & 1) Q1[i] = -Q1[i];
    P = convolution(P, Q1);
    Q = convolution(Q, Q1);
    FOR(i, len(Q1)) Q[i] = Q[2 * i];
    FOR(i, len(Q1) - 1) P[i] = P[2 * i | (N & 1)];
    P.resize(len(Q1) - 1);
    Q.resize(len(Q1));
    N /= 2;
  }
  return fps_div(P, Q)[N];
}

template <typename mint>
mint coef_of_rational_fps(vector<mint> P, vector<mint> Q, ll N) {
  assert(len(P) < len(Q) && Q[0] == mint(1));
  if (N == 0) return (P.empty() ? mint(0) : P[0]);
  int n = len(Q);
  if (mint::ntt_info().fi != -1) {
    if (n <= 10) {
      return coef_of_rational_fps_small(P, Q, N);
    } else {
      return coef_of_rational_fps_ntt(P, Q, N);
    }
  }
  return (n <= 16 ? coef_of_rational_fps_small(P, Q, N)
                  : coef_of_rational_fps_convolution(P, Q, N));
}