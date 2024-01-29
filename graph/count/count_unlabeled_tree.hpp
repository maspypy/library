#include "poly/online/online_exp.hpp"
#include "mod/modint.hpp"
#include "poly/convolution.hpp"

// https://oeis.org/A000055
// https://oeis.org/A000081
template <typename mint>
vc<mint> count_unlabeled_tree(int N, bool rooted) {
  // f: rooted tree
  // f(x) = x prod (1+x^n+x^{2n}+...)^f_n
  // g(x) = f(x)/x
  // log g(x) = sum f[n]log(1+x^n+x^{2n}+...)
  // f[n] given -> [x^n]g(x) given -> f[n+1] given
  vc<mint> f(N + 1);
  vc<mint> log_g(N);
  Online_Exp<mint> X;
  FOR(n, 1, N + 1) {
    f[n] = X.query(n - 1, log_g[n - 1]);
    // -log(1-x)=x+xx/2+...
    FOR(k, 1, (N - 1) / n + 1) { log_g[n * k] += f[n] * inv<mint>(k); }
  }
  if (rooted) return f;
  // この時点で f は unlabeled rooted tree (OEIS A000081)
  // unlabeled tree の母関数は f(x) - 1/2(f(x)^2-f(x^2))
  vc<mint> ff = convolution<mint>(f, f);
  vc<mint> ANS = f;
  FOR(i, N + 1) ANS[i] -= inv<mint>(2) * ff[i];
  FOR(i, N + 1) {
    if (2 * i <= N) ANS[2 * i] += inv<mint>(2) * f[i];
  }
  return ANS;
}
