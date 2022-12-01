---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':x:'
    path: ds/splay/splaytree.hpp
    title: ds/splay/splaytree.hpp
  - icon: ':x:'
    path: ds/splay/splaytree_acted_set.hpp
    title: ds/splay/splaytree_acted_set.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
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
  bundledCode: "#line 1 \"test/mytest/cf702_F_splay.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#pragma\
    \ GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing pi =\
    \ pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\nusing vc\
    \ = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define FOR4_R(i,\
    \ a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))\n#define overload4(a, b, c,\
    \ d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) \\\n  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) &\
    \ s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x\
    \ == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT pick(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\n\ntemplate <typename\
    \ T>\nT pick(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    \ntemplate <typename T>\nT pick(pqg<T> &que) {\n  assert(que.size());\n  T a =\
    \ que.top();\n  que.pop();\n  return a;\n}\n\ntemplate <typename T>\nT pick(vc<T>\
    \ &que) {\n  assert(que.size());\n  T a = que.back();\n  que.pop_back();\n  return\
    \ a;\n}\n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n  return (x\
    \ > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T, typename U>\nT floor(T\
    \ x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q = floor(x, y);\n  return\
    \ {q, x - q * y};\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok,\
    \ ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng\
    \ + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return\
    \ ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng)\
    \ / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b)\
    \ {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename\
    \ T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\n// stable\ntemplate <typename T>\nvector<int>\
    \ argsort(const vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(I);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n}\n#line 1\
    \ \"other/io.hpp\"\nnamespace fastio { // https://nyaannyaan.github.io/library/misc/fastio.hpp\r\
    \nstatic constexpr int SZ = 1 << 17;\r\nchar inbuf[SZ], outbuf[SZ];\r\nint in_left\
    \ = 0, in_right = 0, out_right = 0;\r\n\r\nstruct Pre {\r\n  char num[40000];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i * 4 +\
    \ j] = n % 10 + '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\ninline void load() {\r\n  int len = in_right - in_left;\r\n  memmove(inbuf,\
    \ inbuf + in_left, len);\r\n  in_right = len + fread(inbuf + len, 1, SZ - len,\
    \ stdin);\r\n  in_left = 0;\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(outbuf,\
    \ 1, out_right, stdout);\r\n  out_right = 0;\r\n}\r\n\r\ninline void skip_space()\
    \ {\r\n  if (in_left + 32 > in_right) load();\r\n  while (inbuf[in_left] <= '\
    \ ') in_left++;\r\n}\r\n\r\ninline void read(char &c) {\r\n  if (in_left + 32\
    \ > in_right) load();\r\n  c = inbuf[in_left++];\r\n}\r\ntemplate <typename T>\r\
    \ninline void read(T &x) {\r\n  if (in_left + 32 > in_right) load();\r\n  char\
    \ c;\r\n  do\r\n    c = inbuf[in_left++];\r\n  while (c < '-');\r\n  [[maybe_unused]]\
    \ bool minus = false;\r\n  if constexpr (is_signed<T>::value == true) {\r\n  \
    \  if (c == '-') minus = true, c = inbuf[in_left++];\r\n  }\r\n  x = 0;\r\n  while\
    \ (c >= '0') {\r\n    x = x * 10 + (c & 15);\r\n    c = inbuf[in_left++];\r\n\
    \  }\r\n  if constexpr (is_signed<T>::value == true) {\r\n    if (minus) x = -x;\r\
    \n  }\r\n}\r\ninline void read() {}\r\ntemplate <typename Head, typename... Tail>\r\
    \ninline void read(Head &head, Tail &... tail) {\r\n  read(head);\r\n  read(tail...);\r\
    \n}\r\n\r\ninline void write(char c) {\r\n  if (out_right > SZ - 32) flush();\r\
    \n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool b) {\r\n  if (out_right\
    \ > SZ - 32) flush();\r\n  outbuf[out_right++] = b ? '1' : '0';\r\n}\r\ninline\
    \ void write(const string &s) {\r\n  if (out_right + s.size() > SZ - 32) flush();\r\
    \n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\r\n  out_right\
    \ += s.size();\r\n}\r\ntemplate <typename T>\r\ninline void write(T x) {\r\n \
    \ if (out_right > SZ - 32) flush();\r\n  if (!x) {\r\n    outbuf[out_right++]\
    \ = '0';\r\n    return;\r\n  }\r\n  if constexpr (is_signed<T>::value == true)\
    \ {\r\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\r\n  }\r\n  int i = 12;\r\
    \n  char buf[16];\r\n  while (x >= 10000) {\r\n    memcpy(buf + i, pre.num + (x\
    \ % 10000) * 4, 4);\r\n    x /= 10000;\r\n    i -= 4;\r\n  }\r\n  if (x < 100)\
    \ {\r\n    if (x < 10) {\r\n      outbuf[out_right] = '0' + x;\r\n      ++out_right;\r\
    \n    } else {\r\n      uint32_t q = (uint32_t(x) * 205) >> 11;\r\n      uint32_t\
    \ r = uint32_t(x) - q * 10;\r\n      outbuf[out_right] = '0' + q;\r\n      outbuf[out_right\
    \ + 1] = '0' + r;\r\n      out_right += 2;\r\n    }\r\n  } else {\r\n    if (x\
    \ < 1000) {\r\n      memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);\r\n\
    \      out_right += 3;\r\n    } else {\r\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2), 4);\r\n      out_right += 4;\r\n    }\r\n  }\r\n  memcpy(outbuf\
    \ + out_right, buf + i + 4, 12 - i);\r\n  out_right += 12 - i;\r\n}\r\ninline\
    \ void write() {}\r\ntemplate <typename Head, typename... Tail>\r\ninline void\
    \ write(Head &&head, Tail &&... tail) {\r\n  write(head);\r\n  write(forward<Tail>(tail)...);\r\
    \n}\r\ntemplate <typename... Args>\r\ninline void writen(Args &&... x) {\r\n \
    \ write(forward<Args>(x)...);\r\n  write('\\n');\r\n}\r\n\r\nstruct Dummy {\r\n\
    \  Dummy() { atexit(flush); }\r\n} dummy;\r\n} // namespace fastio\r\n\r\nvoid\
    \ print() { fastio::write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\n\
    void print(Head &&head, Tail &&... tail) {\r\n  fastio::write(head);\r\n  if (sizeof...(Tail))\
    \ fastio::write(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  fastio::read(head);\r\n  read(tail...);\r\n}\r\n\r\n#define INT(...)\
    \   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\
    \r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print<string>(t ? \"YES\" :\
    \ \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print<string>(t\
    \ ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool\
    \ t = 1) { print<string>(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t);\
    \ }\n#line 2 \"alg/monoid/add_pair.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"ds/splay/splaytree.hpp\"\n// Node \u578B\
    \u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate <typename Node,\
    \ int NODES = 1'000'000>\nstruct SplayTree {\n  Node *pool;\n  int pid;\n  using\
    \ np = Node *;\n  using X = typename Node::value_type;\n  using A = typename Node::operator_type;\n\
    \n  SplayTree() : pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid =\
    \ 0; }\n\n  np new_node(const X &x) {\n    np n = &(pool[pid++]);\n    Node::new_node(n,\
    \ x);\n    return n;\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs =\
    \ [&](auto &dfs, int l, int r) -> np {\n      if (l == r) return nullptr;\n  \
    \    if (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n  \
    \    np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n    \
    \  np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n  \
    \    if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n    \
    \  root->update();\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  u32 get_size(np root) { return (root ? root->size : 0); }\n\n  np merge(np\
    \ l_root, np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return\
    \ l_root;\n    splay_kth(r_root, 0); // splay \u3057\u305F\u306E\u3067 prop \u6E08\
    \n    r_root->l = l_root;\n    l_root->p = r_root;\n    r_root->update();\n  \
    \  return r_root;\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n\n  pair<np, np> split(np root, u32 k) {\n    if (k == (root->size))\
    \ return {root, nullptr};\n    if (k == 0) return {nullptr, root};\n    splay_kth(root,\
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
    \  dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k) {\n    splay_kth(root,\
    \ k);\n    return root->get();\n  }\n\n  void set(np &root, u32 k, const X &x)\
    \ {\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np &root,\
    \ u32 k, const X &x) {\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\
    \n  X prod(np &root, u32 l, u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    goto_between(root, l, r);\n    X res = root->prod;\n    splay(root);\n  \
    \  return res;\n  }\n\n  void apply(np &root, u32 l, u32 r, const A &a) {\n  \
    \  assert(0 <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n\
    \    root->apply(a);\n    splay(root);\n  }\n  void apply(np &root, const A &a)\
    \ {\n    if (!root) return;\n    root->apply(a);\n  }\n\n  void reverse(np &root,\
    \ u32 l, u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    root->reverse();\n    splay(root);\n  }\n  void reverse(np &root)\
    \ {\n    if (!root) return;\n    root->reverse();\n  }\n\n  void rotate(Node *n)\
    \ {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update \u306F\
    \ rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n    p =\
    \ n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r = p;\n\
    \      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n      p->r =\
    \ c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r\
    \ = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\n  void splay(Node\
    \ *me) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\
    \u7956\u5148\uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\
    \u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\
    \u4E86\u6642\u70B9\u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    me->prop();\n\
    \    while (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp)\
    \ {\n        rotate(me);\n        p->update();\n        break;\n      }\n    \
    \  bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n   \
    \   if (same) rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n\
    \      pp->update(), p->update();\n    }\n    // me \u306E update \u306F\u6700\
    \u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np\
    \ &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n\
    \      u32 sl = (root->l ? root->l->size : 0);\n      if (k == sl) break;\n  \
    \    root->prop();\n      if (k < sl)\n        root = root->l;\n      else {\n\
    \        k -= sl + 1;\n        root = root->r;\n      }\n    }\n    splay(root);\n\
    \  }\n\n  // \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\
    \u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right(np root, F check) {\n    if (!root) return {nullptr, nullptr};\n\
    \    np c = find_max_right(root, check);\n    if (!c) {\n      splay(root);\n\
    \      return {nullptr, root};\n    }\n    splay(c);\n    np right = c->r;\n \
    \   if (!right) return {c, nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n\
    \    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\u5074\u306E\u30CE\
    \u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np> split_max_right_prod(np\
    \ root, F check) {\n    if (!root) return {nullptr, nullptr};\n    np c = find_max_right_prod(root,\
    \ check);\n    if (!c) {\n      splay(root);\n      return {nullptr, root};\n\
    \    }\n    splay(c);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last);\n \
    \   return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_prod(np\
    \ root, const F &check) {\n    using Mono = typename Node::Monoid_X;\n    X prod\
    \ = Mono::unit();\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\
    \u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok =\
    \ nullptr, last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      X lprod = prod;\n      if (root->l) lprod = Mono::op(lprod, root->l->prod);\n\
    \      lprod = Mono::op(lprod, root->x);\n      if (check(lprod)) {\n        prod\
    \ = lprod;\n        last_ok = root;\n        root = root->r;\n      } else {\n\
    \        root = root->l;\n      }\n    }\n    splay(last);\n    return last_ok;\n\
    \  }\n};\n#line 2 \"ds/splay/splaytree_acted_set.hpp\"\n\nnamespace SplayTreeNodes\
    \ {\ntemplate <typename ActedSet>\nstruct Node_AM {\n  using Monoid_A = typename\
    \ ActedSet::Monoid_A;\n  using A = typename ActedSet::A;\n  using S = typename\
    \ ActedSet::S;\n  using value_type = S;\n  using operator_type = A;\n  using np\
    \ = Node_AM *;\n\n  np p, l, r;\n  S x;\n  A lazy;\n  u32 size;\n  bool rev;\n\
    \n  static void new_node(np n, const S &x) {\n    n->p = n->l = n->r = nullptr;\n\
    \    n->x = x;\n    n->lazy = Monoid_A::unit();\n    n->size = 1;\n    n->rev\
    \ = 0;\n  }\n\n  void update() {\n    size = 1;\n    if (l) { size += l->size;\
    \ }\n    if (r) { size += r->size; }\n  }\n\n  void prop() {\n    if (lazy !=\
    \ Monoid_A::unit()) {\n      if (l) {\n        l->x = ActedSet::act(l->x, lazy);\n\
    \        l->lazy = Monoid_A::op(l->lazy, lazy);\n      }\n      if (r) {\n   \
    \     r->x = ActedSet::act(r->x, lazy);\n        r->lazy = Monoid_A::op(r->lazy,\
    \ lazy);\n      }\n      lazy = Monoid_A::unit();\n    }\n    if (rev) {\n   \
    \   if (l) {\n        l->rev ^= 1;\n        swap(l->l, l->r);\n      }\n     \
    \ if (r) {\n        r->rev ^= 1;\n        swap(r->l, r->r);\n      }\n      rev\
    \ = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\
    \u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\
    \u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\
    \u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  S get() { return x; }\n  void\
    \ set(const S &xx) {\n    x = xx;\n    update();\n  }\n  void apply(const A &a)\
    \ {\n    x = ActedSet::act(x, a);\n    lazy = Monoid_A::op(lazy, a);\n  }\n  void\
    \ reverse() {\n    swap(l, r);\n    rev ^= 1;\n  }\n};\ntemplate <typename ActedSet,\
    \ int NODES>\nusing SplayTree_ActedSet = SplayTree<Node_AM<ActedSet>, NODES>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_ActedSet;\n#line\
    \ 6 \"test/mytest/cf702_F_splay.test.cpp\"\n\n// (\u6240\u6301\u91D1, \u64CD\u4F5C\
    \u56DE\u6570, query index)\nstruct AS {\n  using Monoid_A = Monoid_Add_Pair<int>;\n\
    \  using A = Monoid_A::value_type;\n  using S = tuple<int, int, int>;\n  static\
    \ S act(const S& s, const A& x) {\n    auto [a, b, c] = s;\n    return {a + x.fi,\
    \ b + x.se, c};\n  }\n};\n\nvc<int> solve_cf702F(vc<pair<int, int>> CQ, vc<int>\
    \ query) {\n  const int Q = len(query);\n  sort(all(CQ), [&](auto& a, auto& b)\
    \ -> bool {\n    if (a.se != b.se) return a.se > b.se;\n    return a.fi < b.fi;\n\
    \  });\n  using T = tuple<int, int, int>;\n  vc<T> dat(Q);\n  FOR(q, Q) {\n  \
    \  int x = query[q];\n    dat[q] = {x, 0, q};\n  }\n  sort(all(dat));\n\n  const\
    \ int MAX = 500'000;\n\n  SplayTree_ActedSet<AS, MAX> X;\n  using np = decltype(X)::np;\n\
    \  using S = typename AS::S;\n  np root = X.new_node(dat);\n\n  FOR(i, len(CQ))\
    \ {\n    ll c = CQ[i].fi;\n    np nm, nr;\n    tie(root, nr)\n        = X.split_max_right(root,\
    \ [&](S& s) { return get<0>(s) < c; });\n    X.apply(nr, {-c, 1});\n    tie(nm,\
    \ nr) = X.split_max_right(nr, [&](S& s) { return get<0>(s) < c; });\n    for (auto&&\
    \ [aa, bb, cc]: X.get_all(nm)) assert(aa < c);\n    for (auto&& [aa, bb, cc]:\
    \ X.get_all(nr)) assert(aa >= c);\n    for (auto [val, cnt, idx]: X.get_all(nm))\
    \ {\n      ll t = val;\n      auto [l_root, r_root]\n          = X.split_max_right(root,\
    \ [&](S& s) { return get<0>(s) < t; });\n      root = X.merge(l_root, X.new_node({val,\
    \ cnt, idx}));\n      root = X.merge(root, r_root);\n    }\n    root = X.merge(root,\
    \ nr);\n  }\n  vc<int> ANS(Q);\n  for (auto [val, cnt, idx]: X.get_all(root))\
    \ { ANS[idx] = cnt; }\n  return ANS;\n}\n\nvoid test_1() {\n  vc<pair<int, int>>\
    \ CQ;\n  CQ.eb(7, 5);\n  CQ.eb(3, 5);\n  CQ.eb(4, 3);\n  vc<int> query = {13,\
    \ 14};\n  vc<int> ANS = solve_cf702F(CQ, query);\n  assert(ANS == vc<int>({2,\
    \ 3}));\n}\n\nvoid test_2() {\n  vc<pair<int, int>> CQ;\n  CQ.eb(100, 500);\n\
    \  CQ.eb(50, 499);\n  vc<int> query = {50, 200, 150, 100};\n  vc<int> ANS = solve_cf702F(CQ,\
    \ query);\n  assert(ANS == vc<int>({1, 2, 2, 1}));\n}\n\nvoid solve() {\n  LL(a,\
    \ b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n  test_1();\n  test_2();\n  solve();\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/monoid/add_pair.hpp\"\n#include \"\
    ds/splay/splaytree_acted_set.hpp\"\n\n// (\u6240\u6301\u91D1, \u64CD\u4F5C\u56DE\
    \u6570, query index)\nstruct AS {\n  using Monoid_A = Monoid_Add_Pair<int>;\n\
    \  using A = Monoid_A::value_type;\n  using S = tuple<int, int, int>;\n  static\
    \ S act(const S& s, const A& x) {\n    auto [a, b, c] = s;\n    return {a + x.fi,\
    \ b + x.se, c};\n  }\n};\n\nvc<int> solve_cf702F(vc<pair<int, int>> CQ, vc<int>\
    \ query) {\n  const int Q = len(query);\n  sort(all(CQ), [&](auto& a, auto& b)\
    \ -> bool {\n    if (a.se != b.se) return a.se > b.se;\n    return a.fi < b.fi;\n\
    \  });\n  using T = tuple<int, int, int>;\n  vc<T> dat(Q);\n  FOR(q, Q) {\n  \
    \  int x = query[q];\n    dat[q] = {x, 0, q};\n  }\n  sort(all(dat));\n\n  const\
    \ int MAX = 500'000;\n\n  SplayTree_ActedSet<AS, MAX> X;\n  using np = decltype(X)::np;\n\
    \  using S = typename AS::S;\n  np root = X.new_node(dat);\n\n  FOR(i, len(CQ))\
    \ {\n    ll c = CQ[i].fi;\n    np nm, nr;\n    tie(root, nr)\n        = X.split_max_right(root,\
    \ [&](S& s) { return get<0>(s) < c; });\n    X.apply(nr, {-c, 1});\n    tie(nm,\
    \ nr) = X.split_max_right(nr, [&](S& s) { return get<0>(s) < c; });\n    for (auto&&\
    \ [aa, bb, cc]: X.get_all(nm)) assert(aa < c);\n    for (auto&& [aa, bb, cc]:\
    \ X.get_all(nr)) assert(aa >= c);\n    for (auto [val, cnt, idx]: X.get_all(nm))\
    \ {\n      ll t = val;\n      auto [l_root, r_root]\n          = X.split_max_right(root,\
    \ [&](S& s) { return get<0>(s) < t; });\n      root = X.merge(l_root, X.new_node({val,\
    \ cnt, idx}));\n      root = X.merge(root, r_root);\n    }\n    root = X.merge(root,\
    \ nr);\n  }\n  vc<int> ANS(Q);\n  for (auto [val, cnt, idx]: X.get_all(root))\
    \ { ANS[idx] = cnt; }\n  return ANS;\n}\n\nvoid test_1() {\n  vc<pair<int, int>>\
    \ CQ;\n  CQ.eb(7, 5);\n  CQ.eb(3, 5);\n  CQ.eb(4, 3);\n  vc<int> query = {13,\
    \ 14};\n  vc<int> ANS = solve_cf702F(CQ, query);\n  assert(ANS == vc<int>({2,\
    \ 3}));\n}\n\nvoid test_2() {\n  vc<pair<int, int>> CQ;\n  CQ.eb(100, 500);\n\
    \  CQ.eb(50, 499);\n  vc<int> query = {50, 200, 150, 100};\n  vc<int> ANS = solve_cf702F(CQ,\
    \ query);\n  assert(ANS == vc<int>({1, 2, 2, 1}));\n}\n\nvoid solve() {\n  LL(a,\
    \ b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n  test_1();\n  test_2();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/add_pair.hpp
  - ds/splay/splaytree_acted_set.hpp
  - ds/splay/splaytree.hpp
  isVerificationFile: true
  path: test/mytest/cf702_F_splay.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 18:57:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/cf702_F_splay.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/cf702_F_splay.test.cpp
- /verify/test/mytest/cf702_F_splay.test.cpp.html
title: test/mytest/cf702_F_splay.test.cpp
---
