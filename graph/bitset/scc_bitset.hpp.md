---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/blackbox/scc.hpp
    title: graph/blackbox/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/641/problem/F
  bundledCode: "#line 1 \"graph/blackbox/scc.hpp\"\n\n// G \u3068\u305D\u306E reverse\
    \ graph \u306B\u5BFE\u3057\u3066 dfs \u3092\u884C\u3046\n// topo\u9806\u306F\u6B63\
    \u3057\u3044\u304C, \u63A2\u7D22\u3067\u898B\u305F\u8FBA\u3092\u96C6\u3081\u3066\
    \u3082 scc_dag \u306F\u5F97\u3089\u308C\u306A\u3044\u306E\u3067\u6CE8\u610F\n\
    // set_used(int v, bool rev)\n// find_used(int v, bool rev)\n// find \u306F set\
    \ \u3088\u308A\u3042\u3068\u306B\u547C\u3070\u308C\u308B. rev=false\u30D5\u30A7\
    \u30FC\u30BA\u3068rev=true\u30D5\u30A7\u30FC\u30BA\u304C\u3042\u308B.\ntemplate\
    \ <typename F1, typename F2>\npair<int, vc<int>> blackbox_scc(int N, F1 set_used,\
    \ F2 find_unused) {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n    vc<bool> vis(N);\n\
    \    auto dfs = [&](auto& dfs, int v) -> void {\n      assert(v < N && !vis[v]);\n\
    \      vis[v] = 1, set_used(v, false);\n      while (1) {\n        int to = find_unused(v,\
    \ false);\n        assert(to < N);\n        if (to == -1) break;\n        dfs(dfs,\
    \ to);\n      }\n      ord[--nxt] = v;\n    };\n    FOR(v, N) if (!vis[v]) dfs(dfs,\
    \ v);\n  }\n  vc<int> comp(N);\n  int nc = 0;\n  vc<bool> vis(N);\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n    vis[v] = 1, comp[v] = nc, set_used(v,\
    \ true);\n    while (1) {\n      int to = find_unused(v, true);\n      assert(to\
    \ < N);\n      if (to == -1) break;\n      dfs(dfs, to);\n    }\n  };\n  for (auto&&\
    \ v : ord) {\n    if (!vis[v]) dfs(dfs, v), ++nc;\n  }\n  return {nc, comp};\n\
    }\n#line 2 \"graph/bitset/scc_bitset.hpp\"\n\n// \u5BC6\u30B0\u30E9\u30D5\u306E\
    scc\n// O(N^2/w)\n// https://codeforces.com/contest/641/problem/F\npair<int, vc<int>>\
    \ scc_bitset(vc<My_Bitset> G) {\n  using BS = My_Bitset;\n  const int N = len(G);\n\
    \  vc<BS> RG(N, BS(N));\n  FOR(i, N) FOR(j, N) RG[i][j] = 1 * G[j][i];\n\n  BS\
    \ b0(N, 1);\n  BS b1(N, 1);\n\n  auto set_used = [&](int v, bool rev) -> void\
    \ {\n    if (!rev) b0[v] = 0;\n    if (rev) b1[v] = 0;\n  };\n\n  auto find_unused\
    \ = [&](int v, bool rev) -> int {\n    if (!rev) {\n      BS &x = G[v];\n    \
    \  x &= b0.range(0, len(x));\n      int p = x.prev(len(x));\n      x.resize(p\
    \ + 1);\n      return p;\n    }\n    BS &x = RG[v];\n    x &= b1.range(0, len(x));\n\
    \    int p = x.prev(len(x));\n    x.resize(p + 1);\n    return p;\n  };\n  return\
    \ blackbox_scc(N, set_used, find_unused);\n}\n"
  code: "#include \"graph/blackbox/scc.hpp\"\n\n// \u5BC6\u30B0\u30E9\u30D5\u306E\
    scc\n// O(N^2/w)\n// https://codeforces.com/contest/641/problem/F\npair<int, vc<int>>\
    \ scc_bitset(vc<My_Bitset> G) {\n  using BS = My_Bitset;\n  const int N = len(G);\n\
    \  vc<BS> RG(N, BS(N));\n  FOR(i, N) FOR(j, N) RG[i][j] = 1 * G[j][i];\n\n  BS\
    \ b0(N, 1);\n  BS b1(N, 1);\n\n  auto set_used = [&](int v, bool rev) -> void\
    \ {\n    if (!rev) b0[v] = 0;\n    if (rev) b1[v] = 0;\n  };\n\n  auto find_unused\
    \ = [&](int v, bool rev) -> int {\n    if (!rev) {\n      BS &x = G[v];\n    \
    \  x &= b0.range(0, len(x));\n      int p = x.prev(len(x));\n      x.resize(p\
    \ + 1);\n      return p;\n    }\n    BS &x = RG[v];\n    x &= b1.range(0, len(x));\n\
    \    int p = x.prev(len(x));\n    x.resize(p + 1);\n    return p;\n  };\n  return\
    \ blackbox_scc(N, set_used, find_unused);\n}"
  dependsOn:
  - graph/blackbox/scc.hpp
  isVerificationFile: false
  path: graph/bitset/scc_bitset.hpp
  requiredBy: []
  timestamp: '2025-07-25 21:12:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bitset/scc_bitset.hpp
layout: document
redirect_from:
- /library/graph/bitset/scc_bitset.hpp
- /library/graph/bitset/scc_bitset.hpp.html
title: graph/bitset/scc_bitset.hpp
---
