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
    - https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/disjointsparse.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"string/suffixarray.hpp\"\n#include \"alg/monoid/min_idx.hpp\"\
    \n#include \"ds/segtree.hpp\"\n#include \"graph/base.hpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\npair<Graph<int, 1>, vc<tuple<int, int, int,\
    \ int>>> suffix_tree(SuffixArray& X) {\n  auto SA = X.SA;\n  auto ISA = X.ISA;\n\
    \  auto LCP = X.LCP;\n\n  int N = len(SA);\n\n  using Mono = Monoid_Min_Idx<int,\
    \ 1>;\n\n  SegTree<Mono> seg(N - 1, [&](int i) -> Mono::X { return {LCP[i], i};\
    \ });\n\n  using T = tuple<int, int, int, int>;\n  vc<T> dat;\n  Graph<int, 1>\
    \ G;\n  dat.eb(0, 0, N, 0);\n\n  auto dfs = [&](auto& dfs, int p, int l, int r,\
    \ int h) -> void {\n    if (r == l + 1) {\n      int i = SA[l];\n      int sz\
    \ = N - i;\n      if (h == sz) return;\n      int k = len(dat);\n      dat.eb(l,\
    \ h, l + 1, sz);\n      G.resize(k + 1);\n      G.add(p, k);\n      return;\n\
    \    }\n    auto [lcp, i] = seg.prod(l, r - 1);\n    if (lcp == h) {\n      dfs(dfs,\
    \ p, l, i + 1, h);\n      dfs(dfs, p, i + 1, r, h);\n      return;\n    }\n  \
    \  int k = len(dat);\n    dat.eb(l, h, r, lcp);\n    G.resize(k + 1);\n    G.add(p,\
    \ k);\n    dfs(dfs, k, l, r, lcp);\n  };\n  dfs(dfs, 0, 0, N, 0);\n  G.build();\n\
    \  return {G, dat};\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_tree.hpp
layout: document
redirect_from:
- /library/string/suffix_tree.hpp
- /library/string/suffix_tree.hpp.html
title: string/suffix_tree.hpp
---
