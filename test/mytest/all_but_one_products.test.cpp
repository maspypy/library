#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/all_but_one_products.hpp"

struct Mono {
  using value_type = string;
  using X = value_type;
  static X op(X x, X y) { return x + y; }
  static X unit() { return ""; }
  static constexpr bool commute = 0;
};

void test() {
  vc<string> A = {"a", "b", "c", "d", "e"};
  auto B = all_but_one_products<Mono>(A);
  assert(B[0] == "bcde");
  assert(B[1] == "acde");
  assert(B[2] == "abde");
  assert(B[3] == "abce");
  assert(B[4] == "abcd");
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
