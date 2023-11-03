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
    - https://yukicoder.me/problems/no/1436
  bundledCode: "#line 1 \"test/mytest/find_odd_cycle.test.cpp\"\n#line 1 \"main.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"library/my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC\
    \ optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
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
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U>& A) {\n  T sm =\
    \ 0;\n  for (auto&& a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T>& que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T>& que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T>& que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>&\
    \ que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename\
    \ F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\n\
    double binary_search_real(F check, double ok, double ng, int iter = 100) {\n \
    \ FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n\
    \  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T&\
    \ a, const S& b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T& a, const S& b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string& S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>&\
    \ A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) {\
    \ B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>&\
    \ A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n \
    \      [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T>& A, const vc<int>& I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"library/other/io.hpp\"\n// based on yosupo's\
    \ fastio\n#include <unistd.h>\n\nnamespace fastio {\n#define FASTIO\nstruct has_write_impl\
    \ {\n  template <class T>\n  static auto check(T&& x) -> decltype(x.write(), std::true_type{});\n\
    \n  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\n};\n\nstruct has_read_impl {\n  template <class T>\n  static auto check(T&&\
    \ x) -> decltype(x.read(), std::true_type{});\n\n  template <class T>\n  static\
    \ auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_read\
    \ : public decltype(has_read_impl::check<T>(std::declval<T>())) {};\n\nstruct\
    \ Scanner {\n  FILE* fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0, ed = 0;\n\
    \  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -= st;\n  \
    \  st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed] =\
    \ '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n  \
    \      reread();\n        if (st == ed) return false;\n      }\n      while (st\
    \ != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n    if\
    \ (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i < ed;\
    \ i++) {\n        if (isspace(line[i])) {\n          sep = true;\n          break;\n\
    \        }\n      }\n      if (!sep) reread();\n    }\n    return true;\n  }\n\
    \  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n  bool\
    \ read_single(T& ref) {\n    if (!succ()) return false;\n    while (true) {\n\
    \      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\n\
    \      ref.append(line + st, sz);\n      st += sz;\n      if (!sz || st != ed)\
    \ break;\n      reread();\n    }\n    return true;\n  }\n  template <class T,\
    \ enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T& ref) {\n\
    \    if (!succ()) return false;\n    bool neg = false;\n    if (line[st] == '-')\
    \ {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while (isdigit(line[st]))\
    \ { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref = -ref;\n    return\
    \ true;\n  }\n  template <typename T, typename enable_if<has_read<T>::value>::type*\
    \ = nullptr>\n  inline bool read_single(T& x) {\n    x.read();\n    return true;\n\
    \  }\n  bool read_single(double& ref) {\n    string s;\n    if (!read_single(s))\
    \ return false;\n    ref = std::stod(s);\n    return true;\n  }\n  bool read_single(char&\
    \ ref) {\n    string s;\n    if (!read_single(s) || s.size() != 1) return false;\n\
    \    ref = s[0];\n    return true;\n  }\n  template <class T>\n  bool read_single(vector<T>&\
    \ ref) {\n    for (auto& d: ref) {\n      if (!read_single(d)) return false;\n\
    \    }\n    return true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T,\
    \ U>& p) {\n    return (read_single(p.first) && read_single(p.second));\n  }\n\
    \  template <size_t N = 0, typename T>\n  void read_single_tuple(T& t) {\n   \
    \ if constexpr (N < std::tuple_size<T>::value) {\n      auto& x = std::get<N>(t);\n\
    \      read_single(x);\n      read_single_tuple<N + 1>(t);\n    }\n  }\n  template\
    \ <class... T>\n  bool read_single(tuple<T...>& tpl) {\n    read_single_tuple(tpl);\n\
    \    return true;\n  }\n  void read() {}\n  template <class H, class... T>\n \
    \ void read(H& h, T&... t) {\n    bool f = read_single(h);\n    assert(f);\n \
    \   read(t...);\n  }\n  Scanner(FILE* fp) : fp(fp) {}\n};\n\nstruct Printer {\n\
    \  Printer(FILE* _fp) : fp(_fp) {}\n  ~Printer() { flush(); }\n\n  static constexpr\
    \ size_t SIZE = 1 << 15;\n  FILE* fp;\n  char line[SIZE], small[50];\n  size_t\
    \ pos = 0;\n  void flush() {\n    fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n\
    \  void write(const char val) {\n    if (pos == SIZE) flush();\n    line[pos++]\
    \ = val;\n  }\n  template <class T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\n  void write(T val) {\n    if (pos > (1 << 15) - 50) flush();\n    if (val\
    \ == 0) {\n      write('0');\n      return;\n    }\n    if (val < 0) {\n     \
    \ write('-');\n      val = -val; // todo min\n    }\n    size_t len = 0;\n   \
    \ while (val) {\n      small[len++] = char(0x30 | (val % 10));\n      val /= 10;\n\
    \    }\n    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 -\
    \ i]; }\n    pos += len;\n  }\n  void write(const string s) {\n    for (char c:\
    \ s) write(c);\n  }\n  void write(const char* s) {\n    size_t len = strlen(s);\n\
    \    for (size_t i = 0; i < len; i++) write(s[i]);\n  }\n  void write(const double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  void write(const long double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  template <typename T,\n     \
    \       typename enable_if<has_write<T>::value>::type* = nullptr>\n  inline void\
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
    \ { printer.write('\\n'); }\ntemplate <class Head, class... Tail>\nvoid print(Head&&\
    \ head, Tail&&... tail) {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write('\
    \ ');\n  print(forward<Tail>(tail)...);\n}\n\nvoid read() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid read(Head& head, Tail&... tail) {\n  scanner.read(head);\n\
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
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line 4 \"main.cpp\"\n\n\
    #line 2 \"library/graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n \
    \ int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
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
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
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
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 2 \"library/random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"library/random/random_graph.hpp\"\
    \n\ntemplate <int DIRECTED>\nGraph<int, DIRECTED> random_graph(int n, bool simple)\
    \ {\n  Graph<int, DIRECTED> G(n);\n  vc<pi> cand;\n  FOR(a, n) FOR(b, n) {\n \
    \   if (simple && a == b) continue;\n    if (!DIRECTED && a > b) continue;\n \
    \   cand.eb(a, b);\n  }\n  int m = RNG(0, len(cand) + 1);\n  set<int> ss;\n  FOR(m)\
    \ {\n    while (1) {\n      int i = RNG(0, len(cand));\n      if (simple && ss.count(i))\
    \ continue;\n      ss.insert(i);\n      auto [a, b] = cand[i];\n      G.add(a,\
    \ b);\n      break;\n    }\n  }\n  G.build();\n  return G;\n}\n#line 2 \"library/graph/bipartite_vertex_coloring.hpp\"\
    \n\n#line 2 \"library/ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n};\n#line 5 \"library/graph/bipartite_vertex_coloring.hpp\"\n\n\
    // \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\
    \u306F empty\ntemplate <typename GT>\nvc<int> bipartite_vertex_coloring(GT& G)\
    \ {\n  assert(!GT::is_directed);\n  assert(G.is_prepared());\n\n  int n = G.N;\n\
    \  UnionFind uf(2 * n);\n  for (auto&& e: G.edges) {\n    int u = e.frm, v = e.to;\n\
    \    if (e.cost == 0) uf.merge(u, v), uf.merge(u + n, v + n);\n    if (e.cost\
    \ != 0) uf.merge(u + n, v), uf.merge(u, v + n);\n  }\n\n  vc<int> color(2 * n,\
    \ -1);\n  FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {\n    color[uf[v]] =\
    \ 0;\n    color[uf[v + n]] = 1;\n  }\n  FOR(v, n) color[v] = color[uf[v]];\n \
    \ color.resize(n);\n  FOR(v, n) if (uf[v] == uf[v + n]) return {};\n  return color;\n\
    }\n#line 3 \"library/graph/strongly_connected_component.hpp\"\n\ntemplate <typename\
    \ GT>\npair<int, vc<int>> strongly_connected_component(GT& G) {\n  static_assert(GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N),\
    \ low(N), ord(N, -1), path;\n  int now = 0;\n\n  auto dfs = [&](auto& dfs, int\
    \ v) -> void {\n    low[v] = ord[v] = now++;\n    path.eb(v);\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n        dfs(dfs, to),\
    \ chmin(low[v], low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n \
    \     }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        int u\
    \ = POP(path);\n        ord[u] = N, comp[u] = C;\n        if (u == v) break;\n\
    \      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs,\
    \ v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\n\
    template <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n\
    \  Graph<int, 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n\
    \    int x = comp[e.frm], y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n\
    \  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c,\
    \ to);\n  }\n  DAG.build();\n  return DAG;\n}\n#line 2 \"library/graph/find_odd_cycle.hpp\"\
    \n\n// (vs, es)\n// https://yukicoder.me/problems/no/1436\ntemplate <typename\
    \ GT>\npair<vc<int>, vc<int>> find_odd_cycle(GT& G) {\n  int N = G.N;\n  vc<int>\
    \ comp(N);\n  if constexpr (GT::is_directed) {\n    comp = strongly_connected_component<GT>(G).se;\n\
    \  }\n  vc<int> dist(2 * N, infty<int>);\n  vc<int> par(2 * N, -1); // edge index\n\
    \  deque<int> que;\n  auto add = [&](int v, int d, int p) -> void {\n    if (chmin(dist[v],\
    \ d)) { que.eb(v), par[v] = p; }\n  };\n  FOR(root, N) {\n    if (dist[2 * root\
    \ + 0] < infty<int>) continue;\n    if (dist[2 * root + 1] < infty<int>) continue;\n\
    \    add(2 * root, 0, -1);\n    while (len(que)) {\n      auto v = POP(que);\n\
    \      auto [a, b] = divmod(v, 2);\n      for (auto&& e: G[a]) {\n        if (comp[e.frm]\
    \ != comp[e.to]) continue;\n        int w = 2 * e.to + (b ^ 1);\n        add(w,\
    \ dist[v] + 1, e.id);\n      }\n    }\n    if (dist[2 * root + 1] == infty<int>)\
    \ continue;\n    // found\n    vc<int> edges;\n    vc<int> vs;\n    vs.eb(root);\n\
    \    int v = 2 * root + 1;\n    while (par[v] != -1) {\n      int i = par[v];\n\
    \      edges.eb(i);\n      auto& e = G.edges[i];\n      v = 2 * (e.frm + e.to)\
    \ + 1 - v;\n      vs.eb(v / 2);\n    }\n    reverse(all(edges));\n    reverse(all(vs));\n\
    \    // walk -> cycle\n    vc<int> used(N, -1);\n    int l = -1, r = -1;\n   \
    \ FOR(i, len(vs)) {\n      if (used[vs[i]] == -1) {\n        used[vs[i]] = i;\n\
    \        continue;\n      }\n      l = used[vs[i]];\n      r = i;\n      break;\n\
    \    }\n    assert(l != -1);\n    vs = {vs.begin() + l, vs.begin() + r};\n   \
    \ edges = {edges.begin() + l, edges.begin() + r};\n    vs.eb(vs[0]);\n    return\
    \ {vs, edges};\n  }\n  return {};\n}\n#line 8 \"main.cpp\"\n\nvc<int> find_odd_cycle_naive(Graph<int,\
    \ 1> G) {\n  int N = G.N;\n  vc<int> used_v(N);\n  vc<int> path;\n  vc<int> ANS;\n\
    \  auto dfs = [&](auto& dfs, int v) -> void {\n    if (!ANS.empty()) return;\n\
    \    for (auto& e: G[v]) {\n      if (e.to == path[0] && len(path) % 2 == 1) {\n\
    \        ANS = path;\n        return;\n      }\n      if (!used_v[e.to]) {\n \
    \       used_v[e.to] = 1;\n        path.eb(e.to);\n        dfs(dfs, e.to);\n \
    \       POP(path);\n        used_v[e.to] = 0;\n      }\n    }\n  };\n  FOR(v,\
    \ N) {\n    used_v[v] = 1;\n    path.eb(v);\n    dfs(dfs, v);\n    used_v[v] =\
    \ 0;\n    path.pop_back();\n  }\n  return ANS;\n}\n\nvoid test() {\n  FOR(N, 1,\
    \ 30) {\n    FOR(100) {\n      auto G = random_graph<0>(N, false);\n      auto\
    \ color = bipartite_vertex_coloring(G);\n      if (!color.empty()) continue;\n\
    \      auto [vs, es] = find_odd_cycle(G);\n      int n = len(es);\n      assert(n\
    \ % 2 == 1);\n      assert(len(vs) == 1 + n);\n      assert(vs[0] == vs[n]);\n\
    \      FOR(i, n) {\n        int a = vs[i], b = vs[i + 1];\n        auto& e = G.edges[es[i]];\n\
    \        assert((e.frm == a && e.to == b) || (e.frm == b && e.to == a));\n   \
    \   }\n      UNIQUE(vs);\n      assert(len(vs) == n);\n    }\n  }\n  FOR(N, 1,\
    \ 20) {\n    FOR(100) {\n      auto G = random_graph<1>(N, true);\n      auto\
    \ [vs, es] = find_odd_cycle(G);\n      vc<int> ans = find_odd_cycle_naive(G);\n\
    \      if (vs.empty()) {\n        assert(ans.empty());\n        continue;\n  \
    \    }\n      assert(!ans.empty());\n      int n = len(es);\n\n      assert(n\
    \ % 2 == 1);\n      assert(len(vs) == 1 + n);\n      assert(vs[0] == vs[n]);\n\
    \      FOR(i, n) {\n        int a = vs[i], b = vs[i + 1];\n        auto& e = G.edges[es[i]];\n\
    \        assert(e.frm == a && e.to == b);\n      }\n      UNIQUE(vs);\n      assert(len(vs)\
    \ == n);\n    }\n  }\n}\n\nvoid solve() {\n  INT(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"library/my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
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
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U>& A) {\n  T sm =\
    \ 0;\n  for (auto&& a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T>& que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T>& que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T>& que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>&\
    \ que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename\
    \ F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\n\
    double binary_search_real(F check, double ok, double ng, int iter = 100) {\n \
    \ FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n\
    \  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T&\
    \ a, const S& b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T& a, const S& b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string& S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>&\
    \ A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) {\
    \ B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>&\
    \ A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n \
    \      [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T>& A, const vc<int>& I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"library/other/io.hpp\"\n// based on yosupo's\
    \ fastio\n#include <unistd.h>\n\nnamespace fastio {\n#define FASTIO\nstruct has_write_impl\
    \ {\n  template <class T>\n  static auto check(T&& x) -> decltype(x.write(), std::true_type{});\n\
    \n  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\n};\n\nstruct has_read_impl {\n  template <class T>\n  static auto check(T&&\
    \ x) -> decltype(x.read(), std::true_type{});\n\n  template <class T>\n  static\
    \ auto check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_read\
    \ : public decltype(has_read_impl::check<T>(std::declval<T>())) {};\n\nstruct\
    \ Scanner {\n  FILE* fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0, ed = 0;\n\
    \  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -= st;\n  \
    \  st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed] =\
    \ '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n  \
    \      reread();\n        if (st == ed) return false;\n      }\n      while (st\
    \ != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n    if\
    \ (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i < ed;\
    \ i++) {\n        if (isspace(line[i])) {\n          sep = true;\n          break;\n\
    \        }\n      }\n      if (!sep) reread();\n    }\n    return true;\n  }\n\
    \  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\n  bool\
    \ read_single(T& ref) {\n    if (!succ()) return false;\n    while (true) {\n\
    \      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st + sz])) sz++;\n\
    \      ref.append(line + st, sz);\n      st += sz;\n      if (!sz || st != ed)\
    \ break;\n      reread();\n    }\n    return true;\n  }\n  template <class T,\
    \ enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T& ref) {\n\
    \    if (!succ()) return false;\n    bool neg = false;\n    if (line[st] == '-')\
    \ {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while (isdigit(line[st]))\
    \ { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref = -ref;\n    return\
    \ true;\n  }\n  template <typename T, typename enable_if<has_read<T>::value>::type*\
    \ = nullptr>\n  inline bool read_single(T& x) {\n    x.read();\n    return true;\n\
    \  }\n  bool read_single(double& ref) {\n    string s;\n    if (!read_single(s))\
    \ return false;\n    ref = std::stod(s);\n    return true;\n  }\n  bool read_single(char&\
    \ ref) {\n    string s;\n    if (!read_single(s) || s.size() != 1) return false;\n\
    \    ref = s[0];\n    return true;\n  }\n  template <class T>\n  bool read_single(vector<T>&\
    \ ref) {\n    for (auto& d: ref) {\n      if (!read_single(d)) return false;\n\
    \    }\n    return true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T,\
    \ U>& p) {\n    return (read_single(p.first) && read_single(p.second));\n  }\n\
    \  template <size_t N = 0, typename T>\n  void read_single_tuple(T& t) {\n   \
    \ if constexpr (N < std::tuple_size<T>::value) {\n      auto& x = std::get<N>(t);\n\
    \      read_single(x);\n      read_single_tuple<N + 1>(t);\n    }\n  }\n  template\
    \ <class... T>\n  bool read_single(tuple<T...>& tpl) {\n    read_single_tuple(tpl);\n\
    \    return true;\n  }\n  void read() {}\n  template <class H, class... T>\n \
    \ void read(H& h, T&... t) {\n    bool f = read_single(h);\n    assert(f);\n \
    \   read(t...);\n  }\n  Scanner(FILE* fp) : fp(fp) {}\n};\n\nstruct Printer {\n\
    \  Printer(FILE* _fp) : fp(_fp) {}\n  ~Printer() { flush(); }\n\n  static constexpr\
    \ size_t SIZE = 1 << 15;\n  FILE* fp;\n  char line[SIZE], small[50];\n  size_t\
    \ pos = 0;\n  void flush() {\n    fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n\
    \  void write(const char val) {\n    if (pos == SIZE) flush();\n    line[pos++]\
    \ = val;\n  }\n  template <class T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\n  void write(T val) {\n    if (pos > (1 << 15) - 50) flush();\n    if (val\
    \ == 0) {\n      write('0');\n      return;\n    }\n    if (val < 0) {\n     \
    \ write('-');\n      val = -val; // todo min\n    }\n    size_t len = 0;\n   \
    \ while (val) {\n      small[len++] = char(0x30 | (val % 10));\n      val /= 10;\n\
    \    }\n    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 -\
    \ i]; }\n    pos += len;\n  }\n  void write(const string s) {\n    for (char c:\
    \ s) write(c);\n  }\n  void write(const char* s) {\n    size_t len = strlen(s);\n\
    \    for (size_t i = 0; i < len; i++) write(s[i]);\n  }\n  void write(const double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  void write(const long double\
    \ x) {\n    ostringstream oss;\n    oss << fixed << setprecision(15) << x;\n \
    \   string s = oss.str();\n    write(s);\n  }\n  template <typename T,\n     \
    \       typename enable_if<has_write<T>::value>::type* = nullptr>\n  inline void\
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
    \ { printer.write('\\n'); }\ntemplate <class Head, class... Tail>\nvoid print(Head&&\
    \ head, Tail&&... tail) {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write('\
    \ ');\n  print(forward<Tail>(tail)...);\n}\n\nvoid read() {}\ntemplate <class\
    \ Head, class... Tail>\nvoid read(Head& head, Tail&... tail) {\n  scanner.read(head);\n\
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
    yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line 4 \"main.cpp\"\n\n\
    #line 2 \"library/graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n \
    \ int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
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
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
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
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 2 \"library/random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"library/random/random_graph.hpp\"\
    \n\ntemplate <int DIRECTED>\nGraph<int, DIRECTED> random_graph(int n, bool simple)\
    \ {\n  Graph<int, DIRECTED> G(n);\n  vc<pi> cand;\n  FOR(a, n) FOR(b, n) {\n \
    \   if (simple && a == b) continue;\n    if (!DIRECTED && a > b) continue;\n \
    \   cand.eb(a, b);\n  }\n  int m = RNG(0, len(cand) + 1);\n  set<int> ss;\n  FOR(m)\
    \ {\n    while (1) {\n      int i = RNG(0, len(cand));\n      if (simple && ss.count(i))\
    \ continue;\n      ss.insert(i);\n      auto [a, b] = cand[i];\n      G.add(a,\
    \ b);\n      break;\n    }\n  }\n  G.build();\n  return G;\n}\n#line 2 \"library/graph/bipartite_vertex_coloring.hpp\"\
    \n\n#line 2 \"library/ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n};\n#line 5 \"library/graph/bipartite_vertex_coloring.hpp\"\n\n\
    // \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\
    \u306F empty\ntemplate <typename GT>\nvc<int> bipartite_vertex_coloring(GT& G)\
    \ {\n  assert(!GT::is_directed);\n  assert(G.is_prepared());\n\n  int n = G.N;\n\
    \  UnionFind uf(2 * n);\n  for (auto&& e: G.edges) {\n    int u = e.frm, v = e.to;\n\
    \    if (e.cost == 0) uf.merge(u, v), uf.merge(u + n, v + n);\n    if (e.cost\
    \ != 0) uf.merge(u + n, v), uf.merge(u, v + n);\n  }\n\n  vc<int> color(2 * n,\
    \ -1);\n  FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {\n    color[uf[v]] =\
    \ 0;\n    color[uf[v + n]] = 1;\n  }\n  FOR(v, n) color[v] = color[uf[v]];\n \
    \ color.resize(n);\n  FOR(v, n) if (uf[v] == uf[v + n]) return {};\n  return color;\n\
    }\n#line 3 \"library/graph/strongly_connected_component.hpp\"\n\ntemplate <typename\
    \ GT>\npair<int, vc<int>> strongly_connected_component(GT& G) {\n  static_assert(GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N),\
    \ low(N), ord(N, -1), path;\n  int now = 0;\n\n  auto dfs = [&](auto& dfs, int\
    \ v) -> void {\n    low[v] = ord[v] = now++;\n    path.eb(v);\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n        dfs(dfs, to),\
    \ chmin(low[v], low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n \
    \     }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        int u\
    \ = POP(path);\n        ord[u] = N, comp[u] = C;\n        if (u == v) break;\n\
    \      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs,\
    \ v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\n\
    template <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n\
    \  Graph<int, 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n\
    \    int x = comp[e.frm], y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n\
    \  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c,\
    \ to);\n  }\n  DAG.build();\n  return DAG;\n}\n#line 2 \"library/graph/find_odd_cycle.hpp\"\
    \n\n// (vs, es)\n// https://yukicoder.me/problems/no/1436\ntemplate <typename\
    \ GT>\npair<vc<int>, vc<int>> find_odd_cycle(GT& G) {\n  int N = G.N;\n  vc<int>\
    \ comp(N);\n  if constexpr (GT::is_directed) {\n    comp = strongly_connected_component<GT>(G).se;\n\
    \  }\n  vc<int> dist(2 * N, infty<int>);\n  vc<int> par(2 * N, -1); // edge index\n\
    \  deque<int> que;\n  auto add = [&](int v, int d, int p) -> void {\n    if (chmin(dist[v],\
    \ d)) { que.eb(v), par[v] = p; }\n  };\n  FOR(root, N) {\n    if (dist[2 * root\
    \ + 0] < infty<int>) continue;\n    if (dist[2 * root + 1] < infty<int>) continue;\n\
    \    add(2 * root, 0, -1);\n    while (len(que)) {\n      auto v = POP(que);\n\
    \      auto [a, b] = divmod(v, 2);\n      for (auto&& e: G[a]) {\n        if (comp[e.frm]\
    \ != comp[e.to]) continue;\n        int w = 2 * e.to + (b ^ 1);\n        add(w,\
    \ dist[v] + 1, e.id);\n      }\n    }\n    if (dist[2 * root + 1] == infty<int>)\
    \ continue;\n    // found\n    vc<int> edges;\n    vc<int> vs;\n    vs.eb(root);\n\
    \    int v = 2 * root + 1;\n    while (par[v] != -1) {\n      int i = par[v];\n\
    \      edges.eb(i);\n      auto& e = G.edges[i];\n      v = 2 * (e.frm + e.to)\
    \ + 1 - v;\n      vs.eb(v / 2);\n    }\n    reverse(all(edges));\n    reverse(all(vs));\n\
    \    // walk -> cycle\n    vc<int> used(N, -1);\n    int l = -1, r = -1;\n   \
    \ FOR(i, len(vs)) {\n      if (used[vs[i]] == -1) {\n        used[vs[i]] = i;\n\
    \        continue;\n      }\n      l = used[vs[i]];\n      r = i;\n      break;\n\
    \    }\n    assert(l != -1);\n    vs = {vs.begin() + l, vs.begin() + r};\n   \
    \ edges = {edges.begin() + l, edges.begin() + r};\n    vs.eb(vs[0]);\n    return\
    \ {vs, edges};\n  }\n  return {};\n}\n#line 8 \"main.cpp\"\n\nvc<int> find_odd_cycle_naive(Graph<int,\
    \ 1> G) {\n  int N = G.N;\n  vc<int> used_v(N);\n  vc<int> path;\n  vc<int> ANS;\n\
    \  auto dfs = [&](auto& dfs, int v) -> void {\n    if (!ANS.empty()) return;\n\
    \    for (auto& e: G[v]) {\n      if (e.to == path[0] && len(path) % 2 == 1) {\n\
    \        ANS = path;\n        return;\n      }\n      if (!used_v[e.to]) {\n \
    \       used_v[e.to] = 1;\n        path.eb(e.to);\n        dfs(dfs, e.to);\n \
    \       POP(path);\n        used_v[e.to] = 0;\n      }\n    }\n  };\n  FOR(v,\
    \ N) {\n    used_v[v] = 1;\n    path.eb(v);\n    dfs(dfs, v);\n    used_v[v] =\
    \ 0;\n    path.pop_back();\n  }\n  return ANS;\n}\n\nvoid test() {\n  FOR(N, 1,\
    \ 30) {\n    FOR(100) {\n      auto G = random_graph<0>(N, false);\n      auto\
    \ color = bipartite_vertex_coloring(G);\n      if (!color.empty()) continue;\n\
    \      auto [vs, es] = find_odd_cycle(G);\n      int n = len(es);\n      assert(n\
    \ % 2 == 1);\n      assert(len(vs) == 1 + n);\n      assert(vs[0] == vs[n]);\n\
    \      FOR(i, n) {\n        int a = vs[i], b = vs[i + 1];\n        auto& e = G.edges[es[i]];\n\
    \        assert((e.frm == a && e.to == b) || (e.frm == b && e.to == a));\n   \
    \   }\n      UNIQUE(vs);\n      assert(len(vs) == n);\n    }\n  }\n  FOR(N, 1,\
    \ 20) {\n    FOR(100) {\n      auto G = random_graph<1>(N, true);\n      auto\
    \ [vs, es] = find_odd_cycle(G);\n      vc<int> ans = find_odd_cycle_naive(G);\n\
    \      if (vs.empty()) {\n        assert(ans.empty());\n        continue;\n  \
    \    }\n      assert(!ans.empty());\n      int n = len(es);\n\n      assert(n\
    \ % 2 == 1);\n      assert(len(vs) == 1 + n);\n      assert(vs[0] == vs[n]);\n\
    \      FOR(i, n) {\n        int a = vs[i], b = vs[i + 1];\n        auto& e = G.edges[es[i]];\n\
    \        assert(e.frm == a && e.to == b);\n      }\n      UNIQUE(vs);\n      assert(len(vs)\
    \ == n);\n    }\n  }\n}\n\nvoid solve() {\n  INT(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/find_odd_cycle.test.cpp
  requiredBy: []
  timestamp: '2023-11-03 12:23:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/find_odd_cycle.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/find_odd_cycle.test.cpp
- /verify/test/mytest/find_odd_cycle.test.cpp.html
title: test/mytest/find_odd_cycle.test.cpp
---
