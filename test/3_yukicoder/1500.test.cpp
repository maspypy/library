#define PROBLEM "https://yukicoder.me/problems/no/1500"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/find_linear_rec.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint107;

void solve() {
  vc<mint> A(20);
  set<pi> ss;
  ss.insert(mp(0, 0));
  FOR(i, 20) {
    A[i] = len(ss);
    set<pi> newss;
    for (auto&& [x, y]: ss) {
      newss.insert(mp(x + 3, y + 0));
      newss.insert(mp(x + 3, y + 2));
      newss.insert(mp(x + 2, y + 3));
      newss.insert(mp(x + 0, y + 3));
      newss.insert(mp(x - 2, y + 3));
      newss.insert(mp(x - 3, y + 2));
      newss.insert(mp(x - 3, y + 0));
      newss.insert(mp(x - 3, y - 2));
      newss.insert(mp(x - 2, y - 3));
      newss.insert(mp(x - 0, y - 3));
      newss.insert(mp(x + 2, y - 3));
      newss.insert(mp(x + 3, y - 2));
    }
    swap(ss, newss);
  }
  LL(N);
  // print(find_linear_rec(A));
  // print(A);
  print(interpolate_linear_rec(A, N, 0));
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
