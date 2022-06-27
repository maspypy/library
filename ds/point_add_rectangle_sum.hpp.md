---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':question:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/rectangle_add_ractangle_sum.hpp
    title: ds/rectangle_add_ractangle_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1490_rect_add_rect_sum.test.cpp
    title: test/yukicoder/1490_rect_add_rect_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\
    \n\n\ntemplate <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename\
    \ AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree()\
    \ : FenwickTree(0) {}\n  FenwickTree(int n) : n(n), total(AbelGroup::unit()) {\n\
    \    assert(AbelGroup::commute);\n    dat.assign(n, AbelGroup::unit());\n  }\n\
    \  FenwickTree(vector<E> v) : n(len(v)), total(AbelGroup::unit()) {\n    assert(AbelGroup::commute);\n\
    \    for (int i = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat\
    \ = v;\n    for (int i = n; i >= 1; --i) {\n      int j = i + (i & -i);\n    \
    \  if (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\
    \n  void reset() {\n    total = AbelGroup::unit();\n    dat.assign(n, AbelGroup::unit());\n\
    \  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit();\n    for (; k > 0; k\
    \ -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return ret;\n  }\n\n \
    \ E sum(int L, int R) {\n    E pos = AbelGroup::unit();\n    while (L < R) {\n\
    \      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n    }\n    E\
    \ neg = AbelGroup::unit();\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total\
    \ = AbelGroup::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] =\
    \ AbelGroup::op(dat[k - 1], x);\n  }\n\n  template <class F>\n  int max_right(F\
    \ &check) {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n\
    \    int k = 1;\n    int N = dat.size() + 1;\n    while (2 * k < N) k *= 2;\n\
    \    while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 3 \"ds/point_add_rectangle_sum.hpp\"\
    \n\r\n\r\ntemplate <typename AbelGroup, bool SMALL = false>\r\nstruct Point_Add_Rectangle_Sum\
    \ {\r\n  using G = typename AbelGroup::value_type;\r\n  int Q;\r\n  vector<ll>\
    \ X, Y;\r\n  vector<G> WT;\r\n  vector<tuple<ll, ll, ll, ll>> rect;\r\n\r\n  Point_Add_Rectangle_Sum()\
    \ {}\r\n\r\n  void add_query(ll x, ll y, G w) {\r\n    X.emplace_back(x), Y.emplace_back(y),\
    \ WT.emplace_back(w);\r\n  }\r\n\r\n  void sum_query(ll xl, ll yl, ll xr, ll yr)\
    \ {\r\n    rect.emplace_back(xl, yl, xr, yr);\r\n  }\r\n\r\n  vector<G> calc()\
    \ {\r\n    int N = X.size(), Q = rect.size();\r\n    if (N == 0) return vector<G>(Q,\
    \ AbelGroup::unit());\r\n    int NX = 0, NY = 0;\r\n    if (!SMALL) {\r\n    \
    \  vector<ll> keyX = X, keyY = Y;\r\n      sort(all(keyX));\r\n      keyX.erase(unique(all(keyX)),\
    \ keyX.end());\r\n      sort(all(keyY));\r\n      keyY.erase(unique(all(keyY)),\
    \ keyY.end());\r\n      NX = keyX.size(), NY = keyY.size();\r\n      for (auto\
    \ &&x: X) x = lower_bound(all(keyX), x) - keyX.begin();\r\n      for (auto &&y:\
    \ Y) y = lower_bound(all(keyY), y) - keyY.begin();\r\n      for (auto &&[xl, yl,\
    \ xr, yr]: rect) {\r\n        xl = lower_bound(all(keyX), xl) - keyX.begin();\r\
    \n        xr = lower_bound(all(keyX), xr) - keyX.begin();\r\n        yl = lower_bound(all(keyY),\
    \ yl) - keyY.begin();\r\n        yr = lower_bound(all(keyY), yr) - keyY.begin();\r\
    \n      }\r\n    }\r\n    if (SMALL) {\r\n      ll mx = *(min_element(X.begin(),\
    \ X.end()));\r\n      ll my = *(min_element(Y.begin(), Y.end()));\r\n      for\
    \ (auto &&x: X) x -= mx;\r\n      for (auto &&y: Y) y -= my;\r\n      NX = *(max_element(X.begin(),\
    \ X.end())) + 1;\r\n      NY = *(max_element(Y.begin(), Y.end())) + 1;\r\n   \
    \   for (auto &&[xl, yl, xr, yr]: rect) {\r\n        xl -= mx, xr -= mx;\r\n \
    \       yl -= my, yr -= my;\r\n        xl = max(0, min<int>(xl, NX));\r\n    \
    \    xr = max(0, min<int>(xr, NX));\r\n        yl = max(0, min<int>(yl, NY));\r\
    \n        yr = max(0, min<int>(yr, NY));\r\n      }\r\n    }\r\n    vector<vector<pair<int,\
    \ G>>> ADD(NY + 1);\r\n    vector<vector<tuple<int, int, int>>> CALC_1(NY + 1);\r\
    \n    vector<vector<tuple<int, int, int>>> CALC_2(NY + 1);\r\n    for (int n =\
    \ 0; n < N; ++n) { ADD[Y[n]].emplace_back(X[n], WT[n]); }\r\n    for (int q =\
    \ 0; q < Q; ++q) {\r\n      auto &[xl, yl, xr, yr] = rect[q];\r\n      CALC_1[yr].emplace_back(xl,\
    \ xr, q);\r\n      CALC_2[yl].emplace_back(xl, xr, q);\r\n    };\r\n\r\n    vector<G>\
    \ res(Q, AbelGroup::unit());\r\n    FenwickTree<AbelGroup> bit(NX);\r\n\r\n  \
    \  for (int y = 0; y <= NY; ++y) {\r\n      for (auto &&[xl, xr, q]: CALC_1[y])\
    \ {\r\n        auto x = bit.sum(xl, xr);\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[xl, xr, q]: CALC_2[y]) {\r\n        auto\
    \ x = AbelGroup::inverse(bit.sum(xl, xr));\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[x, g]: ADD[y]) { bit.add(x, g); }\r\n \
    \   }\r\n    return res;\r\n  }\r\n};\n"
  code: "#pragma once\r\n#include \"ds/fenwick.hpp\"\r\n\r\n\r\ntemplate <typename\
    \ AbelGroup, bool SMALL = false>\r\nstruct Point_Add_Rectangle_Sum {\r\n  using\
    \ G = typename AbelGroup::value_type;\r\n  int Q;\r\n  vector<ll> X, Y;\r\n  vector<G>\
    \ WT;\r\n  vector<tuple<ll, ll, ll, ll>> rect;\r\n\r\n  Point_Add_Rectangle_Sum()\
    \ {}\r\n\r\n  void add_query(ll x, ll y, G w) {\r\n    X.emplace_back(x), Y.emplace_back(y),\
    \ WT.emplace_back(w);\r\n  }\r\n\r\n  void sum_query(ll xl, ll yl, ll xr, ll yr)\
    \ {\r\n    rect.emplace_back(xl, yl, xr, yr);\r\n  }\r\n\r\n  vector<G> calc()\
    \ {\r\n    int N = X.size(), Q = rect.size();\r\n    if (N == 0) return vector<G>(Q,\
    \ AbelGroup::unit());\r\n    int NX = 0, NY = 0;\r\n    if (!SMALL) {\r\n    \
    \  vector<ll> keyX = X, keyY = Y;\r\n      sort(all(keyX));\r\n      keyX.erase(unique(all(keyX)),\
    \ keyX.end());\r\n      sort(all(keyY));\r\n      keyY.erase(unique(all(keyY)),\
    \ keyY.end());\r\n      NX = keyX.size(), NY = keyY.size();\r\n      for (auto\
    \ &&x: X) x = lower_bound(all(keyX), x) - keyX.begin();\r\n      for (auto &&y:\
    \ Y) y = lower_bound(all(keyY), y) - keyY.begin();\r\n      for (auto &&[xl, yl,\
    \ xr, yr]: rect) {\r\n        xl = lower_bound(all(keyX), xl) - keyX.begin();\r\
    \n        xr = lower_bound(all(keyX), xr) - keyX.begin();\r\n        yl = lower_bound(all(keyY),\
    \ yl) - keyY.begin();\r\n        yr = lower_bound(all(keyY), yr) - keyY.begin();\r\
    \n      }\r\n    }\r\n    if (SMALL) {\r\n      ll mx = *(min_element(X.begin(),\
    \ X.end()));\r\n      ll my = *(min_element(Y.begin(), Y.end()));\r\n      for\
    \ (auto &&x: X) x -= mx;\r\n      for (auto &&y: Y) y -= my;\r\n      NX = *(max_element(X.begin(),\
    \ X.end())) + 1;\r\n      NY = *(max_element(Y.begin(), Y.end())) + 1;\r\n   \
    \   for (auto &&[xl, yl, xr, yr]: rect) {\r\n        xl -= mx, xr -= mx;\r\n \
    \       yl -= my, yr -= my;\r\n        xl = max(0, min<int>(xl, NX));\r\n    \
    \    xr = max(0, min<int>(xr, NX));\r\n        yl = max(0, min<int>(yl, NY));\r\
    \n        yr = max(0, min<int>(yr, NY));\r\n      }\r\n    }\r\n    vector<vector<pair<int,\
    \ G>>> ADD(NY + 1);\r\n    vector<vector<tuple<int, int, int>>> CALC_1(NY + 1);\r\
    \n    vector<vector<tuple<int, int, int>>> CALC_2(NY + 1);\r\n    for (int n =\
    \ 0; n < N; ++n) { ADD[Y[n]].emplace_back(X[n], WT[n]); }\r\n    for (int q =\
    \ 0; q < Q; ++q) {\r\n      auto &[xl, yl, xr, yr] = rect[q];\r\n      CALC_1[yr].emplace_back(xl,\
    \ xr, q);\r\n      CALC_2[yl].emplace_back(xl, xr, q);\r\n    };\r\n\r\n    vector<G>\
    \ res(Q, AbelGroup::unit());\r\n    FenwickTree<AbelGroup> bit(NX);\r\n\r\n  \
    \  for (int y = 0; y <= NY; ++y) {\r\n      for (auto &&[xl, xr, q]: CALC_1[y])\
    \ {\r\n        auto x = bit.sum(xl, xr);\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[xl, xr, q]: CALC_2[y]) {\r\n        auto\
    \ x = AbelGroup::inverse(bit.sum(xl, xr));\r\n        res[q] = AbelGroup::op(res[q],\
    \ x);\r\n      }\r\n      for (auto &&[x, g]: ADD[y]) { bit.add(x, g); }\r\n \
    \   }\r\n    return res;\r\n  }\r\n};"
  dependsOn:
  - ds/fenwick.hpp
  - alg/group_add.hpp
  isVerificationFile: false
  path: ds/point_add_rectangle_sum.hpp
  requiredBy:
  - ds/rectangle_add_ractangle_sum.hpp
  timestamp: '2022-06-27 16:37:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1490_rect_add_rect_sum.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
documentation_of: ds/point_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/point_add_rectangle_sum.hpp
- /library/ds/point_add_rectangle_sum.hpp.html
title: ds/point_add_rectangle_sum.hpp
---
