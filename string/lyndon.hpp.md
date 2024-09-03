---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/lex_min_suffix_for_all_prefix.hpp
    title: string/lex_min_suffix_for_all_prefix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/lex_minmax_suffix.test.cpp
    title: test/1_mytest/lex_minmax_suffix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/lyndon.test.cpp
    title: test/2_library_checker/string/lyndon.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/lyndon.hpp\"\n\ntemplate <typename CHAR>\nstruct\
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
  code: "\ntemplate <typename CHAR>\nstruct Incremental_Lyndon_Factorization {\n \
    \ vc<CHAR> S;\n  int i = 0, j = 0, k = 0;\n  vc<int> minimum_suffix_len = {0};\n\
    \n  int add(CHAR c) {\n    S.eb(c);\n    // [j, j+(i-k)) simple\n    while (i\
    \ < len(S)) {\n      if (k == i) {\n        assert(j == k);\n        ++i;\n  \
    \    }\n      elif (S[k] == S[i]) { ++k, ++i; }\n      elif (S[k] < S[i]) { k\
    \ = j, ++i; }\n      else {\n        j += (i - j) / (i - k) * (i - k);\n     \
    \   i = k = j;\n      }\n    }\n    if ((i - j) % (i - k) == 0) {\n      minimum_suffix_len.eb(i\
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
  timestamp: '2023-11-15 20:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
