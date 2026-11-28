---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/binary_trie_compressed.hpp
    title: ds/binary_trie_compressed.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    #if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
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
    #line 1 \"ds/binary_trie_compressed.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/binary_trie_compressed.hpp\n\
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
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 3 \"ds/binary_trie_compressed.hpp\"\
    \n\n// \u975E\u6C38\u7D9A\u306A\u3089\u3070\u30012 * \u8981\u7D20\u6570 \u306E\
    \u30CE\u30FC\u30C9\u6570\ntemplate <int LOG, bool PERSISTENT, typename UINT =\
    \ u64,\n    typename SIZE_TYPE = u32>\nstruct Binary_Trie_Compressed {\n  using\
    \ T = SIZE_TYPE;\n  static_assert(is_same_v<T, u32> || is_same_v<T, u64>);\n \
    \ static_assert(0 < LOG && LOG <= numeric_limits<UINT>::digits);\n\n  struct Node\
    \ {\n    int width;\n    UINT val;\n    T cnt;\n    Node *l, *r;\n  };\n\n  Node_Pool<Node>\
    \ pool;\n  using np = Node *;\n\n  void reset() { pool.reset(); }\n\n  np new_root()\
    \ { return nullptr; }\n\n  np add(np root, UINT val, T cnt = 1) {\n    if (!root)\
    \ root = new_node(0, 0);\n    assert((val >> LOG) == 0);\n    return add_rec(root,\
    \ LOG, val, cnt);\n  }\n\n  // f(val, cnt)\n  template <typename F>\n  void enumerate(np\
    \ root, F f) {\n    bool end = false;\n    auto dfs = [&](auto &dfs, np root,\
    \ UINT val, int ht) -> void {\n      if (ht == 0) {\n        f(val, root->cnt,\
    \ end);\n        return;\n      }\n      np c = root->l;\n      if (c) {\n   \
    \     dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width));\n        if\
    \ (end) return;\n      }\n      c = root->r;\n      if (c) {\n        dfs(dfs,\
    \ c, val << (c->width) | (c->val), ht - (c->width));\n        if (end) return;\n\
    \      }\n    };\n    if (root) dfs(dfs, root, 0, LOG);\n  }\n\n  // xor_val \u3057\
    \u305F\u3042\u3068\u306E\u5024\u3067\u6607\u9806 k \u756A\u76EE\n  UINT kth(np\
    \ root, T k, UINT xor_val) {\n    assert(root && k < root->cnt);\n    return kth_rec(root,\
    \ 0, k, LOG, xor_val) ^ xor_val;\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\
    \u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np root, UINT xor_val) {\n  \
    \  assert(root && root->cnt);\n    return kth(root, 0, xor_val);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5927\u5024\n  UINT\
    \ max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ (root->cnt) - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\
    \u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\
    \n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root) return\
    \ 0;\n    return prefix_count_rec(root, LOG, upper, xor_val, 0);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [lo, hi) \u5185\u306B\u5165\
    \u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np root, UINT lo, UINT hi, UINT\
    \ xor_val) {\n    return prefix_count(root, hi, xor_val) - prefix_count(root,\
    \ lo, xor_val);\n  }\n\n private:\n  inline UINT mask(int k) { return UINT(full_mask(k));\
    \ }\n\n  np new_node(int width, UINT val) {\n    np c = pool.create();\n    c->l\
    \ = c->r = nullptr;\n    c->width = width, c->val = val, c->cnt = 0;\n    return\
    \ c;\n  }\n\n  np clone(np c) {\n    if (!c || !PERSISTENT) return c;\n    return\
    \ pool.clone(c);\n  }\n\n  np add_rec(np root, int ht, UINT val, T cnt) {\n  \
    \  root = clone(root);\n    root->cnt += cnt;\n    if (ht == 0) return root;\n\
    \n    bool go_r = (val >> (ht - 1)) & 1;\n    np c = (go_r ? root->r : root->l);\n\
    \    if (!c) {\n      c = new_node(ht, val);\n      c->cnt = cnt;\n      if (!go_r)\
    \ root->l = c;\n      if (go_r) root->r = c;\n      return root;\n    }\n    int\
    \ w = c->width;\n    if ((val >> (ht - w)) == c->val) {\n      c = add_rec(c,\
    \ ht - w, val & mask(ht - w), cnt);\n      if (!go_r) root->l = c;\n      if (go_r)\
    \ root->r = c;\n      return root;\n    }\n    int same = w - 1 - topbit((val\
    \ >> (ht - w)) ^ (c->val));\n    np n = new_node(same, (c->val) >> (w - same));\n\
    \    n->cnt = c->cnt + cnt;\n    c = clone(c);\n    c->width = w - same;\n   \
    \ c->val = c->val & mask(w - same);\n    if ((val >> (ht - same - 1)) & 1) {\n\
    \      n->l = c;\n      n->r = new_node(ht - same, val & mask(ht - same));\n \
    \     n->r->cnt = cnt;\n    } else {\n      n->r = c;\n      n->l = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->l->cnt = cnt;\n    }\n    if (!go_r)\
    \ root->l = n;\n    if (go_r) root->r = n;\n    return root;\n  }\n\n  UINT kth_rec(np\
    \ root, UINT val, T k, int ht, UINT xor_val) {\n    if (ht == 0) return val;\n\
    \    np left = root->l, right = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left,\
    \ right);\n    T sl = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) {\n\
    \      c = left;\n    }\n    if (k >= sl) {\n      c = right, k -= sl;\n    }\n\
    \    int w = c->width;\n    return kth_rec(c, val << w | (c->val), k, ht - w,\
    \ xor_val);\n  }\n\n  T prefix_count_rec(np root, int ht, UINT LIM, UINT xor_val,\
    \ UINT val) {\n    UINT now = (val << ht) ^ (xor_val);\n    if ((LIM >> ht) >\
    \ (now >> ht)) return root->cnt;\n    if (ht == 0 || (LIM >> ht) < (now >> ht))\
    \ return 0;\n    T res = 0;\n    FOR(k, 2) {\n      np c = (k == 0 ? root->l :\
    \ root->r);\n      if (c) {\n        int w = c->width;\n        res += prefix_count_rec(c,\
    \ ht - w, LIM, xor_val, val << w | c->val);\n      }\n    }\n    return res;\n\
    \  }\n};\n#line 3 \"test/5_ai_generated_test/binary_trie_compressed_split.test.cpp\"\
    \n\n// \u5727\u7E2E\u8FBA\u306E\u518D\u5206\u5272\u3068\u91CD\u8907\u8FFD\u52A0\
    \u3092\u3001\u56FA\u5B9Aseed\u306E\u5C0F\u3055\u3044\u6574\u6570\u591A\u91CD\u96C6\
    \u5408\u3067\u7167\u5408\u3002\n// LOG=6 \u306B\u9650\u5B9A\u3059\u308B\u3002\u6C38\
    \u7D9A\u7248\u306F\u53E4\u3044root\u304B\u3089\u3082\u5206\u5C90\u3055\u305B\u3001\
    \u4FDD\u5B58\u6642\u306E\u5024\u3092\u6BD4\u8F03\u3059\u308B\u3002\n// \u56FA\u5B9A\
    \u4F8B\u306E0\u30681\u306F\u4E0A\u4F4D5bit\u3092\u5171\u6709\u3057\u30012\u56DE\
    \u76EE\u306Eadd\u3067mask()\u3092\u901A\u308B\u3002\n\ntemplate<bool Persistent>\n\
    void check() {\n  using Trie = Binary_Trie_Compressed<6, Persistent>;\n  Trie\
    \ t;\n  using NP = typename Trie::np;\n  vc<NP> roots{t.new_root()};\n  vc<vc<u64>>\
    \ history(1);\n  mt19937 rng(0x4bc4b5);\n  for (int step = 0; step < 450; ++step)\
    \ {\n    int prev = len(roots) - 1;\n    if constexpr (Persistent) if (step >=\
    \ 3 && step % 3 == 0) prev = rng() % roots.size();\n    u64 x = step < 3 ? step\
    \ % 2 : rng() % 64;\n    u32 n = 1 + (step < 3 ? 0 : rng() % 4);\n    auto expected\
    \ = history[prev];\n    expected.insert(expected.end(), n, x);\n    roots.push_back(t.add(roots[prev],\
    \ x, n));\n    history.push_back(expected);\n    auto verify = [&](int ver, u64\
    \ key) {\n      const auto& seq = history[ver];\n      vc<u64> sorted;\n     \
    \ for (u64 y : seq) sorted.push_back(y ^ key);\n      sort(sorted.begin(), sorted.end());\n\
    \      NP root = roots[ver];\n      for (u32 k = 0; k < sorted.size(); ++k) assert(t.kth(root,\
    \ k, key) == sorted[k]);\n      for (u64 hi = 0; hi <= 64; ++hi) {\n        auto\
    \ expected_count = lower_bound(sorted.begin(), sorted.end(), hi) - sorted.begin();\n\
    \        assert(t.prefix_count(root, hi, key) == expected_count);\n      }\n \
    \     vc<u64> got;\n      t.enumerate(root, [&](u64 y, u32 cnt, bool&) { got.insert(got.end(),\
    \ cnt, y); });\n      auto want = seq;\n      sort(want.begin(), want.end());\n\
    \      assert(got == want);\n    };\n    verify(len(roots) - 1, rng() % 64);\n\
    \    if constexpr (Persistent) verify(rng() % roots.size(), rng() % 64);\n  }\n\
    }\n\nint main() {\n  check<false>();\n  check<true>();\n  cout << \"compressed\
    \ binary trie: 900 updates passed\\n\";\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"ds/binary_trie_compressed.hpp\"\n\
    \n// \u5727\u7E2E\u8FBA\u306E\u518D\u5206\u5272\u3068\u91CD\u8907\u8FFD\u52A0\u3092\
    \u3001\u56FA\u5B9Aseed\u306E\u5C0F\u3055\u3044\u6574\u6570\u591A\u91CD\u96C6\u5408\
    \u3067\u7167\u5408\u3002\n// LOG=6 \u306B\u9650\u5B9A\u3059\u308B\u3002\u6C38\u7D9A\
    \u7248\u306F\u53E4\u3044root\u304B\u3089\u3082\u5206\u5C90\u3055\u305B\u3001\u4FDD\
    \u5B58\u6642\u306E\u5024\u3092\u6BD4\u8F03\u3059\u308B\u3002\n// \u56FA\u5B9A\u4F8B\
    \u306E0\u30681\u306F\u4E0A\u4F4D5bit\u3092\u5171\u6709\u3057\u30012\u56DE\u76EE\
    \u306Eadd\u3067mask()\u3092\u901A\u308B\u3002\n\ntemplate<bool Persistent>\nvoid\
    \ check() {\n  using Trie = Binary_Trie_Compressed<6, Persistent>;\n  Trie t;\n\
    \  using NP = typename Trie::np;\n  vc<NP> roots{t.new_root()};\n  vc<vc<u64>>\
    \ history(1);\n  mt19937 rng(0x4bc4b5);\n  for (int step = 0; step < 450; ++step)\
    \ {\n    int prev = len(roots) - 1;\n    if constexpr (Persistent) if (step >=\
    \ 3 && step % 3 == 0) prev = rng() % roots.size();\n    u64 x = step < 3 ? step\
    \ % 2 : rng() % 64;\n    u32 n = 1 + (step < 3 ? 0 : rng() % 4);\n    auto expected\
    \ = history[prev];\n    expected.insert(expected.end(), n, x);\n    roots.push_back(t.add(roots[prev],\
    \ x, n));\n    history.push_back(expected);\n    auto verify = [&](int ver, u64\
    \ key) {\n      const auto& seq = history[ver];\n      vc<u64> sorted;\n     \
    \ for (u64 y : seq) sorted.push_back(y ^ key);\n      sort(sorted.begin(), sorted.end());\n\
    \      NP root = roots[ver];\n      for (u32 k = 0; k < sorted.size(); ++k) assert(t.kth(root,\
    \ k, key) == sorted[k]);\n      for (u64 hi = 0; hi <= 64; ++hi) {\n        auto\
    \ expected_count = lower_bound(sorted.begin(), sorted.end(), hi) - sorted.begin();\n\
    \        assert(t.prefix_count(root, hi, key) == expected_count);\n      }\n \
    \     vc<u64> got;\n      t.enumerate(root, [&](u64 y, u32 cnt, bool&) { got.insert(got.end(),\
    \ cnt, y); });\n      auto want = seq;\n      sort(want.begin(), want.end());\n\
    \      assert(got == want);\n    };\n    verify(len(roots) - 1, rng() % 64);\n\
    \    if constexpr (Persistent) verify(rng() % roots.size(), rng() % 64);\n  }\n\
    }\n\nint main() {\n  check<false>();\n  check<true>();\n  cout << \"compressed\
    \ binary trie: 900 updates passed\\n\";\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/binary_trie_compressed.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/binary_trie_compressed_split.test.cpp
  requiredBy: []
  timestamp: '2026-11-29 04:16:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/binary_trie_compressed_split.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/binary_trie_compressed_split.test.cpp
- /verify/test/5_ai_generated_test/binary_trie_compressed_split.test.cpp.html
title: test/5_ai_generated_test/binary_trie_compressed_split.test.cpp
---
