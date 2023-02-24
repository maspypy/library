---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_B.test.cpp
    title: test/aoj/DPL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_3_C.test.cpp
    title: test/aoj/DPL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/cartesian_tree.test.cpp
    title: test/library_checker/tree/cartesian_tree.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc234g.test.cpp
    title: test_atcoder/abc234g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/cartesian_tree.hpp\"\n/*\r\n\u8F9E\u66F8\u9806\u3067\
    \u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\u306B\u3057\u3066\u3044\u308B\
    \u3002\r\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3067\
    \u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\r\n*/\r\ntemplate <typename T, bool\
    \ IS_MIN>\r\nstruct CartesianTree {\r\n  int n;\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> range;\r\n  vc<int> lch, rch, par;\r\n\r\n  CartesianTree(vc<T>& A) :\
    \ n(len(A)), A(A) {\r\n    range.assign(n, {-1, -1});\r\n    lch.assign(n, -1);\r\
    \n    rch.assign(n, -1);\r\n    par.assign(n, -1);\r\n    if (n == 1) {\r\n  \
    \    range[0] = {0, 1};\r\n      return;\r\n    }\r\n    auto is_sm = [&](int\
    \ i, int j) -> bool {\r\n      if (IS_MIN) return (A[i] < A[j]) || (A[i] == A[j]\
    \ && i < j);\r\n      return (A[i] > A[j]) || (A[i] == A[j] && i < j);\r\n   \
    \ };\r\n    vc<int> st;\r\n    FOR(i, n) {\r\n      while (!st.empty() && is_sm(i,\
    \ st.back())) {\r\n        lch[i] = st.back();\r\n        st.pop_back();\r\n \
    \     }\r\n      range[i].fi = (st.empty() ? 0 : st.back() + 1);\r\n      st.eb(i);\r\
    \n    }\r\n    st.clear();\r\n    FOR_R(i, n) {\r\n      while (!st.empty() &&\
    \ is_sm(i, st.back())) {\r\n        rch[i] = st.back();\r\n        st.pop_back();\r\
    \n      }\r\n      range[i].se = (st.empty() ? n : st.back());\r\n      st.eb(i);\r\
    \n    }\r\n    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\r\n    FOR(i, n) if\
    \ (rch[i] != -1) par[rch[i]] = i;\r\n  }\r\n\r\n  // (l, r, h)\r\n  tuple<int,\
    \ int, T> maximum_rectangle(int i) {\r\n    auto [l, r] = range[i];\r\n    return\
    \ {l, r, A[i]};\r\n  }\r\n\r\n  // (l, r, h)\r\n  T max_rectangle_area() {\r\n\
    \    assert(IS_MIN);\r\n    T res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r,\
    \ h] = maximum_rectangle(i);\r\n      chmax(res, (r - l) * h);\r\n    }\r\n  \
    \  return res;\r\n  }\r\n\r\n  ll count_subrectangle(bool baseline) {\r\n    assert(IS_MIN);\r\
    \n    ll res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r, h] = maximum_rectangle(i);\r\
    \n      ll x = (baseline ? h : h * (h + 1) / 2);\r\n      res += x * (i - l +\
    \ 1) * (r - i);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "/*\r\n\u8F9E\u66F8\u9806\u3067\u9AD8\u3055\u3092 unique \u3057\u3066\u3001\
    \u6728\u306B\u3057\u3066\u3044\u308B\u3002\r\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\u3067\u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\
    \r\n*/\r\ntemplate <typename T, bool IS_MIN>\r\nstruct CartesianTree {\r\n  int\
    \ n;\r\n  vc<T>& A;\r\n  vc<pair<int, int>> range;\r\n  vc<int> lch, rch, par;\r\
    \n\r\n  CartesianTree(vc<T>& A) : n(len(A)), A(A) {\r\n    range.assign(n, {-1,\
    \ -1});\r\n    lch.assign(n, -1);\r\n    rch.assign(n, -1);\r\n    par.assign(n,\
    \ -1);\r\n    if (n == 1) {\r\n      range[0] = {0, 1};\r\n      return;\r\n \
    \   }\r\n    auto is_sm = [&](int i, int j) -> bool {\r\n      if (IS_MIN) return\
    \ (A[i] < A[j]) || (A[i] == A[j] && i < j);\r\n      return (A[i] > A[j]) || (A[i]\
    \ == A[j] && i < j);\r\n    };\r\n    vc<int> st;\r\n    FOR(i, n) {\r\n     \
    \ while (!st.empty() && is_sm(i, st.back())) {\r\n        lch[i] = st.back();\r\
    \n        st.pop_back();\r\n      }\r\n      range[i].fi = (st.empty() ? 0 : st.back()\
    \ + 1);\r\n      st.eb(i);\r\n    }\r\n    st.clear();\r\n    FOR_R(i, n) {\r\n\
    \      while (!st.empty() && is_sm(i, st.back())) {\r\n        rch[i] = st.back();\r\
    \n        st.pop_back();\r\n      }\r\n      range[i].se = (st.empty() ? n : st.back());\r\
    \n      st.eb(i);\r\n    }\r\n    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\r\
    \n    FOR(i, n) if (rch[i] != -1) par[rch[i]] = i;\r\n  }\r\n\r\n  // (l, r, h)\r\
    \n  tuple<int, int, T> maximum_rectangle(int i) {\r\n    auto [l, r] = range[i];\r\
    \n    return {l, r, A[i]};\r\n  }\r\n\r\n  // (l, r, h)\r\n  T max_rectangle_area()\
    \ {\r\n    assert(IS_MIN);\r\n    T res = 0;\r\n    FOR(i, n) {\r\n      auto\
    \ [l, r, h] = maximum_rectangle(i);\r\n      chmax(res, (r - l) * h);\r\n    }\r\
    \n    return res;\r\n  }\r\n\r\n  ll count_subrectangle(bool baseline) {\r\n \
    \   assert(IS_MIN);\r\n    ll res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r,\
    \ h] = maximum_rectangle(i);\r\n      ll x = (baseline ? h : h * (h + 1) / 2);\r\
    \n      res += x * (i - l + 1) * (r - i);\r\n    }\r\n    return res;\r\n  }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc234g.test.cpp
  - test/library_checker/tree/cartesian_tree.test.cpp
  - test/aoj/DPL_3_C.test.cpp
  - test/aoj/DPL_3_B.test.cpp
documentation_of: seq/cartesian_tree.hpp
layout: document
redirect_from:
- /library/seq/cartesian_tree.hpp
- /library/seq/cartesian_tree.hpp.html
title: seq/cartesian_tree.hpp
---
