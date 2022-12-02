---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/acted_monoid/cntsum_affine.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/cntsum_affine.hpp\"\
    \n#include \"ds/splay/splaytree_acted_monoid.hpp\"\n\nconst int mod = 998244353;\n\
    \nstruct Node {\n  using value_type = int;\n  using operator_type = pair<int,\
    \ int>;\n  using X = value_type;\n  using A = operator_type;\n  using np = Node\
    \ *;\n\n  np p, l, r;\n  X x, prod;\n  A lazy;\n  u32 size;\n  bool rev;\n\n \
    \ static void new_node(np n, const X &x) {\n    n->p = n->l = n->r = nullptr;\n\
    \    n->x = n->prod = x;\n    n->lazy = {1, 0};\n    n->size = 1;\n    n->rev\
    \ = 0;\n  }\n\n  void update() {\n    size = 1;\n    prod = x;\n    if (l) {\n\
    \      size += l->size;\n      prod += l->prod;\n      if (prod >= mod) prod -=\
    \ mod;\n    }\n    if (r) {\n      size += r->size;\n      prod += r->prod;\n\
    \      if (prod >= mod) prod -= mod;\n    }\n  }\n\n  void prop() {\n    if (lazy\
    \ != A{1, 0}) {\n      ll a = lazy.fi, b = lazy.se;\n      if (l) {\n        l->x\
    \ = (a * (l->x) + b) % mod;\n        l->prod = (a * l->prod + b * l->size) % mod;\n\
    \        l->lazy = {a * l->lazy.fi % mod, (a * l->lazy.se + b) % mod};\n     \
    \ }\n      if (r) {\n        r->x = (a * (r->x) + b) % mod;\n        r->prod =\
    \ (a * r->prod + b * r->size) % mod;\n        r->lazy = {a * r->lazy.fi % mod,\
    \ (a * r->lazy.se + b) % mod};\n      }\n      lazy = {1, 0};\n    }\n    if (rev)\
    \ {\n      if (l) {\n        l->rev ^= 1;\n        swap(l->l, l->r);\n      }\n\
    \      if (r) {\n        r->rev ^= 1;\n        swap(r->l, r->r);\n      }\n  \
    \    rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\u308C\
    \u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\
    \u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\
    \u3066\u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  void apply(const A &aa)\
    \ {\n    ll a = aa.fi, b = aa.se;\n    x = (a * x + b) % mod;\n    prod = (a *\
    \ prod + b * size) % mod;\n    lazy = {a * lazy.fi % mod, (a * lazy.se + b) %\
    \ mod};\n  }\n  void reverse() {\n    swap(l, r);\n    rev ^= 1;\n  }\n};\n\n\
    void solve() {\n  // size \u3092 2 \u91CD\u306B\u6301\u305F\u305B\u3066\u3044\u308B\
    \u306E\u3092\u89E3\u9664\u3059\u308B\n  SplayTree<Node, 1'000'000> X;\n\n  INT(N,\
    \ Q);\n  VEC(int, dat, N);\n\n  auto root = X.new_node(dat);\n\n  FOR(Q) {\n \
    \   INT(t);\n    if (t == 0) {\n      INT(i, x);\n      auto [a, b] = X.split(root,\
    \ i);\n      root = X.merge3(a, X.new_node(x), b);\n    }\n    if (t == 1) {\n\
    \      INT(i);\n      auto [a, b, c] = X.split3(root, i, i + 1);\n      root =\
    \ X.merge(a, c);\n    }\n    if (t == 2) {\n      INT(L, R);\n      X.reverse(root,\
    \ L, R);\n    }\n    if (t == 3) {\n      INT(L, R, b, c);\n      X.apply(root,\
    \ L, R, {b, c});\n    }\n    if (t == 4) {\n      INT(L, R);\n      print(X.prod(root,\
    \ L, R));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp.html
title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
---
