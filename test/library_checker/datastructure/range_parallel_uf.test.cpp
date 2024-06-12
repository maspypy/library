#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/parallel_unionfind.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  INT(N, Q);
  Range_Parallel_UnionFind uf(N);
  VEC(mint, x, N);

  mint ANS = 0;
  auto f = [&](int i, int j) -> void {
    ANS += x[i] * x[j];
    x[i] += x[j];
  };

  FOR(Q) {
    INT(k, a, b);
    uf.merge(a, a + k, b, b + k, f);
    print(ANS);
  }
}

signed main() { solve(); }
