---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/manhattan_nns.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
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
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64()\
    \ {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class\
    \ Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n\
    \  SegTree(int n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f)\
    \ {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size)\
    \ update(i);\n  }\n\n  X get(int i) { return dat[size + i]; }\n  vc<X> get_all()\
    \ { return {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int\
    \ i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const\
    \ X& x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) {\n    assert(0 <= L && L <= R && R <= n);\n    X vl =\
    \ Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n    while (L\
    \ < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr\
    \ = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int\
    \ max_right(F check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) { sm = Monoid::op(sm, dat[L++]); }\n        }\n        return L -\
    \ size;\n      }\n      sm = Monoid::op(sm, dat[L++]);\n    } while ((L & -L)\
    \ != L);\n    return n;\n  }\n\n  template <class F>\n  int min_left(F check,\
    \ int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R\
    \ == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n    \
    \  --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool tie_is_left\
    \ = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n\
    \  using X = value_type;\r\n  static constexpr bool is_small(const X& x, const\
    \ X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi) return\
    \ false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\
    \n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static constexpr\
    \ X unit() { return {infty<T>, -1}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"geo/manhattan_nns.hpp\"\n\r\n// \u70B9\u7FA4 FRM \u304B\u3089\
    \u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector \u306E\
    \ pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X = ll>\r\n\
    pair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>& TO) {\r\
    \n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  vc<int> nbd_idx(N, -1);\r\n  vc<X> dist(N, infty<X>);\r\n\r\n  auto add_ans\
    \ = [&](int i, int j) -> void {\r\n    if (j == -1) return;\r\n    X dx = points[i].fi\
    \ - points[j].fi;\r\n    X dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i],\
    \ abs(dx) + abs(dy))) nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\
    \n  iota(all(I), 0);\r\n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi\
    \ < points[j].fi); });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<X>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};\n#line 5 \"test/1_mytest/manhattan_nns.test.cpp\"\
    \n\nvoid test() {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    vc<pi> A, B;\n    FOR(n)\
    \ {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n      A.eb(a, b);\n\
    \    }\n    FOR(m) {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n\
    \      B.eb(a, b);\n    }\n    auto [dist, J] = manhattan_nns(A, B);\n    FOR(i,\
    \ n) {\n      FOR(j, m) {\n        auto [x1, y1] = A[i];\n        auto [x2, y2]\
    \ = B[j];\n        int d = abs(x1 - x2) + abs(y1 - y2);\n        assert(dist[i]\
    \ <= d);\n        assert(j != J[i] || dist[i] == d);\n      }\n    }\n  }\n}\n\
    \nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n\
    }\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"geo/manhattan_nns.hpp\"\n\nvoid test()\
    \ {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    vc<pi> A, B;\n    FOR(n) {\n      int\
    \ a = RNG(0, 100);\n      int b = RNG(0, 100);\n      A.eb(a, b);\n    }\n   \
    \ FOR(m) {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n      B.eb(a,\
    \ b);\n    }\n    auto [dist, J] = manhattan_nns(A, B);\n    FOR(i, n) {\n   \
    \   FOR(j, m) {\n        auto [x1, y1] = A[i];\n        auto [x2, y2] = B[j];\n\
    \        int d = abs(x1 - x2) + abs(y1 - y2);\n        assert(dist[i] <= d);\n\
    \        assert(j != J[i] || dist[i] == d);\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - geo/manhattan_nns.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/min_idx.hpp
  isVerificationFile: true
  path: test/1_mytest/manhattan_nns.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 04:06:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/manhattan_nns.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/manhattan_nns.test.cpp
- /verify/test/1_mytest/manhattan_nns.test.cpp.html
title: test/1_mytest/manhattan_nns.test.cpp
---
