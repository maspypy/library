#define PROBLEM \
  "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "convex/minplus_convolution.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, M);
  print(minplus_convolution<ll, 1, 1>(A, B));
}

signed main() {
  solve();
  return 0;
}
