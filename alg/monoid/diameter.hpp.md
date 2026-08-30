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
  bundledCode: "#line 1 \"alg/monoid/diameter.hpp\"\n\ntemplate <typename TREE>\n\
    struct Monoid_Diameter {\n  using value_type = pair<int, int>;\n  using X = value_type;\n\
    \  static inline const TREE* tree = nullptr;\n  static void set_tree(const TREE&\
    \ T) { tree = &T; }\n\n  static X op(X L, X R) {\n    assert(tree != nullptr);\n\
    \    if (L.fi == -1) return R;\n    if (R.fi == -1) return L;\n    auto [a, b]\
    \ = L;\n    auto [c, d] = R;\n    for (int v : {c, d}) {\n      int ab = tree->dist(a,\
    \ b);\n      int av = tree->dist(a, v);\n      int bv = tree->dist(b, v);\n  \
    \    int ma = max({ab, av, bv});\n      if (ma == ab) {\n      }\n      elif (ma\
    \ == av) { b = v; }\n      else {\n        a = v;\n      }\n    }\n    return\
    \ {a, b};\n  }\n  static int eval(const X& D) {\n    assert(tree != nullptr);\n\
    \    return tree->dist(D.fi, D.se);\n  }\n\n  static constexpr X id() { return\
    \ {-1, -1}; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename TREE>\nstruct Monoid_Diameter {\n  using value_type\
    \ = pair<int, int>;\n  using X = value_type;\n  static inline const TREE* tree\
    \ = nullptr;\n  static void set_tree(const TREE& T) { tree = &T; }\n\n  static\
    \ X op(X L, X R) {\n    assert(tree != nullptr);\n    if (L.fi == -1) return R;\n\
    \    if (R.fi == -1) return L;\n    auto [a, b] = L;\n    auto [c, d] = R;\n \
    \   for (int v : {c, d}) {\n      int ab = tree->dist(a, b);\n      int av = tree->dist(a,\
    \ v);\n      int bv = tree->dist(b, v);\n      int ma = max({ab, av, bv});\n \
    \     if (ma == ab) {\n      }\n      elif (ma == av) { b = v; }\n      else {\n\
    \        a = v;\n      }\n    }\n    return {a, b};\n  }\n  static int eval(const\
    \ X& D) {\n    assert(tree != nullptr);\n    return tree->dist(D.fi, D.se);\n\
    \  }\n\n  static constexpr X id() { return {-1, -1}; }\n  static constexpr bool\
    \ commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/diameter.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/diameter.hpp
layout: document
redirect_from:
- /library/alg/monoid/diameter.hpp
- /library/alg/monoid/diameter.hpp.html
title: alg/monoid/diameter.hpp
---
