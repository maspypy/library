// frm, to, 重複度
// https://codeforces.com/contest/1951/problem/I
bool K_Forest(ll K, int N, vc<tuple<int, int, ll>> dat) {
  ll sm = 0;
  ll M = len(dat);
  for (auto& [a, b, cnt] : dat) sm += cnt;
  if (sm > K * (N - 1)) return false;

  int s = 0;
  auto left = [&](int v) -> int { return 1 + v; };
  auto right = [&](int i) -> int { return 1 + N + i; };
  int t = right(M);

  FOR(r, N) {
    MaxFlow<ll> G(t + 1, s, t);
    FOR(v, N) if (r != v) G.add(s, left(v), K);

    FOR(i, M) {
      auto [a, b, c] = dat[i];
      G.add(left(a), right(i), infty<ll>);
      G.add(left(b), right(i), infty<ll>);
      G.add(right(i), t, c);
    }
    if (G.flow() < sm) return 0;
  }
  return 1;
}
