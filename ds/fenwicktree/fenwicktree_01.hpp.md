---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':warning:'
    path: graph/ds/range_edge_connected_component_query.hpp
    title: graph/ds/range_edge_connected_component_query.hpp
  - icon: ':warning:'
    path: other/sliding_puzzle_solver.hpp
    title: other/sliding_puzzle_solver.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_polygon.hpp
    title: random/random_polygon.hpp
  - icon: ':heavy_check_mark:'
    path: seq/inversion.hpp
    title: seq/inversion.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_points_in_triangles.test.cpp
    title: test/1_mytest/count_points_in_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/fenwick01.test.cpp
    title: test/1_mytest/fenwick01.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_set_range_freq.test.cpp
    title: test/2_library_checker/data_structure/point_set_range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/predecessor_problem_4.test.cpp
    title: test/2_library_checker/data_structure/predecessor_problem_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
    title: test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/count_points_in_triangles.test.cpp
    title: test/2_library_checker/geometry/count_points_in_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1838.test.cpp
    title: test/3_yukicoder/1838.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/694.test.cpp
    title: test/3_yukicoder/694.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ALDS1_2_A.test.cpp
    title: test/4_aoj/ALDS1_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ALDS1_5.test.cpp
    title: test/4_aoj/ALDS1_5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\n\
    template <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int\
    \ k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return max_right([&k](E x) ->\
    \ bool { return x <= k; }, L);\n  }\n};\n#line 4 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\nstruct FenwickTree_01 {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n\
    \    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }\n    bit.build(n, [&](int\
    \ i) -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return bit.sum_all();\
    \ }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int k) {\n \
    \   int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k / 64] & ((u64(1) << (k\
    \ % 64)) - 1));\n    return ans;\n  }\n  int sum(int L, int R) {\n    if (L ==\
    \ 0) return prefix_sum(R);\n    int ans = 0;\n    ans -= popcnt(dat[L / 64] &\
    \ ((u64(1) << (L % 64)) - 1));\n    ans += popcnt(dat[R / 64] & ((u64(1) << (R\
    \ % 64)) - 1));\n    ans += bit.sum(L / 64, R / 64);\n    return ans;\n  }\n\n\
    \  void add(int k, int x) {\n    if (x == 1) add(k);\n    elif (x == -1) remove(k);\n\
    \    else assert(0);\n  }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) <<\
    \ (k % 64);\n    bit.add(k / 64, 1);\n  }\n  void remove(int k) {\n    dat[k /\
    \ 64] &= ~(u64(1) << (k % 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int\
    \ k, int L = 0) {\n    if (k >= sum_all()) return N;\n    k += popcnt(dat[L /\
    \ 64] & ((u64(1) << (L % 64)) - 1));\n    L /= 64;\n    int mid = 0;\n    auto\
    \ check = [&](auto e) -> bool {\n      if (e <= k) chmax(mid, e);\n      return\
    \ e <= k;\n    };\n    int idx = bit.max_right(check, L);\n    if (idx == n) return\
    \ N;\n    k -= mid;\n    u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p\
    \ <= k) return N;\n    k = binary_search([&](int n) -> bool { return (p - popcnt(x\
    \ >> n)) <= k; }, 0, 64, 0);\n    return 64 * idx + k;\n  }\n\n  int next(int\
    \ k) {\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx] & ~((u64(1)\
    \ << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx\
    \ + 1);\n    if (idx == n || !dat[idx]) return N;\n    return 64 * idx + lowbit(dat[idx]);\n\
    \  }\n\n  int prev(int k) {\n    if (k == N) --k;\n    int idx = k / 64;\n   \
    \ k %= 64;\n    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1)) -\
    \ 1;\n    if (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto\
    \ e) -> bool { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n  \
    \  return 64 * idx + topbit(dat[idx]);\n  }\n};\n"
  code: "#pragma once\n\n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nstruct FenwickTree_01\
    \ {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>> bit;\n  FenwickTree_01()\
    \ {}\n  FenwickTree_01(int n) { build(n); }\n  template <typename F>\n  FenwickTree_01(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    N = m;\n    n\
    \ = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n    bit.build(n);\n  }\n\
    \n  template <typename F>\n  void build(int m, F f) {\n    N = m;\n    n = ceil<int>(N\
    \ + 1, 64);\n    dat.assign(n, u64(0));\n    FOR(i, N) { dat[i / 64] |= u64(f(i))\
    \ << (i % 64); }\n    bit.build(n, [&](int i) -> int { return popcnt(dat[i]);\
    \ });\n  }\n\n  int sum_all() { return bit.sum_all(); }\n  int sum(int k) { return\
    \ prefix_sum(k); }\n  int prefix_sum(int k) {\n    int ans = bit.sum(k / 64);\n\
    \    ans += popcnt(dat[k / 64] & ((u64(1) << (k % 64)) - 1));\n    return ans;\n\
    \  }\n  int sum(int L, int R) {\n    if (L == 0) return prefix_sum(R);\n    int\
    \ ans = 0;\n    ans -= popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));\n   \
    \ ans += popcnt(dat[R / 64] & ((u64(1) << (R % 64)) - 1));\n    ans += bit.sum(L\
    \ / 64, R / 64);\n    return ans;\n  }\n\n  void add(int k, int x) {\n    if (x\
    \ == 1) add(k);\n    elif (x == -1) remove(k);\n    else assert(0);\n  }\n\n \
    \ void add(int k) {\n    dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k / 64,\
    \ 1);\n  }\n  void remove(int k) {\n    dat[k / 64] &= ~(u64(1) << (k % 64));\n\
    \    bit.add(k / 64, -1);\n  }\n\n  int kth(int k, int L = 0) {\n    if (k >=\
    \ sum_all()) return N;\n    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64)) -\
    \ 1));\n    L /= 64;\n    int mid = 0;\n    auto check = [&](auto e) -> bool {\n\
    \      if (e <= k) chmax(mid, e);\n      return e <= k;\n    };\n    int idx =\
    \ bit.max_right(check, L);\n    if (idx == n) return N;\n    k -= mid;\n    u64\
    \ x = dat[idx];\n    int p = popcnt(x);\n    if (p <= k) return N;\n    k = binary_search([&](int\
    \ n) -> bool { return (p - popcnt(x >> n)) <= k; }, 0, 64, 0);\n    return 64\
    \ * idx + k;\n  }\n\n  int next(int k) {\n    int idx = k / 64;\n    k %= 64;\n\
    \    u64 x = dat[idx] & ~((u64(1) << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n\
    \    idx = bit.kth(0, idx + 1);\n    if (idx == n || !dat[idx]) return N;\n  \
    \  return 64 * idx + lowbit(dat[idx]);\n  }\n\n  int prev(int k) {\n    if (k\
    \ == N) --k;\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx];\n   \
    \ if (k < 63) x &= (u64(1) << (k + 1)) - 1;\n    if (x) return 64 * idx + topbit(x);\n\
    \    idx = bit.min_left([&](auto e) -> bool { return e <= 0; }, idx) - 1;\n  \
    \  if (idx == -1) return -1;\n    return 64 * idx + topbit(dat[idx]);\n  }\n};"
  dependsOn:
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_01.hpp
  requiredBy:
  - random/random_polygon.hpp
  - other/sliding_puzzle_solver.hpp
  - geo/count_points_in_triangles.hpp
  - seq/inversion.hpp
  - graph/ds/range_edge_connected_component_query.hpp
  timestamp: '2024-12-25 20:50:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1838.test.cpp
  - test/3_yukicoder/694.test.cpp
  - test/4_aoj/ALDS1_5.test.cpp
  - test/4_aoj/ALDS1_2_A.test.cpp
  - test/1_mytest/polygon_triangulation.test.cpp
  - test/1_mytest/count_points_in_triangles.test.cpp
  - test/1_mytest/fenwick01.test.cpp
  - test/2_library_checker/data_structure/predecessor_problem_4.test.cpp
  - test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
  - test/2_library_checker/data_structure/point_set_range_freq.test.cpp
  - test/2_library_checker/geometry/count_points_in_triangles.test.cpp
documentation_of: ds/fenwicktree/fenwicktree_01.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree_01.hpp
- /library/ds/fenwicktree/fenwicktree_01.hpp.html
title: ds/fenwicktree/fenwicktree_01.hpp
---
