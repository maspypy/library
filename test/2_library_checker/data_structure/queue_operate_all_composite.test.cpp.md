---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"alg/monoid/affine.hpp\"\r\n#include \"ds/sliding_window_aggregation.hpp\"\r\
    \n#include \"mod/modint.hpp\"\r\n\r\nusing mint = modint998;\r\n\r\nvoid solve()\
    \ {\r\n  LL(Q);\r\n  using Mono = Monoid_Affine<mint>;\r\n  using F = Mono::value_type;\r\
    \n\r\n  Sliding_Window_Aggregation<Mono> swag;\r\n\r\n  FOR(_, Q) {\r\n    LL(t);\r\
    \n    if (t == 0) {\r\n      LL(a, b);\r\n      swag.push(F({a, b}));\r\n    }\r\
    \n    elif (t == 1) { swag.pop(); }\r\n    elif (t == 2) {\r\n      LL(x);\r\n\
    \      F f = swag.prod();\r\n      print(Mono::eval(f, x));\r\n    }\r\n  }\r\n\
    }\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/affine.hpp
  - ds/sliding_window_aggregation.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
- /verify/test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp.html
title: test/2_library_checker/data_structure/queue_operate_all_composite.test.cpp
---
