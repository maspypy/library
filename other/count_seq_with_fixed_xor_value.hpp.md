---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/count_seq_with_fixed_xor_value.hpp\"\n// [0, LIM)^N\
    \ \u306E\u3046\u3061\u3067\u3001xor = X \u3068\u306A\u308B\u3082\u306E\u306E\u500B\
    \u6570\ntemplate <typename mint>\nmint count_seq_with_fixed_xor(ll N, ll LIM,\
    \ ll X) {\n  assert(LIM >= 1);\n  --LIM; // closed\n  if (LIM == 0) return (X\
    \ == 0 ? 1 : 0);\n  int LOG = topbit(LIM) + 1;\n  if (X >> LOG) return 0;\n  mint\
    \ res = 0;\n  bool ok = 1;\n  FOR_R(k, LOG) {\n    int LIM1 = LIM >> k & 1;\n\
    \    int X1 = X >> k & 1;\n    if (LIM1) {\n      ll mk = LIM - (LIM >> k << k);\n\
    \      mint a = mint(2).pow(k), b = mk + 1;\n      tie(a, b) = mp(a + b, a - b);\n\
    \      a = a.pow(N), b = b.pow(N);\n      tie(a, b) = mp(a + b, a - b);\n    \
    \  a *= inv<mint>(2), b *= inv<mint>(2);\n      mint now = (X1 ? b : a);\n   \
    \   if ((N & 1) == X1) now -= mint(mk + 1).pow(N);\n      now /= mint(2).pow(k);\n\
    \      res += now;\n    }\n    if (LIM1 * (N & 1) != X1) {\n      ok = 0;\n  \
    \    break;\n    }\n  }\n  if (ok) res += mint(1);\n  return res;\n}\n\n// [0,\
    \ LIM)^N \u306E\u3046\u3061\u3067\u3001xor = X \u3068\u306A\u308B\u3082\u306E\u306E\
    \u500B\u6570\u3002N = 0,1,...,nmax\ntemplate <typename mint>\nvc<mint> count_seq_with_fixed_xor_iota(ll\
    \ nmax, ll LIM, ll X) {\n  assert(LIM >= 1);\n  --LIM; // closed\n  vc<mint> res(nmax\
    \ + 1);\n  if (LIM == 0) {\n    if (X == 0) fill(all(res), mint(1));\n    return\
    \ res;\n  }\n  int LOG = topbit(LIM) + 1;\n  if (X >> LOG) return res;\n  vc<bool>\
    \ ok(nmax + 1, 1);\n  mint x2 = inv<mint>(2);\n  mint px2 = x2.pow(LOG);\n  FOR_R(k,\
    \ LOG) {\n    px2 += px2;\n    int LIM1 = LIM >> k & 1;\n    int X1 = X >> k &\
    \ 1;\n    if (LIM1) {\n      ll mk = LIM - (LIM >> k << k);\n      mint a = mint(2).pow(k),\
    \ b = mk + 1;\n      tie(a, b) = mp(a + b, a - b);\n      mint pa = 1, pb = 1,\
    \ pc = 1;\n      FOR(n, nmax + 1) {\n        if (ok[n]) {\n          mint x =\
    \ (X1 ? (pa - pb) : (pa + pb)) * x2;\n          if ((n & 1) == X1) x -= pc;\n\
    \          res[n] += x * px2;\n        }\n        pa *= a, pb *= b, pc *= mint(mk\
    \ + 1);\n      }\n    }\n    FOR(n, nmax + 1) {\n      if (LIM1 * (n & 1) != X1)\
    \ { ok[n] = 0; }\n    }\n  }\n  FOR(n, nmax + 1) if (ok[n]) res[n] += mint(1);\n\
    \  return res;\n}\n"
  code: "// [0, LIM)^N \u306E\u3046\u3061\u3067\u3001xor = X \u3068\u306A\u308B\u3082\
    \u306E\u306E\u500B\u6570\ntemplate <typename mint>\nmint count_seq_with_fixed_xor(ll\
    \ N, ll LIM, ll X) {\n  assert(LIM >= 1);\n  --LIM; // closed\n  if (LIM == 0)\
    \ return (X == 0 ? 1 : 0);\n  int LOG = topbit(LIM) + 1;\n  if (X >> LOG) return\
    \ 0;\n  mint res = 0;\n  bool ok = 1;\n  FOR_R(k, LOG) {\n    int LIM1 = LIM >>\
    \ k & 1;\n    int X1 = X >> k & 1;\n    if (LIM1) {\n      ll mk = LIM - (LIM\
    \ >> k << k);\n      mint a = mint(2).pow(k), b = mk + 1;\n      tie(a, b) = mp(a\
    \ + b, a - b);\n      a = a.pow(N), b = b.pow(N);\n      tie(a, b) = mp(a + b,\
    \ a - b);\n      a *= inv<mint>(2), b *= inv<mint>(2);\n      mint now = (X1 ?\
    \ b : a);\n      if ((N & 1) == X1) now -= mint(mk + 1).pow(N);\n      now /=\
    \ mint(2).pow(k);\n      res += now;\n    }\n    if (LIM1 * (N & 1) != X1) {\n\
    \      ok = 0;\n      break;\n    }\n  }\n  if (ok) res += mint(1);\n  return\
    \ res;\n}\n\n// [0, LIM)^N \u306E\u3046\u3061\u3067\u3001xor = X \u3068\u306A\u308B\
    \u3082\u306E\u306E\u500B\u6570\u3002N = 0,1,...,nmax\ntemplate <typename mint>\n\
    vc<mint> count_seq_with_fixed_xor_iota(ll nmax, ll LIM, ll X) {\n  assert(LIM\
    \ >= 1);\n  --LIM; // closed\n  vc<mint> res(nmax + 1);\n  if (LIM == 0) {\n \
    \   if (X == 0) fill(all(res), mint(1));\n    return res;\n  }\n  int LOG = topbit(LIM)\
    \ + 1;\n  if (X >> LOG) return res;\n  vc<bool> ok(nmax + 1, 1);\n  mint x2 =\
    \ inv<mint>(2);\n  mint px2 = x2.pow(LOG);\n  FOR_R(k, LOG) {\n    px2 += px2;\n\
    \    int LIM1 = LIM >> k & 1;\n    int X1 = X >> k & 1;\n    if (LIM1) {\n   \
    \   ll mk = LIM - (LIM >> k << k);\n      mint a = mint(2).pow(k), b = mk + 1;\n\
    \      tie(a, b) = mp(a + b, a - b);\n      mint pa = 1, pb = 1, pc = 1;\n   \
    \   FOR(n, nmax + 1) {\n        if (ok[n]) {\n          mint x = (X1 ? (pa - pb)\
    \ : (pa + pb)) * x2;\n          if ((n & 1) == X1) x -= pc;\n          res[n]\
    \ += x * px2;\n        }\n        pa *= a, pb *= b, pc *= mint(mk + 1);\n    \
    \  }\n    }\n    FOR(n, nmax + 1) {\n      if (LIM1 * (n & 1) != X1) { ok[n] =\
    \ 0; }\n    }\n  }\n  FOR(n, nmax + 1) if (ok[n]) res[n] += mint(1);\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/count_seq_with_fixed_xor_value.hpp
  requiredBy: []
  timestamp: '2023-02-12 02:07:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/count_seq_with_fixed_xor_value.hpp
layout: document
redirect_from:
- /library/other/count_seq_with_fixed_xor_value.hpp
- /library/other/count_seq_with_fixed_xor_value.hpp.html
title: other/count_seq_with_fixed_xor_value.hpp
---
