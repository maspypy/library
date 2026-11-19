---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_pbs.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_pbs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/3314.test.cpp
    title: test/3_yukicoder/3314.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/offline_query/parallel_binary_search.hpp
  bundledCode: "#line 1 \"ds/offline_query/parallel_binary_search.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/ds/offline_query/parallel_binary_search.hpp\n\
    /*\n\u4E26\u5217\u4E8C\u5206\u63A2\u7D22\u3002(Q, ok, ng, init, upd, check)\u3002\
    \ncheck \u304C\u6210\u308A\u7ACB\u3064\u304E\u308A\u304E\u308A\u306E upd\u56DE\
    \u6570\u3092\u8FD4\u3059\u3002\n\u30FBvoid upd(t)\uFF1At \u56DE\u76EE\u306E update\n\
    \u30FBbool check(q)\uFF1A\u30AF\u30A8\u30EA q \u306E\u5224\u5B9A\n*/\ntemplate\
    \ <typename F1, typename F2, typename F3>\nvc<int> parallel_binary_search(int\
    \ Q, int ok, int ng, F1 init, F2 upd,\n                               F3 check)\
    \ {\n  int T = max(ok, ng);\n  vc<int> OK(Q, ok), NG(Q, ng);\n  while (1) {\n\
    \    vc<int> check_t(Q, -1);\n    FOR(q, Q) {\n      int& t = check_t[q];\n  \
    \    if (abs(OK[q] - NG[q]) > 1) { t = (OK[q] + NG[q]) / 2; }\n    }\n    vc<int>\
    \ indptr(T + 1);\n    FOR(q, Q) {\n      int& t = check_t[q];\n      if (t !=\
    \ -1) indptr[t + 1]++;\n    }\n    FOR(t, T) indptr[t + 1] += indptr[t];\n   \
    \ int total = indptr.back();\n    if (total == 0) break;\n    auto counter = indptr;\n\
    \    vc<int> csr(total);\n    FOR(q, Q) {\n      int& t = check_t[q];\n      if\
    \ (t != -1) { csr[counter[t]++] = q; }\n    }\n\n    init();\n    int t = 0;\n\
    \    for (auto&& q: csr) {\n      while (t < check_t[q]) { upd(t++); }\n     \
    \ if (check(q))\n        OK[q] = t;\n      else\n        NG[q] = t;\n    }\n \
    \ }\n  return OK;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/offline_query/parallel_binary_search.hpp\n\
    /*\n\u4E26\u5217\u4E8C\u5206\u63A2\u7D22\u3002(Q, ok, ng, init, upd, check)\u3002\
    \ncheck \u304C\u6210\u308A\u7ACB\u3064\u304E\u308A\u304E\u308A\u306E upd\u56DE\
    \u6570\u3092\u8FD4\u3059\u3002\n\u30FBvoid upd(t)\uFF1At \u56DE\u76EE\u306E update\n\
    \u30FBbool check(q)\uFF1A\u30AF\u30A8\u30EA q \u306E\u5224\u5B9A\n*/\ntemplate\
    \ <typename F1, typename F2, typename F3>\nvc<int> parallel_binary_search(int\
    \ Q, int ok, int ng, F1 init, F2 upd,\n                               F3 check)\
    \ {\n  int T = max(ok, ng);\n  vc<int> OK(Q, ok), NG(Q, ng);\n  while (1) {\n\
    \    vc<int> check_t(Q, -1);\n    FOR(q, Q) {\n      int& t = check_t[q];\n  \
    \    if (abs(OK[q] - NG[q]) > 1) { t = (OK[q] + NG[q]) / 2; }\n    }\n    vc<int>\
    \ indptr(T + 1);\n    FOR(q, Q) {\n      int& t = check_t[q];\n      if (t !=\
    \ -1) indptr[t + 1]++;\n    }\n    FOR(t, T) indptr[t + 1] += indptr[t];\n   \
    \ int total = indptr.back();\n    if (total == 0) break;\n    auto counter = indptr;\n\
    \    vc<int> csr(total);\n    FOR(q, Q) {\n      int& t = check_t[q];\n      if\
    \ (t != -1) { csr[counter[t]++] = q; }\n    }\n\n    init();\n    int t = 0;\n\
    \    for (auto&& q: csr) {\n      while (t < check_t[q]) { upd(t++); }\n     \
    \ if (check(q))\n        OK[q] = t;\n      else\n        NG[q] = t;\n    }\n \
    \ }\n  return OK;\n}"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/parallel_binary_search.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/3314.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_pbs.test.cpp
documentation_of: ds/offline_query/parallel_binary_search.hpp
layout: document
redirect_from:
- /library/ds/offline_query/parallel_binary_search.hpp
- /library/ds/offline_query/parallel_binary_search.hpp.html
title: ds/offline_query/parallel_binary_search.hpp
---
