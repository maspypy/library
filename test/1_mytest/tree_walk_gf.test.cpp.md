---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/random_graph.hpp\"\n#include \"graph/tree_walk_generating_function.hpp\"\
    \n#include \"poly/fps_div.hpp\"\n\nusing mint = modint998;\n\ntemplate <bool ALLOW_LOOP>\n\
    void test() {\n  FOR(N, 1, 30) {\n    FOR(50) {\n      Graph<int, 0> G(N);\n \
    \     vv(mint, mat, N, N);\n      for (auto& [a, b]: random_tree(N)) {\n     \
    \   G.add(a, b);\n        mat[a][b] = RNG(0, mint::get_mod());\n        mat[b][a]\
    \ = RNG(0, mint::get_mod());\n      }\n      G.build();\n      if (ALLOW_LOOP)\
    \ { FOR(v, N) mat[v][v] = RNG(mint::get_mod()); }\n      int s = RNG(0, N), t\
    \ = RNG(0, N);\n      int LIM = 200;\n      vc<mint> ANS(LIM + 1);\n      vc<mint>\
    \ dp(N);\n      dp[s] = 1;\n      FOR(k, LIM) {\n        ANS[k] = dp[t];\n   \
    \     vc<mint> newdp(N);\n        FOR(a, N) FOR(b, N) newdp[b] += dp[a] * mat[a][b];\n\
    \        swap(dp, newdp);\n        ANS[k + 1] = dp[t];\n      }\n      auto [f,\
    \ g] = tree_walk_generating_function<ALLOW_LOOP, mint>(\n          G, s, t, [&](int\
    \ i, int j) -> mint { return mat[i][j]; });\n      f.resize(LIM + 1);\n      g.resize(LIM\
    \ + 1);\n      f = fps_div(f, g);\n      assert(f == ANS);\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}\n\n\
    signed main() {\n  test<0>();\n  test<1>();\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/tree_walk_gf.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/tree_walk_gf.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/tree_walk_gf.test.cpp
- /verify/test/1_mytest/tree_walk_gf.test.cpp.html
title: test/1_mytest/tree_walk_gf.test.cpp
---
