---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/blackbox/pascal.hpp
    title: linalg/blackbox/pascal.hpp
  - icon: ':question:'
    path: linalg/blackbox/vandermonde.hpp
    title: linalg/blackbox/vandermonde.hpp
  - icon: ':question:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
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
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':question:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':question:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  - icon: ':question:'
    path: poly/transposed_ntt.hpp
    title: poly/transposed_ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc260/tasks/abc260_Ex
    links:
    - https://atcoder.jp/contests/abc260/tasks/abc260_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc260/tasks/abc260_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/convolution_all.hpp\"\n#include \"linalg/blackbox/pascal.hpp\"\
    \n#include \"linalg/blackbox/vandermonde.hpp\"\n\nusing mint = modint998;\n\n\
    void solve() {\n  LL(N, M);\n  VEC(int, A, N);\n  vc<int> CNT(N);\n  for (auto&&\
    \ x: A) CNT[x - 1]++;\n  // \u5305\u9664\u30EB\u30FC\u30EB\u306E\u500B\u6570 ->\
    \ \u30EB\u30FC\u30EB\u306E\u6C7A\u3081\u65B9\n  vvc<mint> polys;\n  FOR(x, N)\
    \ {\n    int n = CNT[x];\n    if (n <= 1) continue;\n    vc<mint> f(n);\n    FOR(i,\
    \ n) f[i] = C<mint>(n - 1, i) * fact_inv<mint>(n - i);\n    polys.eb(f);\n  }\n\
    \  vc<mint> f = convolution_all(polys);\n\n  FOR(i, len(f)) f[i] *= fact<mint>(N\
    \ - i);\n  f = pascal(f, true, true);\n\n  {\n    mint cf = 1;\n    for (auto&&\
    \ x: CNT) cf *= fact<mint>(x);\n    for (auto&& x: f) x *= cf;\n  }\n\n  int L\
    \ = max(N, M + 1);\n  vc<mint> g(N);\n  FOR(i, len(f)) g[N - 1 - i] = f[i];\n\
    \  g.resize(L);\n\n  vc<mint> x(L);\n  FOR(i, L) x[i] = i;\n  vc<mint> ANS = vandermonde(g,\
    \ x, true, false);\n  ANS.erase(ANS.begin());\n  ANS.resize(M);\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/convolution_all.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/ntt_doubling.hpp
  - linalg/blackbox/pascal.hpp
  - linalg/blackbox/vandermonde.hpp
  - poly/multipoint.hpp
  - poly/middle_product.hpp
  - mod/all_inverse.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/transposed_ntt.hpp
  - poly/sum_of_rationals.hpp
  isVerificationFile: true
  path: test_atcoder/abc260h.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc260h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc260h.test.cpp
- /verify/test_atcoder/abc260h.test.cpp.html
title: test_atcoder/abc260h.test.cpp
---
