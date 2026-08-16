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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/ds/static_toptree.hpp\"\n#include \"graph/shortest_path/bfs01.hpp\"\
    \n#include \"ds/unionfind/unionfind.hpp\"\n#include \"poly/convolution.hpp\"\n\
    \ntemplate <typename mint>\nstruct TREE_ADJ_MATRIX_DP {\n  using poly = vc<mint>;\n\
    \  using Data = array<array<poly, 2>, 2>;\n  using value_type = Data;\n\n  static\
    \ void add(poly& f, poly g) {\n    if (len(f) < len(g)) f.resize(len(g));\n  \
    \  FOR(i, len(g)) f[i] += g[i];\n  };\n\n  static Data rake(Data L, Data R) {\n\
    \    Data Z;\n    add(Z[0][0], convolution(L[0][0], R[0][1]));\n    add(Z[0][1],\
    \ convolution(L[0][1], R[0][1]));\n    add(Z[1][0], convolution(L[0][0], R[1][1]));\n\
    \    add(Z[1][1], convolution(L[0][1], R[1][1]));\n    add(Z[1][0], convolution(L[1][0],\
    \ R[0][1]));\n    add(Z[1][1], convolution(L[1][1], R[0][1]));\n    return Z;\n\
    \  }\n  static Data compress(Data L, Data R) {\n    Data Z;\n    FOR(p, 2) FOR(q,\
    \ 2) FOR(r, 2) { add(Z[p][r], convolution<mint>(L[p][q], R[1 - q][r])); }\n  \
    \  return Z;\n  }\n};\n\n// det(I-xA) \u306E\u8A08\u7B97 (\u56FA\u6709\u591A\u9805\
    \u5F0F\u306E reverse \u306B\u306A\u3063\u3066\u3044\u308B)\n// weight(i,j)\uFF1A\
    A[i][j]\n// \u5076\u6570\u6B21\u3060\u3051\u3057\u304B\u51FA\u3066\u3053\u306A\
    \u3044\u306E\u3067 loop \u3042\u308A\u3088\u308A\u9AD8\u901F\ntemplate <typename\
    \ mint, typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_not_allow_loop(Graph<int,\
    \ 0>& G, F weight) {\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>> tree(G);\n\
    \  Static_TopTree<decltype(tree)> STT(tree);\n\n  // u, v \u306F\u3082\u3046\u8A08\
    \u7B97\u3057\u305F\u304B\n  using Data = array<array<poly, 2>, 2>;\n  auto single\
    \ = [&](int v) -> Data {\n    Data X;\n    int p = tree.parent[v];\n    mint wt\
    \ = (p == -1 ? mint(0) : weight(p, v) * weight(v, p));\n    X[0][0] = poly{mint(1)};\n\
    \    X[0][1] = poly{mint(1)};                   // loop\n    if (p != -1) X[1][1]\
    \ = poly{mint(0), -wt}; // match\n    return X;\n  };\n  Data X = STT.tree_dp<TREE_ADJ_MATRIX_DP<mint>>(single);\n\
    \  vc<mint> ANS(G.N + 1);\n  FOR(i, len(X[0][1])) { ANS[2 * i] += X[0][1][i];\
    \ }\n  return ANS;\n}\n\ntemplate <typename mint, typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix_allow_loop(Graph<int,\
    \ 0>& G, F weight) {\n  using poly = vc<mint>;\n  Tree<Graph<int, 0>> tree(G);\n\
    \  Static_TopTree<decltype(tree)> STT(tree);\n\n  using Data = array<array<poly,\
    \ 2>, 2>;\n  auto single = [&](int v) -> Data {\n    Data X;\n    int p = tree.parent[v];\n\
    \    mint wt = (p == -1 ? mint(0) : weight(p, v) * weight(v, p));\n    X[0][0]\
    \ = poly{mint(1)};\n    X[0][1] = poly{mint(1), -weight(v, v)};             //\
    \ loop\n    if (p != -1) X[1][1] = poly{mint(0), mint(0), -wt}; // match\n   \
    \ return X;\n  };\n  Data X = STT.tree_dp<TREE_ADJ_MATRIX_DP<mint>>(single);\n\
    \  vc<mint> ANS(G.N + 1);\n  FOR(i, len(X[0][1])) { ANS[i] += X[0][1][i]; }\n\
    \  return ANS;\n}\n\n// det(I-xA) \u306E\u8A08\u7B97 (\u56FA\u6709\u591A\u9805\
    \u5F0F\u306E reverse \u306B\u306A\u3063\u3066\u3044\u308B)\n// weight(i,j)\uFF1A\
    A[i][j]\ntemplate <bool ALLOW_LOOP, typename mint, typename F>\nvc<mint> characteristic_poly_of_tree_adjacency_matrix(Graph<int,\
    \ 0>& G, F weight) {\n  if constexpr (ALLOW_LOOP) {\n    return characteristic_poly_of_tree_adjacency_matrix_allow_loop<mint>(G,\
    \ weight);\n  } else {\n    return characteristic_poly_of_tree_adjacency_matrix_not_allow_loop<mint>(G,\
    \ weight);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
layout: document
redirect_from:
- /library/graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
- /library/graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp.html
title: graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp
---
