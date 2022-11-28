---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"string/trie.hpp\"\
    \n\r\n// \u7D42\u7AEF\u30CE\u30FC\u30C9\u306B value \u3092\u5165\u308C\u308B\u3002\
    \r\n// failure link \u3092\u4F5C\u308B\u3068\u3001\u305D\u3053\u304C\u7D42\u7AEF\
    \u3067\u3042\u308B\u3088\u3046\u306A\u6587\u5B57\u5217\u306E value \u3092\r\n\
    // Monoid \u3067\u96C6\u7D04\u3057\u305F value \u304C\u5165\u308B\u3002\r\ntemplate\
    \ <int sigma, typename Monoid = Monoid_Add<int>>\r\nstruct Trie {\r\n  using X\
    \ = typename Monoid::value_type;\r\n  int n_node;\r\n  vector<array<int, sigma>>\
    \ TO;\r\n  vector<int> PAR;\r\n  vector<X> node_value;\r\n  vector<int> BFS;\r\
    \n  vector<int> FAIL;\r\n\r\n  Trie()\r\n      : n_node(1),\r\n        TO({array<int,\
    \ sigma>()}),\r\n        PAR({-1}),\r\n        node_value({Monoid::unit()}) {\r\
    \n    FOR(s, sigma) TO[0][s] = -1;\r\n  }\r\n\r\n  template <typename STRING>\r\
    \n  int add(STRING S, int off, X val) {\r\n    int v = 0;\r\n    for (auto&& ss:\
    \ S) {\r\n      int s = ss - off;\r\n      assert(0 <= s && s < sigma);\r\n  \
    \    if (TO[v][s] == -1) {\r\n        TO[v][s] = create_node();\r\n        PAR[TO[v][s]]\
    \ = v;\r\n      }\r\n      v = TO[v][s];\r\n    }\r\n    node_value[v] = Monoid::op(node_value[v],\
    \ val);\r\n    return v;\r\n  }\r\n\r\n  void make_failure() {\r\n    FAIL.assign(n_node,\
    \ 0);\r\n    BFS.reserve(n_node);\r\n    deque<int> que;\r\n    que.emplace_back(0);\r\
    \n    BFS.emplace_back(0);\r\n    while (!que.empty()) {\r\n      int v = que.front();\r\
    \n      que.pop_front();\r\n      node_value[v] = Monoid::op(node_value[v], node_value[FAIL[v]]);\r\
    \n      for (int s = 0; s < sigma; ++s) {\r\n        if (TO[v][s] == -1) continue;\r\
    \n        int w = TO[v][s];\r\n        que.emplace_back(w);\r\n        BFS.emplace_back(w);\r\
    \n        if (v == 0) continue;\r\n        int f = FAIL[v];\r\n        while (f\
    \ && TO[f][s] == -1) f = FAIL[f];\r\n        if (TO[f][s] == -1)\r\n         \
    \ FAIL[w] = 0;\r\n        else\r\n          FAIL[w] = TO[f][s];\r\n      }\r\n\
    \    }\r\n    for (auto&& v: BFS) {\r\n      FOR(s, sigma) if (TO[v][s] == -1)\
    \ {\r\n        int f = FAIL[v];\r\n        TO[v][s] = TO[f][s];\r\n        if\
    \ (TO[v][s] == -1) TO[v][s] = 0;\r\n      }\r\n    }\r\n  }\r\n\r\nprivate:\r\n\
    \  int create_node() {\r\n    TO.eb(array<int, sigma>());\r\n    FOR(s, sigma)\
    \ TO.back()[s] = -1;\r\n    PAR.eb(-1);\r\n    node_value.eb(Monoid::unit());\r\
    \n    return n_node++;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\n// \u7D42\u7AEF\u30CE\u30FC\u30C9\u306B\
    \ value \u3092\u5165\u308C\u308B\u3002\r\n// failure link \u3092\u4F5C\u308B\u3068\
    \u3001\u305D\u3053\u304C\u7D42\u7AEF\u3067\u3042\u308B\u3088\u3046\u306A\u6587\
    \u5B57\u5217\u306E value \u3092\r\n// Monoid \u3067\u96C6\u7D04\u3057\u305F value\
    \ \u304C\u5165\u308B\u3002\r\ntemplate <int sigma, typename Monoid = Monoid_Add<int>>\r\
    \nstruct Trie {\r\n  using X = typename Monoid::value_type;\r\n  int n_node;\r\
    \n  vector<array<int, sigma>> TO;\r\n  vector<int> PAR;\r\n  vector<X> node_value;\r\
    \n  vector<int> BFS;\r\n  vector<int> FAIL;\r\n\r\n  Trie()\r\n      : n_node(1),\r\
    \n        TO({array<int, sigma>()}),\r\n        PAR({-1}),\r\n        node_value({Monoid::unit()})\
    \ {\r\n    FOR(s, sigma) TO[0][s] = -1;\r\n  }\r\n\r\n  template <typename STRING>\r\
    \n  int add(STRING S, int off, X val) {\r\n    int v = 0;\r\n    for (auto&& ss:\
    \ S) {\r\n      int s = ss - off;\r\n      assert(0 <= s && s < sigma);\r\n  \
    \    if (TO[v][s] == -1) {\r\n        TO[v][s] = create_node();\r\n        PAR[TO[v][s]]\
    \ = v;\r\n      }\r\n      v = TO[v][s];\r\n    }\r\n    node_value[v] = Monoid::op(node_value[v],\
    \ val);\r\n    return v;\r\n  }\r\n\r\n  void make_failure() {\r\n    FAIL.assign(n_node,\
    \ 0);\r\n    BFS.reserve(n_node);\r\n    deque<int> que;\r\n    que.emplace_back(0);\r\
    \n    BFS.emplace_back(0);\r\n    while (!que.empty()) {\r\n      int v = que.front();\r\
    \n      que.pop_front();\r\n      node_value[v] = Monoid::op(node_value[v], node_value[FAIL[v]]);\r\
    \n      for (int s = 0; s < sigma; ++s) {\r\n        if (TO[v][s] == -1) continue;\r\
    \n        int w = TO[v][s];\r\n        que.emplace_back(w);\r\n        BFS.emplace_back(w);\r\
    \n        if (v == 0) continue;\r\n        int f = FAIL[v];\r\n        while (f\
    \ && TO[f][s] == -1) f = FAIL[f];\r\n        if (TO[f][s] == -1)\r\n         \
    \ FAIL[w] = 0;\r\n        else\r\n          FAIL[w] = TO[f][s];\r\n      }\r\n\
    \    }\r\n    for (auto&& v: BFS) {\r\n      FOR(s, sigma) if (TO[v][s] == -1)\
    \ {\r\n        int f = FAIL[v];\r\n        TO[v][s] = TO[f][s];\r\n        if\
    \ (TO[v][s] == -1) TO[v][s] = 0;\r\n      }\r\n    }\r\n  }\r\n\r\nprivate:\r\n\
    \  int create_node() {\r\n    TO.eb(array<int, sigma>());\r\n    FOR(s, sigma)\
    \ TO.back()[s] = -1;\r\n    PAR.eb(-1);\r\n    node_value.eb(Monoid::unit());\r\
    \n    return n_node++;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1269.test.cpp
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
