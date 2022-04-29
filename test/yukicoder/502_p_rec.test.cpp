#define PROBLEM "https://yukicoder.me/problems/no/502"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/kth_term_of_p_recursive.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);
  if (N >= mint::get_mod()) return print(0);
  vc<mint> a = {1};
  vc<vc<mint>> fs(2);
  fs[0] = {1};
  fs[1] = {-1, -1};
  print(kth_term_of_p_recursive(a, fs, N));
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
