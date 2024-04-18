---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':question:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/powproj_sps.test.cpp
    title: test/library_checker/math/powproj_sps.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc253h.test.cpp
    title: test_atcoder/abc253h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/subset_convolution.hpp\"\n\r\n#line 2 \"setfunc/ranked_zeta.hpp\"\
    \n\r\ntemplate <typename T, int LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const\
    \ vc<T>& f) {\r\n  int n = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f)\
    \ == 1 << n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s <\
    \ (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    int w = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 * w) {\r\n \
    \     for (int s = p; s < p + w; ++s) {\r\n        int t = s | 1 << i;\r\n   \
    \     for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\n      }\r\n    }\r\
    \n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  int n = topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0;\
    \ p < (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n \
    \       int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] -=\
    \ Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for (int s =\
    \ 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\n  return f;\r\n}\n#line 4\
    \ \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename T, int LIM = 20>\r\
    \nvc<T> subset_convolution_square(const vc<T>& A) {\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  int n = topbit(len(RA));\r\n  FOR(s, len(RA)) {\r\n    auto& f\
    \ = RA[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x\
    \ += f[i] * f[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T,\
    \ LIM>(RA);\r\n}\r\n\r\ntemplate <typename T, int LIM = 20>\r\nvc<T> subset_convolution(const\
    \ vc<T>& A, const vc<T>& B) {\r\n  if (A == B) return subset_convolution_square(A);\r\
    \n  auto RA = ranked_zeta<T, LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\
    \n  int n = topbit(len(RA));\r\n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], &g\
    \ = RB[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x\
    \ += f[i] * g[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T,\
    \ LIM>(RA);\r\n}\r\n#line 2 \"poly/convolution_naive.hpp\"\n\r\ntemplate <class\
    \ T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vector<T> ans(n + m - 1);\r\n  FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\
    \n  return ans;\r\n}\r\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n\
    \  int n = int(a.size()), m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\r\n  if (n == 0) return {};\r\n  vc<T> ans(n + m - 1);\r\n  if (n <= 16\
    \ && (T::get_mod() < (1 << 30))) {\r\n    for (int k = 0; k < n + m - 1; ++k)\
    \ {\r\n      int s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n  \
    \    u64 sm = 0;\r\n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) *\
    \ (b[k - i].val); }\r\n      ans[k] = sm;\r\n    }\r\n  } else {\r\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\n      int\
    \ t = min(n, k + 1);\r\n      u128 sm = 0;\r\n      for (int i = s; i < t; ++i)\
    \ { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = T::raw(sm % T::get_mod());\r\
    \n    }\r\n  }\r\n  return ans;\r\n}\r\n#line 3 \"setfunc/transposed_sps_composition.hpp\"\
    \n\n// for fixed sps s, consider linear map F:a->b = subset-conv(a,s)\n// given\
    \ x, calculate transpose(F)(x)\ntemplate <typename mint, int LIM>\nvc<mint> transposed_subset_convolution(vc<mint>\
    \ s, vc<mint> x) {\n  /*\n  sum_{j}x_jb_j = sum_{i subset j}x_ja_is_{j-i} = sum_{i}y_ia_i.\n\
    \  y_i = sum_{j supset i}x_js_{j-i}\n  (rev y)_i = sum_{j subset i}(rev x)_js_{i-j}\n\
    \  y = rev(conv(rev x), s)\n  */\n  reverse(all(x));\n  x = subset_convolution<mint,\
    \ LIM>(x, s);\n  reverse(all(x));\n  return x;\n}\n\n// for fixed sps s s.t. s[0]\
    \ == 0.\n// consider linear map F:f->t=f(s) for egf f.\n// given x, calcuate transpose(F)(x)\n\
    // equivalent: calculate sum_i x_i(s^k/k!)_i for k=0,1,...,N\ntemplate <typename\
    \ mint, int LIM>\nvc<mint> transposed_sps_composition_egf(vc<mint>& s, vc<mint>\
    \ x) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N) && len(x)\
    \ == (1 << N) && s[0] == mint(0));\n  vc<mint> y(N + 1);\n  y[0] = x[0];\n  auto&\
    \ dp = x;\n  FOR(i, N) {\n    vc<mint> newdp(1 << (N - 1 - i));\n    FOR(j, N\
    \ - i) {\n      vc<mint> a = {s.begin() + (1 << j), s.begin() + (2 << j)};\n \
    \     vc<mint> b = {dp.begin() + (1 << j), dp.begin() + (2 << j)};\n      b =\
    \ transposed_subset_convolution<mint, LIM>(a, b);\n      FOR(k, len(b)) newdp[k]\
    \ += b[k];\n    }\n    swap(dp, newdp);\n    y[1 + i] = dp[0];\n  }\n  return\
    \ y;\n}\n\n// for fixed sps s s.t. s[0] == 0.\n// consider linear map F:f->t=f(s)\
    \ for polynomial f.\n// given x, calcuate transpose(F)(x)\n// equivalent: calculate\
    \ sum_i x_i(s^k/k!)_i for k=0,1,...,M-1\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ transposed_sps_composition_poly(vc<mint> s, vc<mint> x, int M) {\n  const int\
    \ N = topbit(len(s));\n  assert(len(s) == (1 << N) && len(x) == (1 << N));\n \
    \ mint c = s[0];\n  s[0] -= c;\n  x = transposed_sps_composition_egf<mint, LIM>(s,\
    \ x);\n  vc<mint> g(M);\n  mint pow = 1;\n  FOR(i, M) { g[i] = pow * fact_inv<mint>(i),\
    \ pow *= c; }\n  x = convolution_naive<mint>(x, g);\n  x.resize(M);\n  FOR(i,\
    \ M) x[i] *= fact<mint>(i);\n  return x;\n}\n"
  code: "#include \"setfunc/subset_convolution.hpp\"\n#include \"poly/convolution_naive.hpp\"\
    \n\n// for fixed sps s, consider linear map F:a->b = subset-conv(a,s)\n// given\
    \ x, calculate transpose(F)(x)\ntemplate <typename mint, int LIM>\nvc<mint> transposed_subset_convolution(vc<mint>\
    \ s, vc<mint> x) {\n  /*\n  sum_{j}x_jb_j = sum_{i subset j}x_ja_is_{j-i} = sum_{i}y_ia_i.\n\
    \  y_i = sum_{j supset i}x_js_{j-i}\n  (rev y)_i = sum_{j subset i}(rev x)_js_{i-j}\n\
    \  y = rev(conv(rev x), s)\n  */\n  reverse(all(x));\n  x = subset_convolution<mint,\
    \ LIM>(x, s);\n  reverse(all(x));\n  return x;\n}\n\n// for fixed sps s s.t. s[0]\
    \ == 0.\n// consider linear map F:f->t=f(s) for egf f.\n// given x, calcuate transpose(F)(x)\n\
    // equivalent: calculate sum_i x_i(s^k/k!)_i for k=0,1,...,N\ntemplate <typename\
    \ mint, int LIM>\nvc<mint> transposed_sps_composition_egf(vc<mint>& s, vc<mint>\
    \ x) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N) && len(x)\
    \ == (1 << N) && s[0] == mint(0));\n  vc<mint> y(N + 1);\n  y[0] = x[0];\n  auto&\
    \ dp = x;\n  FOR(i, N) {\n    vc<mint> newdp(1 << (N - 1 - i));\n    FOR(j, N\
    \ - i) {\n      vc<mint> a = {s.begin() + (1 << j), s.begin() + (2 << j)};\n \
    \     vc<mint> b = {dp.begin() + (1 << j), dp.begin() + (2 << j)};\n      b =\
    \ transposed_subset_convolution<mint, LIM>(a, b);\n      FOR(k, len(b)) newdp[k]\
    \ += b[k];\n    }\n    swap(dp, newdp);\n    y[1 + i] = dp[0];\n  }\n  return\
    \ y;\n}\n\n// for fixed sps s s.t. s[0] == 0.\n// consider linear map F:f->t=f(s)\
    \ for polynomial f.\n// given x, calcuate transpose(F)(x)\n// equivalent: calculate\
    \ sum_i x_i(s^k/k!)_i for k=0,1,...,M-1\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ transposed_sps_composition_poly(vc<mint> s, vc<mint> x, int M) {\n  const int\
    \ N = topbit(len(s));\n  assert(len(s) == (1 << N) && len(x) == (1 << N));\n \
    \ mint c = s[0];\n  s[0] -= c;\n  x = transposed_sps_composition_egf<mint, LIM>(s,\
    \ x);\n  vc<mint> g(M);\n  mint pow = 1;\n  FOR(i, M) { g[i] = pow * fact_inv<mint>(i),\
    \ pow *= c; }\n  x = convolution_naive<mint>(x, g);\n  x.resize(M);\n  FOR(i,\
    \ M) x[i] *= fact<mint>(i);\n  return x;\n}\n"
  dependsOn:
  - setfunc/subset_convolution.hpp
  - setfunc/ranked_zeta.hpp
  - poly/convolution_naive.hpp
  isVerificationFile: false
  path: setfunc/transposed_sps_composition.hpp
  requiredBy: []
  timestamp: '2024-04-19 02:20:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/powproj_sps.test.cpp
  - test_atcoder/abc253h.test.cpp
documentation_of: setfunc/transposed_sps_composition.hpp
layout: document
redirect_from:
- /library/setfunc/transposed_sps_composition.hpp
- /library/setfunc/transposed_sps_composition.hpp.html
title: setfunc/transposed_sps_composition.hpp
---
