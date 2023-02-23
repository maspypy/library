---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_monoid/minmincnt_add.hpp
    title: alg/acted_monoid/minmincnt_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/minmincnt.hpp
    title: alg/monoid/minmincnt.hpp
  - icon: ':x:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_4_A.test.cpp
    title: test/aoj/DSL_4_A.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n\
    \  using MA = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n \
    \ using A = typename MA::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A>\
    \ laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int n) { build(n); }\n  template\
    \ <typename F>\n  Lazy_SegTree(int n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const\
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
    \    return dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k);\
    \ }\n    return {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return\
    \ MX::unit();\n    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n\
    \      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n    }\n    X xl = MX::unit(), xr = MX::unit();\n    while\
    \ (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr\
    \ = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl,\
    \ xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r,\
    \ A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n \
    \   l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1)\
    \ apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n     \
    \ if (((l >> i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F\
    \ check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l\
    \ >>= 1;\n      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n\
    \          push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
    \ { sm = MX::op(sm, dat[l++]); }\n        }\n        return l - size;\n      }\n\
    \      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n\
    \  }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>=\
    \ 1;\n      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n  \
    \        push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r],\
    \ sm))) { sm = MX::op(dat[r--], sm); }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r) != r);\n    return\
    \ 0;\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n    ll sz = 1 << (log -\
    \ topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k < size) laz[k]\
    \ = MA::op(laz[k], a);\n  }\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\
    \u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\n\
    struct Monoid_MinMincnt {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    auto [xmin, xmincnt] = x;\r\n    auto [ymin,\
    \ ymincnt] = y;\r\n    if (xmin > ymin) return {ymin, ymincnt};\r\n    if (xmin\
    \ == ymin) return {xmin, xmincnt + ymincnt};\r\n    return {xmin, xmincnt};\r\n\
    \  }\r\n  static constexpr X unit() { return {infty<E>, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/minmincnt_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_MinMincnt_Add {\r\n  using Monoid_X\
    \ = Monoid_MinMincnt<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    auto [xmin,\
    \ xmincnt] = x;\r\n    if (xmin == infty<E>) return x;\r\n    return {xmin + a,\
    \ xmincnt};\r\n  }\r\n};\r\n#line 3 \"other/rectangle_union.hpp\"\n\r\ntemplate\
    \ <typename XY = int>\r\nstruct Rectangle_Union {\r\n  using RECT = tuple<XY,\
    \ XY, XY, XY>;\r\n  vc<RECT> rectangles;\r\n  vc<XY> X, Y;\r\n\r\n  void add_rect(int\
    \ xl, int xr, int yl, int yr) {\r\n    assert(xl < xr && yl < yr);\r\n    X.eb(xl),\
    \ X.eb(xr), Y.eb(yl), Y.eb(yr);\r\n    rectangles.eb(xl, xr, yl, yr);\r\n  }\r\
    \n\r\n  template <typename ANS_TYPE = ll>\r\n  ANS_TYPE calc() {\r\n    UNIQUE(X),\
    \ UNIQUE(Y);\r\n    int N = len(X);\r\n    vc<vc<pair<int, int>>> add(N), rm(N);\r\
    \n    for (auto &&[xl, xr, yl, yr]: rectangles) {\r\n      xl = LB(X, xl), xr\
    \ = LB(X, xr);\r\n      yl = LB(Y, yl), yr = LB(Y, yr);\r\n      add[xl].eb(yl,\
    \ yr);\r\n      rm[xr].eb(yl, yr);\r\n    }\r\n\r\n    using AM = ActedMonoid_MinMincnt_Add<XY>;\r\
    \n    using T = typename AM::Monoid_X::value_type;\r\n    Lazy_SegTree<AM> seg(len(Y)\
    \ - 1, [&](int i) -> T {\r\n      return {0, Y[i + 1] - Y[i]};\r\n    });\r\n\
    \    ANS_TYPE ANS = 0;\r\n    FOR(i, len(X) - 1) {\r\n      ANS_TYPE dx = X[i\
    \ + 1] - X[i];\r\n      for (auto &&[yl, yr]: add[i]) seg.apply(yl, yr, 1);\r\n\
    \      for (auto &&[yl, yr]: rm[i]) seg.apply(yl, yr, -1);\r\n      auto [min,\
    \ mincnt] = seg.prod_all();\r\n      ANS_TYPE n = Y.back() - Y[0];\r\n      if\
    \ (min == 0) n -= mincnt;\r\n      ANS += n * dx;\r\n    }\r\n    return ANS;\r\
    \n  }\r\n};\r\n"
  code: "#include \"ds/segtree/lazy_segtree.hpp\"\r\n#include \"alg/acted_monoid/minmincnt_add.hpp\"\
    \r\n\r\ntemplate <typename XY = int>\r\nstruct Rectangle_Union {\r\n  using RECT\
    \ = tuple<XY, XY, XY, XY>;\r\n  vc<RECT> rectangles;\r\n  vc<XY> X, Y;\r\n\r\n\
    \  void add_rect(int xl, int xr, int yl, int yr) {\r\n    assert(xl < xr && yl\
    \ < yr);\r\n    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);\r\n    rectangles.eb(xl,\
    \ xr, yl, yr);\r\n  }\r\n\r\n  template <typename ANS_TYPE = ll>\r\n  ANS_TYPE\
    \ calc() {\r\n    UNIQUE(X), UNIQUE(Y);\r\n    int N = len(X);\r\n    vc<vc<pair<int,\
    \ int>>> add(N), rm(N);\r\n    for (auto &&[xl, xr, yl, yr]: rectangles) {\r\n\
    \      xl = LB(X, xl), xr = LB(X, xr);\r\n      yl = LB(Y, yl), yr = LB(Y, yr);\r\
    \n      add[xl].eb(yl, yr);\r\n      rm[xr].eb(yl, yr);\r\n    }\r\n\r\n    using\
    \ AM = ActedMonoid_MinMincnt_Add<XY>;\r\n    using T = typename AM::Monoid_X::value_type;\r\
    \n    Lazy_SegTree<AM> seg(len(Y) - 1, [&](int i) -> T {\r\n      return {0, Y[i\
    \ + 1] - Y[i]};\r\n    });\r\n    ANS_TYPE ANS = 0;\r\n    FOR(i, len(X) - 1)\
    \ {\r\n      ANS_TYPE dx = X[i + 1] - X[i];\r\n      for (auto &&[yl, yr]: add[i])\
    \ seg.apply(yl, yr, 1);\r\n      for (auto &&[yl, yr]: rm[i]) seg.apply(yl, yr,\
    \ -1);\r\n      auto [min, mincnt] = seg.prod_all();\r\n      ANS_TYPE n = Y.back()\
    \ - Y[0];\r\n      if (min == 0) n -= mincnt;\r\n      ANS += n * dx;\r\n    }\r\
    \n    return ANS;\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/minmincnt_add.hpp
  - alg/monoid/minmincnt.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: other/rectangle_union.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  - test/aoj/DSL_4_A.test.cpp
documentation_of: other/rectangle_union.hpp
layout: document
redirect_from:
- /library/other/rectangle_union.hpp
- /library/other/rectangle_union.hpp.html
title: other/rectangle_union.hpp
---
