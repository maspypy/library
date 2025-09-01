---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/lex_min_suffix_for_all_prefix.hpp
    title: string/lex_min_suffix_for_all_prefix.hpp
  - icon: ':warning:'
    path: string/non_dominated_suffix.hpp
    title: string/non_dominated_suffix.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/lex_minmax_suffix.test.cpp
    title: test/1_mytest/lex_minmax_suffix.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/lyndon.test.cpp
    title: test/2_library_checker/string/lyndon.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \    reverse(all(I));\n    return I;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename CHAR>\nstruct Incremental_Lyndon_Factorization\
    \ {\n  vc<CHAR> S;\n  int i = 0, j = 0, k = 0;\n  vc<int> minimum_suffix_len =\
    \ {0};\n\n  int add(CHAR c) {\n    S.eb(c);\n    // [j, j+(i-k)) simple\n    while\
    \ (i < len(S)) {\n      if (k == i) {\n        assert(j == k);\n        ++i;\n\
    \      }\n      elif (S[k] == S[i]) { ++k, ++i; }\n      elif (S[k] < S[i]) {\
    \ k = j, ++i; }\n      else {\n        j += (i - j) / (i - k) * (i - k);\n   \
    \     i = k = j;\n      }\n    }\n    if ((i - j) % (i - k) == 0) {\n      minimum_suffix_len.eb(i\
    \ - k);\n    } else {\n      minimum_suffix_len.eb(minimum_suffix_len[k]);\n \
    \   }\n    return minimum_suffix_len[i];\n  }\n\n  vc<int> factorize() {\n   \
    \ int i = len(S);\n    vc<int> I;\n    while (i) {\n      I.eb(i);\n      i -=\
    \ minimum_suffix_len[i];\n    }\n    I.eb(0);\n    reverse(all(I));\n    return\
    \ I;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/lyndon.hpp
  requiredBy:
  - string/lex_min_suffix_for_all_prefix.hpp
  - string/non_dominated_suffix.hpp
  timestamp: '2025-05-18 18:12:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/string/lyndon.test.cpp
  - test/1_mytest/lex_minmax_suffix.test.cpp
documentation_of: string/lyndon.hpp
layout: document
redirect_from:
- /library/string/lyndon.hpp
- /library/string/lyndon.hpp.html
title: string/lyndon.hpp
---
