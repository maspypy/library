#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "string/count_unborderd_string.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void test() {
  vc<mint> A = count_unbordered_string<mint>(20, 2);
  vc<mint> A003000 = {1, 2, 2, 4, 6, 12, 20, 40, 74, 148, 284, 568, 1116, 2232, 4424, 8848, 17622, 35244, 70340, 140680, 281076};
  assert(A == A003000);

  vc<mint> B = count_unbordered_string<mint>(20, 3);
  vc<mint> A019308
      = {1, 3, 6, 18, 48, 144, 414, 1242, 3678, 11034, 32958, 98874, 296208, 888624, 2664630, 7993890, 23977992, 71933976, 215790894, 647372682, 1942085088};
  assert(B == A019308);
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
