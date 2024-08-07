---
data:
  _extendedDependsOn:
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
  - icon: ':x:'
    path: other/count_seq_with_fixed_xor_value.hpp
    title: other/count_seq_with_fixed_xor_value.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
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
    path: poly/differentiate.hpp
    title: poly/differentiate.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':question:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':question:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc288/tasks/abc288_Ex
    links:
    - https://atcoder.jp/contests/abc288/tasks/abc288_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc288/tasks/abc288_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"poly/fps_pow.hpp\"\n#include \"other/count_seq_with_fixed_xor_value.hpp\"\
    \n\nusing mint = modint998;\nusing poly = vc<mint>;\n\nvoid solve() {\n  LL(N,\
    \ M, X);\n  ++M;\n  // vc<mint> F(N + 1);\n  // FOR(n, N + 1) F[n] = count_seq_with_fixed_xor<mint>(n,\
    \ M, X);\n  vc<mint> F = count_seq_with_fixed_xor_iota<mint>(N, M, X);\n  // print(\"\
    F\", F);\n\n  // \u3042\u3068\u306F\u76F8\u7570\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // \u3061\u3087\u3046\u3069 k \u7A2E\u304B\u3089\u306A\u308B\u539F\u59CB\
    \u89E3\u3092 n \u500B\u306B\u3059\u308B\u65B9\u6CD5\u306F\uFF1F\n\n  // f_k(x)\
    \ = sinh(x)^k cosh(x)^{M-k} \u3092 k=0,1,...N \u3067\u6C42\u3081\u308B\n  // f_k'\
    \ = kf_{k-1} + (M-k-1)f_{k+1} \u3092\u4F7F\u3063\u3066\u4F4E\u6B21\u304B\u3089\
    \u9806\u306B\n\n  vv(mint, dp, N + 1, N + 1);\n  dp[0][0] = mint(1);\n  FOR(i,\
    \ 1, N + 1) FOR(k, i + 1) {\n    mint x = 0;\n    if (k) x += mint(k) * dp[k -\
    \ 1][i - 1];\n    if (k + 1 <= N) x += mint(M - k) * dp[k + 1][i - 1];\n    if\
    \ (k == 1 && i == 0) print(k, i, x);\n    dp[k][i] = x *= inv<mint>(i);\n  }\n\
    \  FOR(k, N + 1) FOR(i, N + 1) dp[k][i] *= fact<mint>(i);\n\n  /*\n  FOR(k, N\
    \ + 1) {\n    if (k > M) break;\n    poly f(N + 1), g(N + 1);\n    FOR(i, N +\
    \ 1) {\n      if (i % 2 == 1) f[i] += fact_inv<mint>(i);\n      if (i % 2 == 0)\
    \ g[i] += fact_inv<mint>(i);\n    }\n    f = fps_pow(f, k);\n    g = fps_pow(g,\
    \ M - k);\n    f = convolution(f, g);\n    f.resize(N + 1);\n    FOR(i, N + 1)\
    \ f[i] *= fact<mint>(i);\n    dp[k] = f;\n  }\n  */\n\n  FOR(j, N + 1) {\n   \
    \ FOR(i, j) { F[j] -= F[i] * dp[i][j]; }\n    F[j] /= dp[j][j];\n  }\n\n  poly\
    \ f = {1, 0, -1};\n  f.resize(N + 1);\n  f = fps_pow_1(f, -mint(M));\n\n  mint\
    \ ANS = 0;\n  FOR(k, N + 1) { ANS += F[k] * f[N - k]; }\n  print(ANS);\n}\n\n\
    signed main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/fps_pow.hpp
  - poly/count_terms.hpp
  - poly/fps_exp.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/fps_log.hpp
  - poly/fps_inv.hpp
  - other/count_seq_with_fixed_xor_value.hpp
  isVerificationFile: true
  path: test_atcoder/abc288ex.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc288ex.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc288ex.test.cpp
- /verify/test_atcoder/abc288ex.test.cpp.html
title: test_atcoder/abc288ex.test.cpp
---
