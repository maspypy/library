---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc023/tasks/arc023_1
  bundledCode: "#line 1 \"datetime/datetime.hpp\"\nstruct DateTime {\n  int year,\
    \ month, day;\n  DateTime(int y, int m, int d) : year(y), month(m), day(d) {}\n\
    \n  // 1\u5E741\u67081\u65E5\u304C 0 \u3068\u306A\u308B\u3088\u3046\u306B\u5909\
    \u63DB\n  // https://atcoder.jp/contests/arc023/tasks/arc023_1\n  int to_int()\
    \ {\n    int y = (month <= 2 ? year - 1 : year);\n    int m = (month <= 2 ? month\
    \ + 12 : month);\n    int d = day;\n    return 365 * y + y / 4 - y / 100 + y /\
    \ 400 + 306 * (m + 1) / 10 + d - 429;\n  }\n\n  // \u65E5\u66DC\u65E5\u304C 0\
    \ \u3068\u3057\u3066\u3001\u66DC\u65E5\u3092 [0, 7) \u3067\u8FD4\u3059\n  int\
    \ weekday() { return (to_int() + 1) % 7; }\n};\n"
  code: "struct DateTime {\n  int year, month, day;\n  DateTime(int y, int m, int\
    \ d) : year(y), month(m), day(d) {}\n\n  // 1\u5E741\u67081\u65E5\u304C 0 \u3068\
    \u306A\u308B\u3088\u3046\u306B\u5909\u63DB\n  // https://atcoder.jp/contests/arc023/tasks/arc023_1\n\
    \  int to_int() {\n    int y = (month <= 2 ? year - 1 : year);\n    int m = (month\
    \ <= 2 ? month + 12 : month);\n    int d = day;\n    return 365 * y + y / 4 -\
    \ y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;\n  }\n\n  // \u65E5\u66DC\u65E5\
    \u304C 0 \u3068\u3057\u3066\u3001\u66DC\u65E5\u3092 [0, 7) \u3067\u8FD4\u3059\n\
    \  int weekday() { return (to_int() + 1) % 7; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datetime/datetime.hpp
  requiredBy: []
  timestamp: '2022-08-28 10:13:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datetime/datetime.hpp
layout: document
redirect_from:
- /library/datetime/datetime.hpp
- /library/datetime/datetime.hpp.html
title: datetime/datetime.hpp
---
