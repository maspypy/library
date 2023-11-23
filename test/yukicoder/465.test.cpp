#define PROBLEM "https://yukicoder.me/problems/no/465"

#include "my_template.hpp"
#include "other/io.hpp"

#include "string/palindromic_tree.hpp"

/*
解説にある論文
https://arxiv.org/pdf/1403.2431.pdf
P[r] := {l | S[l:r) is a non-empty palindrome}
これは O(log) 個の等差数列として書ける.
gdp[i]: 等差数列の左端となる点 i に i,i+d,i+2d,... を始点とする
palindrome の集約値を入れる.
*/
vc<pair<int, int>> calc(string S) {
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

  // P, PP
  vc<pair<int, int>> dp(N + 1);
  vc<int> gdp(N + 1);

  auto& path = X.path;
  FOR(j, 1, N + 1) {
    int v = path[j];
    int i = j - X.nodes[v].length;
    dp[j].fi = (i == 0);
    while (v >= 2) {
      if (step[v] == 1) {
        // 1 項だけからなる等差数列の集約で初期化
        gdp[i] = dp[i].fi;
      } else {
        // 等差数列の末尾を追加
        gdp[i] += dp[i + diff[v] * (step[v] - 1)].fi;
      }
      dp[j].se += gdp[i], i += diff[v] * step[v], v = up[v];
    }
    // print(j, dp[j]);
  }
  return dp;
}

void solve() {
  STR(S);
  int N = len(S);
  auto dp1 = calc(S);
  reverse(all(S));
  auto dp2 = calc(S);
  vc<int> PA(N);
  FOR(n, N) { PA[n] = dp2[n].fi; }
  PA = cumsum<int>(PA);
  ll ANS = 0;
  FOR(i, N + 1) ANS += dp1[i].se * ll(PA[N - i]);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}