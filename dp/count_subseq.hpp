template <typename mint, typename T, typename STRING>
mint count_subseq(STRING S) {
  auto key = S;
  UNIQUE(key);
  for(auto&& x : S)x=LB(key,x);
  vc<int> IDX(len(key),-1);
  ll N = len(S);
  vc<mint> DP(N + 1);
  DP[0] = 1;
  FOR(i, N) {
    T c = S[i];
    DP[i + 1] = DP[i] + DP[i];
    if (IDX[c] != -1) { DP[i + 1] -= DP[IDX[c]]; }
    IDX[c] = i;
  }
  return DP.back();
}
