---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1167.test.cpp
    title: test/yukicoder/1167.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc223h.test.cpp
    title: test_atcoder/abc223h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/offline_query/range_xor_basis_query.hpp\"\n\n// \u5217\
    \u3082\u30AF\u30A8\u30EA\u3082 static\ntemplate <typename INT_TYPE, int LOG>\n\
    struct Range_Xor_Basis_Query {\n  int n;\n  int Q;\n  vc<INT_TYPE>& A;\n  vvc<pair<int,\
    \ int>> QUERY;\n\n  Range_Xor_Basis_Query(vc<INT_TYPE>& A) : n(len(A)), Q(0),\
    \ A(A) {\n    QUERY.resize(n + 1);\n  }\n\n  // \u30AF\u30A8\u30EA\u8FFD\u52A0\
    \u3002\n  void query(int L, int R) {\n    assert(0 <= L && L <= R && R <= n);\n\
    \    QUERY[R].eb(Q++, L);\n  }\n\n  // \u95A2\u6570 F(qid, basis) \u3092\u6E21\
    \u3059\n  template <typename CALC>\n  void calc(CALC F) {\n    using P = pair<INT_TYPE,\
    \ int>;\n    array<P, LOG> d;\n    FOR(k, LOG) d[k] = {INT_TYPE(1) << k, -1};\n\
    \    vc<INT_TYPE> basis;\n    FOR(i, n + 1) {\n      for (auto&& [qid, L]: QUERY[i])\
    \ {\n        basis.clear();\n        FOR_R(k, LOG) if (d[k].se >= L) basis.eb(d[k].fi);\n\
    \        F(qid, basis);\n      }\n      if (i == n) break;\n      P p = {A[i],\
    \ i};\n      FOR_R(k, LOG) {\n        if (!(p.fi >> k & 1)) continue;\n      \
    \  if (p.se > d[k].se) swap(p, d[k]);\n        p.fi ^= d[k].fi;\n      }\n   \
    \ }\n  }\n};\n"
  code: "#pragma once\n\n// \u5217\u3082\u30AF\u30A8\u30EA\u3082 static\ntemplate\
    \ <typename INT_TYPE, int LOG>\nstruct Range_Xor_Basis_Query {\n  int n;\n  int\
    \ Q;\n  vc<INT_TYPE>& A;\n  vvc<pair<int, int>> QUERY;\n\n  Range_Xor_Basis_Query(vc<INT_TYPE>&\
    \ A) : n(len(A)), Q(0), A(A) {\n    QUERY.resize(n + 1);\n  }\n\n  // \u30AF\u30A8\
    \u30EA\u8FFD\u52A0\u3002\n  void query(int L, int R) {\n    assert(0 <= L && L\
    \ <= R && R <= n);\n    QUERY[R].eb(Q++, L);\n  }\n\n  // \u95A2\u6570 F(qid,\
    \ basis) \u3092\u6E21\u3059\n  template <typename CALC>\n  void calc(CALC F) {\n\
    \    using P = pair<INT_TYPE, int>;\n    array<P, LOG> d;\n    FOR(k, LOG) d[k]\
    \ = {INT_TYPE(1) << k, -1};\n    vc<INT_TYPE> basis;\n    FOR(i, n + 1) {\n  \
    \    for (auto&& [qid, L]: QUERY[i]) {\n        basis.clear();\n        FOR_R(k,\
    \ LOG) if (d[k].se >= L) basis.eb(d[k].fi);\n        F(qid, basis);\n      }\n\
    \      if (i == n) break;\n      P p = {A[i], i};\n      FOR_R(k, LOG) {\n   \
    \     if (!(p.fi >> k & 1)) continue;\n        if (p.se > d[k].se) swap(p, d[k]);\n\
    \        p.fi ^= d[k].fi;\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/range_xor_basis_query.hpp
  requiredBy: []
  timestamp: '2023-01-23 16:19:24+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1167.test.cpp
  - test_atcoder/abc223h.test.cpp
documentation_of: ds/offline_query/range_xor_basis_query.hpp
layout: document
redirect_from:
- /library/ds/offline_query/range_xor_basis_query.hpp
- /library/ds/offline_query/range_xor_basis_query.hpp.html
title: ds/offline_query/range_xor_basis_query.hpp
---
