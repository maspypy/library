#define PROBLEM "https://yukicoder.me/problems/no/2360"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/suffix_array.hpp"
#include "string/suffix_tree.hpp"
#include "alg/monoid/min_idx.hpp"

void solve() {
  LL(N, Q);
  STR(S);
  Suffix_Array X(S);

  VEC(pi, query, Q);
  for (auto&& [a, b]: query) --a;

  // 場所 -> 長さ, クエリ番号
  vvc<pi> dat(N);
  FOR(q, Q) {
    auto [a, b] = query[q];
    ll n = b - a;
    dat[X.ISA[a]].eb(n, q);
  }

  FOR(i, N) {
    sort(all(dat[i]));
    reverse(all(dat[i]));
  }

  SegTree<Monoid_Min_Idx<int>> seg(N);

  auto upd = [&](int i) -> void {
    if (dat[i].empty())
      seg.set(i, {infty<int>, -1});
    else
      seg.set(i, {dat[i].back().fi, i});
  };

  FOR(i, N) upd(i);

  vi ANS(Q);
  auto [G, rect] = suffix_tree(X);
  ll vis = 0;
  auto dfs = [&](auto& dfs, int v) -> void {
    auto [L, R, a, b] = rect[v];
    ++a, ++b; // 文字列長
    while (1) {
      auto [mi, idx] = seg.prod(L, R);
      if (mi >= b) break;
      auto [sz, qid] = POP(dat[idx]);
      assert(sz == mi);
      upd(idx);
      ll ans = vis;
      ans += (mi - a) * (R - L);
      ANS[qid] = ans;
    }
    vis += (R - L) * (b - a);
    for (auto&& e: G[v]) dfs(dfs, e.to);
  };
  dfs(dfs, 0);

  for (auto&& x: ANS) print(x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
