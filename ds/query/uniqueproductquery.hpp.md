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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#include \"alg/group/add.hpp\"\r\n#include \"ds/segtree.hpp\"\r\n\r\n// [L,\
    \ R) \u5185\u306E\u8981\u7D20 (long long)\u3092 UNIQUE \u3057\u305F\u4E0A\u3067\
    \u3001f(x)\u306E\u7DCF\u7A4D\u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\
    \u3002\r\n// \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\u30BB\
    \u30B0\u6728\r\n// \u30AF\u30A8\u30EA\u3092\u5168\u90E8 add(L,R) \u3059\u308B\r\
    \n// calc(f) \u3068\u3057\u3066\u547C\u3076\r\ntemplate <typename Mono = Group_Add<int>>\r\
    \nstruct UniqueProductQuery {\r\n  using X = typename Mono::value_type;\r\n  int\
    \ N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>> query;\r\n\r\n  UniqueProductQuery(vc<ll>&\
    \ key) : N(len(key)), key(key) {}\r\n\r\n  void add(int L, int R) {\r\n    assert(0\
    \ <= L && L <= R && R <= N);\r\n    query.eb(L, R);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  vc<X> calc(F f) {\r\n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n\
    \    vc<vc<int>> IDS(N + 1);\r\n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono>\
    \ seg(N);\r\n\r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n\r\n\
    \    FOR(i, N) {\r\n      ll x = key[i];\r\n      if (pos.count(x)) { seg.set(pos[x],\
    \ Mono::unit()); }\r\n      pos[x] = i;\r\n      seg.set(i, f(key[i]));\r\n  \
    \    for (auto&& q: IDS[i + 1]) {\r\n        auto [L, R] = query[q];\r\n     \
    \   ANS[q] = seg.prod(L, R);\r\n      }\r\n    }\r\n    return ANS;\r\n  }\r\n\
    \r\n  vc<X> calc() {\r\n    auto f = [&](ll k) -> X { return 1; };\r\n    return\
    \ calc(f);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/uniqueproductquery.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/uniqueproductquery.hpp
layout: document
redirect_from:
- /library/ds/query/uniqueproductquery.hpp
- /library/ds/query/uniqueproductquery.hpp.html
title: ds/query/uniqueproductquery.hpp
---
