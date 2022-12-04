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
    - https://codeforces.com/contest/703/problem/D
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: pds/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"pds/segtree.hpp\"\r\n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\
    \n// key = long long\r\n// [L, R) \u5185\u306E\u8981\u7D20 (long long) \u3092\
    \ UNIQUE \u3057\u305F\u4E0A\u3067\u3001\r\n// f(k),\u306E\u7DCF\u7A4D\u3092\u3068\
    \u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002 f: key -> Monoid value\r\n//\
    \ Online \u5316\u3057\u305F\u3082\u306E\u306E\u3001\u30E1\u30E2\u30EA\u5B9A\u6570\
    \u500D\u304C\u91CD\u3044\r\ntemplate <typename Monoid, int NODES = 1000000>\r\n\
    struct OnlineUniqueProductQuery {\r\n  using X = typename Monoid::value_type;\r\
    \n  int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>> query;\r\n  vc<int> times;\r\
    \n  Persistent_SegTree<Monoid, NODES> seg;\r\n\r\n  template <typename F>\r\n\
    \  OnlineUniqueProductQuery(vc<ll>& key, F f) : N(len(key)), key(key), seg(N)\
    \ {\r\n    times.eb(seg.time());\r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\
    \n    FOR(i, N) {\r\n      ll x = key[i];\r\n      int t = seg.time();\r\n   \
    \   if (pos.count(x)) { t = seg.set(t, pos[x], Monoid::unit); }\r\n      pos[x]\
    \ = i;\r\n      t = seg.set(t, i, f(key[i]));\r\n      times.eb(t);\r\n    }\r\
    \n  }\r\n\r\n  X prod(int L, int R) {\r\n    int t = times[R];\r\n    return seg.prod(t,\
    \ L, R);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/online_uniqueproductquery.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/online_uniqueproductquery.hpp
layout: document
redirect_from:
- /library/ds/online_uniqueproductquery.hpp
- /library/ds/online_uniqueproductquery.hpp.html
title: ds/online_uniqueproductquery.hpp
---
