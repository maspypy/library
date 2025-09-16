---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_add.hpp
    title: alg/acted_monoid/sum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_acted_monoid.hpp
    title: ds/splaytree/splaytree_acted_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/splaytree/splaytree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"alg/acted_monoid/sum_add.hpp\"\n#include \"mod/modint.hpp\"\n#include\
    \ \"random/base.hpp\"\n#include \"ds/splaytree/splaytree_acted_monoid.hpp\"\n\n\
    using mint = modint998;\n\nvoid test() {\n  using AM = ActedMonoid_Sum_Add<int>;\n\
    \n  FOR(1000) {\n    int N = RNG(1, 10);\n    int Q = RNG(1, 1000);\n    SplayTree_ActedMonoid<AM>\
    \ X(N);\n    vc<int> A(N);\n    FOR(i, N) A[i] = RNG(1, 10);\n\n    auto root\
    \ = X.new_node(A);\n\n    FOR(Q) {\n      int t = RNG(0, 7);\n      if (t == 0)\
    \ {\n        vc<int> B = X.get_all(root);\n        FOR(i, N) assert(A[i] == B[i]);\n\
    \      }\n      if (t == 1) {\n        int i = RNG(0, N);\n        assert(A[i]\
    \ == X.get(root, i));\n      }\n      if (t == 2) {\n        int i = RNG(0, N);\n\
    \        int x = RNG(1, 10);\n        X.set(root, i, x);\n        A[i] = x;\n\
    \      }\n      if (t == 3) {\n        int i = RNG(0, N);\n        int x = RNG(1,\
    \ 10);\n        X.multiply(root, i, x);\n        A[i] += x;\n      }\n      if\
    \ (t == 4) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n       \
    \ if (L > R) swap(L, R);\n        ++R;\n        int sm = 0;\n        FOR(i, L,\
    \ R) sm += A[i];\n        assert(X.prod(root, L, R) == sm);\n      }\n      if\
    \ (t == 5) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n       \
    \ if (L > R) swap(L, R);\n        ++R;\n        X.reverse(root, L, R);\n     \
    \   reverse(A.begin() + L, A.begin() + R);\n      }\n      if (t == 6) {\n   \
    \     int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        int a = RNG(1, 10);\n        ++R;\n        FOR(i, L, R) A[i] +=\
    \ a;\n        X.apply(root, L, R, a);\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - alg/acted_monoid/sum_add.hpp
  - alg/monoid/add.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - random/base.hpp
  - ds/splaytree/splaytree_acted_monoid.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/1_mytest/splay_am.test.cpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/splay_am.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/splay_am.test.cpp
- /verify/test/1_mytest/splay_am.test.cpp.html
title: test/1_mytest/splay_am.test.cpp
---
