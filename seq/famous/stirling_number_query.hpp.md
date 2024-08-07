---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_mod_p_1.test.cpp
    title: test/library_checker/math/stirling_mod_p_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_mod_p_2.test.cpp
    title: test/library_checker/math/stirling_mod_p_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\
    \u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename\
    \ U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n  inline static\
    \ U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\n  static\
    \ void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n  \
    \  m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n    r = -r;\n\
    \    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b)\
    \ * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n  Mongomery_modint(U1\
    \ x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n \
    \   return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x\
    \ += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint &operator-=(mint\
    \ y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint\
    \ y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint\
    \ y) const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32 = Mongomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64 = Mongomery_modint<id,\
    \ u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const u64 x) {\r\
    \n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return\
    \ true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return\
    \ false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> lowbit(x\
    \ - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\n\r\n  mint::set_mod(x);\r\
    \n  const mint one(u64(1)), minus_one(x - 1);\r\n  auto ok = [&](u64 a) -> bool\
    \ {\r\n    auto y = mint(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one &&\
    \ y != minus_one && t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one &&\
    \ t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if (x < (u64(1) <<\
    \ 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (!ok(a)) return false;\r\n\
    \  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\
    \ {\r\n      if (!ok(a)) return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n\
    #line 2 \"seq/famous/stirling_number_query.hpp\"\n\n// O(p^2) \u6642\u9593\u306E\
    \u524D\u8A08\u7B97\u306E\u3082\u3068\u3001O(log n) \u6642\u9593\nstruct Stirling_Number_Query\
    \ {\n  const int p;\n  vvc<int> MEMO_C;\n  vvc<int> MEMO_S1;\n  vvc<int> MEMO_S2;\n\
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
    \    if ((i + a) % 2 == 1 && res) { res = p - res; }\n    return res;\n  }\n\n\
    \  int S2(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    if (n == 0) return\
    \ 1;\n    ll i = k / p;\n    int j = k % p;\n    if (n < i) return 0;\n    ll\
    \ a = (n - i) / (p - 1);\n    int b = (n - i) - (p - 1) * a;\n    if (b == 0)\
    \ {\n      b += p - 1;\n      a -= 1;\n    }\n    if (a < 0 || j > b) return 0;\n\
    \    if (b < p - 1) { return C(a, i) * MEMO_S2[b][j] % p; }\n    if (j == 0) return\
    \ C(a, i - 1);\n    return C(a, i) * MEMO_S2[p - 1][j] % p;\n  }\n\nprivate:\n\
    \  void build_C() {\n    auto& A = MEMO_C;\n    A.resize(p);\n    A[0] = {1};\n\
    \    FOR(i, 1, p) {\n      A[i] = A[i - 1];\n      A[i].emplace_back(0);\n   \
    \   FOR(j, 1, i + 1) {\n        A[i][j] += A[i - 1][j - 1];\n        if (A[i][j]\
    \ >= p) A[i][j] -= p;\n      }\n    }\n  }\n\n  void build_S1() {\n    auto& A\
    \ = MEMO_S1;\n    A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i\
    \ + 1, 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n\
    \        if (j < i) A[i][j] += A[i - 1][j] * (p - i + 1);\n        A[i][j] %=\
    \ p;\n      }\n    }\n  }\n\n  void build_S2() {\n    auto& A = MEMO_S2;\n   \
    \ A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i + 1,\
    \ 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n   \
    \     if (j < i) A[i][j] += A[i - 1][j] * j;\n        A[i][j] %= p;\n      }\n\
    \    }\n  }\n};\n"
  code: "#include \"nt/primetest.hpp\"\n\n// O(p^2) \u6642\u9593\u306E\u524D\u8A08\
    \u7B97\u306E\u3082\u3068\u3001O(log n) \u6642\u9593\nstruct Stirling_Number_Query\
    \ {\n  const int p;\n  vvc<int> MEMO_C;\n  vvc<int> MEMO_S1;\n  vvc<int> MEMO_S2;\n\
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
    \    if ((i + a) % 2 == 1 && res) { res = p - res; }\n    return res;\n  }\n\n\
    \  int S2(ll n, ll k) {\n    if (k < 0 || k > n) return 0;\n    if (n == 0) return\
    \ 1;\n    ll i = k / p;\n    int j = k % p;\n    if (n < i) return 0;\n    ll\
    \ a = (n - i) / (p - 1);\n    int b = (n - i) - (p - 1) * a;\n    if (b == 0)\
    \ {\n      b += p - 1;\n      a -= 1;\n    }\n    if (a < 0 || j > b) return 0;\n\
    \    if (b < p - 1) { return C(a, i) * MEMO_S2[b][j] % p; }\n    if (j == 0) return\
    \ C(a, i - 1);\n    return C(a, i) * MEMO_S2[p - 1][j] % p;\n  }\n\nprivate:\n\
    \  void build_C() {\n    auto& A = MEMO_C;\n    A.resize(p);\n    A[0] = {1};\n\
    \    FOR(i, 1, p) {\n      A[i] = A[i - 1];\n      A[i].emplace_back(0);\n   \
    \   FOR(j, 1, i + 1) {\n        A[i][j] += A[i - 1][j - 1];\n        if (A[i][j]\
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
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  isVerificationFile: false
  path: seq/famous/stirling_number_query.hpp
  requiredBy: []
  timestamp: '2023-11-02 05:00:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/stirling_mod_p_2.test.cpp
  - test/library_checker/math/stirling_mod_p_1.test.cpp
documentation_of: seq/famous/stirling_number_query.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_query.hpp
- /library/seq/famous/stirling_number_query.hpp.html
title: seq/famous/stirling_number_query.hpp
---
