---
data:
  _extendedDependsOn:
  - icon: ':x:'
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
  bundledCode: "#line 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63)\
    \ * u64\r\nstruct FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\
    \n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\
    \n  int size() { return n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n,\
    \ F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\
    \n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n\
    \      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n\
    \  }\r\n  template <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\
    \n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log -\
    \ 1) {\r\n      FOR(i, len(seg[h])) { seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B); }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const { return\
    \ seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    assert(0 <=\
    \ i && i < n);\r\n    for (int h = 0; h < log; h++) { seg[h][i / B] |= u64(1)\
    \ << (i % B), i /= B; }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int\
    \ i) {\r\n    assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0;\
    \ h < log; h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i\
    \ / B] |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n\
    \    }\r\n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\
    \n  int next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int\
    \ h = 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n     \
    \ u64 d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B +\
    \ 1;\r\n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int\
    \ g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i\
    \ / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n\
    \  // max [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if\
    \ (i >= n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i ==\
    \ -1) break;\r\n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d)\
    \ {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  string to_string() {\r\n    string s(n, '?');\r\n    for (int i = 0; i < n;\
    \ ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n};\n#line 2\
    \ \"bigint/redundant_binary_number.hpp\"\n\n// 2^i \u3092\u8DB3\u3057\u305F\u308A\
    \u5F15\u3044\u305F\u308A. k-th digit \u306E\u53D6\u5F97.\n// fastset \u4F7F\u7528\
    \u7248.\n// https://qoj.ac/problem/382\nstruct Redundant_Binary_Number_Fast {\n\
    \  const int n;\n  vc<char> dat;\n  FastSet S;\n  Redundant_Binary_Number_Fast(int\
    \ n) : n(n), dat(n), S(n) {}\n\n  int sgn() {\n    int k = S.prev(n - 1);\n  \
    \  return (k == -1 ? 0 : dat[k]);\n  }\n\n  // k-th bit in [0,1]\n  int kth(int\
    \ k) {\n    int j = S.prev(k - 1);\n    int x = dat[k];\n    int y = (j == -1\
    \ ? 0 : dat[j]);\n    if (x == 0) return (y >= 0 ? 0 : 1);\n    return (y >= 0\
    \ ? 1 : 0);\n  }\n\n  // 2^k * x \u3092\u8DB3\u3059\n  void add(int k, ll x) {\n\
    \    while (x) {\n      x += dat[k];\n      dat[k] = x % 2;\n      if (dat[k]\
    \ == 0) {\n        S.erase(k);\n      } else {\n        S.insert(k);\n      }\n\
    \      ++k, x /= 2;\n    }\n  }\n\n  // 2^k \u3092\u8DB3\u3059\n  void add(int\
    \ k) { add(k, 1); }\n  void sub(int k) { add(k, -1); }\n\n  string to_string()\
    \ {\n    string ANS;\n    for (auto& x: dat) { ANS += (x == 0 ? '0' : (x == 1\
    \ ? '+' : '-')); }\n    return ANS;\n  }\n};\n\n// 2^i \u3092\u8DB3\u3057\u305F\
    \u308A\u5F15\u3044\u305F\u308A. k-th digit \u306E\u53D6\u5F97.\ntemplate <typename\
    \ KETA_TYPE = int>\nstruct Redundant_Binary_Number {\n  using T = KETA_TYPE;\n\
    \  map<T, char> dat;\n  Redundant_Binary_Number() {}\n\n  int sgn() {\n    auto\
    \ [k, x] = prev(infty<T>);\n    return x;\n  }\n\n  // k-th bit in [0,1]\n  int\
    \ kth(T k) {\n    int x = (dat.count(k) ? dat[k] : 0);\n    int y = prev(k - 1).se;\n\
    \    if (x == 0) return (y >= 0 ? 0 : 1);\n    return (y >= 0 ? 1 : 0);\n  }\n\
    \n  // 2^k * x \u3092\u8DB3\u3059\n  void add(T k, ll x) {\n    while (x) {\n\
    \      x += dat[k];\n      if (x % 2 == 0) {\n        dat.erase(k);\n      } else\
    \ {\n        dat[k] = x % 2;\n      }\n      ++k, x /= 2;\n    }\n  }\n\n  //\
    \ 2^k \u3092\u8DB3\u3059\n  void add(T k) { add_inner(k, 1); }\n  void sub(T k)\
    \ { add_inner(k, -1); }\n\nprivate:\n  pair<T, char> prev(T k) {\n    while (1)\
    \ {\n      auto it = dat.upper_bound(k);\n      if (it == dat.begin()) return\
    \ {-1, 0};\n      it = ::prev(it);\n      return *it;\n    }\n  }\n};\n"
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
  timestamp: '2024-10-28 19:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bigint/redundant_binary_number.hpp
layout: document
redirect_from:
- /library/bigint/redundant_binary_number.hpp
- /library/bigint/redundant_binary_number.hpp.html
title: bigint/redundant_binary_number.hpp
---
