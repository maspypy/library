---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree/segtree_beats.hpp
    title: ds/segtree/segtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
    title: test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/segtree/beats_summinmax_chminchmax.hpp
  bundledCode: "#line 1 \"ds/segtree/beats_summinmax_chminchmax.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/ds/segtree/beats_summinmax_chminchmax.hpp\n\
    #line 1 \"ds/segtree/segtree_beats.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/segtree_beats.hpp\n\
    \ntemplate <typename ActedMonoid>\nstruct SegTree_Beats {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  SegTree_Beats() {}\n  SegTree_Beats(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree_Beats(int n, F f) {\n \
    \   build(n, f);\n  }\n  SegTree_Beats(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n  }\n  void\
    \ build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n\
    \  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log = 0;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::id());\n    laz.assign(size, MA::id());\n    FOR(i, n) dat[size +\
    \ i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void update(int k) {\
    \ dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void set(int p, X x) {\n \
    \   assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n\
    \  /*\n  void all_apply(int k, A a) {\n    dat[k] = ActedMonoid::act(dat[k], a);\n\
    \    if (k < size) {\n      laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail)\
    \ push(k), update(k);\n    }\n  }\n  */\n\n  vc<X> get_all() {\n    FOR(k, 1,\
    \ size) { push(k); }\n    return {dat.begin() + size, dat.begin() + size + n};\n\
    \  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n  \
    \  if (l == r) return MX::id();\n    l += size, r += size;\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl = MX::id(), xr = MX::id();\n\
    \    while (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r\
    \ & 1) xr = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n    return\
    \ MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int\
    \ l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1)\
    \ apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n     \
    \ if (((l >> i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n    }\n  }\n\n private:\n  void apply_at(int k, A a) {\n    int\
    \ sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k\
    \ < size) {\n      laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail) push(k),\
    \ update(k);\n    }\n  }\n\n  void push(int k) {\n    if (laz[k] == MA::id())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::id();\n  }\n};\n#line 3 \"ds/segtree/beats_summinmax_chminchmax.hpp\"\n\
    \ntemplate <typename T>\nstruct Beats_SumMinMax_ChminChmax {\n  struct SumMinMax\
    \ {\n    struct X {\n      T sum, min, max, minc, maxc, min2, max2;\n      bool\
    \ fail;\n    };\n    using value_type = X;\n    static X op(const X& x, const\
    \ X& y) {\n      if (x.min > x.max) return y;\n      if (y.min > y.max) return\
    \ x;\n      X z;\n      z.sum = x.sum + y.sum;\n\n      z.min = min(x.min, y.min),\
    \ z.max = max(x.max, y.max);\n      z.minc = (x.min == z.min ? x.minc : 0) + (y.min\
    \ == z.min ? y.minc : 0);\n      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max\
    \ == z.max ? y.maxc : 0);\n\n      z.min2 = z.max;\n      if (z.min < x.min &&\
    \ x.min < z.min2) z.min2 = x.min;\n      if (z.min < x.min2 && x.min2 < z.min2)\
    \ z.min2 = x.min2;\n      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\n\
    \      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\n\n      z.max2\
    \ = z.min;\n      if (z.max > x.max && x.max > z.max2) z.max2 = x.max;\n     \
    \ if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\n      if (z.max > y.max\
    \ && y.max > z.max2) z.max2 = y.max;\n      if (z.max > y.max2 && y.max2 > z.max2)\
    \ z.max2 = y.max2;\n\n      z.fail = 0;\n      return z;\n    }\n    static constexpr\
    \ X id() {\n      return {0, infty<T>, -infty<T>, 0, 0, infty<T>, -infty<T>, 0};\n\
    \    }\n    bool commute = true;\n  };\n  struct AddChminChmax {\n    using X\
    \ = tuple<T, T, T>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) {\n      auto [a, b, c] = x;\n      auto [d, e, f] = y;\n\
    \      a += d, b += d, c += d;\n      b = min(b, e), c = min(c, e), c = max(c,\
    \ f);\n      return {a, b, c};\n    }\n    static constexpr X id() { return {0,\
    \ infty<T>, -infty<T>}; }\n    bool commute = false;\n  };\n  struct Beats {\n\
    \    using Monoid_X = SumMinMax;\n    using Monoid_A = AddChminChmax;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& x, const A& a, int cnt) {\n      assert(!x.fail);\n     \
    \ if (x.min > x.max) return x;\n      auto [add, mi, ma] = a;\n      x.sum +=\
    \ cnt * add;\n      x.min += add, x.max += add, x.min2 += add, x.max2 += add;\n\
    \n      if (mi == infty<T> && ma == -infty<T>) return x;\n\n      T before_min\
    \ = x.min, before_max = x.max;\n      x.min = min(x.min, mi), x.min = max(x.min,\
    \ ma);\n      x.max = min(x.max, mi), x.max = max(x.max, ma);\n\n      if (x.min\
    \ == x.max) {\n        x.sum = x.max * cnt, x.max2 = x.min2 = x.max, x.maxc =\
    \ x.minc = cnt;\n      }\n      elif (x.max2 <= x.min) {\n        x.max2 = x.min,\
    \ x.min2 = x.max, x.minc = cnt - x.maxc,\n        x.sum = x.max * x.maxc + x.min\
    \ * x.minc;\n      }\n      elif (x.min2 >= x.max) {\n        x.max2 = x.min,\
    \ x.min2 = x.max, x.maxc = cnt - x.minc,\n        x.sum = x.max * x.maxc + x.min\
    \ * x.minc;\n      }\n      elif (x.min < x.min2 && x.max > x.max2) {\n      \
    \  x.sum += (x.min - before_min) * x.minc + (x.max - before_max) * x.maxc;\n \
    \     }\n      else {\n        x.fail = 1;\n      }\n      return x;\n    }\n\
    \  };\n\n  using X = typename SumMinMax::X;\n  SegTree_Beats<Beats> seg;\n  Beats_SumMinMax_ChminChmax(vc<T>&\
    \ A) {\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\n\
    \  }\n  template <typename F>\n  Beats_SumMinMax_ChminChmax(int n, F f) {\n  \
    \  seg.build(n, [&](int i) -> X { return from_element(f(i)); });\n  }\n  void\
    \ set(int i, T x) { seg.set(i, from_element(x)); }\n\n  // (sum, max, min)\n \
    \ tuple<T, T, T> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n    return\
    \ {e.sum, e.min, e.max};\n  }\n  static X from_element(T x) { return {x, x, x,\
    \ 1, 1, x, x, 0}; }\n\n  void chmin(int l, int r, T x) { seg.apply(l, r, {0, x,\
    \ -infty<T>}); }\n  void chmax(int l, int r, T x) { seg.apply(l, r, {0, infty<T>,\
    \ x}); }\n  void add(int l, int r, T x) { seg.apply(l, r, {x, infty<T>, -infty<T>});\
    \ }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/segtree/beats_summinmax_chminchmax.hpp\n\
    #include \"ds/segtree/segtree_beats.hpp\"\n\ntemplate <typename T>\nstruct Beats_SumMinMax_ChminChmax\
    \ {\n  struct SumMinMax {\n    struct X {\n      T sum, min, max, minc, maxc,\
    \ min2, max2;\n      bool fail;\n    };\n    using value_type = X;\n    static\
    \ X op(const X& x, const X& y) {\n      if (x.min > x.max) return y;\n      if\
    \ (y.min > y.max) return x;\n      X z;\n      z.sum = x.sum + y.sum;\n\n    \
    \  z.min = min(x.min, y.min), z.max = max(x.max, y.max);\n      z.minc = (x.min\
    \ == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\n      z.maxc = (x.max\
    \ == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\n\n      z.min2 = z.max;\n\
    \      if (z.min < x.min && x.min < z.min2) z.min2 = x.min;\n      if (z.min <\
    \ x.min2 && x.min2 < z.min2) z.min2 = x.min2;\n      if (z.min < y.min && y.min\
    \ < z.min2) z.min2 = y.min;\n      if (z.min < y.min2 && y.min2 < z.min2) z.min2\
    \ = y.min2;\n\n      z.max2 = z.min;\n      if (z.max > x.max && x.max > z.max2)\
    \ z.max2 = x.max;\n      if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\n\
    \      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\n      if (z.max >\
    \ y.max2 && y.max2 > z.max2) z.max2 = y.max2;\n\n      z.fail = 0;\n      return\
    \ z;\n    }\n    static constexpr X id() {\n      return {0, infty<T>, -infty<T>,\
    \ 0, 0, infty<T>, -infty<T>, 0};\n    }\n    bool commute = true;\n  };\n  struct\
    \ AddChminChmax {\n    using X = tuple<T, T, T>;\n    using value_type = X;\n\
    \    static constexpr X op(const X& x, const X& y) {\n      auto [a, b, c] = x;\n\
    \      auto [d, e, f] = y;\n      a += d, b += d, c += d;\n      b = min(b, e),\
    \ c = min(c, e), c = max(c, f);\n      return {a, b, c};\n    }\n    static constexpr\
    \ X id() { return {0, infty<T>, -infty<T>}; }\n    bool commute = false;\n  };\n\
    \  struct Beats {\n    using Monoid_X = SumMinMax;\n    using Monoid_A = AddChminChmax;\n\
    \    using X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& x, const A& a, int cnt) {\n      assert(!x.fail);\n     \
    \ if (x.min > x.max) return x;\n      auto [add, mi, ma] = a;\n      x.sum +=\
    \ cnt * add;\n      x.min += add, x.max += add, x.min2 += add, x.max2 += add;\n\
    \n      if (mi == infty<T> && ma == -infty<T>) return x;\n\n      T before_min\
    \ = x.min, before_max = x.max;\n      x.min = min(x.min, mi), x.min = max(x.min,\
    \ ma);\n      x.max = min(x.max, mi), x.max = max(x.max, ma);\n\n      if (x.min\
    \ == x.max) {\n        x.sum = x.max * cnt, x.max2 = x.min2 = x.max, x.maxc =\
    \ x.minc = cnt;\n      }\n      elif (x.max2 <= x.min) {\n        x.max2 = x.min,\
    \ x.min2 = x.max, x.minc = cnt - x.maxc,\n        x.sum = x.max * x.maxc + x.min\
    \ * x.minc;\n      }\n      elif (x.min2 >= x.max) {\n        x.max2 = x.min,\
    \ x.min2 = x.max, x.maxc = cnt - x.minc,\n        x.sum = x.max * x.maxc + x.min\
    \ * x.minc;\n      }\n      elif (x.min < x.min2 && x.max > x.max2) {\n      \
    \  x.sum += (x.min - before_min) * x.minc + (x.max - before_max) * x.maxc;\n \
    \     }\n      else {\n        x.fail = 1;\n      }\n      return x;\n    }\n\
    \  };\n\n  using X = typename SumMinMax::X;\n  SegTree_Beats<Beats> seg;\n  Beats_SumMinMax_ChminChmax(vc<T>&\
    \ A) {\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\n\
    \  }\n  template <typename F>\n  Beats_SumMinMax_ChminChmax(int n, F f) {\n  \
    \  seg.build(n, [&](int i) -> X { return from_element(f(i)); });\n  }\n  void\
    \ set(int i, T x) { seg.set(i, from_element(x)); }\n\n  // (sum, max, min)\n \
    \ tuple<T, T, T> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n    return\
    \ {e.sum, e.min, e.max};\n  }\n  static X from_element(T x) { return {x, x, x,\
    \ 1, 1, x, x, 0}; }\n\n  void chmin(int l, int r, T x) { seg.apply(l, r, {0, x,\
    \ -infty<T>}); }\n  void chmax(int l, int r, T x) { seg.apply(l, r, {0, infty<T>,\
    \ x}); }\n  void add(int l, int r, T x) { seg.apply(l, r, {x, infty<T>, -infty<T>});\
    \ }\n};\n"
  dependsOn:
  - ds/segtree/segtree_beats.hpp
  isVerificationFile: false
  path: ds/segtree/beats_summinmax_chminchmax.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: ds/segtree/beats_summinmax_chminchmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summinmax_chminchmax.hpp
- /library/ds/segtree/beats_summinmax_chminchmax.hpp.html
title: ds/segtree/beats_summinmax_chminchmax.hpp
---
