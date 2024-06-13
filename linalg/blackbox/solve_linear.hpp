#include "random/base.hpp"

// https://arxiv.org/pdf/1204.3735
template <typename mint, typename F1, typename F2>
vc<mint> blackbox_solve_linear(int N, int M, F1 apply_A, F2 apply_AT,
                               vc<mint> b) {
  assert(len(b) == N);
  vc<mint> D1(M), D2(N);
  FOR(i, M) D1[i] = RNG(0, mint::get_mod());
  FOR(i, N) D2[i] = RNG(0, mint::get_mod());
  auto apply_D1 = [&](vc<mint> &v) -> void { FOR(i, M) v[i] *= D1[i]; };
  auto apply_D2 = [&](vc<mint> &v) -> void { FOR(i, N) v[i] *= D2[i]; };
  auto apply_tilde_A = [&](vc<mint> v) -> vc<mint> {
    apply_D1(v);
    v = apply_A(v);
    apply_D2(v);
    v = apply_AT(v);
    apply_D1(v);
    return v;
  };
  vc<mint> v(M);
  FOR(i, M) v[i] = RNG(0, mint::get_mod());
  vc<mint> tilde_b = apply_tilde_A(v);
  vc<mint> c = b;
  apply_D2(c);
  c = apply_AT(c);
  apply_D1(c);
  FOR(i, M) tilde_b[i] += c[i];

  auto dot = [&](vc<mint> &a, vc<mint> &b) -> mint {
    mint ans = 0;
    FOR(i, len(a)) ans += a[i] * b[i];
    return ans;
  };
  auto is_zero = [&](vc<mint> &a) -> bool {
    FOR(i, M) if (a[i] != mint(0)) return false;
    return true;
  };

  auto solve_symmetric = [&](vc<mint> b) -> vc<mint> {
    if (is_zero(b)) return vc<mint>(M);
    vc<mint> w0(M), v0(M);
    mint t0 = 1;
    vc<mint> w1 = b, v1 = apply_tilde_A(b);
    mint t1 = dot(v1, w1);
    if (t1 == mint(0)) return {};
    vc<mint> x(M);
    mint c = dot(b, w1) / t1;
    FOR(i, M) x[i] = c * w1[i];
    while (1) {
      vc<mint> w2(M);
      mint c1 = dot(v1, v1) / t1, c0 = dot(v1, v0) / t0;
      FOR(i, M) w2[i] = v1[i] - c1 * w1[i] - c0 * w0[i];
      if (is_zero(w2)) return x;
      vc<mint> v2 = apply_tilde_A(w2);
      mint t2 = dot(w2, v2);
      if (t2 == mint(0)) return {};
      mint c = dot(b, w2) / t2;
      FOR(i, M) x[i] += c * w2[i];
      swap(v0, v1), swap(v1, v2);
      swap(w0, w1), swap(w1, w2);
      swap(t0, t1), swap(t1, t2);
    }
  };

  // tilde(A)x=tilde(b)
  vc<mint> x = solve_symmetric(tilde_b);
  if (x.empty()) return {};
  FOR(i, M) x[i] -= v[i];
  apply_D1(x);

  // check
  if (apply_A(x) != b) return {};
  return x;
}

// Ax=b
template <typename mint>
vc<mint> sparse_solve_linear(int N, int M, vc<tuple<int, int, mint>> mat,
                             vc<mint> b) {
  assert(len(b) == N);
  auto apply = [&](vc<mint> a) -> vc<mint> {
    assert(len(a) == M);
    vc<mint> b(N);
    for (auto &[i, j, x]: mat) b[i] += a[j] * x;
    return b;
  };
  auto apply_T = [&](vc<mint> a) -> vc<mint> {
    assert(len(a) == N);
    vc<mint> b(M);
    for (auto &[i, j, x]: mat) b[j] += a[i] * x;
    return b;
  };
  return blackbox_solve_linear<mint>(N, M, apply, apply_T, b);
}
