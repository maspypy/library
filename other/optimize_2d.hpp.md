---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/ajo2025-final/submissions/71727945
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"ds/hashmap.hpp\"\n\n\
    // u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\
    \u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n);\
    \ }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n  \
    \  cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\n    return\
    \ i;\n  }\n\n  Val& operator[](const u64& k) {\n    if (cap == 0) extend();\n\
    \    int i = index(k);\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] =\
    \ Val{}, --cap; }\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 4 \"other/optimize_2d.hpp\"\n\n//\
    \ \u3069\u306E\u304F\u3089\u3044\u4F7F\u3048\u308B\u3053\u3068\u304C\u3042\u308B\
    \u306E\u304B\u4E0D\u660E\n// https://atcoder.jp/contests/ajo2025-final/submissions/71727945\n\
    // return: f(x,y),x,y\ntemplate <typename T, bool MINIMIZE, typename F>\ntuple<T,\
    \ ll, ll> optimize_2d(ll x1, ll x2, ll y1, ll y2, F f, int beam_width) {\n  assert(x1\
    \ < x2 && y1 < y2);\n\n  HashMap<T> MP;\n  u64 rnd = RNG_64();\n  auto eval =\
    \ [&](ll x, ll y) -> T {\n    T ans = f(x1 + x, y1 + y);\n    if (!MINIMIZE) ans\
    \ = -ans;\n    return ans;\n  };\n\n  vc<tuple<T, ll, ll>> cand;\n  cand.eb(eval(0,\
    \ 0), 0, 0);\n\n  ll X = x2 - x1, Y = y2 - y1;\n\n  // \u30B9\u30B1\u30FC\u30EB\
    \u304C\u5168\u7136\u9055\u3046\u3068\u304D\u306E\u5BFE\u7B56\u306E\u3064\u3082\
    \u308A\n  ll KX = topbit(X) + 1;\n  ll KY = topbit(Y) + 1;\n\n  while (KX > 0\
    \ || KY > 0) {\n    vc<tuple<T, ll, ll>> nxt = cand;\n    auto upd = [&](ll x,\
    \ ll y) -> void {\n      if (0 <= x && x < X && 0 <= y && y < Y) {\n        u64\
    \ key = rnd * x + y;\n        if (MP.count(key)) return;\n        T z = eval(x,\
    \ y);\n        MP[key] = z;\n        nxt.eb(z, x, y);\n      }\n    };\n    ll\
    \ dx = 0, dy = 0;\n    if (KX < KY) {\n      --KY, dy = 1LL << KY;\n    } else\
    \ {\n      --KX, dx = 1LL << KX;\n    }\n    for (auto& [v, x, y] : cand) {\n\
    \      upd(x - dx, y - dy), upd(x + dx, y + dy);\n    }\n    swap(cand, nxt);\n\
    \    // UNIQUE(cand);\n    if (len(cand) > beam_width) {\n      nth_element(cand.begin(),\
    \ cand.begin() + beam_width, cand.end());\n      cand.resize(beam_width);\n  \
    \  }\n  }\n  auto [v, x, y] = *(min_element(all(cand)));\n  if (!MINIMIZE) v =\
    \ -v;\n  return {v, x1 + x, y1 + y};\n}\n"
  code: "#include \"other/bit.hpp\"\n#include \"ds/hashmap.hpp\"\n#include \"random/base.hpp\"\
    \n\n// \u3069\u306E\u304F\u3089\u3044\u4F7F\u3048\u308B\u3053\u3068\u304C\u3042\
    \u308B\u306E\u304B\u4E0D\u660E\n// https://atcoder.jp/contests/ajo2025-final/submissions/71727945\n\
    // return: f(x,y),x,y\ntemplate <typename T, bool MINIMIZE, typename F>\ntuple<T,\
    \ ll, ll> optimize_2d(ll x1, ll x2, ll y1, ll y2, F f, int beam_width) {\n  assert(x1\
    \ < x2 && y1 < y2);\n\n  HashMap<T> MP;\n  u64 rnd = RNG_64();\n  auto eval =\
    \ [&](ll x, ll y) -> T {\n    T ans = f(x1 + x, y1 + y);\n    if (!MINIMIZE) ans\
    \ = -ans;\n    return ans;\n  };\n\n  vc<tuple<T, ll, ll>> cand;\n  cand.eb(eval(0,\
    \ 0), 0, 0);\n\n  ll X = x2 - x1, Y = y2 - y1;\n\n  // \u30B9\u30B1\u30FC\u30EB\
    \u304C\u5168\u7136\u9055\u3046\u3068\u304D\u306E\u5BFE\u7B56\u306E\u3064\u3082\
    \u308A\n  ll KX = topbit(X) + 1;\n  ll KY = topbit(Y) + 1;\n\n  while (KX > 0\
    \ || KY > 0) {\n    vc<tuple<T, ll, ll>> nxt = cand;\n    auto upd = [&](ll x,\
    \ ll y) -> void {\n      if (0 <= x && x < X && 0 <= y && y < Y) {\n        u64\
    \ key = rnd * x + y;\n        if (MP.count(key)) return;\n        T z = eval(x,\
    \ y);\n        MP[key] = z;\n        nxt.eb(z, x, y);\n      }\n    };\n    ll\
    \ dx = 0, dy = 0;\n    if (KX < KY) {\n      --KY, dy = 1LL << KY;\n    } else\
    \ {\n      --KX, dx = 1LL << KX;\n    }\n    for (auto& [v, x, y] : cand) {\n\
    \      upd(x - dx, y - dy), upd(x + dx, y + dy);\n    }\n    swap(cand, nxt);\n\
    \    // UNIQUE(cand);\n    if (len(cand) > beam_width) {\n      nth_element(cand.begin(),\
    \ cand.begin() + beam_width, cand.end());\n      cand.resize(beam_width);\n  \
    \  }\n  }\n  auto [v, x, y] = *(min_element(all(cand)));\n  if (!MINIMIZE) v =\
    \ -v;\n  return {v, x1 + x, y1 + y};\n}"
  dependsOn:
  - other/bit.hpp
  - ds/hashmap.hpp
  - random/base.hpp
  isVerificationFile: false
  path: other/optimize_2d.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:41:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/optimize_2d.hpp
layout: document
redirect_from:
- /library/other/optimize_2d.hpp
- /library/other/optimize_2d.hpp.html
title: other/optimize_2d.hpp
---
