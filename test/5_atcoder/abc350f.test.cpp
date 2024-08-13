#define PROBLEM "https://atcoder.jp/contests/abc350/tasks/abc350_f"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/splaytree/splaytree.hpp"
#include "ds/splaytree/splaytree_basic.hpp"

void solve() {
  STR(S);
  ll N = len(S);
  SplayTree_Basic<char, 1 << 20> ST;
  using np = decltype(ST)::np;

  int p = 0;
  auto dfs = [&](auto& dfs, int dep) -> np {
    np ans = ST.new_root();
    while (p < len(S)) {
      if (S[p] == '(') {
        ++p;
        auto x = dfs(dfs, dep + 1);
        ST.reverse(x);
        ans = ST.merge(ans, x);
        assert(S[p] == ')');
        ++p;
        continue;
      }
      if (S[p] == ')') { break; }
      char c = S[p];
      if (dep % 2 == 1) c ^= 32;
      np x = ST.new_node(c);
      ans = ST.merge(ans, x);
      p++;
    }
    return ans;
  };

  auto ans = dfs(dfs, 0);
  auto ANS = ST.get_all(ans);
  string X;
  for (auto& ch: ANS) X += ch;
  print(X);
}

signed main() {
  solve();
  return 0;
}