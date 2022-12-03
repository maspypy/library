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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/func/slope.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/func/slope.hpp\"\n\n// \u5EA7\u6A19 0, ..., N-1 \u306B A_i\
    \ \u500B\u3042\u308B\n// \u5EA7\u6A19 0, ..., N-1 \u3067 B_i \u500B\u307E\u3067\
    \u53D7\u3051\u5165\u308C\u3089\u308C\u308B\nll min_cost_matching_on_line_1(vi\
    \ A, vi B) {\n  assert(SUM<ll>(A) <= SUM<ll>(B));\n  const int N = len(A);\n \
    \ Slope_Trick f(vi(N + 1, 0), vi());\n  FOR(i, N) {\n    ll c = A[i] - B[i];\n\
    \    f.shift(c);\n    f.clear_right();\n    f.add_abs(0);\n  }\n  return f.eval(0);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/min_cost_matching_on_line.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/min_cost_matching_on_line.hpp
layout: document
redirect_from:
- /library/flow/min_cost_matching_on_line.hpp
- /library/flow/min_cost_matching_on_line.hpp.html
title: flow/min_cost_matching_on_line.hpp
---
