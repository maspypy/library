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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/my_bitset.hpp\"\n\n// \u5BC6\u30B0\u30E9\u30D5\u306E\u91CD\u307F\
    \u306A\u3057\u6700\u77ED\u8DEF\u554F\u984C\n// 01 \u884C\u5217\u3092 vc<bitset>\
    \ \u306E\u5F62\u3067\u6E21\u3059\n// O(N^2/w)\n// \u53C2\u8003\uFF1A(4000,4000)\
    \ \u3092 4000 \u56DE\u3067 2 \u79D2\u4EE5\u5185\uFF1F\ntemplate <typename BITSET>\n\
    vc<int> bfs_bitset(vc<BITSET>& G, int s) {\n  const int N = len(G);\n  assert(0\
    \ <= s && s < N);\n  vc<int> dist(N, infty<int>);\n  BITSET unused, que;\n  if\
    \ constexpr (is_same_v<BITSET, Bit_Array>) {\n    unused = BITSET(N, 1);\n   \
    \ que = BITSET(N, 0);\n  }\n  FOR(v, N) unused[v] = 1;\n  que[s] = 1;\n\n  int\
    \ d = 0;\n  while (1) {\n    int p = que._Find_first();\n    if (p >= N) break;\n\
    \    BITSET nxt;\n    if constexpr (is_same_v<BITSET, Bit_Array>) { nxt = BITSET(N);\
    \ }\n    while (p < N) {\n      dist[p] = d;\n      unused[p] = 0;\n      nxt\
    \ |= G[p];\n      p = que._Find_next(p);\n    }\n    que = nxt & unused;\n   \
    \ ++d;\n  }\n  return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bitset/bfs_bitset.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bitset/bfs_bitset.hpp
layout: document
redirect_from:
- /library/graph/bitset/bfs_bitset.hpp
- /library/graph/bitset/bfs_bitset.hpp.html
title: graph/bitset/bfs_bitset.hpp
---
