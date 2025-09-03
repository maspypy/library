---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/randomized_bst/rbst.hpp
    title: ds/randomized_bst/rbst.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/rbst.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16\
    \ = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
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
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a\
    \ < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a,\
    \ const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off =\
    \ 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i]\
    \ + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 1 \"ds/randomized_bst/rbst.hpp\"\n//\
    \ \u5358\u306B S \u306E\u5143\u306E\u5217\u3092\u7BA1\u7406\u3059\u308B\ntemplate\
    \ <typename S, bool PERSISTENT>\nstruct RBST {\n  struct Node {\n    Node *l,\
    \ *r;\n    S s;\n    u32 size;\n    bool rev;\n  };\n\n  const int NODES;\n  Node\
    \ *pool;\n  int pid;\n  using np = Node *;\n\n  RBST(int NODES) : NODES(NODES),\
    \ pid(0) { pool = new Node[NODES]; }\n  ~RBST() { delete[] pool; }\n\n  void reset()\
    \ { pid = 0; }\n\n  np new_node(const S &s) {\n    pool[pid].l = pool[pid].r =\
    \ nullptr;\n    pool[pid].s = s;\n    pool[pid].size = 1;\n    pool[pid].rev =\
    \ 0;\n    return &(pool[pid++]);\n  }\n\n  np new_node(const vc<S> &dat) {\n \
    \   auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      u32 m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1,\
    \ r);\n      np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      update(root);\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  np copy_node(np &n) {\n    if (!n || !PERSISTENT) return n;\n    pool[pid].l\
    \ = n->l, pool[pid].r = n->r;\n    pool[pid].s = n->s;\n    pool[pid].size = n->size;\n\
    \    pool[pid].rev = n->rev;\n    return &(pool[pid++]);\n  }\n\n  np merge(np\
    \ l_root, np r_root) { return merge_rec(l_root, r_root); }\n  np merge3(np a,\
    \ np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np c,\
    \ np d) { return merge(merge(merge(a, b), c), d); }\n  pair<np, np> split(np root,\
    \ u32 k) {\n    if (!root) {\n      assert(k == 0);\n      return {nullptr, nullptr};\n\
    \    }\n    assert(0 <= k && k <= root->size);\n    return split_rec(root, k);\n\
    \  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n  \
    \  tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n    return\
    \ {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32 i, u32 j,\
    \ u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto [a, b, c]\
    \ = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  np reverse(np root,\
    \ u32 l, u32 r) {\n    assert(0 <= l && l <= r && r <= root->size);\n    if (r\
    \ - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n    nm->rev\
    \ ^= 1;\n    swap(nm->l, nm->r);\n    return merge3(nl, nm, nr);\n  }\n\n  np\
    \ set(np root, u32 k, const S &s) { return set_rec(root, k, s); }\n  S get(np\
    \ root, u32 k) { return get_rec(root, k, false); }\n\n  vc<S> get_all(np root)\
    \ {\n    vc<S> res;\n    auto dfs = [&](auto &dfs, np root, bool rev) -> void\
    \ {\n      if (!root) return;\n      dfs(dfs, (rev ? root->r : root->l), rev ^\
    \ root->rev);\n      res.eb(root->s);\n      dfs(dfs, (rev ? root->l : root->r),\
    \ rev ^ root->rev);\n    };\n    dfs(dfs, root, 0);\n    return res;\n  }\n\n\
    \  // \u6700\u5F8C\u306B check(s) \u304C\u6210\u308A\u7ACB\u3064\u3068\u3053\u308D\
    \u307E\u3067\u3092\u5DE6\u3068\u3057\u3066 split\n  template <typename F>\n  pair<np,\
    \ np> split_max_right(np root, const F check) {\n    return split_max_right_rec(root,\
    \ check);\n  }\n\nprivate:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n\
    \    static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32\
    \ w = 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n\
    \    // \u81EA\u8EAB\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\
    \u3044\u3002\n    // \u5B50\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\u8907\u6570\u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u3002\n    if (c->rev) {\n      if (c->l) {\n \
    \       c->l = copy_node(c->l);\n        c->l->rev ^= 1;\n        swap(c->l->l,\
    \ c->l->r);\n      }\n      if (c->r) {\n        c->r = copy_node(c->r);\n   \
    \     c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n      }\n      c->rev\
    \ = 0;\n    }\n  }\n\n  void update(np c) {\n    // \u30C7\u30FC\u30BF\u3092\u4FDD\
    \u3063\u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\u3060\u3051\u306A\u306E\
    \u3067\u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size = 1;\n    if (c->l) {\
    \ c->size += c->l->size; }\n    if (c->r) { c->size += c->r->size; }\n  }\n\n\
    \  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return r_root;\n   \
    \ if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
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
    \ {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const S &s) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
    \ k, s);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->s = s;\n      update(root);\n    \
    \  return root;\n    }\n    root = copy_node(root);\n    root->r = set_rec(root->r,\
    \ k - (1 + sl), s);\n    update(root);\n    return root;\n  }\n\n  S get_rec(np\
    \ root, u32 k, bool rev) {\n    np left = (rev ? root->r : root->l);\n    np right\
    \ = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size : 0);\n    if\
    \ (k == sl) return root->s;\n    rev ^= root->rev;\n    if (k < sl) return get_rec(left,\
    \ k, rev);\n    return get_rec(right, k - (1 + sl), rev);\n  }\n\n  template <typename\
    \ F>\n  pair<np, np> split_max_right_rec(np root, const F &check) {\n    if (!root)\
    \ return {nullptr, nullptr};\n    prop(root);\n    root = copy_node(root);\n \
    \   if (check(root->s)) {\n      auto [n1, n2] = split_max_right_rec(root->r,\
    \ check);\n      root->r = n1;\n      update(root);\n      return {root, n2};\n\
    \    }\n    auto [n1, n2] = split_max_right_rec(root->l, check);\n    root->l\
    \ = n2;\n    update(root);\n    return {n1, root};\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 5 \"test/1_mytest/rbst.test.cpp\"\n\nvoid test()\
    \ {\n  RBST<int, true> X(10000);\n  using np = decltype(X)::np;\n\n  FOR(1000)\
    \ {\n    X.reset();\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vvc<int>\
    \ AA(1);\n    FOR(i, N) AA[0].eb(RNG(0, 100));\n    vc<np> roots = {X.new_node(AA[0])};\n\
    \n    FOR(Q) {\n      vc<int> cand = {0, 1, 2, 3};\n      int t = cand[RNG(0,\
    \ len(cand))];\n      int frm = RNG(0, len(AA));\n      vc<int> A = AA[frm];\n\
    \      np root = roots[frm];\n      if (t == 0) {\n        int i = RNG(0, N);\n\
    \        assert(A[i] == X.get(root, i));\n      }\n      if (t == 1) {\n     \
    \   int i = RNG(0, N);\n        int x = RNG(0, 100);\n        root = X.set(root,\
    \ i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n        int L = RNG(0,\
    \ N);\n        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n\
    \        root = X.reverse(root, L, R);\n        reverse(A.begin() + L, A.begin()\
    \ + R);\n      }\n      if (t == 3) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n      AA.eb(A);\n      roots.eb(root);\n  \
    \  }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"ds/randomized_bst/rbst.hpp\"\n#include \"random/base.hpp\"\n\nvoid\
    \ test() {\n  RBST<int, true> X(10000);\n  using np = decltype(X)::np;\n\n  FOR(1000)\
    \ {\n    X.reset();\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vvc<int>\
    \ AA(1);\n    FOR(i, N) AA[0].eb(RNG(0, 100));\n    vc<np> roots = {X.new_node(AA[0])};\n\
    \n    FOR(Q) {\n      vc<int> cand = {0, 1, 2, 3};\n      int t = cand[RNG(0,\
    \ len(cand))];\n      int frm = RNG(0, len(AA));\n      vc<int> A = AA[frm];\n\
    \      np root = roots[frm];\n      if (t == 0) {\n        int i = RNG(0, N);\n\
    \        assert(A[i] == X.get(root, i));\n      }\n      if (t == 1) {\n     \
    \   int i = RNG(0, N);\n        int x = RNG(0, 100);\n        root = X.set(root,\
    \ i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n        int L = RNG(0,\
    \ N);\n        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n\
    \        root = X.reverse(root, L, R);\n        reverse(A.begin() + L, A.begin()\
    \ + R);\n      }\n      if (t == 3) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n      AA.eb(A);\n      roots.eb(root);\n  \
    \  }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - ds/randomized_bst/rbst.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/rbst.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 07:11:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/rbst.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/rbst.test.cpp
- /verify/test/1_mytest/rbst.test.cpp.html
title: test/1_mytest/rbst.test.cpp
---
