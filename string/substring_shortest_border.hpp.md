---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/disjoint_sparse_table.hpp
    title: ds/sparse_table/disjoint_sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1043/problem/G
  bundledCode: "#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct\
    \ Index_Compression_DISTINCT_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T> build(vc<int>\
    \ X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n\
    \    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi + 1]++;\n \
    \   FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x : X) {\n    \
    \  x = dat[x - mi]++;\n    }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n\
    \    dat[0] = 0;\n    return X;\n  }\n  int size() const { return len(dat); }\n\
    \  int val_to_idx(T x) const { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n  int idx_to_val(int i) const { return dat[i]; }\n};\n\ntemplate <typename\
    \ T>\nstruct Index_Compression_SAME_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T>\
    \ build(vc<T> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi\
    \ + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x\
    \ : X) {\n      x = dat[x - mi];\n    }\n    return X;\n  }\n  int size() const\
    \ { return len(dat); }\n  int val_to_idx(T x) const { return dat[clamp<ll>(x -\
    \ mi, 0, ma - mi + 1)]; }\n  int idx_to_val(int i) const { return dat[i]; }\n\
    };\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(const vc<T>& X) {\n    dat.reserve(len(X));\n    vc<pair<T, int>>\
    \ tmp(len(X));\n    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n\
    \    vc<int> ANS(len(X));\n    for (auto [x, j] : tmp) {\n      if (dat.empty()\
    \ || dat.back() != x) dat.eb(x);\n      ANS[j] = len(dat) - 1;\n    }\n    return\
    \ ANS;\n  }\n  int size() const { return len(dat); }\n  int val_to_idx(T x) const\
    \ { return LB(dat, x); }\n  int idx_to_val(int i) const { return dat[i]; }\n};\n\
    \ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(vc<T> X) {\n    dat.reserve(len(X));\n    vc<pair<T, int>> tmp(len(X));\n\
    \    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n    vc<int> ANS(len(X));\n\
    \    for (auto [x, j] : tmp) {\n      dat.eb(x);\n      ANS[j] = len(dat) - 1;\n\
    \    }\n    return ANS;\n  }\n  int size() const { return len(dat); }\n  int val_to_idx(T\
    \ x) const { return LB(dat, x); }\n  int idx_to_val(int i) const { return dat[i];\
    \ }\n};\n\ntemplate <typename T, bool SMALL>\nusing Index_Compression_DISTINCT\
    \ =\n    typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>,\n\
    \                              Index_Compression_DISTINCT_LARGE<T>>::type;\ntemplate\
    \ <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename std::conditional<SMALL,\
    \ Index_Compression_SAME_SMALL<T>,\n                              Index_Compression_SAME_LARGE<T>>::type;\n\
    \n// SAME: [2,3,2] -> [0,1,0]\n// DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\
    \u5217\u3092\u5727\u7E2E\u3057\u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\
    \n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\ntemplate <typename T, bool\
    \ SAME, bool SMALL>\nusing Index_Compression =\n    typename std::conditional<SAME,\
    \ Index_Compression_SAME<T, SMALL>,\n                              Index_Compression_DISTINCT<T,\
    \ SMALL>>::type;\n#line 1 \"alg/monoid/min.hpp\"\n// require: all values x satisfy\
    \ x <= infty<E>\ntemplate <typename E>\nstruct Monoid_Min {\n  using X = E;\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\n  static constexpr X id() { return infty<E>; }\n  static\
    \ constexpr bool commute = true;\n};\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n\
    \  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n\
    \    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 1 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::id(); });\n  }\n  void build(const vc<X>&\
    \ v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::id());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::id(), vr = Monoid::id();\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1)\
    \ vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0 <= L &&\
    \ L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n    while\
    \ (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n      L\
    \ >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n    return\
    \ I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class F>\n\
    \  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n && check(Monoid::id()));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::id();\n    do {\n\
    \      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n          }\n     \
    \   }\n        return L - size;\n      }\n      sm = Monoid::op(sm, dat[L++]);\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::id()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::id();\n    do {\n\
    \      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::id();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >> k)\
    \ + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  UINT\
    \ s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool\
    \ done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n\
    \  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n\
    \    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/sparse_table/disjoint_sparse_table.hpp\"\
    \n\ntemplate <class Monoid>\nstruct Disjoint_Sparse_Table {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Disjoint_Sparse_Table()\
    \ {}\n  Disjoint_Sparse_Table(int n) { build(n); }\n  template <typename F>\n\
    \  Disjoint_Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::id(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].reserve(n);\n    FOR(i, n) dat[0].eb(f(i));\n    FOR(i, 1, log) {\n\
    \      auto& v = dat[i];\n      v = dat[0];\n      int b = 1 << i;\n      for\
    \ (int m = b; m <= n; m += 2 * b) {\n        int L = m - b, R = min(n, m + b);\n\
    \        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\n        FOR(j,\
    \ m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::id();\n    --R;\n    if (L ==\
    \ R) return dat[0][L];\n    int k = topbit(L ^ R);\n    return MX::op(dat[k][L],\
    \ dat[k][R]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::id()));\n    if (L == n)\
    \ return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n\
    \  int min_left(const F check, int R) const {\n    assert(0 <= R && R <= n &&\
    \ check(MX::id()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n   \
    \ while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 3 \"ds/static_range_product.hpp\"\n\n/*\n\u53C2\u8003\uFF1Ahttps://judge.yosupo.jp/submission/106668\n\
    \u9577\u3055 2^LOG \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u308B\uFF0E\
    \u30D6\u30ED\u30C3\u30AF\u5185\u306E prefix, suffix \u3092\u6301\u3064\uFF0E\n\
    \u30D6\u30ED\u30C3\u30AF\u7A4D\u306E\u5217\u3092 ST(DST) \u3067\u6301\u3064\uFF0E\
    \u30D6\u30ED\u30C3\u30AF\u3092\u307E\u305F\u3050\u7A4D\u306F O(1).\n\u77ED\u3044\
    \u3082\u306E\u306F O(1) \u3092\u8AE6\u3081\u3066\u611A\u76F4\u3068\u3044\u3046\
    \u3053\u3068\u306B\u3059\u308B\uFF0E\n\u524D\u8A08\u7B97\uFF1AO(Nlog(N)/2^LOG)\n\
    \u30AF\u30A8\u30EA\uFF1AO(1) / worst O(2^LOG)\n*/\ntemplate <typename Monoid,\
    \ typename SPARSE_TABLE, int LOG = 4>\nstruct Static_Range_Product {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  int N, b_num;\n  vc<X>\
    \ A, pre, suf;  // inclusive\n  SPARSE_TABLE ST;\n\n  Static_Range_Product() {}\n\
    \  template <typename F>\n  Static_Range_Product(int n, F f) {\n    build(n, f);\n\
    \  }\n  Static_Range_Product(const vc<X>& v) { build(v); }\n\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    N = m;\n    b_num = N >> LOG;\n\
    \    A.resize(N);\n    FOR(i, N) A[i] = f(i);\n    pre = A, suf = A;\n    constexpr\
    \ int mask = (1 << LOG) - 1;\n    FOR(i, 1, N) {\n      if (i & mask) pre[i] =\
    \ MX::op(pre[i - 1], A[i]);\n    }\n    FOR_R(i, 1, N) {\n      if (i & mask)\
    \ suf[i - 1] = MX::op(A[i - 1], suf[i]);\n    }\n    ST.build(b_num, [&](int i)\
    \ -> X { return suf[i << LOG]; });\n  }\n\n  // O(1) or O(R-L)\n  X prod(int L,\
    \ int R) const {\n    if (L == R) return MX::id();\n    R -= 1;\n    int a = L\
    \ >> LOG, b = R >> LOG;\n    if (a < b) {\n      X x = ST.prod(a + 1, b);\n  \
    \    x = MX::op(suf[L], x);\n      x = MX::op(x, pre[R]);\n      return x;\n \
    \   }\n    X x = A[L];\n    FOR(i, L + 1, R + 1) x = MX::op(x, A[i]);\n    return\
    \ x;\n  }\n\n  template <class F>\n  int max_right(const F check, int L) const\
    \ {\n    assert(0 <= L && L <= N && check(MX::id()));\n    if (L == N) return\
    \ N;\n    int ok = L, ng = N + 1;\n    while (ok + 1 < ng) {\n      int k = (ok\
    \ + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n    \
    \  if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) const {\n    assert(0 <= R && R <= N && check(MX::id()));\n\
    \    if (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n#line\
    \ 6 \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\u76EE\u306E\
    \ suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\u3068\
    \u304D\u3001\n// SA[i] = j, ISA[j] = i\n// |S|>0 \u3092\u524D\u63D0\uFF08\u305D\
    \u3046\u3067\u306A\u3044\u5834\u5408 dummy \u6587\u5B57\u3092\u8FFD\u52A0\u3057\
    \u3066\u5229\u7528\u305B\u3088\uFF09\n// SEG_TYPE=0: SegTree, 1: SparseTable,\
    \ 2: StaticRangeProduct\ntemplate <int SEG_TYPE = 0>\nstruct Suffix_Array {\n\
    \  vc<int> SA;\n  vc<int> ISA;\n  vc<int> LCP;\n  using Mono = Monoid_Min<int>;\n\
    \  using SEG0 = SegTree<Mono>;\n  using SEG1 = Sparse_Table<Mono>;\n  using SEG2\
    \ = Static_Range_Product<Mono, Sparse_Table<Mono>, 4>;\n  static_assert(SEG_TYPE\
    \ == 0 || SEG_TYPE == 1 || SEG_TYPE == 2);\n  using SegType = conditional_t<SEG_TYPE\
    \ == 0, SEG0,\n      conditional_t<SEG_TYPE == 1, SEG1, SEG2> >;\n  SegType seg;\n\
    \  bool build_seg;\n\n  Suffix_Array() {}\n\n  template <typename STRING>\n  Suffix_Array(const\
    \ STRING& s) {\n    build_seg = 0;\n    auto a = to_compressed_vector(s);\n  \
    \  SA = SA_IS(a);\n    calc_LCP(a);\n  }\n\n  vc<int> to_compressed_vector(const\
    \ string& s) {\n    vc<int> a(len(s));\n    FOR(i, len(s)) a[i] = (unsigned char)s[i];\n\
    \    Index_Compression<int, 1, 1> I;\n    return I.build(a);\n  }\n\n  vc<int>\
    \ to_compressed_vector(const vc<int>& s) {\n    Index_Compression<int, 1, 0> I;\n\
    \    return I.build(s);\n  }\n\n  // lcp(S[i:], S[j:])\n  int lcp(int i, int j)\
    \ {\n    if (!build_seg) {\n      build_seg = true;\n      seg.build(LCP);\n \
    \   }\n    int n = len(SA);\n    if (i == n || j == n) return 0;\n    if (i ==\
    \ j) return n - i;\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i, j);\n\
    \    return seg.prod(i, j);\n  }\n\n  // S[i:] \u3068\u306E lcp \u304C n \u4EE5\
    \u4E0A\u3067\u3042\u308B\u3088\u3046\u306A\u534A\u958B\u533A\u9593\n  pair<int,\
    \ int> lcp_range(int i, int n) {\n    if (!build_seg) {\n      build_seg = true;\n\
    \      seg.build(LCP);\n    }\n    i = ISA[i];\n    int a = seg.min_left([&](auto\
    \ e) -> bool { return e >= n; }, i);\n    int b = seg.max_right([&](auto e) ->\
    \ bool { return e >= n; }, i);\n    return {a, b + 1};\n  }\n\n  // -1: S[L1:R1)\
    \ < S[L2, R2)\n  //  0: S[L1:R1) = S[L2, R2)\n  // +1: S[L1:R1) > S[L2, R2)\n\
    \  int compare(int L1, int R1, int L2, int R2) {\n    int n1 = R1 - L1, n2 = R2\
    \ - L2;\n    int n = lcp(L1, L2);\n    chmin(n, n1);\n    chmin(n, n2);\n    if\
    \ (n == n1 && n == n2) return 0;\n    if (n == n1) return -1;\n    if (n == n2)\
    \ return 1;\n    return (ISA[L1 + n] > ISA[L2 + n] ? 1 : -1);\n  }\n\n private:\n\
    \  void induced_sort(const vc<int>& vect, int val_range, vc<int>& SA,\n      const\
    \ vc<bool>& sl, const vc<int>& lms_idx) {\n    vc<int> l(val_range, 0), r(val_range,\
    \ 0);\n    for (int c : vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n  \
    \    ++r[c];\n    }\n    partial_sum(l.begin(), l.end(), l.begin());\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    fill(SA.begin(), SA.end(), -1);\n    for (int i =\
    \ (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] = lms_idx[i];\n\
    \    for (int i : SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i\
    \ - 1;\n    fill(r.begin(), r.end(), 0);\n    for (int c : vect) ++r[c];\n   \
    \ partial_sum(r.begin(), r.end(), r.begin());\n    for (int k = (int)SA.size()\
    \ - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) {\n\
    \        SA[--r[vect[i - 1]]] = i - 1;\n      }\n  }\n\n  vc<int> SA_IS(vc<int>\
    \ vect) {\n    for (auto& x : vect) ++x;\n    vect.eb(0);\n    int val_range =\
    \ MAX(vect) + 1;\n    const int n = vect.size();\n    vc<int> SA(n), lms_idx;\n\
    \    vc<bool> sl(n);\n    sl[n - 1] = false;\n    for (int i = n - 2; i >= 0;\
    \ --i) {\n      sl[i] = (vect[i] > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i\
    \ + 1]));\n      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n \
    \   reverse(lms_idx.begin(), lms_idx.end());\n    induced_sort(vect, val_range,\
    \ SA, sl, lms_idx);\n    vc<int> new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n\
    \    for (int i = 0, k = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 &&\
    \ sl[SA[i] - 1]) {\n        new_lms_idx[k++] = SA[i];\n      }\n    int cur =\
    \ 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k < new_lms_idx.size(); ++k)\
    \ {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n      if (vect[i]\
    \ != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n      }\n      bool\
    \ flag = false;\n      for (int a = i + 1, b = j + 1;; ++a, ++b) {\n        if\
    \ (vect[a] != vect[b]) {\n          flag = true;\n          break;\n        }\n\
    \        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n          flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n          break;\n   \
    \     }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n    for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if (cur +\
    \ 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec);\n      for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) {\n        new_lms_idx[i] = lms_idx[lms_SA[i]];\n\
    \      }\n    }\n    induced_sort(vect, val_range, SA, sl, new_lms_idx);\n   \
    \ SA.erase(SA.begin());\n    return SA;\n  }\n\n  void calc_LCP(const vc<int>&\
    \ s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n\
    \    if (n == 0) return;\n    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n  \
    \  for (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n\
    \        k = 0;\n        continue;\n      }\n      int j = SA[ISA[i] + 1];\n \
    \     while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]]\
    \ = k;\n    }\n    LCP.resize(n - 1);\n  }\n};\n#line 2 \"string/substring_shortest_border.hpp\"\
    \n\n// \u6700\u77ED border \u306E\u9577\u3055. \u306A\u304B\u3063\u305F\u3089\
    \ R-L. O(sqrt(N)).\n// https://codeforces.com/contest/1043/problem/G\n// N=Q=200_000,\
    \ 1.2sec\nint substring_shortest_border(Suffix_Array<true>& X, int L, int R) {\n\
    \  /*\n  border \u306E border \u306F border \u306A\u306E\u3067\uFF0Cshortest border\
    \ B \u306F borderless.\n  S \u306B\u304A\u3051\u308B B \u306E occurrence \u306F\
    \u91CD\u8907\u3057\u306A\u3044.\n  \u3088\u3063\u3066 B \u3092 prefix \u306B\u6301\
    \u3064\u6587\u5B57\u5217\u306F\u9AD8\u3005 O(N/|B|) \u3067\u3042\u308B.\n  \u3053\
    \u308C\u306F suffix array \u306B\u304A\u3051\u308B\u8FD1\u508D\u3092\u898B\u308C\
    \u3070\u898B\u3064\u304B\u308B.\n  */\n  int N = len(X.SA);\n  int K = sqrt(len(X.SA))\
    \ / 2;\n  FOR(n, 1, K + 1) {\n    if (X.lcp(L, R - n) >= n) return n;\n  }\n \
    \ int ANS = R - L;\n  int idx = X.ISA[L];\n  int lcp = infty<int>;\n  FOR(i, idx\
    \ + 1, N) {\n    chmin(lcp, X.LCP[i - 1]);\n    if (lcp <= K) break; // \u3053\
    \u308C\u3067\u52DD\u624B\u306B O(sqrt(N)) \u306B\u306A\u308B.\n    int M = X.SA[i];\n\
    \    if (L < M && M < R && R - M <= lcp) chmin(ANS, R - M);\n  }\n  lcp = infty<int>;\n\
    \  FOR_R(i, idx) {\n    chmin(lcp, X.LCP[i]);\n    if (lcp <= K) break; // \u3053\
    \u308C\u3067\u52DD\u624B\u306B O(sqrt(N)) \u306B\u306A\u308B.\n    int M = X.SA[i];\n\
    \    if (L < M && M < R && R - M <= lcp) chmin(ANS, R - M);\n  }\n  return ANS;\n\
    }\n"
  code: "#include \"string/suffix_array.hpp\"\n\n// \u6700\u77ED border \u306E\u9577\
    \u3055. \u306A\u304B\u3063\u305F\u3089 R-L. O(sqrt(N)).\n// https://codeforces.com/contest/1043/problem/G\n\
    // N=Q=200_000, 1.2sec\nint substring_shortest_border(Suffix_Array<true>& X, int\
    \ L, int R) {\n  /*\n  border \u306E border \u306F border \u306A\u306E\u3067\uFF0C\
    shortest border B \u306F borderless.\n  S \u306B\u304A\u3051\u308B B \u306E occurrence\
    \ \u306F\u91CD\u8907\u3057\u306A\u3044.\n  \u3088\u3063\u3066 B \u3092 prefix\
    \ \u306B\u6301\u3064\u6587\u5B57\u5217\u306F\u9AD8\u3005 O(N/|B|) \u3067\u3042\
    \u308B.\n  \u3053\u308C\u306F suffix array \u306B\u304A\u3051\u308B\u8FD1\u508D\
    \u3092\u898B\u308C\u3070\u898B\u3064\u304B\u308B.\n  */\n  int N = len(X.SA);\n\
    \  int K = sqrt(len(X.SA)) / 2;\n  FOR(n, 1, K + 1) {\n    if (X.lcp(L, R - n)\
    \ >= n) return n;\n  }\n  int ANS = R - L;\n  int idx = X.ISA[L];\n  int lcp =\
    \ infty<int>;\n  FOR(i, idx + 1, N) {\n    chmin(lcp, X.LCP[i - 1]);\n    if (lcp\
    \ <= K) break; // \u3053\u308C\u3067\u52DD\u624B\u306B O(sqrt(N)) \u306B\u306A\
    \u308B.\n    int M = X.SA[i];\n    if (L < M && M < R && R - M <= lcp) chmin(ANS,\
    \ R - M);\n  }\n  lcp = infty<int>;\n  FOR_R(i, idx) {\n    chmin(lcp, X.LCP[i]);\n\
    \    if (lcp <= K) break; // \u3053\u308C\u3067\u52DD\u624B\u306B O(sqrt(N)) \u306B\
    \u306A\u308B.\n    int M = X.SA[i];\n    if (L < M && M < R && R - M <= lcp) chmin(ANS,\
    \ R - M);\n  }\n  return ANS;\n}\n"
  dependsOn:
  - string/suffix_array.hpp
  - ds/index_compression.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  - other/bit.hpp
  - ds/segtree/segtree.hpp
  - ds/static_range_product.hpp
  - ds/sparse_table/disjoint_sparse_table.hpp
  isVerificationFile: false
  path: string/substring_shortest_border.hpp
  requiredBy: []
  timestamp: '2026-08-31 13:26:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/substring_shortest_border.hpp
layout: document
redirect_from:
- /library/string/substring_shortest_border.hpp
- /library/string/substring_shortest_border.hpp.html
title: string/substring_shortest_border.hpp
---
