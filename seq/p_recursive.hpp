
#include "poly/prefix_product_of_poly.hpp"
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

// a0, ..., a_{r-1} および f_0, ..., f_r を与える
// a_r f_0(0) + a_{r-1}f_1(0) + ... = 0
// a_{r+1} f_0(1) + a_{r}f_1(1) + ... = 0
template <typename T>
T kth_term_of_p_recursive(vc<T> a, vc<vc<T>>& fs, ll k) {
  if (k < len(a)) return a[k];
  int r = len(fs) - 1;
  assert(len(a) >= r);
  a.resize(r);
  assert(len(fs) == r + 1);

  vc<vc<vc<T>>> A;
  A.resize(r);
  FOR(i, r) A[i].resize(r);
  FOR(i, r) {
    // A[0][i] = -fs[i + 1];
    for (auto&& x: fs[i + 1]) A[0][i].eb(-x);
  }
  FOR3(i, 1, r) A[i][i - 1] = fs[0];
  vc<T> den = fs[0];
  auto res = prefix_product_of_poly_matrix(A, k - r + 1);
  reverse(all(a));
  T ANS = 0;
  FOR(j, r) ANS += res[0][j] * a[j];
  ANS /= prefix_product_of_poly(den, k - r + 1);
  return ANS;
}

template <typename mint>
vvc<mint> interpolate_p_recursive(vc<mint> A, int max_m, int max_deg, int k) {
  auto fs = find_p_recursive<mint>(a, 1, 1);
  return kth_term_of_p_recursive<mint>(a, fs, k);
}
