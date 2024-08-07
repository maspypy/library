---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':question:'
    path: ds/segtree/segtree_2d.hpp
    title: ds/segtree/segtree_2d.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc266/tasks/abc266_Ex
    links:
    - https://atcoder.jp/contests/abc266/tasks/abc266_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree/segtree_2d.hpp\"\
    \n#include \"alg/monoid/max.hpp\"\n\nusing Mono = Monoid_Max<ll>;\n\nvoid solve()\
    \ {\n  LL(N);\n  using T = tuple<ll, ll, ll, ll>;\n\n  VEC(T, dat, N);\n  dat.eb(0,\
    \ 0, 0, 0);\n  ++N;\n\n  sort(all(dat), [&](auto& a, auto& b) -> bool {\n    auto\
    \ [at, ax, ay, aa] = a;\n    auto [bt, bx, by, bb] = b;\n    if (ay < by) return\
    \ true;\n    if (ay > by) return false;\n    return at < bt;\n  });\n\n  SegTree_2D<Mono,\
    \ ll, false> seg1(N, [&](int i) -> tuple<int, int, ll> {\n    auto [t, x, y, v]\
    \ = dat[i];\n    return {x, x + y - t, Mono::unit()};\n  });\n  SegTree_2D<Mono,\
    \ ll, false> seg2(N, [&](int i) -> tuple<int, int, ll> {\n    auto [t, x, y, v]\
    \ = dat[i];\n    return {x, x - y + t, Mono::unit()};\n  });\n\n  ll ANS = 0;\n\
    \  FOR(i, N) {\n    const auto [t, x, y, v] = dat[i];\n    if (i == 0) {\n   \
    \   seg1.multiply(i, 0);\n      seg2.multiply(i, 0);\n      continue;\n    }\n\
    \    ll best = -infty<ll>;\n    chmax(best, seg1.prod(-infty<ll>, x + 1, x + y\
    \ - t, infty<ll>));\n    chmax(best, seg2.prod(x, infty<ll>, -infty<ll>, x - y\
    \ + t + 1));\n    if (best < 0) continue;\n    best += v;\n    chmax(ANS, best);\n\
    \    seg1.multiply(i, best);\n    seg2.multiply(i, best);\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/segtree_2d.hpp
  - alg/monoid/max.hpp
  isVerificationFile: true
  path: test_atcoder/abc266h.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc266h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc266h.test.cpp
- /verify/test_atcoder/abc266h.test.cpp.html
title: test_atcoder/abc266h.test.cpp
---
