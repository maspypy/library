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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group_gl2.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"alg/group_gl2.hpp\"\n\ntemplate <typename T>\nstruct\
    \ GSet_GL2_Vec {\n  using Group = Group_GL2<T>;\n  using G = typename Group::value_type;\n\
    \  using X = pair<T, T>;\n  static X act(const G &g, const X &x) {\n    return\
    \ {g[0][0] * x.fi + g[0][1] * x.se, g[1][0] * x.fi + g[1][1] * x.se};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/gset/gset_gl2_vec.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/gset/gset_gl2_vec.hpp
layout: document
redirect_from:
- /library/alg/gset/gset_gl2_vec.hpp
- /library/alg/gset/gset_gl2_vec.hpp.html
title: alg/gset/gset_gl2_vec.hpp
---
