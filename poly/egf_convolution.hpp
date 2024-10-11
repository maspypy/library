
#include "nt/factor.hpp"
#include "mod/mod_inv.hpp"
#include "mod/modint.hpp"
#include "mod/crt3.hpp"
#include "poly/convolution.hpp"

// https://qoj.ac/problem/2205
// 4 * convolution_ntt 程度
// mod は上の問題のために u64 にしておいたが通常 u32 でいいはず
// ANS[k] = sum_{i+j==k} A[i]B[j]
vc<u64> egf_convolution(vc<u64> A, vc<u64> B, u64 mod) {
  assert(mod <= u64(1) << 32);
  vc<int> P;
  for (auto& [p, e]: factor(mod)) P.eb(p);
  int N = len(A) - 1, M = len(B) - 1;
  vc<u64> R(N + M + 1, 1);
  vc<u64> F(N + M + 1, 1);
  vc<u64> IF(N + M + 1, 1);
  FOR(n, 1, N + M + 1) {
    int x = n;
    for (auto& p: P)
      while (x % p == 0) x /= p;
    R[n] = x;
  }
  FOR(n, 1, N + M + 1) F[n] = F[n - 1] * R[n] % mod;
  IF[N + M] = mod_inv(F[N + M], mod);
  FOR_R(n, N + M) IF[n] = IF[n + 1] * R[n + 1] % mod;
  assert(IF[0] == 1);
  // IF は mod で処理する
  FOR(i, N + 1) A[i] = A[i] * IF[i] % mod;
  FOR(i, M + 1) B[i] = B[i] * IF[i] % mod;
  auto calc_mint = [&]<typename mint>() -> vc<mint> {
    // p-part は modint で処理
    vc<mint> X(N + 1), Y(M + 1);
    FOR(i, N + 1) X[i] = A[i];
    FOR(i, M + 1) Y[i] = B[i];
    for (auto& p: P) {
      mint ip = mint(p).inverse();
      vc<mint> IF(N + M + 1, 1);
      for (ll q = p; q <= N + M; q *= p) {
        for (int i = q; i <= N + M; i += q) { IF[i] *= ip; }
      }
      FOR(i, N + M) IF[i + 1] *= IF[i];
      FOR(i, N + 1) X[i] *= IF[i];
      FOR(i, M + 1) Y[i] *= IF[i];
    }
    X = convolution<mint>(X, Y);
    for (auto& p: P) {
      vc<mint> F(N + M + 1, 1);
      for (ll q = p; q <= N + M; q *= p) {
        for (int i = q; i <= N + M; i += q) { F[i] *= p; }
      }
      FOR(i, N + M) F[i + 1] *= F[i];
      FOR(i, N + M + 1) X[i] *= F[i];
    }
    return X;
  };
  constexpr int p0 = 469762049;
  constexpr int p1 = 754974721;
  constexpr int p2 = 880803841;
  constexpr int p3 = 998244353;
  // 謎 by chatgpt
  auto A0 = calc_mint.template operator()<modint<p0>>();
  auto A1 = calc_mint.template operator()<modint<p1>>();
  auto A2 = calc_mint.template operator()<modint<p2>>();
  auto A3 = calc_mint.template operator()<modint<p3>>();
  vc<u64> ANS(N + M + 1);
  FOR(i, N + M + 1) ANS[i] = CRT4<u128, p0, p1, p2, p3>(A0[i].val, A1[i].val, A2[i].val, A3[i].val) % mod;
  FOR(i, N + M + 1) ANS[i] = ANS[i] * F[i] % mod;
  return ANS;
}
