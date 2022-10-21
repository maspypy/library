#define PROBLEM "https://yukicoder.me/problems/no/184"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/xor_basis.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  using Mono = Monoid_XorBasis<ll>;
  auto sp = Mono::unit();
  for (auto&& a: A) { Mono::add_element(sp, a); }
  print(1LL << len(sp));
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
