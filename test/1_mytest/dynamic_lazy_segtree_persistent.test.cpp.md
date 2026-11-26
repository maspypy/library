---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/dynamic_lazy_segtree.hpp
    title: ds/segtree/dynamic_lazy_segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n#if\
    \ defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#endif\n\n#else  // MASPY_TEMPLATE_BODY\n\
    #include <bits/stdc++.h>\n#include <cassert>\n\n#if defined(__GNUC__)\n#pragma\
    \ GCC optimize(\"Ofast,unroll-loops\")\n#endif\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false =\
    \ false;\n\ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 4'040'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 4'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
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
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR1_R(a)\
    \ for (ll i = ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a)\
    \ - 1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload3(__VA_ARGS__,\
    \ FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R,\
    \ FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define all(x) (x).begin(), (x).end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define stoi stoll\n\n// require y > 0\ntemplate <typename T>\nT floor(T x, T\
    \ y) {\n  return x / y - (x % y < 0);\n}\n\n// require y > 0\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return (x / y) + (x % y > 0);\n}\n\n// require y >\
    \ 0\ntemplate <typename T>\nT bmod(T x, T y) {\n  T r = x % y;\n  return (r <\
    \ 0 ? r + y : r);\n}\n\n// require y > 0\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = x / y, r = x % y;\n  if (r < 0) --q, r += y;\n  return {q,\
    \ r};\n}\n\nconstexpr auto TEN = [] {\n  array<u64, 20> A{};\n  A[0] = 1;\n  for\
    \ (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];\n  return A;\n}();\n\ntemplate\
    \ <typename T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(),\
    \ A.end(), T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    template <class C, class T>\ninline long long LB(const C &c, const T &x) {\n \
    \ return lower_bound(c.begin(), c.end(), x) - c.begin();\n}\ntemplate <class C,\
    \ class T>\ninline long long UB(const C &c, const T &x) {\n  return upper_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n\
    \  que.pop_front();\n  return a;\n}\ntemplate <class T, class Container, class\
    \ Compare>\nT POP(priority_queue<T, Container, Compare> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    i128 binary_search(F check, i128 ok, i128 ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (1) {\n    i128 x = (ok + ng) / 2;\n    if (x ==\
    \ ok || x == ng) break;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\
    \ntemplate <typename F>\ndouble binary_search_real(F check, double ok, double\
    \ ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class\
    \ S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a, b);\n  bool changed\
    \ = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n  bool changed = (c !=\
    \ a);\n  a = c;\n  return changed;\n}\n\n// bit operations\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ T>\nstruct all_bit {\n  static_assert(is_integral<T>::value);\n  T s;\n  all_bit(T\
    \ s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ T>\nstruct all_subset {\n  static_assert(is_integral<T>::value);\n  T s;\n \
    \ all_subset(T s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s, t;\n \
    \   bool done = false;\n    T operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n      [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  first.reserve(first.size()\
    \ + (others.size() + ... + 0));\n  (first.insert(first.end(), others.begin(),\
    \ others.end()), ...);\n}\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T,\
    \ i128>, int> = 0>\nconstexpr i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\n\
    constexpr i128 gcd(i128 a, i128 b) {\n  while (b != 0) {\n    i128 c = a % b;\n\
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#endif  // MASPY_TEMPLATE_BODY\n\
    #line 1 \"alg/acted_monoid/summax_assign.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/summax_assign.hpp\n\
    #line 1 \"alg/monoid/summax.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/summax.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi + y.fi,\
    \ max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n  static\
    \ constexpr X id() { return {E(0), -infty<E>}; }\n  static constexpr bool commute\
    \ = 1;\n};\n#line 1 \"alg/monoid/assign.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/assign.hpp\n\
    \ntemplate <typename X>\nstruct Monoid_Assign {\n  static_assert(is_same_v<X,\
    \ int> || is_same_v<X, ll>);\n  static constexpr X none_val = numeric_limits<X>::max();\n\
    \  using value_type = X;\n  static X op(X x, X y) { return (y == none_val ? x\
    \ : y); }\n  static constexpr X id() { return none_val; }\n  static constexpr\
    \ bool commute = false;\n};\n#line 4 \"alg/acted_monoid/summax_assign.hpp\"\n\n\
    template <typename E>\nstruct ActedMonoid_SumMax_Assign {\n  static_assert(is_same_v<E,\
    \ int> || is_same_v<E, ll>);\n  using Monoid_X = Monoid_SumMax<E>;\n  using Monoid_A\
    \ = Monoid_Assign<E>;\n  using X = typename Monoid_X::value_type;\n  using A =\
    \ typename Monoid_A::value_type;\n  static constexpr X act(const X& x, const A&\
    \ a, const ll& size) {\n    if (a == Monoid_A::id()) return x;\n    return {E(size)\
    \ * a, a};\n  }\n};\n#line 1 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree.hpp\n\
    #line 1 \"ds/node_pool.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/node_pool.hpp\n\
    // \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\
    \u6E08\u307F chunk \u3092\u518D\u5229\u7528\u3059\u308B\ntemplate <class Node>\n\
    struct Node_Pool {\n  union Slot {\n    Node node;\n    Slot* next;\n\n    Slot()\
    \ {}\n    ~Slot() {}\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE\
    \ = 1 << 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  int chunk_id = 0;\n  int pos\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  ~Node_Pool() {\n    auto& cache = chunk_cache();\n\
    \    for (auto& p : chunks) cache.eb(std::move(p));\n  }\n\n  template <class...\
    \ Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n    return\
    \ ::new (&s->node) Node(forward<Args>(args)...);\n  }\n\n  np clone(const np x)\
    \ {\n    assert(x);\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(*x);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    Slot*\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  // \u5168 node \u3092\u7121\u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\
    \u4FDD\u6E08\u307F chunk \u306F\u89E3\u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\
    \u964D\u306B\u518D\u5229\u7528\u3059\u308B\u3002\n  void reset() {\n    free_head\
    \ = nullptr;\n    chunk_id = 0;\n    pos = 0;\n  }\n\n  int used() const { return\
    \ chunk_id * CHUNK_SIZE + pos; }\n\n private:\n  static vc<unique_ptr<Slot[]>>&\
    \ chunk_cache() {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\
    \u306B\u7834\u68C4\u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\
    \n    static auto* cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n\
    \  }\n\n  void alloc_chunk() {\n    auto& cache = chunk_cache();\n    if (cache.empty())\
    \ {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n    } else {\n      chunks.eb(std::move(cache.back()));\n\
    \      cache.pop_back();\n    }\n  }\n\n  Slot* new_slot() {\n    if (free_head)\
    \ {\n      Slot* s = free_head;\n      free_head = free_head->next;\n      return\
    \ s;\n    }\n\n    if (chunk_id == len(chunks)) alloc_chunk();\n\n    Slot* s\
    \ = &chunks[chunk_id][pos++];\n    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n\
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 3 \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n\ntemplate <typename AM>\nstruct Dynamic_Lazy_SegTree_Default_Prod {\n  using\
    \ MX = typename AM::Monoid_X;\n  using X = typename AM::X;\n  X operator()(ll,\
    \ ll) const { return MX::id(); }\n};\n\n// set, multiply: 2H nodes \u7A0B\u5EA6\
    \n// apply: 4H nodes \u7A0B\u5EA6\ntemplate <typename ActedMonoid, bool PERSISTENT,\n\
    \    typename DefaultProd = Dynamic_Lazy_SegTree_Default_Prod<ActedMonoid>>\n\
    struct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename AM::X;\n\
    \  using A = typename AM::A;\n  using F = DefaultProd;\n  F default_prod;\n\n\
    \  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  Node_Pool<Node>\
    \ pool;\n  const ll L0, R0;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(ll\
    \ L0, ll R0, F default_prod = F{})\n      : default_prod(std::move(default_prod)),\
    \ L0(L0), R0(R0) {}\n\n  np new_root() { return new_node(); }\n\n  np new_node(const\
    \ X x) {\n    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->x = x,\
    \ c->lazy = MA::id();\n    return c;\n  }\n\n  np new_node(ll l, ll r) {\n   \
    \ assert(l < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node()\
    \ { return L0 == R0 ? nullptr : new_node(L0, R0); }\n\n  np new_node(const vc<X>\
    \ &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs,\
    \ ll l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r - l\
    \ == 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root =\
    \ dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    if (l == r || !root) return MX::id();\n    assert(L0\
    \ <= l && l < r && r <= R0);\n    X x = MX::id();\n    prod_rec(root, L0, R0,\
    \ l, r, x, MA::id());\n    return x;\n  }\n\n  X prod_all(np root) { return prod(root,\
    \ L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(root && L0 <=\
    \ i && i < R0);\n    root = clone(root);\n    set_rec(root, L0, R0, i, x);\n \
    \   return root;\n  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    root = clone(root);\n    multiply_rec(root, L0,\
    \ R0, i, x);\n    return root;\n  }\n\n  np apply(np root, ll l, ll r, const A\
    \ &a) {\n    if (l == r) return root;\n    assert(root && L0 <= l && l < r &&\
    \ r <= R0);\n    root = clone(root);\n    apply_rec(root, L0, R0, l, r, a);\n\
    \    return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::id()));\n    if (L == R0)\
    \ return R0;\n    assert(root);\n    X x = MX::id();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x, MA::id());\n  }\n\n  template <typename F>\n  ll min_left(np\
    \ root, F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::id()));\n\
    \    if (R == L0) return L0;\n    assert(root);\n    X x = MX::id();\n    return\
    \ min_left_rec(root, check, L0, R0, R, x, MA::id());\n  }\n\n  // \u751F\u6210\
    \u6E08\u307F\u306E\u8449\u306B\u3064\u3044\u3066 f(idx, val, end) \u3092\u547C\
    \u3076\n  template <typename F>\n  void enumerate(np root, F f) {\n    bool end\
    \ = false;\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {\n \
    \     if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x, a,\
    \ 1), end);\n        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      if (end) return;\n      dfs(dfs,\
    \ c->r, m, r, a);\n      if (end) return;\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::id());\n  }\n\n  void reset() { pool.reset(); }\n\n  // root[l:r) \u3092\
    \ apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, A a) {\n    static_assert(PERSISTENT);\n\
    \    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r) return root;\n   \
    \ assert(root);\n    if (root == other) return apply(root, l, r, a);\n    root\
    \ = clone(root);\n    copy_interval_rec(root, other, L0, R0, l, r, a);\n    return\
    \ root;\n  }\n\n private:\n  np clone(np c) {\n    if (!c || !PERSISTENT) return\
    \ c;\n    return pool.clone(c);\n  }\n\n  np own(np c, ll l, ll r) { return c\
    \ ? clone(c) : new_node(l, r); }\n\n  X value(np c, ll l, ll r) { return c ? c->x\
    \ : default_prod(l, r); }\n\n  void tag(np c, const A &a, ll len) {\n    c->x\
    \ = AM::act(c->x, a, len);\n    c->lazy = MA::op(c->lazy, a);\n  }\n\n  // c \u306F\
    \u66F8\u304D\u63DB\u3048\u53EF\u80FD\u3002\u5DE6\u53F3\u306E\u5B50\u3082\u66F8\
    \u304D\u63DB\u3048\u53EF\u80FD\u306B\u306A\u3063\u305F\u304B\u3092\u8FD4\u3059\
    \n  bool push(np c, ll l, ll m, ll r) {\n    assert(r - l >= 2);\n    if (c->lazy\
    \ == MA::id()) return false;\n    c->l = own(c->l, l, m);\n    c->r = own(c->r,\
    \ m, r);\n    tag(c->l, c->lazy, m - l);\n    tag(c->r, c->lazy, r - m);\n   \
    \ c->lazy = MA::id();\n    return true;\n  }\n\n  void pull(np c, ll l, ll m,\
    \ ll r) {\n    c->x = MX::op(value(c->l, l, m), value(c->r, m, r));\n  }\n\n \
    \ void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, A a) {\n    //\
    \ c[ql,qr) <- apply(d[ql,qr),a)\n    // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n    if (ql <= l && r <= qr) {\n      if (d) {\n\
    \        c->x = d->x;\n        c->lazy = d->lazy;\n        c->l = d->l, c->r =\
    \ d->r;\n      } else {\n        c->x = default_prod(l, r);\n        c->lazy =\
    \ MA::id();\n        c->l = c->r = nullptr;\n      }\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (d) a = MA::op(d->lazy, a);\n    if (ql < m) {\n      if (!pushed)\
    \ c->l = own(c->l, l, m);\n      copy_interval_rec(c->l, d ? d->l : nullptr, l,\
    \ m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      copy_interval_rec(c->r, d ? d->r : nullptr, m, r, ql, qr, a);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n  void set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r - l == 1) {\n      c->x = x;\n      c->lazy = MA::id();\n \
    \     return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (i < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      set_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      if (!pushed) c->r = own(c->r, m, r);\n   \
    \   set_rec(c->r, m, r, i, x);\n    }\n    pull(c, l, m, r);\n  }\n\n  void multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    if (r - l == 1) {\n      c->x = MX::op(c->x,\
    \ x);\n      c->lazy = MA::id();\n      return;\n    }\n    ll m = (l + r) / 2;\n\
    \    bool pushed = push(c, l, m, r);\n    if (i < m) {\n      if (!pushed) c->l\
    \ = own(c->l, l, m);\n      multiply_rec(c->l, l, m, i, x);\n    } else {\n  \
    \    if (!pushed) c->r = own(c->r, m, r);\n      multiply_rec(c->r, m, r, i, x);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  void apply_rec(np c, ll l, ll r, ll ql,\
    \ ll qr, const A &a) {\n    if (ql <= l && r <= qr) {\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (ql < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      apply_rec(c->r, m, r, ql, qr, a);\n    }\n    pull(c, l, m, r);\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A a) {\n    if (!c)\
    \ {\n      ll L = max(l, ql), R = min(r, qr);\n      x = MX::op(x, AM::act(default_prod(L,\
    \ R), a, R - L));\n      return;\n    }\n    if (ql <= l && r <= qr) {\n     \
    \ x = MX::op(x, AM::act(c->x, a, r - l));\n      return;\n    }\n    ll m = (l\
    \ + r) / 2;\n    a = MA::op(c->lazy, a);\n    if (ql < m) prod_rec(c->l, l, m,\
    \ ql, qr, x, a);\n    if (m < qr) prod_rec(c->r, m, r, ql, qr, x, a);\n  }\n\n\
    \  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x, A a) {\n    if (r <= ql) return r;\n    if (ql <= l) {\n      X\
    \ y = MX::op(x, AM::act(value(c, l, r), a, r - l));\n      if (check(y)) {\n \
    \       x = y;\n        return r;\n      }\n    }\n    if (r - l == 1) return\
    \ l;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy, a);\n    if (ql\
    \ < m) {\n      ll k = max_right_rec(c ? c->l : nullptr, check, l, m, ql, x, a);\n\
    \      if (k < m) return k;\n    }\n    return max_right_rec(c ? c->r : nullptr,\
    \ check, m, r, ql, x, a);\n  }\n\n  template <typename F>\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x, A a) {\n    if (qr <= l) return\
    \ l;\n    if (r <= qr) {\n      X y = MX::op(AM::act(value(c, l, r), a, r - l),\
    \ x);\n      if (check(y)) {\n        x = y;\n        return l;\n      }\n   \
    \ }\n    if (r - l == 1) return r;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy,\
    \ a);\n    if (m < qr) {\n      ll k = min_left_rec(c ? c->r : nullptr, check,\
    \ m, r, qr, x, a);\n      if (m < k) return k;\n    }\n    return min_left_rec(c\
    \ ? c->l : nullptr, check, l, m, qr, x, a);\n  }\n};\n#line 1 \"random/base.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/random/base.hpp\n\n\
    u64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 6 \"test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp\"\
    \n\nvoid test() {\n  using AM = ActedMonoid_SumMax_Assign<int>;\n  using P = typename\
    \ AM::X;\n\n  FOR(100) {\n    int N = RNG(1, 1000);\n\n    vvc<int> AA;\n    AA.eb(vc<int>(N,\
    \ 10));\n    auto fun = [&](ll l, ll r) -> P { return {10 * (r - l), 10}; };\n\
    \    Dynamic_Lazy_SegTree<AM, true, decltype(fun)> X(0, N, fun);\n    using np\
    \ = typename decltype(X)::np;\n\n    int Q = RNG(1, 1000);\n    vc<np> roots;\n\
    \    roots.eb(X.new_node(0, N));\n\n    FOR(Q) {\n      int time = RNG(0, len(roots));\n\
    \      vc<int> A = AA[time];\n      np root = roots[time];\n      int L = RNG(0,\
    \ N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n\n\
    \      int t = RNG(0, 4);\n      if (t == 0) {\n        int i = RNG(0, N);\n \
    \       int x = RNG(1, 100);\n        root = X.set(root, i, {x, x});\n       \
    \ A[i] = x;\n      }\n      if (t == 1) {\n        vc<int> B = {A.begin() + L,\
    \ A.begin() + R};\n        assert(X.prod(root, L, R).fi == SUM<int>(B));\n   \
    \     assert(X.prod(root, L, R).se == MAX(B));\n      }\n      if (t == 2) {\n\
    \        int x = RNG(1, 100);\n        FOR(i, L, R) A[i] = x;\n        root =\
    \ X.apply(root, L, R, x);\n      }\n      if (t == 3) {\n        // max_right\n\
    \        int LIM = R;\n        auto check = [&](auto e) -> bool { return e.se\
    \ <= LIM; };\n        int naive = [&]() -> int {\n          ll mx = 0;\n     \
    \     FOR(i, L, N) {\n            chmax(mx, A[i]);\n            if (mx > LIM)\
    \ return i;\n          }\n          return N;\n        }();\n\n        assert(naive\
    \ == X.max_right(root, check, L));\n      }\n\n      AA.eb(A);\n      roots.eb(root);\n\
    \    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a +\
    \ b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/acted_monoid/summax_assign.hpp\"\n#include \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  using AM = ActedMonoid_SumMax_Assign<int>;\n\
    \  using P = typename AM::X;\n\n  FOR(100) {\n    int N = RNG(1, 1000);\n\n  \
    \  vvc<int> AA;\n    AA.eb(vc<int>(N, 10));\n    auto fun = [&](ll l, ll r) ->\
    \ P { return {10 * (r - l), 10}; };\n    Dynamic_Lazy_SegTree<AM, true, decltype(fun)>\
    \ X(0, N, fun);\n    using np = typename decltype(X)::np;\n\n    int Q = RNG(1,\
    \ 1000);\n    vc<np> roots;\n    roots.eb(X.new_node(0, N));\n\n    FOR(Q) {\n\
    \      int time = RNG(0, len(roots));\n      vc<int> A = AA[time];\n      np root\
    \ = roots[time];\n      int L = RNG(0, N);\n      int R = RNG(0, N);\n      if\
    \ (L > R) swap(L, R);\n      ++R;\n\n      int t = RNG(0, 4);\n      if (t ==\
    \ 0) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root\
    \ = X.set(root, i, {x, x});\n        A[i] = x;\n      }\n      if (t == 1) {\n\
    \        vc<int> B = {A.begin() + L, A.begin() + R};\n        assert(X.prod(root,\
    \ L, R).fi == SUM<int>(B));\n        assert(X.prod(root, L, R).se == MAX(B));\n\
    \      }\n      if (t == 2) {\n        int x = RNG(1, 100);\n        FOR(i, L,\
    \ R) A[i] = x;\n        root = X.apply(root, L, R, x);\n      }\n      if (t ==\
    \ 3) {\n        // max_right\n        int LIM = R;\n        auto check = [&](auto\
    \ e) -> bool { return e.se <= LIM; };\n        int naive = [&]() -> int {\n  \
    \        ll mx = 0;\n          FOR(i, L, N) {\n            chmax(mx, A[i]);\n\
    \            if (mx > LIM) return i;\n          }\n          return N;\n     \
    \   }();\n\n        assert(naive == X.max_right(root, check, L));\n      }\n\n\
    \      AA.eb(A);\n      roots.eb(root);\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/acted_monoid/summax_assign.hpp
  - alg/monoid/summax.hpp
  - alg/monoid/assign.hpp
  - ds/segtree/dynamic_lazy_segtree.hpp
  - ds/node_pool.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  requiredBy: []
  timestamp: '2026-11-25 17:20:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
- /verify/test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp.html
title: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
---
