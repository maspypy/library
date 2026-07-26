---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\n  static constexpr\
    \ u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL)\
    \ {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x)\
    \ : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\r\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\r\n  static constexpr u64 get_mod() { return\
    \ mod; }\r\n\r\n  modint61 &operator+=(const modint61 &a) {\r\n    val = ((val\
    \ += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val) >= mod) ? (val\
    \ + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const {\
    \ return modint61(val ? mod - val : u64(0)); }\r\n  modint61 &operator/=(const\
    \ modint61 &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n  bool operator<(const\
    \ modint61 &other) const { return val < other.val; }\r\n  bool operator==(const\
    \ modint61 &p) const { return val == p.val; }\r\n  bool operator!=(const modint61\
    \ &p) const { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll\
    \ a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\
    \n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\
    \nvoid rd(modint61 &x) {\r\n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val\
    \ < modint61::mod);\r\n}\r\n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n\
    #endif\n#line 2 \"string/deque_rolling_hash.hpp\"\n\n// \u7279\u306B pop \u306F\
    \u30C6\u30B9\u30C8\u3055\u308C\u3066\u306A\u3044\ntemplate <typename CHAR>\nstruct\
    \ Deque_Rolling_Hash {\n  using mint = modint61;\n  // prefix hash(n) = dat[n]+a*pow[n]\n\
    \  mint a;\n  mint base, ibase;\n  vc<mint> pow_table;\n  deque<CHAR> S;\n  deque<mint>\
    \ dat;\n  Deque_Rolling_Hash() : a(0) { dat.eb(0); }\n\n  void set_base(mint _base,\
    \ mint _ibase) {\n    base = _base, ibase = _ibase;\n    assert(base * ibase ==\
    \ 1);\n    pow_table = {mint(1), base};\n  }\n  int size() { return S.size();\
    \ }\n\n  CHAR pop_l() {\n    dat.pop_front();\n    CHAR ch = S.front();\n    S.pop_front();\n\
    \    a = a * base - ch;\n    return ch;\n  }\n  CHAR pop_r() {\n    dat.pop_back();\n\
    \    CHAR ch = S.back();\n    S.pop_back();\n    return ch;\n  }\n\n  void add_l(CHAR\
    \ ch) {\n    assert(len(pow_table) >= 2); // set base?\n    S.emplace_front(ch);\n\
    \    a = (a + ch) * ibase;\n    dat.emplace_front(-a);\n    assert(get(0, 1) !=\
    \ 0);\n  }\n  void add_r(CHAR ch) {\n    assert(len(pow_table) >= 2); // set base?\n\
    \    S.eb(ch), dat.eb(dat.back() * base + ch);\n    assert(get(0, 1) != 0);\n\
    \  }\n\n  mint get(int l, int r) {\n    assert(0 <= l && l <= r && r <= len(S));\n\
    \    return dat[r] - dat[l] * pow(r - l);\n  }\n\n  mint pow(int i) {\n    while\
    \ (i >= len(pow_table)) pow_table.eb(pow_table.back() * pow_table[1]);\n    return\
    \ pow_table[i];\n  }\n};\n"
  code: "#include \"mod/modint61.hpp\"\n\n// \u7279\u306B pop \u306F\u30C6\u30B9\u30C8\
    \u3055\u308C\u3066\u306A\u3044\ntemplate <typename CHAR>\nstruct Deque_Rolling_Hash\
    \ {\n  using mint = modint61;\n  // prefix hash(n) = dat[n]+a*pow[n]\n  mint a;\n\
    \  mint base, ibase;\n  vc<mint> pow_table;\n  deque<CHAR> S;\n  deque<mint> dat;\n\
    \  Deque_Rolling_Hash() : a(0) { dat.eb(0); }\n\n  void set_base(mint _base, mint\
    \ _ibase) {\n    base = _base, ibase = _ibase;\n    assert(base * ibase == 1);\n\
    \    pow_table = {mint(1), base};\n  }\n  int size() { return S.size(); }\n\n\
    \  CHAR pop_l() {\n    dat.pop_front();\n    CHAR ch = S.front();\n    S.pop_front();\n\
    \    a = a * base - ch;\n    return ch;\n  }\n  CHAR pop_r() {\n    dat.pop_back();\n\
    \    CHAR ch = S.back();\n    S.pop_back();\n    return ch;\n  }\n\n  void add_l(CHAR\
    \ ch) {\n    assert(len(pow_table) >= 2); // set base?\n    S.emplace_front(ch);\n\
    \    a = (a + ch) * ibase;\n    dat.emplace_front(-a);\n    assert(get(0, 1) !=\
    \ 0);\n  }\n  void add_r(CHAR ch) {\n    assert(len(pow_table) >= 2); // set base?\n\
    \    S.eb(ch), dat.eb(dat.back() * base + ch);\n    assert(get(0, 1) != 0);\n\
    \  }\n\n  mint get(int l, int r) {\n    assert(0 <= l && l <= r && r <= len(S));\n\
    \    return dat[r] - dat[l] * pow(r - l);\n  }\n\n  mint pow(int i) {\n    while\
    \ (i >= len(pow_table)) pow_table.eb(pow_table.back() * pow_table[1]);\n    return\
    \ pow_table[i];\n  }\n};\n"
  dependsOn:
  - mod/modint61.hpp
  isVerificationFile: false
  path: string/deque_rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-11-29 20:31:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/deque_rolling_hash.hpp
layout: document
redirect_from:
- /library/string/deque_rolling_hash.hpp
- /library/string/deque_rolling_hash.hpp.html
title: string/deque_rolling_hash.hpp
---
