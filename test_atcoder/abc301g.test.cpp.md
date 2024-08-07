---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo3d/base.hpp
    title: geo3d/base.hpp
  - icon: ':x:'
    path: geo3d/cross_point.hpp
    title: geo3d/cross_point.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/rational.hpp
    title: nt/rational.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc301/tasks/abc301_g
    links:
    - https://atcoder.jp/contests/abc301/tasks/abc301_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc301/tasks/abc301_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"nt/rational.hpp\"\
    \n#include \"geo3d/base.hpp\"\n#include \"geo3d/cross_point.hpp\"\n\nusing Q =\
    \ Rational<ll, false>;\n\nusing P = Point_3d<ll>;\nusing PQ = Point_3d<Q>;\n\n\
    void solve() {\n  LL(N);\n  vc<P> point(N);\n  FOR(i, N) {\n    LL(a, b, c);\n\
    \    point[i] = {a, b, c};\n  }\n\n  sort(all(point), [&](auto& a, auto& b) ->\
    \ bool { return a.x < b.x; });\n\n  ll ANS = N;\n\n  vv(ll, CNT, N, N);\n\n  //\
    \ \u76F4\u7DDA\u3072\u3068\u3064\u3060\u3051\n  FOR(i, N) FOR(j, i + 1, N) {\n\
    \    if (point[i].x == point[j].x) continue;\n    Line_3d<ll> L(point[i], point[j]);\n\
    \    ll cnt = 0;\n    FOR(k, N) cnt += L.contain(point[k]);\n    CNT[i][j] = cnt;\n\
    \    chmin(ANS, N - (cnt - 1));\n  }\n\n  vc<PQ> point_PQ(N);\n  FOR(i, N) point_PQ[i]\
    \ = {point[i].x, point[i].y, point[i].z};\n\n  // \u4EA4\u70B9\u3092\u5229\u7528\
    \u3059\u308B\n  FOR(b, N) FOR(a, b) FOR(d, b) FOR(c, d) {\n    Line_3d<ll> L1(point[a],\
    \ point[b]);\n    Line_3d<ll> L2(point[c], point[d]);\n    ll n = count_cross(L1,\
    \ L2);\n    if (n != 1) continue;\n    PQ p = cross_point<Q>(L1, L2);\n    if\
    \ (p.x >= Q(0)) continue;\n    vc<int> OK(N, 1);\n    FOR(i, N) {\n      PQ a\
    \ = point_PQ[i] - p;\n      FOR(j, i) {\n        PQ b = point_PQ[j] - p;\n   \
    \     b = b.cross(a);\n        if (b.x == Q(0) && b.y == Q(0) && b.z == Q(0))\
    \ OK[i] = 0;\n      }\n    }\n    chmin(ANS, SUM<int>(OK));\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - nt/rational.hpp
  - geo3d/base.hpp
  - geo3d/cross_point.hpp
  isVerificationFile: true
  path: test_atcoder/abc301g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc301g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc301g.test.cpp
- /verify/test_atcoder/abc301g.test.cpp.html
title: test_atcoder/abc301g.test.cpp
---
