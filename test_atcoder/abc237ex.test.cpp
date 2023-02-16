#define PROBLEM "https://atcoder.jp/contests/abc237/tasks/abc237_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/maximum_antichain.hpp"
#include "string/is_substring.hpp"

void solve() {
  set<string> ss;
  STR(S);
  ll N = len(S);
  FOR(l, N) FOR3(r, l + 1, N + 1) {
    string T = S.substr(l, r - l);
    string U = T;
    reverse(all(U));
    if (T == U) ss.insert(T);
  }
  vc<string> A;
  for (auto&& x: ss) A.eb(x);
  N = len(A);
  Graph<int, 1> G(N);
  FOR(i, N) FOR(j, N) if (i != j) {
    if (is_substring(A[i], A[j])) G.add(i, j);
  }
  print(len(maximum_antichain(G)));
}

signed main() {
  solve();
  return 0;
}