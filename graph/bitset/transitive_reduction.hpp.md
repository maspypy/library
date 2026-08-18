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
    - https://codeforces.com/problemset/problem/1835/F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/bitset/transitive_closure.hpp\"\n\n// \u5165\u529B\u306F\
    \ DAG. reachability \u95A2\u4FC2\u3092\u4FDD\u3064\u6700\u5C0F\u8FBA\u96C6\u5408\
    \u3092\u6B8B\u3059.\n// N^3/w.\n// https://codeforces.com/problemset/problem/1835/F\n\
    vc<Bit_Array> transitive_reduction(vc<Bit_Array> G) {\n  using BS = Bit_Array;\n\
    \  int N = len(G);\n  vc<BS> H = transitive_closure(G);\n  FOR(v, N) H[v][v] =\
    \ 0;\n  vc<BS> HH(N, BS(N));\n  FOR(i, N) FOR(j, N) {\n    if (H[i][j]) {\n  \
    \    HH[i] |= H[j];\n    }\n  }\n\n  FOR_R(L, N) FOR(R, L + 1, N) {\n    if (HH[L][R])\
    \ G[L][R] = 0;\n  }\n  return G;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bitset/transitive_reduction.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bitset/transitive_reduction.hpp
layout: document
redirect_from:
- /library/graph/bitset/transitive_reduction.hpp
- /library/graph/bitset/transitive_reduction.hpp.html
title: graph/bitset/transitive_reduction.hpp
---
