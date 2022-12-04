#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/add_remove_query.hpp"
#include "ds/rollback_array.hpp"
#include "ds/unionfind/rollback_unionfind.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A0, N);
  using P = pair<int, int>;

  vc<int> query;

  AddRemove_Query<P, true> X;
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b);
      if (a > b) swap(a, b);
      P e = {a, b};
      X.add(len(query), e);
    }
    if (t == 1) {
      LL(a, b);
      if (a > b) swap(a, b);
      P e = {a, b};
      X.remove(len(query), e);
    }
    if (t == 2) {
      LL(v, x);
      P p = {~v, x};
      X.add(len(query), p);
    }
    if (t == 3) {
      LL(v);
      query.eb(v);
    }
  }

  auto upd = X.calc(len(query));
  Q = len(query);
  vi ANS(Q);
  vc<int> I(len(upd));
  iota(all(I), 0);

  RollbackArray<ll> A(A0);
  RollbackUnionFind uf(N);

  auto dfs = [&](auto& dfs, vc<int>& I, int begin, int end) -> void {
    int a_time = A.time();
    int uf_time = uf.time();

    vc<int> IL, IR;
    int mid = (begin + end) / 2;
    // 区間を完全に含む更新クエリを処理する。
    // 部分的に交わるクエリを J に入れる
    for (auto&& i: I) {
      auto [a, b, X] = upd[i];
      if (a <= begin && end <= b) {
        // update
        auto [u, v] = X;
        if (u < 0) {
          int i = uf[~u];
          A.set(i, A.get(i) + v);
        } else {
          u = uf[u], v = uf[v];
          if (u != v) {
            uf.merge(u, v);
            int r = uf[u];
            A.set(r, A.get(u) + A.get(v));
          }
        }
        continue;
      }
      if (a < mid) IL.eb(i);
      if (mid < b) IR.eb(i);
    }
    if (begin + 1 == end) {
      // 求値クエリ
      int v = query[begin];
      ANS[begin] = A.get(uf[v]);
    } else {
      dfs(dfs, IL, begin, mid);
      dfs(dfs, IR, mid, end);
    }
    A.rollback(a_time);
    uf.rollback(uf_time);
  };
  dfs(dfs, I, 0, Q);

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
