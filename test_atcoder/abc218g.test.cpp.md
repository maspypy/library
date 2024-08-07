---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/binary_trie.hpp
    title: ds/binary_trie.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc218/tasks/abc218_g
    links:
    - https://atcoder.jp/contests/abc218/tasks/abc218_g
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc218/tasks/abc218_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/binary_trie.hpp\"\
    \n\nll A[100010];\nint N, m[100010];\nBinary_Trie<30, false, 200'100, u32> BT;\n\
    using np = decltype(BT)::np;\nnp root;\n\nvector<int> G[100010];\n\nint get_med()\
    \ {\n  int cnt = root->cnt;\n  if (cnt & 1) { return BT.kth(root, cnt / 2, 0);\
    \ }\n  return (BT.kth(root, cnt / 2, 0) + BT.kth(root, (cnt - 1) / 2, 0)) / 2;\n\
    }\n\nvoid dfs(int v, int p, int mode) {\n  bool f = true;\n  if (mode) m[v] =\
    \ 1 << 30;\n  root = BT.add(root, A[v], 1);\n  for (auto u: G[v]) {\n    if (u\
    \ == p) continue;\n    f = false;\n    dfs(u, v, (mode + 1) & 1);\n    if (mode)\
    \ {\n      chmin(m[v], m[u]);\n    } else {\n      chmax(m[v], m[u]);\n    }\n\
    \  }\n  if (f) m[v] = get_med();\n  root = BT.add(root, A[v], -1);\n}\n\nvoid\
    \ solve() {\n  INT(N);\n  root = BT.new_root();\n  FOR(i, 1, N + 1) read(A[i]);\n\
    \  FOR(i, 1, N) {\n    INT(x, y);\n    G[x].eb(y), G[y].eb(x);\n  }\n  dfs(1,\
    \ 0, 0);\n  print(m[1]);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/binary_trie.hpp
  isVerificationFile: true
  path: test_atcoder/abc218g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc218g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc218g.test.cpp
- /verify/test_atcoder/abc218g.test.cpp.html
title: test_atcoder/abc218g.test.cpp
---
