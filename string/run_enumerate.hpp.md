---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/zalgorithm.hpp
    title: string/zalgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/string/run_enumerate.test.cpp
    title: test/2_library_checker/string/run_enumerate.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/run_enumerate_vec.test.cpp
    title: test/2_library_checker/string/run_enumerate_vec.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/zalgorithm.hpp\"\n\ntemplate <typename STRING> //\
    \ string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> zalgorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n#line 2 \"string/run_enumerate.hpp\"\n\r\n// (period,\
    \ l, r)\r\n// \u6975\u5927, \u3064\u307E\u308A S[l:r] \u306F\u5468\u671F p (\u305F\
    \u3060\u3057 r-l >= 2p) \u3092\u6301\u3064\u304C\u3001S[l-1:r], S[l:r+1]\r\n//\
    \ \u306F\u305D\u3046\u3067\u306F\u306A\u3044\r\n// \u9AD8\u3005 n \u500B\u4EE5\
    \u4E0B\r\n// sum of (r-l)/p = O(n)\r\ntemplate <typename STRING>\r\nvc<tuple<int,\
    \ int, int>> run_enumerate(const STRING& S) {\r\n  ll N = len(S);\r\n  using T\
    \ = tuple<int, int, int>;\r\n  using P = pair<int, int>;\r\n  vc<vc<P>> by_p(N\
    \ + 1);\r\n\r\n  auto solve_sub = [&](STRING& left, STRING& right) -> vc<T> {\r\
    \n    vc<T> res;\r\n    int n = len(left), m = len(right);\r\n    auto S = left,\
    \ T = right;\r\n    reverse(all(S));\r\n    T.insert(T.end(), all(left));\r\n\
    \    T.insert(T.end(), all(right));\r\n    auto ZS = zalgorithm(S), ZT = zalgorithm(T);\r\
    \n    FOR3(p, 1, n + 1) {\r\n      int a = (p == n ? p : min(ZS[p] + int(p), n));\r\
    \n      int b = min(ZT[n + m - p], m);\r\n      if (a + b < 2 * p) continue;\r\
    \n      res.eb(p, a, b);\r\n    }\r\n    return res;\r\n  };\r\n\r\n  vc<P> st\
    \ = {{0, N}};\r\n  while (!st.empty()) {\r\n    auto [L, R] = st.back();\r\n \
    \   st.pop_back();\r\n    if (R - L <= 1) continue;\r\n    int M = (L + R) / 2;\r\
    \n    st.eb(L, M), st.eb(M, R);\r\n    STRING SL = {S.begin() + L, S.begin() +\
    \ M};\r\n    STRING SR = {S.begin() + M, S.begin() + R};\r\n    {\r\n      auto\
    \ sub_res = solve_sub(SL, SR);\r\n      for (auto&& [p, a, b]: sub_res) by_p[p].eb(M\
    \ - a, M + b);\r\n    }\r\n    {\r\n      reverse(all(SL)), reverse(all(SR));\r\
    \n      auto sub_res = solve_sub(SR, SL);\r\n      for (auto&& [p, a, b]: sub_res)\
    \ by_p[p].eb(M - b, M + a);\r\n    }\r\n  }\r\n\r\n  vc<T> res;\r\n  set<P> done;\r\
    \n  FOR(p, len(by_p)) {\r\n    auto& LR = by_p[p];\r\n    sort(all(LR),\r\n  \
    \       [](auto& x, auto& y) { return P(x.fi, -x.se) < P(y.fi, -y.se); });\r\n\
    \    int r = -1;\r\n    for (auto&& lr: LR) {\r\n      if (chmax(r, lr.se) &&\
    \ !done.count(lr)) {\r\n        done.insert(lr);\r\n        res.eb(p, lr.fi, lr.se);\r\
    \n      }\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
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
  dependsOn:
  - string/zalgorithm.hpp
  isVerificationFile: false
  path: string/run_enumerate.hpp
  requiredBy: []
  timestamp: '2024-09-03 08:13:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/string/run_enumerate.test.cpp
  - test/2_library_checker/string/run_enumerate_vec.test.cpp
documentation_of: string/run_enumerate.hpp
layout: document
redirect_from:
- /library/string/run_enumerate.hpp
- /library/string/run_enumerate.hpp.html
title: string/run_enumerate.hpp
---
