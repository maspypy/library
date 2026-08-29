---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_biconnected.hpp
    title: graph/count/count_labeled_biconnected.hpp
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_bridgeless.hpp
    title: graph/count/count_labeled_bridgeless.hpp
  - icon: ':warning:'
    path: poly/2d/compositional_inverse_2d.hpp
    title: poly/2d/compositional_inverse_2d.hpp
  - icon: ':heavy_check_mark:'
    path: poly/compositional_inverse.hpp
    title: poly/compositional_inverse.hpp
  - icon: ':heavy_check_mark:'
    path: poly/schroder.hpp
    title: poly/schroder.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/compositional_inverset.test.cpp
    title: test/1_mytest/compositional_inverset.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_labeled_biconnected.test.cpp
    title: test/1_mytest/count_labeled_biconnected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_labeled_bridgeless.test.cpp
    title: test/1_mytest/count_labeled_bridgeless.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/power_projection.test.cpp
    title: test/1_mytest/power_projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/compositional_inverse.test.cpp
    title: test/2_library_checker/polynomial/compositional_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/compositional_inverse_dmint.test.cpp
    title: test/2_library_checker/polynomial/compositional_inverse_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/3619.test.cpp
    title: test/3_yukicoder/3619.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/3621.test.cpp
    title: test/3_yukicoder/3621.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/power_projection.hpp\"\n\n#line 1 \"mod/modint_common.hpp\"\
    \n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 3 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (len(dat) <= n)\
    \ {\n    int now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n  \
    \  dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  if\
    \ (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int now = len(dat);\n \
    \   int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n    dat[m - 1]\
    \ = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i] = dat[i + 1]\
    \ * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/modint_common.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 3 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (len(dat) <= n)\
    \ {\n    int now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n  \
    \  dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  if\
    \ (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int now = len(dat);\n \
    \   int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n    dat[m - 1]\
    \ = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i] = dat[i + 1]\
    \ * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
    \ u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n\
    \  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n\
    \  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0,\
    \ u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0\
    \ + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) *\
    \ x2 % p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32\
    \ p0, u32 p1, u32 p2, u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0\
    \ < p1 && p1 < p2 && p2 < p3);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3\
    \ * p2 % p3, p3 - 2, p3);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c\
    \ = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 %\
    \ p2 + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c\
    \ = (a3 - ans_2 % p3 + p3) * x3 % p3;\n  return T(ans_2) + T(c) * T(p01) * T(p2);\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64\
    \ a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0 < p1 && p1 < p2 &&\
    \ p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4 = mod_pow_constexpr(u64(p0)\
    \ * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0)\
    \ * p1;\n  static constexpr u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3\
    \ - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c *\
    \ p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;\n  return\
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"poly/ntt.hpp\"\n\ntemplate\
    \ <class mint>\nvoid ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n\
    \  const int rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n\
    \  static array<mint, 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n\
    \  static array<mint, 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <=\
    \ (1 << max(0, rank2)));\n\n  static bool prepared = 0;\n  if (!prepared) {\n\
    \    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n    iroot[rank2] =\
    \ mint(1) / root[rank2];\n    FOR_R(i, rank2) {\n      root[i] = root[i + 1] *\
    \ root[i + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n    }\n    mint\
    \ prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 2; i++) {\n      rate2[i]\
    \ = root[i + 2] * prod;\n      irate2[i] = iroot[i + 2] * iprod;\n      prod *=\
    \ iroot[i + 2];\n      iprod *= root[i + 2];\n    }\n    prod = 1, iprod = 1;\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\n      rate3[i] = root[i + 3] * prod;\n\
    \      irate3[i] = iroot[i + 3] * iprod;\n      prod *= iroot[i + 3];\n      iprod\
    \ *= root[i + 3];\n    }\n  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n\
    \  assert(n == 1 << h);\n  if (!inverse) {\n    int len = 0;\n    while (len <\
    \ h) {\n      if (h - len == 1) {\n        int p = 1 << (h - len - 1);\n     \
    \   mint rot = 1;\n        FOR(s, 1 << len) {\n          int offset = s << (h\
    \ - len);\n          FOR(i, p) {\n            auto l = a[i + offset];\n      \
    \      auto r = a[i + offset + p] * rot;\n            a[i + offset] = l + r;\n\
    \            a[i + offset + p] = l - r;\n          }\n          rot *= rate2[topbit(~s\
    \ & -~s)];\n        }\n        len++;\n      } else {\n        int p = 1 << (h\
    \ - len - 2);\n        mint rot = 1, imag = root[2];\n        for (int s = 0;\
    \ s < (1 << len); s++) {\n          mint rot2 = rot * rot;\n          mint rot3\
    \ = rot2 * rot;\n          int offset = s << (h - len);\n          for (int i\
    \ = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n            u64\
    \ a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n\
    \            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\n           \
    \ u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag\
    \ = (a1 + mod2 - a3) % mod * imag.val;\n            u64 na2 = mod2 - a2;\n   \
    \         a[i + offset] = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p]\
    \ = a0 + a2 + (2 * mod2 - (a1 + a3));\n            a[i + offset + 2 * p] = a0\
    \ + na2 + a1na3imag;\n            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n\
    \          }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len\
    \ += 2;\n      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n\
    \    FOR(i, len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n     \
    \ if (len == 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n \
    \       FOR(s, 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n\
    \          FOR(i, p) {\n            u64 l = a[i + offset].val;\n            u64\
    \ r = a[i + offset + p].val;\n            a[i + offset] = l + r;\n           \
    \ a[i + offset + p] = (mod + l - r) * irot.val;\n          }\n          irot *=\
    \ irate2[topbit(~s & -~s)];\n        }\n        len--;\n      } else {\n     \
    \   int p = 1 << (h - len);\n        mint irot = 1, iimag = iroot[2];\n      \
    \  FOR(s, (1 << (len - 2))) {\n          mint irot2 = irot * irot;\n         \
    \ mint irot3 = irot2 * irot;\n          int offset = s << (h - len + 2);\n   \
    \       for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 *\
    \ p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2\
    \ = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n\
    \            u64 x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset]\
    \ = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x)\
    \ * irot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3)\
    \ * irot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) *\
    \ irot3.val;\n          }\n          irot *= irate3[topbit(~s & -~s)];\n     \
    \   }\n        len -= 2;\n      }\n    }\n  }\n}\n#line 7 \"poly/convolution.hpp\"\
    \n\ntemplate <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\n  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n\
    \  int n = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n +\
    \ m - 1) sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\
    \u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\
    \u308B\u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  static_assert(!is_same_v<mint, modint<2>>, \"use Bit_Array version for\
    \ mod 2\");\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  if (mint::can_ntt())\
    \ {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a, b);\n    return\
    \ convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return convolution_karatsuba<mint>(a,\
    \ b);\n  return convolution_garner(a, b);\n}\n#line 4 \"poly/power_projection.hpp\"\
    \n\ntemplate <typename mint>\nvc<mint> power_projection_0_ntt(vc<mint> wt, vc<mint>\
    \ f, int m) {\n  assert(len(f) == len(wt) && f[0] == mint(0));\n\n  int n = 1;\n\
    \  while (n < len(f)) n *= 2;\n\n  for (auto& x : f) x = -x;\n  f.resize(n), wt.resize(n);\n\
    \  reverse(all(wt));\n  vc<mint>&P = wt, &Q = f;\n  P.resize(4 * n), Q.resize(4\
    \ * n);\n\n  vc<mint> W(n);\n  {\n    // bit reverse order\n    vc<int> btr(n);\n\
    \    int log = topbit(n);\n    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i &\
    \ 1) << (log - 1)); }\n    int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n\
    \    mint dw = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for\
    \ (auto& i : btr) {\n      W[i] = w, w *= dw;\n    }\n  }\n\n  int k = 1;\n  while\
    \ (n > 1) {\n    /*\n    FFT step\n    04.. -> 048c\n    15.. -> 159d\n    ....\
    \ -> 26ae\n    .... -> 37bf\n    */\n\n    auto doubling_y = [&](vc<mint>& A,\
    \ int l, int r) -> void {\n      mint z = W[k / 2].inverse();\n      vc<mint>\
    \ f(k);\n      FOR(i, l, r) {\n        FOR(j, k) f[j] = A[2 * n * j + i];\n  \
    \      ntt(f, 1);\n        mint r = 1;\n        FOR(j, 1, k) r *= z, f[j] *= r;\n\
    \        ntt(f, 0);\n        FOR(j, k) A[2 * n * (k + j) + i] = f[j];\n      }\n\
    \    };\n\n    auto FFT_x = [&](vc<mint>& A, int l, int r) -> void {\n      vc<mint>\
    \ f(2 * n);\n      FOR(j, l, r) {\n        move(A.begin() + 2 * n * j, A.begin()\
    \ + 2 * n * (j + 1), f.begin());\n        ntt(f, 0);\n        move(all(f), A.begin()\
    \ + 2 * n * j);\n      }\n    };\n\n    if (n <= k) {\n      doubling_y(P, 0,\
    \ n), doubling_y(Q, 1, n);\n      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);\n  \
    \  } else {\n      FFT_x(P, 0, k), FFT_x(Q, 0, k);\n      doubling_y(P, 0, 2 *\
    \ n), doubling_y(Q, 0, 2 * n);\n    }\n    FOR(i, 2 * n * k) Q[i] += 1;\n    FOR(i,\
    \ 2 * n * k, 4 * n * k) Q[i] -= 1;\n\n    /*\n    048c -> 0248????\n    159d ->\
    \ ....????\n    26ae\n    37bf\n    */\n    vc<mint> F(2 * n), G(2 * n), f(n),\
    \ g(n);\n    FOR(j, 2 * k) {\n      move(P.begin() + 2 * n * j, P.begin() + 2\
    \ * n * j + 2 * n, F.begin());\n      move(Q.begin() + 2 * n * j, Q.begin() +\
    \ 2 * n * j + 2 * n, G.begin());\n      FOR(i, n) {\n        f[i] = W[i] * (F[2\
    \ * i] * G[2 * i + 1] - F[2 * i + 1] * G[2 * i]);\n        g[i] = G[2 * i] * G[2\
    \ * i + 1];\n      }\n      ntt(f, 1), ntt(g, 1);\n      fill(f.begin() + n /\
    \ 2, f.end(), mint(0));\n      fill(g.begin() + n / 2, g.end(), mint(0));\n  \
    \    move(all(f), P.begin() + n * j);\n      move(all(g), Q.begin() + n * j);\n\
    \    }\n    fill(P.begin() + 2 * n * k, P.end(), mint(0));\n    fill(Q.begin()\
    \ + 2 * n * k, Q.end(), mint(0));\n    FOR(j, 4 * k) Q[n * j] = 0;\n    n /= 2,\
    \ k *= 2;\n  }\n  FOR(i, k) P[i] = P[2 * i];\n  P.resize(k);\n  mint c = mint(1)\
    \ / mint(k);\n  for (auto& x : P) x *= c;\n  ntt(P, 1);\n  reverse(all(P));\n\
    \  P.resize(m + 1);\n  return P;\n}\n\n// \\sum_jwt[j][x^j]f^i \u3092 i=0,1,...,m\n\
    template <typename mint>\nvc<mint> power_projection_0_garner(vc<mint> wt, vc<mint>\
    \ f, int m) {\n  assert(len(f) == len(wt) && f[0] == mint(0));\n  int n = 1;\n\
    \  while (n < len(f)) n *= 2;\n  f.resize(n), wt.resize(n);\n  reverse(all(wt));\n\
    \n  constexpr u32 p[] = {167772161, 469762049, 754974721};\n  using mint0 = modint<p[0]>;\n\
    \  using mint1 = modint<p[1]>;\n  using mint2 = modint<p[2]>;\n  vc<mint0> W0(2\
    \ * n);\n  vc<mint1> W1(2 * n);\n  vc<mint2> W2(2 * n);\n  {\n    // bit reverse\
    \ order\n    vc<int> btr(2 * n);\n    int log = topbit(2 * n);\n    FOR(i, 2 *\
    \ n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\n    {\n      int\
    \ t = mint0::ntt_info().fi;\n      mint0 r = mint0::ntt_info().se;\n      mint0\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint0 w = 1;\n      for (auto&\
    \ i : btr) {\n        W0[i] = w, w *= dw;\n      }\n    }\n    {\n      int t\
    \ = mint1::ntt_info().fi;\n      mint1 r = mint1::ntt_info().se;\n      mint1\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint1 w = 1;\n      for (auto&\
    \ i : btr) {\n        W1[i] = w, w *= dw;\n      }\n    }\n    {\n      int t\
    \ = mint2::ntt_info().fi;\n      mint2 r = mint2::ntt_info().se;\n      mint2\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint2 w = 1;\n      for (auto&\
    \ i : btr) {\n        W2[i] = w, w *= dw;\n      }\n    }\n  }\n\n  int k = 1;\n\
    \  vc<mint> P(2 * n), Q(2 * n);\n  FOR(i, n) P[i] = wt[i], Q[i] = -f[i];\n\n \
    \ while (n > 1) {\n    vc<mint0> P0(4 * n * k), Q0(4 * n * k);\n    vc<mint1>\
    \ P1(4 * n * k), Q1(4 * n * k);\n    vc<mint2> P2(4 * n * k), Q2(4 * n * k);\n\
    \    FOR(i, 2 * n * k) P0[i] = P[i].val, Q0[i] = Q[i].val;\n    FOR(i, 2 * n *\
    \ k) P1[i] = P[i].val, Q1[i] = Q[i].val;\n    FOR(i, 2 * n * k) P2[i] = P[i].val,\
    \ Q2[i] = Q[i].val;\n    Q0[2 * n * k] = 1, Q1[2 * n * k] = 1, Q2[2 * n * k] =\
    \ 1;\n    ntt(P0, 0), ntt(Q0, 0), ntt(P1, 0), ntt(Q1, 0), ntt(P2, 0), ntt(Q2,\
    \ 0);\n    FOR(i, 2 * n * k) {\n      P0[i] = inv<mint0>(2) * W0[i] *\n      \
    \        (P0[2 * i] * Q0[2 * i + 1] - P0[2 * i + 1] * Q0[2 * i]);\n      Q0[i]\
    \ = Q0[2 * i] * Q0[2 * i + 1];\n      P1[i] = inv<mint1>(2) * W1[i] *\n      \
    \        (P1[2 * i] * Q1[2 * i + 1] - P1[2 * i + 1] * Q1[2 * i]);\n      Q1[i]\
    \ = Q1[2 * i] * Q1[2 * i + 1];\n      P2[i] = inv<mint2>(2) * W2[i] *\n      \
    \        (P2[2 * i] * Q2[2 * i + 1] - P2[2 * i + 1] * Q2[2 * i]);\n      Q2[i]\
    \ = Q2[2 * i] * Q2[2 * i + 1];\n    }\n    P0.resize(2 * n * k), Q0.resize(2 *\
    \ n * k);\n    P1.resize(2 * n * k), Q1.resize(2 * n * k);\n    P2.resize(2 *\
    \ n * k), Q2.resize(2 * n * k);\n    ntt(P0, 1), ntt(Q0, 1), ntt(P1, 1), ntt(Q1,\
    \ 1), ntt(P2, 1), ntt(Q2, 1);\n\n    constexpr i128 K = u128(p[0]) * p[1] * p[2];\n\
    \    auto get = [&](mint0 a, mint1 b, mint2 c) -> mint {\n      i128 x = CRT3<u128,\
    \ p[0], p[1], p[2]>(a.val, b.val, c.val);\n      i128 y = K - x;\n      return\
    \ (x < y ? mint(x) : -mint(y));\n    };\n\n    fill(all(P), mint(0));\n    fill(all(Q),\
    \ mint(0));\n    FOR(j, 2 * k) FOR(i, n / 2) {\n      int k = n * j + i;\n   \
    \   P[k] = get(P0[k], P1[k], P2[k]);\n      Q[k] = get(Q0[k], Q1[k], Q2[k]);\n\
    \    }\n    Q[0] = 0;\n    n /= 2, k *= 2;\n  }\n  vc<mint> F(k);\n  FOR(i, k)\
    \ F[i] = P[2 * i];\n  reverse(all(F));\n  F.resize(m + 1);\n  return F;\n}\n\n\
    // \\sum_j[x^j]f^i \u3092 i=0,1,...,m\ntemplate <typename mint>\nvc<mint> power_projection(vc<mint>\
    \ wt, vc<mint> f, int m) {\n  assert(len(f) == len(wt));\n  static_assert(!is_same_v<mint,\
    \ modint<2>>, \"use Bit_Array version for mod 2\");\n  if (f.empty()) {\n    return\
    \ vc<mint>(m + 1, mint(0));\n  }\n  if (f[0] != mint(0)) {\n    mint c = f[0];\n\
    \    f[0] = 0;\n    vc<mint> A = power_projection(wt, f, m);\n    FOR(p, m + 1)\
    \ A[p] *= fact_inv<mint>(p);\n    vc<mint> B(m + 1);\n    mint pow = 1;\n    FOR(q,\
    \ m + 1) B[q] = pow * fact_inv<mint>(q), pow *= c;\n    A = convolution<mint>(A,\
    \ B);\n    A.resize(m + 1);\n    FOR(i, m + 1) A[i] *= fact<mint>(i);\n    return\
    \ A;\n  }\n  if (mint::can_ntt()) {\n    return power_projection_0_ntt(wt, f,\
    \ m);\n  }\n  return power_projection_0_garner(wt, f, m);\n}\n"
  code: "\n#include \"mod/modint.hpp\"\n#include \"poly/convolution.hpp\"\n\ntemplate\
    \ <typename mint>\nvc<mint> power_projection_0_ntt(vc<mint> wt, vc<mint> f, int\
    \ m) {\n  assert(len(f) == len(wt) && f[0] == mint(0));\n\n  int n = 1;\n  while\
    \ (n < len(f)) n *= 2;\n\n  for (auto& x : f) x = -x;\n  f.resize(n), wt.resize(n);\n\
    \  reverse(all(wt));\n  vc<mint>&P = wt, &Q = f;\n  P.resize(4 * n), Q.resize(4\
    \ * n);\n\n  vc<mint> W(n);\n  {\n    // bit reverse order\n    vc<int> btr(n);\n\
    \    int log = topbit(n);\n    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i &\
    \ 1) << (log - 1)); }\n    int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n\
    \    mint dw = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for\
    \ (auto& i : btr) {\n      W[i] = w, w *= dw;\n    }\n  }\n\n  int k = 1;\n  while\
    \ (n > 1) {\n    /*\n    FFT step\n    04.. -> 048c\n    15.. -> 159d\n    ....\
    \ -> 26ae\n    .... -> 37bf\n    */\n\n    auto doubling_y = [&](vc<mint>& A,\
    \ int l, int r) -> void {\n      mint z = W[k / 2].inverse();\n      vc<mint>\
    \ f(k);\n      FOR(i, l, r) {\n        FOR(j, k) f[j] = A[2 * n * j + i];\n  \
    \      ntt(f, 1);\n        mint r = 1;\n        FOR(j, 1, k) r *= z, f[j] *= r;\n\
    \        ntt(f, 0);\n        FOR(j, k) A[2 * n * (k + j) + i] = f[j];\n      }\n\
    \    };\n\n    auto FFT_x = [&](vc<mint>& A, int l, int r) -> void {\n      vc<mint>\
    \ f(2 * n);\n      FOR(j, l, r) {\n        move(A.begin() + 2 * n * j, A.begin()\
    \ + 2 * n * (j + 1), f.begin());\n        ntt(f, 0);\n        move(all(f), A.begin()\
    \ + 2 * n * j);\n      }\n    };\n\n    if (n <= k) {\n      doubling_y(P, 0,\
    \ n), doubling_y(Q, 1, n);\n      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);\n  \
    \  } else {\n      FFT_x(P, 0, k), FFT_x(Q, 0, k);\n      doubling_y(P, 0, 2 *\
    \ n), doubling_y(Q, 0, 2 * n);\n    }\n    FOR(i, 2 * n * k) Q[i] += 1;\n    FOR(i,\
    \ 2 * n * k, 4 * n * k) Q[i] -= 1;\n\n    /*\n    048c -> 0248????\n    159d ->\
    \ ....????\n    26ae\n    37bf\n    */\n    vc<mint> F(2 * n), G(2 * n), f(n),\
    \ g(n);\n    FOR(j, 2 * k) {\n      move(P.begin() + 2 * n * j, P.begin() + 2\
    \ * n * j + 2 * n, F.begin());\n      move(Q.begin() + 2 * n * j, Q.begin() +\
    \ 2 * n * j + 2 * n, G.begin());\n      FOR(i, n) {\n        f[i] = W[i] * (F[2\
    \ * i] * G[2 * i + 1] - F[2 * i + 1] * G[2 * i]);\n        g[i] = G[2 * i] * G[2\
    \ * i + 1];\n      }\n      ntt(f, 1), ntt(g, 1);\n      fill(f.begin() + n /\
    \ 2, f.end(), mint(0));\n      fill(g.begin() + n / 2, g.end(), mint(0));\n  \
    \    move(all(f), P.begin() + n * j);\n      move(all(g), Q.begin() + n * j);\n\
    \    }\n    fill(P.begin() + 2 * n * k, P.end(), mint(0));\n    fill(Q.begin()\
    \ + 2 * n * k, Q.end(), mint(0));\n    FOR(j, 4 * k) Q[n * j] = 0;\n    n /= 2,\
    \ k *= 2;\n  }\n  FOR(i, k) P[i] = P[2 * i];\n  P.resize(k);\n  mint c = mint(1)\
    \ / mint(k);\n  for (auto& x : P) x *= c;\n  ntt(P, 1);\n  reverse(all(P));\n\
    \  P.resize(m + 1);\n  return P;\n}\n\n// \\sum_jwt[j][x^j]f^i \u3092 i=0,1,...,m\n\
    template <typename mint>\nvc<mint> power_projection_0_garner(vc<mint> wt, vc<mint>\
    \ f, int m) {\n  assert(len(f) == len(wt) && f[0] == mint(0));\n  int n = 1;\n\
    \  while (n < len(f)) n *= 2;\n  f.resize(n), wt.resize(n);\n  reverse(all(wt));\n\
    \n  constexpr u32 p[] = {167772161, 469762049, 754974721};\n  using mint0 = modint<p[0]>;\n\
    \  using mint1 = modint<p[1]>;\n  using mint2 = modint<p[2]>;\n  vc<mint0> W0(2\
    \ * n);\n  vc<mint1> W1(2 * n);\n  vc<mint2> W2(2 * n);\n  {\n    // bit reverse\
    \ order\n    vc<int> btr(2 * n);\n    int log = topbit(2 * n);\n    FOR(i, 2 *\
    \ n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\n    {\n      int\
    \ t = mint0::ntt_info().fi;\n      mint0 r = mint0::ntt_info().se;\n      mint0\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint0 w = 1;\n      for (auto&\
    \ i : btr) {\n        W0[i] = w, w *= dw;\n      }\n    }\n    {\n      int t\
    \ = mint1::ntt_info().fi;\n      mint1 r = mint1::ntt_info().se;\n      mint1\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint1 w = 1;\n      for (auto&\
    \ i : btr) {\n        W1[i] = w, w *= dw;\n      }\n    }\n    {\n      int t\
    \ = mint2::ntt_info().fi;\n      mint2 r = mint2::ntt_info().se;\n      mint2\
    \ dw = r.inverse().pow((1 << t) / (4 * n));\n      mint2 w = 1;\n      for (auto&\
    \ i : btr) {\n        W2[i] = w, w *= dw;\n      }\n    }\n  }\n\n  int k = 1;\n\
    \  vc<mint> P(2 * n), Q(2 * n);\n  FOR(i, n) P[i] = wt[i], Q[i] = -f[i];\n\n \
    \ while (n > 1) {\n    vc<mint0> P0(4 * n * k), Q0(4 * n * k);\n    vc<mint1>\
    \ P1(4 * n * k), Q1(4 * n * k);\n    vc<mint2> P2(4 * n * k), Q2(4 * n * k);\n\
    \    FOR(i, 2 * n * k) P0[i] = P[i].val, Q0[i] = Q[i].val;\n    FOR(i, 2 * n *\
    \ k) P1[i] = P[i].val, Q1[i] = Q[i].val;\n    FOR(i, 2 * n * k) P2[i] = P[i].val,\
    \ Q2[i] = Q[i].val;\n    Q0[2 * n * k] = 1, Q1[2 * n * k] = 1, Q2[2 * n * k] =\
    \ 1;\n    ntt(P0, 0), ntt(Q0, 0), ntt(P1, 0), ntt(Q1, 0), ntt(P2, 0), ntt(Q2,\
    \ 0);\n    FOR(i, 2 * n * k) {\n      P0[i] = inv<mint0>(2) * W0[i] *\n      \
    \        (P0[2 * i] * Q0[2 * i + 1] - P0[2 * i + 1] * Q0[2 * i]);\n      Q0[i]\
    \ = Q0[2 * i] * Q0[2 * i + 1];\n      P1[i] = inv<mint1>(2) * W1[i] *\n      \
    \        (P1[2 * i] * Q1[2 * i + 1] - P1[2 * i + 1] * Q1[2 * i]);\n      Q1[i]\
    \ = Q1[2 * i] * Q1[2 * i + 1];\n      P2[i] = inv<mint2>(2) * W2[i] *\n      \
    \        (P2[2 * i] * Q2[2 * i + 1] - P2[2 * i + 1] * Q2[2 * i]);\n      Q2[i]\
    \ = Q2[2 * i] * Q2[2 * i + 1];\n    }\n    P0.resize(2 * n * k), Q0.resize(2 *\
    \ n * k);\n    P1.resize(2 * n * k), Q1.resize(2 * n * k);\n    P2.resize(2 *\
    \ n * k), Q2.resize(2 * n * k);\n    ntt(P0, 1), ntt(Q0, 1), ntt(P1, 1), ntt(Q1,\
    \ 1), ntt(P2, 1), ntt(Q2, 1);\n\n    constexpr i128 K = u128(p[0]) * p[1] * p[2];\n\
    \    auto get = [&](mint0 a, mint1 b, mint2 c) -> mint {\n      i128 x = CRT3<u128,\
    \ p[0], p[1], p[2]>(a.val, b.val, c.val);\n      i128 y = K - x;\n      return\
    \ (x < y ? mint(x) : -mint(y));\n    };\n\n    fill(all(P), mint(0));\n    fill(all(Q),\
    \ mint(0));\n    FOR(j, 2 * k) FOR(i, n / 2) {\n      int k = n * j + i;\n   \
    \   P[k] = get(P0[k], P1[k], P2[k]);\n      Q[k] = get(Q0[k], Q1[k], Q2[k]);\n\
    \    }\n    Q[0] = 0;\n    n /= 2, k *= 2;\n  }\n  vc<mint> F(k);\n  FOR(i, k)\
    \ F[i] = P[2 * i];\n  reverse(all(F));\n  F.resize(m + 1);\n  return F;\n}\n\n\
    // \\sum_j[x^j]f^i \u3092 i=0,1,...,m\ntemplate <typename mint>\nvc<mint> power_projection(vc<mint>\
    \ wt, vc<mint> f, int m) {\n  assert(len(f) == len(wt));\n  static_assert(!is_same_v<mint,\
    \ modint<2>>, \"use Bit_Array version for mod 2\");\n  if (f.empty()) {\n    return\
    \ vc<mint>(m + 1, mint(0));\n  }\n  if (f[0] != mint(0)) {\n    mint c = f[0];\n\
    \    f[0] = 0;\n    vc<mint> A = power_projection(wt, f, m);\n    FOR(p, m + 1)\
    \ A[p] *= fact_inv<mint>(p);\n    vc<mint> B(m + 1);\n    mint pow = 1;\n    FOR(q,\
    \ m + 1) B[q] = pow * fact_inv<mint>(q), pow *= c;\n    A = convolution<mint>(A,\
    \ B);\n    A.resize(m + 1);\n    FOR(i, m + 1) A[i] *= fact<mint>(i);\n    return\
    \ A;\n  }\n  if (mint::can_ntt()) {\n    return power_projection_0_ntt(wt, f,\
    \ m);\n  }\n  return power_projection_0_garner(wt, f, m);\n}\n"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  - other/bit.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  isVerificationFile: false
  path: poly/power_projection.hpp
  requiredBy:
  - graph/count/count_labeled_bridgeless.hpp
  - graph/count/count_labeled_biconnected.hpp
  - poly/schroder.hpp
  - poly/compositional_inverse.hpp
  - poly/2d/compositional_inverse_2d.hpp
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/power_projection.test.cpp
  - test/1_mytest/count_labeled_biconnected.test.cpp
  - test/1_mytest/compositional_inverset.test.cpp
  - test/1_mytest/count_labeled_bridgeless.test.cpp
  - test/2_library_checker/polynomial/compositional_inverse.test.cpp
  - test/2_library_checker/polynomial/compositional_inverse_dmint.test.cpp
  - test/3_yukicoder/3621.test.cpp
  - test/3_yukicoder/3619.test.cpp
documentation_of: poly/power_projection.hpp
layout: document
redirect_from:
- /library/poly/power_projection.hpp
- /library/poly/power_projection.hpp.html
title: poly/power_projection.hpp
---
