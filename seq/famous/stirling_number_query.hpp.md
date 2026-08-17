---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/is_prime.hpp
    title: nt/is_prime.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/enumerative_combinatorics/stirling_mod_p_1.test.cpp
    title: test/2_library_checker/enumerative_combinatorics/stirling_mod_p_1.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/enumerative_combinatorics/stirling_mod_p_2.test.cpp
    title: test/2_library_checker/enumerative_combinatorics/stirling_mod_p_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 1 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
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
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/is_prime.hpp\"\n\nbool is_prime(const\
    \ u64 x) {\n  assert(x < u64(1) << 62);\n  if (x == 2 or x == 3 or x == 5 or x\
    \ == 7) return true;\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 ==\
    \ 0) return false;\n  if (x < 121) return x > 1;\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\n\n  using mint = Mongomery_modint_64<202311020>;\n\n  mint::set_mod(x);\n\
    \  const mint one(u64(1)), minus_one(x - 1);\n  auto ok = [&](u64 a) -> bool {\n\
    \    auto y = mint(a).pow(d);\n    u64 t = d;\n    while (y != one && y != minus_one\
    \ && t != x - 1) y *= y, t <<= 1;\n    if (y != minus_one && t % 2 == 0) return\
    \ false;\n    return true;\n  };\n  if (x < (u64(1) << 32)) {\n    for (u64 a\
    \ : {2, 7, 61})\n      if (!ok(a)) return false;\n  } else {\n    for (u64 a :\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n      if (!ok(a)) return\
    \ false;\n    }\n  }\n  return true;\n}\n#line 2 \"seq/famous/stirling_number_query.hpp\"\
    \n\n// O(p^2) \u6642\u9593\u306E\u524D\u8A08\u7B97\u306E\u3082\u3068\u3001O(log\
    \ n) \u6642\u9593\nstruct Stirling_Number_Query {\n  const int p;\n  vvc<int>\
    \ MEMO_C;\n  vvc<int> MEMO_S1;\n  vvc<int> MEMO_S2;\n\n  Stirling_Number_Query(int\
    \ p, bool first_kind = true, bool second_kind = true)\n      : p(p) {\n    assert(primetest(p));\n\
    \    assert(p <= (1 << 15));\n    build_C();\n    if (first_kind) build_S1();\n\
    \    if (second_kind) build_S2();\n  }\n\n  int C(ll n, ll k) {\n    if (k < 0\
    \ || k > n) return 0;\n    int res = 1;\n    while (n) {\n      int i = n % p,\
    \ j = k % p;\n      if (j > i) return 0;\n      res = res * MEMO_C[i][j] % p;\n\
    \      n /= p;\n      k /= p;\n    }\n    return res;\n  }\n\n  int S1(ll n, ll\
    \ k) {\n    if (k < 0 || k > n) return 0;\n    ll i = n / p;\n    int j = n %\
    \ p;\n    if (i > k) return 0;\n    ll a = (k - i) / (p - 1);\n    int b = (k\
    \ - i) % (p - 1);\n    if (b == 0 && j > 0) {\n      b += (p - 1);\n      a -=\
    \ 1;\n    }\n    if (a < 0 || i < a || b > j) return 0;\n    int x = C(i, a);\n\
    \    int y = MEMO_S1[j][b];\n    int res = x * y % p;\n    if ((i + a) % 2 ==\
    \ 1 && res) {\n      res = p - res;\n    }\n    return res;\n  }\n\n  int S2(ll\
    \ n, ll k) {\n    if (k < 0 || k > n) return 0;\n    if (n == 0) return 1;\n \
    \   ll i = k / p;\n    int j = k % p;\n    if (n < i) return 0;\n    ll a = (n\
    \ - i) / (p - 1);\n    int b = (n - i) - (p - 1) * a;\n    if (b == 0) {\n   \
    \   b += p - 1;\n      a -= 1;\n    }\n    if (a < 0 || j > b) return 0;\n   \
    \ if (b < p - 1) {\n      return C(a, i) * MEMO_S2[b][j] % p;\n    }\n    if (j\
    \ == 0) return C(a, i - 1);\n    return C(a, i) * MEMO_S2[p - 1][j] % p;\n  }\n\
    \n private:\n  void build_C() {\n    auto& A = MEMO_C;\n    A.resize(p);\n   \
    \ A[0] = {1};\n    FOR(i, 1, p) {\n      A[i] = A[i - 1];\n      A[i].emplace_back(0);\n\
    \      FOR(j, 1, i + 1) {\n        A[i][j] += A[i - 1][j - 1];\n        if (A[i][j]\
    \ >= p) A[i][j] -= p;\n      }\n    }\n  }\n\n  void build_S1() {\n    auto& A\
    \ = MEMO_S1;\n    A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i\
    \ + 1, 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n\
    \        if (j < i) A[i][j] += A[i - 1][j] * (p - i + 1);\n        A[i][j] %=\
    \ p;\n      }\n    }\n  }\n\n  void build_S2() {\n    auto& A = MEMO_S2;\n   \
    \ A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i + 1,\
    \ 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n   \
    \     if (j < i) A[i][j] += A[i - 1][j] * j;\n        A[i][j] %= p;\n      }\n\
    \    }\n  }\n};\n"
  code: "#include \"nt/is_prime.hpp\"\n\n// O(p^2) \u6642\u9593\u306E\u524D\u8A08\u7B97\
    \u306E\u3082\u3068\u3001O(log n) \u6642\u9593\nstruct Stirling_Number_Query {\n\
    \  const int p;\n  vvc<int> MEMO_C;\n  vvc<int> MEMO_S1;\n  vvc<int> MEMO_S2;\n\
    \n  Stirling_Number_Query(int p, bool first_kind = true, bool second_kind = true)\n\
    \      : p(p) {\n    assert(primetest(p));\n    assert(p <= (1 << 15));\n    build_C();\n\
    \    if (first_kind) build_S1();\n    if (second_kind) build_S2();\n  }\n\n  int\
    \ C(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    int res = 1;\n    while\
    \ (n) {\n      int i = n % p, j = k % p;\n      if (j > i) return 0;\n      res\
    \ = res * MEMO_C[i][j] % p;\n      n /= p;\n      k /= p;\n    }\n    return res;\n\
    \  }\n\n  int S1(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    ll i =\
    \ n / p;\n    int j = n % p;\n    if (i > k) return 0;\n    ll a = (k - i) / (p\
    \ - 1);\n    int b = (k - i) % (p - 1);\n    if (b == 0 && j > 0) {\n      b +=\
    \ (p - 1);\n      a -= 1;\n    }\n    if (a < 0 || i < a || b > j) return 0;\n\
    \    int x = C(i, a);\n    int y = MEMO_S1[j][b];\n    int res = x * y % p;\n\
    \    if ((i + a) % 2 == 1 && res) {\n      res = p - res;\n    }\n    return res;\n\
    \  }\n\n  int S2(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    if (n ==\
    \ 0) return 1;\n    ll i = k / p;\n    int j = k % p;\n    if (n < i) return 0;\n\
    \    ll a = (n - i) / (p - 1);\n    int b = (n - i) - (p - 1) * a;\n    if (b\
    \ == 0) {\n      b += p - 1;\n      a -= 1;\n    }\n    if (a < 0 || j > b) return\
    \ 0;\n    if (b < p - 1) {\n      return C(a, i) * MEMO_S2[b][j] % p;\n    }\n\
    \    if (j == 0) return C(a, i - 1);\n    return C(a, i) * MEMO_S2[p - 1][j] %\
    \ p;\n  }\n\n private:\n  void build_C() {\n    auto& A = MEMO_C;\n    A.resize(p);\n\
    \    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i] = A[i - 1];\n      A[i].emplace_back(0);\n\
    \      FOR(j, 1, i + 1) {\n        A[i][j] += A[i - 1][j - 1];\n        if (A[i][j]\
    \ >= p) A[i][j] -= p;\n      }\n    }\n  }\n\n  void build_S1() {\n    auto& A\
    \ = MEMO_S1;\n    A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i\
    \ + 1, 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n\
    \        if (j < i) A[i][j] += A[i - 1][j] * (p - i + 1);\n        A[i][j] %=\
    \ p;\n      }\n    }\n  }\n\n  void build_S2() {\n    auto& A = MEMO_S2;\n   \
    \ A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i + 1,\
    \ 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n   \
    \     if (j < i) A[i][j] += A[i - 1][j] * j;\n        A[i][j] %= p;\n      }\n\
    \    }\n  }\n};"
  dependsOn:
  - nt/is_prime.hpp
  - other/bit.hpp
  - mod/mongomery_modint.hpp
  isVerificationFile: false
  path: seq/famous/stirling_number_query.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:53:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/enumerative_combinatorics/stirling_mod_p_1.test.cpp
  - test/2_library_checker/enumerative_combinatorics/stirling_mod_p_2.test.cpp
documentation_of: seq/famous/stirling_number_query.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_query.hpp
- /library/seq/famous/stirling_number_query.hpp.html
title: seq/famous/stirling_number_query.hpp
---
