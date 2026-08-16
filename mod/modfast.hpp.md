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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/primitive_root.hpp\"\n#include \"nt/lpf_table.hpp\"\n#include\
    \ \"ds/hashmap.hpp\"\n\ntemplate <int p>\nstruct ModFast {\n  static_assert(p\
    \ < (1 << 30));\n\n  u32 root;\n  array<u32, 65537> POW[2];\n  array<pair<u16,\
    \ u16>, 1 + (1 << 20)> FRAC;\n\n  static constexpr int K = 1 << 21;\n  array<u32,\
    \ 2 * K + 1> LOG;\n  array<u32, 2 * K + 1> INV;\n\n  ModFast() {\n    root = (p\
    \ == 998244353 ? 3 : primitive_root(p));\n    build_pow();\n    build_inv();\n\
    \    build_log();\n    build_frac();\n  }\n\n  void build_inv() {\n    INV[K +\
    \ 1] = 1;\n    for (u32 i = 2; i <= K; ++i) {\n      u64 q = (p + i - 1) / i;\n\
    \      INV[K + i] = INV[K + i * q - p] * u64(q) % p;\n    }\n    FOR(i, 1, K +\
    \ 1) INV[K - i] = p - INV[K + i];\n  }\n\n  u32 pow(u32 a, ll exp) {\n    assert(0\
    \ <= a && a < p && 0 <= exp && exp < (1 << 30));\n    if (a == 0) return (exp\
    \ == 0 ? 1 : 0);\n    return pow_r_32(log_r(a) * exp % (p - 1));\n  }\n\n  u32\
    \ pow_r_32(u32 exp) {\n    assert(0 <= exp && exp <= p - 1);\n    return u64(POW[0][exp\
    \ & 32767]) * POW[1][exp >> 15] % p;\n  }\n  u32 pow_r(ll exp) {\n    exp %= p\
    \ - 1;\n    if (exp < 0) exp += p - 1;\n    return u64(POW[0][exp & 32767]) *\
    \ POW[1][exp >> 15] % p;\n  }\n\n  // [0, 2p-2)\n  u32 log_r(u32 x) {\n    assert(1\
    \ <= x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x * b - a * p;\n\
    \    return LOG[K + t] + (p - 1) - LOG[K + b];\n  }\n\n  u32 inverse(u32 x) {\n\
    \    assert(1 <= x && x < p);\n    auto [a, b] = FRAC[x >> 10];\n    u32 t = x\
    \ * b - a * p;\n    return INV[K + t] * u64(b) % p;\n  }\n\n  template <typename\
    \ T>\n  vc<T> get_log_table(int n) {\n    assert(n <= K);\n    return {LOG.begin()\
    \ + K, LOG.begin() + K + n + 1};\n  }\n\n private:\n  void build_pow() {\n   \
    \ POW[0][0] = POW[1][0] = 1;\n    FOR(i, (1 << 15)) POW[0][i + 1] = POW[0][i]\
    \ * u64(root) % p;\n    FOR(i, (1 << 15)) POW[1][i + 1] = POW[1][i] * u64(POW[0][1\
    \ << 15]) % p;\n  }\n\n  // 0.085 sec.\n  void build_log() {\n    const int LIM\
    \ = 1 << 21;\n    auto lpf = lpf_table(LIM);\n\n    const int S = 1 << 17;\n \
    \   HashMap<u32> MP(S);\n    u32 pw = 1;\n    for (int k = 0; k < S; ++k, pw =\
    \ u64(root) * pw % p) {\n      MP[pw] = k;\n    }\n    u32 q = pow_r_32(p - 1\
    \ - S);\n    auto BSGS = [&](u32 s) -> u32 {\n      u32 ans = 0;\n      while\
    \ (1) {\n        u32 v = MP.get(s, -1);\n        if (v != u32(-1)) {\n       \
    \   return ans + v;\n        }\n        ans += S, s = u64(s) * q % p;\n      }\n\
    \      return 0;\n    };\n\n    LOG[K + 1] = 0;\n    FOR(i, 2, 1 + (1 << 21))\
    \ {\n      if (lpf[i] < i) {\n        LOG[K + i] = (LOG[K + lpf[i]] + LOG[K +\
    \ i / lpf[i]]) % (p - 1);\n        continue;\n      }\n      if (i < 100) {\n\
    \        LOG[K + i] = BSGS(i);\n        continue;\n      }\n      if (i * i >\
    \ p) {\n        auto [j, k] = divmod<int>(p, i);\n        // i = (-k)/j\n    \
    \    LOG[K + i] =\n            (LOG[K + k] + (p - 1) / 2 + (p - 1) - LOG[K + j])\
    \ % (p - 1);\n        continue;\n      }\n      while (1) {\n        u32 k = RNG(0,\
    \ p - 1);\n        u64 ans = p - 1 - k;\n        u32 x = u64(i) * pow_r_32(k)\
    \ % p;\n        auto div = [&](u32 q) -> void { x /= q, ans += LOG[K + q]; };\n\
    \        for (u32 q : {2, 3, 5, 7, 11, 13, 17, 19}) {\n          while (x % q\
    \ == 0) div(q);\n        }\n        if (x >= LIM) continue;\n        while (i\
    \ < x && x < LIM && lpf[x] < i) div(lpf[x]);\n        if (1 < x && x < i) div(x);\n\
    \        if (x == 1) {\n          LOG[K + i] = ans % (p - 1);\n          break;\n\
    \        }\n      }\n    }\n    FOR(i, 1, 1 + (1 << 21)) {\n      LOG[K - i] =\
    \ (LOG[K + i] + (p - 1) / 2) % (p - 1);\n    }\n  }\n\n  void build_frac() {\n\
    \    vc<tuple<u16, u16, u16, u16>> que;\n    que.eb(0, 1, 1, 1);\n    while (len(que))\
    \ {\n      auto [a, b, c, d] = POP(que);\n      if (b + d < 2048) {\n        que.eb(a\
    \ + c, b + d, c, d), que.eb(a, b, a + c, b + d);\n        continue;\n      }\n\
    \      u32 s = (u64(a) * p) / (1024 * b);\n      u32 t = (u64(c) * p) / (1024\
    \ * d);\n      FRAC[s] = {a, b}, FRAC[t] = {c, d};\n      a = min(a, c), b = min(b,\
    \ d);\n      FOR(i, s + 1, t) FRAC[i] = {a, b};\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/modfast.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/modfast.hpp
layout: document
redirect_from:
- /library/mod/modfast.hpp
- /library/mod/modfast.hpp.html
title: mod/modfast.hpp
---
