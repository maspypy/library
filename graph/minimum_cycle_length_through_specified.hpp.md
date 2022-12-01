---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: nt/GF2.hpp
    title: nt/GF2.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1775.test.cpp
    title: test/yukicoder/1775.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://epubs.siam.org/doi/10.1137/1.9781611973099.139
    - https://www.slideshare.net/wata_orz/ss-12208032
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"nt/GF2.hpp\"\n\
    #include <emmintrin.h>\n#include <smmintrin.h>\n#include <wmmintrin.h>\n\n__attribute__((target(\"\
    pclmul\"))) inline __m128i myclmul(const __m128i &a,\n                       \
    \                                  const __m128i &b) {\n  return _mm_clmulepi64_si128(a,\
    \ b, 0);\n}\n\n// 2^n \u5143\u4F53\ntemplate <int K>\nstruct GF2 {\n  // irreducible\
    \ poly x^K + ...\n  static constexpr int POLY[65]\n      = {0,  0, 3,  3,   3,\
    \  5,   3,  3,  27,  3,  9,  5,   9, 27, 33, 3,   43,\n         9,  9, 39, 9,\
    \   5,  3,   33, 27, 9,   27, 39, 3,   5, 3,  9,  141, 75,\n         27, 5, 53,\
    \ 63,  99, 17,  57, 9,  39,  89, 33, 27,  3, 33, 45, 113, 29,\n         75, 9,\
    \ 71, 125, 71, 149, 17, 99, 123, 3,  39, 105, 3, 27};\n\n  static constexpr u64\
    \ mask() { return u64(-1) >> (64 - K); }\n\n  __attribute__((target(\"sse4.2\"\
    ))) static u64 mul(u64 a, u64 b) {\n    static bool prepared = 0;\n    static\
    \ u64 MEMO[8][65536];\n    if (!prepared) {\n      prepared = 1;\n      vc<u64>\
    \ tmp(128);\n      tmp[0] = 1;\n      FOR(i, 127) {\n        tmp[i + 1] = tmp[i]\
    \ << 1;\n        if (tmp[i] >> (K - 1) & 1) {\n          tmp[i + 1] ^= POLY[K];\n\
    \          tmp[i + 1] &= mask();\n        }\n      }\n      FOR(k, 8) {\n    \
    \    MEMO[k][0] = 0;\n        FOR(i, 16) {\n          FOR(s, 1 << i) { MEMO[k][s\
    \ | 1 << i] = MEMO[k][s] ^ tmp[16 * k + i]; }\n        }\n      }\n    }\n   \
    \ const __m128i a_ = _mm_set_epi64x(0, a);\n    const __m128i b_ = _mm_set_epi64x(0,\
    \ b);\n    const __m128i c_ = myclmul(a_, b_);\n    u64 lo = _mm_extract_epi64(c_,\
    \ 0);\n    u64 hi = _mm_extract_epi64(c_, 1);\n    u64 x = 0;\n    x ^= MEMO[0][lo\
    \ & 65535];\n    x ^= MEMO[1][(lo >> 16) & 65535];\n    x ^= MEMO[2][(lo >> 32)\
    \ & 65535];\n    x ^= MEMO[3][(lo >> 48) & 65535];\n    x ^= MEMO[4][hi & 65535];\n\
    \    x ^= MEMO[5][(hi >> 16) & 65535];\n    x ^= MEMO[6][(hi >> 32) & 65535];\n\
    \    x ^= MEMO[7][(hi >> 48) & 65535];\n    return x;\n  }\n\n  u64 val;\n  constexpr\
    \ GF2(const u64 val = 0) noexcept : val(val & mask()) {}\n  bool operator<(const\
    \ GF2 &other) const {\n    return val < other.val;\n  } // To use std::map\n \
    \ GF2 &operator+=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator-=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator*=(const GF2 &p) {\n    val = mul(val, p.val);\n    return *this;\n\
    \  }\n\n  GF2 &operator/=(const GF2 &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  GF2 operator-() const { return GF2(-val); }\n  GF2 operator+(const\
    \ GF2 &p) const { return GF2(*this) += p; }\n  GF2 operator-(const GF2 &p) const\
    \ { return GF2(*this) -= p; }\n  GF2 operator*(const GF2 &p) const { return GF2(*this)\
    \ *= p; }\n  GF2 operator/(const GF2 &p) const { return GF2(*this) /= p; }\n \
    \ bool operator==(const GF2 &p) const { return val == p.val; }\n  bool operator!=(const\
    \ GF2 &p) const { return val != p.val; }\n  GF2 inverse() const { return pow((u64(1)\
    \ << K) - 2); }\n  GF2 pow(u64 n) const {\n    GF2 ret(1), mul(val);\n    while\
    \ (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n};\n#line 3 \"graph/minimum_cycle_length_through_specified.hpp\"\
    \n\n// https://www.slideshare.net/wata_orz/ss-12208032\n// https://epubs.siam.org/doi/10.1137/1.9781611973099.139\n\
    // O(2^kN^2M)\ntemplate <typename GT>\nint minimum_cycle_length_through_specified(GT&\
    \ G, vc<int> use) {\n  assert(len(use) >= 2);\n  assert(!G.is_directed());\n \
    \ const int N = G.N;\n  using F = GF2<64>;\n  int s = use.back();\n  use.pop_back();\n\
    \n  // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\u306B\u5909\u5F62\
    \n  // \u59CB\u70B9\u306E\u8FD1\u304F\u3067\u306F\u9006\u5411\u304D\u3092\u9055\
    \u3046\u91CD\u307F\u306B\u3059\u308B\u3053\u3068\u3067\u3001\u5411\u304D\u9055\
    \u3044\u306E\u30AD\u30E3\u30F3\u30BB\u30EA\u30F3\u30B0\u3092\u9632\u3050\n  Graph<F,\
    \ 1> H(G.N);\n  for (auto&& e: G.edges) {\n    F a = RNG_64();\n    F b = a;\n\
    \    if (e.frm == s || e.to == s) b = RNG_64();\n    H.add(e.frm, e.to, a);\n\
    \    H.add(e.to, e.frm, b);\n  }\n  H.build();\n  const int M = H.M;\n\n  int\
    \ K = len(use);\n  vc<int> mask(N);\n  FOR(k, K) mask[use[k]] = 1 << k;\n\n  //\
    \ [\u96C6\u5408][\u6700\u5F8C\u306E\u8FBA]\n  vv(F, dp, 1 << K, M);\n  for (auto&&\
    \ e: H[s]) { dp[mask[e.to]][e.id] = e.cost; }\n  FOR(L, 2, N + 1) {\n    vv(F,\
    \ newdp, 1 << K, M);\n    FOR(s, 1 << K) {\n      vc<F> dp_v(N);\n      FOR(i,\
    \ M) dp_v[H.edges[i].to] += dp[s][i];\n      FOR(v, N) {\n        for (auto&&\
    \ e: H[v]) {\n          int t = s | mask[e.to];\n          if (mask[e.to] && s\
    \ == t) continue;\n          newdp[t][e.id] += dp_v[v] * e.cost;\n          //\
    \ use \u4E0A\u306E\u70B9\u304B\u3089\u623B\u308B\u306E\u3092\u7981\u6B62\u3059\
    \u308B\n          if (mask[v]) { newdp[t][e.id] += dp[s][e.id ^ 1] * e.cost; }\n\
    \        }\n      }\n    }\n    swap(dp, newdp);\n    int full = (1 << K) - 1;\n\
    \    F sm = 0;\n    FOR(i, M) {\n      if (H.edges[i].to == s) sm += dp[full][i];\n\
    \    }\n    if (sm != F(0)) return L;\n  }\n  return -1;\n}\n"
  code: "#include \"random/base.hpp\"\n#include \"nt/GF2.hpp\"\n\n// https://www.slideshare.net/wata_orz/ss-12208032\n\
    // https://epubs.siam.org/doi/10.1137/1.9781611973099.139\n// O(2^kN^2M)\ntemplate\
    \ <typename GT>\nint minimum_cycle_length_through_specified(GT& G, vc<int> use)\
    \ {\n  assert(len(use) >= 2);\n  assert(!G.is_directed());\n  const int N = G.N;\n\
    \  using F = GF2<64>;\n  int s = use.back();\n  use.pop_back();\n\n  // \u91CD\
    \u307F\u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\u306B\u5909\u5F62\n  // \u59CB\
    \u70B9\u306E\u8FD1\u304F\u3067\u306F\u9006\u5411\u304D\u3092\u9055\u3046\u91CD\
    \u307F\u306B\u3059\u308B\u3053\u3068\u3067\u3001\u5411\u304D\u9055\u3044\u306E\
    \u30AD\u30E3\u30F3\u30BB\u30EA\u30F3\u30B0\u3092\u9632\u3050\n  Graph<F, 1> H(G.N);\n\
    \  for (auto&& e: G.edges) {\n    F a = RNG_64();\n    F b = a;\n    if (e.frm\
    \ == s || e.to == s) b = RNG_64();\n    H.add(e.frm, e.to, a);\n    H.add(e.to,\
    \ e.frm, b);\n  }\n  H.build();\n  const int M = H.M;\n\n  int K = len(use);\n\
    \  vc<int> mask(N);\n  FOR(k, K) mask[use[k]] = 1 << k;\n\n  // [\u96C6\u5408\
    ][\u6700\u5F8C\u306E\u8FBA]\n  vv(F, dp, 1 << K, M);\n  for (auto&& e: H[s]) {\
    \ dp[mask[e.to]][e.id] = e.cost; }\n  FOR(L, 2, N + 1) {\n    vv(F, newdp, 1 <<\
    \ K, M);\n    FOR(s, 1 << K) {\n      vc<F> dp_v(N);\n      FOR(i, M) dp_v[H.edges[i].to]\
    \ += dp[s][i];\n      FOR(v, N) {\n        for (auto&& e: H[v]) {\n          int\
    \ t = s | mask[e.to];\n          if (mask[e.to] && s == t) continue;\n       \
    \   newdp[t][e.id] += dp_v[v] * e.cost;\n          // use \u4E0A\u306E\u70B9\u304B\
    \u3089\u623B\u308B\u306E\u3092\u7981\u6B62\u3059\u308B\n          if (mask[v])\
    \ { newdp[t][e.id] += dp[s][e.id ^ 1] * e.cost; }\n        }\n      }\n    }\n\
    \    swap(dp, newdp);\n    int full = (1 << K) - 1;\n    F sm = 0;\n    FOR(i,\
    \ M) {\n      if (H.edges[i].to == s) sm += dp[full][i];\n    }\n    if (sm !=\
    \ F(0)) return L;\n  }\n  return -1;\n}"
  dependsOn:
  - random/base.hpp
  - nt/GF2.hpp
  isVerificationFile: false
  path: graph/minimum_cycle_length_through_specified.hpp
  requiredBy: []
  timestamp: '2022-10-24 13:59:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1775.test.cpp
documentation_of: graph/minimum_cycle_length_through_specified.hpp
layout: document
redirect_from:
- /library/graph/minimum_cycle_length_through_specified.hpp
- /library/graph/minimum_cycle_length_through_specified.hpp.html
title: graph/minimum_cycle_length_through_specified.hpp
---
