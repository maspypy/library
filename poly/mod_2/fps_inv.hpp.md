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
    - https://github.com/maspypy/library/blob/main/poly/mod_2/fps_inv.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/poly/mod_2/fps_inv.hpp\n\
    #include \"poly/mod_2/convolution.hpp\"\n\nBit_Array fps_inv(const Bit_Array&\
    \ F) {\n  if (len(F) == 0) return F;\n  assert(F[0]);\n  auto dfs = [&](auto&\
    \ dfs, int n) -> Bit_Array {\n    // 1/f \u3092 [0,n] \u3067\u6C42\u3081\u308B\
    \n    if (n == 0) {\n      return Bit_Array(1, 1);\n    }\n    int m = n / 2;\n\
    \    Bit_Array g = dfs(dfs, m);\n    Bit_Array gg(n + 1);\n    FOR(i, g.size())\
    \ {\n      if (2 * i <= n) gg[2 * i] = g[i];\n    }\n    Bit_Array h = F.slice(0,\
    \ n + 1);\n    g = convolution(gg, h);\n    g.resize(n + 1);\n    return g;\n\
    \  };\n  return dfs(dfs, F.size() - 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/mod_2/fps_inv.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/mod_2/fps_inv.hpp
layout: document
redirect_from:
- /library/poly/mod_2/fps_inv.hpp
- /library/poly/mod_2/fps_inv.hpp.html
title: poly/mod_2/fps_inv.hpp
---
