#pragma once

#include "poly/convolution.hpp"
#include "poly/convolution2d.hpp"
#include "poly/poly_taylor_shift.hpp"
#include "poly/middle_product.hpp"

template <typename mint>
vc<mint> composition_old(vc<mint>& Q, vc<mint>& P) {
  int n = len(P);
  assert(len(P) == len(Q));
  int k = 1;
  while (k * k < n) ++k;
  // compute powers of P
  vv(mint, pow1, k + 1);
  pow1[0] = {1};
  pow1[1] = P;
  FOR3(i, 2, k + 1) {
    pow1[i] = convolution(pow1[i - 1], pow1[1]);
    pow1[i].resize(n);
  }
  vv(mint, pow2, k + 1);
  pow2[0] = {1};
  pow2[1] = pow1[k];
  FOR3(i, 2, k + 1) {
    pow2[i] = convolution(pow2[i - 1], pow2[1]);
    pow2[i].resize(n);
  }
  vc<mint> ANS(n);
  FOR(i, k + 1) {
    vc<mint> f(n);
    FOR(j, k) {
      if (k * i + j < len(Q)) {
        mint coef = Q[k * i + j];
        FOR(d, len(pow1[j])) f[d] += pow1[j][d] * coef;
      }
    }
    f = convolution(f, pow2[i]);
    f.resize(n);
    FOR(d, n) ANS[d] += f[d];
  }
  return ANS;
}

// https://noshi91.hatenablog.com/entry/2024/03/16/224034
// O(Nlog^2N)
template <typename mint>
vc<mint> composition(vc<mint> f, vc<mint> g) {
  // 必要ではないが簡略化のために，[x^0]g=0 に帰着しておく.
  const int N = len(f) - 1;
  assert(len(f) == N + 1 && len(g) == N + 1);
  if (N == -1) return {};
  mint c = g[0];
  g[0] = 0;
  f = poly_taylor_shift<mint>(f, c);

  auto degree = [&](vvc<mint>& F) -> pair<int, int> {
    return {len(F) - 1, len(F[0]) - 1};
  };

  /*
  f, g は N 次とする.
  合成は (f_i) -> sum_i f_ig(x)^i である. これの転置を考える.
  (h_j) に対して [x^0]h(x^-1)sum_if_ig(x)^i = sum_if_i[x^0]h(x^{-1})g(x)^i
  であるから [x^N]rev_h(x)g(x)^i を計算するというのが転置である．
  したがって合成は [x^N]rev_h(x)g(x)^i 列挙の転置をとれば計算できる.

  転置問題は, 次のような反復により解ける：
  ・入力を reverse する.
  ・次を k=0,1,2,...,K で繰り返す（K=lg n 程度）.
  　・g だけから定まる何らかの G_k(x,y) と畳み込む
  　・適切な部分を抜き出す

  よって合成は次の計算による
  ・次を k=m,...,2,1,0 で繰り返す
  　・適切な部分に入れる
  　・G_k(x,y) との畳み込みの転置でうつす
  ・reverse して出力する.

  G_k(x,y) は k の昇順に計算できて，これを逆順に処理するため，
  ここでは再帰関数により実装する．
  */
  auto dfs = [&](auto& dfs, vvc<mint> G) -> vvc<mint> {
    auto [n, m] = degree(G);
    if (n == 0) {
      // [x^0]g=0 としていたので G=1 である.
      // 転置問題ではこの時点での多項式がそのまま出力となる.
      // よって入力をそのまま多項式に入れて返す.
      vv(mint, F, n + 1, m + 1);
      FOR(j, len(f)) F[0][j] = f[j];
      return F;
    }
    vvc<mint> G1 = G;
    FOR(i, n + 1) {
      if (i % 2 == 0) continue;
      FOR(j, m + 1) G1[i][j] = -G[i][j];
    }
    vvc<mint> G2 = convolution2d(G, G1);
    int n2 = n / 2;
    FOR(i, n2 + 1) G2[i] = G2[2 * i];
    G2.resize(n2 + 1);
    vvc<mint> F = dfs(dfs, G2);
    assert(degree(F) == degree(G2));
    // 転置問題では G1 と畳み込んだあと n の parity に応じた部分を抜き出す.
    // よってまず dfs の出力を抜き出す前の位置に入れて, 畳み込みの転置をとる.

    // 畳み込みの転置をとるとは何なのか.
    // (n,m) 次の多項式積 H(x,y) G(x,y)
    // H, G を適切に配置した (n+1)(2m+1)-1 次多項式を用意して
    // 畳み込んで 2(n+1)(2m+1)-2 次多項式を得る.
    // この適切な (2n,2m) 次多項式を抜き出す.
    // 転置をとると次のようになる.
    // F を適切に配置した (2n,2m) 次多項式を作る.
    // ここから 2(n+1)(2m+1)-2 次多項式を作る.
    // これと適切な多項式の middle product をとって
    // (n+1)(2m+1)-1 次多項式を得る.
    vc<mint> A(2 * (n + 1) * (2 * m + 1) - 1);
    FOR(i, len(F)) FOR(j, len(F[0])) {
      int i1 = 2 * i + (n % 2);
      int idx = i1 * (2 * m + 1) + j;
      A[idx] = F[i][j];
    }
    vc<mint> B((n + 1) * (2 * m + 1));
    FOR(i, n + 1) FOR(j, m + 1) {
      int idx = i * (2 * m + 1) + j;
      B[idx] = G1[i][j];
    }

    A = middle_product<mint>(A, B);
    assert(len(A) == (n + 1) * (2 * m + 1));
    vv(mint, res, n + 1, m + 1);
    FOR(i, n + 1) FOR(j, m + 1) {
      int idx = (2 * m + 1) * i + j;
      res[i][j] = A[idx];
    }
    return res;
  };
  vv(mint, G, N + 1, 2);
  G[0][0] = 1;
  FOR(i, N + 1) G[i][1] = -g[i];
  vvc<mint> F = dfs(dfs, G);
  assert(degree(F) == (pair<int, int>{N, 1}));
  vc<mint> ANS(N + 1);
  FOR(i, N + 1) ANS[i] = F[i][0];
  // 最後に reverse する
  reverse(all(ANS));
  return ANS;
}
