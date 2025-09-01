---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1515/problem/I
  bundledCode: "#line 2 \"alg/monoid_pow.hpp\"\n\n// chat gpt\ntemplate <typename\
    \ U, typename Arg1, typename Arg2>\nstruct has_power_method {\nprivate:\n  //\
    \ \u30D8\u30EB\u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n  template <typename\
    \ V, typename A1, typename A2>\n  static auto check(int)\n      -> decltype(std::declval<V>().power(std::declval<A1>(),\n\
    \                                          std::declval<A2>()),\n            \
    \      std::true_type{});\n  template <typename, typename, typename>\n  static\
    \ auto check(...) -> std::false_type;\n\npublic:\n  // \u30E1\u30BD\u30C3\u30C9\
    \u306E\u6709\u7121\u3092\u8868\u3059\u578B\n  static constexpr bool value = decltype(check<U,\
    \ Arg1, Arg2>(0))::value;\n};\n\ntemplate <typename Monoid>\ntypename Monoid::X\
    \ monoid_pow(typename Monoid::X x, ll exp) {\n  using X = typename Monoid::X;\n\
    \  if constexpr (has_power_method<Monoid, X, ll>::value) {\n    return Monoid::power(x,\
    \ exp);\n  } else {\n    assert(exp >= 0);\n    X res = Monoid::unit();\n    while\
    \ (exp) {\n      if (exp & 1) res = Monoid::op(res, x);\n      x = Monoid::op(x,\
    \ x);\n      exp >>= 1;\n    }\n    return res;\n  }\n}\n#line 2 \"ds/segtree/greedy_subtract_segtree.hpp\"\
    \n\n/*\n\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 i \u306B\u30B3\u30B9\u30C8 cost_i\
    \ \u306E\u7269\u304C cnt_i \u500B\u3042\u308B. dat_i in Monoid \u3082\u3042\u308B\
    .\n\u6240\u6301\u91D1 x \u304B\u3089\u306F\u3058\u3081\u3066 i=l,l+1,...,r-1 \u306B\
    \u3064\u3044\u3066\u8CAA\u6B32\u306B\u3068\u3063\u3066 Monoid \u7A4D\u3092\u8A08\
    \u7B97.\ncost_i < LOG. O(LOG * logN time).\nhttps://codeforces.com/contest/1515/problem/I\n\
    */\ntemplate <typename Monoid, int LOG>\nstruct Greedy_Subtract_SegTree {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  /*\n  [0,2^k) \u306E sum\
    \ \u306B\u6700\u5F8C\u306B [2^k,infty) \u3092\u3061\u3087\u3046\u3069\u3072\u3068\
    \u3064\u3064\u3051\u305F\u3082\u306E\n  [0,2^k) \u306E sum\n  */\n\n  vi cost,\
    \ cnt;\n  vc<X> element;\n\n  struct Node {\n    array<ll, LOG + 1> SM_A;\n  \
    \  array<ll, LOG + 1> SM_B;\n    array<X, LOG + 1> prod_B;\n  };\n  vc<Node> dat;\n\
    \n  int n, log, size;\n  // f(i) = (cost_i, cnt_i, x_i)\n  template <typename\
    \ F>\n  Greedy_Subtract_SegTree(int N, F f) {\n    build(N, f);\n  }\n\n  // f(i)\
    \ = (cost_i, cnt_i, x_i)\n  template <typename F>\n  void build(int n_, F f) {\n\
    \    n = n_;\n    if (n == 0) return;\n    log = 0;\n    while ((1 << log) < n)\
    \ ++log;\n    size = 1 << log;\n    cost.assign(size, 0), cnt.assign(size, 0),\
    \ element.assign(size, MX::unit());\n    FOR(i, n) {\n      tie(cost[i], cnt[i],\
    \ element[i]) = f(i);\n      assert(0 <= cost[i] && cost[i] < (1LL << LOG));\n\
    \    }\n    dat.resize(2 * size);\n    FOR_R(i, 2 * size) update(i);\n  }\n\n\
    \  void update(int idx) {\n    if (size <= idx) {\n      int i = idx - size;\n\
    \      if (n <= i || cnt[i] == 0) {\n        fill(all(dat[idx].SM_A), infty<ll>);\n\
    \        fill(all(dat[idx].SM_B), 0);\n        fill(all(dat[idx].prod_B), MX::unit());\n\
    \        return;\n      }\n      FOR(k, LOG + 1) {\n        if (cost[i] < (1LL\
    \ << k)) {\n          dat[idx].SM_A[k] = infty<ll>;\n          dat[idx].SM_B[k]\
    \ = cost[i] * cnt[i];\n          dat[idx].prod_B[k] = monoid_pow<MX>(element[i],\
    \ cnt[i]);\n        } else {\n          dat[idx].SM_A[k] = cost[i];\n        \
    \  dat[idx].SM_B[k] = 0;\n          dat[idx].prod_B[k] = MX::unit();\n       \
    \ }\n      }\n      return;\n    }\n    int l = 2 * idx + 0, r = 2 * idx + 1;\n\
    \    FOR(k, LOG + 1) {\n      dat[idx].SM_A[k] = min(dat[l].SM_A[k], dat[l].SM_B[k]\
    \ + dat[r].SM_A[k]);\n      dat[idx].SM_B[k] = dat[l].SM_B[k] + dat[r].SM_B[k];\n\
    \      dat[idx].prod_B[k] = MX::op(dat[l].prod_B[k], dat[r].prod_B[k]);\n    }\n\
    \  }\n\n  void set(int i, ll cost_i, ll cnt_i, X x_i) {\n    cost[i] = cost_i,\
    \ cnt[i] = cnt_i, element[i] = x_i;\n    i += size;\n    while (i >= 1) update(i),\
    \ i /= 2;\n  }\n\n  // return: \u6B8B\u91D1, \u30E2\u30CE\u30A4\u30C9\u7A4D\n\
    \  pair<ll, X> query(int L, int R, ll x) {\n    X prod = MX::unit();\n    int\
    \ k = LOG;\n    auto upd_k = [&]() -> void {\n      while (k > 0 && (x < (1LL\
    \ << (k - 1)))) --k;\n    };\n    auto dfs = [&](auto& dfs, int idx, int nl, int\
    \ nr) -> void {\n      if (nr <= L || R <= nl) return;\n      if (size <= idx)\
    \ {\n        int i = idx - size;\n        ll take = (cost[i] == 0 ? cnt[i] : min<ll>(x\
    \ / cost[i], cnt[i]));\n        x -= take * cost[i], prod = MX::op(prod, monoid_pow<MX>(element[i],\
    \ take));\n        upd_k();\n        return;\n      }\n      int l = 2 * idx +\
    \ 0, r = 2 * idx + 1, nm = (nl + nr) / 2;\n      if (L <= nl && nr <= R) {\n \
    \       if (k == 0) {\n          prod = MX::op(prod, dat[idx].prod_B[0]);\n  \
    \        return;\n        }\n        if (dat[idx].SM_B[k] <= x) {\n          x\
    \ -= dat[idx].SM_B[k], prod = MX::op(prod, dat[idx].prod_B[k]);\n          upd_k();\n\
    \          return;\n        }\n        if (x < dat[idx].SM_A[k - 1] && x >= dat[idx].SM_B[k\
    \ - 1]) {\n          x -= dat[idx].SM_B[k - 1], prod = MX::op(prod, dat[idx].prod_B[k\
    \ - 1]);\n          upd_k();\n          return;\n        }\n      }\n      dfs(dfs,\
    \ l, nl, nm);\n      dfs(dfs, r, nm, nr);\n    };\n    dfs(dfs, 1, 0, size);\n\
    \    return {x, prod};\n  }\n\n  // \u5168\u533A\u9593. return: \u6B8B\u91D1,\
    \ \u30E2\u30CE\u30A4\u30C9\u7A4D\n  pair<ll, X> query(ll x) { return query(0,\
    \ size, x); }\n};\n"
  code: "#include \"alg/monoid_pow.hpp\"\n\n/*\n\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \ i \u306B\u30B3\u30B9\u30C8 cost_i \u306E\u7269\u304C cnt_i \u500B\u3042\u308B\
    . dat_i in Monoid \u3082\u3042\u308B.\n\u6240\u6301\u91D1 x \u304B\u3089\u306F\
    \u3058\u3081\u3066 i=l,l+1,...,r-1 \u306B\u3064\u3044\u3066\u8CAA\u6B32\u306B\u3068\
    \u3063\u3066 Monoid \u7A4D\u3092\u8A08\u7B97.\ncost_i < LOG. O(LOG * logN time).\n\
    https://codeforces.com/contest/1515/problem/I\n*/\ntemplate <typename Monoid,\
    \ int LOG>\nstruct Greedy_Subtract_SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  /*\n  [0,2^k) \u306E sum \u306B\u6700\u5F8C\u306B\
    \ [2^k,infty) \u3092\u3061\u3087\u3046\u3069\u3072\u3068\u3064\u3064\u3051\u305F\
    \u3082\u306E\n  [0,2^k) \u306E sum\n  */\n\n  vi cost, cnt;\n  vc<X> element;\n\
    \n  struct Node {\n    array<ll, LOG + 1> SM_A;\n    array<ll, LOG + 1> SM_B;\n\
    \    array<X, LOG + 1> prod_B;\n  };\n  vc<Node> dat;\n\n  int n, log, size;\n\
    \  // f(i) = (cost_i, cnt_i, x_i)\n  template <typename F>\n  Greedy_Subtract_SegTree(int\
    \ N, F f) {\n    build(N, f);\n  }\n\n  // f(i) = (cost_i, cnt_i, x_i)\n  template\
    \ <typename F>\n  void build(int n_, F f) {\n    n = n_;\n    if (n == 0) return;\n\
    \    log = 0;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    cost.assign(size,\
    \ 0), cnt.assign(size, 0), element.assign(size, MX::unit());\n    FOR(i, n) {\n\
    \      tie(cost[i], cnt[i], element[i]) = f(i);\n      assert(0 <= cost[i] &&\
    \ cost[i] < (1LL << LOG));\n    }\n    dat.resize(2 * size);\n    FOR_R(i, 2 *\
    \ size) update(i);\n  }\n\n  void update(int idx) {\n    if (size <= idx) {\n\
    \      int i = idx - size;\n      if (n <= i || cnt[i] == 0) {\n        fill(all(dat[idx].SM_A),\
    \ infty<ll>);\n        fill(all(dat[idx].SM_B), 0);\n        fill(all(dat[idx].prod_B),\
    \ MX::unit());\n        return;\n      }\n      FOR(k, LOG + 1) {\n        if\
    \ (cost[i] < (1LL << k)) {\n          dat[idx].SM_A[k] = infty<ll>;\n        \
    \  dat[idx].SM_B[k] = cost[i] * cnt[i];\n          dat[idx].prod_B[k] = monoid_pow<MX>(element[i],\
    \ cnt[i]);\n        } else {\n          dat[idx].SM_A[k] = cost[i];\n        \
    \  dat[idx].SM_B[k] = 0;\n          dat[idx].prod_B[k] = MX::unit();\n       \
    \ }\n      }\n      return;\n    }\n    int l = 2 * idx + 0, r = 2 * idx + 1;\n\
    \    FOR(k, LOG + 1) {\n      dat[idx].SM_A[k] = min(dat[l].SM_A[k], dat[l].SM_B[k]\
    \ + dat[r].SM_A[k]);\n      dat[idx].SM_B[k] = dat[l].SM_B[k] + dat[r].SM_B[k];\n\
    \      dat[idx].prod_B[k] = MX::op(dat[l].prod_B[k], dat[r].prod_B[k]);\n    }\n\
    \  }\n\n  void set(int i, ll cost_i, ll cnt_i, X x_i) {\n    cost[i] = cost_i,\
    \ cnt[i] = cnt_i, element[i] = x_i;\n    i += size;\n    while (i >= 1) update(i),\
    \ i /= 2;\n  }\n\n  // return: \u6B8B\u91D1, \u30E2\u30CE\u30A4\u30C9\u7A4D\n\
    \  pair<ll, X> query(int L, int R, ll x) {\n    X prod = MX::unit();\n    int\
    \ k = LOG;\n    auto upd_k = [&]() -> void {\n      while (k > 0 && (x < (1LL\
    \ << (k - 1)))) --k;\n    };\n    auto dfs = [&](auto& dfs, int idx, int nl, int\
    \ nr) -> void {\n      if (nr <= L || R <= nl) return;\n      if (size <= idx)\
    \ {\n        int i = idx - size;\n        ll take = (cost[i] == 0 ? cnt[i] : min<ll>(x\
    \ / cost[i], cnt[i]));\n        x -= take * cost[i], prod = MX::op(prod, monoid_pow<MX>(element[i],\
    \ take));\n        upd_k();\n        return;\n      }\n      int l = 2 * idx +\
    \ 0, r = 2 * idx + 1, nm = (nl + nr) / 2;\n      if (L <= nl && nr <= R) {\n \
    \       if (k == 0) {\n          prod = MX::op(prod, dat[idx].prod_B[0]);\n  \
    \        return;\n        }\n        if (dat[idx].SM_B[k] <= x) {\n          x\
    \ -= dat[idx].SM_B[k], prod = MX::op(prod, dat[idx].prod_B[k]);\n          upd_k();\n\
    \          return;\n        }\n        if (x < dat[idx].SM_A[k - 1] && x >= dat[idx].SM_B[k\
    \ - 1]) {\n          x -= dat[idx].SM_B[k - 1], prod = MX::op(prod, dat[idx].prod_B[k\
    \ - 1]);\n          upd_k();\n          return;\n        }\n      }\n      dfs(dfs,\
    \ l, nl, nm);\n      dfs(dfs, r, nm, nr);\n    };\n    dfs(dfs, 1, 0, size);\n\
    \    return {x, prod};\n  }\n\n  // \u5168\u533A\u9593. return: \u6B8B\u91D1,\
    \ \u30E2\u30CE\u30A4\u30C9\u7A4D\n  pair<ll, X> query(ll x) { return query(0,\
    \ size, x); }\n};"
  dependsOn:
  - alg/monoid_pow.hpp
  isVerificationFile: false
  path: ds/segtree/greedy_subtract_segtree.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:12:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/greedy_subtract_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/greedy_subtract_segtree.hpp
- /library/ds/segtree/greedy_subtract_segtree.hpp.html
title: ds/segtree/greedy_subtract_segtree.hpp
---
