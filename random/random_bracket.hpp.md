---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 2 \"random/random_bracket.hpp\"\
    \n\n// return: +1,-1 \u306E\u5217\nvc<int> random_bracket(int N) {\n  vc<int>\
    \ A(2 * N + 1);\n  FOR(i, N + 1) A[i] = 1;\n  FOR(i, N + 1, 2 * N + 1) A[i] =\
    \ -1;\n  shuffle(A);\n  vc<int> B(2 * N + 2);\n  FOR(i, 2 * N + 1) B[i + 1] =\
    \ B[i] + A[i];\n  int k = 0;\n  FOR(i, 2 * N + 1) if (B[k] >= B[i]) k = i;\n \
    \ rotate(A.begin(), A.begin() + k, A.end());\n  return A;\n}\n"
  code: "#include \"random/shuffle.hpp\"\n\n// return: +1,-1 \u306E\u5217\nvc<int>\
    \ random_bracket(int N) {\n  vc<int> A(2 * N + 1);\n  FOR(i, N + 1) A[i] = 1;\n\
    \  FOR(i, N + 1, 2 * N + 1) A[i] = -1;\n  shuffle(A);\n  vc<int> B(2 * N + 2);\n\
    \  FOR(i, 2 * N + 1) B[i + 1] = B[i] + A[i];\n  int k = 0;\n  FOR(i, 2 * N + 1)\
    \ if (B[k] >= B[i]) k = i;\n  rotate(A.begin(), A.begin() + k, A.end());\n  return\
    \ A;\n}\n"
  dependsOn:
  - random/shuffle.hpp
  - random/base.hpp
  isVerificationFile: false
  path: random/random_bracket.hpp
  requiredBy: []
  timestamp: '2026-02-10 00:06:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random_bracket.hpp
layout: document
redirect_from:
- /library/random/random_bracket.hpp
- /library/random/random_bracket.hpp.html
title: random/random_bracket.hpp
---
