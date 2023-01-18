---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: seq/interpolate_periodic_sequence_query.hpp
    title: seq/interpolate_periodic_sequence_query.hpp
  - icon: ':x:'
    path: string/is_substring.hpp
    title: string/is_substring.hpp
  - icon: ':x:'
    path: string/run_enumerate.hpp
    title: string/run_enumerate.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/string/run_enumerate.test.cpp
    title: test/library_checker/string/run_enumerate.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/run_enumerate_vec.test.cpp
    title: test/library_checker/string/run_enumerate_vec.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/zalgorithm.test.cpp
    title: test/library_checker/string/zalgorithm.test.cpp
  - icon: ':x:'
    path: test/mytest/is_substring.test.cpp
    title: test/mytest/is_substring.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1848.test.cpp
    title: test/yukicoder/1848.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  - string/run_enumerate.hpp
  - string/is_substring.hpp
  - seq/interpolate_periodic_sequence_query.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/string/zalgorithm.test.cpp
  - test/library_checker/string/run_enumerate_vec.test.cpp
  - test/library_checker/string/run_enumerate.test.cpp
  - test/yukicoder/1848.test.cpp
  - test/mytest/is_substring.test.cpp
documentation_of: string/zalgorithm.hpp
layout: document
redirect_from:
- /library/string/zalgorithm.hpp
- /library/string/zalgorithm.hpp.html
title: string/zalgorithm.hpp
---
