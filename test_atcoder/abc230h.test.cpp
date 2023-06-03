#define PROBLEM "https://atcoder.jp/contests/abc230/tasks/abc230_h"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/online/online_convolution.hpp"

using mint = modint998;

void solve() {
  /*
  重さ k の金塊 A(x)
  重さ k の空でないふくろ or 金塊 B(x)
  重さ k+1 のふくろ C(x)
  */
  LL(W);
  vc<mint> A(W + 1), B(W + 1), C(W + 1);
  C[0] = 1;

  LL(K);
  FOR(K) {
    INT(w);
    A[w] += mint(1);
  }

  /*
  C(x) = prod (1-x^k)^{-b_k}
  C'(x) / C(x) = sum kb_kx^{k-1}/(1-x^k) = F(x)
  C'(x) = C(x)F(x)

  a_k, b_k, c_k
  -> b_{k+1], f_k
  -> c_{k+1}
  */
  vc<mint> F(W + 1);

  Online_Convolution<mint> X;

  FOR(k, W) {
    B[k + 1] = A[k + 1];
    if (k > 0) B[k + 1] += C[k];
    mint x = mint(k + 1) * B[k + 1];
    int i = k;
    while (i <= W) {
      F[i] += x;
      i += k + 1;
    }
    x = X.query(k, C[k], F[k]);
    C[k + 1] = x * inv<mint>(k + 1);
  }

  C.erase(C.begin());
  C.pop_back();
  for(auto&& x : C) print(x);
}

signed main() {
  solve();

  return 0;
}
