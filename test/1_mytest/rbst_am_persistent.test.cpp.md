---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':question:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/randomized_bst/rbst_acted_monoid.hpp
    title: ds/randomized_bst/rbst_acted_monoid.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/rbst_am_persistent.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
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
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/assign.hpp\"\
    \n\r\ntemplate <typename X, int none_val>\r\nstruct Monoid_Assign {\r\n  using\
    \ value_type = X;\r\n  static X op(X x, X y) { return (y == X(none_val) ? x :\
    \ y); }\r\n  static constexpr X unit() { return X(none_val); }\r\n  static constexpr\
    \ bool commute = false;\r\n};\r\n#line 3 \"alg/acted_monoid/min_assign.hpp\"\n\
    \r\ntemplate <typename E, E none_val>\r\nstruct ActedMonoid_Min_Assign {\r\n \
    \ using Monoid_X = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Assign<E, none_val>;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return\
    \ (a == none_val ? x : a);\r\n  }\r\n};\r\n#line 1 \"ds/randomized_bst/rbst_acted_monoid.hpp\"\
    \ntemplate <typename ActedMonoid, bool PERSISTENT>\nstruct RBST_ActedMonoid {\n\
    \  using Monoid_X = typename ActedMonoid::Monoid_X;\n  using Monoid_A = typename\
    \ ActedMonoid::Monoid_A;\n  using X = typename Monoid_X::value_type;\n  using\
    \ A = typename Monoid_A::value_type;\n\n  struct Node {\n    Node *l, *r;\n  \
    \  X x, prod; // lazy, rev \u53CD\u6620\u6E08\n    A lazy;\n    u32 size;\n  \
    \  bool rev;\n  };\n\n  Node *pool;\n  const int NODES;\n  int pid;\n  using np\
    \ = Node *;\n\n  RBST_ActedMonoid(int NODES) : NODES(NODES), pid(0) { pool = new\
    \ Node[NODES]; }\n  ~RBST_ActedMonoid() { delete[] pool; }\n\n  void reset() {\
    \ pid = 0; }\n\n  np new_node(const X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].x = x;\n    pool[pid].prod = x;\n    pool[pid].lazy = Monoid_A::unit();\n\
    \    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n\
    \  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto &dfs, u32 l,\
    \ u32 r) -> np {\n      if (l == r) return nullptr;\n      if (r == l + 1) return\
    \ new_node(dat[l]);\n      u32 m = (l + r) / 2;\n      np l_root = dfs(dfs, l,\
    \ m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      update(root);\n      return\
    \ root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  np copy_node(np &n)\
    \ {\n    if (!n || !PERSISTENT) return n;\n    pool[pid].l = n->l, pool[pid].r\
    \ = n->r;\n    pool[pid].x = n->x;\n    pool[pid].prod = n->prod;\n    pool[pid].lazy\
    \ = n->lazy;\n    pool[pid].size = n->size;\n    pool[pid].rev = n->rev;\n   \
    \ return &(pool[pid++]);\n  }\n\n  np merge(np l_root, np r_root) { return merge_rec(l_root,\
    \ r_root); }\n  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }\n\
    \  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d);\
    \ }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n      assert(k\
    \ == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <= k && k <= root->size);\n\
    \    return split_rec(root, k);\n  }\n  tuple<np, np, np> split3(np root, u32\
    \ l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n    tie(root,\
    \ nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np, np, np,\
    \ np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root,\
    \ k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\
    \n  X prod(np root, u32 l, u32 r) {\n    if (l == r) return Monoid_X::unit();\n\
    \    return prod_rec(root, l, r, false);\n  }\n  X prod(np root) { return (root\
    \ ? root->prod : Monoid_X::unit()); }\n\n  np reverse(np root, u32 l, u32 r) {\n\
    \    assert(Monoid_X::commute);\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n    return merge3(nl, nm, nr);\n\
    \  }\n\n  np apply(np root, u32 l, u32 r, const A a) {\n    assert(0 <= l && l\
    \ <= r && r <= root->size);\n    return apply_rec(root, l, r, a);\n  }\n  np apply(np\
    \ root, const A a) {\n    if (!root) return root;\n    return apply_rec(root,\
    \ 0, root->size, a);\n  }\n\n  np set(np root, u32 k, const X &x) { return set_rec(root,\
    \ k, x); }\n  np multiply(np root, u32 k, const X &x) { return multiply_rec(root,\
    \ k, x); }\n  X get(np root, u32 k) { return get_rec(root, k, false, Monoid_A::unit());\
    \ }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ np root, bool rev, A lazy) -> void {\n      if (!root) return;\n      X me =\
    \ ActedMonoid::act(root->x, lazy, 1);\n      lazy = Monoid_A::op(root->lazy, lazy);\n\
    \      dfs(dfs, (rev ? root->r : root->l), rev ^ root->rev, lazy);\n      res.eb(me);\n\
    \      dfs(dfs, (rev ? root->l : root->r), rev ^ root->rev, lazy);\n    };\n \
    \   dfs(dfs, root, 0, Monoid_A::unit());\n    return res;\n  }\n\n  template <typename\
    \ F>\n  pair<np, np> split_max_right(np root, const F check) {\n    assert(check(Monoid_X::unit()));\n\
    \    X x = Monoid_X::unit();\n    return split_max_right_rec(root, check, x);\n\
    \  }\n\nprivate:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n   \
    \ static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32 w =\
    \ 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n\
    \    // \u81EA\u8EAB\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\
    \u3044\u3002\n    // \u5B50\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\u8907\u6570\u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u3002\n    bool bl_lazy = (c->lazy != Monoid_A::unit());\n\
    \    bool bl_rev = c->rev;\n    if (bl_lazy || bl_rev) {\n      c->l = copy_node(c->l);\n\
    \      c->r = copy_node(c->r);\n    }\n    if (c->lazy != Monoid_A::unit()) {\n\
    \      if (c->l) {\n        c->l->x = ActedMonoid::act(c->l->x, c->lazy, 1);\n\
    \        c->l->prod = ActedMonoid::act(c->l->prod, c->lazy, c->l->size);\n   \
    \     c->l->lazy = Monoid_A::op(c->l->lazy, c->lazy);\n      }\n      if (c->r)\
    \ {\n        c->r->x = ActedMonoid::act(c->r->x, c->lazy, 1);\n        c->r->prod\
    \ = ActedMonoid::act(c->r->prod, c->lazy, c->r->size);\n        c->r->lazy = Monoid_A::op(c->r->lazy,\
    \ c->lazy);\n      }\n      c->lazy = Monoid_A::unit();\n    }\n    if (c->rev)\
    \ {\n      if (c->l) {\n        c->l->rev ^= 1;\n        swap(c->l->l, c->l->r);\n\
    \      }\n      if (c->r) {\n        c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n\
    \      }\n      c->rev = 0;\n    }\n  }\n\n  void update(np c) {\n    // \u30C7\
    \u30FC\u30BF\u3092\u4FDD\u3063\u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\
    \u3060\u3051\u306A\u306E\u3067\u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size\
    \ = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n \
    \     c->prod = Monoid_X::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n \
    \     c->size += c->r->size;\n      c->prod = Monoid_X::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return\
    \ r_root;\n    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n\
    \      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n    \
    \  return l_root;\n    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n\
    \    r_root->l = merge_rec(l_root, r_root->l);\n    update(r_root);\n    return\
    \ r_root;\n  }\n\n  pair<np, np> split_rec(np root, u32 k) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k <= sl) {\n      auto [nl, nr] = split_rec(root->l, k);\n  \
    \    root = copy_node(root);\n      root->l = nr;\n      update(root);\n     \
    \ return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root = copy_node(root);\n    root->r = nl;\n    update(root);\n    return\
    \ {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const X &x) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
    \ k, x);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->x = x;\n      update(root);\n    \
    \  return root;\n    }\n    root = copy_node(root);\n    root->r = set_rec(root->r,\
    \ k - (1 + sl), x);\n    update(root);\n    return root;\n  }\n\n  np multiply_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root = copy_node(root);\n\
    \      root->l = multiply_rec(root->l, k, x);\n      update(root);\n      return\
    \ root;\n    }\n    if (k == sl) {\n      root = copy_node(root);\n      root->x\
    \ = Monoid_X::op(root->x, x);\n      update(root);\n      return root;\n    }\n\
    \    root = copy_node(root);\n    root->r = multiply_rec(root->r, k - (1 + sl),\
    \ x);\n    update(root);\n    return root;\n  }\n\n  X prod_rec(np root, u32 l,\
    \ u32 r, bool rev) {\n    if (l == 0 && r == root->size) { return root->prod;\
    \ }\n    np left = (rev ? root->r : root->l);\n    np right = (rev ? root->l :\
    \ root->r);\n    u32 sl = (left ? left->size : 0);\n    X res = Monoid_X::unit();\n\
    \    if (l < sl) {\n      X y = prod_rec(left, l, min(r, sl), rev ^ root->rev);\n\
    \      res = Monoid_X::op(res, ActedMonoid::act(y, root->lazy, min(r, sl) - l));\n\
    \    }\n    if (l <= sl && sl < r) res = Monoid_X::op(res, root->x);\n    u32\
    \ k = 1 + sl;\n    if (k < r) {\n      X y = prod_rec(right, max(k, l) - k, r\
    \ - k, rev ^ root->rev);\n      res = Monoid_X::op(res, ActedMonoid::act(y, root->lazy,\
    \ r - max(k, l)));\n    }\n    return res;\n  }\n\n  X get_rec(np root, u32 k,\
    \ bool rev, A lazy) {\n    np left = (rev ? root->r : root->l);\n    np right\
    \ = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size : 0);\n    if\
    \ (k == sl) return ActedMonoid::act(root->x, lazy, 1);\n    lazy = Monoid_A::op(root->lazy,\
    \ lazy);\n    rev ^= root->rev;\n    if (k < sl) return get_rec(left, k, rev,\
    \ lazy);\n    return get_rec(right, k - (1 + sl), rev, lazy);\n  }\n\n  np apply_rec(np\
    \ root, u32 l, u32 r, const A &a) {\n    prop(root);\n    root = copy_node(root);\n\
    \    if (l == 0 && r == root->size) {\n      root->x = ActedMonoid::act(root->x,\
    \ a, 1);\n      root->prod = ActedMonoid::act(root->prod, a, root->size);\n  \
    \    root->lazy = a;\n      return root;\n    }\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (l < sl) root->l = apply_rec(root->l, l, min(r, sl), a);\n   \
    \ if (l <= sl && sl < r) root->x = ActedMonoid::act(root->x, a, 1);\n    u32 k\
    \ = 1 + sl;\n    if (k < r) root->r = apply_rec(root->r, max(k, l) - k, r - k,\
    \ a);\n    update(root);\n    return root;\n  }\n\n  template <typename F>\n \
    \ pair<np, np> split_max_right_rec(np root, F check, X &x) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    root = copy_node(root);\n    X y =\
    \ Monoid_X::op(x, root->prod);\n    if (check(y)) {\n      x = y;\n      return\
    \ {root, nullptr};\n    }\n    np left = root->l, right = root->r;\n    if (left)\
    \ {\n      X y = Monoid_X::op(x, root->l->prod);\n      if (!check(y)) {\n   \
    \     auto [n1, n2] = split_max_right_rec(left, check, x);\n        root->l =\
    \ n2;\n        update(root);\n        return {n1, root};\n      }\n      x = y;\n\
    \    }\n    y = Monoid_X::op(x, root->x);\n    if (!check(y)) {\n      root->l\
    \ = nullptr;\n      update(root);\n      return {left, root};\n    }\n    x =\
    \ y;\n    auto [n1, n2] = split_max_right_rec(right, check, x);\n    root->r =\
    \ n1;\n    update(root);\n    return {root, n2};\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 6 \"test/1_mytest/rbst_am_persistent.test.cpp\"\
    \n\nvoid test() {\n  using AM = ActedMonoid_Min_Assign<int, -1>;\n  using MonoX\
    \ = typename AM::Monoid_X;\n\n  RBST_ActedMonoid<AM, true> X(100000);\n  using\
    \ np = decltype(X)::np;\n\n  FOR(1000) {\n    X.reset();\n    int N = RNG(1, 20);\n\
    \    int Q = RNG(1, 1000);\n    vvc<int> AA(1);\n    vc<np> roots;\n    FOR(i,\
    \ N) AA[0].eb(RNG(1, 100));\n    roots.eb(X.new_node(AA[0]));\n\n    FOR(Q) {\n\
    \      int t = RNG(0, 7);\n      int frm = RNG(0, len(AA));\n      np root = roots[frm];\n\
    \      vc<int> A = AA[frm];\n      if (t == 0) {\n        int i = RNG(0, N);\n\
    \        assert(A[i] == X.get(root, i));\n      }\n      if (t == 1) {\n     \
    \   int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root = X.set(root,\
    \ i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n        int i = RNG(0,\
    \ N);\n        int x = RNG(1, 100);\n        root = X.multiply(root, i, x);\n\
    \        A[i] = MonoX::op(A[i], x);\n      }\n      if (t == 3) {\n        int\
    \ L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n\
    \        ++R;\n        vc<int> B = {A.begin() + L, A.begin() + R};\n        assert(X.prod(root,\
    \ L, R) == MIN(B));\n      }\n      if (t == 4) {\n        int L = RNG(0, N);\n\
    \        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n  \
    \      root = X.reverse(root, L, R);\n        reverse(A.begin() + L, A.begin()\
    \ + R);\n      }\n      if (t == 5) {\n        int L = RNG(0, N);\n        int\
    \ R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n        int x\
    \ = RNG(1, 100);\n        FOR(i, L, R) A[i] = x;\n        root = X.apply(root,\
    \ L, R, x);\n      }\n      if (t == 6) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n      AA.eb(A);\n      roots.eb(root);\n  \
    \  }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/acted_monoid/min_assign.hpp\"\n#include \"ds/randomized_bst/rbst_acted_monoid.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  using AM = ActedMonoid_Min_Assign<int,\
    \ -1>;\n  using MonoX = typename AM::Monoid_X;\n\n  RBST_ActedMonoid<AM, true>\
    \ X(100000);\n  using np = decltype(X)::np;\n\n  FOR(1000) {\n    X.reset();\n\
    \    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vvc<int> AA(1);\n   \
    \ vc<np> roots;\n    FOR(i, N) AA[0].eb(RNG(1, 100));\n    roots.eb(X.new_node(AA[0]));\n\
    \n    FOR(Q) {\n      int t = RNG(0, 7);\n      int frm = RNG(0, len(AA));\n \
    \     np root = roots[frm];\n      vc<int> A = AA[frm];\n      if (t == 0) {\n\
    \        int i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n\
    \      if (t == 1) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n\
    \        root = X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t ==\
    \ 2) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root\
    \ = X.multiply(root, i, x);\n        A[i] = MonoX::op(A[i], x);\n      }\n   \
    \   if (t == 3) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n  \
    \      if (L > R) swap(L, R);\n        ++R;\n        vc<int> B = {A.begin() +\
    \ L, A.begin() + R};\n        assert(X.prod(root, L, R) == MIN(B));\n      }\n\
    \      if (t == 4) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n\
    \        if (L > R) swap(L, R);\n        ++R;\n        root = X.reverse(root,\
    \ L, R);\n        reverse(A.begin() + L, A.begin() + R);\n      }\n      if (t\
    \ == 5) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n        if\
    \ (L > R) swap(L, R);\n        ++R;\n        int x = RNG(1, 100);\n        FOR(i,\
    \ L, R) A[i] = x;\n        root = X.apply(root, L, R, x);\n      }\n      if (t\
    \ == 6) {\n        vc<int> B = X.get_all(root);\n        assert(A == B);\n   \
    \   }\n      AA.eb(A);\n      roots.eb(root);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/monoid/min.hpp
  - alg/monoid/assign.hpp
  - ds/randomized_bst/rbst_acted_monoid.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/rbst_am_persistent.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/rbst_am_persistent.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/rbst_am_persistent.test.cpp
- /verify/test/1_mytest/rbst_am_persistent.test.cpp.html
title: test/1_mytest/rbst_am_persistent.test.cpp
---
