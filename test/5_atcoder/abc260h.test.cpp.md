---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/blackbox/pascal.hpp
    title: linalg/blackbox/pascal.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/blackbox/vandermonde.hpp
    title: linalg/blackbox/vandermonde.hpp
  - icon: ':heavy_check_mark:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  - icon: ':heavy_check_mark:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':heavy_check_mark:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':heavy_check_mark:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  - icon: ':heavy_check_mark:'
    path: poly/transposed_ntt.hpp
    title: poly/transposed_ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc260/tasks/abc260_Ex
    links:
    - https://atcoder.jp/contests/abc260/tasks/abc260_Ex
  bundledCode: "#line 1 \"test/5_atcoder/abc260h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc260/tasks/abc260_Ex\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\n\
    template <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128\
    \ infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n\
    #include <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\nnamespace\
    \ fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar\
    \ obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil = 0,\
    \ pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr\
    \ Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\
    \n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n\
    \        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline\
    \ void load() {\r\n  memcpy(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil\
    \ + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n  if (pir\
    \ < SZ) ibuf[pir++] = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf,\
    \ 1, por, stdout);\r\n  por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do {\r\n\
    \    if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\
    \n}\r\n\r\nvoid rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do {\r\n   \
    \ if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\
    \n  do {\r\n    x += c;\r\n    if (pil == pir) load();\r\n    c = ibuf[pil++];\r\
    \n  } while (!isspace(c));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T\
    \ &x) {\r\n  string s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid rd_integer(T &x) {\r\n  if (pil + 100 > pir) load();\r\n  char c;\r\
    \n  do\r\n    c = ibuf[pil++];\r\n  while (c < '-');\r\n  bool minus = 0;\r\n\
    \  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (c ==\
    \ '-') { minus = 1, c = ibuf[pil++]; }\r\n  }\r\n  x = 0;\r\n  while ('0' <= c)\
    \ { x = x * 10 + (c & 15), c = ibuf[pil++]; }\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\nvoid rd(int\
    \ &x) { rd_integer(x); }\r\nvoid rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128\
    \ &x) { rd_integer(x); }\r\nvoid rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64\
    \ &x) { rd_integer(x); }\r\nvoid rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double\
    \ &x) { rd_real(x); }\r\nvoid rd(long double &x) { rd_real(x); }\r\nvoid rd(f128\
    \ &x) { rd_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid rd(pair<T, U>\
    \ &p) {\r\n  return rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t N = 0,\
    \ typename T>\r\nvoid rd_tuple(T &t) {\r\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n    auto &x = std::get<N>(t);\r\n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\
    \n  }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\
    \n}\r\n\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n\
    \  for (auto &d: x) rd(d);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\
    \n  for (auto &d: x) rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T>\r\nvoid read(H &h, T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n  if (por == SZ) flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const\
    \ string s) {\r\n  for (char c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n\
    \  size_t len = strlen(s);\r\n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n\
    }\r\n\r\ntemplate <typename T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100)\
    \ flush();\r\n  if (x < 0) { obuf[por++] = '-', x = -x; }\r\n  int outi;\r\n \
    \ for (outi = 96; x >= 10000; outi -= 4) {\r\n    memcpy(out + outi, pre.num[x\
    \ % 10000], 4);\r\n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf\
    \ + por, pre.num[x], 4);\r\n    por += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf\
    \ + por, pre.num[x] + 1, 3);\r\n    por += 3;\r\n  } else if (x >= 10) {\r\n \
    \   int q = (x * 103) >> 10;\r\n    obuf[por] = q | '0';\r\n    obuf[por + 1]\
    \ = (x - q * 10) | '0';\r\n    por += 2;\r\n  } else\r\n    obuf[por++] = x |\
    \ '0';\r\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\r\n  por += 96 - outi;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\
    \n  oss << fixed << setprecision(15) << double(x);\r\n  string s = oss.str();\r\
    \n  wt(s);\r\n}\r\n\r\nvoid wt(int x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x);\
    \ }\r\nvoid wt(i128 x) { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\
    \nvoid wt(u64 x) { wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\n\
    void wt(double x) { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\n\
    void wt(f128 x) { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const\
    \ pair<T, U> val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n\
    }\r\ntemplate <size_t N = 0, typename T>\r\nvoid wt_tuple(const T t) {\r\n  if\
    \ constexpr (N < std::tuple_size<T>::value) {\r\n    if constexpr (N > 0) { wt('\
    \ '); }\r\n    const auto x = std::get<N>(t);\r\n    wt(x);\r\n    wt_tuple<N\
    \ + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(tuple<T...> tpl) {\r\
    \n  wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T,\
    \ S> val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n\
    \    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\n\
    void wt(const vector<T> val) {\r\n  auto n = val.size();\r\n  for (size_t i =\
    \ 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\
    \nvoid print() { wt('\\n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head &&head, Tail &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail))\
    \ wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\n// gcc expansion. called\
    \ automaticall after main.\r\nvoid __attribute__((destructor)) _d() { flush();\
    \ }\r\n} // namespace fastio\r\nusing fastio::read;\r\nusing fastio::print;\r\n\
    using fastio::flush;\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...) SHOW_IMPL(__VA_ARGS__,\
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
    \ yes(!t); }\r\n#line 4 \"test/5_atcoder/abc260h.test.cpp\"\n\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact_inv(int n) {\n  static vector<mint> dat\
    \ = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if constexpr (dense) return C_dense<mint>(n,\
    \ k);\n  if constexpr (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k,\
    \ n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint, bool large = false, bool dense\
    \ = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return\
    \ mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint,\
    \ large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int\
    \ mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n  \
    \  modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 836905998};\n    if (mod == 1045430273) return {20,\
    \ 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881)\
    \ return {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt()\
    \ { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"poly/convolution_all.hpp\"\n\r\n#line 2 \"mod/mod_inv.hpp\"\n\r\n//\
    \ long \u3067\u3082\u5927\u4E08\u592B\r\n// (val * x - 1) \u304C mod \u306E\u500D\
    \u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\r\n// \u7279\u306B mod=0\
    \ \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\r\nll mod_inv(ll val, ll mod) {\r\n\
    \  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\n  val %= mod;\r\n  if (val\
    \ < 0) val += mod;\r\n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b >\
    \ 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n\
    \  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n#line 2 \"mod/crt3.hpp\"\
    \n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64\
    \ res = 1;\n  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a %\
    \ mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\n\
    T CRT2(u64 a0, u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1\
    \ = mod_pow_constexpr(p0, p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n\
    \  return a0 + c * p0;\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT\
    \ CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static\
    \ constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  static constexpr u64\
    \ x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n  static constexpr u64\
    \ p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 +\
    \ c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  return T(ans_1) + T(c) *\
    \ T(p01);\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>\n\
    T CRT5(u64 a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0 < p1 && p1\
    \ < p2 && p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 x3\n      = mod_pow_constexpr(u64(p0) *\
    \ p1 % p3 * p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4\n      = mod_pow_constexpr(u64(p0)\
    \ * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0)\
    \ * p1;\n  static constexpr u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3\
    \ - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c *\
    \ p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;\n  return\
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 2 \"poly/convolution_naive.hpp\"\
    \n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\r\
    \nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  if (n > m) return convolution_naive<T>(b, a);\r\n  if\
    \ (n == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  FOR(i, n) FOR(j, m)\
    \ ans[i + j] += a[i] * b[j];\r\n  return ans;\r\n}\r\n\r\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\r\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n > m) return convolution_naive<T>(b, a);\r\n  if (n == 0) return {};\r\
    \n  vc<T> ans(n + m - 1);\r\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\r\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\r\n      int s = max(0, k - m + 1);\r\
    \n      int t = min(n, k + 1);\r\n      u64 sm = 0;\r\n      for (int i = s; i\
    \ < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\n      ans[k] = sm;\r\n\
    \    }\r\n  } else {\r\n    for (int k = 0; k < n + m - 1; ++k) {\r\n      int\
    \ s = max(0, k - m + 1);\r\n      int t = min(n, k + 1);\r\n      u128 sm = 0;\r\
    \n      for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\r\
    \n      ans[k] = T::raw(sm % T::get_mod());\r\n    }\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\r\n\r\n  static\
    \ bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n    root[rank2]\
    \ = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\n    FOR_R(i,\
    \ rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i + 2] * prod;\r\n  \
    \    irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i + 2];\r\n    \
    \  iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n    for (int\
    \ i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] * prod;\r\n  \
    \    irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i + 3];\r\n    \
    \  iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\n \
    \ int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\nnamespace CFFT {\r\nusing real\
    \ = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\r\n  C() : x(0), y(0) {}\r\n\
    \r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline C operator+(const C& c) const\
    \ { return C(x + c.x, y + c.y); }\r\n  inline C operator-(const C& c) const {\
    \ return C(x - c.x, y - c.y); }\r\n  inline C operator*(const C& c) const {\r\n\
    \    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\n\r\n  inline C\
    \ conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI = acosl(-1);\r\n\
    int base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int> rev = {0, 1};\r\
    \n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\n  rev.resize(1\
    \ << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0; i < (1 << nbase);\
    \ i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\r\n  }\r\
    \n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1 << (base + 1));\r\
    \n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\n      rts[i <<\
    \ 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1 << base));\r\n\
    \      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n    }\r\n    ++base;\r\
    \n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n & (n - 1)) ==\
    \ 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\n  int shift\
    \ = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i < (rev[i] >>\
    \ shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int k = 1; k <\
    \ n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n      for (int\
    \ j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\n       \
    \ a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n      }\r\
    \n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 9 \"poly/convolution.hpp\"\n\
    \r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  if (a.empty() || b.empty()) return {};\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\
    \r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\
    \u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\
    \u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.resize(n + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\
    \n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  }\
    \ else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\
    \n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b)\
    \ {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ constexpr int p0 = 167772161;\r\n  static constexpr int p1 = 469762049;\r\n\
    \  static constexpr int p2 = 754974721;\r\n  using mint0 = modint<p0>;\r\n  using\
    \ mint1 = modint<p1>;\r\n  using mint2 = modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\
    \n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i]\
    \ = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val,\
    \ b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  vc<mint> c(len(c0));\r\n  FOR(i, n + m - 1) { c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val); }\r\n  return c;\r\n}\r\n\r\ntemplate\
    \ <typename R>\r\nvc<double> convolution_fft(const vc<R>& a, const vc<R>& b) {\r\
    \n  using C = CFFT::C;\r\n  int need = (int)a.size() + (int)b.size() - 1;\r\n\
    \  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  CFFT::ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    double x = (i < (int)a.size() ? a[i] : 0);\r\n    double y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) { ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x); }\r\n  return\
    \ ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a, const vector<ll>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 2500) return convolution_naive(a, b);\r\n  ll abs_sum_a = 0, abs_sum_b\
    \ = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM, abs_sum_a + abs(a[i]));\r\
    \n  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\n  if (i128(abs_sum_a)\
    \ * abs_sum_b < 1e15) {\r\n    vc<double> c = convolution_fft<ll>(a, b);\r\n \
    \   vc<ll> res(len(c));\r\n    FOR(i, len(c)) res[i] = ll(floor(c[i] + .5));\r\
    \n    return res;\r\n  }\r\n\r\n  static constexpr u32 MOD1 = 167772161; // 2^25\r\
    \n  static constexpr u32 MOD2 = 469762049; // 2^26\r\n  static constexpr u32 MOD3\
    \ = 754974721; // 2^24\r\n\r\n  using mint1 = modint<MOD1>;\r\n  using mint2 =\
    \ modint<MOD2>;\r\n  using mint3 = modint<MOD3>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\
    \n  vc<mint2> a2(n), b2(m);\r\n  vc<mint3> a3(n), b3(m);\r\n  FOR(i, n) a1[i]\
    \ = a[i], a2[i] = a[i], a3[i] = a[i];\r\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i],\
    \ b3[i] = b[i];\r\n\r\n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2\
    \ = convolution_ntt<mint2>(a2, b2);\r\n  auto c3 = convolution_ntt<mint3>(a3,\
    \ b3);\r\n\r\n  u128 prod = u128(MOD1) * MOD2 * MOD3;\r\n  vc<ll> res(n + m -\
    \ 1);\r\n  FOR(i, n + m - 1) {\r\n    u128 x = CRT3<u128, MOD1, MOD2, MOD3>(c1[i].val,\
    \ c2[i].val, c3[i].val);\r\n    res[i] = (x < prod / 2 ? ll(x) : -ll(prod - x));\r\
    \n  }\r\n  return res;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> convolution(const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (mint::can_ntt()) {\r\n    if (min(n, m) <= 50) return\
    \ convolution_karatsuba<mint>(a, b);\r\n    return convolution_ntt(a, b);\r\n\
    \  }\r\n  if (min(n, m) <= 200) return convolution_karatsuba<mint>(a, b);\r\n\
    \  return convolution_garner(a, b);\r\n}\r\n#line 2 \"poly/ntt_doubling.hpp\"\n\
    \n#line 4 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\u591A\u9805\u5F0F\u306E\u9577\
    \u3055 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\u3067 2^k+1 \u306B\u3059\
    \u308B\ntemplate <typename mint, bool transposed = false>\nvoid ntt_doubling(vector<mint>&\
    \ a) {\n  static array<mint, 30> root;\n  static bool prepared = 0;\n  if (!prepared)\
    \ {\n    prepared = 1;\n    const int rank2 = mint::ntt_info().fi;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    FOR_R(i, rank2) { root[i] = root[i + 1] * root[i\
    \ + 1]; }\n  }\n\n  if constexpr (!transposed) {\n    const int M = (int)a.size();\n\
    \    auto b = a;\n    ntt(b, 1);\n    mint r = 1, zeta = root[topbit(2 * M)];\n\
    \    FOR(i, M) b[i] *= r, r *= zeta;\n    ntt(b, 0);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  } else {\n    const int M = len(a) / 2;\n    vc<mint>\
    \ tmp = {a.begin(), a.begin() + M};\n    a = {a.begin() + M, a.end()};\n    transposed_ntt(a,\
    \ 0);\n    mint r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r\
    \ *= zeta;\n    transposed_ntt(a, 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n\
    #line 5 \"poly/convolution_all.hpp\"\n\r\ntemplate <typename T>\r\nvc<T> convolution_all(vc<vc<T>>&\
    \ polys) {\r\n  if (len(polys) == 0) return {T(1)};\r\n  while (1) {\r\n    int\
    \ n = len(polys);\r\n    if (n == 1) break;\r\n    int m = ceil(n, 2);\r\n   \
    \ FOR(i, m) {\r\n      if (2 * i + 1 == n) {\r\n        polys[i] = polys[2 * i];\r\
    \n      } else {\r\n        polys[i] = convolution(polys[2 * i], polys[2 * i +\
    \ 1]);\r\n      }\r\n    }\r\n    polys.resize(m);\r\n  }\r\n  return polys[0];\r\
    \n}\r\n\r\n// product of 1-A[i]x\r\ntemplate <typename mint>\r\nvc<mint> convolution_all_1(vc<mint>\
    \ A) {\r\n  if (!mint::can_ntt()) {\r\n    vvc<mint> polys;\r\n    for (auto&\
    \ a: A) polys.eb(vc<mint>({mint(1), -a}));\r\n    return convolution_all(polys);\r\
    \n  }\r\n  int D = 6;\r\n  using poly = vc<mint>;\r\n  int n = 1;\r\n  while (n\
    \ < len(A)) n *= 2;\r\n  int k = topbit(n);\r\n  vc<mint> F(n), nxt_F(n);\r\n\
    \  FOR(i, len(A)) F[i] = -A[i];\r\n  FOR(d, k) {\r\n    int b = 1 << d;\r\n  \
    \  if (d < D) {\r\n      fill(all(nxt_F), mint(0));\r\n      for (int L = 0; L\
    \ < n; L += 2 * b) {\r\n        FOR(i, b) FOR(j, b) { nxt_F[L + i + j] += F[L\
    \ + i] * F[L + b + j]; }\r\n        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L\
    \ + b + i];\r\n      }\r\n    }\r\n    elif (d == D) {\r\n      for (int L = 0;\
    \ L < n; L += 2 * b) {\r\n        poly f1 = {F.begin() + L, F.begin() + L + b};\r\
    \n        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};\r\n        f1.resize(2\
    \ * b), f2.resize(2 * b), ntt(f1, 0), ntt(f2, 0);\r\n        FOR(i, b) nxt_F[L\
    \ + i] = f1[i] * f2[i] + f1[i] + f2[i];\r\n        FOR(i, b, 2 * b) nxt_F[L +\
    \ i] = f1[i] * f2[i] - f1[i] - f2[i];\r\n      }\r\n    }\r\n    else {\r\n  \
    \    for (int L = 0; L < n; L += 2 * b) {\r\n        poly f1 = {F.begin() + L,\
    \ F.begin() + L + b};\r\n        poly f2 = {F.begin() + L + b, F.begin() + L +\
    \ 2 * b};\r\n        ntt_doubling(f1), ntt_doubling(f2);\r\n        FOR(i, b)\
    \ nxt_F[L + i] = f1[i] * f2[i] + f1[i] + f2[i];\r\n        FOR(i, b, 2 * b) nxt_F[L\
    \ + i] = f1[i] * f2[i] - f1[i] - f2[i];\r\n      }\r\n    }\r\n    swap(F, nxt_F);\r\
    \n  }\r\n  if (k - 1 >= D) ntt(F, 1);\r\n  F.eb(1), reverse(all(F));\r\n  F.resize(len(A)\
    \ + 1);\r\n  return F;\r\n}\n#line 2 \"linalg/blackbox/pascal.hpp\"\n\n// transpose\
    \ = 0\uFF1Ag[p] = sum binom(p,q) f[q]\n// transpose = 1\uFF1Ag[p] = sum binom(q,p)\
    \ f[q]\ntemplate <typename mint>\nvc<mint> pascal(vc<mint> f, bool transpose,\
    \ bool inverse) {\n  if (!transpose) {\n    int n = len(f);\n    vc<mint> g(n);\n\
    \    FOR(i, n) g[i] = fact_inv<mint>(i);\n    if (inverse) FOR(i, n) if (i & 1)\
    \ g[i] = -g[i];\n    FOR(i, n) f[i] *= fact_inv<mint>(i);\n    f = convolution(f,\
    \ g);\n    f.resize(n);\n    FOR(i, n) f[i] *= fact<mint>(i);\n    return f;\n\
    \  }\n  int n = len(f);\n  FOR(i, n) f[i] *= fact<mint>(i);\n  reverse(all(f));\n\
    \  vc<mint> g(n);\n  FOR(i, n) g[i] = fact_inv<mint>(i);\n  if (inverse) FOR(i,\
    \ n) if (i & 1) g[i] = -g[i];\n  f = convolution(f, g);\n  f.resize(n);\n  reverse(all(f));\n\
    \  FOR(i, n) f[i] *= fact_inv<mint>(i);\n  return f;\n}\n#line 2 \"poly/multipoint.hpp\"\
    \n\r\n#line 2 \"poly/middle_product.hpp\"\n\n#line 6 \"poly/middle_product.hpp\"\
    \n\n// n, m \u6B21\u591A\u9805\u5F0F (n>=m) a, b \u2192 n-m \u6B21\u591A\u9805\
    \u5F0F c\n// c[i] = sum_j b[j]a[i+j]\ntemplate <typename mint>\nvc<mint> middle_product(vc<mint>&\
    \ a, vc<mint>& b) {\n  assert(len(a) >= len(b));\n  if (b.empty()) return vc<mint>(len(a)\
    \ - len(b) + 1);\n  if (min(len(b), len(a) - len(b) + 1) <= 60) {\n    return\
    \ middle_product_naive(a, b);\n  }\n  if (!(mint::can_ntt())) {\n    return middle_product_garner(a,\
    \ b);\n  } else {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n),\
    \ fb(n);\n    copy(a.begin(), a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(),\
    \ fb.begin());\n    ntt(fa, 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n \
    \   ntt(fa, 1);\n    fa.resize(len(a));\n    fa.erase(fa.begin(), fa.begin() +\
    \ len(b) - 1);\n    return fa;\n  }\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_garner(vc<mint>&\
    \ a, vc<mint> b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  static constexpr int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n\
    \  static constexpr int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using\
    \ mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0> a0(n), b0(m);\n\
    \  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val,\
    \ a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val,\
    \ b2[i] = b[i].val;\n  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  vc<mint> c(len(c0));\n \
    \ FOR(i, n - m + 1) {\n    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val,\
    \ c2[i].val);\n  }\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_naive(vc<mint>&\
    \ a, vc<mint>& b) {\n  vc<mint> res(len(a) - len(b) + 1);\n  FOR(i, len(res))\
    \ FOR(j, len(b)) res[i] += b[j] * a[i + j];\n  return res;\n}\n#line 2 \"mod/all_inverse.hpp\"\
    \ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>& X) {\n  for (auto&&\
    \ x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint> res(N + 1);\n  res[0]\
    \ = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n\
    \  res.pop_back();\n  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n \
    \ return res;\n}\n#line 2 \"poly/fps_div.hpp\"\n\n#line 2 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\r\nint count_terms(const vc<mint>& f){\r\n  int t =\
    \ 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return t;\r\n}\n#line 4\
    \ \"poly/fps_inv.hpp\"\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\r\n  int N = len(f);\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint> g(N);\r\n  mint g0\
    \ = mint(1) / f[0];\r\n  g[0] = g0;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\
    \n    for (auto&& [k, fk]: dat) {\r\n      if (k > n) break;\r\n      rhs -= fk\
    \ * g[n - k];\r\n    }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return g;\r\n}\r\n\r\
    \ntemplate <typename mint>\r\nvc<mint> fps_inv_dense_ntt(const vc<mint>& F) {\r\
    \n  vc<mint> G = {mint(1) / F[0]};\r\n  ll N = len(F), n = 1;\r\n  G.reserve(N);\r\
    \n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i, min(N, 2\
    \ * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false), ntt(g,\
    \ false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\n    FOR(i,\
    \ n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n  \
    \  ntt(f, true);\r\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\r\n    n *= 2;\r\
    \n  }\r\n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\r\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\r\n  const\
    \ int N = len(F);\r\n  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int\
    \ m = 1;\r\n  while (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m\
    \ + m);\r\n    vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p =\
    \ convolution(p, f);\r\n    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i]\
    \ + R[i] - p[i];\r\n    m += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\
    \n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv(const vc<mint>& f) {\r\n  assert(f[0]\
    \ != mint(0));\r\n  int n = count_terms(f);\r\n  int t = (mint::can_ntt() ? 160\
    \ : 820);\r\n  return (n <= t ? fps_inv_sparse<mint>(f) : fps_inv_dense<mint>(f));\r\
    \n}\r\n#line 5 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\
    \u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool SPARSE = false>\nvc<mint>\
    \ fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE || count_terms(g) < 200) return\
    \ fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n\
    \  f = convolution(f, g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\
    \u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint> fps_div_sparse(vc<mint>\
    \ f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n\
    \    for (auto&& x: f) x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int,\
    \ mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i,\
    \ len(f)) {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i\
    \ - j];\n    }\n  }\n  return f;\n}\n#line 2 \"poly/transposed_ntt.hpp\"\n\ntemplate\
    \ <class mint>\nvoid transposed_ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n\
    \  const int rank2 = mint::ntt_info().fi;\n  const int mod = mint::get_mod();\n\
    \  static array<mint, 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n\
    \  static array<mint, 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <=\
    \ (1 << max(0, rank2)));\n\n  static bool prepared = 0;\n  if (!prepared) {\n\
    \    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n    iroot[rank2] =\
    \ mint(1) / root[rank2];\n    FOR_R(i, rank2) {\n      root[i] = root[i + 1] *\
    \ root[i + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n    }\n    mint\
    \ prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 2; i++) {\n      rate2[i]\
    \ = root[i + 2] * prod;\n      irate2[i] = iroot[i + 2] * iprod;\n      prod *=\
    \ iroot[i + 2];\n      iprod *= root[i + 2];\n    }\n    prod = 1, iprod = 1;\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\n      rate3[i] = root[i + 3] * prod;\n\
    \      irate3[i] = iroot[i + 3] * iprod;\n      prod *= iroot[i + 3];\n      iprod\
    \ *= root[i + 3];\n    }\n  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n\
    \  assert(n == 1 << h);\n  if (!inverse) {\n    int len = h;\n    while (len >\
    \ 0) {\n      if (len == 1) {\n        int p = 1 << (h - len);\n        mint rot\
    \ = 1;\n        FOR(s, 1 << (len - 1)) {\n          int offset = s << (h - len\
    \ + 1);\n          FOR(i, p) {\n            u64 l = a[i + offset].val;\n     \
    \       u64 r = a[i + offset + p].val;\n            a[i + offset] = l + r;\n \
    \           a[i + offset + p] = (mod + l - r) * rot.val;\n          }\n      \
    \    rot *= rate2[topbit(~s & -~s)];\n        }\n        len--;\n      } else\
    \ {\n        int p = 1 << (h - len);\n        mint rot = 1, imag = root[2];\n\
    \        FOR(s, (1 << (len - 2))) {\n          int offset = s << (h - len + 2);\n\
    \          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n       \
    \   for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n\
    \            u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset\
    \ + 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n           \
    \ u64 x = (mod + a2 - a3) * imag.val % mod;\n            a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * rot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * rot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * rot3.val;\n   \
    \       }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len -=\
    \ 2;\n      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n  \
    \  FOR(i, len(a)) a[i] *= coef;\n    int len = 0;\n    while (len < h) {\n   \
    \   if (len == h - 1) {\n        int p = 1 << (h - len - 1);\n        mint irot\
    \ = 1;\n        FOR(s, 1 << len) {\n          int offset = s << (h - len);\n \
    \         FOR(i, p) {\n            auto l = a[i + offset];\n            auto r\
    \ = a[i + offset + p] * irot;\n            a[i + offset] = l + r;\n          \
    \  a[i + offset + p] = l - r;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len++;\n      } else {\n        int p = 1 << (h\
    \ - len - 2);\n        mint irot = 1, iimag = iroot[2];\n        for (int s =\
    \ 0; s < (1 << len); s++) {\n          mint irot2 = irot * irot;\n          mint\
    \ irot3 = irot2 * irot;\n          int offset = s << (h - len);\n          for\
    \ (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n        \
    \    u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * irot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) * irot2.val;\n\
    \            u64 a3 = u64(a[i + offset + 3 * p].val) * irot3.val;\n          \
    \  u64 a1na3imag = (a1 + mod2 - a3) % mod * iimag.val;\n            u64 na2 =\
    \ mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n            a[i\
    \ + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n            a[i + offset\
    \ + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3 * p] = a0 + na2\
    \ + (mod2 - a1na3imag);\n          }\n          irot *= irate3[topbit(~s & -~s)];\n\
    \        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/multipoint.hpp\"\
    \n\r\ntemplate <typename mint>\r\nstruct SubproductTree {\r\n  int m;\r\n  int\
    \ sz;\r\n  vc<vc<mint>> T;\r\n  SubproductTree(const vc<mint>& x) {\r\n    m =\
    \ len(x);\r\n    sz = 1;\r\n    while (sz < m) sz *= 2;\r\n    T.resize(2 * sz);\r\
    \n    FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i] : 0)};\r\n    FOR3_R(i, 1, sz)\
    \ T[i] = convolution(T[2 * i], T[2 * i + 1]);\r\n  }\r\n\r\n  vc<mint> evaluation(vc<mint>\
    \ f) {\r\n    int n = len(f);\r\n    if (n == 0) return vc<mint>(m, mint(0));\r\
    \n    f.resize(2 * n - 1);\r\n    vc<vc<mint>> g(2 * sz);\r\n    g[1] = T[1];\r\
    \n    g[1].resize(n);\r\n    g[1] = fps_inv(g[1]);\r\n    g[1] = middle_product(f,\
    \ g[1]);\r\n    g[1].resize(sz);\r\n\r\n    FOR3(i, 1, sz) {\r\n      g[2 * i]\
    \ = middle_product(g[i], T[2 * i + 1]);\r\n      g[2 * i + 1] = middle_product(g[i],\
    \ T[2 * i]);\r\n    }\r\n    vc<mint> vals(m);\r\n    FOR(i, m) vals[i] = g[sz\
    \ + i][0];\r\n    return vals;\r\n  }\r\n\r\n  vc<mint> interpolation(vc<mint>&\
    \ y) {\r\n    assert(len(y) == m);\r\n    vc<mint> a(m);\r\n    FOR(i, m) a[i]\
    \ = T[1][m - i - 1] * (i + 1);\r\n\r\n    a = evaluation(a);\r\n    vc<vc<mint>>\
    \ t(2 * sz);\r\n    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};\r\n  \
    \  FOR3_R(i, 1, sz) {\r\n      t[i] = convolution(t[2 * i], T[2 * i + 1]);\r\n\
    \      auto tt = convolution(t[2 * i + 1], T[2 * i]);\r\n      FOR(k, len(t[i]))\
    \ t[i][k] += tt[k];\r\n    }\r\n    t[1].resize(m);\r\n    reverse(all(t[1]));\r\
    \n    return t[1];\r\n  }\r\n};\r\n\r\ntemplate <typename mint>\r\nvc<mint> multipoint_evaluation_ntt(vc<mint>\
    \ f, vc<mint> point) {\r\n  using poly = vc<mint>;\r\n  int n = 1, k = 0;\r\n\
    \  while (n < len(point)) n *= 2, ++k;\r\n  vv(mint, F, k + 1, 2 * n);\r\n  FOR(i,\
    \ len(point)) F[0][2 * i] = -point[i];\r\n\r\n  FOR(d, k) {\r\n    int b = 1 <<\
    \ d;\r\n    for (int L = 0; L < 2 * n; L += 4 * b) {\r\n      poly f1 = {F[d].begin()\
    \ + L, F[d].begin() + L + b};\r\n      poly f2 = {F[d].begin() + L + 2 * b, F[d].begin()\
    \ + L + 3 * b};\r\n      ntt_doubling(f1), ntt_doubling(f2);\r\n      FOR(i, b)\
    \ f1[i] += 1, f2[i] += 1;\r\n      FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\r\n\
    \      copy(all(f1), F[d].begin() + L);\r\n      copy(all(f2), F[d].begin() +\
    \ L + 2 * b);\r\n      FOR(i, 2 * b) { F[d + 1][L + i] = f1[i] * f2[i] - 1; }\r\
    \n    }\r\n  }\r\n  vc<mint> P = {F[k].begin(), F[k].begin() + n};\r\n  ntt(P,\
    \ 1), P.eb(1), reverse(all(P)), P.resize(len(f)), P = fps_inv<mint>(P);\r\n  f.resize(n\
    \ + len(P) - 1), f = middle_product<mint>(f, P), reverse(all(f));\r\n  transposed_ntt(f,\
    \ 1);\r\n  vc<mint>& G = f;\r\n  FOR_R(d, k) {\r\n    vc<mint> nxt_G(n);\r\n \
    \   int b = 1 << d;\r\n    for (int L = 0; L < n; L += 2 * b) {\r\n      vc<mint>\
    \ g1(2 * b), g2(2 * b);\r\n      FOR(i, 2 * b) { g1[i] = G[L + i] * F[d][2 * L\
    \ + 2 * b + i]; }\r\n      FOR(i, 2 * b) { g2[i] = G[L + i] * F[d][2 * L + i];\
    \ }\r\n      ntt_doubling<mint, true>(g1), ntt_doubling<mint, true>(g2);\r\n \
    \     FOR(i, b) { nxt_G[L + i] = g1[i], nxt_G[L + b + i] = g2[i]; }\r\n    }\r\
    \n    swap(G, nxt_G);\r\n  }\r\n  G.resize(len(point));\r\n  return G;\r\n}\r\n\
    \r\ntemplate <typename mint>\r\nvc<mint> multipoint_eval(vc<mint>& f, vc<mint>&\
    \ x) {\r\n  if (x.empty()) return {};\r\n  if (mint::can_ntt()) return multipoint_evaluation_ntt(f,\
    \ x);\r\n  SubproductTree<mint> F(x);\r\n  return F.evaluation(f);\r\n}\r\n\r\n\
    template <typename mint>\r\nvc<mint> multipoint_interpolate(vc<mint>& x, vc<mint>&\
    \ y) {\r\n  if (x.empty()) return {};\r\n  SubproductTree<mint> F(x);\r\n  return\
    \ F.interpolation(y);\r\n}\r\n\r\n// calculate f(ar^k) for 0 <= k < m\r\ntemplate\
    \ <typename mint>\r\nvc<mint> multipoint_eval_on_geom_seq(vc<mint> f, mint a,\
    \ mint r, int m) {\r\n  const int n = len(f);\r\n  if (m == 0) return {};\r\n\r\
    \n  auto eval = [&](mint x) -> mint {\r\n    mint fx = 0;\r\n    mint pow = 1;\r\
    \n    FOR(i, n) fx += f[i] * pow, pow *= x;\r\n    return fx;\r\n  };\r\n\r\n\
    \  if (r == mint(0)) {\r\n    vc<mint> res(m);\r\n    FOR(i, 1, m) res[i] = f[0];\r\
    \n    res[0] = eval(a);\r\n    return res;\r\n  }\r\n  if (n < 60 || m < 60) {\r\
    \n    vc<mint> res(m);\r\n    FOR(i, m) res[i] = eval(a), a *= r;\r\n    return\
    \ res;\r\n  }\r\n  assert(r != mint(0));\r\n  // a == 1 \u306B\u5E30\u7740\r\n\
    \  mint pow_a = 1;\r\n  FOR(i, n) f[i] *= pow_a, pow_a *= a;\r\n\r\n  auto calc\
    \ = [&](mint r, int m) -> vc<mint> {\r\n    // r^{t_i} \u306E\u8A08\u7B97\r\n\
    \    vc<mint> res(m);\r\n    mint pow = 1;\r\n    res[0] = 1;\r\n    FOR(i, m\
    \ - 1) {\r\n      res[i + 1] = res[i] * pow;\r\n      pow *= r;\r\n    }\r\n \
    \   return res;\r\n  };\r\n\r\n  vc<mint> A = calc(r, n + m - 1), B = calc(r.inverse(),\
    \ max(n, m));\r\n  FOR(i, n) f[i] *= B[i];\r\n  f = middle_product(A, f);\r\n\
    \  FOR(i, m) f[i] *= B[i];\r\n  return f;\r\n}\r\n\r\n// Y[i] = f(ar^i)\r\ntemplate\
    \ <typename mint>\r\nvc<mint> multipoint_interpolate_on_geom_seq(vc<mint> Y, mint\
    \ a, mint r) {\r\n  const int n = len(Y);\r\n  if (n == 0) return {};\r\n  if\
    \ (n == 1) return {Y[0]};\r\n  assert(r != mint(0));\r\n  mint ir = r.inverse();\r\
    \n\r\n  vc<mint> POW(n + n - 1), tPOW(n + n - 1);\r\n  POW[0] = tPOW[0] = mint(1);\r\
    \n  FOR(i, n + n - 2) POW[i + 1] = POW[i] * r, tPOW[i + 1] = tPOW[i] * POW[i];\r\
    \n\r\n  vc<mint> iPOW(n + n - 1), itPOW(n + n - 1);\r\n  iPOW[0] = itPOW[0] =\
    \ mint(1);\r\n  FOR(i, n) iPOW[i + 1] = iPOW[i] * ir, itPOW[i + 1] = itPOW[i]\
    \ * iPOW[i];\r\n\r\n  // prod_[1,i] 1-r^k\r\n  vc<mint> S(n);\r\n  S[0] = mint(1);\r\
    \n  FOR(i, 1, n) S[i] = S[i - 1] * (mint(1) - POW[i]);\r\n  vc<mint> iS = all_inverse<mint>(S);\r\
    \n  mint sn = S[n - 1] * (mint(1) - POW[n]);\r\n\r\n  FOR(i, n) {\r\n    Y[i]\
    \ = Y[i] * tPOW[n - 1 - i] * itPOW[n - 1] * iS[i] * iS[n - 1 - i];\r\n    if (i\
    \ % 2 == 1) Y[i] = -Y[i];\r\n  }\r\n\r\n  // sum_i Y[i] / 1-r^ix\r\n  FOR(i, n)\
    \ Y[i] *= itPOW[i];\r\n  vc<mint> f = middle_product(tPOW, Y);\r\n  FOR(i, n)\
    \ f[i] *= itPOW[i];\r\n\r\n  // prod 1-r^ix\r\n  vc<mint> g(n);\r\n  g[0] = mint(1);\r\
    \n  FOR(i, 1, n) {\r\n    g[i] = tPOW[i] * sn * iS[i] * iS[n - i];\r\n    if (i\
    \ % 2 == 1) g[i] = -g[i];\r\n  }\r\n  f = convolution<mint>(f, g);\r\n  f.resize(n);\r\
    \n\r\n  reverse(all(f));\r\n  mint ia = a.inverse();\r\n  mint pow = 1;\r\n  FOR(i,\
    \ n) f[i] *= pow, pow *= ia;\r\n  return f;\r\n}\r\n#line 2 \"poly/sum_of_rationals.hpp\"\
    \n\n#line 5 \"poly/sum_of_rationals.hpp\"\n\n// \u6709\u7406\u5F0F\u306E\u548C\
    \u3092\u8A08\u7B97\u3059\u308B\u3002\u5206\u5272\u7D71\u6CBB O(Nlog^2N)\u3002\
    N \u306F\u6B21\u6570\u306E\u548C\u3002\ntemplate <typename mint>\npair<vc<mint>,\
    \ vc<mint>> sum_of_rationals(vc<pair<vc<mint>, vc<mint>>> dat) {\n  if (len(dat)\
    \ == 0) {\n    vc<mint> f = {0}, g = {1};\n    return {f, g};\n  }\n  using P\
    \ = pair<vc<mint>, vc<mint>>;\n  auto add = [&](P& a, P& b) -> P {\n    int na\
    \ = len(a.fi) - 1, da = len(a.se) - 1;\n    int nb = len(b.fi) - 1, db = len(b.se)\
    \ - 1;\n    int n = max(na + db, da + nb);\n    vc<mint> num(n + 1);\n    {\n\
    \      auto f = convolution(a.fi, b.se);\n      FOR(i, len(f)) num[i] += f[i];\n\
    \    }\n    {\n      auto f = convolution(a.se, b.fi);\n      FOR(i, len(f)) num[i]\
    \ += f[i];\n    }\n    auto den = convolution(a.se, b.se);\n    return {num, den};\n\
    \  };\n\n  while (len(dat) > 1) {\n    int n = len(dat);\n    FOR(i, 1, n, 2)\
    \ { dat[i - 1] = add(dat[i - 1], dat[i]); }\n    FOR(i, ceil(n, 2)) dat[i] = dat[2\
    \ * i];\n    dat.resize(ceil(n, 2));\n  }\n  return dat[0];\n}\n\n// sum wt[i]/(1-A[i]x)\n\
    template <typename mint>\npair<vc<mint>, vc<mint>> sum_of_rationals_1(vc<mint>\
    \ A, vc<mint> wt) {\n  using poly = vc<mint>;\n  if (!mint::can_ntt()) {\n   \
    \ vc<pair<poly, poly>> rationals;\n    FOR(i, len(A)) rationals.eb(poly({wt[i]}),\
    \ poly({mint(1), -A[i]}));\n    return sum_of_rationals(rationals);\n  }\n  int\
    \ n = 1;\n  while (n < len(A)) n *= 2;\n  int k = topbit(n);\n  vc<mint> F(n),\
    \ G(n);\n  vc<mint> nxt_F(n), nxt_G(n);\n  FOR(i, len(A)) F[i] = -A[i], G[i] =\
    \ wt[i];\n  int D = 6;\n\n  FOR(d, k) {\n    int b = 1 << d;\n    if (d < D) {\n\
    \      fill(all(nxt_F), mint(0)), fill(all(nxt_G), mint(0));\n      for (int L\
    \ = 0; L < n; L += 2 * b) {\n        FOR(i, b) FOR(j, b) nxt_F[L + i + j] += F[L\
    \ + i] * F[L + b + j];\n        FOR(i, b) FOR(j, b) nxt_G[L + i + j] += F[L +\
    \ i] * G[L + b + j];\n        FOR(i, b) FOR(j, b) nxt_G[L + i + j] += F[L + b\
    \ + i] * G[L + j];\n        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L + b +\
    \ i];\n        FOR(i, b) nxt_G[L + b + i] += G[L + i] + G[L + b + i];\n      }\n\
    \    }\n    elif (d == D) {\n      for (int L = 0; L < n; L += 2 * b) {\n    \
    \    poly f1 = {F.begin() + L, F.begin() + L + b};\n        poly f2 = {F.begin()\
    \ + L + b, F.begin() + L + 2 * b};\n        poly g1 = {G.begin() + L, G.begin()\
    \ + L + b};\n        poly g2 = {G.begin() + L + b, G.begin() + L + 2 * b};\n \
    \       f1.resize(2 * b), f2.resize(2 * b), g1.resize(2 * b), g2.resize(2 * b);\n\
    \        ntt(f1, 0), ntt(f2, 0), ntt(g1, 0), ntt(g2, 0);\n        FOR(i, b) f1[i]\
    \ += 1, f2[i] += 1;\n        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n      \
    \  FOR(i, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - 1;\n        FOR(i, 2 * b) nxt_G[L\
    \ + i] = g1[i] * f2[i] + g2[i] * f1[i];\n      }\n    }\n    else {\n      for\
    \ (int L = 0; L < n; L += 2 * b) {\n        poly f1 = {F.begin() + L, F.begin()\
    \ + L + b};\n        poly f2 = {F.begin() + L + b, F.begin() + L + 2 * b};\n \
    \       poly g1 = {G.begin() + L, G.begin() + L + b};\n        poly g2 = {G.begin()\
    \ + L + b, G.begin() + L + 2 * b};\n        ntt_doubling(f1), ntt_doubling(f2),\
    \ ntt_doubling(g1), ntt_doubling(g2);\n        FOR(i, b) f1[i] += 1, f2[i] +=\
    \ 1;\n        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n        FOR(i, 2 * b)\
    \ nxt_F[L + i] = f1[i] * f2[i] - 1;\n        FOR(i, 2 * b) nxt_G[L + i] = g1[i]\
    \ * f2[i] + g2[i] * f1[i];\n      }\n    }\n    swap(F, nxt_F), swap(G, nxt_G);\n\
    \  }\n  if (k - 1 >= D) ntt(F, 1), ntt(G, 1);\n  F.eb(1);\n  reverse(all(F)),\
    \ reverse(all(G));\n  F.resize(len(A) + 1);\n  G.resize(len(A));\n  return {G,\
    \ F};\n}\n#line 4 \"linalg/blackbox/vandermonde.hpp\"\n\n// transpose = 0\uFF1A\
    g[p] = sum pow(ap,q) f[q]\n// transpose = 1\uFF1Ag[p] = sum pow(aq,p) f[q]\n//\
    \ (false, false) = multipoint eval\n// (false, true) = multipoint interpolate\n\
    // (true, false) = sum of rationals\n// (true, true) = partial frac decomposition\
    \ (fps -> coefs)\ntemplate <typename mint>\nvc<mint> vandermonde(vc<mint> f, vc<mint>\
    \ A, bool transpose, bool inverse) {\n  if (len(f) == 0) return vc<mint>();\n\
    \  int N = len(f);\n  if (!transpose) {\n    if (!inverse) { return multipoint_eval(f,\
    \ A); }\n    if (inverse) { return multipoint_interpolate(A, f); }\n  }\n  if\
    \ (!inverse) {\n    auto [num, den] = sum_of_rationals_1<mint>(A, f);\n    num.resize(N);\n\
    \    return fps_div(num, den);\n  }\n  SubproductTree<mint> X(A);\n  vc<mint>\
    \ g = X.T[1]; // prod(1-ax)\n  g.resize(N + 1);\n  f = convolution<mint>(f, g);\n\
    \  f.resize(N);\n  reverse(all(f));\n  reverse(all(g));\n  FOR(i, len(g) - 1)\
    \ g[i] = g[i + 1] * mint(i + 1);\n  g.pop_back();\n  auto num = X.evaluation(f);\n\
    \  auto den = X.evaluation(g);\n  vc<mint> B(len(A));\n  FOR(i, len(A)) B[i] =\
    \ num[i] / den[i];\n  return B;\n}\n#line 9 \"test/5_atcoder/abc260h.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, M);\n  VEC(int, A, N);\n\
    \  vc<int> CNT(N);\n  for (auto&& x: A) CNT[x - 1]++;\n  // \u5305\u9664\u30EB\
    \u30FC\u30EB\u306E\u500B\u6570 -> \u30EB\u30FC\u30EB\u306E\u6C7A\u3081\u65B9\n\
    \  vvc<mint> polys;\n  FOR(x, N) {\n    int n = CNT[x];\n    if (n <= 1) continue;\n\
    \    vc<mint> f(n);\n    FOR(i, n) f[i] = C<mint>(n - 1, i) * fact_inv<mint>(n\
    \ - i);\n    polys.eb(f);\n  }\n  vc<mint> f = convolution_all(polys);\n\n  FOR(i,\
    \ len(f)) f[i] *= fact<mint>(N - i);\n  f = pascal(f, true, true);\n\n  {\n  \
    \  mint cf = 1;\n    for (auto&& x: CNT) cf *= fact<mint>(x);\n    for (auto&&\
    \ x: f) x *= cf;\n  }\n\n  int L = max(N, M + 1);\n  vc<mint> g(N);\n  FOR(i,\
    \ len(f)) g[N - 1 - i] = f[i];\n  g.resize(L);\n\n  vc<mint> x(L);\n  FOR(i, L)\
    \ x[i] = i;\n  vc<mint> ANS = vandermonde(g, x, true, false);\n  ANS.erase(ANS.begin());\n\
    \  ANS.resize(M);\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc260/tasks/abc260_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/convolution_all.hpp\"\n#include \"linalg/blackbox/pascal.hpp\"\
    \n#include \"linalg/blackbox/vandermonde.hpp\"\n\nusing mint = modint998;\n\n\
    void solve() {\n  LL(N, M);\n  VEC(int, A, N);\n  vc<int> CNT(N);\n  for (auto&&\
    \ x: A) CNT[x - 1]++;\n  // \u5305\u9664\u30EB\u30FC\u30EB\u306E\u500B\u6570 ->\
    \ \u30EB\u30FC\u30EB\u306E\u6C7A\u3081\u65B9\n  vvc<mint> polys;\n  FOR(x, N)\
    \ {\n    int n = CNT[x];\n    if (n <= 1) continue;\n    vc<mint> f(n);\n    FOR(i,\
    \ n) f[i] = C<mint>(n - 1, i) * fact_inv<mint>(n - i);\n    polys.eb(f);\n  }\n\
    \  vc<mint> f = convolution_all(polys);\n\n  FOR(i, len(f)) f[i] *= fact<mint>(N\
    \ - i);\n  f = pascal(f, true, true);\n\n  {\n    mint cf = 1;\n    for (auto&&\
    \ x: CNT) cf *= fact<mint>(x);\n    for (auto&& x: f) x *= cf;\n  }\n\n  int L\
    \ = max(N, M + 1);\n  vc<mint> g(N);\n  FOR(i, len(f)) g[N - 1 - i] = f[i];\n\
    \  g.resize(L);\n\n  vc<mint> x(L);\n  FOR(i, L) x[i] = i;\n  vc<mint> ANS = vandermonde(g,\
    \ x, true, false);\n  ANS.erase(ANS.begin());\n  ANS.resize(M);\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/convolution_all.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  - poly/ntt_doubling.hpp
  - linalg/blackbox/pascal.hpp
  - linalg/blackbox/vandermonde.hpp
  - poly/multipoint.hpp
  - poly/middle_product.hpp
  - mod/all_inverse.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/transposed_ntt.hpp
  - poly/sum_of_rationals.hpp
  isVerificationFile: true
  path: test/5_atcoder/abc260h.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 00:31:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_atcoder/abc260h.test.cpp
layout: document
redirect_from:
- /verify/test/5_atcoder/abc260h.test.cpp
- /verify/test/5_atcoder/abc260h.test.cpp.html
title: test/5_atcoder/abc260h.test.cpp
---