---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/enumerate_occurrences.hpp
    title: string/enumerate_occurrences.hpp
  - icon: ':warning:'
    path: string/generalized_suffix_automaton.hpp
    title: string/generalized_suffix_automaton.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1269.test.cpp
    title: test/3_yukicoder/1269.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d
    - https://github.com/maspypy/library/blob/main/string/trie.hpp
  bundledCode: "#line 1 \"string/trie.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/trie.hpp\n\
    \n// sigma \u304C\u5C0F\u3055\u3044\n// \u4E00\u822C\u306E n \u9802\u70B9\u306E\
    \u6728\u69CB\u9020\u3067 O(n) \u6642\u9593\u3067\u52D5\u304F\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d\n\
    template <int sigma>\nstruct Trie {\n  struct Node {\n    array<int, sigma> ch;\n\
    \    array<int, sigma> nxt; // suffix link -> add c\n    int parent;\n    int\
    \ suffix_link;\n  };\n  int n_node;\n  vc<Node> nodes;\n  vc<int> words;\n  vc<int>\
    \ BFS; // BFS \u9806\n\n  Trie() {\n    n_node = 0;\n    new_node();\n  }\n\n\
    \  Node& operator[](int i) { return nodes[i]; }\n\n  template <typename STRING>\n\
    \  int add(STRING S, int off) {\n    int v = 0;\n    for (auto&& s: S) { v = add_single(v,\
    \ s, off); }\n    words.eb(v);\n    return v;\n  }\n\n  int add_single(int v,\
    \ int c, int off) {\n    c -= off;\n    assert(0 <= c && c < sigma);\n    if (nodes[v].ch[c]\
    \ != -1) return nodes[v].ch[c];\n    nodes[v].ch[c] = new_node();\n    nodes.back().parent\
    \ = v;\n    return nodes[v].ch[c];\n  }\n\n  void calc_suffix_link() {\n    BFS.resize(n_node);\n\
    \    int p = 0, q = 0;\n    BFS[q++] = 0;\n    fill(all(nodes[0].nxt), 0);\n \
    \   while (p < q) {\n      int v = BFS[p++];\n      if (v) nodes[v].nxt = nodes[nodes[v].suffix_link].nxt;\n\
    \      FOR(s, sigma) {\n        int w = nodes[v].ch[s];\n        if (w == -1)\
    \ continue;\n        nodes[w].suffix_link = nodes[v].nxt[s];\n        nodes[v].nxt[s]\
    \ = w;\n        BFS[q++] = w;\n      }\n    }\n  }\n\n  vc<int> calc_count() {\n\
    \    vc<int> count(n_node);\n    for (auto&& x: words) count[x]++;\n    for (auto&&\
    \ v: BFS)\n      if (v) { count[v] += count[nodes[v].suffix_link]; }\n    return\
    \ count;\n  }\n\nprivate:\n  int new_node() {\n    Node c;\n    fill(all(c.ch),\
    \ -1);\n    fill(all(c.nxt), -1);\n    c.parent = -1;\n    c.suffix_link = -1;\n\
    \    nodes.eb(c);\n    return n_node++;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/trie.hpp\n\
    \n// sigma \u304C\u5C0F\u3055\u3044\n// \u4E00\u822C\u306E n \u9802\u70B9\u306E\
    \u6728\u69CB\u9020\u3067 O(n) \u6642\u9593\u3067\u52D5\u304F\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d\n\
    template <int sigma>\nstruct Trie {\n  struct Node {\n    array<int, sigma> ch;\n\
    \    array<int, sigma> nxt; // suffix link -> add c\n    int parent;\n    int\
    \ suffix_link;\n  };\n  int n_node;\n  vc<Node> nodes;\n  vc<int> words;\n  vc<int>\
    \ BFS; // BFS \u9806\n\n  Trie() {\n    n_node = 0;\n    new_node();\n  }\n\n\
    \  Node& operator[](int i) { return nodes[i]; }\n\n  template <typename STRING>\n\
    \  int add(STRING S, int off) {\n    int v = 0;\n    for (auto&& s: S) { v = add_single(v,\
    \ s, off); }\n    words.eb(v);\n    return v;\n  }\n\n  int add_single(int v,\
    \ int c, int off) {\n    c -= off;\n    assert(0 <= c && c < sigma);\n    if (nodes[v].ch[c]\
    \ != -1) return nodes[v].ch[c];\n    nodes[v].ch[c] = new_node();\n    nodes.back().parent\
    \ = v;\n    return nodes[v].ch[c];\n  }\n\n  void calc_suffix_link() {\n    BFS.resize(n_node);\n\
    \    int p = 0, q = 0;\n    BFS[q++] = 0;\n    fill(all(nodes[0].nxt), 0);\n \
    \   while (p < q) {\n      int v = BFS[p++];\n      if (v) nodes[v].nxt = nodes[nodes[v].suffix_link].nxt;\n\
    \      FOR(s, sigma) {\n        int w = nodes[v].ch[s];\n        if (w == -1)\
    \ continue;\n        nodes[w].suffix_link = nodes[v].nxt[s];\n        nodes[v].nxt[s]\
    \ = w;\n        BFS[q++] = w;\n      }\n    }\n  }\n\n  vc<int> calc_count() {\n\
    \    vc<int> count(n_node);\n    for (auto&& x: words) count[x]++;\n    for (auto&&\
    \ v: BFS)\n      if (v) { count[v] += count[nodes[v].suffix_link]; }\n    return\
    \ count;\n  }\n\nprivate:\n  int new_node() {\n    Node c;\n    fill(all(c.ch),\
    \ -1);\n    fill(all(c.nxt), -1);\n    c.parent = -1;\n    c.suffix_link = -1;\n\
    \    nodes.eb(c);\n    return n_node++;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/generalized_suffix_automaton.hpp
  - string/enumerate_occurrences.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1269.test.cpp
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
