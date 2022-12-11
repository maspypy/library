// 単純グラフの存在判定。Erdos-Gallai の定理。
bool check_degree_sequence(vc<int> deg) {
  const int N = len(deg);
  if (MAX(deg) >= N) return false;
  if (SUM<ll>(deg) % 2 != 0) return false;
  vc<int> CNT(N);
  for (auto&& x: deg) CNT[x]++;
  int p = 0;
  FOR(x, N) FOR(CNT[x]) deg[p++] = x;

  vi A(N + 1), B(N + 1);
  FOR(i, N) {
    int d = deg[i];
    A[i + 1] += 2 * i - d;
    if (d < i) { B[0] += 1, B[d] -= 1, A[d] += d, A[i + 1] -= d; }
    if (d >= i) { B[0] += 1, B[i + 1] -= 1; }
  }
  A = cumsum<ll>(A, 0);
  B = cumsum<ll>(B, 0);
  FOR(k, N + 1) {
    ll x = A[k] + B[k] * k;
    print(k, x);
    if (x < 0) return false;
  }
}

vc<pair<int, int>> construct_from_degree_sequence(vc<int> deg) {
  if (!check_degree_sequence(deg)) return {};
  vvc<int> dat(N);
  FOR(v, N) dat[deg[v]].eb(v);
  vc<pair<int, int>> edges;
  int mx = N - 1;
  FOR(N) {
    while (len(dat[mx]) == 0) --mx;
    int v = pick(dat[mx]);
    vc<int> nbd;
    int k = mx;
    while (len(nbd) < deg[v]) {
      if (k == 0) return {};
      if (len(dat[k]) == 0) {
        --k;
        continue;
      }
      int x = pick(dat[k]);
      nbd.eb(x);
    }
    for (auto&& x: nbd) {
      edges.eb(v, x);
      --deg[x];
      dat[deg[x]].eb(x);
    }
    deg[v] = 0;
  }
  return edges;
}