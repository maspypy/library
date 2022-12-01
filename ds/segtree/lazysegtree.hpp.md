---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/ds/lazytreemonoid.hpp
    title: graph/ds/lazytreemonoid.hpp
  - icon: ':x:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1234.test.cpp
    title: test/yukicoder/1234.test.cpp
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
    path: test/yukicoder/749.test.cpp
    title: test/yukicoder/749.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899.test.cpp
    title: test/yukicoder/899.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/lazysegtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct LazySegTree {\n  using Monoid_X = typename ActedMonoid::Monoid_X;\n  using\
    \ Monoid_A = typename ActedMonoid::Monoid_A;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
    \ Monoid_X::unit())) {}\n  LazySegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid_X::unit());\n    laz.assign(size, Monoid_A::unit());\n    FOR(i,\
    \ n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  template\
    \ <typename F>\n  LazySegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit());\n\
    \    laz.assign(size, Monoid_A::unit());\n    FOR(i, n) dat[size + i] = f(i);\n\
    \    FOR3_R(i, 1, size) update(i);\n  }\n\n  void reset() {\n    fill(all(dat),\
    \ Monoid_X::unit());\n    fill(all(laz), Monoid_A::unit());\n  }\n\n  void reset(const\
    \ vc<X>& v) {\n    assert(len(v) == n);\n    reset();\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }\n\n  void all_apply(int\
    \ k, A a) {\n    dat[k] = ActedMonoid::act(dat[k], a);\n    if (k < size) laz[k]\
    \ = Monoid_A::op(laz[k], a);\n  }\n\n  void push(int k) {\n    all_apply(2 * k,\
    \ laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit();\n\
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
    \    p += size;\n    dat[p] = ActedMonoid::act(dat[p], a);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r, A a) {\n \
    \   assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\n    l += size;\n\
    \    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
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
    \ while ((r & -r) != r);\n    return 0;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename ActedMonoid>\nstruct LazySegTree {\n \
    \ using Monoid_X = typename ActedMonoid::Monoid_X;\n  using Monoid_A = typename\
    \ ActedMonoid::Monoid_A;\n  using X = typename Monoid_X::value_type;\n  using\
    \ A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A>\
    \ laz;\n\n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
    \ Monoid_X::unit())) {}\n  LazySegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid_X::unit());\n    laz.assign(size, Monoid_A::unit());\n    FOR(i,\
    \ n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  template\
    \ <typename F>\n  LazySegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit());\n\
    \    laz.assign(size, Monoid_A::unit());\n    FOR(i, n) dat[size + i] = f(i);\n\
    \    FOR3_R(i, 1, size) update(i);\n  }\n\n  void reset() {\n    fill(all(dat),\
    \ Monoid_X::unit());\n    fill(all(laz), Monoid_A::unit());\n  }\n\n  void reset(const\
    \ vc<X>& v) {\n    assert(len(v) == n);\n    reset();\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }\n\n  void all_apply(int\
    \ k, A a) {\n    dat[k] = ActedMonoid::act(dat[k], a);\n    if (k < size) laz[k]\
    \ = Monoid_A::op(laz[k], a);\n  }\n\n  void push(int k) {\n    all_apply(2 * k,\
    \ laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit();\n\
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
    \    p += size;\n    dat[p] = ActedMonoid::act(dat[p], a);\n    for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n  }\n\n  void apply(int l, int r, A a) {\n \
    \   assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\n    l += size;\n\
    \    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) <<\
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
    \ while ((r & -r) != r);\n    return 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/lazysegtree.hpp
  requiredBy:
  - seq/common_interval_decomposition.hpp
  - graph/ds/lazytreemonoid.hpp
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/899.test.cpp
  - test/yukicoder/749.test.cpp
  - test/yukicoder/1234.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1720.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/GRL_5_E.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_H.test.cpp
documentation_of: ds/segtree/lazysegtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/lazysegtree.hpp
- /library/ds/segtree/lazysegtree.hpp.html
title: ds/segtree/lazysegtree.hpp
---
