---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut.hpp
    title: graph/ds/link_cut.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut_path.hpp
    title: graph/ds/link_cut_path.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#line 1 \"my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 =\
    \ unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
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
    \    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n    string\
    \ s = oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double &x)\
    \ {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n\
    \    string s = oss.str();\r\n    write(s);\r\n  }\r\n  template <class T, is_modint_t<T>\
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
    \ { yes(!t); }\r\n#line 5 \"test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"graph/ds/link_cut.hpp\"\
    \n\ntemplate <typename Node, int NODES>\nstruct LinkCutTree_base {\n  int n;\n\
    \  Node *nodes;\n\n  LinkCutTree_base(int n = 0) : n(n) {\n    nodes = new Node[NODES];\n\
    \    FOR(i, n) nodes[i] = Node(i);\n  }\n\n  Node *operator[](int v) { return\
    \ &nodes[v]; }\n\n  // \u30D1\u30B9\u3092\u8868\u3059 splay tree \u306E\u6839\u306B\
    \u306A\u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n  bool is_root(Node *c)\
    \ { return state(c) == 0; }\n  bool is_root(int c) { return state(&nodes[c]) ==\
    \ 0; }\n\n  Node *get_root(Node *c) {\n    expose(c);\n    while (c->l) {\n  \
    \    c->push();\n      c = c->l;\n    }\n    splay(c);\n    return c;\n  }\n\n\
    \  int get_root(int c) { return get_root(&nodes[c])->idx; }\n\n  // c \u306E\u89AA\
    \u3092 p \u306B\u3059\u308B\u3002\n  virtual void link(Node *c, Node *p) {\n \
    \   evert(c);\n    expose(p);\n    c->p = p;\n    p->r = c;\n    p->update();\n\
    \  }\n\n  // c \u306E\u89AA\u3092 p \u306B\u3059\u308B\n  virtual void link(int\
    \ c, int p) { return link(&nodes[c], &nodes[p]); }\n\n  void cut(Node *a, Node\
    \ *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l)\
    \ == a);\n    b->l->p = nullptr;\n    b->l = nullptr;\n    b->update();\n  }\n\
    \n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]); }\n\n  void evert(Node\
    \ *c) {\n    expose(c);\n    c->reverse();\n    c->push();\n  }\n\n  void evert(int\
    \ c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node *v) {\n    assert(get_root(u)\
    \ == get_root(v));\n    expose(u);\n    return expose(v);\n  }\n\n  int lca(int\
    \ u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n  // c \u3068\u6839\u307E\
    \u3067\u304C\u7E4B\u304C\u308C\u3066\u3044\u308B\u72B6\u614B\u306B\u5909\u66F4\
    \u3057\u3066\u3001\u6839\u3092 return \u3059\u308B\n  virtual Node *expose(Node\
    \ *c) {\n    Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\
    \u3063\u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      now->r =\
    \ rp; // \u5B50\u65B9\u5411\u306E\u5909\u66F4\n      now->update();\n      rp\
    \ = now;\n      now = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n \
    \ int expose(int c) {\n    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n\
    \    return x->idx;\n  }\n\n  Node *get_parent(Node *x) {\n    expose(x);\n  \
    \  if (!x->l) return nullptr;\n    x = x->l;\n    while (x->r) x = x->r;\n   \
    \ return x;\n  }\n\n  int get_parent(int x) {\n    Node *p = get_parent((*this)[x]);\n\
    \    return (p ? p->idx : -1);\n  }\n\n  void debug() {\n    FOR(i, n) { nodes[i].debug();\
    \ }\n  }\n\n  virtual void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\
    \u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n \
    \   if (p->l == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    }\
    \ else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp\
    \ && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p =\
    \ pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n)\
    \ {\n    if (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r\
    \ == n) return -1;\n    return 0;\n  }\n\n  void splay(Node *c) {\n    c->push();\n\
    \    while (!is_root(c)) {\n      Node *p = c->p;\n      Node *pp = (p ? p->p\
    \ : nullptr);\n      if (state(p) == 0) {\n        p->push(), c->push();\n   \
    \     rotate(c);\n        if (p) p->update();\n      }\n      elif (state(c) ==\
    \ state(p)) {\n        pp->push(), p->push(), c->push();\n        rotate(p);\n\
    \        rotate(c);\n        if (pp) pp->update();\n        if (p) p->update();\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n        if (p) p->update();\n        if (pp) pp->update();\n\
    \      }\n    }\n    c->update();\n  }\n};\n\nstruct LCT_Node_base {\n  LCT_Node_base\
    \ *l, *r, *p;\n  int idx;\n  bool rev;\n  LCT_Node_base(int i = 0) : l(nullptr),\
    \ r(nullptr), p(nullptr), idx(i) {}\n\n  void update() {}\n\n  void push() {\n\
    \    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n    \
    \  rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n\
    \  }\n};\n\ntemplate <int NODES>\nusing LinkCutTree = LinkCutTree_base<LCT_Node_base,\
    \ NODES>;\n#line 2 \"graph/ds/link_cut_path.hpp\"\n\ntemplate <typename Node,\
    \ int NODES>\nstruct LinkCutTree_Path_base : public LinkCutTree_base<Node, NODES>\
    \ {\n  using X = typename Node::X;\n\n  LinkCutTree_Path_base(int n) : LinkCutTree_base<Node,\
    \ NODES>(n) {}\n\n  LinkCutTree_Path_base(vc<X> dat) : LinkCutTree_base<Node,\
    \ NODES>(len(dat)) {\n    FOR(v, len(dat)) {\n      Node *c = (*this)[v];\n  \
    \    set(c, dat[v]);\n    }\n  }\n\n  template <typename F>\n  LinkCutTree_Path_base(int\
    \ n, F f) : LinkCutTree_base<Node, NODES>(n) {\n    FOR(v, n) {\n      X x = f(v);\n\
    \      Node *c = (*this)[v];\n      set(c, x);\n    }\n  }\n\n  void set(Node\
    \ *c, X x) {\n    this->evert(c);\n    c->x = x;\n    c->update();\n  }\n\n  void\
    \ set(int c, X x) { set((*this)[c], x); }\n\n  void multiply(Node *c, X x) { set(c,\
    \ Node::Mono::op(c->x, x)); }\n\n  void multiply(int c, X x) { multiply((*this)[c],\
    \ x); }\n\n  X prod_path(Node *a, Node *b) {\n    this->evert(a);\n    this->expose(b);\n\
    \    return b->prod;\n  }\n\n  X prod_path(int a, int b) { return prod_path((*this)[a],\
    \ (*this)[b]); }\n};\n\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n\
    \  using Mono = Monoid;\n  using X = typename Monoid::value_type;\n  LCT_Node_Monoid\
    \ *l, *r, *p;\n  int idx;\n  X x, prod, rev_prod;\n  bool rev;\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        x(Monoid::unit()),\n        prod(Monoid::unit()),\n    \
    \    rev_prod(Monoid::unit()) {}\n\n  void update() {\n    prod = rev_prod = x;\n\
    \    if (l) {\n      prod = Monoid::op(l->prod, prod);\n      rev_prod = Monoid::op(rev_prod,\
    \ l->rev_prod);\n    }\n    if (r) {\n      prod = Monoid::op(prod, r->prod);\n\
    \      rev_prod = Monoid::op(r->rev_prod, rev_prod);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n    swap(prod, rev_prod);\n  }\n\n  void debug() {\n    int li = (l ? l->idx\
    \ : -1);\n    int ri = (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n \
    \   print(\"idx\", idx, \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod,\n\
    \          \"rev_prod\", rev_prod);\n  }\n};\n\ntemplate <typename Monoid>\nstruct\
    \ LCT_Node_CommutativeMonoid {\n  using Mono = Monoid;\n  using X = typename Mono::value_type;\n\
    \  LCT_Node_CommutativeMonoid *l, *r, *p;\n  int idx;\n  X x, prod;\n  bool rev;\n\
    \  LCT_Node_CommutativeMonoid(int i = 0)\n      : l(nullptr),\n        r(nullptr),\n\
    \        p(nullptr),\n        idx(i),\n        x(Mono::unit()),\n        prod(Mono::unit())\
    \ {}\n\n  void update() {\n    prod = x;\n    if (l) { prod = Mono::op(l->prod,\
    \ prod); }\n    if (r) { prod = Mono::op(prod, r->prod); }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n  }\n\n  void debug() {\n    int li = (l ? l->idx : -1);\n    int ri =\
    \ (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n    print(\"idx\", idx,\
    \ \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod);\n  }\n};\n\ntemplate\
    \ <typename Monoid, int NODES>\nusing LinkCutTree_Path = LinkCutTree_Path_base<LCT_Node_Monoid<Monoid>,\
    \ NODES>;\n\ntemplate <typename Monoid, int NODES>\nusing LinkCutTree_Path_Commutative\n\
    \    = LinkCutTree_Path_base<LCT_Node_CommutativeMonoid<Monoid>, NODES>;\n#line\
    \ 8 \"test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n\n  LinkCutTree_Path<Monoid_Add<ll>,\
    \ 200000> X(A);\n\n  FOR(N - 1) {\n    LL(u, v);\n    X.link(u, v);\n  }\n\n \
    \ FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n      X.cut(a,\
    \ b);\n      X.link(c, d);\n    }\n    if (t == 1) {\n      LL(p, x);\n      X.multiply(p,\
    \ x);\n    }\n    if (t == 2) {\n      LL(a, b);\n      print(X.prod_path(a, b));\n\
    \    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/monoid/add.hpp\"\
    \n#include \"graph/ds/link_cut_path.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll,\
    \ A, N);\n\n  LinkCutTree_Path<Monoid_Add<ll>, 200000> X(A);\n\n  FOR(N - 1) {\n\
    \    LL(u, v);\n    X.link(u, v);\n  }\n\n  FOR(Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      LL(a, b, c, d);\n      X.cut(a, b);\n      X.link(c, d);\n    }\n\
    \    if (t == 1) {\n      LL(p, x);\n      X.multiply(p, x);\n    }\n    if (t\
    \ == 2) {\n      LL(a, b);\n      print(X.prod_path(a, b));\n    }\n  }\n}\n\n\
    signed main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout <<\
    \ setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n  return\
    \ 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/add.hpp
  - graph/ds/link_cut_path.hpp
  - graph/ds/link_cut.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2022-11-27 19:19:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
---
