template <typename T, T INF = 1LL << 60>
vc<T> maxplus_convolution_concave(vc<T>& A, vc<T>& B) {
  ll NA = len(A), NB = len(B);
  ll LA = 0, RA = NA, LB = 0, RB = NB;
  while (LA < RA && A[LA] == -INF) ++LA;
  while (LA < RA && A[RA - 1] == -INF) --RA;
  while (LB < RB && B[LB] == -INF) ++LB;
  while (LB < RB && B[RB - 1] == -INF) --RB;
  // check concave
  FOR3(i, LA + 1, RA - 1) assert(2 * A[i] >= A[i - 1] + A[i + 1]);
  FOR3(i, LB + 1, RB - 1) assert(2 * B[i] >= B[i - 1] + B[i + 1]);

  vc<T> C(NA + NB - 1, -INF);
  int i = LA, j = LB;
  while (i < RA && j < RB) {
    C[i + j] = A[i] + B[j];
    if (i == RA - 1) ++j;
    elif (j == RB - 1)++ i;
    else {
      if (A[i + 1] + B[j] > A[i] + B[j + 1])
        ++i;
      else
        ++j;
    }
  }
  return C;
}
