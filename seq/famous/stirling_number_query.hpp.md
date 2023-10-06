---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/stirling_mod_p_1.test.cpp
    title: test/library_checker/math/stirling_mod_p_1.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/stirling_mod_p_2.test.cpp
    title: test/library_checker/math/stirling_mod_p_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
    \ u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void\
    \ set_mod(u64 m) {\r\n    assert((m & 1) == 1);\r\n    m64::m = m;\r\n    n2 =\
    \ -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\n    r = -r;\r\
    \n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128 b) { return (b\
    \ + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() : x(0) {}\r\n  m64(u64\
    \ x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\n    u64 y = reduce(x);\r\
    \n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64 y) {\r\n    x\
    \ += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return\
    \ *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n    x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator*=(m64\
    \ y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\n  }\r\n  m64\
    \ operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64 y)\
    \ const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return m64(*this)\
    \ *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m ? x - m :\
    \ x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64 y) const {\
    \ return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64 y = 1, z\
    \ = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *= z;\r\n \
    \   return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\n  using\
    \ u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\
    \n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n\
    \  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
    \ - 1);\r\n  m64::set_mod(x);\r\n  const m64 one(1), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while\
    \ (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;\r\n    if (y !=\
    \ minus_one and t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if\
    \ (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (not ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (not ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 2 \"seq/famous/stirling_number_query.hpp\"\
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
    \ 1 && res) { res = p - res; }\n    return res;\n  }\n\n  int S2(ll n, ll k) {\n\
    \    if (k < 0 || k > n) return 0;\n    if (n == 0) return 1;\n    ll i = k /\
    \ p;\n    int j = k % p;\n    if (n < i) return 0;\n    ll a = (n - i) / (p -\
    \ 1);\n    int b = (n - i) - (p - 1) * a;\n    if (b == 0) {\n      b += p - 1;\n\
    \      a -= 1;\n    }\n    if (a < 0 || j > b) return 0;\n    if (b < p - 1) {\
    \ return C(a, i) * MEMO_S2[b][j] % p; }\n    if (j == 0) return C(a, i - 1);\n\
    \    return C(a, i) * MEMO_S2[p - 1][j] % p;\n  }\n\nprivate:\n  void build_C()\
    \ {\n    auto& A = MEMO_C;\n    A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p)\
    \ {\n      A[i] = A[i - 1];\n      A[i].emplace_back(0);\n      FOR(j, 1, i +\
    \ 1) {\n        A[i][j] += A[i - 1][j - 1];\n        if (A[i][j] >= p) A[i][j]\
    \ -= p;\n      }\n    }\n  }\n\n  void build_S1() {\n    auto& A = MEMO_S1;\n\
    \    A.resize(p);\n    A[0] = {1};\n    FOR(i, 1, p) {\n      A[i].assign(i +\
    \ 1, 0);\n      FOR(j, i + 1) {\n        if (j) A[i][j] += A[i - 1][j - 1];\n\
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
  isVerificationFile: false
  path: seq/famous/stirling_number_query.hpp
  requiredBy: []
  timestamp: '2023-01-09 23:28:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
