
// (status, perm)
// 0: no solution
// 1: unique solution
// 2: many solution (return one solution)
// https://atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_h
pair<int, vc<int>> kth_root_permutation(ll k, vc<int>& A) {
  int N = len(A);
  vc<bool> done(N);
  // サイクル長 → サイクル
  vvc<int> dat(N + 1);
  FOR(v, N) if (!done[v]) {
    vc<int> C = {v};
    while (1) {
      int nxt = A[C.back()];
      if (nxt == v) break;
      C.eb(nxt);
    }
    int n = len(C);
    for (auto&& x: C) {
      done[x] = 1;
      dat[n].eb(x);
    }
  }

  int stat = 1;
  vc<int> ANS(N, -1);

  FOR_R(m, 1, N + 1) {
    ll d = m / gcd(m, k);
    while (len(dat[d]) >= m) {
      vc<int> tmp = {dat[d].end() - m, dat[d].end()};
      dat[d].resize(len(dat[d]) - m);
      vc<int> C(m);
      if (d < m) stat = 2;
      int p = 0;
      FOR(i, m) {
        if (i % d == 0) {
          p = i / d;
        } else {
          p = (p + k) % m;
        }
        C[p] = tmp[i];
      }
      FOR(i, m) {
        int j = (i == m - 1 ? 0 : i + 1);
        ANS[C[i]] = C[j];
      }
    }
  }
  if (MIN(ANS) == -1) return {0, {}};
  return {stat, ANS};
}
