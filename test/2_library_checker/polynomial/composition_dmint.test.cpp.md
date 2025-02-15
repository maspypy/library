---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':heavy_check_mark:'
    path: mod/dynamic_modint.hpp
    title: mod/dynamic_modint.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mongomery_modint.hpp
    title: mod/mongomery_modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':heavy_check_mark:'
    path: poly/composition.hpp
    title: poly/composition.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':heavy_check_mark:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':heavy_check_mark:'
    path: poly/transposed_ntt.hpp
    title: poly/transposed_ntt.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/composition_of_formal_power_series_large
    links:
    - https://judge.yosupo.jp/problem/composition_of_formal_power_series_large
  bundledCode: "#line 1 \"test/2_library_checker/polynomial/composition_dmint.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/composition_of_formal_power_series_large\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif\
    \ else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const vector<U> &A) {\n  T sm = 0;\n  for (auto &&a: A) sm += a;\n\
    \  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\n\
    T POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\n\
    double binary_search_real(F check, double ok, double ng, int iter = 100) {\n \
    \ FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n\
    \  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>\
    \ &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>\
    \ &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 1 \"other/io.hpp\"\n\
    #define FASTIO\r\n#include <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\
    \nnamespace fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\
    \nchar obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil\
    \ = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr\
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
    \ yes(!t); }\r\nvoid YA(bool t = 1) { print(t ? \"YA\" : \"TIDAK\"); }\r\nvoid\
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 5 \"test/2_library_checker/polynomial/composition_dmint.test.cpp\"\
    \n\n#line 2 \"mod/dynamic_modint.hpp\"\n\n#line 2 \"mod/modint_common.hpp\"\n\n\
    struct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1)\
    \ : mint(0)); }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 2 \"\
    mod/primitive_root.hpp\"\n\r\n#line 2 \"nt/factor.hpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n\
    // x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename\
    \ U1, typename U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n\
    \  inline static U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\
    \n  static void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W -\
    \ 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n   \
    \ r = -r;\n    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return\
    \ (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n\
    \  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n   \
    \ U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
    \ y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint\
    \ &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n\
    \  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n\
    \  }\n  mint operator+(mint y) const { return mint(*this) += y; }\n  mint operator-(mint\
    \ y) const { return mint(*this) -= y; }\n  mint operator*(mint y) const { return\
    \ mint(*this) *= y; }\n  bool operator==(mint y) const {\n    return (x >= m ?\
    \ x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const\
    \ { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n\
    \    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1)\
    \ y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32\
    \ = Mongomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64\
    \ = Mongomery_modint<id, u64, u128>;\n#line 3 \"nt/primetest.hpp\"\n\r\nbool primetest(const\
    \ u64 x) {\r\n  assert(x < u64(1) << 62);\r\n  if (x == 2 or x == 3 or x == 5\
    \ or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x\
    \ % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x\
    \ - 1) >> lowbit(x - 1);\r\n\r\n  using mint = Mongomery_modint_64<202311020>;\r\
    \n\r\n  mint::set_mod(x);\r\n  const mint one(u64(1)), minus_one(x - 1);\r\n \
    \ auto ok = [&](u64 a) -> bool {\r\n    auto y = mint(a).pow(d);\r\n    u64 t\
    \ = d;\r\n    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;\r\
    \n    if (y != minus_one && t % 2 == 0) return false;\r\n    return true;\r\n\
    \  };\r\n  if (x < (u64(1) << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if\
    \ (!ok(a)) return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022}) {\r\n      if (!ok(a)) return false;\r\n    }\r\
    \n  }\r\n  return true;\r\n}\n#line 5 \"nt/factor.hpp\"\n\ntemplate <typename\
    \ mint>\nll rho(ll n, ll c) {\n  assert(n > 1);\n  const mint cc(c);\n  auto f\
    \ = [&](mint x) { return x * x + cc; };\n  mint x = 1, y = 2, z = 1, q = 1;\n\
    \  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\n  for (ll r = 1; g == 1; r\
    \ <<= 1) {\n    x = y;\n    FOR(r) y = f(y);\n    for (ll k = 0; k < r && g ==\
    \ 1; k += m) {\n      z = y;\n      FOR(min(m, r - k)) y = f(y), q *= x - y;\n\
    \      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z = f(z);\n\
    \      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n}\n\nll\
    \ find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return n;\n\
    \  FOR(100) {\n    ll m = 0;\n    if (n < (1 << 30)) {\n      using mint = Mongomery_modint_32<20231025>;\n\
    \      mint::set_mod(n);\n      m = rho<mint>(n, RNG(0, n));\n    } else {\n \
    \     using mint = Mongomery_modint_64<20231025>;\n      mint::set_mod(n);\n \
    \     m = rho<mint>(n, RNG(0, n));\n    }\n    if (primetest(m)) return m;\n \
    \   n = m;\n  }\n  assert(0);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\
    \u304F\u308C\u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll,\
    \ int>> pf;\n  FOR(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0)\
    \ {\n      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n     \
    \ pf.eb(p, e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n\
    \    ll e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n\
    \  }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll\
    \ n, vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p =\
    \ lpf[n];\n    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n\
    \    }\n    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/mod_pow.hpp\"\n\
    \r\n#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 5 \"\
    mod/mod_pow.hpp\"\n\r\nu32 mod_pow(int a, ll n, int mod) {\r\n  assert(n >= 0);\r\
    \n  if (mod == 1) return 0;\r\n  a = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod\
    \ & 1) && (mod < (1 << 30))) {\r\n    using mint = Mongomery_modint_32<202311021>;\r\
    \n    mint::set_mod(mod);\r\n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett\
    \ bt(mod);\r\n  int r = 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\
    \n    a = bt.mul(a, a), n >>= 1;\r\n  }\r\n  return r;\r\n}\r\n\r\nu64 mod_pow_64(ll\
    \ a, ll n, u64 mod) {\r\n  assert(n >= 0);\r\n  if (mod == 1) return 0;\r\n  a\
    \ = ((a %= mod) < 0 ? a + mod : a);\r\n  if ((mod & 1) && (mod < (u64(1) << 62)))\
    \ {\r\n    using mint = Mongomery_modint_64<202311021>;\r\n    mint::set_mod(mod);\r\
    \n    return mint(a).pow(n).val();\r\n  }\r\n  Barrett_64 bt(mod);\r\n  ll r =\
    \ 1;\r\n  while (n) {\r\n    if (n & 1) r = bt.mul(r, a);\r\n    a = bt.mul(a,\
    \ a), n >>= 1;\r\n  }\r\n  return r;\r\n}\n#line 6 \"mod/primitive_root.hpp\"\n\
    \r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n  auto\
    \ is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if (mod_pow(g,\
    \ (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\n  while (1)\
    \ {\r\n    int x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return\
    \ -1;\r\n}\r\n\r\nll primitive_root_64(ll p) {\r\n  auto pf = factor(p - 1);\r\
    \n  auto is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow_64(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n \
    \ };\r\n  while (1) {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\
    \n  }\r\n  return -1;\r\n}\r\n\r\n// https://codeforces.com/contest/1190/problem/F\r\
    \nll primitive_root_prime_power_64(ll p, ll e) {\r\n  assert(p >= 3);\r\n  ll\
    \ g = primitive_root_64(p);\r\n  ll q = p;\r\n  ll phi = p - 1;\r\n  FOR(e - 1)\
    \ {\r\n    q *= p;\r\n    phi *= p;\r\n    if (mod_pow_64(g, phi / p, q) == 1)\
    \ g += q / p;\r\n  }\r\n  return g;\r\n}\r\n#line 6 \"mod/dynamic_modint.hpp\"\
    \n\ntemplate <int id>\nstruct Dynamic_Modint {\n  static constexpr bool is_modint\
    \ = true;\n  using mint = Dynamic_Modint;\n  u32 val;\n  static Barrett bt;\n\
    \  static u32 umod() { return bt.umod(); }\n\n  static int get_mod() { return\
    \ (int)(bt.umod()); }\n  static void set_mod(int m) {\n    assert(1 <= m);\n \
    \   bt = Barrett(m);\n  }\n\n  static Dynamic_Modint raw(u32 v) {\n    Dynamic_Modint\
    \ x;\n    x.val = v;\n    return x;\n  }\n  Dynamic_Modint() : val(0) {}\n  Dynamic_Modint(u32\
    \ x) : val(bt.modulo(x)) {}\n  Dynamic_Modint(u64 x) : val(bt.modulo(x)) {}\n\
    \  Dynamic_Modint(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n\
    \  Dynamic_Modint(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}\n \
    \ Dynamic_Modint(i128 x) : val((x %= get_mod()) < 0 ? x + get_mod() : x){};\n\n\
    \  mint& operator+=(const mint& rhs) {\n    val = (val += rhs.val) < umod() ?\
    \ val : val - umod();\n    return *this;\n  }\n  mint& operator-=(const mint&\
    \ rhs) {\n    val = (val += umod() - rhs.val) < umod() ? val : val - umod();\n\
    \    return *this;\n  }\n  mint& operator*=(const mint& rhs) {\n    val = bt.mul(val,\
    \ rhs.val);\n    return *this;\n  }\n  mint& operator/=(const mint& rhs) { return\
    \ *this = *this * rhs.inverse(); }\n  mint operator-() const { return mint() -\
    \ *this; }\n  mint pow(ll n) const {\n    assert(0 <= n);\n    mint x = *this,\
    \ r = 1;\n    while (n) {\n      if (n & 1) r *= x;\n      x *= x, n >>= 1;\n\
    \    }\n    return r;\n  }\n  mint inverse() const {\n    int x = val, mod = get_mod();\n\
    \    int a = x, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a /\
    \ b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    if (u < 0) u\
    \ += mod;\n    return u;\n  }\n\n  friend mint operator+(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) += rhs; }\n  friend mint operator-(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n  friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n  friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n  friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs.val == rhs.val; }\n  friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs.val != rhs.val; }\n  static pair<int,\
    \ int>& get_ntt() {\n    static pair<int, int> p = {-1, -1};\n    return p;\n\
    \  }\n  static void set_ntt_info() {\n    int mod = get_mod();\n    int k = lowbit(mod\
    \ - 1);\n    int r = primitive_root(mod);\n    r = mod_pow(r, (mod - 1) >> k,\
    \ mod);\n    get_ntt() = {k, r};\n  }\n  static pair<int, int> ntt_info() { return\
    \ get_ntt(); }\n  static bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n\
    #ifdef FASTIO\ntemplate <int id>\nvoid rd(Dynamic_Modint<id>& x) {\n  fastio::rd(x.val);\n\
    \  x.val %= Dynamic_Modint<id>::umod();\n}\ntemplate <int id>\nvoid wt(Dynamic_Modint<id>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing dmint = Dynamic_Modint<-1>;\n\
    template <int id>\nBarrett Dynamic_Modint<id>::bt;\n#line 2 \"poly/composition.hpp\"\
    \n\r\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static\
    \ constexpr u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32\
    \ val;\n\n  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return\
    \ x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x\
    \ % umod) {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128\
    \ x) : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x +\
    \ mod : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n\
    \  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 582313106};\n    if (mod == 1012924417) return {21,\
    \ 368093570};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n\r\n// long \u3067\u3082\u5927\u4E08\u592B\r\n//\
    \ (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\
    \r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 2 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64 a, u64 n, u32\
    \ mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n & 1) res = res *\
    \ a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1>\nT CRT2(u64 a0, u64 a1) {\n  static_assert(p0 < p1);\n  static\
    \ constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n  u64 c = (a1 - a0\
    \ + p1) * x0_1 % p1;\n  return a0 + c * p0;\n}\n\ntemplate <typename T, u32 p0,\
    \ u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0 < p1 &&\
    \ p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);\n\
    \  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);\n\
    \  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1) * x1 % p1;\n\
    \  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 % p2;\n  return\
    \ T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2,\
    \ u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0 < p1 &&\
    \ p1 < p2 && p2 < p3);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c =\
    \ (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2\
    \ + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c =\
    \ (a3 - ans_2 % p3 + p3) * x3 % p3;\n  return T(ans_2) + T(c) * T(p01) * T(p2);\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64\
    \ a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0 < p1 && p1 < p2 &&\
    \ p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4 = mod_pow_constexpr(u64(p0)\
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
    \   }\r\n  }\r\n}\r\n#line 8 \"poly/convolution.hpp\"\n\r\ntemplate <class mint>\r\
    \nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\r\n  if (a.empty()\
    \ || b.empty()) return {};\r\n  int n = int(a.size()), m = int(b.size());\r\n\
    \  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\
    \u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n\
    \ + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(), b_last = b.back();\r\n\
    \    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a, b);\r\n    c.resize(n\
    \ + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i +\
    \ len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\
    \n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a\
    \ == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b,\
    \ 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m\
    \ - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\
    \n  if (!n || !m) return {};\r\n  static constexpr int p0 = 167772161;\r\n  static\
    \ constexpr int p1 = 469762049;\r\n  static constexpr int p2 = 754974721;\r\n\
    \  using mint0 = modint<p0>;\r\n  using mint1 = modint<p1>;\r\n  using mint2 =\
    \ modint<p2>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2>\
    \ a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\r\
    \n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\r\n  auto\
    \ c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, n + m - 1) { c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val, c2[i].val);\
    \ }\r\n  return c;\r\n}\r\n\r\nvector<ll> convolution(vector<ll> a, vector<ll>\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 2500) return convolution_naive(a, b);\r\n\r\n  ll mi_a = MIN(a),\
    \ mi_b = MIN(b);\r\n  for (auto& x: a) x -= mi_a;\r\n  for (auto& x: b) x -= mi_b;\r\
    \n  assert(MAX(a) * MAX(b) <= 1e18);\r\n\r\n  auto Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\r\
    \n  vi res(n + m - 1);\r\n  for (int k = 0; k < n + m - 1; ++k) {\r\n    int s\
    \ = max(0, k - m + 1);\r\n    int t = min(n, k + 1);\r\n    res[k] += (t - s)\
    \ * mi_a * mi_b;\r\n    res[k] += mi_a * (Bc[k - s + 1] - Bc[k - t + 1]);\r\n\
    \    res[k] += mi_b * (Ac[t] - Ac[s]);\r\n  }\r\n\r\n  static constexpr u32 MOD1\
    \ = 1004535809;\r\n  static constexpr u32 MOD2 = 1012924417;\r\n  using mint1\
    \ = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\
    \n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\r\n  FOR(i,\
    \ m) b1[i] = b[i], b2[i] = b[i];\r\n\r\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\r\n  auto c2 = convolution_ntt<mint2>(a2, b2);\r\n\r\n  FOR(i, n + m -\
    \ 1) { res[i] += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\r\n  return res;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> convolution(const vc<mint>& a,\
    \ const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (mint::can_ntt()) {\r\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\r\n    return convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\r\n  return convolution_garner(a, b);\r\n\
    }\r\n#line 2 \"poly/poly_taylor_shift.hpp\"\n\r\n#line 2 \"nt/primetable.hpp\"\
    \n\ntemplate <typename T = int>\nvc<T> primetable(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<T> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pair<int, int>> cp;\n    for (int i = 3; i <= S; i += 2) {\n\
    \      if (!sieve[i]) {\n        cp.eb(i, i * i / 2);\n        for (int j = i\
    \ * i; j <= S; j += 2 * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1;\
    \ L <= R; L += S) {\n      array<bool, S> block{};\n      for (auto& [p, idx]:\
    \ cp)\n        for (int i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n\
    \      FOR(i, min(S, R - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n\
    \  }\n  int k = LB(primes, LIM + 1);\n  return {primes.begin(), primes.begin()\
    \ + k};\n}\n#line 3 \"mod/powertable.hpp\"\n\r\n// a^0, ..., a^N\r\ntemplate <typename\
    \ mint>\r\nvc<mint> powertable_1(mint a, ll N) {\r\n  // table of a^i\r\n  vc<mint>\
    \ f(N + 1, 1);\r\n  FOR(i, N) f[i + 1] = a * f[i];\r\n  return f;\r\n}\r\n\r\n\
    // 0^e, ..., N^e\r\ntemplate <typename mint>\r\nvc<mint> powertable_2(ll e, ll\
    \ N) {\r\n  auto primes = primetable(N);\r\n  vc<mint> f(N + 1, 1);\r\n  f[0]\
    \ = mint(0).pow(e);\r\n  for (auto&& p: primes) {\r\n    if (p > N) break;\r\n\
    \    mint xp = mint(p).pow(e);\r\n    ll pp = p;\r\n    while (pp <= N) {\r\n\
    \      ll i = pp;\r\n      while (i <= N) {\r\n        f[i] *= xp;\r\n       \
    \ i += pp;\r\n      }\r\n      pp *= p;\r\n    }\r\n  }\r\n  return f;\r\n}\r\n\
    #line 5 \"poly/poly_taylor_shift.hpp\"\n\r\n// f(x) -> f(x+c)\r\ntemplate <typename\
    \ mint>\r\nvc<mint> poly_taylor_shift(vc<mint> f, mint c) {\r\n  if (c == mint(0))\
    \ return f;\r\n  ll N = len(f);\r\n  FOR(i, N) f[i] *= fact<mint>(i);\r\n  auto\
    \ b = powertable_1<mint>(c, N);\r\n  FOR(i, N) b[i] *= fact_inv<mint>(i);\r\n\
    \  reverse(all(f));\r\n  f = convolution(f, b);\r\n  f.resize(N);\r\n  reverse(all(f));\r\
    \n  FOR(i, N) f[i] *= fact_inv<mint>(i);\r\n  return f;\r\n}\r\n#line 2 \"poly/transposed_ntt.hpp\"\
    \n\ntemplate <class mint>\nvoid transposed_ntt(vector<mint>& a, bool inverse)\
    \ {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n  const\
    \ int mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n  static\
    \ array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\n\
    \  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
    \ = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n\
    \    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i, rank2) {\n      root[i]\
    \ = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n\
    \    }\n    mint prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 2; i++)\
    \ {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i] = iroot[i + 2] * iprod;\n\
    \      prod *= iroot[i + 2];\n      iprod *= root[i + 2];\n    }\n    prod = 1,\
    \ iprod = 1;\n    for (int i = 0; i <= rank2 - 3; i++) {\n      rate3[i] = root[i\
    \ + 3] * prod;\n      irate3[i] = iroot[i + 3] * iprod;\n      prod *= iroot[i\
    \ + 3];\n      iprod *= root[i + 3];\n    }\n  }\n\n  int n = int(a.size());\n\
    \  int h = topbit(n);\n  assert(n == 1 << h);\n  if (!inverse) {\n    int len\
    \ = h;\n    while (len > 0) {\n      if (len == 1) {\n        int p = 1 << (h\
    \ - len);\n        mint rot = 1;\n        FOR(s, 1 << (len - 1)) {\n         \
    \ int offset = s << (h - len + 1);\n          FOR(i, p) {\n            u64 l =\
    \ a[i + offset].val;\n            u64 r = a[i + offset + p].val;\n           \
    \ a[i + offset] = l + r;\n            a[i + offset + p] = (mod + l - r) * rot.val;\n\
    \          }\n          rot *= rate2[topbit(~s & -~s)];\n        }\n        len--;\n\
    \      } else {\n        int p = 1 << (h - len);\n        mint rot = 1, imag =\
    \ root[2];\n        FOR(s, (1 << (len - 2))) {\n          int offset = s << (h\
    \ - len + 2);\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 *\
    \ rot;\n          for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset\
    \ + 0 * p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 *\
    \ p].val;\n            u64 x = (mod + a2 - a3) * imag.val % mod;\n           \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0\
    \ + mod - a1 + x) * rot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2\
    \ * mod - a2 - a3) * rot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 *\
    \ mod - a1 - x) * rot3.val;\n          }\n          rot *= rate3[topbit(~s & -~s)];\n\
    \        }\n        len -= 2;\n      }\n    }\n  } else {\n    mint coef = mint(1)\
    \ / mint(len(a));\n    FOR(i, len(a)) a[i] *= coef;\n    int len = 0;\n    while\
    \ (len < h) {\n      if (len == h - 1) {\n        int p = 1 << (h - len - 1);\n\
    \        mint irot = 1;\n        FOR(s, 1 << len) {\n          int offset = s\
    \ << (h - len);\n          FOR(i, p) {\n            auto l = a[i + offset];\n\
    \            auto r = a[i + offset + p] * irot;\n            a[i + offset] = l\
    \ + r;\n            a[i + offset + p] = l - r;\n          }\n          irot *=\
    \ irate2[topbit(~s & -~s)];\n        }\n        len++;\n      } else {\n     \
    \   int p = 1 << (h - len - 2);\n        mint irot = 1, iimag = iroot[2];\n  \
    \      for (int s = 0; s < (1 << len); s++) {\n          mint irot2 = irot * irot;\n\
    \          mint irot3 = irot2 * irot;\n          int offset = s << (h - len);\n\
    \          for (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n\
    \            u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset\
    \ + p].val) * irot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) *\
    \ irot2.val;\n            u64 a3 = u64(a[i + offset + 3 * p].val) * irot3.val;\n\
    \            u64 a1na3imag = (a1 + mod2 - a3) % mod * iimag.val;\n           \
    \ u64 na2 = mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n     \
    \       a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n          \
    \  a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3\
    \ * p] = a0 + na2 + (mod2 - a1na3imag);\n          }\n          irot *= irate3[topbit(~s\
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 6 \"poly/composition.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> composition_old(vc<mint>& Q, vc<mint>&\
    \ P) {\r\n  int n = len(P);\r\n  assert(len(P) == len(Q));\r\n  int k = 1;\r\n\
    \  while (k * k < n) ++k;\r\n  // compute powers of P\r\n  vv(mint, pow1, k +\
    \ 1);\r\n  pow1[0] = {1};\r\n  pow1[1] = P;\r\n  FOR3(i, 2, k + 1) {\r\n    pow1[i]\
    \ = convolution(pow1[i - 1], pow1[1]);\r\n    pow1[i].resize(n);\r\n  }\r\n  vv(mint,\
    \ pow2, k + 1);\r\n  pow2[0] = {1};\r\n  pow2[1] = pow1[k];\r\n  FOR3(i, 2, k\
    \ + 1) {\r\n    pow2[i] = convolution(pow2[i - 1], pow2[1]);\r\n    pow2[i].resize(n);\r\
    \n  }\r\n  vc<mint> ANS(n);\r\n  FOR(i, k + 1) {\r\n    vc<mint> f(n);\r\n   \
    \ FOR(j, k) {\r\n      if (k * i + j < len(Q)) {\r\n        mint coef = Q[k *\
    \ i + j];\r\n        FOR(d, len(pow1[j])) f[d] += pow1[j][d] * coef;\r\n     \
    \ }\r\n    }\r\n    f = convolution(f, pow2[i]);\r\n    f.resize(n);\r\n    FOR(d,\
    \ n) ANS[d] += f[d];\r\n  }\r\n  return ANS;\r\n}\r\n\r\n// f(g(x)), O(Nlog^2N)\r\
    \ntemplate <typename mint>\r\nvc<mint> composition_0_ntt(vc<mint> f, vc<mint>\
    \ g) {\r\n  assert(len(f) == len(g));\r\n  if (f.empty()) return {};\r\n\r\n \
    \ int n0 = len(f);\r\n  int n = 1;\r\n  while (n < len(f)) n *= 2;\r\n  f.resize(n),\
    \ g.resize(n);\r\n\r\n  vc<mint> W(n);\r\n  {\r\n    // bit reverse order\r\n\
    \    vc<int> btr(n);\r\n    int log = topbit(n);\r\n    FOR(i, n) { btr[i] = (btr[i\
    \ >> 1] >> 1) + ((i & 1) << (log - 1)); }\r\n    int t = mint::ntt_info().fi;\r\
    \n    mint r = mint::ntt_info().se;\r\n    mint dw = r.inverse().pow((1 << t)\
    \ / (2 * n));\r\n    mint w = 1;\r\n    for (auto& i: btr) { W[i] = w, w *= dw;\
    \ }\r\n  }\r\n\r\n  auto rec = [&](auto& rec, int n, int k, vc<mint>& Q) -> vc<mint>\
    \ {\r\n    if (n == 1) {\r\n      reverse(all(f));\r\n      transposed_ntt(f,\
    \ 1);\r\n      mint c = mint(1) / mint(k);\r\n      for (auto& x: f) x *= c;\r\
    \n      vc<mint> p(4 * k);\r\n      FOR(i, k) p[2 * i] = f[i];\r\n      return\
    \ p;\r\n    }\r\n    auto doubling_y = [&](vc<mint>& A, int l, int r, bool t)\
    \ -> void {\r\n      mint z = W[k / 2].inverse();\r\n      vc<mint> f(k);\r\n\
    \      if (!t) {\r\n        FOR(i, l, r) {\r\n          FOR(j, k) f[j] = A[2 *\
    \ n * j + i];\r\n          ntt(f, 1);\r\n          mint r = 1;\r\n          FOR(j,\
    \ 1, k) r *= z, f[j] *= r;\r\n          ntt(f, 0);\r\n          FOR(j, k) A[2\
    \ * n * (k + j) + i] = f[j];\r\n        }\r\n      } else {\r\n        FOR(i,\
    \ l, r) {\r\n          FOR(j, k) f[j] = A[2 * n * (k + j) + i];\r\n          transposed_ntt(f,\
    \ 0);\r\n          mint r = 1;\r\n          FOR(j, 1, k) r *= z, f[j] *= r;\r\n\
    \          transposed_ntt(f, 1);\r\n          FOR(j, k) A[2 * n * j + i] += f[j];\r\
    \n        }\r\n      }\r\n    };\r\n\r\n    auto FFT_x = [&](vc<mint>& A, int\
    \ l, int r, bool t) -> void {\r\n      vc<mint> f(2 * n);\r\n      if (!t) {\r\
    \n        FOR(j, l, r) {\r\n          move(A.begin() + 2 * n * j, A.begin() +\
    \ 2 * n * (j + 1), f.begin());\r\n          ntt(f, 0);\r\n          move(all(f),\
    \ A.begin() + 2 * n * j);\r\n        }\r\n      } else {\r\n        FOR(j, l,\
    \ r) {\r\n          move(A.begin() + 2 * n * j, A.begin() + 2 * n * (j + 1), f.begin());\r\
    \n          transposed_ntt(f, 0);\r\n          move(all(f), A.begin() + 2 * n\
    \ * j);\r\n        }\r\n      }\r\n    };\r\n\r\n    if (n <= k) doubling_y(Q,\
    \ 1, n, 0), FFT_x(Q, 0, 2 * k, 0);\r\n    if (n > k) FFT_x(Q, 0, k, 0), doubling_y(Q,\
    \ 0, 2 * n, 0);\r\n\r\n    FOR(i, 2 * n * k) Q[i] += 1;\r\n    FOR(i, 2 * n *\
    \ k, 4 * n * k) Q[i] -= 1;\r\n\r\n    vc<mint> nxt_Q(4 * n * k);\r\n    vc<mint>\
    \ F(2 * n), G(2 * n), f(n), g(n);\r\n    FOR(j, 2 * k) {\r\n      move(Q.begin()\
    \ + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());\r\n      FOR(i, n) {\
    \ g[i] = G[2 * i] * G[2 * i + 1]; }\r\n      ntt(g, 1);\r\n      move(g.begin(),\
    \ g.begin() + n / 2, nxt_Q.begin() + n * j);\r\n    }\r\n    FOR(j, 4 * k) nxt_Q[n\
    \ * j] = 0;\r\n\r\n    vc<mint> p = rec(rec, n / 2, k * 2, nxt_Q);\r\n    FOR_R(j,\
    \ 2 * k) {\r\n      move(p.begin() + n * j, p.begin() + n * j + n / 2, f.begin());\r\
    \n      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j + 2 * n, G.begin());\r\
    \n      fill(f.begin() + n / 2, f.end(), mint(0));\r\n      transposed_ntt(f,\
    \ 1);\r\n      FOR(i, n) {\r\n        f[i] *= W[i];\r\n        F[2 * i] = G[2\
    \ * i + 1] * f[i], F[2 * i + 1] = -G[2 * i] * f[i];\r\n      }\r\n      move(F.begin(),\
    \ F.end(), p.begin() + 2 * n * j);\r\n    }\r\n    if (n <= k) FFT_x(p, 0, 2 *\
    \ k, 1), doubling_y(p, 0, n, 1);\r\n    if (n > k) doubling_y(p, 0, 2 * n, 1),\
    \ FFT_x(p, 0, k, 1);\r\n    return p;\r\n  };\r\n\r\n  vc<mint> Q(4 * n);\r\n\
    \  FOR(i, n) Q[i] = -g[i];\r\n\r\n  vc<mint> p = rec(rec, n, 1, Q);\r\n  p.resize(n);\r\
    \n  reverse(all(p));\r\n  p.resize(n0);\r\n  return p;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> composition_0_garner(vc<mint> f, vc<mint> g) {\r\n  constexpr\
    \ u32 ps[] = {167772161, 469762049, 754974721};\r\n  using mint0 = modint<ps[0]>;\r\
    \n  using mint1 = modint<ps[1]>;\r\n  using mint2 = modint<ps[2]>;\r\n\r\n  auto\
    \ rec = [&](auto& rec, int n, int k, vc<mint> Q) -> vc<mint> {\r\n    if (n ==\
    \ 1) {\r\n      vc<mint> p(2 * k);\r\n      reverse(all(f));\r\n      FOR(i, k)\
    \ p[2 * i] = f[i];\r\n      return p;\r\n    }\r\n    vc<mint0> Q0(4 * n * k),\
    \ R0(4 * n * k), p0(4 * n * k);\r\n    vc<mint1> Q1(4 * n * k), R1(4 * n * k),\
    \ p1(4 * n * k);\r\n    vc<mint2> Q2(4 * n * k), R2(4 * n * k), p2(4 * n * k);\r\
    \n    FOR(i, 2 * n * k) {\r\n      Q0[i] = Q[i].val, R0[i] = (i % 2 == 0 ? Q[i].val\
    \ : (-Q[i]).val);\r\n      Q1[i] = Q[i].val, R1[i] = (i % 2 == 0 ? Q[i].val :\
    \ (-Q[i]).val);\r\n      Q2[i] = Q[i].val, R2[i] = (i % 2 == 0 ? Q[i].val : (-Q[i]).val);\r\
    \n    }\r\n    ntt(Q0, 0), ntt(Q1, 0), ntt(Q2, 0), ntt(R0, 0), ntt(R1, 0), ntt(R2,\
    \ 0);\r\n    FOR(i, 4 * n * k) Q0[i] *= R0[i], Q1[i] *= R1[i], Q2[i] *= R2[i];\r\
    \n    ntt(Q0, 1), ntt(Q1, 1), ntt(Q2, 1);\r\n    vc<mint> QQ(4 * n * k);\r\n \
    \   FOR(i, 4 * n * k) {\r\n      QQ[i] = CRT3<mint, ps[0], ps[1], ps[2]>(Q0[i].val,\
    \ Q1[i].val, Q2[i].val);\r\n    }\r\n    FOR(i, 0, 2 * n * k, 2) { QQ[2 * n *\
    \ k + i] += Q[i] + Q[i]; }\r\n    vc<mint> nxt_Q(2 * n * k);\r\n    FOR(j, 2 *\
    \ k) FOR(i, n / 2) {\r\n      nxt_Q[n * j + i] = QQ[(2 * n) * j + (2 * i + 0)];\r\
    \n    }\r\n\r\n    vc<mint> nxt_p = rec(rec, n / 2, k * 2, nxt_Q);\r\n    vc<mint>\
    \ pq(4 * n * k);\r\n    FOR(j, 2 * k) FOR(i, n / 2) {\r\n      pq[(2 * n) * j\
    \ + (2 * i + 1)] += nxt_p[n * j + i];\r\n    }\r\n\r\n    vc<mint> p(2 * n * k);\r\
    \n    FOR(i, 2 * n * k) { p[i] += pq[2 * n * k + i]; }\r\n    FOR(i, 4 * n * k)\
    \ {\r\n      p0[i] += pq[i].val, p1[i] += pq[i].val, p2[i] += pq[i].val;\r\n \
    \   }\r\n    transposed_ntt(p0, 1), transposed_ntt(p1, 1), transposed_ntt(p2,\
    \ 1);\r\n    FOR(i, 4 * n * k) p0[i] *= R0[i], p1[i] *= R1[i], p2[i] *= R2[i];\r\
    \n    transposed_ntt(p0, 0), transposed_ntt(p1, 0), transposed_ntt(p2, 0);\r\n\
    \    FOR(i, 2 * n * k) {\r\n      p[i] += CRT3<mint, ps[0], ps[1], ps[2]>(p0[i].val,\
    \ p1[i].val, p2[i].val);\r\n    }\r\n    return p;\r\n  };\r\n  assert(len(f)\
    \ == len(g));\r\n  int n = 1;\r\n  while (n < len(f)) n *= 2;\r\n  int out_len\
    \ = len(f);\r\n  f.resize(n), g.resize(n);\r\n  int k = 1;\r\n  vc<mint> Q(2 *\
    \ n);\r\n  FOR(i, n) Q[i] = -g[i];\r\n  vc<mint> p = rec(rec, n, k, Q);\r\n\r\n\
    \  vc<mint> output(n);\r\n  FOR(i, n) output[i] = p[i];\r\n  reverse(all(output));\r\
    \n  output.resize(out_len);\r\n  return output;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> composition(vc<mint> f, vc<mint> g) {\r\n  assert(len(f) ==\
    \ len(g));\r\n  if (f.empty()) return {};\r\n  // [x^0]g=0 \u306B\u5E30\u7740\u3057\
    \u3066\u304A\u304F\r\n  if (g[0] != mint(0)) {\r\n    f = poly_taylor_shift<mint>(f,\
    \ g[0]);\r\n    g[0] = 0;\r\n  }\r\n  if (mint::can_ntt()) { return composition_0_ntt(f,\
    \ g); }\r\n  return composition_0_garner(f, g);\r\n}\r\n#line 8 \"test/2_library_checker/polynomial/composition_dmint.test.cpp\"\
    \n\nusing mint = dmint;\n\nvoid solve() {\n  mint::set_mod(998244353);\n  LL(N);\n\
    \  VEC(mint, f, N);\n  VEC(mint, g, N);\n  f = composition(f, g);\n  print(f);\n\
    }\n\nsigned main() { solve(); }\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/composition_of_formal_power_series_large\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/dynamic_modint.hpp\"\
    \n#include \"poly/composition.hpp\"\n\nusing mint = dmint;\n\nvoid solve() {\n\
    \  mint::set_mod(998244353);\n  LL(N);\n  VEC(mint, f, N);\n  VEC(mint, g, N);\n\
    \  f = composition(f, g);\n  print(f);\n}\n\nsigned main() { solve(); }\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/dynamic_modint.hpp
  - mod/modint_common.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - random/base.hpp
  - nt/primetest.hpp
  - mod/mongomery_modint.hpp
  - mod/mod_pow.hpp
  - mod/barrett.hpp
  - poly/composition.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/mod_inv.hpp
  - mod/crt3.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/poly_taylor_shift.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - poly/transposed_ntt.hpp
  isVerificationFile: true
  path: test/2_library_checker/polynomial/composition_dmint.test.cpp
  requiredBy: []
  timestamp: '2025-02-12 05:55:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/polynomial/composition_dmint.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/polynomial/composition_dmint.test.cpp
- /verify/test/2_library_checker/polynomial/composition_dmint.test.cpp.html
title: test/2_library_checker/polynomial/composition_dmint.test.cpp
---
