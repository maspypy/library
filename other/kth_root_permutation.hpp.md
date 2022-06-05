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
    - https://atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_h
  bundledCode: "#line 1 \"other/kth_root_permutation.hpp\"\n\n// (status, perm)\n\
    // 0: no solution\n// 1: unique solution\n// 2: many solution (return one solution)\n\
    // https://atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_h\n\
    pair<int, vc<int>> kth_root_permutation(ll k, vc<int>& A) {\n  int N = len(A);\n\
    \  vc<bool> done(N);\n  // \u30B5\u30A4\u30AF\u30EB\u9577 \u2192 \u30B5\u30A4\u30AF\
    \u30EB\n  vvc<int> dat(N + 1);\n  FOR(v, N) if (!done[v]) {\n    vc<int> C = {v};\n\
    \    while (1) {\n      int nxt = A[C.back()];\n      if (nxt == v) break;\n \
    \     C.eb(nxt);\n    }\n    int n = len(C);\n    for (auto&& x: C) {\n      done[x]\
    \ = 1;\n      dat[n].eb(x);\n    }\n  }\n\n  int stat = 1;\n  vc<int> ANS(N, -1);\n\
    \n  FOR_R(m, 1, N + 1) {\n    ll d = m / gcd(m, k);\n    while (len(dat[d]) >=\
    \ m) {\n      vc<int> tmp = {dat[d].end() - m, dat[d].end()};\n      dat[d].resize(len(dat[d])\
    \ - m);\n      vc<int> C(m);\n      if (d < m) stat = 2;\n      int p = 0;\n \
    \     FOR(i, m) {\n        if (i % d == 0) {\n          p = i / d;\n        }\
    \ else {\n          p = (p + k) % m;\n        }\n        C[p] = tmp[i];\n    \
    \  }\n      FOR(i, m) {\n        int j = (i == m - 1 ? 0 : i + 1);\n        ANS[C[i]]\
    \ = C[j];\n      }\n    }\n  }\n  if (MIN(ANS) == -1) return {0, {}};\n  return\
    \ {stat, ANS};\n}\n"
  code: "\n// (status, perm)\n// 0: no solution\n// 1: unique solution\n// 2: many\
    \ solution (return one solution)\n// https://atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_h\n\
    pair<int, vc<int>> kth_root_permutation(ll k, vc<int>& A) {\n  int N = len(A);\n\
    \  vc<bool> done(N);\n  // \u30B5\u30A4\u30AF\u30EB\u9577 \u2192 \u30B5\u30A4\u30AF\
    \u30EB\n  vvc<int> dat(N + 1);\n  FOR(v, N) if (!done[v]) {\n    vc<int> C = {v};\n\
    \    while (1) {\n      int nxt = A[C.back()];\n      if (nxt == v) break;\n \
    \     C.eb(nxt);\n    }\n    int n = len(C);\n    for (auto&& x: C) {\n      done[x]\
    \ = 1;\n      dat[n].eb(x);\n    }\n  }\n\n  int stat = 1;\n  vc<int> ANS(N, -1);\n\
    \n  FOR_R(m, 1, N + 1) {\n    ll d = m / gcd(m, k);\n    while (len(dat[d]) >=\
    \ m) {\n      vc<int> tmp = {dat[d].end() - m, dat[d].end()};\n      dat[d].resize(len(dat[d])\
    \ - m);\n      vc<int> C(m);\n      if (d < m) stat = 2;\n      int p = 0;\n \
    \     FOR(i, m) {\n        if (i % d == 0) {\n          p = i / d;\n        }\
    \ else {\n          p = (p + k) % m;\n        }\n        C[p] = tmp[i];\n    \
    \  }\n      FOR(i, m) {\n        int j = (i == m - 1 ? 0 : i + 1);\n        ANS[C[i]]\
    \ = C[j];\n      }\n    }\n  }\n  if (MIN(ANS) == -1) return {0, {}};\n  return\
    \ {stat, ANS};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/kth_root_permutation.hpp
  requiredBy: []
  timestamp: '2022-06-05 12:23:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/kth_root_permutation.hpp
layout: document
redirect_from:
- /library/other/kth_root_permutation.hpp
- /library/other/kth_root_permutation.hpp.html
title: other/kth_root_permutation.hpp
---
