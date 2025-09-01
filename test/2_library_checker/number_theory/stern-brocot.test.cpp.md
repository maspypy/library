---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/stern_brocot_tree.hpp
    title: nt/stern_brocot_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/stern_brocot_tree
    links:
    - https://judge.yosupo.jp/problem/stern_brocot_tree
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stern_brocot_tree\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"nt/stern_brocot_tree.hpp\"\
    \n\nvoid solve() {\n  using SBT = Stern_Brocot_Tree;\n  STR(S);\n  if (S == \"\
    DECODE_PATH\") {\n    INT(n);\n    vi A;\n    FOR(n) {\n      CHAR(s);\n     \
    \ INT(x);\n      if (A.empty() && s == 'L') { A.eb(0); }\n      A.eb(x);\n   \
    \ }\n    auto [a, b] = SBT::from_path(A);\n    print(a, b);\n  }\n  if (S == \"\
    ENCODE_PATH\") {\n    LL(a, b);\n    vi A = SBT::get_path({a, b});\n    vc<string>\
    \ ANS;\n    FOR(i, len(A)) {\n      if (A[i] == 0) continue;\n      string x =\
    \ (i % 2 == 0 ? \"R\" : \"L\");\n      ANS.eb(x);\n      ANS.eb(to_string(A[i]));\n\
    \    }\n    print(len(ANS) / 2, ANS);\n  }\n  if (S == \"LCA\") {\n    LL(a, b,\
    \ c, d);\n    auto [e, f] = SBT::LCA({a, b}, {c, d});\n    print(e, f);\n  }\n\
    \  if (S == \"ANCESTOR\") {\n    LL(k, a, b);\n    auto [x, y] = SBT::LA({a, b},\
    \ k);\n    if (x == -1) {\n      print(-1);\n    } else {\n      print(x, y);\n\
    \    }\n  }\n  if (S == \"RANGE\") {\n    LL(a, b);\n    auto [x, y] = SBT::range({a,\
    \ b});\n    print(x, y);\n  }\n}\n\nsigned main() {\n  INT(T);\n  FOR(T)\n  solve();\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - nt/stern_brocot_tree.hpp
  isVerificationFile: true
  path: test/2_library_checker/number_theory/stern-brocot.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/number_theory/stern-brocot.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/number_theory/stern-brocot.test.cpp
- /verify/test/2_library_checker/number_theory/stern-brocot.test.cpp.html
title: test/2_library_checker/number_theory/stern-brocot.test.cpp
---
