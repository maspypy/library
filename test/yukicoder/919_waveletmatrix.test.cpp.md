---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/waveletmatrix.hpp
    title: ds/waveletmatrix.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/919
    links:
    - https://yukicoder.me/problems/no/919
  bundledCode: "#line 1 \"test/yukicoder/919_waveletmatrix.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/919\"\n#line 1 \"my_template.hpp\"\n#include\
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
    #define fi first\n#define se second\n\n#define stoi stoll\n\nll SUM(vector<int>\
    \ &A) {\n  ll sum = 0;\n  for (auto &&a: A) sum += a;\n  return sum;\n}\n\ntemplate\
    \ <typename T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum\
    \ += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v)\
    \ *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
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
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename U>\nT ceil(T x, U\
    \ y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T,\
    \ typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n\
    }\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q =\
    \ floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    if (check(x)) {\n      ok = x;\n    } else {\n      ng\
    \ = x;\n    }\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\n\
    inline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(I);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n}\n#line 1\
    \ \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\n\r\n\
    namespace detail {\r\ntemplate <typename T, decltype(&T::is_modint) = &T::is_modint>\r\
    \nstd::true_type check_value(int);\r\ntemplate <typename T>\r\nstd::false_type\
    \ check_value(long);\r\n} // namespace detail\r\n\r\ntemplate <typename T>\r\n\
    struct is_modint : decltype(detail::check_value<T>(0)) {};\r\ntemplate <typename\
    \ T>\r\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\r\ntemplate <typename\
    \ T>\r\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\r\n\r\nstruct\
    \ Scanner {\r\n  FILE *fp;\r\n  char line[(1 << 15) + 1];\r\n  size_t st = 0,\
    \ ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\n \
    \   ed -= st;\r\n    st = 0;\r\n    ed += fread(line + ed, 1, (1 << 15) - ed,\
    \ fp);\r\n    line[ed] = '\\0';\r\n  }\r\n  bool succ() {\r\n    while (true)\
    \ {\r\n      if (st == ed) {\r\n        reread();\r\n        if (st == ed) return\
    \ false;\r\n      }\r\n      while (st != ed && isspace(line[st])) st++;\r\n \
    \     if (st != ed) break;\r\n    }\r\n    if (ed - st <= 50) {\r\n      bool\
    \ sep = false;\r\n      for (size_t i = st; i < ed; i++) {\r\n        if (isspace(line[i]))\
    \ {\r\n          sep = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!sep) reread();\r\n    }\r\n    return true;\r\n  }\r\n  template <class\
    \ T, enable_if_t<is_same<T, string>::value, int> = 0>\r\n  bool read_single(T\
    \ &ref) {\r\n    if (!succ()) return false;\r\n    while (true) {\r\n      size_t\
    \ sz = 0;\r\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\r\n \
    \     ref.append(line + st, sz);\r\n      st += sz;\r\n      if (!sz || st !=\
    \ ed) break;\r\n      reread();\r\n    }\r\n    return true;\r\n  }\r\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\r\n  bool read_single(T\
    \ &ref) {\r\n    if (!succ()) return false;\r\n    bool neg = false;\r\n    if\
    \ (line[st] == '-') {\r\n      neg = true;\r\n      st++;\r\n    }\r\n    ref\
    \ = T(0);\r\n    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf);\
    \ }\r\n    if (neg) ref = -ref;\r\n    return true;\r\n  }\r\n  template <class\
    \ T, is_modint_t<T> * = nullptr>\r\n  bool read_single(T &ref) {\r\n    long long\
    \ val = 0;\r\n    bool f = read_single(val);\r\n    ref = T(val);\r\n    return\
    \ f;\r\n  }\r\n  bool read_single(double &ref) {\r\n    string s;\r\n    if (!read_single(s))\
    \ return false;\r\n    ref = std::stod(s);\r\n    return true;\r\n  }\r\n  bool\
    \ read_single(char &ref) {\r\n    string s;\r\n    if (!read_single(s) || s.size()\
    \ != 1) return false;\r\n    ref = s[0];\r\n    return true;\r\n  }\r\n  template\
    \ <class T>\r\n  bool read_single(vector<T> &ref) {\r\n    for (auto &d: ref)\
    \ {\r\n      if (!read_single(d)) return false;\r\n    }\r\n    return true;\r\
    \n  }\r\n  template <class T, class U>\r\n  bool read_single(pair<T, U> &p) {\r\
    \n    return (read_single(p.first) && read_single(p.second));\r\n  }\r\n  template\
    \ <class A, class B, class C>\r\n  bool read_single(tuple<A, B, C> &p) {\r\n \
    \   return (read_single(get<0>(p)) && read_single(get<1>(p))\r\n            &&\
    \ read_single(get<2>(p)));\r\n  }\r\n  template <class A, class B, class C, class\
    \ D>\r\n  bool read_single(tuple<A, B, C, D> &p) {\r\n    return (read_single(get<0>(p))\
    \ && read_single(get<1>(p))\r\n            && read_single(get<2>(p)) && read_single(get<3>(p)));\r\
    \n  }\r\n  void read() {}\r\n  template <class H, class... T>\r\n  void read(H\
    \ &h, T &... t) {\r\n    bool f = read_single(h);\r\n    assert(f);\r\n    read(t...);\r\
    \n  }\r\n  Scanner(FILE *fp) : fp(fp) {}\r\n};\r\n\r\nstruct Printer {\r\n  Printer(FILE\
    \ *_fp) : fp(_fp) {}\r\n  ~Printer() { flush(); }\r\n\r\n  static constexpr size_t\
    \ SIZE = 1 << 15;\r\n  FILE *fp;\r\n  char line[SIZE], small[50];\r\n  size_t\
    \ pos = 0;\r\n  void flush() {\r\n    fwrite(line, 1, pos, fp);\r\n    pos = 0;\r\
    \n  }\r\n  void write(const char &val) {\r\n    if (pos == SIZE) flush();\r\n\
    \    line[pos++] = val;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n  void write(T val) {\r\n    if (pos > (1 << 15) - 50) flush();\r\
    \n    if (val == 0) {\r\n      write('0');\r\n      return;\r\n    }\r\n    if\
    \ (val < 0) {\r\n      write('-');\r\n      val = -val; // todo min\r\n    }\r\
    \n    size_t len = 0;\r\n    while (val) {\r\n      small[len++] = char(0x30 |\
    \ (val % 10));\r\n      val /= 10;\r\n    }\r\n    for (size_t i = 0; i < len;\
    \ i++) { line[pos + i] = small[len - 1 - i]; }\r\n    pos += len;\r\n  }\r\n \
    \ void write(const string &s) {\r\n    for (char c: s) write(c);\r\n  }\r\n  void\
    \ write(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t i =\
    \ 0; i < len; i++) write(s[i]);\r\n  }\r\n  void write(const double &x) {\r\n\
    \    ostringstream oss;\r\n    oss << setprecision(15) << x;\r\n    string s =\
    \ oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double &x) {\r\
    \n    ostringstream oss;\r\n    oss << setprecision(15) << x;\r\n    string s\
    \ = oss.str();\r\n    write(s);\r\n  }\r\n  template <class T, is_modint_t<T>\
    \ * = nullptr>\r\n  void write(T &ref) {\r\n    write(ref.val);\r\n  }\r\n  template\
    \ <class T>\r\n  void write(const vector<T> &val) {\r\n    auto n = val.size();\r\
    \n    for (size_t i = 0; i < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\
    \n    }\r\n  }\r\n  template <class T, class U>\r\n  void write(const pair<T,\
    \ U> &val) {\r\n    write(val.first);\r\n    write(' ');\r\n    write(val.second);\r\
    \n  }\r\n  template <class A, class B, class C>\r\n  void write(const tuple<A,\
    \ B, C> &val) {\r\n    auto &[a, b, c] = val;\r\n    write(a), write(' '), write(b),\
    \ write(' '), write(c);\r\n  }\r\n  template <class A, class B, class C, class\
    \ D>\r\n  void write(const tuple<A, B, C, D> &val) {\r\n    auto &[a, b, c, d]\
    \ = val;\r\n    write(a), write(' '), write(b), write(' '), write(c), write('\
    \ '), write(d);\r\n  }\r\n  template <class A, class B, class C, class D, class\
    \ E>\r\n  void write(const tuple<A, B, C, D, E> &val) {\r\n    auto &[a, b, c,\
    \ d, e] = val;\r\n    write(a), write(' '), write(b), write(' '), write(c), write('\
    \ '), write(d), write(' '), write(e);\r\n  }\r\n  template <class A, class B,\
    \ class C, class D, class E, class F>\r\n  void write(const tuple<A, B, C, D,\
    \ E, F> &val) {\r\n    auto &[a, b, c, d, e, f] = val;\r\n    write(a), write('\
    \ '), write(b), write(' '), write(c), write(' '), write(d), write(' '), write(e),\
    \ write(' '), write(f);\r\n  }\r\n  template <class T, size_t S>\r\n  void write(const\
    \ array<T, S> &val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i\
    \ < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\n    }\r\n\
    \  }\r\n  void write(i128 val) {\r\n    string s;\r\n    bool negative = 0;\r\n\
    \    if(val < 0){\r\n      negative = 1;\r\n      val = -val;\r\n    }\r\n   \
    \ while (val) {\r\n      s += '0' + int(val % 10);\r\n      val /= 10;\r\n   \
    \ }\r\n    if(negative) s += \"-\";\r\n    reverse(all(s));\r\n    if (len(s)\
    \ == 0) s = \"0\";\r\n    write(s);\r\n  }\r\n};\r\n\r\nScanner scanner = Scanner(stdin);\r\
    \nPrinter printer = Printer(stdout);\r\n\r\nvoid flush() { printer.flush(); }\r\
    \nvoid print() { printer.write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\
    \nvoid print(Head &&head, Tail &&... tail) {\r\n  printer.write(head);\r\n  if\
    \ (sizeof...(Tail)) printer.write(' ');\r\n  print(forward<Tail>(tail)...);\r\n\
    }\r\n\r\nvoid read() {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head\
    \ &head, Tail &... tail) {\r\n  scanner.read(head);\r\n  read(tail...);\r\n}\r\
    \n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ CHAR(...)      \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n\
    #define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\
    \n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\
    \nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1)\
    \ { yes(!t); }\r\n#line 1 \"ds/waveletmatrix.hpp\"\n#include <immintrin.h>\r\n\
    \r\nstruct bit_vector {\r\n  using u32 = uint32_t;\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n\r\n  static constexpr u32 w = 64;\r\n  vector<u64>\
    \ block;\r\n  vector<u32> count;\r\n  u32 n, zeros;\r\n\r\n  inline u32 get(u32\
    \ i) const { return u32(block[i / w] >> (i % w)) & 1u; }\r\n  inline void set(u32\
    \ i) { block[i / w] |= 1LL << (i % w); }\r\n\r\n  bit_vector() {}\r\n  bit_vector(int\
    \ _n) { init(_n); }\r\n  __attribute__((optimize(\"O3\", \"unroll-loops\"))) void\
    \ init(int _n) {\r\n    n = zeros = _n;\r\n    block.resize(n / w + 1, 0);\r\n\
    \    count.resize(block.size(), 0);\r\n  }\r\n\r\n  __attribute__((target(\"popcnt\"\
    ))) void build() {\r\n    for (u32 i = 1; i < block.size(); ++i)\r\n      count[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\r\n    zeros = rank0(n);\r\n\
    \  }\r\n\r\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\r\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\r\n    return count[i / w] +\
    \ _mm_popcnt_u64(_bzhi_u64(block[i / w], i % w));\r\n  }\r\n};\r\n\r\n/*\r\n\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF1Avector<T> \u3092\u6E21\u3059\r\n\u9759\
    \u7684\u306A\u5217\u306B\u5BFE\u3057\u3066\u6B21\u304C O(log N) \u6642\u9593\u3067\
    \u884C\u3048\u308B\r\n\u30FBfreq(l, r, lower, upper)\uFF1A[lower, upper) \u5185\
    \u306E\u8981\u7D20\u306E\u6570\u3048\u4E0A\u3052\r\n\u30FBkth(l, r, lower, upper)\uFF1A\
    [lower, upper) \u5185\u3092\u30BD\u30FC\u30C8\u3057\u305F\u3068\u304D\u306E k\
    \ \u756A\u76EE\r\n*/\r\ntemplate <typename T>\r\nstruct WaveletMatrix {\r\n  using\
    \ u32 = uint32_t;\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\n\r\n\
    \  int n, lg;\r\n  vc<T> key;\r\n  vc<int> A;\r\n  vector<bit_vector> bv;\r\n\r\
    \n  __attribute__((optimize(\"O3\"))) WaveletMatrix(const vc<T>& dat)\r\n    \
    \  : n(len(dat)) {\r\n    key = dat;\r\n    UNIQUE(key);\r\n    A.resize(n);\r\
    \n    FOR(i, n) A[i] = LB(key, dat[i]);\r\n    lg = __lg(max(MAX(A), 1)) + 1;\r\
    \n    bv.assign(lg, n);\r\n    vc<int> cur = A, nxt(n);\r\n    for (int h = lg\
    \ - 1; h >= 0; --h) {\r\n      for (int i = 0; i < n; ++i)\r\n        if ((cur[i]\
    \ >> h) & 1) bv[h].set(i);\r\n      bv[h].build();\r\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\r\n      for (int i = 0; i < n;\
    \ ++i) *it[bv[h].get(i)]++ = cur[i];\r\n      swap(cur, nxt);\r\n    }\r\n  }\r\
    \n\r\n  inline pair<u32, u32> succ0(int l, int r, int h) const {\r\n    return\
    \ make_pair(bv[h].rank0(l), bv[h].rank0(r));\r\n  }\r\n\r\n  inline pair<u32,\
    \ u32> succ1(int l, int r, int h) const {\r\n    u32 l0 = bv[h].rank0(l);\r\n\
    \    u32 r0 = bv[h].rank0(r);\r\n    u32 zeros = bv[h].zeros;\r\n    return make_pair(l\
    \ + zeros - l0, r + zeros - r0);\r\n  }\r\n\r\n  T kth(u32 l, u32 r, u32 k) const\
    \ {\r\n    int res = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n      u32\
    \ l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\n      if (k < r0 - l0)\r\n    \
    \    l = l0, r = r0;\r\n      else {\r\n        k -= r0 - l0;\r\n        res |=\
    \ 1 << h;\r\n        l += bv[h].zeros - l0;\r\n        r += bv[h].zeros - r0;\r\
    \n      }\r\n    }\r\n    return key[res];\r\n  }\r\n\r\n  int freq(int l, int\
    \ r, T lower, T upper) {\r\n    return freq_upper(l, r, upper) - freq_upper(l,\
    \ r, lower);\r\n  }\r\n\r\nprivate:\r\n  int freq_upper(int l, int r, T upper_t)\
    \ {\r\n    int upper = LB(key, upper_t);\r\n    if (upper >= (1 << lg)) return\
    \ r - l;\r\n    int ret = 0;\r\n    for (int h = lg - 1; h >= 0; --h) {\r\n  \
    \    bool f = (upper >> h) & 1;\r\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\r\
    \n      if (f) {\r\n        ret += r0 - l0;\r\n        l += bv[h].zeros - l0;\r\
    \n        r += bv[h].zeros - r0;\r\n      } else {\r\n        l = l0;\r\n    \
    \    r = r0;\r\n      }\r\n    }\r\n    return ret;\r\n  }\r\n};\n#line 5 \"test/yukicoder/919_waveletmatrix.test.cpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(ll, A, N);\n  WaveletMatrix<ll> WM(A);\n \
    \ const ll INF = 1LL << 60;\n  ll ANS = -INF;\n\n  auto get = [&](ll L, ll R)\
    \ -> ll {\n    assert(L < R);\n    ll n = R - L;\n    return WM.kth(L, R, (n -\
    \ 1) / 2);\n  };\n\n  FOR3(K, 1, N + 1) {\n    // \u3068\u308B\u6700\u5927\u56DE\
    \u6570\n    ll LIM = N / K;\n    vi left(LIM);\n    vi right(LIM);\n    FOR(i,\
    \ LIM) left[i] = get(K * i, K * i + K);\n    FOR(i, LIM) right[i] = get(N - K\
    \ * i - K, N - K * i);\n    left = cumsum(left);\n    right = cumsum(right);\n\
    \    // x \u56DE\u4EE5\u4E0B\u3068\u308B\u3068\u304D\u306E\uFF5E\n    FOR(i, LIM)\
    \ chmax(left[i + 1], left[i]);\n    FOR(i, LIM) chmax(right[i + 1], right[i]);\n\
    \    FOR(i, LIM + 1) chmax(ANS, K * (left[i] + right[LIM - i]));\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"ds/waveletmatrix.hpp\"\n\nvoid solve()\
    \ {\n  LL(N);\n  VEC(ll, A, N);\n  WaveletMatrix<ll> WM(A);\n  const ll INF =\
    \ 1LL << 60;\n  ll ANS = -INF;\n\n  auto get = [&](ll L, ll R) -> ll {\n    assert(L\
    \ < R);\n    ll n = R - L;\n    return WM.kth(L, R, (n - 1) / 2);\n  };\n\n  FOR3(K,\
    \ 1, N + 1) {\n    // \u3068\u308B\u6700\u5927\u56DE\u6570\n    ll LIM = N / K;\n\
    \    vi left(LIM);\n    vi right(LIM);\n    FOR(i, LIM) left[i] = get(K * i, K\
    \ * i + K);\n    FOR(i, LIM) right[i] = get(N - K * i - K, N - K * i);\n    left\
    \ = cumsum(left);\n    right = cumsum(right);\n    // x \u56DE\u4EE5\u4E0B\u3068\
    \u308B\u3068\u304D\u306E\uFF5E\n    FOR(i, LIM) chmax(left[i + 1], left[i]);\n\
    \    FOR(i, LIM) chmax(right[i + 1], right[i]);\n    FOR(i, LIM + 1) chmax(ANS,\
    \ K * (left[i] + right[LIM - i]));\n  }\n  print(ANS);\n}\n\nsigned main() {\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/waveletmatrix.hpp
  isVerificationFile: true
  path: test/yukicoder/919_waveletmatrix.test.cpp
  requiredBy: []
  timestamp: '2022-08-13 02:22:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/919_waveletmatrix.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/919_waveletmatrix.test.cpp
- /verify/test/yukicoder/919_waveletmatrix.test.cpp.html
title: test/yukicoder/919_waveletmatrix.test.cpp
---
