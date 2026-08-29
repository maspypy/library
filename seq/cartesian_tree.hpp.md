---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/basic_substring_structure.hpp
    title: string/basic_substring_structure.hpp
  - icon: ':x:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/tree/cartesian_tree.test.cpp
    title: test/2_library_checker/tree/cartesian_tree.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2574.test.cpp
    title: test/3_yukicoder/2574.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DPL_3_B.test.cpp
    title: test/4_aoj/DPL_3_B.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DPL_3_C.test.cpp
    title: test/4_aoj/DPL_3_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/cartesian_tree.hpp\"\n/*\n\u8F9E\u66F8\u9806\u3067\u9AD8\
    \u3055\u3092 unique \u3057\u3066\u3001\u6728\u306B\u3057\u3066\u3044\u308B\u3002\
    \n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3067\u7DDA\
    \u5F62\u6642\u9593\u69CB\u7BC9\u3002\n*/\ntemplate <typename T, bool IS_MIN>\n\
    struct CartesianTree {\n  int n;\n  vc<T>& A;\n  vc<pair<int, int>> range;\n \
    \ vc<int> lch, rch, par;\n  int root;\n\n  CartesianTree(vc<T>& A) : n(len(A)),\
    \ A(A) {\n    range.assign(n, {-1, -1});\n    lch.assign(n, -1);\n    rch.assign(n,\
    \ -1);\n    par.assign(n, -1);\n    if (n == 1) {\n      range[0] = {0, 1};\n\
    \      root = 0;\n      return;\n    }\n    auto is_sm = [&](int i, int j) ->\
    \ bool {\n      if (IS_MIN) return (A[i] < A[j]) || (A[i] == A[j] && i < j);\n\
    \      return (A[i] > A[j]) || (A[i] == A[j] && i < j);\n    };\n    vc<int> st;\n\
    \    FOR(i, n) {\n      while (!st.empty() && is_sm(i, st.back())) {\n       \
    \ lch[i] = st.back();\n        st.pop_back();\n      }\n      range[i].fi = (st.empty()\
    \ ? 0 : st.back() + 1);\n      st.eb(i);\n    }\n    st.clear();\n    FOR_R(i,\
    \ n) {\n      while (!st.empty() && is_sm(i, st.back())) {\n        rch[i] = st.back();\n\
    \        st.pop_back();\n      }\n      range[i].se = (st.empty() ? n : st.back());\n\
    \      st.eb(i);\n    }\n    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\n  \
    \  FOR(i, n) if (rch[i] != -1) par[rch[i]] = i;\n    FOR(i, n) if (par[i] == -1)\
    \ root = i;\n  }\n\n  // (l, r, h)\n  tuple<int, int, T> maximum_rectangle(int\
    \ i) {\n    auto [l, r] = range[i];\n    return {l, r, A[i]};\n  }\n\n  // (l,\
    \ r, h)\n  T max_rectangle_area() {\n    assert(IS_MIN);\n    T res = 0;\n   \
    \ FOR(i, n) {\n      auto [l, r, h] = maximum_rectangle(i);\n      chmax(res,\
    \ (r - l) * h);\n    }\n    return res;\n  }\n\n  ll count_subrectangle(bool baseline)\
    \ {\n    assert(IS_MIN);\n    ll res = 0;\n    FOR(i, n) {\n      auto [l, r,\
    \ h] = maximum_rectangle(i);\n      ll x = (baseline ? h : h * (h + 1) / 2);\n\
    \      res += x * (i - l + 1) * (r - i);\n    }\n    return res;\n  }\n};\n"
  code: "/*\n\u8F9E\u66F8\u9806\u3067\u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\
    \u306B\u3057\u3066\u3044\u308B\u3002\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\u3067\u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\n*/\n\
    template <typename T, bool IS_MIN>\nstruct CartesianTree {\n  int n;\n  vc<T>&\
    \ A;\n  vc<pair<int, int>> range;\n  vc<int> lch, rch, par;\n  int root;\n\n \
    \ CartesianTree(vc<T>& A) : n(len(A)), A(A) {\n    range.assign(n, {-1, -1});\n\
    \    lch.assign(n, -1);\n    rch.assign(n, -1);\n    par.assign(n, -1);\n    if\
    \ (n == 1) {\n      range[0] = {0, 1};\n      root = 0;\n      return;\n    }\n\
    \    auto is_sm = [&](int i, int j) -> bool {\n      if (IS_MIN) return (A[i]\
    \ < A[j]) || (A[i] == A[j] && i < j);\n      return (A[i] > A[j]) || (A[i] ==\
    \ A[j] && i < j);\n    };\n    vc<int> st;\n    FOR(i, n) {\n      while (!st.empty()\
    \ && is_sm(i, st.back())) {\n        lch[i] = st.back();\n        st.pop_back();\n\
    \      }\n      range[i].fi = (st.empty() ? 0 : st.back() + 1);\n      st.eb(i);\n\
    \    }\n    st.clear();\n    FOR_R(i, n) {\n      while (!st.empty() && is_sm(i,\
    \ st.back())) {\n        rch[i] = st.back();\n        st.pop_back();\n      }\n\
    \      range[i].se = (st.empty() ? n : st.back());\n      st.eb(i);\n    }\n \
    \   FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\n    FOR(i, n) if (rch[i] !=\
    \ -1) par[rch[i]] = i;\n    FOR(i, n) if (par[i] == -1) root = i;\n  }\n\n  //\
    \ (l, r, h)\n  tuple<int, int, T> maximum_rectangle(int i) {\n    auto [l, r]\
    \ = range[i];\n    return {l, r, A[i]};\n  }\n\n  // (l, r, h)\n  T max_rectangle_area()\
    \ {\n    assert(IS_MIN);\n    T res = 0;\n    FOR(i, n) {\n      auto [l, r, h]\
    \ = maximum_rectangle(i);\n      chmax(res, (r - l) * h);\n    }\n    return res;\n\
    \  }\n\n  ll count_subrectangle(bool baseline) {\n    assert(IS_MIN);\n    ll\
    \ res = 0;\n    FOR(i, n) {\n      auto [l, r, h] = maximum_rectangle(i);\n  \
    \    ll x = (baseline ? h : h * (h + 1) / 2);\n      res += x * (i - l + 1) *\
    \ (r - i);\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/cartesian_tree.hpp
  requiredBy:
  - string/basic_substring_structure.hpp
  - string/suffix_tree.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/tree/cartesian_tree.test.cpp
  - test/4_aoj/DPL_3_B.test.cpp
  - test/4_aoj/DPL_3_C.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/2574.test.cpp
documentation_of: seq/cartesian_tree.hpp
layout: document
redirect_from:
- /library/seq/cartesian_tree.hpp
- /library/seq/cartesian_tree.hpp.html
title: seq/cartesian_tree.hpp
---
