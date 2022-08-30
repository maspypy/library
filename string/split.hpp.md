---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_9_A.test.cpp
    title: test/aoj/ITP1_9_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/split.hpp\"\nvc<string> split(string S, char sep\
    \ = ',') {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\n    if (s\
    \ == sep)\r\n      res.eb(\"\");\r\n    else\r\n      res.back() += s;\r\n  }\r\
    \n  return res;\r\n}\r\n\r\nvc<string> split(string S, string seps = \" ,\") {\r\
    \n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\n    if (count(all(seps),\
    \ s))\r\n      res.eb(\"\");\r\n    else\r\n      res.back() += s;\r\n  }\r\n\
    \  return res;\r\n}\r\n"
  code: "vc<string> split(string S, char sep = ',') {\r\n  vc<string> res = {\"\"\
    };\r\n  for (auto&& s: S) {\r\n    if (s == sep)\r\n      res.eb(\"\");\r\n  \
    \  else\r\n      res.back() += s;\r\n  }\r\n  return res;\r\n}\r\n\r\nvc<string>\
    \ split(string S, string seps = \" ,\") {\r\n  vc<string> res = {\"\"};\r\n  for\
    \ (auto&& s: S) {\r\n    if (count(all(seps), s))\r\n      res.eb(\"\");\r\n \
    \   else\r\n      res.back() += s;\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/split.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1_9_A.test.cpp
documentation_of: string/split.hpp
layout: document
redirect_from:
- /library/string/split.hpp
- /library/string/split.hpp.html
title: string/split.hpp
---
