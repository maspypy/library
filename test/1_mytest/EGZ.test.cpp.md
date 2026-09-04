---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/csr.hpp
    title: ds/csr.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/EGZ.hpp
    title: nt/EGZ.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/EGZ.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    template <>\nconstexpr double infty<double> = infty<i128>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<i128>;\n\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
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
    \  return a;\n}\n\ntemplate <typename F>\ni128 binary_search(F check, i128 ok,\
    \ i128 ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while\
    \ (1) {\n    i128 x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n   \
    \ (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble\
    \ binary_search_real(F check, double ok, double ng, int iter = 100) {\n  FOR(iter)\
    \ {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return\
    \ changed;\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  T c = min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/EGZ.test.cpp\"\n\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"ds/csr.hpp\"\n\ntemplate <typename\
    \ T>\nstruct CSR {\n  int n;\n  bool prepared;\n  vc<int> ptr;\n  vc<int> I;\n\
    \  vc<T> dat;\n\n  CSR(int n = 0) : n(n), prepared(false) {}\n  void reserve(int\
    \ n) { dat.reserve(n); }\n\n  void add(int i, const T& x) {\n    assert(0 <= i\
    \ && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n  }\n\n  void build() {\n\
    \    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n + 1, 0);\n    for\
    \ (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n\
    \    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int i = I[k];\n     \
    \ tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n \
    \   ptr.insert(ptr.begin(), 0);\n    I.clear();\n  }\n\n  struct range {\n   \
    \ T *first, *last;\n    T* begin() const { return first; }\n    T* end() const\
    \ { return last; }\n    bool empty() const { return first == last; }\n    int\
    \ size() const { return last - first; }\n  };\n\n  range operator[](int i) {\n\
    \    assert(prepared);\n    return range{dat.data() + ptr[i], dat.data() + ptr[i\
    \ + 1]};\n  }\n};\n#line 1 \"mod/mod_inv.hpp\"\n\n// long \u3067\u3082\u5927\u4E08\
    \u592B\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\
    \u3046\u306B\u3059\u308B\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\
    \u3059\nll mod_inv(ll val, ll mod) {\n  if (mod == 0) return 0;\n  mod = abs(mod);\n\
    \  val %= mod;\n  if (val < 0) val += mod;\n  ll a = val, b = mod, u = 1, v =\
    \ 0, t;\n  while (b > 0) {\n    t = a / b;\n    swap(a -= t * b, b), swap(u -=\
    \ t * v, v);\n  }\n  if (u < 0) u += mod;\n  return u;\n}\n#line 3 \"nt/EGZ.hpp\"\
    \n\n// p-subset \u3067\u7DCF\u548C\u304C 0 mod p \u306E\u3082\u306E\u3092\u4F5C\
    \u308B\n// return: indices\nvc<int> EGZ_prime(int p, vc<ll> A) {\n  assert(len(A)\
    \ == p + p - 1);\n  for (auto& x : A) x = bmod<ll>(x, p);\n  CSR<int> ids(p);\n\
    \  FOR(i, len(A)) { ids.add(A[i], i); }\n  ids.build();\n\n  A.clear();\n  FOR(x,\
    \ p) FOR(len(ids[x])) A.eb(x);\n\n  [&]() -> void {\n    FOR(i, p) {\n      if\
    \ (A[i] == A[i + p - 1]) {\n        A = {A.begin() + i, A.begin() + i + p};\n\
    \        return;\n      }\n    }\n    int t = 0;\n    FOR(i, p) t = (t + p - A[i])\
    \ % p;\n    vc<int> par(p, -1);\n    auto exist = [&](int i) -> bool { return\
    \ (i == 0 || par[i] != -1); };\n    FOR(i, p - 1) {\n      if (exist(t)) break;\n\
    \      int d = A[i + p] - A[i];\n      ll L = 0, R = mod_inv(d, p) * t % p;\n\
    \      while (L + 1 < R) {\n        ll M = (L + R) / 2;\n        (exist(M * d\
    \ % p) ? L : R) = M;\n      }\n      par[R * d % p] = i;\n    }\n    while (t\
    \ != 0) {\n      int i = par[t];\n      int d = A[i + p] - A[i];\n      t = (t\
    \ + p - d) % p;\n      A[i] = A[i + p];\n    }\n    A.resize(p);\n  }();\n  vc<int>\
    \ CNT(p);\n  for (auto& x : A) CNT[x]++;\n  vc<int> res;\n  FOR(x, p) {\n    for\
    \ (int i : ids[x]) {\n      if (CNT[x]) --CNT[x], res.eb(i);\n    }\n  }\n  return\
    \ res;\n}\n\n// N-subset \u3067\u7DCF\u548C\u304C 0 mod p \u306E\u3082\u306E\u3092\
    \u4F5C\u308B\n// return: indices\nvc<int> EGZ(int N, vc<ll> A) {\n  for (auto&\
    \ x : A) x = bmod<ll>(x, N);\n  assert(len(A) == 2 * N - 1);\n  if (N == 1) return\
    \ {0};\n  int p = 2;\n  while (N % p != 0) ++p;\n  if (N == p) return EGZ_prime(N,\
    \ A);\n\n  // p is a prime factor\n  int M = N / p;\n  vc<int> ids;\n  vc<int>\
    \ yet;\n  vi nxt_val;\n  int k = 0;\n  // p-EGZ * (2M-1)\n  vc<int> used(2 * p\
    \ - 1);\n  FOR(2 * M - 1) {\n    while (len(yet) < 2 * p - 1) {\n      yet.eb(k++);\n\
    \    }\n    vc<ll> B = rearrange(A, yet);\n    vc<int> way = EGZ_prime(p, B);\n\
    \    FOR(i, 2 * p - 1) used[i] = 0;\n    for (int i : way) used[i] = 1;\n    vc<int>\
    \ nxt;\n    ll x = 0;\n    FOR(i, 2 * p - 1) {\n      if (used[i]) {\n       \
    \ x += A[yet[i]];\n        ids.eb(yet[i]);\n      } else {\n        nxt.eb(yet[i]);\n\
    \      }\n    }\n    swap(yet, nxt);\n    assert(x % p == 0);\n    nxt_val.eb(x\
    \ / p);\n  }\n  vc<int> I = EGZ(M, nxt_val);\n  vc<int> res;\n  for (int i : I)\
    \ {\n    FOR(j, p * i, p * i + p) res.eb(ids[j]);\n  }\n  return res;\n}\n#line\
    \ 6 \"test/1_mytest/EGZ.test.cpp\"\n\nvoid test(int N) {\n  FOR(1000) {\n    vc<ll>\
    \ A(2 * N - 1);\n    FOR(i, len(A)) A[i] = RNG(0, N);\n    vc<int> I = EGZ(N,\
    \ A);\n    ll sm = 0;\n    for (int i : I) sm += A[i];\n    assert(len(I) == N\
    \ && sm % N == 0);\n    sort(all(I));\n    FOR(i, len(I) - 1) assert(I[i] != I[i\
    \ + 1]);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(N, 1, 100) test(N);\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"nt/EGZ.hpp\"\n\nvoid test(int N)\
    \ {\n  FOR(1000) {\n    vc<ll> A(2 * N - 1);\n    FOR(i, len(A)) A[i] = RNG(0,\
    \ N);\n    vc<int> I = EGZ(N, A);\n    ll sm = 0;\n    for (int i : I) sm += A[i];\n\
    \    assert(len(I) == N && sm % N == 0);\n    sort(all(I));\n    FOR(i, len(I)\
    \ - 1) assert(I[i] != I[i + 1]);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(N, 1, 100)\
    \ test(N);\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - nt/EGZ.hpp
  - ds/csr.hpp
  - mod/mod_inv.hpp
  isVerificationFile: true
  path: test/1_mytest/EGZ.test.cpp
  requiredBy: []
  timestamp: '2026-09-01 06:31:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/EGZ.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/EGZ.test.cpp
- /verify/test/1_mytest/EGZ.test.cpp.html
title: test/1_mytest/EGZ.test.cpp
---
