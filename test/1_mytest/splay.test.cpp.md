---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_monoid.hpp
    title: ds/splaytree/splaytree_monoid.hpp
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
    \n#include \"alg/monoid/affine.hpp\"\n#include \"mod/modint.hpp\"\n#include \"\
    random/base.hpp\"\n#include \"ds/splaytree/splaytree_monoid.hpp\"\n\nvoid test()\
    \ {\n  // reverse, set, prod \u306E\u52D5\u4F5C\u3092\u78BA\u8A8D\n  using mint\
    \ = modint998;\n  using Mono = Monoid_Affine<mint>;\n  using X = Mono::value_type;\n\
    \n  auto rnd_X = [&]() -> X {\n    ll a = RNG(0, 1 << 30);\n    ll b = RNG(0,\
    \ 1 << 30);\n    return {mint(a), mint(b)};\n  };\n  auto get_lr = [&](int N)\
    \ -> pi {\n    int l = RNG(0, N);\n    int r = RNG(0, N);\n    if (l > r) swap(l,\
    \ r);\n    ++r;\n    return {l, r};\n  };\n\n  FOR(N, 1, 10) {\n    vc<X> A(N);\n\
    \    FOR(i, N) { A[i] = rnd_X(); }\n    SplayTree_Monoid<Mono> ST(N);\n\n    auto\
    \ root = ST.new_node(A);\n    FOR(100) {\n      int t = RNG(0, 3);\n      if (t\
    \ == 0) {\n        // set\n        int i = RNG(0, N);\n        X x = rnd_X();\n\
    \        A[i] = x;\n        ST.set(root, i, x);\n      }\n      if (t == 1) {\n\
    \        // reverse\n        auto [l, r] = get_lr(N);\n        reverse(A.begin()\
    \ + l, A.begin() + r);\n        ST.reverse(root, l, r);\n      }\n      if (t\
    \ == 2) {\n        // prod\n        auto [l, r] = get_lr(N);\n        X a = Mono::unit();\n\
    \        FOR(i, l, r) a = Mono::op(a, A[i]);\n        X b = ST.prod(root, l, r);\n\
    \        assert(a == b);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - random/base.hpp
  - ds/splaytree/splaytree_monoid.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/1_mytest/splay.test.cpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/splay.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/splay.test.cpp
- /verify/test/1_mytest/splay.test.cpp.html
title: test/1_mytest/splay.test.cpp
---
