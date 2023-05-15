---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: poly/coef_of_rational_fps.hpp
    title: poly/coef_of_rational_fps.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/bell_number_large.hpp
    title: seq/famous/bell_number_large.hpp
  - icon: ':question:'
    path: seq/interpolate_linear_rec.hpp
    title: seq/interpolate_linear_rec.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1500.test.cpp
    title: test/yukicoder/1500.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1516.test.cpp
    title: test/yukicoder/1516.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1547.test.cpp
    title: test/yukicoder/1547.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1844.test.cpp
    title: test/yukicoder/1844.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1962.test.cpp
    title: test/yukicoder/1962.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  - icon: ':x:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  - icon: ':x:'
    path: test_atcoder/agc058d2.test.cpp
    title: test_atcoder/agc058d2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
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
    \   }\r\n  }\r\n}\r\n#line 2 \"poly/ntt_doubling.hpp\"\n\ntemplate <typename mint>\n\
    void ntt_doubling(vector<mint>& a) {\n  const int rank2 = mint::ntt_info().fi;\n\
    \  static array<mint, 30> root;\n  static bool prepared = 0;\n  if (!prepared)\
    \ {\n    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n    FOR_R(i, rank2)\
    \ { root[i] = root[i + 1] * root[i + 1]; }\n  }\n\n  const int M = (int)a.size();\n\
    \  auto b = a;\n  ntt(b, 1);\n  mint r = 1, zeta = root[topbit(2 * M)];\n  FOR(i,\
    \ M) b[i] *= r, r *= zeta;\n  ntt(b, 0);\n  copy(begin(b), end(b), back_inserter(a));\n\
    }\n"
  code: "#include \"poly/ntt.hpp\"\n\ntemplate <typename mint>\nvoid ntt_doubling(vector<mint>&\
    \ a) {\n  const int rank2 = mint::ntt_info().fi;\n  static array<mint, 30> root;\n\
    \  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    FOR_R(i, rank2) { root[i] = root[i + 1] * root[i\
    \ + 1]; }\n  }\n\n  const int M = (int)a.size();\n  auto b = a;\n  ntt(b, 1);\n\
    \  mint r = 1, zeta = root[topbit(2 * M)];\n  FOR(i, M) b[i] *= r, r *= zeta;\n\
    \  ntt(b, 0);\n  copy(begin(b), end(b), back_inserter(a));\n}"
  dependsOn:
  - poly/ntt.hpp
  isVerificationFile: false
  path: poly/ntt_doubling.hpp
  requiredBy:
  - poly/coef_of_rational_fps.hpp
  - seq/interpolate_linear_rec.hpp
  - seq/famous/bell_number_large.hpp
  timestamp: '2023-05-01 17:29:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/agc058d2.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/1547.test.cpp
  - test/yukicoder/1962.test.cpp
  - test/yukicoder/1516.test.cpp
  - test/yukicoder/1844.test.cpp
  - test/yukicoder/1500.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/541.test.cpp
  - test/mytest/bell.test.cpp
  - test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: poly/ntt_doubling.hpp
layout: document
redirect_from:
- /library/poly/ntt_doubling.hpp
- /library/poly/ntt_doubling.hpp.html
title: poly/ntt_doubling.hpp
---
