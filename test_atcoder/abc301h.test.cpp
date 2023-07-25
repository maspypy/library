#define PROBLEM "https://atcoder.jp/contests/abc301/tasks/abc301_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/unionfind.hpp"
#include "graph/ds/tree_monoid.hpp"
#include "alg/monoid/max.hpp"
#include "alg/monoid/min_idx.hpp"
#include "graph/ds/dual_tree_monoid.hpp"

void solve() {
  LL(N, M);
  using T = tuple<int, int, int>;
  vc<T> dat;
  FOR(i, M) {
    LL(a, b, c);
    --a, --b;
    dat.eb(c, a, b);
  }
  auto I = argsort(dat);
  dat = rearrange(dat, I);
  auto new_idx = argsort(I);

  vc<bool> used(M);
  vc<int> tree_idx(M, -1);
  Graph<int, 0> G(N);
  UnionFind uf(N);
  int p = 0;
  FOR(i, M) {
    auto [c, a, b] = dat[i];
    if (uf.merge(a, b)) {
      G.add(a, b, c);
      used[i] = 1;
      tree_idx[i] = p++;
    }
  }
  G.build();

  Tree<decltype(G)> tree(G);
  Tree_Monoid<decltype(tree), Monoid_Max<int>, true> TM(
      tree, [&](int eid) -> int { return G.edges[eid].cost; });

  // 各辺について、禁止したときにどれが使われるか？
  Dual_Tree_Monoid<decltype(tree), Monoid_Min_Idx<int>, true> DTM(tree);

  FOR(eid, M) {
    if (used[eid]) continue;
    auto [c, a, b] = dat[eid];
    DTM.apply_path(a, b, {c, eid});
  }

  vc<int> new_use(N - 1);
  {
    auto tmp = DTM.get_all();
    assert(len(tmp) == N - 1);
    FOR(i, N - 1) new_use[i] = tmp[i].se;
  }

  auto calc = [&](int eid, int s, int t) -> int {
    if (!used[eid]) return 0;
    int c = get<0>(dat[eid]);
    eid = tree_idx[eid];
    ll now = TM.prod_path(s, t);
    TM.set(eid, c + 1);

    ll after = TM.prod_path(s, t);

    if (now == after) return 0;
    int k = new_use[eid];
    if (k == -1) return 1;
    auto [cc, a, b] = dat[k];
    ll x = max<int>({TM.prod_path(s, a), cc, TM.prod_path(b, t)});
    ll y = max<int>({TM.prod_path(s, b), cc, TM.prod_path(a, t)});
    chmin(after, x);
    chmin(after, y);
    return abs(after - now);
  };

  LL(Q);
  FOR(Q) {
    LL(eid, s, t);
    --eid, --s, --t;
    eid = new_idx[eid];
    print(calc(eid, s, t));
    if (used[eid]) {
      int c = get<0>(dat[eid]);
      eid = tree_idx[eid];
      TM.set(eid, c);
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
