#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/hashmap.hpp"
#include "random/hash_vector.hpp"
#include "mod/modint.hpp"
#include "other/connected_dp.hpp"

using mint = modint107;

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}