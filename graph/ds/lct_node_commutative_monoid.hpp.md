---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/ds/range_edge_connected_component_query.hpp
    title: graph/ds/range_edge_connected_component_query.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/2_library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/datastructure/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/2_library_checker/datastructure/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2295.test.cpp
    title: test/3_yukicoder/2295.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2296.test.cpp
    title: test/3_yukicoder/2296.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ds/lct_node_commutative_monoid.hpp\"\n\n// SUBTREE\
    \ : cluster \u304C subtree \u60C5\u5831\u3092\u6301\u3064\u5834\u5408\ntemplate\
    \ <typename Monoid, bool SUBTREE = false>\nstruct LCT_Node_Commutative_Monoid\
    \ {\n  static_assert(Monoid::commute);\n  static constexpr bool NODE_FOR_SUBTREE\
    \ = SUBTREE;\n  using np = LCT_Node_Commutative_Monoid *;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\
    \u3059\u308B.\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ VX = X;\n  X x, vx, mid;\n\n  LCT_Node_Commutative_Monoid(int i = 0)\n     \
    \ : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        idx(i),\n \
    \       size(1),\n        rev(0),\n        x(MX::unit()),\n        vx(MX::unit()),\n\
    \        mid(MX::unit()) {}\n\n  void update() {\n    size = 1;\n    x = vx;\n\
    \    if constexpr (SUBTREE) x = MX::op(x, mid);\n    if (l) { size += l->size,\
    \ x = Monoid::op(l->x, x); }\n    if (r) { size += r->size, x = Monoid::op(x,\
    \ r->x); }\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n\
    \      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  // data \u306E reverse\
    \ \u3082\u884C\u3046\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\
    \n  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, c->x);\n  }\n  void erase_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, MX::inverse(c->x));\n  }\n\
    \n  // b->x \u306B subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void\
    \ change_light(np a, np b) {}\n};\n"
  code: "\n// SUBTREE : cluster \u304C subtree \u60C5\u5831\u3092\u6301\u3064\u5834\
    \u5408\ntemplate <typename Monoid, bool SUBTREE = false>\nstruct LCT_Node_Commutative_Monoid\
    \ {\n  static_assert(Monoid::commute);\n  static constexpr bool NODE_FOR_SUBTREE\
    \ = SUBTREE;\n  using np = LCT_Node_Commutative_Monoid *;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\
    \u3059\u308B.\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ VX = X;\n  X x, vx, mid;\n\n  LCT_Node_Commutative_Monoid(int i = 0)\n     \
    \ : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        idx(i),\n \
    \       size(1),\n        rev(0),\n        x(MX::unit()),\n        vx(MX::unit()),\n\
    \        mid(MX::unit()) {}\n\n  void update() {\n    size = 1;\n    x = vx;\n\
    \    if constexpr (SUBTREE) x = MX::op(x, mid);\n    if (l) { size += l->size,\
    \ x = Monoid::op(l->x, x); }\n    if (r) { size += r->size, x = Monoid::op(x,\
    \ r->x); }\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n\
    \      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  // data \u306E reverse\
    \ \u3082\u884C\u3046\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\
    \n  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, c->x);\n  }\n  void erase_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, MX::inverse(c->x));\n  }\n\
    \n  // b->x \u306B subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void\
    \ change_light(np a, np b) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/lct_node_commutative_monoid.hpp
  requiredBy:
  - graph/ds/range_edge_connected_component_query.hpp
  timestamp: '2023-12-03 14:24:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2295.test.cpp
  - test/3_yukicoder/2296.test.cpp
  - test/2_library_checker/datastructure/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - test/2_library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: graph/ds/lct_node_commutative_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/lct_node_commutative_monoid.hpp
- /library/graph/ds/lct_node_commutative_monoid.hpp.html
title: graph/ds/lct_node_commutative_monoid.hpp
---
