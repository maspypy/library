#define PROBLEM "https://yukicoder.me/problems/no/263"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/rollinghash.hpp"
#include "string/palindromic_tree.hpp"
#include "ds/hashmap.hpp"

void solve() {
  RollingHash RH;
  using M61 = modint61;

  auto get = [&]() -> vc<pair<ll, int>> {
    vc<pair<ll, int>> res;
    STR(S);
    Palindromic_Tree<26> X(S, 'A');
    auto SH = RH.build(S);
    auto CNT = X.count();
    FOR(i, len(X.nodes)) {
      if (X.nodes[i].length <= 0) continue;
      auto [l, r] = X.nodes[i].pos;
      M61 x = RH.query(SH, l, r);
      res.eb(x.val, CNT[i]);
    }
    return res;
  };

  auto A = get();
  auto B = get();

  HashMapLL<int, 20> MP;
  for (auto&& [x, cnt]: A) MP[x] += cnt;
  ll ANS = 0;
  for (auto&& [y, cnt]: B) { ANS += MP.get(y, 0) * ll(cnt); }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
