---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/segtree/segtree_beats.hpp
    title: ds/segtree/segtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/segtree_beats.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct SegTree_Beats {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n\
    \  using MA = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n \
    \ using A = typename MA::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A>\
    \ laz;\n\n  SegTree_Beats() {}\n  SegTree_Beats(int n) { build(n); }\n  template\
    \ <typename F>\n  SegTree_Beats(int n, F f) {\n    build(n, f);\n  }\n  SegTree_Beats(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, MX::unit());\n    laz.assign(size, MA::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  void update(int k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void\
    \ set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i\
    \ <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p &&\
    \ p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n\
    \    return dat[p];\n  }\n\n  /*\n  void all_apply(int k, A a) {\n    dat[k] =\
    \ ActedMonoid::act(dat[k], a);\n    if (k < size) {\n      laz[k] = MA::op(laz[k],\
    \ a);\n      if (dat[k].fail) push(k), update(k);\n    }\n  }\n  */\n\n  vc<X>\
    \ get_all() {\n    FOR(k, 1, size) { push(k); }\n    return {dat.begin() + size,\
    \ dat.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l\
    \ && l <= r && r <= n);\n    if (l == r) return MX::unit();\n    l += size, r\
    \ += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) !=\
    \ l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\
    \    X xl = MX::unit(), xr = MX::unit();\n    while (l < r) {\n      if (l & 1)\
    \ xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r], xr);\n  \
    \    l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X prod_all()\
    \ { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n   \
    \ for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >>\
    \ i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int l2\
    \ = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++, a);\n    \
    \  if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2, r\
    \ = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n    int sz = 1 << (log -\
    \ topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k < size) {\n   \
    \   laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail) push(k), update(k);\n\
    \    }\n  }\n\n  void push(int k) {\n    if (laz[k] == MA::unit()) return;\n \
    \   apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n\
    \  }\n};\n#line 2 \"ds/segtree/beats_summinmax_chminchmax.hpp\"\n\r\ntemplate\
    \ <typename T>\r\nstruct Beats_SumMinMax_ChminChmax {\r\n  struct SumMinMax {\r\
    \n    struct X {\r\n      T sum, min, max, minc, maxc, min2, max2;\r\n      bool\
    \ fail;\r\n    };\r\n    using value_type = X;\r\n    static X op(const X& x,\
    \ const X& y) {\r\n      if (x.min > x.max) return y;\r\n      if (y.min > y.max)\
    \ return x;\r\n      X z;\r\n      z.sum = x.sum + y.sum;\r\n\r\n      z.min =\
    \ min(x.min, y.min), z.max = max(x.max, y.max);\r\n      z.minc = (x.min == z.min\
    \ ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\r\n      z.maxc = (x.max == z.max\
    \ ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\r\n\r\n      z.min2 = z.max;\r\
    \n      if (z.min < x.min && x.min < z.min2) z.min2 = x.min;\r\n      if (z.min\
    \ < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\r\n      if (z.min < y.min &&\
    \ y.min < z.min2) z.min2 = y.min;\r\n      if (z.min < y.min2 && y.min2 < z.min2)\
    \ z.min2 = y.min2;\r\n\r\n      z.max2 = z.min;\r\n      if (z.max > x.max &&\
    \ x.max > z.max2) z.max2 = x.max;\r\n      if (z.max > x.max2 && x.max2 > z.max2)\
    \ z.max2 = x.max2;\r\n      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\r\
    \n      if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\r\n\r\n      z.fail\
    \ = 0;\r\n      return z;\r\n    }\r\n    static constexpr X unit() {\r\n    \
    \  return {0, INF<T>, -INF<T>, 0, 0, INF<T>, -INF<T>, 0};\r\n    }\r\n    bool\
    \ commute = true;\r\n  };\r\n  struct AddChminChmax {\r\n    using X = tuple<T,\
    \ T, T>;\r\n    using value_type = X;\r\n    static constexpr X op(const X& x,\
    \ const X& y) {\r\n      auto [a, b, c] = x;\r\n      auto [d, e, f] = y;\r\n\
    \      a += d, b += d, c += d;\r\n      b = min(b, e), c = min(c, e), c = max(c,\
    \ f);\r\n      return {a, b, c};\r\n    }\r\n    static constexpr X unit() { return\
    \ {0, INF<T>, -INF<T>}; }\r\n    bool commute = false;\r\n  };\r\n  struct Beats\
    \ {\r\n    using Monoid_X = SumMinMax;\r\n    using Monoid_A = AddChminChmax;\r\
    \n    using X = typename Monoid_X::value_type;\r\n    using A = typename Monoid_A::value_type;\r\
    \n    static X act(X& x, const A& a, int cnt) {\r\n      assert(!x.fail);\r\n\
    \      if (x.min > x.max) return x;\r\n      auto [add, mi, ma] = a;\r\n     \
    \ x.sum += cnt * add;\r\n      x.min += add, x.max += add, x.min2 += add, x.max2\
    \ += add;\r\n\r\n      if (mi == INF<T> && ma == -INF<T>) return x;\r\n\r\n  \
    \    T before_min = x.min, before_max = x.max;\r\n      x.min = min(x.min, mi),\
    \ x.min = max(x.min, ma);\r\n      x.max = min(x.max, mi), x.max = max(x.max,\
    \ ma);\r\n\r\n      if (x.min == x.max) {\r\n        x.sum = x.max * cnt, x.max2\
    \ = x.min2 = x.max, x.maxc = x.minc = cnt;\r\n      }\r\n      elif (x.max2 <=\
    \ x.min) {\r\n        x.max2 = x.min, x.min2 = x.max, x.minc = cnt - x.maxc,\r\
    \n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min2\
    \ >= x.max) {\r\n        x.max2 = x.min, x.min2 = x.max, x.maxc = cnt - x.minc,\r\
    \n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min\
    \ < x.min2 && x.max > x.max2) {\r\n        x.sum += (x.min - before_min) * x.minc\
    \ + (x.max - before_max) * x.maxc;\r\n      }\r\n      else {\r\n        x.fail\
    \ = 1;\r\n      }\r\n      return x;\r\n    }\r\n  };\r\n\r\n  using X = typename\
    \ SumMinMax::X;\r\n  SegTree_Beats<Beats> seg;\r\n  Beats_SumMinMax_ChminChmax(vc<T>&\
    \ A) {\r\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\r\
    \n  }\r\n  template <typename F>\r\n  Beats_SumMinMax_ChminChmax(int n, F f) {\r\
    \n    seg.build(n, [&](int i) -> X { return from_element(f(i)); });\r\n  }\r\n\
    \  void set(int i, T x) { seg.set(i, from_element(x)); }\r\n\r\n  // (sum, max,\
    \ min)\r\n  tuple<T, T, T> prod(int l, int r) {\r\n    auto e = seg.prod(l, r);\r\
    \n    return {e.sum, e.min, e.max};\r\n  }\r\n  static X from_element(T x) { return\
    \ {x, x, x, 1, 1, x, x, 0}; }\r\n\r\n  void chmin(int l, int r, T x) { seg.apply(l,\
    \ r, {0, x, -INF<T>}); }\r\n  void chmax(int l, int r, T x) { seg.apply(l, r,\
    \ {0, INF<T>, x}); }\r\n  void add(int l, int r, T x) { seg.apply(l, r, {x, INF<T>,\
    \ -INF<T>}); }\r\n};\r\n"
  code: "#include \"ds/segtree/segtree_beats.hpp\"\r\n\r\ntemplate <typename T>\r\n\
    struct Beats_SumMinMax_ChminChmax {\r\n  struct SumMinMax {\r\n    struct X {\r\
    \n      T sum, min, max, minc, maxc, min2, max2;\r\n      bool fail;\r\n    };\r\
    \n    using value_type = X;\r\n    static X op(const X& x, const X& y) {\r\n \
    \     if (x.min > x.max) return y;\r\n      if (y.min > y.max) return x;\r\n \
    \     X z;\r\n      z.sum = x.sum + y.sum;\r\n\r\n      z.min = min(x.min, y.min),\
    \ z.max = max(x.max, y.max);\r\n      z.minc = (x.min == z.min ? x.minc : 0) +\
    \ (y.min == z.min ? y.minc : 0);\r\n      z.maxc = (x.max == z.max ? x.maxc :\
    \ 0) + (y.max == z.max ? y.maxc : 0);\r\n\r\n      z.min2 = z.max;\r\n      if\
    \ (z.min < x.min && x.min < z.min2) z.min2 = x.min;\r\n      if (z.min < x.min2\
    \ && x.min2 < z.min2) z.min2 = x.min2;\r\n      if (z.min < y.min && y.min < z.min2)\
    \ z.min2 = y.min;\r\n      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\r\
    \n\r\n      z.max2 = z.min;\r\n      if (z.max > x.max && x.max > z.max2) z.max2\
    \ = x.max;\r\n      if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\r\n\
    \      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\r\n      if (z.max\
    \ > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\r\n\r\n      z.fail = 0;\r\n \
    \     return z;\r\n    }\r\n    static constexpr X unit() {\r\n      return {0,\
    \ INF<T>, -INF<T>, 0, 0, INF<T>, -INF<T>, 0};\r\n    }\r\n    bool commute = true;\r\
    \n  };\r\n  struct AddChminChmax {\r\n    using X = tuple<T, T, T>;\r\n    using\
    \ value_type = X;\r\n    static constexpr X op(const X& x, const X& y) {\r\n \
    \     auto [a, b, c] = x;\r\n      auto [d, e, f] = y;\r\n      a += d, b += d,\
    \ c += d;\r\n      b = min(b, e), c = min(c, e), c = max(c, f);\r\n      return\
    \ {a, b, c};\r\n    }\r\n    static constexpr X unit() { return {0, INF<T>, -INF<T>};\
    \ }\r\n    bool commute = false;\r\n  };\r\n  struct Beats {\r\n    using Monoid_X\
    \ = SumMinMax;\r\n    using Monoid_A = AddChminChmax;\r\n    using X = typename\
    \ Monoid_X::value_type;\r\n    using A = typename Monoid_A::value_type;\r\n  \
    \  static X act(X& x, const A& a, int cnt) {\r\n      assert(!x.fail);\r\n   \
    \   if (x.min > x.max) return x;\r\n      auto [add, mi, ma] = a;\r\n      x.sum\
    \ += cnt * add;\r\n      x.min += add, x.max += add, x.min2 += add, x.max2 +=\
    \ add;\r\n\r\n      if (mi == INF<T> && ma == -INF<T>) return x;\r\n\r\n     \
    \ T before_min = x.min, before_max = x.max;\r\n      x.min = min(x.min, mi), x.min\
    \ = max(x.min, ma);\r\n      x.max = min(x.max, mi), x.max = max(x.max, ma);\r\
    \n\r\n      if (x.min == x.max) {\r\n        x.sum = x.max * cnt, x.max2 = x.min2\
    \ = x.max, x.maxc = x.minc = cnt;\r\n      }\r\n      elif (x.max2 <= x.min) {\r\
    \n        x.max2 = x.min, x.min2 = x.max, x.minc = cnt - x.maxc,\r\n        x.sum\
    \ = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min2 >= x.max)\
    \ {\r\n        x.max2 = x.min, x.min2 = x.max, x.maxc = cnt - x.minc,\r\n    \
    \    x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min\
    \ < x.min2 && x.max > x.max2) {\r\n        x.sum += (x.min - before_min) * x.minc\
    \ + (x.max - before_max) * x.maxc;\r\n      }\r\n      else {\r\n        x.fail\
    \ = 1;\r\n      }\r\n      return x;\r\n    }\r\n  };\r\n\r\n  using X = typename\
    \ SumMinMax::X;\r\n  SegTree_Beats<Beats> seg;\r\n  Beats_SumMinMax_ChminChmax(vc<T>&\
    \ A) {\r\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\r\
    \n  }\r\n  template <typename F>\r\n  Beats_SumMinMax_ChminChmax(int n, F f) {\r\
    \n    seg.build(n, [&](int i) -> X { return from_element(f(i)); });\r\n  }\r\n\
    \  void set(int i, T x) { seg.set(i, from_element(x)); }\r\n\r\n  // (sum, max,\
    \ min)\r\n  tuple<T, T, T> prod(int l, int r) {\r\n    auto e = seg.prod(l, r);\r\
    \n    return {e.sum, e.min, e.max};\r\n  }\r\n  static X from_element(T x) { return\
    \ {x, x, x, 1, 1, x, x, 0}; }\r\n\r\n  void chmin(int l, int r, T x) { seg.apply(l,\
    \ r, {0, x, -INF<T>}); }\r\n  void chmax(int l, int r, T x) { seg.apply(l, r,\
    \ {0, INF<T>, x}); }\r\n  void add(int l, int r, T x) { seg.apply(l, r, {x, INF<T>,\
    \ -INF<T>}); }\r\n};\r\n"
  dependsOn:
  - ds/segtree/segtree_beats.hpp
  isVerificationFile: false
  path: ds/segtree/beats_summinmax_chminchmax.hpp
  requiredBy: []
  timestamp: '2023-02-01 22:47:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: ds/segtree/beats_summinmax_chminchmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summinmax_chminchmax.hpp
- /library/ds/segtree/beats_summinmax_chminchmax.hpp.html
title: ds/segtree/beats_summinmax_chminchmax.hpp
---
