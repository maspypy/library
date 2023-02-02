---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/disjointsparse/disjointsparse.hpp
    title: ds/disjointsparse/disjointsparse.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/number_of_substrings.test.cpp
    title: test/library_checker/string/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffix_array.test.cpp
    title: test/library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/suffix_array_vec.test.cpp
    title: test/library_checker/string/suffix_array_vec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/suffix_tree.test.cpp
    title: test/mytest/suffix_tree.test.cpp
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
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/disjointsparse/disjointsparse.hpp\"\
    \n\r\ntemplate <class Monoid>\r\nstruct DisjointSparse {\r\n  using MX = Monoid;\r\
    \n  using X = typename MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\
    \n  DisjointSparse() {}\r\n  DisjointSparse(int n) { build(n); }\r\n  template\
    \ <typename F>\r\n  DisjointSparse(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\
    \  DisjointSparse(const vc<X>& v) { build(v); }\r\n\r\n  void build(int m) {\r\
    \n    build(m, [](int i) -> X { return MX::unit(); });\r\n  }\r\n  void build(const\
    \ vc<X>& v) {\r\n    build(len(v), [&](int i) -> X { return v[i]; });\r\n  }\r\
    \n  template <typename F>\r\n  void build(int m, F f) {\r\n    n = m, log = 1;\r\
    \n    while ((1 << log) < n) ++log;\r\n    dat.resize(log);\r\n    dat[0].reserve(n);\r\
    \n    FOR(i, n) dat[0].eb(f(i));\r\n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\
    \n      v = dat[0];\r\n      int b = 1 << i;\r\n      for (int m = b; m <= n;\
    \ m += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n        FOR3_R(j,\
    \ L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n        FOR3(j, m, R - 1) v[j\
    \ + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int\
    \ L, int R) {\r\n    if (L == R) return MX::unit();\r\n    --R;\r\n    if (L ==\
    \ R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n    return\
    \ MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\n  int max_right(const\
    \ F check, int L) {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\n\
    \    if (L == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1\
    \ < ng) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n\r\n  template <class F>\r\n  int min_left(const F check, int R) {\r\n\
    \    assert(0 <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\
    \n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n#line 5 \"string/suffix_array.hpp\"\
    \n\n// \u8F9E\u66F8\u9806 i \u756A\u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\
    \u59CB\u307E\u308A\u3067\u3042\u308B\u3068\u304D\u3001\n// SA[i] = j, ISA[j] =\
    \ i\nstruct Suffix_Array {\n  vector<int> SA;\n  vector<int> ISA;\n  vector<int>\
    \ LCP;\n  bool build_ds;\n  DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string&\
    \ s) : build_ds(0) {\n    char first = 127, last = 0;\n    for (auto&& c: s) {\n\
    \      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n  }\n\n  Suffix_Array(vector<int>& s) : build_ds(0)\
    \ {\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\n  // S[i:], S[j:]\
    \ \u306E lcp \u3092\u6C42\u3081\u308B\n  int lcp(int i, int j) {\n    int n =\
    \ len(SA);\n    assert(i <= n && j <= n);\n    if (i == n || j == n) return 0;\n\
    \    if (i == j) return n - i;\n    if (!build_ds) {\n      build_ds = 1;\n  \
    \    seg.build(LCP);\n    }\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i,\
    \ j);\n    return seg.prod(i, j);\n  }\n\nprivate:\n  void induced_sort(const\
    \ std::vector<int>& vect, int val_range,\n                    std::vector<int>&\
    \ SA, const std::vector<bool>& sl,\n                    const std::vector<int>&\
    \ lms_idx) {\n    std::vector<int> l(val_range, 0), r(val_range, 0);\n    for\
    \ (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n \
    \   }\n    std::partial_sum(l.begin(), l.end(), l.begin());\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    std::fill(SA.begin(), SA.end(), -1);\n    for (int\
    \ i = (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] =\
    \ lms_idx[i];\n    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    std::fill(r.begin(), r.end(), 0);\n    for (int c: vect)\
    \ ++r[c];\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    for (int\
    \ k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1\
    \ && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }\n  }\n\n  std::vector<int>\
    \ SA_IS(const std::vector<int>& vect, int val_range) {\n    const int n = vect.size();\n\
    \    std::vector<int> SA(n), lms_idx;\n    std::vector<bool> sl(n);\n    sl[n\
    \ - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    std::reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    std::vector<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n \
    \       new_lms_idx[k++] = SA[i];\n      }\n    int cur = 0;\n    SA[n - 1] =\
    \ cur;\n    for (size_t k = 1; k < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k\
    \ - 1], j = new_lms_idx[k];\n      if (vect[i] != vect[j]) {\n        SA[j] =\
    \ ++cur;\n        continue;\n      }\n      bool flag = false;\n      for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n        if (vect[a] != vect[b]) {\n    \
    \      flag = true;\n          break;\n        }\n        if ((!sl[a] && sl[a\
    \ - 1]) || (!sl[b] && sl[b - 1])) {\n          flag = !((!sl[a] && sl[a - 1])\
    \ && (!sl[b] && sl[b - 1]));\n          break;\n        }\n      }\n      SA[j]\
    \ = (flag ? ++cur : cur);\n    }\n    for (size_t i = 0; i < lms_idx.size(); ++i)\
    \ lms_vec[i] = SA[lms_idx[i]];\n    if (cur + 1 < (int)lms_idx.size()) {\n   \
    \   auto lms_SA = SA_IS(lms_vec, cur + 1);\n      for (size_t i = 0; i < lms_idx.size();\
    \ ++i) {\n        new_lms_idx[i] = lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect,\
    \ val_range, SA, sl, new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int>\
    \ calc_suffix_array(const std::string& s,\n                                  \
    \   const char first = 'a',\n                                     const char last\
    \ = 'z') {\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x: vect) x -= (int)first - 1;\n\
    \    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first + 2);\n\
    \    ret.erase(ret.begin());\n    return ret;\n  }\n\n  std::vector<int> calc_suffix_array(const\
    \ vector<int>& s) {\n    vector<int> ss = s;\n    sort(ss.begin(), ss.end());\n\
    \    ss.erase(unique(ss.begin(), ss.end()), ss.end());\n\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x: vect)\n      x = lower_bound(ss.begin(), ss.end(), x) - ss.begin()\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, *max_element(vect.begin(),\
    \ vect.end()) + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  template\
    \ <typename STRING>\n  void calc_LCP(const STRING& s) {\n    int n = s.size(),\
    \ k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n    for (int i = 0; i < n; i++)\
    \ ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i]\
    \ == n - 1) {\n        k = 0;\n        continue;\n      }\n      int j = SA[ISA[i]\
    \ + 1];\n      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n \
    \     LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n  }\n};\n"
  code: "#pragma once\n\n#include \"alg/monoid/min.hpp\"\n#include \"ds/disjointsparse/disjointsparse.hpp\"\
    \n\n// \u8F9E\u66F8\u9806 i \u756A\u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\
    \u59CB\u307E\u308A\u3067\u3042\u308B\u3068\u304D\u3001\n// SA[i] = j, ISA[j] =\
    \ i\nstruct Suffix_Array {\n  vector<int> SA;\n  vector<int> ISA;\n  vector<int>\
    \ LCP;\n  bool build_ds;\n  DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string&\
    \ s) : build_ds(0) {\n    char first = 127, last = 0;\n    for (auto&& c: s) {\n\
    \      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n  }\n\n  Suffix_Array(vector<int>& s) : build_ds(0)\
    \ {\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\n  // S[i:], S[j:]\
    \ \u306E lcp \u3092\u6C42\u3081\u308B\n  int lcp(int i, int j) {\n    int n =\
    \ len(SA);\n    assert(i <= n && j <= n);\n    if (i == n || j == n) return 0;\n\
    \    if (i == j) return n - i;\n    if (!build_ds) {\n      build_ds = 1;\n  \
    \    seg.build(LCP);\n    }\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i,\
    \ j);\n    return seg.prod(i, j);\n  }\n\nprivate:\n  void induced_sort(const\
    \ std::vector<int>& vect, int val_range,\n                    std::vector<int>&\
    \ SA, const std::vector<bool>& sl,\n                    const std::vector<int>&\
    \ lms_idx) {\n    std::vector<int> l(val_range, 0), r(val_range, 0);\n    for\
    \ (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n \
    \   }\n    std::partial_sum(l.begin(), l.end(), l.begin());\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    std::fill(SA.begin(), SA.end(), -1);\n    for (int\
    \ i = (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] =\
    \ lms_idx[i];\n    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    std::fill(r.begin(), r.end(), 0);\n    for (int c: vect)\
    \ ++r[c];\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    for (int\
    \ k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1\
    \ && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }\n  }\n\n  std::vector<int>\
    \ SA_IS(const std::vector<int>& vect, int val_range) {\n    const int n = vect.size();\n\
    \    std::vector<int> SA(n), lms_idx;\n    std::vector<bool> sl(n);\n    sl[n\
    \ - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    std::reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    std::vector<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n \
    \       new_lms_idx[k++] = SA[i];\n      }\n    int cur = 0;\n    SA[n - 1] =\
    \ cur;\n    for (size_t k = 1; k < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k\
    \ - 1], j = new_lms_idx[k];\n      if (vect[i] != vect[j]) {\n        SA[j] =\
    \ ++cur;\n        continue;\n      }\n      bool flag = false;\n      for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n        if (vect[a] != vect[b]) {\n    \
    \      flag = true;\n          break;\n        }\n        if ((!sl[a] && sl[a\
    \ - 1]) || (!sl[b] && sl[b - 1])) {\n          flag = !((!sl[a] && sl[a - 1])\
    \ && (!sl[b] && sl[b - 1]));\n          break;\n        }\n      }\n      SA[j]\
    \ = (flag ? ++cur : cur);\n    }\n    for (size_t i = 0; i < lms_idx.size(); ++i)\
    \ lms_vec[i] = SA[lms_idx[i]];\n    if (cur + 1 < (int)lms_idx.size()) {\n   \
    \   auto lms_SA = SA_IS(lms_vec, cur + 1);\n      for (size_t i = 0; i < lms_idx.size();\
    \ ++i) {\n        new_lms_idx[i] = lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect,\
    \ val_range, SA, sl, new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int>\
    \ calc_suffix_array(const std::string& s,\n                                  \
    \   const char first = 'a',\n                                     const char last\
    \ = 'z') {\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x: vect) x -= (int)first - 1;\n\
    \    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first + 2);\n\
    \    ret.erase(ret.begin());\n    return ret;\n  }\n\n  std::vector<int> calc_suffix_array(const\
    \ vector<int>& s) {\n    vector<int> ss = s;\n    sort(ss.begin(), ss.end());\n\
    \    ss.erase(unique(ss.begin(), ss.end()), ss.end());\n\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x: vect)\n      x = lower_bound(ss.begin(), ss.end(), x) - ss.begin()\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, *max_element(vect.begin(),\
    \ vect.end()) + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  template\
    \ <typename STRING>\n  void calc_LCP(const STRING& s) {\n    int n = s.size(),\
    \ k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n    for (int i = 0; i < n; i++)\
    \ ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i]\
    \ == n - 1) {\n        k = 0;\n        continue;\n      }\n      int j = SA[ISA[i]\
    \ + 1];\n      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n \
    \     LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n  }\n};"
  dependsOn:
  - alg/monoid/min.hpp
  - ds/disjointsparse/disjointsparse.hpp
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy:
  - string/longest_common_substring.hpp
  - string/suffix_tree.hpp
  timestamp: '2023-02-02 02:12:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/suffix_array_vec.test.cpp
  - test/library_checker/string/number_of_substrings.test.cpp
  - test/library_checker/string/suffix_array.test.cpp
  - test/mytest/suffix_tree.test.cpp
  - test_atcoder/arc151_e.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
redirect_from:
- /library/string/suffix_array.hpp
- /library/string/suffix_array.hpp.html
title: string/suffix_array.hpp
---
