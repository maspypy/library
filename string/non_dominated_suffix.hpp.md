---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/lyndon.hpp
    title: string/lyndon.hpp
  - icon: ':heavy_check_mark:'
    path: string/zalgorithm.hpp
    title: string/zalgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \    reverse(all(I));\n    return I;\n  }\n};\n#line 2 \"string/zalgorithm.hpp\"\
    \n\ntemplate <typename STRING> // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> zalgorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n#line 3 \"string/non_dominated_suffix.hpp\"\
    \n\n// suffix X,Y \u306B\u3064\u3044\u3066, Y<X \u304B\u3064 Y notin prefix(X)\
    \ \u3068\u306A\u308B Y \u304C\u306A\u3044 X \u305F\u3061.\n// \u9577\u3055\u306E\
    \u5217\u3092\u8FD4\u3059. \u4E92\u3044\u306B border \u306B\u306A\u3063\u3066\u3044\
    \u308B.\n// donimate \u3068\u3044\u3046\u547C\u79F0\u306F\u898B\u304B\u3051\u306F\
    \u3057\u305F\u3051\u3069\u6A19\u6E96\u7684\u3067\u306A\u3044\u6C17\u304C\u3059\
    \u308B\nvc<int> non_dominated_suffix(string S) {\n  // Lyndon \u306E\u3068\u3053\
    \u308D\u304C\u5019\u88DC\u306A\u306E\u3060\u304C, \u3069\u3046\u3084\u3063\u3066\
    \u8A08\u7B97\u3057\u3088\u3046.\n  // \u305F\u3076\u3093 Duval algo \u306E\u4E2D\
    \u3092\u898B\u308C\u3070\u3044\u3044\u3093\u3060\u3051\u3069\n  // \u8003\u3048\
    \u308B\u306E\u304C\u9762\u5012\u306A\u306E\u3067 Z algorithm \u3067\u5224\u5B9A\
    \u3057\u3066\u307F\u308B\u304B.\n  int N = len(S);\n  Incremental_Lyndon_Factorization<char>\
    \ LDN;\n  FOR(i, N) LDN.add(S[i]);\n  string RS = {S.rbegin(), S.rend()};\n  vc<int>\
    \ Z = zalgorithm(RS);\n\n  vc<int> ANS;\n  vc<int> cut = LDN.factorize();\n  while\
    \ (len(cut) >= 2) {\n    int r = POP(cut);\n    int l = cut.back();\n    int n\
    \ = r - l;\n    int m = N - r;\n    if (Z[n] < m) break;\n    ANS.eb(n + m);\n\
    \  }\n  return ANS;\n}\n"
  code: "#include \"string/lyndon.hpp\"\n#include \"string/zalgorithm.hpp\"\n\n//\
    \ suffix X,Y \u306B\u3064\u3044\u3066, Y<X \u304B\u3064 Y notin prefix(X) \u3068\
    \u306A\u308B Y \u304C\u306A\u3044 X \u305F\u3061.\n// \u9577\u3055\u306E\u5217\
    \u3092\u8FD4\u3059. \u4E92\u3044\u306B border \u306B\u306A\u3063\u3066\u3044\u308B\
    .\n// donimate \u3068\u3044\u3046\u547C\u79F0\u306F\u898B\u304B\u3051\u306F\u3057\
    \u305F\u3051\u3069\u6A19\u6E96\u7684\u3067\u306A\u3044\u6C17\u304C\u3059\u308B\
    \nvc<int> non_dominated_suffix(string S) {\n  // Lyndon \u306E\u3068\u3053\u308D\
    \u304C\u5019\u88DC\u306A\u306E\u3060\u304C, \u3069\u3046\u3084\u3063\u3066\u8A08\
    \u7B97\u3057\u3088\u3046.\n  // \u305F\u3076\u3093 Duval algo \u306E\u4E2D\u3092\
    \u898B\u308C\u3070\u3044\u3044\u3093\u3060\u3051\u3069\n  // \u8003\u3048\u308B\
    \u306E\u304C\u9762\u5012\u306A\u306E\u3067 Z algorithm \u3067\u5224\u5B9A\u3057\
    \u3066\u307F\u308B\u304B.\n  int N = len(S);\n  Incremental_Lyndon_Factorization<char>\
    \ LDN;\n  FOR(i, N) LDN.add(S[i]);\n  string RS = {S.rbegin(), S.rend()};\n  vc<int>\
    \ Z = zalgorithm(RS);\n\n  vc<int> ANS;\n  vc<int> cut = LDN.factorize();\n  while\
    \ (len(cut) >= 2) {\n    int r = POP(cut);\n    int l = cut.back();\n    int n\
    \ = r - l;\n    int m = N - r;\n    if (Z[n] < m) break;\n    ANS.eb(n + m);\n\
    \  }\n  return ANS;\n}\n"
  dependsOn:
  - string/lyndon.hpp
  - string/zalgorithm.hpp
  isVerificationFile: false
  path: string/non_dominated_suffix.hpp
  requiredBy: []
  timestamp: '2025-05-18 18:12:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/non_dominated_suffix.hpp
layout: document
redirect_from:
- /library/string/non_dominated_suffix.hpp
- /library/string/non_dominated_suffix.hpp.html
title: string/non_dominated_suffix.hpp
---
