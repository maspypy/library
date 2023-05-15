#include "mod/modint.hpp"
#include "mod/all_inverse.hpp"

template <typename mint>
struct q_Analogue {
  const mint q;
  const int LIM;
  int D;
  vc<mint> factorial, ifactorial;

  q_Analogue(mint q, int LIM) : q(q), LIM(LIM) {
    assert(LIM < mint::get_mod());
    build();
  }

  void build() {
    factorial.reserve(LIM + 1);
    factorial.eb(1);
    mint x = 1;
    FOR(i, 1, LIM + 1) {
      if (x == mint(0)) break;
      factorial.eb(factorial.back() * x);
      x = q * x + mint(1);
    }
    ifactorial = all_inverse(factorial);
    D = len(factorial);
  }

  mint fact(int N) {
    assert(0 <= N && N <= LIM);
    return (N < D ? factorial[N] : mint(0));
  }
  mint fact_inv(int N) {
    assert(0 <= N && N < D);
    return (N < D ? ifactorial[N] : mint(0));
  }
  mint binom(int N, int K) {
    assert(0 <= N && N <= LIM);
    if (K < 0 || K > N) return mint(0);
    if (N < D) return factorial[N] * ifactorial[K] * ifactorial[N - K];
    auto [n1, n2] = divmod(N, D);
    auto [k1, k2] = divmod(K, D);
    return C<mint>(n1, k1) * binom(n2, k2);
  }
};
