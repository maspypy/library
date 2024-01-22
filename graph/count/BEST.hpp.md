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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linalg/spmat_det.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n#include\
    \ \"linalg/spmat_det.hpp\"\n\n/*\n\u3072\u3068\u3064\u9078\u3093\u3060\u8FBA\u304B\
    \u3089\u59CB\u3081\u3066\u5168\u3066\u306E\u70B9\u30FB\u8FBA\u3092\u901A\u308B\
    \ closed walk \u3092\u6570\u3048\u308B.\n\u591A\u91CD\u8FBA\u306F vc<int>(eid)\
    \ \u3067\u6E21\u3059\uFF0C\u306A\u3051\u308C\u3070\u3059\u3079\u3066 1. e.cost\
    \ \u306F\u53C2\u7167\u3057\u306A\u3044.\n\u8FBA\u306F\u30E9\u30D9\u30EB\u4ED8\u304D\
    \u3067\u8003\u3048\u308B. \u591A\u91CD\u8FBA\u3092\u540C\u4E00\u8996\u3059\u308B\
    \u5834\u5408\u306A\u3069\u306F\u5F8C\u3067\u968E\u4E57\u3067\u5272\u308B\u3053\
    \u3068.\nO(N^2+NM) \uFF08 + \u6700\u5F8C\u306B\u91CD\u8907\u5EA6\u306E\u968E\u4E57\
    \u3092\u304B\u3051\u308B\uFF09\uFF0E\n*/\ntemplate <typename mint, typename GT>\n\
    mint BEST_theorem(GT& G, vc<int> edge_multiplicity = {}) {\n  static_assert(GT::is_directed);\n\
    \  int N = G.N, M = G.M;\n  if (M == 0) return 0;\n  if (edge_multiplicity.empty())\
    \ edge_multiplicity.assign(M, 1);\n\n  // \u3084\u3089\u306A\u304F\u3066\u3082\
    \ 0 \u306B\u306A\u308B\u306F\u305A\u3060\u304C\u4E00\u5FDC\n  UnionFind uf(N);\n\
    \  vc<int> indeg(N), outdeg(N);\n  FOR(i, M) {\n    int a = G.edges[i].frm, b\
    \ = G.edges[i].to, x = edge_multiplicity[i];\n    if (!x) continue;\n    outdeg[a]\
    \ += x, indeg[b] += x;\n    uf.merge(a, b);\n  }\n  if (uf.n_comp != 1) return\
    \ 0;\n  FOR(v, N) if (indeg[v] != outdeg[v]) return 0;\n\n  vc<tuple<int, int,\
    \ mint>> mat;\n  FOR(i, M) {\n    int a = G.edges[i].frm, b = G.edges[i].to, x\
    \ = edge_multiplicity[i];\n    if (a < N - 1 && b < N - 1) mat.eb(a, b, -x);\n\
    \    if (a < N - 1) mat.eb(a, a, x);\n  }\n  mint d = spmat_det(N - 1, mat);\n\
    \  for (auto& x: outdeg) { d *= fact<mint>(x - 1); }\n  return d;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/BEST.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/BEST.hpp
layout: document
redirect_from:
- /library/graph/count/BEST.hpp
- /library/graph/count/BEST.hpp.html
title: graph/count/BEST.hpp
---
