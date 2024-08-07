---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/ds/remove_one_vertex_connectivity.hpp
    title: graph/ds/remove_one_vertex_connectivity.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc334/tasks/abc334_g
    links:
    - https://atcoder.jp/contests/abc334/tasks/abc334_g
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc334/tasks/abc334_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"graph/ds/remove_one_vertex_connectivity.hpp\"\n\nusing mint = modint998;\n\
    \nvoid solve() {\n  LL(H, W);\n  VEC(string, S, H);\n  vv(int, IDX, H, W, -1);\n\
    \  int p = 0;\n  FOR(x, H) FOR(y, W) {\n    if (S[x][y] == '#') { IDX[x][y] =\
    \ p++; }\n  }\n\n  auto isin = [&](int x, int y) -> bool {\n    return (0 <= x\
    \ && x < H && 0 <= y && y < W && S[x][y] == '#');\n  };\n  int dx[] = {1, 0, -1,\
    \ 0, 1, 1, -1, -1};\n  int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};\n\n  Graph<int,\
    \ 0> G(p);\n  FOR(x, H) FOR(y, W) {\n    FOR(d, 2) {\n      int nx = x + dx[d],\
    \ ny = y + dy[d];\n      if (!isin(x, y)) continue;\n      if (!isin(nx, ny))\
    \ continue;\n      G.add(IDX[x][y], IDX[nx][ny]);\n    }\n  }\n  G.build();\n\n\
    \  Remove_One_Vertex_Connectivity X(G);\n  mint ans = 0;\n  FOR(v, p) { ans +=\
    \ X.n_comp(v); }\n  ans /= mint(p);\n  print(ans);\n}\n\nsigned main() {\n  int\
    \ T = 1;\n  // INT(T);\n  FOR(T) solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - graph/ds/remove_one_vertex_connectivity.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test_atcoder/abc334g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc334g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc334g.test.cpp
- /verify/test_atcoder/abc334g.test.cpp.html
title: test_atcoder/abc334g.test.cpp
---
