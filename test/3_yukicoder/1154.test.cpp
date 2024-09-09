#define PROBLEM "https://yukicoder.me/problems/no/1154"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "ds/meldable_heap.hpp"

// https://qoj.ac/contest/1245/problem/6514
void solve() {
  LL(N);
  VEC(ll, A, N);
  Graph<int, 0> G(N);
  G.read_tree();

  ll ANS = 0;

  Meldable_Heap<ll, false, false> X(N);
  using np = decltype(X)::np;

  auto dfs = [&](auto& dfs, int v, int p) -> np {
    np que = X.new_root();
    for (auto& e: G[v]) {
      if (e.to == p) continue;
      np que1 = dfs(dfs, e.to, v);
      que = X.meld(que, que1);
    }
    ll a = A[v];
    while (1) {
      int n = (que ? que->size : 0);
      if (n <= 1) break;
      if (a >= (que->x)) {
        que = X.push(que, a);
        return que;
      }
      ll b = que->x;
      que = X.pop(que);
      ll c = que->x;
      que = X.pop(que);
      a = a + c - b;
    }
    int n = (que ? que->size : 0);
    if (n == 0) {
      que = X.push(que, a);
      return que;
    }
    assert(n == 1);
    ll b = que->x;
    if (a <= b) {
      que = X.pop(que);
      ANS += (N % 2 == 0 ? a - b : b - a);
      return que;
    }
    que = X.push(que, a);
    return que;
  };
  auto que = dfs(dfs, 0, -1);
  vi B = X.get_all(que);
  FOR(k, len(B)) ANS += (k & 1 ? -B[k] : B[k]);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}