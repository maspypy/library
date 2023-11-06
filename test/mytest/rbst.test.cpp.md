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
    path: other/io.hpp
    title: other/io.hpp
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
  bundledCode: "#line 1 \"test/mytest/rbst.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
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
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__,\
    \ FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define FOR_subset(t, s) \\\n  for (ll\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \n#define stoi stoll\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_mod_2(int x) { return __builtin_parity(x); }\nint popcnt_mod_2(u32\
    \ x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll x) { return __builtin_parityll(x);\
    \ }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x); }\n// (0, 1, 2, 3,\
    \ 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n#include\
    \ <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\nnamespace fastio\
    \ {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\
    \nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil = 0, pir = 0, por\
    \ = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num()\
    \ {\r\n    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for\
    \ (int j = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n\
    \ /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline void load()\
    \ {\r\n  memcpy(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n}\r\n\r\ninline void\
    \ flush() {\r\n  fwrite(obuf, 1, por, stdout);\r\n  por = 0;\r\n}\r\n\r\nvoid\
    \ rd(char &c) {\r\n  do {\r\n    if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\
    \n  } while (isspace(c));\r\n}\r\n\r\nvoid rd(string &x) {\r\n  x.clear();\r\n\
    \  char c;\r\n  do {\r\n    if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\
    \n  } while (isspace(c));\r\n  do {\r\n    x += c;\r\n    if (pil == pir) load();\r\
    \n    if (pil == pir) break;\r\n    c = ibuf[pil++];\r\n  } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n  string s;\r\n  rd(s);\r\
    \n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_integer(T &x) {\r\
    \n  if (pil + 100 > pir) load();\r\n  char c;\r\n  do\r\n    c = ibuf[pil++];\r\
    \n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (c == '-') { minus = 1, c = ibuf[pil++];\
    \ }\r\n  }\r\n  x = 0;\r\n  while (c >= '0') { x = x * 10 + (c & 15), c = ibuf[pil++];\
    \ }\r\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if\
    \ (minus) x = -x;\r\n  }\r\n}\r\n\r\nvoid rd(int &x) { rd_integer(x); }\r\nvoid\
    \ rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double &x) { rd_real(x); }\r\nvoid\
    \ rd(long double &x) { rd_real(x); }\r\nvoid rd(f128 &x) { rd_real(x); }\r\n\r\
    \ntemplate <class T, class U>\r\nvoid rd(pair<T, U> &p) {\r\n  return rd(p.first),\
    \ rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(T &t) {\r\
    \n  if constexpr (N < std::tuple_size<T>::value) {\r\n    auto &x = std::get<N>(t);\r\
    \n    rd(x);\r\n    rd<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid\
    \ rd(tuple<T...> &tpl) {\r\n  rd(tpl);\r\n}\r\n\r\ntemplate <size_t N = 0, typename\
    \ T>\r\nvoid rd(array<T, N> &x) {\r\n  for (auto &d: x) rd(d);\r\n}\r\ntemplate\
    \ <class T>\r\nvoid rd(vc<T> &x) {\r\n  for (auto &d: x) rd(d);\r\n}\r\n\r\nvoid\
    \ read() {}\r\ntemplate <class H, class... T>\r\nvoid read(H &h, T &... t) {\r\
    \n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n  if (por == SZ)\
    \ flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const string &s) {\r\n  for (char\
    \ c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n  size_t len = strlen(s);\r\
    \n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100) flush();\r\n  if (x <\
    \ 0) { obuf[por++] = '-', x = -x; }\r\n  int outi;\r\n  for (outi = 96; x >= 10000;\
    \ outi -= 4) {\r\n    memcpy(out + outi, pre.num[x % 10000], 4);\r\n    x /= 10000;\r\
    \n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf + por, pre.num[x], 4);\r\n    por\
    \ += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf + por, pre.num[x] + 1,\
    \ 3);\r\n    por += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103) >>\
    \ 10;\r\n    obuf[por] = q | '0';\r\n    obuf[por + 1] = (x - q * 10) | '0';\r\
    \n    por += 2;\r\n  } else\r\n    obuf[por++] = x | '0';\r\n  memcpy(obuf + por,\
    \ out + outi + 4, 96 - outi);\r\n  por += 96 - outi;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\n  oss << fixed << setprecision(15)\
    \ << double(x);\r\n  string s = oss.str();\r\n  wt(s);\r\n}\r\n\r\nvoid wt(int\
    \ x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x); }\r\nvoid wt(i128 x)\
    \ { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\nvoid wt(u64 x) {\
    \ wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\nvoid wt(double x)\
    \ { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\nvoid wt(f128 x)\
    \ { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const pair<T,\
    \ U> val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n}\r\ntemplate\
    \ <size_t N = 0, typename T>\r\nvoid wt_tuple(const T t) {\r\n  if constexpr (N\
    \ < std::tuple_size<T>::value) {\r\n    if constexpr (N > 0) { wt(' '); }\r\n\
    \    const auto x = std::get<N>(t);\r\n    wt(x);\r\n    wt_tuple<N + 1>(t);\r\
    \n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(tuple<T...> tpl) {\r\n  wt_tuple(tpl);\r\
    \n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T, S> val) {\r\n  auto\
    \ n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\
    \n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\nvoid wt(const vector<T>\
    \ val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n \
    \   if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\nvoid print() { wt('\\\
    n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\n// gcc expansion. called automaticall after main.\r\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\r\n} // namespace fastio\r\nusing fastio::read;\r\nusing fastio::print;\r\
    \nusing fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\
    \n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ U64(...)   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 1 \"ds/randomized_bst/rbst.hpp\"\n// \u5358\u306B S \u306E\
    \u5143\u306E\u5217\u3092\u7BA1\u7406\u3059\u308B\ntemplate <typename S, bool PERSISTENT,\
    \ int NODES>\nstruct RBST {\n  struct Node {\n    Node *l, *r;\n    S s;\n   \
    \ u32 size;\n    bool rev;\n  };\n\n  Node *pool;\n  int pid;\n  using np = Node\
    \ *;\n\n  RBST() : pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid\
    \ = 0; }\n\n  np new_node(const S &s) {\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].s = s;\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return\
    \ &(pool[pid++]);\n  }\n\n  np new_node(const vc<S> &dat) {\n    auto dfs = [&](auto\
    \ &dfs, u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      u32 m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      update(root);\n      return\
    \ root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  np copy_node(np &n)\
    \ {\n    if (!n || !PERSISTENT) return n;\n    pool[pid].l = n->l, pool[pid].r\
    \ = n->r;\n    pool[pid].s = n->s;\n    pool[pid].size = n->size;\n    pool[pid].rev\
    \ = n->rev;\n    return &(pool[pid++]);\n  }\n\n  np merge(np l_root, np r_root)\
    \ { return merge_rec(l_root, r_root); }\n  np merge3(np a, np b, np c) { return\
    \ merge(merge(a, b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n  \
    \    assert(k == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <=\
    \ k && k <= root->size);\n    return split_rec(root, k);\n  }\n  tuple<np, np,\
    \ np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root,\
    \ r);\n    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n\
    \  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n \
    \   tie(root, d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n\
    \    return {a, b, c, d};\n  }\n\n  np reverse(np root, u32 l, u32 r) {\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return root;\n    auto\
    \ [nl, nm, nr] = split3(root, l, r);\n    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n\
    \    return merge3(nl, nm, nr);\n  }\n\n  np set(np root, u32 k, const S &s) {\
    \ return set_rec(root, k, s); }\n  S get(np root, u32 k) { return get_rec(root,\
    \ k, false); }\n\n  vc<S> get_all(np root) {\n    vc<S> res;\n    auto dfs = [&](auto\
    \ &dfs, np root, bool rev) -> void {\n      if (!root) return;\n      dfs(dfs,\
    \ (rev ? root->r : root->l), rev ^ root->rev);\n      res.eb(root->s);\n     \
    \ dfs(dfs, (rev ? root->l : root->r), rev ^ root->rev);\n    };\n    dfs(dfs,\
    \ root, 0);\n    return res;\n  }\n\n  // \u6700\u5F8C\u306B check(s) \u304C\u6210\
    \u308A\u7ACB\u3064\u3068\u3053\u308D\u307E\u3067\u3092\u5DE6\u3068\u3057\u3066\
    \ split\n  template <typename F>\n  pair<np, np> split_max_right(np root, const\
    \ F check) {\n    return split_max_right_rec(root, check);\n  }\n\nprivate:\n\
    \  inline u32 xor128() {\n    static u32 x = 123456789;\n    static u32 y = 362436069;\n\
    \    static u32 z = 521288629;\n    static u32 w = 88675123;\n    u32 t = x ^\
    \ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >> 19))\
    \ ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n    // \u81EA\u8EAB\u3092\u30B3\
    \u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n    // \u5B50\u3092\
    \u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\u8907\u6570\
    \u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\u3081\
    \u3002\n    if (c->rev) {\n      if (c->l) {\n        c->l = copy_node(c->l);\n\
    \        c->l->rev ^= 1;\n        swap(c->l->l, c->l->r);\n      }\n      if (c->r)\
    \ {\n        c->r = copy_node(c->r);\n        c->r->rev ^= 1;\n        swap(c->r->l,\
    \ c->r->r);\n      }\n      c->rev = 0;\n    }\n  }\n\n  void update(np c) {\n\
    \    // \u30C7\u30FC\u30BF\u3092\u4FDD\u3063\u305F\u307E\u307E\u6B63\u5E38\u5316\
    \u3059\u308B\u3060\u3051\u306A\u306E\u3067\u3001\u30B3\u30D4\u30FC\u4E0D\u8981\
    \n    c->size = 1;\n    if (c->l) { c->size += c->l->size; }\n    if (c->r) {\
    \ c->size += c->r->size; }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n  \
    \  if (!l_root) return r_root;\n    if (!r_root) return l_root;\n    u32 sl =\
    \ l_root->size, sr = r_root->size;\n    if (xor128() % (sl + sr) < sl) {\n   \
    \   prop(l_root);\n      l_root = copy_node(l_root);\n      l_root->r = merge_rec(l_root->r,\
    \ r_root);\n      update(l_root);\n      return l_root;\n    }\n    prop(r_root);\n\
    \    r_root = copy_node(r_root);\n    r_root->l = merge_rec(l_root, r_root->l);\n\
    \    update(r_root);\n    return r_root;\n  }\n\n  pair<np, np> split_rec(np root,\
    \ u32 k) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n    u32\
    \ sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n      auto [nl, nr]\
    \ = split_rec(root->l, k);\n      root = copy_node(root);\n      root->l = nr;\n\
    \      update(root);\n      return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r,\
    \ k - (1 + sl));\n    root = copy_node(root);\n    root->r = nl;\n    update(root);\n\
    \    return {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const S &s) {\n \
    \   if (!root) return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
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
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"test/mytest/rbst.test.cpp\"\
    \n\nvoid test() {\n  RBST<int, true, 10000> X;\n  using np = decltype(X)::np;\n\
    \n  FOR(1000) {\n    X.reset();\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n\
    \    vvc<int> AA(1);\n    FOR(i, N) AA[0].eb(RNG(0, 100));\n    vc<np> roots =\
    \ {X.new_node(AA[0])};\n\n    FOR(Q) {\n      vc<int> cand = {0, 1, 2, 3};\n \
    \     int t = cand[RNG(0, len(cand))];\n      int frm = RNG(0, len(AA));\n   \
    \   vc<int> A = AA[frm];\n      np root = roots[frm];\n      if (t == 0) {\n \
    \       int i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n\
    \      if (t == 1) {\n        int i = RNG(0, N);\n        int x = RNG(0, 100);\n\
    \        root = X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t ==\
    \ 2) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L\
    \ > R) swap(L, R);\n        ++R;\n        root = X.reverse(root, L, R);\n    \
    \    reverse(A.begin() + L, A.begin() + R);\n      }\n      if (t == 3) {\n  \
    \      vc<int> B = X.get_all(root);\n        assert(A == B);\n      }\n      AA.eb(A);\n\
    \      roots.eb(root);\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"ds/randomized_bst/rbst.hpp\"\n#include\
    \ \"random/base.hpp\"\n\nvoid test() {\n  RBST<int, true, 10000> X;\n  using np\
    \ = decltype(X)::np;\n\n  FOR(1000) {\n    X.reset();\n    int N = RNG(1, 20);\n\
    \    int Q = RNG(1, 1000);\n    vvc<int> AA(1);\n    FOR(i, N) AA[0].eb(RNG(0,\
    \ 100));\n    vc<np> roots = {X.new_node(AA[0])};\n\n    FOR(Q) {\n      vc<int>\
    \ cand = {0, 1, 2, 3};\n      int t = cand[RNG(0, len(cand))];\n      int frm\
    \ = RNG(0, len(AA));\n      vc<int> A = AA[frm];\n      np root = roots[frm];\n\
    \      if (t == 0) {\n        int i = RNG(0, N);\n        assert(A[i] == X.get(root,\
    \ i));\n      }\n      if (t == 1) {\n        int i = RNG(0, N);\n        int\
    \ x = RNG(0, 100);\n        root = X.set(root, i, x);\n        A[i] = x;\n   \
    \   }\n      if (t == 2) {\n        int L = RNG(0, N);\n        int R = RNG(0,\
    \ N);\n        if (L > R) swap(L, R);\n        ++R;\n        root = X.reverse(root,\
    \ L, R);\n        reverse(A.begin() + L, A.begin() + R);\n      }\n      if (t\
    \ == 3) {\n        vc<int> B = X.get_all(root);\n        assert(A == B);\n   \
    \   }\n      AA.eb(A);\n      roots.eb(root);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/randomized_bst/rbst.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/rbst.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 23:45:48+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/rbst.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/rbst.test.cpp
- /verify/test/mytest/rbst.test.cpp.html
title: test/mytest/rbst.test.cpp
---
