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
    - https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j
    - https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/wavelet_matrix.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"ds/wavelet_matrix.hpp\"\n#include \"graph/tree.hpp\"\n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
    // https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12\ntemplate <typename\
    \ TREE, bool edge, typename T, bool COMPRESS,\n          typename Monoid = Monoid_Add<T>>\n\
    struct Tree_Wavelet_Matrix {\n  TREE& tree;\n  int N;\n  using WM = Wavelet_Matrix<T,\
    \ COMPRESS, Monoid_Add<T>>;\n  using X = typename Monoid::value_type;\n  WM wm;\n\
    \n  Tree_Wavelet_Matrix(TREE& tree, vc<T> A, vc<X> SUM_data = {}, int log = -1)\n\
    \      : tree(tree), N(tree.N) {\n    vc<X>& S = SUM_data;\n    vc<T> A1;\n  \
    \  vc<X> S1;\n    A1.resize(N);\n    if (!S.empty()) S1.resize(N);\n    if (!edge)\
    \ {\n      assert(len(A) == N && (len(S) == 0 || len(S) == N));\n      FOR(v,\
    \ N) A1[tree.LID[v]] = A[v];\n      if (len(S) == N) { FOR(v, N) S1[tree.LID[v]]\
    \ = S[v]; }\n      wm.build(A1, S1, log);\n    } else {\n      assert(len(A) ==\
    \ N - 1 && (len(S) == 0 || len(S) == N - 1));\n      if (!S.empty()) {\n     \
    \   FOR(e, N - 1) { S1[tree.LID[tree.e_to_v(e)]] = S[e]; }\n      }\n      FOR(e,\
    \ N - 1) { A1[tree.LID[tree.e_to_v(e)]] = A[e]; }\n      wm.build(A1, S1, log);\n\
    \    }\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\
    \u308B\u3082\u306E\u3092\u6570\u3048\u308B\n  int count_path(int s, int t, T a,\
    \ T b, T xor_val = 0) {\n    return wm.count(get_segments(s, t), a, b, xor_val);\n\
    \  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\u308B\
    \u3082\u306E\u3092\u6570\u3048\u308B\n  int count_subtree(int u, T a, T b, T xor_val\
    \ = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return wm.count(l + edge,\
    \ r, a, b, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L,\
    \ R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth_value_and_sum(get_segments(s,\
    \ t), k, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R)\
    \ \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_subtree(int\
    \ u, int k, T xor_val = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return\
    \ wm.kth_value_and_sum(l + edge, r, k, xor_val);\n  }\n\n  // xor \u3057\u305F\
    \u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth(get_segments(s, t), k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_subtree(int u, int k, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.kth(l + edge, r, k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067\u4E2D\u592E\u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\
    \u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\n  T median_path(bool\
    \ UPPER, int s, int t, T xor_val = 0) {\n    return wm.median(UPPER, get_segments(s,\
    \ t), xor_val);\n  }\n\n  T median_subtree(bool UPPER, int u, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.median(UPPER, l + edge,\
    \ r, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2) \u756A\
    \u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\n  X sum_path(int\
    \ s, int t, int k1, int k2, T xor_val = 0) {\n    return wm.sum(get_segments(s,\
    \ t), k1, k2, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2)\
    \ \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\
    \n  X sum_subtree(int u, int k1, int k2, T xor_val = 0) {\n    int l = tree.LID[u],\
    \ r = tree.RID[u];\n    return wm.sum(l + edge, r, k1, k2, xor_val);\n  }\n\n\
    \  X sum_all_path(int s, int t) { return wm.sum_all(get_segments(s, t)); }\n\n\
    \  X sum_all_subtree(int u) {\n    int l = tree.LID[u], r = tree.RID[u];\n   \
    \ return wm.sum_all(l + edge, r);\n  }\n\nprivate:\n  vc<pair<int, int>> get_segments(int\
    \ s, int t) {\n    vc<pair<int, int>> segments = tree.get_path_decomposition(s,\
    \ t, edge);\n    for (auto&& [a, b]: segments) {\n      if (a >= b) swap(a, b);\n\
    \      ++b;\n    }\n    return segments;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/tree_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/tree_wavelet_matrix.hpp
layout: document
redirect_from:
- /library/graph/ds/tree_wavelet_matrix.hpp
- /library/graph/ds/tree_wavelet_matrix.hpp.html
title: graph/ds/tree_wavelet_matrix.hpp
---
