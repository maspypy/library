---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e
    - https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i
  bundledCode: "#line 1 \"ds/segtree/range_add_make_increasing.hpp\"\n\n#line 2 \"\
    ds/segtree/dual_segtree.hpp\"\n\ntemplate <typename Monoid>\nstruct Dual_SegTree\
    \ {\n  using MA = Monoid;\n  using A = typename MA::value_type;\n  int n, log,\
    \ size;\n  vc<A> laz;\n\n  Dual_SegTree() : Dual_SegTree(0) {}\n  Dual_SegTree(int\
    \ n) {\n    build(n, [&](int i) -> A { return MA::unit(); });\n  }\n  template\
    \ <typename F>\n  Dual_SegTree(int n, F f) {\n    build(n, f);\n  }\n\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m;\n    log = 1;\n    while\
    \ ((1 << log) < n) ++log;\n    size = 1 << log;\n    laz.assign(size << 1, MA::unit());\n\
    \    FOR(i, n) laz[size + i] = f(i);\n  }\n  void build(int n) {\n    build(n,\
    \ [&](int i) -> A { return MA::unit(); });\n  }\n\n  A get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n    FOR(i, size) push(i);\n\
    \    return {laz.begin() + size, laz.begin() + size + n};\n  }\n\n  void set(int\
    \ p, A x) {\n    get(p);\n    laz[p + size] = x;\n  }\n\n  void apply(int l, int\
    \ r, const A& a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n\
    \    l += size, r += size;\n    if (!MA::commute) {\n      for (int i = log; i\
    \ >= 1; i--) {\n        if (((l >> i) << i) != l) push(l >> i);\n        if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n      }\n    }\n    while (l < r) {\n\
    \      if (l & 1) all_apply(l++, a);\n      if (r & 1) all_apply(--r, a);\n  \
    \    l >>= 1, r >>= 1;\n    }\n  }\n\nprivate:\n  void push(int k) {\n    if (laz[k]\
    \ == MA::unit()) return;\n    all_apply(2 * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n\
    \    laz[k] = MA::unit();\n  }\n  void all_apply(int k, A a) { laz[k] = MA::op(laz[k],\
    \ a); }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fastset.hpp\"\
    \n\r\n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct FastSet {\r\n  static\
    \ constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\n\r\n  FastSet()\
    \ {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  int size() { return n; }\r\n\r\
    \n  template <typename F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n \
    \ }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\
    \n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\
    \n    } while (m > 1);\r\n    log = len(seg);\r\n  }\r\n  template <typename F>\r\
    \n  void build(int n, F f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B]\
    \ |= u64(f(i)) << (i % B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h]))\
    \ { seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B); }\r\n    }\r\n  }\r\n\
    \r\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\r\n\
    \  void insert(int i) {\r\n    assert(0 <= i && i < n);\r\n    for (int h = 0;\
    \ h < log; h++) { seg[h][i / B] |= u64(1) << (i % B), i /= B; }\r\n  }\r\n  void\
    \ add(int i) { insert(i); }\r\n  void erase(int i) {\r\n    assert(0 <= i && i\
    \ < n);\r\n    u64 x = 0;\r\n    for (int h = 0; h < log; h++) {\r\n      seg[h][i\
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
    \n    return s;\r\n  }\r\n};\n#line 5 \"ds/segtree/range_add_make_increasing.hpp\"\
    \n\n// \u533A\u9593\u52A0\u7B97 / \u3042\u308B\u7BC4\u56F2\u3092 prefix \u5074\
    \u304B\u3089\u5358\u8ABF(\u5897\u52A0/\u6E1B\u5C11)\u306B\u306A\u308B\u3088\u3046\
    \u306B\u4FEE\u6B63\n// \u6307\u5B9A\u3057\u306A\u304B\u3063\u305F\u5834\u5408\
    \ 0 \u57CB\u3081\u3067\u521D\u671F\u5316\u3055\u308C\u308B\n// https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e\n\
    // https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i\nstruct Range_Add_Make_Monotonic_Increasing\
    \ {\n  // \u4EE3\u8868\u70B9\u306E\u96C6\u5408\u3092\u6301\u3064. \u4EE3\u8868\
    \u70B9\u306B\u5BFE\u3059\u308B\u5024\u3092\u53CC\u5BFE\u30BB\u30B0\u6728\u3067\
    \u6301\u3064.\n  // A[i-1]>A[i] \u3068\u306A\u3063\u3066\u3044\u308B i \u5168\u4F53\
    \u3082\u6301\u3064.\n  int n;\n  FastSet S, DEC;\n  Dual_SegTree<Monoid_Add<ll>>\
    \ seg;\n\n  Range_Add_Make_Monotonic_Increasing() {}\n  Range_Add_Make_Monotonic_Increasing(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Add_Make_Monotonic_Increasing(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Make_Monotonic_Increasing(const\
    \ vi& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> ll\
    \ { return 0; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    vi v(m);\n    FOR(i, m) v[i] = f(i);\n    build(v);\n  }\n  void build(const\
    \ vi& v) {\n    n = len(v);\n    seg.build(n, [&](int i) -> ll { return v[i];\
    \ }), S.build(n), DEC.build(n + 1);\n    FOR(i, n) S.insert(i);\n    FOR(i, 1,\
    \ n) if (v[i - 1] > v[i]) DEC.insert(i);\n  }\n\n  ll get(int i) { return seg.get(S.prev(i));\
    \ }\n  vi get_all() {\n    auto A = seg.get_all();\n    int p = 0;\n    FOR(i,\
    \ n) {\n      if (S[i]) p = i;\n      A[i] = A[p];\n    }\n    return A;\n  }\n\
    \  void set(int i, ll x) {\n    split(i), split(i + 1);\n    seg.set(i, x);\n\
    \    DEC.insert(i), DEC.insert(i + 1);\n  }\n  void range_add(int L, int R, ll\
    \ x) {\n    split(L), split(R);\n    if (x < 0) DEC.insert(L);\n    if (x > 0)\
    \ DEC.insert(R);\n    seg.apply(L, R, x);\n  }\n  void range_assign(int L, int\
    \ R, ll x) {\n    split(L), split(R);\n    INC.insert(L), INC.insert(R);\n   \
    \ S.enumerate(L, R, [&](int i) -> void { S.erase(i); });\n    S.insert(L);\n \
    \   seg.set(L, x);\n  }\n  void make_increasing(int L, int R) {\n    split(L),\
    \ split(R);\n    DEC.enumerate(L + 1, R, [&](int i) -> void {\n      ll mx = get(i\
    \ - 1);\n      while (i < R) {\n        DEC.erase(i);\n        ll now = get(i);\n\
    \        if (mx < now) break;\n        S.erase(i);\n        i = S.next(i);\n \
    \     }\n    });\n  }\n\nprivate:\n  void split(int p) {\n    if (p == 0 || p\
    \ == n || S[p]) return;\n    seg.set(p, get(p));\n    S.insert(p);\n  }\n};\n"
  code: "\n#include \"ds/segtree/dual_segtree.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n#include \"ds/fastset.hpp\"\n\n// \u533A\u9593\u52A0\u7B97 / \u3042\u308B\u7BC4\
    \u56F2\u3092 prefix \u5074\u304B\u3089\u5358\u8ABF(\u5897\u52A0/\u6E1B\u5C11)\u306B\
    \u306A\u308B\u3088\u3046\u306B\u4FEE\u6B63\n// \u6307\u5B9A\u3057\u306A\u304B\u3063\
    \u305F\u5834\u5408 0 \u57CB\u3081\u3067\u521D\u671F\u5316\u3055\u308C\u308B\n\
    // https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e\n// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i\n\
    struct Range_Add_Make_Monotonic_Increasing {\n  // \u4EE3\u8868\u70B9\u306E\u96C6\
    \u5408\u3092\u6301\u3064. \u4EE3\u8868\u70B9\u306B\u5BFE\u3059\u308B\u5024\u3092\
    \u53CC\u5BFE\u30BB\u30B0\u6728\u3067\u6301\u3064.\n  // A[i-1]>A[i] \u3068\u306A\
    \u3063\u3066\u3044\u308B i \u5168\u4F53\u3082\u6301\u3064.\n  int n;\n  FastSet\
    \ S, DEC;\n  Dual_SegTree<Monoid_Add<ll>> seg;\n\n  Range_Add_Make_Monotonic_Increasing()\
    \ {}\n  Range_Add_Make_Monotonic_Increasing(int n) { build(n); }\n  template <typename\
    \ F>\n  Range_Add_Make_Monotonic_Increasing(int n, F f) {\n    build(n, f);\n\
    \  }\n  Range_Add_Make_Monotonic_Increasing(const vi& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> ll { return 0; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    vi v(m);\n    FOR(i, m) v[i] =\
    \ f(i);\n    build(v);\n  }\n  void build(const vi& v) {\n    n = len(v);\n  \
    \  seg.build(n, [&](int i) -> ll { return v[i]; }), S.build(n), DEC.build(n +\
    \ 1);\n    FOR(i, n) S.insert(i);\n    FOR(i, 1, n) if (v[i - 1] > v[i]) DEC.insert(i);\n\
    \  }\n\n  ll get(int i) { return seg.get(S.prev(i)); }\n  vi get_all() {\n   \
    \ auto A = seg.get_all();\n    int p = 0;\n    FOR(i, n) {\n      if (S[i]) p\
    \ = i;\n      A[i] = A[p];\n    }\n    return A;\n  }\n  void set(int i, ll x)\
    \ {\n    split(i), split(i + 1);\n    seg.set(i, x);\n    DEC.insert(i), DEC.insert(i\
    \ + 1);\n  }\n  void range_add(int L, int R, ll x) {\n    split(L), split(R);\n\
    \    if (x < 0) DEC.insert(L);\n    if (x > 0) DEC.insert(R);\n    seg.apply(L,\
    \ R, x);\n  }\n  void range_assign(int L, int R, ll x) {\n    split(L), split(R);\n\
    \    INC.insert(L), INC.insert(R);\n    S.enumerate(L, R, [&](int i) -> void {\
    \ S.erase(i); });\n    S.insert(L);\n    seg.set(L, x);\n  }\n  void make_increasing(int\
    \ L, int R) {\n    split(L), split(R);\n    DEC.enumerate(L + 1, R, [&](int i)\
    \ -> void {\n      ll mx = get(i - 1);\n      while (i < R) {\n        DEC.erase(i);\n\
    \        ll now = get(i);\n        if (mx < now) break;\n        S.erase(i);\n\
    \        i = S.next(i);\n      }\n    });\n  }\n\nprivate:\n  void split(int p)\
    \ {\n    if (p == 0 || p == n || S[p]) return;\n    seg.set(p, get(p));\n    S.insert(p);\n\
    \  }\n};\n"
  dependsOn:
  - ds/segtree/dual_segtree.hpp
  - alg/monoid/add.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/segtree/range_add_make_increasing.hpp
  requiredBy: []
  timestamp: '2024-10-28 19:23:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/range_add_make_increasing.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_add_make_increasing.hpp
- /library/ds/segtree/range_add_make_increasing.hpp.html
title: ds/segtree/range_add_make_increasing.hpp
---
