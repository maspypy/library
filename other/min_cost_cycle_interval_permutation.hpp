
// (a[i],b[i]) がたくさんある. これらをサイクルに並べて
// sum |b[i]-a[i+1]| を最小化する
// return: {cost, order}
// とりあえずコストだけです
// https://codeforces.com/contest/1685/problem/D2
ll min_cost_cycle_interval_permutation(vi A, vi B) {
  int N = len(A);
  vi X;
  concat(X, A, B);
  UNIQUE(X);
  for (auto& x : A) x = LB(X, x);
  for (auto& x : B) x = LB(X, x);

  int n = len(X);
  UnionFind uf(n);
  vc<int> LR(n), RL(n);
  FOR(i, N) {
    uf.merge(A[i], B[i]);
    if (A[i] < B[i]) {
      LR[A[i]]++, LR[B[i]]--;
    } else {
      RL[B[i]]++, RL[A[i]]--;
    }
  }
  vi Y(n - 1);
  FOR(i, n - 1) Y[i] = X[i + 1] - X[i];
  FOR(i, n - 1) LR[i + 1] += LR[i], RL[i + 1] += RL[i];
  ll ans = 0;
  FOR(i, n - 1) {
    ll k = abs(LR[i] - RL[i]);
    if (k > 0) uf.merge(i, i + 1);
    ans += k * Y[i];
  }
  auto I = argsort(Y);
  for (auto& i : I) {
    if (uf.merge(i, i + 1)) ans += 2 * Y[i];
  }
  return ans;
}
