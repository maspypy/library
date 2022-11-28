#define PROBLEM "https://yukicoder.me/problems/no/1197"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree.hpp"
#include "alg/acted_monoid/cntsum_add.hpp"
#include "graph/ds/lazytreemonoid.hpp"

void solve() {
  LL(N, K, Q);
  VEC(int, C, K);
  for (auto&& v: C) --v;

  Graph<int, 0> G(N);
  G.read_tree();

  TREE<decltype(G)> tree(G);
  using AM = ActedMonoid_CntSum_Add<ll>;
  vc<pi> dat(N);
  FOR(i, N) dat[i] = {1, 0};

  LazyTreeMonoid<decltype(tree), AM> X(tree, dat);

  FOR(i, K) { X.apply_path(0, C[i], 1); }

  ll d_sm = 0;
  auto& dep = tree.depth;
  FOR(i, K) d_sm += dep[C[i]];

  bool out = 0;

  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(k, d);
      --k;
      --d;
      d_sm -= dep[C[k]];
      X.apply_path(0, C[k], -1);
      C[k] = d;
      d_sm += dep[C[k]];
      X.apply_path(0, C[k], 1);
    }
    if (t == 2) {
      LL(v);
      --v;
      ll ANS = dep[v] * K + d_sm;
      ANS -= 2 * X.prod_path(0, v).se;
      ANS += 2 * K;
      print(ANS);
      out = 1;
    }
  }
  if (!out) print();
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
