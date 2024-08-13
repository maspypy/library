#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "linalg/xor/vector_space.hpp"

void solve() {
  LL(N);
  using SP = Vector_Space<u64>;
  SP X;
  u64 S = 0;
  FOR(N) {
    u64 x;
    read(x);
    S ^= x;
    X.add_element(x);
  }
  u64 mask = ~S;

  SP Y;
  for (auto&& e: X.dat) { Y.add_element(e & mask); }
  u64 x = Y.get_max();
  print(x + (S ^ x));
}

signed main() {
  solve();
  return 0;
}
