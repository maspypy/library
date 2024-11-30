---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/binary_trie.hpp
    title: ds/binary_trie.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/1_mytest/binary_trie.test.cpp\"\n#define PROBLEM \"\
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
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 1 \"ds/binary_trie.hpp\"\
    \n// \u975E\u6C38\u7D9A\u306A\u3089\u3070\u30012 * \u8981\u7D20\u6570 \u306E\u30CE\
    \u30FC\u30C9\u6570\ntemplate <int LOG, bool PERSISTENT, int NODES, typename UINT\
    \ = u64,\n          typename SIZE_TYPE = int>\nstruct Binary_Trie {\n  using T\
    \ = SIZE_TYPE;\n  struct Node {\n    int width;\n    UINT val;\n    T cnt;\n \
    \   Node *l, *r;\n  };\n\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n\
    \  Binary_Trie() : pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid\
    \ = 0; }\n\n  np new_root() { return nullptr; }\n\n  np add(np root, UINT val,\
    \ T cnt = 1) {\n    if (!root) root = new_node(0, 0);\n    assert(0 <= val &&\
    \ val < (1LL << LOG));\n    return add_rec(root, LOG, val, cnt);\n  }\n\n  //\
    \ f(val, cnt)\n  template <typename F>\n  void enumerate(np root, F f) {\n   \
    \ auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void {\n      if (ht\
    \ == 0) {\n        f(val, root->cnt);\n        return;\n      }\n      np c =\
    \ root->l;\n      if (c) { dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width));\
    \ }\n      c = root->r;\n      if (c) { dfs(dfs, c, val << (c->width) | (c->val),\
    \ ht - (c->width)); }\n    };\n    if (root) dfs(dfs, root, 0, LOG);\n  }\n\n\
    \  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6607\u9806 k \u756A\u76EE\
    \n  UINT kth(np root, T k, UINT xor_val) {\n    assert(root && 0 <= k && k < root->cnt);\n\
    \    return kth_rec(root, 0, k, LOG, xor_val) ^ xor_val;\n  }\n\n  // xor_val\
    \ \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np\
    \ root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ 0, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\
    \u6700\u5927\u5024\n  UINT max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n\
    \    return kth(root, (root->cnt) - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\
    \u3042\u3068\u306E\u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\
    \u306E\u500B\u6570\n  T prefix_count(np root, UINT upper, UINT xor_val) {\n  \
    \  if (!root) return 0;\n    return prefix_count_rec(root, LOG, upper, xor_val,\
    \ 0);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [lo, hi)\
    \ \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np root, UINT\
    \ lo, UINT hi, UINT xor_val) {\n    return prefix_count(root, hi, xor_val) - prefix_count(root,\
    \ lo, xor_val);\n  }\n\nprivate:\n  inline UINT mask(int k) { return (UINT(1)\
    \ << k) - 1; }\n\n  np new_node(int width, UINT val) {\n    pool[pid].l = pool[pid].r\
    \ = nullptr;\n    pool[pid].width = width;\n    pool[pid].val = val;\n    pool[pid].cnt\
    \ = 0;\n    return &(pool[pid++]);\n  }\n\n  np copy_node(np c) {\n    if (!c\
    \ || !PERSISTENT) return c;\n    np res = &(pool[pid++]);\n    res->width = c->width,\
    \ res->val = c->val;\n    res->cnt = c->cnt, res->l = c->l, res->r = c->r;\n \
    \   return res;\n  }\n\n  np add_rec(np root, int ht, UINT val, T cnt) {\n   \
    \ root = copy_node(root);\n    root->cnt += cnt;\n    if (ht == 0) return root;\n\
    \n    bool go_r = (val >> (ht - 1)) & 1;\n    np c = (go_r ? root->r : root->l);\n\
    \    if (!c) {\n      c = new_node(ht, val);\n      c->cnt = cnt;\n      if (!go_r)\
    \ root->l = c;\n      if (go_r) root->r = c;\n      return root;\n    }\n    int\
    \ w = c->width;\n    if ((val >> (ht - w)) == c->val) {\n      c = add_rec(c,\
    \ ht - w, val & mask(ht - w), cnt);\n      if (!go_r) root->l = c;\n      if (go_r)\
    \ root->r = c;\n      return root;\n    }\n    int same = w - 1 - topbit((val\
    \ >> (ht - w)) ^ (c->val));\n    np n = new_node(same, (c->val) >> (w - same));\n\
    \    n->cnt = c->cnt + cnt;\n    c = copy_node(c);\n    c->width = w - same;\n\
    \    c->val = c->val & mask(w - same);\n    if ((val >> (ht - same - 1)) & 1)\
    \ {\n      n->l = c;\n      n->r = new_node(ht - same, val & mask(ht - same));\n\
    \      n->r->cnt = cnt;\n    } else {\n      n->r = c;\n      n->l = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->l->cnt = cnt;\n    }\n    if (!go_r)\
    \ root->l = n;\n    if (go_r) root->r = n;\n    return root;\n  }\n\n  UINT kth_rec(np\
    \ root, UINT val, T k, int ht, UINT xor_val) {\n    if (ht == 0) return val;\n\
    \    np left = root->l, right = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left,\
    \ right);\n    T sl = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) { c\
    \ = left; }\n    if (k >= sl) { c = right, k -= sl; }\n    int w = c->width;\n\
    \    return kth_rec(c, val << w | (c->val), k, ht - w, xor_val);\n  }\n\n  T prefix_count_rec(np\
    \ root, int ht, UINT LIM, UINT xor_val, UINT val) {\n    UINT now = (val << ht)\
    \ ^ (xor_val);\n    if ((LIM >> ht) > (now >> ht)) return root->cnt;\n    if (ht\
    \ == 0 || (LIM >> ht) < (now >> ht)) return 0;\n    T res = 0;\n    FOR(k, 2)\
    \ {\n      np c = (k == 0 ? root->l : root->r);\n      if (c) {\n        int w\
    \ = c->width;\n        res += prefix_count_rec(c, ht - w, LIM, xor_val, val <<\
    \ w | c->val);\n      }\n    }\n    return res;\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 5 \"test/1_mytest/binary_trie.test.cpp\"\n\nvoid\
    \ test() {\n  const int LOG = 5;\n  Binary_Trie<LOG, false, 100> X;\n\n  FOR(100)\
    \ {\n    vector<int> A;\n    X.reset();\n    auto root = X.new_root();\n    FOR(1000)\
    \ {\n      int t = RNG(0, 5);\n      if (t == 0) { // add\n        int x = RNG(0,\
    \ 1 << LOG);\n        A.eb(x);\n        root = X.add(root, x);\n      }\n    \
    \  if (t == 1) { // get all\n        sort(all(A));\n        vc<int> B;\n     \
    \   X.enumerate(root, [&](int k, int cnt) -> void { FOR(cnt) B.eb(k); });\n  \
    \      assert(A == B);\n      }\n      if (t == 2 && len(A)) { // erase\n    \
    \    int k = RNG(len(A));\n        int x = A[k];\n        swap(A[k], A.back());\n\
    \        A.pop_back();\n        X.add(root, x, -1);\n      }\n      if (t == 3\
    \ && len(A)) { // kth\n        int k = RNG(len(A));\n        int xor_val = RNG(0,\
    \ 1 << LOG);\n        vc<int> B;\n        for (auto&& x: A) B.eb(x ^ xor_val);\n\
    \        sort(all(B));\n        assert(B[k] == int(X.kth(root, k, xor_val)));\n\
    \      }\n      if (t == 4) { // freq\n        int lo = RNG(0, 1 << LOG);\n  \
    \      int hi = RNG(0, 1 << LOG);\n        int xor_val = RNG(0, 1 << LOG);\n \
    \       if (lo > hi) swap(lo, hi);\n        ++hi;\n        int cnt = 0;\n    \
    \    for (auto&& x: A) {\n          int y = x ^ xor_val;\n          if (lo <=\
    \ y && y < hi) ++cnt;\n        }\n        assert(cnt == X.count(root, lo, hi,\
    \ xor_val));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"ds/binary_trie.hpp\"\n#include \"random/base.hpp\"\n\nvoid test()\
    \ {\n  const int LOG = 5;\n  Binary_Trie<LOG, false, 100> X;\n\n  FOR(100) {\n\
    \    vector<int> A;\n    X.reset();\n    auto root = X.new_root();\n    FOR(1000)\
    \ {\n      int t = RNG(0, 5);\n      if (t == 0) { // add\n        int x = RNG(0,\
    \ 1 << LOG);\n        A.eb(x);\n        root = X.add(root, x);\n      }\n    \
    \  if (t == 1) { // get all\n        sort(all(A));\n        vc<int> B;\n     \
    \   X.enumerate(root, [&](int k, int cnt) -> void { FOR(cnt) B.eb(k); });\n  \
    \      assert(A == B);\n      }\n      if (t == 2 && len(A)) { // erase\n    \
    \    int k = RNG(len(A));\n        int x = A[k];\n        swap(A[k], A.back());\n\
    \        A.pop_back();\n        X.add(root, x, -1);\n      }\n      if (t == 3\
    \ && len(A)) { // kth\n        int k = RNG(len(A));\n        int xor_val = RNG(0,\
    \ 1 << LOG);\n        vc<int> B;\n        for (auto&& x: A) B.eb(x ^ xor_val);\n\
    \        sort(all(B));\n        assert(B[k] == int(X.kth(root, k, xor_val)));\n\
    \      }\n      if (t == 4) { // freq\n        int lo = RNG(0, 1 << LOG);\n  \
    \      int hi = RNG(0, 1 << LOG);\n        int xor_val = RNG(0, 1 << LOG);\n \
    \       if (lo > hi) swap(lo, hi);\n        ++hi;\n        int cnt = 0;\n    \
    \    for (auto&& x: A) {\n          int y = x ^ xor_val;\n          if (lo <=\
    \ y && y < hi) ++cnt;\n        }\n        assert(cnt == X.count(root, lo, hi,\
    \ xor_val));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/binary_trie.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/binary_trie.test.cpp
- /verify/test/1_mytest/binary_trie.test.cpp.html
title: test/1_mytest/binary_trie.test.cpp
---
