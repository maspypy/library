---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/blackbox/det.hpp
    title: linalg/blackbox/det.hpp
  - icon: ':x:'
    path: linalg/blackbox/min_poly.hpp
    title: linalg/blackbox/min_poly.hpp
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
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sparse_matrix_det
    links:
    - https://judge.yosupo.jp/problem/sparse_matrix_det
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\r\n\
    #include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"linalg/blackbox/det.hpp\"\
    \r\n\r\n#include \"mod/modint.hpp\"\r\nusing mint = modint998;\r\n\r\nvoid solve()\
    \ {\r\n  LL(N, K);\r\n  using T = tuple<int, int, mint>;\r\n  VEC(T, dat, K);\r\
    \n  auto A = [&](vc<mint> X) -> vc<mint> {\r\n    vc<mint> Y(N);\r\n    for (auto&\
    \ [a, b, c]: dat) Y[b] += X[a] * c;\r\n    return Y;\r\n  };\r\n  mint d = blackbox_det<mint>(N,\
    \ A);\r\n  print(d);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - linalg/blackbox/det.hpp
  - linalg/blackbox/min_poly.hpp
  - seq/find_linear_rec.hpp
  - random/base.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
- /verify/test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp.html
title: test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
---
