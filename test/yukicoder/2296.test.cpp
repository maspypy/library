#define PROBLEM "https://yukicoder.me/problems/no/2296"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/link_cut_path.hpp"
#include "alg/monoid/add.hpp"
#include "ds/unionfind/unionfind.hpp"

void solve() {
  LL(N, X, Q);

  ll nxt = N;
  UnionFind uf(N + N - 1);
  // root ごとに、直径頂点番号
  vc<pair<int, int>> dat(N + N - 1);
  FOR(i, N + N - 1) dat[i] = {i, i};

  LinkCutTree_Path<Monoid_Add<ll>, 500000> tree(N + N - 1);

  auto add = [&](pair<int, int> p, int c) -> pair<int, int> {
    auto [a, b] = p;
    ll ab = tree.prod_path(a, b);
    ll ac = tree.prod_path(a, c);
    ll bc = tree.prod_path(b, c);
    ll mx = max<ll>({ab, ac, bc});
    if (mx == ab) return {a, b};
    if (mx == ac) return {a, c};
    return {b, c};
  };

  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(v, val);
      tree.set(nxt, val);
      tree.link(X, nxt);
      tree.link(nxt, v);
      nxt++;
      int a = uf[v], b = uf[X];
      uf.merge(a, b);
      int r = uf[a];
      for (int c: {a, b}) {
        if (r == c) continue;
        dat[r] = add(dat[r], dat[c].fi);
        dat[r] = add(dat[r], dat[c].se);
      }
    }
    if (t == 2) {
      LL(u, v);
      if (tree.get_root(u) != tree.get_root(v)) {
        print(-1);
      } else {
        ll d = tree.prod_path(u, v);
        print(d);
        X += d;
        X %= N;
      }
    }
    if (t == 3) {
      LL(v);
      auto [a, b] = dat[uf[v]];
      ll d = tree.prod_path(a, b);
      print(d);
    }
    if (t == 4) {
      LL(val);
      X += val;
      X %= N;
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
