#define PROBLEM "https://atcoder.jp/contests/abc212/tasks/abc212_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/function_on_divisors.hpp"

void solve() {
  LL(P);
  Function_on_Divisors<ll> X(P - 1);
  X.set_euler_phi();
  i128 ANS = 1;
  X.enumerate([&](ll a, ll b) -> void { ANS += i128(a) * b; });
  print(ANS % 998244353);
}

signed main() {
  solve();
  return 0;
}