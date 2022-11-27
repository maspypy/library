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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc190/tasks/abc190_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/fenwick.hpp\"\n\
    \n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\u306A\u308B\u3088\u3046\u306B\
    \ rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\u6570\ntemplate <typename\
    \ T>\nvi inversion_rotate(vc<T>& A, bool SMALL = false) {\n  const int N = len(A);\n\
    \  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n    for (auto&& x: A) x\
    \ = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS = 0;\n  FenwickTree<Group_Add<int>>\
    \ bit(K);\n  for (auto&& x: A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x,\
    \ 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n    res[i] = ANS;\n    ll x = A[i];\n\
    \    ANS = ANS + bit.prod(x + 1, K) - bit.sum(x);\n  }\n  return res;\n}\n\nvoid\
    \ solve() {\n  LL(N);\n  VEC(int, A, N);\n  vi ANS = inversion_rotate(A, true);\n\
    \  for (auto&& x: ANS) print(x);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc190f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc190f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc190f.test.cpp
- /verify/test/atcoder/abc190f.test.cpp.html
title: test/atcoder/abc190f.test.cpp
---
