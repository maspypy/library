#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_inv.hpp"
#include "mod/modint.hpp"
#include "seq/partition.hpp"

using mint = modint998;

void solve() {
  LL(N);
  print(partition_number<mint>(N));
}

signed main() {
  solve();

  return 0;
}
