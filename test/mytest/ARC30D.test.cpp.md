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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/bbst/rbst_acted_monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/acted_monoid/cntsum_add.hpp\"\n#include\
    \ \"ds/bbst/rbst_acted_monoid.hpp\"\n\nvoid test_ARC30D_case1() {\n  using AM\
    \ = ActedMonoid_CntSum_Add<ll>;\n  const int MAX = 1000;\n\n  const int N = 5;\n\
    \  const int Q = 5;\n  vi A = {1, 2, 3, 4, 5};\n\n  vc<pi> dat(N);\n  FOR(i, N)\
    \ dat[i] = {1, A[i]};\n  RBST_ActedMonoid<AM, true, MAX> RBST;\n  auto root =\
    \ RBST.new_node(dat);\n\n  auto query_1 = [&](int L, int R, int x) -> void {\n\
    \    root = RBST.apply(root, --L, R, x);\n  };\n  auto query_2 = [&](int a, int\
    \ b, int c, int d) -> void {\n    auto [xl, xm, xr] = RBST.split3(root, --a, b);\n\
    \    auto [yl, ym, yr] = RBST.split3(root, --c, d);\n    root = RBST.merge3(xl,\
    \ ym, xr);\n  };\n  auto query_3 = [&](int L, int R, int ANS) -> void {\n    assert(RBST.prod(root,\
    \ --L, R).se == ANS);\n  };\n\n  query_3(1, 5, 15);\n  query_1(1, 3, 1);\n  query_3(1,\
    \ 3, 9);\n  query_2(1, 3, 2, 4);\n  query_3(1, 5, 20);\n}\n\nvoid test_ARC30D_case2()\
    \ {\n  using AM = ActedMonoid_CntSum_Add<ll>;\n  const int MAX = 1000;\n\n  const\
    \ int N = 10;\n  const int Q = 30;\n  vi A = {-5, -5, -2, -1, 2, -2, 0, -4, 2,\
    \ 5};\n\n  vc<pi> dat(N);\n  FOR(i, N) dat[i] = {1, A[i]};\n  RBST_ActedMonoid<AM,\
    \ true, MAX> RBST;\n  auto root = RBST.new_node(dat);\n\n  auto query_1 = [&](int\
    \ L, int R, int x) -> void {\n    root = RBST.apply(root, --L, R, x);\n  };\n\
    \  auto query_2 = [&](int a, int b, int c, int d) -> void {\n    auto [xl, xm,\
    \ xr] = RBST.split3(root, --a, b);\n    auto [yl, ym, yr] = RBST.split3(root,\
    \ --c, d);\n    root = RBST.merge3(xl, ym, xr);\n  };\n  auto query_3 = [&](int\
    \ L, int R, int ANS) -> void {\n    assert(RBST.prod(root, --L, R).se == ANS);\n\
    \  };\n\n  query_2(9, 10, 9, 10);\n  query_2(3, 5, 2, 4);\n  query_1(2, 10, -1);\n\
    \  query_2(1, 7, 1, 7);\n  query_3(1, 4, -20);\n\n  query_2(1, 6, 2, 7);\n  query_2(5,\
    \ 8, 6, 9);\n  query_3(4, 8, -8);\n  query_3(1, 10, -18);\n  query_3(9, 9, 1);\n\
    \n  query_1(3, 8, -1);\n  query_2(4, 9, 1, 6);\n  query_3(2, 7, -29);\n  query_1(9,\
    \ 10, -4);\n  query_1(6, 9, -5);\n\n  query_1(4, 6, -7);\n  query_3(2, 5, -36);\n\
    \  query_2(10, 10, 7, 7);\n  query_1(3, 4, -10);\n  query_3(4, 9, -78);\n\n  query_3(8,\
    \ 9, -18);\n  query_2(6, 7, 8, 9);\n  query_3(3, 5, -50);\n  query_3(3, 9, -86);\n\
    \  query_1(2, 10, -10);\n\n  query_2(4, 6, 4, 6);\n  query_2(4, 9, 5, 10);\n \
    \ query_1(2, 6, 7);\n  query_3(7, 8, -38);\n  query_1(3, 6, 3);\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test_ARC30D_case1();\n\
    \  test_ARC30D_case2();\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/ARC30D.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/ARC30D.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/ARC30D.test.cpp
- /verify/test/mytest/ARC30D.test.cpp.html
title: test/mytest/ARC30D.test.cpp
---
