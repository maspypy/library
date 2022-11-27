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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/mul.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc276/tasks/abc276_g\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"poly/from_log_differentiation.hpp\"\n#include \"poly/sum_of_rationals.hpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, M);\n  --N;\n  M -= N;\n\
    \  if (M < 0) return print(0);\n  using poly = vc<mint>;\n  vc<pair<poly, poly>>\
    \ rationals;\n  rationals.eb(poly{N}, poly{1, 1});\n  rationals.eb(poly{2, 2,\
    \ 3 * N + 2}, poly{1, 0, 0, -1});\n  auto [a, b] = sum_of_rationals(rationals);\n\
    \  /*\n  vvc<mint> c(5);\n  int r = 4;\n  FOR(i, r + 1) {\n    mint c0 = 0, c1\
    \ = 0;\n    if (i < len(a)) c0 += mint(r - i) * a[i];\n    if (i < len(a)) c1\
    \ += a[i];\n    if (0 <= i - 1 && i - 1 < len(b)) c0 += b[i - 1];\n    c[i] =\
    \ {c0, c1};\n  }\n  mint ANS = kth_term_of_p_recursive(f, c, M);\n  print(ANS);\n\
    \  */\n  auto f = from_log_differentiation(M, a, b);\n  print(f[M]);\n}\n\nsigned\
    \ main() { solve(); }"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc276_g.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc276_g.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc276_g.test.cpp
- /verify/test/atcoder/abc276_g.test.cpp.html
title: test/atcoder/abc276_g.test.cpp
---
