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
    - https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e
    - https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"ds/segtree/dual_segtree.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n#include \"ds/fastset.hpp\"\n\n// \u533A\u9593\u52A0\u7B97 / \u3042\u308B\u7BC4\
    \u56F2\u3092 prefix \u5074\u304B\u3089\u5358\u8ABF(\u5897\u52A0/\u6E1B\u5C11)\u306B\
    \u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\n// \u6307\u5B9A\u3057\u306A\u304B\u3063\
    \u305F\u5834\u5408 0 \u57CB\u3081\u3067\u521D\u671F\u5316\u3055\u308C\u308B\n\
    // https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e\n// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i\n\
    struct Range_Add_Make_Monotonic_Decreasing {\n  // \u4EE3\u8868\u70B9\u306E\u96C6\
    \u5408\u3092\u6301\u3064. \u4EE3\u8868\u70B9\u306B\u5BFE\u3059\u308B\u5024\u3092\
    \u53CC\u5BFE\u30BB\u30B0\u6728\u3067\u6301\u3064.\n  // A[i-1]>A[i] \u3068\u306A\
    \u3063\u3066\u3044\u308B i \u5168\u4F53\u3082\u6301\u3064.\n  int n;\n  FastSet\
    \ S, INC;\n  Dual_SegTree<Monoid_Add<ll>> seg;\n\n  Range_Add_Make_Monotonic_Decreasing()\
    \ {}\n  Range_Add_Make_Monotonic_Decreasing(int n) { build(n); }\n  template <typename\
    \ F>\n  Range_Add_Make_Monotonic_Decreasing(int n, F f) {\n    build(n, f);\n\
    \  }\n  Range_Add_Make_Monotonic_Decreasing(const vi& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> ll { return 0; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    vi v(m);\n    FOR(i, m) v[i] =\
    \ f(i);\n    build(v);\n  }\n  void build(const vi& v) {\n    n = len(v);\n  \
    \  seg.build(n, [&](int i) -> ll { return v[i]; }), S.build(n), INC.build(n +\
    \ 1);\n    FOR(i, n) S.insert(i);\n    FOR(i, 1, n) if (v[i - 1] < v[i]) INC.insert(i);\n\
    \  }\n\n  ll get(int i) { return seg.get(S.prev(i)); }\n  vi get_all() {\n   \
    \ auto A = seg.get_all();\n    int p = 0;\n    FOR(i, n) {\n      if (S[i]) p\
    \ = i;\n      A[i] = A[p];\n    }\n    return A;\n  }\n  void set(int i, ll x)\
    \ {\n    split(i), split(i + 1);\n    seg.set(i, x);\n    INC.insert(i), INC.insert(i\
    \ + 1);\n  }\n  void range_add(int L, int R, ll x) {\n    split(L), split(R);\n\
    \    if (x > 0) INC.insert(L);\n    if (x < 0) INC.insert(R);\n    seg.apply(L,\
    \ R, x);\n  }\n  void range_assign(int L, int R, ll x) {\n    split(L), split(R);\n\
    \    INC.insert(L), INC.insert(R);\n    S.enumerate(L, R, [&](int i) -> void {\
    \ S.erase(i); });\n    S.insert(L);\n    seg.set(L, x);\n  }\n  void make_increasing(int\
    \ L, int R) {\n    split(L), split(R);\n    INC.enumerate(L + 1, R, [&](int i)\
    \ -> void {\n      ll mi = get(i - 1);\n      while (i < R) {\n        INC.erase(i);\n\
    \        ll now = get(i);\n        if (mi > now) break;\n        S.erase(i);\n\
    \        i = S.next(i);\n      }\n    });\n  }\n\nprivate:\n  void split(int p)\
    \ {\n    if (p == 0 || p == n || S[p]) return;\n    seg.set(p, get(p));\n    S.insert(p);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/range_add_make_decreasing.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/range_add_make_decreasing.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_add_make_decreasing.hpp
- /library/ds/segtree/range_add_make_decreasing.hpp.html
title: ds/segtree/range_add_make_decreasing.hpp
---
