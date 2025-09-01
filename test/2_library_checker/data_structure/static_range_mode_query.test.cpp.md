---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: ds/offline_query/rollback_mo.hpp
    title: ds/offline_query/rollback_mo.hpp
  - icon: ':x:'
    path: ds/to_small_key.hpp
    title: ds/to_small_key.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/subprocess.py\"\
    , line 472, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \               **kwargs).stdout\n               ^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/subprocess.py\"\
    , line 577, in run\n    raise CalledProcessError(retcode, process.args,\n    \
    \                         output=stdout, stderr=stderr)\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/offline_query/rollback_mo.hpp\"\
    \n#include \"ds/to_small_key.hpp\"\n\nvoid solve() {\n  INT(N, Q);\n  VEC(int,\
    \ A, N);\n  vc<int> key = A;\n  UNIQUE(key);\n  for (auto& x: A) x = LB(key, x);\n\
    \n  Rollback_Mo mo;\n  FOR(Q) {\n    LL(L, R);\n    mo.add(L, R);\n  }\n  vc<pair<int,\
    \ int>> ANS(Q);\n\n  vc<int> CNT(N);\n  int max_cnt = 0;\n  int max_key = 0;\n\
    \  vc<int> history;\n\n  auto add = [&](int i) -> void {\n    int x = A[i];\n\
    \    history.eb(x);\n    CNT[x]++;\n    if (chmax(max_cnt, CNT[x])) max_key =\
    \ x;\n  };\n\n  auto reset = [&]() -> void {\n    for (auto& x: history) CNT[x]\
    \ = 0;\n    history.clear();\n    max_cnt = 0, max_key = 0;\n  };\n\n  int save_cnt\
    \ = 0, save_key = 0;\n  int save_time = 0;\n  auto save = [&]() -> void {\n  \
    \  save_time = len(history);\n    save_cnt = max_cnt, save_key = max_key;\n  };\n\
    \n  auto rb = [&]() -> void {\n    while (len(history) > save_time) {\n      int\
    \ x = POP(history);\n      CNT[x]--;\n    }\n    max_cnt = save_cnt, max_key =\
    \ save_key;\n  };\n\n  auto query = [&](int q) -> void { ANS[q] = {key[max_key],\
    \ max_cnt}; };\n\n  mo.calc(add, add, reset, save, rb, query);\n  for (auto& x:\
    \ ANS) print(x);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/offline_query/rollback_mo.hpp
  - ds/to_small_key.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/static_range_mode_query.test.cpp
- /verify/test/2_library_checker/data_structure/static_range_mode_query.test.cpp.html
title: test/2_library_checker/data_structure/static_range_mode_query.test.cpp
---
