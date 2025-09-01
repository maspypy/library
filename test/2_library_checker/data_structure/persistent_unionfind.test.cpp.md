---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/dynamic_array.hpp
    title: ds/dynamic_array.hpp
  - icon: ':x:'
    path: ds/unionfind/dynamic_unionfind.hpp
    title: ds/unionfind/dynamic_unionfind.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\
    #line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
    #if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
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
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(),\
    \ T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/2_library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n\r\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n#include <unistd.h>\r\n\r\n\
    // https://judge.yosupo.jp/submission/21623\r\nnamespace fastio {\r\nstatic constexpr\
    \ uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar out[100];\r\
    \n// pointer of ibuf, obuf\r\nuint32_t pil = 0, pir = 0, por = 0;\r\n\r\nstruct\
    \ Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num() {\r\n    for (int\
    \ i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for (int j = 3; j >= 0;\
    \ j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n /= 10;\r\n      }\r\
    \n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n  memcpy(ibuf,\
    \ ibuf + pil, pir - pil);\r\n  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ\
    \ - pir + pil, stdin);\r\n  pil = 0;\r\n  if (pir < SZ) ibuf[pir++] = '\\n';\r\
    \n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf, 1, por, stdout);\r\n  por =\
    \ 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do {\r\n    if (pil + 1 > pir) load();\r\
    \n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n}\r\n\r\nvoid rd(string &x)\
    \ {\r\n  x.clear();\r\n  char c;\r\n  do {\r\n    if (pil + 1 > pir) load();\r\
    \n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n  do {\r\n    x += c;\r\n\
    \    if (pil == pir) load();\r\n    c = ibuf[pil++];\r\n  } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n  string s;\r\n  rd(s);\r\
    \n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_integer(T &x) {\r\
    \n  if (pil + 100 > pir) load();\r\n  char c;\r\n  do\r\n    c = ibuf[pil++];\r\
    \n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (c == '-') { minus = 1, c = ibuf[pil++];\
    \ }\r\n  }\r\n  x = 0;\r\n  while ('0' <= c) { x = x * 10 + (c & 15), c = ibuf[pil++];\
    \ }\r\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if\
    \ (minus) x = -x;\r\n  }\r\n}\r\n\r\nvoid rd(int &x) { rd_integer(x); }\r\nvoid\
    \ rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double &x) { rd_real(x); }\r\nvoid\
    \ rd(long double &x) { rd_real(x); }\r\nvoid rd(f128 &x) { rd_real(x); }\r\n\r\
    \ntemplate <class T, class U>\r\nvoid rd(pair<T, U> &p) {\r\n  return rd(p.first),\
    \ rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd_tuple(T\
    \ &t) {\r\n  if constexpr (N < std::tuple_size<T>::value) {\r\n    auto &x = std::get<N>(t);\r\
    \n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\
    \nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t\
    \ N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n  for (auto &d: x) rd(d);\r\
    \n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\n  for (auto &d: x) rd(d);\r\
    \n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class... T>\r\nvoid read(H &h,\
    \ T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n\
    \  if (por == SZ) flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const string\
    \ s) {\r\n  for (char c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n  size_t\
    \ len = strlen(s);\r\n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n}\r\n\r\n\
    template <typename T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100) flush();\r\
    \n  if (x < 0) { obuf[por++] = '-', x = -x; }\r\n  int outi;\r\n  for (outi =\
    \ 96; x >= 10000; outi -= 4) {\r\n    memcpy(out + outi, pre.num[x % 10000], 4);\r\
    \n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf + por, pre.num[x],\
    \ 4);\r\n    por += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf + por, pre.num[x]\
    \ + 1, 3);\r\n    por += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103)\
    \ >> 10;\r\n    obuf[por] = q | '0';\r\n    obuf[por + 1] = (x - q * 10) | '0';\r\
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
    \nusing fastio::flush;\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...) SHOW_IMPL(__VA_ARGS__,\
    \ SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\r\n#define SHOW_IMPL(_1,\
    \ _2, _3, _4, _5, _6, NAME, ...) NAME\r\n#define SHOW1(x) print(#x, \"=\", (x)),\
    \ flush()\r\n#define SHOW2(x, y) print(#x, \"=\", (x), #y, \"=\", (y)), flush()\r\
    \n#define SHOW3(x, y, z) print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)),\
    \ flush()\r\n#define SHOW4(x, y, z, w) print(#x, \"=\", (x), #y, \"=\", (y), #z,\
    \ \"=\", (z), #w, \"=\", (w)), flush()\r\n#define SHOW5(x, y, z, w, v) print(#x,\
    \ \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", (v)),\
    \ flush()\r\n#define SHOW6(x, y, z, w, v, u) print(#x, \"=\", (x), #y, \"=\",\
    \ (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", (v), #u, \"=\", (u)), flush()\r\
    \n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n\
    \  read(__VA_ARGS__)\r\n#define U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define U64(...)   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ CHAR(...)   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)\
    \      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\nvoid YA(bool t = 1) { print(t ? \"YA\" : \"TIDAK\"); }\r\nvoid\
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 5 \"test/2_library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n\r\n#line 2 \"ds/dynamic_array.hpp\"\n\r\ntemplate <typename T, bool PERSISTENT>\r\
    \nstruct Dynamic_Array {\r\n  static constexpr int LOG = 4;\r\n  static constexpr\
    \ int MASK = (1 << LOG) - 1;\r\n  struct Node {\r\n    T x;\r\n    Node* ch[1\
    \ << LOG] = {};\r\n  };\r\n  const int NODES;\r\n  Node* pool;\r\n  int pid;\r\
    \n  using np = Node*;\r\n  const T x0;\r\n\r\n  Dynamic_Array(int NODES, T default_value)\
    \ : NODES(NODES), pid(0), x0(default_value) { pool = new Node[NODES]; }\r\n  ~Dynamic_Array()\
    \ { delete[] pool; }\r\n  np new_root() {\r\n    pool[pid].x = x0;\r\n    fill(pool[pid].ch,\
    \ pool[pid].ch + (1 << LOG), nullptr);\r\n    return &(pool[pid++]);\r\n  }\r\n\
    \r\n  np new_node(vc<T> dat) {\r\n    np root = new_root();\r\n    FOR(i, len(dat))\
    \ root = set(root, i, dat[i], false);\r\n    return root;\r\n  }\r\n\r\n  T get(np\
    \ c, int idx) {\r\n    if (!c) return x0;\r\n    if (idx == 0) return c->x;\r\n\
    \    return get(c->ch[idx & MASK], (idx - 1) >> LOG);\r\n  }\r\n\r\n  np set(np\
    \ c, int idx, T x, bool make_copy = true) {\r\n    c = (c ? copy_node(c, make_copy)\
    \ : new_root());\r\n    if (idx == 0) {\r\n      c->x = x;\r\n      return c;\r\
    \n    }\r\n    c->ch[idx & MASK] = set(c->ch[idx & MASK], (idx - 1) >> LOG, x);\r\
    \n    return c;\r\n  }\r\n\r\nprivate:\r\n  np copy_node(np c, bool make_copy)\
    \ {\r\n    if (!make_copy || !PERSISTENT) return c;\r\n    pool[pid].x = c->x;\r\
    \n    FOR(k, (1 << LOG)) pool[pid].ch[k] = c->ch[k];\r\n    return &(pool[pid++]);\r\
    \n  }\r\n};\r\n#line 2 \"ds/unionfind/dynamic_unionfind.hpp\"\n\r\ntemplate <bool\
    \ PERSISTENT>\r\nstruct Dynamic_UnionFind {\r\n  // \u7D4C\u8DEF\u5727\u7E2E\u306A\
    \u3057\r\n  Dynamic_Array<int, PERSISTENT> PA;\r\n  using np = typename decltype(PA)::np;\r\
    \n\r\n  Dynamic_UnionFind(int N) : PA(15 * N, -1) {}\r\n\r\n  np new_root() {\
    \ return PA.new_root(); }\r\n\r\n  int root(np c, int x) {\r\n    while (1) {\r\
    \n      int p = PA.get(c, x);\r\n      assert(x != p);\r\n      if (p < 0) break;\r\
    \n      x = p;\r\n    }\r\n    return x;\r\n  }\r\n\r\n  pair<np, bool> merge(np\
    \ c, int x, int y) {\r\n    x = root(c, x), y = root(c, y);\r\n    if (x == y)\
    \ return {c, false};\r\n    if (-PA.get(c, x) < -PA.get(c, y)) swap(x, y);\r\n\
    \    int new_sz = PA.get(c, x) + PA.get(c, y);\r\n    c = PA.set(c, x, new_sz);\r\
    \n    assert(PA.get(c, x) == new_sz);\r\n    c = PA.set(c, y, x);\r\n    assert(PA.get(c,\
    \ y) == x);\r\n    return {c, true};\r\n  }\r\n\r\n  ll size(np c, int x) { return\
    \ -PA.get(c, root(c, x)); }\r\n};\r\n#line 7 \"test/2_library_checker/data_structure/persistent_unionfind.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n\r\n  Dynamic_UnionFind<true> uf(Q);\r\n\
    \  using np = typename decltype(uf)::np;\r\n  vc<np> roots;\r\n\r\n  roots.eb(uf.new_root());\r\
    \n\r\n  FOR(Q) {\r\n    LL(t, k, u, v);\r\n    ++k;\r\n    auto root = roots[k];\r\
    \n    if (t == 0) {\r\n      root = uf.merge(root, u, v).fi;\r\n    } else {\r\
    \n      bool ok = uf.root(root, u) == uf.root(root, v);\r\n      print(ok ? 1\
    \ : 0);\r\n    }\r\n    roots.eb(root);\r\n  }\r\n}\r\n\r\nsigned main() {\r\n\
    \  solve();\r\n\r\n  return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n#include \"my_template.hpp\"\r\n\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"ds/unionfind/dynamic_unionfind.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\
    \n\r\n  Dynamic_UnionFind<true> uf(Q);\r\n  using np = typename decltype(uf)::np;\r\
    \n  vc<np> roots;\r\n\r\n  roots.eb(uf.new_root());\r\n\r\n  FOR(Q) {\r\n    LL(t,\
    \ k, u, v);\r\n    ++k;\r\n    auto root = roots[k];\r\n    if (t == 0) {\r\n\
    \      root = uf.merge(root, u, v).fi;\r\n    } else {\r\n      bool ok = uf.root(root,\
    \ u) == uf.root(root, v);\r\n      print(ok ? 1 : 0);\r\n    }\r\n    roots.eb(root);\r\
    \n  }\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return 0;\r\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/unionfind/dynamic_unionfind.hpp
  - ds/dynamic_array.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 19:47:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/persistent_unionfind.test.cpp
- /verify/test/2_library_checker/data_structure/persistent_unionfind.test.cpp.html
title: test/2_library_checker/data_structure/persistent_unionfind.test.cpp
---
