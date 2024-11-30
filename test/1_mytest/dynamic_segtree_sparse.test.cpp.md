---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/dynamic_segtree_sparse.hpp
    title: ds/segtree/dynamic_segtree_sparse.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/dynamic_segtree_sparse.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(x)\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parity(x) & 1 ? -1 : 1);\
    \ }\nint popcnt_sgn(u64 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 -\
    \ __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\
    \ [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return\
    \ ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/segtree/dynamic_segtree_sparse.hpp\"\
    \n\n// \u5E38\u306B\u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\
    \u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\
    \u52D5\u7684\u30BB\u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod\
    \ \u306E\u985E\u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\
    \u4E00\u822C\u306B\u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\
    \u3068\u304D\u30CE\u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\
    \u308B\ntemplate <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node\
    \ {\n    ll idx;\n    Node *l, *r;\n    X prod, x;\n  };\n  const int NODES;\n\
    \  const ll L0, R0;\n  Node *pool;\n  int pid;\n  using np = Node *;\n  vc<np>\
    \ FREE;\n\n  Dynamic_SegTree_Sparse(int NODES, ll L0, ll R0) : NODES(NODES), L0(L0),\
    \ R0(R0), pid(0) { pool = new Node[NODES]; }\n  ~Dynamic_SegTree_Sparse() { delete[]\
    \ pool; }\n\n  // \u6728 dp \u306E\u30DE\u30FC\u30B8\u306E\u3068\u304D\u306A\u3069\
    \u306B\u4F7F\u7528\u3059\u308B\u3068 MLE \u56DE\u907F\u3067\u304D\u308B\u3053\u3068\
    \u304C\u3042\u308B\n  // https://codeforces.com/problemset/problem/671/D\n  void\
    \ free_subtree(np c) {\n    auto dfs = [&](auto &dfs, np c) -> void {\n      if\
    \ (c->l) dfs(dfs, c->l);\n      if (c->r) dfs(dfs, c->r);\n      FREE.eb(c);\n\
    \    };\n    dfs(dfs, c);\n  }\n\n  np new_root() { return nullptr; }\n\n  np\
    \ new_node(ll idx, const X x) {\n    if (!FREE.empty()) {\n      np c = POP(FREE);\n\
    \      c->idx = idx, c->l = c->r = nullptr;\n      c->prod = c->x = x;\n     \
    \ return c;\n    }\n    assert(pid < NODES);\n    pool[pid].idx = idx;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = pool[pid].prod = x;\n    return\
    \ &(pool[pid++]);\n  }\n\n  X prod(np root, ll l, ll r) {\n    assert(L0 <= l\
    \ && l <= r && r <= R0);\n    if (l == r) return MX::unit();\n    X x = MX::unit();\n\
    \    prod_rec(root, L0, R0, l, r, x);\n    return x;\n  }\n\n  X prod_all(np root)\
    \ { return prod(root, L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n  \
    \  assert(L0 <= i && i < R0);\n    return set_rec(root, L0, R0, i, x);\n  }\n\n\
    \  np multiply(np root, ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n\
    \    return multiply_rec(root, L0, R0, i, x);\n  }\n\n  template <typename F>\n\
    \  ll max_right(np root, F check, ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return max_right_rec(root, check, L0, R0, L, x);\n\
    \  }\n\n  template <typename F>\n  ll min_left(np root, F check, ll R) {\n   \
    \ assert(L0 <= R && R <= R0 && check(MX::unit()));\n    X x = MX::unit();\n  \
    \  return min_left_rec(root, check, L0, R0, R, x);\n  }\n\n  void reset() {\n\
    \    pid = 0;\n    FREE.clear();\n  }\n\n  vc<pair<ll, X>> get_all(np root) {\n\
    \    vc<pair<ll, X>> res;\n    auto dfs = [&](auto &dfs, np c) -> void {\n   \
    \   if (!c) return;\n      dfs(dfs, c->l);\n      res.eb(c->idx, c->x);\n    \
    \  dfs(dfs, c->r);\n    };\n    dfs(dfs, root);\n    return res;\n  }\n\n  X get(np\
    \ root, ll idx) {\n    auto dfs = [&](auto &dfs, np c) -> X {\n      if (!c) return\
    \ Monoid::unit();\n      if (idx == c->idx) return c->x;\n      if (idx < (c->idx))\
    \ return dfs(dfs, c->l);\n      return dfs(dfs, c->r);\n    };\n    return dfs(dfs,\
    \ root);\n  }\n\nprivate:\n  void update(np c) {\n    c->prod = c->x;\n    if\
    \ (c->l) c->prod = MX::op(c->l->prod, c->prod);\n    if (c->r) c->prod = MX::op(c->prod,\
    \ c->r->prod);\n  }\n\n  np copy_node(np c) {\n    if (!c || !PERSISTENT) return\
    \ c;\n    assert(pid < NODES);\n    pool[pid].idx = c->idx;\n    pool[pid].l =\
    \ c->l;\n    pool[pid].r = c->r;\n    pool[pid].x = c->x;\n    pool[pid].prod\
    \ = c->prod;\n    return &(pool[pid++]);\n  }\n\n  np set_rec(np c, ll l, ll r,\
    \ ll i, X x) {\n    if (!c) {\n      c = new_node(i, x);\n      return c;\n  \
    \  }\n    c = copy_node(c);\n    if (c->idx == i) {\n      c->x = x;\n      update(c);\n\
    \      return c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (c->idx\
    \ < i) swap(c->idx, i), swap(c->x, x);\n      c->l = set_rec(c->l, l, m, i, x);\n\
    \    }\n    if (m <= i) {\n      if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n\
    \      c->r = set_rec(c->r, m, r, i, x);\n    }\n    update(c);\n    return c;\n\
    \  }\n\n  np multiply_rec(np c, ll l, ll r, ll i, X x) {\n    if (!c) {\n    \
    \  c = new_node(i, x);\n      return c;\n    }\n    c = copy_node(c);\n    if\
    \ (c->idx == i) {\n      c->x = MX::op(c->x, x);\n      update(c);\n      return\
    \ c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (c->idx < i)\
    \ swap(c->idx, i), swap(c->x, x);\n      c->l = multiply_rec(c->l, l, m, i, x);\n\
    \    }\n    if (m <= i) {\n      if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n\
    \      c->r = multiply_rec(c->r, m, r, i, x);\n    }\n    update(c);\n    return\
    \ c;\n  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {\n    chmax(ql,\
    \ l);\n    chmin(qr, r);\n    if (ql >= qr || !c) return;\n    if (l == ql &&\
    \ r == qr) {\n      x = MX::op(x, c->prod);\n      return;\n    }\n    ll m =\
    \ (l + r) / 2;\n    prod_rec(c->l, l, m, ql, qr, x);\n    if (ql <= (c->idx) &&\
    \ (c->idx) < qr) x = MX::op(x, c->x);\n    prod_rec(c->r, m, r, ql, qr, x);\n\
    \  }\n\n  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l,\
    \ ll r, ll ql, X &x) {\n    if (!c || r <= ql) return R0;\n    if (check(MX::op(x,\
    \ c->prod))) {\n      x = MX::op(x, c->prod);\n      return R0;\n    }\n    ll\
    \ m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n    if\
    \ (k != R0) return k;\n    if (ql <= (c->idx)) {\n      x = MX::op(x, c->x);\n\
    \      if (!check(x)) return c->idx;\n    }\n    return max_right_rec(c->r, check,\
    \ m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c, const\
    \ F &check, ll l, ll r, ll qr, X &x) {\n    if (!c || qr <= l) return L0;\n  \
    \  if (check(MX::op(c->prod, x))) {\n      x = MX::op(c->prod, x);\n      return\
    \ L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m,\
    \ r, qr, x);\n    if (k != L0) return k;\n    if (c->idx < qr) {\n      x = MX::op(c->x,\
    \ x);\n      if (!check(x)) return c->idx + 1;\n    }\n    return min_left_rec(c->l,\
    \ check, l, m, qr, x);\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 6 \"test/1_mytest/dynamic_segtree_sparse.test.cpp\"\
    \n\nvoid test() {\n  using Mono = Monoid_Min<int>;\n  int unit = Mono::unit();\n\
    \n  FOR(100) {\n    int N = RNG(1, 100);\n\n    vc<int> A(N, unit);\n    Dynamic_SegTree_Sparse<Mono,\
    \ false> X(2 * N, 0, N);\n    using np = typename decltype(X)::np;\n    np root\
    \ = nullptr;\n\n    int Q = RNG(1, 1000);\n\n    FOR(Q) {\n      int t = RNG(0,\
    \ 4);\n      int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L,\
    \ R);\n      ++R;\n      if (t == 0) {\n        int i = RNG(0, N);\n        int\
    \ x = RNG(1, 100);\n        root = X.set(root, i, x);\n        A[i] = x;\n   \
    \   }\n      if (t == 1) {\n        int i = RNG(0, N);\n        int x = RNG(1,\
    \ 100);\n        root = X.multiply(root, i, x);\n        chmin(A[i], x);\n   \
    \   }\n      if (t == 2) {\n        vc<int> B = {A.begin() + L, A.begin() + R};\n\
    \        assert(X.prod(root, L, R) == MIN(B));\n      }\n      if (t == 3) {\n\
    \        // max_right\n        int LIM = RNG(1, 100);\n        auto check = [&](auto\
    \ e) -> bool { return e >= LIM; };\n        int naive = [&]() -> int {\n     \
    \     ll mi = unit;\n          FOR(i, L, N) {\n            chmin(mi, A[i]);\n\
    \            if (mi < LIM) return i;\n          }\n          return N;\n     \
    \   }();\n        assert(naive == X.max_right(root, check, L));\n      }\n   \
    \ }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b\
    \ << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/monoid/min.hpp\"\n#include \"ds/segtree/dynamic_segtree_sparse.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  using Mono = Monoid_Min<int>;\n\
    \  int unit = Mono::unit();\n\n  FOR(100) {\n    int N = RNG(1, 100);\n\n    vc<int>\
    \ A(N, unit);\n    Dynamic_SegTree_Sparse<Mono, false> X(2 * N, 0, N);\n    using\
    \ np = typename decltype(X)::np;\n    np root = nullptr;\n\n    int Q = RNG(1,\
    \ 1000);\n\n    FOR(Q) {\n      int t = RNG(0, 4);\n      int L = RNG(0, N);\n\
    \      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n      if\
    \ (t == 0) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n     \
    \   root = X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t == 1) {\n\
    \        int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root = X.multiply(root,\
    \ i, x);\n        chmin(A[i], x);\n      }\n      if (t == 2) {\n        vc<int>\
    \ B = {A.begin() + L, A.begin() + R};\n        assert(X.prod(root, L, R) == MIN(B));\n\
    \      }\n      if (t == 3) {\n        // max_right\n        int LIM = RNG(1,\
    \ 100);\n        auto check = [&](auto e) -> bool { return e >= LIM; };\n    \
    \    int naive = [&]() -> int {\n          ll mi = unit;\n          FOR(i, L,\
    \ N) {\n            chmin(mi, A[i]);\n            if (mi < LIM) return i;\n  \
    \        }\n          return N;\n        }();\n        assert(naive == X.max_right(root,\
    \ check, L));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/monoid/min.hpp
  - ds/segtree/dynamic_segtree_sparse.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/dynamic_segtree_sparse.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/dynamic_segtree_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/dynamic_segtree_sparse.test.cpp
- /verify/test/1_mytest/dynamic_segtree_sparse.test.cpp.html
title: test/1_mytest/dynamic_segtree_sparse.test.cpp
---
