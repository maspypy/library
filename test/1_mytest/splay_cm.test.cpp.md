---
data:
  _extendedDependsOn:
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
    path: ds/splaytree/splaytree_commutative_monoid.hpp
    title: ds/splaytree/splaytree_commutative_monoid.hpp
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
    \n#include \"alg/monoid/add.hpp\"\n#include \"mod/modint.hpp\"\n#include \"ds/splaytree/splaytree_commutative_monoid.hpp\"\
    \n#include \"random/base.hpp\"\n\nusing mint = modint998;\n\nvoid test() {\n \
    \ using Mono = Monoid_Add<int>;\n\n  FOR(1000) {\n    int N = RNG(1, 20);\n  \
    \  int Q = RNG(1, 1000);\n    SplayTree_Commutative_Monoid<Mono> X(N);\n    using\
    \ np = decltype(X)::np;\n    vc<int> A(N);\n    FOR(i, N) A[i] = RNG(0, 100);\n\
    \    np root = X.new_node(A);\n\n    FOR(Q) {\n      vc<int> cand = {0, 1, 2,\
    \ 3, 4, 5};\n      int t = cand[RNG(0, len(cand))];\n      if (t == 0) {\n   \
    \     int i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n \
    \     if (t == 1) {\n        int i = RNG(0, N);\n        int x = RNG(0, 100);\n\
    \        X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n\
    \        int i = RNG(0, N);\n        int x = RNG(0, 100);\n        X.multiply(root,\
    \ i, x);\n        A[i] = Mono::op(A[i], x);\n      }\n      if (t == 3) {\n  \
    \      int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        vc<int> B = {A.begin() + L, A.begin() + R};\n   \
    \     assert(X.prod(root, L, R) == SUM<int>(B));\n      }\n      if (t == 4) {\n\
    \        int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        X.reverse(root, L, R);\n        reverse(A.begin()\
    \ + L, A.begin() + R);\n      }\n      if (t == 5) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/monoid/add.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - ds/splaytree/splaytree_commutative_monoid.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/splay_cm.test.cpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/splay_cm.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/splay_cm.test.cpp
- /verify/test/1_mytest/splay_cm.test.cpp.html
title: test/1_mytest/splay_cm.test.cpp
---
