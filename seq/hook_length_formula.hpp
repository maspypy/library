#pragma once

template <typename mint>
mint hook_length_formula(vc<int> A) {
  if (len(A) == 0) return 1;
  int H = len(A), W = A[0];
  FOR(i, H - 1) assert(A[i] >= A[i + 1]);
  vc<int> B(W);
  reverse(all(A));
  mint ANS = fact<mint>(SUM<int>(A));
  for (auto&& a: A) {
    FOR(j, a) { ANS *= inv<mint>(B[j] + a - j), ++B[j]; }
  }
  return ANS;
}
