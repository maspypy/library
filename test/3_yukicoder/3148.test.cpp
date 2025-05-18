#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/bracket_graph.hpp"
#include "graph/optimal_product_on_tree.hpp"

struct Data {
  ll ans, x0, x1;
};

// 今回は葉が先だねー
struct Mono {
  using value_type = Data;
  using X = value_type;
  static X op(X x, X y) {
    swap(x, y);
    X z;
    z.ans = x.ans + y.ans + x.x1 * y.x0;
    z.x0 = x.x0 + y.x0, z.x1 = x.x1 + y.x1;
    return z;
  }
  static constexpr X unit() { return Data{0, 0, 0}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N);
  STR(S);
  SHOW(S);
  auto [G, LR] = bracket_graph(S);
  VEC(ll, A, N);
  FOR(i, N + 1) SHOW(LR[i]);
  G.debug();
  Tree<decltype(G)> tree(G);
  ++N;
  vi W(N);
  vc<int> I;
  FOR(i, len(S)) if (S[i] == '(') I.eb(i);
  FOR(i, 1, N) {
    int L = LR[i].fi;
    int k = LB(I, L);
    W[i] = A[k];
  }

  SHOW(W);

  vc<Data> dat(N);
  FOR(i, N) dat[i] = {W[i], W[i], 1};
  dat[0] = {0, 0, 0};
  auto comp = [&](Data x, Data y) -> bool {
    if (x.x0 == 0 && x.x1 == 0) return false;
    if (y.x0 == 0 && y.x1 == 0) return true;
    return x.x0 * y.x1 > x.x1 * y.x0;
  };
  auto [ord, x] = optimal_product_on_tree<decltype(tree), Mono, false>(tree, dat, comp);
  ll ANS = 0;
  FOR(i, 1, len(ord)) {
    int v = ord[i];
    ANS += W[v] * i;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
