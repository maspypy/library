#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/triangle.hpp"

void solve() {
  LL(N, M);
  VEC(int, A, N);
  Graph G(N);
  G.read_graph(M, 0, 0);
  i128 sum = 0;
  auto query
      = [&](int a, int b, int c) -> void { sum += i128(A[a]) * A[b] * A[c]; };
  enumerate_triangle(G, query);
  int ANS = sum % 998244353;
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
