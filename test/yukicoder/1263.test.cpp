#define PROBLEM "https://yukicoder.me/problems/no/1263"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "enumerate/partition.hpp"

using mint = modint107;

void solve() {
  mint ANS = 1;
  LL(N);
  auto f = [&](vc<int> P) -> void {
    mint v = fact<mint>(N);
    for (auto&& x: P) v *= inv<mint>(x) * (x % 2 == 0 ? mint(-1) : mint(1));
    vc<int> CNT(N + 1);
    for (auto&& x: P) ++CNT[x];
    for (auto&& x: CNT) v *= fact_inv<mint>(x);
    ANS *= v;
  };
  enumerate_partition(N, f);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
