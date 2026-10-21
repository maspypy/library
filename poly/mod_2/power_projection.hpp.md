---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/poly/mod_2/power_projection.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/poly/mod_2/power_projection.hpp\n\
    #include \"ds/bit_array.hpp\"\n#include \"poly/mod_2/convolution.hpp\"\n\n// ANS[i]\
    \ = sum_j wt[j] [x^j] f(x)^i, 0 <= i <= m\nBit_Array power_projection(Bit_Array\
    \ wt, Bit_Array f, int m) {\n  assert(f.size() == wt.size());\n  assert(m >= 0);\n\
    \n  int sz = f.size();\n  if (sz == 0) return Bit_Array(m + 1);\n\n  int N = sz\
    \ - 1;\n\n  // g[N-j] = wt[j]\n  Bit_Array g(sz);\n  FOR(j, sz) g[N - j] = wt[j];\n\
    \n  Bit_Array ANS(m + 1);\n  auto dfs = [&](auto& dfs, Bit_Array f, Bit_Array\
    \ g, int m, int i0,\n                 int step) -> void {\n    int N = f.size()\
    \ - 1;\n    /*\n    [x^N] f(x)^i g(x), 0 <= i <= m \u3092\n    ANS[i0], ANS[i0+step],\
    \ ... \u306B\u66F8\u304D\u3053\u3080\n    */\n    if (m == 0) {\n      ANS[i0]\
    \ = g[N];\n      return;\n    }\n\n    int n = N / 2;\n    {  // even case\n \
    \     Bit_Array nxtf = f.slice(0, n + 1);\n      Bit_Array nxtg(n + 1);\n    \
    \  FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];\n\n      dfs(dfs, nxtf, nxtg, m /\
    \ 2, i0, step * 2);\n    }\n    {  // odd case\n      g = convolution(f, g);\n\
    \      g.resize(N + 1);\n\n      Bit_Array nxtf = f.slice(0, n + 1);\n      Bit_Array\
    \ nxtg(n + 1);\n      FOR(i, n + 1) nxtg[n - i] = g[N - 2 * i];\n\n      dfs(dfs,\
    \ nxtf, nxtg, (m - 1) / 2, i0 + step, step * 2);\n    }\n  };\n\n  dfs(dfs, f,\
    \ g, m, 0, 1);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/mod_2/power_projection.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/mod_2/power_projection.hpp
layout: document
redirect_from:
- /library/poly/mod_2/power_projection.hpp
- /library/poly/mod_2/power_projection.hpp.html
title: poly/mod_2/power_projection.hpp
---
