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
  bundledCode: "#line 1 \"setfunc/sps_composition.hpp\"\n// sum_i f_i/i! s^i, s^i\
    \ is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint> sps_composition_egf(int\
    \ N, vc<mint>& f, vc<mint>& s) {\n  assert(len(s) == (1 << N) && s[0] == mint(0));\n\
    \  if (len(f) > N) f.resize(N + 1);\n  int D = len(f) - 1;\n  using ARR = array<mint,\
    \ LIM + 1>;\n  vvc<ARR> zs(N);\n  FOR(i, N) {\n    zs[i]\n        = ranked_zeta<mint,\
    \ LIM>({s.begin() + (1 << i), s.begin() + (2 << i)});\n  }\n\n  // dp : (d/dt)^df(s)\
    \ (d=D,D-1,...)\n  vc<mint> dp(1 << (N - D));\n  dp[0] = f[D];\n  FOR_R(d, D)\
    \ {\n    vc<mint> newdp(1 << (N - d));\n    newdp[0] = f[d];\n    vc<ARR> zdp\
    \ = ranked_zeta<mint, LIM>(dp);\n    FOR(i, N - d) {\n      // zs[1<<i:2<<i],\
    \ zdp[0:1<<i]\n      vc<ARR> znewdp(1 << i);\n      FOR(k, 1 << i) {\n       \
    \ FOR(p, i + 1) FOR(q, i - p + 1) {\n          znewdp[k][p + q] += zdp[k][p] *\
    \ zs[i][k][q];\n        }\n      }\n      auto x = ranked_mobius<mint, LIM>(znewdp);\n\
    \      copy(all(x), newdp.begin() + (1 << i));\n    }\n    swap(dp, newdp);\n\
    \  }\n  return dp;\n}\n\n// sum_i f_i/i! s^i, s^i is subset-convolution\ntemplate\
    \ <typename mint, int LIM>\nvc<mint> sps_composition_poly(int N, vc<mint> f, vc<mint>\
    \ s) {\n  if (f.empty()) return vc<mint>(1 << N, mint(0));\n  // convert to egf\
    \ problem\n  mint a = s[0];\n  s[0] = 0;\n  int D = min<int>(len(f) - 1, N);\n\
    \  vc<mint> g(D + 1);\n  FOR(j, D + 1) {\n    mint pow_a = 1;\n    FOR(i, j, len(f))\
    \ { g[j] += f[i] * pow_a, pow_a *= a, f[i] *= mint(i - j); }\n  }\n  return composition_egf_sps<mint,\
    \ LIM>(N, g, s);\n}\n"
  code: "// sum_i f_i/i! s^i, s^i is subset-convolution\ntemplate <typename mint,\
    \ int LIM>\nvc<mint> sps_composition_egf(int N, vc<mint>& f, vc<mint>& s) {\n\
    \  assert(len(s) == (1 << N) && s[0] == mint(0));\n  if (len(f) > N) f.resize(N\
    \ + 1);\n  int D = len(f) - 1;\n  using ARR = array<mint, LIM + 1>;\n  vvc<ARR>\
    \ zs(N);\n  FOR(i, N) {\n    zs[i]\n        = ranked_zeta<mint, LIM>({s.begin()\
    \ + (1 << i), s.begin() + (2 << i)});\n  }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n\
    \  vc<mint> dp(1 << (N - D));\n  dp[0] = f[D];\n  FOR_R(d, D) {\n    vc<mint>\
    \ newdp(1 << (N - d));\n    newdp[0] = f[d];\n    vc<ARR> zdp = ranked_zeta<mint,\
    \ LIM>(dp);\n    FOR(i, N - d) {\n      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR>\
    \ znewdp(1 << i);\n      FOR(k, 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p\
    \ + 1) {\n          znewdp[k][p + q] += zdp[k][p] * zs[i][k][q];\n        }\n\
    \      }\n      auto x = ranked_mobius<mint, LIM>(znewdp);\n      copy(all(x),\
    \ newdp.begin() + (1 << i));\n    }\n    swap(dp, newdp);\n  }\n  return dp;\n\
    }\n\n// sum_i f_i/i! s^i, s^i is subset-convolution\ntemplate <typename mint,\
    \ int LIM>\nvc<mint> sps_composition_poly(int N, vc<mint> f, vc<mint> s) {\n \
    \ if (f.empty()) return vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n\
    \  mint a = s[0];\n  s[0] = 0;\n  int D = min<int>(len(f) - 1, N);\n  vc<mint>\
    \ g(D + 1);\n  FOR(j, D + 1) {\n    mint pow_a = 1;\n    FOR(i, j, len(f)) { g[j]\
    \ += f[i] * pow_a, pow_a *= a, f[i] *= mint(i - j); }\n  }\n  return composition_egf_sps<mint,\
    \ LIM>(N, g, s);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/sps_composition.hpp
  requiredBy: []
  timestamp: '2023-05-04 02:23:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/sps_composition.hpp
layout: document
redirect_from:
- /library/setfunc/sps_composition.hpp
- /library/setfunc/sps_composition.hpp.html
title: setfunc/sps_composition.hpp
---
