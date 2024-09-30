#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/nimber/base.hpp"

using F = Nimber64;
void solve() {
  u64 a, b;
  read(a, b);
  F ANS = F(a) * F(b);
  print(ANS.val);
}

signed main() {
  LL(T);
  FOR(T) solve();

  return 0;
}
