---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':x:'
    path: ds/offline_query/mo.hpp
    title: ds/offline_query/mo.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"ds/fenwicktree/fenwicktree.hpp\"\r\n#include \"ds/offline_query/mo.hpp\"\r\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  vi key = A;\r\n \
    \ UNIQUE(key);\r\n\r\n  for (auto&& x: A) x = LB(key, x);\r\n  ll K = len(key);\r\
    \n  FenwickTree<Monoid_Add<int>> bit(K);\r\n\r\n  Mo mo;\r\n  vi ANS(Q);\r\n \
    \ FOR(Q) {\r\n    LL(L, R);\r\n    mo.add(L, R);\r\n  }\r\n\r\n  ll inv = 0;\r\
    \n  auto add_l = [&](int i) -> void {\r\n    int x = A[i];\r\n    inv += bit.sum(x);\r\
    \n    bit.add(x, +1);\r\n  };\r\n  auto rm_l = [&](int i) -> void {\r\n    int\
    \ x = A[i];\r\n    bit.add(x, -1);\r\n    inv -= bit.sum(x);\r\n  };\r\n  auto\
    \ add_r = [&](int i) -> void {\r\n    int x = A[i];\r\n    inv += bit.sum_all()\
    \ - bit.sum(x + 1);\r\n    bit.add(x, +1);\r\n  };\r\n  auto rm_r = [&](int i)\
    \ -> void {\r\n    int x = A[i];\r\n    bit.add(x, -1);\r\n    inv -= bit.sum_all()\
    \ - bit.sum(x + 1);\r\n  };\r\n  auto calc = [&](int i) -> void { ANS[i] = inv;\
    \ };\r\n  mo.calc(add_l, add_r, rm_l, rm_r, calc);\r\n  for (auto&& x: ANS) print(x);\r\
    \n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  - ds/offline_query/mo.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
- /verify/test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp.html
title: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
---
