---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: string/manacher.hpp
    title: string/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    #if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#endif\n\n#else  // MASPY_TEMPLATE_BODY\n\
    #include <bits/stdc++.h>\n#include <cassert>\n\n#if defined(__GNUC__)\n#pragma\
    \ GCC optimize(\"Ofast,unroll-loops\")\n#endif\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false =\
    \ false;\n\ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 4'040'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 4'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
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
    #line 1 \"string/manacher.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/manacher.hpp\n\
    \n// i<=j \u306B\u5BFE\u3057\u3066 match(i,j) \u304C\u5B9A\u7FA9\u3055\u308C\u3066\
    \u3044\u308B\u3068\u304D\u6975\u5927\u56DE\u6587 [L,R) \u3092\u5217\u6319\u3059\
    \u308B\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c\n\
    template <typename F>\nvc<pair<int, int>> manacher(int n, F match) {\n  if (n\
    \ == 0) return {};\n  assert(n > 0);\n  auto f = [&](int i, int j) -> bool {\n\
    \    if (i > j) return 0;\n    assert((i + j) % 2 == 0);\n    if (i & 1) return\
    \ 1;\n    return match(i / 2, j / 2);\n  };\n  vector<int> dp(2 * n - 1);\n  int\
    \ i = 0, j = 0;\n  while (i < 2 * n - 1) {\n    while (i - j >= 0 && i + j < 2\
    \ * n - 1 && f(i - j, i + j)) ++j;\n    dp[i] = j;\n    int k = 1;\n    while\
    \ (i - k >= 0 && i + k < 2 * n - 1 && k < j && dp[i - k] != j - k) {\n      dp[i\
    \ + k] = min(j - k, dp[i - k]), ++k;\n    }\n    i += k, j = max(j - k, 0);\n\
    \  }\n  vc<pair<int, int>> res;\n  FOR(i, len(dp)) {\n    if (dp[i] == 0) continue;\n\
    \    int l = ceil<int>(i - dp[i] + 1, 2);\n    int r = floor<int>(i + dp[i] -\
    \ 1, 2);\n    if (l <= r) res.eb(l, r + 1);\n  }\n  return res;\n}\n\n// \u6975\
    \u5927\u56DE\u6587 [L, R) \u3092\u5217\u6319\u3059\u308B\ntemplate <typename STRING>\n\
    vc<pair<int, int>> manacher(STRING s) {\n  int n = len(s);\n  if (n == 0) return\
    \ {};\n  return manacher(n, [&](int i, int j) -> bool { return s[i] == s[j]; });\n\
    }\n#line 3 \"test/5_ai_generated_test/manacher_centers_match.test.cpp\"\n\n//\
    \ \u6587\u5B57\u9593\u3068\u6587\u5B57\u4E0A\u306E\u5404\u4E2D\u5FC3\u304B\u3089\
    \u611A\u76F4\u306B\u4F38\u3070\u3057\u3001\u7A7A\u56DE\u6587\u3092\u9664\u3044\
    \u305F [l,r) \u3092\u6BD4\u8F03\u3002\n// \u7B49\u5024\u306E\u307B\u304B\u3001\
    \u540C\u3058\u5270\u4F59\u985E\u3092\u7B49\u5024\u3068\u3059\u308B\u30B3\u30FC\
    \u30EB\u30D0\u30C3\u30AF\u3067\u3082\u7167\u5408\u3059\u308B\u3002\nll cases=0,\
    \ centers=0;\ntemplate<class Match>\nvc<pair<int,int>> expand(int n,Match match)\
    \ {\n  vc<pair<int,int>> a;\n  for(int c=0;c<2*n-1;++c) {\n    int l=c/2,r=(c+1)/2;\n\
    \    while(l>=0 && r<n && match(l,r)) { --l; ++r; }\n    if(l+1<r) a.emplace_back(l+1,r);\n\
    \  }\n  return a;\n}\ntemplate<class S>\nvoid check(const S& s) {\n  const int\
    \ n=s.size();\n  auto eq=[&](int i,int j){return s[i]==s[j];};\n  auto cls=[&](int\
    \ i,int j){return s[i]%3==s[j]%3;};\n  const auto a=expand(n,eq), b=expand(n,cls);\n\
    \  if(manacher(s)!=a || manacher(n,eq)!=a || manacher(n,cls)!=b) {\n    cerr<<\"\
    case=\"<<cases<<\" n=\"<<n<<'\\n';\n    abort();\n  }\n  ++cases;\n  centers+=max(0,2*n-1);\n\
    }\n\n// Colored Tiles \u306E\u884C\u533A\u9593\u3092\u56FA\u5B9A\u3002\u5404\u5217\
    \u3092\u8272\u5217 v[i] \u3068\u307F\u306A\u3057\u3001\n// v[i] == reverse(v[j])\
    \ \u306E\u6BD4\u8F03\u3060\u3051\u3067\u5F97\u305F\u533A\u9593\u304B\u3089\u9577\
    \u65B9\u5F62\u3092\u6570\u3048\u308B\u3002\nll check_grid(int h,int w,int mask)\
    \ {\n  vc<vc<int>> a(h,vc<int>(w));\n  for(auto& row:a) for(int& x:row) { x=mask&1;\
    \ mask>>=1; }\n  int total=0, brute=0;\n  for(int top=0;top<h;++top) for(int bot=top;bot<h;++bot)\
    \ {\n    auto match=[&](int i,int j) {\n      for(int r=top;r<=bot;++r) if(a[r][i]!=a[top+bot-r][j])\
    \ return false;\n      return true;\n    };\n    auto got=manacher(w,match);\n\
    \    if(got!=expand(w,match)) abort();\n    for(auto [l,r]:got) total+=(r-l+1)/2;\n\
    \    // \u4E2D\u5FC3\u62E1\u5F35\u3068\u306F\u5225\u306B\u3001\u9577\u65B9\u5F62\
    \u3059\u3079\u3066\u306E180\u5EA6\u56DE\u8EE2\u3092\u76F4\u63A5\u8ABF\u3079\u308B\
    \u3002\n    for(int l=0;l<w;++l) for(int r=l;r<w;++r) {\n      bool ok=true;\n\
    \      for(int i=top;i<=bot;++i) for(int j=l;j<=r;++j)\n        if(a[i][j]!=a[top+bot-i][l+r-j])\
    \ ok=false;\n      brute+=ok;\n    }\n  }\n  if(total!=brute) abort();\n  return\
    \ h*(h+1)/2;\n}\n\nint main() {\n  for(int n=0,p=1;n<=9;++n,p*=3) {\n    for(int\
    \ mask=0;mask<p;++mask) {\n      string s(n,'\\0');\n      int z=mask;\n     \
    \ for(char& c:s) { c=char(z%3); z/=3; }\n      check(s);\n    }\n  }\n  mt19937\
    \ rng(3709);\n  for(int i=0;i<400;++i) {\n    vc<int> a(rng()%257);\n    for(auto&\
    \ x:a) x=int(rng()%17)-8;\n    check(a);\n  }\n  for(int n:{511,512,513,1023,1024,1025})\n\
    \    for(int k:{1,2,3,7}) {\n      vc<int> a(n);\n      for(int i=0;i<n;++i) a[i]=i%k;\n\
    \      check(a);\n      a[n/2]=-1;\n      check(a);\n    }\n  ll grids=0,row_pairs=0;\n\
    \  for(int h=1;h<=3;++h) for(int w=1;w<=5;++w) {\n    if(h*w>12) continue;\n \
    \   for(int s=0;s<(1<<(h*w));++s) {\n      row_pairs+=check_grid(h,w,s);\n   \
    \   ++grids;\n    }\n  }\n  cout<<grids<<\" grids, \"<<row_pairs<<\" row pairs\
    \ passed\\n\";\n  cout<<cases<<\" inputs, \"<<centers<<\" centers x 3 checks passed\\\
    n\";\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"string/manacher.hpp\"\n\n// \u6587\
    \u5B57\u9593\u3068\u6587\u5B57\u4E0A\u306E\u5404\u4E2D\u5FC3\u304B\u3089\u611A\
    \u76F4\u306B\u4F38\u3070\u3057\u3001\u7A7A\u56DE\u6587\u3092\u9664\u3044\u305F\
    \ [l,r) \u3092\u6BD4\u8F03\u3002\n// \u7B49\u5024\u306E\u307B\u304B\u3001\u540C\
    \u3058\u5270\u4F59\u985E\u3092\u7B49\u5024\u3068\u3059\u308B\u30B3\u30FC\u30EB\
    \u30D0\u30C3\u30AF\u3067\u3082\u7167\u5408\u3059\u308B\u3002\nll cases=0, centers=0;\n\
    template<class Match>\nvc<pair<int,int>> expand(int n,Match match) {\n  vc<pair<int,int>>\
    \ a;\n  for(int c=0;c<2*n-1;++c) {\n    int l=c/2,r=(c+1)/2;\n    while(l>=0 &&\
    \ r<n && match(l,r)) { --l; ++r; }\n    if(l+1<r) a.emplace_back(l+1,r);\n  }\n\
    \  return a;\n}\ntemplate<class S>\nvoid check(const S& s) {\n  const int n=s.size();\n\
    \  auto eq=[&](int i,int j){return s[i]==s[j];};\n  auto cls=[&](int i,int j){return\
    \ s[i]%3==s[j]%3;};\n  const auto a=expand(n,eq), b=expand(n,cls);\n  if(manacher(s)!=a\
    \ || manacher(n,eq)!=a || manacher(n,cls)!=b) {\n    cerr<<\"case=\"<<cases<<\"\
    \ n=\"<<n<<'\\n';\n    abort();\n  }\n  ++cases;\n  centers+=max(0,2*n-1);\n}\n\
    \n// Colored Tiles \u306E\u884C\u533A\u9593\u3092\u56FA\u5B9A\u3002\u5404\u5217\
    \u3092\u8272\u5217 v[i] \u3068\u307F\u306A\u3057\u3001\n// v[i] == reverse(v[j])\
    \ \u306E\u6BD4\u8F03\u3060\u3051\u3067\u5F97\u305F\u533A\u9593\u304B\u3089\u9577\
    \u65B9\u5F62\u3092\u6570\u3048\u308B\u3002\nll check_grid(int h,int w,int mask)\
    \ {\n  vc<vc<int>> a(h,vc<int>(w));\n  for(auto& row:a) for(int& x:row) { x=mask&1;\
    \ mask>>=1; }\n  int total=0, brute=0;\n  for(int top=0;top<h;++top) for(int bot=top;bot<h;++bot)\
    \ {\n    auto match=[&](int i,int j) {\n      for(int r=top;r<=bot;++r) if(a[r][i]!=a[top+bot-r][j])\
    \ return false;\n      return true;\n    };\n    auto got=manacher(w,match);\n\
    \    if(got!=expand(w,match)) abort();\n    for(auto [l,r]:got) total+=(r-l+1)/2;\n\
    \    // \u4E2D\u5FC3\u62E1\u5F35\u3068\u306F\u5225\u306B\u3001\u9577\u65B9\u5F62\
    \u3059\u3079\u3066\u306E180\u5EA6\u56DE\u8EE2\u3092\u76F4\u63A5\u8ABF\u3079\u308B\
    \u3002\n    for(int l=0;l<w;++l) for(int r=l;r<w;++r) {\n      bool ok=true;\n\
    \      for(int i=top;i<=bot;++i) for(int j=l;j<=r;++j)\n        if(a[i][j]!=a[top+bot-i][l+r-j])\
    \ ok=false;\n      brute+=ok;\n    }\n  }\n  if(total!=brute) abort();\n  return\
    \ h*(h+1)/2;\n}\n\nint main() {\n  for(int n=0,p=1;n<=9;++n,p*=3) {\n    for(int\
    \ mask=0;mask<p;++mask) {\n      string s(n,'\\0');\n      int z=mask;\n     \
    \ for(char& c:s) { c=char(z%3); z/=3; }\n      check(s);\n    }\n  }\n  mt19937\
    \ rng(3709);\n  for(int i=0;i<400;++i) {\n    vc<int> a(rng()%257);\n    for(auto&\
    \ x:a) x=int(rng()%17)-8;\n    check(a);\n  }\n  for(int n:{511,512,513,1023,1024,1025})\n\
    \    for(int k:{1,2,3,7}) {\n      vc<int> a(n);\n      for(int i=0;i<n;++i) a[i]=i%k;\n\
    \      check(a);\n      a[n/2]=-1;\n      check(a);\n    }\n  ll grids=0,row_pairs=0;\n\
    \  for(int h=1;h<=3;++h) for(int w=1;w<=5;++w) {\n    if(h*w>12) continue;\n \
    \   for(int s=0;s<(1<<(h*w));++s) {\n      row_pairs+=check_grid(h,w,s);\n   \
    \   ++grids;\n    }\n  }\n  cout<<grids<<\" grids, \"<<row_pairs<<\" row pairs\
    \ passed\\n\";\n  cout<<cases<<\" inputs, \"<<centers<<\" centers x 3 checks passed\\\
    n\";\n}\n"
  dependsOn:
  - my_template.hpp
  - string/manacher.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/manacher_centers_match.test.cpp
  requiredBy: []
  timestamp: '2026-11-29 04:16:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/manacher_centers_match.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/manacher_centers_match.test.cpp
- /verify/test/5_ai_generated_test/manacher_centers_match.test.cpp.html
title: test/5_ai_generated_test/manacher_centers_match.test.cpp
---
