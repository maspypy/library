#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/integer_kth_root.hpp"

void solve() {
  LL(a, k);
  print(integer_kth_root(k, a));
}

signed main() {
  LL(T);
  FOR_(T) solve();

  return 0;
}
