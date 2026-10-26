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
    - https://github.com/maspypy/library/blob/main/other/merge_sort.hpp
  bundledCode: "#line 1 \"other/merge_sort.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/merge_sort.hpp\n\
    // floor(n log_2n) \u56DE\u4EE5\u4E0B\u306E comp call\ntemplate <class T, class\
    \ Comp>\nvoid merge_sort(vc<T>& A, Comp comp) {\n  int n = A.size();\n  vc<T>\
    \ B;\n  B.reserve(n);\n  auto dfs = [&](auto& dfs, int l, int r) -> void {\n \
    \   if (r - l <= 1) return;\n    int m = (l + r) / 2;\n    dfs(dfs, l, m), dfs(dfs,\
    \ m, r);\n    B.clear();\n    int i = l, j = m;\n    while (i < m || j < r) {\n\
    \      if (j == r || (i < m && comp(A[i], A[j]))) {\n        B.emplace_back(A[i++]);\n\
    \      } else {\n        B.emplace_back(A[j++]);\n      }\n    }\n    FOR(k, len(B))\
    \ A[l + k] = B[k];\n  };\n  dfs(dfs, 0, n);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/other/merge_sort.hpp\n\
    // floor(n log_2n) \u56DE\u4EE5\u4E0B\u306E comp call\ntemplate <class T, class\
    \ Comp>\nvoid merge_sort(vc<T>& A, Comp comp) {\n  int n = A.size();\n  vc<T>\
    \ B;\n  B.reserve(n);\n  auto dfs = [&](auto& dfs, int l, int r) -> void {\n \
    \   if (r - l <= 1) return;\n    int m = (l + r) / 2;\n    dfs(dfs, l, m), dfs(dfs,\
    \ m, r);\n    B.clear();\n    int i = l, j = m;\n    while (i < m || j < r) {\n\
    \      if (j == r || (i < m && comp(A[i], A[j]))) {\n        B.emplace_back(A[i++]);\n\
    \      } else {\n        B.emplace_back(A[j++]);\n      }\n    }\n    FOR(k, len(B))\
    \ A[l + k] = B[k];\n  };\n  dfs(dfs, 0, n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/merge_sort.hpp
  requiredBy: []
  timestamp: '2026-10-26 22:30:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/merge_sort.hpp
layout: document
redirect_from:
- /library/other/merge_sort.hpp
- /library/other/merge_sort.hpp.html
title: other/merge_sort.hpp
---
