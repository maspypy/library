---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':x:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':x:'
    path: ds/kdtree/kdtree_acted_monoid.hpp
    title: ds/kdtree/kdtree_acted_monoid.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/kdtree/kdtree_acted_monoid.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"alg/monoid/affine.hpp\"\n#include \"\
    alg/monoid/add_pair.hpp\"\n\nusing mint = modint998;\nstruct ActedMonoid {\n \
    \ using Monoid_X = Monoid_Add_Pair<mint>;\n  using Monoid_A = Monoid_Affine<mint>;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static X act(const X &x, const A &a, const ll &size) { return {x.fi, a.fi *\
    \ x.se + a.se * x.fi}; }\n};\n\nvoid solve() {\n  LL(N, Q);\n  vc<int> X(N), Y(N);\n\
    \  vc<pair<mint, mint>> W(N);\n  FOR(i, N) {\n    INT(x, y, w);\n    X[i] = x,\
    \ Y[i] = y, W[i] = {1, w};\n  }\n\n  vc<tuple<int, int, int, int, int, int, int>>\
    \ query;\n  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      INT(x, y, w);\n  \
    \    int k = len(X);\n      X.eb(x), Y.eb(y), W.eb(0, 0);\n      query.eb(0, k,\
    \ w, 0, 0, 0, 0);\n    }\n    if (t == 1) {\n      INT(k, w);\n      query.eb(1,\
    \ k, w, 0, 0, 0, 0);\n    }\n    if (t == 2) {\n      INT(a, b, c, d);\n     \
    \ query.eb(2, a, c, b, d, 0, 0);\n    }\n    if (t == 3) {\n      INT(a, b, c,\
    \ d, p, q);\n      query.eb(3, a, c, b, d, p, q);\n    }\n  }\n  assert(len(X)\
    \ == len(Y) && len(X) == len(W));\n  KDTree_ActedMonoid<ActedMonoid, int> KDT(X,\
    \ Y, W);\n\n  for (auto &[t, a, b, c, d, A, B]: query) {\n    if (t == 0) { KDT.set(a,\
    \ {1, b}); }\n    if (t == 1) { KDT.set(a, {1, b}); }\n    if (t == 2) {\n   \
    \   mint ANS = KDT.prod(a, b, c, d).se;\n      print(ANS);\n    }\n    if (t ==\
    \ 3) { KDT.apply(a, b, c, d, {A, B}); }\n  }\n}\n\nsigned main() { solve(); }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/kdtree/kdtree_acted_monoid.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - alg/monoid/affine.hpp
  - alg/monoid/add_pair.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
- /verify/test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp.html
title: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
---
