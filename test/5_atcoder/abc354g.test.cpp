#define PROBLEM "https://atcoder.jp/contests/abc354/tasks/abc354_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/is_substring.hpp"
#include "graph/maximum_weighted_antichain.hpp"

void solve() {
  LL(N);
  VEC(string, S, N);
  VEC(ll, A, N);
  {
    map<string, ll> MP;
    FOR(i, N) { chmax(MP[S[i]], A[i]); }
    S.clear();
    A.clear();
    for (auto& [a, b]: MP) { S.eb(a), A.eb(b); }
    N = len(S);
  }
  Graph<int, 1> G(N);
  FOR(i, N) FOR(j, N) {
    if (i == j) continue;
    if (is_substring(S[i], S[j])) G.add(i, j);
  }
  G.build();
  auto [ans, antichain] = maximum_weighted_antichain<ll>(G, A);
  print(ans);

  vc<int> tmp(N);
  ll sm = 0;
  for (auto& v: antichain) { tmp[v] = 1, sm += A[v]; }
  for (auto& e: G.edges) { assert(!tmp[e.frm] || !tmp[e.to]); }
  assert(sm == ans);
}

signed main() { solve(); }
