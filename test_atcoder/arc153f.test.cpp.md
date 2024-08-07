---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/product.hpp
    title: enumerate/product.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/block_cut.hpp
    title: graph/block_cut.hpp
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
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
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
  - icon: ':question:'
    path: seq/famous/stirling_number_2.hpp
    title: seq/famous/stirling_number_2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc153/tasks/arc153_f
    links:
    - https://atcoder.jp/contests/arc153/tasks/arc153_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc153/tasks/arc153_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n\
    #include \"graph/base.hpp\"\n#include \"enumerate/product.hpp\"\n#include \"seq/famous/stirling_number_2.hpp\"\
    \n#include \"graph/block_cut.hpp\"\n\nusing mint = modint998;\n\nvoid naive(Graph<int,\
    \ 0> G) {\n  const int N = G.N;\n  const int M = G.M;\n\n  int ANS = 0;\n\n  auto\
    \ F = [&](vc<int> color) -> void {\n    vv(int, mat, N, N, -1);\n    FOR(i, M)\
    \ {\n      auto e = G.edges[i];\n      int a = e.frm, b = e.to;\n      mat[a][b]\
    \ = mat[b][a] = color[i];\n    }\n    vc<int> P(N);\n    iota(all(P), 0);\n  \
    \  do {\n      int s = 0;\n      FOR(i, N - 1) {\n        int a = P[i], b = P[i\
    \ + 1];\n        if (mat[a][b] == -1) break;\n        s |= 1 << mat[a][b];\n \
    \     }\n      if (s == 7) {\n        ++ANS;\n        return;\n      }\n    }\
    \ while (next_permutation(all(P)));\n  };\n\n  enumerate_product(vc<int>(M, 3),\
    \ F);\n  print(ANS);\n}\n\nvoid solve() {\n  LL(N, M);\n  Graph<int, 0> G(N);\n\
    \  G.read_graph(M);\n  if (N <= 4) return naive(G);\n\n  // i \u5143\u96C6\u5408\
    \u304B\u3089 3 \u5143\u96C6\u5408\u3078\u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\
    \u3052\n  vc<mint> S = stirling_number_2_k<mint>(3, max(N, M));\n  for (auto&&\
    \ x: S) x *= mint(6);\n\n  // 3 \u8272\u3067\u5857\u308B\u65B9\u6CD5\u5168\u4F53\
    \n  mint ANS = S[M];\n\n  auto BCT = block_cut(G);\n  auto deg = BCT.deg_array();\n\
    \  // 3-cycle \u3067\u3042\u3063\u3066\u3001\u552F\u4E00\u306E\u95A2\u7BC0\u70B9\
    \u3092\u542B\u3080\u3082\u306E \u2192 6 \u3092\u5F15\u304F\n  FOR(block, N, BCT.N)\
    \ {\n    if (deg[block] != 3) continue;\n    vc<int> nbd;\n    for (auto&& e:\
    \ BCT[block]) nbd.eb(e.to);\n    int cnt = 0;\n    for (auto&& v: nbd)\n     \
    \ if (deg[v] > 1) ++cnt;\n    if (cnt == 1) ANS -= mint(6);\n  }\n  // cut vertex\
    \ \u306E\u6B21\u6570\u3092 n \u3068\u3057\u3066\n  FOR(cut, N) {\n    int n =\
    \ deg[cut];\n    ANS -= S[n];\n  }\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - graph/base.hpp
  - enumerate/product.hpp
  - seq/famous/stirling_number_2.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/fps_pow.hpp
  - poly/count_terms.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/fps_log.hpp
  - poly/fps_inv.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - graph/block_cut.hpp
  isVerificationFile: true
  path: test_atcoder/arc153f.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/arc153f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/arc153f.test.cpp
- /verify/test_atcoder/arc153f.test.cpp.html
title: test_atcoder/arc153f.test.cpp
---
