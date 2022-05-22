---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269_aho.test.cpp
    title: test/yukicoder/1269_aho.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/trie.hpp\"\ntemplate <int sigma>\r\nstruct Trie {\r\
    \n  int n_node;\r\n  vector<array<int, sigma>> TO;\r\n  vector<int> PAR;\r\n \
    \ vector<ll> node_value;\r\n  vector<int> BFS;\r\n  vector<int> FAIL;\r\n\r\n\
    \  Trie() : n_node(1), TO({array<int, sigma>()}), PAR({-1}), node_value({0}) {\r\
    \n    FOR(s, sigma) TO[0][s] = -1;\r\n  }\r\n\r\n  int add(string S, ll val =\
    \ 1, int off = 'a') {\r\n    int v = 0;\r\n    for (auto&& ss: S) {\r\n      int\
    \ s = ss - off;\r\n      if (TO[v][s] == -1) {\r\n        TO[v][s] = create_node();\r\
    \n        PAR[TO[v][s]] = v;\r\n      }\r\n      v = TO[v][s];\r\n    }\r\n  \
    \  node_value[v] += val;\r\n    return v;\r\n  }\r\n\r\n  int add(vector<int>\
    \ S, ll val = 1) {\r\n    int v = 0;\r\n    for (auto&& s: S) {\r\n      if (TO[v][s]\
    \ == -1) {\r\n        TO[v][s] = create_node();\r\n        PAR[TO[v][s]] = v;\r\
    \n      }\r\n      v = TO[v][s];\r\n    }\r\n    node_value[v] += val;\r\n   \
    \ return v;\r\n  }\r\n\r\n  void make_failure() {\r\n    FAIL.assign(n_node, 0);\r\
    \n    BFS.reserve(n_node);\r\n    deque<int> que;\r\n    que.emplace_back(0);\r\
    \n    BFS.emplace_back(0);\r\n    while (!que.empty()) {\r\n      int v = que.front();\r\
    \n      que.pop_front();\r\n      node_value[v] += node_value[FAIL[v]];\r\n  \
    \    for (int s = 0; s < sigma; ++s) {\r\n        if (TO[v][s] == -1) continue;\r\
    \n        int w = TO[v][s];\r\n        que.emplace_back(w);\r\n        BFS.emplace_back(w);\r\
    \n        if (v == 0) continue;\r\n        int f = FAIL[v];\r\n        while (f\
    \ && TO[f][s] == -1) f = FAIL[f];\r\n        if (TO[f][s] == -1)\r\n         \
    \ FAIL[w] = 0;\r\n        else\r\n          FAIL[w] = TO[f][s];\r\n      }\r\n\
    \    }\r\n    for (auto&& v: BFS) {\r\n      FOR(s, sigma) if (TO[v][s] == -1)\
    \ {\r\n        int f = FAIL[v];\r\n        TO[v][s] = TO[f][s];\r\n        if\
    \ (TO[v][s] == -1) TO[v][s] = 0;\r\n      }\r\n    }\r\n  }\r\n\r\nprivate:\r\n\
    \  int create_node() {\r\n    TO.eb(array<int, sigma>());\r\n    FOR(s, sigma)\
    \ TO.back()[s] = -1;\r\n    PAR.eb(-1);\r\n    node_value.eb(0);\r\n    return\
    \ n_node++;\r\n  }\r\n};\r\n"
  code: "template <int sigma>\r\nstruct Trie {\r\n  int n_node;\r\n  vector<array<int,\
    \ sigma>> TO;\r\n  vector<int> PAR;\r\n  vector<ll> node_value;\r\n  vector<int>\
    \ BFS;\r\n  vector<int> FAIL;\r\n\r\n  Trie() : n_node(1), TO({array<int, sigma>()}),\
    \ PAR({-1}), node_value({0}) {\r\n    FOR(s, sigma) TO[0][s] = -1;\r\n  }\r\n\r\
    \n  int add(string S, ll val = 1, int off = 'a') {\r\n    int v = 0;\r\n    for\
    \ (auto&& ss: S) {\r\n      int s = ss - off;\r\n      if (TO[v][s] == -1) {\r\
    \n        TO[v][s] = create_node();\r\n        PAR[TO[v][s]] = v;\r\n      }\r\
    \n      v = TO[v][s];\r\n    }\r\n    node_value[v] += val;\r\n    return v;\r\
    \n  }\r\n\r\n  int add(vector<int> S, ll val = 1) {\r\n    int v = 0;\r\n    for\
    \ (auto&& s: S) {\r\n      if (TO[v][s] == -1) {\r\n        TO[v][s] = create_node();\r\
    \n        PAR[TO[v][s]] = v;\r\n      }\r\n      v = TO[v][s];\r\n    }\r\n  \
    \  node_value[v] += val;\r\n    return v;\r\n  }\r\n\r\n  void make_failure()\
    \ {\r\n    FAIL.assign(n_node, 0);\r\n    BFS.reserve(n_node);\r\n    deque<int>\
    \ que;\r\n    que.emplace_back(0);\r\n    BFS.emplace_back(0);\r\n    while (!que.empty())\
    \ {\r\n      int v = que.front();\r\n      que.pop_front();\r\n      node_value[v]\
    \ += node_value[FAIL[v]];\r\n      for (int s = 0; s < sigma; ++s) {\r\n     \
    \   if (TO[v][s] == -1) continue;\r\n        int w = TO[v][s];\r\n        que.emplace_back(w);\r\
    \n        BFS.emplace_back(w);\r\n        if (v == 0) continue;\r\n        int\
    \ f = FAIL[v];\r\n        while (f && TO[f][s] == -1) f = FAIL[f];\r\n       \
    \ if (TO[f][s] == -1)\r\n          FAIL[w] = 0;\r\n        else\r\n          FAIL[w]\
    \ = TO[f][s];\r\n      }\r\n    }\r\n    for (auto&& v: BFS) {\r\n      FOR(s,\
    \ sigma) if (TO[v][s] == -1) {\r\n        int f = FAIL[v];\r\n        TO[v][s]\
    \ = TO[f][s];\r\n        if (TO[v][s] == -1) TO[v][s] = 0;\r\n      }\r\n    }\r\
    \n  }\r\n\r\nprivate:\r\n  int create_node() {\r\n    TO.eb(array<int, sigma>());\r\
    \n    FOR(s, sigma) TO.back()[s] = -1;\r\n    PAR.eb(-1);\r\n    node_value.eb(0);\r\
    \n    return n_node++;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2022-05-22 15:35:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1269_aho.test.cpp
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
