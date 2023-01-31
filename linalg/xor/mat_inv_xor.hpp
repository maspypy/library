// 行ベクトルを整数型で表現
template <typename UINT>
vc<UINT> mat_inv_xor(vc<UINT> &A, bool keep_A = 1) {
  vc<UINT> tmp;
  if (keep_A) tmp = A;
  const int N = len(A);
  vc<UINT> B(N);
  FOR(i, N) B[i] = u64(1) << i;
  FOR(i, N) {
    FOR(k, i, N) if (A[k] >> i & 1) {
      if (k != i) { swap(A[i], A[k]), swap(B[i], B[k]); }
      break;
    }
    if (!(A[i] >> i & 1)) return {};
    FOR(k, N) if (i != k) {
      if (!(A[k] >> i & 1)) continue;
      A[k] ^= A[i];
      B[k] ^= B[i];
    }
  }
  if (keep_A) swap(A, tmp);
  return B;
}