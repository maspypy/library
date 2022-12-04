#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/rollback_unionfind.hpp"
#include "ds/rollback_array.hpp"
#include "ds/offline_query/add_remove_query.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A0, N);

  using P = pair<int, int>;
  AddRemove_Query<P, 1> X;
  RollbackArray<ll> A(A0);

  vc<int> query;
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(u, v);
      if (u > v) swap(u, v);
      X.add(len(query), {u, v});
    }
    if (t == 1) {
      LL(u, v);
      if (u > v) swap(u, v);
      X.remove(len(query), {u, v});
    }
    if (t == 2) {
      LL(v, x);
      X.add(len(query), {~v, x});
    }
    if (t == 3) {
      LL(v);
      query.eb(v);
    }
  }
  RollbackUnionFind uf(N);
  // rollback_dfs
  auto upd = X.calc(len(query));
  vi ANS(len(query));
  vc<int> I(len(upd));
  iota(all(I), 0);
  auto dfs = [&](auto& dfs, vc<int>& upd_query_I, int begin, int end) -> void {
    // snapshot
    int a_time = A.time();
    int uf_time = uf.time();

    vc<int> IL, IR;
    int mid = (begin + end) / 2;
    for (auto&& i: upd_query_I) {
      auto [a, b, X] = upd[i];
      if (a <= begin && end <= b) {
        // X で表される update query を処理する
        auto [p, q] = X;
        if (p >= 0) {
          int u = p, v = q;
          u = uf[u], v = uf[v];
          if (u == v) continue;
          uf.merge(u, v);
          int r = uf[u];
          A.set(r, A.get(u) + A.get(v));
        } else {
          int v = ~p, x = q;
          v = uf[v];
          A.set(v, A.get(v) + x);
        }
        continue;
      }
      if (a < mid) IL.eb(i);
      if (mid < b) IR.eb(i);
    }
    if (begin + 1 == end) {
      int v = query[begin];
      ANS[begin] = A.get(uf[v]);
    } else {
      dfs(dfs, IL, begin, mid);
      dfs(dfs, IR, mid, end);
    }
    // rollback
    A.rollback(a_time);
    uf.rollback(uf_time);
  };
  dfs(dfs, I, 0, len(query));
  for (auto&& x: ANS) print(x);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
