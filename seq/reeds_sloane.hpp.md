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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"other/bit.hpp\"\n#include \"nt/factor.hpp\"\n#include \"mod/mod_inv.hpp\"\
    \n#include \"mod/dynamic_modint.hpp\"\n\ntemplate <bool EVEN>\nvc<u32> Reeds_Sloane_Prime_Power(vc<u32>\
    \ S, int p, int e) {\n  using T = std::conditional_t<EVEN, u32, Dynamic_Modint<20260623>>;\n\
    \  u32 M = 1;\n  FOR(e) M *= p;\n  if constexpr (EVEN) {\n    assert(p == 2);\n\
    \  } else {\n    assert(p != 2);\n    T::set_mod(M);\n  }\n  int N = len(S);\n\
    \  if (N == 0) return {1};\n\n  auto decompose = [&](T x) -> pair<T, int> {\n\
    \    if constexpr (EVEN) {\n      int k = lowbit(x);\n      if (k == -1 || k >=\
    \ e) return {1, e};\n      return {x >> k, k};\n    } else {\n      // x = tp^u\n\
    \      int t = x.val, u = 0;\n      if (t == 0) return {1, e};\n      while (t\
    \ % p == 0) t /= p, ++u;\n      return {t, u};\n    }\n  };\n  auto inv = [&](T\
    \ a) -> T {\n    if constexpr (EVEN) {\n      T x = 1;\n      x = x * (2U - a\
    \ * x);\n      x = x * (2U - a * x);\n      x = x * (2U - a * x);\n      x = x\
    \ * (2U - a * x);\n      x = x * (2U - a * x);\n      return x;\n    } else {\n\
    \      return a.pow(M - M / p - 1);\n    }\n  };\n\n  using poly = vc<T>;\n  vc<poly>\
    \ Q(e);\n  vc<int> L(e);\n\n  vc<poly> B(e);\n  vc<int> LB(e);\n  vc<int> nB(e);\n\
    \  vc<T> tB(e);\n\n  T pw = 1;\n  for (int j = 0; j < e; ++j, pw *= p) {\n   \
    \ Q[j] = {pw};\n    L[j] = 0;\n    nB[j] = -1;\n  }\n\n  for (int n = 0; n < N;\
    \ ++n) {\n    // delta=tp^u\n    vc<T> t(e);\n    vc<int> u(e);\n    FOR(j, e)\
    \ {\n      T delta = 0;\n      assert(len(Q[j]) <= 1 + n);\n      FOR(k, len(Q[j]))\
    \ delta += Q[j][k] * S[n - k];\n      tie(t[j], u[j]) = decompose(delta);\n  \
    \  }\n\n    vc<poly> Q_next = Q;\n    vc<int> L_next = L;\n\n    FOR(j, e) {\n\
    \      if (u[j] == e) continue;\n\n      int k = e - 1 - u[j];\n      if (nB[k]\
    \ == -1) {\n        Q_next[j].resize(n + 2);\n        L_next[j] = n + 1;\n   \
    \   } else {\n        L_next[j] = max(L[j], LB[k] + n - nB[k]);\n        Q_next[j].resize(L_next[j]\
    \ + 1);\n        T c = t[j] * inv(tB[k]);\n        FOR(i, len(B[k])) Q_next[j][i\
    \ + n - nB[k]] -= c * B[k][i];\n      }\n    }\n    FOR(j, e) {\n      if (L[j]\
    \ < L_next[j]) {\n        int k = e - 1 - u[j];\n        B[j] = Q[k];\n      \
    \  LB[j] = L[k];\n        nB[j] = n;\n        tB[j] = t[k];\n      }\n    }\n\
    \    swap(Q, Q_next), swap(L, L_next);\n  }\n  if constexpr (EVEN) {\n    return\
    \ Q[0];\n  } else {\n    vc<u32> res;\n    for (auto& x : Q[0]) res.eb(x.val);\n\
    \    assert(len(res) == L[0] + 1);\n    return res;\n  }\n}\n\n/*\nreturn {P(x),Q(x)}\
    \ such that\nS(x)=P(x)/Q(x) mod x^N, [x^0]Q=1\nminimize L=max(deg(P)+1,deg(Q))\n\
    */\ntemplate <typename mint>\npair<vc<mint>, vc<mint>> Reeds_Sloane(vc<mint> S,\
    \ vc<pair<ll, int>> pfs = {}) {\n  u32 mod = mint::get_mod();\n  if (mod > 1 &&\
    \ pfs.empty()) {\n    pfs = factor(mod);\n  }\n  {\n    u32 check = mod;\n   \
    \ for (auto [p, e] : pfs) {\n      FOR(e) {\n        assert(check % p == 0);\n\
    \        check /= p;\n      }\n    }\n    assert(check == 1);\n  }\n\n  if (mod\
    \ == 1) return {{}, {1}};\n\n  int n = len(pfs);\n  vi coef(n);\n  FOR(i, n) {\n\
    \    auto [p, e] = pfs[i];\n    int a = 1, b = mod;\n    FOR(e) a *= p, b /= p;\n\
    \    ll c = mod_inv(b, a);\n    coef[i] = c * b % mod;\n  }\n  vc<mint> Q;\n \
    \ FOR(k, n) {\n    auto [p, e] = pfs[k];\n    int a = 1;\n    FOR(e) a *= p;\n\
    \    vc<u32> T(len(S));\n    FOR(i, len(S)) T[i] = (S[i].val) % a;\n    auto Qk\
    \ = (p == 2 ? Reeds_Sloane_Prime_Power<1>(T, p, e)\n                      : Reeds_Sloane_Prime_Power<0>(T,\
    \ p, e));\n    if (len(Q) < len(Qk)) Q.resize(len(Qk));\n    FOR(i, len(Qk)) Q[i]\
    \ += ll(Qk[i]) * coef[k];\n  }\n  vc<mint> P(len(Q) - 1);\n  FOR(i, len(P)) FOR(j,\
    \ i + 1) P[i] += Q[j] * S[i - j];\n  return {P, Q};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/reeds_sloane.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/reeds_sloane.hpp
layout: document
redirect_from:
- /library/seq/reeds_sloane.hpp
- /library/seq/reeds_sloane.hpp.html
title: seq/reeds_sloane.hpp
---
