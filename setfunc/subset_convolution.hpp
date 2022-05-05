template <typename T>
vc<T> subset_convolution(vc<T>& A, vc<T>& B) {
  auto RA = ranked_zeta(A);
  auto RB = ranked_zeta(A);
  FOR(s, len(RA)) RA[s] *= RB[s];
  return ranked_mobius(RA);
}
