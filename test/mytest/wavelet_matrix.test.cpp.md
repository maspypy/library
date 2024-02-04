---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"ds/wavelet_matrix.hpp\"\n#include \"random/base.hpp\"\n\nvoid test_compress()\
    \ {\n  int N = RNG(1, 64);\n  int MAX = RNG(2, 1 << 10);\n  vc<int> A(N);\n  vc<int>\
    \ X(N);\n  FOR(i, N) X[i] = RNG(MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n\n  Wavelet_Matrix<int,\
    \ true> WM(A, X);\n\n  int Q = 100;\n  FOR(Q) {\n    int L = RNG(0, N);\n    int\
    \ R = RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n    int lo = RNG(0, MAX);\n\
    \    int hi = RNG(0, MAX);\n    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int>\
    \ B = {A.begin() + L, A.begin() + R};\n    vc<int> Y = {X.begin() + L, X.begin()\
    \ + R};\n\n    int t = RNG(0, 5);\n    if (t == 0) { // count\n      int cnt =\
    \ 0;\n      for (auto&& x: B)\n        if (lo <= x && x < hi) cnt += 1;\n    \
    \  assert(WM.count(L, R, lo, hi) == cnt);\n    }\n    if (t == 1) { // sm\n  \
    \    int sm = 0;\n      int k1 = RNG(R - L + 1);\n      int k2 = RNG(R - L + 1);\n\
    \      if (k1 > k2) swap(k1, k2);\n      auto I = argsort(B);\n      FOR(i, k1,\
    \ k2) sm += Y[I[i]];\n      assert(WM.sum(L, R, k1, k2) == sm);\n    }\n    if\
    \ (t == 2) { // kth\n      int k = RNG(R - L);\n      sort(all(B));\n      assert(WM.kth(L,\
    \ R, k) == B[k]);\n    }\n    if (t == 3) { // max_right\n      int a = RNG(0,\
    \ 10);\n      int b = RNG(0, 10);\n      int c = RNG(0, a * (R - L) + b * MAX\
    \ * (R - L) + 1);\n      auto check\n          = [&](int cnt, int sm) -> bool\
    \ { return a * cnt + b * sm <= c; };\n      auto p = WM.max_right(check, L, R);\n\
    \      int k = binary_search(\n          [&](int k) -> bool {\n            int\
    \ sm = WM.sum(L, R, 0, k);\n            return check(k, sm);\n          },\n \
    \         0, R - L + 1);\n      int sm = WM.sum(L, R, 0, k);\n      assert(p.fi\
    \ == k && p.se == sm);\n    }\n    if (t == 4) { // k-th value and sum\n     \
    \ int k = RNG(0, R - L + 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n\
    \      int val = B[I[k]];\n      int sm = 0;\n      FOR(i, k) sm += Y[I[i]];\n\
    \      auto p = WM.kth_value_and_sum(L, R, k);\n      assert(p.fi == val && p.se\
    \ == sm);\n    }\n  }\n}\n\nvoid test_not_compress() {\n  int N = RNG(1, 64);\n\
    \  int log = RNG(1, 7);\n  int MAX = 1 << log;\n  vc<int> A(N);\n  vc<int> X(N);\n\
    \  FOR(i, N) X[i] = RNG(0, MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n  Wavelet_Matrix<int,\
    \ false> WM(A, X, log);\n\n  int Q = 100;\n  FOR(Q) {\n    int L = RNG(0, N);\n\
    \    int R = RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n    int lo = RNG(0,\
    \ MAX);\n    int hi = RNG(0, MAX);\n    int xor_val = RNG(0, MAX);\n    if (lo\
    \ > hi) swap(lo, hi);\n    ++hi;\n    vc<int> B = {A.begin() + L, A.begin() +\
    \ R};\n    vc<int> Y = {X.begin() + L, X.begin() + R};\n    for (auto&& x: B)\
    \ x ^= xor_val;\n\n    int t = RNG(0, 5);\n    if (t == 0) { // count\n      int\
    \ cnt = 0;\n      for (auto&& x: B) {\n        if (lo <= x && x < hi) cnt += 1;\n\
    \      }\n      assert(WM.count(L, R, lo, hi, xor_val) == cnt);\n    }\n    if\
    \ (t == 1) { // sm\n      int sm = 0;\n      int k1 = RNG(R - L + 1);\n      int\
    \ k2 = RNG(R - L + 1);\n      if (k1 > k2) swap(k1, k2);\n      auto I = argsort(B);\n\
    \      FOR(i, k1, k2) sm += Y[I[i]];\n      assert(WM.sum(L, R, k1, k2, xor_val)\
    \ == sm);\n    }\n    if (t == 2) { // kth\n      int k = RNG(R - L);\n      sort(all(B));\n\
    \      assert(WM.kth(L, R, k, xor_val) == B[k]);\n    }\n    if (t == 3) { //\
    \ max_right\n      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n      int c\
    \ = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n         \
    \ = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };\n      auto\
    \ p = WM.max_right(check, L, R, xor_val);\n      int k = binary_search(\n    \
    \      [&](int k) -> bool {\n            int sm = WM.sum(L, R, 0, k, xor_val);\n\
    \            return check(k, sm);\n          },\n          0, R - L + 1);\n  \
    \    int sm = WM.sum(L, R, 0, k, xor_val);\n      assert(k == p.fi && sm == p.se);\n\
    \    }\n    if (t == 4) { // k-th value and sum\n      int k = RNG(0, R - L +\
    \ 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n      int val = B[I[k]];\n\
    \      int sm = 0;\n      FOR(i, k) sm += Y[I[i]];\n      auto p = WM.kth_value_and_sum(L,\
    \ R, k, xor_val);\n      assert(p.fi == val && p.se == sm);\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(1000) test_compress();\n  FOR(1000) test_not_compress();\n\
    \  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/wavelet_matrix.test.cpp
- /verify/test/mytest/wavelet_matrix.test.cpp.html
title: test/mytest/wavelet_matrix.test.cpp
---
