#define PROBLEM "https://judge.yosupo.jp/problem/two_square_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/two_square.hpp"

void solve() {
  LL(N);
  vc<pi> ANS = two_square(N, true);
  print(len(ANS));
  for (auto& x: ANS) print(x);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
