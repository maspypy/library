---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/reeds_sloane.test.cpp
    title: test/1_mytest/reeds_sloane.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
    // x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename\
    \ U1, typename U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n\
    \  inline static U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\
    \n  static void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W -\
    \ 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n   \
    \ r = -r;\n    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return\
    \ (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n\
    \  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n   \
    \ U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
    \ y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint\
    \ &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n\
    \  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n\
    \  }\n  mint operator+(mint y) const { return mint(*this) += y; }\n  mint operator-(mint\
    \ y) const { return mint(*this) -= y; }\n  mint operator*(mint y) const { return\
    \ mint(*this) *= y; }\n  bool operator==(mint y) const {\n    return (x >= m ?\
    \ x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const\
    \ { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n\
    \    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1)\
    \ y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32\
    \ = Mongomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64\
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const\
    \ u64 x) {\r\n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5\
    \ or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x\
    \ % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x\
    \ - 1) >> lowbit(x - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\
    \n\r\n  mint::set_mod(x);\r\n  const mint one(u64(1)), minus_one(x - 1);\r\n \
    \ auto ok = [&](u64 a) -> bool {\r\n    auto y = mint(a).pow(d);\r\n    u64 t\
    \ = d;\r\n    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;\r\
    \n    if (y != minus_one && t % 2 == 0) return false;\r\n    return true;\r\n\
    \  };\r\n  if (x < (u64(1) << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if\
    \ (!ok(a)) return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022}) {\r\n      if (!ok(a)) return false;\r\n    }\r\
    \n  }\r\n  return true;\r\n}\n#line 5 \"nt/factor.hpp\"\n\ntemplate <typename\
    \ mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n  auto f\
    \ = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q = 1;\n\
    \  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g == 1; r\
    \ <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r && g ==\
    \ 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *= x - y;\n\
    \      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z = f(z);\n\
    \      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n}\n\nll\
    \ find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return n;\n\
    \  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint = Mongomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Mongomery_modint_64<20231025>;\n      mint::set_mod(n);\n \
    \     m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll,\
    \ int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0)\
    \ {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n     \
    \ pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/mod_inv.hpp\"\n\
    \r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\
    \u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B\
    \ mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod)\
    \ {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if\
    \ (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while\
    \ (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\
    \n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 3 \"seq/reeds_sloane.hpp\"\
    \n\nvc<int> Reeds_Sloane_Prime_Power(vc<int> S, int p, int e) {\n  int N = len(S);\n\
    \  if (N == 0) return {1};\n  int M = 1;\n  FOR(e) M *= p;\n\n  using mint = Dynamic_Modint<20260623>;\n\
    \  mint::set_mod(M);\n\n  auto decompose = [&](mint x) -> pair<mint, int> {\n\
    \    // x = tp^u\n    int t = x.val, u = 0;\n    if (t == 0) return {1, e};\n\
    \    while (t % p == 0) t /= p, ++u;\n    return {t, u};\n  };\n\n  using poly\
    \ = vc<mint>;\n  vc<poly> Q(e);\n  vc<int> L(e);\n\n  vc<poly> B(e);\n  vc<int>\
    \ LB(e);\n  vc<int> nB(e);\n  vc<mint> tB(e);\n\n  mint pw = 1;\n  for (int i\
    \ = 0; i < e; ++i, pw *= p) {\n    Q[i] = {pw};\n    L[i] = 0;\n    nB[i] = -1;\n\
    \  }\n\n  for (int n = 0; n < N; ++n) {\n    // delta=tp^u\n    vc<mint> t(e);\n\
    \    vc<int> u(e);\n    FOR(i, e) {\n      mint delta = 0;\n      assert(len(Q[i])\
    \ <= 1 + n);\n      FOR(k, len(Q[i])) delta += Q[i][k] * S[n - k];\n      tie(t[i],\
    \ u[i]) = decompose(delta);\n    }\n\n    vc<poly> Q_next = Q;\n    vc<int> L_next\
    \ = L;\n\n    FOR(i, e) {\n      if (u[i] == e) continue;\n\n      int j = e -\
    \ 1 - u[i];\n      if (nB[j] == -1) {\n        Q_next[i].resize(n + 2);\n    \
    \    L_next[i] = n + 1;\n      } else {\n        L_next[i] = max(L[i], LB[j] +\
    \ n - nB[j]);\n        Q_next[i].resize(L_next[i] + 1);\n        mint c = t[i]\
    \ / tB[j];\n        FOR(k, len(B[j])) Q_next[i][k + n - nB[j]] -= c * B[j][k];\n\
    \      }\n    }\n    FOR(i, e) {\n      if (L[i] < L_next[i]) {\n        int j\
    \ = e - 1 - u[i];\n        B[i] = Q[j];\n        LB[i] = L[j];\n        nB[i]\
    \ = n;\n        tB[i] = t[j];\n      }\n    }\n    swap(Q, Q_next);\n    swap(L,\
    \ L_next);\n  }\n  vc<int> res;\n  for (auto& x : Q[0]) res.eb(x.val);\n  assert(len(res)\
    \ == L[0] + 1);\n  return res;\n}\n\n/*\nreturn {P(x),Q(x)} such that\nS(x)=P(x)/Q(x)\
    \ mod x^N, [x^0]Q=1\nminimize L=max(deg(P)+1,deg(Q))\n*/\ntemplate <typename mint>\n\
    pair<vc<mint>, vc<mint>> Reeds_Sloane(vc<mint> S, vc<pair<ll, int>> pfs = {})\
    \ {\n  int mod = mint::get_mod();\n  if (mod > 1 && pfs.empty()) {\n    pfs =\
    \ factor(mod);\n  }\n  {\n    int check = mod;\n    for (auto [p, e] : pfs) {\n\
    \      FOR(e) {\n        assert(check % p == 0);\n        check /= p;\n      }\n\
    \    }\n    assert(check == 1);\n  }\n\n  if (mod == 1) return {{}, {1}};\n\n\
    \  int n = len(pfs);\n  vi coef(n);\n  FOR(i, n) {\n    auto [p, e] = pfs[i];\n\
    \    int a = 1, b = mod;\n    FOR(e) a *= p, b /= p;\n    ll c = mod_inv(b, a);\n\
    \    coef[i] = c * b % mod;\n  }\n  vc<mint> Q;\n  FOR(k, n) {\n    auto [p, e]\
    \ = pfs[k];\n    int a = 1;\n    FOR(e) a *= p;\n    vc<int> T(len(S));\n    FOR(i,\
    \ len(S)) T[i] = (S[i].val) % a;\n    auto Qk = Reeds_Sloane_Prime_Power(T, p,\
    \ e);\n    if (len(Q) < len(Qk)) Q.resize(len(Qk));\n    FOR(i, len(Qk)) Q[i]\
    \ += Qk[i] * coef[k];\n  }\n  vc<mint> P(len(Q) - 1);\n  FOR(i, len(P)) FOR(j,\
    \ i + 1) P[i] += Q[j] * S[i - j];\n  return {P, Q};\n}\n"
  code: "#include \"nt/factor.hpp\"\n#include \"mod/mod_inv.hpp\"\n\nvc<int> Reeds_Sloane_Prime_Power(vc<int>\
    \ S, int p, int e) {\n  int N = len(S);\n  if (N == 0) return {1};\n  int M =\
    \ 1;\n  FOR(e) M *= p;\n\n  using mint = Dynamic_Modint<20260623>;\n  mint::set_mod(M);\n\
    \n  auto decompose = [&](mint x) -> pair<mint, int> {\n    // x = tp^u\n    int\
    \ t = x.val, u = 0;\n    if (t == 0) return {1, e};\n    while (t % p == 0) t\
    \ /= p, ++u;\n    return {t, u};\n  };\n\n  using poly = vc<mint>;\n  vc<poly>\
    \ Q(e);\n  vc<int> L(e);\n\n  vc<poly> B(e);\n  vc<int> LB(e);\n  vc<int> nB(e);\n\
    \  vc<mint> tB(e);\n\n  mint pw = 1;\n  for (int i = 0; i < e; ++i, pw *= p) {\n\
    \    Q[i] = {pw};\n    L[i] = 0;\n    nB[i] = -1;\n  }\n\n  for (int n = 0; n\
    \ < N; ++n) {\n    // delta=tp^u\n    vc<mint> t(e);\n    vc<int> u(e);\n    FOR(i,\
    \ e) {\n      mint delta = 0;\n      assert(len(Q[i]) <= 1 + n);\n      FOR(k,\
    \ len(Q[i])) delta += Q[i][k] * S[n - k];\n      tie(t[i], u[i]) = decompose(delta);\n\
    \    }\n\n    vc<poly> Q_next = Q;\n    vc<int> L_next = L;\n\n    FOR(i, e) {\n\
    \      if (u[i] == e) continue;\n\n      int j = e - 1 - u[i];\n      if (nB[j]\
    \ == -1) {\n        Q_next[i].resize(n + 2);\n        L_next[i] = n + 1;\n   \
    \   } else {\n        L_next[i] = max(L[i], LB[j] + n - nB[j]);\n        Q_next[i].resize(L_next[i]\
    \ + 1);\n        mint c = t[i] / tB[j];\n        FOR(k, len(B[j])) Q_next[i][k\
    \ + n - nB[j]] -= c * B[j][k];\n      }\n    }\n    FOR(i, e) {\n      if (L[i]\
    \ < L_next[i]) {\n        int j = e - 1 - u[i];\n        B[i] = Q[j];\n      \
    \  LB[i] = L[j];\n        nB[i] = n;\n        tB[i] = t[j];\n      }\n    }\n\
    \    swap(Q, Q_next);\n    swap(L, L_next);\n  }\n  vc<int> res;\n  for (auto&\
    \ x : Q[0]) res.eb(x.val);\n  assert(len(res) == L[0] + 1);\n  return res;\n}\n\
    \n/*\nreturn {P(x),Q(x)} such that\nS(x)=P(x)/Q(x) mod x^N, [x^0]Q=1\nminimize\
    \ L=max(deg(P)+1,deg(Q))\n*/\ntemplate <typename mint>\npair<vc<mint>, vc<mint>>\
    \ Reeds_Sloane(vc<mint> S, vc<pair<ll, int>> pfs = {}) {\n  int mod = mint::get_mod();\n\
    \  if (mod > 1 && pfs.empty()) {\n    pfs = factor(mod);\n  }\n  {\n    int check\
    \ = mod;\n    for (auto [p, e] : pfs) {\n      FOR(e) {\n        assert(check\
    \ % p == 0);\n        check /= p;\n      }\n    }\n    assert(check == 1);\n \
    \ }\n\n  if (mod == 1) return {{}, {1}};\n\n  int n = len(pfs);\n  vi coef(n);\n\
    \  FOR(i, n) {\n    auto [p, e] = pfs[i];\n    int a = 1, b = mod;\n    FOR(e)\
    \ a *= p, b /= p;\n    ll c = mod_inv(b, a);\n    coef[i] = c * b % mod;\n  }\n\
    \  vc<mint> Q;\n  FOR(k, n) {\n    auto [p, e] = pfs[k];\n    int a = 1;\n   \
    \ FOR(e) a *= p;\n    vc<int> T(len(S));\n    FOR(i, len(S)) T[i] = (S[i].val)\
    \ % a;\n    auto Qk = Reeds_Sloane_Prime_Power(T, p, e);\n    if (len(Q) < len(Qk))\
    \ Q.resize(len(Qk));\n    FOR(i, len(Qk)) Q[i] += Qk[i] * coef[k];\n  }\n  vc<mint>\
    \ P(len(Q) - 1);\n  FOR(i, len(P)) FOR(j, i + 1) P[i] += Q[j] * S[i - j];\n  return\
    \ {P, Q};\n}\n"
  dependsOn:
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/mod_inv.hpp
  isVerificationFile: false
  path: seq/reeds_sloane.hpp
  requiredBy: []
  timestamp: '2026-06-23 23:59:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/reeds_sloane.test.cpp
documentation_of: seq/reeds_sloane.hpp
layout: document
redirect_from:
- /library/seq/reeds_sloane.hpp
- /library/seq/reeds_sloane.hpp.html
title: seq/reeds_sloane.hpp
---
