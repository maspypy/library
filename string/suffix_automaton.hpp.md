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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/number_of_substrings2.test.cpp
    title: test/2_library_checker/string/number_of_substrings2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/string/suffix_automaton.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/suffix_automaton.hpp: line 2: #pragma once found in a non-first line\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/suffix_automaton.hpp\n\
    #pragma once\n\n#include \"graph/tree.hpp\"\n\n/*\nSAM \u306E\u30CE\u30FC\u30C9\
    \u306F\u90E8\u5206\u6587\u5B57\u5217\u3092 endpos \u96C6\u5408\u3067\u5206\u985E\
    \u3057\u3066\u3044\u308B\nreverse(S) \u306E suffix tree \u3068\u3044\u3046\u306E\
    \u3068\u3060\u3044\u305F\u3044\u540C\u3058\n(v,k): node[v] \u3067 length[k]\n\n\
    node \u756A\u53F7\u304C topological \u9806\u306B\u306A\u308B\u3088\u3046\u306B\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u4ED8\u3051\u76F4\u3057\u3066\u3044\
    \u308B\n*/\n\ntemplate <int sigma = 26>\nstruct Suffix_Automaton {\n  struct Node\
    \ {\n    array<int, sigma> nxt;\n    int link;\n    int max_len;\n\n    // endpos\
    \ information\n    int occ;\n    int min_pos;\n    int max_pos;\n\n    Node(int\
    \ link, int max_len)\n        : link(link),\n          max_len(max_len),\n   \
    \       occ(0),\n          min_pos(infty<int>),\n          max_pos(-infty<int>)\
    \ {\n      fill(all(nxt), -1);\n    }\n  };\n\n  using GT = Graph<int, 1>;\n \
    \ using TREE = Tree<GT>;\n\n  vc<Node> nodes;\n  int n_node;\n\n  Node& operator[](int\
    \ i) { return nodes[i]; }\n\n  // pos[i] := S[0:i) \u306B\u5BFE\u5FDC\u3059\u308B\
    \ node\n  vc<int> pos;\n\n  Suffix_Automaton() {}\n  template <typename STRING>\n\
    \  Suffix_Automaton(const STRING& S, int off) {\n    build(S, off);\n  }\n\n \
    \ template <typename STRING>\n  void build(const STRING& S, int off) {\n    int\
    \ N = len(S);\n\n    nodes.clear();\n    pos.clear();\n    nodes.reserve(2 * N);\n\
    \    pos.reserve(N + 1);\n\n    nodes.eb(-1, 0);\n    pos.eb(0);\n\n    int last\
    \ = 0;\n    for (auto&& x : S) {\n      int c = x - off;\n      assert(0 <= c\
    \ && c < sigma);\n      last = add_single(last, c);\n      pos.eb(last);\n   \
    \ }\n\n    FOR(i, N + 1) {\n      int v = pos[i];\n      ++nodes[v].occ;\n   \
    \   chmin(nodes[v].min_pos, i);\n      chmax(nodes[v].max_pos, i);\n    }\n\n\
    \    // max_len \u6607\u9806\n    int n = len(nodes);\n    vc<int> cnt(N + 1);\n\
    \    for (auto& x : nodes) ++cnt[x.max_len];\n    FOR(i, N) cnt[i + 1] += cnt[i];\n\
    \n    vc<int> ord(n);\n    FOR_R(v, n) {\n      int k = nodes[v].max_len;\n  \
    \    ord[--cnt[k]] = v;\n    }\n\n    FOR_R(i, 1, n) {\n      int v = ord[i];\n\
    \      int p = nodes[v].link;\n      nodes[p].occ += nodes[v].occ;\n      chmin(nodes[p].min_pos,\
    \ nodes[v].min_pos);\n      chmax(nodes[p].max_pos, nodes[v].max_pos);\n    }\n\
    \n    vc<int> new_idx(n);\n    FOR(i, n) new_idx[ord[i]] = i;\n\n    vc<Node>\
    \ new_nodes;\n    new_nodes.reserve(n);\n\n    FOR(i, n) {\n      int v = ord[i];\n\
    \      new_nodes.eb(move(nodes[v]));\n    }\n\n    FOR(v, n) {\n      auto& nd\
    \ = new_nodes[v];\n      if (nd.link != -1) nd.link = new_idx[nd.link];\n    \
    \  for (auto& to : nd.nxt) {\n        if (to != -1) to = new_idx[to];\n      }\n\
    \    }\n    for (auto& v : pos) v = new_idx[v];\n    nodes = move(new_nodes);\n\
    \n    n_node = n;\n    assert(nodes[0].link == -1);\n    FOR(v, 1, n) assert(nodes[v].link\
    \ < v);\n    FOR(v, n) {\n      for (auto to : nodes[v].nxt) {\n        if (to\
    \ != -1) assert(v < to);\n      }\n    }\n  }\n\n  // node v \u304C\u8868\u3059\
    \u6587\u5B57\u5217\u9577\u306E\u534A\u958B\u533A\u9593\n  pair<int, int> len_range(int\
    \ v) const {\n    assert(0 <= v && v < len(nodes));\n    if (v == 0) return {0,\
    \ 1};\n    return {nodes[nodes[v].link].max_len + 1, nodes[v].max_len + 1};\n\
    \  }\n\n  // suffix-link tree\n  pair<GT, TREE> build_tree() const {\n    int\
    \ n = len(nodes);\n    GT G(n);\n    FOR(v, 1, n) G.add(nodes[v].link, v);\n \
    \   G.build();\n    TREE tree(G, 0);\n    return {move(G), move(tree)};\n  }\n\
    \n  // S[L:R) \u3092\u8868\u3059 (node, length)\n  pair<int, int> find_node(const\
    \ TREE& tree, int L, int R) const {\n    int N = len(pos) - 1;\n    assert(0 <=\
    \ L && L <= R && R <= N);\n\n    if (L == R) return {0, 0};\n\n    int k = R -\
    \ L;\n    int v = pos[R];\n\n    v = tree.max_path(\n        [&](int u) -> bool\
    \ { return nodes[u].max_len >= k; }, v, 0);\n\n    assert(v != -1);\n    auto\
    \ [a, b] = len_range(v);\n    assert(a <= k && k < b);\n\n    return {v, k};\n\
    \  }\n\n  // 1 \u6587\u5B57\u8AAD\u307F S \u306E\u90E8\u5206\u6587\u5B57\u5217\
    \u3067\u3042\u308B\u6700\u9577 suffix \u306B\u9077\u79FB\n  pair<int, int> next(pair<int,\
    \ int> p, int c) const {\n    auto [v, k] = p;\n    assert(0 <= c && c < sigma);\n\
    \n    while (v != 0 && nodes[v].nxt[c] == -1) {\n      v = nodes[v].link;\n  \
    \    k = nodes[v].max_len;\n    }\n\n    int to = nodes[v].nxt[c];\n    if (to\
    \ == -1) return {0, 0};\n\n    return {to, k + 1};\n  }\n\n private:\n  int add_single(int\
    \ last, int c) {\n    int cur = len(nodes);\n    nodes.eb(-1, nodes[last].max_len\
    \ + 1);\n\n    int p = last;\n    while (p != -1 && nodes[p].nxt[c] == -1) {\n\
    \      nodes[p].nxt[c] = cur;\n      p = nodes[p].link;\n    }\n\n    if (p ==\
    \ -1) {\n      nodes[cur].link = 0;\n      return cur;\n    }\n\n    int q = nodes[p].nxt[c];\n\
    \n    if (nodes[p].max_len + 1 == nodes[q].max_len) {\n      nodes[cur].link =\
    \ q;\n      return cur;\n    }\n\n    int clone = len(nodes);\n    nodes.eb(nodes[q].link,\
    \ nodes[p].max_len + 1);\n    nodes[clone].nxt = nodes[q].nxt;\n\n    while (p\
    \ != -1 && nodes[p].nxt[c] == q) {\n      nodes[p].nxt[c] = clone;\n      p =\
    \ nodes[p].link;\n    }\n\n    nodes[q].link = clone;\n    nodes[cur].link = clone;\n\
    \n    return cur;\n  }\n};"
  dependsOn:
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: string/suffix_automaton.hpp
  requiredBy: []
  timestamp: '2026-10-30 00:34:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/string/number_of_substrings2.test.cpp
documentation_of: string/suffix_automaton.hpp
layout: document
redirect_from:
- /library/string/suffix_automaton.hpp
- /library/string/suffix_automaton.hpp.html
title: string/suffix_automaton.hpp
---
