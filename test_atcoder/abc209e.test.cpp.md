---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: game/graph_game.hpp
    title: game/graph_game.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/reverse_graph.hpp
    title: graph/reverse_graph.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc209/tasks/abc209_e
    links:
    - https://atcoder.jp/contests/abc209/tasks/abc209_e
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc209/tasks/abc209_e\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"game/graph_game.hpp\"\
    \n#include \"graph/base.hpp\"\n\nvoid solve() {\n  LL(N);\n  VEC(string, dat,\
    \ N);\n  vc<string> states;\n  FOR(i, N) {\n    string a = dat[i].substr(0, 3);\n\
    \    string b = dat[i].substr(len(dat[i]) - 3, 3);\n    states.eb(a);\n    states.eb(b);\n\
    \  }\n  UNIQUE(states);\n\n  Graph<bool, 1> G(len(states));\n  FOR(i, N) {\n \
    \   string a = dat[i].substr(0, 3);\n    string b = dat[i].substr(len(dat[i])\
    \ - 3, 3);\n    G.add(LB(states, a), LB(states, b));\n  }\n  G.build();\n\n  auto\
    \ out = [&](bool win, bool lose) -> void {\n    if (win) return print(\"Aoki\"\
    );\n    if (lose) return print(\"Takahashi\");\n    return print(\"Draw\");\n\
    \  };\n\n  Graph_Game X(G);\n  FOR(i, N) {\n    int v = G.edges[i].to;\n    out(X.win[v],\
    \ X.lose[v]);\n  }\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T)\
    \ solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - game/graph_game.hpp
  - graph/reverse_graph.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test_atcoder/abc209e.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc209e.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc209e.test.cpp
- /verify/test_atcoder/abc209e.test.cpp.html
title: test_atcoder/abc209e.test.cpp
---
