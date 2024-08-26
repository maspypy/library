---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/mybitset.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\n\
    template <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128\
    \ infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/mybitset.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                  \
    \   chrono::high_resolution_clock::now().time_since_epoch())\n               \
    \      .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"ds/my_bitset.hpp\"\n\n\
    // https://codeforces.com/contest/914/problem/F\n// https://yukicoder.me/problems/no/142\n\
    // \u308F\u305A\u304B\u306B\u666E\u901A\u306E bitset \u3088\u308A\u9045\u3044\u3068\
    \u304D\u3082\u3042\u308B\u3088\u3046\u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\
    \u3057\u305F\u304F\u306A\u3044\u3068\u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\
    \u8981\u306A\u3068\u304D\u306B\u4F7F\u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n\
    \  int N;\n  vc<u64> dat;\n\n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int\
    \ N = 0, int x = 0) : N(N) {\n    assert(x == 0 || x == 1);\n    u64 v = (x ==\
    \ 0 ? 0 : -1);\n    dat.assign((N + 63) >> 6, v);\n    if (N) dat.back() >>= (64\
    \ * len(dat) - N);\n  }\n\n  int size() { return N; }\n\n  void resize(int size)\
    \ {\n    dat.resize((size + 63) >> 6);\n    int remainingBits = size & 63;\n \
    \   if (remainingBits != 0) {\n      u64 mask = (u64(1) << remainingBits) - 1;\n\
    \      dat.back() &= mask;\n    }\n    N = size;\n  }\n\n  // thanks to chatgpt!\n\
    \  class Proxy {\n  public:\n    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n\
    \    operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }\n\
    \n    Proxy &operator=(u64 value) {\n      dat[index >> 6] &= ~(u64(1) << (index\
    \ & 63));\n      dat[index >> 6] |= (value & 1) << (index & 63);\n      return\
    \ *this;\n    }\n    void flip() {\n      dat[index >> 6] ^= (u64(1) << (index\
    \ & 63)); // XOR to flip the bit\n    }\n\n  private:\n    vc<u64> &dat;\n   \
    \ int index;\n  };\n\n  Proxy operator[](int i) { return Proxy(dat, i); }\n\n\
    \  bool operator==(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ if (dat[i] != p.dat[i]) return false;\n    return true;\n  }\n\n  T &operator&=(const\
    \ T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n \
    \   return *this;\n  }\n  T &operator|=(const T &p) {\n    assert(N == p.N);\n\
    \    FOR(i, len(dat)) dat[i] |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const\
    \ T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n \
    \   return *this;\n  }\n  T operator&(const T &p) const { return T(*this) &= p;\
    \ }\n  T operator|(const T &p) const { return T(*this) |= p; }\n  T operator^(const\
    \ T &p) const { return T(*this) ^= p; }\n  T operator~() const {\n    T p = (*this);\n\
    \    p.flip_range(0, N);\n    return p;\n  }\n\n  int count() {\n    int ans =\
    \ 0;\n    for (u64 val: dat) ans += popcnt(val);\n    return ans;\n  }\n\n  int\
    \ next(int i) {\n    chmax(i, 0);\n    if (i >= N) return N;\n    int k = i >>\
    \ 6;\n    {\n      u64 x = dat[k];\n      int s = i & 63;\n      x = (x >> s)\
    \ << s;\n      if (x) return (k << 6) | lowbit(x);\n    }\n    FOR(idx, k + 1,\
    \ len(dat)) {\n      if (dat[idx] == 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n\
    \    }\n    return N;\n  }\n\n  int prev(int i) {\n    chmin(i, N - 1);\n    if\
    \ (i <= -1) return -1;\n    int k = i >> 6;\n    if ((i & 63) < 63) {\n      u64\
    \ x = dat[k];\n      x &= (u64(1) << ((i & 63) + 1)) - 1;\n      if (x) return\
    \ (k << 6) | topbit(x);\n      --k;\n    }\n    FOR_R(idx, k + 1) {\n      if\
    \ (dat[idx] == 0) continue;\n      return (idx << 6) | topbit(dat[idx]);\n   \
    \ }\n    return -1;\n  }\n\n  My_Bitset range(int L, int R) {\n    assert(L <=\
    \ R);\n    My_Bitset p(R - L);\n    int rm = (R - L) & 63;\n    FOR(rm) {\n  \
    \    p[R - L - 1] = bool((*this)[R - 1]);\n      --R;\n    }\n    int n = (R -\
    \ L) >> 6;\n    int hi = L & 63;\n    int lo = 64 - hi;\n    int s = L >> 6;\n\
    \    if (hi == 0) {\n      FOR(i, n) { p.dat[i] ^= dat[s + i]; }\n    } else {\n\
    \      FOR(i, n) { p.dat[i] ^= (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }\n\
    \    }\n    return p;\n  }\n\n  int count_range(int L, int R) {\n    assert(L\
    \ <= R);\n    int cnt = 0;\n    while ((L < R) && (L & 63)) cnt += (*this)[L++];\n\
    \    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r =\
    \ R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n \
    \ // [L,R) \u306B p \u3092\u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset\
    \ &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R\
    \ && (L & 63)) { (*this)[L++] = bool(p[a++]); }\n    while (L < R && (R & 63))\
    \ { (*this)[--R] = bool(p[--b]); }\n    // p[a:b] \u3092 [L:R] \u306B\n    int\
    \ l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n\
    \    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] = p.dat[s + i];\n    } else\
    \ {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l +\
    \ i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // [L,R)\
    \ \u306B p \u3092 xor\n  void xor_to_range(int L, int R, My_Bitset &p) {\n   \
    \ assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63))\
    \ {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n      ++a, ++L;\n    }\n   \
    \ while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >> 6] ^= u64(p[b])\
    \ << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6,\
    \ r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a\
    \ & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s + i];\n    } else {\n      int\
    \ hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] ^= (p.dat[s\
    \ + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092\
    \ and\n  void and_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N == R\
    \ - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) {\n      if (!p[a])\
    \ (*this)[L] = 0;\n      a++, L++;\n    }\n    while (L < R && (R & 63)) {\n \
    \     --b, --R;\n      if (!p[b]) (*this)[R] = 0;\n    }\n    // p[a:b] \u3092\
    \ [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >>\
    \ t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] &=\
    \ p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n\
    \      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n\
    \    }\n  }\n\n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n      ++a,\
    \ ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >>\
    \ 6] |= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n   \
    \ int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r\
    \ - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s + i];\n  \
    \  } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n)\
    \ dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\
    \n  // [L,R) \u3092 1 \u306B\u5909\u66F4\n  void set_range(int L, int R) {\n \
    \   while (L < R && (L & 63)) { set(L++); }\n    while (L < R && (R & 63)) { set(--R);\
    \ }\n    FOR(i, L >> 6, R >> 6) dat[i] = u64(-1);\n  }\n\n  // [L,R) \u3092 1\
    \ \u306B\u5909\u66F4\n  void reset_range(int L, int R) {\n    while (L < R &&\
    \ (L & 63)) { reset(L++); }\n    while (L < R && (R & 63)) { reset(--R); }\n \
    \   FOR(i, L >> 6, R >> 6) dat[i] = u64(0);\n  }\n\n  // [L,R) \u3092 flip\n \
    \ void flip_range(int L, int R) {\n    while (L < R && (L & 63)) { flip(L++);\
    \ }\n    while (L < R && (R & 63)) { flip(--R); }\n    FOR(i, L >> 6, R >> 6)\
    \ dat[i] ^= u64(-1);\n  }\n\n  // bitset \u306B\u4ED5\u69D8\u3092\u5408\u308F\u305B\
    \u308B\n  void set(int i) { (*this)[i] = 1; }\n  void reset(int i) { (*this)[i]\
    \ = 0; }\n  void flip(int i) { (*this)[i].flip(); }\n  void set() {\n    fill(all(dat),\
    \ u64(-1));\n    resize(N);\n  }\n  void reset() { fill(all(dat), 0); }\n  void\
    \ flip() {\n    FOR(i, len(dat) - 1) { dat[i] = u64(-1) ^ dat[i]; }\n    int i\
    \ = len(dat) - 1;\n    FOR(k, 64) {\n      if (64 * i + k >= size()) break;\n\
    \      flip(64 * i + k);\n    }\n  }\n  bool any() {\n    FOR(i, len(dat)) {\n\
    \      if (dat[i]) return true;\n    }\n    return false;\n  }\n\n  int _Find_first()\
    \ { return next(0); }\n  int _Find_next(int p) { return next(p + 1); }\n\n  static\
    \ string TO_STR[256];\n  string to_string() const {\n    if (TO_STR[0].empty())\
    \ precompute();\n    string S;\n    for (auto &x: dat) { FOR(i, 8) S += TO_STR[(x\
    \ >> (8 * i) & 255)]; }\n    S.resize(N);\n    return S;\n  }\n\n  static void\
    \ precompute() {\n    FOR(s, 256) {\n      string x;\n      FOR(i, 8) x += '0'\
    \ + (s >> i & 1);\n      TO_STR[s] = x;\n    }\n  }\n};\nstring My_Bitset::TO_STR[256];\n\
    #line 6 \"test/1_mytest/mybitset.test.cpp\"\n\nvoid test() {\n  FOR(N, 2000) {\n\
    \    int Q = 10 * N;\n    vc<int> A(N);\n    My_Bitset B(N);\n    FOR(Q) {\n \
    \     int t = RNG(0, 4);\n      int i = RNG(0, N);\n      if (t == 0) {\n    \
    \    A[i] = 0;\n        B[i] = 0;\n      }\n      if (t == 1) {\n        A[i]\
    \ = 1;\n        B[i] = 1;\n      }\n      if (t == 2) {\n        int p = i;\n\
    \        while (p < N && A[p] == 0) ++p;\n        assert(B.next(i) == p);\n  \
    \    }\n      if (t == 3) {\n        int p = i;\n        while (p >= 0 && A[p]\
    \ == 0) --p;\n        assert(B.prev(i) == p);\n      }\n    }\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"ds/my_bitset.hpp\"\n\nvoid test()\
    \ {\n  FOR(N, 2000) {\n    int Q = 10 * N;\n    vc<int> A(N);\n    My_Bitset B(N);\n\
    \    FOR(Q) {\n      int t = RNG(0, 4);\n      int i = RNG(0, N);\n      if (t\
    \ == 0) {\n        A[i] = 0;\n        B[i] = 0;\n      }\n      if (t == 1) {\n\
    \        A[i] = 1;\n        B[i] = 1;\n      }\n      if (t == 2) {\n        int\
    \ p = i;\n        while (p < N && A[p] == 0) ++p;\n        assert(B.next(i) ==\
    \ p);\n      }\n      if (t == 3) {\n        int p = i;\n        while (p >= 0\
    \ && A[p] == 0) --p;\n        assert(B.prev(i) == p);\n      }\n    }\n  }\n}\n\
    \nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n\
    }\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - ds/my_bitset.hpp
  isVerificationFile: true
  path: test/1_mytest/mybitset.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 23:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/mybitset.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/mybitset.test.cpp
- /verify/test/1_mytest/mybitset.test.cpp.html
title: test/1_mytest/mybitset.test.cpp
---
