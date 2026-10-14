---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/non_adj.test.cpp
    title: test/1_mytest/non_adj.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc464/tasks/abc464_g
    - https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j
  bundledCode: "#line 1 \"convex/path_independent_set.hpp\"\n\n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n\
    // https://atcoder.jp/contests/abc464/tasks/abc464_g\n// \u96A3\u63A5\u3059\u308B\
    \u3082\u306E\u306F\u9078\u3079\u306A\u3044, k \u500B\u9078\u3093\u3060\u3068\u304D\
    \u306E\u6700\u9069\u89E3\u3092\u5168 k \u3067\u5217\u6319\ntemplate <typename\
    \ T, bool MINIMIZE>\nstruct Path_Independent_Set {\n  int N;\n  vc<T> ANS;\n \
    \ vc<pair<int, int>> history;\n\n  Path_Independent_Set(vc<T>& A) { calc(A); }\n\
    \n  void calc(vc<T> A) {\n    if (MINIMIZE) {\n      for (auto& x : A) x = -x;\n\
    \    }\n    N = len(A);\n    vc<bool> rest(N + 2, 1);\n    rest[0] = rest[N +\
    \ 1] = 0;\n    vc<pair<int, int>> range(N + 2);\n    vc<int> left(N + 2), right(N\
    \ + 2);\n    vc<T> val(N + 2);\n    pq_max<pair<T, int>> que;\n    FOR(i, N +\
    \ 2) { left[i] = i - 1, right[i] = i + 1; }\n    FOR(i, N) {\n      val[i + 1]\
    \ = A[i], range[i + 1] = {i, i + 1};\n      que.emplace(val[i + 1], i + 1);\n\
    \    }\n\n    ANS = {0};\n    while (len(que)) {\n      auto [add, i] = POP(que);\n\
    \      if (!rest[i]) continue;\n      ANS.eb(ANS.back() + add);\n      int L =\
    \ left[i], R = right[i];\n      history.eb(range[i]);\n      if (1 <= L) {\n \
    \       right[left[L]] = i, left[i] = left[L];\n      }\n      if (R <= N) {\n\
    \        left[right[R]] = i, right[i] = right[R];\n      }\n      if (rest[L]\
    \ && rest[R]) {\n        val[i] = val[L] + val[R] - val[i];\n        que.emplace(val[i],\
    \ i);\n        range[i] = {range[L].fi, range[R].se};\n      } else {\n      \
    \  rest[i] = 0;\n      }\n      rest[L] = rest[R] = 0;\n    }\n\n    if (MINIMIZE)\
    \ {\n      for (auto& x : ANS) x = -x;\n    }\n  }\n\n  vc<T> get_ANS() { return\
    \ ANS; }\n  vc<int> restore(int n) {\n    vc<int> F(N + 1);\n    FOR(i, n) {\n\
    \      auto [a, b] = history[i];\n      F[a]++, F[b]--;\n    }\n    F = cumsum<int>(F,\
    \ 0);\n    vc<int> I;\n    FOR(i, N) if (F[i] & 1) I.eb(i);\n    return I;\n \
    \ }\n};\n"
  code: "\n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n// https://atcoder.jp/contests/abc464/tasks/abc464_g\n\
    // \u96A3\u63A5\u3059\u308B\u3082\u306E\u306F\u9078\u3079\u306A\u3044, k \u500B\
    \u9078\u3093\u3060\u3068\u304D\u306E\u6700\u9069\u89E3\u3092\u5168 k \u3067\u5217\
    \u6319\ntemplate <typename T, bool MINIMIZE>\nstruct Path_Independent_Set {\n\
    \  int N;\n  vc<T> ANS;\n  vc<pair<int, int>> history;\n\n  Path_Independent_Set(vc<T>&\
    \ A) { calc(A); }\n\n  void calc(vc<T> A) {\n    if (MINIMIZE) {\n      for (auto&\
    \ x : A) x = -x;\n    }\n    N = len(A);\n    vc<bool> rest(N + 2, 1);\n    rest[0]\
    \ = rest[N + 1] = 0;\n    vc<pair<int, int>> range(N + 2);\n    vc<int> left(N\
    \ + 2), right(N + 2);\n    vc<T> val(N + 2);\n    pq_max<pair<T, int>> que;\n\
    \    FOR(i, N + 2) { left[i] = i - 1, right[i] = i + 1; }\n    FOR(i, N) {\n \
    \     val[i + 1] = A[i], range[i + 1] = {i, i + 1};\n      que.emplace(val[i +\
    \ 1], i + 1);\n    }\n\n    ANS = {0};\n    while (len(que)) {\n      auto [add,\
    \ i] = POP(que);\n      if (!rest[i]) continue;\n      ANS.eb(ANS.back() + add);\n\
    \      int L = left[i], R = right[i];\n      history.eb(range[i]);\n      if (1\
    \ <= L) {\n        right[left[L]] = i, left[i] = left[L];\n      }\n      if (R\
    \ <= N) {\n        left[right[R]] = i, right[i] = right[R];\n      }\n      if\
    \ (rest[L] && rest[R]) {\n        val[i] = val[L] + val[R] - val[i];\n       \
    \ que.emplace(val[i], i);\n        range[i] = {range[L].fi, range[R].se};\n  \
    \    } else {\n        rest[i] = 0;\n      }\n      rest[L] = rest[R] = 0;\n \
    \   }\n\n    if (MINIMIZE) {\n      for (auto& x : ANS) x = -x;\n    }\n  }\n\n\
    \  vc<T> get_ANS() { return ANS; }\n  vc<int> restore(int n) {\n    vc<int> F(N\
    \ + 1);\n    FOR(i, n) {\n      auto [a, b] = history[i];\n      F[a]++, F[b]--;\n\
    \    }\n    F = cumsum<int>(F, 0);\n    vc<int> I;\n    FOR(i, N) if (F[i] & 1)\
    \ I.eb(i);\n    return I;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: convex/path_independent_set.hpp
  requiredBy: []
  timestamp: '2026-07-14 09:59:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/non_adj.test.cpp
documentation_of: convex/path_independent_set.hpp
layout: document
redirect_from:
- /library/convex/path_independent_set.hpp
- /library/convex/path_independent_set.hpp.html
title: convex/path_independent_set.hpp
---
