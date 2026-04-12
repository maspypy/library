---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/dummy.hpp
    title: alg/monoid/dummy.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':x:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':x:'
    path: ds/dummy_data_structure.hpp
    title: ds/dummy_data_structure.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: ds/static_range_product_group.hpp
    title: ds/static_range_product_group.hpp
  - icon: ':x:'
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
  bundledCode: "#line 1 \"test/1_mytest/wavelet_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n\
    #if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/wavelet_matrix.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n\
    \  int n;\n  bool prepared = 0;\n  vc<pair<u64, u32>> dat;\n  Bit_Vector(int n\
    \ = 0) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }\n  void set(int i) {\n \
    \   assert(!prepared && (0 <= i && i < n));\n    dat[i >> 6].fi |= u64(1) << (i\
    \ & 63);\n  }\n  void reset() {\n    fill(all(dat), pair<u64, u32>{0, 0});\n \
    \   prepared = 0;\n  }\n  void build() {\n    prepared = 1;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  bool operator[](int\
    \ i) { return dat[i >> 6].fi >> (i & 63) & 1; }\n  // [0, k) \u5185\u306E 1 \u306E\
    \u500B\u6570\n  int count_prefix(int k, bool f = true) {\n    assert(prepared);\n\
    \    auto [a, b] = dat[k >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k &\
    \ 63)) - 1));\n    return (f ? ret : k - ret);\n  }\n  int count(int L, int R,\
    \ bool f = true) {\n    return count_prefix(R, f) - count_prefix(L, f);\n  }\n\
    \  string to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i /\
    \ 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n#line 1 \"alg/monoid/dummy.hpp\"\
    \nstruct Monoid_Dummy {\n  using value_type = char;\n  static constexpr bool commute\
    \ = true;\n  static value_type op(value_type, value_type) { return 0; }\n  static\
    \ value_type unit() { return 0; }\n};\n#line 2 \"ds/dummy_data_structure.hpp\"\
    \n\nstruct Dummy_Data_Structure {\n  using MX = Monoid_Dummy;\n  using T = typename\
    \ MX::value_type;\n  void build(const vc<T>& A) {}\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\ntemplate <typename Y, typename SEGTREE = Dummy_Data_Structure>\r\nstruct\
    \ Wavelet_Matrix {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T = typename\
    \ Mono::value_type;\r\n  static_assert(Mono::commute);\r\n  static_assert(is_same_v<Y,\
    \ int> || is_same_v<Y, ll>);\r\n  int n = 0, log = 0;\r\n  vc<int> mid;\r\n  vc<Bit_Vector>\
    \ bv;\r\n  vc<SEGTREE> seg;\r\n\r\n  Wavelet_Matrix() = default;\r\n\r\n  // f(i)\
    \ = {A[i], dat[i]}\r\n  template <typename F>\r\n  Wavelet_Matrix(int n, F f,\
    \ int log = -1) {\r\n    build(n, f, log);\r\n  }\r\n  Wavelet_Matrix(const vc<Y>&\
    \ A, int log = -1) {\r\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\r\
    \n    build(\r\n        len(A), [&](int i) -> pair<Y, T> { return {A[i], Mono::unit()};\
    \ }, log);\r\n  }\r\n\r\n  template <typename F>\r\n  void build(int n, F f, int\
    \ log) {\r\n    this->n = n;\r\n    vc<Y> A(n);\r\n    vc<T> S(n);\r\n    FOR(i,\
    \ n) tie(A[i], S[i]) = f(i);\r\n    if (log == -1) {\r\n      log = (n == 0 ?\
    \ 0 : topbit(MAX(A)) + 1);\r\n    } else {\r\n      for (auto& x : A) assert(0\
    \ <= x && topbit(x) < log);\r\n    }\r\n    this->log = log;\r\n    if constexpr\
    \ (is_same_v<Y, int>) assert(0 <= log && log <= 30);\r\n    if constexpr (is_same_v<Y,\
    \ ll>) assert(0 <= log && log <= 62);\r\n    mid.resize(log), bv.assign(log, Bit_Vector(n));\r\
    \n    vc<Y> A0(n), A1(n);\r\n    vc<T> S0(n), S1(n);\r\n    seg.resize(log + 1);\r\
    \n    seg[log].build(S);\r\n    for (int d = log - 1; d >= 0; --d) {\r\n     \
    \ int p0 = 0, p1 = 0;\r\n      for (int i = 0; i < n; ++i) {\r\n        if (A[i]\
    \ >> d & 1) {\r\n          bv[d].set(i), A1[p1] = A[i], S1[p1] = S[i], p1++;\r\
    \n        } else {\r\n          A0[p0] = A[i], S0[p0] = S[i], p0++;\r\n      \
    \  }\r\n      }\r\n      swap(A, A0), swap(S, S0);\r\n      move(A1.begin(), A1.begin()\
    \ + p1, A.begin() + p0);\r\n      move(S1.begin(), S1.begin() + p1, S.begin()\
    \ + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\n    }\r\n  }\r\
    \n\r\n  tuple<int, int, int, int> get_subtree(int d, int L, int R) const {\r\n\
    \    assert(1 <= d && d <= log);\r\n    int a = bv[d - 1].count_prefix(L), b =\
    \ bv[d - 1].count_prefix(R);\r\n    return {L - a, R - b, mid[d - 1] + a, mid[d\
    \ - 1] + b};\r\n  }\r\n\r\n  template <typename F>\r\n  void work_point(F f, int\
    \ i) {\r\n    assert(0 <= i && i < n);\r\n    f(log, i);\r\n    FOR_R(d, log)\
    \ {\r\n      int a = bv[d].count_prefix(i);\r\n      if (bv[d][i]) {\r\n     \
    \   i = mid[d] + a;\r\n      } else {\r\n        i = i - a;\r\n      }\r\n   \
    \   f(d, i);\r\n    }\r\n  }\r\n\r\n  template <typename F>\r\n  void work_prefix(F\
    \ f, int L, int R, Y y) const {\r\n    assert(0 <= y && y <= Y(1) << log);\r\n\
    \    if (y == 0) return;\r\n    if (y == Y(1) << log) {\r\n      f(log, L, R);\r\
    \n      return;\r\n    }\r\n    FOR_R(d, log) {\r\n      auto [L0, R0, L1, R1]\
    \ = get_subtree(d + 1, L, R);\r\n      if (y >> d & 1) {\r\n        f(d, L0, R0);\r\
    \n        L = L1, R = R1;\r\n      } else {\r\n        L = L0, R = R0;\r\n   \
    \   }\r\n    }\r\n  }\r\n\r\n  template <typename F>\r\n  void work_range(F f,\
    \ int L, int R, Y y1, Y y2) const {\r\n    assert(0 <= y1 && y1 <= y2 && y2 <=\
    \ Y(1) << log);\r\n    if (y1 == 0) return work_prefix(f, L, R, y2);\r\n    auto\
    \ dfs = [&](auto& dfs, int d, int L, int R, Y y1, Y y2) -> void {\r\n      if\
    \ (y1 == y2) return;\r\n      if (y1 == 0 && y2 == Y(1) << d) {\r\n        f(d,\
    \ L, R);\r\n        return;\r\n      }\r\n      assert(d > 0);\r\n      auto [L0,\
    \ R0, L1, R1] = get_subtree(d, L, R);\r\n      Y m = (Y(1) << (d - 1));\r\n\r\n\
    \      if (y2 <= m) {\r\n        dfs(dfs, d - 1, L0, R0, y1, y2);\r\n      } else\
    \ if (y1 >= m) {\r\n        dfs(dfs, d - 1, L1, R1, y1 - m, y2 - m);\r\n     \
    \ } else {\r\n        dfs(dfs, d - 1, L0, R0, y1, m);\r\n        dfs(dfs, d -\
    \ 1, L1, R1, 0, y2 - m);\r\n      }\r\n    };\r\n    dfs(dfs, log, L, R, y1, y2);\r\
    \n  }\r\n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L, int R, Y y) const\
    \ {\r\n    int cnt = 0;\r\n    work_prefix([&](int d, int a, int b) { cnt += b\
    \ - a; }, L, R, y);\r\n    return cnt;\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n\
    \  int count(int L, int R, Y y1, Y y2) const {\r\n    return prefix_count(L, R,\
    \ y2) - prefix_count(L, R, y1);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  T prefix_prod(int\
    \ L, int R, Y y) const {\r\n    T ans = Mono::unit();\r\n    work_prefix(\r\n\
    \        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); },\
    \ L,\r\n        R, y);\r\n    return ans;\r\n  }\r\n  // [L,R) x [y1,y2)\r\n \
    \ T prod(int L, int R, Y y1, Y y2) const {\r\n    T ans = Mono::unit();\r\n  \
    \  work_range(\r\n        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a,\
    \ b)); }, L,\r\n        R, y1, y2);\r\n    return ans;\r\n  }\r\n  T prod_all(int\
    \ L, int R) const { return seg[log].prod(L, R); }\r\n\r\n  // [L,R) x [0,y)\r\n\
    \  pair<int, T> prefix_count_and_prod(int L, int R, Y y) const {\r\n    pair<int,\
    \ T> ans = {0, Mono::unit()};\r\n    work_prefix(\r\n        [&](int d, int a,\
    \ int b) {\r\n          ans.fi += b - a;\r\n          ans.se = Mono::op(ans.se,\
    \ seg[d].prod(a, b));\r\n        },\r\n        L, R, y);\r\n    return ans;\r\n\
    \  }\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R, Y\
    \ y1, Y y2) const {\r\n    pair<int, T> ans = {0, Mono::unit()};\r\n    work_range(\r\
    \n        [&](int d, int a, int b) {\r\n          ans.fi += b - a;\r\n       \
    \   ans.se = Mono::op(ans.se, seg[d].prod(a, b));\r\n        },\r\n        L,\
    \ R, y1, y2);\r\n    return ans;\r\n  }\r\n\r\n  Y kth(int L, int R, int k) const\
    \ {\r\n    assert(0 <= k && k < R - L);\r\n    Y ans = 0;\r\n    for (int d =\
    \ log - 1; d >= 0; --d) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d + 1,\
    \ L, R);\r\n      if (k < R0 - L0) {\r\n        L = L0, R = R0;\r\n      } else\
    \ {\r\n        ans |= Y(1) << d;\r\n        k -= R0 - L0, L = L1, R = R1;\r\n\
    \      }\r\n    }\r\n    return ans;\r\n  }\r\n\r\n  // y \u4EE5\u4E0A\u6700\u5C0F\
    \ OR 1<<log\r\n  Y next(int L, int R, Y y) const {\r\n    assert(0 <= y && y <=\
    \ (Y(1) << log));\r\n    int k = prefix_count(L, R, y);\r\n    return (k == R\
    \ - L ? Y(1) << log : kth(L, R, k));\r\n  }\r\n\r\n  // y \u4EE5\u4E0B\u6700\u5927\
    \ OR -1\r\n  Y prev(int L, int R, Y y) const {\r\n    assert(0 <= y && y <= (Y(1)\
    \ << log));\r\n    if (y == Y(1) << log) --y;\r\n    int k = prefix_count(L, R,\
    \ y + 1);\r\n    return (k == 0 ? -1 : kth(L, R, k - 1));\r\n  }\r\n\r\n  template\
    \ <bool upper>\r\n  Y median(int L, int R) const {\r\n    assert(0 <= L && L <\
    \ R && R <= n);\r\n    int k = (upper ? (R - L) / 2 : (R - L - 1) / 2);\r\n  \
    \  return kth(L, R, k);\r\n  }\r\n\r\n  void set(int i, T t) {\r\n    assert(0\
    \ <= i && i < n);\r\n    work_point([&](int d, int i) { seg[d].set(i, t); }, i);\r\
    \n  }\r\n  void multiply(int i, T t) {\r\n    assert(0 <= i && i < n);\r\n   \
    \ work_point([&](int d, int i) { seg[d].multiply(i, t); }, i);\r\n  }\r\n  void\
    \ add(int i, T t) {\r\n    assert(0 <= i && i < n);\r\n    work_point([&](int\
    \ d, int i) { seg[d].add(i, t); }, i);\r\n  }\r\n\r\n  // [L,R) x [0,y) \u3067\
    \u306E check(y, cnt, prod) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\r\
    \n  template <typename F>\r\n  tuple<Y, int, T> max_right(F check, int L, int\
    \ R) const {\r\n    int cnt = 0;\r\n    Y y = 0;\r\n    T t = Mono::unit();\r\n\
    \    assert(check(0, 0, Mono::unit()));\r\n    T t_all = seg[log].prod(L, R);\r\
    \n    if (check(Y(1) << log, R - L, t_all)) {\r\n      return {Y(1) << log, R\
    \ - L, t_all};\r\n    }\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      auto\
    \ [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n      Y y1 = y | Y(1) << d;\r\
    \n      int cnt1 = cnt + R0 - L0;\r\n      T t1 = Mono::op(t, seg[d].prod(L0,\
    \ R0));\r\n      if (check(y1, cnt1, t1)) {\r\n        y = y1, cnt = cnt1, t =\
    \ t1, L = L1, R = R1;\r\n      } else {\r\n        L = L0, R = R0;\r\n      }\r\
    \n    }\r\n    return {y, cnt, t};\r\n  }\r\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"ds/static_range_product_group.hpp\"\n\
    \ntemplate <typename Monoid>\nstruct Static_Range_Product_Group {\n  using MX\
    \ = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  vc<X> dat;\n  Static_Range_Product_Group()\
    \ {}\n  template <typename F>\n  Static_Range_Product_Group(int m, F f) {\n  \
    \  build(m, f);\n  }\n  Static_Range_Product_Group(vc<X>& A) {\n    build(len(A),\
    \ [&](int i) -> X { return A[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m;\n    dat.assign(n + 1, MX::unit());\n    for (int i =\
    \ 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], f(i));\n  }\n  void build(vc<X>&\
    \ A) {\n    n = len(A);\n    dat.assign(n + 1, MX::unit());\n    for (int i =\
    \ 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);\n  }\n  X prod(int l, int\
    \ r) { return MX::op(MX::inverse(dat[l]), dat[r]); }\n};\n\ntemplate <typename\
    \ T>\nusing Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;\n#line 2 \"\
    ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type = X;\n\
    \  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n);\
    \ }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n\
    \  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m,\
    \ [](int i) -> X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n  \
    \  FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  vc<int> prod_ids(int\
    \ L, int R) {\n    assert(0 <= L && L <= R && R <= n);\n    vc<int> I, J;\n  \
    \  L += size, R += size;\n    while (L < R) {\n      if (L & 1) I.eb(L++);\n \
    \     if (R & 1) J.eb(--R);\n      L >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n\
    \    concat(I, J);\n    return I;\n  }\n\n  X prod_all() { return dat[1]; }\n\n\
    \  template <class F>\n  int max_right(F check, int L) {\n    assert(0 <= L &&\
    \ L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n\
    \    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n   \
    \   if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n      \
    \    L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n            sm\
    \ = Monoid::op(sm, dat[L++]);\n          }\n        }\n        return L - size;\n\
    \      }\n      sm = Monoid::op(sm, dat[L++]);\n    } while ((L & -L) != L);\n\
    \    return n;\n  }\n\n  template <class F>\n  int min_left(F check, int R) {\n\
    \    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R == 0) return\
    \ 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n      --R;\n     \
    \ while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R], sm)))\
    \ {\n        while (R < size) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R--], sm);\n          }\n        }\n\
    \        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n \
    \   } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >>\
    \ k) + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 10 \"test/1_mytest/wavelet_matrix.test.cpp\"\
    \n\ntemplate <bool SMALL_Y, typename SEGTREE>\nvoid test(int N) {\n  int MAX =\
    \ RNG(2, 1 << 10);\n  vc<int> A(N);\n  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(MAX);\n\
    \  FOR(i, N) A[i] = RNG(MAX);\n\n  Wavelet_Matrix<int, false, SEGTREE> WM(A, X);\n\
    \  using Mono = typename SEGTREE::MX;\n\n  int Q = 100;\n  FOR(Q) {\n    int L\
    \ = RNG(0, max(1, N));\n    int R = RNG(0, max(1, N + 1));\n    if (L > R) swap(L,\
    \ R);\n    int lo = RNG(0, MAX);\n    int hi = RNG(0, MAX);\n    if (lo > hi)\
    \ swap(lo, hi);\n    ++hi;\n    vc<int> B = {A.begin() + L, A.begin() + R};\n\
    \    vc<int> Y = {X.begin() + L, X.begin() + R};\n    int t = RNG(0, 7);\n   \
    \ if (t == 0) { // count\n      int cnt = 0;\n      for (auto&& x: B)\n      \
    \  if (lo <= x && x < hi) cnt += 1;\n      assert(WM.count(L, R, lo, hi) == cnt);\n\
    \    }\n    if (t == 1) { // sm\n      int sm = Mono::unit();\n      FOR(i, L,\
    \ R) if (lo <= A[i] && A[i] < hi) sm = Mono::op(sm, X[i]);\n      assert(WM.prod(L,\
    \ R, lo, hi) == sm);\n    }\n    if (t == 2) { // kth\n      if (L == R) continue;\n\
    \      int k = RNG(R - L);\n      sort(all(B));\n      assert(WM.kth(L, R, k)\
    \ == B[k]);\n    }\n    if (is_same_v<Mono, Monoid_Add<int>> && t == 3) { // max_right\n\
    \      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n      int c = RNG(0, a\
    \ * (R - L) + b * MAX * (R - L) + 1);\n      auto check = [&](int cut, int cnt,\
    \ int sm) -> bool { return a * cnt + b * sm <= c; };\n      auto p = WM.max_right(check,\
    \ L, R);\n      int cnt = 0, sm = 0;\n      binary_search(\n          [&](int\
    \ y) -> bool {\n            auto [c, s] = WM.prefix_count_and_prod(L, R, y);\n\
    \            if (check(0, c, s)) cnt = c, sm = s;\n            return check(0,\
    \ c, s);\n          },\n          -10, MAX + 10);\n      assert(get<1>(p) == cnt\
    \ && get<2>(p) == sm);\n    }\n    if (t == 4) { // k-th value and prod\n    \
    \  int k = RNG(0, R - L + 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n\
    \      int val = B[I[k]];\n      int sm = Mono::unit();\n      FOR(i, k) sm =\
    \ Mono::op(sm, Y[I[i]]);\n      auto p = WM.kth_value_and_prod(L, R, k);\n   \
    \   assert(p.fi == val && p.se == sm);\n    }\n    if (t == 5) { // next\n   \
    \   int x = RNG(-1, MAX + 2);\n      int ans = infty<int>;\n      for (auto& b:\
    \ B) {\n        if (x <= b) chmin(ans, b);\n      }\n      assert(ans == WM.next(L,\
    \ R, x));\n    }\n    if (t == 6) { // prev\n      int x = RNG(-1, MAX + 1);\n\
    \      int ans = -infty<int>;\n      for (auto& b: B) {\n        if (b <= x) chmax(ans,\
    \ b);\n      }\n      assert(ans == WM.prev(L, R, x));\n    }\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(N, 64) {\n    FOR(50) {\n      test<true, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n\
    \      test<false, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n      test<true,\
    \ SegTree<Monoid_Min<int>>>(N);\n      test<false, SegTree<Monoid_Min<int>>>(N);\n\
    \    }\n  }\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"random/base.hpp\"\n#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n#include \"ds/static_range_product_group.hpp\"\n#include \"ds/segtree/segtree.hpp\"\
    \n#include \"alg/monoid/min.hpp\"\n\ntemplate <bool SMALL_Y, typename SEGTREE>\n\
    void test(int N) {\n  int MAX = RNG(2, 1 << 10);\n  vc<int> A(N);\n  vc<int> X(N);\n\
    \  FOR(i, N) X[i] = RNG(MAX);\n  FOR(i, N) A[i] = RNG(MAX);\n\n  Wavelet_Matrix<int,\
    \ false, SEGTREE> WM(A, X);\n  using Mono = typename SEGTREE::MX;\n\n  int Q =\
    \ 100;\n  FOR(Q) {\n    int L = RNG(0, max(1, N));\n    int R = RNG(0, max(1,\
    \ N + 1));\n    if (L > R) swap(L, R);\n    int lo = RNG(0, MAX);\n    int hi\
    \ = RNG(0, MAX);\n    if (lo > hi) swap(lo, hi);\n    ++hi;\n    vc<int> B = {A.begin()\
    \ + L, A.begin() + R};\n    vc<int> Y = {X.begin() + L, X.begin() + R};\n    int\
    \ t = RNG(0, 7);\n    if (t == 0) { // count\n      int cnt = 0;\n      for (auto&&\
    \ x: B)\n        if (lo <= x && x < hi) cnt += 1;\n      assert(WM.count(L, R,\
    \ lo, hi) == cnt);\n    }\n    if (t == 1) { // sm\n      int sm = Mono::unit();\n\
    \      FOR(i, L, R) if (lo <= A[i] && A[i] < hi) sm = Mono::op(sm, X[i]);\n  \
    \    assert(WM.prod(L, R, lo, hi) == sm);\n    }\n    if (t == 2) { // kth\n \
    \     if (L == R) continue;\n      int k = RNG(R - L);\n      sort(all(B));\n\
    \      assert(WM.kth(L, R, k) == B[k]);\n    }\n    if (is_same_v<Mono, Monoid_Add<int>>\
    \ && t == 3) { // max_right\n      int a = RNG(0, 10);\n      int b = RNG(0, 10);\n\
    \      int c = RNG(0, a * (R - L) + b * MAX * (R - L) + 1);\n      auto check\
    \ = [&](int cut, int cnt, int sm) -> bool { return a * cnt + b * sm <= c; };\n\
    \      auto p = WM.max_right(check, L, R);\n      int cnt = 0, sm = 0;\n     \
    \ binary_search(\n          [&](int y) -> bool {\n            auto [c, s] = WM.prefix_count_and_prod(L,\
    \ R, y);\n            if (check(0, c, s)) cnt = c, sm = s;\n            return\
    \ check(0, c, s);\n          },\n          -10, MAX + 10);\n      assert(get<1>(p)\
    \ == cnt && get<2>(p) == sm);\n    }\n    if (t == 4) { // k-th value and prod\n\
    \      int k = RNG(0, R - L + 1);\n      B.eb(infty<int>);\n      auto I = argsort(B);\n\
    \      int val = B[I[k]];\n      int sm = Mono::unit();\n      FOR(i, k) sm =\
    \ Mono::op(sm, Y[I[i]]);\n      auto p = WM.kth_value_and_prod(L, R, k);\n   \
    \   assert(p.fi == val && p.se == sm);\n    }\n    if (t == 5) { // next\n   \
    \   int x = RNG(-1, MAX + 2);\n      int ans = infty<int>;\n      for (auto& b:\
    \ B) {\n        if (x <= b) chmin(ans, b);\n      }\n      assert(ans == WM.next(L,\
    \ R, x));\n    }\n    if (t == 6) { // prev\n      int x = RNG(-1, MAX + 1);\n\
    \      int ans = -infty<int>;\n      for (auto& b: B) {\n        if (b <= x) chmax(ans,\
    \ b);\n      }\n      assert(ans == WM.prev(L, R, x));\n    }\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(N, 64) {\n    FOR(50) {\n      test<true, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n\
    \      test<false, Static_Range_Product_Group<Monoid_Add<int>>>(N);\n      test<true,\
    \ SegTree<Monoid_Min<int>>>(N);\n      test<false, SegTree<Monoid_Min<int>>>(N);\n\
    \    }\n  }\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - ds/dummy_data_structure.hpp
  - alg/monoid/dummy.hpp
  - ds/static_range_product_group.hpp
  - alg/monoid/add.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/1_mytest/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2026-04-13 08:42:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/wavelet_matrix.test.cpp
- /verify/test/1_mytest/wavelet_matrix.test.cpp.html
title: test/1_mytest/wavelet_matrix.test.cpp
---
