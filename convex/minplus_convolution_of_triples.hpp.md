---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/minplus_convolution_convex.hpp
    title: convex/minplus_convolution_convex.hpp
  - icon: ':question:'
    path: convex/smawk.hpp
    title: convex/smawk.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/minplus_conv_triple.test.cpp
    title: test/mytest/minplus_conv_triple.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/436/problem/E
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
    \ (i,k) \u306E\u3046\u3061\u9078\u3076\u65B9\uFF08j or k\uFF09\ntemplate <typename\
    \ F>\nvc<int> SMAWK(int H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int>\
    \ X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\
    \    vc<int> YY;\n    for (auto&& y: Y) {\n      while (len(YY)) {\n        int\
    \ py = YY.back(), x = X[len(YY) - 1];\n        if (select(x, py, y) == py) break;\n\
    \        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\
    \    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs,\
    \ XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n   \
    \ int p = 0;\n    FOR(i, 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() :\
    \ I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n\
    \        best = select(X[i], best, Y[p]);\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n\
    \  return dfs(dfs, X, Y);\n}\n#line 2 \"convex/minplus_convolution_convex.hpp\"\
    \n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution_convex(vc<T>\
    \ A, vc<T> B) {\n  static_assert(convA || convB);\n  if (!convB) swap(A, B);\n\
    \  int NA = len(A), NB = len(B);\n  int N = NA + NB - 1;\n  int L = 0, R = NB;\n\
    \  while (L < R && B[L] == infty<T>) ++L;\n  if (L == R) return vc<T>(N, infty<T>);\n\
    \  while (B[R - 1] == infty<T>) --R;\n  B = {B.begin() + L, B.begin() + R};\n\
    \  int nB = R - L;\n  int n = NA + nB - 1;\n\n  auto select = [&](int i, int j,\
    \ int k) -> int {\n    if (i < k) return j;\n    if (i - j >= nB) return k;\n\
    \    return (A[j] + B[i - j] > A[k] + B[i - k] ? k : j);\n  };\n\n  vc<int> J\
    \ = SMAWK(n, NA, select);\n  vc<T> C(N, infty<T>);\n  FOR(i, n) C[L + i] = (A[J[i]]\
    \ == infty<T> ? infty<T> : A[J[i]] + B[i - J[i]]);\n  return C;\n}\n#line 2 \"\
    convex/minplus_convolution_of_triples.hpp\"\n\n// https://codeforces.com/contest/436/problem/E\n\
    // \u9577\u3055 3 \u306E\u6570\u5217 {a[i][0], a[i][1], a[i][2]} \u305F\u3061\u306E\
    \u7573\u307F\u8FBC\u307F, O(NlogN)\n// \u540C\u7A2E\u306E\u554F\u984C\uFF1A(a_i,b_i)\
    \ \u304C\u3042\u3063\u3066\u3001b_i \u306F a_i \u3092\u53D6\u3063\u3066\u304B\u3089\
    \u3060\u3051\u53D6\u308C\u308B\ntemplate <typename T>\nstruct MinPlus_Convolution_of_Triples\
    \ {\n  int N = 0;\n  T sm0 = 0;\n  vc<array<T, 3>> dat;\n  vc<T> dp1, dp2, dp;\n\
    \  vc<int> I1, I2;\n  bool solved = false;\n\n  void add(T x0, T x1, T x2) { sm0\
    \ += x0, dat.eb(array<T, 3>{x0, x1, x2}); }\n\n  void solve() {\n    solved =\
    \ true;\n    N = dat.size();\n    FOR(i, N) {\n      int a = dat[i][1] - dat[i][0],\
    \ b = dat[i][2] - dat[i][1];\n      (a <= b ? I1 : I2).eb(i);\n    };\n    sort(all(I2),\
    \ [&](int i, int j) -> bool {\n      return dat[i][2] - dat[i][0] < dat[j][2]\
    \ - dat[j][0];\n    });\n    solve_1();\n    solve_2();\n    dp = minplus_convolution_convex<T,\
    \ true, false>(dp1, dp2);\n    for (auto&& x: dp) x += sm0;\n  }\n\n  T operator[](int\
    \ i) { return dp[i]; }\n\n  vc<int> restore(int k) {\n    assert(solved);\n  \
    \  int k1 = -1, k2 = -1;\n    FOR(i, k + 1) {\n      int j = k - i;\n      if\
    \ (0 <= i && i < len(dp1) && 0 <= j && j < len(dp2)\n          && dp1[i] + dp2[j]\
    \ + sm0 == dp[k]) {\n        k1 = i, k2 = j;\n        break;\n      }\n    }\n\
    \    assert(k1 != -1 && k2 != -1);\n    vc<int> x(N);\n    vc<int> x1 = restore_1(k1);\n\
    \    vc<int> x2 = restore_2(k2);\n    for (int i = 0; i < N; ++i) x[i] = x1[i]\
    \ + x2[i];\n    return x;\n  }\n\nprivate:\n  void solve_1() {\n    dp1.reserve(len(I1));\n\
    \    for (int i: I1) {\n      dp1.eb(dat[i][1] - dat[i][0]), dp1.eb(dat[i][2]\
    \ - dat[i][1]);\n    }\n    sort(all(dp1));\n    dp1 = cumsum<T>(dp1);\n  }\n\n\
    \  vc<int> restore_1(int k) {\n    vc<pair<T, int>> A;\n    for (int i: I1) {\n\
    \      A.eb(dat[i][1] - dat[i][0], i);\n      A.eb(dat[i][2] - dat[i][1], i);\n\
    \    }\n    nth_element(A.begin(), A.begin() + k, A.end());\n    vc<int> x(N);\n\
    \    FOR(i, k) x[A[i].se]++;\n    return x;\n  }\n\n  void solve_2() {\n    //\
    \ B-A > C-B \u306E\u30B1\u30FC\u30B9\n    // \u89E3\u306E\u69CB\u9020\u3092\u8003\
    \u3048\u308B\u3068\u3001\u307B\u3068\u3093\u3069\u3059\u3079\u3066\u3067 x=0 or\
    \ x=2 \u3068\u3044\u3046\u3068\u308A\u304B\u305F\u306B\u306A\u308B\n    // \u65E2\
    \u306B C-A \u3067\u30BD\u30FC\u30C8\u6E08\n    auto& I = I2;\n    int n = len(I);\n\
    \    dp2.assign(2 * n + 1, infty<T>);\n    // \u5076\u6570\u500B\n    dp2[0] =\
    \ 0;\n    for (int i = 0; i < n; ++i) {\n      dp2[2 * i + 2] = dp2[2 * i] + (dat[I[i]][2]\
    \ - dat[I[i]][0]);\n    }\n    // \u5947\u6570\u500B, prefix \u304B\u3089\u3072\
    \u3068\u3064\u30AD\u30E3\u30F3\u30BB\u30EB\u3059\u308B\n    T ma = -infty<T>;\n\
    \    for (int i = 0; i < n; ++i) {\n      chmax(ma, dat[I[i]][2] - dat[I[i]][1]);\n\
    \      chmin(dp2[2 * i + 1], dp2[2 * i + 2] - ma);\n    }\n    // \u5947\u6570\
    \u500B, suffix \u304B\u3089\u3072\u3068\u3064\u8FFD\u52A0\u3059\u308B\n    T mi\
    \ = infty<T>;\n    for (int i = n - 1; i >= 0; --i) {\n      chmin(mi, dat[I[i]][1]\
    \ - dat[I[i]][0]);\n      chmin(dp2[2 * i + 1], dp2[2 * i] + mi);\n    }\n   \
    \ return;\n  }\n\n  vc<int> restore_2(int k) {\n    auto& I = I2;\n    int n =\
    \ len(I);\n    vc<int> x(N);\n    if (k % 2 == 0) {\n      FOR(i, k / 2) x[I[i]]\
    \ = 2;\n      return x;\n    }\n    pair<T, int> ma = {-infty<T>, -1};\n    FOR(i,\
    \ (k + 1) / 2) {\n      if (chmax(ma.fi, dat[I[i]][2] - dat[I[i]][1])) ma.se =\
    \ I[i];\n    }\n    if (dp2[k] == dp2[k + 1] - ma.fi) {\n      FOR(i, (k + 1)\
    \ / 2) x[I[i]] = 2;\n      x[ma.se]--;\n      return x;\n    }\n    pair<T, int>\
    \ mi = {infty<T>, -1};\n    for (int i = n - 1; i >= k / 2; --i) {\n      if (chmin(mi.fi,\
    \ dat[I[i]][1] - dat[I[i]][0])) mi.se = I[i];\n    }\n    if (dp2[k] == dp2[k\
    \ - 1] + mi.fi) {\n      FOR(i, (k - 1) / 2) x[I[i]] = 2;\n      x[mi.se] = 1;\n\
    \      return x;\n    }\n    assert(0);\n    return x;\n  }\n};\n"
  code: "#include \"convex/minplus_convolution_convex.hpp\"\n\n// https://codeforces.com/contest/436/problem/E\n\
    // \u9577\u3055 3 \u306E\u6570\u5217 {a[i][0], a[i][1], a[i][2]} \u305F\u3061\u306E\
    \u7573\u307F\u8FBC\u307F, O(NlogN)\n// \u540C\u7A2E\u306E\u554F\u984C\uFF1A(a_i,b_i)\
    \ \u304C\u3042\u3063\u3066\u3001b_i \u306F a_i \u3092\u53D6\u3063\u3066\u304B\u3089\
    \u3060\u3051\u53D6\u308C\u308B\ntemplate <typename T>\nstruct MinPlus_Convolution_of_Triples\
    \ {\n  int N = 0;\n  T sm0 = 0;\n  vc<array<T, 3>> dat;\n  vc<T> dp1, dp2, dp;\n\
    \  vc<int> I1, I2;\n  bool solved = false;\n\n  void add(T x0, T x1, T x2) { sm0\
    \ += x0, dat.eb(array<T, 3>{x0, x1, x2}); }\n\n  void solve() {\n    solved =\
    \ true;\n    N = dat.size();\n    FOR(i, N) {\n      int a = dat[i][1] - dat[i][0],\
    \ b = dat[i][2] - dat[i][1];\n      (a <= b ? I1 : I2).eb(i);\n    };\n    sort(all(I2),\
    \ [&](int i, int j) -> bool {\n      return dat[i][2] - dat[i][0] < dat[j][2]\
    \ - dat[j][0];\n    });\n    solve_1();\n    solve_2();\n    dp = minplus_convolution_convex<T,\
    \ true, false>(dp1, dp2);\n    for (auto&& x: dp) x += sm0;\n  }\n\n  T operator[](int\
    \ i) { return dp[i]; }\n\n  vc<int> restore(int k) {\n    assert(solved);\n  \
    \  int k1 = -1, k2 = -1;\n    FOR(i, k + 1) {\n      int j = k - i;\n      if\
    \ (0 <= i && i < len(dp1) && 0 <= j && j < len(dp2)\n          && dp1[i] + dp2[j]\
    \ + sm0 == dp[k]) {\n        k1 = i, k2 = j;\n        break;\n      }\n    }\n\
    \    assert(k1 != -1 && k2 != -1);\n    vc<int> x(N);\n    vc<int> x1 = restore_1(k1);\n\
    \    vc<int> x2 = restore_2(k2);\n    for (int i = 0; i < N; ++i) x[i] = x1[i]\
    \ + x2[i];\n    return x;\n  }\n\nprivate:\n  void solve_1() {\n    dp1.reserve(len(I1));\n\
    \    for (int i: I1) {\n      dp1.eb(dat[i][1] - dat[i][0]), dp1.eb(dat[i][2]\
    \ - dat[i][1]);\n    }\n    sort(all(dp1));\n    dp1 = cumsum<T>(dp1);\n  }\n\n\
    \  vc<int> restore_1(int k) {\n    vc<pair<T, int>> A;\n    for (int i: I1) {\n\
    \      A.eb(dat[i][1] - dat[i][0], i);\n      A.eb(dat[i][2] - dat[i][1], i);\n\
    \    }\n    nth_element(A.begin(), A.begin() + k, A.end());\n    vc<int> x(N);\n\
    \    FOR(i, k) x[A[i].se]++;\n    return x;\n  }\n\n  void solve_2() {\n    //\
    \ B-A > C-B \u306E\u30B1\u30FC\u30B9\n    // \u89E3\u306E\u69CB\u9020\u3092\u8003\
    \u3048\u308B\u3068\u3001\u307B\u3068\u3093\u3069\u3059\u3079\u3066\u3067 x=0 or\
    \ x=2 \u3068\u3044\u3046\u3068\u308A\u304B\u305F\u306B\u306A\u308B\n    // \u65E2\
    \u306B C-A \u3067\u30BD\u30FC\u30C8\u6E08\n    auto& I = I2;\n    int n = len(I);\n\
    \    dp2.assign(2 * n + 1, infty<T>);\n    // \u5076\u6570\u500B\n    dp2[0] =\
    \ 0;\n    for (int i = 0; i < n; ++i) {\n      dp2[2 * i + 2] = dp2[2 * i] + (dat[I[i]][2]\
    \ - dat[I[i]][0]);\n    }\n    // \u5947\u6570\u500B, prefix \u304B\u3089\u3072\
    \u3068\u3064\u30AD\u30E3\u30F3\u30BB\u30EB\u3059\u308B\n    T ma = -infty<T>;\n\
    \    for (int i = 0; i < n; ++i) {\n      chmax(ma, dat[I[i]][2] - dat[I[i]][1]);\n\
    \      chmin(dp2[2 * i + 1], dp2[2 * i + 2] - ma);\n    }\n    // \u5947\u6570\
    \u500B, suffix \u304B\u3089\u3072\u3068\u3064\u8FFD\u52A0\u3059\u308B\n    T mi\
    \ = infty<T>;\n    for (int i = n - 1; i >= 0; --i) {\n      chmin(mi, dat[I[i]][1]\
    \ - dat[I[i]][0]);\n      chmin(dp2[2 * i + 1], dp2[2 * i] + mi);\n    }\n   \
    \ return;\n  }\n\n  vc<int> restore_2(int k) {\n    auto& I = I2;\n    int n =\
    \ len(I);\n    vc<int> x(N);\n    if (k % 2 == 0) {\n      FOR(i, k / 2) x[I[i]]\
    \ = 2;\n      return x;\n    }\n    pair<T, int> ma = {-infty<T>, -1};\n    FOR(i,\
    \ (k + 1) / 2) {\n      if (chmax(ma.fi, dat[I[i]][2] - dat[I[i]][1])) ma.se =\
    \ I[i];\n    }\n    if (dp2[k] == dp2[k + 1] - ma.fi) {\n      FOR(i, (k + 1)\
    \ / 2) x[I[i]] = 2;\n      x[ma.se]--;\n      return x;\n    }\n    pair<T, int>\
    \ mi = {infty<T>, -1};\n    for (int i = n - 1; i >= k / 2; --i) {\n      if (chmin(mi.fi,\
    \ dat[I[i]][1] - dat[I[i]][0])) mi.se = I[i];\n    }\n    if (dp2[k] == dp2[k\
    \ - 1] + mi.fi) {\n      FOR(i, (k - 1) / 2) x[I[i]] = 2;\n      x[mi.se] = 1;\n\
    \      return x;\n    }\n    assert(0);\n    return x;\n  }\n};"
  dependsOn:
  - convex/minplus_convolution_convex.hpp
  - convex/smawk.hpp
  isVerificationFile: false
  path: convex/minplus_convolution_of_triples.hpp
  requiredBy: []
  timestamp: '2023-08-07 05:07:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/minplus_conv_triple.test.cpp
documentation_of: convex/minplus_convolution_of_triples.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution_of_triples.hpp
- /library/convex/minplus_convolution_of_triples.hpp.html
title: convex/minplus_convolution_of_triples.hpp
---
