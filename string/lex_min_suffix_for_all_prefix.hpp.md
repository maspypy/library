---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/lyndon.hpp
    title: string/lyndon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/lex_minmax_suffix.test.cpp
    title: test/1_mytest/lex_minmax_suffix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/lyndon.hpp\"\n\ntemplate <typename CHAR>\nstruct\
    \ Incremental_Lyndon_Factorization {\n  vc<CHAR> S;\n  int i = 0, j = 0, k = 0;\n\
    \  vc<int> minimum_suffix_len = {0};\n\n  int add(CHAR c) {\n    S.eb(c);\n  \
    \  // [j, j+(i-k)) simple\n    while (i < len(S)) {\n      if (k == i) {\n   \
    \     assert(j == k);\n        ++i;\n      }\n      elif (S[k] == S[i]) { ++k,\
    \ ++i; }\n      elif (S[k] < S[i]) { k = j, ++i; }\n      else {\n        j +=\
    \ (i - j) / (i - k) * (i - k);\n        i = k = j;\n      }\n    }\n    if ((i\
    \ - j) % (i - k) == 0) {\n      minimum_suffix_len.eb(i - k);\n    } else {\n\
    \      minimum_suffix_len.eb(minimum_suffix_len[k]);\n    }\n    return minimum_suffix_len[i];\n\
    \  }\n\n  vc<int> factorize() {\n    int i = len(S);\n    vc<int> I;\n    while\
    \ (i) {\n      I.eb(i);\n      i -= minimum_suffix_len[i];\n    }\n    I.eb(0);\n\
    \    reverse(all(I));\n    return I;\n  }\n};\n#line 2 \"string/lex_min_suffix_for_all_prefix.hpp\"\
    \n\n// ANS[i] := length of lex-min suffix of S[0,i)\nvc<int> lex_min_suffix_for_all_prefix(string\
    \ S) {\n  int N = len(S);\n  Incremental_Lyndon_Factorization<char> LD;\n  FOR(i,\
    \ N) LD.add(S[i]);\n  return LD.minimum_suffix_len;\n}\n"
  code: "#include \"string/lyndon.hpp\"\n\n// ANS[i] := length of lex-min suffix of\
    \ S[0,i)\nvc<int> lex_min_suffix_for_all_prefix(string S) {\n  int N = len(S);\n\
    \  Incremental_Lyndon_Factorization<char> LD;\n  FOR(i, N) LD.add(S[i]);\n  return\
    \ LD.minimum_suffix_len;\n}"
  dependsOn:
  - string/lyndon.hpp
  isVerificationFile: false
  path: string/lex_min_suffix_for_all_prefix.hpp
  requiredBy: []
  timestamp: '2025-05-18 18:12:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/lex_minmax_suffix.test.cpp
documentation_of: string/lex_min_suffix_for_all_prefix.hpp
layout: document
redirect_from:
- /library/string/lex_min_suffix_for_all_prefix.hpp
- /library/string/lex_min_suffix_for_all_prefix.hpp.html
title: string/lex_min_suffix_for_all_prefix.hpp
---
