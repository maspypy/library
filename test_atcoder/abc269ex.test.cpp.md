---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
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
  - icon: ':x:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: poly/sum_of_prefix_suffix_products.hpp
    title: poly/sum_of_prefix_suffix_products.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc269/tasks/abc269_Ex\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/base.hpp\"\
    \n#include \"graph/tree.hpp\"\n#include \"poly/convolution_all.hpp\"\n#include\
    \ \"poly/sum_of_prefix_suffix_products.hpp\"\n\nusing mint = modint998;\n\nvoid\
    \ solve() {\n  LL(N);\n  Graph<int, 1> G(N);\n  FOR(v, 1, N) {\n    LL(p);\n \
    \   --p;\n    G.add(p, v);\n  }\n  G.build();\n  Tree<decltype(G)> tree(G);\n\n\
    \  using poly = vc<mint>;\n\n  auto dfs = [&](auto& dfs, int v) -> vc<mint> {\n\
    \    auto P = tree.heavy_path_at(v);\n    int n = len(P);\n    vc<poly> F(n);\n\
    \    FOR(i, n) {\n      int a = P[i];\n      vc<poly> polys;\n      for (auto&&\
    \ e: G[a]) {\n        if (tree.head[e.to] == v) continue;\n        polys.eb(dfs(dfs,\
    \ e.to));\n      }\n      F[i] = convolution_all(polys);\n    }\n    vc<poly>\
    \ G(n);\n    FOR(i, n) G[i] = {mint(1)};\n    G.back() = {mint(0), mint(1)};\n\
    \    return sum_of_prefix_suffix_products(F, G);\n  };\n  auto f = dfs(dfs, 0);\n\
    \  f.erase(f.begin());\n  f.resize(N);\n  for (auto&& x: f) print(x);\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n\
    \  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/base.hpp
  - graph/tree.hpp
  - poly/convolution_all.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/sum_of_prefix_suffix_products.hpp
  isVerificationFile: true
  path: test_atcoder/abc269ex.test.cpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc269ex.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc269ex.test.cpp
- /verify/test_atcoder/abc269ex.test.cpp.html
title: test_atcoder/abc269ex.test.cpp
---
