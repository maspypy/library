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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fenwick.hpp\"\n\n// A, B\uFF1A\u5B9A\u6570\n// Sparse Laurent\
    \ Polynomial f(x,y) \u3092\u4E0E\u3048\u308B\n// [x^py^q] f(x,y)/(1-x)^A(1-y)^B\
    \ \u3092\u305F\u304F\u3055\u3093\u6C42\u3081\u308B\n// O(AB N logN) \u6642\u9593\
    \ntemplate <int A, int B, typename T>\nstruct Coefficient_Query_2D {\n  struct\
    \ Mono {\n    using value_type = array<T, A * B>;\n    using X = value_type;\n\
    \    static X op(X x, X y) {\n      FOR(i, A * B) x[i] += y[i];\n      return\
    \ x;\n    }\n    static constexpr X unit() { return X{}; }\n    static constexpr\
    \ bool commute = 1;\n  };\n\n  vc<tuple<ll, ll, T>> F;\n  vc<pi> QUERY;\n\n  Coefficient_Query_2D()\
    \ {}\n  void add(ll x, ll y, T c) { F.eb(x, y, c); }\n  void query(ll p, ll q)\
    \ { QUERY.eb(p, q); }\n\n  // \u6700\u5F8C\u306B (A-1)!(B-1)! \u3067\u5272\u308B\
    \u304B\u3069\u3046\u304B\u3002\u3075\u3064\u3046\u306F\u5272\u308B\u3002\n  vc<T>\
    \ calc(bool div_fact = true) {\n    // \u52A0\u7B97\u3059\u308B\u70B9\u306E x\
    \ \u306B\u3064\u3044\u3066\u5EA7\u5727\n    sort(all(F),\n         [&](auto& a,\
    \ auto& b) -> bool { return get<0>(a) < get<0>(b); });\n    vi keyX;\n    keyX.reserve(len(F));\n\
    \    for (auto&& [a, b, c]: F) {\n      if (keyX.empty() || keyX.back() != a)\
    \ keyX.eb(a);\n      a = len(keyX) - 1;\n    }\n    keyX.shrink_to_fit();\n\n\
    \    // y \u6607\u9806\u306B\u30AF\u30A8\u30EA\u51E6\u7406\u3059\u308B\n    const\
    \ int Q = len(QUERY);\n    vc<int> I(Q);\n    iota(all(I), 0);\n    sort(all(I),\n\
    \         [&](auto& a, auto& b) -> bool { return QUERY[a].se < QUERY[b].se; });\n\
    \    sort(all(F),\n         [&](auto& a, auto& b) -> bool { return get<1>(a) <\
    \ get<1>(b); });\n\n    FenwickTree<Mono> bit(len(keyX));\n\n    vc<T> res(Q);\n\
    \    int ptr = 0;\n    for (auto&& qid: I) {\n      auto [p, q] = QUERY[qid];\n\
    \      // y <= q \u3068\u306A\u308B F \u306E\u52A0\u7B97\n      while (ptr < len(F)\
    \ && get<1>(F[ptr]) <= q) {\n        auto& [ia, b, w] = F[ptr++];\n        ll\
    \ a = keyX[ia];\n        // w(p-a+1)...(p-a+A-1)(q-b+1)...(q-b+B-1) \u3092 p,q\
    \ \u306E\u591A\u9805\u5F0F\u3068\u3057\u3066\n        vc<T> f(A), g(B);\n    \
    \    f[0] = w, g[0] = 1;\n        FOR(i, A - 1) { FOR_R(j, i + 1) f[j + 1] +=\
    \ f[j] * T(-a + 1 + i); }\n        FOR(i, B - 1) { FOR_R(j, i + 1) g[j + 1] +=\
    \ g[j] * T(-b + 1 + i); }\n        reverse(all(f));\n        reverse(all(g));\n\
    \        array<T, A * B> G{};\n        FOR(i, A) FOR(j, B) G[B * i + j] = f[i]\
    \ * g[j];\n        bit.add(ia, G);\n      }\n      auto SM = bit.sum(UB(keyX,\
    \ p));\n      T sm = 0;\n      T pow_p = 1;\n      FOR(i, A) {\n        T prod\
    \ = pow_p;\n        FOR(j, B) {\n          sm += prod * SM[B * i + j];\n     \
    \     prod *= T(q);\n        }\n        pow_p *= T(p);\n      }\n      res[qid]\
    \ = sm;\n    }\n    if (div_fact) {\n      T cf = T(1);\n      FOR(a, 1, A) cf\
    \ *= T(a);\n      FOR(b, 1, B) cf *= T(b);\n      for (auto&& x: res) x /= cf;\n\
    \    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/coeffient_query_2d.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/coeffient_query_2d.hpp
layout: document
redirect_from:
- /library/ds/query/coeffient_query_2d.hpp
- /library/ds/query/coeffient_query_2d.hpp.html
title: ds/query/coeffient_query_2d.hpp
---
