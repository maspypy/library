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
    PROBLEM: https://atcoder.jp/contests/agc023/tasks/agc023_f
    links:
    - https://atcoder.jp/contests/agc023/tasks/agc023_f
    - https://trap.jp/post/1224/
  bundledCode: "#line 1 \"test_atcoder/agc023f.test.cpp\"\n#line 1 \"main.cpp\"\n\
    #define PROBLEM \"https://atcoder.jp/contests/agc023/tasks/agc023_f\"\n#line 1\
    \ \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int>\
    \ = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int>\
    \ * 2;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr\
    \ u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * infty<ll>;\ntemplate <>\nconstexpr double infty<double> = infty<ll>;\ntemplate\
    \ <>\nconstexpr long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll,\
    \ ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
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
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    tie(ok, ng) =\
    \ (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return ok;\n}\ntemplate <typename\
    \ F>\ndouble binary_search_real(F check, double ok, double ng, int iter = 100)\
    \ {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    tie(ok, ng) = (check(x)\
    \ ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n#endif\n\
    #line 1 \"library/other/io.hpp\"\n// based on yosupo's fastio\n#include <unistd.h>\n\
    \nnamespace fastio {\n#define FASTIO\n// \u30AF\u30E9\u30B9\u304C read(), print()\
    \ \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\
    \u30BF\u95A2\u6570\nstruct has_write_impl {\n  template <class T>\n  static auto\
    \ check(T &&x) -> decltype(x.write(), std::true_type{});\n\n  template <class\
    \ T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\n\
    class has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
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
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line 2 \"library/graph/tree.hpp\"\
    \n\n#line 2 \"library/graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph *G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type *begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type\
    \ *end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph *G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto &&e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto &&e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto &&e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto &&e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto &&e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto &&eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto &&e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto &&e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 4 \"library/graph/tree.hpp\"\n\n// HLD euler tour \u3092\u3068\
    \u3063\u3066\u3044\u308D\u3044\u308D\u3002\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\
    \u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\u308B\u3002\n\
    template <typename GT>\nstruct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using\
    \ WT = typename GT::cost_type;\n  int N;\n  vector<int> LID, RID, head, V, parent,\
    \ VtoE;\n  vc<int> depth;\n  vc<WT> depth_weighted;\n\n  Tree(GT &G, int r = 0,\
    \ bool hld = 1) : G(G) { build(r, hld); }\n\n  void build(int r = 0, bool hld\
    \ = 1) {\n    if (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\
    \u3068\u304D\n    N = G.N;\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\n    assert(G.is_prepared());\n    int t1\
    \ = 0;\n    dfs_sz(r, -1, hld);\n    dfs_hld(r, t1);\n  }\n\n  void dfs_sz(int\
    \ v, int p, bool hld) {\n    auto &sz = RID;\n    parent[v] = p;\n    depth[v]\
    \ = (p == -1 ? 0 : depth[p] + 1);\n    sz[v] = 1;\n    int l = G.indptr[v], r\
    \ = G.indptr[v + 1];\n    auto &csr = G.csr_edges;\n    // \u4F7F\u3046\u8FBA\u304C\
    \u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\n    for (int i = r - 2; i >=\
    \ l; --i) {\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i +\
    \ 1]);\n    }\n    int hld_sz = 0;\n    for (int i = l; i < r; ++i) {\n      auto\
    \ e = csr[i];\n      if (depth[e.to] != -1) continue;\n      depth_weighted[e.to]\
    \ = depth_weighted[v] + e.cost;\n      VtoE[e.to] = e.id;\n      dfs_sz(e.to,\
    \ v, hld);\n      sz[v] += sz[e.to];\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\n    }\n  }\n\n  void dfs_hld(int v, int\
    \ &times) {\n    LID[v] = times++;\n    RID[v] += LID[v];\n    V[LID[v]] = v;\n\
    \    bool heavy = true;\n    for (auto &&e: G[v]) {\n      if (depth[e.to] <=\
    \ depth[v]) continue;\n      head[e.to] = (heavy ? head[v] : e.to);\n      heavy\
    \ = false;\n      dfs_hld(e.to, times);\n    }\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) {\n    vc<int> P = {v};\n    while (1) {\n      int a = P.back();\n     \
    \ for (auto &&e: G[a]) {\n        if (e.to != parent[a] && head[e.to] == v) {\n\
    \          P.eb(e.to);\n          break;\n        }\n      }\n      if (P.back()\
    \ == a) break;\n    }\n    return P;\n  }\n\n  int e_to_v(int eid) {\n    auto\
    \ e = G.edges[eid];\n    return (parent[e.frm] == e.to ? e.frm : e.to);\n  }\n\
    \  int v_to_e(int v) { return VtoE[v]; }\n\n  int ELID(int v) { return 2 * LID[v]\
    \ - depth[v]; }\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\n\n \
    \ /* k: 0-indexed */\n  int LA(int v, int k) {\n    assert(k <= depth[v]);\n \
    \   while (1) {\n      int u = head[v];\n      if (LID[v] - k >= LID[u]) return\
    \ V[LID[v] - k];\n      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n\
    \  }\n  int la(int u, int v) { return LA(u, v); }\n\n  int LCA(int u, int v) {\n\
    \    for (;; v = parent[head[v]]) {\n      if (LID[u] > LID[v]) swap(u, v);\n\
    \      if (head[u] == head[v]) return u;\n    }\n  }\n  // root \u3092\u6839\u3068\
    \u3057\u305F\u5834\u5408\u306E lca\n  int LCA_root(int u, int v, int root) {\n\
    \    return LCA(u, v) ^ LCA(u, root) ^ LCA(v, root);\n  }\n  int lca(int u, int\
    \ v) { return LCA(u, v); }\n  int lca_root(int u, int v, int root) { return LCA_root(u,\
    \ v, root); }\n\n  int subtree_size(int v, int root = -1) {\n    if (root == -1)\
    \ return RID[v] - LID[v];\n    if (v == root) return N;\n    int x = jump(v, root,\
    \ 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return N - RID[x]\
    \ + LID[x];\n  }\n\n  int dist(int a, int b) {\n    int c = LCA(a, b);\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\n  }\n\n  WT dist_weighted(int a, int b)\
    \ {\n    int c = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b]\
    \ - WT(2) * depth_weighted[c];\n  }\n\n  // a is in b\n  bool in_subtree(int a,\
    \ int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\n\n  int jump(int a,\
    \ int b, ll k) {\n    if (k == 1) {\n      if (a == b) return -1;\n      return\
    \ (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n    }\n  \
    \  int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc = depth[b]\
    \ - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac) return\
    \ LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) {\n    vc<int> res;\n    for (auto &&e: G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int\
    \ u, int v, bool edge) {\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\
    \u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n    while (1) {\n\
    \      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v]) {\n        down.eb(LID[head[v]],\
    \ LID[v]);\n        v = parent[head[v]];\n      } else {\n        up.eb(LID[u],\
    \ LID[head[u]]);\n        u = parent[head[u]];\n      }\n    }\n    if (LID[u]\
    \ < LID[v]) down.eb(LID[u] + edge, LID[v]);\n    elif (LID[v] + edge <= LID[u])\
    \ up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n    up.insert(up.end(),\
    \ all(down));\n    return up;\n  }\n\n  vc<int> restore_path(int u, int v) {\n\
    \    vc<int> P;\n    for (auto &&[a, b]: get_path_decomposition(u, v, 0)) {\n\
    \      if (a <= b) {\n        FOR(i, a, b + 1) P.eb(V[i]);\n      } else {\n \
    \       FOR_R(i, b, a + 1) P.eb(V[i]);\n      }\n    }\n    return P;\n  }\n};\n\
    #line 2 \"library/ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n,\
    \ n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n};\n#line 3 \"library/graph/optimal_product_on_tree.hpp\"\n\n//\
    \ \u6728\u306E\u5404\u9802\u70B9\u306B\u5168\u9806\u5E8F\u30E2\u30CE\u30A4\u30C9\
    \u306E\u5143\u304C\u7F6E\u304B\u308C\u3066\u3044\u308B\uFF08x<=y -> axb<=ayb\uFF09\
    \n// topological \u9806\u5E8F\u3067\u304B\u3051\u308B\u3068\u304D\uFF0C\u7D50\u679C\
    \u3092\u6700\u5927\u5316\u3059\u308B\n// https://atcoder.jp/contests/agc023/tasks/agc023_f\n\
    template <typename TREE, typename Monoid, bool MINIMIZE, typename F>\npair<vc<int>,\
    \ typename Monoid::X> optimal_product_on_tree(\n    TREE &tree, vc<typename Monoid::X>\
    \ A, F compare) {\n  const int N = tree.N;\n  const int root = tree.V[0];\n  using\
    \ X = typename Monoid::value_type;\n\n  vc<int> head(N), tail(N), nxt(N);\n  FOR(v,\
    \ N) head[v] = v, tail[v] = v, nxt[v] = -1;\n\n  UnionFind uf(N);\n  // (x, v,\
    \ size v)\n  using T = tuple<X, int, int>;\n  auto my_compare = [&](T &t1, T &t2)\
    \ -> bool {\n    X &x1 = get<0>(t1);\n    X &x2 = get<0>(t2);\n    if constexpr\
    \ (MINIMIZE) return compare(x2, x1);\n    if constexpr (!MINIMIZE) return compare(x1,\
    \ x2);\n  };\n\n  priority_queue<T, vc<T>, decltype(my_compare)> que(my_compare);\n\
    \  FOR(v, N) if (v != root) que.emplace(A[v], v, 1);\n\n  while (len(que)) {\n\
    \    auto [_, v, sv] = que.top();\n    que.pop();\n    if (uf.size(v) != sv) continue;\n\
    \    int a = head[uf[v]], b = tail[uf[v]];\n    int p = uf[tree.parent[a]];\n\
    \    int c = head[p], d = tail[p];\n    X x = Monoid::op(A[p], A[v]);\n    uf.merge(p,\
    \ v);\n    v = uf[v];\n    A[v] = x, head[v] = c, tail[v] = b, nxt[d] = a;\n \
    \   if (uf[v] == uf[root]) continue;\n    que.emplace(A[v], v, uf.size(v));\n\
    \  }\n  vc<int> I = {root};\n  while (nxt[I.back()] != -1) I.eb(nxt[I.back()]);\n\
    \  return {I, A[uf[root]]};\n}\n#line 5 \"main.cpp\"\n\nstruct Data {\n  ll ans,\
    \ x0, x1;\n};\n\nstruct Mono {\n  using value_type = Data;\n  using X = value_type;\n\
    \  static X op(X x, X y) {\n    X z;\n    z.ans = x.ans + y.ans + x.x1 * y.x0;\n\
    \    z.x0 = x.x0 + y.x0, z.x1 = x.x1 + y.x1;\n    return z;\n  }\n  static constexpr\
    \ X unit() { return Data{0, 0, 0}; }\n  static constexpr bool commute = 0;\n};\n\
    \nvoid solve() {\n  LL(N);\n  Graph<bool, 1> G(N);\n  FOR(v, 1, N) {\n    INT(p);\n\
    \    G.add(--p, v);\n  }\n  G.build();\n  Tree<decltype(G)> tree(G);\n  vc<Data>\
    \ A(N);\n  FOR(v, N) {\n    INT(x);\n    if (x == 0) { A[v] = Data{0, 1, 0}; }\n\
    \    if (x == 1) { A[v] = Data{0, 0, 1}; }\n  }\n  auto comp = [&](Data x, Data\
    \ y) -> bool { return x.x0 * y.x1 > x.x1 * y.x0; };\n  auto [ord, x]\n      =\
    \ optimal_product_on_tree<decltype(tree), Mono, true>(tree, A, comp);\n  print(x.ans);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/agc023/tasks/agc023_f\"\
    \n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int>\
    \ = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int>\
    \ * 2;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr\
    \ u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * infty<ll>;\ntemplate <>\nconstexpr double infty<double> = infty<ll>;\ntemplate\
    \ <>\nconstexpr long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll,\
    \ ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
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
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    tie(ok, ng) =\
    \ (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return ok;\n}\ntemplate <typename\
    \ F>\ndouble binary_search_real(F check, double ok, double ng, int iter = 100)\
    \ {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    tie(ok, ng) = (check(x)\
    \ ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n#endif\n\
    #line 1 \"library/other/io.hpp\"\n// based on yosupo's fastio\n#include <unistd.h>\n\
    \nnamespace fastio {\n#define FASTIO\n// \u30AF\u30E9\u30B9\u304C read(), print()\
    \ \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\
    \u30BF\u95A2\u6570\nstruct has_write_impl {\n  template <class T>\n  static auto\
    \ check(T &&x) -> decltype(x.write(), std::true_type{});\n\n  template <class\
    \ T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\n\
    class has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
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
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line 2 \"library/graph/tree.hpp\"\
    \n\n#line 2 \"library/graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph *G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type *begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type\
    \ *end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph *G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto &&e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto &&e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto &&e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto &&e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto &&e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto &&eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto &&e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto &&e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 4 \"library/graph/tree.hpp\"\n\n// HLD euler tour \u3092\u3068\
    \u3063\u3066\u3044\u308D\u3044\u308D\u3002\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\
    \u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\u308B\u3002\n\
    template <typename GT>\nstruct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using\
    \ WT = typename GT::cost_type;\n  int N;\n  vector<int> LID, RID, head, V, parent,\
    \ VtoE;\n  vc<int> depth;\n  vc<WT> depth_weighted;\n\n  Tree(GT &G, int r = 0,\
    \ bool hld = 1) : G(G) { build(r, hld); }\n\n  void build(int r = 0, bool hld\
    \ = 1) {\n    if (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\
    \u3068\u304D\n    N = G.N;\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\n    assert(G.is_prepared());\n    int t1\
    \ = 0;\n    dfs_sz(r, -1, hld);\n    dfs_hld(r, t1);\n  }\n\n  void dfs_sz(int\
    \ v, int p, bool hld) {\n    auto &sz = RID;\n    parent[v] = p;\n    depth[v]\
    \ = (p == -1 ? 0 : depth[p] + 1);\n    sz[v] = 1;\n    int l = G.indptr[v], r\
    \ = G.indptr[v + 1];\n    auto &csr = G.csr_edges;\n    // \u4F7F\u3046\u8FBA\u304C\
    \u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\n    for (int i = r - 2; i >=\
    \ l; --i) {\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i +\
    \ 1]);\n    }\n    int hld_sz = 0;\n    for (int i = l; i < r; ++i) {\n      auto\
    \ e = csr[i];\n      if (depth[e.to] != -1) continue;\n      depth_weighted[e.to]\
    \ = depth_weighted[v] + e.cost;\n      VtoE[e.to] = e.id;\n      dfs_sz(e.to,\
    \ v, hld);\n      sz[v] += sz[e.to];\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\n    }\n  }\n\n  void dfs_hld(int v, int\
    \ &times) {\n    LID[v] = times++;\n    RID[v] += LID[v];\n    V[LID[v]] = v;\n\
    \    bool heavy = true;\n    for (auto &&e: G[v]) {\n      if (depth[e.to] <=\
    \ depth[v]) continue;\n      head[e.to] = (heavy ? head[v] : e.to);\n      heavy\
    \ = false;\n      dfs_hld(e.to, times);\n    }\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) {\n    vc<int> P = {v};\n    while (1) {\n      int a = P.back();\n     \
    \ for (auto &&e: G[a]) {\n        if (e.to != parent[a] && head[e.to] == v) {\n\
    \          P.eb(e.to);\n          break;\n        }\n      }\n      if (P.back()\
    \ == a) break;\n    }\n    return P;\n  }\n\n  int e_to_v(int eid) {\n    auto\
    \ e = G.edges[eid];\n    return (parent[e.frm] == e.to ? e.frm : e.to);\n  }\n\
    \  int v_to_e(int v) { return VtoE[v]; }\n\n  int ELID(int v) { return 2 * LID[v]\
    \ - depth[v]; }\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\n\n \
    \ /* k: 0-indexed */\n  int LA(int v, int k) {\n    assert(k <= depth[v]);\n \
    \   while (1) {\n      int u = head[v];\n      if (LID[v] - k >= LID[u]) return\
    \ V[LID[v] - k];\n      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n\
    \  }\n  int la(int u, int v) { return LA(u, v); }\n\n  int LCA(int u, int v) {\n\
    \    for (;; v = parent[head[v]]) {\n      if (LID[u] > LID[v]) swap(u, v);\n\
    \      if (head[u] == head[v]) return u;\n    }\n  }\n  // root \u3092\u6839\u3068\
    \u3057\u305F\u5834\u5408\u306E lca\n  int LCA_root(int u, int v, int root) {\n\
    \    return LCA(u, v) ^ LCA(u, root) ^ LCA(v, root);\n  }\n  int lca(int u, int\
    \ v) { return LCA(u, v); }\n  int lca_root(int u, int v, int root) { return LCA_root(u,\
    \ v, root); }\n\n  int subtree_size(int v, int root = -1) {\n    if (root == -1)\
    \ return RID[v] - LID[v];\n    if (v == root) return N;\n    int x = jump(v, root,\
    \ 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return N - RID[x]\
    \ + LID[x];\n  }\n\n  int dist(int a, int b) {\n    int c = LCA(a, b);\n    return\
    \ depth[a] + depth[b] - 2 * depth[c];\n  }\n\n  WT dist_weighted(int a, int b)\
    \ {\n    int c = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b]\
    \ - WT(2) * depth_weighted[c];\n  }\n\n  // a is in b\n  bool in_subtree(int a,\
    \ int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\n\n  int jump(int a,\
    \ int b, ll k) {\n    if (k == 1) {\n      if (a == b) return -1;\n      return\
    \ (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n    }\n  \
    \  int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc = depth[b]\
    \ - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac) return\
    \ LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) {\n    vc<int> res;\n    for (auto &&e: G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int\
    \ u, int v, bool edge) {\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\
    \u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n    while (1) {\n\
    \      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v]) {\n        down.eb(LID[head[v]],\
    \ LID[v]);\n        v = parent[head[v]];\n      } else {\n        up.eb(LID[u],\
    \ LID[head[u]]);\n        u = parent[head[u]];\n      }\n    }\n    if (LID[u]\
    \ < LID[v]) down.eb(LID[u] + edge, LID[v]);\n    elif (LID[v] + edge <= LID[u])\
    \ up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n    up.insert(up.end(),\
    \ all(down));\n    return up;\n  }\n\n  vc<int> restore_path(int u, int v) {\n\
    \    vc<int> P;\n    for (auto &&[a, b]: get_path_decomposition(u, v, 0)) {\n\
    \      if (a <= b) {\n        FOR(i, a, b + 1) P.eb(V[i]);\n      } else {\n \
    \       FOR_R(i, b, a + 1) P.eb(V[i]);\n      }\n    }\n    return P;\n  }\n};\n\
    #line 2 \"library/ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n,\
    \ n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n};\n#line 3 \"library/graph/optimal_product_on_tree.hpp\"\n\n//\
    \ \u6728\u306E\u5404\u9802\u70B9\u306B\u5168\u9806\u5E8F\u30E2\u30CE\u30A4\u30C9\
    \u306E\u5143\u304C\u7F6E\u304B\u308C\u3066\u3044\u308B\uFF08x<=y -> axb<=ayb\uFF09\
    \n// topological \u9806\u5E8F\u3067\u304B\u3051\u308B\u3068\u304D\uFF0C\u7D50\u679C\
    \u3092\u6700\u5927\u5316\u3059\u308B\n// https://atcoder.jp/contests/agc023/tasks/agc023_f\n\
    template <typename TREE, typename Monoid, bool MINIMIZE, typename F>\npair<vc<int>,\
    \ typename Monoid::X> optimal_product_on_tree(\n    TREE &tree, vc<typename Monoid::X>\
    \ A, F compare) {\n  const int N = tree.N;\n  const int root = tree.V[0];\n  using\
    \ X = typename Monoid::value_type;\n\n  vc<int> head(N), tail(N), nxt(N);\n  FOR(v,\
    \ N) head[v] = v, tail[v] = v, nxt[v] = -1;\n\n  UnionFind uf(N);\n  // (x, v,\
    \ size v)\n  using T = tuple<X, int, int>;\n  auto my_compare = [&](T &t1, T &t2)\
    \ -> bool {\n    X &x1 = get<0>(t1);\n    X &x2 = get<0>(t2);\n    if constexpr\
    \ (MINIMIZE) return compare(x2, x1);\n    if constexpr (!MINIMIZE) return compare(x1,\
    \ x2);\n  };\n\n  priority_queue<T, vc<T>, decltype(my_compare)> que(my_compare);\n\
    \  FOR(v, N) if (v != root) que.emplace(A[v], v, 1);\n\n  while (len(que)) {\n\
    \    auto [_, v, sv] = que.top();\n    que.pop();\n    if (uf.size(v) != sv) continue;\n\
    \    int a = head[uf[v]], b = tail[uf[v]];\n    int p = uf[tree.parent[a]];\n\
    \    int c = head[p], d = tail[p];\n    X x = Monoid::op(A[p], A[v]);\n    uf.merge(p,\
    \ v);\n    v = uf[v];\n    A[v] = x, head[v] = c, tail[v] = b, nxt[d] = a;\n \
    \   if (uf[v] == uf[root]) continue;\n    que.emplace(A[v], v, uf.size(v));\n\
    \  }\n  vc<int> I = {root};\n  while (nxt[I.back()] != -1) I.eb(nxt[I.back()]);\n\
    \  return {I, A[uf[root]]};\n}\n#line 5 \"main.cpp\"\n\nstruct Data {\n  ll ans,\
    \ x0, x1;\n};\n\nstruct Mono {\n  using value_type = Data;\n  using X = value_type;\n\
    \  static X op(X x, X y) {\n    X z;\n    z.ans = x.ans + y.ans + x.x1 * y.x0;\n\
    \    z.x0 = x.x0 + y.x0, z.x1 = x.x1 + y.x1;\n    return z;\n  }\n  static constexpr\
    \ X unit() { return Data{0, 0, 0}; }\n  static constexpr bool commute = 0;\n};\n\
    \nvoid solve() {\n  LL(N);\n  Graph<bool, 1> G(N);\n  FOR(v, 1, N) {\n    INT(p);\n\
    \    G.add(--p, v);\n  }\n  G.build();\n  Tree<decltype(G)> tree(G);\n  vc<Data>\
    \ A(N);\n  FOR(v, N) {\n    INT(x);\n    if (x == 0) { A[v] = Data{0, 1, 0}; }\n\
    \    if (x == 1) { A[v] = Data{0, 0, 1}; }\n  }\n  auto comp = [&](Data x, Data\
    \ y) -> bool { return x.x0 * y.x1 > x.x1 * y.x0; };\n  auto [ord, x]\n      =\
    \ optimal_product_on_tree<decltype(tree), Mono, true>(tree, A, comp);\n  print(x.ans);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/agc023f.test.cpp
  requiredBy: []
  timestamp: '2023-06-23 23:20:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/agc023f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/agc023f.test.cpp
- /verify/test_atcoder/agc023f.test.cpp.html
title: test_atcoder/agc023f.test.cpp
---
