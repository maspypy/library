---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#include \"other/random.hpp\"\r\n#include \"nt/primetest.hpp\"\r\n\r\n//\
    \ O(N2^N)\r\ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph&\
    \ G) {\r\n  assert(G.is_prepared());\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\
    \n  FOR(v, N) for (auto&& e : G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E\
    \ subset \u3067\u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\
    \u3048\u4E0A\u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s,\
    \ 1 << v) { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 <<\
    \ N);\r\n  auto solve_p = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N\
    \ - popcnt(s)) & 1 ? 1 : -1);\r\n    FOR(k, 1, N) {\r\n      ll sum = 0;\r\n \
    \     FOR(s, 1 << N) {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s]\
    \ %= p;\r\n        sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n   \
    \   if (sum != 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int\
    \ ANS = 0;\r\n  chmax(ANS, solve_p(0));\r\n\r\n  FOR(TRIAL) {\r\n    int p;\r\n\
    \    while (1) {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p))\
    \ break;\r\n    }\r\n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/chromatic.hpp
layout: document
redirect_from:
- /library/graph/chromatic.hpp
- /library/graph/chromatic.hpp.html
title: graph/chromatic.hpp
---
