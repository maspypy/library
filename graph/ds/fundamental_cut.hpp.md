---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1889/problem/E
  bundledCode: "#line 1 \"graph/ds/fundamental_cut.hpp\"\n\n// \u6728\u304A\u3088\u3073\
    , 2 \u70B9\u7D44 M \u500B\u3092\u4E0E\u3048\u308B.\n// set_on, set_off: M \u500B\
    \u306E\u7D44\u306E\u30AA\u30F3\u30AA\u30D5\u304C\u3067\u304D\u308B.\n// query(v):\
    \ v, par[v] \u3067\u5206\u96E2\u3055\u308C\u308B\u7D44\u306E\u756A\u53F7\u306E\
    \u3072\u3068\u3064\u3092\u51FA\u529B\n// https://codeforces.com/contest/1889/problem/E\n\
    template <typename TREE>\nstruct Fundamental_Cut {\n  TREE& tree;\n\n  int N,\
    \ M;\n  vc<int> A, B, on;\n  vc<int> IA, IB, rk_A, rk_B, FA, FB;\n  SegTree<Monoid_Max_Idx<int>>\
    \ seg_AB;\n  SegTree<Monoid_Min_Idx<int>> seg_BA;\n\n  // f(i) = a, b, bool(on,off)\n\
    \  template <typename F>\n  Fundamental_Cut(TREE& tree, int M, F f) : tree(tree),\
    \ N(tree.N), M(M) {\n    FOR(i, M) {\n      auto [a, b, t] = f(i);\n      a =\
    \ tree.LID[a], b = tree.LID[b];\n      if (a > b) swap(a, b);\n      A.eb(a),\
    \ B.eb(b), on.eb(t);\n    }\n    IA = argsort(A), IB = argsort(B);\n    rk_A =\
    \ argsort(IA), rk_B = argsort(IB);\n    seg_AB.build(M, [&](int i) -> pair<int,\
    \ int> {\n      if (!on[i]) return {-infty<int>, -1};\n      return {B[IA[i]],\
    \ IA[i]};\n    });\n    seg_BA.build(M, [&](int i) -> pair<int, int> {\n     \
    \ if (!on[i]) return {infty<int>, -1};\n      return {A[IB[i]], IB[i]};\n    });\n\
    \    FA.resize(N + 1), FB.resize(N + 1);\n    for (auto x : A) FA[1 + x]++;\n\
    \    for (auto x : B) FB[1 + x]++;\n    FOR(i, N) FA[i + 1] += FA[i], FB[i + 1]\
    \ += FB[i];\n  }\n\n  void set_on(int i) {\n    if (on[i]) return;\n    on[i]\
    \ = 1;\n    seg_AB.set(rk_A[i], {B[i], i}), seg_BA.set(rk_B[i], {A[i], i});\n\
    \  }\n\n  void set_off(int i) {\n    if (!on[i]) return;\n    on[i] = 0;\n   \
    \ seg_AB.set(rk_A[i], {-infty<int>, -1}),\n        seg_BA.set(rk_B[i], {infty<int>,\
    \ -1});\n  }\n\n  int query(int v) {\n    int L = tree.LID[v], R = tree.RID[v];\n\
    \    int i = seg_AB.prod(FA[L], FA[R]).se;\n    if (i != -1 && R <= B[i]) return\
    \ i;\n    i = seg_BA.prod(FB[L], FB[R]).se;\n    if (i != -1 && A[i] < L) return\
    \ i;\n    return -1;\n  }\n};\n"
  code: "\n// \u6728\u304A\u3088\u3073, 2 \u70B9\u7D44 M \u500B\u3092\u4E0E\u3048\u308B\
    .\n// set_on, set_off: M \u500B\u306E\u7D44\u306E\u30AA\u30F3\u30AA\u30D5\u304C\
    \u3067\u304D\u308B.\n// query(v): v, par[v] \u3067\u5206\u96E2\u3055\u308C\u308B\
    \u7D44\u306E\u756A\u53F7\u306E\u3072\u3068\u3064\u3092\u51FA\u529B\n// https://codeforces.com/contest/1889/problem/E\n\
    template <typename TREE>\nstruct Fundamental_Cut {\n  TREE& tree;\n\n  int N,\
    \ M;\n  vc<int> A, B, on;\n  vc<int> IA, IB, rk_A, rk_B, FA, FB;\n  SegTree<Monoid_Max_Idx<int>>\
    \ seg_AB;\n  SegTree<Monoid_Min_Idx<int>> seg_BA;\n\n  // f(i) = a, b, bool(on,off)\n\
    \  template <typename F>\n  Fundamental_Cut(TREE& tree, int M, F f) : tree(tree),\
    \ N(tree.N), M(M) {\n    FOR(i, M) {\n      auto [a, b, t] = f(i);\n      a =\
    \ tree.LID[a], b = tree.LID[b];\n      if (a > b) swap(a, b);\n      A.eb(a),\
    \ B.eb(b), on.eb(t);\n    }\n    IA = argsort(A), IB = argsort(B);\n    rk_A =\
    \ argsort(IA), rk_B = argsort(IB);\n    seg_AB.build(M, [&](int i) -> pair<int,\
    \ int> {\n      if (!on[i]) return {-infty<int>, -1};\n      return {B[IA[i]],\
    \ IA[i]};\n    });\n    seg_BA.build(M, [&](int i) -> pair<int, int> {\n     \
    \ if (!on[i]) return {infty<int>, -1};\n      return {A[IB[i]], IB[i]};\n    });\n\
    \    FA.resize(N + 1), FB.resize(N + 1);\n    for (auto x : A) FA[1 + x]++;\n\
    \    for (auto x : B) FB[1 + x]++;\n    FOR(i, N) FA[i + 1] += FA[i], FB[i + 1]\
    \ += FB[i];\n  }\n\n  void set_on(int i) {\n    if (on[i]) return;\n    on[i]\
    \ = 1;\n    seg_AB.set(rk_A[i], {B[i], i}), seg_BA.set(rk_B[i], {A[i], i});\n\
    \  }\n\n  void set_off(int i) {\n    if (!on[i]) return;\n    on[i] = 0;\n   \
    \ seg_AB.set(rk_A[i], {-infty<int>, -1}),\n        seg_BA.set(rk_B[i], {infty<int>,\
    \ -1});\n  }\n\n  int query(int v) {\n    int L = tree.LID[v], R = tree.RID[v];\n\
    \    int i = seg_AB.prod(FA[L], FA[R]).se;\n    if (i != -1 && R <= B[i]) return\
    \ i;\n    i = seg_BA.prod(FB[L], FB[R]).se;\n    if (i != -1 && A[i] < L) return\
    \ i;\n    return -1;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/fundamental_cut.hpp
  requiredBy: []
  timestamp: '2025-07-25 21:12:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/fundamental_cut.hpp
layout: document
redirect_from:
- /library/graph/ds/fundamental_cut.hpp
- /library/graph/ds/fundamental_cut.hpp.html
title: graph/ds/fundamental_cut.hpp
---
