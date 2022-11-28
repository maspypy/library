---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/lazy/cntsum_add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/lazy/cntsum_add.hpp\"\n#include \"\
    ds/bbst/rbst_lazy.hpp\"\n#include \"random/base.hpp\"\n\nvoid test() {\n  using\
    \ Lazy = Lazy_CntSum_Add<int>;\n  using MonoX = typename Lazy::X_structure;\n\n\
    \  RBST_Lazy<Lazy, 100> X;\n  FOR(1000) {\n    X.reset();\n    int N = RNG(1,\
    \ 3);\n    int Q = RNG(1, 1000);\n    vc<int> A(N);\n    FOR(i, N) A[i] = RNG(1,\
    \ 10);\n\n    vc<pair<int, int>> seg_raw(N);\n    FOR(i, N) seg_raw[i] = {1, A[i]};\n\
    \    auto root = X.new_node(seg_raw);\n\n    FOR(Q) {\n      int t = RNG(0, 6);\n\
    \      if (t == 0) {\n        int i = RNG(0, N);\n        assert(A[i] == X.get(root,\
    \ i).se);\n      }\n      if (t == 1) {\n        int i = RNG(0, N);\n        int\
    \ x = RNG(1, 10);\n        root = X.set(root, i, {1, x});\n        A[i] = x;\n\
    \      }\n      if (t == 2) {\n        int i = RNG(0, N);\n        int x = RNG(1,\
    \ 10);\n        root = X.multiply(root, i, {0, x});\n        A[i] += x;\n    \
    \  }\n      if (t == 3) {\n        int L = RNG(0, N);\n        int R = RNG(0,\
    \ N);\n        if (L > R) swap(L, R);\n        ++R;\n        int sm = 0;\n   \
    \     FOR(i, L, R) sm += A[i];\n        assert(X.prod(root, L, R).se == sm);\n\
    \      }\n      if (t == 4) {\n        int L = RNG(0, N);\n        int R = RNG(0,\
    \ N);\n        if (L > R) swap(L, R);\n        ++R;\n        root = X.reverse(root,\
    \ L, R);\n        reverse(A.begin() + L, A.begin() + R);\n      }\n      if (t\
    \ == 5) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n        if\
    \ (L > R) swap(L, R);\n        int a = RNG(1, 10);\n        ++R;\n        FOR(i,\
    \ L, R) A[i] += a;\n        root = X.apply(root, L, R, a);\n      }\n    }\n \
    \ }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n\
    \  test();\n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/rbst_lazy_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/rbst_lazy_2.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/rbst_lazy_2.test.cpp
- /verify/test/mytest/rbst_lazy_2.test.cpp.html
title: test/mytest/rbst_lazy_2.test.cpp
---
