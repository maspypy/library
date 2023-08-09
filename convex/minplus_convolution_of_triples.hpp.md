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
    - https://codeforces.com/contest/436/problem/E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convex/minplus_convolution_convex.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: convex/minplus_convolution_of_triples.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/minplus_convolution_of_triples.hpp
layout: document
redirect_from:
- /library/convex/minplus_convolution_of_triples.hpp
- /library/convex/minplus_convolution_of_triples.hpp.html
title: convex/minplus_convolution_of_triples.hpp
---
