#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/nim_product.hpp"

void solve() {
  u64 a, b;
  read(a, b);
  print(nim_product(a, b));
}

signed main() {
  LL(T);
  FOR(T) solve();

  return 0;
}
