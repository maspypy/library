#include "nt/integer_kth_root.hpp"

// Dirichlet 級数自体は vc<T> で持つことにする.
// この構造体がそれに対する操作を持っていることにする.
struct Dirichlet {
  u64 N;
  u32 t, sq, n;
  Dirichlet(u64 N) : N(N) {
    assert(N <= u64(1) << 50);
    sq = sqrtl(N);
    t = (u64(sq) * sq + sq <= N ? sq : sq - 1);
    n = t + sq + 1;
    // [0,1,...,t,N/sq,...,N/1] (t<sq の場合の sq も両対応)
  };

  inline u32 get_index(u64 d) {
    assert(d > 0);
    return (d <= t ? d : n - u32(double(N) / d));
  }

  inline u64 get_floor(u32 i) { return (i <= t ? i : double(N) / (n - i)); }

  template <typename T>
  vc<T> convolution(vc<T> &F, vc<T> &G) {
    assert(len(F) == n && len(G) == n);
    if (N == 1) return {T(0), F[1] * G[1]};
    vc<T> f(n), g(n);
    FOR(i, 1, n) f[i] = F[i] - F[i - 1];
    FOR(i, 1, n) g[i] = G[i] - G[i - 1];

    vc<T> H(n);
    u64 K = integer_kth_root(3, N);
    u64 S = K * K;
    // S 以下であるような商について
    for (u64 a = 1; a <= K; ++a) {
      H[(a * a <= sq ? a * a : n - N / (a * a))] += f[a] * g[a];
      if (a * (a + 1) <= t) {  // a * small = small
        u64 ub = t / a;
        for (u64 b = a + 1; b <= ub; ++b) {
          H[a * b] += f[a] * g[b] + f[b] * g[a];
        }
      }
      // a * small = large
      {
        u64 q = min<u64>(S / a, t);
        for (u64 b = max(a, t / a) + 1; b <= q; ++b) {
          H[n - N / (a * b)] += f[a] * g[b] + f[b] * g[a];
        }
      }
      // a * large = large
      if (N / sq <= S / a) {
        u64 p = N / (S / a + 1) + 1;
        for (u64 b = p; b <= sq; ++b) {
          H[n - N / (a * (N / b))] += f[a] * g[n - b] + g[a] * f[n - b];
        }
      }
    }
    FOR(i, 1, n) H[i] += H[i - 1];
    for (u64 z = 1; N / z > S; ++z) {
      u64 M = N / z;
      u64 ub = sqrtl(M);
      H[n - z] = 0;
      for (u64 a = 1; a <= ub; ++a) {
        int idx = get_index(M / a);
        H[n - z] += f[a] * G[idx] + g[a] * F[idx];
      }
      H[n - z] -= F[ub] * G[ub];
    }
    return H;
  }

  // G=H/F
  template <typename T>
  vc<T> div(vc<T> &H, vc<T> &F) {
    assert(len(F) == n && len(H) == n && F[1] != 0);
    if (N == 1) return {T(0), H[1] / F[1]};
    T c = F[1].inverse();
    for (auto &x : F) x *= c;

    vc<T> f(n), g(n), h(n);
    FOR(i, 1, n) f[i] = F[i] - F[i - 1];
    FOR(i, 1, n) h[i] = H[i] - H[i - 1];

    u64 K = integer_kth_root(3, N);
    u64 S = max<u64>(sq, K * K);
    g[1] = H[1];

    for (u64 i = 2; i < n; ++i) {
      u64 a = get_floor(i);
      if (a > S) break;
      g[i] = h[i] - g[1] * f[i];
      if (a * a <= S) h[get_index(a * a)] -= f[i] * g[i];
      u64 ub = min(i - 1, S / a);
      FOR(b, 2, ub + 1) { h[get_index(a * b)] -= f[i] * g[b] + f[b] * g[i]; }
    }
    vc<mint> G = cumsum<mint>(g, 0);
    for (u64 z = N / (S + 1); z >= 1; --z) {
      G[n - z] = H[n - z] - g[1] * F[n - z];
      u64 M = N / z;
      u64 ub = sqrtl(M);
      G[n - z] += F[ub] * G[ub];
      for (u64 a = 2; a <= ub; ++a) {
        int idx = get_index(M / a);
        G[n - z] -= f[a] * G[idx] + g[a] * F[idx];
      }
    }
    for (auto &x : G) x *= c;
    c = c.inverse();
    for (auto &x : F) x *= c;
    for (auto &x : H) x *= c;
    return G;
  }
};
