
#include "linalg/solve_linear.hpp"
#include "mod/all_inverse.hpp"

/*
return: polynomial sequence F[0](x),...,F[m](x)
F[0](n)A[n+m]+...+F[m](n)A[n]=0
何かが失敗したら return empty
*/
template <typename mint>
vvc<mint> find_p_recursive(vc<mint> A, int max_m, int max_deg) {
  int N = (1 + max_m) * (1 + max_deg);
  auto idx = [&](int i, int d) -> int { return (1 + max_deg) * i + d; };

  assert(len(A) >= N + max_m);
  vv(mint, mat, N, N);
  FOR(row, N) {
    FOR(i, max_m + 1) {
      mint pw = 1;
      FOR(j, max_deg + 1) { mat[row][idx(i, j)] = A[row + max_m - i] * pw, pw *= row; }
    }
  }
  auto Xs = solve_linear<mint>(mat, vc<mint>(N, mint(0)));
  Xs.erase(Xs.begin());
  if (Xs.empty()) return {};
  vvc<mint> F(max_m + 1);
  FOR(i, max_m + 1) {
    vc<mint> f(max_deg + 1);
    FOR(j, max_deg + 1) f[j] = Xs[0][idx(i, j)];
    while (len(f) && f.back() == mint(0)) POP(f);
    F[i] = f;
  }
  while (F[0].empty()) F.erase(F.begin());
  int m = len(F) - 1;
  auto poly_eval = [&](vc<mint>& f, mint x) -> mint {
    mint pw = 1, ans = 0;
    FOR(i, len(f)) ans += f[i] * pw, pw *= x;
    return ans;
  };

  FOR(n, len(A) - m) {
    mint sm = 0;
    FOR(i, m + 1) sm += poly_eval(F[i], n) * A[n + m - i];
    if (sm != 0) return {};
  }
  return F;
}

// A[0], ..., A[N]
template <typename mint>
vc<mint> extend_p_recursive(vc<mint> A, vvc<mint> F, int N) {
  auto poly_eval = [&](vc<mint>& f, mint x) -> mint {
    mint pw = 1, ans = 0;
    FOR(i, len(f)) ans += f[i] * pw, pw *= x;
    return ans;
  };
  int M = len(F) - 1;
  if (len(A) >= N + 1) return {A.begin(), A.begin() + N + 1};
  A.resize(N + 1);
  vc<mint> S(N - M + 1);
  FOR(n, N - M + 1) S[n] = poly_eval(F[0], n);
  S = all_inverse<mint>(S);
  FOR(n, N - M + 1) {
    mint ans = 0;
    FOR(i, 1, M + 1) ans += A[n + M - i] * poly_eval(F[i], n);
    A[n + M] = (-ans) * S[n];
  }
  return A;
}
