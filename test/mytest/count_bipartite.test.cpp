#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_bipartite.hpp"

using mint = modint998;

void test() {
  vc<mint> A = count_bipartite<mint>(10, true);
  vc<mint> B = {0LL,    1LL,     1LL,       3LL,        19LL,        195LL,
                3031LL, 67263LL, 2086099LL, 89224635LL, 5254054111LL};
  assert(A == B);
  A = count_bipartite<mint>(10, false);
  B = {1LL,    1LL,      2LL,       7LL,         41LL,        376LL,
       5177LL, 103237LL, 2922446LL, 116011231LL, 6433447397LL};
  assert(A == B);
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}