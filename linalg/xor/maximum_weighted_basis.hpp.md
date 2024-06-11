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
    - https://codeforces.com/gym/102331/problem/E
  bundledCode: "#line 1 \"linalg/xor/maximum_weighted_basis.hpp\"\n// https://codeforces.com/gym/102331/problem/E\n\
    template <typename UINT, int LIM, typename WT>\nstruct Maximum_Weighted_Basis\
    \ {\n  array<int, LIM> idx;\n  array<UINT, LIM> basis; // \u7C21\u7D04\u5316\u3055\
    \u308C\u305F\u57FA\u5E95\n  array<WT, LIM> wt;\n  WT wt_sum;\n  int dim, nxt_idx;\n\
    \n  Maximum_Weighted_Basis() {\n    fill(all(idx), -1);\n    fill(all(basis),\
    \ 0);\n    fill(all(wt), 0);\n    wt_sum = 0, dim = 0, nxt_idx = 0;\n  }\n\n \
    \ int topbit(UINT x) {\n    if constexpr (is_same_v<UINT, u128>) {\n      return\
    \ (x <= -1ull ? ::topbit(static_cast<u64>(x))\n                         : 64 +\
    \ ::topbit(static_cast<u64>(x >> 64)));\n    } else {\n      return ::topbit(x);\n\
    \    }\n  }\n\n  // \u6D88\u3048\u308B\u3082\u306E\u306E\u756A\u53F7\n  int add(UINT\
    \ x, WT w) {\n    int p = nxt_idx++;\n    while (x) {\n      int k = topbit(x);\n\
    \      if (idx[k] == -1) {\n        idx[k] = p, wt[k] = w, dim++, basis[k] = x,\
    \ wt_sum += w;\n        return -1;\n      }\n      if (wt[k] < w) {\n        wt_sum\
    \ = wt_sum - wt[k] + w;\n        swap(idx[k], p), swap(wt[k], w), swap(basis[k],\
    \ x);\n      }\n      x ^= basis[k];\n    }\n    return p;\n  }\n};\n"
  code: "// https://codeforces.com/gym/102331/problem/E\ntemplate <typename UINT,\
    \ int LIM, typename WT>\nstruct Maximum_Weighted_Basis {\n  array<int, LIM> idx;\n\
    \  array<UINT, LIM> basis; // \u7C21\u7D04\u5316\u3055\u308C\u305F\u57FA\u5E95\
    \n  array<WT, LIM> wt;\n  WT wt_sum;\n  int dim, nxt_idx;\n\n  Maximum_Weighted_Basis()\
    \ {\n    fill(all(idx), -1);\n    fill(all(basis), 0);\n    fill(all(wt), 0);\n\
    \    wt_sum = 0, dim = 0, nxt_idx = 0;\n  }\n\n  int topbit(UINT x) {\n    if\
    \ constexpr (is_same_v<UINT, u128>) {\n      return (x <= -1ull ? ::topbit(static_cast<u64>(x))\n\
    \                         : 64 + ::topbit(static_cast<u64>(x >> 64)));\n    }\
    \ else {\n      return ::topbit(x);\n    }\n  }\n\n  // \u6D88\u3048\u308B\u3082\
    \u306E\u306E\u756A\u53F7\n  int add(UINT x, WT w) {\n    int p = nxt_idx++;\n\
    \    while (x) {\n      int k = topbit(x);\n      if (idx[k] == -1) {\n      \
    \  idx[k] = p, wt[k] = w, dim++, basis[k] = x, wt_sum += w;\n        return -1;\n\
    \      }\n      if (wt[k] < w) {\n        wt_sum = wt_sum - wt[k] + w;\n     \
    \   swap(idx[k], p), swap(wt[k], w), swap(basis[k], x);\n      }\n      x ^= basis[k];\n\
    \    }\n    return p;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/maximum_weighted_basis.hpp
  requiredBy: []
  timestamp: '2024-06-11 22:40:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/maximum_weighted_basis.hpp
layout: document
redirect_from:
- /library/linalg/xor/maximum_weighted_basis.hpp
- /library/linalg/xor/maximum_weighted_basis.hpp.html
title: linalg/xor/maximum_weighted_basis.hpp
---
