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
  bundledCode: "#line 1 \"graph/ds/lct_node_commutative_monoid.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct LCT_Node_Commutative_Monoid {\n  static_assert(Monoid::commute);\n\
    \  using np = LCT_Node_Commutative_Monoid *;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\
    \n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\u9802\u70B9\
    \u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\u3059\u308B\
    .\n  using MX = Monoid;\n  using X = MX::value_type;\n  using VX = X;\n  X x,\
    \ vx;\n\n  LCT_Node_Commutative_Monoid(int i = 0)\n      : l(nullptr),\n     \
    \   r(nullptr),\n        p(nullptr),\n        idx(i),\n        size(1),\n    \
    \    rev(0),\n        x(MX::unit()),\n        vx(MX::unit()) {}\n\n  void update()\
    \ {\n    size = 1;\n    x = vx;\n    if (l) { size += l->size, x = Monoid::op(l->x,\
    \ x); }\n    if (r) { size += r->size, x = Monoid::op(x, r->x); }\n  }\n\n  void\
    \ push() {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  // data \u306E reverse \u3082\u884C\u3046\n \
    \ void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\n  // LCT \u5185\u3067\
    \ expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\u306F\u5909\u66F4\u3060\
    \u3051\n  void set(VX x) { vx = x; }\n\n  // c \u304C\u3053\u306E\u6642\u70B9\u3067\
    \u306F update \u3055\u308C\u3066\u3044\u306A\u3044\u304B\u3082\u3057\u308C\u306A\
    \u3044\u304C, x \u306F\u6B63\u5E38\u306A\u3082\u306E\u304C\u5165\u308B\n  // c->x\
    \ \u7B49\u306F\u4F7F\u308F\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u3059\u308B\
    \n  // c->idx \u3092\u6301\u3063\u3066\u304A\u304F\u3068\u63A2\u7D22\u3067\u304D\
    \u308B\u3053\u3068\u304C\u3042\u308B\n  void add_light(np c, X x) {}\n  void erase_light(np\
    \ c, X x) {}\n};\n"
  code: "\ntemplate <typename Monoid>\nstruct LCT_Node_Commutative_Monoid {\n  static_assert(Monoid::commute);\n\
    \  using np = LCT_Node_Commutative_Monoid *;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\
    \n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\u9802\u70B9\
    \u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\u3059\u308B\
    .\n  using MX = Monoid;\n  using X = MX::value_type;\n  using VX = X;\n  X x,\
    \ vx;\n\n  LCT_Node_Commutative_Monoid(int i = 0)\n      : l(nullptr),\n     \
    \   r(nullptr),\n        p(nullptr),\n        idx(i),\n        size(1),\n    \
    \    rev(0),\n        x(MX::unit()),\n        vx(MX::unit()) {}\n\n  void update()\
    \ {\n    size = 1;\n    x = vx;\n    if (l) { size += l->size, x = Monoid::op(l->x,\
    \ x); }\n    if (r) { size += r->size, x = Monoid::op(x, r->x); }\n  }\n\n  void\
    \ push() {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  // data \u306E reverse \u3082\u884C\u3046\n \
    \ void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\n  // LCT \u5185\u3067\
    \ expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\u306F\u5909\u66F4\u3060\
    \u3051\n  void set(VX x) { vx = x; }\n\n  // c \u304C\u3053\u306E\u6642\u70B9\u3067\
    \u306F update \u3055\u308C\u3066\u3044\u306A\u3044\u304B\u3082\u3057\u308C\u306A\
    \u3044\u304C, x \u306F\u6B63\u5E38\u306A\u3082\u306E\u304C\u5165\u308B\n  // c->x\
    \ \u7B49\u306F\u4F7F\u308F\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u3059\u308B\
    \n  // c->idx \u3092\u6301\u3063\u3066\u304A\u304F\u3068\u63A2\u7D22\u3067\u304D\
    \u308B\u3053\u3068\u304C\u3042\u308B\n  void add_light(np c, X x) {}\n  void erase_light(np\
    \ c, X x) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/lct_node_commutative_monoid.hpp
  requiredBy: []
  timestamp: '2023-12-03 03:12:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/lct_node_commutative_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/lct_node_commutative_monoid.hpp
- /library/graph/ds/lct_node_commutative_monoid.hpp.html
title: graph/ds/lct_node_commutative_monoid.hpp
---
