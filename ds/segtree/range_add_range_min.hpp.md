---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_min.test.cpp
    title: test/1_mytest/range_add_range_min.test.cpp
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
    \  }\n};\n#line 2 \"ds/segtree/range_add_range_min.hpp\"\n\n// INF+x==INF \u307F\
    \u305F\u3044\u306A\u51E6\u7406\u306F\u5165\u308C\u3066\u3044\u306A\u3044\n// N=Q=10^6\
    \ \u3067 lazysegtree \u3088\u308A 40% \u7A0B\u5EA6\u9AD8\u901F\ntemplate <typename\
    \ T>\nstruct Range_Add_Range_Min {\n  struct Mono {\n    using value_type = pair<T,\
    \ T>;\n    using X = value_type;\n    static X op(X L, X R) { return {L.fi + R.fi,\
    \ min(L.se, L.fi + R.se)}; }\n    static constexpr X unit() { return {0, infty<ll>};\
    \ }\n    static constexpr bool commute = false;\n  };\n  int n;\n  SegTree<Mono>\
    \ seg;\n\n  Range_Add_Range_Min() {}\n  Range_Add_Range_Min(int n) { build(n);\
    \ }\n  template <typename F>\n  Range_Add_Range_Min(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Range_Add_Range_Min(const vc<T>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> T { return infty<T>; });\n  }\n  void build(const\
    \ vc<T>& v) {\n    build(len(v), [&](int i) -> T { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m;\n    T pre = 0;\n    seg.build(n,\
    \ [&](int i) -> pair<T, T> {\n      T t = f(i) - pre;\n      pre += t;\n     \
    \ return {t, t};\n    });\n  }\n\n  T prod(int L, int R) {\n    if (L == R) return\
    \ infty<T>;\n    ll ans = seg.prod(L, R).se;\n    L += seg.size;\n    for (; L\
    \ > 0; L /= 2) {\n      if (L & 1) ans += seg.dat[--L].fi;\n    }\n    return\
    \ ans;\n  }\n\n  void apply(int L, int R, T x) {\n    T l = seg.get(L).fi + x;\n\
    \    seg.set(L, {l, l});\n    if (R == n) return;\n    T r = seg.get(R).fi - x;\n\
    \    seg.set(R, {r, r});\n  }\n};\n"
  code: "#include \"ds/segtree/segtree.hpp\"\n\n// INF+x==INF \u307F\u305F\u3044\u306A\
    \u51E6\u7406\u306F\u5165\u308C\u3066\u3044\u306A\u3044\n// N=Q=10^6 \u3067 lazysegtree\
    \ \u3088\u308A 40% \u7A0B\u5EA6\u9AD8\u901F\ntemplate <typename T>\nstruct Range_Add_Range_Min\
    \ {\n  struct Mono {\n    using value_type = pair<T, T>;\n    using X = value_type;\n\
    \    static X op(X L, X R) { return {L.fi + R.fi, min(L.se, L.fi + R.se)}; }\n\
    \    static constexpr X unit() { return {0, infty<ll>}; }\n    static constexpr\
    \ bool commute = false;\n  };\n  int n;\n  SegTree<Mono> seg;\n\n  Range_Add_Range_Min()\
    \ {}\n  Range_Add_Range_Min(int n) { build(n); }\n  template <typename F>\n  Range_Add_Range_Min(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Range_Min(const vc<T>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> T { return infty<T>; });\n\
    \  }\n  void build(const vc<T>& v) {\n    build(len(v), [&](int i) -> T { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m;\n    T pre = 0;\n    seg.build(n, [&](int i) -> pair<T, T> {\n      T t =\
    \ f(i) - pre;\n      pre += t;\n      return {t, t};\n    });\n  }\n\n  T prod(int\
    \ L, int R) {\n    if (L == R) return infty<T>;\n    ll ans = seg.prod(L, R).se;\n\
    \    L += seg.size;\n    for (; L > 0; L /= 2) {\n      if (L & 1) ans += seg.dat[--L].fi;\n\
    \    }\n    return ans;\n  }\n\n  void apply(int L, int R, T x) {\n    T l = seg.get(L).fi\
    \ + x;\n    seg.set(L, {l, l});\n    if (R == n) return;\n    T r = seg.get(R).fi\
    \ - x;\n    seg.set(R, {r, r});\n  }\n};"
  dependsOn:
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: ds/segtree/range_add_range_min.hpp
  requiredBy: []
  timestamp: '2025-01-29 14:09:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/range_add_range_min.test.cpp
documentation_of: ds/segtree/range_add_range_min.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_add_range_min.hpp
- /library/ds/segtree/range_add_range_min.hpp.html
title: ds/segtree/range_add_range_min.hpp
---
