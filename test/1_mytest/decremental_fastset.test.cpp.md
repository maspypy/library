---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/decremental_fastset.hpp
    title: ds/decremental_fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/timer.hpp
    title: other/timer.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/decremental_fastset.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/decremental_fastset.test.cpp\"\
    \n\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n, n_comp;\n\
    \  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void\
    \ build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  void\
    \ reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x] >= 0)\
    \ {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n     \
    \ x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n    x = (*this)[x];\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x],\
    \ y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x,\
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n\n\
    \  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] = (*this)[i];\n\
    \    return A;\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 1 \"other/timer.hpp\"\n\nstruct\
    \ Timer {\n  bool started;\n  chrono::high_resolution_clock::time_point s;\n\n\
    \  Timer() : started(false) {}\n  void start() {\n    started = true;\n    s =\
    \ chrono::high_resolution_clock::now();\n  }\n\n  // second from start\n  double\
    \ operator()() {\n    assert(started);\n    chrono::high_resolution_clock::time_point\
    \ t = chrono::high_resolution_clock::now();\n    chrono::duration<double> diff\
    \ = t - s;\n    return diff.count();\n  }\n};\n#line 2 \"ds/fastset.hpp\"\n\r\n\
    // 64-ary tree\r\n// space: (N/63) * u64\r\nstruct FastSet {\r\n  static constexpr\
    \ u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int\
    \ n) { build(n); }\r\n\r\n  int size() { return n; }\r\n\r\n  template <typename\
    \ F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int\
    \ m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n  \
    \  log = len(seg);\r\n  }\r\n  template <typename F>\r\n  void build(int n, F\
    \ f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i %\
    \ B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h])) {\r\n        seg[h\
    \ + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\r\
    \n  void insert(int i) {\r\n    assert(0 <= i && i < n);\r\n    for (int h = 0;\
    \ h < log; h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /= B;\r\n   \
    \ }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n  \
    \  assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0; h < log;\
    \ h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B]\
    \ |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\
    \n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int\
    \ next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int h =\
    \ 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      u64\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int g =\
    \ h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // max\
    \ [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if (i >=\
    \ n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i == -1) break;\r\
    \n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d) {\r\n        i\
    \ = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  void reset() {\r\n    enumerate(0, n, [&](int i) -> void { erase(i); });\r\n\
    \  }\r\n\r\n  string to_string() {\r\n    string s(n, '?');\r\n    for (int i\
    \ = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n\
    };\n#line 2 \"ds/decremental_fastset.hpp\"\n\n// amortized linear\n// MoFR \u306A\
    \u3057\u3060\u3068 FastSet \u3088\u308A\u9045\u304B\u3063\u305F\nstruct Decremental_FastSet\
    \ {\n  struct Decremental_Neighbor_UF {\n    int n;\n    UnionFind uf;\n    vc<int>\
    \ L, R;\n    Decremental_Neighbor_UF(int n) : n(n), uf(n + 2), L(n + 2), R(n +\
    \ 2) {\n      FOR(i, n + 2) L[i] = i, R[i] = i;\n    }\n    void erase(int i)\
    \ {\n      assert(0 <= i && i < n);\n      ++i;\n      int l = L[uf[i - 1]], r\
    \ = R[uf[i]];\n      uf.merge(i, i - 1);\n      L[uf[i]] = l, R[uf[i]] = r;\n\
    \    }\n    int prev(int i) {\n      assert(-1 <= i);\n      chmin(i, n - 1);\n\
    \      return L[uf[i + 1]] - 1;\n    }\n    int next(int i) {\n      assert(i\
    \ <= n);\n      chmax(i, 0);\n      return R[uf[i]];\n    }\n  };\n  int N, n;\n\
    \  vc<u64> dat;\n  Decremental_Neighbor_UF X;\n  Decremental_FastSet(int N) :\
    \ N(N), n((N + 63) / 64), X(n) {\n    dat.assign(n, u64(-1));\n    if (n) dat.back()\
    \ = u64(-1) >> (64 * n - N);\n  }\n\n  bool operator[](int i) { return (dat[i\
    \ / 64] >> (i & 63) & 1); }\n\n  void erase(int i) {\n    int a = i / 64, b =\
    \ i & 63;\n    if (!(dat[a] >> b & 1)) return;\n    dat[a] &= ~(u64(1) << b);\n\
    \    if (dat[a] == 0) {\n      X.erase(a);\n    }\n  }\n  int prev(int i) {\n\
    \    assert(-1 <= i);\n    chmin(i, N - 1);\n    if (i == -1) return -1;\n   \
    \ int a = i / 64, b = i & 63;\n    u64 x = dat[a] & (u64(-1) >> (63 - b));\n \
    \   if (x != 0) return 64 * a + topbit(x);\n    a = X.prev(a - 1);\n    return\
    \ (a == -1 ? -1 : 64 * a + topbit(dat[a]));\n  }\n  int next(int i) {\n    assert(i\
    \ <= N);\n    chmax(i, 0);\n    if (i == N) return N;\n    int a = i / 64, b =\
    \ i & 63;\n    u64 x = dat[a] >> b;\n    if (x != 0) return 64 * a + b + lowbit(x);\n\
    \    a = X.next(a + 1);\n    return (a == n ? N : 64 * a + lowbit(dat[a]));\n\
    \  }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int r, F&&\
    \ f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n  }\n\n  string\
    \ to_string() {\n    string S(N, '.');\n    FOR(i, N) S[i] = '0' + (dat[i / 64]\
    \ >> (i & 63) & 1);\n    return S;\n  }\n};\n#line 9 \"test/1_mytest/decremental_fastset.test.cpp\"\
    \n\n// ackerman. memory \u591A\u3081\nstruct Decremental_FastSet_UF_ONLY {\n \
    \ int n;\n  UnionFind uf;\n  vc<int> L, R;\n  Decremental_FastSet_UF_ONLY(int\
    \ n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {\n    FOR(i, n + 2) L[i] = i, R[i]\
    \ = i;\n  }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n    ++i;\n \
    \   int l = L[uf[i - 1]], r = R[uf[i]];\n    uf.merge(i, i - 1);\n    L[uf[i]]\
    \ = l, R[uf[i]] = r;\n  }\n  int prev(int i) {\n    assert(-1 <= i);\n    chmin(i,\
    \ n - 1);\n    return L[uf[i + 1]] - 1;\n  }\n  int next(int i) {\n    assert(i\
    \ <= n);\n    chmax(i, 0);\n    return R[uf[i]];\n  }\n};\n\nvc<pair<int, int>>\
    \ sol1(vc<int> A, vc<int> B) {\n  int N = len(A);\n  FastSet FS(N, [&](int i)\
    \ -> int { return 1; });\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n\
    \    ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvc<pair<int,\
    \ int>> sol2(vc<int> A, vc<int> B) {\n  int N = len(A);\n  Decremental_FastSet\
    \ FS(N);\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n \
    \   ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvc<pair<int,\
    \ int>> sol3(vc<int> A, vc<int> B) {\n  int N = len(A);\n  Decremental_FastSet_UF_ONLY\
    \ FS(N);\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n \
    \   ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvoid test()\
    \ {\n  vc<double> X, Y, Z;\n  FOR(100) {\n    int N = 1 << 20;\n    vc<int> A(N);\n\
    \    FOR(i, N) A[i] = i;\n    shuffle(A);\n    vc<int> B(N);\n    FOR(i, N) B[i]\
    \ = RNG(0, N);\n    vc<pair<int, int>> ANS1, ANS2, ANS3;\n    {\n      Timer timer;\n\
    \      timer.start();\n      ANS1 = sol1(A, B);\n      X.eb(timer());\n    }\n\
    \    {\n      Timer timer;\n      timer.start();\n      ANS2 = sol2(A, B);\n \
    \     Y.eb(timer());\n    }\n\n    {\n      Timer timer;\n      timer.start();\n\
    \      ANS3 = sol3(A, B);\n      Z.eb(timer());\n    }\n    // print(X.back(),\
    \ Y.back(), Z.back());\n\n    assert(ANS1 == ANS2);\n    assert(ANS1 == ANS3);\n\
    \  }\n  // print(SUM<double>(X));\n  // print(SUM<double>(Y));\n  // print(SUM<double>(Z));\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/unionfind/unionfind.hpp\"\n#include \"random/shuffle.hpp\"\n\
    #include \"other/timer.hpp\"\n#include \"ds/fastset.hpp\"\n#include \"ds/decremental_fastset.hpp\"\
    \n\n// ackerman. memory \u591A\u3081\nstruct Decremental_FastSet_UF_ONLY {\n \
    \ int n;\n  UnionFind uf;\n  vc<int> L, R;\n  Decremental_FastSet_UF_ONLY(int\
    \ n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {\n    FOR(i, n + 2) L[i] = i, R[i]\
    \ = i;\n  }\n  void erase(int i) {\n    assert(0 <= i && i < n);\n    ++i;\n \
    \   int l = L[uf[i - 1]], r = R[uf[i]];\n    uf.merge(i, i - 1);\n    L[uf[i]]\
    \ = l, R[uf[i]] = r;\n  }\n  int prev(int i) {\n    assert(-1 <= i);\n    chmin(i,\
    \ n - 1);\n    return L[uf[i + 1]] - 1;\n  }\n  int next(int i) {\n    assert(i\
    \ <= n);\n    chmax(i, 0);\n    return R[uf[i]];\n  }\n};\n\nvc<pair<int, int>>\
    \ sol1(vc<int> A, vc<int> B) {\n  int N = len(A);\n  FastSet FS(N, [&](int i)\
    \ -> int { return 1; });\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n\
    \    ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvc<pair<int,\
    \ int>> sol2(vc<int> A, vc<int> B) {\n  int N = len(A);\n  Decremental_FastSet\
    \ FS(N);\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n \
    \   ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvc<pair<int,\
    \ int>> sol3(vc<int> A, vc<int> B) {\n  int N = len(A);\n  Decremental_FastSet_UF_ONLY\
    \ FS(N);\n  vc<pair<int, int>> ANS(N);\n  FOR(i, N) {\n    FS.erase(A[i]);\n \
    \   ANS[i] = {FS.prev(B[i]), FS.next(B[i])};\n  }\n  return ANS;\n}\n\nvoid test()\
    \ {\n  vc<double> X, Y, Z;\n  FOR(100) {\n    int N = 1 << 20;\n    vc<int> A(N);\n\
    \    FOR(i, N) A[i] = i;\n    shuffle(A);\n    vc<int> B(N);\n    FOR(i, N) B[i]\
    \ = RNG(0, N);\n    vc<pair<int, int>> ANS1, ANS2, ANS3;\n    {\n      Timer timer;\n\
    \      timer.start();\n      ANS1 = sol1(A, B);\n      X.eb(timer());\n    }\n\
    \    {\n      Timer timer;\n      timer.start();\n      ANS2 = sol2(A, B);\n \
    \     Y.eb(timer());\n    }\n\n    {\n      Timer timer;\n      timer.start();\n\
    \      ANS3 = sol3(A, B);\n      Z.eb(timer());\n    }\n    // print(X.back(),\
    \ Y.back(), Z.back());\n\n    assert(ANS1 == ANS2);\n    assert(ANS1 == ANS3);\n\
    \  }\n  // print(SUM<double>(X));\n  // print(SUM<double>(Y));\n  // print(SUM<double>(Z));\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/unionfind/unionfind.hpp
  - random/shuffle.hpp
  - random/base.hpp
  - other/timer.hpp
  - ds/fastset.hpp
  - ds/decremental_fastset.hpp
  isVerificationFile: true
  path: test/1_mytest/decremental_fastset.test.cpp
  requiredBy: []
  timestamp: '2026-02-05 01:08:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/decremental_fastset.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/decremental_fastset.test.cpp
- /verify/test/1_mytest/decremental_fastset.test.cpp.html
title: test/1_mytest/decremental_fastset.test.cpp
---
