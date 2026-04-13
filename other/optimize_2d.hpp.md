---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
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
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\
    \u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\
    \u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n   \
    \ used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size()\
    \ { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int\
    \ i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask)\
    \ {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if\
    \ (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"random/base.hpp\"\n\nu64\
    \ RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 3 \"other/optimize_2d.hpp\"\n\n// \u3069\u306E\u304F\
    \u3089\u3044\u4F7F\u3048\u308B\u3053\u3068\u304C\u3042\u308B\u306E\u304B\u4E0D\
    \u660E\n// https://atcoder.jp/contests/ajo2025-final/submissions/71727945\n//\
    \ return: f(x,y),x,y\ntemplate <typename T, bool MINIMIZE, typename F>\ntuple<T,\
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
  code: "#include \"ds/hashmap.hpp\"\n#include \"random/base.hpp\"\n\n// \u3069\u306E\
    \u304F\u3089\u3044\u4F7F\u3048\u308B\u3053\u3068\u304C\u3042\u308B\u306E\u304B\
    \u4E0D\u660E\n// https://atcoder.jp/contests/ajo2025-final/submissions/71727945\n\
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
  - ds/hashmap.hpp
  - random/base.hpp
  isVerificationFile: false
  path: other/optimize_2d.hpp
  requiredBy: []
  timestamp: '2026-02-03 22:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/optimize_2d.hpp
layout: document
redirect_from:
- /library/other/optimize_2d.hpp
- /library/other/optimize_2d.hpp.html
title: other/optimize_2d.hpp
---
