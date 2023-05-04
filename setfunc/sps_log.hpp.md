---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc213g.test.cpp
    title: test_atcoder/abc213g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM = 20>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n\
    \ = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f) == 1 << n);\r\n\
    \  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)]\
    \ = f[s];\r\n  for (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for\
    \ (int p = 0; p < (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w;\
    \ ++s) {\r\n        int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d)\
    \ Rf[t][d] += Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\n\
    template <typename T, int LIM = 20>\r\nvc<T> ranked_mobius(vc<array<T, LIM + 1>>&\
    \ Rf) {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\n  for\
    \ (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0; p <\
    \ (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n     \
    \   int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\
    \n      }\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for (int s = 0; s < (1 <<\
    \ n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\n}\n#line 2 \"setfunc/sps_composition.hpp\"\
    \n\n// sum_i f_i/i! s^i, s^i is subset-convolution\ntemplate <typename mint, int\
    \ LIM>\nvc<mint> sps_composition_egf(int N, vc<mint>& f, vc<mint>& s) {\n  assert(len(s)\
    \ == (1 << N) && s[0] == mint(0));\n  if (len(f) > N) f.resize(N + 1);\n  int\
    \ D = len(f) - 1;\n  using ARR = array<mint, LIM + 1>;\n  vvc<ARR> zs(N);\n  FOR(i,\
    \ N) {\n    zs[i]\n        = ranked_zeta<mint, LIM>({s.begin() + (1 << i), s.begin()\
    \ + (2 << i)});\n  }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n  vc<mint> dp(1\
    \ << (N - D));\n  dp[0] = f[D];\n  FOR_R(d, D) {\n    vc<mint> newdp(1 << (N -\
    \ d));\n    newdp[0] = f[d];\n    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);\n\
    \    FOR(i, N - d) {\n      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR> znewdp(1\
    \ << i);\n      FOR(k, 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p + 1) {\n\
    \          znewdp[k][p + q] += zdp[k][p] * zs[i][k][q];\n        }\n      }\n\
    \      auto x = ranked_mobius<mint, LIM>(znewdp);\n      copy(all(x), newdp.begin()\
    \ + (1 << i));\n    }\n    swap(dp, newdp);\n  }\n  return dp;\n}\n\n// sum_i\
    \ f_i/i! s^i, s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_composition_poly(int N, vc<mint> f, vc<mint> s) {\n  if (f.empty()) return\
    \ vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n  mint a = s[0];\n\
    \  s[0] = 0;\n  int D = min<int>(len(f) - 1, N);\n  vc<mint> g(D + 1);\n  FOR(j,\
    \ D + 1) {\n    mint pow_a = 1;\n    FOR(i, j, len(f)) { g[j] += f[i] * pow_a,\
    \ pow_a *= a, f[i] *= mint(i - j); }\n  }\n  return sps_composition_egf<mint,\
    \ LIM>(N, g, s);\n}\n#line 2 \"setfunc/sps_log.hpp\"\n\ntemplate <typename mint,\
    \ int LIM>\nvc<mint> sps_log(int N, vc<mint> s) {\n  assert(len(s) == (1 << N)\
    \ && s[0] == mint(1));\n  vc<mint> f(N + 1);\n  FOR(i, 1, N + 1) f[i] = -fact<mint>(i\
    \ - 1);\n  for (auto&& x: s) x = -x;\n  s[0] = 0;\n  return sps_composition_egf<mint,\
    \ LIM>(N, f, s);\n}\n"
  code: "#include \"setfunc/sps_composition.hpp\"\n\ntemplate <typename mint, int\
    \ LIM>\nvc<mint> sps_log(int N, vc<mint> s) {\n  assert(len(s) == (1 << N) &&\
    \ s[0] == mint(1));\n  vc<mint> f(N + 1);\n  FOR(i, 1, N + 1) f[i] = -fact<mint>(i\
    \ - 1);\n  for (auto&& x: s) x = -x;\n  s[0] = 0;\n  return sps_composition_egf<mint,\
    \ LIM>(N, f, s);\n}\n"
  dependsOn:
  - setfunc/sps_composition.hpp
  - setfunc/ranked_zeta.hpp
  isVerificationFile: false
  path: setfunc/sps_log.hpp
  requiredBy: []
  timestamp: '2023-05-04 13:29:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc213g.test.cpp
documentation_of: setfunc/sps_log.hpp
layout: document
redirect_from:
- /library/setfunc/sps_log.hpp
- /library/setfunc/sps_log.hpp.html
title: setfunc/sps_log.hpp
---
