---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/minidx_add.hpp
    title: alg/acted_monoid/minidx_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/minidx.hpp
    title: alg/monoid/minidx.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"test/1_mytest/minidx_add.test.cpp\"\n#define PROBLEM \"\
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
    \ numeric_limits<double>::infinity();\ntemplate <>\nconstexpr long double infty<long\
    \ double> =\n    numeric_limits<long double>::infinity();\n\nusing pi = pair<ll,\
    \ ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (1)\
    \ {\n    ll x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c\
    \ = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\
    template <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F\
    \ -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  first.reserve(first.size() + (others.size() + ... + 0));\n\
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n\n// i128\n\
    template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr i128 abs(T\
    \ x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128 b) {\n\
    \  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return abs(a);\n\
    }\n#endif\n#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 1 \"alg/monoid/minidx.hpp\"\
    \n\ntemplate <typename T, bool tie_is_left = true>\nstruct Monoid_MinIdx {\n \
    \ using value_type = pair<T, int>;\n  using X = value_type;\n  static constexpr\
    \ bool is_small(const X& x, const X& y) {\n    if (x.fi < y.fi) return true;\n\
    \    if (x.fi > y.fi) return false;\n    return (tie_is_left ? (x.se < y.se) :\
    \ (x.se >= y.se));\n  }\n  static X op(X x, X y) { return (is_small(x, y) ? x\
    \ : y); }\n  static constexpr X unit() { return {infty<T>, -1}; }\n  static constexpr\
    \ bool commute = true;\n};\n#line 3 \"alg/acted_monoid/minidx_add.hpp\"\n\r\n\
    template <typename E, bool tie_is_left = true>\r\nstruct ActedMonoid_MinIdx_Add\
    \ {\r\n  using Monoid_X = Monoid_MinIdx<E, tie_is_left>;\r\n  using Monoid_A =\
    \ Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A =\
    \ typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    if (x.fi == infty<E>) return x;\r\n    return\
    \ {x.fi + a, x.se};\r\n  }\r\n};\r\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
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
    \  return x;\n}\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename\
    \ ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX =\
    \ typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename\
    \ MX::value_type;\n  using A = typename MA::value_type;\n  int n, log, size;\n\
    \  vc<X> dat;\n  vc<A> laz;\n  vc<bool> has_laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int n, F f) {\n  \
    \  build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    laz.assign(size, MA::unit());\n    has_laz.assign(size, false);\n    FOR(i,\
    \ n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void update(int\
    \ k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void set(int p, X x)\
    \ {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >=\
    \ 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n  void multiply(int p, const X& x) {\n    assert(0 <= p && p <\
    \ n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = MX::op(dat[p], x);\n    for (int i = 1; i <= log; i++) update(p >> i);\n \
    \ }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for\
    \ (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  vc<X>\
    \ get_all() {\n    FOR(k, 1, size) { push(k); }\n    return {dat.begin() + size,\
    \ dat.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l\
    \ && l <= r && r <= n);\n    if (l == r) return MX::unit();\n    l += size, r\
    \ += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) !=\
    \ l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\
    \    X xl = MX::unit(), xr = MX::unit();\n    while (l < r) {\n      if (l & 1)\
    \ xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r], xr);\n  \
    \    l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X prod_all()\
    \ { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n   \
    \ for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >>\
    \ i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int l2\
    \ = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++, a);\n    \
    \  if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2, r\
    \ = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\n  template <typename F>\n  int max_right(const F check, int l) {\n\
    \    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n    if (l == n)\
    \ return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >> i);\n\
    \    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l >>= 1;\n      if\
    \ (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n          push(l);\n\
    \          l = (2 * l);\n          if (check(MX::op(sm, dat[l]))) {\n        \
    \    sm = MX::op(sm, dat[l++]);\n          }\n        }\n        return l - size;\n\
    \      }\n      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n   \
    \ return n;\n  }\n\n  template <typename F>\n  int min_left(const F check, int\
    \ r) {\n    assert(0 <= r && r <= n);\n    assert(check(MX::unit()));\n    if\
    \ (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--) push((r\
    \ - 1) >> i);\n    X sm = MX::unit();\n    do {\n      r--;\n      while (r >\
    \ 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat[r], sm))) {\n        while\
    \ (r < size) {\n          push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r],\
    \ sm))) {\n            sm = MX::op(dat[r--], sm);\n          }\n        }\n  \
    \      return r + 1 - size;\n      }\n      sm = MX::op(dat[r], sm);\n    } while\
    \ ((r & -r) != r);\n    return 0;\n  }\n\n  // l <= i xor (xor_val) < r \u3068\
    \u306A\u308B i \u5168\u4F53\u306B apply\n  void apply_xor_range(int l, int r,\
    \ int xor_val, A a) {\n    assert(!(n & (n - 1)));\n    assert(0 <= xor_val &&\
    \ xor_val < n);\n    assert(0 <= l && l <= r && r <= n);\n\n    auto dfs = [&](auto&\
    \ dfs, int idx, int seg_l, int seg_r) -> void {\n      if (l <= seg_l && seg_r\
    \ <= r) {\n        return apply_at(idx, a);\n      }\n      if (r <= seg_l ||\
    \ seg_r <= l) return;\n      push(idx);\n      int seg_m = (seg_l + seg_r) / 2;\n\
    \      int bit = (seg_r - seg_l) / 2;\n      int left = 2 * idx + 0, right = 2\
    \ * idx + 1;\n      if (xor_val & bit) swap(left, right);\n      dfs(dfs, left,\
    \ seg_l, seg_m);\n      dfs(dfs, right, seg_m, seg_r);\n      update(idx);\n \
    \   };\n    dfs(dfs, 1, 0, n);\n  }\n\n private:\n  void apply_at(int k, A a)\
    \ {\n    ll sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n\
    \    if (k < size) has_laz[k] = 1, laz[k] = MA::op(laz[k], a);\n  }\n  void push(int\
    \ k) {\n    if (!has_laz[k]) return;\n    has_laz[k] = 0;\n    apply_at(2 * k,\
    \ laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n  }\n};\n#line\
    \ 6 \"test/1_mytest/minidx_add.test.cpp\"\n\nvoid test() {\n  int N = RNG(1, 100);\n\
    \  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(1, 100);\n  using AM = ActedMonoid_MinIdx_Add<int>;\n\
    \  using Mono = typename AM::Monoid_X;\n  Lazy_SegTree<AM> seg(N, [&](int i) ->\
    \ typename Mono::value_type {\n    return {A[i], i};\n  });\n  int Q = RNG(1,\
    \ 100);\n  FOR(Q) {\n    ll t = RNG(0, 2);\n    ll L = RNG(0, N);\n    ll R =\
    \ RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n    if (t == 1) {\n      ll\
    \ x = RNG(1, 100);\n      FOR(i, L, R) A[i] += x;\n      seg.apply(L, R, x);\n\
    \    }\n    if (t == 2) {\n      vc<int> B = {A.begin() + L, A.begin() + R};\n\
    \      int mx = MIN(B);\n      int idx = -1;\n      FOR_R(i, L, R) if (A[i] ==\
    \ mx) idx = i;\n      assert(seg.prod(L, R) == mp(mx, idx));\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/acted_monoid/minidx_add.hpp\"\n#include \"random/base.hpp\"\n\
    #include \"ds/segtree/lazy_segtree.hpp\"\n\nvoid test() {\n  int N = RNG(1, 100);\n\
    \  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(1, 100);\n  using AM = ActedMonoid_MinIdx_Add<int>;\n\
    \  using Mono = typename AM::Monoid_X;\n  Lazy_SegTree<AM> seg(N, [&](int i) ->\
    \ typename Mono::value_type {\n    return {A[i], i};\n  });\n  int Q = RNG(1,\
    \ 100);\n  FOR(Q) {\n    ll t = RNG(0, 2);\n    ll L = RNG(0, N);\n    ll R =\
    \ RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n    if (t == 1) {\n      ll\
    \ x = RNG(1, 100);\n      FOR(i, L, R) A[i] += x;\n      seg.apply(L, R, x);\n\
    \    }\n    if (t == 2) {\n      vc<int> B = {A.begin() + L, A.begin() + R};\n\
    \      int mx = MIN(B);\n      int idx = -1;\n      FOR_R(i, L, R) if (A[i] ==\
    \ mx) idx = i;\n      assert(seg.prod(L, R) == mp(mx, idx));\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - alg/acted_monoid/minidx_add.hpp
  - alg/monoid/add.hpp
  - alg/monoid/minidx.hpp
  - random/base.hpp
  - ds/segtree/lazy_segtree.hpp
  - other/bit.hpp
  isVerificationFile: true
  path: test/1_mytest/minidx_add.test.cpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/minidx_add.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/minidx_add.test.cpp
- /verify/test/1_mytest/minidx_add.test.cpp.html
title: test/1_mytest/minidx_add.test.cpp
---
