---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/5_atcoder/abc350_g.test.cpp
    title: test/5_atcoder/abc350_g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ds/lct_node_base.hpp\"\n// SUBTREE : cluster \u304C\
    \ subtree \u60C5\u5831\u3092\u6301\u3064\u5834\u5408\nstruct LCT_Node_Base {\n\
    \  using np = LCT_Node_Base*;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\n  np l, r,\
    \ p;\n  int idx, size; // size \u306F heavy path \u306E\u9802\u70B9\u6570\n  bool\
    \ rev;\n  using X = int;\n  using VX = int;\n\n  LCT_Node_Base(int i = 0)\n  \
    \    : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0) {}\n\n  void\
    \ update() {\n    size = 1;\n    if (l) { size += l->size; }\n    if (r) { size\
    \ += r->size; }\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n\
    \      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  // data \u306E reverse\
    \ \u3082\u884C\u3046\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\
    \n  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) {}\n\n  void add_light(np c)\
    \ {}\n  void erase_light(np c) {}\n\n  // b->x \u306B subtree value \u304C\u5165\
    \u3063\u3066\u3044\u308B.\n  void change_light(np a, np b) {}\n};\n"
  code: "// SUBTREE : cluster \u304C subtree \u60C5\u5831\u3092\u6301\u3064\u5834\u5408\
    \nstruct LCT_Node_Base {\n  using np = LCT_Node_Base*;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  using X = int;\n  using VX = int;\n\n  LCT_Node_Base(int\
    \ i = 0)\n      : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0)\
    \ {}\n\n  void update() {\n    size = 1;\n    if (l) { size += l->size; }\n  \
    \  if (r) { size += r->size; }\n  }\n\n  void push() {\n    if (rev) {\n     \
    \ if (l) l->reverse();\n      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\
    \n  // data \u306E reverse \u3082\u884C\u3046\n  void reverse() {\n    rev ^=\
    \ 1;\n    swap(l, r);\n  }\n\n  // LCT \u5185\u3067 expose, update \u3092\u884C\
    \u3046\u306E\u3067\u3053\u3053\u306F\u5909\u66F4\u3060\u3051\n  void set(VX x)\
    \ {}\n\n  void add_light(np c) {}\n  void erase_light(np c) {}\n\n  // b->x \u306B\
    \ subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void change_light(np\
    \ a, np b) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/lct_node_base.hpp
  requiredBy: []
  timestamp: '2023-12-23 13:05:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_atcoder/abc350_g.test.cpp
documentation_of: graph/ds/lct_node_base.hpp
layout: document
redirect_from:
- /library/graph/ds/lct_node_base.hpp
- /library/graph/ds/lct_node_base.hpp.html
title: graph/ds/lct_node_base.hpp
---
