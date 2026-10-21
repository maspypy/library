---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree_2d.hpp
    title: ds/segtree/segtree_2d.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/1_mytest/seg2d.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    #if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#endif\n#else  // MASPY_TEMPLATE_BODY\n\
    #include <bits/stdc++.h>\n#include <cassert>\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false =\
    \ false;\n\ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<i128>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i128>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing pq_max = priority_queue<T>;\ntemplate <class T>\nusing\
    \ pq_min = priority_queue<T, vector<T>, greater<T>>;\n\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n \
    \     h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR1_R(a)\
    \ for (ll i = ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a)\
    \ - 1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload3(__VA_ARGS__,\
    \ FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R,\
    \ FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define all(x) (x).begin(), (x).end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define stoi stoll\n\n// require y > 0\ntemplate <typename T>\nT floor(T x, T\
    \ y) {\n  return x / y - (x % y < 0);\n}\n\n// require y > 0\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return (x / y) + (x % y > 0);\n}\n\n// require y >\
    \ 0\ntemplate <typename T>\nT bmod(T x, T y) {\n  T r = x % y;\n  return (r <\
    \ 0 ? r + y : r);\n}\n\n// require y > 0\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = x / y, r = x % y;\n  if (r < 0) --q, r += y;\n  return {q,\
    \ r};\n}\n\nconstexpr auto TEN = [] {\n  array<u64, 20> A{};\n  A[0] = 1;\n  for\
    \ (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];\n  return A;\n}();\n\ntemplate\
    \ <typename T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(),\
    \ A.end(), T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    template <class C, class T>\ninline long long LB(const C &c, const T &x) {\n \
    \ return lower_bound(c.begin(), c.end(), x) - c.begin();\n}\ntemplate <class C,\
    \ class T>\ninline long long UB(const C &c, const T &x) {\n  return upper_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n\
    \  que.pop_front();\n  return a;\n}\ntemplate <class T, class Container, class\
    \ Compare>\nT POP(priority_queue<T, Container, Compare> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    i128 binary_search(F check, i128 ok, i128 ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (1) {\n    i128 x = (ok + ng) / 2;\n    if (x ==\
    \ ok || x == ng) break;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\
    \ntemplate <typename F>\ndouble binary_search_real(F check, double ok, double\
    \ ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class\
    \ S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a, b);\n  bool changed\
    \ = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n  bool changed = (c !=\
    \ a);\n  a = c;\n  return changed;\n}\n\n// bit operations\nint popcnt(int x)\
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
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ T>\nstruct all_bit {\n  static_assert(is_integral<T>::value);\n  T s;\n  all_bit(T\
    \ s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ T>\nstruct all_subset {\n  static_assert(is_integral<T>::value);\n  T s;\n \
    \ all_subset(T s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s, t;\n \
    \   bool done = false;\n    T operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n      [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  first.reserve(first.size()\
    \ + (others.size() + ... + 0));\n  (first.insert(first.end(), others.begin(),\
    \ others.end()), ...);\n}\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T,\
    \ i128>, int> = 0>\nconstexpr i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\n\
    constexpr i128 gcd(i128 a, i128 b) {\n  while (b != 0) {\n    i128 c = a % b;\n\
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#endif  // MASPY_TEMPLATE_BODY\n\
    #line 3 \"test/1_mytest/seg2d.test.cpp\"\n\n#line 1 \"random/base.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/random/base.hpp\n\nu64 RNG_64()\
    \ {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n     \
    \                 chrono::high_resolution_clock::now().time_since_epoch())\n \
    \                         .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"ds/segtree/segtree_2d.hpp\"\n\
    // Source: https://github.com/maspypy/library/blob/main/ds/segtree/segtree_2d.hpp\n\
    // \u70B9\u306E\u91CD\u8907\u304C\u3042\u3063\u3066\u3082\u5225\u306E\u70B9\u3068\
    \u3057\u3066 set \u306A\u3069\u304C\u3055\u308C\u308B\ntemplate <typename Monoid,\
    \ typename XY, bool SMALL_X = false>\nstruct SegTree_2D {\n  using MX = Monoid;\n\
    \  using S = typename MX::value_type;\n  static_assert(MX::commute);\n  int N;\n\
    \  // X to idx\n  vc<XY> keyX;\n  int minX;\n  // top node \u306E\u70B9\u5217\n\
    \  vc<XY> all_Y;\n  vc<int> pos;\n  // segtree data\n  int NX, log, size;\n  vc<int>\
    \ indptr;\n  vc<S> dat;\n  // fractional cascading\n  vc<int> to_left;\n\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y)\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY, XY, S> {\n\
    \          return {X[i], Y[i], MX::id()};\n        }) {}\n\n  SegTree_2D(vc<XY>&\
    \ X, vc<XY>& Y, vc<S>& vals)\n      : SegTree_2D(len(X), [&](int i) -> tuple<XY,\
    \ XY, S> {\n          return {X[i], Y[i], vals[i]};\n        }) {}\n\n  // f(i)\
    \ = (x,y,val)\n  template <typename F>\n  SegTree_2D(int N, F f) {\n    vc<XY>\
    \ X(N), Y(N);\n    vc<S> wt(N);\n    FOR(i, N) {\n      auto [a, b, c] = f(i);\n\
    \      X[i] = a, Y[i] = b, wt[i] = c;\n    }\n    if (!SMALL_X) {\n      keyX\
    \ = X;\n      UNIQUE(keyX);\n      NX = len(keyX);\n    } else {\n      minX =\
    \ (X.empty() ? 0 : MIN(X));\n      NX = (X.empty() ? 1 : MAX(X) - minX + 1);\n\
    \    }\n\n    log = 0;\n    while ((1 << log) < NX) ++log;\n    size = (1 << log);\n\
    \n    vc<int> IX(N);\n    FOR(i, N) IX[i] = xtoi(X[i]);\n    indptr.assign(2 *\
    \ size, 0);\n    for (auto i: IX) {\n      i += size;\n      while (i) indptr[i]++,\
    \ i /= 2;\n    }\n    indptr = cumsum<int>(indptr);\n    dat.assign(2 * indptr.back(),\
    \ MX::id());\n    to_left.assign(indptr[size], 0);\n\n    vc<int> ptr = indptr;\n\
    \    vc<int> I = argsort(Y);\n    pos.resize(N);\n    FOR(i, N) pos[I[i]] = i;\n\
    \    for (auto raw_idx: I) {\n      int i = IX[raw_idx] + size;\n      int j =\
    \ -1;\n      while (i) {\n        int p = ptr[i];\n        ptr[i]++;\n       \
    \ dat[indptr[i + 1] + p] = wt[raw_idx];\n        if (j != -1) { to_left[p] = (j\
    \ % 2 == 0); }\n        j = i, i /= 2;\n      }\n    }\n    to_left = cumsum<int>(to_left);\n\
    \n    FOR(i, 2 * size) {\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \      FOR_R(j, 1, n) {\n        dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off\
    \ + 2 * j + 1]);\n      }\n    }\n    all_Y = Y;\n    sort(all(all_Y));\n  }\n\
    \n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void multiply(int\
    \ raw_idx, S val) {\n    int i = 1, p = pos[raw_idx];\n    while (1) {\n     \
    \ multiply_i(i, p - indptr[i], val);\n      if (i >= size) break;\n      int lc\
    \ = to_left[p] - to_left[indptr[i]];\n      int rc = (p - indptr[i]) - lc;\n \
    \     if (to_left[p + 1] - to_left[p]) {\n        p = indptr[2 * i + 0] + lc;\n\
    \        i = 2 * i + 0;\n      } else {\n        p = indptr[2 * i + 1] + rc;\n\
    \        i = 2 * i + 1;\n      }\n    }\n  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\
    \u305F\u70B9\u7FA4\u306E index\n  void set(int raw_idx, S val) {\n    int i =\
    \ 1, p = pos[raw_idx];\n    while (1) {\n      set_i(i, p - indptr[i], val);\n\
    \      if (i >= size) break;\n      int lc = to_left[p] - to_left[indptr[i]];\n\
    \      int rc = (p - indptr[i]) - lc;\n      if (to_left[p + 1] - to_left[p])\
    \ {\n        p = indptr[2 * i + 0] + lc;\n        i = 2 * i + 0;\n      } else\
    \ {\n        p = indptr[2 * i + 1] + rc;\n        i = 2 * i + 1;\n      }\n  \
    \  }\n  }\n\n  S prod(XY lx, XY rx, XY ly, XY ry) {\n    assert(lx <= rx && ly\
    \ <= ry);\n    int L = xtoi(lx), R = xtoi(rx);\n    S res = MX::id();\n    auto\
    \ dfs = [&](auto& dfs, int i, int l, int r, int a, int b) -> void {\n      if\
    \ (a == b || R <= l || r <= L) return;\n      if (L <= l && r <= R) {\n      \
    \  res = MX::op(res, prod_i(i, a, b));\n        return;\n      }\n      int la\
    \ = to_left[indptr[i] + a] - to_left[indptr[i]];\n      int ra = a - la;\n   \
    \   int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\n      int rb = b -\
    \ lb;\n      int m = (l + r) / 2;\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\n\
    \      dfs(dfs, 2 * i + 1, m, r, ra, rb);\n    };\n    dfs(dfs, 1, 0, size, LB(all_Y,\
    \ ly), LB(all_Y, ry));\n    return res;\n  }\n\n  // \u77E9\u5F62\u5185\u306E\u5168\
    \u70B9\u3092\u6570\u3048\u308B, NlogN\n  int count(XY lx, XY rx, XY ly, XY ry)\
    \ {\n    assert(lx <= rx && ly <= ry);\n    int L = xtoi(lx), R = xtoi(rx);\n\
    \    int res = 0;\n    auto dfs = [&](auto& dfs, int i, int l, int r, int a, int\
    \ b) -> void {\n      if (a == b || R <= l || r <= L) return;\n      if (L <=\
    \ l && r <= R) {\n        res += b - a;\n        return;\n      }\n      int la\
    \ = to_left[indptr[i] + a] - to_left[indptr[i]];\n      int ra = a - la;\n   \
    \   int lb = to_left[indptr[i] + b] - to_left[indptr[i]];\n      int rb = b -\
    \ lb;\n      int m = (l + r) / 2;\n      dfs(dfs, 2 * i + 0, l, m, la, lb);\n\
    \      dfs(dfs, 2 * i + 1, m, r, ra, rb);\n    };\n    dfs(dfs, 1, 0, size, LB(all_Y,\
    \ ly), LB(all_Y, ry));\n    return res;\n  }\n\nprivate:\n  inline int xtoi(XY\
    \ x) {\n    if constexpr (SMALL_X) return clamp<XY>(x - minX, 0, NX);\n    return\
    \ LB(keyX, x);\n  }\n\n  S prod_i(int i, int a, int b) {\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    int off = 2 * LID;\n    int L = n + a, R\
    \ = n + b;\n    S val = MX::id();\n    while (L < R) {\n      if (L & 1) val =\
    \ MX::op(val, dat[off + (L++)]);\n      if (R & 1) val = MX::op(dat[off + (--R)],\
    \ val);\n      L >>= 1, R >>= 1;\n    }\n    return val;\n  }\n  void multiply_i(int\
    \ i, int j, S val) {\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \    int off = 2 * LID;\n    j += n;\n    while (j) {\n      dat[off + j] = MX::op(dat[off\
    \ + j], val);\n      j >>= 1;\n    }\n  }\n  void set_i(int i, int j, S val) {\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    int off = 2 * LID;\n\
    \    j += n;\n    dat[off + j] = val;\n    while (j > 1) {\n      j /= 2;\n  \
    \    dat[off + j] = MX::op(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);\n    }\n\
    \  }\n};\n#line 1 \"alg/monoid/min.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/min.hpp\n\
    // require: all values x satisfy x <= infty<E>\ntemplate <typename E>\nstruct\
    \ Monoid_Min {\n  using X = E;\n  using value_type = X;\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return min(x, y); }\n  static constexpr\
    \ X id() { return infty<E>; }\n  static constexpr bool commute = true;\n};\n#line\
    \ 7 \"test/1_mytest/seg2d.test.cpp\"\n\nvoid test() {\n  FOR(N, 100) {\n    FOR(Q,\
    \ 100) {\n      vc<int> X(N), Y(N), val(N);\n      FOR(i, N) X[i] = RNG(0, 5),\
    \ Y[i] = RNG(0, 5), val[i] = RNG(0, 100);\n      SegTree_2D<Monoid_Min<int>, int,\
    \ true> seg(X, Y, val);\n      FOR(Q) {\n        int t = RNG(0, 3);\n        if\
    \ (N == 0) t = 2;\n        if (t == 0) {\n          int i = RNG(0, N);\n     \
    \     val[i] = RNG(0, 100);\n          seg.set(i, val[i]);\n        }\n      \
    \  if (t == 1) {\n          int i = RNG(0, N);\n          int x = RNG(0, 100);\n\
    \          chmin(val[i], x);\n          seg.multiply(i, val[i]);\n        }\n\
    \        if (t == 2) {\n          int a = RNG(0, 5), b = RNG(0, 5), c = RNG(0,\
    \ 5), d = RNG(0, 5);\n          if (a > b) swap(a, b);\n          if (c > d) swap(c,\
    \ d);\n          int ans = infty<int>;\n          FOR(i, N) {\n            if\
    \ (a <= X[i] && X[i] < b && c <= Y[i] && Y[i] < d)\n              chmin(ans, val[i]);\n\
    \          }\n          assert(ans == seg.prod(a, b, c, d));\n        }\n    \
    \  }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n\
    }\n"
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
  timestamp: '2026-10-22 01:32:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/seg2d.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/seg2d.test.cpp
- /verify/test/1_mytest/seg2d.test.cpp.html
title: test/1_mytest/seg2d.test.cpp
---
