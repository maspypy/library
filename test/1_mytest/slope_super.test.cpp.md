---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convex/slope_super.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/shuffle.hpp\"\n#include \"convex/slope_super.hpp\"\n\nvoid\
    \ test(int N, bool from_zero, int add_prob) {\n  Slope_Trick_Super<ll> ST(N);\n\
    \  using F = typename decltype(ST)::FUNC;\n\n  vc<int> L(2 * N - 1), R(2 * N -\
    \ 1), A(N), B(N);\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n\n  FOR(i, N) {\n \
    \   L[i] = RNG(0, 5);\n    if (from_zero) L[i] = 0;\n    R[i] = RNG(0, 5);\n \
    \   if (L[i] > R[i]) swap(L[i], R[i]);\n    A[i] = RNG(-3, 4);\n    B[i] = RNG(-3,\
    \ 4);\n  }\n  vvc<ll> dp(2 * N - 1);\n  vc<F> func(2 * N - 1);\n  FOR(i, N) {\n\
    \    dp[i].resize(R[i] + 1, infty<ll>);\n    FOR(x, L[i], R[i] + 1) dp[i][x] =\
    \ A[i] * x + B[i];\n    func[i] = ST.segment_func(L[i], R[i], A[i], B[i]);\n \
    \   FOR(x, L[i], R[i] + 1) {\n      ll me = ST.eval(func[i], x);\n      ll god\
    \ = dp[i][x];\n      assert(me == god);\n    }\n  }\n\n  FOR(i, N, 2 * N - 1)\
    \ {\n    shuffle(I);\n    int t = (RNG(0, 100) < add_prob ? 0 : 1);\n    int a\
    \ = POP(I), b = POP(I);\n    I.eb(i);\n    if (dp[a].empty() || dp[b].empty())\
    \ continue;\n    if (t == 0) {\n      // ADD\n      L[i] = max(L[a], L[b]);\n\
    \      R[i] = min(R[a], R[b]);\n      if (L[i] > R[i]) continue;\n      dp[i].assign(R[i]\
    \ + 1, infty<ll>);\n      FOR(x, L[i], R[i] + 1) dp[i][x] = dp[a][x] + dp[b][x];\n\
    \      func[i] = ST.add(func[a], func[b]);\n    }\n    if (t == 1) {\n      //\
    \ conv\n      L[i] = L[a] + L[b];\n      R[i] = R[a] + R[b];\n      dp[i].assign(R[i]\
    \ + 1, infty<ll>);\n      FOR(x1, L[a], R[a] + 1) {\n        FOR(x2, L[b], R[b]\
    \ + 1) { chmin(dp[i][x1 + x2], dp[a][x1] + dp[b][x2]); }\n      }\n      func[i]\
    \ = ST.convolve(func[a], func[b]);\n    }\n    vi X(R[i] + 1, infty<ll>);\n  \
    \  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);\n    assert(func[i].x0 ==\
    \ L[i]);\n    assert(func[i].x1 == R[i]);\n    assert(X == dp[i]);\n    auto [fx,\
    \ x] = ST.get_min(func[i]);\n    assert(L[i] <= x && x <= R[i]);\n    assert(MIN(X)\
    \ == fx && X[x] == fx);\n  }\n  int i = 2 * N - 2;\n  if (dp[i].empty()) return;\n\
    \  int t = RNG(0, 2);\n  if (t == 0) {\n    // clear right\n    FOR(x, L[i] +\
    \ 1, R[i] + 1) chmin(dp[i][x], dp[i][x - 1]);\n    ST.clear_right(func[i]);\n\
    \  }\n  if (t == 2) {\n    // clear left\n    FOR_R(x, L[i] + 1, R[i] + 1) chmin(dp[i][x\
    \ - 1], dp[i][x]);\n    ST.clear_left(func[i]);\n  }\n  vi X(R[i] + 1, infty<ll>);\n\
    \  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);\n  assert(func[i].x0 ==\
    \ L[i]);\n  assert(func[i].x1 == R[i]);\n  assert(X == dp[i]);\n}\n\nvoid solve()\
    \ {\n  int x, y;\n  cin >> x >> y;\n  cout << x + y << \"\\n\";\n}\n\nsigned main()\
    \ {\n  vc<int> ns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000};\n  vc<int> ps = {50,\
    \ 100, 0, 95, 5};\n  for (auto& n: ns) {\n    for (auto& p: ps) {\n      FOR(20)\
    \ {\n        test(n, false, p);\n        test(n, true, p);\n      }\n    }\n \
    \ }\n\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/slope_super.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/slope_super.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/slope_super.test.cpp
- /verify/test/1_mytest/slope_super.test.cpp.html
title: test/1_mytest/slope_super.test.cpp
---
