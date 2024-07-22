---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree_beats.hpp
    title: ds/segtree/segtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1526_2.test.cpp
    title: test/yukicoder/1526_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \  }\n};\n#line 2 \"ds/segtree/beats_summax_chmin.hpp\"\ntemplate <typename T>\n\
    struct Beats_SumMax_Chmin {\n  struct SumMax {\n    struct X {\n      T sum, max,\
    \ maxc, max2;\n      bool fail;\n    };\n    using value_type = X;\n    static\
    \ X op(const X& x, const X& y) {\n      if (x.max == -infty<T>) return y;\n  \
    \    if (y.max == -infty<T>) return x;\n      X z;\n      z.sum = x.sum + y.sum;\n\
    \n      z.max = max(x.max, y.max);\n      z.maxc = (x.max == z.max ? x.maxc :\
    \ 0) + (y.max == z.max ? y.maxc : 0);\n\n      z.max2 = -infty<T>;\n      if (z.max\
    \ > x.max && x.max > z.max2) z.max2 = x.max;\n      if (z.max > x.max2 && x.max2\
    \ > z.max2) z.max2 = x.max2;\n      if (z.max > y.max && y.max > z.max2) z.max2\
    \ = y.max;\n      if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\n\n\
    \      z.fail = 0;\n      return z;\n    }\n    static constexpr X unit() { return\
    \ {0, -infty<T>, 0, -infty<T>, 0}; }\n    bool commute = true;\n  };\n  struct\
    \ AddChmin {\n    using X = pair<T, T>;\n    using value_type = X;\n    static\
    \ constexpr X op(const X& x, const X& y) {\n      auto [a, b] = x;\n      auto\
    \ [d, e] = y;\n      a += d, b += d, b = min(b, e);\n      return {a, b};\n  \
    \  }\n    static constexpr X unit() { return {0, infty<T>}; }\n    bool commute\
    \ = false;\n  };\n  struct Beats {\n    using Monoid_X = SumMax;\n    using Monoid_A\
    \ = AddChmin;\n    using X = typename Monoid_X::value_type;\n    using A = typename\
    \ Monoid_A::value_type;\n    static X act(X& x, const A& a, int cnt) {\n     \
    \ assert(!x.fail);\n      if (x.max == -infty<T>) return x;\n      auto [add,\
    \ mi] = a;\n      x.sum += cnt * add, x.max += add, x.max2 += add;\n\n      if\
    \ (mi == infty<T>) return x;\n\n      T before_max = x.max;\n      x.max = min(x.max,\
    \ mi);\n      if (x.maxc == cnt) { x.max2 = x.max, x.sum = cnt * x.max; }\n  \
    \    elif (x.max2 < x.max) { x.sum += (x.max - before_max) * x.maxc; }\n     \
    \ else {\n        x.fail = 1;\n      }\n      return x;\n    }\n  };\n  using\
    \ X = typename SumMax::X;\n  SegTree_Beats<Beats> seg;\n  Beats_SumMax_Chmin(vc<T>&\
    \ A) {\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\n\
    \  }\n  template <typename F>\n  Beats_SumMax_Chmin(int n, F f) {\n    seg.build(n,\
    \ [&](int i) -> X { return from_element(f(i)); });\n  }\n\n  void set(int i, T\
    \ x) { seg.set(i, from_element(x)); }\n\n  // (sum, max)\n  pair<T, T> prod(int\
    \ l, int r) {\n    auto e = seg.prod(l, r);\n    return {e.sum, e.max};\n  }\n\
    \  static X from_element(T x) { return {x, x, 1, x}; }\n\n  void chmin(int l,\
    \ int r, ll x) { seg.apply(l, r, {0, x}); }\n  void add(int l, int r, ll x) {\
    \ seg.apply(l, r, {x, infty<T>}); }\n};\n"
  code: "#include \"ds/segtree/segtree_beats.hpp\"\ntemplate <typename T>\nstruct\
    \ Beats_SumMax_Chmin {\n  struct SumMax {\n    struct X {\n      T sum, max, maxc,\
    \ max2;\n      bool fail;\n    };\n    using value_type = X;\n    static X op(const\
    \ X& x, const X& y) {\n      if (x.max == -infty<T>) return y;\n      if (y.max\
    \ == -infty<T>) return x;\n      X z;\n      z.sum = x.sum + y.sum;\n\n      z.max\
    \ = max(x.max, y.max);\n      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max\
    \ == z.max ? y.maxc : 0);\n\n      z.max2 = -infty<T>;\n      if (z.max > x.max\
    \ && x.max > z.max2) z.max2 = x.max;\n      if (z.max > x.max2 && x.max2 > z.max2)\
    \ z.max2 = x.max2;\n      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\n\
    \      if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\n\n      z.fail\
    \ = 0;\n      return z;\n    }\n    static constexpr X unit() { return {0, -infty<T>,\
    \ 0, -infty<T>, 0}; }\n    bool commute = true;\n  };\n  struct AddChmin {\n \
    \   using X = pair<T, T>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) {\n      auto [a, b] = x;\n      auto [d, e] = y;\n      a\
    \ += d, b += d, b = min(b, e);\n      return {a, b};\n    }\n    static constexpr\
    \ X unit() { return {0, infty<T>}; }\n    bool commute = false;\n  };\n  struct\
    \ Beats {\n    using Monoid_X = SumMax;\n    using Monoid_A = AddChmin;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& x, const A& a, int cnt) {\n      assert(!x.fail);\n     \
    \ if (x.max == -infty<T>) return x;\n      auto [add, mi] = a;\n      x.sum +=\
    \ cnt * add, x.max += add, x.max2 += add;\n\n      if (mi == infty<T>) return\
    \ x;\n\n      T before_max = x.max;\n      x.max = min(x.max, mi);\n      if (x.maxc\
    \ == cnt) { x.max2 = x.max, x.sum = cnt * x.max; }\n      elif (x.max2 < x.max)\
    \ { x.sum += (x.max - before_max) * x.maxc; }\n      else {\n        x.fail =\
    \ 1;\n      }\n      return x;\n    }\n  };\n  using X = typename SumMax::X;\n\
    \  SegTree_Beats<Beats> seg;\n  Beats_SumMax_Chmin(vc<T>& A) {\n    seg.build(len(A),\
    \ [&](int i) -> X { return from_element(A[i]); });\n  }\n  template <typename\
    \ F>\n  Beats_SumMax_Chmin(int n, F f) {\n    seg.build(n, [&](int i) -> X { return\
    \ from_element(f(i)); });\n  }\n\n  void set(int i, T x) { seg.set(i, from_element(x));\
    \ }\n\n  // (sum, max)\n  pair<T, T> prod(int l, int r) {\n    auto e = seg.prod(l,\
    \ r);\n    return {e.sum, e.max};\n  }\n  static X from_element(T x) { return\
    \ {x, x, 1, x}; }\n\n  void chmin(int l, int r, ll x) { seg.apply(l, r, {0, x});\
    \ }\n  void add(int l, int r, ll x) { seg.apply(l, r, {x, infty<T>}); }\n};\n"
  dependsOn:
  - ds/segtree/segtree_beats.hpp
  isVerificationFile: false
  path: ds/segtree/beats_summax_chmin.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1526_2.test.cpp
documentation_of: ds/segtree/beats_summax_chmin.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summax_chmin.hpp
- /library/ds/segtree/beats_summax_chmin.hpp.html
title: ds/segtree/beats_summax_chmin.hpp
---
