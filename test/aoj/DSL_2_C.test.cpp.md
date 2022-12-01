---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/kdtree_monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/kdtree_monoid.hpp\"\
    \n\nstruct Mono {\n  using value_type = vc<int>;\n  using X = value_type;\n  static\
    \ X op(X x, X y) {\n    x.insert(x.end(), all(y));\n    return x;\n  }\n  static\
    \ X unit() { return {}; }\n  static constexpr bool commute = 1;\n};\n\nvoid solve()\
    \ {\n  LL(N);\n  vi X, Y;\n  vvc<int> idx(N);\n  FOR(i, N) {\n    LL(x, y);\n\
    \    X.eb(x);\n    Y.eb(y);\n    idx[i].eb(i);\n  }\n  KDTree_Monoid<Mono> KDT(X,\
    \ Y, idx);\n\n  LL(Q);\n  FOR(Q) {\n    LL(xl, xr, yl, yr);\n    flush();\n  \
    \  auto e = KDT.prod(xl, xr + 1, yl, yr + 1);\n    sort(all(e));\n    for (auto&&\
    \ v: e) print(v);\n    print();\n  }\n}\n\nsigned main() {\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL_2_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_C.test.cpp
- /verify/test/aoj/DSL_2_C.test.cpp.html
title: test/aoj/DSL_2_C.test.cpp
---
