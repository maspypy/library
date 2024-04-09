#include "string/palindromic_tree.hpp"

/*
https://arxiv.org/pdf/1403.2431.pdf
回文に分割する dp は O(nlog n) time, O(n) space になる
同じところに遷移するものをまとめたもの gdp
・dp[i] := dp_init[i]
・F(i, dp[i], gdp[j]): dp[i] に gdp[j] からの遷移を追加
・gdp[i] := gdp_unit
・G(i, gdp[j], dp[i]): gdp[j] に dp[i] からの遷移をまとめる
偶数長のものに制限してやることもある
この場合 i が奇数のときの F は何もしなければよい
https://codeforces.com/contest/932/problem/G
https://codeforces.com/problemset/problem/906/E
*/
template <typename DP, typename GDP, typename F1, typename F2>
vc<DP> palindrome_decomposition_dp(string S, vc<DP> dp_init, GDP gdp_unit, F1 F,
                                   F2 G) {
  int N = len(S);
  Palindromic_Tree<26> X(S, 'a');
  int n = len(X.nodes);
  /*
  各ノードに対して
  suffix との長さの差分
  同じ差分で何ステップ遡れるか？
  遡った先の node
  */
  vc<int> diff(n, infty<int>);
  vc<int> step(n);
  vc<int> up(n);
  FOR(v, 2, n) {
    int w = X.nodes[v].link;
    int d = X.nodes[v].length - X.nodes[w].length;
    diff[v] = d;
    step[v] = (diff[v] == diff[w] ? step[w] : 0) + 1;
    up[v] = (diff[v] == diff[w] ? up[w] : w);
  }

  vc<DP>& dp = dp_init;
  assert(len(dp) == N + 1);
  vc<GDP> gdp(N + 1);
  auto& path = X.path;
  FOR(j, 1, N + 1) {
    int v = path[j];
    int i = j - X.nodes[v].length;
    while (v >= 2) {
      if (step[v] == 1) {
        // 1 項だけからなる等差数列の集約で初期化
        gdp[i] = gdp_unit;
        gdp[i] = G(i, gdp[i], dp[i]);
      } else {
        // 等差数列の末尾を追加
        int idx = i + diff[v] * (step[v] - 1);
        gdp[i] = G(idx, gdp[i], dp[idx]);
      }
      dp[j] = F(j, dp[j], gdp[i]), i += diff[v] * step[v], v = up[v];
    }
  }
  return dp;
}
