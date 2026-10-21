---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: seq/interpolate_periodic_sequence.hpp
    title: seq/interpolate_periodic_sequence.hpp
  - icon: ':question:'
    path: string/find_runs.hpp
    title: string/find_runs.hpp
  - icon: ':heavy_check_mark:'
    path: string/is_substring.hpp
    title: string/is_substring.hpp
  - icon: ':warning:'
    path: string/non_dominated_suffix.hpp
    title: string/non_dominated_suffix.hpp
  - icon: ':warning:'
    path: string/periods.hpp
    title: string/periods.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/is_substring.test.cpp
    title: test/1_mytest/is_substring.test.cpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/3_yukicoder/2858.test.cpp
    title: test/3_yukicoder/2858.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/string/z_algorithm.hpp
  bundledCode: "#line 1 \"string/z_algorithm.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/z_algorithm.hpp\n\
    \ntemplate <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> z_algorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/z_algorithm.hpp\n\
    \ntemplate <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> z_algorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy:
  - string/find_runs.hpp
  - string/is_substring.hpp
  - string/periods.hpp
  - string/non_dominated_suffix.hpp
  - seq/interpolate_periodic_sequence.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2858.test.cpp
  - test/3_yukicoder/1848.test.cpp
  - test/1_mytest/is_substring.test.cpp
  - test/2_library_checker/string/run_enumerate_vec.test.cpp
  - test/2_library_checker/string/zalgorithm.test.cpp
  - test/2_library_checker/string/run_enumerate.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
