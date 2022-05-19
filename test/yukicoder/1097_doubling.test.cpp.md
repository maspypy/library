---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://trap.jp/post/1224/
  bundledCode: "#line 1 \"test/yukicoder/1097_doubling.test.cpp\"\n#line 1 \"/home/maspy/compro/library/my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
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
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool\
    \ chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b,\
    \ 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
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
    \ len(A);\n  assert(len(I) == n);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n\
    \  return B;\n}\n#line 1 \"/home/maspy/compro/library/other/io.hpp\"\n// based\
    \ on yosupo's fastio\n#include <unistd.h>\n\nnamespace detail {\ntemplate <typename\
    \ T, decltype(&T::is_modint) = &T::is_modint>\nstd::true_type check_value(int);\n\
    template <typename T>\nstd::false_type check_value(long);\n} // namespace detail\n\
    \ntemplate <typename T>\nstruct is_modint : decltype(detail::check_value<T>(0))\
    \ {};\ntemplate <typename T>\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\n\
    template <typename T>\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\n\
    \nstruct Scanner {\n  FILE *fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0,\
    \ ed = 0;\n  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -=\
    \ st;\n    st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed]\
    \ = '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n\
    \        reread();\n        if (st == ed) return false;\n      }\n      while\
    \ (st != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n \
    \   if (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i\
    \ < ed; i++) {\n        if (isspace(line[i])) {\n          sep = true;\n     \
    \     break;\n        }\n      }\n      if (!sep) reread();\n    }\n    return\
    \ true;\n  }\n  template <class T, enable_if_t<is_same<T, string>::value, int>\
    \ = 0>\n  bool read_single(T &ref) {\n    if (!succ()) return false;\n    while\
    \ (true) {\n      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st\
    \ + sz])) sz++;\n      ref.append(line + st, sz);\n      st += sz;\n      if (!sz\
    \ || st != ed) break;\n      reread();\n    }\n    return true;\n  }\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T\
    \ &ref) {\n    if (!succ()) return false;\n    bool neg = false;\n    if (line[st]\
    \ == '-') {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while\
    \ (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref\
    \ = -ref;\n    return true;\n  }\n  template <class T, is_modint_t<T> * = nullptr>\n\
    \  bool read_single(T &ref) {\n    long long val = 0;\n    bool f = read_single(val);\n\
    \    ref = T(val);\n    return f;\n  }\n  bool read_single(double &ref) {\n  \
    \  string s;\n    if (!read_single(s)) return false;\n    ref = std::stod(s);\n\
    \    return true;\n  }\n  bool read_single(char &ref) {\n    string s;\n    if\
    \ (!read_single(s) || s.size() != 1) return false;\n    ref = s[0];\n    return\
    \ true;\n  }\n  template <class T>\n  bool read_single(vector<T> &ref) {\n   \
    \ for (auto &d: ref) {\n      if (!read_single(d)) return false;\n    }\n    return\
    \ true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T, U> &p)\
    \ {\n    return (read_single(p.first) && read_single(p.second));\n  }\n  template\
    \ <class A, class B, class C>\n  bool read_single(tuple<A, B, C> &p) {\n    return\
    \ (read_single(get<0>(p)) && read_single(get<1>(p))\n            && read_single(get<2>(p)));\n\
    \  }\n  template <class A, class B, class C, class D>\n  bool read_single(tuple<A,\
    \ B, C, D> &p) {\n    return (read_single(get<0>(p)) && read_single(get<1>(p))\n\
    \            && read_single(get<2>(p)) && read_single(get<3>(p)));\n  }\n  void\
    \ read() {}\n  template <class H, class... T>\n  void read(H &h, T &... t) {\n\
    \    bool f = read_single(h);\n    assert(f);\n    read(t...);\n  }\n  Scanner(FILE\
    \ *fp) : fp(fp) {}\n};\n\nstruct Printer {\n  Printer(FILE *_fp) : fp(_fp) {}\n\
    \  ~Printer() { flush(); }\n\n  static constexpr size_t SIZE = 1 << 15;\n  FILE\
    \ *fp;\n  char line[SIZE], small[50];\n  size_t pos = 0;\n  void flush() {\n \
    \   fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n  void write(const char &val)\
    \ {\n    if (pos == SIZE) flush();\n    line[pos++] = val;\n  }\n  template <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\n  void write(T val) {\n   \
    \ if (pos > (1 << 15) - 50) flush();\n    if (val == 0) {\n      write('0');\n\
    \      return;\n    }\n    if (val < 0) {\n      write('-');\n      val = -val;\
    \ // todo min\n    }\n    size_t len = 0;\n    while (val) {\n      small[len++]\
    \ = char(0x30 | (val % 10));\n      val /= 10;\n    }\n    for (size_t i = 0;\
    \ i < len; i++) { line[pos + i] = small[len - 1 - i]; }\n    pos += len;\n  }\n\
    \  void write(const string &s) {\n    for (char c: s) write(c);\n  }\n  void write(const\
    \ char *s) {\n    size_t len = strlen(s);\n    for (size_t i = 0; i < len; i++)\
    \ write(s[i]);\n  }\n  void write(const double &x) {\n    ostringstream oss;\n\
    \    oss << setprecision(15) << x;\n    string s = oss.str();\n    write(s);\n\
    \  }\n  void write(const long double &x) {\n    ostringstream oss;\n    oss <<\
    \ setprecision(15) << x;\n    string s = oss.str();\n    write(s);\n  }\n  template\
    \ <class T, is_modint_t<T> * = nullptr>\n  void write(T &ref) {\n    write(ref.val);\n\
    \  }\n  template <class T>\n  void write(const vector<T> &val) {\n    auto n =\
    \ val.size();\n    for (size_t i = 0; i < n; i++) {\n      if (i) write(' ');\n\
    \      write(val[i]);\n    }\n  }\n  template <class T, class U>\n  void write(const\
    \ pair<T, U> &val) {\n    write(val.first);\n    write(' ');\n    write(val.second);\n\
    \  }\n  template <class A, class B, class C>\n  void write(const tuple<A, B, C>\
    \ &val) {\n    auto &[a, b, c] = val;\n    write(a), write(' '), write(b), write('\
    \ '), write(c);\n  }\n  template <class A, class B, class C, class D>\n  void\
    \ write(const tuple<A, B, C, D> &val) {\n    auto &[a, b, c, d] = val;\n    write(a),\
    \ write(' '), write(b), write(' '), write(c), write(' '), write(d);\n  }\n  template\
    \ <class A, class B, class C, class D, class E>\n  void write(const tuple<A, B,\
    \ C, D, E> &val) {\n    auto &[a, b, c, d, e] = val;\n    write(a), write(' '),\
    \ write(b), write(' '), write(c), write(' '), write(d),\n        write(' '), write(e);\n\
    \  }\n  template <class A, class B, class C, class D, class E, class F>\n  void\
    \ write(const tuple<A, B, C, D, E, F> &val) {\n    auto &[a, b, c, d, e, f] =\
    \ val;\n    write(a), write(' '), write(b), write(' '), write(c), write(' '),\
    \ write(d),\n        write(' '), write(e), write(' '), write(f);\n  }\n  template\
    \ <class T, size_t S>\n  void write(const array<T, S> &val) {\n    auto n = val.size();\n\
    \    for (size_t i = 0; i < n; i++) {\n      if (i) write(' ');\n      write(val[i]);\n\
    \    }\n  }\n  void write(i128 val) {\n    string s;\n    bool negative = 0;\n\
    \    if (val < 0) {\n      negative = 1;\n      val = -val;\n    }\n    while\
    \ (val) {\n      s += '0' + int(val % 10);\n      val /= 10;\n    }\n    if (negative)\
    \ s += \"-\";\n    reverse(all(s));\n    if (len(s) == 0) s = \"0\";\n    write(s);\n\
    \  }\n};\n\nScanner scanner = Scanner(stdin);\nPrinter printer = Printer(stdout);\n\
    \nvoid flush() { printer.flush(); }\nvoid print() { printer.write('\\n'); }\n\
    template <class Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail)\
    \ {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write(' ');\n  print(forward<Tail>(tail)...);\n\
    }\n\nvoid read() {}\ntemplate <class Head, class... Tail>\nvoid read(Head &head,\
    \ Tail &... tail) {\n  scanner.read(head);\n  read(tail...);\n}\n\n#define INT(...)\
    \   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define LL(...)   \\\n  ll\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n#define CHAR(...)   \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define DBL(...)      \\\n  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define\
    \ VEC(type, name, size) \\\n  vector<type> name(size);    \\\n  read(name)\n#define\
    \ VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\"\
    \ : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t\
    \ ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t =\
    \ 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line\
    \ 1 \"/home/maspy/compro/library/ds/doubling.hpp\"\n// \u72B6\u614B a \u304B\u3089\
    \ 1 \u56DE\u64CD\u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\
    \u3057\u3001\u30E2\u30CE\u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\
    \n// \u72B6\u614B\u6570 N\n// set(i, to, x)\n// \u884C\u304D\u5148\u304C\u306A\
    \u3044\u5834\u5408\uFF1A-1 \uFF08set \u4E0D\u8981\uFF09\ntemplate <typename Monoid,\
    \ int LOG>\nstruct Doubling {\n  using X = typename Monoid::value_type;\n  int\
    \ N;\n  bool is_prepared;\n  vvc<int> TO;\n  vvc<X> DP;\n\n  Doubling(int N) :\
    \ N(N), is_prepared(0) {\n    TO.assign(LOG, vc<int>(N, -1));\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::unit()));\n  }\n\n  void set(int i, int to, X x) {\n    assert(!is_prepared);\n\
    \    assert(-1 <= to && to < N);\n    TO[0][i] = to;\n    DP[0][i] = x;\n  }\n\
    \n  void build() {\n    if (is_prepared) return;\n    is_prepared = 1;\n    FOR(k,\
    \ LOG - 1) {\n      FOR(v, N) {\n        int w = TO[k][v];\n        if (w == -1)\
    \ {\n          TO[k + 1][v] = -1;\n          DP[k + 1][v] = DP[k][v];\n      \
    \    continue;\n        }\n        TO[k + 1][v] = TO[k][w];\n        DP[k + 1][v]\
    \ = Monoid::op(DP[k][v], DP[k][w]);\n      }\n    }\n  }\n\n  pair<int, X> calc(int\
    \ i, ll step) {\n    assert(is_prepared);\n    assert(step < (1LL << LOG));\n\
    \    X x = Monoid::unit();\n    FOR(k, LOG) {\n      if (i == -1) break;\n   \
    \   if (step & 1LL << k) {\n        x = Monoid::op(x, DP[k][i]);\n        i =\
    \ TO[k][i];\n      }\n    }\n    return {i, x};\n  }\n\n  template <typename F>\n\
    \  ll max_step(F check, int i) {\n    assert(is_prepared);\n    // step\u6570\n\
    \    X x = Monoid::unit();\n    ll step = 0;\n    assert(check(x));\n    FOR_R(k,\
    \ LOG) {\n      int j = TO[k][i];\n      X y = Monoid::op(x, DP[k][i]);\n    \
    \  if (check(y)) {\n        step |= 1LL << k;\n        i = j;\n        x = y;\n\
    \        assert(i != -1);\n      }\n    }\n    return step;\n  }\n\n  void debug()\
    \ {\n    print(\"TO\");\n    FOR(k, LOG) print(TO[k]);\n    print(\"DP\");\n \
    \   FOR(k, LOG) print(DP[k]);\n  }\n};\n#line 2 \"/home/maspy/compro/library/alg/group_add.hpp\"\
    \ntemplate <class X>\nstruct Group_Add {\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return n * x; }\n  static constexpr X unit() { return\
    \ X(0); }\n  static constexpr bool commute = true;\n};\n#line 5 \"main.cpp\"\n\
    \nvoid solve() {\n  LL(N);\n  VEC(ll, A, N);\n  Doubling<Group_Add<ll>, 50> X(N);\n\
    \  FOR(i, N) { X.set(i, (i + A[i]) % N, A[i]); }\n  X.build();\n\n  LL(Q);\n \
    \ FOR(Q) {\n    LL(k);\n    auto [to, val] = X.calc(0, k);\n    print(val);\n\
    \  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  code: "#line 1 \"/home/maspy/compro/library/my_template.hpp\"\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using i128 = __int128;\n\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n#define vv(type,\
    \ name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
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
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool\
    \ chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b,\
    \ 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
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
    \ len(A);\n  assert(len(I) == n);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n\
    \  return B;\n}\n#line 1 \"/home/maspy/compro/library/other/io.hpp\"\n// based\
    \ on yosupo's fastio\n#include <unistd.h>\n\nnamespace detail {\ntemplate <typename\
    \ T, decltype(&T::is_modint) = &T::is_modint>\nstd::true_type check_value(int);\n\
    template <typename T>\nstd::false_type check_value(long);\n} // namespace detail\n\
    \ntemplate <typename T>\nstruct is_modint : decltype(detail::check_value<T>(0))\
    \ {};\ntemplate <typename T>\nusing is_modint_t = enable_if_t<is_modint<T>::value>;\n\
    template <typename T>\nusing is_not_modint_t = enable_if_t<!is_modint<T>::value>;\n\
    \nstruct Scanner {\n  FILE *fp;\n  char line[(1 << 15) + 1];\n  size_t st = 0,\
    \ ed = 0;\n  void reread() {\n    memmove(line, line + st, ed - st);\n    ed -=\
    \ st;\n    st = 0;\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\n    line[ed]\
    \ = '\\0';\n  }\n  bool succ() {\n    while (true) {\n      if (st == ed) {\n\
    \        reread();\n        if (st == ed) return false;\n      }\n      while\
    \ (st != ed && isspace(line[st])) st++;\n      if (st != ed) break;\n    }\n \
    \   if (ed - st <= 50) {\n      bool sep = false;\n      for (size_t i = st; i\
    \ < ed; i++) {\n        if (isspace(line[i])) {\n          sep = true;\n     \
    \     break;\n        }\n      }\n      if (!sep) reread();\n    }\n    return\
    \ true;\n  }\n  template <class T, enable_if_t<is_same<T, string>::value, int>\
    \ = 0>\n  bool read_single(T &ref) {\n    if (!succ()) return false;\n    while\
    \ (true) {\n      size_t sz = 0;\n      while (st + sz < ed && !isspace(line[st\
    \ + sz])) sz++;\n      ref.append(line + st, sz);\n      st += sz;\n      if (!sz\
    \ || st != ed) break;\n      reread();\n    }\n    return true;\n  }\n  template\
    \ <class T, enable_if_t<is_integral<T>::value, int> = 0>\n  bool read_single(T\
    \ &ref) {\n    if (!succ()) return false;\n    bool neg = false;\n    if (line[st]\
    \ == '-') {\n      neg = true;\n      st++;\n    }\n    ref = T(0);\n    while\
    \ (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }\n    if (neg) ref\
    \ = -ref;\n    return true;\n  }\n  template <class T, is_modint_t<T> * = nullptr>\n\
    \  bool read_single(T &ref) {\n    long long val = 0;\n    bool f = read_single(val);\n\
    \    ref = T(val);\n    return f;\n  }\n  bool read_single(double &ref) {\n  \
    \  string s;\n    if (!read_single(s)) return false;\n    ref = std::stod(s);\n\
    \    return true;\n  }\n  bool read_single(char &ref) {\n    string s;\n    if\
    \ (!read_single(s) || s.size() != 1) return false;\n    ref = s[0];\n    return\
    \ true;\n  }\n  template <class T>\n  bool read_single(vector<T> &ref) {\n   \
    \ for (auto &d: ref) {\n      if (!read_single(d)) return false;\n    }\n    return\
    \ true;\n  }\n  template <class T, class U>\n  bool read_single(pair<T, U> &p)\
    \ {\n    return (read_single(p.first) && read_single(p.second));\n  }\n  template\
    \ <class A, class B, class C>\n  bool read_single(tuple<A, B, C> &p) {\n    return\
    \ (read_single(get<0>(p)) && read_single(get<1>(p))\n            && read_single(get<2>(p)));\n\
    \  }\n  template <class A, class B, class C, class D>\n  bool read_single(tuple<A,\
    \ B, C, D> &p) {\n    return (read_single(get<0>(p)) && read_single(get<1>(p))\n\
    \            && read_single(get<2>(p)) && read_single(get<3>(p)));\n  }\n  void\
    \ read() {}\n  template <class H, class... T>\n  void read(H &h, T &... t) {\n\
    \    bool f = read_single(h);\n    assert(f);\n    read(t...);\n  }\n  Scanner(FILE\
    \ *fp) : fp(fp) {}\n};\n\nstruct Printer {\n  Printer(FILE *_fp) : fp(_fp) {}\n\
    \  ~Printer() { flush(); }\n\n  static constexpr size_t SIZE = 1 << 15;\n  FILE\
    \ *fp;\n  char line[SIZE], small[50];\n  size_t pos = 0;\n  void flush() {\n \
    \   fwrite(line, 1, pos, fp);\n    pos = 0;\n  }\n  void write(const char &val)\
    \ {\n    if (pos == SIZE) flush();\n    line[pos++] = val;\n  }\n  template <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\n  void write(T val) {\n   \
    \ if (pos > (1 << 15) - 50) flush();\n    if (val == 0) {\n      write('0');\n\
    \      return;\n    }\n    if (val < 0) {\n      write('-');\n      val = -val;\
    \ // todo min\n    }\n    size_t len = 0;\n    while (val) {\n      small[len++]\
    \ = char(0x30 | (val % 10));\n      val /= 10;\n    }\n    for (size_t i = 0;\
    \ i < len; i++) { line[pos + i] = small[len - 1 - i]; }\n    pos += len;\n  }\n\
    \  void write(const string &s) {\n    for (char c: s) write(c);\n  }\n  void write(const\
    \ char *s) {\n    size_t len = strlen(s);\n    for (size_t i = 0; i < len; i++)\
    \ write(s[i]);\n  }\n  void write(const double &x) {\n    ostringstream oss;\n\
    \    oss << setprecision(15) << x;\n    string s = oss.str();\n    write(s);\n\
    \  }\n  void write(const long double &x) {\n    ostringstream oss;\n    oss <<\
    \ setprecision(15) << x;\n    string s = oss.str();\n    write(s);\n  }\n  template\
    \ <class T, is_modint_t<T> * = nullptr>\n  void write(T &ref) {\n    write(ref.val);\n\
    \  }\n  template <class T>\n  void write(const vector<T> &val) {\n    auto n =\
    \ val.size();\n    for (size_t i = 0; i < n; i++) {\n      if (i) write(' ');\n\
    \      write(val[i]);\n    }\n  }\n  template <class T, class U>\n  void write(const\
    \ pair<T, U> &val) {\n    write(val.first);\n    write(' ');\n    write(val.second);\n\
    \  }\n  template <class A, class B, class C>\n  void write(const tuple<A, B, C>\
    \ &val) {\n    auto &[a, b, c] = val;\n    write(a), write(' '), write(b), write('\
    \ '), write(c);\n  }\n  template <class A, class B, class C, class D>\n  void\
    \ write(const tuple<A, B, C, D> &val) {\n    auto &[a, b, c, d] = val;\n    write(a),\
    \ write(' '), write(b), write(' '), write(c), write(' '), write(d);\n  }\n  template\
    \ <class A, class B, class C, class D, class E>\n  void write(const tuple<A, B,\
    \ C, D, E> &val) {\n    auto &[a, b, c, d, e] = val;\n    write(a), write(' '),\
    \ write(b), write(' '), write(c), write(' '), write(d),\n        write(' '), write(e);\n\
    \  }\n  template <class A, class B, class C, class D, class E, class F>\n  void\
    \ write(const tuple<A, B, C, D, E, F> &val) {\n    auto &[a, b, c, d, e, f] =\
    \ val;\n    write(a), write(' '), write(b), write(' '), write(c), write(' '),\
    \ write(d),\n        write(' '), write(e), write(' '), write(f);\n  }\n  template\
    \ <class T, size_t S>\n  void write(const array<T, S> &val) {\n    auto n = val.size();\n\
    \    for (size_t i = 0; i < n; i++) {\n      if (i) write(' ');\n      write(val[i]);\n\
    \    }\n  }\n  void write(i128 val) {\n    string s;\n    bool negative = 0;\n\
    \    if (val < 0) {\n      negative = 1;\n      val = -val;\n    }\n    while\
    \ (val) {\n      s += '0' + int(val % 10);\n      val /= 10;\n    }\n    if (negative)\
    \ s += \"-\";\n    reverse(all(s));\n    if (len(s) == 0) s = \"0\";\n    write(s);\n\
    \  }\n};\n\nScanner scanner = Scanner(stdin);\nPrinter printer = Printer(stdout);\n\
    \nvoid flush() { printer.flush(); }\nvoid print() { printer.write('\\n'); }\n\
    template <class Head, class... Tail>\nvoid print(Head &&head, Tail &&... tail)\
    \ {\n  printer.write(head);\n  if (sizeof...(Tail)) printer.write(' ');\n  print(forward<Tail>(tail)...);\n\
    }\n\nvoid read() {}\ntemplate <class Head, class... Tail>\nvoid read(Head &head,\
    \ Tail &... tail) {\n  scanner.read(head);\n  read(tail...);\n}\n\n#define INT(...)\
    \   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define LL(...)   \\\n  ll\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n#define CHAR(...)   \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define DBL(...)      \\\n  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define\
    \ VEC(type, name, size) \\\n  vector<type> name(size);    \\\n  read(name)\n#define\
    \ VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\"\
    \ : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t\
    \ ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t =\
    \ 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\n#line\
    \ 1 \"/home/maspy/compro/library/ds/doubling.hpp\"\n// \u72B6\u614B a \u304B\u3089\
    \ 1 \u56DE\u64CD\u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\
    \u3057\u3001\u30E2\u30CE\u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\
    \n// \u72B6\u614B\u6570 N\n// set(i, to, x)\n// \u884C\u304D\u5148\u304C\u306A\
    \u3044\u5834\u5408\uFF1A-1 \uFF08set \u4E0D\u8981\uFF09\ntemplate <typename Monoid,\
    \ int LOG>\nstruct Doubling {\n  using X = typename Monoid::value_type;\n  int\
    \ N;\n  bool is_prepared;\n  vvc<int> TO;\n  vvc<X> DP;\n\n  Doubling(int N) :\
    \ N(N), is_prepared(0) {\n    TO.assign(LOG, vc<int>(N, -1));\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::unit()));\n  }\n\n  void set(int i, int to, X x) {\n    assert(!is_prepared);\n\
    \    assert(-1 <= to && to < N);\n    TO[0][i] = to;\n    DP[0][i] = x;\n  }\n\
    \n  void build() {\n    if (is_prepared) return;\n    is_prepared = 1;\n    FOR(k,\
    \ LOG - 1) {\n      FOR(v, N) {\n        int w = TO[k][v];\n        if (w == -1)\
    \ {\n          TO[k + 1][v] = -1;\n          DP[k + 1][v] = DP[k][v];\n      \
    \    continue;\n        }\n        TO[k + 1][v] = TO[k][w];\n        DP[k + 1][v]\
    \ = Monoid::op(DP[k][v], DP[k][w]);\n      }\n    }\n  }\n\n  pair<int, X> calc(int\
    \ i, ll step) {\n    assert(is_prepared);\n    assert(step < (1LL << LOG));\n\
    \    X x = Monoid::unit();\n    FOR(k, LOG) {\n      if (i == -1) break;\n   \
    \   if (step & 1LL << k) {\n        x = Monoid::op(x, DP[k][i]);\n        i =\
    \ TO[k][i];\n      }\n    }\n    return {i, x};\n  }\n\n  template <typename F>\n\
    \  ll max_step(F check, int i) {\n    assert(is_prepared);\n    // step\u6570\n\
    \    X x = Monoid::unit();\n    ll step = 0;\n    assert(check(x));\n    FOR_R(k,\
    \ LOG) {\n      int j = TO[k][i];\n      X y = Monoid::op(x, DP[k][i]);\n    \
    \  if (check(y)) {\n        step |= 1LL << k;\n        i = j;\n        x = y;\n\
    \        assert(i != -1);\n      }\n    }\n    return step;\n  }\n\n  void debug()\
    \ {\n    print(\"TO\");\n    FOR(k, LOG) print(TO[k]);\n    print(\"DP\");\n \
    \   FOR(k, LOG) print(DP[k]);\n  }\n};\n#line 2 \"/home/maspy/compro/library/alg/group_add.hpp\"\
    \ntemplate <class X>\nstruct Group_Add {\n  using value_type = X;\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return n * x; }\n  static constexpr X unit() { return\
    \ X(0); }\n  static constexpr bool commute = true;\n};\n#line 5 \"main.cpp\"\n\
    \nvoid solve() {\n  LL(N);\n  VEC(ll, A, N);\n  Doubling<Group_Add<ll>, 50> X(N);\n\
    \  FOR(i, N) { X.set(i, (i + A[i]) % N, A[i]); }\n  X.build();\n\n  LL(Q);\n \
    \ FOR(Q) {\n    LL(k);\n    auto [to, val] = X.calc(0, k);\n    print(val);\n\
    \  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yukicoder/1097_doubling.test.cpp
  requiredBy: []
  timestamp: '2022-05-20 02:27:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1097_doubling.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1097_doubling.test.cpp
- /verify/test/yukicoder/1097_doubling.test.cpp.html
title: test/yukicoder/1097_doubling.test.cpp
---
