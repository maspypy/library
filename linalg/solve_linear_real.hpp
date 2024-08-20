
// 正方行列 full rank 前提
// 誤差で死ぬパターンがないかは知らない
// https://codeforces.com/contest/267/problem/C
template <typename T>
vc<T> solve_linear_real(vc<vc<T>> a, vc<T> b, int n = -1, int m = -1) {
  if (n == -1) { n = len(a); }
  assert(n == len(a) && n == len(b));
  FOR(i, n) assert(len(a[i]) == n);
  FOR(i, n) {
    T mx = abs(a[i][i]);
    int k = i;
    FOR(j, i + 1, n) if (chmax(mx, abs(a[j][i]))) k = j;
    if (k != i) { swap(a[i], a[k]), swap(b[i], b[k]); }
    T c = T(1) / a[i][i];
    for (auto&& x: a[i]) x *= c;
    b[i] *= c;
    FOR(k, n) {
      if (i != k) {
        T c = a[k][i];
        FOR(j, i, n) a[k][j] -= c * a[i][j];
        b[k] -= c * b[i];
      }
    }
  }
  return b;
}