---
data:
  _extendedDependsOn: []
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
    - https://trap.jp/post/1224/
  bundledCode: "#line 1 \"test/mytest/minplus_convex.test.cpp\"\n#line 1 \"main.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"library/my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC\
    \ optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using i128 = __int128;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
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
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\ntemplate <typename T, typename U>\npair<T, T> divmod(T x,\
    \ U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ assert(!que.empty());\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate\
    \ <typename T>\nT POP(vc<T> &que) {\n  assert(!que.empty());\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok,\
    \ x));\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n\
    \  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>\
    \ &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>\
    \ &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"library/other/io.hpp\"\n// based on yosupo's\
    \ fastio\n#include <unistd.h>\n\nnamespace fastio {\n#define FASTIO\n// \u30AF\
    \u30E9\u30B9\u304C read(), print() \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\u30E1\u30BF\u95A2\u6570\nstruct has_write_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.write(), std::true_type{});\n\
    \n  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\n};\n\nstruct has_read_impl {\n  template <class T>\n  static auto check(T\
    \ &&x) -> decltype(x.read(), std::true_type{});\n\n  template <class T>\n  static\
    \ auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_read\
    \ : public decltype(has_read_impl::check<T>(std::declval<T>())) {};\n\nstruct\
    \ Scanner {\n  FILE *fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0, ed = 0;\n\
    \  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -= st;\n  \
    \  st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed] =\
    \ '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n  \
    \      reread();\n        if (st == ed) return false;\n      }\n      while (st\
    \ != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n    if\
    \ (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i < ed;\
    \ i++) {\n        if (isspace(line[i])) {\n          sep = true;\n          break;\n\
    \        }\n      }\n      if (!sep) reread();\n    }\n    return true;\n  }\n\
    \  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n  bool\
    \ read_single(T &ref) {\n    if (!succ()) return false;\n    while (true) {\n\
    \      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\n\
    \      ref.append(line + st, sz);\n      st += sz;\n      if (!sz || st != ed)\
    \ break;\n      reread();\n    }\n    return true;\n  }\n  template <class T,\
    \ enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T &ref) {\n\
    \    if (!succ()) return false;\n    bool neg = false;\n    if (line[st] == '-')\
    \ {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while (isdigit(line[st]))\
    \ { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref = -ref;\n    return\
    \ true;\n  }\n  template <typename T,\n            typename enable_if<has_read<T>::value>::type\
    \ * = nullptr>\n  inline bool read_single(T &x) {\n    x.read();\n    return true;\n\
    \  }\n  bool read_single(double &ref) {\n    string s;\n    if (!read_single(s))\
    \ return false;\n    ref = std::stod(s);\n    return true;\n  }\n  bool read_single(char\
    \ &ref) {\n    string s;\n    if (!read_single(s) || s.size() != 1) return false;\n\
    \    ref = s[0];\n    return true;\n  }\n  template <class T>\n  bool read_single(vector<T>\
    \ &ref) {\n    for (auto &d: ref) {\n      if (!read_single(d)) return false;\n\
    \    }\n    return true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T,\
    \ U> &p) {\n    return (read_single(p.first) && read_single(p.second));\n  }\n\
    \  template <size_t N = 0, typename T>\n  void read_single_tuple(T &t) {\n   \
    \ if constexpr (N < std::tuple_size<T>::value) {\n      auto &x = std::get<N>(t);\n\
    \      read_single(x);\n      read_single_tuple<N + 1>(t);\n    }\n  }\n  template\
    \ <class... T>\n  bool read_single(tuple<T...> &tpl) {\n    read_single_tuple(tpl);\n\
    \    return true;\n  }\n  void read() {}\n  template <class H, class... T>\n \
    \ void read(H &h, T &... t) {\n    bool f = read_single(h);\n    assert(f);\n\
    \    read(t...);\n  }\n  Scanner(FILE *fp) : fp(fp) {}\n};\n\nstruct Printer {\n\
    \  Printer(FILE *_fp) : fp(_fp) {}\n  ~Printer() { flush(); }\n\n  static constexpr\
    \ size_t SIZE = 1 << 15;\n  FILE *fp;\n  char line[SIZE], small[50];\n  size_t\
    \ pos = 0;\n  void flush() {\n    fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n\
    \  void write(const char val) {\n    if (pos == SIZE) flush();\n    line[pos++]\
    \ = val;\n  }\n  template <class T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\n  void write(T val) {\n    if (pos > (1 << 15) - 50) flush();\n    if (val\
    \ == 0) {\n      write('0');\n      return;\n    }\n    if (val < 0) {\n     \
    \ write('-');\n      val = -val; // todo min\n    }\n    size_t len = 0;\n   \
    \ while (val) {\n      small[len++] = char(0x30 | (val % 10));\n      val /= 10;\n\
    \    }\n    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 -\
    \ i]; }\n    pos += len;\n  }\n  void write(const string s) {\n    for (char c:\
    \ s) write(c);\n  }\n  void write(const char *s) {\n    size_t len = strlen(s);\n\
    \    for (size_t i = 0; i < len; i++) write(s[i]);\n  }\n  void write(const double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  void write(const long double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  template <typename T,\n     \
    \       typename enable_if<has_write<T>::value>::type * = nullptr>\n  inline void\
    \ write(T x) {\n    x.write();\n  }\n  template <class T>\n  void write(const\
    \ vector<T> val) {\n    auto n = val.size();\n    for (size_t i = 0; i < n; i++)\
    \ {\n      if (i) write(' ');\n      write(val[i]);\n    }\n  }\n  template <class\
    \ T, class U>\n  void write(const pair<T, U> val) {\n    write(val.first);\n \
    \   write(' ');\n    write(val.second);\n  }\n  template <size_t N = 0, typename\
    \ T>\n  void write_tuple(const T t) {\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\n      if constexpr (N > 0) { write(' '); }\n      const auto x = std::get<N>(t);\n\
    \      write(x);\n      write_tuple<N + 1>(t);\n    }\n  }\n  template <class...\
    \ T>\n  bool write(tuple<T...> tpl) {\n    write_tuple(tpl);\n    return true;\n\
    \  }\n  template <class T, size_t S>\n  void write(const array<T, S> val) {\n\
    \    auto n = val.size();\n    for (size_t i = 0; i < n; i++) {\n      if (i)\
    \ write(' ');\n      write(val[i]);\n    }\n  }\n  void write(i128 val) {\n  \
    \  string s;\n    bool negative = 0;\n    if (val < 0) {\n      negative = 1;\n\
    \      val = -val;\n    }\n    while (val) {\n      s += '0' + int(val % 10);\n\
    \      val /= 10;\n    }\n    if (negative) s += \"-\";\n    reverse(all(s));\n\
    \    if (len(s) == 0) s = \"0\";\n    write(s);\n  }\n};\nScanner scanner = Scanner(stdin);\n\
    Printer printer = Printer(stdout);\nvoid flush() { printer.flush(); }\nvoid print()\
    \ { printer.write('\\n'); }\ntemplate <class Head, class... Tail>\nvoid print(Head\
    \ &&head, Tail &&... tail) {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write('\
    \ ');\n  print(forward<Tail>(tail)...);\n}\n\nvoid read() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid read(Head &head, Tail &... tail) {\n  scanner.read(head);\n\
    \  read(tail...);\n}\n} // namespace fastio\nusing fastio::print;\nusing fastio::flush;\n\
    using fastio::read;\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)\
    \      \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)  \
    \ \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n\
    \  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size)\
    \ \\\n  vector<type> name(size);    \\\n  read(name)\n#define VV(type, name, h,\
    \ w)                     \\\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\n\
    void NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"\
    No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"\
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line 2 \"library/random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 5 \"main.cpp\"\
    \n\n#line 1 \"library/convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
    \ (i,k) \u306E\u3046\u3061\u9078\u3076\u65B9\uFF08j or k\uFF09\ntemplate <typename\
    \ F>\nvc<int> SMAWK(int H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int>\
    \ X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\
    \    vc<int> YY;\n    for (auto&& y: Y) {\n      while (len(YY)) {\n        int\
    \ py = YY.back(), x = X[len(YY) - 1];\n        if (select(x, py, y) == py) break;\n\
    \        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\
    \    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs,\
    \ XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n   \
    \ int p = 0;\n    FOR(i, 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() :\
    \ I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n\
    \        best = select(X[i], best, Y[p]);\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n\
    \  return dfs(dfs, X, Y);\n}\n#line 2 \"library/convex/minplus_convolution_convex.hpp\"\
    \n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution_convex(vc<T>\
    \ A, vc<T> B, const T INF) {\n  static_assert(convA || convB);\n  assert(INF <\
    \ INF + INF);\n  if (!convB) swap(A, B);\n  int NA = len(A), NB = len(B);\n  int\
    \ N = NA + NB - 1;\n  int L = 0, R = NB;\n  while (L < R && B[L] == INF) ++L;\n\
    \  if (L == R) return vc<T>(N, INF);\n  while (B[R - 1] == INF) --R;\n  B = {B.begin()\
    \ + L, B.begin() + R};\n  int nB = R - L;\n  int n = NA + nB - 1;\n\n  auto select\
    \ = [&](int i, int j, int k) -> int {\n    if (i < k) return j;\n    if (i - j\
    \ >= nB) return k;\n    return (A[j] + B[i - j] > A[k] + B[i - k] ? k : j);\n\
    \  };\n\n  vc<int> J = SMAWK(n, NA, select);\n  vc<T> C(N, INF);\n  FOR(i, n)\
    \ C[L + i] = (A[J[i]] == INF ? INF : A[J[i]] + B[i - J[i]]);\n  return C;\n}\n\
    #line 7 \"main.cpp\"\n\nconst int INF = numeric_limits<int>::max() / 2;\n\nvc<int>\
    \ gen(int L, int N, int R) {\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(-100, 100);\n\
    \  sort(all(A));\n  A = cumsum<int>(A);\n  FOR(L) A.insert(A.begin(), INF);\n\
    \  FOR(R) A.insert(A.end(), INF);\n  return A;\n}\n\nvc<int> naive(vc<int> A,\
    \ vc<int> B) {\n  int N = len(A), M = len(B);\n  vc<int> C(N + M - 1, INF);\n\
    \  FOR(i, N) FOR(j, M) {\n    if (A[i] == INF || B[j] == INF) continue;\n    chmin(C[i\
    \ + j], A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1,\
    \ 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1);\n    FOR(a2, 5) FOR(b2, 10)\
    \ FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2);\n      vc<int> C = minplus_convolution_convex<int,\
    \ 1, 1>(A, B, INF);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\ntemplate <typename T, typename U>\npair<T, T> divmod(T x,\
    \ U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ assert(!que.empty());\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate\
    \ <typename T>\nT POP(vc<T> &que) {\n  assert(!que.empty());\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok,\
    \ x));\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n\
    \  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>\
    \ &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>\
    \ &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"library/other/io.hpp\"\n// based on yosupo's\
    \ fastio\n#include <unistd.h>\n\nnamespace fastio {\n#define FASTIO\n// \u30AF\
    \u30E9\u30B9\u304C read(), print() \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\u30E1\u30BF\u95A2\u6570\nstruct has_write_impl {\n  template\
    \ <class T>\n  static auto check(T &&x) -> decltype(x.write(), std::true_type{});\n\
    \n  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\n};\n\nstruct has_read_impl {\n  template <class T>\n  static auto check(T\
    \ &&x) -> decltype(x.read(), std::true_type{});\n\n  template <class T>\n  static\
    \ auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_read\
    \ : public decltype(has_read_impl::check<T>(std::declval<T>())) {};\n\nstruct\
    \ Scanner {\n  FILE *fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0, ed = 0;\n\
    \  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -= st;\n  \
    \  st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed] =\
    \ '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n  \
    \      reread();\n        if (st == ed) return false;\n      }\n      while (st\
    \ != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n    if\
    \ (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i < ed;\
    \ i++) {\n        if (isspace(line[i])) {\n          sep = true;\n          break;\n\
    \        }\n      }\n      if (!sep) reread();\n    }\n    return true;\n  }\n\
    \  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n  bool\
    \ read_single(T &ref) {\n    if (!succ()) return false;\n    while (true) {\n\
    \      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\n\
    \      ref.append(line + st, sz);\n      st += sz;\n      if (!sz || st != ed)\
    \ break;\n      reread();\n    }\n    return true;\n  }\n  template <class T,\
    \ enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T &ref) {\n\
    \    if (!succ()) return false;\n    bool neg = false;\n    if (line[st] == '-')\
    \ {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while (isdigit(line[st]))\
    \ { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref = -ref;\n    return\
    \ true;\n  }\n  template <typename T,\n            typename enable_if<has_read<T>::value>::type\
    \ * = nullptr>\n  inline bool read_single(T &x) {\n    x.read();\n    return true;\n\
    \  }\n  bool read_single(double &ref) {\n    string s;\n    if (!read_single(s))\
    \ return false;\n    ref = std::stod(s);\n    return true;\n  }\n  bool read_single(char\
    \ &ref) {\n    string s;\n    if (!read_single(s) || s.size() != 1) return false;\n\
    \    ref = s[0];\n    return true;\n  }\n  template <class T>\n  bool read_single(vector<T>\
    \ &ref) {\n    for (auto &d: ref) {\n      if (!read_single(d)) return false;\n\
    \    }\n    return true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T,\
    \ U> &p) {\n    return (read_single(p.first) && read_single(p.second));\n  }\n\
    \  template <size_t N = 0, typename T>\n  void read_single_tuple(T &t) {\n   \
    \ if constexpr (N < std::tuple_size<T>::value) {\n      auto &x = std::get<N>(t);\n\
    \      read_single(x);\n      read_single_tuple<N + 1>(t);\n    }\n  }\n  template\
    \ <class... T>\n  bool read_single(tuple<T...> &tpl) {\n    read_single_tuple(tpl);\n\
    \    return true;\n  }\n  void read() {}\n  template <class H, class... T>\n \
    \ void read(H &h, T &... t) {\n    bool f = read_single(h);\n    assert(f);\n\
    \    read(t...);\n  }\n  Scanner(FILE *fp) : fp(fp) {}\n};\n\nstruct Printer {\n\
    \  Printer(FILE *_fp) : fp(_fp) {}\n  ~Printer() { flush(); }\n\n  static constexpr\
    \ size_t SIZE = 1 << 15;\n  FILE *fp;\n  char line[SIZE], small[50];\n  size_t\
    \ pos = 0;\n  void flush() {\n    fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n\
    \  void write(const char val) {\n    if (pos == SIZE) flush();\n    line[pos++]\
    \ = val;\n  }\n  template <class T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\n  void write(T val) {\n    if (pos > (1 << 15) - 50) flush();\n    if (val\
    \ == 0) {\n      write('0');\n      return;\n    }\n    if (val < 0) {\n     \
    \ write('-');\n      val = -val; // todo min\n    }\n    size_t len = 0;\n   \
    \ while (val) {\n      small[len++] = char(0x30 | (val % 10));\n      val /= 10;\n\
    \    }\n    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 -\
    \ i]; }\n    pos += len;\n  }\n  void write(const string s) {\n    for (char c:\
    \ s) write(c);\n  }\n  void write(const char *s) {\n    size_t len = strlen(s);\n\
    \    for (size_t i = 0; i < len; i++) write(s[i]);\n  }\n  void write(const double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  void write(const long double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  template <typename T,\n     \
    \       typename enable_if<has_write<T>::value>::type * = nullptr>\n  inline void\
    \ write(T x) {\n    x.write();\n  }\n  template <class T>\n  void write(const\
    \ vector<T> val) {\n    auto n = val.size();\n    for (size_t i = 0; i < n; i++)\
    \ {\n      if (i) write(' ');\n      write(val[i]);\n    }\n  }\n  template <class\
    \ T, class U>\n  void write(const pair<T, U> val) {\n    write(val.first);\n \
    \   write(' ');\n    write(val.second);\n  }\n  template <size_t N = 0, typename\
    \ T>\n  void write_tuple(const T t) {\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\n      if constexpr (N > 0) { write(' '); }\n      const auto x = std::get<N>(t);\n\
    \      write(x);\n      write_tuple<N + 1>(t);\n    }\n  }\n  template <class...\
    \ T>\n  bool write(tuple<T...> tpl) {\n    write_tuple(tpl);\n    return true;\n\
    \  }\n  template <class T, size_t S>\n  void write(const array<T, S> val) {\n\
    \    auto n = val.size();\n    for (size_t i = 0; i < n; i++) {\n      if (i)\
    \ write(' ');\n      write(val[i]);\n    }\n  }\n  void write(i128 val) {\n  \
    \  string s;\n    bool negative = 0;\n    if (val < 0) {\n      negative = 1;\n\
    \      val = -val;\n    }\n    while (val) {\n      s += '0' + int(val % 10);\n\
    \      val /= 10;\n    }\n    if (negative) s += \"-\";\n    reverse(all(s));\n\
    \    if (len(s) == 0) s = \"0\";\n    write(s);\n  }\n};\nScanner scanner = Scanner(stdin);\n\
    Printer printer = Printer(stdout);\nvoid flush() { printer.flush(); }\nvoid print()\
    \ { printer.write('\\n'); }\ntemplate <class Head, class... Tail>\nvoid print(Head\
    \ &&head, Tail &&... tail) {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write('\
    \ ');\n  print(forward<Tail>(tail)...);\n}\n\nvoid read() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid read(Head &head, Tail &... tail) {\n  scanner.read(head);\n\
    \  read(tail...);\n}\n} // namespace fastio\nusing fastio::print;\nusing fastio::flush;\n\
    using fastio::read;\n\n#define INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define LL(...)   \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)\
    \      \\\n  string __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define CHAR(...)  \
    \ \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define DBL(...)      \\\n\
    \  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define VEC(type, name, size)\
    \ \\\n  vector<type> name(size);    \\\n  read(name)\n#define VV(type, name, h,\
    \ w)                     \\\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\n\
    void NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"\
    No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t = 1) { print(t ? \"\
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line 2 \"library/random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 5 \"main.cpp\"\
    \n\n#line 1 \"library/convex/smawk.hpp\"\n// select(i,j,k) \u306F (i,j) \u3068\
    \ (i,k) \u306E\u3046\u3061\u9078\u3076\u65B9\uFF08j or k\uFF09\ntemplate <typename\
    \ F>\nvc<int> SMAWK(int H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int>\
    \ X, vc<int> Y) -> vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n\
    \    vc<int> YY;\n    for (auto&& y: Y) {\n      while (len(YY)) {\n        int\
    \ py = YY.back(), x = X[len(YY) - 1];\n        if (select(x, py, y) == py) break;\n\
    \        YY.pop_back();\n      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n\
    \    vc<int> XX;\n    FOR(i, 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs,\
    \ XX, YY);\n    vc<int> I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n   \
    \ int p = 0;\n    FOR(i, 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() :\
    \ I[i + 1]);\n      int best = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n\
    \        best = select(X[i], best, Y[p]);\n      }\n      I[i] = best;\n    }\n\
    \    return I;\n  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n\
    \  return dfs(dfs, X, Y);\n}\n#line 2 \"library/convex/minplus_convolution_convex.hpp\"\
    \n\ntemplate <typename T, bool convA, bool convB>\nvc<T> minplus_convolution_convex(vc<T>\
    \ A, vc<T> B, const T INF) {\n  static_assert(convA || convB);\n  assert(INF <\
    \ INF + INF);\n  if (!convB) swap(A, B);\n  int NA = len(A), NB = len(B);\n  int\
    \ N = NA + NB - 1;\n  int L = 0, R = NB;\n  while (L < R && B[L] == INF) ++L;\n\
    \  if (L == R) return vc<T>(N, INF);\n  while (B[R - 1] == INF) --R;\n  B = {B.begin()\
    \ + L, B.begin() + R};\n  int nB = R - L;\n  int n = NA + nB - 1;\n\n  auto select\
    \ = [&](int i, int j, int k) -> int {\n    if (i < k) return j;\n    if (i - j\
    \ >= nB) return k;\n    return (A[j] + B[i - j] > A[k] + B[i - k] ? k : j);\n\
    \  };\n\n  vc<int> J = SMAWK(n, NA, select);\n  vc<T> C(N, INF);\n  FOR(i, n)\
    \ C[L + i] = (A[J[i]] == INF ? INF : A[J[i]] + B[i - J[i]]);\n  return C;\n}\n\
    #line 7 \"main.cpp\"\n\nconst int INF = numeric_limits<int>::max() / 2;\n\nvc<int>\
    \ gen(int L, int N, int R) {\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(-100, 100);\n\
    \  sort(all(A));\n  A = cumsum<int>(A);\n  FOR(L) A.insert(A.begin(), INF);\n\
    \  FOR(R) A.insert(A.end(), INF);\n  return A;\n}\n\nvc<int> naive(vc<int> A,\
    \ vc<int> B) {\n  int N = len(A), M = len(B);\n  vc<int> C(N + M - 1, INF);\n\
    \  FOR(i, N) FOR(j, M) {\n    if (A[i] == INF || B[j] == INF) continue;\n    chmin(C[i\
    \ + j], A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1,\
    \ 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1);\n    FOR(a2, 5) FOR(b2, 10)\
    \ FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2);\n      vc<int> C = minplus_convolution_convex<int,\
    \ 1, 1>(A, B, INF);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/minplus_convex.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 22:01:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/minplus_convex.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/minplus_convex.test.cpp
- /verify/test/mytest/minplus_convex.test.cpp.html
title: test/mytest/minplus_convex.test.cpp
---
