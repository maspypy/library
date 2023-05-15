#define PROBLEM "https://yukicoder.me/problems/no/1211"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/functional.hpp"

void solve() {
  LL(N, K);
  VEC(int, A, N);
  FOR(i, N) A.eb(A[i]);
  auto Ac = cumsum<ll>(A);

  auto check = [&](ll S) -> bool {
    // 全部 S 以上にできる
    if (S <= 0) return 1;
    FunctionalGraph<int> FG(N + N + 1);
    int j = 0;
    FOR(i, N + N + 1) {
      while (j < N + N && Ac[j] < Ac[i] + S) ++j;
      FG.add(i, j);
    }
    auto [G, tree] = FG.build();
    auto TO = FG.jump_all(tree, K);
    FOR(i, N) if (TO[i] <= i + N) return true;
    return false;
  };

  ll ANS = binary_search(check, 0, SUM<ll>(A) / K + 1);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}