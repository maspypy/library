---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree/lazysegtree_beats.hpp
    title: ds/segtree/lazysegtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1526.test.cpp
    title: test/yukicoder/1526.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/lazysegtree_beats.hpp\"\n\ntemplate <typename\
    \ Lazy>\nstruct LazySegTreeBeats {\n  using Monoid_X = typename Lazy::X_structure;\n\
    \  using Monoid_A = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTreeBeats() : LazySegTreeBeats(0) {}\n  LazySegTreeBeats(int\
    \ n) : LazySegTreeBeats(vc<X>(n, Monoid_X::unit())) {}\n  LazySegTreeBeats(vc<X>\
    \ v) : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit());\n    laz.assign(size,\
    \ Monoid_A::unit());\n    FOR(i, n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size)\
    \ update(i);\n  }\n\n  void update(int k) { dat[k] = Monoid_X::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n\n  void all_apply(int k, A a) {\n    dat[k] = Lazy::act(dat[k],\
    \ a);\n    if (k < size) {\n      laz[k] = Monoid_A::op(laz[k], a);\n      if\
    \ (dat[k].fail) push(k), update(k);\n    }\n  }\n\n  void push(int k) {\n    all_apply(2\
    \ * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit();\n\
    \  }\n\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(i, size) push(i);\n\
    \    return {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return\
    \ Monoid_X::unit();\n\n    l += size;\n    r += size;\n\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    X xl = Monoid_X::unit(),\
    \ xr = Monoid_X::unit();\n    while (l < r) {\n      if (l & 1) xl = Monoid_X::op(xl,\
    \ dat[l++]);\n      if (r & 1) xr = Monoid_X::op(dat[--r], xr);\n      l >>= 1;\n\
    \      r >>= 1;\n    }\n\n    return Monoid_X::op(xl, xr);\n  }\n\n  X prod_all()\
    \ { return dat[1]; }\n\n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    if (!Monoid_A::commute)\n      for (int i = log; i >= 1;\
    \ i--) push(p >> i);\n    dat[p] = Lazy::act(dat[p], a);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r, A a) {\n \
    \   assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \    }\n\n    {\n      int l2 = l, r2 = r;\n      while (l < r) {\n        if\
    \ (l & 1) all_apply(l++, a);\n        if (r & 1) all_apply(--r, a);\n        l\
    \ >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n \
    \   for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) update(l\
    \ >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n\
    \  template <typename C>\n  int max_right(C& check, int l) {\n    assert(0 <=\
    \ l && l <= n);\n    assert(check(Monoid_X::unit()));\n    if (l == n) return\
    \ n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n    X\
    \ sm = Monoid_X::unit();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if\
    \ (!check(Monoid_X::op(sm, dat[l]))) {\n        while (l < size) {\n         \
    \ push(l);\n          l = (2 * l);\n          if (check(Monoid_X::op(sm, dat[l])))\
    \ {\n            sm = Monoid_X::op(sm, dat[l]);\n            l++;\n          }\n\
    \        }\n        return l - size;\n      }\n      sm = Monoid_X::op(sm, dat[l]);\n\
    \      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n  template <typename\
    \ C>\n  int min_left(C& check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(Monoid_X::unit()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = Monoid_X::unit();\n    do {\n      r--;\n  \
    \    while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(Monoid_X::op(dat[r],\
    \ sm))) {\n        while (r < size) {\n          push(r);\n          r = (2 *\
    \ r + 1);\n          if (check(Monoid_X::op(dat[r], sm))) {\n            sm =\
    \ Monoid_X::op(dat[r], sm);\n            r--;\n          }\n        }\n      \
    \  return r + 1 - size;\n      }\n      sm = Monoid_X::op(dat[r], sm);\n    }\
    \ while ((r & -r) != r);\n    return 0;\n  }\n\n  void debug() { print(\"lazysegtree\
    \ getall:\", get_all()); }\n};\n#line 2 \"ds/segtree/beats_summin_chmax.hpp\"\n\
    \nconstexpr ll Beats_INF = 1LL << 40;\n\nstruct Beats_SumMin_Chmax {\n  struct\
    \ CntSumMin {\n    struct X {\n      ll cnt, sum, min, minc, min2;\n      bool\
    \ fail;\n    };\n    using value_type = X;\n    static X op(const X& x, const\
    \ X& y) {\n      if (x.cnt == 0) return y;\n      if (y.cnt == 0) return x;\n\
    \      X z;\n      z.cnt = x.cnt + y.cnt, z.sum = x.sum + y.sum;\n\n      z.min\
    \ = min(x.min, y.min);\n      z.minc = (x.min == z.min ? x.minc : 0) + (y.min\
    \ == z.min ? y.minc : 0);\n\n      z.min2 = Beats_INF;\n      if (z.min < x.min\
    \ && x.min < z.min2) z.min2 = x.min;\n      if (z.min < x.min2 && x.min2 < z.min2)\
    \ z.min2 = x.min2;\n      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\n\
    \      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\n\n      z.fail\
    \ = 0;\n      return z;\n    }\n    static constexpr X unit() { return {0, 0,\
    \ 0, 0, 0, 0}; }\n    bool commute = true;\n  };\n  struct AddChmax {\n    using\
    \ X = pi;\n    using value_type = X;\n    static constexpr X op(const X& x, const\
    \ X& y) {\n      auto [a, c] = x;\n      auto [d, f] = y;\n      a += d, c +=\
    \ d;\n      c = max(c, f);\n      return {a, c};\n    }\n    static constexpr\
    \ X unit() { return {0, -Beats_INF}; }\n    bool commute = false;\n  };\n  struct\
    \ Lazy {\n    using MX = CntSumMin;\n    using MA = AddChmax;\n    using X_structure\
    \ = MX;\n    using A_structure = MA;\n    using X = MX::value_type;\n    using\
    \ A = MA::value_type;\n    static X act(X& x, const A& a) {\n      if (x.cnt ==\
    \ 0) return x;\n      assert(!x.fail);\n      auto [add, ma] = a;\n      x.sum\
    \ += x.cnt * add;\n      x.min += add, x.min2 += add;\n      if (ma == -Beats_INF)\
    \ return x;\n\n      ll before_min = x.min;\n      x.min = max(x.min, ma);\n \
    \     if (x.minc == x.cnt) {\n        x.min2 = x.min;\n        x.sum = x.cnt *\
    \ x.min;\n        return x;\n      }\n      if (x.min2 > x.min) {\n        x.sum\
    \ += (x.min - before_min) * x.minc;\n      } else {\n        x.fail = 1;\n   \
    \   }\n      return x;\n    }\n  };\n  LazySegTreeBeats<Lazy> seg;\n  Beats_SumMin_Chmax(vc<ll>&\
    \ A) {\n    using X = Lazy::MX::value_type;\n    vc<X> seg_raw(len(A));\n    FOR(i,\
    \ len(A)) {\n      ll x = A[i];\n      seg_raw[i] = {1, x, x, 1, x};\n    }\n\
    \    seg = LazySegTreeBeats<Lazy>(seg_raw);\n  }\n\n  void set(int i, ll x) {\
    \ seg.set(i, {1, x, x, 1, x}); }\n\n  Lazy::MX::value_type prod(int l, int r)\
    \ {\n    auto e = seg.prod(l, r);\n    return e;\n  }\n\n  void chmax(int l, int\
    \ r, ll x) { seg.apply(l, r, {0, x}); }\n\n  void add(int l, int r, ll x) { seg.apply(l,\
    \ r, {x, -Beats_INF}); }\n\n  void apply(int l, int r, pi addchmax) { seg.apply(l,\
    \ r, addchmax); }\n};\n"
  code: "#include \"ds/segtree/lazysegtree_beats.hpp\"\n\nconstexpr ll Beats_INF =\
    \ 1LL << 40;\n\nstruct Beats_SumMin_Chmax {\n  struct CntSumMin {\n    struct\
    \ X {\n      ll cnt, sum, min, minc, min2;\n      bool fail;\n    };\n    using\
    \ value_type = X;\n    static X op(const X& x, const X& y) {\n      if (x.cnt\
    \ == 0) return y;\n      if (y.cnt == 0) return x;\n      X z;\n      z.cnt =\
    \ x.cnt + y.cnt, z.sum = x.sum + y.sum;\n\n      z.min = min(x.min, y.min);\n\
    \      z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\n\
    \n      z.min2 = Beats_INF;\n      if (z.min < x.min && x.min < z.min2) z.min2\
    \ = x.min;\n      if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\n  \
    \    if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\n      if (z.min < y.min2\
    \ && y.min2 < z.min2) z.min2 = y.min2;\n\n      z.fail = 0;\n      return z;\n\
    \    }\n    static constexpr X unit() { return {0, 0, 0, 0, 0, 0}; }\n    bool\
    \ commute = true;\n  };\n  struct AddChmax {\n    using X = pi;\n    using value_type\
    \ = X;\n    static constexpr X op(const X& x, const X& y) {\n      auto [a, c]\
    \ = x;\n      auto [d, f] = y;\n      a += d, c += d;\n      c = max(c, f);\n\
    \      return {a, c};\n    }\n    static constexpr X unit() { return {0, -Beats_INF};\
    \ }\n    bool commute = false;\n  };\n  struct Lazy {\n    using MX = CntSumMin;\n\
    \    using MA = AddChmax;\n    using X_structure = MX;\n    using A_structure\
    \ = MA;\n    using X = MX::value_type;\n    using A = MA::value_type;\n    static\
    \ X act(X& x, const A& a) {\n      if (x.cnt == 0) return x;\n      assert(!x.fail);\n\
    \      auto [add, ma] = a;\n      x.sum += x.cnt * add;\n      x.min += add, x.min2\
    \ += add;\n      if (ma == -Beats_INF) return x;\n\n      ll before_min = x.min;\n\
    \      x.min = max(x.min, ma);\n      if (x.minc == x.cnt) {\n        x.min2 =\
    \ x.min;\n        x.sum = x.cnt * x.min;\n        return x;\n      }\n      if\
    \ (x.min2 > x.min) {\n        x.sum += (x.min - before_min) * x.minc;\n      }\
    \ else {\n        x.fail = 1;\n      }\n      return x;\n    }\n  };\n  LazySegTreeBeats<Lazy>\
    \ seg;\n  Beats_SumMin_Chmax(vc<ll>& A) {\n    using X = Lazy::MX::value_type;\n\
    \    vc<X> seg_raw(len(A));\n    FOR(i, len(A)) {\n      ll x = A[i];\n      seg_raw[i]\
    \ = {1, x, x, 1, x};\n    }\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\n  }\n\
    \n  void set(int i, ll x) { seg.set(i, {1, x, x, 1, x}); }\n\n  Lazy::MX::value_type\
    \ prod(int l, int r) {\n    auto e = seg.prod(l, r);\n    return e;\n  }\n\n \
    \ void chmax(int l, int r, ll x) { seg.apply(l, r, {0, x}); }\n\n  void add(int\
    \ l, int r, ll x) { seg.apply(l, r, {x, -Beats_INF}); }\n\n  void apply(int l,\
    \ int r, pi addchmax) { seg.apply(l, r, addchmax); }\n};\n"
  dependsOn:
  - ds/segtree/lazysegtree_beats.hpp
  isVerificationFile: false
  path: ds/segtree/beats_summin_chmax.hpp
  requiredBy: []
  timestamp: '2022-12-02 19:13:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1526.test.cpp
documentation_of: ds/segtree/beats_summin_chmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summin_chmax.hpp
- /library/ds/segtree/beats_summin_chmax.hpp.html
title: ds/segtree/beats_summin_chmax.hpp
---
