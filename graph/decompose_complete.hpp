vc<vi> to_paths(ll N) {
  // 偶数頂点の無向完全グラフをハミルトンパスに分解
  assert(N >= 0 && N % 2 == 0);
  ll K = N / 2;
  vv(ll, paths, K, N);
  FOR(k, K) FOR(n, N) {
    auto &x = paths[k][n];
    x = k + (n & 1 ? (n + 1) / 2 : -(n / 2));
    if (x < 0)
      x += N;
    if (x >= N)
      x -= N;
  }
  return paths;
}

vc<vi> to_cycles(ll N) {
  // 奇数頂点の無向完全グラフをハミルトトンサイクルに分解
  assert(N >= 0 && N % 2 == 1);
  auto paths = to_paths(N - 1);
  FORIN(P, paths) P.eb(N - 1);
  return paths;
}

vc<vi> to_matchings(ll N) {
  // 偶数頂点の無向完全グラフをマッチングに分解
  // 辺彩色しているといってもよい
  // このうちどの 2 個を選んでも、ハミルトンサイクルになる。
  assert(N > 0 && N % 2 == 0);
  vv(ll, match, N - 1, N);
  ll mod = N - 1;
  FOR(a, mod) {
    match[a][0] = N - 1, match[a][1] = a;
    FOR3(k, 1, N / 2) {
      ll b = a - k, c = a + k;
      if (b < 0)
        b += mod;
      if (c >= mod)
        c -= mod;
      match[a][2 * k] = b, match[a][2 * k + 1] = c;
    }
  }
  return match;
}

pair<vc<vi>, vi> to_cycles_and_matching(ll N) {
  // 偶数頂点の無向完全グラフを、ハミルトンサイクルと 1 つのマッチングに分解
  assert(N > 0 && N % 2 == 0);
  vv(ll, cycles, N / 2 - 1, N);
  ll mod = N - 1;
  FOR(a, mod - 1) if (a % 2 == 0) {
    auto &C = cycles[a / 2];
    // 和が 2a, 2a+2 のどちらかになるときに結ぶ
    C[0] = a;
    FOR(i, N - 2) {
      ll nxt = (i % 2 == 0 ? 2 * a + 2 - C[i] : 2 * a - C[i]);
      if (nxt < 0)
        nxt += mod;
      if (nxt >= mod)
        nxt -= mod;
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