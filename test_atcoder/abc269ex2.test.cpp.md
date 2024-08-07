---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
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
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc269/tasks/abc269_Ex
    links:
    - https://atcoder.jp/contests/abc269/tasks/abc269_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc269/tasks/abc269_Ex\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/static_toptree.hpp\"\
    \n#include \"poly/convolution.hpp\"\n\nusing mint = modint998;\n\nvoid solve()\
    \ {\n  LL(N);\n  Graph<int, 1> G(N);\n  FOR(v, 1, N) {\n    INT(p);\n    G.add(--p,\
    \ v);\n  }\n  G.build();\n\n  Tree<decltype(G)> tree(G);\n  Static_TopTree<decltype(tree)>\
    \ STT(tree);\n  /*\n  heavy path \u4E0A\u306E\u70B9\u306A\u3057\u30FB\u3042\u308A\
    \n  */\n  using poly = vc<mint>;\n  using Data = pair<poly, poly>;\n\n  auto single\
    \ = [&](int v) -> Data {\n    poly f = {1};\n    poly g = {0, 1};\n    return\
    \ {f, g};\n  };\n\n  auto rake = [&](Data &x, Data &y, int u, int v) -> Data {\n\
    \    auto &[f1, g1] = x;\n    auto &[f2, g2] = y;\n    if (v == -1) {\n      if\
    \ (len(f1) < len(g1)) swap(f1, g1);\n      if (len(f2) < len(g2)) swap(f2, g2);\n\
    \      FOR(i, len(g1)) f1[i] += g1[i];\n      FOR(i, len(g2)) f2[i] += g2[i];\n\
    \      poly f = convolution<mint>(f1, f2);\n      return {f, {}};\n    }\n   \
    \ if (len(f2) < len(g2)) swap(f2, g2);\n    FOR(i, len(g2)) f2[i] += g2[i];\n\
    \    poly g = f2;\n    g.insert(g.begin(), 0);\n    return {f2, g};\n  };\n\n\
    \  auto compress = [&](Data &x, Data &y, int a, int b, int c) -> Data {\n    auto\
    \ &[f1, g1] = x;\n    auto &[f2, g2] = y;\n    poly f = convolution<mint>(f1,\
    \ f2);\n    // g1(x) + f1(x)g2(x)\n    poly g = convolution<mint>(f1, g2);\n \
    \   FOR(i, len(g1)) g[i] += g1[i];\n\n    return {f, g};\n  };\n\n  auto [f, g]\
    \ = STT.tree_dp<Data>(single, rake, compress);\n  vc<mint> ANS(N + 1);\n  FOR(i,\
    \ len(f)) ANS[i] += f[i];\n  FOR(i, len(g)) ANS[i] += g[i];\n  FOR(i, 1, N + 1)\
    \ print(ANS[i]);\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  isVerificationFile: true
  path: test_atcoder/abc269ex2.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc269ex2.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc269ex2.test.cpp
- /verify/test_atcoder/abc269ex2.test.cpp.html
title: test_atcoder/abc269ex2.test.cpp
---
