pair<int, vc<int>> scc_tournament_by_indegrees(vc<int> indeg) {
  int N = len(indeg);
  auto I = argsort(indeg);
  vc<int> ANS(N);
  ll sm = 0;
  int nxt = 0;
  FOR(i, N) {
    int v = I[i];
    ANS[v] = nxt;
    // I[0:i] がひとつの成分かどうか
    sm += indeg[v];
    ll TS = sm - (i + 1) * i / 2;
    if (TS == 0) ++nxt;
  }
  return {nxt, ANS};
}
