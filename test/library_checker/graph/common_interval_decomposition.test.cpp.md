---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/acted_monoid/min_add.hpp
    title: alg/acted_monoid/min_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: seq/common_interval_decomposition.hpp
    title: seq/common_interval_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/common_interval_decomposition_tree
    links:
    - https://judge.yosupo.jp/problem/common_interval_decomposition_tree
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
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/common_interval_decomposition_tree\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"seq/common_interval_decomposition.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(int, P, N);\n  Common_Inverval_Decomposition<1000000>\
    \ X(P);\n  int nxt = 0;\n  auto dfs = [&](auto& dfs, auto n, int p) -> void {\n\
    \    string t = (n->inc || n->dec || (n->r - n->l == 1) ? \"linear\" : \"prime\"\
    );\n    print(p, n->l, n->r - 1, t);\n    int v = nxt++;\n    for (auto&& c: n->ch)\
    \ dfs(dfs, c, v);\n  };\n  print(X.pid);\n  dfs(dfs, X.root, -1);\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - seq/common_interval_decomposition.hpp
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/min_add.hpp
  - alg/monoid/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/library_checker/graph/common_interval_decomposition.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/common_interval_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/common_interval_decomposition.test.cpp
- /verify/test/library_checker/graph/common_interval_decomposition.test.cpp.html
title: test/library_checker/graph/common_interval_decomposition.test.cpp
---
