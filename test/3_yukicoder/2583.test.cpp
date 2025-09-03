#define PROBLEM "https://yukicoder.me/problems/no/2583"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/poly_divmod.hpp"
#include "poly/fps_pow.hpp"
#include "poly/fps_div.hpp"
#include "poly/poly_taylor_shift.hpp"
#include "poly/composition_f_a_plus_bx_div_c_plus_dx.hpp"

using mint = modint998;

/*
A(x)y+(x^2-1)y'=0 の解をとる.
A(x)/1-x^2 = a'(x)+b/1-x+c/1+x となる a,b,c をとると
e^{a(x)}(1-x)^{-b}(1+x)^c が満たす.

F_k(x) = e^{a(x)}(1-x)^{-b}(1+x)^cG_k(x) とする.
F_k'/F_k = a'(x)+b/1-x+c/1+x+G_k'/G_k = A(x)/1-x^2 + G_k'(x)/G_k(x)

F_{k+1} = G_k'/G_k(x^2-1)F_k
G_{k+1}=G_k/F_k F_{k+1} = G_k'(x)(x^2-1)

結局
微分して (x^2-1) 倍
に帰着
とりあえずここまで実装する

欲しいもの：G の [x^(N+1)] まで
初期値：G の [x^(2N+1)] まで
*/

vc<mint> sub2(vc<mint> F, ll N) {
  // F_{k+1} = (xx+2x)F_k'
  // はみ出るやつも全部保持する必要あり！
  F.resize(len(F) + N);
  /*
  FOR(N) {
    vc<mint> nxt(len(F));
    FOR(i, 1, len(F)) {
      mint x = mint(i) * F[i];
      nxt[i] += x + x;
      if (i + 1 < len(F)) nxt[i + 1] += x;
    }
    swap(F, nxt);
  }
  return F;
  */
  // (x/(2+x))^d が固有値 2d の固有関数
  // F(x) = \sum g_k(x/(2+x))^k と書けば勝ち
  // F(x) = G(x/(2+x))
  // F((2y)/(1-y)) = G(y)

  // F((2y)/(1-y)) = G(y)
  vc<mint> G = composition_f_a_plus_bx_div_c_plus_dx<mint, 0>(
      F, mint(0), mint(2), mint(1), mint(-1));

  // print(F);
  // print(G);

  FOR(d, len(G)) { G[d] *= mint(2 * d).pow(N); }

  // F(x) = G(x/(2+x))
  vc<mint> H = composition_f_a_plus_bx_div_c_plus_dx<mint, 0>(
      G, mint(0), mint(1), mint(2), mint(1));
  // print(G);
  // print(H);
  return H;
}

// void test() {
//   vc<mint> F = {1, 2, 3};
//   sub2(F, 1);
// }

vc<mint> sub(vc<mint> F, ll N) {
  assert(len(F) == 2 * N + 2);
  /*
  FOR(N) {
    vc<mint> nxt(2 * N + 2);
    FOR(i, len(F)) {
      if (i == 0) continue;
      mint x = mint(i) * F[i];
      nxt[i - 1] -= x;
      if (i + 1 < 2 * N + 2) nxt[i + 1] += x;
    }
    swap(F, nxt);
  }
  return F;
  */

  /*
  F_{k+1}=(x^2-1)F_k'
  G_k(x):=F_k(x+1)
  G_{k+1}(x)=(x^2+2x)G_k(x)
  F_{k+1}(x)=(x^2+2x)F_k(x) に帰着
  */
  F = poly_taylor_shift<mint>(F, 1);
  F = sub2(F, N);
  F = poly_taylor_shift<mint>(F, -1);
  F.resize(N + 2);
  return F;
}

void solve() {
  LL(N, M);
  vc<mint> F0;
  ll LEN = 2 * N + 2;
  {
    VEC(mint, A, M);
    vc<mint> B = {1, 0, -1};
    auto [Q, R] = poly_divmod(A, B);
    vc<mint> a = Q;
    a.insert(a.begin(), 0);
    FOR(i, 1, len(a)) a[i] *= inv<mint>(i);
    R.resize(2);
    mint b = (R[0] + R[1]) * inv<mint>(2);
    mint c = (R[0] - R[1]) * inv<mint>(2);
    a.resize(LEN);

    vc<mint> f = fps_exp(a);
    vc<mint> g = {1, -1};
    g.resize(LEN);
    g = fps_pow_1<mint>(g, -b);
    vc<mint> h = {1, 1};
    h.resize(LEN);
    h = fps_pow_1<mint>(h, c);
    f = convolution<mint>(f, g);
    f.resize(LEN);
    f = convolution<mint>(f, h);
    f.resize(LEN);
    F0 = f;
  }
  // F(x) = F0(x)G(x)
  vc<mint> G = {0, 1};
  G.resize(LEN);
  G = fps_div(G, F0);

  G = sub(G, N);
  F0.resize(N + 2);
  G.resize(N + 2);
  // F(x)=F0(x)G(x)
  vc<mint> ANS = convolution<mint>(F0, G);
  ANS.resize(N + 2);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}