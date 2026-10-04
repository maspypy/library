---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/unionfind/unionfind.hpp\"\n#include \"random/shuffle.hpp\"\n\
    #include \"other/timer.hpp\"\n#include \"ds/fastset.hpp\"\n#include \"ds/decremental_fastset.hpp\"\
    \n\n// ackerman. memory \u591A\u3081\nstruct Decremental_FastSet_UF_ONLY {\n \
    \ int n;\n  UnionFind uf;\n  vc<int> L, R;\n  Decremental_FastSet_UF_ONLY(int\
    \ n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {\n    FOR(i, n + 2) L[i] = i, R[i]\
    \ = i;\n  }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n    ++i;\n \
    \   int l = L[uf[i - 1]], r = R[uf[i]];\n    uf.merge(i, i - 1);\n    L[uf[i]]\
    \ = l, R[uf[i]] = r;\n  }\n  int prev(int i) {\n    assert(-1 <= i);\n    chmin(i,\
    \ n - 1);\n    return L[uf[i + 1]] - 1;\n  }\n  int next(int i) {\n    assert(i\
    \ <= n);\n    chmax(i, 0);\n    return R[uf[i]];\n  }\n};\n\nvc<pair<int, int>>\
    \ sol1(vc<int> A, vc<int> B) {\n  int N = len(A);\n  FastSet FS(N, [&](int i)\
    \ -> int { return 1; });\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n\
    \    ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvc<pair<int,\
    \ int>> sol2(vc<int> A, vc<int> B) {\n  int N = len(A);\n  Decremental_FastSet\
    \ FS(N);\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n \
    \   ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvc<pair<int,\
    \ int>> sol3(vc<int> A, vc<int> B) {\n  int N = len(A);\n  Decremental_FastSet_UF_ONLY\
    \ FS(N);\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n \
    \   ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvoid test()\
    \ {\n  vc<double> X, Y, Z;\n  FOR(100) {\n    int N = 1 << 20;\n    vc<int> A(N);\n\
    \    FOR(i, N) A[i] = i;\n    shuffle(A);\n    vc<int> B(N);\n    FOR(i, N) B[i]\
    \ = RNG(0, N);\n    vc<pair<int, int>> ANS1, ANS2, ANS3;\n    {\n      Timer timer;\n\
    \      timer.start();\n      ANS1 = sol1(A, B);\n      X.eb(timer());\n    }\n\
    \    {\n      Timer timer;\n      timer.start();\n      ANS2 = sol2(A, B);\n \
    \     Y.eb(timer());\n    }\n\n    {\n      Timer timer;\n      timer.start();\n\
    \      ANS3 = sol3(A, B);\n      Z.eb(timer());\n    }\n    // print(X.back(),\
    \ Y.back(), Z.back());\n\n    assert(ANS1 == ANS2);\n    assert(ANS1 == ANS3);\n\
    \  }\n  // print(SUM<double>(X));\n  // print(SUM<double>(Y));\n  // print(SUM<double>(Z));\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/decremental_fastset.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/decremental_fastset.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/decremental_fastset.test.cpp
- /verify/test/1_mytest/decremental_fastset.test.cpp.html
title: test/1_mytest/decremental_fastset.test.cpp
---
