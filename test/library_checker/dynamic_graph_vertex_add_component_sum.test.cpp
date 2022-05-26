#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "pds/rollbackunionfind.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, a, N);

  using QT = tuple<int, int, int>;
  vc<QT> query(Q);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(u, v);
      if (u > v) swap(u, v);
      query[q] = {t, u, v};
    }
    if (t == 1) {
      LL(u, v);
      if (u > v) swap(u, v);
      query[q] = {t, u, v};
    }
    if (t == 2) {
      LL(v, x);
      query[q] = {t, v, x};
    }
    if (t == 3) {
      LL(v);
      query[q] = {t, v, -1};
    }
  }

  map<pair<int, int>, vc<int>> MP;
  FOR(q, Q) {
    auto& [t, a, b] = query[q];
    if (t == 0 || t == 1) {
      pair<int, int> p = {a, b};
      MP[p].eb(q);
    }
  }

  int size = 1;
  while (size < Q) size *= 2;

  /*
  0 a b ： merge a, b
  1 v x : add v x
  2 q v: answer query q
  */

  vvc<QT> query2(2 * size);
  for (auto&& [p, Ts]: MP) {
    if (Ts.size() % 2 == 1) Ts.eb(Q);
    auto [a, b] = p;
    FOR(i, 0, len(Ts), 2) {
      ll l = Ts[i];
      ll r = Ts[i + 1];
      l += size;
      r += size;
      while (l < r) {
        if (l % 2 == 1) { query2[l++].eb(0, a, b); }
        if (r % 2 == 1) { query2[--r].eb(0, a, b); }
        l /= 2, r /= 2;
      }
    }
  }
  FOR(q, Q) {
    auto [t, a, b] = query[q];
    if (t == 0 || t == 1) continue;
    if (t == 2) {
      int v = a, x = b;
      ll l = q, r = Q;
      l += size;
      r += size;
      while (l < r) {
        if (l % 2 == 1) { query2[l++].eb(1, v, x); }
        if (r % 2 == 1) { query2[--r].eb(1, v, x); }
        l /= 2, r /= 2;
      }
    }
    if (t == 3) { query2[q + size].eb(2, q, a); }
  }

  RollbackArray<ll> A(a);
  RollbackUnionFind uf(N);
  vi ANS(Q);

  auto dfs = [&](auto& dfs, int idx) -> void {
    int time1 = A.time();
    int time2 = uf.time();
    //
    for (auto&& [t, a, b]: query2[idx]) {
      if (t == 0) {
        a = uf[a], b = uf[b];
        if (a == b) continue;
        uf.merge(a, b);
        A.set(uf[a], A.get(a) + A.get(b));
      }
      if (t == 1) {
        a = uf[a];
        A.set(a, A.get(a) + b);
      }
      if (t == 2) {
        ll ans = A.get(uf[b]);
        ANS[a] = ans;
      }
    }
    if (idx < size) {
      dfs(dfs, 2 * idx + 0);
      dfs(dfs, 2 * idx + 1);
    }
    A.rollback(time1);
    uf.rollback(time2);
  };
  dfs(dfs, 1);
  FOR(q, Q) {
    auto [t, a, b] = query[q];
    if (t == 3) print(ANS[q]);
  }
}

signed main() {
  solve();

  return 0;
}
