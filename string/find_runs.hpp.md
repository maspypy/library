---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
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
    links:
    - https://github.com/maspypy/library/blob/main/string/find_runs.hpp
  bundledCode: "#line 1 \"string/find_runs.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/find_runs.hpp\n\
    #line 1 \"string/z_algorithm.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/z_algorithm.hpp\n\
    \ntemplate <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> z_algorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n#line 3 \"string/find_runs.hpp\"\
    \n\n// (period, l, r)\n// \u6975\u5927, \u3064\u307E\u308A S[l:r] \u306F\u5468\
    \u671F p (\u305F\u3060\u3057 r-l >= 2p) \u3092\u6301\u3064\u304C\u3001S[l-1:r],\
    \ S[l:r+1]\n// \u306F\u305D\u3046\u3067\u306F\u306A\u3044\n// \u9AD8\u3005 n \u500B\
    \u4EE5\u4E0B\n// sum of (r-l)/p = O(n)\ntemplate <typename STRING>\nvc<tuple<int,\
    \ int, int>> find_runs(const STRING& S) {\n  ll N = len(S);\n  using T = tuple<int,\
    \ int, int>;\n  using P = pair<int, int>;\n  vc<vc<P>> by_p(N + 1);\n\n  auto\
    \ solve_sub = [&](STRING& left, STRING& right) -> vc<T> {\n    vc<T> res;\n  \
    \  int n = len(left), m = len(right);\n    auto S = left, T = right;\n    reverse(all(S));\n\
    \    T.insert(T.end(), all(left));\n    T.insert(T.end(), all(right));\n    auto\
    \ ZS = z_algorithm(S), ZT = z_algorithm(T);\n    FOR3(p, 1, n + 1) {\n      int\
    \ a = (p == n ? p : min(ZS[p] + int(p), n));\n      int b = min(ZT[n + m - p],\
    \ m);\n      if (a + b < 2 * p) continue;\n      res.eb(p, a, b);\n    }\n   \
    \ return res;\n  };\n\n  vc<P> st = {{0, N}};\n  while (!st.empty()) {\n    auto\
    \ [L, R] = st.back();\n    st.pop_back();\n    if (R - L <= 1) continue;\n   \
    \ int M = (L + R) / 2;\n    st.eb(L, M), st.eb(M, R);\n    STRING SL = {S.begin()\
    \ + L, S.begin() + M};\n    STRING SR = {S.begin() + M, S.begin() + R};\n    {\n\
    \      auto sub_res = solve_sub(SL, SR);\n      for (auto&& [p, a, b] : sub_res)\
    \ by_p[p].eb(M - a, M + b);\n    }\n    {\n      reverse(all(SL)), reverse(all(SR));\n\
    \      auto sub_res = solve_sub(SR, SL);\n      for (auto&& [p, a, b] : sub_res)\
    \ by_p[p].eb(M - b, M + a);\n    }\n  }\n\n  vc<T> res;\n  set<P> done;\n  FOR(p,\
    \ len(by_p)) {\n    auto& LR = by_p[p];\n    sort(all(LR),\n         [](auto&\
    \ x, auto& y) { return P(x.fi, -x.se) < P(y.fi, -y.se); });\n    int r = -1;\n\
    \    for (auto&& lr : LR) {\n      if (chmax(r, lr.se) && !done.count(lr)) {\n\
    \        done.insert(lr);\n        res.eb(p, lr.fi, lr.se);\n      }\n    }\n\
    \  }\n  return res;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/find_runs.hpp\n\
    #include \"string/z_algorithm.hpp\"\n\n// (period, l, r)\n// \u6975\u5927, \u3064\
    \u307E\u308A S[l:r] \u306F\u5468\u671F p (\u305F\u3060\u3057 r-l >= 2p) \u3092\
    \u6301\u3064\u304C\u3001S[l-1:r], S[l:r+1]\n// \u306F\u305D\u3046\u3067\u306F\u306A\
    \u3044\n// \u9AD8\u3005 n \u500B\u4EE5\u4E0B\n// sum of (r-l)/p = O(n)\ntemplate\
    \ <typename STRING>\nvc<tuple<int, int, int>> find_runs(const STRING& S) {\n \
    \ ll N = len(S);\n  using T = tuple<int, int, int>;\n  using P = pair<int, int>;\n\
    \  vc<vc<P>> by_p(N + 1);\n\n  auto solve_sub = [&](STRING& left, STRING& right)\
    \ -> vc<T> {\n    vc<T> res;\n    int n = len(left), m = len(right);\n    auto\
    \ S = left, T = right;\n    reverse(all(S));\n    T.insert(T.end(), all(left));\n\
    \    T.insert(T.end(), all(right));\n    auto ZS = z_algorithm(S), ZT = z_algorithm(T);\n\
    \    FOR3(p, 1, n + 1) {\n      int a = (p == n ? p : min(ZS[p] + int(p), n));\n\
    \      int b = min(ZT[n + m - p], m);\n      if (a + b < 2 * p) continue;\n  \
    \    res.eb(p, a, b);\n    }\n    return res;\n  };\n\n  vc<P> st = {{0, N}};\n\
    \  while (!st.empty()) {\n    auto [L, R] = st.back();\n    st.pop_back();\n \
    \   if (R - L <= 1) continue;\n    int M = (L + R) / 2;\n    st.eb(L, M), st.eb(M,\
    \ R);\n    STRING SL = {S.begin() + L, S.begin() + M};\n    STRING SR = {S.begin()\
    \ + M, S.begin() + R};\n    {\n      auto sub_res = solve_sub(SL, SR);\n     \
    \ for (auto&& [p, a, b] : sub_res) by_p[p].eb(M - a, M + b);\n    }\n    {\n \
    \     reverse(all(SL)), reverse(all(SR));\n      auto sub_res = solve_sub(SR,\
    \ SL);\n      for (auto&& [p, a, b] : sub_res) by_p[p].eb(M - b, M + a);\n   \
    \ }\n  }\n\n  vc<T> res;\n  set<P> done;\n  FOR(p, len(by_p)) {\n    auto& LR\
    \ = by_p[p];\n    sort(all(LR),\n         [](auto& x, auto& y) { return P(x.fi,\
    \ -x.se) < P(y.fi, -y.se); });\n    int r = -1;\n    for (auto&& lr : LR) {\n\
    \      if (chmax(r, lr.se) && !done.count(lr)) {\n        done.insert(lr);\n \
    \       res.eb(p, lr.fi, lr.se);\n      }\n    }\n  }\n  return res;\n}\n"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: false
  path: string/find_runs.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/string/run_enumerate_vec.test.cpp
  - test/2_library_checker/string/run_enumerate.test.cpp
documentation_of: string/find_runs.hpp
layout: document
redirect_from:
- /library/string/find_runs.hpp
- /library/string/find_runs.hpp.html
title: string/find_runs.hpp
---
