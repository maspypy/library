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
  code: "#include \"ds/my_bitset.hpp\"\n\n// det = 0 \u306E\u5834\u5408\u306B\u306F\
    \ empty \u3092\u304B\u3048\u3059\ntemplate <typename BS>\nvc<BS> mat_inv(vc<BS>\
    \ A) {\n  int N = len(A);\n  vc<BS> B(N);\n  if constexpr (is_same_v<BS, Bit_Array>)\
    \ { FOR(i, N) B[i] = BS(N); }\n  FOR(i, N) B[i][i] = 1;\n  FOR(i, N) {\n    FOR(k,\
    \ i + 1, N) if (A[k][i]) {\n      swap(A[k], A[i]);\n      swap(B[k], B[i]);\n\
    \      break;\n    }\n    if (!A[i][i]) return {};\n    FOR(k, N) {\n      if\
    \ (i == k) continue;\n      if (A[k][i]) {\n        if constexpr (is_same_v<BS,\
    \ Bit_Array>) {\n          A[k].xor_suffix(i, A[i]);\n          B[k] ^= B[i];\n\
    \        } else {\n          A[k] ^= A[i];\n          B[k] ^= B[i];\n        }\n\
    \      }\n    }\n  }\n  return B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/bitset/mat_inv.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/bitset/mat_inv.hpp
layout: document
redirect_from:
- /library/linalg/bitset/mat_inv.hpp
- /library/linalg/bitset/mat_inv.hpp.html
title: linalg/bitset/mat_inv.hpp
---
