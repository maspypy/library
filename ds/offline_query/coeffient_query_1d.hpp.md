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
  bundledCode: "#line 1 \"ds/offline_query/coeffient_query_1d.hpp\"\n// A\uFF1A\u5B9A\
    \u6570\n// Sparse Laurent Polynomial f(x) \u3092\u4E0E\u3048\u308B\n// [x^p] f(x)/(1-x)^A\
    \ \u3092\u305F\u304F\u3055\u3093\u6C42\u3081\u308B\n// O(AN) \u6642\u9593\ntemplate\
    \ <int A, typename T>\nstruct Coefficient_Query_2D {\n  vc<tuple<ll, T>> F;\n\
    \  vc<ll> QUERY;\n\n  Coefficient_Query_2D() {}\n  void add(ll x, T c) { F.eb(x,\
    \ c); }\n  void query(ll p) { QUERY.eb(p); }\n\n  vc<T> calc() {\n    // x \u6607\
    \u9806\u306B\u30AF\u30A8\u30EA\u51E6\u7406\u3059\u308B\n    const int Q = len(QUERY);\n\
    \    vc<int> I(Q);\n    iota(all(I), 0);\n    sort(all(I), [&](auto& a, auto&\
    \ b) -> bool { return QUERY[a] < QUERY[b]; });\n    sort(all(F), [&](auto& a,\
    \ auto& b) -> bool { return a.se < b.se; });\n\n    array<T, A> dat{};\n    vc<T>\
    \ res(Q);\n    int ptr = 0;\n    for (auto&& qid: I) {\n      auto p = QUERY[qid];\n\
    \      // x <= p \u3068\u306A\u308B F \u306E\u52A0\u7B97\n      while (ptr < len(F)\
    \ && F[ptr].fi <= p) {\n        auto& [a, w] = F[ptr++];\n        // c(p-i+1)...(p-i+A-1)\n\
    \        vc<T> f(A);\n        f[0] = w;\n        FOR(i, A - 1) { FOR_R(j, i +\
    \ 1) f[j + 1] += f[j] * T(-a + 1 + i); }\n        reverse(all(f));\n        FOR(i,\
    \ len(f)) dat[i] += f[i];\n      }\n      T sm = 0;\n      T pow_p = 1;\n    \
    \  FOR(i, A) {\n        sm += pow_p * dat[i];\n        pow_p *= T(p);\n      }\n\
    \      res[qid] = sm;\n    }\n    return res;\n  }\n};\n"
  code: "// A\uFF1A\u5B9A\u6570\n// Sparse Laurent Polynomial f(x) \u3092\u4E0E\u3048\
    \u308B\n// [x^p] f(x)/(1-x)^A \u3092\u305F\u304F\u3055\u3093\u6C42\u3081\u308B\
    \n// O(AN) \u6642\u9593\ntemplate <int A, typename T>\nstruct Coefficient_Query_2D\
    \ {\n  vc<tuple<ll, T>> F;\n  vc<ll> QUERY;\n\n  Coefficient_Query_2D() {}\n \
    \ void add(ll x, T c) { F.eb(x, c); }\n  void query(ll p) { QUERY.eb(p); }\n\n\
    \  vc<T> calc() {\n    // x \u6607\u9806\u306B\u30AF\u30A8\u30EA\u51E6\u7406\u3059\
    \u308B\n    const int Q = len(QUERY);\n    vc<int> I(Q);\n    iota(all(I), 0);\n\
    \    sort(all(I), [&](auto& a, auto& b) -> bool { return QUERY[a] < QUERY[b];\
    \ });\n    sort(all(F), [&](auto& a, auto& b) -> bool { return a.se < b.se; });\n\
    \n    array<T, A> dat{};\n    vc<T> res(Q);\n    int ptr = 0;\n    for (auto&&\
    \ qid: I) {\n      auto p = QUERY[qid];\n      // x <= p \u3068\u306A\u308B F\
    \ \u306E\u52A0\u7B97\n      while (ptr < len(F) && F[ptr].fi <= p) {\n       \
    \ auto& [a, w] = F[ptr++];\n        // c(p-i+1)...(p-i+A-1)\n        vc<T> f(A);\n\
    \        f[0] = w;\n        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1] += f[j] *\
    \ T(-a + 1 + i); }\n        reverse(all(f));\n        FOR(i, len(f)) dat[i] +=\
    \ f[i];\n      }\n      T sm = 0;\n      T pow_p = 1;\n      FOR(i, A) {\n   \
    \     sm += pow_p * dat[i];\n        pow_p *= T(p);\n      }\n      res[qid] =\
    \ sm;\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/coeffient_query_1d.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/coeffient_query_1d.hpp
layout: document
redirect_from:
- /library/ds/offline_query/coeffient_query_1d.hpp
- /library/ds/offline_query/coeffient_query_1d.hpp.html
title: ds/offline_query/coeffient_query_1d.hpp
---
