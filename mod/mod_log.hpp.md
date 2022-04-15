---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':x:'
    path: other/discrete_log.hpp
    title: other/discrete_log.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
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
    }\n\ntemplate <typename mint>\nmint C(ll n, ll k, bool large = false) {\n  assert(n\
    \ >= 0);\n  if (k < 0 || n < k) return 0;\n  if (!large) return fact<mint>(n)\
    \ * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n  k = min(k, n - k);\n  mint x(1);\n\
    \  FOR(i, k) { x *= mint(n - i); }\n  x *= fact_inv<mint>(k);\n  return x;\n}\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    using amint = ArbitraryModInt;\n#line 1 \"other/discrete_log.hpp\"\n// log_a b\
    \ \u306E\u8A08\u7B97\r\n// \u300C*\u300D \u304C\u5B9A\u7FA9\u3055\u308C\u305F\u30AF\
    \u30E9\u30B9\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H \u3092\u6301\u305F\u305B\
    \u308B\r\n// lb \u4EE5\u4E0A\u306E\u89E3\u3092\u304B\u3048\u3059\r\ntemplate <typename\
    \ X>\r\nll discrete_log(X a, X b, ll LIM, function<ll(X)> H, int lb = 0) {\r\n\
    \  {\r\n    int n = lb;\r\n    X p = a;\r\n    while (n) {\r\n      if (n & 1)\
    \ b /= p;\r\n      p *= p;\r\n      n /= 2;\r\n    }\r\n  }\r\n\r\n  ll K = 1;\r\
    \n  while (K * K < LIM) ++K;\r\n\r\n  unordered_map<ll, int> MP;\r\n  MP.reserve(K\
    \ + 1);\r\n  X p = 1;\r\n  FOR(k, K + 1) {\r\n    auto key = H(p);\r\n    if (!MP.count(key))\
    \ MP[key] = k;\r\n    if (k != K) p = p * a;\r\n  }\r\n  p = X(1) / p;\r\n  FOR(k,\
    \ K + 1) {\r\n    auto key = H(b);\r\n    if (MP.count(key)) return k * K + MP[key]\
    \ + lb;\r\n    b *= p;\r\n  }\r\n  return -1;\r\n}\r\n#line 3 \"mod/mod_log.hpp\"\
    \n\r\nint mod_log(int mod, ll a, ll b) {\r\n  a = divmod(a, mod).se;\r\n  b =\
    \ divmod(b, mod).se;\r\n  // \u307E\u305A\u7FA4\u306B\u5E30\u7740\u3059\u308B\u3002\
    \u5C0F\u3055\u3044\u5834\u5408\u306F\u8ABF\u3079\u308B\r\n  ll p = 1 % mod;\r\n\
    \  FOR(k, 32) {\r\n    if (p == b) return k;\r\n    p = p * a % mod;\r\n  }\r\n\
    \  if (a == 0 || b == 0) return -1;\r\n  ll g = gcd(mod, p);\r\n  if (b % g !=\
    \ 0) return -1;\r\n  mod /= g;\r\n  a %= mod, b %= mod;\r\n  if (gcd(b, mod) >\
    \ 1) return -1;\r\n  // \u7FA4\u306B\u5E30\u7740\u3055\u308C\u305F\r\n  amint::set_mod(mod);\r\
    \n  return discrete_log<amint>(\r\n      amint(a), amint(b), mod, [](auto x) {\
    \ return x.val; }, 32);\r\n}\r\n"
  code: "#include \"mod/modint.hpp\"\r\n#include \"other/discrete_log.hpp\"\r\n\r\n\
    int mod_log(int mod, ll a, ll b) {\r\n  a = divmod(a, mod).se;\r\n  b = divmod(b,\
    \ mod).se;\r\n  // \u307E\u305A\u7FA4\u306B\u5E30\u7740\u3059\u308B\u3002\u5C0F\
    \u3055\u3044\u5834\u5408\u306F\u8ABF\u3079\u308B\r\n  ll p = 1 % mod;\r\n  FOR(k,\
    \ 32) {\r\n    if (p == b) return k;\r\n    p = p * a % mod;\r\n  }\r\n  if (a\
    \ == 0 || b == 0) return -1;\r\n  ll g = gcd(mod, p);\r\n  if (b % g != 0) return\
    \ -1;\r\n  mod /= g;\r\n  a %= mod, b %= mod;\r\n  if (gcd(b, mod) > 1) return\
    \ -1;\r\n  // \u7FA4\u306B\u5E30\u7740\u3055\u308C\u305F\r\n  amint::set_mod(mod);\r\
    \n  return discrete_log<amint>(\r\n      amint(a), amint(b), mod, [](auto x) {\
    \ return x.val; }, 32);\r\n}\r\n"
  dependsOn:
  - mod/modint.hpp
  - other/discrete_log.hpp
  isVerificationFile: false
  path: mod/mod_log.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: mod/mod_log.hpp
layout: document
redirect_from:
- /library/mod/mod_log.hpp
- /library/mod/mod_log.hpp.html
title: mod/mod_log.hpp
---
