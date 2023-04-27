---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/longest_common_substr.test.cpp
    title: test/mytest/longest_common_substr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/arc151_e.test.cpp
    title: test_atcoder/arc151_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 5 \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\
    \u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\
    \u3068\u304D\u3001\n// SA[i] = j, ISA[j] = i\nstruct Suffix_Array {\n  vector<int>\
    \ SA;\n  vector<int> ISA;\n  vector<int> LCP;\n  Sparse_Table<Monoid_Min<int>>\
    \ seg;\n  // DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string& s,\
    \ bool lcp_query = false) {\n    char first = 127, last = 0;\n    for (auto&&\
    \ c: s) {\n      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n    if (lcp_query) seg.build(LCP);\n  }\n\n\
    \  Suffix_Array(vector<int>& s, bool lcp_query = false) {\n    SA = calc_suffix_array(s);\n\
    \    calc_LCP(s);\n    if (lcp_query) seg.build(LCP);\n  }\n\n  // lcp(S[i:],\
    \ S[j:])\n  int lcp(int i, int j) {\n    int n = len(SA);\n    if (i == n || j\
    \ == n) return 0;\n    if (i == j) return n - i;\n    i = ISA[i], j = ISA[j];\n\
    \    if (i > j) swap(i, j);\n    return seg.prod(i, j);\n  }\n\nprivate:\n  void\
    \ induced_sort(const std::vector<int>& vect, int val_range,\n                \
    \    std::vector<int>& SA, const std::vector<bool>& sl,\n                    const\
    \ std::vector<int>& lms_idx) {\n    std::vector<int> l(val_range, 0), r(val_range,\
    \ 0);\n    for (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n   \
    \   ++r[c];\n    }\n    std::partial_sum(l.begin(), l.end(), l.begin());\n   \
    \ std::partial_sum(r.begin(), r.end(), r.begin());\n    std::fill(SA.begin(),\
    \ SA.end(), -1);\n    for (int i = (int)lms_idx.size() - 1; i >= 0; --i)\n   \
    \   SA[--r[vect[lms_idx[i]]]] = lms_idx[i];\n    for (int i: SA)\n      if (i\
    \ >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i - 1;\n    std::fill(r.begin(), r.end(),\
    \ 0);\n    for (int c: vect) ++r[c];\n    std::partial_sum(r.begin(), r.end(),\
    \ r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i\
    \ = SA[k])\n      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }\n\
    \  }\n\n  std::vector<int> SA_IS(const std::vector<int>& vect, int val_range)\
    \ {\n    const int n = vect.size();\n    std::vector<int> SA(n), lms_idx;\n  \
    \  std::vector<bool> sl(n);\n    sl[n - 1] = false;\n    for (int i = n - 2; i\
    \ >= 0; --i) {\n      sl[i] = (vect[i] > vect[i + 1] || (vect[i] == vect[i + 1]\
    \ && sl[i + 1]));\n      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);\n\
    \    }\n    std::reverse(lms_idx.begin(), lms_idx.end());\n    induced_sort(vect,\
    \ val_range, SA, sl, lms_idx);\n    std::vector<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n      if (!sl[SA[i]]\
    \ && SA[i] >= 1 && sl[SA[i] - 1]) {\n        new_lms_idx[k++] = SA[i];\n     \
    \ }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k < new_lms_idx.size();\
    \ ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n      if (vect[i]\
    \ != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n      }\n      bool\
    \ flag = false;\n      for (int a = i + 1, b = j + 1;; ++a, ++b) {\n        if\
    \ (vect[a] != vect[b]) {\n          flag = true;\n          break;\n        }\n\
    \        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n          flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n          break;\n   \
    \     }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n    for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if (cur +\
    \ 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec, cur + 1);\n \
    \     for (size_t i = 0; i < lms_idx.size(); ++i) {\n        new_lms_idx[i] =\
    \ lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect, val_range, SA, sl,\
    \ new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int> calc_suffix_array(const\
    \ std::string& s,\n                                     const char first = 'a',\n\
    \                                     const char last = 'z') {\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x: vect) x -= (int)first - 1;\n    vect.back() = 0;\n    auto\
    \ ret = SA_IS(vect, (int)last - (int)first + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  std::vector<int> calc_suffix_array(const vector<int>&\
    \ s) {\n    vector<int> ss = s;\n    sort(ss.begin(), ss.end());\n    ss.erase(unique(ss.begin(),\
    \ ss.end()), ss.end());\n\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x: vect)\n      x = lower_bound(ss.begin(),\
    \ ss.end(), x) - ss.begin() + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect,\
    \ *max_element(vect.begin(), vect.end()) + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  template <typename STRING>\n  void calc_LCP(const STRING&\
    \ s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n\
    \    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++,\
    \ k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n        k = 0;\n        continue;\n\
    \      }\n      int j = SA[ISA[i] + 1];\n      while (i + k < n && j + k < n &&\
    \ s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n    }\n    LCP.resize(n\
    \ - 1);\n  }\n};\n#line 2 \"string/longest_common_substring.hpp\"\n\ntemplate\
    \ <typename STRING>\ntuple<int, int, int, int> longest_common_substring(STRING&\
    \ S, STRING& T) {\n  int dummy = max<int>(*max_element(all(S)), *max_element(all(T)))\
    \ + 1;\n  STRING ST;\n  for (auto&& x: S) ST.push_back(x);\n  ST.push_back(dummy);\n\
    \  for (auto&& x: T) ST.push_back(x);\n  Suffix_Array X(ST);\n  auto& SA = X.SA;\n\
    \  auto& LCP = X.LCP;\n\n  tuple<int, int, int, int> res = {0, 0, 0, 0};\n  int\
    \ n = 0;\n  FOR(i, len(ST) - 1) {\n    int i1 = SA[i], i2 = SA[i + 1];\n    if\
    \ (i1 > i2) swap(i1, i2);\n    if (i1 < len(S) && len(S) < i2 && chmax(n, LCP[i]))\
    \ {\n      int a = i1, b = i2 - len(S) - 1;\n      res = {a, a + n, b, b + n};\n\
    \    }\n  }\n  return res;\n}\n"
  code: "#include \"string/suffix_array.hpp\"\n\ntemplate <typename STRING>\ntuple<int,\
    \ int, int, int> longest_common_substring(STRING& S, STRING& T) {\n  int dummy\
    \ = max<int>(*max_element(all(S)), *max_element(all(T))) + 1;\n  STRING ST;\n\
    \  for (auto&& x: S) ST.push_back(x);\n  ST.push_back(dummy);\n  for (auto&& x:\
    \ T) ST.push_back(x);\n  Suffix_Array X(ST);\n  auto& SA = X.SA;\n  auto& LCP\
    \ = X.LCP;\n\n  tuple<int, int, int, int> res = {0, 0, 0, 0};\n  int n = 0;\n\
    \  FOR(i, len(ST) - 1) {\n    int i1 = SA[i], i2 = SA[i + 1];\n    if (i1 > i2)\
    \ swap(i1, i2);\n    if (i1 < len(S) && len(S) < i2 && chmax(n, LCP[i])) {\n \
    \     int a = i1, b = i2 - len(S) - 1;\n      res = {a, a + n, b, b + n};\n  \
    \  }\n  }\n  return res;\n}"
  dependsOn:
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: string/longest_common_substring.hpp
  requiredBy: []
  timestamp: '2023-04-08 01:03:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/arc151_e.test.cpp
  - test/mytest/longest_common_substr.test.cpp
documentation_of: string/longest_common_substring.hpp
layout: document
redirect_from:
- /library/string/longest_common_substring.hpp
- /library/string/longest_common_substring.hpp.html
title: string/longest_common_substring.hpp
---
