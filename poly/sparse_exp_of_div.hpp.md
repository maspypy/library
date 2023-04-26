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
    \  [Previous line repeated 4 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/from_log_differentiation.hpp\"\n\n// exp(f/g) \u3067 f,g\
    \ \u304C sparse\ntemplate <typename mint>\nvc<mint> sparse_exp_of_div(int N, const\
    \ vc<mint>& f, const vc<mint>& g) {\n  assert(f[0] == mint(0));\n  assert(g[0]\
    \ == mint(1));\n  using P = pair<int, mint>;\n  vc<P> dat_f, dat_g;\n  FOR(i,\
    \ len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);\n  FOR(i, len(g)) if (g[i] !=\
    \ mint(0)) dat_g.eb(i, g[i]);\n\n  vc<mint> a(len(f) + len(g) - 2), b(2 * len(g)\
    \ - 1);\n  // a = f'g-fg', b = g^2\n  for (auto&& [i, x]: dat_f) {\n    for (auto&&\
    \ [j, y]: dat_g) { a[i + j - 1] += x * y * mint(i - j); }\n  }\n  for (auto&&\
    \ [i, x]: dat_g) {\n    for (auto&& [j, y]: dat_g) { b[i + j] += x * y; }\n  }\n\
    \  return from_log_differentiation(N, a, b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/sparse_exp_of_div.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/sparse_exp_of_div.hpp
layout: document
redirect_from:
- /library/poly/sparse_exp_of_div.hpp
- /library/poly/sparse_exp_of_div.hpp.html
title: poly/sparse_exp_of_div.hpp
---
