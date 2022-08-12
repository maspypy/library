---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: pds/rollbackarray.hpp
    title: pds/rollbackarray.hpp
  - icon: ':x:'
    path: pds/rollbackunionfind.hpp
    title: pds/rollbackunionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \ { yes(!t); }\r\n#line 1 \"pds/rollbackarray.hpp\"\ntemplate <typename T>\r\n\
    struct RollbackArray {\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n\
    \  RollbackArray(vc<T> x) : dat(x) {}\r\n\r\n  int time() { return len(history);\
    \ }\r\n  void rollback(int t) {\r\n    FOR_R(i, t, time()) {\r\n      auto& [idx,\
    \ v] = history[i];\r\n      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\
    \n  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\
    \n    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n};\r\n#line 2\
    \ \"pds/rollbackunionfind.hpp\"\n\r\nstruct RollbackUnionFind {\r\n  RollbackArray<int>\
    \ dat; // parent or size\r\n\r\n  RollbackUnionFind(int n) : dat(vc<int>(n, -1))\
    \ {}\r\n\r\n  int operator[](int v) {\r\n    while (dat.get(v) >= 0) v = dat.get(v);\r\
    \n    return v;\r\n  }\r\n\r\n  int size(int v) { return -dat.get((*this)[v]);\
    \ }\r\n  int time() { return dat.time(); }\r\n  void rollback(int t) { dat.rollback(t);\
    \ }\r\n\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a], b = (*this)[b];\r\
    \n    if (a == b) return false;\r\n    if (dat.get(a) > dat.get(b)) swap(a, b);\r\
    \n    dat.set(a, dat.get(a) + dat.get(b));\r\n    dat.set(b, a);\r\n    return\
    \ true;\r\n  }\r\n};\r\n#line 6 \"test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, a, N);\n\n  using QT = tuple<int, int,\
    \ int>;\n  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n  \
    \    LL(u, v);\n      if (u > v) swap(u, v);\n      query[q] = {t, u, v};\n  \
    \  }\n    if (t == 1) {\n      LL(u, v);\n      if (u > v) swap(u, v);\n     \
    \ query[q] = {t, u, v};\n    }\n    if (t == 2) {\n      LL(v, x);\n      query[q]\
    \ = {t, v, x};\n    }\n    if (t == 3) {\n      LL(v);\n      query[q] = {t, v,\
    \ -1};\n    }\n  }\n\n  map<pair<int, int>, vc<int>> MP;\n  FOR(q, Q) {\n    auto&\
    \ [t, a, b] = query[q];\n    if (t == 0 || t == 1) {\n      pair<int, int> p =\
    \ {a, b};\n      MP[p].eb(q);\n    }\n  }\n\n  int size = 1;\n  while (size <\
    \ Q) size *= 2;\n\n  /*\n  0 a b \uFF1A merge a, b\n  1 v x : add v x\n  2 q v:\
    \ answer query q\n  */\n\n  vvc<QT> query2(2 * size);\n  for (auto&& [p, Ts]:\
    \ MP) {\n    if (Ts.size() % 2 == 1) Ts.eb(Q);\n    auto [a, b] = p;\n    FOR(i,\
    \ 0, len(Ts), 2) {\n      ll l = Ts[i];\n      ll r = Ts[i + 1];\n      l += size;\n\
    \      r += size;\n      while (l < r) {\n        if (l % 2 == 1) { query2[l++].eb(0,\
    \ a, b); }\n        if (r % 2 == 1) { query2[--r].eb(0, a, b); }\n        l /=\
    \ 2, r /= 2;\n      }\n    }\n  }\n  FOR(q, Q) {\n    auto [t, a, b] = query[q];\n\
    \    if (t == 0 || t == 1) continue;\n    if (t == 2) {\n      int v = a, x =\
    \ b;\n      ll l = q, r = Q;\n      l += size;\n      r += size;\n      while\
    \ (l < r) {\n        if (l % 2 == 1) { query2[l++].eb(1, v, x); }\n        if\
    \ (r % 2 == 1) { query2[--r].eb(1, v, x); }\n        l /= 2, r /= 2;\n      }\n\
    \    }\n    if (t == 3) { query2[q + size].eb(2, q, a); }\n  }\n\n  RollbackArray<ll>\
    \ A(a);\n  RollbackUnionFind uf(N);\n  vi ANS(Q);\n\n  auto dfs = [&](auto& dfs,\
    \ int idx) -> void {\n    int time1 = A.time();\n    int time2 = uf.time();\n\
    \    //\n    for (auto&& [t, a, b]: query2[idx]) {\n      if (t == 0) {\n    \
    \    a = uf[a], b = uf[b];\n        if (a == b) continue;\n        uf.merge(a,\
    \ b);\n        A.set(uf[a], A.get(a) + A.get(b));\n      }\n      if (t == 1)\
    \ {\n        a = uf[a];\n        A.set(a, A.get(a) + b);\n      }\n      if (t\
    \ == 2) {\n        ll ans = A.get(uf[b]);\n        ANS[a] = ans;\n      }\n  \
    \  }\n    if (idx < size) {\n      dfs(dfs, 2 * idx + 0);\n      dfs(dfs, 2 *\
    \ idx + 1);\n    }\n    A.rollback(time1);\n    uf.rollback(time2);\n  };\n  dfs(dfs,\
    \ 1);\n  FOR(q, Q) {\n    auto [t, a, b] = query[q];\n    if (t == 3) print(ANS[q]);\n\
    \  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"pds/rollbackunionfind.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, a, N);\n\n  using QT = tuple<int, int,\
    \ int>;\n  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n  \
    \    LL(u, v);\n      if (u > v) swap(u, v);\n      query[q] = {t, u, v};\n  \
    \  }\n    if (t == 1) {\n      LL(u, v);\n      if (u > v) swap(u, v);\n     \
    \ query[q] = {t, u, v};\n    }\n    if (t == 2) {\n      LL(v, x);\n      query[q]\
    \ = {t, v, x};\n    }\n    if (t == 3) {\n      LL(v);\n      query[q] = {t, v,\
    \ -1};\n    }\n  }\n\n  map<pair<int, int>, vc<int>> MP;\n  FOR(q, Q) {\n    auto&\
    \ [t, a, b] = query[q];\n    if (t == 0 || t == 1) {\n      pair<int, int> p =\
    \ {a, b};\n      MP[p].eb(q);\n    }\n  }\n\n  int size = 1;\n  while (size <\
    \ Q) size *= 2;\n\n  /*\n  0 a b \uFF1A merge a, b\n  1 v x : add v x\n  2 q v:\
    \ answer query q\n  */\n\n  vvc<QT> query2(2 * size);\n  for (auto&& [p, Ts]:\
    \ MP) {\n    if (Ts.size() % 2 == 1) Ts.eb(Q);\n    auto [a, b] = p;\n    FOR(i,\
    \ 0, len(Ts), 2) {\n      ll l = Ts[i];\n      ll r = Ts[i + 1];\n      l += size;\n\
    \      r += size;\n      while (l < r) {\n        if (l % 2 == 1) { query2[l++].eb(0,\
    \ a, b); }\n        if (r % 2 == 1) { query2[--r].eb(0, a, b); }\n        l /=\
    \ 2, r /= 2;\n      }\n    }\n  }\n  FOR(q, Q) {\n    auto [t, a, b] = query[q];\n\
    \    if (t == 0 || t == 1) continue;\n    if (t == 2) {\n      int v = a, x =\
    \ b;\n      ll l = q, r = Q;\n      l += size;\n      r += size;\n      while\
    \ (l < r) {\n        if (l % 2 == 1) { query2[l++].eb(1, v, x); }\n        if\
    \ (r % 2 == 1) { query2[--r].eb(1, v, x); }\n        l /= 2, r /= 2;\n      }\n\
    \    }\n    if (t == 3) { query2[q + size].eb(2, q, a); }\n  }\n\n  RollbackArray<ll>\
    \ A(a);\n  RollbackUnionFind uf(N);\n  vi ANS(Q);\n\n  auto dfs = [&](auto& dfs,\
    \ int idx) -> void {\n    int time1 = A.time();\n    int time2 = uf.time();\n\
    \    //\n    for (auto&& [t, a, b]: query2[idx]) {\n      if (t == 0) {\n    \
    \    a = uf[a], b = uf[b];\n        if (a == b) continue;\n        uf.merge(a,\
    \ b);\n        A.set(uf[a], A.get(a) + A.get(b));\n      }\n      if (t == 1)\
    \ {\n        a = uf[a];\n        A.set(a, A.get(a) + b);\n      }\n      if (t\
    \ == 2) {\n        ll ans = A.get(uf[b]);\n        ANS[a] = ans;\n      }\n  \
    \  }\n    if (idx < size) {\n      dfs(dfs, 2 * idx + 0);\n      dfs(dfs, 2 *\
    \ idx + 1);\n    }\n    A.rollback(time1);\n    uf.rollback(time2);\n  };\n  dfs(dfs,\
    \ 1);\n  FOR(q, Q) {\n    auto [t, a, b] = query[q];\n    if (t == 3) print(ANS[q]);\n\
    \  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - pds/rollbackunionfind.hpp
  - pds/rollbackarray.hpp
  isVerificationFile: true
  path: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
  requiredBy: []
  timestamp: '2022-08-13 02:22:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
- /verify/test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp.html
title: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
---
