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
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: other/sliding_puzzle_solver.hpp
    title: other/sliding_puzzle_solver.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1838.test.cpp
    title: test/3_yukicoder/1838.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/694.test.cpp
    title: test/3_yukicoder/694.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ALDS1_2_A.test.cpp
    title: test/4_aoj/ALDS1_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ALDS1_5.test.cpp
    title: test/4_aoj/ALDS1_5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\n#line 1 \"other/bit.hpp\"\
    \n\nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\nint popcnt_sgn(int\
    \ x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }\nint popcnt_sgn(u32\
    \ x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\nint popcnt_sgn(ll x) { return\
    \ (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x)\
    \ & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x == 0 ? -1\
    \ : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32 x) { return\
    \ (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  assert(0 <= k && k < int(8\
    \ * sizeof(T)));\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return x >> k &\
    \ 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  UINT s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n\
    \    bool done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
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
    \  void multiply(int k, E x) {\n    SHOW(n, k);\n    static_assert(G::commute);\n\
    \    assert(0 <= k && k < n);\n    total = G::op(total, x);\n    for (++k; k <=\
    \ n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int k, E\
    \ x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class F>\n\
    \  int max_right(const F check, int L = 0) const {\n    assert(check(G::id()));\n\
    \    E s = G::id();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) {\n        \
    \  s = G::op(s, G::inverse(dat[i - 1])), i -= 1;\n        }\n        if (i ==\
    \ 0) {\n          return topbit(n) + 1;\n        }\n        int k = lowbit(i)\
    \ - 1;\n        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i\
    \ + (1 << k) - 1]);\n        if (!check(t)) {\n          return k;\n        }\n\
    \        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n\
    \    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n     \
    \   E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (i + (1 << k) <= L || check(t))\
    \ {\n          i += (1 << k), s = t;\n        }\n      }\n    }\n    return i;\n\
    \  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check, int L = 0) const {\n    assert(check(L, G::id()));\n    E s = G::id();\n\
    \    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]()\
    \ {\n      while (1) {\n        if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= 1;\n        }\n        if (i == 0) {\n          return topbit(n)\
    \ + 1;\n        }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) >\
    \ n) return k;\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(i\
    \ + (1 << k), t)) {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i\
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
    \  }\n};\n#line 3 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\nstruct FenwickTree_01\
    \ {\n  using MX = Monoid_Add<int>;\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n  void build(vc<int> dat) {\n    build(len(dat),\
    \ [&](int i) -> int { return dat[i]; });\n  }\n\n  template <typename F>\n  void\
    \ build(int m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }\n    bit.build(n,\
    \ [&](int i) -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return\
    \ bit.sum_all(); }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int\
    \ k) {\n    int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k / 64] & ((u64(1)\
    \ << (k % 64)) - 1));\n    return ans;\n  }\n  int sum(int L, int R) {\n    if\
    \ (L == 0) return prefix_sum(R);\n    int ans = 0;\n    ans -= popcnt(dat[L /\
    \ 64] & ((u64(1) << (L % 64)) - 1));\n    ans += popcnt(dat[R / 64] & ((u64(1)\
    \ << (R % 64)) - 1));\n    ans += bit.sum(L / 64, R / 64);\n    return ans;\n\
    \  }\n  int get(int i) {\n    assert(0 <= i && i < N);\n    return sum(i, i +\
    \ 1);\n  }\n  int prod(int L, int R) { return sum(L, R); }\n\n  void add(int k,\
    \ int x) {\n    assert(0 <= k && k < N);\n    if (x == 1) {\n      assert(sum(k,\
    \ k + 1) == 0);\n      add(k);\n    }\n    elif (x == -1) {\n      assert(sum(k,\
    \ k + 1) == 1);\n      remove(k);\n    }\n    else assert(0);\n  }\n  void multiply(int\
    \ k, int x) { add(k, x); }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) <<\
    \ (k % 64);\n    bit.add(k / 64, 1);\n  }\n  void remove(int k) {\n    dat[k /\
    \ 64] &= ~(u64(1) << (k % 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int\
    \ k, int L = 0) {\n    if (k >= sum_all()) return N;\n    k += popcnt(dat[L /\
    \ 64] & ((u64(1) << (L % 64)) - 1));\n    L /= 64;\n    int mid = 0;\n    auto\
    \ check = [&](auto e) -> bool {\n      if (e <= k) chmax(mid, e);\n      return\
    \ e <= k;\n    };\n    int idx = bit.max_right(check, L);\n    if (idx == n) return\
    \ N;\n    k -= mid;\n    u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p\
    \ <= k) return N;\n    k = binary_search([&](int n) -> bool { return (p - popcnt(x\
    \ >> n)) <= k; },\n                      0, 64, 0);\n    return 64 * idx + k;\n\
    \  }\n\n  int next(int k) {\n    int idx = k / 64;\n    k %= 64;\n    u64 x =\
    \ dat[idx] & ~((u64(1) << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n\
    \    idx = bit.kth(0, idx + 1);\n    if (idx == n || !dat[idx]) return N;\n  \
    \  return 64 * idx + lowbit(dat[idx]);\n  }\n\n  int prev(int k) {\n    if (k\
    \ == N) --k;\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx];\n   \
    \ if (k < 63) x &= (u64(1) << (k + 1)) - 1;\n    if (x) return 64 * idx + topbit(x);\n\
    \    idx = bit.min_left([&](auto e) -> bool { return e <= 0; }, idx) - 1;\n  \
    \  if (idx == -1) return -1;\n    return 64 * idx + topbit(dat[idx]);\n  }\n\n\
    \  string to_string() {\n    string out;\n    FOR(i, N) out += '0' + (dat[i /\
    \ 64] >> (i & 63) & 1);\n    return out;\n  }\n};\n#line 2 \"seq/inversion.hpp\"\
    \n\ntemplate <typename T>\nll inversion(vc<T> A) {\n  int N = len(A);\n  if (A.empty())\
    \ return 0;\n  ll ANS = 0;\n  FenwickTree_01 bit(N);\n  auto I = argsort(A);\n\
    \  for (auto& i : I) {\n    ANS += bit.sum_all() - bit.sum(i);\n    bit.add(i,\
    \ 1);\n  }\n  return ANS;\n}\n\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\
    \u306A\u308B\u3088\u3046\u306B rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\
    \u6570\ntemplate <typename T, bool SMALL = false>\nvi inversion_rotate(vc<T>&\
    \ A) {\n  const int N = len(A);\n  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n\
    \    for (auto&& x : A) x = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS =\
    \ 0;\n  FenwickTree<Monoid_Add<int>> bit(K);\n  for (auto&& x : A) {\n    ANS\
    \ += bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n\
    \    res[i] = ANS;\n    ll x = A[i];\n    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);\n\
    \  }\n  return res;\n}\n\n// inv[i][j] = inversion A[i:j) \u3067\u3042\u308B\u3088\
    \u3046\u306A (N+1, N+1) \u30C6\u30FC\u30D6\u30EB\ntemplate <typename T>\nvvc<int>\
    \ all_range_inversion(const vc<T>& A) {\n  int N = len(A);\n  vv(int, dp, N +\
    \ 1, N + 1);\n  FOR_R(L, N + 1) FOR(R, L + 2, N + 1) {\n    dp[L][R] = dp[L][R\
    \ - 1] + dp[L + 1][R] - dp[L + 1][R - 1];\n    if (A[L] > A[R - 1]) ++dp[L][R];\n\
    \  }\n  return dp;\n}\n\ntemplate <typename T>\nll inversion_between(vc<T> A,\
    \ vc<T> B) {\n  int N = len(A);\n  map<T, vc<int>> MP;\n  FOR(i, N) MP[B[i]].eb(i);\n\
    \  vc<int> TO(N);\n  FOR_R(i, N) {\n    auto& I = MP[A[i]];\n    if (I.empty())\
    \ return -1;\n    TO[i] = POP(I);\n  }\n  return inversion(TO);\n}\n"
  code: "#include \"ds/fenwicktree/fenwicktree_01.hpp\"\n\ntemplate <typename T>\n\
    ll inversion(vc<T> A) {\n  int N = len(A);\n  if (A.empty()) return 0;\n  ll ANS\
    \ = 0;\n  FenwickTree_01 bit(N);\n  auto I = argsort(A);\n  for (auto& i : I)\
    \ {\n    ANS += bit.sum_all() - bit.sum(i);\n    bit.add(i, 1);\n  }\n  return\
    \ ANS;\n}\n\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\u306A\u308B\u3088\
    \u3046\u306B rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\u6570\ntemplate\
    \ <typename T, bool SMALL = false>\nvi inversion_rotate(vc<T>& A) {\n  const int\
    \ N = len(A);\n  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n    for (auto&&\
    \ x : A) x = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS = 0;\n  FenwickTree<Monoid_Add<int>>\
    \ bit(K);\n  for (auto&& x : A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x,\
    \ 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n    res[i] = ANS;\n    ll x = A[i];\n\
    \    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);\n  }\n  return res;\n\
    }\n\n// inv[i][j] = inversion A[i:j) \u3067\u3042\u308B\u3088\u3046\u306A (N+1,\
    \ N+1) \u30C6\u30FC\u30D6\u30EB\ntemplate <typename T>\nvvc<int> all_range_inversion(const\
    \ vc<T>& A) {\n  int N = len(A);\n  vv(int, dp, N + 1, N + 1);\n  FOR_R(L, N +\
    \ 1) FOR(R, L + 2, N + 1) {\n    dp[L][R] = dp[L][R - 1] + dp[L + 1][R] - dp[L\
    \ + 1][R - 1];\n    if (A[L] > A[R - 1]) ++dp[L][R];\n  }\n  return dp;\n}\n\n\
    template <typename T>\nll inversion_between(vc<T> A, vc<T> B) {\n  int N = len(A);\n\
    \  map<T, vc<int>> MP;\n  FOR(i, N) MP[B[i]].eb(i);\n  vc<int> TO(N);\n  FOR_R(i,\
    \ N) {\n    auto& I = MP[A[i]];\n    if (I.empty()) return -1;\n    TO[i] = POP(I);\n\
    \  }\n  return inversion(TO);\n}"
  dependsOn:
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - other/bit.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: seq/inversion.hpp
  requiredBy:
  - other/sliding_puzzle_solver.hpp
  timestamp: '2026-08-31 22:36:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/4_aoj/ALDS1_2_A.test.cpp
  - test/4_aoj/ALDS1_5.test.cpp
  - test/3_yukicoder/694.test.cpp
  - test/3_yukicoder/1838.test.cpp
documentation_of: seq/inversion.hpp
layout: document
redirect_from:
- /library/seq/inversion.hpp
- /library/seq/inversion.hpp.html
title: seq/inversion.hpp
---
