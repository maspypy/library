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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"poly/convolution.hpp\"\n\n// \u6709\u7406\u5F0F\
    \u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\u5206\u5272\u7D71\u6CBB O(Nlog^2N)\u3002\
    N \u306F\u6B21\u6570\u306E\u548C\u3002\ntemplate <typename mint>\npair<vc<mint>,\
    \ vc<mint>> sum_of_rationals(vc<pair<vc<mint>, vc<mint>>> dat) {\n  if (len(dat)\
    \ == 0) {\n    vc<mint> f = {0}, g = {1};\n    return {f, g};\n  }\n  using P\
    \ = pair<vc<mint>, vc<mint>>;\n  auto add = [&](P& a, P& b) -> P {\n    int na\
    \ = len(a.fi) - 1, da = len(a.se) - 1;\n    int nb = len(b.fi) - 1, db = len(b.se)\
    \ - 1;\n    int n = max(na + db, da + nb);\n    vc<mint> num(n + 1);\n    {\n\
    \      auto f = convolution(a.fi, b.se);\n      FOR(i, len(f)) num[i] += f[i];\n\
    \    }\n    {\n      auto f = convolution(a.se, b.fi);\n      FOR(i, len(f)) num[i]\
    \ += f[i];\n    }\n    auto den = convolution(a.se, b.se);\n    return {num, den};\n\
    \  };\n\n  while (len(dat) > 1) {\n    int n = len(dat);\n    FOR(i, 1, n, 2)\
    \ { dat[i - 1] = add(dat[i - 1], dat[i]); }\n    FOR(i, ceil(n, 2)) dat[i] = dat[2\
    \ * i];\n    dat.resize(ceil(n, 2));\n  }\n  return dat[0];\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/sum_of_rationals.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/sum_of_rationals.hpp
layout: document
redirect_from:
- /library/poly/sum_of_rationals.hpp
- /library/poly/sum_of_rationals.hpp.html
title: poly/sum_of_rationals.hpp
---
