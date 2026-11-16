---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
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
    links:
    - https://github.com/maspypy/library/blob/main/mod/modular_subset_sum.hpp
  bundledCode: "#line 1 \"mod/modular_subset_sum.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/modular_subset_sum.hpp\n\
    #line 1 \"random/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/random/base.hpp\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"mod/modint61.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/mod/modint61.hpp\n\nstruct modint61\
    \ {\n  static constexpr u64 mod = (1ULL << 61) - 1;\n  u64 val;\n  constexpr modint61()\
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
    \n\n// Faster Deterministic Modular Subset Sum. arXiv preprint arXiv:2012.06062.\n\
    // modular subset sum \u306E\u305F\u3081\u306E\u3001\u30B7\u30D5\u30C8\u4ED8\u304D\
    \u30BB\u30B0\u6728\n// shift \u306B\u306F 2^(N-k) \u6642\u9593\u304B\u304B\u308B\
    \nstruct ShiftTree {\n  using M61 = modint61;\n  int delta;\n  int N, n;\n  M61\
    \ base;\n  vc<M61> dat;\n  vc<M61> base_pow;\n\n  ShiftTree(int N, ll base) :\
    \ delta(0), N(N), n(topbit(N)), base(base) {\n    assert(N == (1 << n));\n   \
    \ dat.assign(2 * N, 0);\n\n    base_pow.assign(n, 1);\n    base_pow[n - 1] = base;\n\
    \    FOR_R(i, n - 1) base_pow[i] = base_pow[i + 1] * base_pow[i + 1];\n  }\n\n\
    \  inline int skew(int k) { return (delta >> (n - k)) & 1; }\n\n  inline int left(int\
    \ k, int i) {\n    int mask = (1 << (k + 1)) - 1;\n    return ((2 * i + 0 - skew(k\
    \ + 1)) & mask) + (1 << (k + 1));\n  }\n\n  inline int right(int k, int i) {\n\
    \    int mask = (1 << (k + 1)) - 1;\n    return ((2 * i + 1 - skew(k + 1)) & mask)\
    \ + (1 << (k + 1));\n  }\n\n  inline int parent(int k, int i) {\n    int mask\
    \ = (1 << k) - 1;\n    return (((i + skew(k)) & mask) + (1 << k)) / 2;\n  }\n\n\
    \  inline void update(int k, int i) {\n    M61 b = base_pow[k];\n    dat[i] =\
    \ b * dat[left(k, i)] + dat[right(k, i)];\n  }\n\n  inline void set(int i, ll\
    \ x) {\n    i = (i + N - delta) % N + N;\n    dat[i] = x;\n    int k = n;\n  \
    \  while (i != 1) {\n      i = parent(k, i);\n      --k;\n      update(k, i);\n\
    \    }\n  }\n\n  void shift(int k) {\n    k %= N;\n    if (k < 0) k += N;\n  \
    \  if (k == 0) return;\n    int j = lowbit(k);\n    delta = (delta + k) % N;\n\
    \    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k) update(k, i); }\n  }\n\n  // [a,b)\
    \ \u306B\u304A\u3051\u308B difference \u306E\u5217\u6319\u3002output sensitive\u3002\
    \n  // T \u306E\u30CE\u30FC\u30C9 i\u3001Q \u306E\u30CE\u30FC\u30C9 j \u304C (x,y)\
    \ \u3092\u6307\u3059\u3068\u3059\u308B\u3002\n  static void find_differences(vc<int>&\
    \ res, ShiftTree& T, ShiftTree& Q, int a,\n                               int\
    \ b, int k, int i, int j, int x, int y) {\n    if (T.dat[i] == Q.dat[j]) return;\n\
    \    if (max(a, x) >= min(b, y)) return;\n    if (y == x + 1) {\n      res.eb(x);\n\
    \      return;\n    }\n    int z = (x + y) / 2;\n    find_differences(res, T,\
    \ Q, a, b, k + 1, T.left(k, i), Q.left(k, j), x, z);\n    find_differences(res,\
    \ T, Q, a, b, k + 1, T.right(k, i), Q.right(k, j), z,\n                     y);\n\
    \  }\n\n  static vc<int> diff(ShiftTree& T, ShiftTree& Q, int a, int b) {\n  \
    \  assert(T.N == Q.N);\n    vc<int> res;\n    find_differences(res, T, Q, a, b,\
    \ 0, 1, 1, 0, T.N);\n    return res;\n  }\n};\n\n/*\n\u8A08\u7B97\u91CF\uFF1A\
    (|vals| + mod) * log(mod)\n\u30FBcan(x) \u307E\u305F\u306F [x] \u3067 bool \u3092\
    \u8FD4\u3059\u3002\n\u30FBrestore(x) \u3067\u5FA9\u5143\u3002\n\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u306B\u306F\u3001(mod, vals) \u3092\u308F\u305F\u3059\
    \n*/\ntemplate <typename INT>\nstruct Modular_Subset_Sum {\n  int mod;\n  vc<INT>&\
    \ vals;\n  vc<int> par;\n\n  Modular_Subset_Sum(int mod, vc<INT>& vals) : mod(mod),\
    \ vals(vals) {\n    for (auto&& x : vals) assert(0 <= x && x < mod);\n    par.assign(mod,\
    \ -1);\n\n    const ll base = RNG(0, (1LL << 61) - 1);\n\n    int k = 1;\n   \
    \ while ((1 << k) < 2 * mod) ++k;\n\n    int L = 1 << k;\n    assert(L >= 2 *\
    \ mod);\n\n    ShiftTree T1(L, base);\n    ShiftTree T2(L, base);\n    T1.set(0,\
    \ 1);\n    T2.set(0, 1);\n    T2.set(L - mod, 1);\n\n    auto bit_rev = [&](int\
    \ i) -> int {\n      int x = 0;\n      FOR(k) {\n        x = 2 * x + (i & 1);\n\
    \        i >>= 1;\n      }\n      return x;\n    };\n\n    vc<vi> IDS(L);\n  \
    \  FOR(i, len(vals)) { IDS[vals[i]].eb(i); }\n\n    FOR(i, 1, L) {\n      int\
    \ x = bit_rev(i);\n      if (len(IDS[x]) == 0) continue;\n      T2.shift(x - T2.delta);\n\
    \      for (auto&& idx : IDS[x]) {\n        auto diff = ShiftTree::diff(T1, T2,\
    \ 0, mod);\n        for (auto&& d : diff) {\n          if (can(d)) continue;\n\
    \          par[d] = idx;\n          T1.set(d, 1);\n          T2.set((d + x) %\
    \ L, 1);\n          T2.set((L + d + x - mod) % L, 1);\n        }\n      }\n  \
    \  }\n  }\n\n  bool can(int x) {\n    if (x >= mod) return false;\n    return\
    \ (x == 0 || par[x] != -1);\n  }\n\n  bool operator[](int x) { return can(x);\
    \ }\n  vc<int> restore(int x) {\n    assert(can(x));\n    vc<int> res;\n    while\
    \ (x) {\n      int i = par[x];\n      res.eb(i);\n      x -= vals[i];\n      if\
    \ (x < 0) x += mod;\n    }\n    reverse(all(res));\n    return res;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/mod/modular_subset_sum.hpp\n\
    #include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\n\n// Faster Deterministic\
    \ Modular Subset Sum. arXiv preprint arXiv:2012.06062.\n// modular subset sum\
    \ \u306E\u305F\u3081\u306E\u3001\u30B7\u30D5\u30C8\u4ED8\u304D\u30BB\u30B0\u6728\
    \n// shift \u306B\u306F 2^(N-k) \u6642\u9593\u304B\u304B\u308B\nstruct ShiftTree\
    \ {\n  using M61 = modint61;\n  int delta;\n  int N, n;\n  M61 base;\n  vc<M61>\
    \ dat;\n  vc<M61> base_pow;\n\n  ShiftTree(int N, ll base) : delta(0), N(N), n(topbit(N)),\
    \ base(base) {\n    assert(N == (1 << n));\n    dat.assign(2 * N, 0);\n\n    base_pow.assign(n,\
    \ 1);\n    base_pow[n - 1] = base;\n    FOR_R(i, n - 1) base_pow[i] = base_pow[i\
    \ + 1] * base_pow[i + 1];\n  }\n\n  inline int skew(int k) { return (delta >>\
    \ (n - k)) & 1; }\n\n  inline int left(int k, int i) {\n    int mask = (1 << (k\
    \ + 1)) - 1;\n    return ((2 * i + 0 - skew(k + 1)) & mask) + (1 << (k + 1));\n\
    \  }\n\n  inline int right(int k, int i) {\n    int mask = (1 << (k + 1)) - 1;\n\
    \    return ((2 * i + 1 - skew(k + 1)) & mask) + (1 << (k + 1));\n  }\n\n  inline\
    \ int parent(int k, int i) {\n    int mask = (1 << k) - 1;\n    return (((i +\
    \ skew(k)) & mask) + (1 << k)) / 2;\n  }\n\n  inline void update(int k, int i)\
    \ {\n    M61 b = base_pow[k];\n    dat[i] = b * dat[left(k, i)] + dat[right(k,\
    \ i)];\n  }\n\n  inline void set(int i, ll x) {\n    i = (i + N - delta) % N +\
    \ N;\n    dat[i] = x;\n    int k = n;\n    while (i != 1) {\n      i = parent(k,\
    \ i);\n      --k;\n      update(k, i);\n    }\n  }\n\n  void shift(int k) {\n\
    \    k %= N;\n    if (k < 0) k += N;\n    if (k == 0) return;\n    int j = lowbit(k);\n\
    \    delta = (delta + k) % N;\n    FOR_R(k, n - j) { FOR3(i, 1 << k, 2 << k) update(k,\
    \ i); }\n  }\n\n  // [a,b) \u306B\u304A\u3051\u308B difference \u306E\u5217\u6319\
    \u3002output sensitive\u3002\n  // T \u306E\u30CE\u30FC\u30C9 i\u3001Q \u306E\u30CE\
    \u30FC\u30C9 j \u304C (x,y) \u3092\u6307\u3059\u3068\u3059\u308B\u3002\n  static\
    \ void find_differences(vc<int>& res, ShiftTree& T, ShiftTree& Q, int a,\n   \
    \                            int b, int k, int i, int j, int x, int y) {\n   \
    \ if (T.dat[i] == Q.dat[j]) return;\n    if (max(a, x) >= min(b, y)) return;\n\
    \    if (y == x + 1) {\n      res.eb(x);\n      return;\n    }\n    int z = (x\
    \ + y) / 2;\n    find_differences(res, T, Q, a, b, k + 1, T.left(k, i), Q.left(k,\
    \ j), x, z);\n    find_differences(res, T, Q, a, b, k + 1, T.right(k, i), Q.right(k,\
    \ j), z,\n                     y);\n  }\n\n  static vc<int> diff(ShiftTree& T,\
    \ ShiftTree& Q, int a, int b) {\n    assert(T.N == Q.N);\n    vc<int> res;\n \
    \   find_differences(res, T, Q, a, b, 0, 1, 1, 0, T.N);\n    return res;\n  }\n\
    };\n\n/*\n\u8A08\u7B97\u91CF\uFF1A(|vals| + mod) * log(mod)\n\u30FBcan(x) \u307E\
    \u305F\u306F [x] \u3067 bool \u3092\u8FD4\u3059\u3002\n\u30FBrestore(x) \u3067\
    \u5FA9\u5143\u3002\n\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u306F\u3001\
    (mod, vals) \u3092\u308F\u305F\u3059\n*/\ntemplate <typename INT>\nstruct Modular_Subset_Sum\
    \ {\n  int mod;\n  vc<INT>& vals;\n  vc<int> par;\n\n  Modular_Subset_Sum(int\
    \ mod, vc<INT>& vals) : mod(mod), vals(vals) {\n    for (auto&& x : vals) assert(0\
    \ <= x && x < mod);\n    par.assign(mod, -1);\n\n    const ll base = RNG(0, (1LL\
    \ << 61) - 1);\n\n    int k = 1;\n    while ((1 << k) < 2 * mod) ++k;\n\n    int\
    \ L = 1 << k;\n    assert(L >= 2 * mod);\n\n    ShiftTree T1(L, base);\n    ShiftTree\
    \ T2(L, base);\n    T1.set(0, 1);\n    T2.set(0, 1);\n    T2.set(L - mod, 1);\n\
    \n    auto bit_rev = [&](int i) -> int {\n      int x = 0;\n      FOR(k) {\n \
    \       x = 2 * x + (i & 1);\n        i >>= 1;\n      }\n      return x;\n   \
    \ };\n\n    vc<vi> IDS(L);\n    FOR(i, len(vals)) { IDS[vals[i]].eb(i); }\n\n\
    \    FOR(i, 1, L) {\n      int x = bit_rev(i);\n      if (len(IDS[x]) == 0) continue;\n\
    \      T2.shift(x - T2.delta);\n      for (auto&& idx : IDS[x]) {\n        auto\
    \ diff = ShiftTree::diff(T1, T2, 0, mod);\n        for (auto&& d : diff) {\n \
    \         if (can(d)) continue;\n          par[d] = idx;\n          T1.set(d,\
    \ 1);\n          T2.set((d + x) % L, 1);\n          T2.set((L + d + x - mod) %\
    \ L, 1);\n        }\n      }\n    }\n  }\n\n  bool can(int x) {\n    if (x >=\
    \ mod) return false;\n    return (x == 0 || par[x] != -1);\n  }\n\n  bool operator[](int\
    \ x) { return can(x); }\n  vc<int> restore(int x) {\n    assert(can(x));\n   \
    \ vc<int> res;\n    while (x) {\n      int i = par[x];\n      res.eb(i);\n   \
    \   x -= vals[i];\n      if (x < 0) x += mod;\n    }\n    reverse(all(res));\n\
    \    return res;\n  }\n};\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: mod/modular_subset_sum.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
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
