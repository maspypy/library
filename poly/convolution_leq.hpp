// https://codeforces.com/contest/1641/problem/E
template <typename T>
vc<T> convolution_leq(vc<T> f, vc<T> g, bool strict) {
  /*
  h[k] = sum_{i+j=k and i<=j} f_ig_j
  if strict: i < j
  */
  vc<T> h(len(f) + len(g) - 1);
  ll THRESH = 60;

  ll N = max(len(f), len(g));
  vc<pair<int, int>> que;
  que.eb(0, N);
  while (!que.empty()) {
    auto [L, R] = que.back();
    que.pop_back();
    if (R - L <= THRESH) {
      FOR3(i, L, min<int>(R, len(f))) FOR3(j, i + 1, min<int>(R, len(g))) {
        h[i + j] += f[i] * g[j];
      }
      continue;
    }
    ll M = (L + R) / 2;
    que.eb(L, M), que.eb(M, R);
    if (len(f) <= L || len(g) <= M) continue;
    auto p = convolution<T>({f.begin() + L, f.begin() + min<int>(M, len(f))},
                            {g.begin() + M, g.begin() + min<int>(R, len(g))});
    FOR(i, len(p)) h[L + M + i] += p[i];
  }
  if (!strict) { FOR(i, min(len(f), len(g))) h[i + i] += f[i] * g[i]; }
  return h;
}