// 偶数頂点の無向完全グラフをハミルトンパスに分解
vvc<int> to_paths(ll N) {
  assert(N >= 0 && N % 2 == 0);
  ll K = N / 2;
  vv(int, paths, K, N);
  FOR(k, K) FOR(n, N) {
    auto &x = paths[k][n];
    x = k + (n & 1 ? (n + 1) / 2 : -(n / 2));
    if (x < 0) x += N;
    if (x >= N) x -= N;
  }
  return paths;
}

// 奇数頂点の無向完全グラフをハミルトトンサイクルに分解
vvc<int> to_cycles(ll N) {
  assert(N >= 0 && N % 2 == 1);
  auto paths = to_paths(N - 1);
  for (auto &&P: paths) P.eb(N - 1);
  return paths;
}

// https://codeforces.com/contest/12/problem/E
// 偶数頂点の無向完全グラフをマッチングに分解
// 辺彩色しているといってもよい
// このうちどの 2 個を選んでも、ハミルトンサイクルになる。
vvc<pair<int, int>> to_matchings(ll N) {
  assert(N > 0 && N % 2 == 0);
  vvc<pair<int, int>> res(N - 1);
  const int mod = N - 1;
  FOR(a, mod) {
    res[a].reserve(N / 2);
    res[a].eb(N - 1, a);
    int x = a, y = a;
    FOR(N / 2 - 1) {
      --x, ++y;
      if (x < 0) x += N - 1;
      if (y >= N - 1) y -= N - 1;
      res[a].eb(x, y);
    }
  }
  return res;
}

// 偶数頂点の無向完全グラフを、ハミルトンサイクルと 1 つのマッチングに分解
pair<vc<vi>, vi> to_cycles_and_matching(ll N) {
  assert(N > 0 && N % 2 == 0);
  vv(ll, cycles, N / 2 - 1, N);
  ll mod = N - 1;
  FOR(a, mod - 1) if (a % 2 == 0) {
    auto &C = cycles[a / 2];
    // 和が 2a, 2a+2 のどちらかになるときに結ぶ
    C[0] = a;
    FOR(i, N - 2) {
      ll nxt = (i % 2 == 0 ? 2 * a + 2 - C[i] : 2 * a - C[i]);
      if (nxt < 0) nxt += mod;
      if (nxt >= mod) nxt -= mod;
      C[i + 1] = nxt;
    }
    C[N - 1] = mod;
  }
  vi match(N);
  FOR(a, mod / 2) {
    ll b = mod - 2 - a;
    match[2 * a] = a, match[2 * a + 1] = b;
  }
  match[N - 2] = N - 2, match[N - 1] = N - 1;
  return {cycles, match};
}