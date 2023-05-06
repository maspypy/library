#define PROBLEM "https://yukicoder.me/problems/no/2295"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "mod/modint.hpp"

#include "graph/ds/link_cut_path.hpp"
#include "alg/monoid/max.hpp"

using mint = modint998;
void solve() {
  LL(N, X, Q);

  ll nxt = N;
  UnionFind uf(N + N - 1);
  // root ごとに、直径頂点番号
  vc<pair<int, int>> dat(N + N - 1);
  FOR(i, N + N - 1) dat[i] = {i, i};
  LinkCutTree_Path<Monoid_Max<int>, 500000> tree(N + N - 1);

  vc<mint> dp(N + N - 1);

  auto Q1 = [&](ll a, ll b, ll val) -> void {
    if (uf[a] == uf[b]) return;
    tree.set(nxt, val);
    tree.link(a, nxt);
    tree.link(nxt, b);
    nxt++;

    a = uf[a], b = uf[b];
    ll xa = uf.size(a), xb = uf.size(b);
    mint ans = dp[a] + dp[b] + mint(xa * xb) * mint(val);
    uf.merge(a, b);
    dp[uf[a]] = ans;
  };

  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(v, val);
      Q1(X, v, val);
    }
    if (t == 2) {
      LL(u, v);
      if (uf[u] != uf[v]) {
        print(-1);
      } else {
        ll d = tree.prod_path(u, v);
        if (u == v) d = 0;
        print(d);
        X += d;
        X %= N;
      }
    }
    if (t == 3) {
      LL(v);
      print(dp[uf[v]]);
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
