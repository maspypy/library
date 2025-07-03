---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
    title: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
  - icon: ':x:'
    path: test/4_aoj/ITP1_9_A.test.cpp
    title: test/4_aoj/ITP1_9_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
  - test/4_aoj/ITP1_9_A.test.cpp
documentation_of: string/split.hpp
layout: document
redirect_from:
- /library/string/split.hpp
- /library/string/split.hpp.html
title: string/split.hpp
---
