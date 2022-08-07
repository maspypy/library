template <typename mint>
vc<mint> all_inverse(vc<mint>& X) {
  for (auto&& x: X) assert(x != mint(0));
  int N = len(X);
  vc<mint> res(N + 1);
  res[0] = mint(1);
  FOR(i, N) res[i + 1] = res[i] * X[i];
  mint t = res.back().inverse();
  res.pop_back();
  FOR_R(i, N) {
    res[i] *= t;
    t *= X[i];
  }
  return res;
}