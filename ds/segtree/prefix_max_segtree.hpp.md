---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/prefix_max_segtree.test.cpp
    title: test/1_mytest/prefix_max_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/contest/1540/problem/8338
  bundledCode: "#line 1 \"ds/segtree/prefix_max_segtree.hpp\"\n\n/*\nkey[0],...,key[n-1]\
    \ \u304C\u3042\u308B\n\u30E2\u30CE\u30A4\u30C9\u306E\u5217 x[0],...,x[n-1] \u304C\
    \u3042\u308B\nquery(l,r): l \u304B\u3089\u898B\u3048\u308B\u3068\u3053\u308D\u306B\
    \u5BFE\u3059\u308B monoid product\n\u898B\u3048\u308B: key[i]==max(key[0]...key[i])\n\
    Qlog^2n\nhttps://qoj.ac/contest/1540/problem/8338\n*/\ntemplate <typename KEY_TYPE,\
    \ typename Monoid>\nstruct Prefix_Max_SegTree {\n  using MX = Monoid;\n  using\
    \ KEY = KEY_TYPE;\n  using X = typename MX::value_type;\n  int n, size, log;\n\
    \  struct Data {\n    KEY max;\n    X prod, rprod; // rprod \u306F\u3053\u306E\
    \u533A\u9593\u3060\u3051\u3067\u8A08\u7B97\u3057\u305F\u3068\u304D\u306E\u53F3\
    \u5074\n  };\n\n  vc<Data> dat;\n\n  Prefix_Max_SegTree() {}\n  Prefix_Max_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Prefix_Max_SegTree(int n, F f)\
    \ {\n    build(n, f);\n  }\n  Prefix_Max_SegTree(const vc<X>& v) { build(v); }\n\
    \n  void build(int m) {\n    build(m, [](int i) -> pair<KEY, X> { return {-infty<int>,\
    \ MX::unit()}; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n\
    \    dat.assign(size << 1, {-infty<int>, MX::unit(), MX::unit()});\n    FOR(i,\
    \ n) {\n      auto [k, x] = f(i);\n      dat[size + i] = {k, x, MX::unit()};\n\
    \    }\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void set(int i, pair<KEY, X>\
    \ p) {\n    int k = p.fi;\n    X x = p.se;\n    i += size;\n    dat[i] = {k, x,\
    \ MX::unit()};\n    while (i > 1) i /= 2, update(i);\n  }\n\n  X prod_all() {\
    \ return dat[1].prod; }\n  X prod(int L, int R) {\n    KEY k = -infty<KEY>;\n\
    \    vc<int> suff;\n    L += size, R += size;\n    X prod = MX::unit();\n    while\
    \ (L < R) {\n      if (L & 1) { prod = MX::op(prod, dfs(L, k)), chmax(k, dat[L].max),\
    \ ++L; }\n      if (R & 1) { suff.eb(--R); }\n      L /= 2, R /= 2;\n    }\n \
    \   reverse(all(suff));\n    for (auto& v: suff) { prod = MX::op(prod, dfs(v,\
    \ k)), chmax(k, dat[v].max); }\n    return prod;\n  }\n\n  pair<KEY, X> get(int\
    \ i) { return {dat[size + i].max, dat[size + i].prod}; }\n  pair<vc<KEY>, vc<X>>\
    \ get_all() {\n    vc<KEY> key(n);\n    vc<X> x(n);\n    FOR(i, n) key[i] = dat[size\
    \ + i].max, x[i] = dat[size + i].prod;\n    return {key, x};\n  }\n\nprivate:\n\
    \  void update(int i) {\n    assert(0 <= i && i < size);\n    dat[i].max = max(dat[2\
    \ * i + 0].max, dat[2 * i + 1].max);\n    dat[i].rprod = dfs(2 * i + 1, dat[2\
    \ * i + 0].max);\n    dat[i].prod = MX::op(dat[2 * i + 0].prod, dat[i].rprod);\n\
    \  }\n\n  X dfs(int v, KEY k) {\n    // prefix \u306B k \u3092\u7F6E\u3044\u305F\
    \u5834\u5408\u306E subtree(v) \u3067\u306E\u5024\n    if (size <= v) { return\
    \ (k <= dat[v].max ? dat[v].prod : MX::unit()); }\n    if (k <= dat[2 * v + 0].max)\
    \ { return MX::op(dfs(2 * v + 0, k), dat[v].rprod); }\n    return dfs(2 * v +\
    \ 1, k);\n  }\n};\n"
  code: "\n/*\nkey[0],...,key[n-1] \u304C\u3042\u308B\n\u30E2\u30CE\u30A4\u30C9\u306E\
    \u5217 x[0],...,x[n-1] \u304C\u3042\u308B\nquery(l,r): l \u304B\u3089\u898B\u3048\
    \u308B\u3068\u3053\u308D\u306B\u5BFE\u3059\u308B monoid product\n\u898B\u3048\u308B\
    : key[i]==max(key[0]...key[i])\nQlog^2n\nhttps://qoj.ac/contest/1540/problem/8338\n\
    */\ntemplate <typename KEY_TYPE, typename Monoid>\nstruct Prefix_Max_SegTree {\n\
    \  using MX = Monoid;\n  using KEY = KEY_TYPE;\n  using X = typename MX::value_type;\n\
    \  int n, size, log;\n  struct Data {\n    KEY max;\n    X prod, rprod; // rprod\
    \ \u306F\u3053\u306E\u533A\u9593\u3060\u3051\u3067\u8A08\u7B97\u3057\u305F\u3068\
    \u304D\u306E\u53F3\u5074\n  };\n\n  vc<Data> dat;\n\n  Prefix_Max_SegTree() {}\n\
    \  Prefix_Max_SegTree(int n) { build(n); }\n  template <typename F>\n  Prefix_Max_SegTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Prefix_Max_SegTree(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> pair<KEY, X> { return\
    \ {-infty<int>, MX::unit()}; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, {-infty<int>, MX::unit(), MX::unit()});\n\
    \    FOR(i, n) {\n      auto [k, x] = f(i);\n      dat[size + i] = {k, x, MX::unit()};\n\
    \    }\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void set(int i, pair<KEY, X>\
    \ p) {\n    int k = p.fi;\n    X x = p.se;\n    i += size;\n    dat[i] = {k, x,\
    \ MX::unit()};\n    while (i > 1) i /= 2, update(i);\n  }\n\n  X prod_all() {\
    \ return dat[1].prod; }\n  X prod(int L, int R) {\n    KEY k = -infty<KEY>;\n\
    \    vc<int> suff;\n    L += size, R += size;\n    X prod = MX::unit();\n    while\
    \ (L < R) {\n      if (L & 1) { prod = MX::op(prod, dfs(L, k)), chmax(k, dat[L].max),\
    \ ++L; }\n      if (R & 1) { suff.eb(--R); }\n      L /= 2, R /= 2;\n    }\n \
    \   reverse(all(suff));\n    for (auto& v: suff) { prod = MX::op(prod, dfs(v,\
    \ k)), chmax(k, dat[v].max); }\n    return prod;\n  }\n\n  pair<KEY, X> get(int\
    \ i) { return {dat[size + i].max, dat[size + i].prod}; }\n  pair<vc<KEY>, vc<X>>\
    \ get_all() {\n    vc<KEY> key(n);\n    vc<X> x(n);\n    FOR(i, n) key[i] = dat[size\
    \ + i].max, x[i] = dat[size + i].prod;\n    return {key, x};\n  }\n\nprivate:\n\
    \  void update(int i) {\n    assert(0 <= i && i < size);\n    dat[i].max = max(dat[2\
    \ * i + 0].max, dat[2 * i + 1].max);\n    dat[i].rprod = dfs(2 * i + 1, dat[2\
    \ * i + 0].max);\n    dat[i].prod = MX::op(dat[2 * i + 0].prod, dat[i].rprod);\n\
    \  }\n\n  X dfs(int v, KEY k) {\n    // prefix \u306B k \u3092\u7F6E\u3044\u305F\
    \u5834\u5408\u306E subtree(v) \u3067\u306E\u5024\n    if (size <= v) { return\
    \ (k <= dat[v].max ? dat[v].prod : MX::unit()); }\n    if (k <= dat[2 * v + 0].max)\
    \ { return MX::op(dfs(2 * v + 0, k), dat[v].rprod); }\n    return dfs(2 * v +\
    \ 1, k);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/prefix_max_segtree.hpp
  requiredBy: []
  timestamp: '2024-11-03 20:52:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/prefix_max_segtree.test.cpp
documentation_of: ds/segtree/prefix_max_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/prefix_max_segtree.hpp
- /library/ds/segtree/prefix_max_segtree.hpp.html
title: ds/segtree/prefix_max_segtree.hpp
---
