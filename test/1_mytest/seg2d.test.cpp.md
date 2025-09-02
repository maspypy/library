---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':x:'
    path: ds/segtree/segtree_2d.hpp
    title: ds/segtree/segtree_2d.hpp
  - icon: ':x:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
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
  bundledCode: "#line 1 \"test/1_mytest/seg2d.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#if\
    \ defined(__MINGW32__) || defined(__MINGW64__)\n#include <bits/allocator.h>\n\
    #endif\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/seg2d.test.cpp\"\n\n\
    #line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"ds/segtree/segtree_2d.hpp\"\n// \u70B9\u306E\
    \u91CD\u8907\u304C\u3042\u3063\u3066\u3082\u5225\u306E\u70B9\u3068\u3057\u3066\
    \ set \u306A\u3069\u304C\u3055\u308C\u308B\r\ntemplate <typename Monoid, typename\
    \ XY, bool SMALL_X = false>\r\nstruct SegTree_2D {\r\n  using MX = Monoid;\r\n\
    \  using S = typename MX::value_type;\r\n  static_assert(MX::commute);\r\n  int\
    \ N;\r\n  // X to idx\r\n  vc<XY> keyX;\r\n  int minX;\r\n  // top node \u306E\
    \u70B9\u5217\r\n  vc<XY> all_Y;\r\n  vc<int> pos;\r\n  // segtree data\r\n  int\
    \ NX, log, size;\r\n  vc<int> indptr;\r\n  vc<S> dat;\r\n  // fractional cascading\r\
    \n  vc<int> to_left;\r\n\r\n  SegTree_2D(vc<XY>& X, vc<XY>& Y)\r\n      : SegTree_2D(len(X),\
    \ [&](int i) -> tuple<XY, XY, S> {\r\n          return {X[i], Y[i], MX::unit()};\r\
    \n        }) {}\r\n\r\n  SegTree_2D(vc<XY>& X, vc<XY>& Y, vc<S>& vals)\r\n   \
    \   : SegTree_2D(len(X), [&](int i) -> tuple<XY, XY, S> {\r\n          return\
    \ {X[i], Y[i], vals[i]};\r\n        }) {}\r\n\r\n  // f(i) = (x,y,val)\r\n  template\
    \ <typename F>\r\n  SegTree_2D(int N, F f) {\r\n    vc<XY> X(N), Y(N);\r\n   \
    \ vc<S> wt(N);\r\n    FOR(i, N) {\r\n      auto [a, b, c] = f(i);\r\n      X[i]\
    \ = a, Y[i] = b, wt[i] = c;\r\n    }\r\n    if (!SMALL_X) {\r\n      keyX = X;\r\
    \n      UNIQUE(keyX);\r\n      NX = len(keyX);\r\n    } else {\r\n      minX =\
    \ (X.empty() ? 0 : MIN(X));\r\n      NX = (X.empty() ? 1 : MAX(X) - minX + 1);\r\
    \n    }\r\n\r\n    log = 0;\r\n    while ((1 << log) < NX) ++log;\r\n    size\
    \ = (1 << log);\r\n\r\n    vc<int> IX(N);\r\n    FOR(i, N) IX[i] = xtoi(X[i]);\r\
    \n    indptr.assign(2 * size, 0);\r\n    for (auto i: IX) {\r\n      i += size;\r\
    \n      while (i) indptr[i]++, i /= 2;\r\n    }\r\n    indptr = cumsum<int>(indptr);\r\
    \n    dat.assign(2 * indptr.back(), MX::unit());\r\n    to_left.assign(indptr[size],\
    \ 0);\r\n\r\n    vc<int> ptr = indptr;\r\n    vc<int> I = argsort(Y);\r\n    pos.resize(N);\r\
    \n    FOR(i, N) pos[I[i]] = i;\r\n    for (auto raw_idx: I) {\r\n      int i =\
    \ IX[raw_idx] + size;\r\n      int j = -1;\r\n      while (i) {\r\n        int\
    \ p = ptr[i];\r\n        ptr[i]++;\r\n        dat[indptr[i + 1] + p] = wt[raw_idx];\r\
    \n        if (j != -1) { to_left[p] = (j % 2 == 0); }\r\n        j = i, i /= 2;\r\
    \n      }\r\n    }\r\n    to_left = cumsum<int>(to_left);\r\n\r\n    FOR(i, 2\
    \ * size) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n      FOR_R(j, 1, n) {\r\n        dat[off + j] = MX::op(dat[off + 2 * j + 0],\
    \ dat[off + 2 * j + 1]);\r\n      }\r\n    }\r\n    all_Y = Y;\r\n    sort(all(all_Y));\r\
    \n  }\r\n\r\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\r\
    \n  void multiply(int raw_idx, S val) {\r\n    int i = 1, p = pos[raw_idx];\r\n\
    \    while (1) {\r\n      multiply_i(i, p - indptr[i], val);\r\n      if (i >=\
    \ size) break;\r\n      int lc = to_left[p] - to_left[indptr[i]];\r\n      int\
    \ rc = (p - indptr[i]) - lc;\r\n      if (to_left[p + 1] - to_left[p]) {\r\n \
    \       p = indptr[2 * i + 0] + lc;\r\n        i = 2 * i + 0;\r\n      } else\
    \ {\r\n        p = indptr[2 * i + 1] + rc;\r\n        i = 2 * i + 1;\r\n     \
    \ }\r\n    }\r\n  }\r\n\r\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\
    \u306E index\r\n  void set(int raw_idx, S val) {\r\n    int i = 1, p = pos[raw_idx];\r\
    \n    while (1) {\r\n      set_i(i, p - indptr[i], val);\r\n      if (i >= size)\
    \ break;\r\n      int lc = to_left[p] - to_left[indptr[i]];\r\n      int rc =\
    \ (p - indptr[i]) - lc;\r\n      if (to_left[p + 1] - to_left[p]) {\r\n      \
    \  p = indptr[2 * i + 0] + lc;\r\n        i = 2 * i + 0;\r\n      } else {\r\n\
    \        p = indptr[2 * i + 1] + rc;\r\n        i = 2 * i + 1;\r\n      }\r\n\
    \    }\r\n  }\r\n\r\n  S prod(XY lx, XY rx, XY ly, XY ry) {\r\n    assert(lx <=\
    \ rx && ly <= ry);\r\n    int L = xtoi(lx), R = xtoi(rx);\r\n    S res = MX::unit();\r\
    \n    auto dfs = [&](auto& dfs, int i, int l, int r, int a, int b) -> void {\r\
    \n      if (a == b || R <= l || r <= L) return;\r\n      if (L <= l && r <= R)\
    \ {\r\n        res = MX::op(res, prod_i(i, a, b));\r\n        return;\r\n    \
    \  }\r\n      int la = to_left[indptr[i] + a] - to_left[indptr[i]];\r\n      int\
    \ ra = a - la;\r\n      int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\r\
    \n      int rb = b - lb;\r\n      int m = (l + r) / 2;\r\n      dfs(dfs, 2 * i\
    \ + 0, l, m, la, lb);\r\n      dfs(dfs, 2 * i + 1, m, r, ra, rb);\r\n    };\r\n\
    \    dfs(dfs, 1, 0, size, LB(all_Y, ly), LB(all_Y, ry));\r\n    return res;\r\n\
    \  }\r\n\r\n  // \u77E9\u5F62\u5185\u306E\u5168\u70B9\u3092\u6570\u3048\u308B\
    , NlogN\r\n  int count(XY lx, XY rx, XY ly, XY ry) {\r\n    assert(lx <= rx &&\
    \ ly <= ry);\r\n    int L = xtoi(lx), R = xtoi(rx);\r\n    int res = 0;\r\n  \
    \  auto dfs = [&](auto& dfs, int i, int l, int r, int a, int b) -> void {\r\n\
    \      if (a == b || R <= l || r <= L) return;\r\n      if (L <= l && r <= R)\
    \ {\r\n        res += b - a;\r\n        return;\r\n      }\r\n      int la = to_left[indptr[i]\
    \ + a] - to_left[indptr[i]];\r\n      int ra = a - la;\r\n      int lb = to_left[indptr[i]\
    \ + b] - to_left[indptr[i]];\r\n      int rb = b - lb;\r\n      int m = (l + r)\
    \ / 2;\r\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\r\n      dfs(dfs, 2 * i + 1,\
    \ m, r, ra, rb);\r\n    };\r\n    dfs(dfs, 1, 0, size, LB(all_Y, ly), LB(all_Y,\
    \ ry));\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  inline int xtoi(XY x) {\r\
    \n    if constexpr (SMALL_X) return clamp<XY>(x - minX, 0, NX);\r\n    return\
    \ LB(keyX, x);\r\n  }\r\n\r\n  S prod_i(int i, int a, int b) {\r\n    int LID\
    \ = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    int off = 2 * LID;\r\n  \
    \  int L = n + a, R = n + b;\r\n    S val = MX::unit();\r\n    while (L < R) {\r\
    \n      if (L & 1) val = MX::op(val, dat[off + (L++)]);\r\n      if (R & 1) val\
    \ = MX::op(dat[off + (--R)], val);\r\n      L >>= 1, R >>= 1;\r\n    }\r\n   \
    \ return val;\r\n  }\r\n  void multiply_i(int i, int j, S val) {\r\n    int LID\
    \ = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    int off = 2 * LID;\r\n  \
    \  j += n;\r\n    while (j) {\r\n      dat[off + j] = MX::op(dat[off + j], val);\r\
    \n      j >>= 1;\r\n    }\r\n  }\r\n  void set_i(int i, int j, S val) {\r\n  \
    \  int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    int off = 2 * LID;\r\
    \n    j += n;\r\n    dat[off + j] = val;\r\n    while (j > 1) {\r\n      j /=\
    \ 2;\r\n      dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\r\
    \n    }\r\n  }\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }\r\
    \n  static constexpr X unit() { return infty<E>; }\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n#line 7 \"test/1_mytest/seg2d.test.cpp\"\n\nvoid test()\
    \ {\n  FOR(N, 100) {\n    FOR(Q, 100) {\n      vc<int> X(N), Y(N), val(N);\n \
    \     FOR(i, N) X[i] = RNG(0, 5), Y[i] = RNG(0, 5), val[i] = RNG(0, 100);\n  \
    \    SegTree_2D<Monoid_Min<int>, int, true> seg(X, Y, val);\n      FOR(Q) {\n\
    \        int t = RNG(0, 3);\n        if (N == 0) t = 2;\n        if (t == 0) {\n\
    \          int i = RNG(0, N);\n          val[i] = RNG(0, 100);\n          seg.set(i,\
    \ val[i]);\n        }\n        if (t == 1) {\n          int i = RNG(0, N);\n \
    \         int x = RNG(0, 100);\n          chmin(val[i], x);\n          seg.multiply(i,\
    \ val[i]);\n        }\n        if (t == 2) {\n          int a = RNG(0, 5), b =\
    \ RNG(0, 5), c = RNG(0, 5), d = RNG(0, 5);\n          if (a > b) swap(a, b);\n\
    \          if (c > d) swap(c, d);\n          int ans = infty<int>;\n         \
    \ FOR(i, N) {\n            if (a <= X[i] && X[i] < b && c <= Y[i] && Y[i] < d)\n\
    \              chmin(ans, val[i]);\n          }\n          assert(ans == seg.prod(a,\
    \ b, c, d));\n        }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"ds/segtree/segtree_2d.hpp\"\n#include\
    \ \"alg/monoid/min.hpp\"\n\nvoid test() {\n  FOR(N, 100) {\n    FOR(Q, 100) {\n\
    \      vc<int> X(N), Y(N), val(N);\n      FOR(i, N) X[i] = RNG(0, 5), Y[i] = RNG(0,\
    \ 5), val[i] = RNG(0, 100);\n      SegTree_2D<Monoid_Min<int>, int, true> seg(X,\
    \ Y, val);\n      FOR(Q) {\n        int t = RNG(0, 3);\n        if (N == 0) t\
    \ = 2;\n        if (t == 0) {\n          int i = RNG(0, N);\n          val[i]\
    \ = RNG(0, 100);\n          seg.set(i, val[i]);\n        }\n        if (t == 1)\
    \ {\n          int i = RNG(0, N);\n          int x = RNG(0, 100);\n          chmin(val[i],\
    \ x);\n          seg.multiply(i, val[i]);\n        }\n        if (t == 2) {\n\
    \          int a = RNG(0, 5), b = RNG(0, 5), c = RNG(0, 5), d = RNG(0, 5);\n \
    \         if (a > b) swap(a, b);\n          if (c > d) swap(c, d);\n         \
    \ int ans = infty<int>;\n          FOR(i, N) {\n            if (a <= X[i] && X[i]\
    \ < b && c <= Y[i] && Y[i] < d)\n              chmin(ans, val[i]);\n         \
    \ }\n          assert(ans == seg.prod(a, b, c, d));\n        }\n      }\n    }\n\
    \  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - ds/segtree/segtree_2d.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/1_mytest/seg2d.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 06:34:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/seg2d.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/seg2d.test.cpp
- /verify/test/1_mytest/seg2d.test.cpp.html
title: test/1_mytest/seg2d.test.cpp
---
