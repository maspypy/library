---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/online/online_convolution.hpp
    title: poly/online/online_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/simple_perm.test.cpp
    title: test/mytest/simple_perm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://oeis.org/A059372
    - https://oeis.org/A111111
  bundledCode: "#line 2 \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>&\
    \ a, bool inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  static bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\
    \n    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\
    \n    FOR_R(i, rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n    \
    \  iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod\
    \ = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i\
    \ + 2] * prod;\r\n      irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i\
    \ + 2];\r\n      iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] *\
    \ prod;\r\n      irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i +\
    \ 3];\r\n      iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\
    \n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 3 \"poly/online/online_convolution.hpp\"\n\n/*\nquery(i)\uFF1A\
    a[i], b[i] \u3092\u4E0E\u3048\u3066 ab[i] \u3092\u5F97\u308B\u3002\n2^{17}\uFF1A\
    127ms\n2^{18}\uFF1A277ms\n2^{19}\uFF1A570ms\n2^{20}\uFF1A1220ms\n*/\ntemplate\
    \ <class mint>\nstruct Online_Convolution {\n  vc<mint> f, g, h, b0, b1;\n  vvc<mint>\
    \ fm, gm;\n  int p;\n\n  Online_Convolution() : p(0) { assert(mint::can_ntt());\
    \ }\n\n  mint query(int i, mint f_i, mint g_i) {\n    assert(i == p);\n    f.eb(f_i),\
    \ g.eb(g_i);\n    int z = __builtin_ctz(p + 2), w = 1 << z, s;\n    if (p + 2\
    \ == w) {\n      b0 = f, b0.resize(2 * w);\n      ntt(b0, false);\n      fm.eb(b0.begin(),\
    \ b0.begin() + w);\n      b1 = g, b1.resize(2 * w);\n      ntt(b1, false);\n \
    \     gm.eb(b1.begin(), b1.begin() + w);\n      FOR(i, 2 * w) b0[i] *= b1[i];\n\
    \      s = w - 2;\n      h.resize(2 * s + 2);\n    } else {\n      b0.assign(f.end()\
    \ - w, f.end()), b0.resize(2 * w);\n      ntt(b0, false);\n      FOR(i, 2 * w)\
    \ b0[i] *= gm[z][i];\n      b1.assign(g.end() - w, g.end()), b1.resize(2 * w);\n\
    \      ntt(b1, false);\n      FOR(i, 2 * w) b0[i] += b1[i] * fm[z][i];\n     \
    \ s = w - 1;\n    }\n    ntt(b0, true);\n    FOR(i, s + 1) h[p + i] += b0[s +\
    \ i];\n    return h[p++];\n  }\n};\n#line 2 \"seq/famous/simple_permutations.hpp\"\
    \n\n// https://oeis.org/A059372 sum_{n>0} n!x^n \u306E\u9006\u95A2\u6570\ntemplate\
    \ <typename mint>\nvc<mint> revert_transform_of_factorials(const int N) {\n  //\
    \ xQ' = Q^2 + (1+x)Q'Q\n  // R = Q^2 \u3068\u3057\u3066\u3001xQ' = R + 1/2 (1+x)R'\n\
    \  // [x^n] \u3092\u898B\u308B\u3068\u3001nQn = Rn + 1/2(n+1)R_{n+1} + 1/2 nR_n\
    \ \u306E\u5F62\n  //\n  // Q = x + x^2F \u3068\u3059\u308C\u3070 F_{n-3} \u307E\
    \u3067\u5206\u304B\u3063\u305F\u6642\u70B9\u3067\n  // Q_{n-1}, R_n \u307E\u3067\
    \u78BA\u5B9A\u3002R = x^2+x^4F^2+2x^3F \u3068\u3057\u3066\u3001\n  // Q_n = F_{n-2},\
    \ R_{n+1} = (\u78BA\u5B9A) + 2F_{n-2} \u306E\u5F62\n  vc<mint> Q(N + 1), R(N +\
    \ 2);\n  Q[1] = 1, R[2] = 1;\n  vc<mint> F(N - 1), FF(N - 1);\n  Online_Convolution<mint>\
    \ X;\n  FOR(n, 2, N + 1) {\n    mint x = R[n] + mint(n) * inv<mint>(2) * R[n];\n\
    \    if (n >= 3) x += mint(n + 1) * FF[n - 3] * inv<mint>(2);\n    Q[n] = F[n\
    \ - 2] = -x;\n    FF[n - 2] = X.query(n - 2, x, x);\n    if (n + 1 >= 4) R[n +\
    \ 1] += FF[n + 1 - 4];\n    R[n + 1] += mint(2) * F[n - 2];\n  }\n  return Q;\n\
    }\n\n// https://oeis.org/A111111\n// \u305F\u3060\u3057\u3001n=1, 2 \u306B\u5BFE\
    \u3057\u3066\u306F 0 \u3092\u8FD4\u3059\u3088\u3046\u306B\u3057\u3066\u3044\u308B\
    \ntemplate <typename mint>\nvc<mint> simple_permutations(const int N) {\n  vc<mint>\
    \ S = revert_transform_of_factorials<mint>(N);\n  for (auto&& x: S) x = -x;\n\
    \  S[1] += mint(1);\n  FOR(i, 2, N + 1) {\n    if (i % 2 == 0) S[i] -= 2;\n  \
    \  if (i % 2 == 1) S[i] += 2;\n  }\n  return S;\n}\n"
  code: "#include \"poly/online/online_convolution.hpp\"\n\n// https://oeis.org/A059372\
    \ sum_{n>0} n!x^n \u306E\u9006\u95A2\u6570\ntemplate <typename mint>\nvc<mint>\
    \ revert_transform_of_factorials(const int N) {\n  // xQ' = Q^2 + (1+x)Q'Q\n \
    \ // R = Q^2 \u3068\u3057\u3066\u3001xQ' = R + 1/2 (1+x)R'\n  // [x^n] \u3092\u898B\
    \u308B\u3068\u3001nQn = Rn + 1/2(n+1)R_{n+1} + 1/2 nR_n \u306E\u5F62\n  //\n \
    \ // Q = x + x^2F \u3068\u3059\u308C\u3070 F_{n-3} \u307E\u3067\u5206\u304B\u3063\
    \u305F\u6642\u70B9\u3067\n  // Q_{n-1}, R_n \u307E\u3067\u78BA\u5B9A\u3002R =\
    \ x^2+x^4F^2+2x^3F \u3068\u3057\u3066\u3001\n  // Q_n = F_{n-2}, R_{n+1} = (\u78BA\
    \u5B9A) + 2F_{n-2} \u306E\u5F62\n  vc<mint> Q(N + 1), R(N + 2);\n  Q[1] = 1, R[2]\
    \ = 1;\n  vc<mint> F(N - 1), FF(N - 1);\n  Online_Convolution<mint> X;\n  FOR(n,\
    \ 2, N + 1) {\n    mint x = R[n] + mint(n) * inv<mint>(2) * R[n];\n    if (n >=\
    \ 3) x += mint(n + 1) * FF[n - 3] * inv<mint>(2);\n    Q[n] = F[n - 2] = -x;\n\
    \    FF[n - 2] = X.query(n - 2, x, x);\n    if (n + 1 >= 4) R[n + 1] += FF[n +\
    \ 1 - 4];\n    R[n + 1] += mint(2) * F[n - 2];\n  }\n  return Q;\n}\n\n// https://oeis.org/A111111\n\
    // \u305F\u3060\u3057\u3001n=1, 2 \u306B\u5BFE\u3057\u3066\u306F 0 \u3092\u8FD4\
    \u3059\u3088\u3046\u306B\u3057\u3066\u3044\u308B\ntemplate <typename mint>\nvc<mint>\
    \ simple_permutations(const int N) {\n  vc<mint> S = revert_transform_of_factorials<mint>(N);\n\
    \  for (auto&& x: S) x = -x;\n  S[1] += mint(1);\n  FOR(i, 2, N + 1) {\n    if\
    \ (i % 2 == 0) S[i] -= 2;\n    if (i % 2 == 1) S[i] += 2;\n  }\n  return S;\n\
    }\n"
  dependsOn:
  - poly/online/online_convolution.hpp
  - poly/ntt.hpp
  isVerificationFile: false
  path: seq/famous/simple_permutations.hpp
  requiredBy: []
  timestamp: '2023-08-20 01:21:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/simple_perm.test.cpp
documentation_of: seq/famous/simple_permutations.hpp
layout: document
redirect_from:
- /library/seq/famous/simple_permutations.hpp
- /library/seq/famous/simple_permutations.hpp.html
title: seq/famous/simple_permutations.hpp
---
