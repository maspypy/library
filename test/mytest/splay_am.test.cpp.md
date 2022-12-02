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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/acted_monoid/cntsum_add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/cntsum_add.hpp\"\n\
    #include \"mod/modint.hpp\"\n#include \"random/base.hpp\"\n#include \"ds/splay/splaytree_acted_monoid.hpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  using AM = ActedMonoid_CntSum_Add<int>;\n\
    \n  SplayTree_ActedMonoid<AM, 100> X;\n\n  FOR(1000) {\n    X.reset();\n    int\
    \ N = RNG(1, 10);\n    int Q = RNG(1, 1000);\n    vc<int> A(N);\n    FOR(i, N)\
    \ A[i] = RNG(1, 10);\n\n    vc<pair<int, int>> seg_raw(N);\n    FOR(i, N) seg_raw[i]\
    \ = {1, A[i]};\n    auto root = X.new_node(seg_raw);\n\n    FOR(Q) {\n      int\
    \ t = RNG(0, 7);\n      if (t == 0) {\n        vc<pair<int, int>> B = X.get_all(root);\n\
    \        FOR(i, N) assert(A[i] == B[i].se);\n      }\n      if (t == 1) {\n  \
    \      int i = RNG(0, N);\n        assert(A[i] == X.get(root, i).se);\n      }\n\
    \      if (t == 2) {\n        int i = RNG(0, N);\n        int x = RNG(1, 10);\n\
    \        X.set(root, i, {1, x});\n        A[i] = x;\n      }\n      if (t == 3)\
    \ {\n        int i = RNG(0, N);\n        int x = RNG(1, 10);\n        X.multiply(root,\
    \ i, {0, x});\n        A[i] += x;\n      }\n      if (t == 4) {\n        int L\
    \ = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n \
    \       ++R;\n        int sm = 0;\n        FOR(i, L, R) sm += A[i];\n        assert(X.prod(root,\
    \ L, R).se == sm);\n      }\n      if (t == 5) {\n        int L = RNG(0, N);\n\
    \        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n  \
    \      X.reverse(root, L, R);\n        reverse(A.begin() + L, A.begin() + R);\n\
    \      }\n      if (t == 6) {\n        int L = RNG(0, N);\n        int R = RNG(0,\
    \ N);\n        if (L > R) swap(L, R);\n        int a = RNG(1, 10);\n        ++R;\n\
    \        FOR(i, L, R) A[i] += a;\n        X.apply(root, L, R, a);\n      }\n \
    \   }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/splay_am.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/splay_am.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/splay_am.test.cpp
- /verify/test/mytest/splay_am.test.cpp.html
title: test/mytest/splay_am.test.cpp
---
