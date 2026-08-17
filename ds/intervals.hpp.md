---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    - https://codeforces.com/contest/1638/problem/E
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
    \ s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n};\n#line 2 \"ds/intervals.hpp\"\
    \n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\u3082\u306E\ntemplate <typename\
    \ T>\nstruct Intervals_Fast {\n  const int LLIM, RLIM;\n  const T none_val;\n\
    \  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\
    \u5408\u8A08\n  int total_num;\n  int total_len;\n  vc<T> dat;\n  FastSet ss;\n\
    \n  Intervals_Fast(int N, T none_val)\n      : LLIM(0),\n        RLIM(N),\n  \
    \      none_val(none_val),\n        total_num(0),\n        total_len(0),\n   \
    \     dat(N, none_val),\n        ss(N) {\n    ss.insert(0);\n  }\n\n  // x \u3092\
    \u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97 l, r, t\n  tuple<int,\
    \ int, T> get(int x, bool ERASE = false) {\n    int l = ss.prev(x);\n    int r\
    \ = ss.next(x + 1);\n    T t = dat[l];\n    if (t != none_val && ERASE) {\n  \
    \    --total_num, total_len -= r - l;\n      dat[l] = none_val;\n      merge_at(l);\n\
    \      merge_at(r);\n    }\n    return {l, r, t};\n  }\n\n  // [L, R) \u5185\u306E\
    \u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\n  // f(l,r,x)\n  template <typename\
    \ F>\n  void enumerate_range(int L, int R, F f, bool ERASE = false) {\n    assert(LLIM\
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
    \ set(int L, int R, T t) {\n    if (L == R) return;\n    enumerate_range(L, R,\
    \ [](int l, int r, T x) -> void {}, true);\n    ss.insert(L);\n    dat[L] = t;\n\
    \    if (t != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n \
    \   merge_at(R);\n  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n\
    \    enumerate_range(0, RLIM, f, false);\n  }\n\n  void merge_at(int p) {\n  \
    \  if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p - 1);\n    if (dat[p]\
    \ == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n      ss.erase(p);\n\
    \    }\n  }\n\n  vc<T> get_all() {\n    vc<T> res(RLIM, none_val);\n    enumerate_all([&](int\
    \ a, int b, T t) -> void { FOR(i, a, b) res[i] = t; });\n    return res;\n  }\n\
    };\n\n// https://codeforces.com/contest/1638/problem/E\n// \u6301\u3064\u5024\u306E\
    \u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\
    \n// \u5148\u8AAD\u307F\u53EF\u80FD\u306A\u3089\u5EA7\u5727\u3057\u3066 fastset\
    \ \u306E\u65B9\u304C\u901F\u3044\ntemplate <typename T, typename X = ll>\nstruct\
    \ Intervals {\n  static constexpr X LLIM = -infty<X>;\n  static constexpr X RLIM\
    \ = infty<X>;\n  T none_val;\n  // const T none_val;\n  // none_val \u3067\u306A\
    \u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n\
    \  X total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val = 0) : none_val(none_val),\
    \ total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<X, X, T> get(X x, bool ERASE = false) {\n    auto it2 = dat.upper_bound(x);\n\
    \    auto it1 = prev(it2);\n    auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n\
    \    if (tl != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n\
    \      dat[l] = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n   \
    \ return {l, r, tl};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\
    \u53D6\u5F97 f(l, r, t)\n  template <typename F>\n  void enumerate_range(X L,\
    \ X R, F f, bool ERASE = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n\
    \    if (!ERASE) {\n      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi\
    \ < R) {\n        auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi,\
    \ R), (*it).se);\n        it = it2;\n      }\n      return;\n    }\n    // \u534A\
    \u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\n    auto p = prev(dat.upper_bound(L));\n\
    \    if ((*p).fi < L) {\n      dat[L] = (*p).se;\n      if (dat[L] != none_val)\
    \ ++total_num;\n    }\n    p = dat.lower_bound(R);\n    if (R < (*p).fi) {\n \
    \     T t = (*prev(p)).se;\n      dat[R] = t;\n      if (t != none_val) ++total_num;\n\
    \    }\n    p = dat.lower_bound(L);\n    while (1) {\n      if ((*p).fi >= R)\
    \ break;\n      auto q = next(p);\n      T t = (*p).se;\n      f((*p).fi, (*q).fi,\
    \ t);\n      if (t != none_val) --total_num, total_len -= (*q).fi - (*p).fi;\n\
    \      p = dat.erase(p);\n    }\n    dat[L] = none_val;\n  }\n\n  void set(X L,\
    \ X R, T t) {\n    assert(L <= R);\n    if (L == R) return;\n    enumerate_range(L,\
    \ R, [](int l, int r, T x) -> void {}, true);\n    dat[L] = t;\n    if (t != none_val)\
    \ total_num++, total_len += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n\
    \  template <typename F>\n  void enumerate_all(F f) {\n    enumerate_range(LLIM,\
    \ RLIM, f, false);\n  }\n\n  void merge_at(X p) {\n    if (p == LLIM || RLIM ==\
    \ p) return;\n    auto itp = dat.lower_bound(p);\n    assert((*itp).fi == p);\n\
    \    auto itq = prev(itp);\n    if ((*itp).se == (*itq).se) {\n      if ((*itp).se\
    \ != none_val) --total_num;\n      dat.erase(itp);\n    }\n  }\n};\n"
  code: "#include \"ds/fastset.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\
    \u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const int LLIM,\
    \ RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\
    \u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int total_len;\n\
    \  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n      : LLIM(0),\n\
    \        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n      \
    \  total_len(0),\n        dat(N, none_val),\n        ss(N) {\n    ss.insert(0);\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<int, int, T> get(int x, bool ERASE = false) {\n    int l =\
    \ ss.prev(x);\n    int r = ss.next(x + 1);\n    T t = dat[l];\n    if (t != none_val\
    \ && ERASE) {\n      --total_num, total_len -= r - l;\n      dat[l] = none_val;\n\
    \      merge_at(l);\n      merge_at(r);\n    }\n    return {l, r, t};\n  }\n\n\
    \  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\n  // f(l,r,x)\n\
    \  template <typename F>\n  void enumerate_range(int L, int R, F f, bool ERASE\
    \ = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n\
    \    if (!ERASE) {\n      int l = ss.prev(L);\n      while (l < R) {\n       \
    \ int r = ss.next(l + 1);\n        f(max(l, L), min(r, R), dat[l]);\n        l\
    \ = r;\n      }\n      return;\n    }\n    // \u534A\u7AEF\u306A\u3068\u3053\u308D\
    \u306E\u5206\u5272\n    int p = ss.prev(L);\n    if (p < L) {\n      ss.insert(L);\n\
    \      dat[L] = dat[p];\n      if (dat[L] != none_val) ++total_num;\n    }\n \
    \   p = ss.next(R);\n    if (R < p) {\n      dat[R] = dat[ss.prev(R)];\n     \
    \ ss.insert(R);\n      if (dat[R] != none_val) ++total_num;\n    }\n    p = L;\n\
    \    while (p < R) {\n      int q = ss.next(p + 1);\n      T x = dat[p];\n   \
    \   f(p, q, x);\n      if (dat[p] != none_val) --total_num, total_len -= q - p;\n\
    \      ss.erase(p);\n      p = q;\n    }\n    ss.insert(L);\n    dat[L] = none_val;\n\
    \  }\n\n  void set(int L, int R, T t) {\n    if (L == R) return;\n    enumerate_range(L,\
    \ R, [](int l, int r, T x) -> void {}, true);\n    ss.insert(L);\n    dat[L] =\
    \ t;\n    if (t != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n\
    \    merge_at(R);\n  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n\
    \    enumerate_range(0, RLIM, f, false);\n  }\n\n  void merge_at(int p) {\n  \
    \  if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p - 1);\n    if (dat[p]\
    \ == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n      ss.erase(p);\n\
    \    }\n  }\n\n  vc<T> get_all() {\n    vc<T> res(RLIM, none_val);\n    enumerate_all([&](int\
    \ a, int b, T t) -> void { FOR(i, a, b) res[i] = t; });\n    return res;\n  }\n\
    };\n\n// https://codeforces.com/contest/1638/problem/E\n// \u6301\u3064\u5024\u306E\
    \u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\
    \n// \u5148\u8AAD\u307F\u53EF\u80FD\u306A\u3089\u5EA7\u5727\u3057\u3066 fastset\
    \ \u306E\u65B9\u304C\u901F\u3044\ntemplate <typename T, typename X = ll>\nstruct\
    \ Intervals {\n  static constexpr X LLIM = -infty<X>;\n  static constexpr X RLIM\
    \ = infty<X>;\n  T none_val;\n  // const T none_val;\n  // none_val \u3067\u306A\
    \u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n\
    \  X total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val = 0) : none_val(none_val),\
    \ total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<X, X, T> get(X x, bool ERASE = false) {\n    auto it2 = dat.upper_bound(x);\n\
    \    auto it1 = prev(it2);\n    auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n\
    \    if (tl != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n\
    \      dat[l] = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n   \
    \ return {l, r, tl};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\
    \u53D6\u5F97 f(l, r, t)\n  template <typename F>\n  void enumerate_range(X L,\
    \ X R, F f, bool ERASE = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n\
    \    if (!ERASE) {\n      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi\
    \ < R) {\n        auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi,\
    \ R), (*it).se);\n        it = it2;\n      }\n      return;\n    }\n    // \u534A\
    \u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\n    auto p = prev(dat.upper_bound(L));\n\
    \    if ((*p).fi < L) {\n      dat[L] = (*p).se;\n      if (dat[L] != none_val)\
    \ ++total_num;\n    }\n    p = dat.lower_bound(R);\n    if (R < (*p).fi) {\n \
    \     T t = (*prev(p)).se;\n      dat[R] = t;\n      if (t != none_val) ++total_num;\n\
    \    }\n    p = dat.lower_bound(L);\n    while (1) {\n      if ((*p).fi >= R)\
    \ break;\n      auto q = next(p);\n      T t = (*p).se;\n      f((*p).fi, (*q).fi,\
    \ t);\n      if (t != none_val) --total_num, total_len -= (*q).fi - (*p).fi;\n\
    \      p = dat.erase(p);\n    }\n    dat[L] = none_val;\n  }\n\n  void set(X L,\
    \ X R, T t) {\n    assert(L <= R);\n    if (L == R) return;\n    enumerate_range(L,\
    \ R, [](int l, int r, T x) -> void {}, true);\n    dat[L] = t;\n    if (t != none_val)\
    \ total_num++, total_len += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n\
    \  template <typename F>\n  void enumerate_all(F f) {\n    enumerate_range(LLIM,\
    \ RLIM, f, false);\n  }\n\n  void merge_at(X p) {\n    if (p == LLIM || RLIM ==\
    \ p) return;\n    auto itp = dat.lower_bound(p);\n    assert((*itp).fi == p);\n\
    \    auto itq = prev(itp);\n    if ((*itp).se == (*itq).se) {\n      if ((*itp).se\
    \ != none_val) --total_num;\n      dat.erase(itp);\n    }\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  - other/bit.hpp
  isVerificationFile: false
  path: ds/intervals.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/intervals.hpp
layout: document
redirect_from:
- /library/ds/intervals.hpp
- /library/ds/intervals.hpp.html
title: ds/intervals.hpp
---
