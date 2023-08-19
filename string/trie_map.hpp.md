---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/trie_map.hpp\"\ntemplate <typename CHAR>\r\nstruct\
    \ Trie {\r\n  using MP = map<CHAR, int>;\r\n  int n_node;\r\n  vector<MP> TO;\r\
    \n  vector<int> PAR;\r\n  vector<int> BFS;\r\n  vector<int> FAIL;\r\n\r\n  Trie()\
    \ : n_node(1), TO({MP()}), PAR({-1}) {}\r\n\r\n  template <typename STRING>\r\n\
    \  int add(STRING S) {\r\n    int v = 0;\r\n    for (auto&& s: S) {\r\n      if\
    \ (!TO[v].count(s)) {\r\n        TO[v][s] = create_node();\r\n        PAR[TO[v][s]]\
    \ = v;\r\n      }\r\n      v = TO[v][s];\r\n    }\r\n    return v;\r\n  }\r\n\r\
    \n  int create_node() {\r\n    TO.eb(MP());\r\n    PAR.eb(-1);\r\n    return n_node++;\r\
    \n  }\r\n};\n"
  code: "template <typename CHAR>\r\nstruct Trie {\r\n  using MP = map<CHAR, int>;\r\
    \n  int n_node;\r\n  vector<MP> TO;\r\n  vector<int> PAR;\r\n  vector<int> BFS;\r\
    \n  vector<int> FAIL;\r\n\r\n  Trie() : n_node(1), TO({MP()}), PAR({-1}) {}\r\n\
    \r\n  template <typename STRING>\r\n  int add(STRING S) {\r\n    int v = 0;\r\n\
    \    for (auto&& s: S) {\r\n      if (!TO[v].count(s)) {\r\n        TO[v][s] =\
    \ create_node();\r\n        PAR[TO[v][s]] = v;\r\n      }\r\n      v = TO[v][s];\r\
    \n    }\r\n    return v;\r\n  }\r\n\r\n  int create_node() {\r\n    TO.eb(MP());\r\
    \n    PAR.eb(-1);\r\n    return n_node++;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie_map.hpp
  requiredBy: []
  timestamp: '2023-08-19 23:11:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie_map.hpp
layout: document
redirect_from:
- /library/string/trie_map.hpp
- /library/string/trie_map.hpp.html
title: string/trie_map.hpp
---
