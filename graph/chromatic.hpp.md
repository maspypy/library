---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\
    \n\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate\
    \ <int id, typename U1, typename U2>\nstruct Mongomery_modint {\n  using mint\
    \ = Mongomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int W\
    \ = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(5) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint()\
    \ : x(0) {}\n  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const\
    \ {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
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
    \n  }\r\n  return true;\r\n}\n#line 3 \"graph/chromatic.hpp\"\n\r\n// O(N2^N)\r\
    \ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph& G) {\r\
    \n  assert(G.is_prepared());\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\n  FOR(v,\
    \ N) for (auto&& e: G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset \u3067\
    \u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\
    \u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1 << v)\
    \ { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\n\
    \  auto solve_p = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s))\
    \ & 1 ? 1 : -1);\r\n    FOR(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1\
    \ << N) {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\
    \n        sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum\
    \ != 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\
    \n  chmax(ANS, solve_p(0));\r\n\r\n  FOR(TRIAL) {\r\n    int p;\r\n    while (1)\
    \ {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p)) break;\r\
    \n    }\r\n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\n"
  code: "#include \"random/base.hpp\"\r\n#include \"nt/primetest.hpp\"\r\n\r\n// O(N2^N)\r\
    \ntemplate <typename Graph, int TRIAL = 0>\r\nint chromatic_number(Graph& G) {\r\
    \n  assert(G.is_prepared());\r\n\r\n  int N = G.N;\r\n  vc<int> nbd(N);\r\n  FOR(v,\
    \ N) for (auto&& e: G[v]) nbd[v] |= 1 << e.to;\r\n\r\n  // s \u306E subset \u3067\
    \u3042\u308B\u3088\u3046\u306A\u72EC\u7ACB\u96C6\u5408\u306E\u6570\u3048\u4E0A\
    \u3052\r\n  vc<int> dp(1 << N);\r\n  dp[0] = 1;\r\n  FOR(v, N) FOR(s, 1 << v)\
    \ { dp[s | 1 << v] = dp[s] + dp[s & (~nbd[v])]; }\r\n\r\n  vi pow(1 << N);\r\n\
    \  auto solve_p = [&](int p) -> int {\r\n    FOR(s, 1 << N) pow[s] = ((N - popcnt(s))\
    \ & 1 ? 1 : -1);\r\n    FOR(k, 1, N) {\r\n      ll sum = 0;\r\n      FOR(s, 1\
    \ << N) {\r\n        pow[s] = pow[s] * dp[s];\r\n        if (p) pow[s] %= p;\r\
    \n        sum += pow[s];\r\n      }\r\n      if (p) sum %= p;\r\n      if (sum\
    \ != 0) { return k; }\r\n    }\r\n    return N;\r\n  };\r\n\r\n  int ANS = 0;\r\
    \n  chmax(ANS, solve_p(0));\r\n\r\n  FOR(TRIAL) {\r\n    int p;\r\n    while (1)\
    \ {\r\n      p = RNG(1LL << 30, 1LL << 31);\r\n      if (primetest(p)) break;\r\
    \n    }\r\n    chmax(ANS, solve_p(p));\r\n  }\r\n  return ANS;\r\n}\r\n"
  dependsOn:
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  isVerificationFile: false
  path: graph/chromatic.hpp
  requiredBy: []
  timestamp: '2023-11-02 05:00:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/chromatic_number.test.cpp
documentation_of: graph/chromatic.hpp
layout: document
redirect_from:
- /library/graph/chromatic.hpp
- /library/graph/chromatic.hpp.html
title: graph/chromatic.hpp
---
