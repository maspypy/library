---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/splay/splaytree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/splay/splaytree.hpp\"\n\nnamespace SplayTreeNodes {\ntemplate\
    \ <typename ActedMonoid>\nstruct Node_AM {\n  using Monoid_A = typename ActedMonoid::Monoid_A;\n\
    \  using Monoid_X = typename ActedMonoid::Monoid_X;\n  using A = typename Monoid_A::value_type;\n\
    \  using X = typename Monoid_X::value_type;\n  using value_type = X;\n  using\
    \ operator_type = A;\n  using np = Node_AM *;\n\n  np p, l, r;\n  X x, prod;\n\
    \  A lazy;\n  u32 size;\n  bool rev;\n\n  static void new_node(np n, const X &x)\
    \ {\n    n->p = n->l = n->r = nullptr;\n    n->x = n->prod = x;\n    n->lazy =\
    \ Monoid_A::unit();\n    n->size = 1;\n    n->rev = 0;\n  }\n\n  void update()\
    \ {\n    size = 1;\n    prod = x;\n    if (l) {\n      size += l->size;\n    \
    \  prod = Monoid_X::op(l->prod, prod);\n    }\n    if (r) {\n      size += r->size;\n\
    \      prod = Monoid_X::op(prod, r->prod);\n    }\n  }\n\n  void prop() {\n  \
    \  if (lazy != Monoid_A::unit()) {\n      if (l) {\n        l->x = ActedMonoid::act(l->x,\
    \ lazy);\n        l->prod = ActedMonoid::act(l->prod, lazy);\n        l->lazy\
    \ = Monoid_A::op(l->lazy, lazy);\n      }\n      if (r) {\n        r->x = ActedMonoid::act(r->x,\
    \ lazy);\n        r->prod = ActedMonoid::act(r->prod, lazy);\n        r->lazy\
    \ = Monoid_A::op(r->lazy, lazy);\n      }\n      lazy = Monoid_A::unit();\n  \
    \  }\n    if (rev) {\n      if (l) {\n        l->rev ^= 1;\n        swap(l->l,\
    \ l->r);\n      }\n      if (r) {\n        r->rev ^= 1;\n        swap(r->l, r->r);\n\
    \      }\n      rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\
    \u3070\u308C\u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\
    \u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\
    \u304C\u3063\u3066\u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  X get()\
    \ { return x; }\n  void set(const X &xx) {\n    x = xx;\n    update();\n  }\n\
    \  void multiply(const X &xx) {\n    x = Monoid_X::op(x, xx);\n    update();\n\
    \  }\n  void apply(const A &a) {\n    x = ActedMonoid::act(x, a);\n    prod =\
    \ ActedMonoid::act(prod, a);\n    lazy = Monoid_A::op(lazy, a);\n  }\n  void reverse()\
    \ {\n    swap(l, r);\n    rev ^= 1;\n  }\n};\ntemplate <typename ActedMonoid,\
    \ int NODES>\nusing SplayTree_ActedMonoid = SplayTree<Node_AM<ActedMonoid>, NODES>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_ActedMonoid;"
  dependsOn: []
  isVerificationFile: false
  path: ds/splay_tree/splaytree_acted_monoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/splay_tree/splaytree_acted_monoid.hpp
layout: document
redirect_from:
- /library/ds/splay_tree/splaytree_acted_monoid.hpp
- /library/ds/splay_tree/splaytree_acted_monoid.hpp.html
title: ds/splay_tree/splaytree_acted_monoid.hpp
---
