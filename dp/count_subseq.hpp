template <typename mint, typename T>
mint count_subseq(vc<T> S) {
  ll N = len(S);
  map<T, ll> IDX;
  vc<mint> DP(N + 1);
  DP[0] = 1;
  FOR(i, N) {
    T c = S[i];
    DP[i + 1] = DP[i] + DP[i];
    if (IDX.count(c)) { DP[i + 1] -= DP[IDX[c]]; }
    IDX[c] = i;
  }
  return DP.back();
}
