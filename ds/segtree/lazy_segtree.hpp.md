---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/ds/lazy_tree_monoid.hpp
    title: graph/ds/lazy_tree_monoid.hpp
  - icon: ':x:'
    path: other/rectangle_union.hpp
    title: other/rectangle_union.hpp
  - icon: ':x:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_4_A.test.cpp
    title: test/aoj/DSL_4_A.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
    title: test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/common_interval_decomposition.test.cpp
    title: test/library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':x:'
    path: test/mytest/max_assign.test.cpp
    title: test/mytest/max_assign.test.cpp
  - icon: ':x:'
    path: test/mytest/max_max.test.cpp
    title: test/mytest/max_max.test.cpp
  - icon: ':x:'
    path: test/mytest/max_min.test.cpp
    title: test/mytest/max_min.test.cpp
  - icon: ':x:'
    path: test/mytest/maxidx_add.test.cpp
    title: test/mytest/maxidx_add.test.cpp
  - icon: ':x:'
    path: test/mytest/min_max.test.cpp
    title: test/mytest/min_max.test.cpp
  - icon: ':x:'
    path: test/mytest/min_min.test.cpp
    title: test/mytest/min_min.test.cpp
  - icon: ':x:'
    path: test/mytest/minidx_add.test.cpp
    title: test/mytest/minidx_add.test.cpp
  - icon: ':x:'
    path: test/mytest/minmax_add.test.cpp
    title: test/mytest/minmax_add.test.cpp
  - icon: ':x:'
    path: test/mytest/summax_add.test.cpp
    title: test/mytest/summax_add.test.cpp
  - icon: ':x:'
    path: test/mytest/summax_assign.test.cpp
    title: test/mytest/summax_assign.test.cpp
  - icon: ':x:'
    path: test/mytest/summin_add.test.cpp
    title: test/mytest/summin_add.test.cpp
  - icon: ':x:'
    path: test/mytest/summin_assign.test.cpp
    title: test/mytest/summin_assign.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1234.test.cpp
    title: test/yukicoder/1234.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1548.test.cpp
    title: test/yukicoder/1548.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1720.test.cpp
    title: test/yukicoder/1720.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':x:'
    path: test/yukicoder/255.test.cpp
    title: test/yukicoder/255.test.cpp
  - icon: ':x:'
    path: test/yukicoder/749.test.cpp
    title: test/yukicoder/749.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899.test.cpp
    title: test/yukicoder/899.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n\
    \  using MA = typename AM::Monoid_A;\n  static_assert(MX::commute);\n  using X\
    \ = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n, log,\
    \ size;\n  vc<X> dat;\n  vc<A> laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int n, F f) {\n  \
    \  build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n \
    \   FOR(k, 1, size) { push(k); }\n    return {dat.begin() + size, dat.begin()\
    \ + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    if (l == r) return MX::unit();\n    l += size, r += size;\n  \
    \  for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >>\
    \ i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X x = MX::unit();\n\
    \    while (l < r) {\n      if (l & 1) x = MX::op(x, dat[l++]);\n      if (r &\
    \ 1) x = MX::op(x, dat[--r]);\n      l >>= 1, r >>= 1;\n    }\n    return x;\n\
    \  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n\
    \    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size,\
    \ r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i)\
    \ != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n \
    \   }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++,\
    \ a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n  \
    \  l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i)\
    \ << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1)\
    \ >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F check,\
    \ int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n  \
    \  if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l >>= 1;\n\
    \      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n       \
    \   push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
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
    \ = MA::unit();\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree {\n\
    \  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA =\
    \ typename AM::Monoid_A;\n  static_assert(MX::commute);\n  using X = typename\
    \ MX::value_type;\n  using A = typename MA::value_type;\n  int n, log, size;\n\
    \  vc<X> dat;\n  vc<A> laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int n) { build(n);\
    \ }\n  template <typename F>\n  Lazy_SegTree(int n, F f) {\n    build(n, f);\n\
    \  }\n  Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n \
    \   FOR(k, 1, size) { push(k); }\n    return {dat.begin() + size, dat.begin()\
    \ + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    if (l == r) return MX::unit();\n    l += size, r += size;\n  \
    \  for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >>\
    \ i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X x = MX::unit();\n\
    \    while (l < r) {\n      if (l & 1) x = MX::op(x, dat[l++]);\n      if (r &\
    \ 1) x = MX::op(x, dat[--r]);\n      l >>= 1, r >>= 1;\n    }\n    return x;\n\
    \  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n\
    \    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size,\
    \ r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i)\
    \ != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n \
    \   }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++,\
    \ a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n  \
    \  l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i)\
    \ << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1)\
    \ >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F check,\
    \ int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n  \
    \  if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l >>= 1;\n\
    \      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n       \
    \   push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
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
    \ = MA::unit();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/lazy_segtree.hpp
  requiredBy:
  - other/rectangle_union.hpp
  - seq/common_interval_decomposition.hpp
  - graph/ds/lazy_tree_monoid.hpp
  timestamp: '2022-12-04 21:11:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/899.test.cpp
  - test/yukicoder/749.test.cpp
  - test/yukicoder/1234.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1720.test.cpp
  - test/yukicoder/1270.test.cpp
  - test/yukicoder/255.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/yukicoder/1548.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/mytest/min_max.test.cpp
  - test/mytest/summax_add.test.cpp
  - test/mytest/minidx_add.test.cpp
  - test/mytest/maxidx_add.test.cpp
  - test/mytest/summin_add.test.cpp
  - test/mytest/minmax_add.test.cpp
  - test/mytest/max_max.test.cpp
  - test/mytest/summax_assign.test.cpp
  - test/mytest/min_min.test.cpp
  - test/mytest/max_min.test.cpp
  - test/mytest/summin_assign.test.cpp
  - test/mytest/max_assign.test.cpp
  - test/library_checker/datastructure/area_of_union_of_rectangles.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - test/library_checker/graph/common_interval_decomposition.test.cpp
  - test/aoj/DSL_4_A.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/GRL_5_E.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_H.test.cpp
documentation_of: ds/segtree/lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/lazy_segtree.hpp
- /library/ds/segtree/lazy_segtree.hpp.html
title: ds/segtree/lazy_segtree.hpp
---
