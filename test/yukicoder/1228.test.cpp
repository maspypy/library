#define PROBLEM "https://yukicoder.me/problems/no/1228"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid_xor_basis.hpp"

void solve() {
  LL(X, K);
  if (X == 0) ++K;
  if (K == 0) {
    Yes();
    print(1);
    print(1 ^ X);
    return;
  }
  ll n = topbit(K);
  if (K != 1 << n) return No();

  using Mono = Monoid_XorBasis<int>;
  auto V = Mono::unit();
  vc<int> ANS;

  if (X != 0) {
    ANS.eb(X);
    Mono::add_element(V, X);
  }

  while (1) {
    int dim = len(V);
    int free = len(ANS) - len(V);
    if (K == (1 << free)) break;
    ll mex = 0;
    while (1) {
      bool ok = 1;
      for (auto&& x: ANS)
        if (x == mex) {
          ++mex;
          ok = 0;
        }
      if (ok) break;
    }
    ANS.eb(mex);
    Mono::add_element(V, mex);
  }
  if (ANS.empty()) ANS.eb(1);
  Yes();
  print(len(ANS));
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
