---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/online_square.test.cpp
    title: test/1_mytest/online_square.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2801.test.cpp
    title: test/3_yukicoder/2801.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid ntt(vector<mint>&\
    \ a, bool inverse) {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n\
    \  const u32 mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n \
    \ static array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\
    \n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static u32 prepared_mod\
    \ = 0;\n  if (prepared_mod != mod) {\n    prepared_mod = mod;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 2 \"poly/online/online_square.hpp\"\n\n\
    /*\nquery(i)\uFF1Aa[i]] \u3092\u4E0E\u3048\u3066 (a^2)[i] \u3092\u5F97\u308B\u3002\
    \n2^{17}\uFF1A52ms\n2^{18}\uFF1A107ms\n2^{19}\uFF1A237ms\n2^{20}\uFF1A499ms\n\
    */\ntemplate <class mint>\nstruct Online_Square {\n  vc<mint> f, h, b0, b1;\n\
    \  vvc<mint> fm;\n  int p;\n\n  Online_Square() : p(0) { assert(mint::can_ntt());\
    \ }\n\n  mint query(int i, mint f_i) {\n    assert(i == p);\n    f.eb(f_i);\n\
    \    int z = __builtin_ctz(p + 2), w = 1 << z, s;\n    if (p + 2 == w) {\n   \
    \   b0 = f, b0.resize(2 * w);\n      ntt(b0, false);\n      fm.eb(b0.begin(),\
    \ b0.begin() + w);\n      FOR(i, 2 * w) b0[i] *= b0[i];\n      s = w - 2;\n  \
    \    h.resize(2 * s + 2);\n    } else {\n      b0.assign(f.end() - w, f.end()),\
    \ b0.resize(2 * w);\n      ntt(b0, false);\n      FOR(i, 2 * w) b0[i] *= mint(2)\
    \ * fm[z][i];\n      s = w - 1;\n    }\n    ntt(b0, true);\n    FOR(i, s + 1)\
    \ h[p + i] += b0[s + i];\n    return h[p++];\n  }\n};\n"
  code: "#include \"poly/ntt.hpp\"\n\n/*\nquery(i)\uFF1Aa[i]] \u3092\u4E0E\u3048\u3066\
    \ (a^2)[i] \u3092\u5F97\u308B\u3002\n2^{17}\uFF1A52ms\n2^{18}\uFF1A107ms\n2^{19}\uFF1A\
    237ms\n2^{20}\uFF1A499ms\n*/\ntemplate <class mint>\nstruct Online_Square {\n\
    \  vc<mint> f, h, b0, b1;\n  vvc<mint> fm;\n  int p;\n\n  Online_Square() : p(0)\
    \ { assert(mint::can_ntt()); }\n\n  mint query(int i, mint f_i) {\n    assert(i\
    \ == p);\n    f.eb(f_i);\n    int z = __builtin_ctz(p + 2), w = 1 << z, s;\n \
    \   if (p + 2 == w) {\n      b0 = f, b0.resize(2 * w);\n      ntt(b0, false);\n\
    \      fm.eb(b0.begin(), b0.begin() + w);\n      FOR(i, 2 * w) b0[i] *= b0[i];\n\
    \      s = w - 2;\n      h.resize(2 * s + 2);\n    } else {\n      b0.assign(f.end()\
    \ - w, f.end()), b0.resize(2 * w);\n      ntt(b0, false);\n      FOR(i, 2 * w)\
    \ b0[i] *= mint(2) * fm[z][i];\n      s = w - 1;\n    }\n    ntt(b0, true);\n\
    \    FOR(i, s + 1) h[p + i] += b0[s + i];\n    return h[p++];\n  }\n};\n"
  dependsOn:
  - poly/ntt.hpp
  isVerificationFile: false
  path: poly/online/online_square.hpp
  requiredBy: []
  timestamp: '2026-09-28 10:13:21+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/online_square.test.cpp
  - test/3_yukicoder/2801.test.cpp
documentation_of: poly/online/online_square.hpp
layout: document
redirect_from:
- /library/poly/online/online_square.hpp
- /library/poly/online/online_square.hpp.html
title: poly/online/online_square.hpp
---
