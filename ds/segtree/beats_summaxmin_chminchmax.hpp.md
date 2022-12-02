---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/segtree/lazysegtree_beats.hpp
    title: ds/segtree/lazysegtree_beats.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ getall:\", get_all()); }\n};\n#line 2 \"ds/segtree/beats_summaxmin_chminchmax.hpp\"\
    \n\r\nconstexpr ll Beats_INF = 1LL << 40;\r\n\r\nstruct Beats_SumMaxMin_ChminChmax\
    \ {\r\n  struct CntSumMinMax {\r\n    struct X {\r\n      ll cnt, sum, min, max,\
    \ minc, maxc, min2, max2;\r\n      bool fail;\r\n    };\r\n    using value_type\
    \ = X;\r\n    static X op(const X& x, const X& y) {\r\n      if (x.min > x.max)\
    \ return y;\r\n      if (y.min > y.max) return x;\r\n      X z;\r\n      z.cnt\
    \ = x.cnt + y.cnt, z.sum = x.sum + y.sum;\r\n\r\n      z.min = min(x.min, y.min),\
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
    \ 0, Beats_INF, -Beats_INF, 0, 0, Beats_INF, -Beats_INF, 0};\r\n    }\r\n    bool\
    \ commute = true;\r\n  };\r\n  struct AddChminChmax {\r\n    using X = tuple<ll,\
    \ ll, ll>;\r\n    using value_type = X;\r\n    static constexpr X op(const X&\
    \ x, const X& y) {\r\n      auto [a, b, c] = x;\r\n      auto [d, e, f] = y;\r\
    \n      a += d, b += d, c += d;\r\n      b = min(b, e), c = min(c, e);\r\n   \
    \   c = max(c, f);\r\n      return {a, b, c};\r\n    }\r\n    static constexpr\
    \ X unit() { return {0, Beats_INF, -Beats_INF}; }\r\n    bool commute = false;\r\
    \n  };\r\n  struct Lazy {\r\n    using MX = CntSumMinMax;\r\n    using MA = AddChminChmax;\r\
    \n    using X_structure = MX;\r\n    using A_structure = MA;\r\n    using X =\
    \ MX::value_type;\r\n    using A = MA::value_type;\r\n    static X act(X& x, const\
    \ A& a) {\r\n      assert(!x.fail);\r\n      if (x.cnt == 0) return x;\r\n   \
    \   auto [add, mi, ma] = a;\r\n      x.sum += x.cnt * add;\r\n      x.min += add,\
    \ x.max += add;\r\n      x.min2 += add, x.max2 += add;\r\n\r\n      if (mi ==\
    \ Beats_INF && ma == -Beats_INF) return x;\r\n\r\n      ll before_min = x.min,\
    \ before_max = x.max;\r\n      x.min = min(x.min, mi);\r\n      x.min = max(x.min,\
    \ ma);\r\n      x.max = min(x.max, mi);\r\n      x.max = max(x.max, ma);\r\n\r\
    \n      if (x.min == x.max) {\r\n        x.sum = x.max * x.cnt;\r\n        x.max2\
    \ = x.min2 = x.max;\r\n        x.maxc = x.minc = x.cnt;\r\n      }\r\n      elif\
    \ (x.max2 <= x.min) {\r\n        x.max2 = x.min, x.min2 = x.max;\r\n        x.minc\
    \ = x.cnt - x.maxc;\r\n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n  \
    \    }\r\n      elif (x.min2 >= x.max) {\r\n        x.max2 = x.min, x.min2 = x.max;\r\
    \n        x.maxc = x.cnt - x.minc;\r\n        x.sum = x.max * x.maxc + x.min *\
    \ x.minc;\r\n      }\r\n      elif (x.min < x.min2 && x.max > x.max2) {\r\n  \
    \      x.sum += (x.min - before_min) * x.minc;\r\n        x.sum += (x.max - before_max)\
    \ * x.maxc;\r\n      }\r\n      else {\r\n        x.fail = 1;\r\n      }\r\n \
    \     return x;\r\n    }\r\n  };\r\n  LazySegTreeBeats<Lazy> seg;\r\n  Beats_SumMaxMin_ChminChmax(vc<ll>&\
    \ A) {\r\n    using X = Lazy::MX::value_type;\r\n    vc<X> seg_raw(len(A));\r\n\
    \    FOR(i, len(A)) {\r\n      ll x = A[i];\r\n      seg_raw[i] = {1, x, x, x,\
    \ 1, 1, x, x, 0};\r\n    }\r\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\r\n \
    \ }\r\n\r\n  void set(int i, ll x) { seg.set(i, {1, x, x, x, 1, 1, x, x, 0});\
    \ }\r\n\r\n  Lazy::MX::value_type prod(int l, int r) {\r\n    auto e = seg.prod(l,\
    \ r);\r\n    return e;\r\n  }\r\n\r\n  void chmin(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, x, -Beats_INF}); }\r\n\r\n  void chmax(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, Beats_INF, x}); }\r\n\r\n  void add(int l, int r, ll x) { seg.apply(l,\
    \ r, {x, Beats_INF, -Beats_INF}); }\r\n};\r\n"
  code: "#include \"ds/segtree/lazysegtree_beats.hpp\"\r\n\r\nconstexpr ll Beats_INF\
    \ = 1LL << 40;\r\n\r\nstruct Beats_SumMaxMin_ChminChmax {\r\n  struct CntSumMinMax\
    \ {\r\n    struct X {\r\n      ll cnt, sum, min, max, minc, maxc, min2, max2;\r\
    \n      bool fail;\r\n    };\r\n    using value_type = X;\r\n    static X op(const\
    \ X& x, const X& y) {\r\n      if (x.min > x.max) return y;\r\n      if (y.min\
    \ > y.max) return x;\r\n      X z;\r\n      z.cnt = x.cnt + y.cnt, z.sum = x.sum\
    \ + y.sum;\r\n\r\n      z.min = min(x.min, y.min), z.max = max(x.max, y.max);\r\
    \n      z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\r\
    \n      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\r\
    \n\r\n      z.min2 = z.max;\r\n      if (z.min < x.min && x.min < z.min2) z.min2\
    \ = x.min;\r\n      if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\r\n\
    \      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\r\n      if (z.min\
    \ < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\r\n\r\n      z.max2 = z.min;\r\
    \n      if (z.max > x.max && x.max > z.max2) z.max2 = x.max;\r\n      if (z.max\
    \ > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\r\n      if (z.max > y.max &&\
    \ y.max > z.max2) z.max2 = y.max;\r\n      if (z.max > y.max2 && y.max2 > z.max2)\
    \ z.max2 = y.max2;\r\n\r\n      z.fail = 0;\r\n      return z;\r\n    }\r\n  \
    \  static constexpr X unit() {\r\n      return {0, 0, Beats_INF, -Beats_INF, 0,\
    \ 0, Beats_INF, -Beats_INF, 0};\r\n    }\r\n    bool commute = true;\r\n  };\r\
    \n  struct AddChminChmax {\r\n    using X = tuple<ll, ll, ll>;\r\n    using value_type\
    \ = X;\r\n    static constexpr X op(const X& x, const X& y) {\r\n      auto [a,\
    \ b, c] = x;\r\n      auto [d, e, f] = y;\r\n      a += d, b += d, c += d;\r\n\
    \      b = min(b, e), c = min(c, e);\r\n      c = max(c, f);\r\n      return {a,\
    \ b, c};\r\n    }\r\n    static constexpr X unit() { return {0, Beats_INF, -Beats_INF};\
    \ }\r\n    bool commute = false;\r\n  };\r\n  struct Lazy {\r\n    using MX =\
    \ CntSumMinMax;\r\n    using MA = AddChminChmax;\r\n    using X_structure = MX;\r\
    \n    using A_structure = MA;\r\n    using X = MX::value_type;\r\n    using A\
    \ = MA::value_type;\r\n    static X act(X& x, const A& a) {\r\n      assert(!x.fail);\r\
    \n      if (x.cnt == 0) return x;\r\n      auto [add, mi, ma] = a;\r\n      x.sum\
    \ += x.cnt * add;\r\n      x.min += add, x.max += add;\r\n      x.min2 += add,\
    \ x.max2 += add;\r\n\r\n      if (mi == Beats_INF && ma == -Beats_INF) return\
    \ x;\r\n\r\n      ll before_min = x.min, before_max = x.max;\r\n      x.min =\
    \ min(x.min, mi);\r\n      x.min = max(x.min, ma);\r\n      x.max = min(x.max,\
    \ mi);\r\n      x.max = max(x.max, ma);\r\n\r\n      if (x.min == x.max) {\r\n\
    \        x.sum = x.max * x.cnt;\r\n        x.max2 = x.min2 = x.max;\r\n      \
    \  x.maxc = x.minc = x.cnt;\r\n      }\r\n      elif (x.max2 <= x.min) {\r\n \
    \       x.max2 = x.min, x.min2 = x.max;\r\n        x.minc = x.cnt - x.maxc;\r\n\
    \        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min2\
    \ >= x.max) {\r\n        x.max2 = x.min, x.min2 = x.max;\r\n        x.maxc = x.cnt\
    \ - x.minc;\r\n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n\
    \      elif (x.min < x.min2 && x.max > x.max2) {\r\n        x.sum += (x.min -\
    \ before_min) * x.minc;\r\n        x.sum += (x.max - before_max) * x.maxc;\r\n\
    \      }\r\n      else {\r\n        x.fail = 1;\r\n      }\r\n      return x;\r\
    \n    }\r\n  };\r\n  LazySegTreeBeats<Lazy> seg;\r\n  Beats_SumMaxMin_ChminChmax(vc<ll>&\
    \ A) {\r\n    using X = Lazy::MX::value_type;\r\n    vc<X> seg_raw(len(A));\r\n\
    \    FOR(i, len(A)) {\r\n      ll x = A[i];\r\n      seg_raw[i] = {1, x, x, x,\
    \ 1, 1, x, x, 0};\r\n    }\r\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\r\n \
    \ }\r\n\r\n  void set(int i, ll x) { seg.set(i, {1, x, x, x, 1, 1, x, x, 0});\
    \ }\r\n\r\n  Lazy::MX::value_type prod(int l, int r) {\r\n    auto e = seg.prod(l,\
    \ r);\r\n    return e;\r\n  }\r\n\r\n  void chmin(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, x, -Beats_INF}); }\r\n\r\n  void chmax(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, Beats_INF, x}); }\r\n\r\n  void add(int l, int r, ll x) { seg.apply(l,\
    \ r, {x, Beats_INF, -Beats_INF}); }\r\n};\r\n"
  dependsOn:
  - ds/segtree/lazysegtree_beats.hpp
  isVerificationFile: false
  path: ds/segtree/beats_summaxmin_chminchmax.hpp
  requiredBy: []
  timestamp: '2022-12-02 19:13:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_summaxmin_chminchmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summaxmin_chminchmax.hpp
- /library/ds/segtree/beats_summaxmin_chminchmax.hpp.html
title: ds/segtree/beats_summaxmin_chminchmax.hpp
---
