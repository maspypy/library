---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/base.hpp
    title: nt/nimber/base.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/nimber_impl.hpp
    title: nt/nimber/nimber_impl.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/nimber_log.hpp
    title: nt/nimber/nimber_log.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/nimber_log.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
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
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/nimber_log.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"nt/nimber/nimber_impl.hpp\"\nnamespace NIM_PRODUCT\
    \ {\r\nu16 E[65535 * 2 + 7];\r\nu16 L[65536];\r\nu64 S[4][65536];\r\nu64 SR[4][65536];\r\
    \n\r\nu16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0);\
    \ }\r\nu16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6]\
    \ : 0); }\r\nu16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\r\nu16 mul_15_15(u16\
    \ a) { return (a ? E[6 + L[a]] : 0); }\r\nu32 p32_mul_31(u32 a, u32 b) {\r\n \
    \ u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\n  u16 x =\
    \ p16_15(al, bl);\r\n  u16 y = p16_15_15(ah, bh);\r\n  u16 z = p16_15(al ^ ah,\
    \ bl ^ bh);\r\n  return u32(y ^ z) << 16 | mul_15(z ^ x);\r\n}\r\nu32 mul_31(u32\
    \ a) {\r\n  u16 al = a & 65535, ah = a >> 16;\r\n  return u32(mul_15(al ^ ah))\
    \ << 16 | mul_15_15(ah);\r\n}\r\n\r\nu16 prod(u16 a, u16 b) { return (a && b ?\
    \ E[u32(L[a]) + L[b]] : 0); }\r\nu32 prod(u32 a, u32 b) {\r\n  u16 al = a & 65535,\
    \ ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\n  u16 c = prod(al, bl);\r\n \
    \ return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c) << 16 | (p16_15(ah, bh) ^ c);\r\
    \n}\r\nu64 prod(u64 a, u64 b) {\r\n  u32 al = a & 0xffffffff, ah = a >> 32, bl\
    \ = b & 0xffffffff, bh = b >> 32;\r\n  u32 c = prod(al, bl);\r\n  return u64(prod(al\
    \ ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);\r\n}\r\n\r\nu16 square(u16\
    \ a) { return S[0][a]; }\r\nu32 square(u32 a) { return S[0][a & 65535] ^ S[1][a\
    \ >> 16]; }\r\nu64 square(u64 a) { return S[0][a & 65535] ^ S[1][a >> 16 & 65535]\
    \ ^ S[2][a >> 32 & 65535] ^ S[3][a >> 48 & 65535]; }\r\nu16 sqrt(u16 a) { return\
    \ SR[0][a]; }\r\nu32 sqrt(u32 a) { return SR[0][a & 65535] ^ SR[1][a >> 16]; }\r\
    \nu64 sqrt(u64 a) { return SR[0][a & 65535] ^ SR[1][a >> 16 & 65535] ^ SR[2][a\
    \ >> 32 & 65535] ^ SR[3][a >> 48 & 65535]; }\r\n\r\n// inv: 2^16 \u306E\u5171\u5F79\
    \u304C 2^16+1 \u3067\u3042\u308B\u3053\u3068\u306A\u3069\u3092\u4F7F\u3046. x^{-1}=y(xy)^{-1}\
    \ \u3068\u3044\u3046\u8981\u9818.\r\nu16 inverse(u16 a) { return E[65535 - L[a]];\
    \ }\r\nu32 inverse(u32 a) {\r\n  if (a < 65536) return inverse(u16(a));\r\n  u16\
    \ al = a & 65535, ah = a >> 16;\r\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah] *\
    \ 2 + 3];\r\n  int k = 65535 - L[norm];\r\n  al = (al ^ ah ? E[L[al ^ ah] + k]\
    \ : 0), ah = E[L[ah] + k];\r\n  return al | u32(ah) << 16;\r\n}\r\nu64 inverse(u64\
    \ a) {\r\n  if (a <= u32(-1)) return inverse(u32(a));\r\n  u32 al = a & 0xffffffff,\
    \ ah = a >> 32;\r\n  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));\r\n  u32\
    \ i = inverse(norm);\r\n  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;\r\n\
    }\r\n\r\nvoid __attribute__((constructor)) init_nim_table() {\r\n  // 2^16 \u672A\
    \u6E80\u306E\u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\u59CB\u6839 10279\
    \ \u3067\u306E\u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\r\n  // 2^k \u3068\
    \u306E\u7A4D\r\n  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661,\
    \ 5686, 3862, 1323, 334, 647, 61560, 20636, 4267, 8445};\r\n  u16 nxt[65536];\r\
    \n  FOR(i, 16) {\r\n    FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\r\
    \n  }\r\n  E[0] = 1;\r\n  FOR(i, 65534) E[i + 1] = nxt[E[i]];\r\n  memcpy(E +\
    \ 65535, E, 131070);\r\n  memcpy(E + 131070, E, 14);\r\n  FOR(i, 65535) L[E[i]]\
    \ = i;\r\n  FOR(t, 4) {\r\n    FOR(i, 16) {\r\n      int k = 16 * t + i;\r\n \
    \     u64 X = prod(u64(1) << k, u64(1) << k);\r\n      FOR(s, 1 << i) S[t][s |\
    \ 1 << i] = S[t][s] ^ X;\r\n    }\r\n  }\r\n  FOR(t, 4) {\r\n    FOR(i, 16) {\r\
    \n      int k = 16 * t + i;\r\n      u64 X = u64(1) << k;\r\n      FOR(63) X =\
    \ square(X);\r\n      FOR(s, 1 << i) SR[t][s | 1 << i] = SR[t][s] ^ X;\r\n   \
    \ }\r\n  }\r\n}\r\n} // namespace NIM_PRODUCT\r\n#line 3 \"nt/nimber/base.hpp\"\
    \n\ntemplate <typename UINT>\nstruct Nimber {\n  using F = Nimber;\n  UINT val;\n\
    \n  constexpr Nimber(UINT x = 0) : val(x) {}\n  F &operator+=(const F &p) {\n\
    \    val ^= p.val;\n    return *this;\n  }\n  F &operator-=(const F &p) {\n  \
    \  val ^= p.val;\n    return *this;\n  }\n  F &operator*=(const F &p) {\n    val\
    \ = NIM_PRODUCT::prod(val, p.val);\n    return *this;\n  }\n  F &operator/=(const\
    \ F &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  F operator-()\
    \ const { return *this; }\n  F operator+(const F &p) const { return F(*this) +=\
    \ p; }\n  F operator-(const F &p) const { return F(*this) -= p; }\n  F operator*(const\
    \ F &p) const { return F(*this) *= p; }\n  F operator/(const F &p) const { return\
    \ F(*this) /= p; }\n  bool operator==(const F &p) const { return val == p.val;\
    \ }\n  bool operator!=(const F &p) const { return val != p.val; }\n  F inverse()\
    \ const { return NIM_PRODUCT::inverse(val); }\n  F pow(u64 n) const {\n    assert(n\
    \ >= 0);\n    UINT ret = 1, mul = val;\n    while (n > 0) {\n      if (n & 1)\
    \ ret = NIM_PRODUCT::prod(ret, mul);\n      mul = NIM_PRODUCT::square(mul);\n\
    \      n >>= 1;\n    }\n    return F(ret);\n  }\n  F square() { return F(NIM_PRODUCT::square(val));\
    \ }\n  F sqrt() { return F(NIM_PRODUCT::sqrt(val)); }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <typename T>\nvoid rd(Nimber<T> &x) {\n  fastio::rd(x.val);\n}\ntemplate <typename\
    \ T>\nvoid wt(Nimber<T> &x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing Nimber16\
    \ = Nimber<u16>;\nusing Nimber32 = Nimber<u32>;\nusing Nimber64 = Nimber<u64>;\n\
    #line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct\
    \ HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\
    \u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32 n) {\r\n \
    \   u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k -\
    \ 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  //\
    \ size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\
    \u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used),\
    \ 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) /\
    \ 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i\
    \ = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\
    \n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\
    \n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i]\
    \ = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k,\
    \ Val default_value) {\r\n    int i = index(k);\r\n    return (used[i] ? val[i]\
    \ : default_value);\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i =\
    \ index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\
    \n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\
    \n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"mod/crt3.hpp\"\n\nconstexpr\
    \ u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n\
    \  FOR(32) {\n    if (n & 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n\
    \  }\n  return res;\n}\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0,\
    \ u64 a1) {\n  static_assert(p0 < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64\
    \ a2) {\n  static_assert(p0 < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0\
    \ + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) *\
    \ x2 % p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32\
    \ p0, u32 p1, u32 p2, u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0\
    \ < p1 && p1 < p2 && p2 < p3);\n  static constexpr u64 x1 = mod_pow_constexpr(p0,\
    \ p1 - 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2,\
    \ p2 - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3\
    \ * p2 % p3, p3 - 2, p3);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c\
    \ = (a1 - a0 + p1) * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 %\
    \ p2 + p2) * x2 % p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c\
    \ = (a3 - ans_2 % p3 + p3) * x3 % p3;\n  return T(ans_2) + T(c) * T(p01) * T(p2);\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>\nT CRT5(u64\
    \ a0, u64 a1, u64 a2, u64 a3, u64 a4) {\n  static_assert(p0 < p1 && p1 < p2 &&\
    \ p2 < p3 && p3 < p4);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 -\
    \ 2, p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2\
    \ - 2, p2);\n  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 *\
    \ p2 % p3, p3 - 2, p3);\n  static constexpr u64 x4 = mod_pow_constexpr(u64(p0)\
    \ * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);\n  static constexpr u64 p01 = u64(p0)\
    \ * p1;\n  static constexpr u64 p23 = u64(p2) * p3;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);\n  c = static_cast<u64>(a3\
    \ - ans_2 % p3 + p3) * x3 % p3;\n  u128 ans_3 = ans_2 + static_cast<u128>(c *\
    \ p2) * p01;\n  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;\n  return\
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 4 \"nt/nimber/nimber_log.hpp\"\n\
    \n// primitive root\nconst Nimber64 root_64 = u64(1) << 32 | 6;\nconst Nimber32\
    \ root_32 = 2147483651;\nconst Nimber16 root_16 = 41899;\n\nu64 nimber_log(Nimber16\
    \ x) {\n  assert(x != 0);\n  u32 ans = u32(37991) * NIM_PRODUCT::L[x.val];\n \
    \ return ans % 65535;\n}\n\nu64 nimber_log(Nimber32 x) {\n  using F = Nimber32;\n\
    \  assert(x != 0);\n  static HashMap<u32> MP(330);\n  static F g = 0;\n  if (len(MP)\
    \ == 0) {\n    // build\n    g = root_32.pow(65535); // 65537 \u4E57\u6839\n \
    \   F gg = g.pow(200);\n    F pow = 1;\n    FOR(i, 330) MP[pow.val] = i, pow *=\
    \ gg;\n  }\n  u64 a = [&]() -> u32 {\n    F x1 = x.pow(65535);\n    FOR(i, 200)\
    \ {\n      u32 k = MP.get(x1.val, -1);\n      if (k != u32(-1)) { return (65537\
    \ + 200 * k - i) % 65537; }\n      x1 *= g;\n    }\n    assert(0);\n    return\
    \ 0;\n  }();\n  u64 b = nimber_log(Nimber16(x.pow(65537).val));\n  return CRT2<u64,\
    \ 65535, 65537>(b, a);\n}\n\nu64 nimber_log(Nimber64 x) {\n  using F = Nimber64;\n\
    \  assert(x != 0);\n  const u64 mod1 = u32(-1);\n  const u64 mod2 = mod1 + 2;\n\
    \  const u32 p1 = 641;\n  const u32 p2 = 6700417;\n  static HashMap<u32> MP1(3400);\n\
    \  static HashMap<u32> MP2(641);\n  static F g1, g2;\n  if (len(MP1) == 0) {\n\
    \    g1 = root_64.pow(mod1 * p1); // p2 \u4E57\u6839\n    g2 = root_64.pow(mod1\
    \ * p2); // p1 \u4E57\u6839\n    F gg = g1.pow(2000);\n    F pow = 1;\n    FOR(i,\
    \ 3400) MP1[pow.val] = i, pow *= gg;\n    pow = 1;\n    FOR(i, 641) MP2[pow.val]\
    \ = i, pow *= g2;\n  }\n  u64 a1 = [&]() -> u64 {\n    F x1 = x.pow(mod1 * p1);\n\
    \    FOR(i, 2000) {\n      u32 k = MP1.get(x1.val, -1);\n      if (k != u32(-1))\
    \ { return (p2 + 2000 * k - i) % p2; }\n      x1 *= g1;\n    }\n    assert(0);\n\
    \    return 0;\n  }();\n  u64 a2 = MP2[x.pow(mod1 * p2).val];\n  u64 b = nimber_log(Nimber32(x.pow(mod2).val));\n\
    \  u64 a = CRT2<u64, p1, p2>(a2, a1);\n  u128 ans = u128(a) * (u64(-1) - mod1)\
    \ + u128(b) * mod2;\n  if (ans & 1) ans += u64(-1);\n  return (ans / 2) % u64(-1);\n\
    }\n\n// \u6700\u5C0F\u89E3. \u3061\u3087\u3046\u3069 -1 \u3092 false \u306E\u610F\
    \u5473\u306B\u4F7F\u3048\u308B.\ntemplate <typename F>\nu64 nimber_log(F x, F\
    \ y) {\n  u64 X = nimber_log(x), Y = nimber_log(y);\n  // X*n = Y mod (2^64-1)\n\
    \  u64 mod = -1;\n  u64 a = X, b = mod;\n  i128 u = 1, v = 0, t;\n  while (b >\
    \ 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n  }\n \
    \ if (Y % a != 0) return -1;\n  if (u < 0) u += mod;\n  return (Y / a) * u % (mod\
    \ / a);\n}\n#line 6 \"test/1_mytest/nimber_log.test.cpp\"\n\nvoid test_16() {\n\
    \  FOR(n, 1, 65536) {\n    Nimber16 x(n);\n    u64 m = nimber_log(x);\n    assert(root_16.pow(m)\
    \ == x);\n  }\n}\n\nvoid test_32() {\n  FOR(1 << 15) {\n    Nimber32 x(RNG_64());\n\
    \    if (x == 0) continue;\n    u64 n = nimber_log(x);\n    assert(root_32.pow(n)\
    \ == x);\n  }\n}\n\nvoid test_64() {\n  FOR(1 << 15) {\n    Nimber64 x(RNG_64());\n\
    \    if (x == 0) continue;\n    u64 n = nimber_log(x);\n    assert(root_64.pow(n)\
    \ == x);\n  }\n  FOR(1 << 15) {\n    Nimber64 x(RNG_64());\n    Nimber64 y(RNG_64());\n\
    \    if (x == 0 || y == 0) continue;\n    u64 n = nimber_log(x, y);\n    if (n\
    \ != u64(-1)) assert(x.pow(n) == y);\n  }\n  FOR(1 << 15) {\n    Nimber64 x(RNG_64());\n\
    \    u64 n = RNG_64();\n    Nimber64 y = x.pow(n);\n    u64 m = nimber_log(x,\
    \ y);\n    assert(m != u64(-1) && x.pow(m) == y);\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test_16();\n  test_32();\n  test_64();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"nt/nimber/nimber_log.hpp\"\n\nvoid\
    \ test_16() {\n  FOR(n, 1, 65536) {\n    Nimber16 x(n);\n    u64 m = nimber_log(x);\n\
    \    assert(root_16.pow(m) == x);\n  }\n}\n\nvoid test_32() {\n  FOR(1 << 15)\
    \ {\n    Nimber32 x(RNG_64());\n    if (x == 0) continue;\n    u64 n = nimber_log(x);\n\
    \    assert(root_32.pow(n) == x);\n  }\n}\n\nvoid test_64() {\n  FOR(1 << 15)\
    \ {\n    Nimber64 x(RNG_64());\n    if (x == 0) continue;\n    u64 n = nimber_log(x);\n\
    \    assert(root_64.pow(n) == x);\n  }\n  FOR(1 << 15) {\n    Nimber64 x(RNG_64());\n\
    \    Nimber64 y(RNG_64());\n    if (x == 0 || y == 0) continue;\n    u64 n = nimber_log(x,\
    \ y);\n    if (n != u64(-1)) assert(x.pow(n) == y);\n  }\n  FOR(1 << 15) {\n \
    \   Nimber64 x(RNG_64());\n    u64 n = RNG_64();\n    Nimber64 y = x.pow(n);\n\
    \    u64 m = nimber_log(x, y);\n    assert(m != u64(-1) && x.pow(m) == y);\n \
    \ }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test_16();\n  test_32();\n  test_64();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - nt/nimber/nimber_log.hpp
  - nt/nimber/base.hpp
  - nt/nimber/nimber_impl.hpp
  - ds/hashmap.hpp
  - mod/crt3.hpp
  isVerificationFile: true
  path: test/1_mytest/nimber_log.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/nimber_log.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/nimber_log.test.cpp
- /verify/test/1_mytest/nimber_log.test.cpp.html
title: test/1_mytest/nimber_log.test.cpp
---
