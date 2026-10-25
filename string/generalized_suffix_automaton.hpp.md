---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: string/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/string/generalized_suffix_automaton.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/generalized_suffix_automaton.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/generalized_suffix_automaton.hpp\n\
    #pragma once\n\n#include \"graph/tree.hpp\"\n#include \"string/trie.hpp\"\n\n\
    /*\n\u5165\u529B\uFF1A\u8907\u6570\u6587\u5B57\u5217 or trie\nO(|trie nodes|)\n\
    node \u756A\u53F7\u306F topological \u9806\u306B\u4ED8\u3051\u76F4\u3057\u3066\
    \u3044\u308B\n*/\n\ntemplate <int sigma = 26>\nstruct Generalized_Suffix_Automaton\
    \ {\n  struct Node {\n    array<int, sigma> nxt;\n    int link;\n    int max_len;\n\
    \n    Node(int link, int max_len) : link(link), max_len(max_len) {\n      fill(all(nxt),\
    \ -1);\n    }\n  };\n\n  using GT = Graph<int, 1>;\n  using TREE = Tree<GT>;\n\
    \n  vc<Node> nodes;\n  int n_node;\n\n  Node& operator[](int i) { return nodes[i];\
    \ }\n  const Node& operator[](int i) const { return nodes[i]; }\n\n  Generalized_Suffix_Automaton()\
    \ {}\n\n  template <typename STRING>\n  Generalized_Suffix_Automaton(const vc<STRING>&\
    \ SS, int off) {\n    build(SS, off);\n  }\n\n  // n \u9802\u70B9 trie \u304B\u3089\
    \u69CB\u7BC9. O(n sigma).\n  void build(const Trie<sigma>& TRIE) {\n    int N\
    \ = TRIE.n_node;\n\n    nodes.clear();\n    vc<int> trie_pos(N, -1);\n    nodes.reserve(2\
    \ * N);\n\n    nodes.eb(-1, 0);\n    trie_pos[0] = 0;\n\n    // trie \u3092 BFS\
    \ (depth \u6607\u9806) \u3067\u51E6\u7406\u3059\u308B.\n    vc<int> que(N);\n\
    \    int ql = 0, qr = 0;\n    que[qr++] = 0;\n    while (ql < qr) {\n      int\
    \ v = que[ql++];\n      int p = trie_pos[v];\n      FOR(c, sigma) {\n        int\
    \ w = TRIE.nodes[v].ch[c];\n        if (w == -1) continue;\n        trie_pos[w]\
    \ = add_single(p, c);\n        que[qr++] = w;\n      }\n    }\n\n    normalize();\n\
    \  }\n\n  // \u8907\u6570\u6587\u5B57\u5217\u304B\u3089 trie \u3092\u4F5C\u308A\
    \u3001\u305D\u308C\u3092 generalized SAM \u306B\u3059\u308B.\n  template <typename\
    \ STRING>\n  void build(const vc<STRING>& SS, int off) {\n    Trie<sigma> TRIE;\n\
    \    for (auto& S : SS) TRIE.add(S, off);\n    build(TRIE);\n  }\n\n  // node\
    \ v \u304C\u8868\u3059\u6587\u5B57\u5217\u9577\u306E\u534A\u958B\u533A\u9593\n\
    \  pair<int, int> len_range(int v) const {\n    assert(0 <= v && v < len(nodes));\n\
    \    if (v == 0) return {0, 1};\n    return {nodes[nodes[v].link].max_len + 1,\
    \ nodes[v].max_len + 1};\n  }\n\n  // suffix-link tree\n  pair<GT, TREE> build_tree()\
    \ const {\n    int n = len(nodes);\n    GT G(n);\n    FOR(v, 1, n) G.add(nodes[v].link,\
    \ v);\n    G.build();\n    TREE tree(G, 0);\n    return {move(G), move(tree)};\n\
    \  }\n\n  // 1 \u6587\u5B57\u8AAD\u307F\u3001\u5165\u529B\u6587\u5B57\u5217\u7FA4\
    \u306E\u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\u308B\u6700\u9577 suffix \u306B\
    \u9077\u79FB.\n  pair<int, int> next(pair<int, int> p, int c) const {\n    auto\
    \ [v, k] = p;\n    assert(0 <= c && c < sigma);\n\n    while (v != 0 && nodes[v].nxt[c]\
    \ == -1) {\n      v = nodes[v].link;\n      k = nodes[v].max_len;\n    }\n\n \
    \   int to = nodes[v].nxt[c];\n    if (to == -1) return {0, 0};\n    return {to,\
    \ k + 1};\n  }\n\n private:\n  // trie \u306E edge: SAM state p --c--> ? \u3092\
    \u8FFD\u52A0\u3059\u308B generalized extension.\n  // p \u306F trie depth \u9806\
    \u306B\u51E6\u7406\u3055\u308C\u308B.\n  int add_single(int p, int c) {\n    //\
    \ \u65E2\u306B\u9077\u79FB\u304C\u3042\u308B\u5834\u5408\u3001\u305D\u306E\u9077\
    \u79FB\u5148\u306E max_len \u304C\u3061\u3087\u3046\u3069\u306A\u3089\u518D\u5229\
    \u7528\u3059\u308B.\n    // \u9577\u3055\u304C\u98DB\u3093\u3067\u3044\u308B\u5834\
    \u5408\u306F split \u3059\u308B.\n    if (nodes[p].nxt[c] != -1) {\n      int\
    \ q = nodes[p].nxt[c];\n      if (nodes[p].max_len + 1 == nodes[q].max_len) return\
    \ q;\n\n      int clone = len(nodes);\n      nodes.eb(nodes[q].link, nodes[p].max_len\
    \ + 1);\n      nodes[clone].nxt = nodes[q].nxt;\n\n      int x = p;\n      while\
    \ (x != -1 && nodes[x].nxt[c] == q) {\n        nodes[x].nxt[c] = clone;\n    \
    \    x = nodes[x].link;\n      }\n      nodes[q].link = clone;\n      return clone;\n\
    \    }\n\n    int cur = len(nodes);\n    nodes.eb(-1, nodes[p].max_len + 1);\n\
    \n    int x = p;\n    while (x != -1 && nodes[x].nxt[c] == -1) {\n      nodes[x].nxt[c]\
    \ = cur;\n      x = nodes[x].link;\n    }\n\n    if (x == -1) {\n      nodes[cur].link\
    \ = 0;\n      return cur;\n    }\n\n    int q = nodes[x].nxt[c];\n    if (nodes[x].max_len\
    \ + 1 == nodes[q].max_len) {\n      nodes[cur].link = q;\n      return cur;\n\
    \    }\n\n    int clone = len(nodes);\n    nodes.eb(nodes[q].link, nodes[x].max_len\
    \ + 1);\n    nodes[clone].nxt = nodes[q].nxt;\n\n    while (x != -1 && nodes[x].nxt[c]\
    \ == q) {\n      nodes[x].nxt[c] = clone;\n      x = nodes[x].link;\n    }\n\n\
    \    nodes[q].link = clone;\n    nodes[cur].link = clone;\n    return cur;\n \
    \ }\n\n  // max_len \u6607\u9806\u306B reindex.\n  void normalize() {\n    int\
    \ n = len(nodes);\n    int max_len = 0;\n    for (auto& x : nodes) chmax(max_len,\
    \ x.max_len);\n\n    vc<int> cnt(max_len + 1);\n    for (auto& x : nodes) ++cnt[x.max_len];\n\
    \    FOR(i, max_len) cnt[i + 1] += cnt[i];\n\n    vc<int> ord(n);\n    FOR_R(v,\
    \ n) {\n      int k = nodes[v].max_len;\n      ord[--cnt[k]] = v;\n    }\n\n \
    \   vc<int> new_idx(n);\n    FOR(i, n) new_idx[ord[i]] = i;\n\n    vc<Node> new_nodes;\n\
    \    new_nodes.reserve(n);\n    FOR(i, n) new_nodes.eb(move(nodes[ord[i]]));\n\
    \n    FOR(v, n) {\n      auto& nd = new_nodes[v];\n      if (nd.link != -1) nd.link\
    \ = new_idx[nd.link];\n      for (auto& to : nd.nxt) {\n        if (to != -1)\
    \ to = new_idx[to];\n      }\n    }\n\n    nodes = move(new_nodes);\n    n_node\
    \ = n;\n\n    assert(nodes[0].link == -1);\n    FOR(v, 1, n) assert(nodes[v].link\
    \ < v);\n    FOR(v, n) {\n      for (auto to : nodes[v].nxt) {\n        if (to\
    \ != -1) assert(v < to);\n      }\n    }\n  }\n};\n"
  dependsOn:
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - string/trie.hpp
  isVerificationFile: false
  path: string/generalized_suffix_automaton.hpp
  requiredBy: []
  timestamp: '2026-10-25 14:31:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/generalized_suffix_automaton.hpp
layout: document
redirect_from:
- /library/string/generalized_suffix_automaton.hpp
- /library/string/generalized_suffix_automaton.hpp.html
title: string/generalized_suffix_automaton.hpp
---
