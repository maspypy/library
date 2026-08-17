---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/problem/382
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
    \ : (1ULL << n) - 1; }\n#line 2 \"ds/fastset.hpp\"\n\n// 64-ary tree\n// space:\
    \ (N/63) * u64\nstruct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0,\
    \ log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\
    \n  int size() { return n; }\n\n  void fill_one() {\n    int cur = n;\n    for\
    \ (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i]\
    \ = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n\
    \    }\n  }\n\n  template <typename F>\n  FastSet(int n, F f) {\n    build(n,\
    \ f);\n  }\n\n  void build(int m) {\n    seg.clear();\n    n = m;\n    do {\n\
    \      seg.push_back(vc<u64>((m + B - 1) / B));\n      m = (m + B - 1) / B;\n\
    \    } while (m > 1);\n    log = len(seg);\n  }\n  template <typename F>\n  void\
    \ build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i / B] |= u64(f(i))\
    \ << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h])) {\n        seg[h\
    \ + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n    }\n  }\n\n  bool\
    \ operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\n  void insert(int\
    \ i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h < log; h++) {\n  \
    \    seg[h][i / B] |= u64(1) << (i % B), i /= B;\n    }\n  }\n  void add(int i)\
    \ { insert(i); }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n    u64\
    \ x = 0;\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] &= ~(u64(1)\
    \ << (i % B));\n      seg[h][i / B] |= x << (i % B);\n      x = bool(seg[h][i\
    \ / B]);\n      i /= B;\n    }\n  }\n  void remove(int i) { erase(i); }\n\n  //\
    \ min[x,n) or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i, 0);\n\
    \    for (int h = 0; h < log; h++) {\n      if (i / B == seg[h].size()) break;\n\
    \      u64 d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i = i / B +\
    \ 1;\n        continue;\n      }\n      i += lowbit(d);\n      for (int g = h\
    \ - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n\
    \  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for\
    \ (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n\
    \      }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--)\
    \ {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return\
    \ i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int r) { return next(l)\
    \ < r; }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int\
    \ r, F f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n  }\n\n\
    \  void reset() {\n    enumerate(0, n, [&](int i) -> void { erase(i); });\n  }\n\
    \n  string to_string() {\n    string s(n, '?');\n    for (int i = 0; i < n; ++i)\
    \ s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n#line 2 \"bigint/redundant_binary_number.hpp\"\
    \n\n// 2^i \u3092\u8DB3\u3057\u305F\u308A\u5F15\u3044\u305F\u308A. k-th digit\
    \ \u306E\u53D6\u5F97.\n// fastset \u4F7F\u7528\u7248.\n// https://qoj.ac/problem/382\n\
    struct Redundant_Binary_Number_Fast {\n  const int n;\n  vc<char> dat;\n  FastSet\
    \ S;\n  Redundant_Binary_Number_Fast(int n) : n(n), dat(n), S(n) {}\n\n  int sgn()\
    \ {\n    int k = S.prev(n - 1);\n    return (k == -1 ? 0 : dat[k]);\n  }\n\n \
    \ // k-th bit in [0,1]\n  int kth(int k) {\n    int j = S.prev(k - 1);\n    int\
    \ x = dat[k];\n    int y = (j == -1 ? 0 : dat[j]);\n    if (x == 0) return (y\
    \ >= 0 ? 0 : 1);\n    return (y >= 0 ? 1 : 0);\n  }\n\n  // 2^k * x \u3092\u8DB3\
    \u3059\n  void add(int k, ll x) {\n    while (x) {\n      x += dat[k];\n     \
    \ dat[k] = x % 2;\n      if (dat[k] == 0) {\n        S.erase(k);\n      } else\
    \ {\n        S.insert(k);\n      }\n      ++k, x /= 2;\n    }\n  }\n\n  // 2^k\
    \ \u3092\u8DB3\u3059\n  void add(int k) { add(k, 1); }\n  void sub(int k) { add(k,\
    \ -1); }\n\n  string to_string() {\n    string ANS;\n    for (auto& x: dat) {\
    \ ANS += (x == 0 ? '0' : (x == 1 ? '+' : '-')); }\n    return ANS;\n  }\n};\n\n\
    // 2^i \u3092\u8DB3\u3057\u305F\u308A\u5F15\u3044\u305F\u308A. k-th digit \u306E\
    \u53D6\u5F97.\ntemplate <typename KETA_TYPE = int>\nstruct Redundant_Binary_Number\
    \ {\n  using T = KETA_TYPE;\n  map<T, char> dat;\n  Redundant_Binary_Number()\
    \ {}\n\n  int sgn() {\n    auto [k, x] = prev(infty<T>);\n    return x;\n  }\n\
    \n  // k-th bit in [0,1]\n  int kth(T k) {\n    int x = (dat.count(k) ? dat[k]\
    \ : 0);\n    int y = prev(k - 1).se;\n    if (x == 0) return (y >= 0 ? 0 : 1);\n\
    \    return (y >= 0 ? 1 : 0);\n  }\n\n  // 2^k * x \u3092\u8DB3\u3059\n  void\
    \ add(T k, ll x) {\n    while (x) {\n      x += dat[k];\n      if (x % 2 == 0)\
    \ {\n        dat.erase(k);\n      } else {\n        dat[k] = x % 2;\n      }\n\
    \      ++k, x /= 2;\n    }\n  }\n\n  // 2^k \u3092\u8DB3\u3059\n  void add(T k)\
    \ { add_inner(k, 1); }\n  void sub(T k) { add_inner(k, -1); }\n\nprivate:\n  pair<T,\
    \ char> prev(T k) {\n    while (1) {\n      auto it = dat.upper_bound(k);\n  \
    \    if (it == dat.begin()) return {-1, 0};\n      it = ::prev(it);\n      return\
    \ *it;\n    }\n  }\n};\n"
  code: "#include \"ds/fastset.hpp\"\n\n// 2^i \u3092\u8DB3\u3057\u305F\u308A\u5F15\
    \u3044\u305F\u308A. k-th digit \u306E\u53D6\u5F97.\n// fastset \u4F7F\u7528\u7248\
    .\n// https://qoj.ac/problem/382\nstruct Redundant_Binary_Number_Fast {\n  const\
    \ int n;\n  vc<char> dat;\n  FastSet S;\n  Redundant_Binary_Number_Fast(int n)\
    \ : n(n), dat(n), S(n) {}\n\n  int sgn() {\n    int k = S.prev(n - 1);\n    return\
    \ (k == -1 ? 0 : dat[k]);\n  }\n\n  // k-th bit in [0,1]\n  int kth(int k) {\n\
    \    int j = S.prev(k - 1);\n    int x = dat[k];\n    int y = (j == -1 ? 0 : dat[j]);\n\
    \    if (x == 0) return (y >= 0 ? 0 : 1);\n    return (y >= 0 ? 1 : 0);\n  }\n\
    \n  // 2^k * x \u3092\u8DB3\u3059\n  void add(int k, ll x) {\n    while (x) {\n\
    \      x += dat[k];\n      dat[k] = x % 2;\n      if (dat[k] == 0) {\n       \
    \ S.erase(k);\n      } else {\n        S.insert(k);\n      }\n      ++k, x /=\
    \ 2;\n    }\n  }\n\n  // 2^k \u3092\u8DB3\u3059\n  void add(int k) { add(k, 1);\
    \ }\n  void sub(int k) { add(k, -1); }\n\n  string to_string() {\n    string ANS;\n\
    \    for (auto& x: dat) { ANS += (x == 0 ? '0' : (x == 1 ? '+' : '-')); }\n  \
    \  return ANS;\n  }\n};\n\n// 2^i \u3092\u8DB3\u3057\u305F\u308A\u5F15\u3044\u305F\
    \u308A. k-th digit \u306E\u53D6\u5F97.\ntemplate <typename KETA_TYPE = int>\n\
    struct Redundant_Binary_Number {\n  using T = KETA_TYPE;\n  map<T, char> dat;\n\
    \  Redundant_Binary_Number() {}\n\n  int sgn() {\n    auto [k, x] = prev(infty<T>);\n\
    \    return x;\n  }\n\n  // k-th bit in [0,1]\n  int kth(T k) {\n    int x = (dat.count(k)\
    \ ? dat[k] : 0);\n    int y = prev(k - 1).se;\n    if (x == 0) return (y >= 0\
    \ ? 0 : 1);\n    return (y >= 0 ? 1 : 0);\n  }\n\n  // 2^k * x \u3092\u8DB3\u3059\
    \n  void add(T k, ll x) {\n    while (x) {\n      x += dat[k];\n      if (x %\
    \ 2 == 0) {\n        dat.erase(k);\n      } else {\n        dat[k] = x % 2;\n\
    \      }\n      ++k, x /= 2;\n    }\n  }\n\n  // 2^k \u3092\u8DB3\u3059\n  void\
    \ add(T k) { add_inner(k, 1); }\n  void sub(T k) { add_inner(k, -1); }\n\nprivate:\n\
    \  pair<T, char> prev(T k) {\n    while (1) {\n      auto it = dat.upper_bound(k);\n\
    \      if (it == dat.begin()) return {-1, 0};\n      it = ::prev(it);\n      return\
    \ *it;\n    }\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: bigint/redundant_binary_number.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bigint/redundant_binary_number.hpp
layout: document
redirect_from:
- /library/bigint/redundant_binary_number.hpp
- /library/bigint/redundant_binary_number.hpp.html
title: bigint/redundant_binary_number.hpp
---
