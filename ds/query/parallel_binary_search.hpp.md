---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/query/parallel_binary_search.hpp\"\n/*\r\n\u4E26\u5217\
    \u4E8C\u5206\u63A2\u7D22\u3002(Q, ok, ng, init, upd, check)\u3002\r\ncheck \u304C\
    \u6210\u308A\u7ACB\u3064\u304E\u308A\u304E\u308A\u306E upd\u56DE\u6570\u3092\u8FD4\
    \u3059\u3002\r\n\u30FBvoid upd(t)\uFF1At \u56DE\u76EE\u306E update\r\n\u30FBbool\
    \ check(q)\uFF1A\u30AF\u30A8\u30EA q \u306E\u5224\u5B9A\r\n*/\r\ntemplate <typename\
    \ F1, typename F2, typename F3>\r\nvc<int> parallel_binary_search(int Q, int ok,\
    \ int ng, F1 init, F2 upd,\r\n                               F3 check) {\r\n \
    \ int T = max(ok, ng);\r\n  vc<int> OK(Q, ok), NG(Q, ng);\r\n  while (1) {\r\n\
    \    vc<int> check_t(Q, -1);\r\n    FOR(q, Q) {\r\n      int& t = check_t[q];\r\
    \n      if (abs(OK[q] - NG[q]) > 1) { t = (OK[q] + NG[q]) / 2; }\r\n    }\r\n\
    \    vc<int> indptr(T + 1);\r\n    FOR(q, Q) {\r\n      int& t = check_t[q];\r\
    \n      if (t != -1) indptr[t + 1]++;\r\n    }\r\n    FOR(t, T) indptr[t + 1]\
    \ += indptr[t];\r\n    int total = indptr.back();\r\n    if (total == 0) break;\r\
    \n    auto counter = indptr;\r\n    vc<int> csr(total);\r\n    FOR(q, Q) {\r\n\
    \      int& t = check_t[q];\r\n      if (t != -1) { csr[counter[t]++] = q; }\r\
    \n    }\r\n\r\n    init();\r\n    int t = 0;\r\n    for (auto&& q: csr) {\r\n\
    \      while (t < check_t[q]) { upd(t++); }\r\n      if (check(q))\r\n       \
    \ OK[q] = t;\r\n      else\r\n        NG[q] = t;\r\n    }\r\n  }\r\n  return OK;\r\
    \n}\n"
  code: "/*\r\n\u4E26\u5217\u4E8C\u5206\u63A2\u7D22\u3002(Q, ok, ng, init, upd, check)\u3002\
    \r\ncheck \u304C\u6210\u308A\u7ACB\u3064\u304E\u308A\u304E\u308A\u306E upd\u56DE\
    \u6570\u3092\u8FD4\u3059\u3002\r\n\u30FBvoid upd(t)\uFF1At \u56DE\u76EE\u306E\
    \ update\r\n\u30FBbool check(q)\uFF1A\u30AF\u30A8\u30EA q \u306E\u5224\u5B9A\r\
    \n*/\r\ntemplate <typename F1, typename F2, typename F3>\r\nvc<int> parallel_binary_search(int\
    \ Q, int ok, int ng, F1 init, F2 upd,\r\n                               F3 check)\
    \ {\r\n  int T = max(ok, ng);\r\n  vc<int> OK(Q, ok), NG(Q, ng);\r\n  while (1)\
    \ {\r\n    vc<int> check_t(Q, -1);\r\n    FOR(q, Q) {\r\n      int& t = check_t[q];\r\
    \n      if (abs(OK[q] - NG[q]) > 1) { t = (OK[q] + NG[q]) / 2; }\r\n    }\r\n\
    \    vc<int> indptr(T + 1);\r\n    FOR(q, Q) {\r\n      int& t = check_t[q];\r\
    \n      if (t != -1) indptr[t + 1]++;\r\n    }\r\n    FOR(t, T) indptr[t + 1]\
    \ += indptr[t];\r\n    int total = indptr.back();\r\n    if (total == 0) break;\r\
    \n    auto counter = indptr;\r\n    vc<int> csr(total);\r\n    FOR(q, Q) {\r\n\
    \      int& t = check_t[q];\r\n      if (t != -1) { csr[counter[t]++] = q; }\r\
    \n    }\r\n\r\n    init();\r\n    int t = 0;\r\n    for (auto&& q: csr) {\r\n\
    \      while (t < check_t[q]) { upd(t++); }\r\n      if (check(q))\r\n       \
    \ OK[q] = t;\r\n      else\r\n        NG[q] = t;\r\n    }\r\n  }\r\n  return OK;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/parallel_binary_search.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/parallel_binary_search.hpp
layout: document
redirect_from:
- /library/ds/query/parallel_binary_search.hpp
- /library/ds/query/parallel_binary_search.hpp.html
title: ds/query/parallel_binary_search.hpp
---
