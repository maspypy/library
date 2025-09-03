#define PROBLEM "https://yukicoder.me/problems/no/1752"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/meldable_heap.hpp"
#include "graph/base.hpp"

/*
根より上に k 個の端点がある場合の最適解
*/

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();

  Meldable_Heap<ll, false, false> X(N);
  using np = decltype(X)::np;

  auto dfs = [&](auto& dfs, int v, int p) -> np {
    np que = X.new_root();
    for (auto& e: G[v]) {
      if (e.to == p) continue;
      que = X.meld(que, dfs(dfs, e.to, v));
    }
    ll sz = (que ? que->size : 0);
    if (sz == 0) { que = X.push(que, 1); }
    elif (sz == 1) { que->x += 1; }
    else {
      ll a = que->x;
      que = X.pop(que);
      ll b = que->x;
      if (a % 2 == 0 && b % 2 == 0) {
        que->x += a;
        que = X.push(que, 1);
      } else {
        que->x += a + 1;
      }
    }
    return que;
  };
  auto que = dfs(dfs, 0, -1);
  print(que->x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}