---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/min2.hpp
    title: alg/monoid/min2.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc245/tasks/abc245_g
    links:
    - https://atcoder.jp/contests/abc245/tasks/abc245_g
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc245/tasks/abc245_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/base.hpp\"\
    \n#include \"alg/monoid/min2.hpp\"\n\nvoid solve() {\n  LL(N, M, K, L);\n  VEC(ll,\
    \ A, N);\n  for (auto&& a: A) --a;\n  VEC(ll, B, L);\n  for (auto&& b: B) --b;\n\
    \n  Graph<int, 0> G(N);\n  G.read_graph(M, 1);\n\n  using Mono = Monoid_Min2<ll,\
    \ int>;\n  using Data = typename Mono::Data;\n  vc<Data> dist(N, Mono::unit());\n\
    \n  using T = tuple<ll, int, int>; // \u8DDD\u96E2\u3001\u753A\u3001\u8272\n \
    \ pqg<T> que;\n\n  auto add = [&](ll v, ll c, ll x) -> void {\n    if (dist[v].add_element(x,\
    \ c)) que.emplace(x, v, c);\n  };\n\n  for (auto&& b: B) add(b, A[b], 0);\n\n\
    \  while (len(que)) {\n    auto [dv, v, c] = que.top();\n    que.pop();\n    bool\
    \ ok = 0;\n    auto& e = dist[v];\n    if (e.min1 == dv && e.key1 == c) ok = 1;\n\
    \    if (e.min2 == dv && e.key2 == c) ok = 1;\n    if (!ok) continue;\n    for\
    \ (auto&& e: G[v]) { add(e.to, c, dv + e.cost); }\n  }\n\n  vi ANS(N);\n  FOR(v,\
    \ N) {\n    auto& e = dist[v];\n    ll x = infty<ll>;\n    if (e.key1 != A[v])\
    \ chmin(x, e.min1);\n    if (e.key2 != A[v]) chmin(x, e.min2);\n    if (x == infty<ll>)\
    \ x = -1;\n    ANS[v] = x;\n  }\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/base.hpp
  - alg/monoid/min2.hpp
  isVerificationFile: true
  path: test_atcoder/abc245g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc245g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc245g.test.cpp
- /verify/test_atcoder/abc245g.test.cpp.html
title: test_atcoder/abc245g.test.cpp
---
