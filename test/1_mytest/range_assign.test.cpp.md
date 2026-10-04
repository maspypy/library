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
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/segtree/range_assignment_segtree.hpp\"\n#include \"ds/segtree/lazy_segtree.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n#include \"alg/acted_monoid/sum_assign.hpp\"\
    \n#include \"random/base.hpp\"\n\nstruct PROB {\n  int N, Q;\n  vc<ll> INIT;\n\
    \  vc<tuple<int, int, int>> QUERY;\n};\n\nPROB gen(int N, int Q) {\n  PROB p;\n\
    \  p.N = N, p.Q = Q;\n  FOR(N) { p.INIT.eb(RNG(0, 1 << 30)); }\n  FOR(Q) {\n \
    \   int t = RNG(0, 2);\n    int l = RNG(0, N), r = RNG(0, N);\n    int x = RNG(0,\
    \ 1 << 30);\n    if (l > r) swap(l, r);\n    ++r;\n    if (t == 0) p.QUERY.eb(l,\
    \ r, x);\n    if (t == 1) p.QUERY.eb(l, r, -1);\n  }\n  return p;\n}\n\nvi sol_1(PROB\
    \ p) {\n  vi ANS;\n  Lazy_SegTree<ActedMonoid_Sum_Assign<ll, -1>> seg(p.INIT);\n\
    \  for (auto& [l, r, x]: p.QUERY) {\n    if (x == -1) {\n      ANS.eb(seg.prod(l,\
    \ r));\n    } else {\n      seg.apply(l, r, x);\n    }\n  }\n  return ANS;\n}\n\
    \nvi sol_2(PROB p) {\n  vi ANS;\n  Range_Assignment_SegTree<Monoid_Add<ll>> seg(p.INIT);\n\
    \  for (auto& [l, r, x]: p.QUERY) {\n    if (x == -1) {\n      ANS.eb(seg.prod(l,\
    \ r));\n    } else {\n      seg.assign(l, r, x);\n    }\n  }\n  return ANS;\n\
    }\n\nvoid test() {\n  int N = 1 << 22, Q = 1 << 22;\n  PROB p = gen(N, Q);\n \
    \ double a = clock();\n  vi A = sol_1(p);\n  double b = clock();\n  vi B = sol_2(p);\n\
    \  double c = clock();\n  a = (b - a) / CLOCKS_PER_SEC;\n  b = (c - b) / CLOCKS_PER_SEC;\n\
    \  assert(A == B);\n  // cout << a << \"\\n\"; 1.563 sec\n  // cout << b << \"\
    \\n\"; 1.376 sec\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/range_assign.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/range_assign.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/range_assign.test.cpp
- /verify/test/1_mytest/range_assign.test.cpp.html
title: test/1_mytest/range_assign.test.cpp
---
