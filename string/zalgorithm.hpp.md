---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_periodic_sequence.hpp
    title: seq/interpolate_periodic_sequence.hpp
  - icon: ':heavy_check_mark:'
    path: string/is_substring.hpp
    title: string/is_substring.hpp
  - icon: ':heavy_check_mark:'
    path: string/run_enumerate.hpp
    title: string/run_enumerate.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/is_substring.test.cpp
    title: test/1_mytest/is_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/run_enumerate.test.cpp
    title: test/2_library_checker/string/run_enumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/run_enumerate_vec.test.cpp
    title: test/2_library_checker/string/run_enumerate_vec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/zalgorithm.test.cpp
    title: test/2_library_checker/string/zalgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1848.test.cpp
    title: test/3_yukicoder/1848.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2626_2.test.cpp
    title: test/3_yukicoder/2626_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2858.test.cpp
    title: test/3_yukicoder/2858.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc237ex.test.cpp
    title: test/5_atcoder/abc237ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc279b.test.cpp
    title: test/5_atcoder/abc279b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc354g.test.cpp
    title: test/5_atcoder/abc354g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/zalgorithm.hpp\"\n\ntemplate <typename STRING> //\
    \ string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> zalgorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n"
  code: "#pragma once\n\ntemplate <typename STRING> // string, vector \u3069\u3061\
    \u3089\u3067\u3082\nvector<int> zalgorithm(const STRING& s) {\n  int n = int(s.size());\n\
    \  if (n == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1,\
    \ j = 0; i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j\
    \ + z[j] - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n   \
    \ if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgorithm.hpp
  requiredBy:
  - string/run_enumerate.hpp
  - string/is_substring.hpp
  - seq/interpolate_periodic_sequence.hpp
  timestamp: '2024-09-03 08:13:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2858.test.cpp
  - test/3_yukicoder/2626_2.test.cpp
  - test/3_yukicoder/1848.test.cpp
  - test/5_atcoder/abc354g.test.cpp
  - test/5_atcoder/abc237ex.test.cpp
  - test/5_atcoder/abc279b.test.cpp
  - test/1_mytest/is_substring.test.cpp
  - test/2_library_checker/string/run_enumerate_vec.test.cpp
  - test/2_library_checker/string/zalgorithm.test.cpp
  - test/2_library_checker/string/run_enumerate.test.cpp
documentation_of: string/zalgorithm.hpp
layout: document
redirect_from:
- /library/string/zalgorithm.hpp
- /library/string/zalgorithm.hpp.html
title: string/zalgorithm.hpp
---
