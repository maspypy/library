// https://oeis.org/A006125
template <typename mint>
vc<mint> count_labeled_undirected(int N) {
  vc<mint> F(N + 1);
  mint pow2 = 1;
  F[0] = 1;
  FOR(i, 1, N + 1) F[i] = F[i - 1] * pow2, pow2 += pow2;
  return F;
}
