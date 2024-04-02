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
    - https://codeforces.com/problemset/problem/10/E
    - https://graal.ens-lyon.fr/~abenoit/algo09/coins2.pdf
  bundledCode: "#line 1 \"other/greedy_coin_counter_example.hpp\"\n\n// https://codeforces.com/problemset/problem/10/E\n\
    // \u6700\u5C0F\u53CD\u4F8B or -1 \u3092\u8FD4\u3059.\n// O(N^3)\nint greedy_coin_counter_example(vc<int>\
    \ A) {\n  int N = len(A);\n  UNIQUE(A);\n  reverse(all(A));\n  assert(A.back()\
    \ == 1);\n  assert(A.back() < (1 << 30));\n  /*\n  https://graal.ens-lyon.fr/~abenoit/algo09/coins2.pdf\n\
    \n  c_i\uFF1A\u964D\u9806, distinct \u3092\u4EEE\u5B9A.\n  \u4E0D\u7B49\u53F7\u306F\
    \u8F9E\u66F8\u9806\u306B\u95A2\u3059\u308B\u3082\u306E, \u6700\u9069\u3068\u306F\
    \u5927\u304D\u3055\u304C\u6700\u5C0F\u306E\u4E2D\u3067\u8F9E\u66F8\u9806\u6700\
    \u9069\uFF0E\n  M(x): \u6700\u9069\u89E3, G(x): \u8CAA\u6B32\u89E3.\n\n  \u6700\
    \u5C0F\u53CD\u4F8B w \u306E\u69CB\u9020\u3092\u8003\u3048\u308B\n  M(w)\uFF1A\
    i,...,j \u3092\u4F7F\u3046\n  G(w)\uFF1Ai-1\u4EE5\u524D\u3092\u4F55\u304B\u4F7F\
    \u3046\n  \u6700\u5C0F\u53CD\u4F8B\u3088\u308A M(w-c[j])=G(w-c[j]) \u3088\u308A\
    \ G(w-c[j]) \u306F i-1 \u4EE5\u524D\u3092\u4F7F\u308F\u306A\u3044.\n  w-c[j]<c[i-1].\n\
    \n  M(w)=M(w-c[i])+c[i]=G(w-c[i])+c[i]\n  >\n  G(c[i-1]-1-c[i])+c[i]=G(c[i-1]-1)\n\
    \  >=G(w-c[j])=M(w-c[j])\n  M(w) \u3068 M(w-c[j]) \u306E\u9593\u306A\u306E\u3067\
    \ G(c[i-1]-1) \u306F i,...,j-1 \u306B\u3064\u3044\u3066 M \u3068\u540C\u3058.\n\
    \  ----\n  \u3053\u306E\u3053\u3068\u3088\u308A i,j \u3092\u6C7A\u3081\u308B\u3068\
    \ w \u304C\u6C7A\u307E\u308B.\n  G(c[i-1]-1) \u3092\u8A08\u7B97\u3057\u3066, \u305D\
    \u306E [i,j] \u90E8\u5206\u3092\u3068\u3063\u3066\u3053\u308C\u3070\u3088\u3044\
    .\n  \u3088\u3063\u3066\u6700\u9069\u89E3\u306E\u5019\u88DC\u306F O(N^2) \u7A2E\
    \u985E\u306B\u306A\u308B.\n\n  \u672C\u5F53\u306B\u6700\u5C0F\u53CD\u4F8B\u306B\
    \u306A\u3063\u3066\u3044\u308B\u304B\u306E\u78BA\u8A8D\n  G(w): \u8A08\u7B97\n\
    \  M(w): c[i] \u3092\u4F7F\u3063\u305F\u3042\u3068 M(w-c[i])=G(w-c[i])\n  \u691C\
    \u8A3C\u3082 O(N) \u3067\u3067\u304D\u308B. \u5168\u4F53\u3067 O(N^3) \u6642\u9593\
    .\n  */\n  int ANS = -1;\n  auto upd = [&](int ans) -> void { ANS = (ANS == -1\
    \ ? ans : min(ANS, ans)); };\n  auto greedy = [&](int x) -> int {\n    int cnt\
    \ = 0;\n    FOR(i, N) cnt += x / A[i], x %= A[i];\n    return cnt;\n  };\n\n \
    \ vc<int> S(N);\n  FOR(i, 1, N) {\n    int x = A[i - 1] - 1;\n    FOR(j, i, N)\
    \ S[j] = x / A[j], x %= A[j];\n    int sm = 0, M = 0;\n    FOR(j, i, N) {\n  \
    \    sm += A[j] * S[j], M += S[j];\n      if (M + 1 < greedy(sm + A[j])) upd(sm\
    \ + A[j]);\n    }\n  }\n  return ANS;\n}\n"
  code: "\n// https://codeforces.com/problemset/problem/10/E\n// \u6700\u5C0F\u53CD\
    \u4F8B or -1 \u3092\u8FD4\u3059.\n// O(N^3)\nint greedy_coin_counter_example(vc<int>\
    \ A) {\n  int N = len(A);\n  UNIQUE(A);\n  reverse(all(A));\n  assert(A.back()\
    \ == 1);\n  assert(A.back() < (1 << 30));\n  /*\n  https://graal.ens-lyon.fr/~abenoit/algo09/coins2.pdf\n\
    \n  c_i\uFF1A\u964D\u9806, distinct \u3092\u4EEE\u5B9A.\n  \u4E0D\u7B49\u53F7\u306F\
    \u8F9E\u66F8\u9806\u306B\u95A2\u3059\u308B\u3082\u306E, \u6700\u9069\u3068\u306F\
    \u5927\u304D\u3055\u304C\u6700\u5C0F\u306E\u4E2D\u3067\u8F9E\u66F8\u9806\u6700\
    \u9069\uFF0E\n  M(x): \u6700\u9069\u89E3, G(x): \u8CAA\u6B32\u89E3.\n\n  \u6700\
    \u5C0F\u53CD\u4F8B w \u306E\u69CB\u9020\u3092\u8003\u3048\u308B\n  M(w)\uFF1A\
    i,...,j \u3092\u4F7F\u3046\n  G(w)\uFF1Ai-1\u4EE5\u524D\u3092\u4F55\u304B\u4F7F\
    \u3046\n  \u6700\u5C0F\u53CD\u4F8B\u3088\u308A M(w-c[j])=G(w-c[j]) \u3088\u308A\
    \ G(w-c[j]) \u306F i-1 \u4EE5\u524D\u3092\u4F7F\u308F\u306A\u3044.\n  w-c[j]<c[i-1].\n\
    \n  M(w)=M(w-c[i])+c[i]=G(w-c[i])+c[i]\n  >\n  G(c[i-1]-1-c[i])+c[i]=G(c[i-1]-1)\n\
    \  >=G(w-c[j])=M(w-c[j])\n  M(w) \u3068 M(w-c[j]) \u306E\u9593\u306A\u306E\u3067\
    \ G(c[i-1]-1) \u306F i,...,j-1 \u306B\u3064\u3044\u3066 M \u3068\u540C\u3058.\n\
    \  ----\n  \u3053\u306E\u3053\u3068\u3088\u308A i,j \u3092\u6C7A\u3081\u308B\u3068\
    \ w \u304C\u6C7A\u307E\u308B.\n  G(c[i-1]-1) \u3092\u8A08\u7B97\u3057\u3066, \u305D\
    \u306E [i,j] \u90E8\u5206\u3092\u3068\u3063\u3066\u3053\u308C\u3070\u3088\u3044\
    .\n  \u3088\u3063\u3066\u6700\u9069\u89E3\u306E\u5019\u88DC\u306F O(N^2) \u7A2E\
    \u985E\u306B\u306A\u308B.\n\n  \u672C\u5F53\u306B\u6700\u5C0F\u53CD\u4F8B\u306B\
    \u306A\u3063\u3066\u3044\u308B\u304B\u306E\u78BA\u8A8D\n  G(w): \u8A08\u7B97\n\
    \  M(w): c[i] \u3092\u4F7F\u3063\u305F\u3042\u3068 M(w-c[i])=G(w-c[i])\n  \u691C\
    \u8A3C\u3082 O(N) \u3067\u3067\u304D\u308B. \u5168\u4F53\u3067 O(N^3) \u6642\u9593\
    .\n  */\n  int ANS = -1;\n  auto upd = [&](int ans) -> void { ANS = (ANS == -1\
    \ ? ans : min(ANS, ans)); };\n  auto greedy = [&](int x) -> int {\n    int cnt\
    \ = 0;\n    FOR(i, N) cnt += x / A[i], x %= A[i];\n    return cnt;\n  };\n\n \
    \ vc<int> S(N);\n  FOR(i, 1, N) {\n    int x = A[i - 1] - 1;\n    FOR(j, i, N)\
    \ S[j] = x / A[j], x %= A[j];\n    int sm = 0, M = 0;\n    FOR(j, i, N) {\n  \
    \    sm += A[j] * S[j], M += S[j];\n      if (M + 1 < greedy(sm + A[j])) upd(sm\
    \ + A[j]);\n    }\n  }\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/greedy_coin_counter_example.hpp
  requiredBy: []
  timestamp: '2024-04-02 23:34:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/greedy_coin_counter_example.hpp
layout: document
redirect_from:
- /library/other/greedy_coin_counter_example.hpp
- /library/other/greedy_coin_counter_example.hpp.html
title: other/greedy_coin_counter_example.hpp
---
