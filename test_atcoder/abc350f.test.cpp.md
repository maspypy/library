---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':x:'
    path: ds/splaytree/splaytree_basic.hpp
    title: ds/splaytree/splaytree_basic.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc350/tasks/abc350_f
    links:
    - https://atcoder.jp/contests/abc350/tasks/abc350_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc350/tasks/abc350_f\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/splaytree/splaytree.hpp\"\
    \n#include \"ds/splaytree/splaytree_basic.hpp\"\n\nvoid solve() {\n  STR(S);\n\
    \  ll N = len(S);\n  SplayTree_Basic<char, 1 << 20> ST;\n  using np = decltype(ST)::np;\n\
    \n  int p = 0;\n  auto dfs = [&](auto& dfs, int dep) -> np {\n    np ans = ST.new_root();\n\
    \    while (p < len(S)) {\n      if (S[p] == '(') {\n        ++p;\n        auto\
    \ x = dfs(dfs, dep + 1);\n        ST.reverse(x);\n        ans = ST.merge(ans,\
    \ x);\n        assert(S[p] == ')');\n        ++p;\n        continue;\n      }\n\
    \      if (S[p] == ')') { break; }\n      char c = S[p];\n      if (dep % 2 ==\
    \ 1) c ^= 32;\n      np x = ST.new_node(c);\n      ans = ST.merge(ans, x);\n \
    \     p++;\n    }\n    return ans;\n  };\n\n  auto ans = dfs(dfs, 0);\n  auto\
    \ ANS = ST.get_all(ans);\n  string X;\n  for (auto& ch: ANS) X += ch;\n  print(X);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/splaytree/splaytree.hpp
  - ds/splaytree/splaytree_basic.hpp
  isVerificationFile: true
  path: test_atcoder/abc350f.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc350f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc350f.test.cpp
- /verify/test_atcoder/abc350f.test.cpp.html
title: test_atcoder/abc350f.test.cpp
---
