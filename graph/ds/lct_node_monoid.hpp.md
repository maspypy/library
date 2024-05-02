---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ds/lct_node_monoid.hpp\"\n\ntemplate <typename Monoid>\n\
    struct LCT_Node_Monoid {\n  using np = LCT_Node_Monoid *;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\
    \u3059\u308B.\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ VX = X;\n\n  X x, rx, vx;\n\n  LCT_Node_Monoid(int i = 0)\n      : l(nullptr),\n\
    \        r(nullptr),\n        p(nullptr),\n        idx(i),\n        size(1),\n\
    \        rev(0),\n        x(MX::unit()),\n        rx(MX::unit()),\n        vx(MX::unit())\
    \ {}\n\n  void update() {\n    size = 1;\n    x = vx, rx = vx;\n    if (l) {\n\
    \      size += l->size, x = Monoid::op(l->x, x), rx = Monoid::op(rx, l->rx);\n\
    \    }\n    if (r) {\n      size += r->size, x = Monoid::op(x, r->x), rx = Monoid::op(r->rx,\
    \ rx);\n    }\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n\
    \      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  // data \u306E reverse\
    \ \u3082\u884C\u3046\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n   \
    \ swap(x, rx);\n  }\n\n  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\
    \u306E\u3067\u3053\u3053\u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx\
    \ = x; }\n\n  void add_light(np c) {}\n  void erase_light(np c) {}\n  void change_light(np\
    \ a, np b) {}\n};\n"
  code: "\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n  using np = LCT_Node_Monoid\
    \ *;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\n  np l, r, p;\n  int idx, size; //\
    \ size \u306F heavy path \u306E\u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\
    \u3054\u3068\u306B\u5B9A\u7FA9\u3059\u308B.\n  using MX = Monoid;\n  using X =\
    \ typename MX::value_type;\n  using VX = X;\n\n  X x, rx, vx;\n\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        size(1),\n        rev(0),\n        x(MX::unit()),\n    \
    \    rx(MX::unit()),\n        vx(MX::unit()) {}\n\n  void update() {\n    size\
    \ = 1;\n    x = vx, rx = vx;\n    if (l) {\n      size += l->size, x = Monoid::op(l->x,\
    \ x), rx = Monoid::op(rx, l->rx);\n    }\n    if (r) {\n      size += r->size,\
    \ x = Monoid::op(x, r->x), rx = Monoid::op(r->rx, rx);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  // data \u306E reverse \u3082\u884C\u3046\n \
    \ void reverse() {\n    rev ^= 1;\n    swap(l, r);\n    swap(x, rx);\n  }\n\n\
    \  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {}\n  void erase_light(np c) {}\n  void change_light(np a, np b) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/lct_node_monoid.hpp
  requiredBy: []
  timestamp: '2023-12-03 14:26:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
documentation_of: graph/ds/lct_node_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/lct_node_monoid.hpp
- /library/graph/ds/lct_node_monoid.hpp.html
title: graph/ds/lct_node_monoid.hpp
---
