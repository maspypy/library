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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/mod_sqrt.hpp\"\n#include \"nt/primetest.hpp\"\n#include \"\
    mod/primitive_root.hpp\"\n\n// a[i]+a[j] \u304C distinct \u306B\u306A\u308B\u3088\
    \u3046\u306B a[i] \u3092\u4F5C\u308B\n// [0,p(p-1)) \u306B p-1 \u500B\u3068\u3044\
    \u3046\u7C21\u5358\u306A\u65B9\u6CD5\u304C\u3042\u308B.\nstruct Sidon_Sequence\
    \ {\n  u32 N, p, r;\n  // positive \u306B\u3057\u305F\n  vc<u32> exp, log;\n \
    \ vc<u64> A;\n\n  Sidon_Sequence(u32 N) : N(N) {\n    p = max<ll>(3, N + 1);\n\
    \    while (!primetest(p)) ++p;\n    exp.resize(p - 1);\n    log.resize(p);\n\
    \    u32 r = primitive_root(p);\n    exp[0] = 1;\n    FOR(i, p - 2) exp[i + 1]\
    \ = exp[i] * u64(r) % p;\n    FOR(i, p - 1) log[exp[i]] = i;\n    A.resize(N);\n\
    \    for (u32 i = 0; i < N; ++i) {\n      u64 a = i;\n      u64 b = exp[i];\n\
    \      u64 t = (a < b ? a - b + p - 1 : a - b);\n      A[i] = (b + t * p) % (u64(p)\
    \ * (p - 1));\n    }\n  }\n\n  u64 operator[](int i) { return A[i]; }\n\n  pair<int,\
    \ int> query(u64 val) {\n    u64 prod = exp[val % (p - 1)];\n    u64 sm = val\
    \ % p;\n    u64 sq = (sm * sm + 4 * (p - prod)) % p;\n    if (log[sq] & 1) return\
    \ {-1, -1};\n    assert(log[sq] % 2 == 0);\n    u64 k = log[sq] / 2;\n    u32\
    \ x = sm + exp[k], y = sm + p - exp[k];\n    x += (x & 1) * p, y += (y & 1) *\
    \ p;\n    x = x / 2 % p, y = y / 2 % p;\n    x = log[x], y = log[y];\n    if (x\
    \ < N && y < N && A[x] + A[y] == val) return {x, y};\n    return {-1, -1};\n \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/sidon_sequence.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/sidon_sequence.hpp
layout: document
redirect_from:
- /library/seq/sidon_sequence.hpp
- /library/seq/sidon_sequence.hpp.html
title: seq/sidon_sequence.hpp
---
