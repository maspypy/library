---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
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
    path: test/library_checker/string/run_enumerate.test.cpp
    title: test/library_checker/string/run_enumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/run_enumerate_vec.test.cpp
    title: test/library_checker/string/run_enumerate_vec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm.test.cpp
    title: test/library_checker/string/zalgorithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/is_substring.test.cpp
    title: test/mytest/is_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1848.test.cpp
    title: test/yukicoder/1848.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc237ex.test.cpp
    title: test_atcoder/abc237ex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/zalgorithm.hpp\"\ntemplate <typename STRING>  //\
    \ string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> zalgorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n"
  code: "template <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> zalgorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/zalgorithm.hpp
  requiredBy:
  - seq/interpolate_periodic_sequence.hpp
  - string/is_substring.hpp
  - string/run_enumerate.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/zalgorithm.test.cpp
  - test/library_checker/string/run_enumerate.test.cpp
  - test/library_checker/string/run_enumerate_vec.test.cpp
  - test/mytest/is_substring.test.cpp
  - test/yukicoder/1848.test.cpp
  - test_atcoder/abc237ex.test.cpp
documentation_of: string/zalgorithm.hpp
layout: document
redirect_from:
- /library/string/zalgorithm.hpp
- /library/string/zalgorithm.hpp.html
title: string/zalgorithm.hpp
---
