---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
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
  bundledCode: "#line 1 \"test/mytest/wavelet_matrix.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll> = ll(infty<int>)\
    \ * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate\
    \ <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128>\
    \ = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr double infty<double>\
    \ = infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n\
    \  vc<pair<u32, u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0,\
    \ 0}); }\n\n  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void\
    \ build() {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool\
    \ f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1)\
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n#line 2 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\n// \u5EA7\u5727\u3059\u308B\u304B\u3069\u3046\u304B\u3092 COMPRESS \u3067\
    \u6307\u5B9A\u3059\u308B\r\n// xor \u7684\u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\
    \u5834\u5408\u306B\u306F\u3001\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\
    \ log \u3092\u6E21\u3059\u3053\u3068\r\ntemplate <typename T, bool COMPRESS, bool\
    \ USE_SUM>\r\nstruct Wavelet_Matrix {\r\n  int N, lg;\r\n  vector<int> mid;\r\n\
    \  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n  bool set_log;\r\n  vvc<T> cumsum;\r\
    \n\r\n  Wavelet_Matrix() {}\r\n\r\n  // \u548C\u3092\u4F7F\u308F\u306A\u3044\u306A\
    \u3089\u3001SUM_data \u306F\u7A7A\u3067\u3088\u3044\r\n  Wavelet_Matrix(vc<T>\
    \ A, vc<T> SUM_data = {}, int log = -1) {\r\n    build(A, SUM_data, log);\r\n\
    \  }\r\n\r\n  void build(vc<T> A, vc<T> SUM_data = {}, int log = -1) {\r\n   \
    \ if constexpr (USE_SUM) { assert(len(SUM_data) == len(A)); }\r\n    N = len(A),\
    \ lg = log, set_log = (log != -1);\r\n    if (N == 0) {\r\n      lg = 0;\r\n \
    \     return;\r\n    }\r\n    vc<T>& S = SUM_data;\r\n    if (COMPRESS) {\r\n\
    \      assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\
    \n      for (auto&& i: I) {\r\n        if (key.empty() || key.back() != A[i])\
    \ key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\
    \n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg),\
    \ bv.assign(lg, Bit_Vector(N));\r\n    if constexpr (USE_SUM) cumsum.assign(1\
    \ + lg, vc<T>(N + 1, 0));\r\n    S.resize(N);\r\n    vc<T> A0(N), A1(N);\r\n \
    \   vc<T> S0(N), S1(N);\r\n    FOR_R(d, -1, lg) {\r\n      int p0 = 0, p1 = 0;\r\
    \n      if constexpr (USE_SUM) {\r\n        FOR(i, N) { cumsum[d + 1][i + 1] =\
    \ cumsum[d + 1][i] + S[i]; }\r\n      }\r\n      if (d == -1) break;\r\n     \
    \ FOR(i, N) {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) {\r\n  \
    \        if constexpr (USE_SUM) S0[p0] = S[i];\r\n          A0[p0++] = A[i];\r\
    \n        } else {\r\n          if constexpr (USE_SUM) S1[p1] = S[i];\r\n    \
    \      bv[d].set(i), A1[p1++] = A[i];\r\n        }\r\n      }\r\n      mid[d]\
    \ = p0;\r\n      bv[d].build();\r\n      swap(A, A0), swap(S, S0);\r\n      FOR(i,\
    \ p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];\r\n    }\r\n  }\r\n\r\n  // [L,R)\
    \ x [a,b), (cnt, monoid value)\r\n  pair<int, T> range_cnt_sum(int L, int R, T\
    \ a, T b, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if\
    \ (a == b) return {0, 0};\r\n    int cnt = 0;\r\n    T sm = 0;\r\n    auto dfs\
    \ = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {\r\n      if (rx\
    \ <= a || b <= lx) return;\r\n      if (a <= lx && rx <= b) {\r\n        cnt +=\
    \ R - L, sm += get(d, L, R);\r\n        return;\r\n      }\r\n      --d;\r\n \
    \     T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx),\
    \ dfs(dfs, d, l1, r1, mx, rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) <<\
    \ lg);\r\n    return {cnt, sm};\r\n  }\r\n\r\n  // smallest k, sum of [0,k)\r\n\
    \  pair<T, T> kth_value_sum(int L, int R, int k, T xor_val = 0) {\r\n    assert(0\
    \ <= k && k <= R - L);\r\n    if (k == R - L) { return {infty<T>, sum_all(L, R)};\
    \ }\r\n    if (L == R) return {infty<T>, 0};\r\n    if (xor_val != 0) assert(set_log);\r\
    \n    T sm = 0, val = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      //\
    \ \u3044\u307E\u5E45 d+1 \u306E trie node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\
    \u3053\u308D\u306B\u884C\u304F\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      if (k < r0 - l0) {\r\n      \
    \  L = l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, val |= T(1) << d,\
    \ L = l1, R = r1;\r\n        if constexpr (USE_SUM) sm += get(d, l0, r0);\r\n\
    \      }\r\n    }\r\n    if constexpr (USE_SUM) sm += get(0, L, L + k);\r\n  \
    \  if (COMPRESS) val = key[val];\r\n\r\n    return {val, sm};\r\n  }\r\n\r\n \
    \ int count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return range_cnt_sum(L,\
    \ R, a, b, xor_val).fi;\r\n  }\r\n  T sum(int L, int R, T a, T b, T xor_val =\
    \ 0) {\r\n    return range_cnt_sum(L, R, a, b, xor_val).se;\r\n  }\r\n  T kth(int\
    \ L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k && k < R - L);\r\n  \
    \  return kth_value_sum(L, R, k, xor_val).fi;\r\n  }\r\n\r\n  // x \u4EE5\u4E0A\
    \r\n  T next(int L, int R, T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\
    \n    if (L == R) return infty<T>;\r\n    T ans = infty<T>;\r\n\r\n    auto dfs\
    \ = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {\r\n      if (ans\
    \ <= lx || L == R || rx <= x) return;\r\n      if (d == 0) {\r\n        chmin(ans,\
    \ lx);\r\n        return;\r\n      }\r\n      --d;\r\n      T mx = (lx + rx) /\
    \ 2;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\r\n      int l1\
    \ = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d & 1) swap(l0,\
    \ l1), swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1,\
    \ mx, rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\r\n    return ans;\r\
    \n  }\r\n\r\n  // x \u4EE5\u4E0A\r\n  T prev(int L, int R, T x, T xor_val = 0)\
    \ {\r\n    if (xor_val != 0) assert(set_log);\r\n    if (L == R) return infty<T>;\r\
    \n    static_assert(is_same_v<T, int> || is_same_v<T, ll>);\r\n    T ans = -1;\r\
    \n\r\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {\r\
    \n      if ((rx - 1) <= ans || L == R || x < lx) return;\r\n      if (d == 0)\
    \ {\r\n        chmin(ans, lx);\r\n        return;\r\n      }\r\n      --d;\r\n\
    \      T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      dfs(dfs, d, l1, r1, mx, rx),\
    \ dfs(dfs, d, l0, r0, lx, mx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) <<\
    \ lg);\r\n    return ans;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\
    \u3001[L, R) \u306E\u4E2D\u3067\u4E2D\u592E\u5024\u3002\r\n  // LOWER = true\uFF1A\
    \u4E0B\u5074\u4E2D\u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\r\
    \n  T median(bool UPPER, int L, int R, T xor_val = 0) {\r\n    int n = R - L;\r\
    \n    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return kth(L, R, k, xor_val);\r\
    \n  }\r\n\r\n  T sum_all(int L, int R) { return get(lg, L, R); }\r\n\r\n  // check(cnt,\
    \ prefix sum) \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\u306E\
    \ (cnt, sum)\r\n  template <typename F>\r\n  pair<int, T> max_right(F check, int\
    \ L, int R, T xor_val = 0) {\r\n    assert(check(0, 0));\r\n    if (xor_val !=\
    \ 0) assert(set_log);\r\n    if (L == R) return {0, 0};\r\n    if (check(R - L,\
    \ get(lg, L, R))) return {R - L, get(lg, L, R)};\r\n    int cnt = 0;\r\n    T\
    \ sm = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      if\
    \ (check(cnt + r0 - l0, sm + get(d, l0, r0))) {\r\n        cnt += r0 - l0, sm\
    \ += get(d, l0, r0);\r\n        L = l1, R = r1;\r\n      } else {\r\n        L\
    \ = l0, R = r0;\r\n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int\
    \ k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0,\r\n       \
    \ R - L);\r\n    cnt += k, sm += get(0, L, L + k);\r\n    return {cnt, sm};\r\n\
    \  }\r\n\r\nprivate:\r\n  inline T get(int d, int L, int R) {\r\n    if constexpr\
    \ (USE_SUM) cumsum[d][R] - cumsum[d][L];\r\n    return 0;\r\n  }\r\n};\n#line\
    \ 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 5 \"test/mytest/wavelet_matrix.test.cpp\"\
    \n\nvoid test_compress() {\n  int N = RNG(0, 64);\n  int MAX = RNG(2, 1 << 10);\n\
    \  vc<int> A(N);\n  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(MAX);\n  FOR(i, N) A[i]\
    \ = RNG(MAX);\n\n  Wavelet_Matrix<int, true> WM(A, X);\n\n  int Q = 100;\n  FOR(Q)\
    \ {\n    int L = RNG(0, max(1, N));\n    int R = RNG(0, max(1, N + 1));\n    if\
    \ (L > R) swap(L, R);\n    int lo = RNG(0, MAX);\n    int hi = RNG(0, MAX);\n\
    \    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int> B = {A.begin() + L, A.begin()\
    \ + R};\n    vc<int> Y = {X.begin() + L, X.begin() + R};\n\n    int t = RNG(0,\
    \ 5);\n    if (t == 0) { // count\n      int cnt = 0;\n      for (auto&& x: B)\n\
    \        if (lo <= x && x < hi) cnt += 1;\n      assert(WM.count(L, R, lo, hi)\
    \ == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = 0;\n      int k1 =\
    \ RNG(R - L + 1);\n      int k2 = RNG(R - L + 1);\n      if (k1 > k2) swap(k1,\
    \ k2);\n      auto I = argsort(B);\n      FOR(i, k1, k2) sm += Y[I[i]];\n    \
    \  assert(WM.sum(L, R, k1, k2) == sm);\n    }\n    if (t == 2) { // kth\n    \
    \  if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n   \
    \   assert(WM.kth(L, R, k) == B[k]);\n    }\n    if (t == 3) { // max_right\n\
    \      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n      int c = RNG(0, a\
    \ * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n          = [&](int cnt,\
    \ int sm) -> bool { return a * cnt + b * sm <= c; };\n      auto p = WM.max_right(check,\
    \ L, R);\n      int k = binary_search(\n          [&](int k) -> bool {\n     \
    \       int sm = WM.sum(L, R, 0, k);\n            return check(k, sm);\n     \
    \     },\n          0, R - L + 1);\n      int sm = WM.sum(L, R, 0, k);\n     \
    \ assert(p.fi == k && p.se == sm);\n    }\n    if (t == 4) { // k-th value and\
    \ sum\n      int k = RNG(0, R - L + 1);\n      B.eb(infty<int>);\n      auto I\
    \ = argsort(B);\n      int val = B[I[k]];\n      int sm = 0;\n      FOR(i, k)\
    \ sm += Y[I[i]];\n      auto p = WM.kth_value_and_sum(L, R, k);\n      assert(p.fi\
    \ == val && p.se == sm);\n    }\n  }\n}\n\nvoid test_not_compress() {\n  int N\
    \ = RNG(0, 64);\n  int log = RNG(1, 7);\n  int MAX = 1 << log;\n  vc<int> A(N);\n\
    \  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(0, MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n\
    \  Wavelet_Matrix<int, false> WM(A, X, log);\n\n  int Q = 100;\n  FOR(Q) {\n \
    \   int L = RNG(0, max(1, N));\n    int R = RNG(0, max(1, N + 1));\n    if (L\
    \ > R) swap(L, R);\n    int lo = RNG(0, MAX);\n    int hi = RNG(0, MAX);\n   \
    \ int xor_val = RNG(0, MAX);\n    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int>\
    \ B = {A.begin() + L, A.begin() + R};\n    vc<int> Y = {X.begin() + L, X.begin()\
    \ + R};\n    for (auto&& x: B) x ^= xor_val;\n\n    int t = RNG(0, 5);\n    if\
    \ (t == 0) { // count\n      int cnt = 0;\n      for (auto&& x: B) {\n       \
    \ if (lo <= x && x < hi) cnt += 1;\n      }\n      assert(WM.count(L, R, lo, hi,\
    \ xor_val) == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = 0;\n     \
    \ int k1 = RNG(R - L + 1);\n      int k2 = RNG(R - L + 1);\n      if (k1 > k2)\
    \ swap(k1, k2);\n      auto I = argsort(B);\n      FOR(i, k1, k2) sm += Y[I[i]];\n\
    \      assert(WM.sum(L, R, k1, k2, xor_val) == sm);\n    }\n    if (t == 2) {\
    \ // kth\n      if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n\
    \      assert(WM.kth(L, R, k, xor_val) == B[k]);\n    }\n    if (t == 3) { //\
    \ max_right\n      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n      int c\
    \ = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n         \
    \ = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };\n      auto\
    \ p = WM.max_right(check, L, R, xor_val);\n      int k = binary_search(\n    \
    \      [&](int k) -> bool {\n            int sm = WM.sum(L, R, 0, k, xor_val);\n\
    \            return check(k, sm);\n          },\n          0, R - L + 1);\n  \
    \    int sm = WM.sum(L, R, 0, k, xor_val);\n      assert(k == p.fi && sm == p.se);\n\
    \    }\n    if (t == 4) { // k-th value and sum\n      int k = RNG(0, R - L +\
    \ 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n      int val = B[I[k]];\n\
    \      int sm = 0;\n      FOR(i, k) sm += Y[I[i]];\n      auto p = WM.kth_value_and_sum(L,\
    \ R, k, xor_val);\n      assert(p.fi == val && p.se == sm);\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(1000) test_compress();\n  FOR(1000) test_not_compress();\n\
    \  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n#include \"random/base.hpp\"\
    \n\nvoid test_compress() {\n  int N = RNG(0, 64);\n  int MAX = RNG(2, 1 << 10);\n\
    \  vc<int> A(N);\n  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(MAX);\n  FOR(i, N) A[i]\
    \ = RNG(MAX);\n\n  Wavelet_Matrix<int, true> WM(A, X);\n\n  int Q = 100;\n  FOR(Q)\
    \ {\n    int L = RNG(0, max(1, N));\n    int R = RNG(0, max(1, N + 1));\n    if\
    \ (L > R) swap(L, R);\n    int lo = RNG(0, MAX);\n    int hi = RNG(0, MAX);\n\
    \    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int> B = {A.begin() + L, A.begin()\
    \ + R};\n    vc<int> Y = {X.begin() + L, X.begin() + R};\n\n    int t = RNG(0,\
    \ 5);\n    if (t == 0) { // count\n      int cnt = 0;\n      for (auto&& x: B)\n\
    \        if (lo <= x && x < hi) cnt += 1;\n      assert(WM.count(L, R, lo, hi)\
    \ == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = 0;\n      int k1 =\
    \ RNG(R - L + 1);\n      int k2 = RNG(R - L + 1);\n      if (k1 > k2) swap(k1,\
    \ k2);\n      auto I = argsort(B);\n      FOR(i, k1, k2) sm += Y[I[i]];\n    \
    \  assert(WM.sum(L, R, k1, k2) == sm);\n    }\n    if (t == 2) { // kth\n    \
    \  if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n   \
    \   assert(WM.kth(L, R, k) == B[k]);\n    }\n    if (t == 3) { // max_right\n\
    \      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n      int c = RNG(0, a\
    \ * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n          = [&](int cnt,\
    \ int sm) -> bool { return a * cnt + b * sm <= c; };\n      auto p = WM.max_right(check,\
    \ L, R);\n      int k = binary_search(\n          [&](int k) -> bool {\n     \
    \       int sm = WM.sum(L, R, 0, k);\n            return check(k, sm);\n     \
    \     },\n          0, R - L + 1);\n      int sm = WM.sum(L, R, 0, k);\n     \
    \ assert(p.fi == k && p.se == sm);\n    }\n    if (t == 4) { // k-th value and\
    \ sum\n      int k = RNG(0, R - L + 1);\n      B.eb(infty<int>);\n      auto I\
    \ = argsort(B);\n      int val = B[I[k]];\n      int sm = 0;\n      FOR(i, k)\
    \ sm += Y[I[i]];\n      auto p = WM.kth_value_and_sum(L, R, k);\n      assert(p.fi\
    \ == val && p.se == sm);\n    }\n  }\n}\n\nvoid test_not_compress() {\n  int N\
    \ = RNG(0, 64);\n  int log = RNG(1, 7);\n  int MAX = 1 << log;\n  vc<int> A(N);\n\
    \  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(0, MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n\
    \  Wavelet_Matrix<int, false> WM(A, X, log);\n\n  int Q = 100;\n  FOR(Q) {\n \
    \   int L = RNG(0, max(1, N));\n    int R = RNG(0, max(1, N + 1));\n    if (L\
    \ > R) swap(L, R);\n    int lo = RNG(0, MAX);\n    int hi = RNG(0, MAX);\n   \
    \ int xor_val = RNG(0, MAX);\n    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int>\
    \ B = {A.begin() + L, A.begin() + R};\n    vc<int> Y = {X.begin() + L, X.begin()\
    \ + R};\n    for (auto&& x: B) x ^= xor_val;\n\n    int t = RNG(0, 5);\n    if\
    \ (t == 0) { // count\n      int cnt = 0;\n      for (auto&& x: B) {\n       \
    \ if (lo <= x && x < hi) cnt += 1;\n      }\n      assert(WM.count(L, R, lo, hi,\
    \ xor_val) == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = 0;\n     \
    \ int k1 = RNG(R - L + 1);\n      int k2 = RNG(R - L + 1);\n      if (k1 > k2)\
    \ swap(k1, k2);\n      auto I = argsort(B);\n      FOR(i, k1, k2) sm += Y[I[i]];\n\
    \      assert(WM.sum(L, R, k1, k2, xor_val) == sm);\n    }\n    if (t == 2) {\
    \ // kth\n      if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n\
    \      assert(WM.kth(L, R, k, xor_val) == B[k]);\n    }\n    if (t == 3) { //\
    \ max_right\n      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n      int c\
    \ = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);\n      auto check\n         \
    \ = [&](int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };\n      auto\
    \ p = WM.max_right(check, L, R, xor_val);\n      int k = binary_search(\n    \
    \      [&](int k) -> bool {\n            int sm = WM.sum(L, R, 0, k, xor_val);\n\
    \            return check(k, sm);\n          },\n          0, R - L + 1);\n  \
    \    int sm = WM.sum(L, R, 0, k, xor_val);\n      assert(k == p.fi && sm == p.se);\n\
    \    }\n    if (t == 4) { // k-th value and sum\n      int k = RNG(0, R - L +\
    \ 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n      int val = B[I[k]];\n\
    \      int sm = 0;\n      FOR(i, k) sm += Y[I[i]];\n      auto p = WM.kth_value_and_sum(L,\
    \ R, k, xor_val);\n      assert(p.fi == val && p.se == sm);\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(1000) test_compress();\n  FOR(1000) test_not_compress();\n\
    \  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-05-03 02:10:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/wavelet_matrix.test.cpp
- /verify/test/mytest/wavelet_matrix.test.cpp.html
title: test/mytest/wavelet_matrix.test.cpp
---
