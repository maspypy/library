---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':x:'
    path: ds/offline_query/range_mex_query.hpp
    title: ds/offline_query/range_mex_query.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/range_mex.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16\
    \ = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nconstexpr ll\
    \ TEN[] = {\n    1LL,\n    10LL,\n    100LL,\n    1000LL,\n    10000LL,\n    100000LL,\n\
    \    1000000LL,\n    10000000LL,\n    100000000LL,\n    1000000000LL,\n    10000000000LL,\n\
    \    100000000000LL,\n    1000000000000LL,\n    10000000000000LL,\n    100000000000000LL,\n\
    \    1000000000000000LL,\n    10000000000000000LL,\n    100000000000000000LL,\n\
    \    1000000000000000000LL,\n};\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a\
    \ < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a,\
    \ const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off =\
    \ 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i]\
    \ + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 4 \"test/1_mytest/range_mex.test.cpp\"\n\n#line\
    \ 1 \"ds/offline_query/range_mex_query.hpp\"\n\r\n#line 2 \"ds/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n,\
    \ log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template <typename\
    \ F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v)\
    \ { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return\
    \ MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, MX::unit());\n    FOR(i, n) dat[size + i]\
    \ = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  X get(int i) { return dat[size\
    \ + i]; }\n  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size\
    \ + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 4 \"ds/offline_query/range_mex_query.hpp\"\n\r\n// \u914D\u5217\u306F\
    \ static\r\n// \u30AF\u30A8\u30EA\u3082\u5148\u8AAD\u307F\u3059\u308B\r\n// example:\
    \ https://codeforces.com/contest/1436/problem/E\r\ntemplate <int BEGIN, typename\
    \ T = ll>\r\nstruct RangeMexQuery {\r\n  vc<T>& A;\r\n  vc<pair<int, int>> query;\r\
    \n\r\n  RangeMexQuery(vc<T>& A) : A(A) {}\r\n  void add(int l, int r) { query.eb(l,\
    \ r); }\r\n\r\n  vc<T> calc() {\r\n    int N = len(A);\r\n    // segtree, value\
    \ -> last idx\r\n    using Mono = Monoid_Min<int>;\r\n    vc<int> seg_raw(N +\
    \ 2, -1);\r\n    SegTree<Mono> seg(seg_raw);\r\n\r\n    int Q = len(query);\r\n\
    \    vc<T> ANS(Q);\r\n    vc<vc<int>> IDS(N + 1);\r\n    FOR(q, Q) {\r\n     \
    \ auto [L, R] = query[q];\r\n      IDS[R].eb(q);\r\n    }\r\n\r\n    FOR(i, N\
    \ + 1) {\r\n      // solve query\r\n      for (auto&& q: IDS[i]) {\r\n       \
    \ int L = query[q].fi;\r\n        auto check = [&](int x) -> bool { return x >=\
    \ L; };\r\n        int mex = seg.max_right(check, BEGIN);\r\n        ANS[q] =\
    \ mex;\r\n      }\r\n      // update segtree\r\n      if (i < N && A[i] < N +\
    \ 2) seg.set(A[i], i);\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n#line 6 \"\
    test/1_mytest/range_mex.test.cpp\"\n\npair<vc<int>, vc<pi>> gen(int N, int LIM,\
    \ int Q) {\n  vc<int> A(N);\n  FOR(i, N) { A[i] = RNG(0, LIM); }\n  vc<pi> query;\n\
    \  FOR(q, Q) {\n    int l = RNG(0, N);\n    int r = RNG(l, N + 1);\n    query.eb(l,\
    \ r);\n  }\n  return {A, query};\n}\n\nvc<int> naive(vc<int> A, vc<pi> query,\
    \ int begin) {\n  vc<int> ANS;\n  for (auto&& [l, r]: query) {\n    int mex =\
    \ begin;\n    while (1) {\n      bool ok = 1;\n      FOR(i, l, r) if (A[i] ==\
    \ mex) ok = 0;\n      if (ok) break;\n      ++mex;\n    }\n    ANS.eb(mex);\n\
    \  }\n  return ANS;\n}\n\nvoid test_0() {\n  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q,\
    \ 1, 20) {\n    auto [A, query] = gen(N, LIM, Q);\n    RangeMexQuery<0, int> X(A);\n\
    \    for (auto&& [l, r]: query) X.add(l, r);\n    assert(naive(A, query, 0) ==\
    \ X.calc());\n  }\n}\n\nvoid test_1() {\n  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q,\
    \ 1, 20) {\n    auto [A, query] = gen(N, LIM, Q);\n    for (auto&& x: A) ++x;\n\
    \    RangeMexQuery<1, int> X(A);\n    for (auto&& [l, r]: query) X.add(l, r);\n\
    \    assert(naive(A, query, 1) == X.calc());\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  test_0();\n  test_1();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n\n#include \"ds/offline_query/range_mex_query.hpp\"\
    \n\npair<vc<int>, vc<pi>> gen(int N, int LIM, int Q) {\n  vc<int> A(N);\n  FOR(i,\
    \ N) { A[i] = RNG(0, LIM); }\n  vc<pi> query;\n  FOR(q, Q) {\n    int l = RNG(0,\
    \ N);\n    int r = RNG(l, N + 1);\n    query.eb(l, r);\n  }\n  return {A, query};\n\
    }\n\nvc<int> naive(vc<int> A, vc<pi> query, int begin) {\n  vc<int> ANS;\n  for\
    \ (auto&& [l, r]: query) {\n    int mex = begin;\n    while (1) {\n      bool\
    \ ok = 1;\n      FOR(i, l, r) if (A[i] == mex) ok = 0;\n      if (ok) break;\n\
    \      ++mex;\n    }\n    ANS.eb(mex);\n  }\n  return ANS;\n}\n\nvoid test_0()\
    \ {\n  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q, 1, 20) {\n    auto [A, query] = gen(N,\
    \ LIM, Q);\n    RangeMexQuery<0, int> X(A);\n    for (auto&& [l, r]: query) X.add(l,\
    \ r);\n    assert(naive(A, query, 0) == X.calc());\n  }\n}\n\nvoid test_1() {\n\
    \  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q, 1, 20) {\n    auto [A, query] = gen(N,\
    \ LIM, Q);\n    for (auto&& x: A) ++x;\n    RangeMexQuery<1, int> X(A);\n    for\
    \ (auto&& [l, r]: query) X.add(l, r);\n    assert(naive(A, query, 1) == X.calc());\n\
    \  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test_0();\n  test_1();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - ds/offline_query/range_mex_query.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/1_mytest/range_mex.test.cpp
  requiredBy: []
  timestamp: '2025-09-04 02:56:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/range_mex.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/range_mex.test.cpp
- /verify/test/1_mytest/range_mex.test.cpp.html
title: test/1_mytest/range_mex.test.cpp
---
