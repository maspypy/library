---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_monoid/max_add.hpp
    title: alg/acted_monoid/max_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':question:'
    path: ds/segtree/dynamic_segtree_sparse.hpp
    title: ds/segtree/dynamic_segtree_sparse.hpp
  - icon: ':x:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':x:'
    path: ds/segtree/range_add_range_max.hpp
    title: ds/segtree/range_add_range_max.hpp
  - icon: ':x:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/range_add_range_max.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
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
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nconstexpr ll\
    \ TEN[] = {\n    1LL,\n    10LL,\n    100LL,\n    1000LL,\n    10000LL,\n    100000LL,\n\
    \    1000000LL,\n    10000000LL,\n    100000000LL,\n    1000000000LL,\n    10000000000LL,\n\
    \    100000000000LL,\n    1000000000000LL,\n    10000000000000LL,\n    100000000000000LL,\n\
    \    1000000000000000LL,\n    10000000000000000LL,\n    100000000000000000LL,\n\
    \    1000000000000000000LL,\n};\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <class T,\
    \ class Container, class Compare>\nT POP(priority_queue<T, Container, Compare>\
    \ &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n\
    }\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok\
    \ = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok - ng) > 1)\
    \ {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  vc<T> &res\
    \ = first;\n  (res.insert(res.end(), others.begin(), others.end()), ...);\n}\n\
    #endif\n#line 3 \"test/1_mytest/range_add_range_max.test.cpp\"\n\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/max.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct Monoid_Max {\r\n  using X = E;\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return max(x, y); }\r\
    \n  static constexpr X unit() { return -infty<E>; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/max_add.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct ActedMonoid_Max_Add {\r\n  using Monoid_X = Monoid_Max<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (x == -infty<E>) return x;\r\n\
    \    return x + a;\r\n  }\r\n};\r\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\n\
    template <typename ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int n, F f) {\n  \
    \  build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int\
    \ p, const X& x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat[p] = MX::op(dat[p], x);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k);\
    \ }\n    return {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int\
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return\
    \ MX::unit();\n    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n\
    \      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n    }\n    X xl = MX::unit(), xr = MX::unit();\n    while\
    \ (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr\
    \ = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl,\
    \ xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r,\
    \ A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n \
    \   l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1)\
    \ apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n     \
    \ if (((l >> i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F\
    \ check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l\
    \ >>= 1;\n      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n\
    \          push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
    \ { sm = MX::op(sm, dat[l++]); }\n        }\n        return l - size;\n      }\n\
    \      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n\
    \  }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>=\
    \ 1;\n      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n  \
    \        push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r],\
    \ sm))) { sm = MX::op(dat[r--], sm); }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r) != r);\n    return\
    \ 0;\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n    ll sz = 1 << (log -\
    \ topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k < size) laz[k]\
    \ = MA::op(laz[k], a);\n  }\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 1 \"ds/segtree/dynamic_segtree_sparse.hpp\"\n\n\
    // \u5E38\u306B\u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\u3042\
    \u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\u52D5\
    \u7684\u30BB\u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod\
    \ \u306E\u985E\u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\
    \u4E00\u822C\u306B\u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\
    \u3068\u304D\u30CE\u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\
    \u308B\ntemplate <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node\
    \ {\n    int ch[2];\n    ll idx;\n    X prod, x;\n  };\n  const ll L0, R0;\n \
    \ static constexpr int NIL = 0;\n  vc<Node> node;\n  vc<int> FREE;\n\n  Dynamic_SegTree_Sparse(ll\
    \ L0, ll R0) : L0(L0), R0(R0) { reset(); }\n  void reserve(int n) { node.reserve(n\
    \ + 1); }\n  void reset() {\n    node.clear(), FREE.clear();\n    node.eb(Node{{NIL,\
    \ NIL}, 0, MX::unit(), MX::unit()});  // NIL\n  }\n\n  // \u6728 dp \u306E\u30DE\
    \u30FC\u30B8\u306E\u3068\u304D\u306A\u3069\u306B\u4F7F\u7528\u3059\u308B\u3068\
    \ MLE \u56DE\u907F\u3067\u304D\u308B\u3053\u3068\u304C\u3042\u308B\n  // https://codeforces.com/problemset/problem/671/D\n\
    \  void free_subtree(int c) {\n    assert(c != NIL);\n    auto dfs = [&](auto\
    \ &dfs, int c) -> void {\n      if (c == NIL) return;\n      dfs(dfs, node[c].ch[0]),\
    \ dfs(dfs, node[c].ch[1]);\n      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\
    \n  inline int new_root() { return NIL; }\n\n  inline int new_node(ll idx, const\
    \ X x) {\n    if (!FREE.empty()) {\n      int id = POP(FREE);\n      node[id].ch[0]\
    \ = node[id].ch[1] = NIL;\n      node[id].idx = idx, node[id].x = x, node[id].prod\
    \ = x;\n      return id;\n    }\n    node.eb(Node{{NIL, NIL}, idx, x, x});\n \
    \   return int(node.size()) - 1;\n  }\n  inline Node operator[](int i) const {\
    \ return node[i]; }\n\n  X prod(int root, ll l, ll r) {\n    assert(L0 <= l &&\
    \ l <= r && r <= R0);\n    if (root == NIL || l == r) return MX::unit();\n   \
    \ X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x);\n    return x;\n  }\n\
    \n  X prod_all(int root) { return (root == NIL ? MX::unit() : node[root].prod);\
    \ }\n\n  int set(int root, ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n\
    \    return set_rec(root, L0, R0, i, x);\n  }\n\n  int multiply(int root, ll i,\
    \ const X &x) {\n    assert(L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  template <typename F>\n  ll max_right(int root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename\
    \ F>\n  ll min_left(int root, F check, ll R) {\n    assert(L0 <= R && R <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  vc<pair<ll, X>> get_all(int root) {\n    vc<pair<ll,\
    \ X>> res;\n    auto dfs = [&](auto &dfs, int c) -> void {\n      if (c == NIL)\
    \ return;\n      dfs(dfs, node[c].ch[0]);\n      res.eb(node[c].idx, node[c].x);\n\
    \      dfs(dfs, node[c].ch[1]);\n    };\n    dfs(dfs, root);\n    return res;\n\
    \  }\n\n  X get(int root, ll idx) {\n    auto dfs = [&](auto &dfs, int c) -> X\
    \ {\n      if (c == NIL) return MX::unit();\n      if (idx == node[c].idx) return\
    \ node[c].x;\n      return dfs(dfs, node[c].ch[idx > node[c].idx]);\n    };\n\
    \    return dfs(dfs, root);\n  }\n\n private:\n  inline void update(int c) {\n\
    \    node[c].prod = node[c].x;\n    node[c].prod = MX::op(node[node[c].ch[0]].prod,\
    \ node[c].prod);\n    node[c].prod = MX::op(node[c].prod, node[node[c].ch[1]].prod);\n\
    \  }\n\n  inline int copy_node(int c) {\n    if constexpr (!PERSISTENT)\n    \
    \  return c;\n    else {\n      if (c == NIL) return c;\n      node.eb(node[c]);\n\
    \      return int(node.size()) - 1;\n    }\n  }\n\n  int set_rec(int c, ll l,\
    \ ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c = copy_node(c);\n\
    \    if (node[c].idx == i) {\n      node[c].x = x;\n      update(c);\n      return\
    \ c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (node[c].idx\
    \ < i) swap(node[c].idx, i), swap(node[c].x, x);\n      node[c].ch[0] = set_rec(node[c].ch[0],\
    \ l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx,\
    \ i), swap(node[c].x, x);\n      node[c].ch[1] = set_rec(node[c].ch[1], m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  int multiply_rec(int\
    \ c, ll l, ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c\
    \ = copy_node(c);\n    if (node[c].idx == i) {\n      node[c].x = MX::op(node[c].x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[0] = multiply_rec(node[c].ch[0], l, m, i, x);\n    }\n\
    \    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[1] = multiply_rec(node[c].ch[1], m, r, i, x);\n    }\n\
    \    update(c);\n    return c;\n  }\n\n  void prod_rec(int c, ll l, ll r, ll ql,\
    \ ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr || c\
    \ == NIL) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, node[c].prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(node[c].ch[0], l,\
    \ m, ql, qr, x);\n    if (ql <= (node[c].idx) && (node[c].idx) < qr) x = MX::op(x,\
    \ node[c].x);\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\n  }\n\n  template\
    \ <typename F>\n  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X\
    \ &x) {\n    if (c == NIL || r <= ql) return R0;\n    if (check(MX::op(x, node[c].prod)))\
    \ {\n      x = MX::op(x, node[c].prod);\n      return R0;\n    }\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);\n  \
    \  if (k != R0) return k;\n    if (ql <= node[c].idx) {\n      x = MX::op(x, node[c].x);\n\
    \      if (!check(x)) return node[c].idx;\n    }\n    return max_right_rec(node[c].ch[1],\
    \ check, m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(int\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\n    if (c == NIL || qr <= l)\
    \ return L0;\n    if (check(MX::op(node[c].prod, x))) {\n      x = MX::op(node[c].prod,\
    \ x);\n      return L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(node[c].ch[1],\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (node[c].idx < qr)\
    \ {\n      x = MX::op(node[c].x, x);\n      if (!check(x)) return node[c].idx\
    \ + 1;\n    }\n    return min_left_rec(node[c].ch[0], check, l, m, qr, x);\n \
    \ }\n};\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 3 \"ds/segtree/range_add_range_max.hpp\"\n\n// INF+x==INF \u307F\
    \u305F\u3044\u306A\u51E6\u7406\u306F\u5165\u308C\u3066\u3044\u306A\u3044\n// N=Q=10^6\
    \ \u3067 lazysegtree \u3088\u308A 40% \u7A0B\u5EA6\u9AD8\u901F\ntemplate <typename\
    \ T>\nstruct Range_Add_Range_Max {\n  struct Mono {\n    using value_type = pair<T,\
    \ T>;\n    using X = value_type;\n    static X op(X L, X R) { return {L.fi + R.fi,\
    \ max(L.se, L.fi + R.se)}; }\n    static constexpr X unit() { return {0, -2 *\
    \ infty<T>}; }\n    static constexpr bool commute = false;\n  };\n  int n;\n \
    \ T lazy;\n  SegTree<Mono> seg;\n\n  Range_Add_Range_Max() {}\n  // (n) \u3060\
    \u3051\u3060\u3068 0 \u57CB\u3081\u3067\u521D\u671F\u5316\u3057\u307E\u3059\n\
    \  Range_Add_Range_Max(int n) { build(n); }\n  template <typename F>\n  Range_Add_Range_Max(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Range_Add_Range_Max(const vc<T> &v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> T { return 0; });\n  }\n\
    \  void build(const vc<T> &v) {\n    build(len(v), [&](int i) -> T { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    lazy = 0;\n\
    \    n = m;\n    T pre = 0;\n    seg.build(n, [&](int i) -> pair<T, T> {\n   \
    \   T t = f(i) - pre;\n      pre += t;\n      return {t, t};\n    });\n  }\n\n\
    \  T prod(int L, int R) {\n    if (L == R) return -infty<T>;\n    ll ans = seg.prod(L,\
    \ R).se;\n    L += seg.size;\n    for (; L > 0; L /= 2) {\n      if (L & 1) ans\
    \ += seg.dat[--L].fi;\n    }\n    return ans + lazy;\n  }\n\n  T prod_all() {\
    \ return prod(0, n); }\n\n  // \u57FA\u672C\u30C7\u30D0\u30C3\u30B0\u7528\u3068\
    \u3044\u3046\u3064\u3082\u308A\u3067\u3055\u307C\u308A O(NlogN) \u306B\u306A\u3063\
    \u3066\u3044\u308B\n  vc<T> get_all() {\n    vc<T> ANS(n);\n    FOR(i, n) ANS[i]\
    \ = prod(i, i + 1);\n    return ANS;\n  }\n\n  void apply(int L, int R, T x) {\
    \ apply_suffix(L, x), apply_suffix(R, -x); }\n\n  // [0,i)\n  void apply_prefix(int\
    \ i, T x) {\n    lazy += x;\n    apply_suffix(i, -x);\n  }\n\n  // [i,n)\n  void\
    \ apply_suffix(int i, T x) {\n    if (i == n) return;\n    T t = seg.get(i).fi\
    \ + x;\n    seg.set(i, {t, t});\n  }\n  void apply_all(T x) { lazy += x; }\n\n\
    \  void set(int i, T x) {\n    T now = prod(i, i + 1);\n    apply(i, i + 1, x\
    \ - now);\n  }\n\n  void multiply(int i, T x) {\n    T now = prod(i, i + 1);\n\
    \    if (now < x) apply(i, i + 1, x - now);\n  }\n};\n\n// \u5EA7\u6A19\u306F\
    \ long long. \u307B\u307C verify \u3055\u308C\u3066\u3044\u306A\u3044\n// https://codeforces.com/contest/542/problem/B\n\
    template <typename T>\nstruct Dynamic_Range_Add_Range_Max {\n  struct Mono {\n\
    \    using value_type = pair<T, T>;\n    using X = value_type;\n    static X op(X\
    \ L, X R) { return {L.fi + R.fi, max(L.se, L.fi + R.se)}; }\n    static constexpr\
    \ X unit() { return {0, 0}; }\n    static constexpr bool commute = false;\n  };\n\
    \  int n;\n  Dynamic_SegTree_Sparse<Mono, false> seg;\n  T lazy;\n  using np =\
    \ typename decltype(seg)::np;\n  np root;\n\n  // range apply * 2 \u304F\u3089\
    \u3044\u306E\u30CE\u30FC\u30C9\u6570\n  Dynamic_Range_Add_Range_Max(int NODES,\
    \ ll L, ll R)\n      : seg(NODES, L, R), lazy(0) {\n    root = seg.new_root();\n\
    \  }\n\n  T prod(ll L, ll R) {\n    if (L == R) return -infty<T>;\n    ll ans\
    \ = seg.prod(root, L, R).se;\n    ans += seg.prod(root, seg.L0, L).fi;\n    return\
    \ ans + lazy;\n  }\n\n  void apply(ll L, ll R, T x) { apply_suffix(L, x), apply_suffix(R,\
    \ -x); }\n\n  // [i,n)\n  void apply_suffix(ll i, T x) {\n    if (i == seg.R0)\
    \ return;\n    T t = seg.get(root, i).fi + x;\n    root = seg.set(root, i, {t,\
    \ t});\n  }\n  void apply_all(T x) { lazy += x; }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 8 \"test/1_mytest/range_add_range_max.test.cpp\"\
    \n\nvi sol_0(int N, int Q, vi A, vc<tuple<int, int, int, int>> query) {\n  Lazy_SegTree<ActedMonoid_Max_Add<ll>>\
    \ seg(A);\n  vi ANS;\n  for (auto [t, l, r, x] : query) {\n    if (t == 0) {\n\
    \      ANS.eb(seg.prod(l, r));\n    }\n    if (t == 1) {\n      seg.apply(l, r,\
    \ x);\n    }\n  }\n  return ANS;\n}\n\nvi sol_1(int N, int Q, vi A, vc<tuple<int,\
    \ int, int, int>> query) {\n  Range_Add_Range_Max<ll> seg(A);\n  vi ANS;\n  for\
    \ (auto [t, l, r, x] : query) {\n    if (t == 0) {\n      ANS.eb(seg.prod(l, r));\n\
    \    }\n    if (t == 1) {\n      seg.apply(l, r, x);\n    }\n  }\n  return ANS;\n\
    }\n\nvoid test_1() {\n  int N = 1'000'000;\n  int Q = 1'000'000;\n  int K = 1'000'000'000;\n\
    \  vi A(N);\n  vc<tuple<int, int, int, int>> query(Q);\n  FOR(i, N) A[i] = RNG(-K,\
    \ K + 1);\n  FOR(q, Q) {\n    int t = RNG(0, 2);\n    int l = RNG(0, N);\n   \
    \ int r = RNG(0, N);\n    if (l > r)\n      swap(l, r);\n    ++r;\n    int x =\
    \ RNG(-K, K + 1);\n    query[q] = {t, l, r, x};\n  }\n  auto T0 = std::chrono::high_resolution_clock::now();\n\
    \  auto ANS_0 = sol_0(N, Q, A, query);\n  auto T1 = std::chrono::high_resolution_clock::now();\n\
    \  auto ANS_1 = sol_1(N, Q, A, query);\n  auto T2 = std::chrono::high_resolution_clock::now();\n\
    \  double t0 = chrono::duration<double>(T1 - T0).count();\n  double t1 = chrono::duration<double>(T2\
    \ - T1).count();\n  assert(ANS_0 == ANS_1);\n  // cout << t0 << \" \" << t1 <<\
    \ endl;\n  // 10 \u56DE\u5E73\u5747\u3067 450ms, 270ms \u7A0B\u5EA6.\n}\n\nvoid\
    \ test_2() {\n  FOR(N, 1, 10) {\n    FOR(Q, 1, 10) {\n      int K = 1'000'000'000;\n\
    \      vi A(N);\n      vc<tuple<int, int, int, int>> query(Q);\n      FOR(i, N)\
    \ A[i] = RNG(-K, K + 1);\n      FOR(q, Q) {\n        int t = RNG(0, 2);\n    \
    \    int l = RNG(0, N);\n        int r = RNG(0, N);\n        if (l > r)\n    \
    \      swap(l, r);\n        ++r;\n        int x = RNG(-K, K + 1);\n        query[q]\
    \ = {t, l, r, x};\n      }\n      auto ANS_0 = sol_0(N, Q, A, query);\n      auto\
    \ ANS_1 = sol_1(N, Q, A, query);\n      assert(ANS_0 == ANS_1);\n    }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_1();\n  test_2();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"alg/acted_monoid/max_add.hpp\"\n#include \"ds/segtree/lazy_segtree.hpp\"\
    \n#include \"ds/segtree/range_add_range_max.hpp\"\n#include \"random/base.hpp\"\
    \n\nvi sol_0(int N, int Q, vi A, vc<tuple<int, int, int, int>> query) {\n  Lazy_SegTree<ActedMonoid_Max_Add<ll>>\
    \ seg(A);\n  vi ANS;\n  for (auto [t, l, r, x] : query) {\n    if (t == 0) {\n\
    \      ANS.eb(seg.prod(l, r));\n    }\n    if (t == 1) {\n      seg.apply(l, r,\
    \ x);\n    }\n  }\n  return ANS;\n}\n\nvi sol_1(int N, int Q, vi A, vc<tuple<int,\
    \ int, int, int>> query) {\n  Range_Add_Range_Max<ll> seg(A);\n  vi ANS;\n  for\
    \ (auto [t, l, r, x] : query) {\n    if (t == 0) {\n      ANS.eb(seg.prod(l, r));\n\
    \    }\n    if (t == 1) {\n      seg.apply(l, r, x);\n    }\n  }\n  return ANS;\n\
    }\n\nvoid test_1() {\n  int N = 1'000'000;\n  int Q = 1'000'000;\n  int K = 1'000'000'000;\n\
    \  vi A(N);\n  vc<tuple<int, int, int, int>> query(Q);\n  FOR(i, N) A[i] = RNG(-K,\
    \ K + 1);\n  FOR(q, Q) {\n    int t = RNG(0, 2);\n    int l = RNG(0, N);\n   \
    \ int r = RNG(0, N);\n    if (l > r)\n      swap(l, r);\n    ++r;\n    int x =\
    \ RNG(-K, K + 1);\n    query[q] = {t, l, r, x};\n  }\n  auto T0 = std::chrono::high_resolution_clock::now();\n\
    \  auto ANS_0 = sol_0(N, Q, A, query);\n  auto T1 = std::chrono::high_resolution_clock::now();\n\
    \  auto ANS_1 = sol_1(N, Q, A, query);\n  auto T2 = std::chrono::high_resolution_clock::now();\n\
    \  double t0 = chrono::duration<double>(T1 - T0).count();\n  double t1 = chrono::duration<double>(T2\
    \ - T1).count();\n  assert(ANS_0 == ANS_1);\n  // cout << t0 << \" \" << t1 <<\
    \ endl;\n  // 10 \u56DE\u5E73\u5747\u3067 450ms, 270ms \u7A0B\u5EA6.\n}\n\nvoid\
    \ test_2() {\n  FOR(N, 1, 10) {\n    FOR(Q, 1, 10) {\n      int K = 1'000'000'000;\n\
    \      vi A(N);\n      vc<tuple<int, int, int, int>> query(Q);\n      FOR(i, N)\
    \ A[i] = RNG(-K, K + 1);\n      FOR(q, Q) {\n        int t = RNG(0, 2);\n    \
    \    int l = RNG(0, N);\n        int r = RNG(0, N);\n        if (l > r)\n    \
    \      swap(l, r);\n        ++r;\n        int x = RNG(-K, K + 1);\n        query[q]\
    \ = {t, l, r, x};\n      }\n      auto ANS_0 = sol_0(N, Q, A, query);\n      auto\
    \ ANS_1 = sol_1(N, Q, A, query);\n      assert(ANS_0 == ANS_1);\n    }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_1();\n  test_2();\n  solve();\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/acted_monoid/max_add.hpp
  - alg/monoid/add.hpp
  - alg/monoid/max.hpp
  - ds/segtree/lazy_segtree.hpp
  - ds/segtree/range_add_range_max.hpp
  - ds/segtree/dynamic_segtree_sparse.hpp
  - ds/segtree/segtree.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/range_add_range_max.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 04:40:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/range_add_range_max.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/range_add_range_max.test.cpp
- /verify/test/1_mytest/range_add_range_max.test.cpp.html
title: test/1_mytest/range_add_range_max.test.cpp
---
