---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/4_1.test.cpp
    title: test/3_yukicoder/4_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_\
    \ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"mod/modint61.hpp\"\n\nstruct modint61 {\n \
    \ static constexpr u64 mod = (1ULL << 61) - 1;\n  u64 val;\n  constexpr modint61()\
    \ : val(0ULL) {}\n  constexpr modint61(u32 x) : val(x) {}\n  constexpr modint61(u64\
    \ x) : val(x % mod) {}\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\n  static constexpr u64 get_mod() { return\
    \ mod; }\n\n  modint61 &operator+=(const modint61 &a) {\n    val = ((val += a.val)\
    \ >= mod) ? (val - mod) : val;\n    return *this;\n  }\n  modint61 &operator-=(const\
    \ modint61 &a) {\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\n   \
    \ return *this;\n  }\n  modint61 &operator*=(const modint61 &a) {\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\n    val = (y >> 61)\
    \ + (y & mod);\n    val = (val >= mod) ? (val - mod) : val;\n    return *this;\n\
    \  }\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\n  modint61 operator+(const modint61 &p) const { return modint61(*this) +=\
    \ p; }\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\n  bool operator==(const modint61 &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\n  modint61 inverse()\
    \ const {\n    ll a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n  \
    \    t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ modint61(u);\n  }\n  modint61 pow(ll n) const {\n    assert(n >= 0);\n    modint61\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul, n >>= 1;\n    }\n    return ret;\n  }\n};\n\n#ifdef FASTIO\nvoid\
    \ rd(modint61 &x) {\n  fastio::rd(x.val);\n  assert(0 <= x.val && x.val < modint61::mod);\n\
    }\n\nvoid wt(modint61 x) { fastio::wt(x.val); }\n#endif\n#line 4 \"mod/modular_subset_sum.hpp\"\
    \n\r\n// Faster Deterministic Modular Subset Sum. arXiv preprint arXiv:2012.06062.\r\
    \n// modular subset sum \u306E\u305F\u3081\u306E\u3001\u30B7\u30D5\u30C8\u4ED8\
    \u304D\u30BB\u30B0\u6728\r\n// shift \u306B\u306F 2^(N-k) \u6642\u9593\u304B\u304B\
    \u308B\r\nstruct ShiftTree {\r\n  using M61 = modint61;\r\n  int delta;\r\n  int\
    \ N, n;\r\n  M61 base;\r\n  vc<M61> dat;\r\n  vc<M61> base_pow;\r\n\r\n  ShiftTree(int\
    \ N, ll base) : delta(0), N(N), n(topbit(N)), base(base) {\r\n    assert(N ==\
    \ (1 << n));\r\n    dat.assign(2 * N, 0);\r\n\r\n    base_pow.assign(n, 1);\r\n\
    \    base_pow[n - 1] = base;\r\n    FOR_R(i, n - 1) base_pow[i] = base_pow[i +\
    \ 1] * base_pow[i + 1];\r\n  }\r\n\r\n  inline int skew(int k) { return (delta\
    \ >> (n - k)) & 1; }\r\n\r\n  inline int left(int k, int i) {\r\n    int mask\
    \ = (1 << (k + 1)) - 1;\r\n    return ((2 * i + 0 - skew(k + 1)) & mask) + (1\
    \ << (k + 1));\r\n  }\r\n\r\n  inline int right(int k, int i) {\r\n    int mask\
    \ = (1 << (k + 1)) - 1;\r\n    return ((2 * i + 1 - skew(k + 1)) & mask) + (1\
    \ << (k + 1));\r\n  }\r\n\r\n  inline int parent(int k, int i) {\r\n    int mask\
    \ = (1 << k) - 1;\r\n    return (((i + skew(k)) & mask) + (1 << k)) / 2;\r\n \
    \ }\r\n\r\n  inline void update(int k, int i) {\r\n    M61 b = base_pow[k];\r\n\
    \    dat[i] = b * dat[left(k, i)] + dat[right(k, i)];\r\n  }\r\n\r\n  inline void\
    \ set(int i, ll x) {\r\n    i = (i + N - delta) % N + N;\r\n    dat[i] = x;\r\n\
    \    int k = n;\r\n    while (i != 1) {\r\n      i = parent(k, i);\r\n      --k;\r\
    \n      update(k, i);\r\n    }\r\n  }\r\n\r\n  void shift(int k) {\r\n    k %=\
    \ N;\r\n    if (k < 0) k += N;\r\n    if (k == 0) return;\r\n    int j = lowbit(k);\r\
    \n    delta = (delta + k) % N;\r\n    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k)\
    \ update(k, i); }\r\n  }\r\n\r\n  // [a,b) \u306B\u304A\u3051\u308B difference\
    \ \u306E\u5217\u6319\u3002output sensitive\u3002\r\n  // T \u306E\u30CE\u30FC\u30C9\
    \ i\u3001Q \u306E\u30CE\u30FC\u30C9 j \u304C (x,y) \u3092\u6307\u3059\u3068\u3059\
    \u308B\u3002\r\n  static void find_differences(vc<int>& res, ShiftTree& T, ShiftTree&\
    \ Q, int a,\r\n                               int b, int k, int i, int j, int\
    \ x, int y) {\r\n    if (T.dat[i] == Q.dat[j]) return;\r\n    if (max(a, x) >=\
    \ min(b, y)) return;\r\n    if (y == x + 1) {\r\n      res.eb(x);\r\n      return;\r\
    \n    }\r\n    int z = (x + y) / 2;\r\n    find_differences(res, T, Q, a, b, k\
    \ + 1, T.left(k, i), Q.left(k, j), x, z);\r\n    find_differences(res, T, Q, a,\
    \ b, k + 1, T.right(k, i), Q.right(k, j), z,\r\n                     y);\r\n \
    \ }\r\n\r\n  static vc<int> diff(ShiftTree& T, ShiftTree& Q, int a, int b) {\r\
    \n    assert(T.N == Q.N);\r\n    vc<int> res;\r\n    find_differences(res, T,\
    \ Q, a, b, 0, 1, 1, 0, T.N);\r\n    return res;\r\n  }\r\n};\r\n\r\n/*\r\n\u8A08\
    \u7B97\u91CF\uFF1A(|vals| + mod) * log(mod)\r\n\u30FBcan(x) \u307E\u305F\u306F\
    \ [x] \u3067 bool \u3092\u8FD4\u3059\u3002\r\n\u30FBrestore(x) \u3067\u5FA9\u5143\
    \u3002\r\n\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u306F\u3001(mod, vals)\
    \ \u3092\u308F\u305F\u3059\r\n*/\r\ntemplate <typename INT>\r\nstruct Modular_Subset_Sum\
    \ {\r\n  int mod;\r\n  vc<INT>& vals;\r\n  vc<int> par;\r\n\r\n  Modular_Subset_Sum(int\
    \ mod, vc<INT>& vals) : mod(mod), vals(vals) {\r\n    for (auto&& x : vals) assert(0\
    \ <= x && x < mod);\r\n    par.assign(mod, -1);\r\n\r\n    const ll base = RNG(0,\
    \ (1LL << 61) - 1);\r\n\r\n    int k = 1;\r\n    while ((1 << k) < 2 * mod) ++k;\r\
    \n\r\n    int L = 1 << k;\r\n    assert(L >= 2 * mod);\r\n\r\n    ShiftTree T1(L,\
    \ base);\r\n    ShiftTree T2(L, base);\r\n    T1.set(0, 1);\r\n    T2.set(0, 1);\r\
    \n    T2.set(L - mod, 1);\r\n\r\n    auto bit_rev = [&](int i) -> int {\r\n  \
    \    int x = 0;\r\n      FOR(k) {\r\n        x = 2 * x + (i & 1);\r\n        i\
    \ >>= 1;\r\n      }\r\n      return x;\r\n    };\r\n\r\n    vc<vi> IDS(L);\r\n\
    \    FOR(i, len(vals)) { IDS[vals[i]].eb(i); }\r\n\r\n    FOR(i, 1, L) {\r\n \
    \     int x = bit_rev(i);\r\n      if (len(IDS[x]) == 0) continue;\r\n      T2.shift(x\
    \ - T2.delta);\r\n      for (auto&& idx : IDS[x]) {\r\n        auto diff = ShiftTree::diff(T1,\
    \ T2, 0, mod);\r\n        for (auto&& d : diff) {\r\n          if (can(d)) continue;\r\
    \n          par[d] = idx;\r\n          T1.set(d, 1);\r\n          T2.set((d +\
    \ x) % L, 1);\r\n          T2.set((L + d + x - mod) % L, 1);\r\n        }\r\n\
    \      }\r\n    }\r\n  }\r\n\r\n  bool can(int x) {\r\n    if (x >= mod) return\
    \ false;\r\n    return (x == 0 || par[x] != -1);\r\n  }\r\n\r\n  bool operator[](int\
    \ x) { return can(x); }\r\n  vc<int> restore(int x) {\r\n    assert(can(x));\r\
    \n    vc<int> res;\r\n    while (x) {\r\n      int i = par[x];\r\n      res.eb(i);\r\
    \n      x -= vals[i];\r\n      if (x < 0) x += mod;\r\n    }\r\n    reverse(all(res));\r\
    \n    return res;\r\n  }\r\n};\r\n"
  code: "#include \"other/bit.hpp\"\r\n#include \"random/base.hpp\"\r\n#include \"\
    mod/modint61.hpp\"\r\n\r\n// Faster Deterministic Modular Subset Sum. arXiv preprint\
    \ arXiv:2012.06062.\r\n// modular subset sum \u306E\u305F\u3081\u306E\u3001\u30B7\
    \u30D5\u30C8\u4ED8\u304D\u30BB\u30B0\u6728\r\n// shift \u306B\u306F 2^(N-k) \u6642\
    \u9593\u304B\u304B\u308B\r\nstruct ShiftTree {\r\n  using M61 = modint61;\r\n\
    \  int delta;\r\n  int N, n;\r\n  M61 base;\r\n  vc<M61> dat;\r\n  vc<M61> base_pow;\r\
    \n\r\n  ShiftTree(int N, ll base) : delta(0), N(N), n(topbit(N)), base(base) {\r\
    \n    assert(N == (1 << n));\r\n    dat.assign(2 * N, 0);\r\n\r\n    base_pow.assign(n,\
    \ 1);\r\n    base_pow[n - 1] = base;\r\n    FOR_R(i, n - 1) base_pow[i] = base_pow[i\
    \ + 1] * base_pow[i + 1];\r\n  }\r\n\r\n  inline int skew(int k) { return (delta\
    \ >> (n - k)) & 1; }\r\n\r\n  inline int left(int k, int i) {\r\n    int mask\
    \ = (1 << (k + 1)) - 1;\r\n    return ((2 * i + 0 - skew(k + 1)) & mask) + (1\
    \ << (k + 1));\r\n  }\r\n\r\n  inline int right(int k, int i) {\r\n    int mask\
    \ = (1 << (k + 1)) - 1;\r\n    return ((2 * i + 1 - skew(k + 1)) & mask) + (1\
    \ << (k + 1));\r\n  }\r\n\r\n  inline int parent(int k, int i) {\r\n    int mask\
    \ = (1 << k) - 1;\r\n    return (((i + skew(k)) & mask) + (1 << k)) / 2;\r\n \
    \ }\r\n\r\n  inline void update(int k, int i) {\r\n    M61 b = base_pow[k];\r\n\
    \    dat[i] = b * dat[left(k, i)] + dat[right(k, i)];\r\n  }\r\n\r\n  inline void\
    \ set(int i, ll x) {\r\n    i = (i + N - delta) % N + N;\r\n    dat[i] = x;\r\n\
    \    int k = n;\r\n    while (i != 1) {\r\n      i = parent(k, i);\r\n      --k;\r\
    \n      update(k, i);\r\n    }\r\n  }\r\n\r\n  void shift(int k) {\r\n    k %=\
    \ N;\r\n    if (k < 0) k += N;\r\n    if (k == 0) return;\r\n    int j = lowbit(k);\r\
    \n    delta = (delta + k) % N;\r\n    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k)\
    \ update(k, i); }\r\n  }\r\n\r\n  // [a,b) \u306B\u304A\u3051\u308B difference\
    \ \u306E\u5217\u6319\u3002output sensitive\u3002\r\n  // T \u306E\u30CE\u30FC\u30C9\
    \ i\u3001Q \u306E\u30CE\u30FC\u30C9 j \u304C (x,y) \u3092\u6307\u3059\u3068\u3059\
    \u308B\u3002\r\n  static void find_differences(vc<int>& res, ShiftTree& T, ShiftTree&\
    \ Q, int a,\r\n                               int b, int k, int i, int j, int\
    \ x, int y) {\r\n    if (T.dat[i] == Q.dat[j]) return;\r\n    if (max(a, x) >=\
    \ min(b, y)) return;\r\n    if (y == x + 1) {\r\n      res.eb(x);\r\n      return;\r\
    \n    }\r\n    int z = (x + y) / 2;\r\n    find_differences(res, T, Q, a, b, k\
    \ + 1, T.left(k, i), Q.left(k, j), x, z);\r\n    find_differences(res, T, Q, a,\
    \ b, k + 1, T.right(k, i), Q.right(k, j), z,\r\n                     y);\r\n \
    \ }\r\n\r\n  static vc<int> diff(ShiftTree& T, ShiftTree& Q, int a, int b) {\r\
    \n    assert(T.N == Q.N);\r\n    vc<int> res;\r\n    find_differences(res, T,\
    \ Q, a, b, 0, 1, 1, 0, T.N);\r\n    return res;\r\n  }\r\n};\r\n\r\n/*\r\n\u8A08\
    \u7B97\u91CF\uFF1A(|vals| + mod) * log(mod)\r\n\u30FBcan(x) \u307E\u305F\u306F\
    \ [x] \u3067 bool \u3092\u8FD4\u3059\u3002\r\n\u30FBrestore(x) \u3067\u5FA9\u5143\
    \u3002\r\n\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u306F\u3001(mod, vals)\
    \ \u3092\u308F\u305F\u3059\r\n*/\r\ntemplate <typename INT>\r\nstruct Modular_Subset_Sum\
    \ {\r\n  int mod;\r\n  vc<INT>& vals;\r\n  vc<int> par;\r\n\r\n  Modular_Subset_Sum(int\
    \ mod, vc<INT>& vals) : mod(mod), vals(vals) {\r\n    for (auto&& x : vals) assert(0\
    \ <= x && x < mod);\r\n    par.assign(mod, -1);\r\n\r\n    const ll base = RNG(0,\
    \ (1LL << 61) - 1);\r\n\r\n    int k = 1;\r\n    while ((1 << k) < 2 * mod) ++k;\r\
    \n\r\n    int L = 1 << k;\r\n    assert(L >= 2 * mod);\r\n\r\n    ShiftTree T1(L,\
    \ base);\r\n    ShiftTree T2(L, base);\r\n    T1.set(0, 1);\r\n    T2.set(0, 1);\r\
    \n    T2.set(L - mod, 1);\r\n\r\n    auto bit_rev = [&](int i) -> int {\r\n  \
    \    int x = 0;\r\n      FOR(k) {\r\n        x = 2 * x + (i & 1);\r\n        i\
    \ >>= 1;\r\n      }\r\n      return x;\r\n    };\r\n\r\n    vc<vi> IDS(L);\r\n\
    \    FOR(i, len(vals)) { IDS[vals[i]].eb(i); }\r\n\r\n    FOR(i, 1, L) {\r\n \
    \     int x = bit_rev(i);\r\n      if (len(IDS[x]) == 0) continue;\r\n      T2.shift(x\
    \ - T2.delta);\r\n      for (auto&& idx : IDS[x]) {\r\n        auto diff = ShiftTree::diff(T1,\
    \ T2, 0, mod);\r\n        for (auto&& d : diff) {\r\n          if (can(d)) continue;\r\
    \n          par[d] = idx;\r\n          T1.set(d, 1);\r\n          T2.set((d +\
    \ x) % L, 1);\r\n          T2.set((L + d + x - mod) % L, 1);\r\n        }\r\n\
    \      }\r\n    }\r\n  }\r\n\r\n  bool can(int x) {\r\n    if (x >= mod) return\
    \ false;\r\n    return (x == 0 || par[x] != -1);\r\n  }\r\n\r\n  bool operator[](int\
    \ x) { return can(x); }\r\n  vc<int> restore(int x) {\r\n    assert(can(x));\r\
    \n    vc<int> res;\r\n    while (x) {\r\n      int i = par[x];\r\n      res.eb(i);\r\
    \n      x -= vals[i];\r\n      if (x < 0) x += mod;\r\n    }\r\n    reverse(all(res));\r\
    \n    return res;\r\n  }\r\n};\r\n"
  dependsOn:
  - other/bit.hpp
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: mod/modular_subset_sum.hpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/4_1.test.cpp
documentation_of: mod/modular_subset_sum.hpp
layout: document
redirect_from:
- /library/mod/modular_subset_sum.hpp
- /library/mod/modular_subset_sum.hpp.html
title: mod/modular_subset_sum.hpp
---
