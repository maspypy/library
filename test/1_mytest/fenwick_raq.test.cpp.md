---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_add.hpp
    title: alg/acted_monoid/sum_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree_range_add.hpp
    title: ds/fenwicktree/fenwicktree_range_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/fenwick_raq.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n\
    #include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\
    \u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\
    \u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include\
    \ <bits/stdc++.h>\n#include <cassert>\n\nusing namespace std;\n\nusing ll = long\
    \ long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing\
    \ f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false = false;\n\
    \ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<i128>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i128>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing pq_max = priority_queue<T>;\ntemplate <class T>\nusing\
    \ pq_min = priority_queue<T, vector<T>, greater<T>>;\n\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n \
    \     h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n\
    #define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\n// require y > 0\n\
    template <typename T>\nT floor(T x, T y) {\n  return x / y - (x % y < 0);\n}\n\
    \n// require y > 0\ntemplate <typename T>\nT ceil(T x, T y) {\n  return (x / y)\
    \ + (x % y > 0);\n}\n\n// require y > 0\ntemplate <typename T>\nT bmod(T x, T\
    \ y) {\n  T r = x % y;\n  return (r < 0 ? r + y : r);\n}\n\n// require y > 0\n\
    template <typename T>\npair<T, T> divmod(T x, T y) {\n  T q = x / y, r = x % y;\n\
    \  if (r < 0) --q, r += y;\n  return {q, r};\n}\n\nconstexpr auto TEN = [] {\n\
    \  array<u64, 20> A{};\n  A[0] = 1;\n  for (int i = 1; i < 20; ++i) A[i] = 10\
    \ * A[i - 1];\n  return A;\n}();\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\ni128 binary_search(F check, i128 ok,\
    \ i128 ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while\
    \ (1) {\n    i128 x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n   \
    \ (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble\
    \ binary_search_real(F check, double ok, double ng, int iter = 100) {\n  FOR(iter)\
    \ {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return\
    \ changed;\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  T c = min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/fenwick_raq.test.cpp\"\n\n#line\
    \ 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\
    \n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n  vc<bool> has_laz;\n\n  Lazy_SegTree()\
    \ {}\n  Lazy_SegTree(int n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id(); });\n\
    \  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::id());\n    laz.assign(size, MA::id());\n    has_laz.assign(size,\
    \ false);\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n\
    \  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n\
    \  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i =\
    \ 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const X& x) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = MX::op(dat[p], x);\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return\
    \ dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k); }\n    return\
    \ {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r)\
    \ {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return MX::id();\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    X xl = MX::id(), xr = MX::id();\n    while (l < r) {\n  \
    \    if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r],\
    \ xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X\
    \ prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int\
    \ l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++, a);\n \
    \     if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2,\
    \ r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) !=\
    \ l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n\
    \    }\n  }\n\n  template <typename F>\n  int max_right(const F check, int l)\
    \ {\n    assert(0 <= l && l <= n);\n    assert(check(MX::id()));\n    if (l ==\
    \ n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    X sm = MX::id();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm,\
    \ dat[l]))) {\n        while (l < size) {\n          push(l);\n          l = (2\
    \ * l);\n          if (check(MX::op(sm, dat[l]))) {\n            sm = MX::op(sm,\
    \ dat[l++]);\n          }\n        }\n        return l - size;\n      }\n    \
    \  sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n \
    \ }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::id()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::id();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n\
    \      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n       \
    \   push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r], sm)))\
    \ {\n            sm = MX::op(dat[r--], sm);\n          }\n        }\n        return\
    \ r + 1 - size;\n      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r)\
    \ != r);\n    return 0;\n  }\n\n  // l <= i xor (xor_val) < r \u3068\u306A\u308B\
    \ i \u5168\u4F53\u306B apply\n  void apply_xor_range(int l, int r, int xor_val,\
    \ A a) {\n    assert(!(n & (n - 1)));\n    assert(0 <= xor_val && xor_val < n);\n\
    \    assert(0 <= l && l <= r && r <= n);\n\n    auto dfs = [&](auto& dfs, int\
    \ idx, int seg_l, int seg_r) -> void {\n      if (l <= seg_l && seg_r <= r) {\n\
    \        return apply_at(idx, a);\n      }\n      if (r <= seg_l || seg_r <= l)\
    \ return;\n      push(idx);\n      int seg_m = (seg_l + seg_r) / 2;\n      int\
    \ bit = (seg_r - seg_l) / 2;\n      int left = 2 * idx + 0, right = 2 * idx +\
    \ 1;\n      if (xor_val & bit) swap(left, right);\n      dfs(dfs, left, seg_l,\
    \ seg_m);\n      dfs(dfs, right, seg_m, seg_r);\n      update(idx);\n    };\n\
    \    dfs(dfs, 1, 0, n);\n  }\n\n private:\n  void apply_at(int k, A a) {\n   \
    \ ll sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if\
    \ (k < size) has_laz[k] = 1, laz[k] = MA::op(laz[k], a);\n  }\n  void push(int\
    \ k) {\n    if (!has_laz[k]) return;\n    has_laz[k] = 0;\n    apply_at(2 * k,\
    \ laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k] = MA::id();\n  }\n};\n#line\
    \ 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add {\n  using\
    \ X = E;\n  using value_type = X;\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\n  static constexpr X id() { return X(0); }\n  static constexpr\
    \ bool commute = true;\n};\n#line 2 \"alg/acted_monoid/sum_add.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct ActedMonoid_Sum_Add {\r\n  using Monoid_X = Monoid_Add<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    return x + a * E(size);\r\n  }\r\n\
    };\r\n#line 1 \"ds/fenwicktree/fenwicktree_range_add.hpp\"\n\n#line 1 \"other/bit.hpp\"\
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
    \  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total = G::op(total,\
    \ x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n\
    \  }\n  void set(int k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\
    \n  template <class F>\n  int max_right(const F check, int L = 0) const {\n  \
    \  assert(check(G::id()));\n    E s = G::id();\n    int i = L;\n    // 2^k \u9032\
    \u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n        if (i\
    \ % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i - 1])), i -= 1;\n     \
    \   }\n        if (i == 0) {\n          return topbit(n) + 1;\n        }\n   \
    \     int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n      \
    \  E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) {\n        \
    \  return k;\n        }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i\
    \ & -i;\n      }\n    }();\n    while (k) {\n      --k;\n      if (i + (1 << k)\
    \ - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if\
    \ (i + (1 << k) <= L || check(t)) {\n          i += (1 << k), s = t;\n       \
    \ }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n  template <class\
    \ F>\n  int max_right_with_index(const F check, int L = 0) const {\n    assert(check(L,\
    \ G::id()));\n    E s = G::id();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\
    \u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1)\
    \ {\n          s = G::op(s, G::inverse(dat[i - 1])), i -= 1;\n        }\n    \
    \    if (i == 0) {\n          return topbit(n) + 1;\n        }\n        int k\
    \ = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (!check(i + (1 << k), t)) {\n          return\
    \ k;\n        }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n\
    \      }\n    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 <\
    \ len(dat)) {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (i +\
    \ (1 << k) <= L || check(i + (1 << k), t)) {\n          i += (1 << k), s = t;\n\
    \        }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) const {\n    assert(check(G::id()));\n    E s\
    \ = G::id();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\
    \u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n  \
    \    s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n   \
    \ }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n    //\
    \ 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\
    \u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i\
    \ + (1 << k) - 1]));\n      if (!check(t)) {\n        i += (1 << k), s = t;\n\
    \      }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int L = 0) const {\n\
    \    return max_right([&k](E x) -> bool { return x <= k; }, L);\n  }\n};\n#line\
    \ 3 \"ds/fenwicktree/fenwicktree_range_add.hpp\"\n\n// \u9045\u5EF6\u30BB\u30B0\
    \u6728\u3088\u308A 4 \uFF5E 5 \u500D\u9AD8\u901F\uFF1F\n// https://maspypy.github.io/library/test/mytest/fenwick_raq.test.cpp\n\
    // https://codeforces.com/contest/860/submission/228355081\ntemplate <typename\
    \ AbelianGroup>\nstruct FenwickTree_Range_Add {\n  using G = AbelianGroup;\n \
    \ using E = typename AbelianGroup::value_type;\n  int n;\n  FenwickTree<G> bit0;\n\
    \  FenwickTree<G> bit1;\n\n  FenwickTree_Range_Add() {}\n  FenwickTree_Range_Add(int\
    \ n) { build(n); }\n  template <typename F>\n  FenwickTree_Range_Add(int n, F\
    \ f) {\n    build(n, f);\n  }\n  FenwickTree_Range_Add(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    bit0.build(n), bit1.build(n);\n\
    \  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m;\n    bit0.build(m, f);\n    bit1.build(m);\n  }\n\n  void add_at(int i, E\
    \ val) { bit0.add(i, val); }\n\n  void add(int L, int R, E val) {\n    bit0.add(L,\
    \ G::power(val, -L));\n    bit0.add(R, G::power(val, R));\n    bit1.add(L, val);\n\
    \    bit1.add(R, G::inverse(val));\n  }\n\n  E prod(int L, int R) {\n    E prod_R\
    \ = G::op(G::power(bit1.prod(R), R), bit0.prod(R));\n    E prod_L = G::op(G::power(bit1.prod(L),\
    \ L), bit0.prod(L));\n    return G::op(G::inverse(prod_L), prod_R);\n  }\n};\n\
    #line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 8 \"test/1_mytest/fenwick_raq.test.cpp\"\n\nvc<int>\
    \ solve_seg(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>> query) {\n  Lazy_SegTree<ActedMonoid_Sum_Add<int>>\
    \ seg(A);\n  vc<int> ANS;\n  for (auto& [L, R, x]: query) {\n    if (x == 0)\n\
    \      ANS.eb(seg.prod(L, R));\n    else\n      seg.apply(L, R, x);\n  }\n  return\
    \ ANS;\n}\n\nvc<int> solve_bit(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>>\
    \ query) {\n  FenwickTree_Range_Add<Monoid_Add<int>> seg(A);\n  vc<int> ANS;\n\
    \  for (auto& [L, R, x]: query) {\n    if (x == 0)\n      ANS.eb(seg.prod(L, R));\n\
    \    else\n      seg.add(L, R, x);\n  }\n  return ANS;\n}\n\nvoid test() {\n \
    \ ll N = 1 << 18, Q = 1 << 18;\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(0, 100);\n\
    \  vc<tuple<int, int, int>> query;\n  FOR(Q) {\n    int L = RNG(0, N), R = RNG(0,\
    \ N);\n    if (L > R) swap(L, R);\n    ++R;\n    int t = RNG(0, 2);\n    int x\
    \ = RNG(0, 100);\n    if (t == 1) x = 0;\n    query.eb(L, R, x);\n  }\n  vc<int>\
    \ ANS_1 = solve_seg(N, Q, A, query);\n  vc<int> ANS_2 = solve_bit(N, Q, A, query);\n\
    \  assert(ANS_1 == ANS_2);\n\n  /*\n  int a = clock();\n  FOR(100) solve_seg(N,\
    \ Q, A, query);\n  int b = clock();\n  FOR(100) solve_bit(N, Q, A, query);\n \
    \ int c = clock();\n  print(b - a, c - b);\n  print(double(b - a) / double(c -\
    \ b));\n  4.4 \u500D\u304F\u3089\u3044\u9AD8\u901F\u3068\u3044\u3046\u3053\u3068\
    \u306B\n  */\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/segtree/lazy_segtree.hpp\"\n#include \"alg/acted_monoid/sum_add.hpp\"\
    \n#include \"ds/fenwicktree/fenwicktree_range_add.hpp\"\n#include \"random/base.hpp\"\
    \n\nvc<int> solve_seg(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>> query) {\n\
    \  Lazy_SegTree<ActedMonoid_Sum_Add<int>> seg(A);\n  vc<int> ANS;\n  for (auto&\
    \ [L, R, x]: query) {\n    if (x == 0)\n      ANS.eb(seg.prod(L, R));\n    else\n\
    \      seg.apply(L, R, x);\n  }\n  return ANS;\n}\n\nvc<int> solve_bit(ll N, ll\
    \ Q, vc<int> A, vc<tuple<int, int, int>> query) {\n  FenwickTree_Range_Add<Monoid_Add<int>>\
    \ seg(A);\n  vc<int> ANS;\n  for (auto& [L, R, x]: query) {\n    if (x == 0)\n\
    \      ANS.eb(seg.prod(L, R));\n    else\n      seg.add(L, R, x);\n  }\n  return\
    \ ANS;\n}\n\nvoid test() {\n  ll N = 1 << 18, Q = 1 << 18;\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(0, 100);\n  vc<tuple<int, int, int>> query;\n  FOR(Q)\
    \ {\n    int L = RNG(0, N), R = RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n\
    \    int t = RNG(0, 2);\n    int x = RNG(0, 100);\n    if (t == 1) x = 0;\n  \
    \  query.eb(L, R, x);\n  }\n  vc<int> ANS_1 = solve_seg(N, Q, A, query);\n  vc<int>\
    \ ANS_2 = solve_bit(N, Q, A, query);\n  assert(ANS_1 == ANS_2);\n\n  /*\n  int\
    \ a = clock();\n  FOR(100) solve_seg(N, Q, A, query);\n  int b = clock();\n  FOR(100)\
    \ solve_bit(N, Q, A, query);\n  int c = clock();\n  print(b - a, c - b);\n  print(double(b\
    \ - a) / double(c - b));\n  4.4 \u500D\u304F\u3089\u3044\u9AD8\u901F\u3068\u3044\
    \u3046\u3053\u3068\u306B\n  */\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - ds/segtree/lazy_segtree.hpp
  - other/bit.hpp
  - alg/acted_monoid/sum_add.hpp
  - alg/monoid/add.hpp
  - ds/fenwicktree/fenwicktree_range_add.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/fenwick_raq.test.cpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/fenwick_raq.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/fenwick_raq.test.cpp
- /verify/test/1_mytest/fenwick_raq.test.cpp.html
title: test/1_mytest/fenwick_raq.test.cpp
---
