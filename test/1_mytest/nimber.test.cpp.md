---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/xor/basis.hpp
    title: linalg/xor/basis.hpp
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
    path: nt/nimber/solve_quadratic.hpp
    title: nt/nimber/solve_quadratic.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/nimber.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\
    \n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include\
    \ <cassert>\n\nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\n\
    using u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128\
    \ = __int128;\nusing u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate\
    \ <class>\nconstexpr bool dependent_false = false;\n\ntemplate <class T>\nconstexpr\
    \ T infty = [] {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\"\
    );\n  return T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
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
    \ ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n\
    #define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\n// require y > 0\n\
    template <typename T>\nT floor(T x, T y) {\n  return x / y - (x % y < 0);\n}\n\
    \n// require y > 0\ntemplate <typename T>\nT ceil(T x, T y) {\n  return (x / y)\
    \ + (x % y > 0);\n}\n\n// require y > 0\ntemplate <typename T>\nT bmod(T x, T\
    \ y) {\n  T r = x % y;\n  return (r < 0 ? r + y : r);\n}\n\n// require y > 0\n\
    template <typename T>\npair<T, T> divmod(T x, T y) {\n  T q = x / y, r = x % y;\n\
    \  if (r < 0) --q, r += y;\n  return {q, r};\n}\n\nconstexpr auto TEN = [] {\n\
    \  array<u64, 20> A{};\n  A[0] = 1;\n  for (int i = 1; i < 20; ++i) A[i] = 10\
    \ * A[i - 1];\n  return A;\n}();\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (1)\
    \ {\n    ll x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c\
    \ = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\
    template <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F\
    \ -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
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
    \ &...others) {\n  first.reserve(first.size() + (others.size() + ... + 0));\n\
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n\n// i128\n\
    template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr i128 abs(T\
    \ x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128 b) {\n\
    \  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return abs(a);\n\
    }\n#endif\n#line 3 \"test/1_mytest/nimber.test.cpp\"\n\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"nt/nimber/nimber_impl.hpp\"\nnamespace NIM_PRODUCT\
    \ {\nu16 E[65535 * 2 + 7];\nu16 L[65536];\nu64 S[4][65536];\nu64 SR[4][65536];\n\
    \nu16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }\n\
    u16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }\n\
    u16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\nu16 mul_15_15(u16 a) { return\
    \ (a ? E[6 + L[a]] : 0); }\nu32 p32_mul_31(u32 a, u32 b) {\n  u16 al = a & 65535,\
    \ ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16 x = p16_15(al, bl);\n  u16\
    \ y = p16_15_15(ah, bh);\n  u16 z = p16_15(al ^ ah, bl ^ bh);\n  return u32(y\
    \ ^ z) << 16 | mul_15(z ^ x);\n}\nu32 mul_31(u32 a) {\n  u16 al = a & 65535, ah\
    \ = a >> 16;\n  return u32(mul_15(al ^ ah)) << 16 | mul_15_15(ah);\n}\n\nu16 prod(u16\
    \ a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }\nu32 prod(u32 a, u32\
    \ b) {\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16\
    \ c = prod(al, bl);\n  return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c) << 16\
    \ | (p16_15(ah, bh) ^ c);\n}\nu64 prod(u64 a, u64 b) {\n  u32 al = a & 0xffffffff,\
    \ ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;\n  u32 c = prod(al, bl);\n\
    \  return u64(prod(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);\n\
    }\n\nu16 square(u16 a) { return S[0][a]; }\nu32 square(u32 a) { return S[0][a\
    \ & 65535] ^ S[1][a >> 16]; }\nu64 square(u64 a) { return S[0][a & 65535] ^ S[1][a\
    \ >> 16 & 65535] ^ S[2][a >> 32 & 65535] ^ S[3][a >> 48 & 65535]; }\nu16 sqrt(u16\
    \ a) { return SR[0][a]; }\nu32 sqrt(u32 a) { return SR[0][a & 65535] ^ SR[1][a\
    \ >> 16]; }\nu64 sqrt(u64 a) { return SR[0][a & 65535] ^ SR[1][a >> 16 & 65535]\
    \ ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 & 65535]; }\n\n// inv: 2^16 \u306E\u5171\
    \u5F79\u304C 2^16+1 \u3067\u3042\u308B\u3053\u3068\u306A\u3069\u3092\u4F7F\u3046\
    . x^{-1}=y(xy)^{-1} \u3068\u3044\u3046\u8981\u9818.\nu16 inverse(u16 a) { return\
    \ E[65535 - L[a]]; }\nu32 inverse(u32 a) {\n  if (a < 65536) return inverse(u16(a));\n\
    \  u16 al = a & 65535, ah = a >> 16;\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah]\
    \ * 2 + 3];\n  int k = 65535 - L[norm];\n  al = (al ^ ah ? E[L[al ^ ah] + k] :\
    \ 0), ah = E[L[ah] + k];\n  return al | u32(ah) << 16;\n}\nu64 inverse(u64 a)\
    \ {\n  if (a <= u32(-1)) return inverse(u32(a));\n  u32 al = a & 0xffffffff, ah\
    \ = a >> 32;\n  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));\n  u32 i =\
    \ inverse(norm);\n  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;\n}\n\nvoid\
    \ __attribute__((constructor)) init_nim_table() {\n  // 2^16 \u672A\u6E80\u306E\
    \u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\u59CB\u6839 10279 \u3067\u306E\
    \u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\n  // 2^k \u3068\u306E\u7A4D\n\
    \  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661, 5686, 3862, 1323,\
    \ 334, 647, 61560, 20636, 4267, 8445};\n  u16 nxt[65536];\n  FOR(i, 16) {\n  \
    \  FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\n  }\n  E[0] = 1;\n \
    \ FOR(i, 65534) E[i + 1] = nxt[E[i]];\n  memcpy(E + 65535, E, 131070);\n  memcpy(E\
    \ + 131070, E, 14);\n  FOR(i, 65535) L[E[i]] = i;\n  FOR(t, 4) {\n    FOR(i, 16)\
    \ {\n      int k = 16 * t + i;\n      u64 X = prod(u64(1) << k, u64(1) << k);\n\
    \      FOR(s, 1 << i) S[t][s | 1 << i] = S[t][s] ^ X;\n    }\n  }\n  FOR(t, 4)\
    \ {\n    FOR(i, 16) {\n      int k = 16 * t + i;\n      u64 X = u64(1) << k;\n\
    \      FOR(63) X = square(X);\n      FOR(s, 1 << i) SR[t][s | 1 << i] = SR[t][s]\
    \ ^ X;\n    }\n  }\n}\n} // namespace NIM_PRODUCT\n#line 2 \"nt/nimber/base.hpp\"\
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
    #line 1 \"nt/nimber/nimber_impl.hpp\"\nnamespace NIM_PRODUCT {\nu16 E[65535 *\
    \ 2 + 7];\nu16 L[65536];\nu64 S[4][65536];\nu64 SR[4][65536];\n\nu16 p16_15(u16\
    \ a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }\nu16 p16_15_15(u16\
    \ a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }\nu16 mul_15(u16\
    \ a) { return (a ? E[3 + L[a]] : 0); }\nu16 mul_15_15(u16 a) { return (a ? E[6\
    \ + L[a]] : 0); }\nu32 p32_mul_31(u32 a, u32 b) {\n  u16 al = a & 65535, ah =\
    \ a >> 16, bl = b & 65535, bh = b >> 16;\n  u16 x = p16_15(al, bl);\n  u16 y =\
    \ p16_15_15(ah, bh);\n  u16 z = p16_15(al ^ ah, bl ^ bh);\n  return u32(y ^ z)\
    \ << 16 | mul_15(z ^ x);\n}\nu32 mul_31(u32 a) {\n  u16 al = a & 65535, ah = a\
    \ >> 16;\n  return u32(mul_15(al ^ ah)) << 16 | mul_15_15(ah);\n}\n\nu16 prod(u16\
    \ a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }\nu32 prod(u32 a, u32\
    \ b) {\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16\
    \ c = prod(al, bl);\n  return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c) << 16\
    \ | (p16_15(ah, bh) ^ c);\n}\nu64 prod(u64 a, u64 b) {\n  u32 al = a & 0xffffffff,\
    \ ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;\n  u32 c = prod(al, bl);\n\
    \  return u64(prod(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);\n\
    }\n\nu16 square(u16 a) { return S[0][a]; }\nu32 square(u32 a) { return S[0][a\
    \ & 65535] ^ S[1][a >> 16]; }\nu64 square(u64 a) { return S[0][a & 65535] ^ S[1][a\
    \ >> 16 & 65535] ^ S[2][a >> 32 & 65535] ^ S[3][a >> 48 & 65535]; }\nu16 sqrt(u16\
    \ a) { return SR[0][a]; }\nu32 sqrt(u32 a) { return SR[0][a & 65535] ^ SR[1][a\
    \ >> 16]; }\nu64 sqrt(u64 a) { return SR[0][a & 65535] ^ SR[1][a >> 16 & 65535]\
    \ ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 & 65535]; }\n\n// inv: 2^16 \u306E\u5171\
    \u5F79\u304C 2^16+1 \u3067\u3042\u308B\u3053\u3068\u306A\u3069\u3092\u4F7F\u3046\
    . x^{-1}=y(xy)^{-1} \u3068\u3044\u3046\u8981\u9818.\nu16 inverse(u16 a) { return\
    \ E[65535 - L[a]]; }\nu32 inverse(u32 a) {\n  if (a < 65536) return inverse(u16(a));\n\
    \  u16 al = a & 65535, ah = a >> 16;\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah]\
    \ * 2 + 3];\n  int k = 65535 - L[norm];\n  al = (al ^ ah ? E[L[al ^ ah] + k] :\
    \ 0), ah = E[L[ah] + k];\n  return al | u32(ah) << 16;\n}\nu64 inverse(u64 a)\
    \ {\n  if (a <= u32(-1)) return inverse(u32(a));\n  u32 al = a & 0xffffffff, ah\
    \ = a >> 32;\n  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));\n  u32 i =\
    \ inverse(norm);\n  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;\n}\n\nvoid\
    \ __attribute__((constructor)) init_nim_table() {\n  // 2^16 \u672A\u6E80\u306E\
    \u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\u59CB\u6839 10279 \u3067\u306E\
    \u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\n  // 2^k \u3068\u306E\u7A4D\n\
    \  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661, 5686, 3862, 1323,\
    \ 334, 647, 61560, 20636, 4267, 8445};\n  u16 nxt[65536];\n  FOR(i, 16) {\n  \
    \  FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\n  }\n  E[0] = 1;\n \
    \ FOR(i, 65534) E[i + 1] = nxt[E[i]];\n  memcpy(E + 65535, E, 131070);\n  memcpy(E\
    \ + 131070, E, 14);\n  FOR(i, 65535) L[E[i]] = i;\n  FOR(t, 4) {\n    FOR(i, 16)\
    \ {\n      int k = 16 * t + i;\n      u64 X = prod(u64(1) << k, u64(1) << k);\n\
    \      FOR(s, 1 << i) S[t][s | 1 << i] = S[t][s] ^ X;\n    }\n  }\n  FOR(t, 4)\
    \ {\n    FOR(i, 16) {\n      int k = 16 * t + i;\n      u64 X = u64(1) << k;\n\
    \      FOR(63) X = square(X);\n      FOR(s, 1 << i) SR[t][s | 1 << i] = SR[t][s]\
    \ ^ X;\n    }\n  }\n}\n} // namespace NIM_PRODUCT\n#line 2 \"nt/nimber/base.hpp\"\
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
    #line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"linalg/xor/basis.hpp\"\n\n/*\n\u4F7F\u3044\u5206\u3051\
    \u65B9\u91DD\nVector_Space: \u7DDA\u5F62\u7A7A\u9593\u305D\u306E\u3082\u306E\u3092\
    \u7BA1\u7406\nBasis: \u5143\u306E\u57FA\u5E95\u306B\u3088\u308B\u7DDA\u5F62\u7D50\
    \u5408\u8868\u793A\u3082\u7BA1\u7406\nbasis[i]: i \u756A\u76EE\u306B\u8FFD\u52A0\
    \u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\u3042\
    \u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\narray<UINT, MAX_DIM>\
    \ rbasis: \u4E0A\u4E09\u89D2\u5316\u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n\
    way<UINT,UINT> rbasis[i] \u3092 basis[j] \u3067\u4F5C\u308B\u65B9\u6CD5\n*/\n\
    template <int MAX_DIM>\nstruct Basis {\n  static_assert(MAX_DIM <= 128);\n  using\
    \ UINT = conditional_t<(MAX_DIM <= 32), u32,\n                             conditional_t<(MAX_DIM\
    \ <= 64), u64, u128>>;\n  int rank;\n  array<UINT, MAX_DIM> basis;\n  array<UINT,\
    \ MAX_DIM> rbasis;\n  array<UINT, MAX_DIM> way;\n  Basis() : rank(0), basis{},\
    \ rbasis{}, way{} {}\n\n  // return : (sum==x \u306B\u3067\u304D\u308B\u304B,\
    \ \u305D\u306E\u65B9\u6CD5)\n  pair<bool, UINT> solve(UINT x) {\n    UINT c =\
    \ 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i] != 0)) {\n \
    \       c ^= way[i], x ^= rbasis[i];\n      }\n    }\n    if (x == 0) return {true,\
    \ c};\n    return {false, 0};\n  }\n\n  // return : (sum==x \u306B\u3067\u304D\
    \u308B\u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\u5408\u306B\u306F\u8FFD\
    \u52A0\u3059\u308B\n  pair<bool, UINT> solve_or_add(UINT x) {\n    UINT y = x,\
    \ c = 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i] != 0)) {\n\
    \        c ^= way[i], x ^= rbasis[i];\n      }\n    }\n    if (x == 0) return\
    \ {true, c};\n    int k = lowbit(x);\n    basis[rank] = y, rbasis[k] = x, way[k]\
    \ = c | UINT(1) << rank, ++rank;\n    return {false, 0};\n  }\n};\n#line 3 \"\
    nt/nimber/solve_quadratic.hpp\"\n\nnamespace NIMBER_QUADRATIC {\n// x^2+x==a \u3092\
    \u89E3\u304F. Trace(a)==0 \u304C\u5FC5\u8981.\n// Nimber \u3067\u306F Trace \u306F\
    \ topbit.\n// topbit==0 \u3067\u3042\u308B\u7A7A\u9593\u304B\u3089\u5076\u6570\
    \u5168\u4F53\u3078\u306E\u5168\u5358\u5C04\u304C\u3042\u308B.\n// \u3053\u308C\
    \u3092\u524D\u8A08\u7B97\u3057\u305F\u3044. \u7DDA\u5F62\u5199\u50CF\u306A\u306E\
    \u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F\u3092\u89E3\u3044\u3066\u57CB\u3081\u8FBC\
    \u3080\u3060\u3051\u3067\u3088\u3044.\n\nu64 Q[4][65536];\n\nvoid __attribute__((constructor))\
    \ precalc() {\n  Basis<63> B;\n  FOR(i, 63) {\n    Nimber64 x(u64(1) << (i + 1));\n\
    \    x = x.square() + x;\n    assert(!B.solve_or_add(x.val).fi);\n  }\n  FOR(k,\
    \ 63) {\n    int t = k / 16, i = k % 16;\n    u64 X = B.way[k] * 2;\n    FOR(s,\
    \ 1 << i) Q[t][s | 1 << i] = Q[t][s] ^ X;\n  }\n}\n\nu16 f(u16 a) { return Q[0][a];\
    \ }\nu32 f(u32 a) { return Q[0][a & 65535] ^ Q[1][a >> 16]; }\nu64 f(u64 a) {\
    \ return Q[0][a & 65535] ^ Q[1][a >> 16 & 65535] ^ Q[2][a >> 32 & 65535] ^ Q[3][a\
    \ >> 48 & 65535]; }\n\ntemplate <typename U>\nvc<U> solve_quadratic_1(U a) {\n\
    \  constexpr int k = numeric_limits<U>::digits - 1;\n  if (a >> k & 1) return\
    \ {};\n  return {f(a), U(f(a) | 1)};\n}\n} // namespace NIMBER_QUADRATIC\n\ntemplate\
    \ <typename F>\nvc<F> solve_quadratic(F a, F b) {\n  if (a == F(0)) return {b.sqrt()};\n\
    \  b /= a.square();\n  vc<F> ANS;\n  for (auto& x: NIMBER_QUADRATIC::solve_quadratic_1(b.val))\
    \ { ANS.eb(a * F(x)); }\n  return ANS;\n}\n#line 7 \"test/1_mytest/nimber.test.cpp\"\
    \n\ntemplate <typename U>\nvoid test() {\n  using F = Nimber<U>;\n  auto test\
    \ = [&](F x) -> void {\n    assert(x * x == x.square());\n    assert(x.sqrt().square()\
    \ == x);\n    if (x != F(0)) assert(x * x.inverse() == F(1));\n  };\n  FOR(i,\
    \ 1 << 20) { test(i); }\n  FOR(10000) { test(F(RNG_64())); }\n\n  auto test_q\
    \ = [&](F a, F x) -> void {\n    F b = x * x + a * x;\n    vc<F> ANS = solve_quadratic(a,\
    \ b);\n    for (auto& z: ANS) { assert(z * z + a * z == b); }\n    FOR(j, len(ANS))\
    \ FOR(i, j) { assert(ANS[i] != ANS[j]); }\n    int exist = 0;\n    FOR(i, len(ANS))\
    \ exist += (ANS[i] == x);\n    assert(exist == 1);\n  };\n  // quadratic\n  FOR(a,\
    \ 100) {\n    FOR(x, 100) { test_q(a, x); }\n  }\n  FOR(10000) { test_q(F(RNG_64()),\
    \ F(RNG_64())); }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test<u16>();\n  test<u32>();\n\
    \  test<u64>();\n  solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"nt/nimber/base.hpp\"\n#include \"\
    nt/nimber/solve_quadratic.hpp\"\n\ntemplate <typename U>\nvoid test() {\n  using\
    \ F = Nimber<U>;\n  auto test = [&](F x) -> void {\n    assert(x * x == x.square());\n\
    \    assert(x.sqrt().square() == x);\n    if (x != F(0)) assert(x * x.inverse()\
    \ == F(1));\n  };\n  FOR(i, 1 << 20) { test(i); }\n  FOR(10000) { test(F(RNG_64()));\
    \ }\n\n  auto test_q = [&](F a, F x) -> void {\n    F b = x * x + a * x;\n   \
    \ vc<F> ANS = solve_quadratic(a, b);\n    for (auto& z: ANS) { assert(z * z +\
    \ a * z == b); }\n    FOR(j, len(ANS)) FOR(i, j) { assert(ANS[i] != ANS[j]); }\n\
    \    int exist = 0;\n    FOR(i, len(ANS)) exist += (ANS[i] == x);\n    assert(exist\
    \ == 1);\n  };\n  // quadratic\n  FOR(a, 100) {\n    FOR(x, 100) { test_q(a, x);\
    \ }\n  }\n  FOR(10000) { test_q(F(RNG_64()), F(RNG_64())); }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test<u16>();\n  test<u32>();\n  test<u64>();\n  solve();\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - nt/nimber/base.hpp
  - nt/nimber/nimber_impl.hpp
  - nt/nimber/solve_quadratic.hpp
  - linalg/xor/basis.hpp
  - other/bit.hpp
  isVerificationFile: true
  path: test/1_mytest/nimber.test.cpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/nimber.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/nimber.test.cpp
- /verify/test/1_mytest/nimber.test.cpp.html
title: test/1_mytest/nimber.test.cpp
---
