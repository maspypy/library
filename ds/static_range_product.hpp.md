---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/sparse_table/disjoint_sparse_table.hpp
    title: ds/sparse_table/disjoint_sparse_table.hpp
  - icon: ':x:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':x:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/basic_substring_structure.hpp
    title: string/basic_substring_structure.hpp
  - icon: ':x:'
    path: string/lex_max_suffix_for_all_prefix.hpp
    title: string/lex_max_suffix_for_all_prefix.hpp
  - icon: ':x:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':warning:'
    path: string/many_string_compare.hpp
    title: string/many_string_compare.hpp
  - icon: ':warning:'
    path: string/sort_substrings.hpp
    title: string/sort_substrings.hpp
  - icon: ':warning:'
    path: string/substring_shortest_border.hpp
    title: string/substring_shortest_border.hpp
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':x:'
    path: string/suffix_lcp_change.hpp
    title: string/suffix_lcp_change.hpp
  - icon: ':x:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/lex_minmax_suffix.test.cpp
    title: test/1_mytest/lex_minmax_suffix.test.cpp
  - icon: ':x:'
    path: test/1_mytest/longest_common_substr.test.cpp
    title: test/1_mytest/longest_common_substr.test.cpp
  - icon: ':x:'
    path: test/1_mytest/suffix_lcp_change.test.cpp
    title: test/1_mytest/suffix_lcp_change.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/staticrmq.test.cpp
    title: test/2_library_checker/data_structure/staticrmq.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/longest_common_substring.test.cpp
    title: test/2_library_checker/string/longest_common_substring.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/number_of_substrings.test.cpp
    title: test/2_library_checker/string/number_of_substrings.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/suffix_array.test.cpp
    title: test/2_library_checker/string/suffix_array.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/string/suffix_array_vec.test.cpp
    title: test/2_library_checker/string/suffix_array_vec.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/106668
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
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\
    \u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\
    \u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class\
    \ Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) {\
    \ build(n); }\n  template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m)\
    \ {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i,\
    \ n) dat[0][i] = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i])\
    \ - (1 << i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j]\
    \ = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::unit();\n    if (R == L + 1) return\
    \ dat[0][L];\n    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R\
    \ - (1 << k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::unit()));\n    if (L ==\
    \ n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n     \
    \ int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok\
    \ = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class\
    \ F>\n  int min_left(const F check, int R) const {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
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
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"ds/sparse_table/disjoint_sparse_table.hpp\"\n\ntemplate\
    \ <class Monoid>\nstruct Disjoint_Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Disjoint_Sparse_Table()\
    \ {}\n  Disjoint_Sparse_Table(int n) { build(n); }\n  template <typename F>\n\
    \  Disjoint_Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n  Disjoint_Sparse_Table(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].reserve(n);\n    FOR(i, n) dat[0].eb(f(i));\n    FOR(i, 1, log) {\n\
    \      auto& v = dat[i];\n      v = dat[0];\n      int b = 1 << i;\n      for\
    \ (int m = b; m <= n; m += 2 * b) {\n        int L = m - b, R = min(n, m + b);\n\
    \        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\n        FOR(j,\
    \ m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\n      }\n    }\n  }\n\n  X prod(int\
    \ L, int R) const {\n    if (L == R) return MX::unit();\n    --R;\n    if (L ==\
    \ R) return dat[0][L];\n    int k = topbit(L ^ R);\n    return MX::op(dat[k][L],\
    \ dat[k][R]);\n  }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L) const {\n    assert(0 <= L && L <= n && check(MX::unit()));\n    if (L ==\
    \ n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n     \
    \ int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok\
    \ = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class\
    \ F>\n  int min_left(const F check, int R) const {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
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
    \ int R) const {\n    if (L == R) return MX::unit();\n    R -= 1;\n    int a =\
    \ L >> LOG, b = R >> LOG;\n    if (a < b) {\n      X x = ST.prod(a + 1, b);\n\
    \      x = MX::op(suf[L], x);\n      x = MX::op(x, pre[R]);\n      return x;\n\
    \    }\n    X x = A[L];\n    FOR(i, L + 1, R + 1) x = MX::op(x, A[i]);\n    return\
    \ x;\n  }\n\n  template <class F>\n  int max_right(const F check, int L) const\
    \ {\n    assert(0 <= L && L <= N && check(MX::unit()));\n    if (L == N) return\
    \ N;\n    int ok = L, ng = N + 1;\n    while (ok + 1 < ng) {\n      int k = (ok\
    \ + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n    \
    \  if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) const {\n    assert(0 <= R && R <= N && check(MX::unit()));\n\
    \    if (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n"
  code: "#include \"ds/sparse_table/sparse_table.hpp\"\n#include \"ds/sparse_table/disjoint_sparse_table.hpp\"\
    \n\n/*\n\u53C2\u8003\uFF1Ahttps://judge.yosupo.jp/submission/106668\n\u9577\u3055\
    \ 2^LOG \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u308B\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u5185\u306E prefix, suffix \u3092\u6301\u3064\uFF0E\n\u30D6\u30ED\
    \u30C3\u30AF\u7A4D\u306E\u5217\u3092 ST(DST) \u3067\u6301\u3064\uFF0E\u30D6\u30ED\
    \u30C3\u30AF\u3092\u307E\u305F\u3050\u7A4D\u306F O(1).\n\u77ED\u3044\u3082\u306E\
    \u306F O(1) \u3092\u8AE6\u3081\u3066\u611A\u76F4\u3068\u3044\u3046\u3053\u3068\
    \u306B\u3059\u308B\uFF0E\n\u524D\u8A08\u7B97\uFF1AO(Nlog(N)/2^LOG)\n\u30AF\u30A8\
    \u30EA\uFF1AO(1) / worst O(2^LOG)\n*/\ntemplate <typename Monoid, typename SPARSE_TABLE,\
    \ int LOG = 4>\nstruct Static_Range_Product {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  int N, b_num;\n  vc<X> A, pre, suf;  // inclusive\n\
    \  SPARSE_TABLE ST;\n\n  Static_Range_Product() {}\n  template <typename F>\n\
    \  Static_Range_Product(int n, F f) {\n    build(n, f);\n  }\n  Static_Range_Product(const\
    \ vc<X>& v) { build(v); }\n\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n    FOR(i, N)\
    \ A[i] = f(i);\n    pre = A, suf = A;\n    constexpr int mask = (1 << LOG) - 1;\n\
    \    FOR(i, 1, N) {\n      if (i & mask) pre[i] = MX::op(pre[i - 1], A[i]);\n\
    \    }\n    FOR_R(i, 1, N) {\n      if (i & mask) suf[i - 1] = MX::op(A[i - 1],\
    \ suf[i]);\n    }\n    ST.build(b_num, [&](int i) -> X { return suf[i << LOG];\
    \ });\n  }\n\n  // O(1) or O(R-L)\n  X prod(int L, int R) const {\n    if (L ==\
    \ R) return MX::unit();\n    R -= 1;\n    int a = L >> LOG, b = R >> LOG;\n  \
    \  if (a < b) {\n      X x = ST.prod(a + 1, b);\n      x = MX::op(suf[L], x);\n\
    \      x = MX::op(x, pre[R]);\n      return x;\n    }\n    X x = A[L];\n    FOR(i,\
    \ L + 1, R + 1) x = MX::op(x, A[i]);\n    return x;\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L) const {\n    assert(0 <= L && L <=\
    \ N && check(MX::unit()));\n    if (L == N) return N;\n    int ok = L, ng = N\
    \ + 1;\n    while (ok + 1 < ng) {\n      int k = (ok + ng) / 2;\n      bool bl\
    \ = check(prod(L, k));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n\
    \    return ok;\n  }\n\n  template <class F>\n  int min_left(const F check, int\
    \ R) const {\n    assert(0 <= R && R <= N && check(MX::unit()));\n    if (R ==\
    \ 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok) {\n      int\
    \ k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if (bl) ok = k;\n\
    \      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};"
  dependsOn:
  - ds/sparse_table/sparse_table.hpp
  - other/bit.hpp
  - ds/sparse_table/disjoint_sparse_table.hpp
  isVerificationFile: false
  path: ds/static_range_product.hpp
  requiredBy:
  - string/suffix_lcp_change.hpp
  - string/many_string_compare.hpp
  - string/lex_max_suffix_for_all_prefix.hpp
  - string/basic_substring_structure.hpp
  - string/suffix_tree.hpp
  - string/sort_substrings.hpp
  - string/suffix_array.hpp
  - string/longest_common_substring.hpp
  - string/substring_shortest_border.hpp
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/lex_minmax_suffix.test.cpp
  - test/1_mytest/suffix_lcp_change.test.cpp
  - test/1_mytest/longest_common_substr.test.cpp
  - test/2_library_checker/data_structure/staticrmq.test.cpp
  - test/2_library_checker/string/suffix_array.test.cpp
  - test/2_library_checker/string/longest_common_substring.test.cpp
  - test/2_library_checker/string/suffix_array_vec.test.cpp
  - test/2_library_checker/string/number_of_substrings.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
documentation_of: ds/static_range_product.hpp
layout: document
redirect_from:
- /library/ds/static_range_product.hpp
- /library/ds/static_range_product.hpp.html
title: ds/static_range_product.hpp
---
