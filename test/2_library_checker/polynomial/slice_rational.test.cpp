#define PROBLEM \
  "https://judge.yosupo.jp/problem/consecutive_terms_of_linear_recurrent_sequence"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/slice_rational_fps.hpp"

using mint = modint998;
void solve() {
  LL(N, a, b);
  VEC(mint, A, N);
  VEC(mint, g, N);
  for (auto&& x: g) x = -x;
  g.insert(g.begin(), 1);
  auto f = convolution(A, g);
  f.resize(N);
  print(slice_rational_fps(f, g, a, a + b));
}

signed main() { solve(); }
