
// https://atcoder.jp/contests/arc044/tasks/arc044_d
// 辞書最小 OR
// 入力は [0,N) permutation
vc<int> inverse_suffix_array(vc<int> A) {
  int N = len(A);
  vc<int> rk(N);
  FOR(i, N) rk[A[i]] = i;
  FOR(i, N) assert(rk[A[i]] == i && A[rk[i]] == i);
  vc<int> S(N);
  FOR(k, 1, N) {
    int i = A[k - 1], j = A[k];
    S[j] = S[i];
    if (i < N - 1 && (j == N - 1 || (rk[i + 1] > rk[j + 1]))) S[j]++;
  }
  return S;
}
