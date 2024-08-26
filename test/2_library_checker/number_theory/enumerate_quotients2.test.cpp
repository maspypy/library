#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/array_on_floor.hpp"

void solve() {
  LL(N);
  Array_On_Floor<int> A(N);
  print(len(A));
  FOR(i, len(A)) print(A.get_floor(i));
}

signed main() {
  solve();
  return 0;
}