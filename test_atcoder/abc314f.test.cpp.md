---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/tree_of_unionfind.hpp
    title: graph/tree_of_unionfind.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc314/tasks/abc314_f
    links:
    - https://atcoder.jp/contests/abc314/tasks/abc314_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc314/tasks/abc314_f\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/tree_of_unionfind.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nvoid solve() {\n \
    \ LL(N);\n  vc<pair<int, int>> query;\n  FOR(N - 1) {\n    LL(a, b);\n    query.eb(--a,\
    \ --b);\n  }\n\n  auto G = tree_of_unionfind(N, query, false);\n  int root = N\
    \ + N - 2;\n  vc<int> sz(N + N - 1);\n\n  {\n    auto dfs = [&](auto& dfs, int\
    \ v) -> void {\n      if (0 <= v && v < N) sz[v]++;\n      for (auto&& e: G[v])\
    \ {\n        dfs(dfs, e.to);\n        sz[v] += sz[e.to];\n      }\n    };\n  \
    \  dfs(dfs, root);\n  }\n\n  vc<mint> dp(N + N - 1);\n  {\n    auto dfs = [&](auto&\
    \ dfs, int v) -> void {\n      if (v < N) return;\n      vc<int> ch;\n      for\
    \ (auto&& e: G[v]) ch.eb(e.to);\n      assert(len(ch) == 2);\n      int s = ch[0],\
    \ t = ch[1];\n      ll a = sz[s], b = sz[t];\n      mint ps = mint(a) / mint(a\
    \ + b);\n      mint qs = mint(1) - ps;\n      dp[s] += dp[v] + ps;\n      dp[t]\
    \ += dp[v] + qs;\n      dfs(dfs, s);\n      dfs(dfs, t);\n    };\n    dfs(dfs,\
    \ root);\n  }\n  // print(sz);\n  dp.resize(N);\n  print(dp);\n}\n\nsigned main()\
    \ {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/tree_of_unionfind.hpp
  - graph/base.hpp
  - ds/unionfind/unionfind.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test_atcoder/abc314f.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc314f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc314f.test.cpp
- /verify/test_atcoder/abc314f.test.cpp.html
title: test_atcoder/abc314f.test.cpp
---
