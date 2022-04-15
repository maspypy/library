template <typename mint>
vector<mint> find_linear_rec(vector<mint>& A) {
  int N = len(A);
  vc<mint> B = {1}, C = {1};
  int l = 0, m = 1;
  mint p = 1;
  FOR(i, N) {
    mint d = A[i];
    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }
    if (d == 0) {
      ++m;
      continue;
    }
    auto tmp = C;
    mint q = d / p;
    if (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C), 0);
    FOR(j, len(B)) C[j + m] -= q * B[j];
    if (l + l <= i) {
      B = tmp;
      l = i + 1 - l, m = 1;
      p = d;
    } else {
      ++m;
    }
  }
  return C;
}
