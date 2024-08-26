---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree_beats.hpp
    title: ds/segtree/segtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d
    - https://codeforces.com/blog/entry/82094#comment-688448
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
    \  }\n};\n#line 2 \"ds/segtree/beats_kinetic.hpp\"\n\n// (x[i],y[i]) \u304B\u3089\
    \u306A\u308B\u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\u306B y[i] :- y[i] + ax[i]\
    \ + b \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\u308B\n// x \u306B\u306F\
    \u5358\u8ABF\u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1, y,sum(b):T2, T1*T1<=T2.\n\
    // https://codeforces.com/blog/entry/82094#comment-688448\n// https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\n\
    template <typename T1, typename T2>\nstruct Beats_Kinetic_Max {\n  struct Mono_X\
    \ {\n    struct X {\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n      bool\
    \ fail;\n    };\n    using value_type = X;\n    static X op(X L, X R) {\n    \
    \  X M;\n      if (L.y < R.y) { swap(L, R); }\n      M.x = L.x, M.y = L.y;\n \
    \     M.nxt_change = min(L.nxt_change, R.nxt_change);\n      if (L.x < R.x) {\n\
    \        T2 t = floor<T2>(L.y - R.y, R.x - L.x);\n        chmin(M.nxt_change,\
    \ t + 1);\n      }\n      M.fail = 0;\n      return M;\n    }\n    static constexpr\
    \ X unit() { return {0, -infty<T2>, infty<T1>, 0}; }\n    bool commute = true;\n\
    \  };\n  struct Mono_A {\n    using X = pair<T1, T2>;\n    using value_type =\
    \ X;\n    static constexpr X op(const X& x, const X& y) { return {x.fi + y.fi,\
    \ x.se + y.se}; }\n    static constexpr X unit() { return {0, 0}; }\n    bool\
    \ commute = true;\n  };\n  struct Beats {\n    using Monoid_X = Mono_X;\n    using\
    \ Monoid_A = Mono_A;\n    using X = typename Monoid_X::value_type;\n    using\
    \ A = typename Monoid_A::value_type;\n    static X act(X& M, const A& a, int cnt)\
    \ {\n      assert(!M.fail && a.fi >= 0);\n      if (M.nxt_change <= a.fi) {\n\
    \        M.fail = 1;\n        return M;\n      }\n      M.y += T2(a.fi) * M.x\
    \ + a.se;\n      M.nxt_change -= a.fi;\n      return M;\n    }\n  };\n  using\
    \ S = typename Mono_X::X;\n  SegTree_Beats<Beats> seg;\n  Beats_Kinetic_Max(vc<T1>&\
    \ X, vc<T2>& Y) {\n    seg.build(len(X), [&](int i) -> S { return {X[i], Y[i],\
    \ infty<T1>, 0}; });\n  }\n  template <typename F>\n  Beats_Kinetic_Max(int n,\
    \ F f) {\n    seg.build(n, [&](int i) -> S {\n      auto [x, y] = f(i);\n    \
    \  return {x, y, infty<T1>, 0};\n    });\n  }\n\n  void set(int i, T1 x, T2 y)\
    \ { seg.set(i, {x, y, infty<T1>, 0}); }\n\n  // (x,y)\n  pair<T1, T2> prod(int\
    \ l, int r) {\n    auto e = seg.prod(l, r);\n    return {e.x, e.y};\n  }\n  pair<T1,\
    \ T2> prod_all() {\n    auto e = seg.prod_all();\n    return {e.x, e.y};\n  }\n\
    \  void apply(int l, int r, T1 a, T2 b) { seg.apply(l, r, {a, b}); }\n};\n\n//\
    \ (x[i],y[i]) \u304B\u3089\u306A\u308B\u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\
    \u306B y[i] :- y[i] + ax[i] + b \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\
    \u308B\n// x \u306B\u306F\u5358\u8ABF\u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1,\
    \ y,sum(b):T2, T1*T1<=T2.\n// https://codeforces.com/blog/entry/82094#comment-688448\n\
    // https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\ntemplate <typename\
    \ T1, typename T2>\nstruct Beats_Kinetic_Min {\n  struct Mono_X {\n    struct\
    \ X {\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n      bool fail;\n    };\n\
    \    using value_type = X;\n    static X op(X L, X R) {\n      X M;\n      if\
    \ (L.y > R.y) { swap(L, R); }\n      M.x = L.x, M.y = L.y;\n      M.nxt_change\
    \ = min(L.nxt_change, R.nxt_change);\n      if (L.x > R.x) {\n        T2 t = floor<T2>(R.y\
    \ - L.y, L.x - R.x);\n        chmin(M.nxt_change, t + 1);\n      }\n      M.fail\
    \ = 0;\n      return M;\n    }\n    static constexpr X unit() { return {0, infty<T2>,\
    \ infty<T1>, 0}; }\n    bool commute = true;\n  };\n  struct Mono_A {\n    using\
    \ X = pair<T1, T2>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) { return {x.fi + y.fi, x.se + y.se}; }\n    static constexpr\
    \ X unit() { return {0, 0}; }\n    bool commute = true;\n  };\n  struct Beats\
    \ {\n    using Monoid_X = Mono_X;\n    using Monoid_A = Mono_A;\n    using X =\
    \ typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& M, const A& a, int cnt) {\n      assert(!M.fail && a.fi >=\
    \ 0);\n      if (M.nxt_change <= a.fi) {\n        M.fail = 1;\n        return\
    \ M;\n      }\n      M.y += T2(a.fi) * M.x + a.se;\n      M.nxt_change -= a.fi;\n\
    \      return M;\n    }\n  };\n  using S = typename Mono_X::X;\n  SegTree_Beats<Beats>\
    \ seg;\n  Beats_Kinetic_Min(vc<T1>& X, vc<T2>& Y) {\n    seg.build(len(X), [&](int\
    \ i) -> S { return {X[i], Y[i], infty<T1>, 0}; });\n  }\n  template <typename\
    \ F>\n  Beats_Kinetic_Min(int n, F f) {\n    seg.build(n, [&](int i) -> S {\n\
    \      auto [x, y] = f(i);\n      return {x, y, infty<T1>, 0};\n    });\n  }\n\
    \n  void set(int i, T1 x, T2 y) { seg.set(i, {x, y, infty<T1>, 0}); }\n\n  //\
    \ (x,y)\n  pair<T1, T2> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n \
    \   return {e.x, e.y};\n  }\n  pair<T1, T2> prod_all() {\n    auto e = seg.prod_all();\n\
    \    return {e.x, e.y};\n  }\n  void apply(int l, int r, T1 a, T2 b) { seg.apply(l,\
    \ r, {a, b}); }\n};\n"
  code: "#include \"ds/segtree/segtree_beats.hpp\"\n\n// (x[i],y[i]) \u304B\u3089\u306A\
    \u308B\u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\u306B y[i] :- y[i] + ax[i] +\
    \ b \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\u308B\n// x \u306B\u306F\u5358\
    \u8ABF\u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1, y,sum(b):T2, T1*T1<=T2.\n\
    // https://codeforces.com/blog/entry/82094#comment-688448\n// https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\n\
    template <typename T1, typename T2>\nstruct Beats_Kinetic_Max {\n  struct Mono_X\
    \ {\n    struct X {\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n      bool\
    \ fail;\n    };\n    using value_type = X;\n    static X op(X L, X R) {\n    \
    \  X M;\n      if (L.y < R.y) { swap(L, R); }\n      M.x = L.x, M.y = L.y;\n \
    \     M.nxt_change = min(L.nxt_change, R.nxt_change);\n      if (L.x < R.x) {\n\
    \        T2 t = floor<T2>(L.y - R.y, R.x - L.x);\n        chmin(M.nxt_change,\
    \ t + 1);\n      }\n      M.fail = 0;\n      return M;\n    }\n    static constexpr\
    \ X unit() { return {0, -infty<T2>, infty<T1>, 0}; }\n    bool commute = true;\n\
    \  };\n  struct Mono_A {\n    using X = pair<T1, T2>;\n    using value_type =\
    \ X;\n    static constexpr X op(const X& x, const X& y) { return {x.fi + y.fi,\
    \ x.se + y.se}; }\n    static constexpr X unit() { return {0, 0}; }\n    bool\
    \ commute = true;\n  };\n  struct Beats {\n    using Monoid_X = Mono_X;\n    using\
    \ Monoid_A = Mono_A;\n    using X = typename Monoid_X::value_type;\n    using\
    \ A = typename Monoid_A::value_type;\n    static X act(X& M, const A& a, int cnt)\
    \ {\n      assert(!M.fail && a.fi >= 0);\n      if (M.nxt_change <= a.fi) {\n\
    \        M.fail = 1;\n        return M;\n      }\n      M.y += T2(a.fi) * M.x\
    \ + a.se;\n      M.nxt_change -= a.fi;\n      return M;\n    }\n  };\n  using\
    \ S = typename Mono_X::X;\n  SegTree_Beats<Beats> seg;\n  Beats_Kinetic_Max(vc<T1>&\
    \ X, vc<T2>& Y) {\n    seg.build(len(X), [&](int i) -> S { return {X[i], Y[i],\
    \ infty<T1>, 0}; });\n  }\n  template <typename F>\n  Beats_Kinetic_Max(int n,\
    \ F f) {\n    seg.build(n, [&](int i) -> S {\n      auto [x, y] = f(i);\n    \
    \  return {x, y, infty<T1>, 0};\n    });\n  }\n\n  void set(int i, T1 x, T2 y)\
    \ { seg.set(i, {x, y, infty<T1>, 0}); }\n\n  // (x,y)\n  pair<T1, T2> prod(int\
    \ l, int r) {\n    auto e = seg.prod(l, r);\n    return {e.x, e.y};\n  }\n  pair<T1,\
    \ T2> prod_all() {\n    auto e = seg.prod_all();\n    return {e.x, e.y};\n  }\n\
    \  void apply(int l, int r, T1 a, T2 b) { seg.apply(l, r, {a, b}); }\n};\n\n//\
    \ (x[i],y[i]) \u304B\u3089\u306A\u308B\u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\
    \u306B y[i] :- y[i] + ax[i] + b \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\
    \u308B\n// x \u306B\u306F\u5358\u8ABF\u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1,\
    \ y,sum(b):T2, T1*T1<=T2.\n// https://codeforces.com/blog/entry/82094#comment-688448\n\
    // https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\ntemplate <typename\
    \ T1, typename T2>\nstruct Beats_Kinetic_Min {\n  struct Mono_X {\n    struct\
    \ X {\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n      bool fail;\n    };\n\
    \    using value_type = X;\n    static X op(X L, X R) {\n      X M;\n      if\
    \ (L.y > R.y) { swap(L, R); }\n      M.x = L.x, M.y = L.y;\n      M.nxt_change\
    \ = min(L.nxt_change, R.nxt_change);\n      if (L.x > R.x) {\n        T2 t = floor<T2>(R.y\
    \ - L.y, L.x - R.x);\n        chmin(M.nxt_change, t + 1);\n      }\n      M.fail\
    \ = 0;\n      return M;\n    }\n    static constexpr X unit() { return {0, infty<T2>,\
    \ infty<T1>, 0}; }\n    bool commute = true;\n  };\n  struct Mono_A {\n    using\
    \ X = pair<T1, T2>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) { return {x.fi + y.fi, x.se + y.se}; }\n    static constexpr\
    \ X unit() { return {0, 0}; }\n    bool commute = true;\n  };\n  struct Beats\
    \ {\n    using Monoid_X = Mono_X;\n    using Monoid_A = Mono_A;\n    using X =\
    \ typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& M, const A& a, int cnt) {\n      assert(!M.fail && a.fi >=\
    \ 0);\n      if (M.nxt_change <= a.fi) {\n        M.fail = 1;\n        return\
    \ M;\n      }\n      M.y += T2(a.fi) * M.x + a.se;\n      M.nxt_change -= a.fi;\n\
    \      return M;\n    }\n  };\n  using S = typename Mono_X::X;\n  SegTree_Beats<Beats>\
    \ seg;\n  Beats_Kinetic_Min(vc<T1>& X, vc<T2>& Y) {\n    seg.build(len(X), [&](int\
    \ i) -> S { return {X[i], Y[i], infty<T1>, 0}; });\n  }\n  template <typename\
    \ F>\n  Beats_Kinetic_Min(int n, F f) {\n    seg.build(n, [&](int i) -> S {\n\
    \      auto [x, y] = f(i);\n      return {x, y, infty<T1>, 0};\n    });\n  }\n\
    \n  void set(int i, T1 x, T2 y) { seg.set(i, {x, y, infty<T1>, 0}); }\n\n  //\
    \ (x,y)\n  pair<T1, T2> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n \
    \   return {e.x, e.y};\n  }\n  pair<T1, T2> prod_all() {\n    auto e = seg.prod_all();\n\
    \    return {e.x, e.y};\n  }\n  void apply(int l, int r, T1 a, T2 b) { seg.apply(l,\
    \ r, {a, b}); }\n};\n"
  dependsOn:
  - ds/segtree/segtree_beats.hpp
  isVerificationFile: false
  path: ds/segtree/beats_kinetic.hpp
  requiredBy: []
  timestamp: '2024-08-26 04:14:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_kinetic.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_kinetic.hpp
- /library/ds/segtree/beats_kinetic.hpp.html
title: ds/segtree/beats_kinetic.hpp
---
