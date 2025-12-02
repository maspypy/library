// https://uoj.ac/contest/103/problem/1015
template <typename T>
vc<T> division_free_xor_convolution(vc<T> a, vc<T> b) {
  int K = topbit(len(a));
  int n = len(a);
  SHOW(a);
  SHOW(b);
  // y = x + 1
  // x = y - 1
  // supseset zeta
  for (int i = 1; i != n; i <<= 1) {
    for (int j = 0; j != n; j += i << 1) {
      for (int k = 0; k != i; k++) {
        a[j + k] -= a[i + j + k];
        b[j + k] -= b[i + j + k];
      }
    }
  }
  SHOW(a);
  SHOW(b);

  // ranked
  vv(T, A, 1 << K, 0);
  vv(T, B, 1 << K, 0);
  FOR(s, n) {
    int k = popcnt(s);
    A[s].resize(k + 1);
    B[s].resize(k + 1);
    A[s][k] += a[s];
    B[s][k] += b[s];
  }

  // subset zeta
  for (int i = 1; i != n; i <<= 1) {
    for (int j = 0; j != n; j += i << 1) {
      for (int k = 0; k != i; k++) {
        int m = len(A[j + k]);
        FOR(d, m) A[i + j + k][d] += A[j + k][d];
        FOR(d, m) B[i + j + k][d] += B[j + k][d];
      }
    }
  }

  // pointwise convolution
  FOR(s, n) { A[s] = convolution<T>(A[s], B[s]); }

  // subset mobius
  for (int i = 1; i != n; i <<= 1) {
    for (int j = 0; j != n; j += i << 1) {
      for (int k = 0; k != i; k++) {
        int m = len(A[j + k]);
        FOR(d, m) { A[i + j + k][d] -= A[j + k][d]; }
      }
    }
  }

  // unrank. ここを上手くやる
  FOR(s, n) {
    int m = popcnt(s);
    T x = 0;
    FOR_R(i, m, len(A[s])) { x = x + x + A[s][i]; }
    a[s] = x;
  }

  // y = x + 1
  for (int i = 1; i != n; i <<= 1) {
    for (int j = 0; j != n; j += i << 1) {
      for (int k = 0; k != i; k++) {
        a[j + k] += a[i + j + k];
      }
    }
  }
  return a;
}
