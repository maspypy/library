---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc268_ex.test.cpp
    title: test_atcoder/abc268_ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"string/trie.hpp\"\
    \n\r\ntemplate <int sigma>\r\nstruct Trie {\r\n  using ARR = array<int, sigma>;\r\
    \n  int n_node;\r\n  vc<ARR> TO;\r\n  vc<int> parent;\r\n  vc<int> suffix_link;\r\
    \n  vc<int> words;\r\n  vc<int> V; // BFS \u9806\r\n\r\n  Trie() {\r\n    n_node\
    \ = 0;\r\n    new_node();\r\n  }\r\n\r\n  template <typename STRING>\r\n  int\
    \ add(STRING S, int off) {\r\n    int v = 0;\r\n    for (auto&& ss: S) {\r\n \
    \     int s = ss - off;\r\n      assert(0 <= s && s < sigma);\r\n      if (TO[v][s]\
    \ == -1) {\r\n        TO[v][s] = new_node();\r\n        parent.back() = v;\r\n\
    \      }\r\n      v = TO[v][s];\r\n    }\r\n    words.eb(v);\r\n    return v;\r\
    \n  }\r\n\r\n  int add_char(int v, int c, int off) {\r\n    c -= off;\r\n    if\
    \ (TO[v][c] != -1) return TO[v][c];\r\n    TO[v][c] = new_node();\r\n    parent.back()\
    \ = v;\r\n    return TO[v][c];\r\n  }\r\n\r\n  void calc_suffix_link(bool upd_TO)\
    \ {\r\n    suffix_link.assign(n_node, -1);\r\n    V.resize(n_node);\r\n    int\
    \ p = 0, q = 0;\r\n    V[q++] = 0;\r\n    while (p < q) {\r\n      int v = V[p++];\r\
    \n      FOR(s, sigma) {\r\n        int w = TO[v][s];\r\n        if (w == -1) continue;\r\
    \n        V[q++] = w;\r\n        int f = suffix_link[v];\r\n        while (f !=\
    \ -1 && TO[f][s] == -1) f = suffix_link[f];\r\n        suffix_link[w] = (f ==\
    \ -1 ? 0 : TO[f][s]);\r\n      }\r\n    }\r\n    if (!upd_TO) return;\r\n    for\
    \ (auto&& v: V) {\r\n      FOR(s, sigma) if (TO[v][s] == -1) {\r\n        int\
    \ f = suffix_link[v];\r\n        TO[v][s] = (f == -1 ? 0 : TO[f][s]);\r\n    \
    \  }\r\n    }\r\n  }\r\n\r\n  vc<int> calc_count() {\r\n    assert(!suffix_link.empty());\r\
    \n    vc<int> count(n_node);\r\n    for (auto&& x: words) count[x]++;\r\n    for\
    \ (auto&& v: V)\r\n      if (v) { count[v] += count[suffix_link[v]]; }\r\n   \
    \ return count;\r\n  }\r\n\r\nprivate:\r\n  int new_node() {\r\n    parent.eb(-1);\r\
    \n    TO.eb(ARR{});\r\n    fill(all(TO.back()), -1);\r\n    return n_node++;\r\
    \n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\ntemplate <int sigma>\r\nstruct Trie\
    \ {\r\n  using ARR = array<int, sigma>;\r\n  int n_node;\r\n  vc<ARR> TO;\r\n\
    \  vc<int> parent;\r\n  vc<int> suffix_link;\r\n  vc<int> words;\r\n  vc<int>\
    \ V; // BFS \u9806\r\n\r\n  Trie() {\r\n    n_node = 0;\r\n    new_node();\r\n\
    \  }\r\n\r\n  template <typename STRING>\r\n  int add(STRING S, int off) {\r\n\
    \    int v = 0;\r\n    for (auto&& ss: S) {\r\n      int s = ss - off;\r\n   \
    \   assert(0 <= s && s < sigma);\r\n      if (TO[v][s] == -1) {\r\n        TO[v][s]\
    \ = new_node();\r\n        parent.back() = v;\r\n      }\r\n      v = TO[v][s];\r\
    \n    }\r\n    words.eb(v);\r\n    return v;\r\n  }\r\n\r\n  int add_char(int\
    \ v, int c, int off) {\r\n    c -= off;\r\n    if (TO[v][c] != -1) return TO[v][c];\r\
    \n    TO[v][c] = new_node();\r\n    parent.back() = v;\r\n    return TO[v][c];\r\
    \n  }\r\n\r\n  void calc_suffix_link(bool upd_TO) {\r\n    suffix_link.assign(n_node,\
    \ -1);\r\n    V.resize(n_node);\r\n    int p = 0, q = 0;\r\n    V[q++] = 0;\r\n\
    \    while (p < q) {\r\n      int v = V[p++];\r\n      FOR(s, sigma) {\r\n   \
    \     int w = TO[v][s];\r\n        if (w == -1) continue;\r\n        V[q++] =\
    \ w;\r\n        int f = suffix_link[v];\r\n        while (f != -1 && TO[f][s]\
    \ == -1) f = suffix_link[f];\r\n        suffix_link[w] = (f == -1 ? 0 : TO[f][s]);\r\
    \n      }\r\n    }\r\n    if (!upd_TO) return;\r\n    for (auto&& v: V) {\r\n\
    \      FOR(s, sigma) if (TO[v][s] == -1) {\r\n        int f = suffix_link[v];\r\
    \n        TO[v][s] = (f == -1 ? 0 : TO[f][s]);\r\n      }\r\n    }\r\n  }\r\n\r\
    \n  vc<int> calc_count() {\r\n    assert(!suffix_link.empty());\r\n    vc<int>\
    \ count(n_node);\r\n    for (auto&& x: words) count[x]++;\r\n    for (auto&& v:\
    \ V)\r\n      if (v) { count[v] += count[suffix_link[v]]; }\r\n    return count;\r\
    \n  }\r\n\r\nprivate:\r\n  int new_node() {\r\n    parent.eb(-1);\r\n    TO.eb(ARR{});\r\
    \n    fill(all(TO.back()), -1);\r\n    return n_node++;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2023-01-05 20:02:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc268_ex.test.cpp
  - test/yukicoder/1269.test.cpp
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
