// 行ベクトルを整数型で表現
template <typename UINT>
vc<UINT> mat_inv(vc<UINT> A) {
  const int N = len(A);
  vc<UINT> B(N);
  FOR(i, N) B[i] = UINT(1) << i;

  FOR(k, N) {
    int p = -1;
    FOR(i, k, N) {
      if (A[i] >> k & 1) {
        p = i;
        break;
      }
    }
    assert(p != -1);
    swap(A[k], A[p]);
    swap(B[k], B[p]);

    FOR(i, N) {
      if (i != k && (A[i] >> k & 1)) {
        A[i] ^= A[k];
        B[i] ^= B[k];
      }
    }
  }
  return B;
}