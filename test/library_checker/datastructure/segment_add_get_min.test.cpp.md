---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://codeforces.com/blog/entry/96344
    - https://judge.yosupo.jp/problem/segment_add_get_min
    - https://judge.yosupo.jp/submission/21623
    - https://trap.jp/post/1224/
  bundledCode: "#line 1 \"test/library_checker/datastructure/segment_add_get_min.test.cpp\"\
    \n#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return B;\n}\n#endif\n#line 1 \"library/other/io.hpp\"\n#define FASTIO\n#include\
    \ <unistd.h>\n\n// https://judge.yosupo.jp/submission/21623\nnamespace fastio\
    \ {\nstatic constexpr uint32_t SZ = 1 << 17;\nchar ibuf[SZ];\nchar obuf[SZ];\n\
    char out[100];\n// pointer of ibuf, obuf\nuint32_t pil = 0, pir = 0, por = 0;\n\
    \nstruct Pre {\n  char num[10000][4];\n  constexpr Pre() : num() {\n    for (int\
    \ i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--)\
    \ {\n        num[i][j] = n % 10 | '0';\n        n /= 10;\n      }\n    }\n  }\n\
    } constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n\
    \  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil\
    \ = 0;\n  if (pir < SZ) ibuf[pir++] = '\\n';\n}\n\ninline void flush() {\n  fwrite(obuf,\
    \ 1, por, stdout);\n  por = 0;\n}\n\nvoid rd(char &c) {\n  do {\n    if (pil +\
    \ 1 > pir) load();\n    c = ibuf[pil++];\n  } while (isspace(c));\n}\n\nvoid rd(string\
    \ &x) {\n  x.clear();\n  char c;\n  do {\n    if (pil + 1 > pir) load();\n   \
    \ c = ibuf[pil++];\n  } while (isspace(c));\n  do {\n    x += c;\n    if (pil\
    \ == pir) load();\n    c = ibuf[pil++];\n  } while (!isspace(c));\n}\n\ntemplate\
    \ <typename T>\nvoid rd_real(T &x) {\n  string s;\n  rd(s);\n  x = stod(s);\n\
    }\n\ntemplate <typename T>\nvoid rd_integer(T &x) {\n  if (pil + 100 > pir) load();\n\
    \  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n  bool minus = 0;\n\
    \  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\n    if (c == '-')\
    \ { minus = 1, c = ibuf[pil++]; }\n  }\n  x = 0;\n  while ('0' <= c) { x = x *\
    \ 10 + (c & 15), c = ibuf[pil++]; }\n  if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\n    if (minus) x = -x;\n  }\n}\n\nvoid rd(int &x) { rd_integer(x);\
    \ }\nvoid rd(ll &x) { rd_integer(x); }\nvoid rd(i128 &x) { rd_integer(x); }\n\
    void rd(u32 &x) { rd_integer(x); }\nvoid rd(u64 &x) { rd_integer(x); }\nvoid rd(u128\
    \ &x) { rd_integer(x); }\nvoid rd(double &x) { rd_real(x); }\nvoid rd(long double\
    \ &x) { rd_real(x); }\nvoid rd(f128 &x) { rd_real(x); }\n\ntemplate <class T,\
    \ class U>\nvoid rd(pair<T, U> &p) {\n  return rd(p.first), rd(p.second);\n}\n\
    template <size_t N = 0, typename T>\nvoid rd_tuple(T &t) {\n  if constexpr (N\
    \ < std::tuple_size<T>::value) {\n    auto &x = std::get<N>(t);\n    rd(x);\n\
    \    rd_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid rd(tuple<T...> &tpl)\
    \ {\n  rd_tuple(tpl);\n}\n\ntemplate <size_t N = 0, typename T>\nvoid rd(array<T,\
    \ N> &x) {\n  for (auto &d: x) rd(d);\n}\ntemplate <class T>\nvoid rd(vc<T> &x)\
    \ {\n  for (auto &d: x) rd(d);\n}\n\nvoid read() {}\ntemplate <class H, class...\
    \ T>\nvoid read(H &h, T &... t) {\n  rd(h), read(t...);\n}\n\nvoid wt(const char\
    \ c) {\n  if (por == SZ) flush();\n  obuf[por++] = c;\n}\nvoid wt(const string\
    \ s) {\n  for (char c: s) wt(c);\n}\nvoid wt(const char *s) {\n  size_t len =\
    \ strlen(s);\n  for (size_t i = 0; i < len; i++) wt(s[i]);\n}\n\ntemplate <typename\
    \ T>\nvoid wt_integer(T x) {\n  if (por > SZ - 100) flush();\n  if (x < 0) { obuf[por++]\
    \ = '-', x = -x; }\n  int outi;\n  for (outi = 96; x >= 10000; outi -= 4) {\n\
    \    memcpy(out + outi, pre.num[x % 10000], 4);\n    x /= 10000;\n  }\n  if (x\
    \ >= 1000) {\n    memcpy(obuf + por, pre.num[x], 4);\n    por += 4;\n  } else\
    \ if (x >= 100) {\n    memcpy(obuf + por, pre.num[x] + 1, 3);\n    por += 3;\n\
    \  } else if (x >= 10) {\n    int q = (x * 103) >> 10;\n    obuf[por] = q | '0';\n\
    \    obuf[por + 1] = (x - q * 10) | '0';\n    por += 2;\n  } else\n    obuf[por++]\
    \ = x | '0';\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\n  por += 96 -\
    \ outi;\n}\n\ntemplate <typename T>\nvoid wt_real(T x) {\n  ostringstream oss;\n\
    \  oss << fixed << setprecision(15) << double(x);\n  string s = oss.str();\n \
    \ wt(s);\n}\n\nvoid wt(int x) { wt_integer(x); }\nvoid wt(ll x) { wt_integer(x);\
    \ }\nvoid wt(i128 x) { wt_integer(x); }\nvoid wt(u32 x) { wt_integer(x); }\nvoid\
    \ wt(u64 x) { wt_integer(x); }\nvoid wt(u128 x) { wt_integer(x); }\nvoid wt(double\
    \ x) { wt_real(x); }\nvoid wt(long double x) { wt_real(x); }\nvoid wt(f128 x)\
    \ { wt_real(x); }\n\ntemplate <class T, class U>\nvoid wt(const pair<T, U> val)\
    \ {\n  wt(val.first);\n  wt(' ');\n  wt(val.second);\n}\ntemplate <size_t N =\
    \ 0, typename T>\nvoid wt_tuple(const T t) {\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\n    if constexpr (N > 0) { wt(' '); }\n    const auto x = std::get<N>(t);\n\
    \    wt(x);\n    wt_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid wt(tuple<T...>\
    \ tpl) {\n  wt_tuple(tpl);\n}\ntemplate <class T, size_t S>\nvoid wt(const array<T,\
    \ S> val) {\n  auto n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if\
    \ (i) wt(' ');\n    wt(val[i]);\n  }\n}\ntemplate <class T>\nvoid wt(const vector<T>\
    \ val) {\n  auto n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if (i)\
    \ wt(' ');\n    wt(val[i]);\n  }\n}\n\nvoid print() { wt('\\n'); }\ntemplate <class\
    \ Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  wt(head);\n\
    \  if (sizeof...(Tail)) wt(' ');\n  print(forward<Tail>(tail)...);\n}\n\n// gcc\
    \ expansion. called automaticall after main.\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n} // namespace fastio\nusing fastio::read;\nusing fastio::print;\n\
    using fastio::flush;\n\n#if defined(LOCAL)\n#define SHOW(...) \\\n  SHOW_IMPL(__VA_ARGS__,\
    \ SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\n#define SHOW_IMPL(_1, _2, _3, _4,\
    \ NAME, ...) NAME\n#define SHOW1(x) print(#x, \"=\", (x)), flush()\n#define SHOW2(x,\
    \ y) print(#x, \"=\", (x), #y, \"=\", (y)), flush()\n#define SHOW3(x, y, z) print(#x,\
    \ \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)), flush()\n#define SHOW4(x, y, z,\
    \ w) \\\n  print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w)),\
    \ flush()\n#else\n#define SHOW(...)\n#endif\n\n#define INT(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define U32(...)   \\\n  u32 __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define U64(...)\
    \   \\\n  u64 __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)      \\\n\
    \  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)   \\\n  char\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n  double __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size) \\\n  vector<type>\
    \ name(size);    \\\n  read(name)\n#define VV(type, name, h, w)              \
    \       \\\n  vector<vector<type>> name(h, vector<type>(w)); \\\n  read(name)\n\
    \nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool t = 1) {\
    \ YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid No(bool\
    \ t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\n\
    void no(bool t = 1) { yes(!t); }\n#line 1 \"library/convex/dynamic_lichao.hpp\"\
    \n/*\nstruct F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\u5024\
    \n  int a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n*/\n\n//\
    \ \u76F4\u7DDA\u8FFD\u52A0\u304B\u3064\u975E\u6C38\u7D9A\u306A\u3089\u7A7A\u9593\
    \ Q \u3067\u3088\u3044\u3002\n// \u95A2\u6570\u306F ll -> T\u3002[L, R) \u4E0A\
    \ f \u304C overflow \u3057\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u3002\n//\
    \ evaluate \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\u3001totally monotone \u306A\
    \u95A2\u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\ntemplate <typename FUNC, bool\
    \ PERSISTENT, int NODES, bool MINIMIZE>\nstruct Dynamic_LiChao_Tree {\n  using\
    \ T = typename FUNC::value_type;\n  vc<FUNC> funcs;\n\n  static inline T evaluate(FUNC\
    \ &f, ll x) { return f(x); }\n\n  struct Node {\n    int fid;\n    Node *l, *r;\n\
    \  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n\n  using np = Node *;\n\n  Dynamic_LiChao_Tree(ll\
    \ L, ll R) : pid(0), L(L), R(R) {\n    pool = new Node[NODES];\n  }\n\n  void\
    \ reset() {\n    funcs.clear();\n    pid = 0;\n  }\n\n  np new_root() { return\
    \ nullptr; }\n\n  np new_node() {\n    pool[pid].fid = -1;\n    pool[pid].l =\
    \ nullptr, pool[pid].r = nullptr;\n    return &(pool[pid++]);\n  }\n\n  np add_line(np\
    \ root, FUNC f) {\n    int fid = len(funcs);\n    funcs.eb(f);\n    if (!root)\
    \ root = new_node();\n    return add_line_rec(root, fid, L, R);\n  }\n\n  // [xl,\
    \ xr)\n  np add_segment(np root, ll xl, ll xr, FUNC f) {\n    int fid = len(funcs);\n\
    \    funcs.eb(f);\n    if (!root) root = new_node();\n    return add_segment_rec(root,\
    \ xl, xr, fid, L, R);\n  }\n\n  // (\u5024\u30FB\u95A2\u6570\u756A\u53F7)\n  pair<T,\
    \ int> query(np root, ll x) {\n    assert(L <= x && x < R);\n    if (!root) {\n\
    \      if (MINIMIZE) return {infty<T>, -1};\n      if (!MINIMIZE) return {-infty<T>,\
    \ -1};\n    }\n    return query_rec(root, x, L, R);\n  }\n\nprivate:\n  np copy_node(Node\
    \ *c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].fid = c->fid;\n \
    \   pool[pid].l = c->l, pool[pid].r = c->r;\n    return &(pool[pid++]);\n  }\n\
    \n  inline T evaluate_inner(int fid, ll x) {\n    if (fid == -1) { return (MINIMIZE\
    \ ? infty<T> : -infty<T>); };\n    return evaluate(funcs[fid], x);\n  }\n\n  np\
    \ add_segment_rec(np c, ll xl, ll xr, int fid, ll node_l, ll node_r) {\n    chmax(xl,\
    \ node_l), chmin(xr, node_r);\n    if (xl >= xr) return c;\n    if (node_l < xl\
    \ || xr < node_r) {\n      c = copy_node(c);\n      ll node_m = (node_l + node_r)\
    \ / 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r) c->r = new_node();\n\
    \      c->l = add_segment_rec(c->l, xl, xr, fid, node_l, node_m);\n      c->r\
    \ = add_segment_rec(c->r, xl, xr, fid, node_m, node_r);\n      return c;\n   \
    \ }\n    return add_line_rec(c, fid, node_l, node_r);\n  }\n\n  np add_line_rec(np\
    \ c, int fid, ll node_l, ll node_r) {\n    int gid = c->fid;\n    T fl = evaluate_inner(fid,\
    \ node_l), fr = evaluate_inner(fid, node_r - 1);\n    T gl = evaluate_inner(gid,\
    \ node_l), gr = evaluate_inner(gid, node_r - 1);\n    bool bl = (MINIMIZE ? fl\
    \ < gl : fl > gl);\n    bool br = (MINIMIZE ? fr < gr : fr > gr);\n    if (bl\
    \ && br) {\n      c = copy_node(c);\n      c->fid = fid;\n      return c;\n  \
    \  }\n    if (!bl && !br) { return c; }\n\n    c = copy_node(c);\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    auto fm = evaluate_inner(fid, node_m), gm = evaluate_inner(gid,\
    \ node_m);\n    bool bm = (MINIMIZE ? fm < gm : fm > gm);\n    if (bm) {\n   \
    \   c->fid = fid;\n      if (bl) {\n        if (!c->r) c->r = new_node();\n  \
    \      c->r = add_line_rec(c->r, gid, node_m, node_r);\n      } else {\n     \
    \   if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l, gid, node_l,\
    \ node_m);\n      }\n    }\n    if (!bm) {\n      if (!bl) {\n        if (!c->r)\
    \ c->r = new_node();\n        c->r = add_line_rec(c->r, fid, node_m, node_r);\n\
    \      } else {\n        if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l,\
    \ fid, node_l, node_m);\n      }\n    }\n    return c;\n  }\n\n  pair<T, int>\
    \ query_rec(np c, ll x, ll node_l, ll node_r) {\n    int fid = c->fid;\n    pair<T,\
    \ int> res = {evaluate_inner(fid, x), fid};\n    ll node_m = (node_l + node_r)\
    \ / 2;\n    if (x < node_m && c->l) {\n      pair<T, int> res1 = query_rec(c->l,\
    \ x, node_l, node_m);\n      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n\
    \    }\n    if (x >= node_m && c->r) {\n      pair<T, int> res1 = query_rec(c->r,\
    \ x, node_m, node_r);\n      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n\
    \    }\n    return res;\n  }\n};\n#line 5 \"main.cpp\"\n\nstruct F {\n  using\
    \ value_type = ll; // operator() \u306E\u623B\u308A\u5024\n  int a;\n  ll b;\n\
    \  ll operator()(ll x) { return a * x + b; }\n};\n\nvoid solve() {\n  LL(N, Q);\n\
    \  Dynamic_LiChao_Tree<F, 0, 15'000'000, 1> X(-infty<int>, infty<int>);\n  using\
    \ np = decltype(X)::np;\n  np root = X.new_root();\n  FOR(N) {\n    LL(l, r, a,\
    \ b);\n    root = X.add_segment(root, l, r, {a, b});\n  }\n  vc<int> points;\n\
    \  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      LL(l, r, a, b);\n      root\
    \ = X.add_segment(root, l, r, {a, b});\n    }\n    if (t == 1) {\n      INT(x);\n\
    \      auto [fval, fid] = X.query(root, x);\n      if (fid == -1) print(\"INFINITY\"\
    );\n      if (fid != -1) print(fval);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return B;\n}\n#endif\n#line 1 \"library/other/io.hpp\"\n#define FASTIO\n#include\
    \ <unistd.h>\n\n// https://judge.yosupo.jp/submission/21623\nnamespace fastio\
    \ {\nstatic constexpr uint32_t SZ = 1 << 17;\nchar ibuf[SZ];\nchar obuf[SZ];\n\
    char out[100];\n// pointer of ibuf, obuf\nuint32_t pil = 0, pir = 0, por = 0;\n\
    \nstruct Pre {\n  char num[10000][4];\n  constexpr Pre() : num() {\n    for (int\
    \ i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >= 0; j--)\
    \ {\n        num[i][j] = n % 10 | '0';\n        n /= 10;\n      }\n    }\n  }\n\
    } constexpr pre;\n\ninline void load() {\n  memcpy(ibuf, ibuf + pil, pir - pil);\n\
    \  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\n  pil\
    \ = 0;\n  if (pir < SZ) ibuf[pir++] = '\\n';\n}\n\ninline void flush() {\n  fwrite(obuf,\
    \ 1, por, stdout);\n  por = 0;\n}\n\nvoid rd(char &c) {\n  do {\n    if (pil +\
    \ 1 > pir) load();\n    c = ibuf[pil++];\n  } while (isspace(c));\n}\n\nvoid rd(string\
    \ &x) {\n  x.clear();\n  char c;\n  do {\n    if (pil + 1 > pir) load();\n   \
    \ c = ibuf[pil++];\n  } while (isspace(c));\n  do {\n    x += c;\n    if (pil\
    \ == pir) load();\n    c = ibuf[pil++];\n  } while (!isspace(c));\n}\n\ntemplate\
    \ <typename T>\nvoid rd_real(T &x) {\n  string s;\n  rd(s);\n  x = stod(s);\n\
    }\n\ntemplate <typename T>\nvoid rd_integer(T &x) {\n  if (pil + 100 > pir) load();\n\
    \  char c;\n  do\n    c = ibuf[pil++];\n  while (c < '-');\n  bool minus = 0;\n\
    \  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\n    if (c == '-')\
    \ { minus = 1, c = ibuf[pil++]; }\n  }\n  x = 0;\n  while ('0' <= c) { x = x *\
    \ 10 + (c & 15), c = ibuf[pil++]; }\n  if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\n    if (minus) x = -x;\n  }\n}\n\nvoid rd(int &x) { rd_integer(x);\
    \ }\nvoid rd(ll &x) { rd_integer(x); }\nvoid rd(i128 &x) { rd_integer(x); }\n\
    void rd(u32 &x) { rd_integer(x); }\nvoid rd(u64 &x) { rd_integer(x); }\nvoid rd(u128\
    \ &x) { rd_integer(x); }\nvoid rd(double &x) { rd_real(x); }\nvoid rd(long double\
    \ &x) { rd_real(x); }\nvoid rd(f128 &x) { rd_real(x); }\n\ntemplate <class T,\
    \ class U>\nvoid rd(pair<T, U> &p) {\n  return rd(p.first), rd(p.second);\n}\n\
    template <size_t N = 0, typename T>\nvoid rd_tuple(T &t) {\n  if constexpr (N\
    \ < std::tuple_size<T>::value) {\n    auto &x = std::get<N>(t);\n    rd(x);\n\
    \    rd_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid rd(tuple<T...> &tpl)\
    \ {\n  rd_tuple(tpl);\n}\n\ntemplate <size_t N = 0, typename T>\nvoid rd(array<T,\
    \ N> &x) {\n  for (auto &d: x) rd(d);\n}\ntemplate <class T>\nvoid rd(vc<T> &x)\
    \ {\n  for (auto &d: x) rd(d);\n}\n\nvoid read() {}\ntemplate <class H, class...\
    \ T>\nvoid read(H &h, T &... t) {\n  rd(h), read(t...);\n}\n\nvoid wt(const char\
    \ c) {\n  if (por == SZ) flush();\n  obuf[por++] = c;\n}\nvoid wt(const string\
    \ s) {\n  for (char c: s) wt(c);\n}\nvoid wt(const char *s) {\n  size_t len =\
    \ strlen(s);\n  for (size_t i = 0; i < len; i++) wt(s[i]);\n}\n\ntemplate <typename\
    \ T>\nvoid wt_integer(T x) {\n  if (por > SZ - 100) flush();\n  if (x < 0) { obuf[por++]\
    \ = '-', x = -x; }\n  int outi;\n  for (outi = 96; x >= 10000; outi -= 4) {\n\
    \    memcpy(out + outi, pre.num[x % 10000], 4);\n    x /= 10000;\n  }\n  if (x\
    \ >= 1000) {\n    memcpy(obuf + por, pre.num[x], 4);\n    por += 4;\n  } else\
    \ if (x >= 100) {\n    memcpy(obuf + por, pre.num[x] + 1, 3);\n    por += 3;\n\
    \  } else if (x >= 10) {\n    int q = (x * 103) >> 10;\n    obuf[por] = q | '0';\n\
    \    obuf[por + 1] = (x - q * 10) | '0';\n    por += 2;\n  } else\n    obuf[por++]\
    \ = x | '0';\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\n  por += 96 -\
    \ outi;\n}\n\ntemplate <typename T>\nvoid wt_real(T x) {\n  ostringstream oss;\n\
    \  oss << fixed << setprecision(15) << double(x);\n  string s = oss.str();\n \
    \ wt(s);\n}\n\nvoid wt(int x) { wt_integer(x); }\nvoid wt(ll x) { wt_integer(x);\
    \ }\nvoid wt(i128 x) { wt_integer(x); }\nvoid wt(u32 x) { wt_integer(x); }\nvoid\
    \ wt(u64 x) { wt_integer(x); }\nvoid wt(u128 x) { wt_integer(x); }\nvoid wt(double\
    \ x) { wt_real(x); }\nvoid wt(long double x) { wt_real(x); }\nvoid wt(f128 x)\
    \ { wt_real(x); }\n\ntemplate <class T, class U>\nvoid wt(const pair<T, U> val)\
    \ {\n  wt(val.first);\n  wt(' ');\n  wt(val.second);\n}\ntemplate <size_t N =\
    \ 0, typename T>\nvoid wt_tuple(const T t) {\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\n    if constexpr (N > 0) { wt(' '); }\n    const auto x = std::get<N>(t);\n\
    \    wt(x);\n    wt_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid wt(tuple<T...>\
    \ tpl) {\n  wt_tuple(tpl);\n}\ntemplate <class T, size_t S>\nvoid wt(const array<T,\
    \ S> val) {\n  auto n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if\
    \ (i) wt(' ');\n    wt(val[i]);\n  }\n}\ntemplate <class T>\nvoid wt(const vector<T>\
    \ val) {\n  auto n = val.size();\n  for (size_t i = 0; i < n; i++) {\n    if (i)\
    \ wt(' ');\n    wt(val[i]);\n  }\n}\n\nvoid print() { wt('\\n'); }\ntemplate <class\
    \ Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail) {\n  wt(head);\n\
    \  if (sizeof...(Tail)) wt(' ');\n  print(forward<Tail>(tail)...);\n}\n\n// gcc\
    \ expansion. called automaticall after main.\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n} // namespace fastio\nusing fastio::read;\nusing fastio::print;\n\
    using fastio::flush;\n\n#if defined(LOCAL)\n#define SHOW(...) \\\n  SHOW_IMPL(__VA_ARGS__,\
    \ SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\n#define SHOW_IMPL(_1, _2, _3, _4,\
    \ NAME, ...) NAME\n#define SHOW1(x) print(#x, \"=\", (x)), flush()\n#define SHOW2(x,\
    \ y) print(#x, \"=\", (x), #y, \"=\", (y)), flush()\n#define SHOW3(x, y, z) print(#x,\
    \ \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)), flush()\n#define SHOW4(x, y, z,\
    \ w) \\\n  print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w)),\
    \ flush()\n#else\n#define SHOW(...)\n#endif\n\n#define INT(...)   \\\n  int __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n#define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define U32(...)   \\\n  u32 __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define U64(...)\
    \   \\\n  u64 __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)      \\\n\
    \  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)   \\\n  char\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n  double __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size) \\\n  vector<type>\
    \ name(size);    \\\n  read(name)\n#define VV(type, name, h, w)              \
    \       \\\n  vector<vector<type>> name(h, vector<type>(w)); \\\n  read(name)\n\
    \nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\nvoid NO(bool t = 1) {\
    \ YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\nvoid No(bool\
    \ t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\n\
    void no(bool t = 1) { yes(!t); }\n#line 1 \"library/convex/dynamic_lichao.hpp\"\
    \n/*\nstruct F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\u5024\
    \n  int a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n*/\n\n//\
    \ \u76F4\u7DDA\u8FFD\u52A0\u304B\u3064\u975E\u6C38\u7D9A\u306A\u3089\u7A7A\u9593\
    \ Q \u3067\u3088\u3044\u3002\n// \u95A2\u6570\u306F ll -> T\u3002[L, R) \u4E0A\
    \ f \u304C overflow \u3057\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u3002\n//\
    \ evaluate \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\u3001totally monotone \u306A\
    \u95A2\u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\ntemplate <typename FUNC, bool\
    \ PERSISTENT, int NODES, bool MINIMIZE>\nstruct Dynamic_LiChao_Tree {\n  using\
    \ T = typename FUNC::value_type;\n  vc<FUNC> funcs;\n\n  static inline T evaluate(FUNC\
    \ &f, ll x) { return f(x); }\n\n  struct Node {\n    int fid;\n    Node *l, *r;\n\
    \  };\n\n  Node *pool;\n  int pid;\n  ll L, R;\n\n  using np = Node *;\n\n  Dynamic_LiChao_Tree(ll\
    \ L, ll R) : pid(0), L(L), R(R) {\n    pool = new Node[NODES];\n  }\n\n  void\
    \ reset() {\n    funcs.clear();\n    pid = 0;\n  }\n\n  np new_root() { return\
    \ nullptr; }\n\n  np new_node() {\n    pool[pid].fid = -1;\n    pool[pid].l =\
    \ nullptr, pool[pid].r = nullptr;\n    return &(pool[pid++]);\n  }\n\n  np add_line(np\
    \ root, FUNC f) {\n    int fid = len(funcs);\n    funcs.eb(f);\n    if (!root)\
    \ root = new_node();\n    return add_line_rec(root, fid, L, R);\n  }\n\n  // [xl,\
    \ xr)\n  np add_segment(np root, ll xl, ll xr, FUNC f) {\n    int fid = len(funcs);\n\
    \    funcs.eb(f);\n    if (!root) root = new_node();\n    return add_segment_rec(root,\
    \ xl, xr, fid, L, R);\n  }\n\n  // (\u5024\u30FB\u95A2\u6570\u756A\u53F7)\n  pair<T,\
    \ int> query(np root, ll x) {\n    assert(L <= x && x < R);\n    if (!root) {\n\
    \      if (MINIMIZE) return {infty<T>, -1};\n      if (!MINIMIZE) return {-infty<T>,\
    \ -1};\n    }\n    return query_rec(root, x, L, R);\n  }\n\nprivate:\n  np copy_node(Node\
    \ *c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].fid = c->fid;\n \
    \   pool[pid].l = c->l, pool[pid].r = c->r;\n    return &(pool[pid++]);\n  }\n\
    \n  inline T evaluate_inner(int fid, ll x) {\n    if (fid == -1) { return (MINIMIZE\
    \ ? infty<T> : -infty<T>); };\n    return evaluate(funcs[fid], x);\n  }\n\n  np\
    \ add_segment_rec(np c, ll xl, ll xr, int fid, ll node_l, ll node_r) {\n    chmax(xl,\
    \ node_l), chmin(xr, node_r);\n    if (xl >= xr) return c;\n    if (node_l < xl\
    \ || xr < node_r) {\n      c = copy_node(c);\n      ll node_m = (node_l + node_r)\
    \ / 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r) c->r = new_node();\n\
    \      c->l = add_segment_rec(c->l, xl, xr, fid, node_l, node_m);\n      c->r\
    \ = add_segment_rec(c->r, xl, xr, fid, node_m, node_r);\n      return c;\n   \
    \ }\n    return add_line_rec(c, fid, node_l, node_r);\n  }\n\n  np add_line_rec(np\
    \ c, int fid, ll node_l, ll node_r) {\n    int gid = c->fid;\n    T fl = evaluate_inner(fid,\
    \ node_l), fr = evaluate_inner(fid, node_r - 1);\n    T gl = evaluate_inner(gid,\
    \ node_l), gr = evaluate_inner(gid, node_r - 1);\n    bool bl = (MINIMIZE ? fl\
    \ < gl : fl > gl);\n    bool br = (MINIMIZE ? fr < gr : fr > gr);\n    if (bl\
    \ && br) {\n      c = copy_node(c);\n      c->fid = fid;\n      return c;\n  \
    \  }\n    if (!bl && !br) { return c; }\n\n    c = copy_node(c);\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    auto fm = evaluate_inner(fid, node_m), gm = evaluate_inner(gid,\
    \ node_m);\n    bool bm = (MINIMIZE ? fm < gm : fm > gm);\n    if (bm) {\n   \
    \   c->fid = fid;\n      if (bl) {\n        if (!c->r) c->r = new_node();\n  \
    \      c->r = add_line_rec(c->r, gid, node_m, node_r);\n      } else {\n     \
    \   if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l, gid, node_l,\
    \ node_m);\n      }\n    }\n    if (!bm) {\n      if (!bl) {\n        if (!c->r)\
    \ c->r = new_node();\n        c->r = add_line_rec(c->r, fid, node_m, node_r);\n\
    \      } else {\n        if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l,\
    \ fid, node_l, node_m);\n      }\n    }\n    return c;\n  }\n\n  pair<T, int>\
    \ query_rec(np c, ll x, ll node_l, ll node_r) {\n    int fid = c->fid;\n    pair<T,\
    \ int> res = {evaluate_inner(fid, x), fid};\n    ll node_m = (node_l + node_r)\
    \ / 2;\n    if (x < node_m && c->l) {\n      pair<T, int> res1 = query_rec(c->l,\
    \ x, node_l, node_m);\n      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n\
    \    }\n    if (x >= node_m && c->r) {\n      pair<T, int> res1 = query_rec(c->r,\
    \ x, node_m, node_r);\n      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n\
    \    }\n    return res;\n  }\n};\n#line 5 \"main.cpp\"\n\nstruct F {\n  using\
    \ value_type = ll; // operator() \u306E\u623B\u308A\u5024\n  int a;\n  ll b;\n\
    \  ll operator()(ll x) { return a * x + b; }\n};\n\nvoid solve() {\n  LL(N, Q);\n\
    \  Dynamic_LiChao_Tree<F, 0, 15'000'000, 1> X(-infty<int>, infty<int>);\n  using\
    \ np = decltype(X)::np;\n  np root = X.new_root();\n  FOR(N) {\n    LL(l, r, a,\
    \ b);\n    root = X.add_segment(root, l, r, {a, b});\n  }\n  vc<int> points;\n\
    \  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      LL(l, r, a, b);\n      root\
    \ = X.add_segment(root, l, r, {a, b});\n    }\n    if (t == 1) {\n      INT(x);\n\
    \      auto [fval, fid] = X.query(root, x);\n      if (fid == -1) print(\"INFINITY\"\
    );\n      if (fid != -1) print(fval);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2024-06-17 07:14:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/segment_add_get_min.test.cpp
- /verify/test/library_checker/datastructure/segment_add_get_min.test.cpp.html
title: test/library_checker/datastructure/segment_add_get_min.test.cpp
---
