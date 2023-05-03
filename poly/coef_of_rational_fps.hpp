#include "poly/fps_div.hpp"
#include "poly/ntt_doubling.hpp"

template <typename mint>
mint coef_of_rational_fps_small(vector<mint> P, vector<mint> Q, ll N) {
  int m = len(Q) - 1;
  using poly = vc<mint>;
  auto dfs = [&](auto& dfs, ll N) -> poly {
    // x^N mod G
    if (N == 0) return {1};
    poly f = dfs(dfs, N / 2);
    f = convolution(f, f);
    if (N & 1) f.insert(f.begin(), mint(0));
    FOR_R(i, m, len(f)) { FOR(j, 1, len(Q)) f[i - j] -= Q[j] * f[i]; }
    f.resize(m);
    return f;
  };
  poly f = dfs(dfs, N);
  FOR(i, m) { FOR(j, 1, len(Q)) P[i] -= Q[j] * P[i - j]; }
  mint res = 0;
  FOR(i, m) res += f[i] * P[i];
  return res;
}

template <typename mint>
mint coef_of_rational_fps_ntt(vector<mint> P, vector<mint> Q, ll N) {
  int log = 0;
  while ((1 << log) < len(Q)) ++log;
  int n = 1 << log;
  P.resize(2 * n), Q.resize(2 * n);
  ntt(P, 0), ntt(Q, 0);
  vc<int> btr(n);
  FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }

  int t = mint::ntt_info().fi;
  mint r = mint::ntt_info().se;
  mint dw = r.inverse().pow((1 << t) / (2 * n));

  vc<mint> S, T;
  while (N >= n) {
    mint w = inv<mint>(2);
    T.resize(n);
    FOR(i, n) T[i] = Q[2 * i + 0] * Q[2 * i + 1];
    S.resize(n);
    if (N & 1) {
      for (auto& i: btr) {
        S[i] = (P[2 * i] * Q[2 * i + 1] - P[2 * i + 1] * Q[2 * i]) * w;
        w *= dw;
      }
    } else {
      FOR(i, n) {
        S[i] = (P[2 * i] * Q[2 * i + 1] + P[2 * i + 1] * Q[2 * i]) * w;
      }
    }
    swap(P, S), swap(Q, T);
    N >>= 1;
    if (N < n) break;
    ntt_doubling(P);
    ntt_doubling(Q);
  }
  ntt(P, 1), ntt(Q, 1);
  return fps_div(P, Q)[N];
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
    if (n <= 20) {
      return coef_of_rational_fps_small(P, Q, N);
    } else {
      return coef_of_rational_fps_ntt(P, Q, N);
    }
  }
}