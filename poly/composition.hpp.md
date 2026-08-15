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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"poly/convolution.hpp\"\r\n#include \"poly/poly_taylor_shift.hpp\"\
    \r\n#include \"poly/transposed_ntt.hpp\"\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ composition_old(vc<mint>& Q, vc<mint>& P) {\r\n  int n = len(P);\r\n  assert(len(P)\
    \ == len(Q));\r\n  int k = 1;\r\n  while (k * k < n) ++k;\r\n  // compute powers\
    \ of P\r\n  vv(mint, pow1, k + 1);\r\n  pow1[0] = {1};\r\n  pow1[1] = P;\r\n \
    \ FOR3(i, 2, k + 1) {\r\n    pow1[i] = convolution(pow1[i - 1], pow1[1]);\r\n\
    \    pow1[i].resize(n);\r\n  }\r\n  vv(mint, pow2, k + 1);\r\n  pow2[0] = {1};\r\
    \n  pow2[1] = pow1[k];\r\n  FOR3(i, 2, k + 1) {\r\n    pow2[i] = convolution(pow2[i\
    \ - 1], pow2[1]);\r\n    pow2[i].resize(n);\r\n  }\r\n  vc<mint> ANS(n);\r\n \
    \ FOR(i, k + 1) {\r\n    vc<mint> f(n);\r\n    FOR(j, k) {\r\n      if (k * i\
    \ + j < len(Q)) {\r\n        mint coef = Q[k * i + j];\r\n        FOR(d, len(pow1[j]))\
    \ f[d] += pow1[j][d] * coef;\r\n      }\r\n    }\r\n    f = convolution(f, pow2[i]);\r\
    \n    f.resize(n);\r\n    FOR(d, n) ANS[d] += f[d];\r\n  }\r\n  return ANS;\r\n\
    }\r\n\r\n// f(g(x)), O(Nlog^2N)\r\ntemplate <typename mint>\r\nvc<mint> composition_0_ntt(vc<mint>\
    \ f, vc<mint> g) {\r\n  assert(len(f) == len(g));\r\n  if (f.empty()) return {};\r\
    \n\r\n  int n0 = len(f);\r\n  int n = 1;\r\n  while (n < len(f)) n *= 2;\r\n \
    \ f.resize(n), g.resize(n);\r\n\r\n  vc<mint> W(n);\r\n  {\r\n    // bit reverse\
    \ order\r\n    vc<int> btr(n);\r\n    int log = topbit(n);\r\n    FOR(i, n) {\
    \ btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\r\n    int t = mint::ntt_info().fi;\r\
    \n    mint r = mint::ntt_info().se;\r\n    mint dw = r.inverse().pow((1 << t)\
    \ / (2 * n));\r\n    mint w = 1;\r\n    for (auto& i: btr) { W[i] = w, w *= dw;\
    \ }\r\n  }\r\n\r\n  auto rec = [&](auto& rec, int n, int k, vc<mint>& Q) -> vc<mint>\
    \ {\r\n    if (n == 1) {\r\n      reverse(all(f));\r\n      transposed_ntt(f,\
    \ 1);\r\n      mint c = mint(1) / mint(k);\r\n      for (auto& x: f) x *= c;\r\
    \n      vc<mint> p(4 * k);\r\n      FOR(i, k) p[2 * i] = f[i];\r\n      return\
    \ p;\r\n    }\r\n    auto doubling_y = [&](vc<mint>& A, int l, int r, bool t)\
    \ -> void {\r\n      mint z = W[k / 2].inverse();\r\n      vc<mint> f(k);\r\n\
    \      if (!t) {\r\n        FOR(i, l, r) {\r\n          FOR(j, k) f[j] = A[2 *\
    \ n * j + i];\r\n          ntt(f, 1);\r\n          mint r = 1;\r\n          FOR(j,\
    \ 1, k) r *= z, f[j] *= r;\r\n          ntt(f, 0);\r\n          FOR(j, k) A[2\
    \ * n * (k + j) + i] = f[j];\r\n        }\r\n      } else {\r\n        FOR(i,\
    \ l, r) {\r\n          FOR(j, k) f[j] = A[2 * n * (k + j) + i];\r\n          transposed_ntt(f,\
    \ 0);\r\n          mint r = 1;\r\n          FOR(j, 1, k) r *= z, f[j] *= r;\r\n\
    \          transposed_ntt(f, 1);\r\n          FOR(j, k) A[2 * n * j + i] += f[j];\r\
    \n        }\r\n      }\r\n    };\r\n\r\n    auto FFT_x = [&](vc<mint>& A, int\
    \ l, int r, bool t) -> void {\r\n      vc<mint> f(2 * n);\r\n      if (!t) {\r\
    \n        FOR(j, l, r) {\r\n          move(A.begin() + 2 * n * j, A.begin() +\
    \ 2 * n * (j + 1), f.begin());\r\n          ntt(f, 0);\r\n          move(all(f),\
    \ A.begin() + 2 * n * j);\r\n        }\r\n      } else {\r\n        FOR(j, l,\
    \ r) {\r\n          move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());\r\
    \n          transposed_ntt(f, 0);\r\n          move(all(f), A.begin() + 2 * n\
    \ * j);\r\n        }\r\n      }\r\n    };\r\n\r\n    if (n <= k) doubling_y(Q,\
    \ 1, n, 0), FFT_x(Q, 0, 2 * k, 0);\r\n    if (n > k) FFT_x(Q, 0, k, 0), doubling_y(Q,\
    \ 0, 2 * n, 0);\r\n\r\n    FOR(i, 2 * n * k) Q[i] += 1;\r\n    FOR(i, 2 * n *\
    \ k, 4 * n * k) Q[i] -= 1;\r\n\r\n    vc<mint> nxt_Q(4 * n * k);\r\n    vc<mint>\
    \ F(2 * n), G(2 * n), f(n), g(n);\r\n    FOR(j, 2 * k) {\r\n      move(Q.begin()\
    \ + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());\r\n      FOR(i, n) {\
    \ g[i] = G[2 * i] * G[2 * i + 1]; }\r\n      ntt(g, 1);\r\n      move(g.begin(),\
    \ g.begin() + n / 2, nxt_Q.begin() + n * j);\r\n    }\r\n    FOR(j, 4 * k) nxt_Q[n\
    \ * j] = 0;\r\n\r\n    vc<mint> p = rec(rec, n / 2, k * 2, nxt_Q);\r\n    FOR_R(j,\
    \ 2 * k) {\r\n      move(p.begin() + n * j, p.begin() + n * j + n / 2, f.begin());\r\
    \n      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());\r\
    \n      fill(f.begin() + n / 2, f.end(), mint(0));\r\n      transposed_ntt(f,\
    \ 1);\r\n      FOR(i, n) {\r\n        f[i] *= W[i];\r\n        F[2 * i] = G[2\
    \ * i + 1] * f[i], F[2 * i + 1] = -G[2 * i] * f[i];\r\n      }\r\n      move(F.begin(),\
    \ F.end(), p.begin() + 2 * n * j);\r\n    }\r\n    if (n <= k) FFT_x(p, 0, 2 *\
    \ k, 1), doubling_y(p, 0, n, 1);\r\n    if (n > k) doubling_y(p, 0, 2 * n, 1),\
    \ FFT_x(p, 0, k, 1);\r\n    return p;\r\n  };\r\n\r\n  vc<mint> Q(4 * n);\r\n\
    \  FOR(i, n) Q[i] = -g[i];\r\n\r\n  vc<mint> p = rec(rec, n, 1, Q);\r\n  p.resize(n);\r\
    \n  reverse(all(p));\r\n  p.resize(n0);\r\n  return p;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> composition_0_garner(vc<mint> f, vc<mint> g) {\r\n  constexpr\
    \ u32 ps[] = {167772161, 469762049, 754974721};\r\n  using mint0 = modint<ps[0]>;\r\
    \n  using mint1 = modint<ps[1]>;\r\n  using mint2 = modint<ps[2]>;\r\n\r\n  auto\
    \ rec = [&](auto& rec, int n, int k, vc<mint> Q) -> vc<mint> {\r\n    if (n ==\
    \ 1) {\r\n      vc<mint> p(2 * k);\r\n      reverse(all(f));\r\n      FOR(i, k)\
    \ p[2 * i] = f[i];\r\n      return p;\r\n    }\r\n    vc<mint0> Q0(4 * n * k),\
    \ R0(4 * n * k), p0(4 * n * k);\r\n    vc<mint1> Q1(4 * n * k), R1(4 * n * k),\
    \ p1(4 * n * k);\r\n    vc<mint2> Q2(4 * n * k), R2(4 * n * k), p2(4 * n * k);\r\
    \n    FOR(i, 2 * n * k) {\r\n      Q0[i] = Q[i].val, R0[i] = (i % 2 == 0 ? Q[i].val\
    \ : (-Q[i]).val);\r\n      Q1[i] = Q[i].val, R1[i] = (i % 2 == 0 ? Q[i].val :\
    \ (-Q[i]).val);\r\n      Q2[i] = Q[i].val, R2[i] = (i % 2 == 0 ? Q[i].val : (-Q[i]).val);\r\
    \n    }\r\n    ntt(Q0, 0), ntt(Q1, 0), ntt(Q2, 0), ntt(R0, 0), ntt(R1, 0), ntt(R2,\
    \ 0);\r\n    FOR(i, 4 * n * k) Q0[i] *= R0[i], Q1[i] *= R1[i], Q2[i] *= R2[i];\r\
    \n    ntt(Q0, 1), ntt(Q1, 1), ntt(Q2, 1);\r\n    vc<mint> QQ(4 * n * k);\r\n \
    \   FOR(i, 4 * n * k) {\r\n      QQ[i] = CRT3<mint, ps[0], ps[1], ps[2]>(Q0[i].val,\
    \ Q1[i].val, Q2[i].val);\r\n    }\r\n    FOR(i, 0, 2 * n * k, 2) { QQ[2 * n *\
    \ k + i] += Q[i] + Q[i]; }\r\n    vc<mint> nxt_Q(2 * n * k);\r\n    FOR(j, 2 *\
    \ k) FOR(i, n / 2) {\r\n      nxt_Q[n * j + i] = QQ[(2 * n) * j + (2 * i + 0)];\r\
    \n    }\r\n\r\n    vc<mint> nxt_p = rec(rec, n / 2, k * 2, nxt_Q);\r\n    vc<mint>\
    \ pq(4 * n * k);\r\n    FOR(j, 2 * k) FOR(i, n / 2) {\r\n      pq[(2 * n) * j\
    \ + (2 * i + 1)] += nxt_p[n * j + i];\r\n    }\r\n\r\n    vc<mint> p(2 * n * k);\r\
    \n    FOR(i, 2 * n * k) { p[i] += pq[2 * n * k + i]; }\r\n    FOR(i, 4 * n * k)\
    \ {\r\n      p0[i] += pq[i].val, p1[i] += pq[i].val, p2[i] += pq[i].val;\r\n \
    \   }\r\n    transposed_ntt(p0, 1), transposed_ntt(p1, 1), transposed_ntt(p2,\
    \ 1);\r\n    FOR(i, 4 * n * k) p0[i] *= R0[i], p1[i] *= R1[i], p2[i] *= R2[i];\r\
    \n    transposed_ntt(p0, 0), transposed_ntt(p1, 0), transposed_ntt(p2, 0);\r\n\
    \    FOR(i, 2 * n * k) {\r\n      p[i] += CRT3<mint, ps[0], ps[1], ps[2]>(p0[i].val,\
    \ p1[i].val, p2[i].val);\r\n    }\r\n    return p;\r\n  };\r\n  assert(len(f)\
    \ == len(g));\r\n  int n = 1;\r\n  while (n < len(f)) n *= 2;\r\n  int out_len\
    \ = len(f);\r\n  f.resize(n), g.resize(n);\r\n  int k = 1;\r\n  vc<mint> Q(2 *\
    \ n);\r\n  FOR(i, n) Q[i] = -g[i];\r\n  vc<mint> p = rec(rec, n, k, Q);\r\n\r\n\
    \  vc<mint> output(n);\r\n  FOR(i, n) output[i] = p[i];\r\n  reverse(all(output));\r\
    \n  output.resize(out_len);\r\n  return output;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> composition(vc<mint> f, vc<mint> g) {\r\n  assert(len(f) ==\
    \ len(g));\r\n  if (f.empty()) return {};\r\n  // [x^0]g=0 \u306B\u5E30\u7740\u3057\
    \u3066\u304A\u304F\r\n  if (g[0] != mint(0)) {\r\n    f = poly_taylor_shift<mint>(f,\
    \ g[0]);\r\n    g[0] = 0;\r\n  }\r\n  if (mint::can_ntt()) { return composition_0_ntt(f,\
    \ g); }\r\n  return composition_0_garner(f, g);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/composition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/composition.hpp
layout: document
redirect_from:
- /library/poly/composition.hpp
- /library/poly/composition.hpp.html
title: poly/composition.hpp
---
