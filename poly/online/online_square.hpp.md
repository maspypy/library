---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/online_square.test.cpp
    title: test/1_mytest/online_square.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2801.test.cpp
    title: test/3_yukicoder/2801.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
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
  - other/bit.hpp
  isVerificationFile: false
  path: poly/online/online_square.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
