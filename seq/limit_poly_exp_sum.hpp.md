---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint.hpp\"\ntemplate <u32 mod>\nstruct modint {\n\
    \  static constexpr bool is_modint = true;\n  u32 val;\n  constexpr modint(const\
    \ ll val = 0) noexcept\n      : val(val >= 0 ? val % mod : (mod - (-val) % mod)\
    \ % mod) {}\n  bool operator<(const modint &other) const {\n    return val < other.val;\n\
    \  } // To use std::map\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (u32)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(get_mod() - val); }\n  modint operator+(const modint &p) const\
    \ { return modint(*this) += p; }\n  modint operator-(const modint &p) const {\
    \ return modint(*this) -= p; }\n  modint operator*(const modint &p) const { return\
    \ modint(*this) *= p; }\n  modint operator/(const modint &p) const { return modint(*this)\
    \ /= p; }\n  bool operator==(const modint &p) const { return val == p.val; }\n\
    \  bool operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(int64_t n) const {\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n\nstruct ArbitraryModInt {\n  static constexpr bool is_modint\
    \ = true;\n  u32 val;\n  ArbitraryModInt() : val(0) {}\n  ArbitraryModInt(int64_t\
    \ y)\n      : val(y >= 0 ? y % get_mod()\n                   : (get_mod() - (-y)\
    \ % get_mod()) % get_mod()) {}\n  bool operator<(const ArbitraryModInt &other)\
    \ const {\n    return val < other.val;\n  } // To use std::map<ArbitraryModInt,\
    \ T>\n  static u32 &get_mod() {\n    static u32 mod = 0;\n    return mod;\n  }\n\
    \  static void set_mod(int md) { get_mod() = md; }\n  ArbitraryModInt &operator+=(const\
    \ ArbitraryModInt &p) {\n    if ((val += p.val) >= get_mod()) val -= get_mod();\n\
    \    return *this;\n  }\n  ArbitraryModInt &operator-=(const ArbitraryModInt &p)\
    \ {\n    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {\n   \
    \ unsigned long long a = (unsigned long long)val * p.val;\n    unsigned xh = (unsigned)(a\
    \ >> 32), xl = (unsigned)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d), \"\
    =d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return *this;\n\
    \  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-() const {\
    \ return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n};\n\ntemplate <typename mint>\ntuple<mint, mint,\
    \ mint> get_factorial_data(int n) {\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> fact = {1, 1};\n  static\
    \ vector<mint> fact_inv = {1, 1};\n  static vector<mint> inv = {0, 1};\n  while\
    \ (len(fact) <= n) {\n    int k = len(fact);\n    fact.eb(fact[k - 1] * mint(k));\n\
    \    auto q = ceil(mod, k);\n    int r = k * q - mod;\n    inv.eb(inv[r] * mint(q));\n\
    \    fact_inv.eb(fact_inv[k - 1] * inv[k]);\n  }\n  return {fact[n], fact_inv[n],\
    \ inv[n]};\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static constexpr\
    \ int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return 0;\n \
    \ return get<0>(get_factorial_data<mint>(n));\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static constexpr int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  return get<1>(get_factorial_data<mint>(n));\n}\n\ntemplate\
    \ <typename mint>\nmint inv(int n) {\n  static constexpr int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  return get<2>(get_factorial_data<mint>(n));\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C(ll n, ll k) {\n  assert(n\
    \ >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n\
    \  FOR(i, k) { x *= mint(n - i); }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\
    \ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n\
    \ >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    using amint = ArbitraryModInt;\n#line 2 \"seq/limit_poly_exp_sum.hpp\"\ntemplate\
    \ <typename mint>\r\nmint limit_poly_exp_sum(vc<mint> a, mint r) {\r\n  /*\r\n\
    \  a[i] = (prefix sum of r^i * (polynomial of i)) \u3068\u306A\u3063\u3066\u3044\
    \u308B\u3082\u306E\u306E\u6975\u9650\r\n  fps \u3067\u306F (1-rx)^d(1-x) \u306E\
    \u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\u5408\u3068\u3044\u3046\u3053\
    \u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d + c / (1-x) \u3068\u3057\u3066\
    \u3001c \u304C\u7B54\u3067\u3042\u308B\r\n  */\r\n  mint c = 0;\r\n  int d = len(a)\
    \ - 1;\r\n  mint p = 1;\r\n  FOR(i, d + 1) {\r\n    c += a[d - i] * p * C<mint>(d,\
    \ i);\r\n    p *= -r;\r\n  }\r\n  c /= (mint(1) - r).pow(d);\r\n  return c;\r\n\
    }\r\n"
  code: "#include \"mod/modint.hpp\"\r\ntemplate <typename mint>\r\nmint limit_poly_exp_sum(vc<mint>\
    \ a, mint r) {\r\n  /*\r\n  a[i] = (prefix sum of r^i * (polynomial of i)) \u3068\
    \u306A\u3063\u3066\u3044\u308B\u3082\u306E\u306E\u6975\u9650\r\n  fps \u3067\u306F\
    \ (1-rx)^d(1-x) \u306E\u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\u5408\u3068\
    \u3044\u3046\u3053\u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d + c / (1-x)\
    \ \u3068\u3057\u3066\u3001c \u304C\u7B54\u3067\u3042\u308B\r\n  */\r\n  mint c\
    \ = 0;\r\n  int d = len(a) - 1;\r\n  mint p = 1;\r\n  FOR(i, d + 1) {\r\n    c\
    \ += a[d - i] * p * C<mint>(d, i);\r\n    p *= -r;\r\n  }\r\n  c /= (mint(1) -\
    \ r).pow(d);\r\n  return c;\r\n}\r\n"
  dependsOn:
  - mod/modint.hpp
  isVerificationFile: false
  path: seq/limit_poly_exp_sum.hpp
  requiredBy: []
  timestamp: '2022-04-22 16:55:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly_limit.test.cpp
documentation_of: seq/limit_poly_exp_sum.hpp
layout: document
redirect_from:
- /library/seq/limit_poly_exp_sum.hpp
- /library/seq/limit_poly_exp_sum.hpp.html
title: seq/limit_poly_exp_sum.hpp
---
