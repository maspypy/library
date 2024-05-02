---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/manhattan_nns.test.cpp
    title: test/mytest/manhattan_nns.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool tie_is_left\
    \ = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n\
    \  using X = value_type;\r\n  static constexpr bool is_small(const X& x, const\
    \ X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi) return\
    \ false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\
    \n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static constexpr\
    \ X unit() { return {infty<T>, -1}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"geo/manhattan_nns.hpp\"\n\r\n// \u70B9\u7FA4 FRM \u304B\u3089\
    \u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector \u306E\
    \ pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X = ll>\r\n\
    pair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>& TO) {\r\
    \n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  vc<int> nbd_idx(N, -1);\r\n  vc<X> dist(N, infty<X>);\r\n\r\n  auto add_ans\
    \ = [&](int i, int j) -> void {\r\n    if (j == -1) return;\r\n    X dx = points[i].fi\
    \ - points[j].fi;\r\n    X dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i],\
    \ abs(dx) + abs(dy))) nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\
    \n  iota(all(I), 0);\r\n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi\
    \ < points[j].fi); });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<X>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};\n"
  code: "#include \"ds/segtree/segtree.hpp\"\r\n#include \"alg/monoid/min_idx.hpp\"\
    \r\n\r\n// \u70B9\u7FA4 FRM \u304B\u3089\u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\
    \u70B9\u63A2\u7D22\r\n// vector \u306E pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\
    \ntemplate <typename X = ll>\r\npair<vc<X>, vc<int>> manhattan_nns(vc<pair<X,\
    \ X>> FRM, vc<pair<X, X>>& TO) {\r\n  assert(len(TO) >= 1);\r\n  int N = len(FRM),\
    \ M = len(TO);\r\n  vc<pair<X, X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\
    \n  FOR(i, M) points[N + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\
    \n  UNIQUE(Y);\r\n\r\n  vc<int> nbd_idx(N, -1);\r\n  vc<X> dist(N, infty<X>);\r\
    \n\r\n  auto add_ans = [&](int i, int j) -> void {\r\n    if (j == -1) return;\r\
    \n    X dx = points[i].fi - points[j].fi;\r\n    X dy = points[i].se - points[j].se;\r\
    \n    if (chmin(dist[i], abs(dx) + abs(dy))) nbd_idx[i] = j - N;\r\n  };\r\n\r\
    \n  vc<int> I(N + M);\r\n  iota(all(I), 0);\r\n  sort(all(I), [&](auto& i, auto&\
    \ j) { return (points[i].fi < points[j].fi); });\r\n  auto calc = [&]() -> void\
    \ {\r\n    SegTree<Monoid_Min_Idx<X>> seg1(len(Y)), seg2(len(Y));\r\n    for (auto&&\
    \ i: I) {\r\n      auto [x, y] = points[i];\r\n      int idx = LB(Y, y);\r\n \
    \     if (i < N) {\r\n        add_ans(i, seg1.prod(idx, len(Y)).se);\r\n     \
    \   add_ans(i, seg2.prod(0, idx).se);\r\n      }\r\n      elif (i >= N) {\r\n\
    \        seg1.set(idx, {y - x, i});\r\n        seg2.set(idx, {-(x + y), i});\r\
    \n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\n  reverse(all(I));\r\n  FOR(i,\
    \ N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\n  return {dist, nbd_idx};\r\n\
    };"
  dependsOn:
  - ds/segtree/segtree.hpp
  - alg/monoid/min_idx.hpp
  isVerificationFile: false
  path: geo/manhattan_nns.hpp
  requiredBy: []
  timestamp: '2023-04-14 22:06:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/manhattan_nns.test.cpp
documentation_of: geo/manhattan_nns.hpp
layout: document
redirect_from:
- /library/geo/manhattan_nns.hpp
- /library/geo/manhattan_nns.hpp.html
title: geo/manhattan_nns.hpp
---
