---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':question:'
    path: ds/sortable_array.hpp
    title: ds/sortable_array.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/sortable_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n\
    #if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/sortable_array.test.cpp\"\
    \n\n#line 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63) * u64\r\
    \nstruct FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64>\
    \ seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  int size()\
    \ { return n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n, F f) {\r\n\
    \    build(n, f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\n\
    \    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n\
    \      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n\
    \  }\r\n  template <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\
    \n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log -\
    \ 1) {\r\n      FOR(i, len(seg[h])) { seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B); }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const { return\
    \ seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    assert(0 <=\
    \ i && i < n);\r\n    for (int h = 0; h < log; h++) { seg[h][i / B] |= u64(1)\
    \ << (i % B), i /= B; }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int\
    \ i) {\r\n    assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0;\
    \ h < log; h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i\
    \ / B] |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n\
    \    }\r\n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\
    \n  int next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int\
    \ h = 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n     \
    \ u64 d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B +\
    \ 1;\r\n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int\
    \ g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i\
    \ / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n\
    \  // max [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if\
    \ (i >= n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i ==\
    \ -1) break;\r\n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d)\
    \ {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  string to_string() {\r\n    string s(n, '?');\r\n    for (int i = 0; i < n;\
    \ ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n};\n#line 1\
    \ \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool {\n  struct Slot\
    \ {\n    union alignas(Node) {\n      Slot* next;\n      unsigned char storage[sizeof(Node)];\n\
    \    };\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 <<\
    \ 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur = nullptr;\n  int cur_used\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool() { alloc_chunk(); }\n\n \
    \ template <class... Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(forward<Args>(args)...);\n  }\n\n  np clone(const np\
    \ x) {\n    assert(x);\n    Slot* s = new_slot();\n    return ::new (s) Node(*x);\
    \  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u547C\u3073\
    \u51FA\u3057\n  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n\
    \    auto s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head\
    \ = s;\n  }\n\n  void reset() {\n    free_head = nullptr;\n    if (!chunks.empty())\
    \ {\n      cur = chunks[0].get();\n      cur_used = 0;\n    }\n  }\n\n private:\n\
    \  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 3 \"ds/sortable_array.hpp\"\n\n// int \u5217\
    \u3092\u6271\u3046. key \u306E\u91CD\u8907\u53EF.\nstruct Sortable_Array {\n \
    \ const int N, KEY_MAX;\n\n  struct Node {\n    int size;\n    Node *l, *r;\n\
    \  };\n  Node_Pool<Node> pool;\n  using np = Node*;\n\n  FastSet ss;       //\
    \ \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n  vector<np>\
    \ root;  // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree \u306E node\
    \ \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_Array(int NODES,\
    \ int KEY_MAX, vector<int> key)\n      : N(key.size()), KEY_MAX(KEY_MAX), ss(key.size())\
    \ {\n    init(key);\n  }\n\n  void set(int i, int key) {\n    assert(0 <= key\
    \ && key < KEY_MAX);\n    split_at(i), split_at(i + 1);\n    rev[i] = 0, root[i]\
    \ = new_node(0);\n    set_rec(root[i], 0, KEY_MAX, key);\n  }\n\n  void sort_inc(int\
    \ l, int r) {\n    if (l == r) return;\n    split_at(l), split_at(r);\n    while\
    \ (1) {\n      np c = root[l];\n      int i = ss.next(l + 1);\n      if (i ==\
    \ r) break;\n      root[l] = merge(0, KEY_MAX, c, root[i]);\n      ss.erase(i);\n\
    \    }\n    rev[l] = 0;\n  };\n\n  void sort_dec(int l, int r) {\n    if (l ==\
    \ r) return;\n    sort_inc(l, r), rev[l] = 1;\n  };\n\n  vc<int> get_all() {\n\
    \    vector<int> key;\n    key.reserve(N);\n    auto dfs = [&](auto& dfs, np n,\
    \ int l, int r, bool rev) -> void {\n      if (!n || !n->size) return;\n     \
    \ if (r == l + 1) {\n        FOR(n->size) key.eb(l);\n        return;\n      }\n\
    \      int m = (l + r) / 2;\n      if (!rev) {\n        dfs(dfs, n->l, l, m, rev),\
    \ dfs(dfs, n->r, m, r, rev);\n      }\n      if (rev) {\n        dfs(dfs, n->r,\
    \ m, r, rev), dfs(dfs, n->l, l, m, rev);\n      }\n    };\n    for (int i = 0;\
    \ i < N; ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n   \
    \ }\n    return key;\n  }\n\n  int get(int idx) {\n    auto dfs = [&](auto& dfs,\
    \ np n, int l, int r, int k) -> int {\n      if (r == l + 1) {\n        return\
    \ l;\n      }\n      int m = (l + r) / 2;\n      int s = (n->l ? n->l->size :\
    \ 0);\n      if (k < s) return dfs(dfs, n->l, l, m, k);\n      return dfs(dfs,\
    \ n->r, m, r, k - s);\n    };\n    int i = ss.prev(idx);\n    int k = idx - i;\n\
    \    int s = root[i]->size;\n    if (rev[i]) k = s - 1 - k;\n    return dfs(dfs,\
    \ root[i], 0, KEY_MAX, k);\n  }\n\n private:\n  void init(vector<int>& key) {\n\
    \    rev.assign(N, 0), root.clear(), root.reserve(N);\n    ss.build(N, [&](int\
    \ i) -> int { return 1; });\n    for (int i = 0; i < N; ++i) {\n      root.eb(new_node(0));\n\
    \      assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);\n      root[a] = nl,\
    \ root[x] = nr;\n      rev[a] = rev[x] = 0;\n    } else {\n      auto [nl, nr]\
    \ = split(root[a], 0, KEY_MAX, b - x);\n      root[a] = nr, root[x] = nl;\n  \
    \    rev[a] = rev[x] = 1;\n    }\n  }\n\n  void rebuild() {\n    auto key = get_all();\n\
    \    pool.reset();\n    init(key);\n  }\n\n  np new_node(int size) {\n    np c\
    \ = pool.create();\n    c->l = c->r = nullptr, c->size = size;\n    return c;\n\
    \  }\n\n  pair<np, np> split(np n, int l, int r, int k) {\n    if (k == 0) {\n\
    \      return {nullptr, n};\n    }\n    if (k == n->size) {\n      return {n,\
    \ nullptr};\n    }\n    if (r == l + 1) {\n      int s = n->size;\n      n->size\
    \ = k;\n      Node* b = new_node(s - k);\n      return {n, b};\n    }\n    int\
    \ s = (n->l ? n->l->size : 0);\n    Node* b = new_node(0);\n    int m = (l + r)\
    \ / 2;\n    if (k <= s) {\n      auto [nl, nr] = split(n->l, l, m, k);\n     \
    \ b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n    }\n    if (k > s) {\n\
    \      auto [nl, nr] = split(n->r, m, r, k - s);\n      n->l = n->l, n->r = nl,\
    \ b->l = nullptr, b->r = nr;\n    }\n    update(n), update(b);\n    return {n,\
    \ b};\n  }\n\n  np merge(int l, int r, np a, np b) {\n    if (!a) return b;\n\
    \    if (!b) return a;\n    if (r == l + 1) {\n      a->size += b->size;\n   \
    \   return a;\n    }\n    int m = (l + r) / 2;\n    a->l = merge(l, m, a->l, b->l),\
    \ a->r = merge(m, r, a->r, b->r);\n    update(a);\n    return a;\n  }\n\n  void\
    \ update(np n) {\n    if (!(n->l) && !(n->r)) {\n      return;\n    }\n    if\
    \ (!(n->l)) {\n      n->size = n->r->size;\n      return;\n    }\n    if (!(n->r))\
    \ {\n      n->size = n->l->size;\n      return;\n    }\n    n->size = n->l->size\
    \ + n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k) {\n    if (r\
    \ == l + 1) {\n      n->size = 1;\n      return;\n    }\n    int m = (l + r) /\
    \ 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node(0);\n      set_rec(n->l,\
    \ l, m, k);\n    }\n    if (m <= k) {\n      if (!(n->r)) n->r = new_node(0);\n\
    \      set_rec(n->r, m, r, k);\n    }\n    update(n);\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/sortable_array.test.cpp\"\n\n\
    void test() {\n  int N = RNG(1, 64);\n  int MAX = RNG(2, 20);\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(MAX);\n  Sortable_Array X(1000, MAX, A);\n\n  int Q =\
    \ 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n    if (t == 0) {\n      vc<int>\
    \ B = X.get_all();\n      assert(A == B);\n    }\n    if (t == 0) {\n      int\
    \ idx = RNG(0, N);\n      assert(A[idx] == X.get(idx));\n    }\n    if (t == 2)\
    \ {\n      int idx = RNG(0, N);\n      int x = RNG(MAX);\n      A[idx] = x;\n\
    \      X.set(idx, x);\n    }\n    if (t == 3) {\n      int L = RNG(0, N);\n  \
    \    int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n      X.sort_inc(L,\
    \ R);\n      sort(A.begin() + L, A.begin() + R);\n    }\n    if (t == 4) {\n \
    \     int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n\
    \      ++R;\n      X.sort_dec(L, R);\n      sort(A.begin() + L, A.begin() + R);\n\
    \      reverse(A.begin() + L, A.begin() + R);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(100) test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"ds/sortable_array.hpp\"\n#include \"random/base.hpp\"\
    \n\nvoid test() {\n  int N = RNG(1, 64);\n  int MAX = RNG(2, 20);\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(MAX);\n  Sortable_Array X(1000, MAX, A);\n\n  int Q =\
    \ 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n    if (t == 0) {\n      vc<int>\
    \ B = X.get_all();\n      assert(A == B);\n    }\n    if (t == 0) {\n      int\
    \ idx = RNG(0, N);\n      assert(A[idx] == X.get(idx));\n    }\n    if (t == 2)\
    \ {\n      int idx = RNG(0, N);\n      int x = RNG(MAX);\n      A[idx] = x;\n\
    \      X.set(idx, x);\n    }\n    if (t == 3) {\n      int L = RNG(0, N);\n  \
    \    int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n      X.sort_inc(L,\
    \ R);\n      sort(A.begin() + L, A.begin() + R);\n    }\n    if (t == 4) {\n \
    \     int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n\
    \      ++R;\n      X.sort_dec(L, R);\n      sort(A.begin() + L, A.begin() + R);\n\
    \      reverse(A.begin() + L, A.begin() + R);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(100) test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - ds/sortable_array.hpp
  - ds/fastset.hpp
  - ds/node_pool.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/sortable_array.test.cpp
  requiredBy: []
  timestamp: '2025-09-16 20:23:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/sortable_array.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/sortable_array.test.cpp
- /verify/test/1_mytest/sortable_array.test.cpp.html
title: test/1_mytest/sortable_array.test.cpp
---
