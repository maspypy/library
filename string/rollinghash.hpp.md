---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/263.test.cpp
    title: test/yukicoder/263.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"string/rollinghash.hpp\"\
    \n\nstruct RollingHash {\n  static const uint64_t mod = (1ull << 61ull) - 1;\n\
    \  const uint64_t base;\n  vector<uint64_t> power;\n\n  static inline uint64_t\
    \ add(uint64_t a, uint64_t b) {\n    if ((a += b) >= mod) a -= mod;\n    return\
    \ a;\n  }\n\n  static inline uint64_t mul(uint64_t a, uint64_t b) {\n    const\
    \ uint64_t MASK30 = (1LL << 30) - 1;\n    const uint64_t MASK31 = (1LL << 31)\
    \ - 1;\n    const uint64_t MASK61 = (1LL << 61) - 1;\n    uint64_t au = a >> 31,\
    \ ad = a & MASK31;\n    uint64_t bu = b >> 31, bd = b & MASK31;\n    uint64_t\
    \ x = ad * bu + au * bd;\n    uint64_t xu = x >> 30, xd = x & MASK30;\n    x =\
    \ au * bu * 2 + xu + (xd << 31) + ad * bd;\n    xu = x >> 61, xd = x & MASK61;\n\
    \    x = xu + xd;\n    if (x >= MASK61) x -= MASK61;\n    return x;\n  }\n\n \
    \ static inline uint64_t generate_base() { return RNG(mod); }\n\n  inline void\
    \ expand(size_t sz) {\n    if (power.size() < sz + 1) {\n      int pre_sz = (int)power.size();\n\
    \      power.resize(sz + 1);\n      for (int i = pre_sz - 1; i < sz; i++) {\n\
    \        power[i + 1] = mul(power[i], base);\n      }\n    }\n  }\n\n  explicit\
    \ RollingHash(uint64_t base = generate_base())\n      : base(base), power{1} {}\n\
    \n  template <typename STRING>\n  vector<uint64_t> build(const STRING& s) const\
    \ {\n    int sz = s.size();\n    vector<uint64_t> hashed(sz + 1);\n    for (int\
    \ i = 0; i < sz; i++) {\n      hashed[i + 1] = add(mul(hashed[i], base), s[i]);\n\
    \    }\n    return hashed;\n  }\n\n  uint64_t query(const vector<uint64_t>& s,\
    \ int l, int r) {\n    expand(r - l);\n    return add(s[r], mod - mul(s[l], power[r\
    \ - l]));\n  }\n\n  uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {\n\
    \    expand(h2len);\n    return add(mul(h1, power[h2len]), h2);\n  }\n\n  int\
    \ lcp(const vector<uint64_t>& a, int l1, int r1, const vector<uint64_t>& b,\n\
    \          int l2, int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int low\
    \ = 0, high = len + 1;\n    while (high - low > 1) {\n      int mid = (low + high)\
    \ / 2;\n      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n        low\
    \ = mid;\n      else\n        high = mid;\n    }\n    return low;\n  }\n};\n"
  code: "#pragma once\n#include \"random/base.hpp\"\n\nstruct RollingHash {\n  static\
    \ const uint64_t mod = (1ull << 61ull) - 1;\n  const uint64_t base;\n  vector<uint64_t>\
    \ power;\n\n  static inline uint64_t add(uint64_t a, uint64_t b) {\n    if ((a\
    \ += b) >= mod) a -= mod;\n    return a;\n  }\n\n  static inline uint64_t mul(uint64_t\
    \ a, uint64_t b) {\n    const uint64_t MASK30 = (1LL << 30) - 1;\n    const uint64_t\
    \ MASK31 = (1LL << 31) - 1;\n    const uint64_t MASK61 = (1LL << 61) - 1;\n  \
    \  uint64_t au = a >> 31, ad = a & MASK31;\n    uint64_t bu = b >> 31, bd = b\
    \ & MASK31;\n    uint64_t x = ad * bu + au * bd;\n    uint64_t xu = x >> 30, xd\
    \ = x & MASK30;\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\n    xu = x\
    \ >> 61, xd = x & MASK61;\n    x = xu + xd;\n    if (x >= MASK61) x -= MASK61;\n\
    \    return x;\n  }\n\n  static inline uint64_t generate_base() { return RNG(mod);\
    \ }\n\n  inline void expand(size_t sz) {\n    if (power.size() < sz + 1) {\n \
    \     int pre_sz = (int)power.size();\n      power.resize(sz + 1);\n      for\
    \ (int i = pre_sz - 1; i < sz; i++) {\n        power[i + 1] = mul(power[i], base);\n\
    \      }\n    }\n  }\n\n  explicit RollingHash(uint64_t base = generate_base())\n\
    \      : base(base), power{1} {}\n\n  template <typename STRING>\n  vector<uint64_t>\
    \ build(const STRING& s) const {\n    int sz = s.size();\n    vector<uint64_t>\
    \ hashed(sz + 1);\n    for (int i = 0; i < sz; i++) {\n      hashed[i + 1] = add(mul(hashed[i],\
    \ base), s[i]);\n    }\n    return hashed;\n  }\n\n  uint64_t query(const vector<uint64_t>&\
    \ s, int l, int r) {\n    expand(r - l);\n    return add(s[r], mod - mul(s[l],\
    \ power[r - l]));\n  }\n\n  uint64_t combine(uint64_t h1, uint64_t h2, size_t\
    \ h2len) {\n    expand(h2len);\n    return add(mul(h1, power[h2len]), h2);\n \
    \ }\n\n  int lcp(const vector<uint64_t>& a, int l1, int r1, const vector<uint64_t>&\
    \ b,\n          int l2, int r2) {\n    int len = min(r1 - l1, r2 - l2);\n    int\
    \ low = 0, high = len + 1;\n    while (high - low > 1) {\n      int mid = (low\
    \ + high) / 2;\n      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n\
    \        low = mid;\n      else\n        high = mid;\n    }\n    return low;\n\
    \  }\n};\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2022-10-23 11:21:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/263.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
