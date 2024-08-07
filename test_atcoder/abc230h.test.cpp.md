---
data:
  _extendedDependsOn:
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
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/online/online_convolution.hpp
    title: poly/online/online_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc230/tasks/abc230_h
    links:
    - https://atcoder.jp/contests/abc230/tasks/abc230_h
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc230/tasks/abc230_h\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/online/online_convolution.hpp\"\n\nusing mint = modint998;\n\
    \nvoid solve() {\n  /*\n  \u91CD\u3055 k \u306E\u91D1\u584A A(x)\n  \u91CD\u3055\
    \ k \u306E\u7A7A\u3067\u306A\u3044\u3075\u304F\u308D or \u91D1\u584A B(x)\n  \u91CD\
    \u3055 k+1 \u306E\u3075\u304F\u308D C(x)\n  */\n  LL(W);\n  vc<mint> A(W + 1),\
    \ B(W + 1), C(W + 1);\n  C[0] = 1;\n\n  LL(K);\n  FOR(K) {\n    INT(w);\n    A[w]\
    \ += mint(1);\n  }\n\n  /*\n  C(x) = prod (1-x^k)^{-b_k}\n  C'(x) / C(x) = sum\
    \ kb_kx^{k-1}/(1-x^k) = F(x)\n  C'(x) = C(x)F(x)\n\n  a_k, b_k, c_k\n  -> b_{k+1],\
    \ f_k\n  -> c_{k+1}\n  */\n  vc<mint> F(W + 1);\n\n  Online_Convolution<mint>\
    \ X;\n\n  FOR(k, W) {\n    B[k + 1] = A[k + 1];\n    if (k > 0) B[k + 1] += C[k];\n\
    \    mint x = mint(k + 1) * B[k + 1];\n    int i = k;\n    while (i <= W) {\n\
    \      F[i] += x;\n      i += k + 1;\n    }\n    x = X.query(k, C[k], F[k]);\n\
    \    C[k + 1] = x * inv<mint>(k + 1);\n  }\n\n  C.erase(C.begin());\n  C.pop_back();\n\
    \  for(auto&& x : C) print(x);\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n\
    }\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/online/online_convolution.hpp
  - poly/ntt.hpp
  isVerificationFile: true
  path: test_atcoder/abc230h.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc230h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc230h.test.cpp
- /verify/test_atcoder/abc230h.test.cpp.html
title: test_atcoder/abc230h.test.cpp
---
