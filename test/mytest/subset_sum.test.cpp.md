---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
  - icon: ':heavy_check_mark:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':heavy_check_mark:'
    path: knapsack/subset_sum.hpp
    title: knapsack/subset_sum.hpp
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
  bundledCode: "#line 1 \"test/mytest/subset_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \  return B;\n}\n#endif\n#line 3 \"test/mytest/subset_sum.test.cpp\"\n\n#line\
    \ 2 \"ds/my_bitset.hpp\"\n\n// https://codeforces.com/contest/914/problem/F\n\
    // https://yukicoder.me/problems/no/142\n// \u308F\u305A\u304B\u306B\u666E\u901A\
    \u306E bitset \u3088\u308A\u9045\u3044\u3068\u304D\u3082\u3042\u308B\u3088\u3046\
    \u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\u3057\u305F\u304F\u306A\u3044\u3068\
    \u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\u8981\u306A\u3068\u304D\u306B\u4F7F\
    \u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\
    \n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int N = 0, int x = 0) : N(N) {\n\
    \    assert(x == 0 || x == 1);\n    u64 v = (x == 0 ? 0 : -1);\n    dat.assign((N\
    \ + 63) >> 6, v);\n    if (N) dat.back() >>= (64 * len(dat) - N);\n  }\n\n  int\
    \ size() { return N; }\n\n  void resize(int size) {\n    dat.resize((size + 63)\
    \ >> 6);\n    int remainingBits = size & 63;\n    if (remainingBits != 0) {\n\
    \      u64 mask = (u64(1) << remainingBits) - 1;\n      dat.back() &= mask;\n\
    \    }\n    N = size;\n  }\n\n  // thanks to chatgpt!\n  class Proxy {\n  public:\n\
    \    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n    operator bool() const\
    \ { return (dat[index >> 6] >> (index & 63)) & 1; }\n\n    Proxy &operator=(u64\
    \ value) {\n      dat[index >> 6] &= ~(u64(1) << (index & 63));\n      dat[index\
    \ >> 6] |= (value & 1) << (index & 63);\n      return *this;\n    }\n    void\
    \ flip() {\n      dat[index >> 6] ^= (u64(1) << (index & 63)); // XOR to flip\
    \ the bit\n    }\n\n  private:\n    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy\
    \ operator[](int i) { return Proxy(dat, i); }\n\n  bool operator==(const T &p)\
    \ {\n    assert(N == p.N);\n    FOR(i, len(dat)) if (dat[i] != p.dat[i]) return\
    \ false;\n    return true;\n  }\n\n  T &operator&=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n    return *this;\n  }\n\
    \  T &operator|=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i]\
    \ |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n    return *this;\n  }\n\
    \  T operator&(const T &p) const { return T(*this) &= p; }\n  T operator|(const\
    \ T &p) const { return T(*this) |= p; }\n  T operator^(const T &p) const { return\
    \ T(*this) ^= p; }\n\n  int count() {\n    int ans = 0;\n    for (u64 val: dat)\
    \ ans += popcnt(val);\n    return ans;\n  }\n\n  int next(int i) {\n    chmax(i,\
    \ 0);\n    if (i >= N) return N;\n    int k = i >> 6;\n    {\n      u64 x = dat[k];\n\
    \      int s = i & 63;\n      x = (x >> s) << s;\n      if (x) return (k << 6)\
    \ | lowbit(x);\n    }\n    FOR(idx, k + 1, len(dat)) {\n      if (dat[idx] ==\
    \ 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n    }\n    return\
    \ N;\n  }\n\n  int prev(int i) {\n    chmin(i, N - 1);\n    if (i <= -1) return\
    \ -1;\n    int k = i >> 6;\n    if ((i & 63) < 63) {\n      u64 x = dat[k];\n\
    \      x &= (u64(1) << ((i & 63) + 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n\
    \      --k;\n    }\n    FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n\
    \      return (idx << 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n \
    \ My_Bitset range(int L, int R) {\n    assert(L <= R);\n    My_Bitset p(R - L);\n\
    \    int rm = (R - L) & 63;\n    FOR(rm) {\n      p[R - L - 1] = bool((*this)[R\
    \ - 1]);\n      --R;\n    }\n    int n = (R - L) >> 6;\n    int hi = L & 63;\n\
    \    int lo = 64 - hi;\n    int s = L >> 6;\n    if (hi == 0) {\n      FOR(i,\
    \ n) { p.dat[i] ^= dat[s + i]; }\n    } else {\n      FOR(i, n) { p.dat[i] ^=\
    \ (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }\n    }\n    return p;\n  }\n\n\
    \  int count_range(int L, int R) {\n    assert(L <= R);\n    int cnt = 0;\n  \
    \  while ((L < R) && (L & 63)) cnt += (*this)[L++];\n    while ((L < R) && (R\
    \ & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r = R >> 6;\n    FOR(i, l,\
    \ r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n  // [L,R) \u306B p \u3092\
    \u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N\
    \ == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) { (*this)[L++]\
    \ = bool(p[a++]); }\n    while (L < R && (R & 63)) { (*this)[--R] = bool(p[--b]);\
    \ }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int\
    \ s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i,\
    \ n) dat[l + i] = p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int\
    \ lo = 64 - hi;\n      FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1\
    \ + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 xor\n  void xor_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] ^= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  // [L,R) \u306B p \u3092 and\n  void and_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      if (!p[a++]) (*this)[L++] = 0;\n    }\n    while\
    \ (L < R && (R & 63)) {\n      if (!p[--b]) (*this)[--R] = 0;\n    }\n    // p[a:b]\
    \ \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t\
    \ = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l +\
    \ i] &= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64\
    \ - hi;\n      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i]\
    \ << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] |= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  string to_string() const {\n    string S;\n    FOR(i, N) S +=\
    \ '0' + (dat[i >> 6] >> (i & 63) & 1);\n    return S;\n  }\n\n  // bitset \u306B\
    \u4ED5\u69D8\u3092\u5408\u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1;\
    \ }\n  void reset(int i) { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip();\
    \ }\n  void set() {\n    fill(all(dat), u64(-1));\n    resize(N);\n  }\n  void\
    \ reset() { fill(all(dat), 0); }\n  void flip() {\n    FOR(i, len(dat) - 1) {\
    \ dat[i] = u64(-1) ^ dat[i]; }\n    int i = len(dat) - 1;\n    FOR(k, 64) {\n\
    \      if (64 * i + k >= size()) break;\n      flip(64 * i + k);\n    }\n  }\n\
    \  bool any() {\n    FOR(i, len(dat)) {\n      if (dat[i]) return true;\n    }\n\
    \    return false;\n  }\n\n  int _Find_first() { return next(0); }\n  int _Find_next(int\
    \ p) { return next(p + 1); }\n};\n#line 1 \"enumerate/bits.hpp\"\ntemplate <typename\
    \ F>\nvoid enumerate_bits_32(u32 s, F f) {\n  while (s) {\n    int i = __builtin_ctz(s);\n\
    \    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate <typename F>\nvoid enumerate_bits_64(u64\
    \ s, F f) {\n  while (s) {\n    int i = __builtin_ctzll(s);\n    f(i);\n    s\
    \ ^= u64(1) << i;\n  }\n}\n\ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS&\
    \ b, int L, int R, F f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p\
    \ < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n#line 3 \"knapsack/subset_sum.hpp\"\
    \n\n// O(N MAX(vals))\ntemplate <typename T>\nvc<int> subset_sum_solution_1(vc<T>&\
    \ vals, int target) {\n  int n = len(vals);\n  if (n == 0) return {};\n  int mx\
    \ = MAX(vals);\n  int b = 0, sb = 0;\n  while (b < n && sb + vals[b] <= target)\
    \ { sb += vals[b++]; }\n  if (b == n && sb != target) return {};\n\n  int off\
    \ = target - mx + 1;\n  vc<int> dp(2 * mx, -1);\n  vv(int, PAR, n, 2 * mx, -1);\n\
    \  dp[sb - off] = b;\n  FOR3(i, b, n) {\n    auto newdp = dp;\n    auto& par =\
    \ PAR[i];\n    int a = vals[i];\n    FOR(j, mx) {\n      if (chmax(newdp[j + a],\
    \ dp[j])) { par[j + a] = -2; }\n    }\n    FOR3_R(j, mx, 2 * mx) {\n      FOR3_R(k,\
    \ max(dp[j], 0), newdp[j]) {\n        if (chmax(newdp[j - vals[k]], k)) par[j\
    \ - vals[k]] = k;\n      }\n    }\n    swap(dp, newdp);\n  }\n  if (dp[mx - 1]\
    \ == -1) return {};\n  vc<bool> use(n);\n  int i = n - 1, j = mx - 1;\n  while\
    \ (i >= b) {\n    int p = PAR[i][j];\n    if (p == -2) {\n      use[i] = !use[i];\n\
    \      j -= vals[i--];\n    }\n    elif (p == -1) { --i; }\n    else {\n     \
    \ use[p] = !use[p];\n      j += vals[p];\n    }\n  }\n  while (i >= 0) {\n   \
    \ use[i] = !use[i];\n    --i;\n  }\n  vc<int> I;\n  FOR(i, n) if (use[i]) I.eb(i);\n\
    \n  ll sm = 0;\n  for (auto&& i: I) sm += vals[i];\n  assert(sm == target);\n\n\
    \  return I;\n}\n\n// O(N target / w)\ntemplate <typename T>\nvc<int> subset_sum_solution_2(vc<T>&\
    \ vals, int target) {\n  int n = len(vals);\n  auto I = argsort(vals);\n  My_Bitset\
    \ dp(1, 1);\n  vc<int> last(target + 1, -1);\n  FOR(k, n) {\n    int v = vals[I[k]];\n\
    \    if (v > target) continue;\n    My_Bitset newdp = dp;\n    int new_size =\
    \ len(dp) + v;\n    newdp.resize(new_size);\n    newdp.or_to_range(v, new_size,\
    \ dp);\n    if (len(newdp) > target + 1) newdp.resize(target + 1);\n    // update\
    \ \u3057\u305F\u3068\u3053\u308D\u3092\u30E1\u30E2\n    FOR(i, len(newdp.dat))\
    \ {\n      u64 upd = (i < len(dp.dat) ? dp.dat[i] : u64(0)) ^ newdp.dat[i];\n\
    \      enumerate_bits_64(upd, [&](int p) -> void { last[(i << 6) | p] = I[k];\
    \ });\n    }\n    swap(dp, newdp);\n  }\n  if (target >= len(dp) || !dp[target])\
    \ return {};\n  vc<int> ANS;\n  while (target > 0) {\n    int i = last[target];\n\
    \    ANS.eb(i);\n    target -= vals[i];\n  }\n  return ANS;\n}\n\n// O(sum^{1.5}\
    \ / w)\n// sum=10^6 \u3067 150ms\uFF1Ahttps://codeforces.com/contest/755/problem/F\n\
    template <typename T>\nvc<int> subset_sum_solution_3(vc<T>& vals, int target)\
    \ {\n  int SM = SUM<int>(vals);\n  int N = len(vals);\n  vvc<int> IDS(SM + 1);\n\
    \  FOR(i, N) IDS[vals[i]].eb(i);\n  vc<pair<int, int>> par(N, {-1, -1});\n  vc<int>\
    \ grp_vals;\n  vc<int> raw_idx;\n  FOR(x, 1, SM + 1) {\n    auto& I = IDS[x];\n\
    \    while (len(I) >= 3) {\n      int a = POP(I), b = POP(I);\n      int c = len(par);\n\
    \      par.eb(a, b);\n      IDS[2 * x].eb(c);\n    }\n    for (auto& i: I) {\n\
    \      grp_vals.eb(x);\n      raw_idx.eb(i);\n    }\n  }\n  auto I = subset_sum_solution_2<int>(grp_vals,\
    \ target);\n  vc<int> ANS;\n  for (auto& i: I) {\n    vc<int> st = {raw_idx[i]};\n\
    \    while (len(st)) {\n      auto c = POP(st);\n      if (c < N) {\n        ANS.eb(c);\n\
    \        continue;\n      }\n      auto [a, b] = par[c];\n      st.eb(a), st.eb(b);\n\
    \    }\n  }\n  return ANS;\n}\n\ntemplate <typename T>\nvc<int> subset_sum_solution_4(vc<T>&\
    \ vals, T target) {\n  if (target <= 0) return {};\n  int N = len(vals);\n  int\
    \ M = N / 2;\n\n  auto calc = [&](int L, int R) -> vc<T> {\n    int n = R - L;\n\
    \    vc<T> dp = {0};\n    FOR(i, n) {\n      T a = vals[L + i];\n      vc<T> dp1(len(dp));\n\
    \      FOR(k, len(dp)) dp1[k] = dp[k] + a;\n      vc<T> newdp;\n      merge(all(dp),\
    \ all(dp1), back_inserter(newdp));\n      swap(dp, newdp);\n    }\n    return\
    \ dp;\n  };\n\n  auto restore = [&](int L, int R, T v) -> vc<int> {\n    int n\
    \ = R - L;\n    vc<T> dp(1 << n);\n    FOR(i, n) FOR(s, 1 << i) dp[s | 1 << i]\
    \ = dp[s] + vals[L + i];\n    FOR(s, 1 << n) {\n      if (dp[s] == v) {\n    \
    \    vc<int> I;\n        FOR(i, n) if (s >> i & 1) I.eb(L + i);\n        return\
    \ I;\n      }\n    }\n    assert(0);\n    return {};\n  };\n\n  auto dp1 = calc(0,\
    \ M);\n  auto dp2 = calc(M, N);\n  int t = 0;\n  FOR_R(s, len(dp1)) {\n    while\
    \ (t + 1 < len(dp2) && dp1[s] + dp2[t + 1] <= target) { ++t; }\n    if (dp1[s]\
    \ + dp2[t] == target) {\n      vc<int> I1 = restore(0, M, dp1[s]);\n      vc<int>\
    \ I2 = restore(M, N, dp2[t]);\n      I1.insert(I1.end(), all(I2));\n      return\
    \ I1;\n    }\n  }\n  return {};\n}\n\ntemplate <typename T>\nvc<int> subset_sum(vc<T>&\
    \ vals, T target) {\n  if (target <= 0) return {};\n  int n = len(vals);\n  if\
    \ (n == 0) return {};\n  int mx = MAX(vals);\n\n  // \u3057\u304D\u3044\u5024\u306E\
    \u8ABF\u6574\u3092\u3057\u3066\u3044\u306A\u3044\n  // solution 1: O(N mx))\n\
    \  // solution 2: O(N target / w)\n  // solution 3: O(sum^1.5 / w)\n  // solution\
    \ 4: O(2^(N/2))\n  double x1 = double(len(vals)) * mx;\n  double x2 = double(len(vals))\
    \ * target / 500.0;\n  double x3 = pow(SUM<double>(vals), 1.5) / 500.0;\n  double\
    \ x4 = pow(2.0, 0.5 * len(vals));\n  double mi = min({x1, x2, x3, x4});\n  if\
    \ (x1 == mi) return subset_sum_solution_1(vals, target);\n  if (x2 == mi) return\
    \ subset_sum_solution_2(vals, target);\n  if (x3 == mi) return subset_sum_solution_3(vals,\
    \ target);\n  return subset_sum_solution_4(vals, target);\n}\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"test/mytest/subset_sum.test.cpp\"\
    \n\nvoid test() {\n  FOR(10) {\n    FOR(N, 10) {\n      vc<int> A(N);\n      FOR(i,\
    \ N) A[i] = RNG(0, 100);\n      FOR(s, 1, 500) {\n        vc<int> I1 = subset_sum_solution_1<int>(A,\
    \ s);\n        vc<int> I2 = subset_sum_solution_2<int>(A, s);\n        vc<int>\
    \ I3 = subset_sum_solution_3<int>(A, s);\n        vc<int> I4 = subset_sum_solution_4<int>(A,\
    \ s);\n        vc<int> I5 = subset_sum_solution_4<int>(A, s);\n        if (I1.empty())\
    \ {\n          assert(I2.empty());\n          assert(I3.empty());\n          assert(I4.empty());\n\
    \          assert(I5.empty());\n          continue;\n        }\n        for (vc<int>\
    \ I: {I1, I2, I3, I4, I5}) {\n          FOR(i, len(I) - 1) assert(I[i] != I[i\
    \ + 1]);\n          int sm = 0;\n          for (auto& i: I) sm += A[i];\n    \
    \      assert(sm == s);\n        }\n      }\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"knapsack/subset_sum.hpp\"\n#include \"random/base.hpp\"\n\nvoid\
    \ test() {\n  FOR(10) {\n    FOR(N, 10) {\n      vc<int> A(N);\n      FOR(i, N)\
    \ A[i] = RNG(0, 100);\n      FOR(s, 1, 500) {\n        vc<int> I1 = subset_sum_solution_1<int>(A,\
    \ s);\n        vc<int> I2 = subset_sum_solution_2<int>(A, s);\n        vc<int>\
    \ I3 = subset_sum_solution_3<int>(A, s);\n        vc<int> I4 = subset_sum_solution_4<int>(A,\
    \ s);\n        vc<int> I5 = subset_sum_solution_4<int>(A, s);\n        if (I1.empty())\
    \ {\n          assert(I2.empty());\n          assert(I3.empty());\n          assert(I4.empty());\n\
    \          assert(I5.empty());\n          continue;\n        }\n        for (vc<int>\
    \ I: {I1, I2, I3, I4, I5}) {\n          FOR(i, len(I) - 1) assert(I[i] != I[i\
    \ + 1]);\n          int sm = 0;\n          for (auto& i: I) sm += A[i];\n    \
    \      assert(sm == s);\n        }\n      }\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - knapsack/subset_sum.hpp
  - ds/my_bitset.hpp
  - enumerate/bits.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/subset_sum.test.cpp
  requiredBy: []
  timestamp: '2023-12-21 22:18:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/subset_sum.test.cpp
- /verify/test/mytest/subset_sum.test.cpp.html
title: test/mytest/subset_sum.test.cpp
---