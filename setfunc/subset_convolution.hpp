template <typename T, int LIM = 20>
vc<T> subset_convolution(vc<T>& A, vc<T>& B) {
  using F = array<T, LIM + 1>;
  int N = len(A);
  int log = topbit(N);
  assert(N == 1 << log);
  vc<F> RA(N), RB(N);
  FOR(s, N) RA[s][popcnt(s)] = A[s];
  FOR(s, N) RB[s][popcnt(s)] = B[s];
  // subset zeta
  FOR(i, log) FOR(s, 1 << log) if (!(s & 1 << i)) {
    int t = s | 1 << i;
    FOR(k, log + 1) RA[t][k] += RA[s][k], RB[t][k] += RB[s][k];
  }
  // pointwise multiplication
  FOR(s, 1 << log) {
    auto &f = RA[s], &g = RB[s];
    FOR_R(i, log + 1) {
      FOR3(j, 1, log - i + 1) f[i + j] += f[i] * g[j];
      f[i] *= g[0];
    }
  }
  // subset mobius
  FOR(i, log) FOR(s, 1 << log) if (!(s & 1 << i)) {
    int t = s | 1 << i;
    FOR(k, log + 1) RA[t][k] -= RA[s][k];
  }
  vc<T> res(N);
  FOR(s, N) res[s] = RA[s][popcnt(s)];
  return res;
}
