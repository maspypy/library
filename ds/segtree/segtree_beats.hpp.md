---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/segtree/beats_summax_chmin.hpp
    title: ds/segtree/beats_summax_chmin.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/beats_summin_chmax.hpp
    title: ds/segtree/beats_summin_chmax.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/beats_summinmax_chminchmax.hpp
    title: ds/segtree/beats_summinmax_chminchmax.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
    title: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1526.test.cpp
    title: test/yukicoder/1526.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1526_2.test.cpp
    title: test/yukicoder/1526_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \  }\n};\n"
  code: "#pragma once\n\ntemplate <typename ActedMonoid>\nstruct SegTree_Beats {\n\
    \  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA =\
    \ typename AM::Monoid_A;\n  using X = typename MX::value_type;\n  using A = typename\
    \ MA::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  SegTree_Beats()\
    \ {}\n  SegTree_Beats(int n) { build(n); }\n  template <typename F>\n  SegTree_Beats(int\
    \ n, F f) {\n    build(n, f);\n  }\n  SegTree_Beats(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n\
    \    dat.assign(size << 1, MX::unit());\n    laz.assign(size, MA::unit());\n \
    \   FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
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
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_beats.hpp
  requiredBy:
  - ds/segtree/beats_summinmax_chminchmax.hpp
  - ds/segtree/beats_summin_chmax.hpp
  - ds/segtree/beats_summax_chmin.hpp
  timestamp: '2023-01-31 23:12:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1526_2.test.cpp
  - test/yukicoder/1526.test.cpp
  - test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: ds/segtree/segtree_beats.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_beats.hpp
- /library/ds/segtree/segtree_beats.hpp.html
title: ds/segtree/segtree_beats.hpp
---
