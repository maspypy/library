---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/extended_lichao_1.hpp
    title: convex/extended_lichao_1.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/extended_lichao.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(),\
    \ T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/extended_lichao.test.cpp\"\
    \n\n#line 1 \"convex/extended_lichao_1.hpp\"\n// https://codeforces.com/blog/entry/86731)\n\
    // chmin(A[x],ax+b), A[x]+=ax+b, get A[x]\n// \u3064\u304B\u3048\u305F https://codeforces.com/contest/1120/problem/F\n\
    template <bool MINIMIZE>\nstruct Extended_LiChao_Tree_1 {\n  // \u5165\u51FA\u529B\
    \u4EE5\u5916\u3067\u306F minimize \u3057\u3066\u3044\u308B\n  struct F {\n   \
    \ ll a, b;\n    F(ll a = 0, ll b = 0) : a(a), b(b) {}\n    ll operator()(ll x)\
    \ { return a * x + b; }\n    void add(F &other) {\n      if (b == infty<ll> ||\
    \ other.b == infty<ll>) {\n        a = 0, b = infty<ll>;\n      } else {\n   \
    \     a += other.a, b += other.b;\n      }\n    }\n  };\n\n  vi X;\n  vc<F> dat,\
    \ lazy;\n  int n, log, size;\n\n  Extended_LiChao_Tree_1(vi X_) : X(X_) {\n  \
    \  UNIQUE(X);\n    n = len(X), log = 1;\n    while ((1 << log) < n) ++log;\n \
    \   size = 1 << log;\n    dat.assign(size << 1, F(0, infty<ll>));\n    lazy.assign(size\
    \ << 1, F(0, 0));\n  }\n\n  // O(logN). f(x) := min(f(x), ax+b).\n  void chmin_line(ll\
    \ a, ll b) {\n    static_assert(MINIMIZE);\n    chmin_line_rec(1, F(a, b), 0,\
    \ n);\n  }\n\n  // O(logN). f(x) := max(f(x), ax+b).\n  void chmax_line(ll a,\
    \ ll b) {\n    static_assert(!MINIMIZE);\n    chmin_line_rec(1, F(-a, -b), 0,\
    \ n);\n  }\n\n  // O(log^2N). f(x) := min(f(x), ax+b) for L<=x<R.\n  // index\
    \ \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\u56F2.\n  void chmin_segment(ll\
    \ L, ll R, ll a, ll b) {\n    static_assert(MINIMIZE);\n    chmin_segment_rec(1,\
    \ LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  // O(log^2N). f(x) := max(f(x),\
    \ ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\
    \u56F2.\n  void chmax_segment(ll L, ll R, ll a, ll b) {\n    static_assert(!MINIMIZE);\n\
    \    chmin_segment_rec(1, LB(X, L), LB(X, R), F(-a, -b), 0, n);\n  }\n\n  // O(1).\
    \ f(x) := f(x)+ax+b.\n  void add_line(ll a, ll b) {\n    if (!MINIMIZE) a = -a,\
    \ b = -b;\n    add_segment_rec(1, 0, n, F(a, b), 0, n);\n  }\n\n  // O(log^2N).\
    \ f(x) := f(x)+ax+b for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[]\
    \ \u306E\u7BC4\u56F2.\n  void add_segment(ll L, ll R, ll a, ll b) {\n    if (!MINIMIZE)\
    \ a = -a, b = -b;\n    add_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);\n\
    \  }\n\n  ll query(ll x) {\n    int idx = LB(X, x);\n    assert(0 <= idx && idx\
    \ < n && X[idx] == x);\n    ll ans = query_rec(1, idx, 0, n, F(0, 0));\n    return\
    \ MINIMIZE ? ans : -ans;\n  }\n\nprivate:\n  void push(int i) {\n    dat[2 * i\
    \ + 0].add(lazy[i]), lazy[2 * i + 0].add(lazy[i]);\n    dat[2 * i + 1].add(lazy[i]),\
    \ lazy[2 * i + 1].add(lazy[i]);\n    lazy[i] = F(0, 0);\n  }\n\n  void chmin_segment_rec(int\
    \ i, ll xl, ll xr, F f, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr,\
    \ node_r);\n    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n\
    \      ll node_m = (node_l + node_r) / 2;\n      push(i);\n      chmin_segment_rec(2\
    \ * i + 0, xl, xr, f, node_l, node_m);\n      chmin_segment_rec(2 * i + 1, xl,\
    \ xr, f, node_m, node_r);\n      return;\n    }\n    chmin_line_rec(i, f, node_l,\
    \ node_r);\n  }\n\n  void chmin_line_rec(int i, F f, ll node_l, ll node_r) {\n\
    \    F g = dat[i];\n    ll fl = f(X[node_l]), fr = f(X[node_r - 1]);\n    ll gl\
    \ = g(X[node_l]), gr = g(X[node_r - 1]);\n    if (fl <= gl && fr <= gr) {\n  \
    \    dat[i] = f;\n      return;\n    }\n    if (fl >= gl && fr >= gr) { return;\
    \ }\n    ll node_m = (node_l + node_r) / 2;\n    ll fm = f(X[node_m]), gm = g(X[node_m]);\n\
    \    push(i);\n    if (fm < gm && fl < gl) dat[i] = f, chmin_line_rec(2 * i +\
    \ 1, g, node_m, node_r);\n    elif (fm < gm && fl >= gl) dat[i] = f, chmin_line_rec(2\
    \ * i + 0, g, node_l, node_m);\n    elif (fm >= gm && gl < fl) chmin_line_rec(2\
    \ * i + 1, f, node_m, node_r);\n    elif (fm >= gm && gl >= fl) chmin_line_rec(2\
    \ * i + 0, f, node_l, node_m);\n  }\n\n  void add_segment_rec(int i, ll xl, ll\
    \ xr, F f, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n\
    \    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      push(i);\n      chmin_line_rec(2 * i + 0, dat[i],\
    \ node_l, node_m);\n      chmin_line_rec(2 * i + 1, dat[i], node_m, node_r);\n\
    \      dat[i] = F(0, infty<ll>);\n      add_segment_rec(2 * i + 0, xl, xr, f,\
    \ node_l, node_m);\n      add_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);\n\
    \      return;\n    }\n    dat[i].add(f), lazy[i].add(f);\n  }\n\n  ll query_rec(int\
    \ i, ll x, ll node_l, ll node_r, F laz) {\n    ll res = dat[i](X[x]);\n    if\
    \ (res < infty<ll>) res += laz(X[x]);\n    ll node_m = (node_l + node_r) / 2;\n\
    \    laz.add(lazy[i]);\n    if (node_r == node_l + 1) return res;\n    if (x <\
    \ node_m) { chmin(res, query_rec(2 * i + 0, x, node_l, node_m, laz)); }\n    if\
    \ (x >= node_m) { chmin(res, query_rec(2 * i + 1, x, node_m, node_r, laz)); }\n\
    \    return res;\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 7 \"test/1_mytest/extended_lichao.test.cpp\"\
    \n\nvoid test_minimize() {\n  ll N = RNG(1, 100);\n\n  vi X(201);\n  FOR(i, 201)\
    \ X[i] = i - 100;\n  shuffle(X);\n  X.resize(N);\n\n  Extended_LiChao_Tree_1<true>\
    \ LCT(X);\n  vi A(N, infty<ll>);\n\n  ll Q = 100;\n  FOR(Q) {\n    ll t = RNG(0,\
    \ 3);\n    ll L = RNG(-100, 101);\n    ll R = RNG(-100, 101);\n    if (L > R)\
    \ swap(L, R);\n    ++R;\n    ll a = RNG(-10, 10);\n    ll b = RNG(-100, 100);\n\
    \    if (t == 0) {\n      // line\n      LCT.chmin_line(a, b);\n      FOR(i, N)\
    \ chmin(A[i], a * X[i] + b);\n    }\n    if (t == 1) {\n      // segment\n   \
    \   LCT.chmin_segment(L, R, a, b);\n      FOR(i, N) {\n        if (L <= X[i] &&\
    \ X[i] < R) chmin(A[i], a * X[i] + b);\n      }\n    }\n    if (t == 2) {\n  \
    \    // apply\n      LCT.add_segment(L, R, a, b);\n      FOR(i, N) {\n       \
    \ if (L <= X[i] && X[i] < R && A[i] < infty<ll>) A[i] += a * X[i] + b;\n     \
    \ }\n    }\n    FOR(i, N) {\n      ll god = A[i];\n      ll ans = LCT.query(X[i]);\n\
    \      assert(god == ans);\n    }\n  }\n}\n\nvoid test_maximize() {\n  ll N =\
    \ RNG(1, 100);\n\n  vi X(201);\n  FOR(i, 201) X[i] = i - 100;\n  shuffle(X);\n\
    \  X.resize(N);\n\n  Extended_LiChao_Tree_1<false> LCT(X);\n  vi A(N, -infty<ll>);\n\
    \n  ll Q = 100;\n  FOR(Q) {\n    ll t = RNG(0, 3);\n    ll L = RNG(-100, 101);\n\
    \    ll R = RNG(-100, 101);\n    if (L > R) swap(L, R);\n    ++R;\n    ll a =\
    \ RNG(-10, 10);\n    ll b = RNG(-100, 100);\n    if (t == 0) {\n      // line\n\
    \      LCT.chmax_line(a, b);\n      FOR(i, N) chmax(A[i], a * X[i] + b);\n   \
    \ }\n    if (t == 1) {\n      // segment\n      LCT.chmax_segment(L, R, a, b);\n\
    \      FOR(i, N) {\n        if (L <= X[i] && X[i] < R) chmax(A[i], a * X[i] +\
    \ b);\n      }\n    }\n    if (t == 2) {\n      // apply\n      LCT.add_segment(L,\
    \ R, a, b);\n      FOR(i, N) {\n        if (L <= X[i] && X[i] < R && A[i] > -infty<ll>)\
    \ A[i] += a * X[i] + b;\n      }\n    }\n    FOR(i, N) {\n      ll god = A[i];\n\
    \      ll ans = LCT.query(X[i]);\n      assert(god == ans);\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(10000) test_minimize();\n  FOR(10000) test_maximize();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"convex/extended_lichao_1.hpp\"\n#include \"random/base.hpp\"\n\
    #include \"random/shuffle.hpp\"\n\nvoid test_minimize() {\n  ll N = RNG(1, 100);\n\
    \n  vi X(201);\n  FOR(i, 201) X[i] = i - 100;\n  shuffle(X);\n  X.resize(N);\n\
    \n  Extended_LiChao_Tree_1<true> LCT(X);\n  vi A(N, infty<ll>);\n\n  ll Q = 100;\n\
    \  FOR(Q) {\n    ll t = RNG(0, 3);\n    ll L = RNG(-100, 101);\n    ll R = RNG(-100,\
    \ 101);\n    if (L > R) swap(L, R);\n    ++R;\n    ll a = RNG(-10, 10);\n    ll\
    \ b = RNG(-100, 100);\n    if (t == 0) {\n      // line\n      LCT.chmin_line(a,\
    \ b);\n      FOR(i, N) chmin(A[i], a * X[i] + b);\n    }\n    if (t == 1) {\n\
    \      // segment\n      LCT.chmin_segment(L, R, a, b);\n      FOR(i, N) {\n \
    \       if (L <= X[i] && X[i] < R) chmin(A[i], a * X[i] + b);\n      }\n    }\n\
    \    if (t == 2) {\n      // apply\n      LCT.add_segment(L, R, a, b);\n     \
    \ FOR(i, N) {\n        if (L <= X[i] && X[i] < R && A[i] < infty<ll>) A[i] +=\
    \ a * X[i] + b;\n      }\n    }\n    FOR(i, N) {\n      ll god = A[i];\n     \
    \ ll ans = LCT.query(X[i]);\n      assert(god == ans);\n    }\n  }\n}\n\nvoid\
    \ test_maximize() {\n  ll N = RNG(1, 100);\n\n  vi X(201);\n  FOR(i, 201) X[i]\
    \ = i - 100;\n  shuffle(X);\n  X.resize(N);\n\n  Extended_LiChao_Tree_1<false>\
    \ LCT(X);\n  vi A(N, -infty<ll>);\n\n  ll Q = 100;\n  FOR(Q) {\n    ll t = RNG(0,\
    \ 3);\n    ll L = RNG(-100, 101);\n    ll R = RNG(-100, 101);\n    if (L > R)\
    \ swap(L, R);\n    ++R;\n    ll a = RNG(-10, 10);\n    ll b = RNG(-100, 100);\n\
    \    if (t == 0) {\n      // line\n      LCT.chmax_line(a, b);\n      FOR(i, N)\
    \ chmax(A[i], a * X[i] + b);\n    }\n    if (t == 1) {\n      // segment\n   \
    \   LCT.chmax_segment(L, R, a, b);\n      FOR(i, N) {\n        if (L <= X[i] &&\
    \ X[i] < R) chmax(A[i], a * X[i] + b);\n      }\n    }\n    if (t == 2) {\n  \
    \    // apply\n      LCT.add_segment(L, R, a, b);\n      FOR(i, N) {\n       \
    \ if (L <= X[i] && X[i] < R && A[i] > -infty<ll>) A[i] += a * X[i] + b;\n    \
    \  }\n    }\n    FOR(i, N) {\n      ll god = A[i];\n      ll ans = LCT.query(X[i]);\n\
    \      assert(god == ans);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(10000)\
    \ test_minimize();\n  FOR(10000) test_maximize();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - convex/extended_lichao_1.hpp
  - random/base.hpp
  - random/shuffle.hpp
  isVerificationFile: true
  path: test/1_mytest/extended_lichao.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 19:47:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/extended_lichao.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/extended_lichao.test.cpp
- /verify/test/1_mytest/extended_lichao.test.cpp.html
title: test/1_mytest/extended_lichao.test.cpp
---
