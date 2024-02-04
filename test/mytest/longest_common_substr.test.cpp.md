---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':question:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
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
  bundledCode: "#line 1 \"test/mytest/longest_common_substr.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// \u53C2\u8003\
    \ https://codeforces.com/blog/entry/96344\n// bmi,bmi2,lzcnt \u306F ucup \u3067\
    \u30B3\u30F3\u30D1\u30A4\u30EB\u30A8\u30E9\u30FC\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n#pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
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
    \  return B;\n}\n#endif\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"string/suffix_array.hpp\"\
    \n\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Min\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 1 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002disjoint sparse table\
    \ \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\nstruct Sparse_Table\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n, log;\n\
    \  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) { build(n); }\n \
    \ template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n\
    \  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m,\
    \ [](int i) -> X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i, n) dat[0][i]\
    \ = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i]) - (1 <<\
    \ i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j],\
    \ dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int L, int R) {\n  \
    \  if (L == R) return MX::unit();\n    if (R == L + 1) return dat[0][L];\n   \
    \ int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R - (1 << k)]);\n\
    \  }\n\n  template <class F>\n  int max_right(const F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(MX::unit()));\n    if (L == n) return n;\n    int ok\
    \ = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok + ng) / 2;\n\
    \      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n      if (!bl) ng\
    \ = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int min_left(const\
    \ F check, int R) {\n    assert(0 <= R && R <= n && check(MX::unit()));\n    if\
    \ (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok) {\n  \
    \    int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if (bl)\
    \ ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n#line 5 \"\
    string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\u76EE\u306E suffix\
    \ \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\u3068\u304D\u3001\
    \n// SA[i] = j, ISA[j] = i\n// |S|>0 \u3092\u524D\u63D0\uFF08\u305D\u3046\u3067\
    \u306A\u3044\u5834\u5408 dummy \u6587\u5B57\u3092\u8FFD\u52A0\u3057\u3066\u5229\
    \u7528\u305B\u3088\uFF09\ntemplate <bool USE_LCP_QUERY = 0>\nstruct Suffix_Array\
    \ {\n  vc<int> SA;\n  vc<int> ISA;\n  vc<int> LCP;\n  Sparse_Table<Monoid_Min<int>>\
    \ seg;\n  // DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string& s)\
    \ {\n    assert(len(s) > 0);\n    char first = 127, last = 0;\n    for (auto&&\
    \ c: s) {\n      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n    if (USE_LCP_QUERY) seg.build(LCP);\n  }\n\
    \n  Suffix_Array(vc<int>& s) {\n    assert(len(s) > 0);\n    SA = calc_suffix_array(s);\n\
    \    calc_LCP(s);\n    if (USE_LCP_QUERY) seg.build(LCP);\n  }\n\n  // lcp(S[i:],\
    \ S[j:])\n  int lcp(int i, int j) {\n    static_assert(USE_LCP_QUERY);\n    int\
    \ n = len(SA);\n    if (i == n || j == n) return 0;\n    if (i == j) return n\
    \ - i;\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i, j);\n    return seg.prod(i,\
    \ j);\n  }\n\n  // S[i:] \u3068\u306E lcp \u304C n \u4EE5\u4E0A\u3067\u3042\u308B\
    \u3088\u3046\u306A\u534A\u958B\u533A\u9593\n  pair<int, int> lcp_range(int i,\
    \ int n) {\n    static_assert(USE_LCP_QUERY);\n    i = ISA[i];\n    int a = seg.min_left([&](auto\
    \ e) -> bool { return e >= n; }, i);\n    int b = seg.max_right([&](auto e) ->\
    \ bool { return e >= n; }, i);\n    return {a, b + 1};\n  }\n\n  // -1: S[L1:R1)\
    \ < S[L2, R2)\n  //  0: S[L1:R1) = S[L2, R2)\n  // +1: S[L1:R1) > S[L2, R2)\n\
    \  int compare(int L1, int R1, int L2, int R2) {\n    int N = len(SA);\n    int\
    \ n1 = R1 - L1, n2 = R2 - L2;\n    int n = lcp(L1, L2);\n    if (n == n1 && n\
    \ == n2) return 0;\n    if (n == n1) return -1;\n    if (n == n2) return 1;\n\
    \    return (ISA[L1 + n] > ISA[L2 + n] ? 1 : -1);\n  }\n\nprivate:\n  void induced_sort(const\
    \ vc<int>& vect, int val_range, vc<int>& SA,\n                    const vc<bool>&\
    \ sl, const vc<int>& lms_idx) {\n    vc<int> l(val_range, 0), r(val_range, 0);\n\
    \    for (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n\
    \    }\n    partial_sum(l.begin(), l.end(), l.begin());\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    fill(SA.begin(), SA.end(), -1);\n    for (int i =\
    \ (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] = lms_idx[i];\n\
    \    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i - 1]]++] = i\
    \ - 1;\n    fill(r.begin(), r.end(), 0);\n    for (int c: vect) ++r[c];\n    partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    for (int k = (int)SA.size() - 1, i = SA[k]; k >= 1;\
    \ --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i\
    \ - 1; }\n  }\n\n  vc<int> SA_IS(const vc<int>& vect, int val_range) {\n    const\
    \ int n = vect.size();\n    vc<int> SA(n), lms_idx;\n    vc<bool> sl(n);\n   \
    \ sl[n - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    reverse(lms_idx.begin(), lms_idx.end());\n\
    \    induced_sort(vect, val_range, SA, sl, lms_idx);\n    vc<int> new_lms_idx(lms_idx.size()),\
    \ lms_vec(lms_idx.size());\n    for (int i = 0, k = 0; i < n; ++i)\n      if (!sl[SA[i]]\
    \ && SA[i] >= 1 && sl[SA[i] - 1]) {\n        new_lms_idx[k++] = SA[i];\n     \
    \ }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k < new_lms_idx.size();\
    \ ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n      if (vect[i]\
    \ != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n      }\n      bool\
    \ flag = false;\n      for (int a = i + 1, b = j + 1;; ++a, ++b) {\n        if\
    \ (vect[a] != vect[b]) {\n          flag = true;\n          break;\n        }\n\
    \        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1])) {\n          flag\
    \ = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n          break;\n   \
    \     }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n    for (size_t\
    \ i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n    if (cur +\
    \ 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec, cur + 1);\n \
    \     for (size_t i = 0; i < lms_idx.size(); ++i) {\n        new_lms_idx[i] =\
    \ lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect, val_range, SA, sl,\
    \ new_lms_idx);\n    return SA;\n  }\n\n  vc<int> calc_suffix_array(const string&\
    \ s, const char first = 'a',\n                            const char last = 'z')\
    \ {\n    vc<int> vect(s.size() + 1);\n    copy(begin(s), end(s), begin(vect));\n\
    \    for (auto& x: vect) x -= (int)first - 1;\n    vect.back() = 0;\n    auto\
    \ ret = SA_IS(vect, (int)last - (int)first + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  vc<int> calc_suffix_array(const vc<int>& s) {\n   \
    \ vc<int> ss = s;\n    UNIQUE(ss);\n\n    vc<int> vect(s.size() + 1);\n    copy(all(s),\
    \ vect.begin());\n    for (auto& x: vect) x = LB(ss, x) + 1;\n    vect.back()\
    \ = 0;\n    auto ret = SA_IS(vect, MAX(vect) + 2);\n    ret.erase(ret.begin());\n\
    \    return ret;\n  }\n\n  template <typename STRING>\n  void calc_LCP(const STRING&\
    \ s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n\
    \    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++,\
    \ k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n        k = 0;\n        continue;\n\
    \      }\n      int j = SA[ISA[i] + 1];\n      while (i + k < n && j + k < n &&\
    \ s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n    }\n    LCP.resize(n\
    \ - 1);\n  }\n};\n#line 2 \"string/longest_common_substring.hpp\"\n\ntemplate\
    \ <typename STRING>\ntuple<int, int, int, int> longest_common_substring(STRING&\
    \ S, STRING& T) {\n  int dummy = max<int>(*max_element(all(S)), *max_element(all(T)))\
    \ + 1;\n  STRING ST;\n  for (auto&& x: S) ST.push_back(x);\n  ST.push_back(dummy);\n\
    \  for (auto&& x: T) ST.push_back(x);\n  Suffix_Array X(ST);\n  auto& SA = X.SA;\n\
    \  auto& LCP = X.LCP;\n\n  tuple<int, int, int, int> res = {0, 0, 0, 0};\n  int\
    \ n = 0;\n  FOR(i, len(ST) - 1) {\n    int i1 = SA[i], i2 = SA[i + 1];\n    if\
    \ (i1 > i2) swap(i1, i2);\n    if (i1 < len(S) && len(S) < i2 && chmax(n, LCP[i]))\
    \ {\n      int a = i1, b = i2 - len(S) - 1;\n      res = {a, a + n, b, b + n};\n\
    \    }\n  }\n  return res;\n}\n#line 5 \"test/mytest/longest_common_substr.test.cpp\"\
    \n\nvoid test_pair(string A, string B) {\n  auto [a1, a2, b1, b2] = longest_common_substring<string>(A,\
    \ B);\n  {\n    assert(0 <= a1 && a1 <= a2 && a2 <= len(A));\n    assert(0 <=\
    \ b1 && b1 <= b2 && b2 <= len(B));\n    string x = A.substr(a1, a2 - a1);\n  \
    \  string y = B.substr(b1, b2 - b1);\n    assert(x == y);\n  }\n  int n = a2 -\
    \ a1 + 1;\n  set<string> ss;\n  FOR(i, len(A) - n + 1) { ss.insert(A.substr(i,\
    \ n)); }\n  FOR(i, len(B) - n + 1) { assert(!ss.count(B.substr(i, n))); }\n}\n\
    \nvoid test() {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    FOR(100) {\n      string\
    \ s, t;\n      FOR(n) {\n        int x = RNG(0, 3);\n        s += 'a' + x;\n \
    \     }\n      FOR(m) {\n        int x = RNG(0, 3);\n        t += 'a' + x;\n \
    \     }\n      test_pair(s, t);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"string/longest_common_substring.hpp\"\
    \n\nvoid test_pair(string A, string B) {\n  auto [a1, a2, b1, b2] = longest_common_substring<string>(A,\
    \ B);\n  {\n    assert(0 <= a1 && a1 <= a2 && a2 <= len(A));\n    assert(0 <=\
    \ b1 && b1 <= b2 && b2 <= len(B));\n    string x = A.substr(a1, a2 - a1);\n  \
    \  string y = B.substr(b1, b2 - b1);\n    assert(x == y);\n  }\n  int n = a2 -\
    \ a1 + 1;\n  set<string> ss;\n  FOR(i, len(A) - n + 1) { ss.insert(A.substr(i,\
    \ n)); }\n  FOR(i, len(B) - n + 1) { assert(!ss.count(B.substr(i, n))); }\n}\n\
    \nvoid test() {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    FOR(100) {\n      string\
    \ s, t;\n      FOR(n) {\n        int x = RNG(0, 3);\n        s += 'a' + x;\n \
    \     }\n      FOR(m) {\n        int x = RNG(0, 3);\n        t += 'a' + x;\n \
    \     }\n      test_pair(s, t);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - string/longest_common_substring.hpp
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: true
  path: test/mytest/longest_common_substr.test.cpp
  requiredBy: []
  timestamp: '2024-02-02 01:26:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/longest_common_substr.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/longest_common_substr.test.cpp
- /verify/test/mytest/longest_common_substr.test.cpp.html
title: test/mytest/longest_common_substr.test.cpp
---