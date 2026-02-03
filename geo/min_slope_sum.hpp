
// https://uoj.ac/contest/104/problem/1037
// A, B が下側凸包になっていて A[i]+B[j] の x 座標が正であることが保証
// A[i]+B[j] の min slope を求める. O(log N+log M)
template <typename P>
P min_slope_sum(vc<P>& A, vc<P>& B) {
  int N = len(A), M = len(B);
  ll NL = 0, NR = N;
  ll ML = 0, MR = M;

  auto better = [&](P p, P q) -> bool { return p.y * q.x < q.y * p.x; };

  while (NL + 1 < NR && ML + 1 < MR) {
    ll n = (NL + NR) / 2;
    ll m = (ML + MR) / 2;
    P p = A[n] + B[m];
    P pa = A[n] - A[n - 1];
    P pb = B[m] - B[m - 1];
    if (better(pa, pb)) {
      if (better(pb, p)) {
        NL = n;
      } else {
        MR = m;
      }
    } else {
      if (better(pa, p)) {
        ML = m;
      } else {
        NR = n;
      }
    }
  }
  while (ML + 1 < MR) {
    ll n = NL, m = (ML + MR) / 2;
    P p = A[n] + B[m];
    (better(p, A[n] + B[m - 1]) ? ML : MR) = m;
  }
  while (NL + 1 < NR) {
    ll m = ML, n = (NL + NR) / 2;
    P p = A[n] + B[m];
    (better(p, A[n - 1] + B[m]) ? NL : NR) = n;
  }
  return A[NL] + B[ML];
}
