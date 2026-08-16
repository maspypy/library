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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/zalgorithm.hpp:\
    \ line -1: no such header\n"
  code: "#include \"string/zalgorithm.hpp\"\r\n\r\n// (period, l, r)\r\n// \u6975\u5927\
    , \u3064\u307E\u308A S[l:r] \u306F\u5468\u671F p (\u305F\u3060\u3057 r-l >= 2p)\
    \ \u3092\u6301\u3064\u304C\u3001S[l-1:r], S[l:r+1]\r\n// \u306F\u305D\u3046\u3067\
    \u306F\u306A\u3044\r\n// \u9AD8\u3005 n \u500B\u4EE5\u4E0B\r\n// sum of (r-l)/p\
    \ = O(n)\r\ntemplate <typename STRING>\r\nvc<tuple<int, int, int>> run_enumerate(const\
    \ STRING& S) {\r\n  ll N = len(S);\r\n  using T = tuple<int, int, int>;\r\n  using\
    \ P = pair<int, int>;\r\n  vc<vc<P>> by_p(N + 1);\r\n\r\n  auto solve_sub = [&](STRING&\
    \ left, STRING& right) -> vc<T> {\r\n    vc<T> res;\r\n    int n = len(left),\
    \ m = len(right);\r\n    auto S = left, T = right;\r\n    reverse(all(S));\r\n\
    \    T.insert(T.end(), all(left));\r\n    T.insert(T.end(), all(right));\r\n \
    \   auto ZS = zalgorithm(S), ZT = zalgorithm(T);\r\n    FOR3(p, 1, n + 1) {\r\n\
    \      int a = (p == n ? p : min(ZS[p] + int(p), n));\r\n      int b = min(ZT[n\
    \ + m - p], m);\r\n      if (a + b < 2 * p) continue;\r\n      res.eb(p, a, b);\r\
    \n    }\r\n    return res;\r\n  };\r\n\r\n  vc<P> st = {{0, N}};\r\n  while (!st.empty())\
    \ {\r\n    auto [L, R] = st.back();\r\n    st.pop_back();\r\n    if (R - L <=\
    \ 1) continue;\r\n    int M = (L + R) / 2;\r\n    st.eb(L, M), st.eb(M, R);\r\n\
    \    STRING SL = {S.begin() + L, S.begin() + M};\r\n    STRING SR = {S.begin()\
    \ + M, S.begin() + R};\r\n    {\r\n      auto sub_res = solve_sub(SL, SR);\r\n\
    \      for (auto&& [p, a, b]: sub_res) by_p[p].eb(M - a, M + b);\r\n    }\r\n\
    \    {\r\n      reverse(all(SL)), reverse(all(SR));\r\n      auto sub_res = solve_sub(SR,\
    \ SL);\r\n      for (auto&& [p, a, b]: sub_res) by_p[p].eb(M - b, M + a);\r\n\
    \    }\r\n  }\r\n\r\n  vc<T> res;\r\n  set<P> done;\r\n  FOR(p, len(by_p)) {\r\
    \n    auto& LR = by_p[p];\r\n    sort(all(LR),\r\n         [](auto& x, auto& y)\
    \ { return P(x.fi, -x.se) < P(y.fi, -y.se); });\r\n    int r = -1;\r\n    for\
    \ (auto&& lr: LR) {\r\n      if (chmax(r, lr.se) && !done.count(lr)) {\r\n   \
    \     done.insert(lr);\r\n        res.eb(p, lr.fi, lr.se);\r\n      }\r\n    }\r\
    \n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/run_enumerate.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/run_enumerate.hpp
layout: document
redirect_from:
- /library/string/run_enumerate.hpp
- /library/string/run_enumerate.hpp.html
title: string/run_enumerate.hpp
---
