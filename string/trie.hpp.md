---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1269.test.cpp
    title: test/3_yukicoder/1269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc268_ex.test.cpp
    title: test/5_atcoder/abc268_ex.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc362g.test.cpp
    title: test/5_atcoder/abc362g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d
  bundledCode: "#line 1 \"string/trie.hpp\"\n\r\n// sigma \u304C\u5C0F\u3055\u3044\
    \r\n// \u4E00\u822C\u306E n \u9802\u70B9\u306E\u6728\u69CB\u9020\u3067 O(n) \u6642\
    \u9593\u3067\u52D5\u304F\r\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d\r\
    \ntemplate <int sigma>\r\nstruct Trie {\r\n  struct Node {\r\n    array<int, sigma>\
    \ ch;\r\n    array<int, sigma> nxt; // suffix link -> add c\r\n    int parent;\r\
    \n    int suffix_link;\r\n  };\r\n  int n_node;\r\n  vc<Node> nodes;\r\n  vc<int>\
    \ words;\r\n  vc<int> BFS; // BFS \u9806\r\n\r\n  Trie() {\r\n    n_node = 0;\r\
    \n    new_node();\r\n  }\r\n\r\n  Node& operator[](int i) { return nodes[i]; }\r\
    \n\r\n  template <typename STRING>\r\n  int add(STRING S, int off) {\r\n    int\
    \ v = 0;\r\n    for (auto&& s: S) { v = add_single(v, s, off); }\r\n    words.eb(v);\r\
    \n    return v;\r\n  }\r\n\r\n  int add_single(int v, int c, int off) {\r\n  \
    \  c -= off;\r\n    assert(0 <= c && c < sigma);\r\n    if (nodes[v].ch[c] !=\
    \ -1) return nodes[v].ch[c];\r\n    nodes[v].ch[c] = new_node();\r\n    nodes.back().parent\
    \ = v;\r\n    return nodes[v].ch[c];\r\n  }\r\n\r\n  void calc_suffix_link() {\r\
    \n    BFS.resize(n_node);\r\n    int p = 0, q = 0;\r\n    BFS[q++] = 0;\r\n  \
    \  fill(all(nodes[0].nxt), 0);\r\n    while (p < q) {\r\n      int v = BFS[p++];\r\
    \n      if (v) nodes[v].nxt = nodes[nodes[v].suffix_link].nxt;\r\n      FOR(s,\
    \ sigma) {\r\n        int w = nodes[v].ch[s];\r\n        if (w == -1) continue;\r\
    \n        nodes[w].suffix_link = nodes[v].nxt[s];\r\n        nodes[v].nxt[s] =\
    \ w;\r\n        BFS[q++] = w;\r\n      }\r\n    }\r\n  }\r\n\r\n  vc<int> calc_count()\
    \ {\r\n    vc<int> count(n_node);\r\n    for (auto&& x: words) count[x]++;\r\n\
    \    for (auto&& v: BFS)\r\n      if (v) { count[v] += count[nodes[v].suffix_link];\
    \ }\r\n    return count;\r\n  }\r\n\r\nprivate:\r\n  int new_node() {\r\n    Node\
    \ c;\r\n    fill(all(c.ch), -1);\r\n    fill(all(c.nxt), -1);\r\n    c.parent\
    \ = -1;\r\n    c.suffix_link = -1;\r\n    nodes.eb(c);\r\n    return n_node++;\r\
    \n  }\r\n};\r\n"
  code: "\r\n// sigma \u304C\u5C0F\u3055\u3044\r\n// \u4E00\u822C\u306E n \u9802\u70B9\
    \u306E\u6728\u69CB\u9020\u3067 O(n) \u6642\u9593\u3067\u52D5\u304F\r\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d\r\
    \ntemplate <int sigma>\r\nstruct Trie {\r\n  struct Node {\r\n    array<int, sigma>\
    \ ch;\r\n    array<int, sigma> nxt; // suffix link -> add c\r\n    int parent;\r\
    \n    int suffix_link;\r\n  };\r\n  int n_node;\r\n  vc<Node> nodes;\r\n  vc<int>\
    \ words;\r\n  vc<int> BFS; // BFS \u9806\r\n\r\n  Trie() {\r\n    n_node = 0;\r\
    \n    new_node();\r\n  }\r\n\r\n  Node& operator[](int i) { return nodes[i]; }\r\
    \n\r\n  template <typename STRING>\r\n  int add(STRING S, int off) {\r\n    int\
    \ v = 0;\r\n    for (auto&& s: S) { v = add_single(v, s, off); }\r\n    words.eb(v);\r\
    \n    return v;\r\n  }\r\n\r\n  int add_single(int v, int c, int off) {\r\n  \
    \  c -= off;\r\n    assert(0 <= c && c < sigma);\r\n    if (nodes[v].ch[c] !=\
    \ -1) return nodes[v].ch[c];\r\n    nodes[v].ch[c] = new_node();\r\n    nodes.back().parent\
    \ = v;\r\n    return nodes[v].ch[c];\r\n  }\r\n\r\n  void calc_suffix_link() {\r\
    \n    BFS.resize(n_node);\r\n    int p = 0, q = 0;\r\n    BFS[q++] = 0;\r\n  \
    \  fill(all(nodes[0].nxt), 0);\r\n    while (p < q) {\r\n      int v = BFS[p++];\r\
    \n      if (v) nodes[v].nxt = nodes[nodes[v].suffix_link].nxt;\r\n      FOR(s,\
    \ sigma) {\r\n        int w = nodes[v].ch[s];\r\n        if (w == -1) continue;\r\
    \n        nodes[w].suffix_link = nodes[v].nxt[s];\r\n        nodes[v].nxt[s] =\
    \ w;\r\n        BFS[q++] = w;\r\n      }\r\n    }\r\n  }\r\n\r\n  vc<int> calc_count()\
    \ {\r\n    vc<int> count(n_node);\r\n    for (auto&& x: words) count[x]++;\r\n\
    \    for (auto&& v: BFS)\r\n      if (v) { count[v] += count[nodes[v].suffix_link];\
    \ }\r\n    return count;\r\n  }\r\n\r\nprivate:\r\n  int new_node() {\r\n    Node\
    \ c;\r\n    fill(all(c.ch), -1);\r\n    fill(all(c.nxt), -1);\r\n    c.parent\
    \ = -1;\r\n    c.suffix_link = -1;\r\n    nodes.eb(c);\r\n    return n_node++;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2024-09-19 11:54:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1269.test.cpp
  - test/5_atcoder/abc268_ex.test.cpp
  - test/5_atcoder/abc362g.test.cpp
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
