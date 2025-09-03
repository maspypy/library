#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "ds/unionfind/unionfind.hpp"
#include "graph/tree_dp/subtree_hash.hpp"
#include "enumerate/unlabeled_tree.hpp"

void test(int n) {
  /*
  ・数え上げが正しいこと
  ・木になること
  ・あとは目視でいいか
  */
  int cnt = 0;
  enumerate_unlabeled_tree(n, [&](vc<pair<int, int>> edges) -> void {
    ++cnt;
    assert(len(edges) == n - 1);
    // if (n <= 6) { print(n, ",", edges); }
    UnionFind uf(n);
    for (auto& [a, b]: edges) { assert(uf.merge(a, b)); }
  });
  // https://oeis.org/A000055
  vi AC = {
      0, 1, 1, 1, 2, 3, 6, 11, 23, 47, 106, 235, 551, 1301, 3159, 7741, 19320, 48629, 123867, 317955, 823065, 2144505, 5623756, 14828074, 39299897, 104636890,
  };
  assert(cnt == AC[n]);
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(n, 1, 21) test(n);
  solve();
  return 0;
}