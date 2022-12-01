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
    - https://codeforces.com/contest/1436/problem/E
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree.hpp:\
    \ line -1: no such header\n"
  code: "\r\n#include \"ds/segtree.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n\r\n\
    // \u914D\u5217\u306F static\r\n// \u30AF\u30A8\u30EA\u3082\u5148\u8AAD\u307F\u3059\
    \u308B\r\n// example: https://codeforces.com/contest/1436/problem/E\r\ntemplate\
    \ <int BEGIN, typename T = ll>\r\nstruct RangeMexQuery {\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> query;\r\n\r\n  RangeMexQuery(vc<T>& A) : A(A) {}\r\n  void add(int l,\
    \ int r) { query.eb(l, r); }\r\n\r\n  vc<T> calc() {\r\n    int N = len(A);\r\n\
    \    // segtree, value -> last idx\r\n    using Mono = Monoid_Min<int>;\r\n  \
    \  vc<int> seg_raw(N + 2, -1);\r\n    SegTree<Mono> seg(seg_raw);\r\n\r\n    int\
    \ Q = len(query);\r\n    vc<T> ANS(Q);\r\n    vc<vc<int>> IDS(N + 1);\r\n    FOR(q,\
    \ Q) {\r\n      auto [L, R] = query[q];\r\n      IDS[R].eb(q);\r\n    }\r\n\r\n\
    \    FOR(i, N + 1) {\r\n      // solve query\r\n      for (auto&& q: IDS[i]) {\r\
    \n        int L = query[q].fi;\r\n        auto check = [&](int x) -> bool { return\
    \ x >= L; };\r\n        int mex = seg.max_right(check, BEGIN);\r\n        ANS[q]\
    \ = mex;\r\n      }\r\n      // update segtree\r\n      if (i < N && A[i] < N\
    \ + 2) seg.set(A[i], i);\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/range_mex_query.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/range_mex_query.hpp
layout: document
redirect_from:
- /library/ds/offline_query/range_mex_query.hpp
- /library/ds/offline_query/range_mex_query.hpp.html
title: ds/offline_query/range_mex_query.hpp
---
