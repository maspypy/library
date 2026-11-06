---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: linalg/ecottea_matrix_dp.hpp
    title: linalg/ecottea_matrix_dp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
    title: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ITP1_9_A.test.cpp
    title: test/4_aoj/ITP1_9_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/string/split.hpp
  bundledCode: "#line 1 \"string/split.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/split.hpp\n\
    vc<string> split(string S, string seps = \" ,\") {\n  vc<string> res = {\"\"};\n\
    \  for (auto&& s : S) {\n    if (count(all(seps), s))\n      res.eb(\"\");\n \
    \   else\n      res.back() += s;\n  }\n  return res;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/split.hpp\n\
    vc<string> split(string S, string seps = \" ,\") {\n  vc<string> res = {\"\"};\n\
    \  for (auto&& s : S) {\n    if (count(all(seps), s))\n      res.eb(\"\");\n \
    \   else\n      res.back() += s;\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/split.hpp
  requiredBy:
  - linalg/ecottea_matrix_dp.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
