---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/offline_query/mo.hpp
    title: ds/offline_query/mo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/prefix_sum_of_binom.test.cpp
    title: test/1_mytest/prefix_sum_of_binom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2206.test.cpp
    title: test/3_yukicoder/2206.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2206_2.test.cpp
    title: test/3_yukicoder/2206_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/mod/prefix_sum_of_binom.hpp
  bundledCode: "#line 1 \"mod/prefix_sum_of_binom.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/prefix_sum_of_binom.hpp\n\
    #line 1 \"ds/offline_query/mo.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/offline_query/mo.hpp\n\
    // Nsqrt(Q)\nstruct Mo {\n  vc<pair<int, int>> LR;\n  void add(int L, int R) {\
    \ LR.emplace_back(L, R); }\n\n  static vc<int> get_mo_order(vc<pair<int, int>>\
    \ LR) {\n    int N = 1;\n    for (auto &&[l, r] : LR) chmax(N, l), chmax(N, r);\n\
    \    int Q = len(LR);\n    if (Q == 0) return {};\n    int bs = sqrt(3) * N /\
    \ sqrt(2 * Q);\n    chmax(bs, 1);\n    vc<int> I(Q);\n    iota(all(I), 0);\n \
    \   sort(all(I), [&](int a, int b) {\n      int aa = LR[a].fi / bs, bb = LR[b].fi\
    \ / bs;\n      if (aa != bb) return aa < bb;\n      return (aa & 1) ? LR[a].se\
    \ > LR[b].se : LR[a].se < LR[b].se;\n    });\n\n    auto cost = [&](int a, int\
    \ b) -> int {\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se -\
    \ LR[I[b]].se);\n    };\n\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\
    6%\u7A0B\u5EA6\u6539\u5584\n    auto work = [&](int k) -> void {\n      if (cost(k,\
    \ k + 2) + cost(k + 1, k + 3) <\n          cost(k, k + 1) + cost(k + 2, k + 3))\
    \ {\n        swap(I[k + 1], I[k + 2]);\n      }\n      if (cost(k, k + 3) + cost(k\
    \ + 1, k + 4) <\n          cost(k, k + 1) + cost(k + 3, k + 4)) {\n        swap(I[k\
    \ + 1], I[k + 3]);\n      }\n    };\n    FOR(k, Q - 5) work(k);\n    FOR_R(k,\
    \ Q - 5) work(k);\n    return I;\n  }\n\n  template <typename F1, typename F2,\
    \ typename F3, typename F4, typename F5>\n  void calc(F1 add_l, F2 add_r, F3 rm_l,\
    \ F4 rm_r, F5 query) {\n    auto I = get_mo_order(LR);\n    int l = 0, r = 0;\n\
    \    for (auto idx : I) {\n      while (l > LR[idx].fi) add_l(--l);\n      while\
    \ (r < LR[idx].se) add_r(r++);\n      while (l < LR[idx].fi) rm_l(l++);\n    \
    \  while (r > LR[idx].se) rm_r(--r);\n      query(idx);\n    }\n  }\n};\n#line\
    \ 3 \"mod/prefix_sum_of_binom.hpp\"\n\ntemplate <typename mint>\nstruct Prefix_Sum_of_Binom\
    \ {\n  static constexpr u32 mod = mint::get_mod();\n  const int MAX_N;\n  const\
    \ int B;\n  vc<mint> POW;\n  vvc<mint> dat;\n\n  Prefix_Sum_of_Binom(int MAX_N)\
    \ : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {\n    assert(MAX_N >= 0);\n    int K = ceil(MAX_N,\
    \ B + B) + 2;\n    int p = max(MAX_N, K * B);\n    POW.assign(p + 1, mint(1));\n\
    \    FOR(i, p) POW[i + 1] = POW[i] + POW[i];\n    dat.resize(K);\n    FOR(k, 0,\
    \ K) {\n      // [0, kB] \u3067\u306E closed sum\n      vc<mint>& f = dat[k];\n\
    \      if (MAX_N + 1 - k * B <= 0) continue;\n      f.resize(MAX_N + 1 - k * B);\n\
    \      int m = k * B;\n      f[0] = POW[m] * fact<mint>(m);\n      FOR(i, MAX_N\
    \ - m) {\n        f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);\n\
    \      }\n    }\n  }\n\n  // \\sum_{k=0}^{m-1} binom(n,k)\n  mint query(int n,\
    \ int m) {\n    assert(0 <= m);\n    chmin(m, n + 1);\n    if (m == 0) return\
    \ mint(0);\n    if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);\n    --m;\n\
    \    int a = m / B;\n\n    if (m <= a * B + B / 2) {\n      u128 t = 0;\n    \
    \  FOR(i, a * B + 1, m + 1) {\n        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n\
    \ - i).val);\n      }\n      return _get(n, a) + mint::raw(t % mod) * fact<mint>(n);\n\
    \    } else {\n      u128 t = 0;\n      FOR(i, m + 1, (a + 1) * B + 1) {\n   \
    \     t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);\n      }\n\
    \      return _get(n, a + 1) - mint::raw(t % mod) * fact<mint>(n);\n    }\n  \
    \  return 0;\n  }\n\n private:\n  mint _get(int n, int k) {\n    if (n <= k *\
    \ B) return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k * B);\n \
    \ }\n};\n\ntemplate <typename mint>\nstruct Prefix_Sum_of_Binom_Offline {\n  vc<pair<int,\
    \ int>> query;\n\n  void add(int n, int m) { query.eb(n, m); }\n\n  vc<mint> calc()\
    \ {\n    int Q = len(query);\n    vc<mint> ANS(Q);\n    auto I = Mo::get_mo_order(query);\n\
    \    int n = 0, m = 0;\n    mint ans = 0;\n    mint inv2 = inv<mint>(2);\n   \
    \ for (auto& i : I) {\n      auto [nn, mm] = query[i];\n      while (n < nn) {\n\
    \        ans = ans + ans - C<mint>(n, m - 1);\n        n++;\n      }\n      while\
    \ (n > nn) {\n        ans += C<mint>(n - 1, m - 1);\n        ans *= inv2;\n  \
    \      --n;\n      }\n      while (m < mm) {\n        ans += C<mint>(n, m++);\n\
    \      }\n      while (m > mm) {\n        ans -= C<mint>(n, --m);\n      }\n \
    \     ANS[i] = ans;\n    }\n    return ANS;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/mod/prefix_sum_of_binom.hpp\n\
    #include \"ds/offline_query/mo.hpp\"\n\ntemplate <typename mint>\nstruct Prefix_Sum_of_Binom\
    \ {\n  static constexpr u32 mod = mint::get_mod();\n  const int MAX_N;\n  const\
    \ int B;\n  vc<mint> POW;\n  vvc<mint> dat;\n\n  Prefix_Sum_of_Binom(int MAX_N)\
    \ : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {\n    assert(MAX_N >= 0);\n    int K = ceil(MAX_N,\
    \ B + B) + 2;\n    int p = max(MAX_N, K * B);\n    POW.assign(p + 1, mint(1));\n\
    \    FOR(i, p) POW[i + 1] = POW[i] + POW[i];\n    dat.resize(K);\n    FOR(k, 0,\
    \ K) {\n      // [0, kB] \u3067\u306E closed sum\n      vc<mint>& f = dat[k];\n\
    \      if (MAX_N + 1 - k * B <= 0) continue;\n      f.resize(MAX_N + 1 - k * B);\n\
    \      int m = k * B;\n      f[0] = POW[m] * fact<mint>(m);\n      FOR(i, MAX_N\
    \ - m) {\n        f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);\n\
    \      }\n    }\n  }\n\n  // \\sum_{k=0}^{m-1} binom(n,k)\n  mint query(int n,\
    \ int m) {\n    assert(0 <= m);\n    chmin(m, n + 1);\n    if (m == 0) return\
    \ mint(0);\n    if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);\n    --m;\n\
    \    int a = m / B;\n\n    if (m <= a * B + B / 2) {\n      u128 t = 0;\n    \
    \  FOR(i, a * B + 1, m + 1) {\n        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n\
    \ - i).val);\n      }\n      return _get(n, a) + mint::raw(t % mod) * fact<mint>(n);\n\
    \    } else {\n      u128 t = 0;\n      FOR(i, m + 1, (a + 1) * B + 1) {\n   \
    \     t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);\n      }\n\
    \      return _get(n, a + 1) - mint::raw(t % mod) * fact<mint>(n);\n    }\n  \
    \  return 0;\n  }\n\n private:\n  mint _get(int n, int k) {\n    if (n <= k *\
    \ B) return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k * B);\n \
    \ }\n};\n\ntemplate <typename mint>\nstruct Prefix_Sum_of_Binom_Offline {\n  vc<pair<int,\
    \ int>> query;\n\n  void add(int n, int m) { query.eb(n, m); }\n\n  vc<mint> calc()\
    \ {\n    int Q = len(query);\n    vc<mint> ANS(Q);\n    auto I = Mo::get_mo_order(query);\n\
    \    int n = 0, m = 0;\n    mint ans = 0;\n    mint inv2 = inv<mint>(2);\n   \
    \ for (auto& i : I) {\n      auto [nn, mm] = query[i];\n      while (n < nn) {\n\
    \        ans = ans + ans - C<mint>(n, m - 1);\n        n++;\n      }\n      while\
    \ (n > nn) {\n        ans += C<mint>(n - 1, m - 1);\n        ans *= inv2;\n  \
    \      --n;\n      }\n      while (m < mm) {\n        ans += C<mint>(n, m++);\n\
    \      }\n      while (m > mm) {\n        ans -= C<mint>(n, --m);\n      }\n \
    \     ANS[i] = ans;\n    }\n    return ANS;\n  }\n};\n"
  dependsOn:
  - ds/offline_query/mo.hpp
  isVerificationFile: false
  path: mod/prefix_sum_of_binom.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/prefix_sum_of_binom.test.cpp
  - test/3_yukicoder/2206.test.cpp
  - test/3_yukicoder/2206_2.test.cpp
documentation_of: mod/prefix_sum_of_binom.hpp
layout: document
redirect_from:
- /library/mod/prefix_sum_of_binom.hpp
- /library/mod/prefix_sum_of_binom.hpp.html
title: mod/prefix_sum_of_binom.hpp
---
