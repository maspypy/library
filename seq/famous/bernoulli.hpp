#include "poly/fps_div.hpp"
#include "mod/powertable.hpp"

template <typename mint>
vc<mint> bernoulli_number(int N) {
  int n = N / 2;
  vc<mint> F(n + 1), G(n + 1);
  mint pow = 1;
  FOR(i, n + 1) {
    F[i] = fact_inv<mint>(2 * i) * pow;
    G[i] = fact_inv<mint>(2 * i + 1) * pow;
    pow *= inv<mint>(4);
  }
  F = fps_div<mint>(F, G);
  vc<mint> B(N + 1);
  if (1 <= N) B[1] = -inv<mint>(2);
  FOR(i, n + 1) B[2 * i] = F[i] * fact<mint>(2 * i);
  return B;
}

template <typename mint>
mint single_bernoulli(int n) {
  // https://atcoder.jp/contests/xmascon23/tasks/xmascon23_e
  if (n == 0) return 1;
  if (n == 1) return -inv<mint>(2);
  /*
  B_n = [x^n/n!] x / (exp(x)-1) = F(1-e^x)
  F(x) = 1+(1/2)x+(1/3)x^2+...
  これを x^n で打ち切る
  F(x) = 1+(1/2)x+(1/3)x^2+...+(1/n+1)x^n, G(x) = F(1-x)
  (xF(x)) d/dx = 1-x^{n+1}/1-x
  ((1-x)G(x)) -d/dx = 1-(1-x)^{n+1}/x = H(x)
  */
  vc<mint> G(n + 2);
  mint sm = 0;
  FOR(i, 1, n + 2) {
    mint c = C<mint>(n + 1, i);
    mint h = (i % 2 == 0 ? c : -c);
    // H(x) = ... gx^{i-1}
    G[i] = h * inv<mint>(i);
    sm += inv<mint>(i);
  }
  G[0] = sm;
  FOR(i, n) G[i + 1] += G[i];
  vc<mint> pow = powertable_2<mint>(n, n);
  mint ans = 0;
  FOR(i, n + 1) { ans += pow[i] * G[i]; }
  return ans;
}
