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
  bundledCode: "#line 1 \"seq/gray_code.hpp\"\n// 0, ..., 2^{LOG}-1 \u306E\u9806\u5217\
    \u3067\u3042\u3063\u3066\u30011 bit \u305A\u3064\u5909\u5316\u3059\u308B\u3082\
    \u306E\u3092\u8FD4\u3059\r\nvc<int> gray_code(int LOG) {\r\n  vc<int> res(1 <<\
    \ LOG);\r\n  FOR(v, 1 << LOG) res[v] = v ^ (v >> 1);\r\n  return res;\r\n}\r\n"
  code: "// 0, ..., 2^{LOG}-1 \u306E\u9806\u5217\u3067\u3042\u3063\u3066\u30011 bit\
    \ \u305A\u3064\u5909\u5316\u3059\u308B\u3082\u306E\u3092\u8FD4\u3059\r\nvc<int>\
    \ gray_code(int LOG) {\r\n  vc<int> res(1 << LOG);\r\n  FOR(v, 1 << LOG) res[v]\
    \ = v ^ (v >> 1);\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/gray_code.hpp
  requiredBy: []
  timestamp: '2022-04-24 15:02:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/gray_code.hpp
layout: document
redirect_from:
- /library/seq/gray_code.hpp
- /library/seq/gray_code.hpp.html
title: seq/gray_code.hpp
---
