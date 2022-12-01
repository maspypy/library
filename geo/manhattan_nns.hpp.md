---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/103577/problem/K
  bundledCode: "#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using X = typename Monoid::value_type;\n  using value_type = X;\n\
    \  vector<X> dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0) {}\n  SegTree(int\
    \ n) : SegTree(vector<X>(n, Monoid::unit())) {}\n  SegTree(vector<X> v) : n(v.size())\
    \ {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n \
    \   dat.assign(size << 1, Monoid::unit());\n    for (int i = 0; i < n; ++i) dat[size\
    \ + i] = v[i];\n    for (int i = size - 1; i >= 1; --i) update(i);\n  }\n\n  template\
    \ <typename F>\n  SegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1 <<\
    \ log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = f(i);\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  void reset() { fill(all(dat), Monoid::unit());\
    \ }\n\n  void set_all(const vector<X>& v) {\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  X operator[](int i) { return dat[size\
    \ + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L\
    \ <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F& check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n      \
    \      sm = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n\
    \        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n     \
    \ L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001\
    prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n\
    \  X Xor_prod(int l, int r, int xor_val) {\n    assert(Monoid::commute);\n   \
    \ X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 2 \"alg/monoid/min_idx.hpp\"\
    \n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx\
    \ {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static\
    \ constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return\
    \ true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se\
    \ < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x,\
    \ y) ? x : y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"geo/manhattan_nns.hpp\"\
    \n\r\n// https://codeforces.com/gym/103577/problem/K\r\n// \u70B9\u7FA4 FRM \u304B\
    \u3089\u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector\
    \ \u306E pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X =\
    \ ll>\r\npair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>&\
    \ TO) {\r\n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  const X INF = numeric_limits<X>::max();\r\n\r\n  vc<int> nbd_idx(N, -1);\r\
    \n  vc<X> dist(N, INF);\r\n\r\n  auto add_ans = [&](int i, int j) -> void {\r\n\
    \    if (j == -1) return;\r\n    X dx = points[i].fi - points[j].fi;\r\n    X\
    \ dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i], abs(dx) + abs(dy)))\
    \ nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\n  iota(all(I), 0);\r\
    \n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi < points[j].fi);\
    \ });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<ll, INF>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};\n"
  code: "#include \"ds/segtree/segtree.hpp\"\r\n#include \"alg/monoid/min_idx.hpp\"\
    \r\n\r\n// https://codeforces.com/gym/103577/problem/K\r\n// \u70B9\u7FA4 FRM\
    \ \u304B\u3089\u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n//\
    \ vector \u306E pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename\
    \ X = ll>\r\npair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X,\
    \ X>>& TO) {\r\n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n\
    \  vc<pair<X, X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i,\
    \ M) points[N + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\
    \n  UNIQUE(Y);\r\n\r\n  const X INF = numeric_limits<X>::max();\r\n\r\n  vc<int>\
    \ nbd_idx(N, -1);\r\n  vc<X> dist(N, INF);\r\n\r\n  auto add_ans = [&](int i,\
    \ int j) -> void {\r\n    if (j == -1) return;\r\n    X dx = points[i].fi - points[j].fi;\r\
    \n    X dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i], abs(dx) +\
    \ abs(dy))) nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\n  iota(all(I),\
    \ 0);\r\n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi < points[j].fi);\
    \ });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<ll, INF>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};"
  dependsOn:
  - ds/segtree/segtree.hpp
  - alg/monoid/min_idx.hpp
  isVerificationFile: false
  path: geo/manhattan_nns.hpp
  requiredBy: []
  timestamp: '2022-12-01 22:25:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/manhattan_nns.hpp
layout: document
redirect_from:
- /library/geo/manhattan_nns.hpp
- /library/geo/manhattan_nns.hpp.html
title: geo/manhattan_nns.hpp
---
