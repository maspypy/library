---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/ds/dualtreemonoid.hpp
    title: graph/ds/dualtreemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_point_add.test.cpp
    title: test/library_checker/datastructure/range_affine_point_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1524.test.cpp
    title: test/yukicoder/1524.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/913.test.cpp
    title: test/yukicoder/913.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/dualsegtree.hpp\"\n\ntemplate <typename Monoid>\nstruct\
    \ DualSegTree {\n  using A = typename Monoid::value_type;\n  int n, log, size;\n\
    \  vc<A> laz;\n\n  DualSegTree() : DualSegTree(0) {}\n  DualSegTree(int n) { resize(n);\
    \ }\n\n  void reset() { fill(all(laz), Monoid::unit()); }\n  void resize(int n_)\
    \ {\n    n = n_;\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size =\
    \ 1 << log;\n    laz.assign(size << 1, Monoid::unit());\n  }\n\n  void all_apply(int\
    \ k, A a) { laz[k] = Monoid::op(laz[k], a); }\n\n  A get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n    FOR(i, size) push(i);\n\
    \    return {laz.begin() + size, laz.begin() + size + n};\n  }\n\n  void apply(int\
    \ l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\
    \n    l += size;\n    r += size;\n\n    if (!Monoid::commute) {\n      for (int\
    \ i = log; i >= 1; i--) {\n        if (((l >> i) << i) != l) push(l >> i);\n \
    \       if (((r >> i) << i) != r) push((r - 1) >> i);\n      }\n    }\n\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) all_apply(l++,\
    \ a);\n        if (r & 1) all_apply(--r, a);\n        l >>= 1;\n        r >>=\
    \ 1;\n      }\n      l = l2;\n      r = r2;\n    }\n  }\n  void debug() { print(\"\
    dualsegtree getall:\", get_all()); }\n\nprivate:\n  void push(int k) {\n    all_apply(2\
    \ * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid::unit();\n\
    \  }\n};\n"
  code: "#pragma once\n\ntemplate <typename Monoid>\nstruct DualSegTree {\n  using\
    \ A = typename Monoid::value_type;\n  int n, log, size;\n  vc<A> laz;\n\n  DualSegTree()\
    \ : DualSegTree(0) {}\n  DualSegTree(int n) { resize(n); }\n\n  void reset() {\
    \ fill(all(laz), Monoid::unit()); }\n  void resize(int n_) {\n    n = n_;\n  \
    \  log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    laz.assign(size\
    \ << 1, Monoid::unit());\n  }\n\n  void all_apply(int k, A a) { laz[k] = Monoid::op(laz[k],\
    \ a); }\n\n  A get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n  \
    \  for (int i = log; i >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n \
    \ vc<A> get_all() {\n    FOR(i, size) push(i);\n    return {laz.begin() + size,\
    \ laz.begin() + size + n};\n  }\n\n  void apply(int l, int r, A a) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return;\n\n    l += size;\n    r\
    \ += size;\n\n    if (!Monoid::commute) {\n      for (int i = log; i >= 1; i--)\
    \ {\n        if (((l >> i) << i) != l) push(l >> i);\n        if (((r >> i) <<\
    \ i) != r) push((r - 1) >> i);\n      }\n    }\n\n    {\n      int l2 = l, r2\
    \ = r;\n      while (l < r) {\n        if (l & 1) all_apply(l++, a);\n       \
    \ if (r & 1) all_apply(--r, a);\n        l >>= 1;\n        r >>= 1;\n      }\n\
    \      l = l2;\n      r = r2;\n    }\n  }\n  void debug() { print(\"dualsegtree\
    \ getall:\", get_all()); }\n\nprivate:\n  void push(int k) {\n    all_apply(2\
    \ * k, laz[k]);\n    all_apply(2 * k + 1, laz[k]);\n    laz[k] = Monoid::unit();\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/dualsegtree.hpp
  requiredBy:
  - graph/ds/dualtreemonoid.hpp
  timestamp: '2022-10-28 17:48:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/913.test.cpp
  - test/yukicoder/1524.test.cpp
  - test/library_checker/datastructure/range_affine_point_add.test.cpp
documentation_of: ds/dualsegtree.hpp
layout: document
redirect_from:
- /library/ds/dualsegtree.hpp
- /library/ds/dualsegtree.hpp.html
title: ds/dualsegtree.hpp
---
