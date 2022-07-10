---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/primesum.hpp
    title: nt/primesum.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: other/io2.hpp
    title: other/io2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
  bundledCode: "#line 1 \"test/aoj/0009_prime_pi.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\
    \n#line 1 \"my_template.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define FOR4_R(i,\
    \ a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))\n#define overload4(a, b, c,\
    \ d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) \\\n  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) &\
    \ s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\ntemplate <typename\
    \ T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a: A) sum += a;\n\
    \  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end())\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    if (check(x)) {\n      ok = x;\n    } else {\n      ng\
    \ = x;\n    }\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\n\
    inline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\nvi s_to_vi(const string &S, char first_char) {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(A);\n  assert(len(I) == n);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n\
    \  return B;\n}\n#line 1 \"other/io2.hpp\"\n#define INT(...) \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  IN(__VA_ARGS__)\r\n#define LL(...) \\\r\n  ll __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\
    \n#define STR(...) \\\r\n  string __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define\
    \ CHR(...) \\\r\n  char __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n#define DBL(...)\
    \ \\\r\n  long double __VA_ARGS__; \\\r\n  IN(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid read(int &a) { cin >> a; }\r\
    \nvoid read(long long &a) { cin >> a; }\r\nvoid read(char &a) { cin >> a; }\r\n\
    void read(double &a) { cin >> a; }\r\nvoid read(long double &a) { cin >> a; }\r\
    \nvoid read(string &a) { cin >> a; }\r\ntemplate <class T, class S> void read(pair<T,\
    \ S> &p) { read(p.first), read(p.second); }\r\ntemplate <class T> void read(vector<T>\
    \ &a) {for(auto &i : a) read(i);}\r\ntemplate <class T> void read(T &a) { cin\
    \ >> a; }\r\nvoid IN() {}\r\ntemplate <class Head, class... Tail> void IN(Head\
    \ &head, Tail &...tail) {\r\n  read(head);\r\n  IN(tail...);\r\n}\r\n\r\ntemplate\
    \ <typename T, typename U>\r\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ A) {\r\n  os << A.fi << \" \" << A.se;\r\n  return os;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nostream& operator<<(ostream& os, const vector<T>& A) {\r\n \
    \ for (size_t i = 0; i < A.size(); i++) {\r\n    if(i) os << \" \";\r\n    os\
    \ << A[i];\r\n  }\r\n  return os;\r\n}\r\n\r\nvoid print() {\r\n  cout << \"\\\
    n\";\r\n  cout.flush();\r\n}\r\n\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head&& head, Tail&&... tail) {\r\n  cout << head;\r\n  if (sizeof...(Tail))\
    \ cout << \" \";\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid YES(bool\
    \ t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\
    \nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1)\
    \ { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid\
    \ no(bool t = 1) { yes(!t); }\r\n#line 4 \"test/aoj/0009_prime_pi.test.cpp\"\n\
    \n#line 2 \"nt/primetable.hpp\"\nvc<ll> primetable(int LIM) {\n  ++LIM;\n  const\
    \ int S = 32768;\n  static int done = 2;\n  static vc<ll> primes = {2}, sieve(S\
    \ + 1);\n\n  if (done < LIM) {\n    done = LIM;\n\n    primes = {2}, sieve.assign(S\
    \ + 1, 0);\n    const int R = LIM / 2;\n    primes.reserve(int(LIM / log(LIM)\
    \ * 1.1));\n    vc<pi> cp;\n    for (int i = 3; i <= S; i += 2) {\n      if (!sieve[i])\
    \ {\n        cp.eb(i, i * i / 2);\n        for (int j = i * i; j <= S; j += 2\
    \ * i) sieve[j] = 1;\n      }\n    }\n    for (int L = 1; L <= R; L += S) {\n\
    \      array<bool, S> block{};\n      for (auto& [p, idx]: cp)\n        for (int\
    \ i = idx; i < S + L; idx = (i += p)) block[i - L] = 1;\n      FOR(i, min(S, R\
    \ - L)) if (!block[i]) primes.eb((L + i) * 2 + 1);\n    }\n  }\n  int k = LB(primes,\
    \ LIM + 1);\n  return {primes.begin(), primes.begin() + k};\n}\n#line 2 \"nt/primesum.hpp\"\
    \n\r\n/*\r\nN \u3068\u5B8C\u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix\
    \ sum \u95A2\u6570 F \u3092\u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\
    \u308B n \u306B\u5BFE\u3059\u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\
    \u3002\r\n\u7279\u306B\u3001p^k \u306E\u548C\u3084\u3001mod m \u3054\u3068\u3067\
    \u306E p^k \u306E\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\r\nComplexity:\
    \ O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n*/\r\ntemplate <typename T>\r\npair<vc<T>,\
    \ vc<T>> primesum_F(ll N, function<T(ll)> F) {\r\n  ll sqN = sqrtl(N);\r\n  auto\
    \ primes = primetable(sqN);\r\n  vc<T> sum_lo(sqN + 1), sum_hi(sqN + 1);\r\n \
    \ FOR3(i, 1, sqN + 1) sum_lo[i] = F(i) - 1;\r\n  FOR3(i, 1, sqN + 1) sum_hi[i]\
    \ = F(double(N) / i) - 1;\r\n  for (auto&& p: primes) {\r\n    ll pp = p * p;\r\
    \n    if (pp > N) break;\r\n    ll R = min(sqN, N / pp);\r\n    ll M = sqN / p;\r\
    \n    T x = sum_lo[p - 1];\r\n    T fp = sum_lo[p] - sum_lo[p - 1];\r\n    FOR3(i,\
    \ 1, M + 1) sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n    FOR3(i, M + 1, R + 1)\
    \ sum_hi[i] -= fp * (sum_lo[double(N) / (i * p)] - x);\r\n    FOR3_R(n, pp, sqN\
    \ + 1) sum_lo[n] -= fp * (sum_lo[double(n) / p] - x);\r\n  }\r\n  return {sum_lo,\
    \ sum_hi};\r\n}\r\n\r\ntemplate <typename T>\r\npair<vc<T>, vc<T>> primecnt(ll\
    \ N) {\r\n  auto F = [&](ll N) -> T { return N; };\r\n  return primesum_F<T>(N,\
    \ F);\r\n}\r\n\r\ntemplate <typename T>\r\npair<vc<T>, vc<T>> primesum(ll N) {\r\
    \n  auto F = [&](ll N) -> T {\r\n    return (N & 1 ? T((N + 1) / 2) * T(N) : T(N\
    \ / 2) * T(N + 1));\r\n  };\r\n  return primesum_F<T>(N, F);\r\n}\r\n#line 6 \"\
    test/aoj/0009_prime_pi.test.cpp\"\n\nvoid solve() {\n  ll N;\n  while (cin >>\
    \ N) {\n    auto [lo, hi] = primecnt<ll>(N);\n    print(hi[1]);\n  }\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n\
    \  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\
    \n#include \"my_template.hpp\"\n#include \"other/io2.hpp\"\n\n#include \"nt/primesum.hpp\"\
    \n\nvoid solve() {\n  ll N;\n  while (cin >> N) {\n    auto [lo, hi] = primecnt<ll>(N);\n\
    \    print(hi[1]);\n  }\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io2.hpp
  - nt/primesum.hpp
  - nt/primetable.hpp
  isVerificationFile: true
  path: test/aoj/0009_prime_pi.test.cpp
  requiredBy: []
  timestamp: '2022-07-10 22:01:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/0009_prime_pi.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0009_prime_pi.test.cpp
- /verify/test/aoj/0009_prime_pi.test.cpp.html
title: test/aoj/0009_prime_pi.test.cpp
---
