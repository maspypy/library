#pragma once

template <typename T>
vc<vc<T>> ranked_zeta(const vc<T>& f) {
  int n = topbit(len(f));
  assert(len(f) == 1 << n);
  vv(T, Rf, 1 << n, n + 1);
  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];
  for (int i = 0; i < n; ++i) {
    for (int s = 0; s < (1 << n); ++s) {
      int t = s | 1 << i;
      if (s == t) continue;
      for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];
    }
  }
  return Rf;
}

template <typename T>
vc<T> ranked_mobius(vc<vc<T>>& Rf) {
  int n = topbit(len(Rf));
  assert(len(Rf) == 1 << n);
  for (int i = 0; i < n; ++i) {
    for (int s = 0; s < (1 << n); ++s) {
      int t = s | 1 << i;
      if (s == t) continue;
      for (int d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];
    }
  }
  vc<T> f(1 << n);
  for (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];
  return f;
}