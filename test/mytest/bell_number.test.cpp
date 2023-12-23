#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "other/io.hpp"

#include "seq/famous/bell_number.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void test() {
  vc<mint> A = bell_number<mint>(10);
  vc<mint> B
      = {mint(1),   mint(1),   mint(2),    mint(5),     mint(15),    mint(52),
         mint(203), mint(877), mint(4140), mint(21147), mint(115975)};
  assert(A == B);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}
