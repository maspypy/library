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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/my_bitset.hpp\"\n\n// Method of Four Russians O(NMK/wlogN)\n\
    // (N1/K+2^K)/K N2 N3 / w\nvc<Bit_Array> matrix_mul_mod_2(vc<Bit_Array>& A, vc<Bit_Array>&\
    \ B, int N1 = -1, int N2 = -1, int N3 = -1) {\n  using BS = Bit_Array;\n  if (N1\
    \ == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }\n  vc<BS> C(N1, BS(N3));\n\
    \  if (N1 < 50) {\n    FOR(i, N1) FOR(j, N2) {\n      if (A[i][j]) C[i] ^= B[j];\n\
    \    }\n    return C;\n  }\n  const int K = (N1 < 1200 ? 4 : 8);\n  vc<BS> tmp(1\
    \ << K, BS(N3));\n\n  for (int L = 0; L < N2; L += K) {\n    int R = min(L + K,\
    \ N2);\n    int n = R - L;\n    FOR(i, n) FOR(s, 1 << i) tmp[s | 1 << i] = tmp[s]\
    \ ^ B[L + i];\n    FOR(i, N1) {\n      u32 s = A[i].dat[L / 64] >> (L & 63) &\
    \ ((1 << K) - 1);\n      C[i] ^= tmp[s];\n    }\n  }\n  return C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/bitset/matrix_mul_mod_2.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/bitset/matrix_mul_mod_2.hpp
layout: document
redirect_from:
- /library/linalg/bitset/matrix_mul_mod_2.hpp
- /library/linalg/bitset/matrix_mul_mod_2.hpp.html
title: linalg/bitset/matrix_mul_mod_2.hpp
---
