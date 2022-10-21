---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/263.test.cpp
    title: test/yukicoder/263.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/palindromic_tree.hpp\"\n// palindromic tree \u3092\
    \u4F5C\u308B\ntemplate <int sigma>\nstruct Palindromic_Tree {\n  struct Node {\n\
    \    array<int, sigma> TO;\n    int link;\n    int length;\n    pair<int, int>\
    \ pos; // position of first ocurrence\n    Node(int link, int length, int l, int\
    \ r)\n        : link(link), length(length), pos({l, r}) {\n      fill(all(TO),\
    \ -1);\n    }\n  };\n\n  vc<Node> nodes;\n  vc<int> path;\n\n  template <typename\
    \ STRING>\n  Palindromic_Tree(const STRING& S, char off) {\n    nodes.eb(Node(-1,\
    \ -1, 0, -1));\n    nodes.eb(Node(0, 0, 0, 0));\n    path = {0};\n    int p =\
    \ 0;\n    FOR(i, len(S)) {\n      path.eb(p);\n      int x = S[i] - off;\n   \
    \   while (p) {\n        int j = i - 1 - nodes[p].length;\n        bool can =\
    \ (j >= 0 && S[j] - off == x);\n        if (!can) {\n          p = nodes[p].link;\n\
    \          continue;\n        }\n        break;\n      }\n      if (nodes[p].TO[x]\
    \ != -1) {\n        p = nodes[p].TO[x];\n        continue;\n      }\n      int\
    \ to = len(nodes);\n      int l = i - 1 - nodes[p].length;\n      int r = i +\
    \ 1;\n      nodes[p].TO[x] = to;\n\n      int link;\n      if (p == 0) link =\
    \ 1;\n      if (p != 0) {\n        while (1) {\n          p = nodes[p].link;\n\
    \          int j = i - 1 - nodes[p].length;\n          bool can = (j >= 0 && S[j]\
    \ - off == x) || (p == 0);\n          if (can) break;\n        }\n        assert(nodes[p].TO[x]\
    \ != -1);\n        link = nodes[p].TO[x];\n      }\n      nodes.eb(Node(link,\
    \ r - l, l, r));\n      p = to;\n    }\n    path.eb(p);\n  }\n\n  vc<int> count()\
    \ {\n    vc<int> res(len(nodes));\n    for (auto&& p: path) res[p]++;\n    FOR_R(k,\
    \ 1, len(nodes)) {\n      int link = nodes[k].link;\n      res[link] += res[k];\n\
    \    }\n    return res;\n  }\n};\n"
  code: "// palindromic tree \u3092\u4F5C\u308B\ntemplate <int sigma>\nstruct Palindromic_Tree\
    \ {\n  struct Node {\n    array<int, sigma> TO;\n    int link;\n    int length;\n\
    \    pair<int, int> pos; // position of first ocurrence\n    Node(int link, int\
    \ length, int l, int r)\n        : link(link), length(length), pos({l, r}) {\n\
    \      fill(all(TO), -1);\n    }\n  };\n\n  vc<Node> nodes;\n  vc<int> path;\n\
    \n  template <typename STRING>\n  Palindromic_Tree(const STRING& S, char off)\
    \ {\n    nodes.eb(Node(-1, -1, 0, -1));\n    nodes.eb(Node(0, 0, 0, 0));\n   \
    \ path = {0};\n    int p = 0;\n    FOR(i, len(S)) {\n      path.eb(p);\n     \
    \ int x = S[i] - off;\n      while (p) {\n        int j = i - 1 - nodes[p].length;\n\
    \        bool can = (j >= 0 && S[j] - off == x);\n        if (!can) {\n      \
    \    p = nodes[p].link;\n          continue;\n        }\n        break;\n    \
    \  }\n      if (nodes[p].TO[x] != -1) {\n        p = nodes[p].TO[x];\n       \
    \ continue;\n      }\n      int to = len(nodes);\n      int l = i - 1 - nodes[p].length;\n\
    \      int r = i + 1;\n      nodes[p].TO[x] = to;\n\n      int link;\n      if\
    \ (p == 0) link = 1;\n      if (p != 0) {\n        while (1) {\n          p =\
    \ nodes[p].link;\n          int j = i - 1 - nodes[p].length;\n          bool can\
    \ = (j >= 0 && S[j] - off == x) || (p == 0);\n          if (can) break;\n    \
    \    }\n        assert(nodes[p].TO[x] != -1);\n        link = nodes[p].TO[x];\n\
    \      }\n      nodes.eb(Node(link, r - l, l, r));\n      p = to;\n    }\n   \
    \ path.eb(p);\n  }\n\n  vc<int> count() {\n    vc<int> res(len(nodes));\n    for\
    \ (auto&& p: path) res[p]++;\n    FOR_R(k, 1, len(nodes)) {\n      int link =\
    \ nodes[k].link;\n      res[link] += res[k];\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/palindromic_tree.hpp
  requiredBy: []
  timestamp: '2022-10-13 10:42:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/263.test.cpp
documentation_of: string/palindromic_tree.hpp
layout: document
redirect_from:
- /library/string/palindromic_tree.hpp
- /library/string/palindromic_tree.hpp.html
title: string/palindromic_tree.hpp
---
