---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/problem/382
  bundledCode: "#line 1 \"ds/fastset.hpp\"\n// 64-ary tree\n// space: (N/63) * u64\n\
    struct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0, log = 0;\n  vvc<u64>\
    \ seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\n  int size() { return\
    \ n; }\n\n  void fill_one() {\n    int cur = n;\n    for (auto& vs : seg) {\n\
    \      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i] = -1ull;\n      if\
    \ (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n    }\n  }\n\n  template\
    \ <typename F>\n  FastSet(int n, F f) {\n    build(n, f);\n  }\n\n  void build(int\
    \ m) {\n    seg.clear();\n    n = m;\n    do {\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\n      m = (m + B - 1) / B;\n    } while (m > 1);\n    log =\
    \ len(seg);\n  }\n  template <typename F>\n  void build(int n, F f) {\n    build(n);\n\
    \    FOR(i, n) { seg[0][i / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log\
    \ - 1) {\n      FOR(i, len(seg[h])) {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\n      }\n    }\n  }\n\n  bool operator[](int i) const {\n    assert(0\
    \ <= i && i < n);\n    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int\
    \ i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h < log; h++) {\n  \
    \    u64& x = seg[h][i / B];\n      u64 mask = u64(1) << (i % B);\n      if (x\
    \ & mask) return;\n      x |= mask;\n      i /= B;\n    }\n  }\n  void add(int\
    \ i) { insert(i); }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n   \
    \ for (int h = 0; h < log; h++) {\n      u64& x = seg[h][i / B];\n      u64 mask\
    \ = u64(1) << (i % B);\n      if (!(x & mask)) return;\n      x ^= mask;\n   \
    \   if (x) return;\n      i /= B;\n    }\n  }\n  void remove(int i) { erase(i);\
    \ }\n\n  // min[x,n) or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i,\
    \ 0);\n    for (int h = 0; h < log; h++) {\n      if (i / B == seg[h].size())\
    \ break;\n      u64 d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i\
    \ = i / B + 1;\n        continue;\n      }\n      i += lowbit(d);\n      for (int\
    \ g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n\
    \      }\n      return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n\
    \  int prev(int i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for\
    \ (int h = 0; h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n\
    \      }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--)\
    \ {\n        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return\
    \ i;\n    }\n    return -1;\n  }\n\n  bool any(int l, int r) {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    return next(l) < r;\n  }\n\n  // [l, r). erase=true\
    \ \u306E\u3068\u304D\u3001callback \u5185\u304B\u3089 this \u3092\u5909\u66F4\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\u3002\n  template <typename F>\n  void enumerate(int\
    \ l, int r, F f, bool erase = false) {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    if (!erase) {\n      for (int x = next(l); x < r; x = next(x + 1)) f(x);\n\
    \      return;\n    }\n    for (int x = next(l); x < r;) {\n      int w = x /\
    \ B;\n      int lo = max(l, w * int(B)) - w * int(B);\n      int hi = min(r, (w\
    \ + 1) * int(B)) - w * int(B);\n      u64 erase_bits = seg[0][w] & (full_mask(hi)\
    \ & ~full_mask(lo));\n      u64 bits = erase_bits;\n      while (bits) {\n   \
    \     int k = lowbit(bits);\n        f(w * int(B) + k);\n        bits ^= u64(1)\
    \ << k;\n      }\n      seg[0][w] ^= erase_bits;\n      if (!seg[0][w]) propagate_empty_word(w);\n\
    \      x = next(min(r, (w + 1) * int(B)));\n    }\n  }\n\n  void reset() {\n \
    \   int x = next(0);\n    while (x < n) {\n      int w = x / B;\n      seg[0][w]\
    \ = 0;\n      propagate_empty_word(w);\n      x = next(min(n, (w + 1) * int(B)));\n\
    \    }\n  }\n\n  string to_string() {\n    string s(n, '?');\n    for (int i =\
    \ 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n\n private:\n\
    \  // seg[0][w] \u304C 0 \u306B\u306A\u3063\u305F\u5F8C\u306B\u547C\u3076\u3002\
    \n  void propagate_empty_word(int i) {\n    for (int h = 1; h < log; ++h) {\n\
    \      u64& y = seg[h][i / B];\n      u64 mask = u64(1) << (i % B);\n      y ^=\
    \ mask;\n      if (y) break;\n      i /= B;\n    }\n  }\n};\n#line 2 \"bigint/redundant_binary_number.hpp\"\
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
  isVerificationFile: false
  path: bigint/redundant_binary_number.hpp
  requiredBy: []
  timestamp: '2026-10-05 00:23:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bigint/redundant_binary_number.hpp
layout: document
redirect_from:
- /library/bigint/redundant_binary_number.hpp
- /library/bigint/redundant_binary_number.hpp.html
title: bigint/redundant_binary_number.hpp
---
