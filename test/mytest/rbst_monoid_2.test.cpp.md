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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/bbst/rbst_monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/monoid/affine.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"ds/bbst/rbst_monoid.hpp\"\n#include \"random/base.hpp\"\n\nusing\
    \ mint = modint998;\n\nvoid test() {\n  using Mono = Monoid_Affine<mint>;\n  RBST_Monoid<Mono,\
    \ false, 100> X;\n  auto rnd_affine = [&]() -> pair<mint, mint> {\n    int a =\
    \ RNG(0, 3);\n    int b = RNG(0, 3);\n    return {a, b};\n  };\n\n  using T =\
    \ typename Mono::value_type;\n\n  FOR(1000) {\n    X.reset();\n    int N = 2;\n\
    \    int Q = RNG(1, 1000);\n    vc<T> A(N);\n    FOR(i, N) A[i] = rnd_affine();\n\
    \    auto root = X.new_node(A);\n\n    FOR(Q) {\n      vc<int> cand = {0, 1, 2,\
    \ 3, 4, 5};\n      int t = cand[RNG(0, len(cand))];\n      if (t == 0) {\n   \
    \     int i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n \
    \     if (t == 1) {\n        int i = RNG(0, N);\n        T x = rnd_affine();\n\
    \        root = X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t ==\
    \ 2) {\n        int i = RNG(0, N);\n        T x = rnd_affine();\n        root\
    \ = X.multiply(root, i, x);\n        A[i] = Mono::op(A[i], x);\n      }\n    \
    \  if (t == 3) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n   \
    \     if (L > R) swap(L, R);\n        ++R;\n        vc<T> B = {A.begin() + L,\
    \ A.begin() + R};\n        T t = Mono::unit();\n        for (auto&& b: B) t =\
    \ Mono::op(t, b);\n        assert(X.prod(root, L, R) == t);\n      }\n      if\
    \ (t == 4) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n       \
    \ if (L > R) swap(L, R);\n        ++R;\n        root = X.reverse(root, L, R);\n\
    \        reverse(A.begin() + L, A.begin() + R);\n      }\n      if (t == 5) {\n\
    \        vc<T> B = X.get_all(root);\n        assert(A == B);\n      }\n    }\n\
    \  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n\
    \  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/rbst_monoid_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/rbst_monoid_2.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/rbst_monoid_2.test.cpp
- /verify/test/mytest/rbst_monoid_2.test.cpp.html
title: test/mytest/rbst_monoid_2.test.cpp
---
