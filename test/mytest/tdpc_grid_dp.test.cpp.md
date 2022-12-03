---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: connected_dp/squares.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"ds/hashmap.hpp\"\n#include \"random/hash_vector.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"connected_dp/squares.hpp\"\n\nusing\
    \ mint = modint107;\n\nmint calc_tdpc_grid(int H, int W) {\n  HashMapLL<int> MP;\n\
    \n  using P = pair<vc<int>, int>;\n  vc<P> states;\n\n  auto get_hash = [&](vc<int>\
    \ a, int b) -> ll {\n    a.eb(b);\n    return hash_vector<int>(a);\n  };\n\n \
    \ vc<int> init(H, -1);\n  init[0] = 0;\n  states.eb(init, 0);\n  vc<int> end(H,\
    \ -1);\n  end[H - 1] = H - 1;\n  states.eb(end, H - 1);\n  FOR(i, 2) {\n    auto\
    \ [a, b] = states[i];\n    ll h = get_hash(a, b);\n    MP[h] = i;\n  }\n\n  vc<pi>\
    \ edges;\n\n  int p = -1;\n  while (1) {\n    ++p;\n    if (p >= len(states))\
    \ break;\n    auto [now, r] = states[p];\n    for (auto&& [nxt, convert]: connected_dp_squares::next_states(now))\
    \ {\n      int s = convert[r];\n      if (s == -1) continue;\n      ll h = get_hash(nxt,\
    \ s);\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt,\
    \ s);\n      }\n      edges.eb(p, MP[h]);\n    }\n  }\n\n  int S = len(states);\n\
    \  vc<mint> dp(S);\n  dp[0] = mint(1);\n  FOR(W + 1) {\n    vc<mint> newdp(S);\n\
    \    for (auto&& [a, b]: edges) newdp[b] += dp[a];\n    swap(dp, newdp);\n  }\n\
    \  return dp[1];\n}\n\nvoid test() {\n  assert(calc_tdpc_grid(2, 2).val == 3);\n\
    \  assert(calc_tdpc_grid(5, 8).val == 950397139);\n  assert(calc_tdpc_grid(8,\
    \ 5).val == 950397139);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\
    \nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/tdpc_grid_dp.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/tdpc_grid_dp.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/tdpc_grid_dp.test.cpp
- /verify/test/mytest/tdpc_grid_dp.test.cpp.html
title: test/mytest/tdpc_grid_dp.test.cpp
---
