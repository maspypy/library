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
    - https://codeforces.com/problemset/problem/1098/F
    - https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "\n#include \"string/suffix_array.hpp\"\n#include \"seq/cartesian_tree.hpp\"\
    \n#include \"graph/base.hpp\"\n#include \"ds/fastset.hpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\ntemplate <typename STRING, typename SUFFIX>\n\
    struct Suffix_Tree {\n  STRING& S;\n  SUFFIX& X;\n  Suffix_Tree(STRING& S, SUFFIX&\
    \ X) : S(S), X(X) {}\n\n  pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> build()\
    \ {\n    auto& SA = X.SA;\n    auto& LCP = X.LCP;\n\n    vc<tuple<int, int, int,\
    \ int>> dat;\n    vc<tuple<int, int, int>> edges;\n\n    int N = len(SA);\n  \
    \  if (N == 1) {\n      Graph<int, 1> G(2);\n      G.add(0, 1);\n      G.build();\n\
    \      dat.eb(0, 1, 0, 1), dat.eb(0, 1, 1, 2);\n      return {G, dat};\n    }\n\
    \n    dat.eb(0, N, -1, 0);\n    CartesianTree<int, true> CT(LCP);\n\n    auto\
    \ dfs = [&](auto& dfs, int p, int idx, int h) -> void {\n      int L = CT.range[idx].fi;\n\
    \      int R = CT.range[idx].se + 1;\n      int hh = LCP[idx];\n      if (h <\
    \ hh) {\n        edges.eb(p, len(dat), hh - h);\n        p = len(dat);\n     \
    \   dat.eb(L, R, h, hh);\n      }\n      if (CT.lch[idx] == -1) {\n        if\
    \ (hh < N - SA[idx]) {\n          edges.eb(p, len(dat), N - SA[idx] - hh);\n \
    \         dat.eb(idx, idx + 1, hh, N - SA[idx]);\n        }\n      } else {\n\
    \        dfs(dfs, p, CT.lch[idx], hh);\n      }\n      if (CT.rch[idx] == -1)\
    \ {\n        if (hh < N - SA[idx + 1]) {\n          edges.eb(p, len(dat), N -\
    \ SA[idx + 1] - hh);\n          dat.eb(idx + 1, idx + 2, hh, N - SA[idx + 1]);\n\
    \        }\n      } else {\n        dfs(dfs, p, CT.rch[idx], hh);\n      }\n \
    \   };\n    int r = CT.root;\n    if (LCP[r] > 0) {\n      edges.eb(0, 1, LCP[r]);\n\
    \      dat.eb(0, N, 0, LCP[r]);\n      dfs(dfs, 1, r, LCP[r]);\n    } else {\n\
    \      dfs(dfs, 0, r, 0);\n    }\n    for (auto& [a, b, c, d]: dat) ++c, ++d;\n\
    \n    Graph<int, 1> G(len(dat));\n    for (auto&& [a, b, c]: edges) G.add(a, b,\
    \ c);\n    G.build();\n    return {G, dat};\n  }\n\n  // S[i:N) \u306B\u5BFE\u5FDC\
    \u3059\u308B\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059\n  // https://codeforces.com/problemset/problem/1098/F\n\
    \  vc<int> get_suffix_positions(Graph<int, 1>& G, vc<tuple<int, int, int, int>>&\
    \ dat) {\n    int N = len(S);\n    FastSet FS(N);\n    FOR(i, N) FS.insert(i);\n\
    \    vc<int> ANS(N);\n    FOR_R(v, len(dat)) {\n      auto [a, b, c, d] = dat[v];\n\
    \      FS.enumerate(a, b, [&](int i) -> void {\n        FS.erase(i);\n       \
    \ ANS[X.SA[i]] = v;\n      });\n    }\n    return ANS;\n  }\n\n  // trie \u306E\
    \u8981\u9818\u3067\u3059\u3059\u3080\uFF08failure link \u306F\u306A\u3044\uFF09\
    \n  // (node, length)\n  // \u884C\u304D\u904E\u304E\uFF1A(-1,0)\n  pair<int,\
    \ int> next(Graph<int, 1>& G, vc<tuple<int, int, int, int>>& dat, pair<int, int>\
    \ p, int ch) {\n    auto [node, length] = p;\n    if (node == -1) return {-1,\
    \ 0};\n    auto [l, r, a, b] = dat[node];\n    if (length + 1 < b) {\n      int\
    \ i = X.SA[l];\n      // S[i:i+length]\n      if (ch != S[i + length]) return\
    \ {-1, 0};\n      return {node, length + 1};\n    }\n    for (auto& e: G[node])\
    \ {\n      int n = e.to;\n      auto [l, r, a, b] = dat[n];\n      assert(a ==\
    \ length + 1);\n      int i = X.SA[l];\n      // S[i:i+length]\n      if (ch ==\
    \ S[i + length]) return {n, length + 1};\n    }\n    return {-1, 0};\n  }\n};\n"
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
