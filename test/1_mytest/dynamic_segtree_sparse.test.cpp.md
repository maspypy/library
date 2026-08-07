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
  bundledCode: "#line 1 \"test/1_mytest/dynamic_segtree_sparse.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n//\
    \ \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\
    \u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"\
    avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include <cassert>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class>\nconstexpr\
    \ bool dependent_false = false;\n\ntemplate <class T>\nconstexpr T infty = []\
    \ {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\");\n  return\
    \ T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
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
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
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
    }\n#endif\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 1 \"ds/segtree/dynamic_segtree_sparse.hpp\"\n\n// \u5E38\u306B\u307B\
    \u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\u3042\u308B\u3053\u3068\
    \u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\u52D5\u7684\u30BB\u30B0\
    \u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod \u306E\u985E\u306F\
    \u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\u4E00\u822C\u306B\
    \u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\u3068\u304D\u30CE\
    \u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\u308B\ntemplate\
    \ <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node {\n    int\
    \ ch[2];\n    ll idx;\n    X prod, x;\n  };\n  const ll L0, R0;\n  static constexpr\
    \ int NIL = 0;\n  vc<Node> node;\n  vc<int> FREE;\n\n  Dynamic_SegTree_Sparse(ll\
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
    \  }\n\n  inline int clone(int c) {\n    if constexpr (!PERSISTENT)\n      return\
    \ c;\n    else {\n      if (c == NIL) return c;\n      node.eb(node[c]);\n   \
    \   return int(node.size()) - 1;\n    }\n  }\n\n  int set_rec(int c, ll l, ll\
    \ r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c = clone(c);\n\
    \    if (node[c].idx == i) {\n      node[c].x = x;\n      update(c);\n      return\
    \ c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (node[c].idx\
    \ < i) swap(node[c].idx, i), swap(node[c].x, x);\n      node[c].ch[0] = set_rec(node[c].ch[0],\
    \ l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx,\
    \ i), swap(node[c].x, x);\n      node[c].ch[1] = set_rec(node[c].ch[1], m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  int multiply_rec(int\
    \ c, ll l, ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c\
    \ = clone(c);\n    if (node[c].idx == i) {\n      node[c].x = MX::op(node[c].x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[0] = multiply_rec(node[c].ch[0], l, m, i, x);\n    }\n\
    \    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[1] = multiply_rec(node[c].ch[1], m, r, i, x);\n    }\n\
    \    update(c);\n    return c;\n  }\n\n  void prod_rec(int c, ll l, ll r, ll ql,\
    \ ll qr, X &x) {\n    chmax(ql, l), chmin(qr, r);\n    if (ql >= qr || c == NIL)\
    \ return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, node[c].prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(node[c].ch[0], l,\
    \ m, ql, qr, x);\n    if (ql <= (node[c].idx) && (node[c].idx) < qr) x = MX::op(x,\
    \ node[c].x);\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\n  }\n\n  template\
    \ <typename F>\n  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X\
    \ &x) {\n    if (c == NIL || r <= ql) return R0;\n    if (ql <= l && check(MX::op(x,\
    \ node[c].prod))) {\n      x = MX::op(x, node[c].prod);\n      return R0;\n  \
    \  }\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(node[c].ch[0], check,\
    \ l, m, ql, x);\n    if (k != R0) return k;\n    if (ql <= node[c].idx) {\n  \
    \    x = MX::op(x, node[c].x);\n      if (!check(x)) return node[c].idx;\n   \
    \ }\n    return max_right_rec(node[c].ch[1], check, m, r, ql, x);\n  }\n\n  template\
    \ <typename F>\n  ll min_left_rec(int c, const F &check, ll l, ll r, ll qr, X\
    \ &x) {\n    if (c == NIL || qr <= l) return L0;\n    if (check(MX::op(node[c].prod,\
    \ x))) {\n      x = MX::op(node[c].prod, x);\n      return L0;\n    }\n    ll\
    \ m = (l + r) / 2;\n    ll k = min_left_rec(node[c].ch[1], check, m, r, qr, x);\n\
    \    if (k != L0) return k;\n    if (node[c].idx < qr) {\n      x = MX::op(node[c].x,\
    \ x);\n      if (!check(x)) return node[c].idx + 1;\n    }\n    return min_left_rec(node[c].ch[0],\
    \ check, l, m, qr, x);\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 6 \"test/1_mytest/dynamic_segtree_sparse.test.cpp\"\
    \n\nvoid test() {\n  using Mono = Monoid_Min<int>;\n  int unit = Mono::unit();\n\
    \n  FOR(100) {\n    int N = RNG(1, 100);\n\n    vc<int> A(N, unit);\n    Dynamic_SegTree_Sparse<Mono,\
    \ false> X(0, N);\n    int root = 0;\n\n    int Q = RNG(1, 1000);\n\n    FOR(Q)\
    \ {\n      int t = RNG(0, 4);\n      int L = RNG(0, N);\n      int R = RNG(0,\
    \ N);\n      if (L > R) swap(L, R);\n      ++R;\n      if (t == 0) {\n       \
    \ int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root = X.set(root,\
    \ i, x);\n        A[i] = x;\n      }\n      if (t == 1) {\n        int i = RNG(0,\
    \ N);\n        int x = RNG(1, 100);\n        root = X.multiply(root, i, x);\n\
    \        chmin(A[i], x);\n      }\n      if (t == 2) {\n        vc<int> B = {A.begin()\
    \ + L, A.begin() + R};\n        assert(X.prod(root, L, R) == MIN(B));\n      }\n\
    \      if (t == 3) {\n        // max_right\n        int LIM = RNG(1, 100);\n \
    \       auto check = [&](auto e) -> bool { return e >= LIM; };\n        int naive\
    \ = [&]() -> int {\n          ll mi = unit;\n          FOR(i, L, N) {\n      \
    \      chmin(mi, A[i]);\n            if (mi < LIM) return i;\n          }\n  \
    \        return N;\n        }();\n        assert(naive == X.max_right(root, check,\
    \ L));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/monoid/min.hpp\"\n#include \"ds/segtree/dynamic_segtree_sparse.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  using Mono = Monoid_Min<int>;\n\
    \  int unit = Mono::unit();\n\n  FOR(100) {\n    int N = RNG(1, 100);\n\n    vc<int>\
    \ A(N, unit);\n    Dynamic_SegTree_Sparse<Mono, false> X(0, N);\n    int root\
    \ = 0;\n\n    int Q = RNG(1, 1000);\n\n    FOR(Q) {\n      int t = RNG(0, 4);\n\
    \      int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L,\
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
  dependsOn:
  - my_template.hpp
  - alg/monoid/min.hpp
  - ds/segtree/dynamic_segtree_sparse.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/dynamic_segtree_sparse.test.cpp
  requiredBy: []
  timestamp: '2026-08-08 05:13:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/dynamic_segtree_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/dynamic_segtree_sparse.test.cpp
- /verify/test/1_mytest/dynamic_segtree_sparse.test.cpp.html
title: test/1_mytest/dynamic_segtree_sparse.test.cpp
---
