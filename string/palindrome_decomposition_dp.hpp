#include "string/palindromic_tree.hpp"

// dp[i] := すべての n 個への分割に対する x^n の総和
// dp[j] = sum_i dp[i]*x if [i,j) palindrome
// https://arxiv.org/pdf/1403.2431.pdf
// 偶数長のものに制限してやる：https://codeforces.com/contest/932/problem/G
template <typename T, typename F1, typename F2>
vc<T> palindrome_decomposition_dp(string S, T add_unit, T mul_unit, F1 add,
                                  F2 mul_x) {
  int N = len(S);
  Palindromic_Tree<26> X(S, 'a');
  int n = len(X.nodes);
  // even length に制限

  /*
  各ノードに対して
  suffix との長さの差分
  同じ差分で何ステップ遡れるか？
  遡った先の node
  */
  vc<int> diff(n, infty<int>);
  vc<int> step(n);
  vc<int> up(n);
  vc<int> even_link FOR(v, 2, n) {
    int w = X.nodes[v].link;
    int d = X.nodes[v].length - X.nodes[w].length;
    diff[v] = d;
    step[v] = (diff[v] == diff[w] ? step[w] : 0) + 1;
    up[v] = (diff[v] == diff[w] ? up[w] : w);
  }

  vc<T> dp(N + 1, add_unit);
  vc<T> gdp(N + 1, add_unit);
  dp[0] = mul_unit;

  auto& path = X.path;
  FOR(j, 1, N + 1) {
    int v = path[j];
    int i = j - X.nodes[v].length;
    while (v >= 2) {
      if (step[v] == 1) {
        // 1 項だけからなる等差数列の集約で初期化
        gdp[i] = dp[i];
      } else {
        // 等差数列の末尾を追加
        gdp[i] = add(gdp[i], dp[i + diff[v] * (step[v] - 1)]);
      }
      dp[j] = add(dp[j], mul_x(gdp[i])), i += diff[v] * step[v], v = up[v];
    }
  }
  return dp;
}
