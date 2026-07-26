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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#include \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 k \u756A\u76EE\
    \u306E suffix \u3068\u306E LCP. k=0,1,2,... \u3068\u3057\u305F\u3068\u304D\u306E\
    \u5909\u5316.\n// return: {init,change}\n// init[i] = lcp(0,i)\n// change[k]:\
    \ k->k+1, (l,r,x)\ntemplate <typename SUFFIX>\npair<vc<int>, vvc<tuple<int, int,\
    \ int>>> suffix_lcp_change(SUFFIX& X) {\n  auto& SA = X.SA;\n  auto& LCP = X.LCP;\n\
    \  int N = len(SA);\n  vc<int> init(N);\n  vvc<tuple<int, int, int>> left(N -\
    \ 1), right(N - 1);\n  {\n    vc<tuple<int, int, int>> st;\n    st.eb(0, 1, N\
    \ - SA[0]);\n    FOR(i, N - 1) {\n      while (len(st)) {\n        auto [l, r,\
    \ x] = st.back();\n        if (x <= LCP[i]) break;\n        POP(st);\n      }\n\
    \      int s = (st.empty() ? 0 : get<1>(st.back()));\n      st.eb(s, i + 1, LCP[i]);\n\
    \      if (s < i + 1) left[i].eb(s, i + 1, LCP[i]);\n      st.eb(i + 1, i + 2,\
    \ N - SA[i + 1]);\n    }\n  }\n  {\n    vc<tuple<int, int, int>> st;\n    st.eb(N\
    \ - 1, N, N - SA[N - 1]);\n    FOR_R(i, N - 1) {\n      while (len(st)) {\n  \
    \      auto [l, r, x] = st.back();\n        if (x <= LCP[i]) break;\n        right[i].eb(l,\
    \ r, x);\n        POP(st);\n      }\n      int t = (st.empty() ? N : get<0>(st.back()));\n\
    \      st.eb(i + 1, t, LCP[i]);\n      st.eb(i, i + 1, N - SA[i]);\n    }\n  \
    \  for (auto [l, r, x]: st) { FOR(i, l, r) init[i] = x; }\n  }\n  vvc<tuple<int,\
    \ int, int>> change(N - 1);\n  FOR(i, N - 1) {\n    vc<tuple<int, int, int>> S;\n\
    \    concat(S, left[i], right[i]);\n    for (auto [l, r, x]: S) {\n      if (!change[i].empty()\
    \ && get<2>(change[i].back()) == x) {\n        get<1>(change[i].back()) = r;\n\
    \      } else {\n        change[i].eb(l, r, x);\n      }\n    }\n  }\n  return\
    \ {init, change};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_lcp_change.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix_lcp_change.hpp
layout: document
redirect_from:
- /library/string/suffix_lcp_change.hpp
- /library/string/suffix_lcp_change.hpp.html
title: string/suffix_lcp_change.hpp
---
