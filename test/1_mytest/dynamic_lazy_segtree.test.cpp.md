---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  - icon: ':question:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':question:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':question:'
    path: ds/segtree/dynamic_lazy_segtree.hpp
    title: ds/segtree/dynamic_lazy_segtree.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/dynamic_lazy_segtree.test.cpp\"\n#define PROBLEM\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"alg/monoid/summax.hpp\"\
    \n\ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi + y.fi,\
    \ max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n  static\
    \ constexpr X unit() { return {E(0), -infty<E>}; }\n  static constexpr bool commute\
    \ = 1;\n};\n#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, int none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == X(none_val) ? x : y); }\r\n  static constexpr X unit() { return\
    \ X(none_val); }\r\n  static constexpr bool commute = false;\r\n};\r\n#line 3\
    \ \"alg/acted_monoid/summax_assign.hpp\"\n\r\ntemplate <typename E, E none_val>\r\
    \nstruct ActedMonoid_SumMax_Assign {\r\n  using Monoid_X = Monoid_SumMax<E>;\r\
    \n  using Monoid_A = Monoid_Assign<E, none_val>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X& x, const A& a, const ll& size) {\r\n    if (a == Monoid_A::unit()) return\
    \ x;\r\n    return {E(size) * a, a};\r\n  }\r\n};\r\n#line 2 \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n\n// Q*4logN \u7A0B\u5EA6\u5FC5\u8981? apply \u3067 4logN \u30CE\u30FC\u30C9\
    \u4F5C\u3063\u3066\u3044\u308B\u3068\u601D\u3046\ntemplate <typename ActedMonoid,\
    \ bool PERSISTENT>\nstruct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename AM::X;\n  using A = typename AM::A;\n  using F = function<X(ll,\
    \ ll)>;\n  F default_prod;\n\n  struct Node {\n    Node *l, *r;\n    X x;\n  \
    \  A lazy;\n  };\n\n  const int NODES;\n  const ll L0, R0;\n  Node *pool;\n  int\
    \ pid;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(\n      int NODES, ll L0,\
    \ ll R0, F default_prod = [](ll, ll) -> X { return MX::unit(); })\n      : default_prod(default_prod),\
    \ NODES(NODES), L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n  }\n \
    \ ~Dynamic_Lazy_SegTree() { delete[] pool; }\n\n  np new_root() { return new_node(L0,\
    \ R0); }\n\n  np new_node(const X x) {\n    assert(pid < NODES);\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].lazy = MA::unit();\n\
    \    return &(pool[pid++]);\n  }\n\n  np new_node(ll l, ll r) {\n    assert(l\
    \ < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node() { return\
    \ new_node(L0, R0); }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0 == 0\
    \ && R0 == len(dat));\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {\n\
    \      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      ll m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\n      X x = MX::op(l_root->x, r_root->x);\n      np root = new_node(x);\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np root, ll l, ll r) {\n    if (l ==\
    \ r || !root) return MX::unit();\n    assert(pid && L0 <= l && l < r && r <= R0);\n\
    \    X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x, MA::unit());\n   \
    \ return x;\n  }\n\n  X prod_all(np root) { return prod(root, L0, R0); }\n\n \
    \ np set(np root, ll i, const X &x) {\n    assert(pid && L0 <= i && i < R0);\n\
    \    return set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np root, ll i,\
    \ const X &x) {\n    assert(pid && L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  np apply(np root, ll l, ll r, const A &a) {\n    if\
    \ (l == r) return root;\n    assert(pid && L0 <= l && l < r && r <= R0);\n   \
    \ return apply_rec(root, L0, R0, l, r, a);\n  }\n\n  template <typename F>\n \
    \ ll max_right(np root, F check, ll L) {\n    assert(pid && L0 <= L && L <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x);\n  }\n\n  template <typename F>\n  ll min_left(np root,\
    \ F check, ll R) {\n    assert(pid && L0 <= R && R <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return min_left_rec(root, check, L0, R0, R, x);\n\
    \  }\n\n  // f(idx, val)\n  template <typename F>\n  void enumerate(np root, F\
    \ f) {\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {\n     \
    \ if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x, a, 1));\n\
    \        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n\
    \    dfs(dfs, root, L0, R0, MA::unit());\n  }\n\n  void reset() { pid = 0; }\n\
    \n  // root[l:r) \u3092 apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\
    \u3082\u306E\u3092\u8FD4\u3059\n  np copy_interval(np root, np other, ll l, ll\
    \ r, A a) {\n    if (root == other) return root;\n    root = copy_node(root);\n\
    \    copy_interval_rec(root, other, L0, R0, l, r, a);\n    return root;\n  }\n\
    \nprivate:\n  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n   \
    \ pool[pid].l = c->l, pool[pid].r = c->r;\n    pool[pid].x = c->x;\n    pool[pid].lazy\
    \ = c->lazy;\n    return &(pool[pid++]);\n  }\n\n  void prop(np c, ll l, ll r)\
    \ {\n    assert(r - l >= 2);\n    ll m = (l + r) / 2;\n    if (c->lazy == MA::unit())\
    \ return;\n    c->l = (c->l ? copy_node(c->l) : new_node(l, m));\n    c->l->x\
    \ = AM::act(c->l->x, c->lazy, m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n\
    \    c->r = (c->r ? copy_node(c->r) : new_node(m, r));\n    c->r->x = AM::act(c->r->x,\
    \ c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy\
    \ = MA::unit();\n  }\n\n  void copy_interval_rec(np c, np d, ll l, ll r, ll ql,\
    \ ll qr, A a) {\n    // c[ql,qr) <- apply(d[ql,qr),a)\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n    chmax(ql, l),\
    \ chmin(qr, r);\n    if (ql >= qr) return;\n    if (l == ql && r == qr) {\n  \
    \    if (d) {\n        c->x = AM::act(d->x, a, r - l), c->lazy = MA::op(d->lazy,\
    \ a);\n        c->l = d->l, c->r = d->r;\n      } else {\n        c->x = AM::act(default_prod(l,\
    \ r), a, r - l), c->lazy = a;\n        c->l = nullptr, c->r = nullptr;\n     \
    \ }\n      return;\n    }\n    // push\n    ll m = (l + r) / 2;\n    c->l = (c->l\
    \ ? copy_node(c->l) : new_node());\n    c->r = (c->r ? copy_node(c->r) : new_node());\n\
    \    c->l->x = AM::act(c->l->x, c->lazy, m - l);\n    c->l->lazy = MA::op(c->l->lazy,\
    \ c->lazy);\n    c->r->x = AM::act(c->r->x, c->lazy, r - m);\n    c->r->lazy =\
    \ MA::op(c->r->lazy, c->lazy);\n    c->lazy = MA::unit();\n    if (d) a = MA::op(d->lazy,\
    \ a);\n    copy_interval_rec(c->l, (d && d->l ? d->l : nullptr), l, m, ql, qr,\
    \ a);\n    copy_interval_rec(c->r, (d && d->r ? d->r : nullptr), m, r, ql, qr,\
    \ a);\n    c->x = MX::op(c->l->x, c->r->x);\n    return;\n  }\n\n  np set_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    if (r == l + 1) {\n      c = copy_node(c);\n\
    \      c->x = x;\n      c->lazy = MA::unit();\n      return c;\n    }\n    prop(c,\
    \ l, r);\n    ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l, m);\n   \
    \ if (!c->r) c->r = new_node(m, r);\n\n    c = copy_node(c);\n    if (i < m) {\n\
    \      c->l = set_rec(c->l, l, m, i, x);\n    } else {\n      c->r = set_rec(c->r,\
    \ m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n \
    \ }\n\n  np multiply_rec(np c, ll l, ll r, ll i, const X &x) {\n    if (r == l\
    \ + 1) {\n      c = copy_node(c);\n      c->x = MX::op(c->x, x);\n      c->lazy\
    \ = MA::unit();\n      return c;\n    }\n    prop(c, l, r);\n    ll m = (l + r)\
    \ / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m,\
    \ r);\n\n    c = copy_node(c);\n    if (i < m) {\n      c->l = multiply_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      c->r = multiply_rec(c->r, m, r, i, x);\n \
    \   }\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  void prod_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, X &x, A lazy) {\n    chmax(ql, l);\n    chmin(qr,\
    \ r);\n    if (ql >= qr) return;\n    if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql,\
    \ qr), lazy, qr - ql));\n      return;\n    }\n    if (l == ql && r == qr) {\n\
    \      x = MX::op(x, AM::act(c->x, lazy, r - l));\n      return;\n    }\n    ll\
    \ m = (l + r) / 2;\n    lazy = MA::op(c->lazy, lazy);\n    prod_rec(c->l, l, m,\
    \ ql, qr, x, lazy);\n    prod_rec(c->r, m, r, ql, qr, x, lazy);\n  }\n\n  np apply_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, const A &a) {\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return c;\n    if (l\
    \ == ql && r == qr) {\n      c = copy_node(c);\n      c->x = AM::act(c->x, a,\
    \ r - l);\n      c->lazy = MA::op(c->lazy, a);\n      return c;\n    }\n    prop(c,\
    \ l, r);\n    ll m = (l + r) / 2;\n    c = copy_node(c);\n    c->l = apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    c->r = apply_rec(c->r, m, r, ql, qr, a);\n    c->x =\
    \ MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  template <typename F>\n \
    \ ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {\n    if (r\
    \ <= ql) return r;\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    if\
    \ (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x, c->x);\n      return\
    \ r;\n    }\n    if (r == l + 1) return l;\n    prop(c, l, r);\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n    if (k <\
    \ m) return k;\n    return max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n \
    \ template <typename F>\n  ll min_left_rec(np c, const F &check, ll l, ll r, ll\
    \ qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l, r);\n \
    \   chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n      x = MX::op(c->x,\
    \ x);\n      return l;\n    }\n    if (r == l + 1) return r;\n    prop(c, l, r);\n\
    \    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check, m, r, qr, x);\n\
    \    if (m < k) return k;\n    return min_left_rec(c->l, check, l, m, qr, x);\n\
    \  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 6 \"test/1_mytest/dynamic_lazy_segtree.test.cpp\"\
    \n\nvoid test() {\n  using AM = ActedMonoid_SumMax_Assign<int, -1>;\n  using P\
    \ = typename AM::X;\n\n  FOR(1000) {\n    int N = RNG(1, 1000);\n    int Q = RNG(1,\
    \ 1000);\n    vc<int> A(N, 10);\n    Dynamic_Lazy_SegTree<AM, false> X(1 + 40\
    \ * Q, 0, N, [](ll l, ll r) -> P { return {10 * (r - l), 10}; });\n\n    auto\
    \ root = X.new_node(0, N);\n\n    FOR(Q) {\n      int t = RNG(0, 4);\n      int\
    \ L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n   \
    \   ++R;\n      if (t == 0) {\n        int i = RNG(0, N);\n        int x = RNG(1,\
    \ 100);\n        root = X.set(root, i, {x, x});\n        A[i] = x;\n      }\n\
    \      if (t == 1) {\n        vc<int> B = {A.begin() + L, A.begin() + R};\n  \
    \      assert(X.prod(root, L, R).fi == SUM<int>(B));\n        assert(X.prod(root,\
    \ L, R).se == MAX(B));\n      }\n      if (t == 2) {\n        int x = RNG(1, 100);\n\
    \        FOR(i, L, R) A[i] = x;\n        root = X.apply(root, L, R, x);\n    \
    \  }\n      if (t == 3) {\n        // max_right\n        int LIM = R;\n      \
    \  auto check = [&](auto e) -> bool { return e.se <= LIM; };\n        int naive\
    \ = [&]() -> int {\n          ll mx = 0;\n          FOR(i, L, N) {\n         \
    \   chmax(mx, A[i]);\n            if (mx > LIM) return i;\n          }\n     \
    \     return N;\n        }();\n\n        assert(naive == X.max_right(root, check,\
    \ L));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/acted_monoid/summax_assign.hpp\"\n#include \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  using AM = ActedMonoid_SumMax_Assign<int,\
    \ -1>;\n  using P = typename AM::X;\n\n  FOR(1000) {\n    int N = RNG(1, 1000);\n\
    \    int Q = RNG(1, 1000);\n    vc<int> A(N, 10);\n    Dynamic_Lazy_SegTree<AM,\
    \ false> X(1 + 40 * Q, 0, N, [](ll l, ll r) -> P { return {10 * (r - l), 10};\
    \ });\n\n    auto root = X.new_node(0, N);\n\n    FOR(Q) {\n      int t = RNG(0,\
    \ 4);\n      int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L,\
    \ R);\n      ++R;\n      if (t == 0) {\n        int i = RNG(0, N);\n        int\
    \ x = RNG(1, 100);\n        root = X.set(root, i, {x, x});\n        A[i] = x;\n\
    \      }\n      if (t == 1) {\n        vc<int> B = {A.begin() + L, A.begin() +\
    \ R};\n        assert(X.prod(root, L, R).fi == SUM<int>(B));\n        assert(X.prod(root,\
    \ L, R).se == MAX(B));\n      }\n      if (t == 2) {\n        int x = RNG(1, 100);\n\
    \        FOR(i, L, R) A[i] = x;\n        root = X.apply(root, L, R, x);\n    \
    \  }\n      if (t == 3) {\n        // max_right\n        int LIM = R;\n      \
    \  auto check = [&](auto e) -> bool { return e.se <= LIM; };\n        int naive\
    \ = [&]() -> int {\n          ll mx = 0;\n          FOR(i, L, N) {\n         \
    \   chmax(mx, A[i]);\n            if (mx > LIM) return i;\n          }\n     \
    \     return N;\n        }();\n\n        assert(naive == X.max_right(root, check,\
    \ L));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - alg/acted_monoid/summax_assign.hpp
  - alg/monoid/summax.hpp
  - alg/monoid/assign.hpp
  - ds/segtree/dynamic_lazy_segtree.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/dynamic_lazy_segtree.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/dynamic_lazy_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/dynamic_lazy_segtree.test.cpp
- /verify/test/1_mytest/dynamic_lazy_segtree.test.cpp.html
title: test/1_mytest/dynamic_lazy_segtree.test.cpp
---
