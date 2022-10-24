// pair<新しい状態、今の成分 → 新しい成分>
vc<pair<vc<int>, vc<int>>> connected_dp_next_states(vc<int> now) {
  int N = len(now);
  vc<pair<vc<int>, vc<int>>> res;
  FOR(s, 1 << N) {
    vc<int> par(N + N);
    FOR(i, N) par[i] = (s & 1 << i ? i : -1);
    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i] + N);
    auto find = [&](int x) -> int {
      while (par[x] != x) { x = par[x] = par[par[x]]; }
      return x;
    };
    auto merge = [&](int a, int b) -> void {
      a = find(a), b = find(b);
      if (a == b) return;
      if (a > b) swap(a, b);
      par[b] = a;
    };

    FOR(i, N - 1) if (par[i] != -1 && par[i + 1] != -1) merge(i, i + 1);
    FOR(i, N) if (par[i] != -1 && par[N + i] != -1) merge(i, N + i);
    FOR(i, N + N) if (par[i] != -1) par[i] = find(i);
    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;
    res.eb(vc<int>(par.begin(), par.begin() + N),
           vc<int>(par.begin() + N, par.end()));
  }
  return res;
}