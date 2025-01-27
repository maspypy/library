---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/solve_linear.hpp
    title: linalg/solve_linear.hpp
  - icon: ':question:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/p_recursive.hpp\"\n\n#line 1 \"linalg/solve_linear.hpp\"\
    \n/*\r\n0 \u884C\u76EE\u306B\u89E3\u306E\u3072\u3068\u3064\u3002\r\n1\uFF5E\u884C\
    \u76EE\u306B\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u304C\u884C\u30D9\u30AF\u30C8\
    \u30EB\u3068\u3057\u3066\u5165\u308B\u3002\r\n\u89E3\u306A\u3057 = empty\r\n*/\r\
    \ntemplate <typename T>\r\nvc<vc<T>> solve_linear(vc<vc<T>> a, vc<T> b, int n\
    \ = -1, int m = -1) {\r\n  if (n == -1) {\r\n    n = len(a);\r\n    assert(n >\
    \ 0);\r\n    m = len(a[0]);\r\n  }\r\n  assert(n == len(a) && n == len(b));\r\n\
    \  int rk = 0;\r\n  FOR(j, m) {\r\n    if (rk == n) break;\r\n    FOR(i, rk, n)\
    \ if (a[i][j] != 0) {\r\n      swap(a[rk], a[i]);\r\n      swap(b[rk], b[i]);\r\
    \n      break;\r\n    }\r\n    if (a[rk][j] == 0) continue;\r\n    T c = T(1)\
    \ / a[rk][j];\r\n    for (auto&& x: a[rk]) x *= c;\r\n    b[rk] *= c;\r\n    FOR(i,\
    \ n) if (i != rk) {\r\n      T c = a[i][j];\r\n      if (c == T(0)) continue;\r\
    \n      b[i] -= b[rk] * c;\r\n      FOR(k, j, m) { a[i][k] -= a[rk][k] * c; }\r\
    \n    }\r\n    ++rk;\r\n  }\r\n  FOR(i, rk, n) if (b[i] != 0) return {};\r\n \
    \ vc<vc<T>> res(1, vc<T>(m));\r\n  vc<int> pivot(m, -1);\r\n  int p = 0;\r\n \
    \ FOR(i, rk) {\r\n    while (a[i][p] == 0) ++p;\r\n    res[0][p] = b[i];\r\n \
    \   pivot[p] = i;\r\n  }\r\n  FOR(j, m) if (pivot[j] == -1) {\r\n    vc<T> x(m);\r\
    \n    x[j] = -1;\r\n    FOR(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];\r\
    \n    res.eb(x);\r\n  }\r\n  return res;\r\n}\r\n#line 2 \"mod/all_inverse.hpp\"\
    \ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>& X) {\n  for (auto&&\
    \ x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint> res(N + 1);\n  res[0]\
    \ = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n\
    \  res.pop_back();\n  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n \
    \ return res;\n}\n#line 4 \"seq/p_recursive.hpp\"\n\n/*\nreturn: polynomial sequence\
    \ F[0](x),...,F[m](x)\nF[0](n)A[n+m]+...+F[m](n)A[n]=0\n\u4F55\u304B\u304C\u5931\
    \u6557\u3057\u305F\u3089 return empty\n*/\ntemplate <typename mint>\nvvc<mint>\
    \ find_p_recursive(vc<mint> A, int max_m, int max_deg) {\n  int N = (1 + max_m)\
    \ * (1 + max_deg);\n  auto idx = [&](int i, int d) -> int { return (1 + max_deg)\
    \ * i + d; };\n\n  assert(len(A) >= N + max_m);\n  vv(mint, mat, N, N);\n  FOR(row,\
    \ N) {\n    FOR(i, max_m + 1) {\n      mint pw = 1;\n      FOR(j, max_deg + 1)\
    \ { mat[row][idx(i, j)] = A[row + max_m - i] * pw, pw *= row; }\n    }\n  }\n\
    \  auto Xs = solve_linear<mint>(mat, vc<mint>(N, mint(0)));\n  Xs.erase(Xs.begin());\n\
    \  if (Xs.empty()) return {};\n  vvc<mint> F(max_m + 1);\n  FOR(i, max_m + 1)\
    \ {\n    vc<mint> f(max_deg + 1);\n    FOR(j, max_deg + 1) f[j] = Xs[0][idx(i,\
    \ j)];\n    while (len(f) && f.back() == mint(0)) POP(f);\n    F[i] = f;\n  }\n\
    \  while (F[0].empty()) F.erase(F.begin());\n  int m = len(F) - 1;\n  auto poly_eval\
    \ = [&](vc<mint>& f, mint x) -> mint {\n    mint pw = 1, ans = 0;\n    FOR(i,\
    \ len(f)) ans += f[i] * pw, pw *= x;\n    return ans;\n  };\n\n  FOR(n, len(A)\
    \ - m) {\n    mint sm = 0;\n    FOR(i, m + 1) sm += poly_eval(F[i], n) * A[n +\
    \ m - i];\n    if (sm != 0) return {};\n  }\n  return F;\n}\n\n// A[0], ..., A[N]\n\
    template <typename mint>\nvc<mint> extend_p_recursive(vc<mint> A, vvc<mint> F,\
    \ int N) {\n  auto poly_eval = [&](vc<mint>& f, mint x) -> mint {\n    mint pw\
    \ = 1, ans = 0;\n    FOR(i, len(f)) ans += f[i] * pw, pw *= x;\n    return ans;\n\
    \  };\n  int M = len(F) - 1;\n  if (len(A) >= N + 1) return {A.begin(), A.begin()\
    \ + N + 1};\n  A.resize(N + 1);\n  vc<mint> S(N - M + 1);\n  FOR(n, N - M + 1)\
    \ S[n] = poly_eval(F[0], n);\n  S = all_inverse<mint>(S);\n  FOR(n, N - M + 1)\
    \ {\n    mint ans = 0;\n    FOR(i, 1, M + 1) ans += A[n + M - i] * poly_eval(F[i],\
    \ n);\n    A[n + M] = (-ans) * S[n];\n  }\n  return A;\n}\n"
  code: "\n#include \"linalg/solve_linear.hpp\"\n#include \"mod/all_inverse.hpp\"\n\
    \n/*\nreturn: polynomial sequence F[0](x),...,F[m](x)\nF[0](n)A[n+m]+...+F[m](n)A[n]=0\n\
    \u4F55\u304B\u304C\u5931\u6557\u3057\u305F\u3089 return empty\n*/\ntemplate <typename\
    \ mint>\nvvc<mint> find_p_recursive(vc<mint> A, int max_m, int max_deg) {\n  int\
    \ N = (1 + max_m) * (1 + max_deg);\n  auto idx = [&](int i, int d) -> int { return\
    \ (1 + max_deg) * i + d; };\n\n  assert(len(A) >= N + max_m);\n  vv(mint, mat,\
    \ N, N);\n  FOR(row, N) {\n    FOR(i, max_m + 1) {\n      mint pw = 1;\n     \
    \ FOR(j, max_deg + 1) { mat[row][idx(i, j)] = A[row + max_m - i] * pw, pw *= row;\
    \ }\n    }\n  }\n  auto Xs = solve_linear<mint>(mat, vc<mint>(N, mint(0)));\n\
    \  Xs.erase(Xs.begin());\n  if (Xs.empty()) return {};\n  vvc<mint> F(max_m +\
    \ 1);\n  FOR(i, max_m + 1) {\n    vc<mint> f(max_deg + 1);\n    FOR(j, max_deg\
    \ + 1) f[j] = Xs[0][idx(i, j)];\n    while (len(f) && f.back() == mint(0)) POP(f);\n\
    \    F[i] = f;\n  }\n  while (F[0].empty()) F.erase(F.begin());\n  int m = len(F)\
    \ - 1;\n  auto poly_eval = [&](vc<mint>& f, mint x) -> mint {\n    mint pw = 1,\
    \ ans = 0;\n    FOR(i, len(f)) ans += f[i] * pw, pw *= x;\n    return ans;\n \
    \ };\n\n  FOR(n, len(A) - m) {\n    mint sm = 0;\n    FOR(i, m + 1) sm += poly_eval(F[i],\
    \ n) * A[n + m - i];\n    if (sm != 0) return {};\n  }\n  return F;\n}\n\n// A[0],\
    \ ..., A[N]\ntemplate <typename mint>\nvc<mint> extend_p_recursive(vc<mint> A,\
    \ vvc<mint> F, int N) {\n  auto poly_eval = [&](vc<mint>& f, mint x) -> mint {\n\
    \    mint pw = 1, ans = 0;\n    FOR(i, len(f)) ans += f[i] * pw, pw *= x;\n  \
    \  return ans;\n  };\n  int M = len(F) - 1;\n  if (len(A) >= N + 1) return {A.begin(),\
    \ A.begin() + N + 1};\n  A.resize(N + 1);\n  vc<mint> S(N - M + 1);\n  FOR(n,\
    \ N - M + 1) S[n] = poly_eval(F[0], n);\n  S = all_inverse<mint>(S);\n  FOR(n,\
    \ N - M + 1) {\n    mint ans = 0;\n    FOR(i, 1, M + 1) ans += A[n + M - i] *\
    \ poly_eval(F[i], n);\n    A[n + M] = (-ans) * S[n];\n  }\n  return A;\n}\n"
  dependsOn:
  - linalg/solve_linear.hpp
  - mod/all_inverse.hpp
  isVerificationFile: false
  path: seq/p_recursive.hpp
  requiredBy: []
  timestamp: '2024-12-17 23:15:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/p_recursive.hpp
layout: document
redirect_from:
- /library/seq/p_recursive.hpp
- /library/seq/p_recursive.hpp.html
title: seq/p_recursive.hpp
---
