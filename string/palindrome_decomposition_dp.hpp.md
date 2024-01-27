---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/palindromic_tree.hpp
    title: string/palindromic_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/palindrome_decomposition_dp.test.cpp
    title: test/mytest/palindrome_decomposition_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/465.test.cpp
    title: test/yukicoder/465.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/pdf/1403.2431.pdf
    - https://codeforces.com/contest/932/problem/G
  bundledCode: "#line 1 \"string/palindromic_tree.hpp\"\n// palindromic tree \u3092\
    \u4F5C\u308B\ntemplate <int sigma>\nstruct Palindromic_Tree {\n  struct Node {\n\
    \    array<int, sigma> TO;\n    int link;\n    int length;\n    pair<int, int>\
    \ pos; // position of first ocurrence\n    Node(int link, int length, int l, int\
    \ r)\n        : link(link), length(length), pos({l, r}) {\n      fill(all(TO),\
    \ -1);\n    }\n  };\n\n  vc<Node> nodes;\n  vc<int> path;\n\n  template <typename\
    \ STRING>\n  Palindromic_Tree(const STRING& S, char off) {\n    nodes.eb(Node(-1,\
    \ -1, 0, -1));\n    nodes.eb(Node(0, 0, 0, 0));\n    int p = 0;\n    FOR(i, len(S))\
    \ {\n      path.eb(p);\n      int x = S[i] - off;\n      while (p) {\n       \
    \ int j = i - 1 - nodes[p].length;\n        bool can = (j >= 0 && S[j] - off ==\
    \ x);\n        if (!can) {\n          p = nodes[p].link;\n          continue;\n\
    \        }\n        break;\n      }\n      if (nodes[p].TO[x] != -1) {\n     \
    \   p = nodes[p].TO[x];\n        continue;\n      }\n      int to = len(nodes);\n\
    \      int l = i - 1 - nodes[p].length;\n      int r = i + 1;\n      nodes[p].TO[x]\
    \ = to;\n\n      int link;\n      if (p == 0) link = 1;\n      if (p != 0) {\n\
    \        while (1) {\n          p = nodes[p].link;\n          int j = i - 1 -\
    \ nodes[p].length;\n          bool can = (j >= 0 && S[j] - off == x) || (p ==\
    \ 0);\n          if (can) break;\n        }\n        assert(nodes[p].TO[x] !=\
    \ -1);\n        link = nodes[p].TO[x];\n      }\n      nodes.eb(Node(link, r -\
    \ l, l, r));\n      p = to;\n    }\n    path.eb(p);\n  }\n\n  // node \u3054\u3068\
    \u306E\u51FA\u73FE\u56DE\u6570\n  vc<int> count() {\n    vc<int> res(len(nodes));\n\
    \    for (auto&& p: path) res[p]++;\n    FOR_R(k, 1, len(nodes)) {\n      int\
    \ link = nodes[k].link;\n      res[link] += res[k];\n    }\n    return res;\n\
    \  }\n};\n#line 2 \"string/palindrome_decomposition_dp.hpp\"\n\n// dp[i] := \u3059\
    \u3079\u3066\u306E n \u500B\u3078\u306E\u5206\u5272\u306B\u5BFE\u3059\u308B x^n\
    \ \u306E\u7DCF\u548C\n// dp[j] = sum_i dp[i]*x if [i,j) palindrome\n// https://arxiv.org/pdf/1403.2431.pdf\n\
    // \u5076\u6570\u9577\u306E\u3082\u306E\u306B\u5236\u9650\u3057\u3066\u3084\u308B\
    \uFF1Ahttps://codeforces.com/contest/932/problem/G\ntemplate <typename T, typename\
    \ F1, typename F2>\nvc<T> palindrome_decomposition_dp(string S, T add_unit, T\
    \ mul_unit, F1 add,\n                                  F2 mul_x) {\n  int N =\
    \ len(S);\n  Palindromic_Tree<26> X(S, 'a');\n  int n = len(X.nodes);\n  // even\
    \ length \u306B\u5236\u9650\n\n  /*\n  \u5404\u30CE\u30FC\u30C9\u306B\u5BFE\u3057\
    \u3066\n  suffix \u3068\u306E\u9577\u3055\u306E\u5DEE\u5206\n  \u540C\u3058\u5DEE\
    \u5206\u3067\u4F55\u30B9\u30C6\u30C3\u30D7\u9061\u308C\u308B\u304B\uFF1F\n  \u9061\
    \u3063\u305F\u5148\u306E node\n  */\n  vc<int> diff(n, infty<int>);\n  vc<int>\
    \ step(n);\n  vc<int> up(n);\n  FOR(v, 2, n) {\n    int w = X.nodes[v].link;\n\
    \    int d = X.nodes[v].length - X.nodes[w].length;\n    diff[v] = d;\n    step[v]\
    \ = (diff[v] == diff[w] ? step[w] : 0) + 1;\n    up[v] = (diff[v] == diff[w] ?\
    \ up[w] : w);\n  }\n\n  vc<T> dp(N + 1, add_unit);\n  vc<T> gdp(N + 1, add_unit);\n\
    \  dp[0] = mul_unit;\n\n  auto& path = X.path;\n  FOR(j, 1, N + 1) {\n    int\
    \ v = path[j];\n    int i = j - X.nodes[v].length;\n    while (v >= 2) {\n   \
    \   if (step[v] == 1) {\n        // 1 \u9805\u3060\u3051\u304B\u3089\u306A\u308B\
    \u7B49\u5DEE\u6570\u5217\u306E\u96C6\u7D04\u3067\u521D\u671F\u5316\n        gdp[i]\
    \ = dp[i];\n      } else {\n        // \u7B49\u5DEE\u6570\u5217\u306E\u672B\u5C3E\
    \u3092\u8FFD\u52A0\n        gdp[i] = add(gdp[i], dp[i + diff[v] * (step[v] - 1)]);\n\
    \      }\n      dp[j] = add(dp[j], mul_x(gdp[i])), i += diff[v] * step[v], v =\
    \ up[v];\n    }\n  }\n  return dp;\n}\n"
  code: "#include \"string/palindromic_tree.hpp\"\n\n// dp[i] := \u3059\u3079\u3066\
    \u306E n \u500B\u3078\u306E\u5206\u5272\u306B\u5BFE\u3059\u308B x^n \u306E\u7DCF\
    \u548C\n// dp[j] = sum_i dp[i]*x if [i,j) palindrome\n// https://arxiv.org/pdf/1403.2431.pdf\n\
    // \u5076\u6570\u9577\u306E\u3082\u306E\u306B\u5236\u9650\u3057\u3066\u3084\u308B\
    \uFF1Ahttps://codeforces.com/contest/932/problem/G\ntemplate <typename T, typename\
    \ F1, typename F2>\nvc<T> palindrome_decomposition_dp(string S, T add_unit, T\
    \ mul_unit, F1 add,\n                                  F2 mul_x) {\n  int N =\
    \ len(S);\n  Palindromic_Tree<26> X(S, 'a');\n  int n = len(X.nodes);\n  // even\
    \ length \u306B\u5236\u9650\n\n  /*\n  \u5404\u30CE\u30FC\u30C9\u306B\u5BFE\u3057\
    \u3066\n  suffix \u3068\u306E\u9577\u3055\u306E\u5DEE\u5206\n  \u540C\u3058\u5DEE\
    \u5206\u3067\u4F55\u30B9\u30C6\u30C3\u30D7\u9061\u308C\u308B\u304B\uFF1F\n  \u9061\
    \u3063\u305F\u5148\u306E node\n  */\n  vc<int> diff(n, infty<int>);\n  vc<int>\
    \ step(n);\n  vc<int> up(n);\n  FOR(v, 2, n) {\n    int w = X.nodes[v].link;\n\
    \    int d = X.nodes[v].length - X.nodes[w].length;\n    diff[v] = d;\n    step[v]\
    \ = (diff[v] == diff[w] ? step[w] : 0) + 1;\n    up[v] = (diff[v] == diff[w] ?\
    \ up[w] : w);\n  }\n\n  vc<T> dp(N + 1, add_unit);\n  vc<T> gdp(N + 1, add_unit);\n\
    \  dp[0] = mul_unit;\n\n  auto& path = X.path;\n  FOR(j, 1, N + 1) {\n    int\
    \ v = path[j];\n    int i = j - X.nodes[v].length;\n    while (v >= 2) {\n   \
    \   if (step[v] == 1) {\n        // 1 \u9805\u3060\u3051\u304B\u3089\u306A\u308B\
    \u7B49\u5DEE\u6570\u5217\u306E\u96C6\u7D04\u3067\u521D\u671F\u5316\n        gdp[i]\
    \ = dp[i];\n      } else {\n        // \u7B49\u5DEE\u6570\u5217\u306E\u672B\u5C3E\
    \u3092\u8FFD\u52A0\n        gdp[i] = add(gdp[i], dp[i + diff[v] * (step[v] - 1)]);\n\
    \      }\n      dp[j] = add(dp[j], mul_x(gdp[i])), i += diff[v] * step[v], v =\
    \ up[v];\n    }\n  }\n  return dp;\n}\n"
  dependsOn:
  - string/palindromic_tree.hpp
  isVerificationFile: false
  path: string/palindrome_decomposition_dp.hpp
  requiredBy: []
  timestamp: '2023-12-29 11:33:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/palindrome_decomposition_dp.test.cpp
  - test/yukicoder/465.test.cpp
documentation_of: string/palindrome_decomposition_dp.hpp
layout: document
redirect_from:
- /library/string/palindrome_decomposition_dp.hpp
- /library/string/palindrome_decomposition_dp.hpp.html
title: string/palindrome_decomposition_dp.hpp
---
