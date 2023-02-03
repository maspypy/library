// 行ベクトルを整数型で表現
template <typename UINT>
vc<UINT> mat_inv(vc<UINT> A) {
  const int N = len(A);
  vc<UINT> B(N);
  FOR(i, N) B[i] = u64(1) << i;
  FOR(i, N) FOR(j, N) if (j != i) {
    if (chmin(A[i], A[i] ^ A[j])) B[i] ^= B[j];
  }
  vc<UINT> res(N);
  FOR(i, N) res[topbit(A[i])] = B[i];
  return res;
}