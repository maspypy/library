---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/gray_code.test.cpp
    title: test/1_mytest/gray_code.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/seq/famous/gray_code.hpp
  bundledCode: "#line 1 \"seq/famous/gray_code.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/seq/famous/gray_code.hpp\n\
    // 0, ..., 2^{LOG}-1 \u306E\u9806\u5217\u3067\u3042\u3063\u3066\u30011 bit \u305A\
    \u3064\u5909\u5316\u3059\u308B\u3082\u306E\u3092\u8FD4\u3059\nvc<int> gray_code(int\
    \ LOG) {\n  vc<int> res(1 << LOG);\n  FOR(v, 1 << LOG) res[v] = v ^ (v >> 1);\n\
    \  return res;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/seq/famous/gray_code.hpp\n\
    // 0, ..., 2^{LOG}-1 \u306E\u9806\u5217\u3067\u3042\u3063\u3066\u30011 bit \u305A\
    \u3064\u5909\u5316\u3059\u308B\u3082\u306E\u3092\u8FD4\u3059\nvc<int> gray_code(int\
    \ LOG) {\n  vc<int> res(1 << LOG);\n  FOR(v, 1 << LOG) res[v] = v ^ (v >> 1);\n\
    \  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/gray_code.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/gray_code.test.cpp
documentation_of: seq/famous/gray_code.hpp
layout: document
redirect_from:
- /library/seq/famous/gray_code.hpp
- /library/seq/famous/gray_code.hpp.html
title: seq/famous/gray_code.hpp
---
