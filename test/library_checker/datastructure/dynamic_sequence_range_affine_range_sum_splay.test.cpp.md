---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_monoid/sum_affine.hpp
    title: alg/acted_monoid/sum_affine.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree_acted_monoid.hpp
    title: ds/splaytree/splaytree_acted_monoid.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
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
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/sum_affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"ds/splaytree/splaytree_acted_monoid.hpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  using AM = ActedMonoid_Sum_Affine<mint>;\n\
    \  SplayTree_ActedMonoid<AM, 1'000'000> X;\n  using P = typename AM::X;\n\n  INT(N,\
    \ Q);\n  VEC(mint, dat, N);\n  auto root = X.new_node(dat);\n\n  FOR(Q) {\n  \
    \  INT(t);\n    if (t == 0) {\n      INT(i, x);\n      auto [a, b] = X.split(root,\
    \ i);\n      root = X.merge3(a, X.new_node(mint(x)), b);\n    }\n    if (t ==\
    \ 1) {\n      INT(i);\n      auto [a, b, c] = X.split3(root, i, i + 1);\n    \
    \  root = X.merge(a, c);\n    }\n    if (t == 2) {\n      INT(L, R);\n      X.reverse(root,\
    \ L, R);\n    }\n    if (t == 3) {\n      INT(L, R, b, c);\n      X.apply(root,\
    \ L, R, {mint(b), mint(c)});\n    }\n    if (t == 4) {\n      INT(L, R);\n   \
    \   print(X.prod(root, L, R));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/acted_monoid/sum_affine.hpp
  - alg/monoid/add.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - ds/splaytree/splaytree_acted_monoid.hpp
  - ds/splaytree/splaytree.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp.html
title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
---
