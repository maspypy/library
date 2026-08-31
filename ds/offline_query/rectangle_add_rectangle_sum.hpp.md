---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/coefficient_query_2d.hpp
    title: ds/offline_query/coefficient_query_2d.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
    title: test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1490.test.cpp
    title: test/3_yukicoder/1490.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \ SMALL>>::type;\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"alg/monoid/add.hpp\"\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct FenwickTree {\n  using G = Monoid;\n  using MX = Monoid;\n  using E = typename\
    \ G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n\
    \  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::id());\n    total\
    \ = G::id();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i)\
    \ -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F\
    \ f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::id();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() const { return\
    \ total; }\n  E sum_all() const { return total; }\n  E sum(int k) const { return\
    \ prefix_sum(k); }\n  E prod(int k) const { return prefix_prod(k); }\n  E prefix_sum(int\
    \ k) const { return prefix_prod(k); }\n  E prefix_prod(int k) const {\n    chmin(k,\
    \ n);\n    E ret = G::id();\n    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k\
    \ - 1]);\n    return ret;\n  }\n  E sum(int L, int R) const { return prod(L, R);\
    \ }\n  E prod(int L, int R) const {\n    chmax(L, 0), chmin(R, n);\n    if (L\
    \ == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E\
    \ pos = G::id(), neg = G::id();\n    while (L < R) {\n      pos = G::op(pos, dat[R\
    \ - 1]), R -= R & -R;\n    }\n    while (R < L) {\n      neg = G::op(neg, dat[L\
    \ - 1]), L -= L & -L;\n    }\n    return G::op(pos, G::inverse(neg));\n  }\n\n\
    \  vc<E> get_all() const {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i,\
    \ i + 1);\n    return res;\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n\
    \  void multiply(int k, E x) {\n    static_assert(G::commute);\n    assert(0 <=\
    \ k && k < n);\n    total = G::op(total, x);\n    for (++k; k <= n; k += k & -k)\
    \ dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int k, E x) { add(k, G::op(G::inverse(prod(k,\
    \ k + 1)), x)); }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L = 0) const {\n    assert(check(G::id()));\n    E s = G::id();\n    int i =\
    \ L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while\
    \ (1) {\n        if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i -\
    \ 1])), i -= 1;\n        }\n        if (i == 0) {\n          return topbit(n)\
    \ + 1;\n        }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) >\
    \ n) return k;\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t))\
    \ {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i - 1])),\
    \ i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n      if (i +\
    \ (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n\
    \        if (i + (1 << k) <= L || check(t)) {\n          i += (1 << k), s = t;\n\
    \        }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n  template\
    \ <class F>\n  int max_right_with_index(const F check, int L = 0) const {\n  \
    \  assert(check(L, G::id()));\n    E s = G::id();\n    int i = L;\n    // 2^k\
    \ \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n   \
    \     if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i - 1])), i -=\
    \ 1;\n        }\n        if (i == 0) {\n          return topbit(n) + 1;\n    \
    \    }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(i + (1 <<\
    \ k), t)) {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n     \
    \ if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k)\
    \ - 1]);\n        if (i + (1 << k) <= L || check(i + (1 << k), t)) {\n       \
    \   i += (1 << k), s = t;\n        }\n      }\n    }\n    return i;\n  }\n\n \
    \ template <class F>\n  int min_left(const F check, int R) const {\n    assert(check(G::id()));\n\
    \    E s = G::id();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\
    \u308D\u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s))\
    \ {\n      s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n\
    \    }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n \
    \   // 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\
    \u6301\u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s,\
    \ G::inverse(dat[i + (1 << k) - 1]));\n      if (!check(t)) {\n        i += (1\
    \ << k), s = t;\n      }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int\
    \ L = 0) const {\n    return max_right([&k](E x) -> bool { return x <= k; }, L);\n\
    \  }\n};\n#line 3 \"ds/offline_query/coefficient_query_2d.hpp\"\n\n// A, B\uFF1A\
    \u5B9A\u6570\n// \u5EA7\u6A19\u306F ll \u3067\u4FC2\u6570\u306F T\n// Sparse Laurent\
    \ Polynomial f(x,y) \u3092\u4E0E\u3048\u308B\n// [x^py^q] f(x,y)/(1-x)^A(1-y)^B\
    \ \u3092\u305F\u304F\u3055\u3093\u6C42\u3081\u308B\n// O(AB N logN) \u6642\u9593\
    \ntemplate <int A, int B, typename T, bool STATIC>\nstruct Coefficient_Query_2D\
    \ {\n  struct Mono {\n    using value_type = array<T, A * B>;\n    using X = value_type;\n\
    \    static X op(X x, X y) {\n      FOR(i, A * B) x[i] += y[i];\n      return\
    \ x;\n    }\n    static constexpr X id() { return X{}; }\n    static constexpr\
    \ bool commute = 1;\n  };\n  vc<tuple<ll, ll, T, int>> query;\n\n  int nsum =\
    \ 0;\n  Coefficient_Query_2D() {}\n  void add_query(ll x, ll y, T c) {\n    if\
    \ (c != T(0)) query.eb(x, y, c, -1);\n  }\n  void sum_query(ll p, ll q) { query.eb(p,\
    \ q, 0, nsum++); }\n\n  // \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306A\u3069\
    \u306E\u72B6\u6CC1\u6B21\u7B2C\u3067\u66F8\u304D\u63DB\u3048\u308B\n  template\
    \ <int n>\n  void comb_array(ll x, array<T, n>& S) {\n    static_assert(n < 4);\n\
    \    if constexpr (n == 1) S = {T(1)};\n    if constexpr (n == 2) S = {T(1), T(x)};\n\
    \    if constexpr (n == 3) S = {T(1), T(x), T(x * (x - 1) / 2)};\n  }\n  template\
    \ <int n>\n  void coef_array(ll b, array<T, n>& S) {\n    static_assert(n < 4);\n\
    \    // [t^x]t^b(1-t)^{-n} \u3092 binom(x,k) \u306E\u7DDA\u5F62\u7D50\u5408\u3067\
    \u8868\u3059\u4FC2\u6570\n    if constexpr (n == 1) S = {T(1)};\n    if constexpr\
    \ (n == 2) S = {T(1 - b), T(1)};\n    if constexpr (n == 3) S = {T((b - 1) * (b\
    \ - 2) / 2), T(2 - b), T(1)};\n  }\n\n  vc<T> ANS;\n  bool done = false;\n  void\
    \ calc_static(const vc<int>& ADD_I, vc<int>& GET_I) {\n    if (ADD_I.empty() ||\
    \ GET_I.empty()) return;\n    Index_Compression<ll, true, false> IY;\n    {\n\
    \      vc<ll> tmp;\n      for (int q : ADD_I) {\n        auto [a, b, w, qid] =\
    \ query[q];\n        if (qid == -1) tmp.eb(b);\n      }\n      IY.build(tmp);\n\
    \    }\n\n    FenwickTree<Mono> bit(len(IY));\n\n    array<T, A> CX;\n    array<T,\
    \ B> CY;\n    array<T, A * B> tmp;\n\n    int ptr = 0;\n    for (int q : GET_I)\
    \ {\n      auto [a, b, w, qid] = query[q];\n      while (ptr < len(ADD_I) && (get<0>(query[ADD_I[ptr]]))\
    \ <= a) {\n        int q = ADD_I[ptr++];\n        auto [a, b, w, qid] = query[q];\n\
    \        coef_array<A>(a, CX);\n        coef_array<B>(b, CY);\n        FOR(i,\
    \ A) FOR(j, B) tmp[B * i + j] = CX[i] * CY[j] * w;\n        bit.add(IY.val_to_idx(b),\
    \ tmp);\n      }\n      comb_array<A>(a, CX);\n      comb_array<B>(b, CY);\n \
    \     // calc query\n      tmp = bit.prod(IY.val_to_idx(b + 1));\n      T ans\
    \ = 0;\n      FOR(i, A) FOR(j, B) ans += tmp[B * i + j] * CX[i] * CY[j];\n   \
    \   ANS[qid] += ans;\n    }\n  }\n\n  vc<T> calc() {\n    assert(!done);\n   \
    \ done = 1;\n    ANS.assign(nsum, 0);\n    int Q = len(query);\n    auto comp\
    \ = [&](int i, int j) -> bool {\n      return (get<0>(query[i])) < (get<0>(query[j]));\n\
    \    };\n    if (STATIC) {\n      vc<int> ADD, GET;\n      FOR(i, Q) { (get<3>(query[i])\
    \ == -1 ? ADD : GET).eb(i); }\n      sort(all(ADD), comp);\n      sort(all(GET),\
    \ comp);\n      calc_static(ADD, GET);\n      return ANS;\n    }\n    auto dfs\
    \ = [&](auto& dfs, int L, int R) -> pair<vc<int>, vc<int>> {\n      vc<int> ADD,\
    \ GET;\n      if (R == L + 1) {\n        (get<3>(query[L]) == -1 ? ADD : GET).eb(L);\n\
    \        return {ADD, GET};\n      }\n      int M = (L + R) / 2;\n      auto [ADD1,\
    \ GET1] = dfs(dfs, L, M);\n      auto [ADD2, GET2] = dfs(dfs, M, R);\n      calc_static(ADD1,\
    \ GET2);\n      ADD.resize(len(ADD1) + len(ADD2));\n      GET.resize(len(GET1)\
    \ + len(GET2));\n      merge(all(ADD1), all(ADD2), ADD.begin(), comp);\n     \
    \ merge(all(GET1), all(GET2), GET.begin(), comp);\n      return {ADD, GET};\n\
    \    };\n    dfs(dfs, 0, Q);\n    return ANS;\n  }\n};\n#line 2 \"ds/offline_query/rectangle_add_rectangle_sum.hpp\"\
    \n\ntemplate <typename T>\nstruct Rectangle_Add_Rectangle_Sum {\n  Coefficient_Query_2D<2,\
    \ 2, T, true> CQ;\n  void add_query(ll x1, ll x2, ll y1, ll y2, T w) {\n    CQ.add_query(x1,\
    \ y1, w), CQ.add_query(x1, y2, -w);\n    CQ.add_query(x2, y1, -w), CQ.add_query(x2,\
    \ y2, w);\n  }\n  void sum_query(ll x1, ll x2, ll y1, ll y2) {\n    --x1, --y1,\
    \ --x2, --y2;\n    CQ.sum_query(x1, y1), CQ.sum_query(x1, y2);\n    CQ.sum_query(x2,\
    \ y1), CQ.sum_query(x2, y2);\n  }\n  vc<T> calc() {\n    vc<T> tmp = CQ.calc();\n\
    \    int Q = len(tmp) / 4;\n    vc<T> res(Q);\n    FOR(q, Q) {\n      res[q] =\
    \ tmp[4 * q] - tmp[4 * q + 1] - tmp[4 * q + 2] + tmp[4 * q + 3];\n    }\n    return\
    \ res;\n  }\n};\n"
  code: "#include \"ds/offline_query/coefficient_query_2d.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Rectangle_Add_Rectangle_Sum {\n  Coefficient_Query_2D<2, 2, T, true>\
    \ CQ;\n  void add_query(ll x1, ll x2, ll y1, ll y2, T w) {\n    CQ.add_query(x1,\
    \ y1, w), CQ.add_query(x1, y2, -w);\n    CQ.add_query(x2, y1, -w), CQ.add_query(x2,\
    \ y2, w);\n  }\n  void sum_query(ll x1, ll x2, ll y1, ll y2) {\n    --x1, --y1,\
    \ --x2, --y2;\n    CQ.sum_query(x1, y1), CQ.sum_query(x1, y2);\n    CQ.sum_query(x2,\
    \ y1), CQ.sum_query(x2, y2);\n  }\n  vc<T> calc() {\n    vc<T> tmp = CQ.calc();\n\
    \    int Q = len(tmp) / 4;\n    vc<T> res(Q);\n    FOR(q, Q) {\n      res[q] =\
    \ tmp[4 * q] - tmp[4 * q + 1] - tmp[4 * q + 2] + tmp[4 * q + 3];\n    }\n    return\
    \ res;\n  }\n};"
  dependsOn:
  - ds/offline_query/coefficient_query_2d.hpp
  - ds/index_compression.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - other/bit.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/offline_query/rectangle_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '2026-08-31 13:26:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
  - test/3_yukicoder/1490.test.cpp
documentation_of: ds/offline_query/rectangle_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp
- /library/ds/offline_query/rectangle_add_rectangle_sum.hpp.html
title: ds/offline_query/rectangle_add_rectangle_sum.hpp
---
