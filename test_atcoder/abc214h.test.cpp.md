---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/mincostflow.hpp
    title: flow/mincostflow.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc214/tasks/abc214_h
    links:
    - https://atcoder.jp/contests/abc214/tasks/abc214_h
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_h\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/strongly_connected_component.hpp\"\
    \n#include \"flow/mincostflow.hpp\"\n\nvoid solve() {\n  LL(N, M, K);\n  Graph<int,\
    \ 1> G0(N);\n  G0.read_graph(M);\n\n  auto [nc, comp] = strongly_connected_component(G0);\n\
    \  auto DAG = scc_dag(G0, nc, comp);\n  vi X(nc);\n  FOR(v, N) {\n    INT(x);\n\
    \    X[comp[v]] += x;\n  }\n\n  auto idx1 = [&](int i) -> int { return 1 + 2 *\
    \ i + 0; };\n  auto idx2 = [&](int i) -> int { return 1 + 2 * i + 1; };\n  int\
    \ source = 0, sink = 1 + nc + nc;\n\n  Min_Cost_Flow<int, ll, true> G(2 * nc +\
    \ 2, source, sink);\n  G.add(source, idx1(comp[0]), K, 0);\n  FOR(v, nc) {\n \
    \   G.add(idx1(v), idx2(v), 1, -X[v]);\n    G.add(idx1(v), idx2(v), K, 0);\n \
    \   G.add(idx2(v), sink, K, 0);\n  }\n  for (auto&& e: DAG.edges) { G.add(idx2(e.frm),\
    \ idx1(e.to), K, 0); }\n\n  auto [a, b] = G.flow();\n  assert(a == K);\n  print(-b);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/strongly_connected_component.hpp
  - graph/base.hpp
  - flow/mincostflow.hpp
  isVerificationFile: true
  path: test_atcoder/abc214h.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc214h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc214h.test.cpp
- /verify/test_atcoder/abc214h.test.cpp.html
title: test_atcoder/abc214h.test.cpp
---
