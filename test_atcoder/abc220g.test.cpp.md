---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/max2.hpp
    title: alg/monoid/max2.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/perpendicular_bisector.hpp
    title: geo/perpendicular_bisector.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc220/tasks/abc220_g
    links:
    - https://atcoder.jp/contests/abc220/tasks/abc220_g
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc220/tasks/abc220_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"geo/base.hpp\"\n\
    #include \"geo/perpendicular_bisector.hpp\"\n#include \"random/base.hpp\"\n#include\
    \ \"ds/hashmap.hpp\"\n#include \"alg/monoid/max2.hpp\"\n\nusing P = Point<ll>;\n\
    \nvoid solve() {\n  LL(N);\n  vc<P> point(N);\n  vi C(N);\n  FOR(i, N) read(point[i],\
    \ C[i]);\n\n  u64 aa = RNG_64(), bb = RNG_64(), cc = RNG_64();\n\n  using Mono\
    \ = Monoid_Max2<ll, ll>;\n  using Data = typename Mono::Data;\n  HashMap<Data>\
    \ MP;\n\n  FOR(j, N) FOR(i, j) {\n    Line<ll> L = perpendicular_bisector(point[i],\
    \ point[j]);\n    L.normalize();\n    u64 key = 0;\n    key += u64(L.a + infty<ll>)\
    \ * aa;\n    key += u64(L.b + infty<ll>) * bb;\n    key += u64(L.c + infty<ll>)\
    \ * cc;\n    if (!MP.count(key)) MP[key] = Mono::unit();\n    ll g = gcd(L.a,\
    \ L.b);\n    Point<ll> normal = {L.b / g, -L.a / g};\n    ll t = normal.dot(point[i]);\n\
    \    MP[key].add_element(C[i] + C[j], t);\n  }\n\n  ll ANS = -1;\n  MP.enumerate_all([&](auto\
    \ key, auto dat) -> void {\n    ll ans = dat.max1 + dat.max2;\n    chmax(ANS,\
    \ ans);\n  });\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - geo/base.hpp
  - geo/perpendicular_bisector.hpp
  - random/base.hpp
  - ds/hashmap.hpp
  - alg/monoid/max2.hpp
  isVerificationFile: true
  path: test_atcoder/abc220g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc220g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc220g.test.cpp
- /verify/test_atcoder/abc220g.test.cpp.html
title: test_atcoder/abc220g.test.cpp
---
