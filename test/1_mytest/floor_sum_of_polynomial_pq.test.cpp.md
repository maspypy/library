---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/monoid_for_floor_sum_pq.hpp
    title: alg/monoid/monoid_for_floor_sum_pq.hpp
  - icon: ':x:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
  - icon: ':x:'
    path: mod/floor_monoid_product.hpp
    title: mod/floor_monoid_product.hpp
  - icon: ':x:'
    path: mod/floor_sum_of_linear_polynomial_pq.hpp
    title: mod/floor_sum_of_linear_polynomial_pq.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/floor_sum_of_polynomial_pq.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
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
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ ll(distance((c).begin(), lower_bound(all(c), (x))))\n#define UB(c, x) ll(distance((c).begin(),\
    \ upper_bound(all(c), (x))))\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <class T,\
    \ class Container, class Compare>\nT POP(priority_queue<T, Container, Compare>\
    \ &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n\
    }\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok\
    \ = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok - ng) > 1)\
    \ {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  vc<T> &res\
    \ = first;\n  (res.insert(res.end(), others.begin(), others.end()), ...);\n}\n\
    #endif\n#line 3 \"test/1_mytest/floor_sum_of_polynomial_pq.test.cpp\"\n\n#line\
    \ 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class T>\n\
    \  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n  template\
    \ <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate <class\
    \ T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n\
    \ != 0);\n  return 1.0 / n;\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n\
    \  static const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static\
    \ vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1]\
    \ * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int\
    \ n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while\
    \ (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n\
    }\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return\
    \ (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head,\
    \ class... Tail>\nmint multinomial(Head &&head, Tail &&...tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n    return (d == 0 ?\
    \ mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n\
    #line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n\
    \  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n\
    \  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod)\
    \ {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 582313106};\n    if (mod == 1012924417) return {21,\
    \ 368093570};\n    if (mod == 1224736769) return {24, 1191450770};\n    if (mod\
    \ == 2013265921) return {27, 244035102};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"alg/monoid_pow.hpp\"\n\n// chat\
    \ gpt\ntemplate <typename U, typename Arg1, typename Arg2>\nstruct has_power_method\
    \ {\nprivate:\n  // \u30D8\u30EB\u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n \
    \ template <typename V, typename A1, typename A2>\n  static auto check(int)\n\
    \      -> decltype(std::declval<V>().power(std::declval<A1>(),\n             \
    \                             std::declval<A2>()),\n                  std::true_type{});\n\
    \  template <typename, typename, typename>\n  static auto check(...) -> std::false_type;\n\
    \npublic:\n  // \u30E1\u30BD\u30C3\u30C9\u306E\u6709\u7121\u3092\u8868\u3059\u578B\
    \n  static constexpr bool value = decltype(check<U, Arg1, Arg2>(0))::value;\n\
    };\n\ntemplate <typename Monoid>\ntypename Monoid::X monoid_pow(typename Monoid::X\
    \ x, ll exp) {\n  using X = typename Monoid::X;\n  if constexpr (has_power_method<Monoid,\
    \ X, ll>::value) {\n    return Monoid::power(x, exp);\n  } else {\n    assert(exp\
    \ >= 0);\n    X res = Monoid::unit();\n    while (exp) {\n      if (exp & 1) res\
    \ = Monoid::op(res, x);\n      x = Monoid::op(x, x);\n      exp >>= 1;\n    }\n\
    \    return res;\n  }\n}\n#line 3 \"mod/floor_monoid_product.hpp\"\n\n// https://yukicoder.me/submissions/883884\n\
    // https://qoj.ac/contest/1411/problem/7620\n// U \u306F\u7BC4\u56F2\u5185\u3067\
    \ ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\
    \u5EA6\n// yyy x yyyy x ... yyy x yyy (x \u3092 N \u500B)\n// k \u500B\u76EE\u306E\
    \ x \u307E\u3067\u306B floor(ak+b,m) \u500B\u306E y \u304C\u3042\u308B\n// my<=ax+b\
    \ \u306B\u304A\u3051\u308B lattice path \u306B\u304A\u3051\u308B\u8FBA\u306E\u5217\
    \u3068\u898B\u306A\u305B\u308B\ntemplate <typename Monoid, typename X, typename\
    \ U>\nX floor_monoid_product(X x, X y, U N, U a, U b, U m) {\n  U c = (a * N +\
    \ b) / m;\n  X pre = Monoid::unit(), suf = Monoid::unit();\n  while (1) {\n  \
    \  const U p = a / m, q = b / m;\n    a %= m, b %= m;\n    x = Monoid::op(x, monoid_pow<Monoid>(y,\
    \ p));\n    pre = Monoid::op(pre, monoid_pow<Monoid>(y, q));\n    c -= (p * N\
    \ + q);\n    if (c == 0) break;\n    const U d = (m * c - b - 1) / a + 1;\n  \
    \  suf = Monoid::op(y, Monoid::op(monoid_pow<Monoid>(x, N - d), suf));\n    b\
    \ = m - b - 1 + a, N = c - 1, c = d;\n    swap(m, a), swap(x, y);\n  }\n  x =\
    \ monoid_pow<Monoid>(x, N);\n  return Monoid::op(Monoid::op(pre, x), suf);\n}\n\
    #line 1 \"alg/monoid/monoid_for_floor_sum_pq.hpp\"\n\n// floor path \u3067 (x,y)\
    \ \u304B\u3089 x \u65B9\u5411\u306B\u9032\u3080\u3068\u304D\u306B p^xq^yx^k1y^k2\
    \ \u3092\u8DB3\u3059\ntemplate <typename T, int K1, int K2>\nstruct Monoid_for_floor_sum_pq\
    \ {\n  using ARR = array<array<T, K2 + 1>, K1 + 1>;\n  struct Data {\n    ARR\
    \ dp;\n    T dx, dy;\n    T prod;\n  };\n\n  static pair<T, T> &get_pq() {\n \
    \   static pair<T, T> pq = {T(1), T(1)};\n    return pq;\n  }\n\n  static void\
    \ set_pq(T p, T q) { get_pq() = {p, q}; }\n\n  using value_type = Data;\n  using\
    \ X = value_type;\n  static X op(X a, X b) {\n    static constexpr int n = max(K1,\
    \ K2);\n    static T comb[n + 1][n + 1];\n    if (comb[0][0] != T(1)) {\n    \
    \  comb[0][0] = T(1);\n      FOR(i, n) FOR(j, i + 1) { comb[i + 1][j] += comb[i][j],\
    \ comb[i + 1][j + 1] += comb[i][j]; }\n    }\n\n    array<T, K1 + 1> pow_x;\n\
    \    array<T, K2 + 1> pow_y;\n    pow_x[0] = 1, pow_y[0] = 1;\n    FOR(i, K1)\
    \ pow_x[i + 1] = pow_x[i] * a.dx;\n    FOR(i, K2) pow_y[i + 1] = pow_y[i] * a.dy;\n\
    \n    FOR(i, K1 + 1) FOR(j, K2 + 1) { b.dp[i][j] *= a.prod; }\n\n    // +dy\n\
    \    FOR(i, K1 + 1) {\n      FOR_R(j, K2 + 1) {\n        T x = b.dp[i][j];\n \
    \       FOR(k, j + 1, K2 + 1) b.dp[i][k] += comb[k][j] * pow_y[k - j] * x;\n \
    \     }\n    }\n\n    // +dx\n    FOR(j, K2 + 1) {\n      FOR_R(i, K1 + 1) { FOR(k,\
    \ i, K1 + 1) a.dp[k][j] += comb[k][i] * pow_x[k - i] * b.dp[i][j]; }\n    }\n\n\
    \    a.dx += b.dx, a.dy += b.dy, a.prod *= b.prod;\n    return a;\n  }\n\n  static\
    \ X to_x() {\n    X x = unit();\n    x.dp[0][0] = 1, x.dx = 1, x.prod = get_pq().fi;\n\
    \    return x;\n  }\n  static X to_y() {\n    X x = unit();\n    x.dy = 1, x.prod\
    \ = get_pq().se;\n    return x;\n  }\n  static constexpr X unit() { return {ARR{},\
    \ T(0), T(0), T(1)}; }\n  static constexpr bool commute = 0;\n};\n#line 3 \"mod/floor_sum_of_linear_polynomial_pq.hpp\"\
    \n\n// \u5168\u90E8\u975E\u8CA0, T \u306F\u7B54, U \u306F ax+b \u304C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\ntemplate <typename T, int K1,\
    \ int K2, typename U>\narray<array<T, K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial_nonnegative_pq(T\
    \ p, T q, U N, U a, U b, U mod) {\n  static_assert(is_same_v<U, u64> || is_same_v<U,\
    \ u128>);\n  assert(a == 0 || N < (U(-1) - b) / a);\n  using Mono = Monoid_for_floor_sum_pq<T,\
    \ K1, K2>;\n  Mono::set_pq(p, q);\n  auto x = floor_monoid_product<Mono>(Mono::to_x(),\
    \ Mono::to_y(), N, a, b, mod);\n  return x.dp;\n};\n\n// sum_{L<=x<R} x^i floor(ax+b,mod)^j\n\
    // a+bx \u304C I, U \u3067\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\ntemplate <typename T, int K1, int K2, typename I>\narray<array<T, K2 +\
    \ 1>, K1 + 1> floor_sum_of_linear_polynomial_pq(T p, T q, I L, I R, I a, I b,\
    \ I mod) {\n  static_assert(is_same_v<I, ll> || is_same_v<I, i128>);\n  assert(L\
    \ <= R && mod > 0);\n  using Mono = Monoid_for_floor_sum_pq<T, K1, K2>;\n  Mono::set_pq(p,\
    \ q);\n  if (a < 0) {\n    auto ANS = floor_sum_of_linear_polynomial_pq<T, K1,\
    \ K2, I>(p.inverse(), q, -R + 1, -L + 1, -a, b, mod);\n    FOR(i, K1 + 1) {\n\
    \      if (i % 2 == 1) { FOR(j, K2 + 1) ANS[i][j] = -ANS[i][j]; }\n    }\n   \
    \ return ANS;\n  }\n  assert(a >= 0);\n  I ADD_X = L;\n  I N = R - L;\n  b +=\
    \ a * L;\n  I ADD_Y = floor<I>(b, mod);\n  b -= ADD_Y * mod;\n  assert(a >= 0\
    \ && b >= 0);\n\n  using Mono = Monoid_for_floor_sum_pq<T, K1, K2>;\n  using Data\
    \ = typename Mono::Data;\n  using U = std::conditional_t<is_same_v<I, ll>, u64,\
    \ u128>;\n  Data A = floor_monoid_product<Mono, Data, U>(Mono::to_x(), Mono::to_y(),\
    \ N, a, b, mod);\n  Data offset = Mono::unit();\n  offset.dx = T(ADD_X), offset.dy\
    \ = T(ADD_Y);\n  A = Mono::op(offset, A);\n  T mul = p.pow(ADD_X) * q.pow(ADD_Y);\n\
    \  FOR(i, K1 + 1) FOR(j, K2 + 1) A.dp[i][j] *= mul;\n  return A.dp;\n};\n#line\
    \ 6 \"test/1_mytest/floor_sum_of_polynomial_pq.test.cpp\"\n\nusing mint = modint998;\n\
    \ntemplate <int K1, int K2>\nvoid test_1() {\n  FOR(p, 1, 4) FOR(q, 1, 4) {\n\
    \    FOR(M, 1, 5) {\n      FOR(a, 10) FOR(b, 10) {\n        array<array<mint,\
    \ K2 + 1>, K1 + 1> dp{};\n        FOR(N, 10) {\n          array<array<mint, K2\
    \ + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial_nonnegative_pq<mint, K1,\
    \ K2, u64>(p, q, N, a, b, M);\n          assert(dp == ans);\n          ll y =\
    \ floor(a * N + b, M);\n          FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] += mint(p).pow(N)\
    \ * mint(q).pow(y) * mint(N).pow(i) * mint(y).pow(j);\n        }\n      }\n  \
    \  }\n  }\n}\n\ntemplate <int K1, int K2>\nvoid test_2() {\n  FOR(p, 1, 4) FOR(q,\
    \ 1, 4) {\n    FOR(M, 1, 5) {\n      FOR(a, -5, 6) FOR(b, -5, 6) {\n        FOR(L,\
    \ -5, 6) {\n          array<array<mint, K2 + 1>, K1 + 1> dp{};\n          FOR(R,\
    \ L, 6) {\n            array<array<mint, K2 + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial_pq<mint,\
    \ K1, K2, ll>(p, q, L, R, a, b, M);\n            assert(dp == ans);\n        \
    \    ll y = floor(a * R + b, M);\n            FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j]\
    \ += mint(p).pow(R) * mint(q).pow(y) * mint(R).pow(i) * mint(y).pow(j);\n    \
    \      }\n        }\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n \
    \ cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test_1<0,\
    \ 0>();\n  test_1<0, 1>();\n  test_1<0, 2>();\n  test_1<1, 0>();\n  test_1<1,\
    \ 1>();\n  test_1<1, 2>();\n  test_1<2, 0>();\n  test_1<2, 1>();\n  test_1<2,\
    \ 2>();\n  test_1<4, 4>();\n\n  test_2<0, 0>();\n  test_2<0, 1>();\n  test_2<0,\
    \ 2>();\n  test_2<1, 0>();\n  test_2<1, 1>();\n  test_2<1, 2>();\n  test_2<2,\
    \ 0>();\n  test_2<2, 1>();\n  test_2<2, 2>();\n  test_2<4, 4>();\n\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"mod/modint.hpp\"\n#include \"mod/floor_sum_of_linear_polynomial_pq.hpp\"\
    \n\nusing mint = modint998;\n\ntemplate <int K1, int K2>\nvoid test_1() {\n  FOR(p,\
    \ 1, 4) FOR(q, 1, 4) {\n    FOR(M, 1, 5) {\n      FOR(a, 10) FOR(b, 10) {\n  \
    \      array<array<mint, K2 + 1>, K1 + 1> dp{};\n        FOR(N, 10) {\n      \
    \    array<array<mint, K2 + 1>, K1 + 1> ans = floor_sum_of_linear_polynomial_nonnegative_pq<mint,\
    \ K1, K2, u64>(p, q, N, a, b, M);\n          assert(dp == ans);\n          ll\
    \ y = floor(a * N + b, M);\n          FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] +=\
    \ mint(p).pow(N) * mint(q).pow(y) * mint(N).pow(i) * mint(y).pow(j);\n       \
    \ }\n      }\n    }\n  }\n}\n\ntemplate <int K1, int K2>\nvoid test_2() {\n  FOR(p,\
    \ 1, 4) FOR(q, 1, 4) {\n    FOR(M, 1, 5) {\n      FOR(a, -5, 6) FOR(b, -5, 6)\
    \ {\n        FOR(L, -5, 6) {\n          array<array<mint, K2 + 1>, K1 + 1> dp{};\n\
    \          FOR(R, L, 6) {\n            array<array<mint, K2 + 1>, K1 + 1> ans\
    \ = floor_sum_of_linear_polynomial_pq<mint, K1, K2, ll>(p, q, L, R, a, b, M);\n\
    \            assert(dp == ans);\n            ll y = floor(a * R + b, M);\n   \
    \         FOR(i, K1 + 1) FOR(j, K2 + 1) dp[i][j] += mint(p).pow(R) * mint(q).pow(y)\
    \ * mint(R).pow(i) * mint(y).pow(j);\n          }\n        }\n      }\n    }\n\
    \  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test_1<0, 0>();\n  test_1<0, 1>();\n  test_1<0,\
    \ 2>();\n  test_1<1, 0>();\n  test_1<1, 1>();\n  test_1<1, 2>();\n  test_1<2,\
    \ 0>();\n  test_1<2, 1>();\n  test_1<2, 2>();\n  test_1<4, 4>();\n\n  test_2<0,\
    \ 0>();\n  test_2<0, 1>();\n  test_2<0, 2>();\n  test_2<1, 0>();\n  test_2<1,\
    \ 1>();\n  test_2<1, 2>();\n  test_2<2, 0>();\n  test_2<2, 1>();\n  test_2<2,\
    \ 2>();\n  test_2<4, 4>();\n\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/floor_sum_of_linear_polynomial_pq.hpp
  - mod/floor_monoid_product.hpp
  - alg/monoid_pow.hpp
  - alg/monoid/monoid_for_floor_sum_pq.hpp
  isVerificationFile: true
  path: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 05:45:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
- /verify/test/1_mytest/floor_sum_of_polynomial_pq.test.cpp.html
title: test/1_mytest/floor_sum_of_polynomial_pq.test.cpp
---
