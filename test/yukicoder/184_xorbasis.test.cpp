#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid_xor_basis.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  using Mono = Monoid_XorBasis<ll, 61>;
  auto sp = Mono::unit();
  for (auto&& a: A) { Mono::add_element(sp, a); }
  int dim = 0;
  for (auto&& x: sp)
    if (x) ++dim;
  print(1LL << dim);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
