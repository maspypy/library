#pragma once

template <typename T, int LIM>
vc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {
  int n = topbit(len(f));
  assert(n <= LIM);
  assert(len(f) == 1 << n);
  vc<array<T, LIM + 1>> Rf(1 << n);
  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];
  for (int i = 0; i < n; ++i) {
    int w = 1 << i;
    for (int p = 0; p < (1 << n); p += 2 * w) {
      for (int s = p; s < p + w; ++s) {
        int t = s | 1 << i;
        for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];
      }
    }
  }
  return Rf;
}

template <typename T, int LIM>
vc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf) {
  int n = topbit(len(Rf));
  assert(len(Rf) == 1 << n);
  for (int i = 0; i < n; ++i) {
    int w = 1 << i;
    for (int p = 0; p < (1 << n); p += 2 * w) {
      for (int s = p; s < p + w; ++s) {
        int t = s | 1 << i;
        for (int d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];
      }
    }
  }
  vc<T> f(1 << n);
  for (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];
  return f;
}