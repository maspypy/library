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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/all_cycle_common_vertex.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n// #include \"other/io.hpp\"\n\n#include \"graph/base.hpp\"\
    \n#include \"graph/all_cycle_common_vertex.hpp\"\n\n#include \"random/base.hpp\"\
    \n\nvc<int> naive(Graph<int, 1> G) {\n  int N = G.N;\n  vc<int> ANS;\n  auto dag\
    \ = [&](vc<int> V) -> bool {\n    Graph<int, 1> H = G.rearrange(V);\n    return\
    \ V.empty() || (!toposort(H).empty());\n  };\n  vc<int> V;\n  FOR(i, N) V.eb(i);\n\
    \  if (dag(V)) return {};\n  FOR(v, N) {\n    V.erase(find(all(V), v));\n    if\
    \ (dag(V)) ANS.eb(v);\n    V.eb(v);\n  }\n  return ANS;\n}\n\nvoid test() {\n\
    \  FOR(1 << 18) {\n    int N = RNG(1, 4);\n    Graph<int, 1> G(N);\n    int prob\
    \ = RNG(0, 100);\n    FOR(a, N) FOR(b, N) {\n      if (a == b) continue;\n   \
    \   if (RNG(0, 100) < prob) G.add(a, b);\n    }\n    G.build();\n    auto ANS1\
    \ = all_cycle_common_vertex(G, 0);\n    auto ANS2 = naive(G);\n    sort(all(ANS1));\n\
    \    sort(all(ANS2));\n    // G.debug();\n    // SHOW(ANS1, ANS2);\n    assert(ANS1\
    \ == ANS2);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/all_cycle_common_vertex.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/all_cycle_common_vertex.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/all_cycle_common_vertex.test.cpp
- /verify/test/1_mytest/all_cycle_common_vertex.test.cpp.html
title: test/1_mytest/all_cycle_common_vertex.test.cpp
---
