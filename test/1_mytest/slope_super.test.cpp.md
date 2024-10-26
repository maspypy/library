---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':heavy_check_mark:'
    path: convex/slope_trick/slope_super.hpp
    title: convex/slope_trick/slope_super.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/slope_super.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/slope_super.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 2 \"ds/splaytree/splaytree.hpp\"\
    \n\n/*\nupdate \u3067\u3061\u3083\u3093\u3068 prod \u304C\u8A08\u7B97\u3055\u308C\
    \u3066\u304F\u308C\u308C\u3070 prod \u306F op(lprod,x,rprod) \u3067\u306A\u304F\
    \u3066\u3082\u3088\u3044.\n*/\n\n// Node \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\
    \u3066\u4F7F\u3046\ntemplate <typename Node>\nstruct SplayTree {\n  Node *pool;\n\
    \  const int NODES;\n  int pid;\n  using np = Node *;\n  using X = typename Node::value_type;\n\
    \  using A = typename Node::operator_type;\n  vc<np> FREE;\n\n  SplayTree(int\
    \ NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n  ~SplayTree() {\
    \ delete[] pool; }\n\n  void free_subtree(np c) {\n    if (!c) return;\n    auto\
    \ dfs = [&](auto &dfs, np c) -> void {\n      if (c->l) dfs(dfs, c->l);\n    \
    \  if (c->r) dfs(dfs, c->r);\n      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\
    \n  void reset() {\n    pid = 0;\n    FREE.clear();\n  }\n\n  np new_root() {\
    \ return nullptr; }\n\n  np new_node(const X &x) {\n    assert(!FREE.empty() ||\
    \ pid < NODES);\n    np n = (FREE.empty() ? &(pool[pid++]) : POP(FREE));\n   \
    \ Node::new_node(n, x);\n    return n;\n  }\n\n  np new_node(const vc<X> &dat)\
    \ {\n    auto dfs = [&](auto &dfs, int l, int r) -> np {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      int m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1,\
    \ r);\n      np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n  \
    \    root->update();\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  u32 get_size(np root) { return (root ? root->size : 0); }\n\n  np merge(np\
    \ l_root, np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return\
    \ l_root;\n    assert((!l_root->p) && (!r_root->p));\n    splay_kth(r_root, 0);\
    \ // splay \u3057\u305F\u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n   \
    \ l_root->p = r_root;\n    r_root->update();\n    return r_root;\n  }\n  np merge3(np\
    \ a, np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np\
    \ c, np d) { return merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np\
    \ root, u32 k) {\n    assert(!root || !root->p);\n    if (k == 0) return {nullptr,\
    \ root};\n    if (k == (root->size)) return {root, nullptr};\n    splay_kth(root,\
    \ k - 1);\n    np right = root->r;\n    root->r = nullptr, right->p = nullptr;\n\
    \    root->update();\n    return {root, right};\n  }\n  tuple<np, np, np> split3(np\
    \ root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n\
    \    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np,\
    \ np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root,\
    \ d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a,\
    \ b, c, d};\n  }\n\n  // \u90E8\u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\
    \u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\
    \u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\
    \u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\
    \u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay\
    \ \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np\
    \ &root, u32 l, u32 r) {\n    if (l == 0 && r == root->size) return;\n    if (l\
    \ == 0) {\n      splay_kth(root, r);\n      root = root->l;\n      return;\n \
    \   }\n    if (r == root->size) {\n      splay_kth(root, l - 1);\n      root =\
    \ root->r;\n      return;\n    }\n    splay_kth(root, r);\n    np rp = root;\n\
    \    root = rp->l;\n    root->p = nullptr;\n    splay_kth(root, l - 1);\n    root->p\
    \ = rp;\n    rp->l = root;\n    rp->update();\n    root = root->r;\n  }\n\n  vc<X>\
    \ get_all(const np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np\
    \ root) -> void {\n      if (!root) return;\n      root->prop();\n      dfs(dfs,\
    \ root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n  \
    \  dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k) {\n    assert(root\
    \ == nullptr || !root->p);\n    splay_kth(root, k);\n    return root->get();\n\
    \  }\n\n  void set(np &root, u32 k, const X &x) {\n    assert(root != nullptr\
    \ && !root->p);\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np\
    \ &root, u32 k, const X &x) {\n    assert(root != nullptr && !root->p);\n    splay_kth(root,\
    \ k);\n    root->multiply(x);\n  }\n\n  X prod(np &root, u32 l, u32 r) {\n   \
    \ assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    if (l == r) return Mono::unit();\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    goto_between(root, l, r);\n    X res = root->prod;\n    splay(root, true);\n\
    \    return res;\n  }\n\n  X prod(np &root) {\n    assert(root == nullptr || !root->p);\n\
    \    using Mono = typename Node::Monoid_X;\n    return (root ? root->prod : Mono::unit());\n\
    \  }\n\n  void apply(np &root, u32 l, u32 r, const A &a) {\n    if (l == r) return;\n\
    \    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n\
    \    root->apply(a);\n    splay(root, true);\n  }\n  void apply(np &root, const\
    \ A &a) {\n    if (!root) return;\n    root->apply(a);\n  }\n\n  void reverse(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    if (l\
    \ == r) return;\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    root->reverse();\n    splay(root, true);\n  }\n  void reverse(np\
    \ root) {\n    if (!root) return;\n    root->reverse();\n  }\n\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update\
    \ \u306F rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r\
    \ = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n    \
    \  p->r = c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r\
    \ == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\
    \n  void prop_from_root(np c) {\n    if (!c->p) {\n      c->prop();\n      return;\n\
    \    }\n    prop_from_root(c->p);\n    c->prop();\n  }\n\n  void splay(Node *me,\
    \ bool prop_from_root_done) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\
    \u3067\u3001me \u306E\u7956\u5148\uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\
    \u306B prop \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\
    \u306B\u3001splay \u7D42\u4E86\u6642\u70B9\u3067 me \u306F upd / prop \u6E08\u3067\
    \u3042\u308B\n    if (!prop_from_root_done) prop_from_root(me);\n    me->prop();\n\
    \    while (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp)\
    \ {\n        rotate(me);\n        p->update();\n        break;\n      }\n    \
    \  bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n   \
    \   if (same) rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n\
    \      pp->update(), p->update();\n    }\n    // me \u306E update \u306F\u6700\
    \u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np\
    \ &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n\
    \      root->prop();\n      u32 sl = (root->l ? root->l->size : 0);\n      if\
    \ (k == sl) break;\n      if (k < sl)\n        root = root->l;\n      else {\n\
    \        k -= sl + 1;\n        root = root->r;\n      }\n    }\n    splay(root,\
    \ true);\n  }\n\n  // check(x), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\
    \u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template\
    \ <typename F>\n  pair<np, np> split_max_right(np root, F check) {\n    if (!root)\
    \ return {nullptr, nullptr};\n    assert(!root->p);\n    np c = find_max_right(root,\
    \ check);\n    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n\
    \    }\n    splay(c, true);\n    np right = c->r;\n    if (!right) return {c,\
    \ nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n\
    \    return {c, right};\n  }\n\n  // check(x, cnt), \u5DE6\u5074\u306E\u30CE\u30FC\
    \u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\
    \u308B\n  template <typename F>\n  pair<np, np> split_max_right_cnt(np root, F\
    \ check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_cnt(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right_prod(np root, F check) {\n    if (!root) return {nullptr,\
    \ nullptr};\n    assert(!root->p);\n    np c = find_max_right_prod(root, check);\n\
    \    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n    }\n\
    \    splay(c, true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_cnt(np\
    \ root, const F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok\
    \ \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok\
    \ = nullptr, last = nullptr;\n    ll n = 0;\n    while (root) {\n      last =\
    \ root;\n      root->prop();\n      ll ns = (root->l ? root->l->size : 0);\n \
    \     if (check(root->x, n + ns + 1)) {\n        last_ok = root;\n        n +=\
    \ ns + 1;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\n  template\
    \ <typename F>\n  np find_max_right_prod(np root, const F &check) {\n    using\
    \ Mono = typename Node::Monoid_X;\n    X prod = Mono::unit();\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->prop();\n      np tmp = root->r;\n      root->r\
    \ = nullptr;\n      root->update();\n      X lprod = Mono::op(prod, root->prod);\n\
    \      root->r = tmp;\n      root->update();\n      if (check(lprod)) {\n    \
    \    prod = lprod;\n        last_ok = root;\n        root = root->r;\n      }\
    \ else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n  \
    \  return last_ok;\n  }\n};\n#line 2 \"alg/monoid/add_pair.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\r\
    \n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const\
    \ X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit() { return {0,\
    \ 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"convex/slope_trick/slope_super.hpp\"\
    \n\nnamespace SLOPE_TRICK_SUPER {\n/*\n\u50BE\u304D\u3068\u5EA7\u6A19\u304C\u5168\
    \u90E8 T.\n(x0,y0,a0) / \u50BE\u304D\u5909\u5316\u3092 splay tree \u3067\u6301\
    \u3064.\n\u672B\u5C3E\u306B\u306F\u5FC5\u305A infty \u304C\u5165\u3063\u3066\u3044\
    \u308B\u3088\u3046\u306B\u3059\u308B.\n(0,10),(1,6),(3,4),(6,7)\n->\n(x0,y0,a0)=(0,10,-4)\n\
    dat = ([1,3],[3,2])\n\nf(x) \u306E\u8A08\u7B97, (min,argmin) \u306E\u8A08\u7B97\
    \n\u52A0\u6CD5, \u7573\u307F\u8FBC\u307F\n\n\u52A0\u6CD5: easy\nf(x) \u306E\u8A08\
    \u7B97: sum(a), sum(xa) \u304C\u8981\u308B\n\u7573\u307F\u8FBC\u307F: x->x+c \u304C\
    \u8981\u308B\n*/\n\ntemplate <typename T>\nstruct Node {\n  using value_type =\
    \ pair<T, T>;\n  using operator_type = T;\n  using np = Node *;\n  using Monoid_X\
    \ = Monoid_Add_Pair<T>;\n\n  np p, l, r;\n  bool rev;\n  u32 size;\n  pair<T,\
    \ T> x;    // (x,a)\n  pair<T, T> prod; // (a sum, xa sum)\n  T add_x;\n\n  static\
    \ void new_node(np n, const pair<T, T> &x) {\n    n->p = n->l = n->r = nullptr,\
    \ n->rev = 0, n->size = 1;\n    n->x = x, n->prod = {x.se, x.fi * x.se}, n->add_x\
    \ = 0;\n  }\n\n  void update() {\n    size = 1;\n    if (l) { size += l->size;\
    \ }\n    if (r) { size += r->size; }\n    prod = {x.se, x.fi * x.se};\n    if\
    \ (l) prod = Monoid_X::op(prod, l->prod);\n    if (r) prod = Monoid_X::op(prod,\
    \ r->prod);\n  }\n\n  void prop() {\n    assert(!rev);\n    if (add_x == 0) return;\n\
    \    if (l) l->x.fi += add_x, l->prod.se += l->prod.fi * add_x, l->add_x += add_x;\n\
    \    if (r) r->x.fi += add_x, r->prod.se += r->prod.fi * add_x, r->add_x += add_x;\n\
    \    add_x = 0;\n  }\n\n  void apply(T a) { x.fi += a, prod.se += a * prod.fi,\
    \ add_x += a; }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\
    \u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\
    \u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\
    \u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  pair<T, T> get() { return\
    \ x; }\n  void set(const pair<T, T> &xx) {\n    x = xx;\n    update();\n  }\n\
    };\n\n// \u95A2\u6570\u306F\u7834\u58CA\u7684\u306A\u5909\u66F4\u306B\u3055\u308C\
    \u308B\ntemplate <typename T>\nstruct Slope_Trick_Super {\n  SplayTree<Node<T>>\
    \ ST;\n  using np = Node<T> *;\n\n  struct FUNC {\n    np root; // \u5B9A\u7FA9\
    \u57DF\u304C\u3053\u308F\u308C\u3066\u3044\u305F\u3089 root == empty\n    T x0,\
    \ x1, a0, y0;\n    int size() { return (root ? root->size : 0); }\n  };\n\n  Slope_Trick_Super(int\
    \ NODES) : ST(NODES) {}\n\n  // (L,R,a,b) : [L,R] \u3067 y=ax+b\n  FUNC segment_func(T\
    \ L, T R, T a, T b) { return {nullptr, L, R, a, a * L + b}; }\n  FUNC from_points(vc<pair<T,\
    \ T>> &point) {\n    return from_points(len(point), [&](int i) -> pair<T, T> {\
    \ return point[i]; });\n  }\n  template <typename F>\n  FUNC from_points(int N,\
    \ F f) {\n    vc<T> X(N), Y(N);\n    FOR(i, N) tie(X[i], Y[i]) = f(i);\n    if\
    \ (N == 1) return segment_func(X[0], X[0], 0, Y[0]);\n    T a0 = (Y[1] - Y[0])\
    \ / (X[1] - X[0]);\n    T x0 = X[0], x1 = X.back();\n    vc<pair<T, T>> dat;\n\
    \    T a = a0;\n    FOR(i, 1, N - 1) {\n      T a1 = (Y[i + 1] - Y[i]) / (X[i\
    \ + 1] - X[i]);\n      dat.eb(X[i], a1 - a), a = a1;\n    }\n    return FUNC{ST.new_node(dat),\
    \ x0, x1, a0, Y[0]};\n  }\n\n  pair<T, T> domain(FUNC &f) { return {f.x0, f.x1};\
    \ }\n  T eval(FUNC &f, T x) {\n    auto [x0, x1] = domain(f);\n    if (!(x0 <=\
    \ x && x <= x1)) return infty<T>;\n    auto [l, r] = ST.split_max_right(f.root,\
    \ [&](auto dat) -> bool { return dat.fi <= x; });\n    auto [a_sum, xa_sum] =\
    \ ST.prod(l);\n    f.root = ST.merge(l, r);\n    return f.y0 + f.a0 * (x - x0)\
    \ + a_sum * x - xa_sum;\n  }\n  FUNC restrict_domain(FUNC &f, T L, T R) {\n  \
    \  auto [x0, x1] = domain(f);\n    chmax(L, x0), chmin(R, x1);\n    if (L > R)\
    \ {\n      ST.free_subtree(f.root), f.root = nullptr;\n      f.root = nullptr;\n\
    \      f.x0 = infty<T>, f.x1 = -infty<T>;\n      return f;\n    }\n    // \u307E\
    \u305A\u306F\u53F3\u5074\u3092\u3061\u3062\u3081\u308B. R \u4EE5\u4E0A\u306E\u50BE\
    \u304D\u5909\u5316\u3092\u6D88\u3057\u3066\u3057\u307E\u3048\u3070\u3088\u3044\
    \n    auto [l, r] = ST.split_max_right(f.root, [&](auto dat) -> bool { return\
    \ dat.fi < R; });\n    ST.free_subtree(r);\n    // \u5DE6\u5074\u3092\u3061\u3062\
    \u3081\u308B.\n    tie(l, r) = ST.split_max_right(l, [&](auto dat) -> bool { return\
    \ dat.fi <= L; });\n    auto [a_sum, xa_sum] = ST.prod(l);\n    T new_a0 = f.a0\
    \ + a_sum;\n    T new_y0 = f.y0 + f.a0 * (L - x0) + a_sum * L - xa_sum;\n    ST.free_subtree(l);\n\
    \    f.root = r, f.x0 = L, f.x1 = R, f.a0 = new_a0, f.y0 = new_y0;\n    return\
    \ f;\n  }\n  FUNC add(FUNC &f, FUNC &g) {\n    T x0 = max(f.x0, g.x0);\n    T\
    \ x1 = min(f.x1, g.x1);\n    restrict_domain(f, x0, x1), restrict_domain(g, x0,\
    \ x1);\n    if (x0 > x1) return f;\n    T y0 = f.y0 + g.y0, a0 = f.a0 + g.a0;\n\
    \n    if (len(f) < len(g)) swap(f, g);\n    auto tmp = ST.get_all(g.root);\n \
    \   ST.free_subtree(g.root);\n    f.x0 = x0, f.x1 = x1, f.a0 = a0, f.y0 = y0;\n\
    \    if (!f.root) {\n      f.root = ST.new_node(tmp);\n      return f;\n    }\n\
    \    // \u3042\u3068\u306F\u5358\u306B tmp \u3092\u633F\u5165\u3057\u3066\u3044\
    \u3051\u3070\u3044\u3044\n    auto dfs = [&](auto &dfs, np root, int l, int r)\
    \ -> void {\n      if (l == r) return;\n      root->prop();\n      T x = root->x.fi;\n\
    \      // [l,m),[m,r)\n      int m = binary_search([&](int i) -> bool { return\
    \ tmp[i].fi >= x; }, r, l - 1, 0);\n      if (l < m) {\n        if (!root->l)\
    \ {\n          root->l = ST.new_node({tmp.begin() + l, tmp.begin() + m});\n  \
    \      } else {\n          dfs(dfs, root->l, l, m);\n        }\n        root->l->p\
    \ = root;\n      }\n      if (m < r) {\n        if (!root->r) {\n          root->r\
    \ = ST.new_node({tmp.begin() + m, tmp.begin() + r});\n        } else {\n     \
    \     dfs(dfs, root->r, m, r);\n        }\n        root->r->p = root;\n      }\n\
    \      root->update();\n    };\n    dfs(dfs, f.root, 0, len(tmp));\n    return\
    \ f;\n  }\n  FUNC sum_all(vc<FUNC> &funcs) {\n    assert(len(funcs) >= 1);\n \
    \   T x0 = funcs[0].x0, x1 = funcs[0].x1;\n    for (auto &g: funcs) chmax(x0,\
    \ g.x0), chmin(x1, g.x1);\n    if (x0 > x1) {\n      for (auto &f: funcs) { ST.free_subtree(f.root);\
    \ }\n      return {nullptr, infty<T>, -infty<T>, 0, 0};\n    }\n    for (auto\
    \ &f: funcs) f = restrict_domain(f, x0, x1);\n    int idx = 0;\n    FOR(i, 1,\
    \ len(funcs)) if (len(funcs[idx]) < len(funcs[i])) idx = i;\n    swap(funcs[idx],\
    \ funcs.back());\n    FUNC f = POP(funcs);\n    vc<pair<T, T>> dat;\n    for (auto\
    \ &g: funcs) {\n      f.y0 += g.y0, f.a0 += g.a0;\n      auto tmp = ST.get_all(g.root);\n\
    \      concat(dat, tmp);\n      ST.free_subtree(g.root);\n    }\n    sort(all(dat));\n\
    \    // \u3042\u3068\u306F\u5358\u306B dat \u3092\u633F\u5165\u3057\u3066\u3044\
    \u3051\u3070\u3044\u3044\n    if (!f.root) {\n      f.root = ST.new_node(dat);\n\
    \      return f;\n    }\n    auto dfs = [&](auto &dfs, np root, int l, int r)\
    \ -> void {\n      if (l == r) return;\n      root->prop();\n      T x = root->x.fi;\n\
    \      // [l,m),[m,r)\n      int m = binary_search([&](int i) -> bool { return\
    \ dat[i].fi >= x; }, r, l - 1, 0);\n      if (l < m) {\n        if (!root->l)\
    \ {\n          root->l = ST.new_node({dat.begin() + l, dat.begin() + m});\n  \
    \      } else {\n          dfs(dfs, root->l, l, m);\n        }\n        root->l->p\
    \ = root;\n      }\n      if (m < r) {\n        if (!root->r) {\n          root->r\
    \ = ST.new_node({dat.begin() + m, dat.begin() + r});\n        } else {\n     \
    \     dfs(dfs, root->r, m, r);\n        }\n        root->r->p = root;\n      }\n\
    \      root->update();\n    };\n    dfs(dfs, f.root, 0, len(dat));\n    return\
    \ f;\n  }\n\n  FUNC shift(FUNC &f, T add_x, T add_y) {\n    ST.apply(f.root, add_x);\n\
    \    f.x0 += add_x, f.x1 += add_x, f.y0 += add_y;\n    return f;\n  }\n\n  //\
    \ h[z]=min(x+y==z)f(x)+g(y)\n  FUNC convolve(FUNC &f, FUNC &g) {\n    if (f.x0\
    \ > f.x1 || g.x0 > g.x1) { return {nullptr, infty<T>, -infty<T>, 0, 0}; }\n  \
    \  if (len(f) < len(g)) swap(f, g);\n    shift(f, g.x0, g.y0), shift(g, -g.x0,\
    \ -g.y0);\n    if (len(g) == 0) { return convolve_segment(f, 0, g.x1, g.a0, 0);\
    \ }\n    auto tmp = ST.get_all(g.root);\n    ST.free_subtree(g.root);\n    f =\
    \ convolve_segment(f, 0, tmp[0].fi, g.a0, 0);\n    T a = g.a0;\n    FOR(i, len(tmp))\
    \ {\n      T nx = (i + 1 < len(tmp) ? tmp[i + 1].fi : g.x1);\n      a += tmp[i].se;\n\
    \      f = convolve_segment(f, 0, nx - tmp[i].fi, a, 0);\n      for (auto &[x,\
    \ a]: ST.get_all(f.root)) {\n        assert(f.x0 <= x && x <= f.x1);\n       \
    \ if (f.root) assert(!f.root->p);\n      }\n    }\n    return f;\n  }\n\n  //\
    \ [x0,x1], y=ax+b\n  FUNC convolve_segment(FUNC &f, T x0, T x1, T a, T b) {\n\
    \    assert(x0 <= x1);\n    if (f.x0 > f.x1) { return {nullptr, infty<T>, -infty<T>,\
    \ 0, 0}; }\n    f = shift(f, x0, a * x0 + b);\n    T d = x1 - x0;\n    if (d ==\
    \ 0) return f;\n    // (0,0) \u304B\u3089 (x1,ax1) \u3078\u306E\u7DDA\u5206\u3092\
    \u3069\u3053\u304B\u306B\u633F\u5165\u3059\u308B\n    // \u7279\u306B x0, y0 \u306F\
    \u3053\u306E\u307E\u307E\u3067\u3088\u3044\n    if (f.x0 == f.x1) { return {nullptr,\
    \ f.x0, f.x0 + d, a, f.y0}; }\n    // \u5148\u982D\u306B\u633F\u5165\u3067\u304D\
    \u308B\u5834\u5408\n    if (a <= f.a0) {\n      ST.apply(f.root, d);\n      f.root\
    \ = ST.merge(ST.new_node({f.x0 + d, f.a0 - a}), f.root);\n      f.x1 += d, f.a0\
    \ = a;\n      return f;\n    }\n    // \u672B\u5C3E\u306B\u633F\u5165\u3067\u304D\
    \u308B\u5834\u5408\n    T a_last = f.a0 + ST.prod(f.root).fi;\n    if (a_last\
    \ <= a) {\n      f.root = ST.merge(f.root, ST.new_node({f.x1, a - a_last}));\n\
    \      f.x1 += d;\n      return f;\n    }\n    // \u9593\u306E\u3069\u3053\u304B\
    \u306B\u633F\u5165\n    auto [l, r] = ST.split_max_right_prod(f.root, [&](auto\
    \ prod) -> bool { return f.a0 + prod.fi < a; });\n    T asum = ST.prod(l).fi;\n\
    \    T a1 = a - (asum + f.a0);\n    auto [xx, aa] = ST.get(r, 0);\n    ST.apply(r,\
    \ d);\n    ST.set(r, 0, {xx + d, aa - a1});\n    f.root = ST.merge3(l, ST.new_node({xx,\
    \ a1}), r);\n    f.x1 += d;\n    return f;\n  }\n\n  FUNC add_const(FUNC &f, T\
    \ a) {\n    f.y0 += a;\n    return f;\n  }\n\n  FUNC add_linear(FUNC &f, T a,\
    \ T b) {\n    f.y0 += a * f.x0 + b;\n    f.a0 += a;\n    return f;\n  }\n\n  //\
    \ (a-x)+\n  FUNC add_a_minus_x(FUNC &f, T a) {\n    auto [x0, x1] = domain(f);\n\
    \    if (x0 > x1) return f;\n    if (a <= x0) return f;\n    if (x1 <= a) return\
    \ add_linear(f, -1, a);\n    vc<pair<T, T>> point;\n    point.eb(x0, a - x0),\
    \ point.eb(a, 0), point.eb(x1, 0);\n    FUNC g = from_points(point);\n    return\
    \ add(f, g);\n  }\n\n  // (x-a)+\n  FUNC add_x_minus_a(FUNC &f, T a) {\n    auto\
    \ [x0, x1] = domain(f);\n    if (x0 > x1) return f;\n    if (a <= x0) return add_linear(f,\
    \ 1, -a);\n    if (x1 <= a) return f;\n    vc<pair<T, T>> point;\n    point.eb(x0,\
    \ 0), point.eb(a, 0), point.eb(x1, x1 - a);\n    FUNC g = from_points(point);\n\
    \    return add(f, g);\n  }\n\n  // |x-a|\n  FUNC add_abs(FUNC &f, T a) {\n  \
    \  f = add_a_minus_x(f, a);\n    f = add_x_minus_a(f, a);\n    return f;\n  }\n\
    \n  // fx,x\n  pair<T, T> get_min(FUNC &f) {\n    if (f.x0 > f.x1) return {infty<T>,\
    \ 0};\n    if (f.a0 >= 0) { return {f.y0, f.x0}; }\n    auto [l, r] = ST.split_max_right_prod(f.root,\
    \ [&](auto prod) -> bool { return f.a0 + prod.fi < 0; });\n    auto [asum, xasum]\
    \ = ST.prod(l);\n    T x = (r ? ST.get(r, 0).fi : f.x1);\n    f.root = ST.merge(l,\
    \ r);\n    T y = f.y0 + f.a0 * (x - f.x0) + x * asum - xasum;\n    return {y,\
    \ x};\n  }\n\n  FUNC clear_right(FUNC &f) {\n    if (f.a0 >= 0) {\n      ST.free_subtree(f.root),\
    \ f.root = nullptr, f.a0 = 0;\n      return f;\n    }\n    auto [l, r] = ST.split_max_right_prod(f.root,\
    \ [&](auto prod) -> bool { return f.a0 + prod.fi < 0; });\n    f.root = l;\n \
    \   if (!r) { return f; }\n    T x = ST.get(r, 0).fi;\n    ST.free_subtree(r);\n\
    \    f.root = ST.merge(f.root, ST.new_node({x, -(f.a0 + ST.prod(l).fi)}));\n \
    \   return f;\n  }\n  FUNC clear_left(FUNC &f) {\n    if (f.a0 >= 0) { return\
    \ f; }\n    auto [l, r] = ST.split_max_right_prod(f.root, [&](auto prod) -> bool\
    \ { return f.a0 + prod.fi < 0; });\n    auto [asum, xasum] = ST.prod(l);\n   \
    \ if (!r) {\n      // \u5B9A\u6570\u306B\u3059\u308B\n      T x = f.x1;\n    \
    \  T y = f.y0 + f.a0 * (x - f.x0) + x * asum - xasum;\n      ST.free_subtree(l);\n\
    \      f.root = nullptr;\n      f.y0 = y, f.a0 = 0;\n      return f;\n    }\n\
    \    T x = ST.get(f.root, 0).fi;\n    T y = f.y0 + f.a0 * (x - f.x0) + x * asum\
    \ - xasum;\n    T a = f.a0 + asum + ST.get(r, 0).se;\n    ST.free_subtree(l);\n\
    \    f.root = r;\n    ST.set(r, 0, {x, a});\n    f.y0 = y;\n    f.a0 = 0;\n  \
    \  return f;\n  }\n#ifdef FASTIO\n  void debug(FUNC &f) {\n    auto dat = ST.get_all(f.root);\n\
    \    SHOW(f.x0, f.x1, f.a0, f.y0);\n    SHOW(dat);\n  }\n#endif\n};\n} // namespace\
    \ SLOPE_TRICK_SUPER\nusing SLOPE_TRICK_SUPER::Slope_Trick_Super;\n#line 6 \"test/1_mytest/slope_super.test.cpp\"\
    \n\nvoid test(int N, bool from_zero, int add_prob) {\n  Slope_Trick_Super<ll>\
    \ ST(N);\n  using F = typename decltype(ST)::FUNC;\n\n  vc<int> L(2 * N - 1),\
    \ R(2 * N - 1), A(N), B(N);\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n\n  FOR(i,\
    \ N) {\n    L[i] = RNG(0, 5);\n    if (from_zero) L[i] = 0;\n    R[i] = RNG(0,\
    \ 5);\n    if (L[i] > R[i]) swap(L[i], R[i]);\n    A[i] = RNG(-3, 4);\n    B[i]\
    \ = RNG(-3, 4);\n  }\n  vvc<ll> dp(2 * N - 1);\n  vc<F> func(2 * N - 1);\n  FOR(i,\
    \ N) {\n    dp[i].resize(R[i] + 1, infty<ll>);\n    FOR(x, L[i], R[i] + 1) dp[i][x]\
    \ = A[i] * x + B[i];\n    func[i] = ST.segment_func(L[i], R[i], A[i], B[i]);\n\
    \    FOR(x, L[i], R[i] + 1) {\n      ll me = ST.eval(func[i], x);\n      ll god\
    \ = dp[i][x];\n      assert(me == god);\n    }\n  }\n\n  FOR(i, N, 2 * N - 1)\
    \ {\n    shuffle(I);\n    int t = (RNG(0, 100) < add_prob ? 0 : 1);\n    int a\
    \ = POP(I), b = POP(I);\n    I.eb(i);\n    if (dp[a].empty() || dp[b].empty())\
    \ continue;\n    if (t == 0) {\n      // ADD\n      L[i] = max(L[a], L[b]);\n\
    \      R[i] = min(R[a], R[b]);\n      if (L[i] > R[i]) continue;\n      dp[i].assign(R[i]\
    \ + 1, infty<ll>);\n      FOR(x, L[i], R[i] + 1) dp[i][x] = dp[a][x] + dp[b][x];\n\
    \      func[i] = ST.add(func[a], func[b]);\n    }\n    if (t == 1) {\n      //\
    \ conv\n      L[i] = L[a] + L[b];\n      R[i] = R[a] + R[b];\n      dp[i].assign(R[i]\
    \ + 1, infty<ll>);\n      FOR(x1, L[a], R[a] + 1) {\n        FOR(x2, L[b], R[b]\
    \ + 1) { chmin(dp[i][x1 + x2], dp[a][x1] + dp[b][x2]); }\n      }\n      func[i]\
    \ = ST.convolve(func[a], func[b]);\n    }\n    vi X(R[i] + 1, infty<ll>);\n  \
    \  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);\n    assert(func[i].x0 ==\
    \ L[i]);\n    assert(func[i].x1 == R[i]);\n    assert(X == dp[i]);\n    auto [fx,\
    \ x] = ST.get_min(func[i]);\n    assert(L[i] <= x && x <= R[i]);\n    assert(MIN(X)\
    \ == fx && X[x] == fx);\n  }\n  int i = 2 * N - 2;\n  if (dp[i].empty()) return;\n\
    \  int t = RNG(0, 2);\n  if (t == 0) {\n    // clear right\n    FOR(x, L[i] +\
    \ 1, R[i] + 1) chmin(dp[i][x], dp[i][x - 1]);\n    ST.clear_right(func[i]);\n\
    \  }\n  if (t == 2) {\n    // clear left\n    FOR_R(x, L[i] + 1, R[i] + 1) chmin(dp[i][x\
    \ - 1], dp[i][x]);\n    ST.clear_left(func[i]);\n  }\n  vi X(R[i] + 1, infty<ll>);\n\
    \  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);\n  assert(func[i].x0 ==\
    \ L[i]);\n  assert(func[i].x1 == R[i]);\n  assert(X == dp[i]);\n}\n\nvoid solve()\
    \ {\n  int x, y;\n  cin >> x >> y;\n  cout << x + y << \"\\n\";\n}\n\nsigned main()\
    \ {\n  vc<int> ns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000};\n  vc<int> ps = {50,\
    \ 100, 0, 95, 5};\n  for (auto& n: ns) {\n    for (auto& p: ps) {\n      FOR(20)\
    \ {\n        test(n, false, p);\n        test(n, true, p);\n      }\n    }\n \
    \ }\n\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/shuffle.hpp\"\n#include \"convex/slope_trick/slope_super.hpp\"\
    \n\nvoid test(int N, bool from_zero, int add_prob) {\n  Slope_Trick_Super<ll>\
    \ ST(N);\n  using F = typename decltype(ST)::FUNC;\n\n  vc<int> L(2 * N - 1),\
    \ R(2 * N - 1), A(N), B(N);\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n\n  FOR(i,\
    \ N) {\n    L[i] = RNG(0, 5);\n    if (from_zero) L[i] = 0;\n    R[i] = RNG(0,\
    \ 5);\n    if (L[i] > R[i]) swap(L[i], R[i]);\n    A[i] = RNG(-3, 4);\n    B[i]\
    \ = RNG(-3, 4);\n  }\n  vvc<ll> dp(2 * N - 1);\n  vc<F> func(2 * N - 1);\n  FOR(i,\
    \ N) {\n    dp[i].resize(R[i] + 1, infty<ll>);\n    FOR(x, L[i], R[i] + 1) dp[i][x]\
    \ = A[i] * x + B[i];\n    func[i] = ST.segment_func(L[i], R[i], A[i], B[i]);\n\
    \    FOR(x, L[i], R[i] + 1) {\n      ll me = ST.eval(func[i], x);\n      ll god\
    \ = dp[i][x];\n      assert(me == god);\n    }\n  }\n\n  FOR(i, N, 2 * N - 1)\
    \ {\n    shuffle(I);\n    int t = (RNG(0, 100) < add_prob ? 0 : 1);\n    int a\
    \ = POP(I), b = POP(I);\n    I.eb(i);\n    if (dp[a].empty() || dp[b].empty())\
    \ continue;\n    if (t == 0) {\n      // ADD\n      L[i] = max(L[a], L[b]);\n\
    \      R[i] = min(R[a], R[b]);\n      if (L[i] > R[i]) continue;\n      dp[i].assign(R[i]\
    \ + 1, infty<ll>);\n      FOR(x, L[i], R[i] + 1) dp[i][x] = dp[a][x] + dp[b][x];\n\
    \      func[i] = ST.add(func[a], func[b]);\n    }\n    if (t == 1) {\n      //\
    \ conv\n      L[i] = L[a] + L[b];\n      R[i] = R[a] + R[b];\n      dp[i].assign(R[i]\
    \ + 1, infty<ll>);\n      FOR(x1, L[a], R[a] + 1) {\n        FOR(x2, L[b], R[b]\
    \ + 1) { chmin(dp[i][x1 + x2], dp[a][x1] + dp[b][x2]); }\n      }\n      func[i]\
    \ = ST.convolve(func[a], func[b]);\n    }\n    vi X(R[i] + 1, infty<ll>);\n  \
    \  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);\n    assert(func[i].x0 ==\
    \ L[i]);\n    assert(func[i].x1 == R[i]);\n    assert(X == dp[i]);\n    auto [fx,\
    \ x] = ST.get_min(func[i]);\n    assert(L[i] <= x && x <= R[i]);\n    assert(MIN(X)\
    \ == fx && X[x] == fx);\n  }\n  int i = 2 * N - 2;\n  if (dp[i].empty()) return;\n\
    \  int t = RNG(0, 2);\n  if (t == 0) {\n    // clear right\n    FOR(x, L[i] +\
    \ 1, R[i] + 1) chmin(dp[i][x], dp[i][x - 1]);\n    ST.clear_right(func[i]);\n\
    \  }\n  if (t == 2) {\n    // clear left\n    FOR_R(x, L[i] + 1, R[i] + 1) chmin(dp[i][x\
    \ - 1], dp[i][x]);\n    ST.clear_left(func[i]);\n  }\n  vi X(R[i] + 1, infty<ll>);\n\
    \  FOR(x, L[i], R[i] + 1) X[x] = ST.eval(func[i], x);\n  assert(func[i].x0 ==\
    \ L[i]);\n  assert(func[i].x1 == R[i]);\n  assert(X == dp[i]);\n}\n\nvoid solve()\
    \ {\n  int x, y;\n  cin >> x >> y;\n  cout << x + y << \"\\n\";\n}\n\nsigned main()\
    \ {\n  vc<int> ns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1000};\n  vc<int> ps = {50,\
    \ 100, 0, 95, 5};\n  for (auto& n: ns) {\n    for (auto& p: ps) {\n      FOR(20)\
    \ {\n        test(n, false, p);\n        test(n, true, p);\n      }\n    }\n \
    \ }\n\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/shuffle.hpp
  - random/base.hpp
  - convex/slope_trick/slope_super.hpp
  - ds/splaytree/splaytree.hpp
  - alg/monoid/add_pair.hpp
  isVerificationFile: true
  path: test/1_mytest/slope_super.test.cpp
  requiredBy: []
  timestamp: '2024-10-26 12:30:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/slope_super.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/slope_super.test.cpp
- /verify/test/1_mytest/slope_super.test.cpp.html
title: test/1_mytest/slope_super.test.cpp
---
