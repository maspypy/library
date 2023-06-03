#define PROBLEM "https://yukicoder.me/problems/no/694"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/inversion.hpp"

void solve() {
  LL(N);
  VEC(int, A, N);
  auto ANS = inversion_rotate(A);
  for (auto&& x: ANS) print(x);
}

signed main() {
  solve();
  return 0;
}