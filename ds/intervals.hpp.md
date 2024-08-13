---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/5_atcoder/abc256d.test.cpp
    title: test/5_atcoder/abc256d.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256ex.test.cpp
    title: test/5_atcoder/abc256ex.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256ex2.test.cpp
    title: test/5_atcoder/abc256ex2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/1638/problem/E
  bundledCode: "#line 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63)\
    \ * u64\r\nstruct FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\
    \n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\
    \n  int size() { return n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n,\
    \ F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\
    \n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n\
    \      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n\
    \  }\r\n  template <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\
    \n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log -\
    \ 1) {\r\n      FOR(i, len(seg[h])) {\r\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\r\n      }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const\
    \ { return seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    for\
    \ (int h = 0; h < log; h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /=\
    \ B;\r\n    }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i)\
    \ {\r\n    u64 x = 0;\r\n    for (int h = 0; h < log; h++) {\r\n      seg[h][i\
    \ / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B] |= x << (i % B);\r\n  \
    \    x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int next(int i) {\r\n    assert(i\
    \ <= n);\r\n    chmax(i, 0);\r\n    for (int h = 0; h < log; h++) {\r\n      if\
    \ (i / B == seg[h].size()) break;\r\n      u64 d = seg[h][i / B] >> (i % B);\r\
    \n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\n      }\r\n\
    \      i += lowbit(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n       \
    \ i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\
    \n    }\r\n    return n;\r\n  }\r\n\r\n  // max [0,x], or -1\r\n  int prev(int\
    \ i) {\r\n    assert(i >= -1);\r\n    if (i >= n) i = n - 1;\r\n    for (int h\
    \ = 0; h < log; h++) {\r\n      if (i == -1) break;\r\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\r\n      if (!d) {\r\n        i = i / B - 1;\r\n     \
    \   continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\n      for (int g\
    \ = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += topbit(seg[g][i /\
    \ B]);\r\n      }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n\
    \  bool any(int l, int r) { return next(l) < r; }\r\n\r\n  // [l, r)\r\n  template\
    \ <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n    for (int x = next(l);\
    \ x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n  string to_string() {\r\n    string\
    \ s(n, '?');\r\n    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\
    \n    return s;\r\n  }\r\n};\n#line 2 \"ds/intervals.hpp\"\n\n// FastSet \u3067\
    \u9AD8\u901F\u5316\u3057\u305F\u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast\
    \ {\n  const int LLIM, RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\
    \u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n\
    \  int total_len;\n  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n\
    \      : LLIM(0),\n        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n\
    \        total_len(0),\n        dat(N, none_val),\n        ss(N) {\n    ss.insert(0);\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<int, int, T> get(int x, bool ERASE) {\n    int l = ss.prev(x);\n\
    \    int r = ss.next(x + 1);\n    T t = dat[l];\n    if (t != none_val && ERASE)\
    \ {\n      --total_num, total_len -= r - l;\n      dat[l] = none_val;\n      merge_at(l);\n\
    \      merge_at(r);\n    }\n    return {l, r, t};\n  }\n\n  // [L, R) \u5185\u306E\
    \u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\n  // f(l,r,x)\n  template <typename\
    \ F>\n  void enumerate_range(int L, int R, F f, bool ERASE) {\n    assert(LLIM\
    \ <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    if (!ERASE) {\n\
    \      int l = ss.prev(L);\n      while (l < R) {\n        int r = ss.next(l +\
    \ 1);\n        f(max(l, L), min(r, R), dat[l]);\n        l = r;\n      }\n   \
    \   return;\n    }\n    // \u534A\u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\
    \n    int p = ss.prev(L);\n    if (p < L) {\n      ss.insert(L);\n      dat[L]\
    \ = dat[p];\n      if (dat[L] != none_val) ++total_num;\n    }\n    p = ss.next(R);\n\
    \    if (R < p) {\n      dat[R] = dat[ss.prev(R)];\n      ss.insert(R);\n    \
    \  if (dat[R] != none_val) ++total_num;\n    }\n    p = L;\n    while (p < R)\
    \ {\n      int q = ss.next(p + 1);\n      T x = dat[p];\n      f(p, q, x);\n \
    \     if (dat[p] != none_val) --total_num, total_len -= q - p;\n      ss.erase(p);\n\
    \      p = q;\n    }\n    ss.insert(L);\n    dat[L] = none_val;\n  }\n\n  void\
    \ set(int L, int R, T t) {\n    if (L == R) return;\n    enumerate_range(\n  \
    \      L, R, [](int l, int r, T x) -> void {}, true);\n    ss.insert(L);\n   \
    \ dat[L] = t;\n    if (t != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n\
    \    merge_at(R);\n  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n\
    \    enumerate_range(0, RLIM, f, false);\n  }\n\n  void merge_at(int p) {\n  \
    \  if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p - 1);\n    if (dat[p]\
    \ == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n      ss.erase(p);\n\
    \    }\n  }\n};\n\n// https://codeforces.com/contest/1638/problem/E\n// \u6301\
    \u3064\u5024\u306E\u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n\
    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\
    \u5B9A\u3059\u308B\ntemplate <typename T, typename X = ll>\nstruct Intervals {\n\
    \  static constexpr X LLIM = -infty<X>;\n  static constexpr X RLIM = infty<X>;\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n  }\n\n  // x \u3092\
    \u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97 l, r, t\n  tuple<X,\
    \ X, T> get(X x, bool ERASE) {\n    auto it2 = dat.upper_bound(x);\n    auto it1\
    \ = prev(it2);\n    auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n    if (tl\
    \ != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n      dat[l]\
    \ = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n    return {l, r,\
    \ tl};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\
    \ f(l, r, t)\n  template <typename F>\n  void enumerate_range(X L, X R, F f, bool\
    \ ERASE) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n    if (!ERASE) {\n\
    \      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi < R) {\n   \
    \     auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi, R), (*it).se);\n\
    \        it = it2;\n      }\n      return;\n    }\n    // \u534A\u7AEF\u306A\u3068\
    \u3053\u308D\u306E\u5206\u5272\n    auto p = prev(dat.upper_bound(L));\n    if\
    \ ((*p).fi < L) {\n      dat[L] = (*p).se;\n      if (dat[L] != none_val) ++total_num;\n\
    \    }\n    p = dat.lower_bound(R);\n    if (R < (*p).fi) {\n      T t = (*prev(p)).se;\n\
    \      dat[R] = t;\n      if (t != none_val) ++total_num;\n    }\n    p = dat.lower_bound(L);\n\
    \    while (1) {\n      if ((*p).fi >= R) break;\n      auto q = next(p);\n  \
    \    T t = (*p).se;\n      f((*p).fi, (*q).fi, t);\n      if (t != none_val) --total_num,\
    \ total_len -= (*q).fi - (*p).fi;\n      p = dat.erase(p);\n    }\n    dat[L]\
    \ = none_val;\n  }\n\n  void set(X L, X R, T t) {\n    assert(L <= R);\n    if\
    \ (L == R) return;\n    enumerate_range(\n        L, R, [](int l, int r, T x)\
    \ -> void {}, true);\n    dat[L] = t;\n    if (t != none_val) total_num++, total_len\
    \ += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n  template <typename F>\n\
    \  void enumerate_all(F f) {\n    enumerate_range(LLIM, RLIM, f, false);\n  }\n\
    \n  void merge_at(X p) {\n    if (p == LLIM || RLIM == p) return;\n    auto itp\
    \ = dat.lower_bound(p);\n    assert((*itp).fi == p);\n    auto itq = prev(itp);\n\
    \    if ((*itp).se == (*itq).se) {\n      if ((*itp).se != none_val) --total_num;\n\
    \      dat.erase(itp);\n    }\n  }\n};\n"
  code: "#include \"ds/fastset.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\
    \u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const int LLIM,\
    \ RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\
    \u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int total_len;\n\
    \  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n      : LLIM(0),\n\
    \        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n      \
    \  total_len(0),\n        dat(N, none_val),\n        ss(N) {\n    ss.insert(0);\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<int, int, T> get(int x, bool ERASE) {\n    int l = ss.prev(x);\n\
    \    int r = ss.next(x + 1);\n    T t = dat[l];\n    if (t != none_val && ERASE)\
    \ {\n      --total_num, total_len -= r - l;\n      dat[l] = none_val;\n      merge_at(l);\n\
    \      merge_at(r);\n    }\n    return {l, r, t};\n  }\n\n  // [L, R) \u5185\u306E\
    \u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\n  // f(l,r,x)\n  template <typename\
    \ F>\n  void enumerate_range(int L, int R, F f, bool ERASE) {\n    assert(LLIM\
    \ <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    if (!ERASE) {\n\
    \      int l = ss.prev(L);\n      while (l < R) {\n        int r = ss.next(l +\
    \ 1);\n        f(max(l, L), min(r, R), dat[l]);\n        l = r;\n      }\n   \
    \   return;\n    }\n    // \u534A\u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\
    \n    int p = ss.prev(L);\n    if (p < L) {\n      ss.insert(L);\n      dat[L]\
    \ = dat[p];\n      if (dat[L] != none_val) ++total_num;\n    }\n    p = ss.next(R);\n\
    \    if (R < p) {\n      dat[R] = dat[ss.prev(R)];\n      ss.insert(R);\n    \
    \  if (dat[R] != none_val) ++total_num;\n    }\n    p = L;\n    while (p < R)\
    \ {\n      int q = ss.next(p + 1);\n      T x = dat[p];\n      f(p, q, x);\n \
    \     if (dat[p] != none_val) --total_num, total_len -= q - p;\n      ss.erase(p);\n\
    \      p = q;\n    }\n    ss.insert(L);\n    dat[L] = none_val;\n  }\n\n  void\
    \ set(int L, int R, T t) {\n    if (L == R) return;\n    enumerate_range(\n  \
    \      L, R, [](int l, int r, T x) -> void {}, true);\n    ss.insert(L);\n   \
    \ dat[L] = t;\n    if (t != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n\
    \    merge_at(R);\n  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n\
    \    enumerate_range(0, RLIM, f, false);\n  }\n\n  void merge_at(int p) {\n  \
    \  if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p - 1);\n    if (dat[p]\
    \ == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n      ss.erase(p);\n\
    \    }\n  }\n};\n\n// https://codeforces.com/contest/1638/problem/E\n// \u6301\
    \u3064\u5024\u306E\u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n\
    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\
    \u5B9A\u3059\u308B\ntemplate <typename T, typename X = ll>\nstruct Intervals {\n\
    \  static constexpr X LLIM = -infty<X>;\n  static constexpr X RLIM = infty<X>;\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n  }\n\n  // x \u3092\
    \u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97 l, r, t\n  tuple<X,\
    \ X, T> get(X x, bool ERASE) {\n    auto it2 = dat.upper_bound(x);\n    auto it1\
    \ = prev(it2);\n    auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n    if (tl\
    \ != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n      dat[l]\
    \ = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n    return {l, r,\
    \ tl};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\
    \ f(l, r, t)\n  template <typename F>\n  void enumerate_range(X L, X R, F f, bool\
    \ ERASE) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n    if (!ERASE) {\n\
    \      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi < R) {\n   \
    \     auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi, R), (*it).se);\n\
    \        it = it2;\n      }\n      return;\n    }\n    // \u534A\u7AEF\u306A\u3068\
    \u3053\u308D\u306E\u5206\u5272\n    auto p = prev(dat.upper_bound(L));\n    if\
    \ ((*p).fi < L) {\n      dat[L] = (*p).se;\n      if (dat[L] != none_val) ++total_num;\n\
    \    }\n    p = dat.lower_bound(R);\n    if (R < (*p).fi) {\n      T t = (*prev(p)).se;\n\
    \      dat[R] = t;\n      if (t != none_val) ++total_num;\n    }\n    p = dat.lower_bound(L);\n\
    \    while (1) {\n      if ((*p).fi >= R) break;\n      auto q = next(p);\n  \
    \    T t = (*p).se;\n      f((*p).fi, (*q).fi, t);\n      if (t != none_val) --total_num,\
    \ total_len -= (*q).fi - (*p).fi;\n      p = dat.erase(p);\n    }\n    dat[L]\
    \ = none_val;\n  }\n\n  void set(X L, X R, T t) {\n    assert(L <= R);\n    if\
    \ (L == R) return;\n    enumerate_range(\n        L, R, [](int l, int r, T x)\
    \ -> void {}, true);\n    dat[L] = t;\n    if (t != none_val) total_num++, total_len\
    \ += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n  template <typename F>\n\
    \  void enumerate_all(F f) {\n    enumerate_range(LLIM, RLIM, f, false);\n  }\n\
    \n  void merge_at(X p) {\n    if (p == LLIM || RLIM == p) return;\n    auto itp\
    \ = dat.lower_bound(p);\n    assert((*itp).fi == p);\n    auto itq = prev(itp);\n\
    \    if ((*itp).se == (*itq).se) {\n      if ((*itp).se != none_val) --total_num;\n\
    \      dat.erase(itp);\n    }\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/intervals.hpp
  requiredBy: []
  timestamp: '2024-04-27 11:55:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_atcoder/abc256d.test.cpp
  - test/5_atcoder/abc256ex.test.cpp
  - test/5_atcoder/abc256ex2.test.cpp
documentation_of: ds/intervals.hpp
layout: document
redirect_from:
- /library/ds/intervals.hpp
- /library/ds/intervals.hpp.html
title: ds/intervals.hpp
---
