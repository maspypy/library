---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/blackbox/vandermonde.hpp
    title: linalg/blackbox/vandermonde.hpp
  - icon: ':heavy_check_mark:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  - icon: ':question:'
    path: mod/crt3.hpp
    title: mod/crt3.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':heavy_check_mark:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':heavy_check_mark:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/ntt_doubling.hpp
    title: poly/ntt_doubling.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  - icon: ':heavy_check_mark:'
    path: poly/transposed_ntt.hpp
    title: poly/transposed_ntt.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/vandermonde.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n\
    #include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\
    \u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\
    \u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include\
    \ <bits/stdc++.h>\n#include <cassert>\n\nusing namespace std;\n\nusing ll = long\
    \ long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing\
    \ f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false = false;\n\
    \ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ numeric_limits<double>::infinity();\ntemplate <>\nconstexpr long double infty<long\
    \ double> =\n    numeric_limits<long double>::infinity();\n\nusing pi = pair<ll,\
    \ ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
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
    }\n#endif\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"poly/multipoint.hpp\"\n\n#line 1 \"poly/middle_product.hpp\"\
    \n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr u32 mod_pow_constexpr(u64\
    \ a, u64 n, u32 mod) {\n  a %= mod;\n  u64 res = 1;\n  FOR(32) {\n    if (n &\
    \ 1) res = res * a % mod;\n    a = a * a % mod, n /= 2;\n  }\n  return res;\n\
    }\n\ntemplate <typename T, u32 p0, u32 p1>\nT CRT2(u64 a0, u64 a1) {\n  static_assert(p0\
    \ < p1);\n  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);\n \
    \ u64 c = (a1 - a0 + p1) * x0_1 % p1;\n  return a0 + c * p0;\n}\n\ntemplate <typename\
    \ T, u32 p0, u32 p1, u32 p2>\nT CRT3(u64 a0, u64 a1, u64 a2) {\n  static_assert(p0\
    \ < p1 && p1 < p2);\n  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2,\
    \ p1);\n  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 -\
    \ 2, p2);\n  static constexpr u64 p01 = u64(p0) * p1;\n  u64 c = (a1 - a0 + p1)\
    \ * x1 % p1;\n  u64 ans_1 = a0 + c * p0;\n  c = (a2 - ans_1 % p2 + p2) * x2 %\
    \ p2;\n  return T(ans_1) + T(c) * T(p01);\n}\n\ntemplate <typename T, u32 p0,\
    \ u32 p1, u32 p2, u32 p3>\nT CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {\n  static_assert(p0\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"mod/modint_common.hpp\"\n\n\
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
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 5 \"poly/middle_product.hpp\"\n\n// n, m \u6B21\u591A\u9805\u5F0F (n>=m)\
    \ a, b \u2192 n-m \u6B21\u591A\u9805\u5F0F c\n// c[i] = sum_j b[j]a[i+j]\ntemplate\
    \ <typename mint>\nvc<mint> middle_product(vc<mint>& a, vc<mint>& b) {\n  assert(len(a)\
    \ >= len(b));\n  if (b.empty()) return vc<mint>(len(a) - len(b) + 1);\n  if (min(len(b),\
    \ len(a) - len(b) + 1) <= 60) {\n    return middle_product_naive(a, b);\n  }\n\
    \  if (!(mint::can_ntt())) {\n    return middle_product_garner(a, b);\n  } else\
    \ {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n), fb(n);\n    copy(a.begin(),\
    \ a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(), fb.begin());\n    ntt(fa,\
    \ 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n    ntt(fa, 1);\n    fa.resize(len(a));\n\
    \    fa.erase(fa.begin(), fa.begin() + len(b) - 1);\n    return fa;\n  }\n}\n\n\
    template <typename mint>\nvc<mint> middle_product_garner(vc<mint>& a, vc<mint>\
    \ b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n  static constexpr\
    \ int p0 = 167772161;\n  static constexpr int p1 = 469762049;\n  static constexpr\
    \ int p2 = 754974721;\n  using mint0 = modint<p0>;\n  using mint1 = modint<p1>;\n\
    \  using mint2 = modint<p2>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  vc<mint> c(len(c0));\n \
    \ FOR(i, n - m + 1) {\n    c[i] = CRT3<mint, p0, p1, p2>(c0[i].val, c1[i].val,\
    \ c2[i].val);\n  }\n  return c;\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_naive(vc<mint>&\
    \ a, vc<mint>& b) {\n  vc<mint> res(len(a) - len(b) + 1);\n  FOR(i, len(res))\
    \ FOR(j, len(b)) res[i] += b[j] * a[i + j];\n  return res;\n}\n#line 1 \"mod/all_inverse.hpp\"\
    \ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>& X) {\n  for (auto&&\
    \ x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint> res(N + 1);\n  res[0]\
    \ = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n\
    \  res.pop_back();\n  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n \
    \ return res;\n}\n#line 1 \"poly/fps_div.hpp\"\n\n#line 1 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\nint count_terms(const vc<mint>& f){\n  int t = 0;\n\
    \  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\n  return t;\n}\n#line 1 \"poly/count_terms.hpp\"\
    \ntemplate<typename mint>\nint count_terms(const vc<mint>& f){\n  int t = 0;\n\
    \  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\n  return t;\n}\n#line 1 \"poly/convolution.hpp\"\
    \n\n#line 1 \"mod/modint_common.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/convolution.hpp\"\n\ntemplate\
    \ <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n\
    \  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n + m - 1)\
    \ sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\
    \u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\
    \u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  if (mint::get_mod() == 2) {\n    vc<modint998> aa, bb;\n    for (auto&\
    \ x : a) aa.eb(x.val);\n    for (auto& x : b) bb.eb(x.val);\n    aa = convolution<modint998>(aa,\
    \ bb);\n    vc<mint> ANS(len(aa));\n    FOR(i, len(aa)) ANS[i] = aa[i].val & 1;\n\
    \    return ANS;\n  }\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 3 \"poly/fps_inv.hpp\"\n\ntemplate <typename mint>\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\n  int N = len(f);\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, N)\
    \ if (f[i] != mint(0)) dat.eb(i, f[i]);\n  vc<mint> g(N);\n  mint g0 = mint(1)\
    \ / f[0];\n  g[0] = g0;\n  FOR(n, 1, N) {\n    mint rhs = 0;\n    for (auto&&\
    \ [k, fk]: dat) {\n      if (k > n) break;\n      rhs -= fk * g[n - k];\n    }\n\
    \    g[n] = rhs * g0;\n  }\n  return g;\n}\n\ntemplate <typename mint>\nvc<mint>\
    \ fps_inv_dense_ntt(const vc<mint>& F) {\n  vc<mint> G = {mint(1) / F[0]};\n \
    \ ll N = len(F), n = 1;\n  G.reserve(N);\n  while (n < N) {\n    vc<mint> f(2\
    \ * n), g(2 * n);\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\n    FOR(i, n) g[i]\
    \ = G[i];\n    ntt(f, false), ntt(g, false);\n    FOR(i, 2 * n) f[i] *= g[i];\n\
    \    ntt(f, true);\n    FOR(i, n) f[i] = 0;\n    ntt(f, false);\n    FOR(i, 2\
    \ * n) f[i] *= g[i];\n    ntt(f, true);\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\n\
    \    n *= 2;\n  }\n  return G;\n}\n\ntemplate <typename mint>\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\n  const\
    \ int N = len(F);\n  vc<mint> R = {mint(1) / F[0]};\n  vc<mint> p;\n  int m =\
    \ 1;\n  while (m < N) {\n    p = convolution(R, R);\n    p.resize(m + m);\n  \
    \  vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\n    p = convolution(p,\
    \ f);\n    R.resize(m + m);\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\n  \
    \  m += m;\n  }\n  R.resize(N);\n  return R;\n}\n\ntemplate <typename mint>\n\
    vc<mint> fps_inv(const vc<mint>& f) {\n  assert(f[0] != mint(0));\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 160 : 820);\n  return (n <= t ? fps_inv_sparse<mint>(f)\
    \ : fps_inv_dense<mint>(f));\n}\n#line 4 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\
    \u9577\u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool\
    \ SPARSE = false>\nvc<mint> fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE ||\
    \ count_terms(g) < 200) return fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n\
    \  g = fps_inv<mint>(g);\n  f = convolution(f, g);\n  f.resize(n);\n  return f;\n\
    }\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint>\
    \ fps_div_sparse(vc<mint> f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint\
    \ cf = g[0].inverse();\n    for (auto&& x: f) x *= cf;\n    for (auto&& x: g)\
    \ x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] !=\
    \ mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f)) {\n    for (auto&& [j, x]: dat)\
    \ {\n      if (i >= j) f[i] += x * f[i - j];\n    }\n  }\n  return f;\n}\n#line\
    \ 1 \"poly/ntt_doubling.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x)\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 3 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\
    \u591A\u9805\u5F0F\u306E\u9577\u3055 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\
    \u3067 2^k+1 \u306B\u3059\u308B\ntemplate <typename mint, bool transposed = false>\n\
    void ntt_doubling(vector<mint>& a) {\n  static array<mint, 30> root;\n  static\
    \ bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    const int rank2\
    \ = mint::ntt_info().fi;\n    root[rank2] = mint::ntt_info().se;\n    FOR_R(i,\
    \ rank2) { root[i] = root[i + 1] * root[i + 1]; }\n  }\n\n  if constexpr (!transposed)\
    \ {\n    const int M = (int)a.size();\n    auto b = a;\n    ntt(b, 1);\n    mint\
    \ r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) b[i] *= r, r *= zeta;\n  \
    \  ntt(b, 0);\n    copy(begin(b), end(b), back_inserter(a));\n  } else {\n   \
    \ const int M = len(a) / 2;\n    vc<mint> tmp = {a.begin(), a.begin() + M};\n\
    \    a = {a.begin() + M, a.end()};\n    transposed_ntt(a, 0);\n    mint r = 1,\
    \ zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r *= zeta;\n    transposed_ntt(a,\
    \ 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n#line 1 \"poly/transposed_ntt.hpp\"\
    \n\ntemplate <class mint>\nvoid transposed_ntt(vector<mint>& a, bool inverse)\
    \ {\n  assert(mint::can_ntt());\n  const int rank2 = mint::ntt_info().fi;\n  const\
    \ u32 mod = mint::get_mod();\n  static array<mint, 30> root, iroot;\n  static\
    \ array<mint, 30> rate2, irate2;\n  static array<mint, 30> rate3, irate3;\n\n\
    \  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\n  static bool prepared\
    \ = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2] = mint::ntt_info().se;\n\
    \    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i, rank2) {\n      root[i]\
    \ = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\n\
    \    }\n    mint prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 2; i++)\
    \ {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i] = iroot[i + 2] * iprod;\n\
    \      prod *= iroot[i + 2];\n      iprod *= root[i + 2];\n    }\n    prod = 1,\
    \ iprod = 1;\n    for (int i = 0; i <= rank2 - 3; i++) {\n      rate3[i] = root[i\
    \ + 3] * prod;\n      irate3[i] = iroot[i + 3] * iprod;\n      prod *= iroot[i\
    \ + 3];\n      iprod *= root[i + 3];\n    }\n  }\n\n  int n = int(a.size());\n\
    \  int h = topbit(n);\n  assert(n == 1 << h);\n  if (!inverse) {\n    int len\
    \ = h;\n    while (len > 0) {\n      if (len == 1) {\n        int p = 1 << (h\
    \ - len);\n        mint rot = 1;\n        FOR(s, 1 << (len - 1)) {\n         \
    \ int offset = s << (h - len + 1);\n          FOR(i, p) {\n            u64 l =\
    \ a[i + offset].val;\n            u64 r = a[i + offset + p].val;\n           \
    \ a[i + offset] = l + r;\n            a[i + offset + p] = (mod + l - r) * rot.val;\n\
    \          }\n          rot *= rate2[topbit(~s & -~s)];\n        }\n        len--;\n\
    \      } else {\n        int p = 1 << (h - len);\n        mint rot = 1, imag =\
    \ root[2];\n        FOR(s, (1 << (len - 2))) {\n          int offset = s << (h\
    \ - len + 2);\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 *\
    \ rot;\n          for (int i = 0; i < p; i++) {\n            u64 a0 = a[i + offset\
    \ + 0 * p].val;\n            u64 a1 = a[i + offset + 1 * p].val;\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\n            u64 a3 = a[i + offset + 3 *\
    \ p].val;\n            u64 x = (mod + a2 - a3) * imag.val % mod;\n           \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n            a[i + offset + 1 * p] = (a0\
    \ + mod - a1 + x) * rot.val;\n            a[i + offset + 2 * p] = (a0 + a1 + 2\
    \ * mod - a2 - a3) * rot2.val;\n            a[i + offset + 3 * p] = (a0 + 2 *\
    \ mod - a1 - x) * rot3.val;\n          }\n          rot *= rate3[topbit(~s & -~s)];\n\
    \        }\n        len -= 2;\n      }\n    }\n  } else {\n    mint coef = mint(1)\
    \ / mint(len(a));\n    FOR(i, len(a)) a[i] *= coef;\n    int len = 0;\n    while\
    \ (len < h) {\n      if (len == h - 1) {\n        int p = 1 << (h - len - 1);\n\
    \        mint irot = 1;\n        FOR(s, 1 << len) {\n          int offset = s\
    \ << (h - len);\n          FOR(i, p) {\n            auto l = a[i + offset];\n\
    \            auto r = a[i + offset + p] * irot;\n            a[i + offset] = l\
    \ + r;\n            a[i + offset + p] = l - r;\n          }\n          irot *=\
    \ irate2[topbit(~s & -~s)];\n        }\n        len++;\n      } else {\n     \
    \   int p = 1 << (h - len - 2);\n        mint irot = 1, iimag = iroot[2];\n  \
    \      for (int s = 0; s < (1 << len); s++) {\n          mint irot2 = irot * irot;\n\
    \          mint irot3 = irot2 * irot;\n          int offset = s << (h - len);\n\
    \          for (int i = 0; i < p; i++) {\n            u64 mod2 = u64(mod) * mod;\n\
    \            u64 a0 = a[i + offset].val;\n            u64 a1 = u64(a[i + offset\
    \ + p].val) * irot.val;\n            u64 a2 = u64(a[i + offset + 2 * p].val) *\
    \ irot2.val;\n            u64 a3 = u64(a[i + offset + 3 * p].val) * irot3.val;\n\
    \            u64 a1na3imag = (a1 + mod2 - a3) % mod * iimag.val;\n           \
    \ u64 na2 = mod2 - a2;\n            a[i + offset] = a0 + a2 + a1 + a3;\n     \
    \       a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n          \
    \  a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n            a[i + offset + 3\
    \ * p] = a0 + na2 + (mod2 - a1na3imag);\n          }\n          irot *= irate3[topbit(~s\
    \ & -~s)];\n        }\n        len += 2;\n      }\n    }\n  }\n}\n#line 7 \"poly/multipoint.hpp\"\
    \n\ntemplate <typename mint>\nstruct SubproductTree {\n  int m;\n  int sz;\n \
    \ vc<vc<mint>> T;\n  SubproductTree(const vc<mint>& x) {\n    m = len(x);\n  \
    \  sz = 1;\n    while (sz < m) sz *= 2;\n    T.resize(2 * sz);\n    FOR(i, sz)\
    \ T[sz + i] = {1, (i < m ? -x[i] : 0)};\n    FOR3_R(i, 1, sz) T[i] = convolution(T[2\
    \ * i], T[2 * i + 1]);\n  }\n\n  vc<mint> evaluation(vc<mint> f) {\n    int n\
    \ = len(f);\n    if (n == 0) return vc<mint>(m, mint(0));\n    f.resize(2 * n\
    \ - 1);\n    vc<vc<mint>> g(2 * sz);\n    g[1] = T[1];\n    g[1].resize(n);\n\
    \    g[1] = fps_inv(g[1]);\n    g[1] = middle_product(f, g[1]);\n    g[1].resize(sz);\n\
    \n    FOR3(i, 1, sz) {\n      g[2 * i] = middle_product(g[i], T[2 * i + 1]);\n\
    \      g[2 * i + 1] = middle_product(g[i], T[2 * i]);\n    }\n    vc<mint> vals(m);\n\
    \    FOR(i, m) vals[i] = g[sz + i][0];\n    return vals;\n  }\n\n  vc<mint> interpolation(vc<mint>&\
    \ y) {\n    assert(len(y) == m);\n    vc<mint> a(m);\n    FOR(i, m) a[i] = T[1][m\
    \ - i - 1] * (i + 1);\n\n    a = evaluation(a);\n    vc<vc<mint>> t(2 * sz);\n\
    \    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};\n    FOR3_R(i, 1, sz)\
    \ {\n      t[i] = convolution(t[2 * i], T[2 * i + 1]);\n      auto tt = convolution(t[2\
    \ * i + 1], T[2 * i]);\n      FOR(k, len(t[i])) t[i][k] += tt[k];\n    }\n   \
    \ t[1].resize(m);\n    reverse(all(t[1]));\n    return t[1];\n  }\n};\n\ntemplate\
    \ <typename mint>\nvc<mint> multipoint_evaluation_ntt(vc<mint> f, vc<mint> point)\
    \ {\n  using poly = vc<mint>;\n  int n = 1, k = 0;\n  while (n < len(point)) n\
    \ *= 2, ++k;\n  vv(mint, F, k + 1, 2 * n);\n  FOR(i, len(point)) F[0][2 * i] =\
    \ -point[i];\n\n  FOR(d, k) {\n    int b = 1 << d;\n    for (int L = 0; L < 2\
    \ * n; L += 4 * b) {\n      poly f1 = {F[d].begin() + L, F[d].begin() + L + b};\n\
    \      poly f2 = {F[d].begin() + L + 2 * b, F[d].begin() + L + 3 * b};\n     \
    \ ntt_doubling(f1), ntt_doubling(f2);\n      FOR(i, b) f1[i] += 1, f2[i] += 1;\n\
    \      FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n      copy(all(f1), F[d].begin()\
    \ + L);\n      copy(all(f2), F[d].begin() + L + 2 * b);\n      FOR(i, 2 * b) {\
    \ F[d + 1][L + i] = f1[i] * f2[i] - 1; }\n    }\n  }\n  vc<mint> P = {F[k].begin(),\
    \ F[k].begin() + n};\n  ntt(P, 1), P.eb(1), reverse(all(P)), P.resize(len(f)),\
    \ P = fps_inv<mint>(P);\n  f.resize(n + len(P) - 1), f = middle_product<mint>(f,\
    \ P), reverse(all(f));\n  transposed_ntt(f, 1);\n  vc<mint>& G = f;\n  FOR_R(d,\
    \ k) {\n    vc<mint> nxt_G(n);\n    int b = 1 << d;\n    for (int L = 0; L < n;\
    \ L += 2 * b) {\n      vc<mint> g1(2 * b), g2(2 * b);\n      FOR(i, 2 * b) { g1[i]\
    \ = G[L + i] * F[d][2 * L + 2 * b + i]; }\n      FOR(i, 2 * b) { g2[i] = G[L +\
    \ i] * F[d][2 * L + i]; }\n      ntt_doubling<mint, true>(g1), ntt_doubling<mint,\
    \ true>(g2);\n      FOR(i, b) { nxt_G[L + i] = g1[i], nxt_G[L + b + i] = g2[i];\
    \ }\n    }\n    swap(G, nxt_G);\n  }\n  G.resize(len(point));\n  return G;\n}\n\
    \ntemplate <typename mint>\nvc<mint> multipoint_eval(vc<mint>& f, vc<mint>& x)\
    \ {\n  if (x.empty()) return {};\n  if (mint::can_ntt()) return multipoint_evaluation_ntt(f,\
    \ x);\n  SubproductTree<mint> F(x);\n  return F.evaluation(f);\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> multipoint_interpolate(vc<mint>& x, vc<mint>& y) {\n\
    \  if (x.empty()) return {};\n  SubproductTree<mint> F(x);\n  return F.interpolation(y);\n\
    }\n\n// calculate f(ar^k) for 0 <= k < m\ntemplate <typename mint>\nvc<mint> multipoint_eval_on_geom_seq(vc<mint>\
    \ f, mint a, mint r, int m) {\n  const int n = len(f);\n  if (m == 0) return {};\n\
    \n  auto eval = [&](mint x) -> mint {\n    mint fx = 0;\n    mint pow = 1;\n \
    \   FOR(i, n) fx += f[i] * pow, pow *= x;\n    return fx;\n  };\n\n  if (r ==\
    \ mint(0)) {\n    vc<mint> res(m);\n    FOR(i, 1, m) res[i] = f[0];\n    res[0]\
    \ = eval(a);\n    return res;\n  }\n  if (n < 60 || m < 60) {\n    vc<mint> res(m);\n\
    \    FOR(i, m) res[i] = eval(a), a *= r;\n    return res;\n  }\n  assert(r !=\
    \ mint(0));\n  // a == 1 \u306B\u5E30\u7740\n  mint pow_a = 1;\n  FOR(i, n) f[i]\
    \ *= pow_a, pow_a *= a;\n\n  auto calc = [&](mint r, int m) -> vc<mint> {\n  \
    \  // r^{t_i} \u306E\u8A08\u7B97\n    vc<mint> res(m);\n    mint pow = 1;\n  \
    \  res[0] = 1;\n    FOR(i, m - 1) {\n      res[i + 1] = res[i] * pow;\n      pow\
    \ *= r;\n    }\n    return res;\n  };\n\n  vc<mint> A = calc(r, n + m - 1), B\
    \ = calc(r.inverse(), max(n, m));\n  FOR(i, n) f[i] *= B[i];\n  f = middle_product(A,\
    \ f);\n  FOR(i, m) f[i] *= B[i];\n  return f;\n}\n\n// Y[i] = f(ar^i)\ntemplate\
    \ <typename mint>\nvc<mint> multipoint_interpolate_on_geom_seq(vc<mint> Y, mint\
    \ a, mint r) {\n  const int n = len(Y);\n  if (n == 0) return {};\n  if (n ==\
    \ 1) return {Y[0]};\n  assert(r != mint(0));\n  mint ir = r.inverse();\n\n  vc<mint>\
    \ POW(n + n - 1), tPOW(n + n - 1);\n  POW[0] = tPOW[0] = mint(1);\n  FOR(i, n\
    \ + n - 2) POW[i + 1] = POW[i] * r, tPOW[i + 1] = tPOW[i] * POW[i];\n\n  vc<mint>\
    \ iPOW(n + n - 1), itPOW(n + n - 1);\n  iPOW[0] = itPOW[0] = mint(1);\n  FOR(i,\
    \ n) iPOW[i + 1] = iPOW[i] * ir, itPOW[i + 1] = itPOW[i] * iPOW[i];\n\n  // prod_[1,i]\
    \ 1-r^k\n  vc<mint> S(n);\n  S[0] = mint(1);\n  FOR(i, 1, n) S[i] = S[i - 1] *\
    \ (mint(1) - POW[i]);\n  vc<mint> iS = all_inverse<mint>(S);\n  mint sn = S[n\
    \ - 1] * (mint(1) - POW[n]);\n\n  FOR(i, n) {\n    Y[i] = Y[i] * tPOW[n - 1 -\
    \ i] * itPOW[n - 1] * iS[i] * iS[n - 1 - i];\n    if (i % 2 == 1) Y[i] = -Y[i];\n\
    \  }\n\n  // sum_i Y[i] / 1-r^ix\n  FOR(i, n) Y[i] *= itPOW[i];\n  vc<mint> f\
    \ = middle_product(tPOW, Y);\n  FOR(i, n) f[i] *= itPOW[i];\n\n  // prod 1-r^ix\n\
    \  vc<mint> g(n);\n  g[0] = mint(1);\n  FOR(i, 1, n) {\n    g[i] = tPOW[i] * sn\
    \ * iS[i] * iS[n - i];\n    if (i % 2 == 1) g[i] = -g[i];\n  }\n  f = convolution<mint>(f,\
    \ g);\n  f.resize(n);\n\n  reverse(all(f));\n  mint ia = a.inverse();\n  mint\
    \ pow = 1;\n  FOR(i, n) f[i] *= pow, pow *= ia;\n  return f;\n}\n#line 1 \"poly/sum_of_rationals.hpp\"\
    \n\n#line 1 \"poly/convolution.hpp\"\n\n#line 1 \"mod/modint_common.hpp\"\n\n\
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
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/convolution.hpp\"\n\ntemplate\
    \ <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n\
    \  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n + m - 1)\
    \ sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\
    \u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\
    \u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  if (mint::get_mod() == 2) {\n    vc<modint998> aa, bb;\n    for (auto&\
    \ x : a) aa.eb(x.val);\n    for (auto& x : b) bb.eb(x.val);\n    aa = convolution<modint998>(aa,\
    \ bb);\n    vc<mint> ANS(len(aa));\n    FOR(i, len(aa)) ANS[i] = aa[i].val & 1;\n\
    \    return ANS;\n  }\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 1 \"poly/ntt_doubling.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 3 \"poly/ntt_doubling.hpp\"\n\n// 2^k \u6B21\
    \u591A\u9805\u5F0F\u306E\u9577\u3055 2^k \u304C\u4E0E\u3048\u3089\u308C\u308B\u306E\
    \u3067 2^k+1 \u306B\u3059\u308B\ntemplate <typename mint, bool transposed = false>\n\
    void ntt_doubling(vector<mint>& a) {\n  static array<mint, 30> root;\n  static\
    \ bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    const int rank2\
    \ = mint::ntt_info().fi;\n    root[rank2] = mint::ntt_info().se;\n    FOR_R(i,\
    \ rank2) { root[i] = root[i + 1] * root[i + 1]; }\n  }\n\n  if constexpr (!transposed)\
    \ {\n    const int M = (int)a.size();\n    auto b = a;\n    ntt(b, 1);\n    mint\
    \ r = 1, zeta = root[topbit(2 * M)];\n    FOR(i, M) b[i] *= r, r *= zeta;\n  \
    \  ntt(b, 0);\n    copy(begin(b), end(b), back_inserter(a));\n  } else {\n   \
    \ const int M = len(a) / 2;\n    vc<mint> tmp = {a.begin(), a.begin() + M};\n\
    \    a = {a.begin() + M, a.end()};\n    transposed_ntt(a, 0);\n    mint r = 1,\
    \ zeta = root[topbit(2 * M)];\n    FOR(i, M) a[i] *= r, r *= zeta;\n    transposed_ntt(a,\
    \ 1);\n    FOR(i, M) a[i] += tmp[i];\n  }\n}\n#line 4 \"poly/sum_of_rationals.hpp\"\
    \n\n// \u6709\u7406\u5F0F\u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002\u5206\
    \u5272\u7D71\u6CBB O(Nlog^2N)\u3002N \u306F\u6B21\u6570\u306E\u548C\u3002\ntemplate\
    \ <typename mint>\npair<vc<mint>, vc<mint>> sum_of_rationals(vc<pair<vc<mint>,\
    \ vc<mint>>> dat) {\n  if (len(dat) == 0) {\n    vc<mint> f = {0}, g = {1};\n\
    \    return {f, g};\n  }\n  using P = pair<vc<mint>, vc<mint>>;\n  auto add =\
    \ [&](P& a, P& b) -> P {\n    int na = len(a.fi) - 1, da = len(a.se) - 1;\n  \
    \  int nb = len(b.fi) - 1, db = len(b.se) - 1;\n    int n = max(na + db, da +\
    \ nb);\n    vc<mint> num(n + 1);\n    {\n      auto f = convolution(a.fi, b.se);\n\
    \      FOR(i, len(f)) num[i] += f[i];\n    }\n    {\n      auto f = convolution(a.se,\
    \ b.fi);\n      FOR(i, len(f)) num[i] += f[i];\n    }\n    auto den = convolution(a.se,\
    \ b.se);\n    return {num, den};\n  };\n\n  while (len(dat) > 1) {\n    int n\
    \ = len(dat);\n    FOR(i, 1, n, 2) { dat[i - 1] = add(dat[i - 1], dat[i]); }\n\
    \    FOR(i, ceil(n, 2)) dat[i] = dat[2 * i];\n    dat.resize(ceil(n, 2));\n  }\n\
    \  return dat[0];\n}\n\n// sum wt[i]/(1-A[i]x)\ntemplate <typename mint>\npair<vc<mint>,\
    \ vc<mint>> sum_of_rationals_1(vc<mint> A, vc<mint> wt) {\n  using poly = vc<mint>;\n\
    \  if (!mint::can_ntt()) {\n    vc<pair<poly, poly>> rationals;\n    FOR(i, len(A))\
    \ rationals.eb(poly({wt[i]}), poly({mint(1), -A[i]}));\n    return sum_of_rationals(rationals);\n\
    \  }\n  int n = 1;\n  while (n < len(A)) n *= 2;\n  int k = topbit(n);\n  vc<mint>\
    \ F(n), G(n);\n  vc<mint> nxt_F(n), nxt_G(n);\n  FOR(i, len(A)) F[i] = -A[i],\
    \ G[i] = wt[i];\n  int D = 6;\n\n  FOR(d, k) {\n    int b = 1 << d;\n    if (d\
    \ < D) {\n      fill(all(nxt_F), mint(0)), fill(all(nxt_G), mint(0));\n      for\
    \ (int L = 0; L < n; L += 2 * b) {\n        FOR(i, b) FOR(j, b) nxt_F[L + i +\
    \ j] += F[L + i] * F[L + b + j];\n        FOR(i, b) FOR(j, b) nxt_G[L + i + j]\
    \ += F[L + i] * G[L + b + j];\n        FOR(i, b) FOR(j, b) nxt_G[L + i + j] +=\
    \ F[L + b + i] * G[L + j];\n        FOR(i, b) nxt_F[L + b + i] += F[L + i] + F[L\
    \ + b + i];\n        FOR(i, b) nxt_G[L + b + i] += G[L + i] + G[L + b + i];\n\
    \      }\n    }\n    elif (d == D) {\n      for (int L = 0; L < n; L += 2 * b)\
    \ {\n        poly f1 = {F.begin() + L, F.begin() + L + b};\n        poly f2 =\
    \ {F.begin() + L + b, F.begin() + L + 2 * b};\n        poly g1 = {G.begin() +\
    \ L, G.begin() + L + b};\n        poly g2 = {G.begin() + L + b, G.begin() + L\
    \ + 2 * b};\n        f1.resize(2 * b), f2.resize(2 * b), g1.resize(2 * b), g2.resize(2\
    \ * b);\n        ntt(f1, 0), ntt(f2, 0), ntt(g1, 0), ntt(g2, 0);\n        FOR(i,\
    \ b) f1[i] += 1, f2[i] += 1;\n        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n\
    \        FOR(i, 2 * b) nxt_F[L + i] = f1[i] * f2[i] - 1;\n        FOR(i, 2 * b)\
    \ nxt_G[L + i] = g1[i] * f2[i] + g2[i] * f1[i];\n      }\n    }\n    else {\n\
    \      for (int L = 0; L < n; L += 2 * b) {\n        poly f1 = {F.begin() + L,\
    \ F.begin() + L + b};\n        poly f2 = {F.begin() + L + b, F.begin() + L + 2\
    \ * b};\n        poly g1 = {G.begin() + L, G.begin() + L + b};\n        poly g2\
    \ = {G.begin() + L + b, G.begin() + L + 2 * b};\n        ntt_doubling(f1), ntt_doubling(f2),\
    \ ntt_doubling(g1), ntt_doubling(g2);\n        FOR(i, b) f1[i] += 1, f2[i] +=\
    \ 1;\n        FOR(i, b, 2 * b) f1[i] -= 1, f2[i] -= 1;\n        FOR(i, 2 * b)\
    \ nxt_F[L + i] = f1[i] * f2[i] - 1;\n        FOR(i, 2 * b) nxt_G[L + i] = g1[i]\
    \ * f2[i] + g2[i] * f1[i];\n      }\n    }\n    swap(F, nxt_F), swap(G, nxt_G);\n\
    \  }\n  if (k - 1 >= D) ntt(F, 1), ntt(G, 1);\n  F.eb(1);\n  reverse(all(F)),\
    \ reverse(all(G));\n  F.resize(len(A) + 1);\n  G.resize(len(A));\n  return {G,\
    \ F};\n}\n#line 1 \"poly/fps_div.hpp\"\n\n#line 1 \"poly/count_terms.hpp\"\ntemplate<typename\
    \ mint>\nint count_terms(const vc<mint>& f){\n  int t = 0;\n  FOR(i, len(f)) if(f[i]\
    \ != mint(0)) ++t;\n  return t;\n}\n#line 1 \"poly/count_terms.hpp\"\ntemplate<typename\
    \ mint>\nint count_terms(const vc<mint>& f){\n  int t = 0;\n  FOR(i, len(f)) if(f[i]\
    \ != mint(0)) ++t;\n  return t;\n}\n#line 1 \"poly/convolution.hpp\"\n\n#line\
    \ 1 \"mod/modint_common.hpp\"\n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x)\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 3 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod\
    \ = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint> dat\
    \ = {1, 1};\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i\
    \ - 1] * mint::raw(i);\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\n\
    mint fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  if (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    dat[m - 1] = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i]\
    \ = dat[i + 1] * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class\
    \ mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\u592B\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\nll mod_inv(ll\
    \ val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n  val %= mod;\n\
    \  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v = 0, t;\n  while\
    \ (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -= t * v, v);\n \
    \ }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 1 \"mod/crt3.hpp\"\n\nconstexpr\
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
    \ T(ans_3) + T(c) * T(p01) * T(p23);\n}\n#line 1 \"poly/convolution_naive.hpp\"\
    \n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>\n\
    vc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()),\
    \ m = int(b.size());\n  if (n > m) return convolution_naive<T>(b, a);\n  if (n\
    \ == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j, m) ans[i +\
    \ j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename enable_if<has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vc<T> ans(n + m - 1);\n  if (n <= 16 && (T::get_mod()\
    \ < (1 << 30))) {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0,\
    \ k - m + 1);\n      int t = min(n, k + 1);\n      u64 sm = 0;\n      for (int\
    \ i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] =\
    \ sm;\n    }\n  } else {\n    for (int k = 0; k < n + m - 1; ++k) {\n      int\
    \ s = max(0, k - m + 1);\n      int t = min(n, k + 1);\n      u128 sm = 0;\n \
    \     for (int i = s; i < t; ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n\
    \      ans[k] = T::raw(sm % T::get_mod());\n    }\n  }\n  return ans;\n}\n#line\
    \ 1 \"poly/convolution_naive.hpp\"\n\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\nvc<T> convolution_naive(const vc<T>& a, const vc<T>& b) {\n  int\
    \ n = int(a.size()), m = int(b.size());\n  if (n > m) return convolution_naive<T>(b,\
    \ a);\n  if (n == 0) return {};\n  vector<T> ans(n + m - 1);\n  FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\n  return ans;\n}\n\ntemplate <class T, typename\
    \ enable_if<has_mod<T>::value>::type* = nullptr>\nvc<T> convolution_naive(const\
    \ vc<T>& a, const vc<T>& b) {\n  int n = int(a.size()), m = int(b.size());\n \
    \ if (n > m) return convolution_naive<T>(b, a);\n  if (n == 0) return {};\n  vc<T>\
    \ ans(n + m - 1);\n  if (n <= 16 && (T::get_mod() < (1 << 30))) {\n    for (int\
    \ k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n      int t\
    \ = min(n, k + 1);\n      u64 sm = 0;\n      for (int i = s; i < t; ++i) { sm\
    \ += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = sm;\n    }\n  } else {\n\
    \    for (int k = 0; k < n + m - 1; ++k) {\n      int s = max(0, k - m + 1);\n\
    \      int t = min(n, k + 1);\n      u128 sm = 0;\n      for (int i = s; i < t;\
    \ ++i) { sm += u64(a[i].val) * (b[k - i].val); }\n      ans[k] = T::raw(sm % T::get_mod());\n\
    \    }\n  }\n  return ans;\n}\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n\
    // \u4EFB\u610F\u306E\u74B0\u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T>\
    \ convolution_karatsuba(const vc<T>& f, const vc<T>& g) {\n  const int thresh\
    \ = 30;\n  if (min(len(f), len(g)) <= thresh) return convolution_naive(f, g);\n\
    \  int n = max(len(f), len(g));\n  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n\
    \  if (len(f) < m) f1 = f;\n  if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n\
    \  if (len(f) >= m) f2 = {f.begin() + m, f.end()};\n  if (len(g) < m) g1 = g;\n\
    \  if (len(g) >= m) g1 = {g.begin(), g.begin() + m};\n  if (len(g) >= m) g2 =\
    \ {g.begin() + m, g.end()};\n  vc<T> a = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ b = convolution_karatsuba(f2, g2);\n  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i,\
    \ len(g2)) g1[i] += g2[i];\n  vc<T> c = convolution_karatsuba(f1, g1);\n  vc<T>\
    \ F(len(f) + len(g) - 1);\n  assert(2 * m + len(b) <= len(F));\n  FOR(i, len(a))\
    \ F[i] += a[i], c[i] -= a[i];\n  FOR(i, len(b)) F[2 * m + i] += b[i], c[i] -=\
    \ b[i];\n  if (c.back() == T(0)) c.pop_back();\n  FOR(i, len(c)) if (c[i] != T(0))\
    \ F[m + i] += c[i];\n  return F;\n}\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int\
    \ x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n  \
    \  int operator*() const { return lowbit(s); }\n    void operator++() { s &= s\
    \ - 1; }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"poly/ntt.hpp\"\n\ntemplate <class mint>\nvoid\
    \ ntt(vector<mint>& a, bool inverse) {\n  assert(mint::can_ntt());\n  const int\
    \ rank2 = mint::ntt_info().fi;\n  const u32 mod = mint::get_mod();\n  static array<mint,\
    \ 30> root, iroot;\n  static array<mint, 30> rate2, irate2;\n  static array<mint,\
    \ 30> rate3, irate3;\n\n  assert(rank2 != -1 && len(a) <= (1 << max(0, rank2)));\n\
    \n  static bool prepared = 0;\n  if (!prepared) {\n    prepared = 1;\n    root[rank2]\
    \ = mint::ntt_info().se;\n    iroot[rank2] = mint(1) / root[rank2];\n    FOR_R(i,\
    \ rank2) {\n      root[i] = root[i + 1] * root[i + 1];\n      iroot[i] = iroot[i\
    \ + 1] * iroot[i + 1];\n    }\n    mint prod = 1, iprod = 1;\n    for (int i =\
    \ 0; i <= rank2 - 2; i++) {\n      rate2[i] = root[i + 2] * prod;\n      irate2[i]\
    \ = iroot[i + 2] * iprod;\n      prod *= iroot[i + 2];\n      iprod *= root[i\
    \ + 2];\n    }\n    prod = 1, iprod = 1;\n    for (int i = 0; i <= rank2 - 3;\
    \ i++) {\n      rate3[i] = root[i + 3] * prod;\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\n      prod *= iroot[i + 3];\n      iprod *= root[i + 3];\n    }\n\
    \  }\n\n  int n = int(a.size());\n  int h = topbit(n);\n  assert(n == 1 << h);\n\
    \  if (!inverse) {\n    int len = 0;\n    while (len < h) {\n      if (h - len\
    \ == 1) {\n        int p = 1 << (h - len - 1);\n        mint rot = 1;\n      \
    \  FOR(s, 1 << len) {\n          int offset = s << (h - len);\n          FOR(i,\
    \ p) {\n            auto l = a[i + offset];\n            auto r = a[i + offset\
    \ + p] * rot;\n            a[i + offset] = l + r;\n            a[i + offset +\
    \ p] = l - r;\n          }\n          rot *= rate2[topbit(~s & -~s)];\n      \
    \  }\n        len++;\n      } else {\n        int p = 1 << (h - len - 2);\n  \
    \      mint rot = 1, imag = root[2];\n        for (int s = 0; s < (1 << len);\
    \ s++) {\n          mint rot2 = rot * rot;\n          mint rot3 = rot2 * rot;\n\
    \          int offset = s << (h - len);\n          for (int i = 0; i < p; i++)\
    \ {\n            u64 mod2 = u64(mod) * mod;\n            u64 a0 = a[i + offset].val;\n\
    \            u64 a1 = u64(a[i + offset + p].val) * rot.val;\n            u64 a2\
    \ = u64(a[i + offset + 2 * p].val) * rot2.val;\n            u64 a3 = u64(a[i +\
    \ offset + 3 * p].val) * rot3.val;\n            u64 a1na3imag = (a1 + mod2 - a3)\
    \ % mod * imag.val;\n            u64 na2 = mod2 - a2;\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n \
    \           a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n         \
    \ }\n          rot *= rate3[topbit(~s & -~s)];\n        }\n        len += 2;\n\
    \      }\n    }\n  } else {\n    mint coef = mint(1) / mint(len(a));\n    FOR(i,\
    \ len(a)) a[i] *= coef;\n    int len = h;\n    while (len) {\n      if (len ==\
    \ 1) {\n        int p = 1 << (h - len);\n        mint irot = 1;\n        FOR(s,\
    \ 1 << (len - 1)) {\n          int offset = s << (h - len + 1);\n          FOR(i,\
    \ p) {\n            u64 l = a[i + offset].val;\n            u64 r = a[i + offset\
    \ + p].val;\n            a[i + offset] = l + r;\n            a[i + offset + p]\
    \ = (mod + l - r) * irot.val;\n          }\n          irot *= irate2[topbit(~s\
    \ & -~s)];\n        }\n        len--;\n      } else {\n        int p = 1 << (h\
    \ - len);\n        mint irot = 1, iimag = iroot[2];\n        FOR(s, (1 << (len\
    \ - 2))) {\n          mint irot2 = irot * irot;\n          mint irot3 = irot2\
    \ * irot;\n          int offset = s << (h - len + 2);\n          for (int i =\
    \ 0; i < p; i++) {\n            u64 a0 = a[i + offset + 0 * p].val;\n        \
    \    u64 a1 = a[i + offset + 1 * p].val;\n            u64 a2 = a[i + offset +\
    \ 2 * p].val;\n            u64 a3 = a[i + offset + 3 * p].val;\n            u64\
    \ x = (mod + a2 - a3) * iimag.val % mod;\n            a[i + offset] = a0 + a1\
    \ + a2 + a3;\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\n\
    \            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\n\
    \            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\n  \
    \        }\n          irot *= irate3[topbit(~s & -~s)];\n        }\n        len\
    \ -= 2;\n      }\n    }\n  }\n}\n#line 8 \"poly/convolution.hpp\"\n\ntemplate\
    \ <class mint>\nvector<mint> convolution_ntt(vector<mint> a, vector<mint> b) {\n\
    \  assert(mint::can_ntt());\n  if (a.empty() || b.empty()) return {};\n  int n\
    \ = int(a.size()), m = int(b.size());\n  int sz = 1;\n  while (sz < n + m - 1)\
    \ sz *= 2;\n\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\
    \u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\
    \u306E\u3067\u3002\n  if ((n + m - 3) <= sz / 2) {\n    auto a_last = a.back(),\
    \ b_last = b.back();\n    a.pop_back(), b.pop_back();\n    auto c = convolution(a,\
    \ b);\n    c.resize(n + m - 1);\n    c[n + m - 2] = a_last * b_last;\n    FOR(i,\
    \ len(a)) c[i + len(b)] += a[i] * b_last;\n    FOR(i, len(b)) c[i + len(a)] +=\
    \ b[i] * a_last;\n    return c;\n  }\n\n  a.resize(sz), b.resize(sz);\n  bool\
    \ same = a == b;\n  ntt(a, 0);\n  if (same) {\n    b = a;\n  } else {\n    ntt(b,\
    \ 0);\n  }\n  FOR(i, sz) a[i] *= b[i];\n  ntt(a, 1);\n  a.resize(n + m - 1);\n\
    \  return a;\n}\n\ntemplate <typename mint>\nvector<mint> convolution_garner(const\
    \ vector<mint>& a, const vector<mint>& b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  static constexpr int p0 = 167772161;\n  static constexpr\
    \ int p1 = 469762049;\n  static constexpr int p2 = 754974721;\n  using mint0 =\
    \ modint<p0>;\n  using mint1 = modint<p1>;\n  using mint2 = modint<p2>;\n  vc<mint0>\
    \ a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i,\
    \ n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i] = a[i].val;\n  FOR(i, m) b0[i]\
    \ = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n  auto c0 = convolution_ntt<mint0>(a0,\
    \ b0);\n  auto c1 = convolution_ntt<mint1>(a1, b1);\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\n  vc<mint> c(len(c0));\n  FOR(i, n + m - 1) {\n    c[i] = CRT3<mint, p0,\
    \ p1, p2>(c0[i].val, c1[i].val, c2[i].val);\n  }\n  return c;\n}\n\nvector<ll>\
    \ convolution(vector<ll> a, vector<ll> b) {\n  int n = len(a), m = len(b);\n \
    \ if (!n || !m) return {};\n  if (min(n, m) <= 2500) return convolution_naive(a,\
    \ b);\n\n  ll mi_a = MIN(a), mi_b = MIN(b);\n  for (auto& x : a) x -= mi_a;\n\
    \  for (auto& x : b) x -= mi_b;\n  assert(MAX(a) * MAX(b) <= 1e18);\n\n  auto\
    \ Ac = cumsum<ll>(a), Bc = cumsum<ll>(b);\n  vi res(n + m - 1);\n  for (int k\
    \ = 0; k < n + m - 1; ++k) {\n    int s = max(0, k - m + 1);\n    int t = min(n,\
    \ k + 1);\n    res[k] += (t - s) * mi_a * mi_b;\n    res[k] += mi_a * (Bc[k -\
    \ s + 1] - Bc[k - t + 1]);\n    res[k] += mi_b * (Ac[t] - Ac[s]);\n  }\n\n  static\
    \ constexpr u32 MOD1 = 1004535809;\n  static constexpr u32 MOD2 = 1012924417;\n\
    \  using mint1 = modint<MOD1>;\n  using mint2 = modint<MOD2>;\n\n  vc<mint1> a1(n),\
    \ b1(m);\n  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i];\n\
    \  FOR(i, m) b1[i] = b[i], b2[i] = b[i];\n\n  auto c1 = convolution_ntt<mint1>(a1,\
    \ b1);\n  auto c2 = convolution_ntt<mint2>(a2, b2);\n\n  FOR(i, n + m - 1) { res[i]\
    \ += CRT2<u64, MOD1, MOD2>(c1[i].val, c2[i].val); }\n  return res;\n}\n\ntemplate\
    \ <typename mint>\nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b)\
    \ {\n  if (mint::get_mod() == 2) {\n    vc<modint998> aa, bb;\n    for (auto&\
    \ x : a) aa.eb(x.val);\n    for (auto& x : b) bb.eb(x.val);\n    aa = convolution<modint998>(aa,\
    \ bb);\n    vc<mint> ANS(len(aa));\n    FOR(i, len(aa)) ANS[i] = aa[i].val & 1;\n\
    \    return ANS;\n  }\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  if (mint::can_ntt()) {\n    if (min(n, m) <= 50) return convolution_karatsuba<mint>(a,\
    \ b);\n    return convolution_ntt(a, b);\n  }\n  if (min(n, m) <= 200) return\
    \ convolution_karatsuba<mint>(a, b);\n  return convolution_garner(a, b);\n}\n\
    #line 3 \"poly/fps_inv.hpp\"\n\ntemplate <typename mint>\nvc<mint> fps_inv_sparse(const\
    \ vc<mint>& f) {\n  int N = len(f);\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, N)\
    \ if (f[i] != mint(0)) dat.eb(i, f[i]);\n  vc<mint> g(N);\n  mint g0 = mint(1)\
    \ / f[0];\n  g[0] = g0;\n  FOR(n, 1, N) {\n    mint rhs = 0;\n    for (auto&&\
    \ [k, fk]: dat) {\n      if (k > n) break;\n      rhs -= fk * g[n - k];\n    }\n\
    \    g[n] = rhs * g0;\n  }\n  return g;\n}\n\ntemplate <typename mint>\nvc<mint>\
    \ fps_inv_dense_ntt(const vc<mint>& F) {\n  vc<mint> G = {mint(1) / F[0]};\n \
    \ ll N = len(F), n = 1;\n  G.reserve(N);\n  while (n < N) {\n    vc<mint> f(2\
    \ * n), g(2 * n);\n    FOR(i, min(N, 2 * n)) f[i] = F[i];\n    FOR(i, n) g[i]\
    \ = G[i];\n    ntt(f, false), ntt(g, false);\n    FOR(i, 2 * n) f[i] *= g[i];\n\
    \    ntt(f, true);\n    FOR(i, n) f[i] = 0;\n    ntt(f, false);\n    FOR(i, 2\
    \ * n) f[i] *= g[i];\n    ntt(f, true);\n    FOR(i, n, min(N, 2 * n)) G.eb(-f[i]);\n\
    \    n *= 2;\n  }\n  return G;\n}\n\ntemplate <typename mint>\nvc<mint> fps_inv_dense(const\
    \ vc<mint>& F) {\n  if (mint::can_ntt()) return fps_inv_dense_ntt(F);\n  const\
    \ int N = len(F);\n  vc<mint> R = {mint(1) / F[0]};\n  vc<mint> p;\n  int m =\
    \ 1;\n  while (m < N) {\n    p = convolution(R, R);\n    p.resize(m + m);\n  \
    \  vc<mint> f = {F.begin(), F.begin() + min(m + m, N)};\n    p = convolution(p,\
    \ f);\n    R.resize(m + m);\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\n  \
    \  m += m;\n  }\n  R.resize(N);\n  return R;\n}\n\ntemplate <typename mint>\n\
    vc<mint> fps_inv(const vc<mint>& f) {\n  assert(f[0] != mint(0));\n  int n = count_terms(f);\n\
    \  int t = (mint::can_ntt() ? 160 : 820);\n  return (n <= t ? fps_inv_sparse<mint>(f)\
    \ : fps_inv_dense<mint>(f));\n}\n#line 4 \"poly/fps_div.hpp\"\n\n// f/g. f \u306E\
    \u9577\u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate <typename mint, bool\
    \ SPARSE = false>\nvc<mint> fps_div(vc<mint> f, vc<mint> g) {\n  if (SPARSE ||\
    \ count_terms(g) < 200) return fps_div_sparse(f, g);\n  int n = len(f);\n  g.resize(n);\n\
    \  g = fps_inv<mint>(g);\n  f = convolution(f, g);\n  f.resize(n);\n  return f;\n\
    }\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\ntemplate <typename mint>\nvc<mint>\
    \ fps_div_sparse(vc<mint> f, vc<mint>& g) {\n  if (g[0] != mint(1)) {\n    mint\
    \ cf = g[0].inverse();\n    for (auto&& x: f) x *= cf;\n    for (auto&& x: g)\
    \ x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n  FOR(i, 1, len(g)) if (g[i] !=\
    \ mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f)) {\n    for (auto&& [j, x]: dat)\
    \ {\n      if (i >= j) f[i] += x * f[i - j];\n    }\n  }\n  return f;\n}\n#line\
    \ 4 \"linalg/blackbox/vandermonde.hpp\"\n\n// transpose = 0\uFF1Ag[p] = sum pow(ap,q)\
    \ f[q]\n// transpose = 1\uFF1Ag[p] = sum pow(aq,p) f[q]\n// (false, false) = multipoint\
    \ eval\n// (false, true) = multipoint interpolate\n// (true, false) = sum of rationals\n\
    // (true, true) = partial frac decomposition (fps -> coefs)\ntemplate <typename\
    \ mint>\nvc<mint> vandermonde(vc<mint> f, vc<mint> A, bool transpose, bool inverse)\
    \ {\n  if (len(f) == 0) return vc<mint>();\n  int N = len(f);\n  if (!transpose)\
    \ {\n    if (!inverse) { return multipoint_eval(f, A); }\n    if (inverse) { return\
    \ multipoint_interpolate(A, f); }\n  }\n  if (!inverse) {\n    auto [num, den]\
    \ = sum_of_rationals_1<mint>(A, f);\n    num.resize(N);\n    return fps_div(num,\
    \ den);\n  }\n  SubproductTree<mint> X(A);\n  vc<mint> g = X.T[1]; // prod(1-ax)\n\
    \  g.resize(N + 1);\n  f = convolution<mint>(f, g);\n  f.resize(N);\n  reverse(all(f));\n\
    \  reverse(all(g));\n  FOR(i, len(g) - 1) g[i] = g[i + 1] * mint(i + 1);\n  g.pop_back();\n\
    \  auto num = X.evaluation(f);\n  auto den = X.evaluation(g);\n  vc<mint> B(len(A));\n\
    \  FOR(i, len(A)) B[i] = num[i] / den[i];\n  return B;\n}\n#line 6 \"test/1_mytest/vandermonde.test.cpp\"\
    \n\ntemplate <typename mint>\nvc<mint> naive(vc<mint> f, vc<mint> A, bool transpose)\
    \ {\n  assert(len(f) == len(A));\n  int N = len(f);\n  vc<mint> g(N);\n  if (!transpose)\
    \ { FOR(i, N) FOR(j, N) g[i] += A[i].pow(j) * f[j]; }\n  if (transpose) { FOR(i,\
    \ N) FOR(j, N) g[i] += A[j].pow(i) * f[j]; }\n  return g;\n}\n\nusing mint = modint998;\n\
    vc<mint> gen(int n) {\n  vc<mint> f(n);\n  set<mint> ss;\n  FOR(i, n) {\n    while\
    \ (1) {\n      mint x = RNG(-100, 100);\n      if (ss.count(x)) continue;\n  \
    \    ss.insert(x);\n      f[i] = x;\n      break;\n    }\n  }\n  return f;\n}\n\
    \nvoid test() {\n  FOR(t, 2) {\n    FOR(n, 100) {\n      auto f = gen(n), A =\
    \ gen(n);\n      auto g = vandermonde<mint>(f, A, t, 0);\n      auto g1 = naive(f,\
    \ A, t);\n      assert(g == g1);\n      auto f1 = vandermonde<mint>(g, A, t, 1);\n\
    \      assert(f == f1);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"random/base.hpp\"\n#include \"linalg/blackbox/vandermonde.hpp\"\
    \n\ntemplate <typename mint>\nvc<mint> naive(vc<mint> f, vc<mint> A, bool transpose)\
    \ {\n  assert(len(f) == len(A));\n  int N = len(f);\n  vc<mint> g(N);\n  if (!transpose)\
    \ { FOR(i, N) FOR(j, N) g[i] += A[i].pow(j) * f[j]; }\n  if (transpose) { FOR(i,\
    \ N) FOR(j, N) g[i] += A[j].pow(i) * f[j]; }\n  return g;\n}\n\nusing mint = modint998;\n\
    vc<mint> gen(int n) {\n  vc<mint> f(n);\n  set<mint> ss;\n  FOR(i, n) {\n    while\
    \ (1) {\n      mint x = RNG(-100, 100);\n      if (ss.count(x)) continue;\n  \
    \    ss.insert(x);\n      f[i] = x;\n      break;\n    }\n  }\n  return f;\n}\n\
    \nvoid test() {\n  FOR(t, 2) {\n    FOR(n, 100) {\n      auto f = gen(n), A =\
    \ gen(n);\n      auto g = vandermonde<mint>(f, A, t, 0);\n      auto g1 = naive(f,\
    \ A, t);\n      assert(g == g1);\n      auto f1 = vandermonde<mint>(g, A, t, 1);\n\
    \      assert(f == f1);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >>\
    \ a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - linalg/blackbox/vandermonde.hpp
  - poly/multipoint.hpp
  - poly/middle_product.hpp
  - poly/ntt.hpp
  - other/bit.hpp
  - mod/crt3.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/all_inverse.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt_doubling.hpp
  - poly/transposed_ntt.hpp
  - poly/sum_of_rationals.hpp
  isVerificationFile: true
  path: test/1_mytest/vandermonde.test.cpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/vandermonde.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/vandermonde.test.cpp
- /verify/test/1_mytest/vandermonde.test.cpp.html
title: test/1_mytest/vandermonde.test.cpp
---
