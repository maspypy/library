---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/palindromic_tree.hpp
    title: string/palindromic_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/palindrome_decomposition_dp.test.cpp
    title: test/1_mytest/palindrome_decomposition_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/465.test.cpp
    title: test/3_yukicoder/465.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/pdf/1403.2431.pdf
    - https://codeforces.com/contest/932/problem/G
    - https://codeforces.com/problemset/problem/906/E
  bundledCode: "#line 1 \"string/palindromic_tree.hpp\"\ntemplate <int sigma>\nstruct\
    \ Palindromic_Tree {\n  struct Node {\n    array<int, sigma> TO;\n    int link;\n\
    \    int length;\n    int diff;            // link \u3068\u306E\u5DEE\u5206\n\
    \    int slink;           // series link, diff \u3067\u306A\u308B\u3079\u304F\u305F\
    \u3069\u3063\u305F\u5148\n    pair<int, int> pos;  // one occurrence [l, r)\n\n\
    \    Node(int link = -1, int length = 0, int l = 0, int r = 0)\n        : link(link),\
    \ length(length), diff(0), slink(0), pos({l, r}) {\n      fill(all(TO), -1);\n\
    \    }\n  };\n\n  vc<Node> nodes;\n  // |path|=|S|+1\n  // path[i]: longest palindromic\
    \ suffix of S[0, i)\n  vc<int> path;\n\n  Palindromic_Tree() {}\n\n  template\
    \ <typename STRING>\n  Palindromic_Tree(const STRING& S, char off) {\n    build(S,\
    \ off);\n  }\n\n  int size() const { return len(nodes); }\n\n  template <typename\
    \ STRING>\n  void build(const STRING& S, char off) {\n    nodes.clear();\n   \
    \ path.clear();\n\n    // 0: imaginary root (length = -1)\n    // 1: empty root\
    \ (length = 0)\n    nodes.eb(Node(-1, -1, 0, -1));\n    nodes.eb(Node(0, 0, 0,\
    \ 0));\n    nodes[0].diff = nodes[1].diff = 0;\n    nodes[0].slink = nodes[1].slink\
    \ = 0;\n\n    int p = 1;\n    FOR(i, len(S)) {\n      path.eb(p);\n      int x\
    \ = S[i] - off;\n      assert(0 <= x && x < sigma);\n\n      while (p) {\n   \
    \     int j = i - 1 - nodes[p].length;\n        bool can = (j >= 0 && S[j] - off\
    \ == x);\n        if (can) break;\n        p = nodes[p].link;\n      }\n\n   \
    \   if (nodes[p].TO[x] != -1) {\n        p = nodes[p].TO[x];\n        continue;\n\
    \      }\n\n      int to = len(nodes);\n      int l = i - 1 - nodes[p].length;\n\
    \      int r = i + 1;\n      nodes[p].TO[x] = to;\n\n      int link = 1;\n   \
    \   if (p != 0) {\n        int q = nodes[p].link;\n        while (1) {\n     \
    \     int j = i - 1 - nodes[q].length;\n          bool can = (j >= 0 && S[j] -\
    \ off == x);\n          if (can) break;\n          q = nodes[q].link;\n      \
    \  }\n        assert(nodes[q].TO[x] != -1);\n        link = nodes[q].TO[x];\n\
    \      }\n\n      nodes.eb(Node(link, r - l, l, r));\n      nodes[to].diff = nodes[to].length\
    \ - nodes[link].length;\n      nodes[to].slink =\n          (nodes[to].diff ==\
    \ nodes[link].diff ? nodes[link].slink : link);\n      p = to;\n    }\n    path.eb(p);\n\
    \  }\n\n  // length of maximum suffix palindrome of [l,r)\n  int max_suffix_length(int\
    \ l, int r) {\n    assert(0 <= l && l < r && r < len(path));\n    int n = r -\
    \ l;\n    int v = path[r];\n    while (v > 1) {\n      int d = nodes[v].diff;\n\
    \      int hi = nodes[v].length;\n      int u = nodes[v].slink;\n      int low\
    \ = nodes[u].length + d;\n      if (hi <= n) return hi;\n      if (low <= n) {\n\
    \        // hi - xd <= n\n        int x = ceil<int>(hi - n, d);\n        return\
    \ hi - x * d;\n      }\n      v = u;\n    }\n    assert(false);\n  }\n\n  // node(>=2)\
    \ \u3054\u3068\u306E\u51FA\u73FE\u56DE\u6570\n  vc<int> count() {\n    vc<int>\
    \ res(len(nodes));\n    for (auto&& p : path) res[p]++;\n    FOR_R(k, 1, len(nodes))\
    \ {\n      int link = nodes[k].link;\n      res[link] += res[k];\n    }\n    res[0]\
    \ = res[1] = 0;\n    return res;\n  }\n};\n#line 2 \"string/palindrome_decomposition_dp.hpp\"\
    \n\n/*\nhttps://arxiv.org/pdf/1403.2431.pdf\n\u56DE\u6587\u306B\u5206\u5272\u3059\
    \u308B dp \u306F O(nlog n) time, O(n) space \u306B\u306A\u308B\n\u540C\u3058\u3068\
    \u3053\u308D\u306B\u9077\u79FB\u3059\u308B\u3082\u306E\u3092\u307E\u3068\u3081\
    \u305F\u3082\u306E gdp\n\u30FBdp[i] := dp_init[i]\n\u30FBF(i, dp[i], gdp[j]):\
    \ dp[i] \u306B gdp[j] \u304B\u3089\u306E\u9077\u79FB\u3092\u8FFD\u52A0\n\u30FB\
    gdp[i] := gdp_unit\n\u30FBG(i, gdp[j], dp[i]): gdp[j] \u306B dp[i] \u304B\u3089\
    \u306E\u9077\u79FB\u3092\u307E\u3068\u3081\u308B\n\u5076\u6570\u9577\u306E\u3082\
    \u306E\u306B\u5236\u9650\u3057\u3066\u3084\u308B\u3053\u3068\u3082\u3042\u308B\
    \n\u3053\u306E\u5834\u5408 i \u304C\u5947\u6570\u306E\u3068\u304D\u306E F \u306F\
    \u4F55\u3082\u3057\u306A\u3051\u308C\u3070\u3088\u3044\nhttps://codeforces.com/contest/932/problem/G\n\
    https://codeforces.com/problemset/problem/906/E\n*/\ntemplate <typename DP, typename\
    \ GDP, typename F1, typename F2>\nvc<DP> palindrome_decomposition_dp(string S,\
    \ vc<DP> dp_init, GDP gdp_unit, F1 F,\n                                   F2 G)\
    \ {\n  int N = len(S);\n  Palindromic_Tree<26> X(S, 'a');\n  int n = len(X.nodes);\n\
    \  /*\n  \u5404\u30CE\u30FC\u30C9\u306B\u5BFE\u3057\u3066\n  suffix \u3068\u306E\
    \u9577\u3055\u306E\u5DEE\u5206\n  \u540C\u3058\u5DEE\u5206\u3067\u4F55\u30B9\u30C6\
    \u30C3\u30D7\u9061\u308C\u308B\u304B\uFF1F\n  \u9061\u3063\u305F\u5148\u306E node\n\
    \  */\n  vc<int> diff(n, infty<int>);\n  vc<int> step(n);\n  vc<int> up(n);\n\
    \  FOR(v, 2, n) {\n    int w = X.nodes[v].link;\n    int d = X.nodes[v].length\
    \ - X.nodes[w].length;\n    diff[v] = d;\n    step[v] = (diff[v] == diff[w] ?\
    \ step[w] : 0) + 1;\n    up[v] = (diff[v] == diff[w] ? up[w] : w);\n  }\n\n  vc<DP>&\
    \ dp = dp_init;\n  assert(len(dp) == N + 1);\n  vc<GDP> gdp(N + 1);\n  auto& path\
    \ = X.path;\n  FOR(j, 1, N + 1) {\n    int v = path[j];\n    int i = j - X.nodes[v].length;\n\
    \    while (v >= 2) {\n      if (step[v] == 1) {\n        // 1 \u9805\u3060\u3051\
    \u304B\u3089\u306A\u308B\u7B49\u5DEE\u6570\u5217\u306E\u96C6\u7D04\u3067\u521D\
    \u671F\u5316\n        gdp[i] = gdp_unit;\n        gdp[i] = G(i, gdp[i], dp[i]);\n\
    \      } else {\n        // \u7B49\u5DEE\u6570\u5217\u306E\u672B\u5C3E\u3092\u8FFD\
    \u52A0\n        int idx = i + diff[v] * (step[v] - 1);\n        gdp[i] = G(idx,\
    \ gdp[i], dp[idx]);\n      }\n      dp[j] = F(j, dp[j], gdp[i]), i += diff[v]\
    \ * step[v], v = up[v];\n    }\n  }\n  return dp;\n}\n"
  code: "#include \"string/palindromic_tree.hpp\"\n\n/*\nhttps://arxiv.org/pdf/1403.2431.pdf\n\
    \u56DE\u6587\u306B\u5206\u5272\u3059\u308B dp \u306F O(nlog n) time, O(n) space\
    \ \u306B\u306A\u308B\n\u540C\u3058\u3068\u3053\u308D\u306B\u9077\u79FB\u3059\u308B\
    \u3082\u306E\u3092\u307E\u3068\u3081\u305F\u3082\u306E gdp\n\u30FBdp[i] := dp_init[i]\n\
    \u30FBF(i, dp[i], gdp[j]): dp[i] \u306B gdp[j] \u304B\u3089\u306E\u9077\u79FB\u3092\
    \u8FFD\u52A0\n\u30FBgdp[i] := gdp_unit\n\u30FBG(i, gdp[j], dp[i]): gdp[j] \u306B\
    \ dp[i] \u304B\u3089\u306E\u9077\u79FB\u3092\u307E\u3068\u3081\u308B\n\u5076\u6570\
    \u9577\u306E\u3082\u306E\u306B\u5236\u9650\u3057\u3066\u3084\u308B\u3053\u3068\
    \u3082\u3042\u308B\n\u3053\u306E\u5834\u5408 i \u304C\u5947\u6570\u306E\u3068\u304D\
    \u306E F \u306F\u4F55\u3082\u3057\u306A\u3051\u308C\u3070\u3088\u3044\nhttps://codeforces.com/contest/932/problem/G\n\
    https://codeforces.com/problemset/problem/906/E\n*/\ntemplate <typename DP, typename\
    \ GDP, typename F1, typename F2>\nvc<DP> palindrome_decomposition_dp(string S,\
    \ vc<DP> dp_init, GDP gdp_unit, F1 F,\n                                   F2 G)\
    \ {\n  int N = len(S);\n  Palindromic_Tree<26> X(S, 'a');\n  int n = len(X.nodes);\n\
    \  /*\n  \u5404\u30CE\u30FC\u30C9\u306B\u5BFE\u3057\u3066\n  suffix \u3068\u306E\
    \u9577\u3055\u306E\u5DEE\u5206\n  \u540C\u3058\u5DEE\u5206\u3067\u4F55\u30B9\u30C6\
    \u30C3\u30D7\u9061\u308C\u308B\u304B\uFF1F\n  \u9061\u3063\u305F\u5148\u306E node\n\
    \  */\n  vc<int> diff(n, infty<int>);\n  vc<int> step(n);\n  vc<int> up(n);\n\
    \  FOR(v, 2, n) {\n    int w = X.nodes[v].link;\n    int d = X.nodes[v].length\
    \ - X.nodes[w].length;\n    diff[v] = d;\n    step[v] = (diff[v] == diff[w] ?\
    \ step[w] : 0) + 1;\n    up[v] = (diff[v] == diff[w] ? up[w] : w);\n  }\n\n  vc<DP>&\
    \ dp = dp_init;\n  assert(len(dp) == N + 1);\n  vc<GDP> gdp(N + 1);\n  auto& path\
    \ = X.path;\n  FOR(j, 1, N + 1) {\n    int v = path[j];\n    int i = j - X.nodes[v].length;\n\
    \    while (v >= 2) {\n      if (step[v] == 1) {\n        // 1 \u9805\u3060\u3051\
    \u304B\u3089\u306A\u308B\u7B49\u5DEE\u6570\u5217\u306E\u96C6\u7D04\u3067\u521D\
    \u671F\u5316\n        gdp[i] = gdp_unit;\n        gdp[i] = G(i, gdp[i], dp[i]);\n\
    \      } else {\n        // \u7B49\u5DEE\u6570\u5217\u306E\u672B\u5C3E\u3092\u8FFD\
    \u52A0\n        int idx = i + diff[v] * (step[v] - 1);\n        gdp[i] = G(idx,\
    \ gdp[i], dp[idx]);\n      }\n      dp[j] = F(j, dp[j], gdp[i]), i += diff[v]\
    \ * step[v], v = up[v];\n    }\n  }\n  return dp;\n}\n"
  dependsOn:
  - string/palindromic_tree.hpp
  isVerificationFile: false
  path: string/palindrome_decomposition_dp.hpp
  requiredBy: []
  timestamp: '2026-03-14 08:28:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/465.test.cpp
  - test/1_mytest/palindrome_decomposition_dp.test.cpp
documentation_of: string/palindrome_decomposition_dp.hpp
layout: document
redirect_from:
- /library/string/palindrome_decomposition_dp.hpp
- /library/string/palindrome_decomposition_dp.hpp.html
title: string/palindrome_decomposition_dp.hpp
---
