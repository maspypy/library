---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/string/trie_map.hpp
  bundledCode: "#line 1 \"string/trie_map.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/trie_map.hpp\n\
    template <typename CHAR>\nstruct Trie {\n  using MP = map<CHAR, int>;\n  int n_node;\n\
    \  vector<MP> TO;\n  vector<int> PAR;\n  vector<int> BFS;\n  vector<int> FAIL;\n\
    \  vc<int> words;\n\n  Trie() : n_node(1), TO({MP()}), PAR({-1}) {}\n\n  template\
    \ <typename STRING>\n  int add(STRING S) {\n    int v = 0;\n    for (auto&& s:\
    \ S) {\n      if (!TO[v].count(s)) {\n        TO[v][s] = create_node();\n    \
    \    PAR[TO[v][s]] = v;\n      }\n      v = TO[v][s];\n    }\n    words.eb(v);\n\
    \    return v;\n  }\n\n  int create_node() {\n    TO.eb(MP());\n    PAR.eb(-1);\n\
    \    return n_node++;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/trie_map.hpp\n\
    template <typename CHAR>\nstruct Trie {\n  using MP = map<CHAR, int>;\n  int n_node;\n\
    \  vector<MP> TO;\n  vector<int> PAR;\n  vector<int> BFS;\n  vector<int> FAIL;\n\
    \  vc<int> words;\n\n  Trie() : n_node(1), TO({MP()}), PAR({-1}) {}\n\n  template\
    \ <typename STRING>\n  int add(STRING S) {\n    int v = 0;\n    for (auto&& s:\
    \ S) {\n      if (!TO[v].count(s)) {\n        TO[v][s] = create_node();\n    \
    \    PAR[TO[v][s]] = v;\n      }\n      v = TO[v][s];\n    }\n    words.eb(v);\n\
    \    return v;\n  }\n\n  int create_node() {\n    TO.eb(MP());\n    PAR.eb(-1);\n\
    \    return n_node++;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie_map.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie_map.hpp
layout: document
redirect_from:
- /library/string/trie_map.hpp
- /library/string/trie_map.hpp.html
title: string/trie_map.hpp
---
