---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/palindrome_decomposition_dp.hpp
    title: string/palindrome_decomposition_dp.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/palindrome_decomposition_dp.test.cpp
    title: test/1_mytest/palindrome_decomposition_dp.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/eertree.test.cpp
    title: test/2_library_checker/string/eertree.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2606.test.cpp
    title: test/3_yukicoder/2606.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/263.test.cpp
    title: test/3_yukicoder/263.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/465.test.cpp
    title: test/3_yukicoder/465.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    \ = res[1] = 0;\n    return res;\n  }\n};\n"
  code: "template <int sigma>\nstruct Palindromic_Tree {\n  struct Node {\n    array<int,\
    \ sigma> TO;\n    int link;\n    int length;\n    int diff;            // link\
    \ \u3068\u306E\u5DEE\u5206\n    int slink;           // series link, diff \u3067\
    \u306A\u308B\u3079\u304F\u305F\u3069\u3063\u305F\u5148\n    pair<int, int> pos;\
    \  // one occurrence [l, r)\n\n    Node(int link = -1, int length = 0, int l =\
    \ 0, int r = 0)\n        : link(link), length(length), diff(0), slink(0), pos({l,\
    \ r}) {\n      fill(all(TO), -1);\n    }\n  };\n\n  vc<Node> nodes;\n  // |path|=|S|+1\n\
    \  // path[i]: longest palindromic suffix of S[0, i)\n  vc<int> path;\n\n  Palindromic_Tree()\
    \ {}\n\n  template <typename STRING>\n  Palindromic_Tree(const STRING& S, char\
    \ off) {\n    build(S, off);\n  }\n\n  int size() const { return len(nodes); }\n\
    \n  template <typename STRING>\n  void build(const STRING& S, char off) {\n  \
    \  nodes.clear();\n    path.clear();\n\n    // 0: imaginary root (length = -1)\n\
    \    // 1: empty root (length = 0)\n    nodes.eb(Node(-1, -1, 0, -1));\n    nodes.eb(Node(0,\
    \ 0, 0, 0));\n    nodes[0].diff = nodes[1].diff = 0;\n    nodes[0].slink = nodes[1].slink\
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
    \ = res[1] = 0;\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromic_tree.hpp
  requiredBy:
  - string/palindrome_decomposition_dp.hpp
  timestamp: '2026-03-14 08:28:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/string/eertree.test.cpp
  - test/3_yukicoder/2606.test.cpp
  - test/3_yukicoder/465.test.cpp
  - test/3_yukicoder/263.test.cpp
  - test/1_mytest/palindrome_decomposition_dp.test.cpp
documentation_of: string/palindromic_tree.hpp
layout: document
redirect_from:
- /library/string/palindromic_tree.hpp
- /library/string/palindromic_tree.hpp.html
title: string/palindromic_tree.hpp
---
