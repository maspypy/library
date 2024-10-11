
// https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_d
// empty OR 辞書順最小
vc<int> inverse_z_algorithm(vc<int> Z) {
  int N = len(Z);
  if (Z[0] != N) return {};
  UnionFind uf(N);
  vvc<int> NEQ(N);
  int i = 1, j = 0;
  while (i < N) {
    while (i + j < N) {
      if (Z[i] != j) {
        uf.merge(j, i + j), ++j;
      } else {
        NEQ[j].eb(i + j), NEQ[i + j].eb(j);
        break;
      }
    }
    if (Z[i] != j) return {};
    if (j == 0) {
      ++i;
      continue;
    }
    int k = 1;
    while (i + k < N && k + Z[k] < j) {
      if (Z[i + k] != Z[k]) return {};
      ++k;
    }
    i += k, j -= k;
  }
  vvc<int> vs(N);
  FOR(v, N) vs[uf[v]].eb(v);
  vc<int> ANS(N, -1);
  FOR(v, N) {
    int r = uf[v];
    if (ANS[r] != -1) continue;
    vc<int> tmp;
    for (auto& w: vs[r]) {
      for (auto& to: NEQ[w]) {
        if (ANS[to] != -1) tmp.eb(ANS[to]);
      }
    }
    int x = mex(tmp);
    for (auto& w: vs[r]) ANS[w] = x;
  }
  return ANS;
}
