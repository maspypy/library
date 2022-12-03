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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/offline_query/parallel_binary_search.hpp\"\
    \n#include \"ds/fenwick/fenwick.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll,\
    \ A, N);\n  using QT = tuple<ll, ll, ll>;\n  VEC(QT, query, Q);\n\n  auto I =\
    \ argsort(A);\n  FenwickTree<Monoid_Add<int>> bit(N);\n  auto init = [&]() ->\
    \ void { bit.reset(N); };\n  auto upd = [&](int t) -> void { bit.add(I[t], 1);\
    \ };\n  auto check = [&](int q) -> bool {\n    auto [l, r, k] = query[q];\n  \
    \  int x = bit.sum(l, r);\n    return x > k;\n  };\n  auto OK = parallel_binary_search(Q,\
    \ N, 0, init, upd, check);\n  FOR(q, Q) {\n    int t = OK[q];\n    print(A[I[t\
    \ - 1]]);\n  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
- /verify/test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp.html
title: test/library_checker/datastructure/range_kth_smallest_pbs.test.cpp
---
