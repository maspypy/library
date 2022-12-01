---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  - icon: ':x:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':x:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_mod
    links:
    - https://judge.yosupo.jp/problem/kth_root_mod
  bundledCode: "#line 1 \"test/library_checker/math/kth_root_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\r\n#line 1 \"my_template.hpp\"\
    \n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
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
    \ \"other/io.hpp\"\nnamespace fastio {\r\n// https://nyaannyaan.github.io/library/misc/fastio.hpp\
    \ \u3092\u5143\u306B\u6539\u9020\r\n\r\n// \u30AF\u30E9\u30B9\u304C read(), print()\
    \ \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\
    \u30BF\u95A2\u6570\r\nstruct has_print_impl {\r\n  template <class T>\r\n  static\
    \ auto check(T &&x) -> decltype(x.print(), std::true_type{});\r\n\r\n  template\
    \ <class T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate\
    \ <class T>\r\nclass has_print : public decltype(has_print_impl::check<T>(std::declval<T>()))\
    \ {\r\n};\r\n\r\nstruct has_read_impl {\r\n  template <class T>\r\n  static auto\
    \ check(T &&x) -> decltype(x.read(), std::true_type{});\r\n\r\n  template <class\
    \ T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate <class\
    \ T>\r\nclass has_read : public decltype(has_read_impl::check<T>(std::declval<T>()))\
    \ {};\r\n\r\nstatic constexpr int SZ = 1 << 17;\r\nchar inbuf[SZ], outbuf[SZ];\r\
    \nint in_left = 0, in_right = 0, out_right = 0;\r\n\r\nstruct Pre {\r\n  char\
    \ num[40000];\r\n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000;\
    \ i++) {\r\n      int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n     \
    \   num[i * 4 + j] = n % 10 + '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n\
    \  }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n  int len = in_right -\
    \ in_left;\r\n  memmove(inbuf, inbuf + in_left, len);\r\n  in_right = len + fread(inbuf\
    \ + len, 1, SZ - len, stdin);\r\n  in_left = 0;\r\n}\r\n\r\ninline void flush()\
    \ {\r\n  fwrite(outbuf, 1, out_right, stdout);\r\n  out_right = 0;\r\n}\r\n\r\n\
    inline void read_single(char &c) {\r\n  if (in_left + 32 > in_right) load();\r\
    \n  c = inbuf[in_left++];\r\n}\r\n\r\ntemplate <class T, enable_if_t<is_same<T,\
    \ string>::value, int> = 0>\r\ninline void read_single(T &x) {\r\n  char c = '\
    \ ';\r\n  do {\r\n    if (in_left + 32 > in_right) load();\r\n    c = inbuf[in_left++];\r\
    \n  } while (c == ' ' || c == '\\n');\r\n  x += c;\r\n  while (1) {\r\n    if\
    \ (in_left + 32 > in_right) load();\r\n    c = inbuf[in_left++];\r\n    if (c\
    \ == ' ' || c == '\\n') break;\r\n    x += c;\r\n  }\r\n}\r\n\r\ntemplate <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\r\ninline void read_single(T\
    \ &x) {\r\n  if (in_left + 32 > in_right) load();\r\n  char c;\r\n  do\r\n   \
    \ c = inbuf[in_left++];\r\n  while (c < '-');\r\n  bool minus = false;\r\n  if\
    \ constexpr (is_signed<T>::value == true) {\r\n    if (c == '-') minus = true,\
    \ c = inbuf[in_left++];\r\n  }\r\n  x = 0;\r\n  while (c >= '0') {\r\n    x =\
    \ x * 10 + (c & 15);\r\n    c = inbuf[in_left++];\r\n  }\r\n  if constexpr (is_signed<T>::value\
    \ == true) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\ntemplate <typename T,\
    \ typename enable_if<has_read<T>::value>::type * = nullptr>\r\ninline void read_single(T\
    \ x) {\r\n  x.read();\r\n}\r\ntemplate <class T>\r\ninline void read_single(vector<T>\
    \ &ref) {\r\n  for (auto &d: ref) read_single(d);\r\n}\r\ntemplate <class T, int\
    \ N>\r\ninline void read_single(array<T, N> &ref) {\r\n  for (auto &d: ref) read_single(d);\r\
    \n}\r\ntemplate <class T, class U>\r\ninline void read_single(pair<T, U> &p) {\r\
    \n  read_single(p.first), read_single(p.second);\r\n}\r\ntemplate <class... T>\r\
    \ninline void read_single(tuple<T...> &tpl) {\r\n  apply([&](auto... t) { (read(t),\
    \ ...); }, tpl);\r\n}\r\n\r\ninline void read() {}\r\ntemplate <typename Head,\
    \ typename... Tail>\r\ninline void read(Head &head, Tail &... tail) {\r\n  read_single(head);\r\
    \n  read(tail...);\r\n}\r\n\r\ninline void write(char c) {\r\n  if (out_right\
    \ > SZ - 32) flush();\r\n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool\
    \ b) {\r\n  if (out_right > SZ - 32) flush();\r\n  outbuf[out_right++] = b ? '1'\
    \ : '0';\r\n}\r\ninline void write(const string &s) {\r\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\r\n  memcpy(outbuf + out_right, s.data(), sizeof(char) *\
    \ s.size());\r\n  out_right += s.size();\r\n}\r\ntemplate <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\ninline void write(T x) {\r\n  if (out_right > SZ - 32) flush();\r\
    \n  if (!x) {\r\n    outbuf[out_right++] = '0';\r\n    return;\r\n  }\r\n  if\
    \ constexpr (is_signed<T>::value == true) {\r\n    if (x < 0) outbuf[out_right++]\
    \ = '-', x = -x;\r\n  }\r\n  int i = 12;\r\n  char buf[16];\r\n  while (x >= 10000)\
    \ {\r\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\r\n    x /= 10000;\r\
    \n    i -= 4;\r\n  }\r\n  if (x < 100) {\r\n    if (x < 10) {\r\n      outbuf[out_right]\
    \ = '0' + x;\r\n      ++out_right;\r\n    } else {\r\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\r\n      uint32_t r = uint32_t(x) - q * 10;\r\n      outbuf[out_right]\
    \ = '0' + q;\r\n      outbuf[out_right + 1] = '0' + r;\r\n      out_right += 2;\r\
    \n    }\r\n  } else {\r\n    if (x < 1000) {\r\n      memcpy(outbuf + out_right,\
    \ pre.num + (x << 2) + 1, 3);\r\n      out_right += 3;\r\n    } else {\r\n   \
    \   memcpy(outbuf + out_right, pre.num + (x << 2), 4);\r\n      out_right += 4;\r\
    \n    }\r\n  }\r\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\r\n  out_right\
    \ += 12 - i;\r\n}\r\ninline void write(const double &x) {\r\n  ostringstream oss;\r\
    \n  oss << fixed << setprecision(15) << x;\r\n  string s = oss.str();\r\n  write(s);\r\
    \n}\r\ninline void write(const long double &x) {\r\n  ostringstream oss;\r\n \
    \ oss << fixed << setprecision(15) << x;\r\n  string s = oss.str();\r\n  write(s);\r\
    \n}\r\ntemplate <typename T, typename enable_if<has_print<T>::value>::type * =\
    \ nullptr>\r\ninline void write(T x) {\r\n  x.print();\r\n}\r\ntemplate <class\
    \ T>\r\nvoid write(const vector<T> &val) {\r\n  auto n = val.size();\r\n  for\
    \ (size_t i = 0; i < n; i++) {\r\n    if (i) write(' ');\r\n    write(val[i]);\r\
    \n  }\r\n}\r\ntemplate <class T, class U>\r\nvoid write(const pair<T, U> &val)\
    \ {\r\n  write(val.first);\r\n  write(' ');\r\n  write(val.second);\r\n}\r\ntemplate\
    \ <class T, size_t S>\r\ninline void write(const array<T, S> &val) {\r\n  auto\
    \ n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) write('\
    \ ');\r\n    write(val[i]);\r\n  }\r\n}\r\ninline void write(i128 val) {\r\n \
    \ string s;\r\n  bool negative = 0;\r\n  if (val < 0) {\r\n    negative = 1;\r\
    \n    val = -val;\r\n  }\r\n  while (val) {\r\n    s += '0' + int(val % 10);\r\
    \n    val /= 10;\r\n  }\r\n  if (negative) s += \"-\";\r\n  reverse(all(s));\r\
    \n  if (len(s) == 0) s = \"0\";\r\n  write(s);\r\n}\r\nstruct Dummy {\r\n  Dummy()\
    \ { atexit(flush); }\r\n} dummy;\r\n\r\nvoid print() { fastio::write('\\n'); }\r\
    \ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&... tail)\
    \ {\r\n  fastio::write(head);\r\n  if (sizeof...(Tail)) fastio::write(' ');\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n} // namespace fastio\r\nusing fastio::read;\r\
    \nusing fastio::print;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\
    \n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define CHAR(...)   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    \r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n \
    \ read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print<string>(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print<string>(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t);\
    \ }\r\nvoid yes(bool t = 1) { print<string>(t ? \"yes\" : \"no\"); }\r\nvoid no(bool\
    \ t = 1) { yes(!t); }\r\n#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using\
    \ i64 = int64_t;\r\n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\
    \r\n  inline static u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod\
    \ m)\r\n  static void set_mod(u64 m) {\r\n    assert(m < (1ull << 62));\r\n  \
    \  assert((m & 1) == 1);\r\n    m64::m = m;\r\n    n2 = -u128(m) % m;\r\n    r\
    \ = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\n    r = -r;\r\n    assert(r * m ==\
    \ -1ull);\r\n  }\r\n  static u64 reduce(u128 b) { return (b + u128(u64(b) * r)\
    \ * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() : x(0) {}\r\n  m64(u64 x) : x(reduce(u128(x)\
    \ * n2)){};\r\n  u64 val() const {\r\n    u64 y = reduce(x);\r\n    return y >=\
    \ m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64 y) {\r\n    x += y.x - (m <<\
    \ 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\
    \n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n    x = (i64(x) < 0 ? x + (m\
    \ << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator*=(m64 y) {\r\n  \
    \  x = reduce(u128(x) * y.x);\r\n    return *this;\r\n  }\r\n  m64 operator+(m64\
    \ y) const { return m64(*this) += y; }\r\n  m64 operator-(m64 y) const { return\
    \ m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return m64(*this) *= y;\
    \ }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64 y) const { return\
    \ not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64 y = 1, z = *this;\r\
    \n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *= z;\r\n    return y;\r\
    \n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\n  using u64 = uint64_t;\r\
    \n  if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\n  if (x % 2 == 0\
    \ or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n  if (x < 121) return\
    \ x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x - 1);\r\n  m64::set_mod(x);\r\
    \n  const m64 one(1), minus_one(x - 1);\r\n  auto ok = [&](u64 a) {\r\n    auto\
    \ y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one and y != minus_one\
    \ and t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one and t % 2 == 0) return\
    \ false;\r\n    return true;\r\n  };\r\n  if (x < (1ull << 32)) {\r\n    for (u64\
    \ a: {2, 7, 61})\r\n      if (not ok(a)) return false;\r\n  } else {\r\n    for\
    \ (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\r\n      if (x\
    \ <= a) return true;\r\n      if (not ok(a)) return false;\r\n    }\r\n  }\r\n\
    \  return true;\r\n}\n#line 2 \"mod/primitive_root.hpp\"\n\r\n#line 3 \"nt/factor.hpp\"\
    \n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll n) { return uniform_int_distribution<ll>(0,\
    \ n - 1)(rng_mt); }\n\nll rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n >\
    \ 1);\n  const m64 cc(c);\n  auto f = [&](m64 x) { return x * x + cc; };\n  m64\
    \ x = 1, y = 2, z = 1, q = 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5);\
    \ // ?\n  for (ll r = 1; g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n\
    \    for (ll k = 0; k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m,\
    \ r - k)) y = f(y), q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if\
    \ (g == n) do {\n      z = f(z);\n      g = gcd((x - z).val(), n);\n    } while\
    \ (g == 1);\n  return g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n\
    \  if (primetest(n)) return n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n\
    \    if (primetest(m)) return m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n\
    \  assert(false);\n  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\
    \u308B\nvc<pair<ll, int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>>\
    \ pf;\n  FOR3(p, 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n\
    \      ll e = 0;\n      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p,\
    \ e);\n    }\n  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll\
    \ e = 0;\n    do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n \
    \ }\n  sort(all(pf));\n  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n,\
    \ vc<int>& lpf) {\n  vc<pair<ll, int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n\
    \    int e = 0;\n    while (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n\
    \    res.eb(p, e);\n  }\n  return res;\n}\n#line 2 \"mod/fast_div.hpp\"\nstruct\
    \ fast_div {\r\n  // Min25 https://judge.yosupo.jp/submission/46090\r\n  // \u540C\
    \u3058\u5B9A\u6570\u3067\u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\u3068\u304D\
    \u306E\u9AD8\u901F\u5316\u306B\u4F7F\u3048\u308B\r\n  using i64 = long long;\r\
    \n  using u64 = unsigned long long;\r\n  using u128 = __uint128_t;\r\n  constexpr\
    \ fast_div() : m(), s(), x() {}\r\n  constexpr fast_div(int n)\r\n      : m(n),\
    \ s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\n  constexpr\
    \ friend u64 operator/(u64 n, const fast_div& d) {\r\n    return (u128(n) * d.x\
    \ >> d.s) >> 64;\r\n  }\r\n  constexpr friend int operator%(u64 n, const fast_div&\
    \ d) {\r\n    return n - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64, int>\
    \ divmod(u64 n) const {\r\n    u64 q = n / *this;\r\n    return {q, n - q * m};\r\
    \n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 3 \"mod/mod_pow.hpp\"\
    \n// int\r\nll mod_pow(ll a, ll n, int mod){\r\n  fast_div fd(mod);\r\n  a = a\
    \ % fd;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while(n){\r\n    if(n & 1) v = v *\
    \ p % fd;\r\n    p = p * p % fd;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\
    \r\nll mod_pow_long(ll a, ll n, ll mod){\r\n  a %= mod;\r\n  ll p = a;\r\n  ll\
    \ v = 1;\r\n  while(n){\r\n    if(n & 1) v = i128(v) * p % mod;\r\n    p = i128(p)\
    \ * p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  FOR3(x, 1, p) {\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n\
    }\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf = factor(p - 1);\r\n  auto\
    \ is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if (mod_pow_long(g,\
    \ (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\n  while (1)\
    \ {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return\
    \ -1;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\
    \r\nll mod_inv(ll val, ll mod) {\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\
    \n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a /\
    \ b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u\
    \ += mod;\r\n  return u;\r\n}\r\n#line 2 \"ds/hashmap.hpp\"\ntemplate <typename\
    \ Val, int LOG = 20>\r\nstruct HashMapLL {\r\n  int N;\r\n  ll* keys;\r\n  Val*\
    \ vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const int shift;\r\n\
    \  const uint64_t r = 11995408973635179863ULL;\r\n  HashMapLL()\r\n      : N(1\
    \ << LOG), keys(new ll[N]), vals(new Val[N]), shift(64 - __lg(N)) {}\r\n  int\
    \ hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const ll& key, Val default_value) {\r\n    int i = index(key);\r\n \
    \   if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n\r\n  vc<pair<ll, Val>> items() {\r\n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\
    \n    for (auto&& i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\
    \n};\r\n\r\ntemplate <typename KEY, typename VAL, int LOG>\r\nstruct HashMap {\r\
    \n  HashMapLL<VAL, LOG> MP;\r\n  function<ll(KEY)> f;\r\n  HashMap(function<ll(KEY)>\
    \ f) : MP(), f(f) {}\r\n\r\n  int index(const KEY& key) { return MP.index(f(key));\
    \ }\r\n\r\n  VAL& operator[](const KEY& key) { return MP[f(key)]; }\r\n\r\n  bool\
    \ contain(const KEY& key) { return MP.contain(f(key)); }\r\n\r\n  bool count(const\
    \ KEY& key) { return MP.count(f(key)); }\r\n\r\n  void reset() { MP.reset(); }\r\
    \n};\r\n#line 5 \"mod/mod_kth_root.hpp\"\n\r\n// mod \u306F int\r\nint mod_kth_root(ll\
    \ k, ll a, int mod) {\r\n  assert(primetest(mod) && 0 <= a && a < mod);\r\n  if\
    \ (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a == 0) return 0;\r\n  if (mod ==\
    \ 2) return a;\r\n  k %= mod - 1;\r\n  fast_div fd(mod);\r\n\r\n  ll g = gcd(k,\
    \ mod - 1);\r\n  if (mod_pow(a, (mod - 1) / g, mod) != 1) return -1;\r\n\r\n \
    \ ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a = mod_pow(a, c, mod);\r\n  k =\
    \ (k * c) % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g = primitive_root(mod);\r\
    \n\r\n  auto solve_pp = [&](ll p, int e, ll a) -> ll {\r\n    int f = 0;\r\n \
    \   ll pf = 1;\r\n    while ((mod - 1) % (pf * p) == 0) ++f, pf *= p;\r\n    ll\
    \ m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\
    \u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\u3068\u308A\u305F\u3044\u3002\
    \u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\u3066\u3044\u308B\r\n    \u30FB\
    a / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\u3002\u307E\u305A\u306F\u3001b\
    \ \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\u5897\u3084\u3057\u3066\u3044\
    \u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n\
    \    int pc = 1;\r\n    FOR(c) pc *= p;\r\n    int pe = 1;\r\n    FOR(e) pe *=\
    \ p;\r\n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\u59CB p \u4E57\u6839\u306B\
    \u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\u306E\u30BB\u30C3\u30C8\
    \u30A2\u30C3\u30D7\r\n    ll G = mod_pow(g, (mod - 1) / p, mod);\r\n    int M\
    \ = 0;\r\n    unordered_map<ll, int> MP;\r\n    ll GM_inv = -1;\r\n    if (c)\
    \ {\r\n      while (M * M < p) ++M;\r\n      MP.reserve(M + 1);\r\n      ll Gpow\
    \ = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n        Gpow = Gpow *\
    \ G % fd;\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod - 2, mod);\r\n    }\r\
    \n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1 \u304C\u5206\u304B\u3063\
    \u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1 \u306B\u3057\u305F\u3044\u3002\
    \r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\u63A2\u3059\u3002\u539F\u59CB\
    \ p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B = G^k \u306B\u5E30\u7740\u3002\
    \r\n      */\r\n      ll B = mod_pow(b, m * pc / p, mod);\r\n      int k = [&](ll\
    \ B) -> int {\r\n        FOR(m, M + 1) {\r\n          if (MP.count(B)) return\
    \ m * M + MP[B];\r\n          B = B * GM_inv % fd;\r\n        }\r\n        return\
    \ -1;\r\n      }(B);\r\n      x = x * mod_pow(g, pf / pc / pe * k, mod) % fd;\r\
    \n      ll exp = pf / pc * k % (mod - 1);\r\n      b = b * mod_pow(g, mod - 1\
    \ - exp, mod) % fd;\r\n      --c;\r\n      pc /= p;\r\n    }\r\n    int k = pe\
    \ - mod_inv(m, pe);\r\n    k = (k * m + 1) / pe;\r\n    ll y = mod_pow(b, k, mod);\r\
    \n    x = x * y % fd;\r\n    return x;\r\n  };\r\n\r\n  auto pf = factor(k);\r\
    \n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return a;\r\n}\r\n\r\n\
    ll mod_kth_root_long(ll k, ll a, ll mod) {\r\n  static HashMapLL<ll, 20> MP;\r\
    \n\r\n  assert(primetest(mod) && 0 <= a && a < mod);\r\n  if (k == 0) return (a\
    \ == 1 ? 1 : -1);\r\n  if (a == 0) return 0;\r\n  if (mod == 2) return a;\r\n\
    \  k %= mod - 1;\r\n\r\n  ll g = gcd(k, mod - 1);\r\n  if (mod_pow_long(a, (mod\
    \ - 1) / g, mod) != 1) return -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\
    \n  a = mod_pow_long(a, c, mod);\r\n  k = i128(k) * c % (mod - 1);\r\n  if (k\
    \ == 0) return 1;\r\n\r\n  g = primitive_root_long(mod);\r\n\r\n  auto solve_pp\
    \ = [&](ll p, ll e, ll a) -> ll {\r\n    ll f = 0;\r\n    ll pf = 1;\r\n    while\
    \ (((mod - 1) / pf) % p == 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n\
    \    /*\r\n    \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E\
    \ p^e \u4E57\u6839\u3092\u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\
    \u306F\u5206\u304B\u3063\u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\
    \u7DAD\u6301\u3059\u308B\u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\
    \u308B\u56DE\u6570\u3092\u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\
    \n    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n    ll pc = 1;\r\n    FOR(c)\
    \ pc *= p;\r\n    ll pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\
    \u3089\u3070\u539F\u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\
    \u6570\u554F\u984C\u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow_long(g,\
    \ (mod - 1) / p, mod);\r\n    ll M = 0;\r\n    ll GM_inv = -1;\r\n    if (c) {\r\
    \n      while (M * M < p) ++M;\r\n      MP.reset();\r\n      ll Gpow = 1;\r\n\
    \      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n        Gpow = i128(Gpow) * G %\
    \ mod;\r\n      }\r\n      GM_inv = mod_pow_long(Gpow, mod - 2, mod);\r\n    }\r\
    \n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1 \u304C\u5206\u304B\u3063\
    \u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1 \u306B\u3057\u305F\u3044\u3002\
    \r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\u63A2\u3059\u3002\u539F\u59CB\
    \ p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B = G^k \u306B\u5E30\u7740\u3002\
    \r\n      */\r\n      ll B = mod_pow_long(b, pc / p * m, mod);\r\n      ll k =\
    \ [&](ll B) -> ll {\r\n        FOR(m, M + 1) {\r\n          if (MP.count(B)) return\
    \ m * M + MP[B];\r\n          B = i128(B) * GM_inv % mod;\r\n        }\r\n   \
    \     return -1;\r\n      }(B);\r\n      x = i128(x) * mod_pow_long(g, pf / pc\
    \ / pe * k, mod) % mod;\r\n\r\n      ll exp = pf / pc * i128(k) % (mod - 1);\r\
    \n      b = i128(b) * mod_pow_long(g, mod - 1 - exp, mod) % mod;\r\n      --c;\r\
    \n      pc /= p;\r\n    }\r\n    ll k = pe - mod_inv(m, pe);\r\n    k = (i128(k)\
    \ * m + 1) / pe;\r\n    ll y = mod_pow_long(b, k, mod);\r\n    x = i128(x) * y\
    \ % mod;\r\n    return x;\r\n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&&\
    \ [p, e]: pf) a = solve_pp(p, e, a);\r\n  return a;\r\n}\r\n#line 5 \"test/library_checker/math/kth_root_mod.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(k, y, p);\r\n  ll x = mod_kth_root(k, y % p, p);\r\
    \n  print(x);\r\n}\r\n\r\nsigned main() {\r\n  LL(T);\r\n  FOR(T) solve();\r\n\
    \r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"mod/mod_kth_root.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(k, y, p);\r\n  ll x = mod_kth_root(k, y % p, p);\r\
    \n  print(x);\r\n}\r\n\r\nsigned main() {\r\n  LL(T);\r\n  FOR(T) solve();\r\n\
    \r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/mod_kth_root.hpp
  - nt/primetest.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - mod/mod_pow.hpp
  - mod/fast_div.hpp
  - random/base.hpp
  - mod/mod_inv.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/library_checker/math/kth_root_mod.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 21:03:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/kth_root_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/kth_root_mod.test.cpp
- /verify/test/library_checker/math/kth_root_mod.test.cpp.html
title: test/library_checker/math/kth_root_mod.test.cpp
---
