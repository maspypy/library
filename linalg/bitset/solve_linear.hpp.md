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
  code: "#include \"ds/my_bitset.hpp\"\n\n// \u884C\u30D9\u30AF\u30C8\u30EB\u3092\
    \ bitset \u306B\u3059\u308B\n// (2000, 8000) \u3067 300ms \u7A0B\u5EA6\uFF08ABC276H\uFF09\
    \nvc<Bit_Array> solve_linear(int n, int m, vc<Bit_Array> A, Bit_Array b) {\n \
    \ using BS = Bit_Array;\n  assert(len(b) == n);\n  int rk = 0;\n  FOR(j, m) {\n\
    \    if (rk == n) break;\n    FOR(i, rk + 1, n) if (A[i][j]) {\n      swap(A[rk],\
    \ A[i]);\n      if (b[rk] != b[i]) b[rk] = !b[rk], b[i] = !b[i];\n      break;\n\
    \    }\n    if (!A[rk][j]) continue;\n    FOR(i, n) if (i != rk) {\n      if (A[i][j])\
    \ { b[i] = b[i] ^ b[rk], A[i] = A[i] ^ A[rk]; }\n    }\n    ++rk;\n  }\n  FOR(i,\
    \ rk, n) if (b[i]) return {};\n  vc<BS> res(1, BS(m));\n\n  vc<int> pivot(m, -1);\n\
    \  int p = 0;\n  FOR(i, rk) {\n    while (!A[i][p]) ++p;\n    res[0][p] = bool(b[i]),\
    \ pivot[p] = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    BS x(m);\n    x[j]\
    \ = 1;\n    FOR(k, j) if (pivot[k] != -1 && A[pivot[k]][j]) x[k] = 1;\n    res.eb(x);\n\
    \  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/bitset/solve_linear.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/bitset/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/bitset/solve_linear.hpp
- /library/linalg/bitset/solve_linear.hpp.html
title: linalg/bitset/solve_linear.hpp
---
