---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/stern_brocot_tree.hpp
    title: nt/stern_brocot_tree.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/stern_brocot.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n\
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
    \ abs(a);\n}\n#endif\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n                 \
    \     chrono::high_resolution_clock::now().time_since_epoch())\n             \
    \             .count()) *\n                  10150724397891781847ULL;\n  x_ ^=\
    \ x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim > 0);\n\
    \  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n  return\
    \ l + RNG_64() % (r - l);\n}\n#line 1 \"nt/stern_brocot_tree.hpp\"\n\nstruct Stern_Brocot_Tree\
    \ {\n  using PATH = vi; // \u306F\u3058\u3081\u306F R\n\n  static tuple<PATH,\
    \ pi, pi> get_path_and_range(pi x) {\n    PATH path;\n    pi l = {0, 1}, r = {1,\
    \ 0};\n    pi m = {1, 1};\n    ll det_l = l.fi * x.se - l.se * x.fi;\n    ll det_r\
    \ = r.fi * x.se - r.se * x.fi;\n    ll det_m = det_l + det_r;\n    while (1) {\n\
    \      if (det_m == 0) break;\n      ll k = ceil(-det_m, det_r);\n      path.eb(k);\n\
    \      l = {l.fi + k * r.fi, l.se + k * r.se};\n      m = {l.fi + r.fi, l.se +\
    \ r.se};\n      det_l += k * det_r;\n      det_m += k * det_r;\n      if (det_m\
    \ == 0) break;\n      k = ceil(det_m, -det_l);\n      path.eb(k);\n      r = {r.fi\
    \ + k * l.fi, r.se + k * l.se};\n      m = {l.fi + r.fi, l.se + r.se};\n     \
    \ det_r += k * det_l;\n      det_m += k * det_l;\n    }\n    return {path, l,\
    \ r};\n  }\n\n  static PATH get_path(pi x) {\n    auto [path, l, r] = get_path_and_range(x);\n\
    \    return path;\n  }\n\n  static pair<pi, pi> range(pi x) {\n    auto [path,\
    \ l, r] = get_path_and_range(x);\n    return {l, r};\n  }\n\n  // x in range(y)\n\
    \  static bool in_subtree(pi x, pi y) {\n    auto [l, r] = range(y);\n    bool\
    \ ok_l = i128(x.fi) * l.se - i128(x.se) * l.fi > 0;\n    bool ok_r = i128(r.fi)\
    \ * x.se - i128(r.se) * x.fi > 0;\n    return ok_l && ok_r;\n  }\n\n  template\
    \ <typename T = ll>\n  static pair<T, T> from_path(PATH& p) {\n    using P = pair<T,\
    \ T>;\n    P l = {0, 1}, r = {1, 0};\n    FOR(i, len(p)) {\n      ll k = p[i];\n\
    \      if (i % 2 == 0) {\n        l.fi += T(k) * r.fi;\n        l.se += T(k) *\
    \ r.se;\n      }\n      if (i % 2 == 1) {\n        r.fi += T(k) * l.fi;\n    \
    \    r.se += T(k) * l.se;\n      }\n    }\n    return {l.fi + r.fi, l.se + r.se};\n\
    \  }\n\n  static pair<pi, pi> child(pi x) {\n    auto [l, r] = range(x);\n   \
    \ pi lc = {l.fi + x.fi, l.se + x.se};\n    pi rc = {x.fi + r.fi, x.se + r.se};\n\
    \    return {lc, rc};\n  }\n\n  static pi LCA(pi x, pi y) {\n    auto Px = get_path(x);\n\
    \    auto Py = get_path(y);\n    vi P;\n    FOR(i, min(len(Px), len(Py))) {\n\
    \      ll k = min(Px[i], Py[i]);\n      P.eb(k);\n      if (k < Px[i] || k < Py[i])\
    \ break;\n    }\n    return from_path(P);\n  }\n\n  static pi LA(pi x, ll dep)\
    \ {\n    pi l = {0, 1}, r = {1, 0};\n    pi m = {1, 1};\n    ll det_l = l.fi *\
    \ x.se - l.se * x.fi;\n    ll det_r = r.fi * x.se - r.se * x.fi;\n    ll det_m\
    \ = det_l + det_r;\n    while (1) {\n      if (det_m == 0 || dep == 0) break;\n\
    \      ll k = min(dep, ceil(-det_m, det_r));\n      l = {l.fi + k * r.fi, l.se\
    \ + k * r.se};\n      m = {l.fi + r.fi, l.se + r.se};\n      det_l += k * det_r;\n\
    \      det_m += k * det_r;\n      dep -= k;\n      if (det_m == 0 || dep == 0)\
    \ break;\n      k = min(dep, ceil(det_m, -det_l));\n      r = {r.fi + k * l.fi,\
    \ r.se + k * l.se};\n      m = {l.fi + r.fi, l.se + r.se};\n      det_r += k *\
    \ det_l;\n      det_m += k * det_l;\n      dep -= k;\n    }\n    if (dep == 0)\
    \ return m;\n    return {-1, -1};\n  }\n\n  static string to_string(PATH& p) {\n\
    \    string res;\n    char c = 'L';\n    for (auto&& x: p) {\n      c = 'L' +\
    \ 'R' - c;\n      if (x == 0) continue;\n      res += c;\n      res += \" \" +\
    \ std::to_string(x);\n    }\n    return res;\n  }\n};\n#line 5 \"test/1_mytest/stern_brocot.test.cpp\"\
    \n\nvoid test() {\n  using SBT = Stern_Brocot_Tree;\n  // get_path\n  assert(SBT::get_path({1,\
    \ 1}) == vi());\n  assert(SBT::get_path({1, 2}) == vi({0, 1}));\n  assert(SBT::get_path({2,\
    \ 1}) == vi({1}));\n  assert(SBT::get_path({1, 3}) == vi({0, 2}));\n  assert(SBT::get_path({2,\
    \ 3}) == vi({0, 1, 1}));\n  assert(SBT::get_path({3, 2}) == vi({1, 1}));\n  assert(SBT::get_path({3,\
    \ 1}) == vi({2}));\n  assert(SBT::get_path({1, 4}) == vi({0, 3}));\n  assert(SBT::get_path({2,\
    \ 5}) == vi({0, 2, 1}));\n  assert(SBT::get_path({3, 5}) == vi({0, 1, 1, 1}));\n\
    \  assert(SBT::get_path({3, 4}) == vi({0, 1, 2}));\n  assert(SBT::get_path({4,\
    \ 3}) == vi({1, 2}));\n  assert(SBT::get_path({5, 3}) == vi({1, 1, 1}));\n  assert(SBT::get_path({5,\
    \ 2}) == vi({2, 1}));\n  assert(SBT::get_path({4, 1}) == vi({3}));\n  // range\n\
    \  assert(SBT::range({1, 1}) == mp(pi{0, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 2}) == mp(pi{0, 1}, pi{1, 1}));\n  assert(SBT::range({2, 1}) == mp(pi{1, 1},\
    \ pi{1, 0}));\n  assert(SBT::range({1, 3}) == mp(pi{0, 1}, pi{1, 2}));\n  assert(SBT::range({2,\
    \ 3}) == mp(pi{1, 2}, pi{1, 1}));\n  assert(SBT::range({3, 2}) == mp(pi{1, 1},\
    \ pi{2, 1}));\n  assert(SBT::range({3, 1}) == mp(pi{2, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 4}) == mp(pi{0, 1}, pi{1, 3}));\n  assert(SBT::range({2, 5}) == mp(pi{1, 3},\
    \ pi{1, 2}));\n  assert(SBT::range({3, 5}) == mp(pi{1, 2}, pi{2, 3}));\n  assert(SBT::range({3,\
    \ 4}) == mp(pi{2, 3}, pi{1, 1}));\n  assert(SBT::range({4, 3}) == mp(pi{1, 1},\
    \ pi{3, 2}));\n  assert(SBT::range({5, 3}) == mp(pi{3, 2}, pi{2, 1}));\n  assert(SBT::range({5,\
    \ 2}) == mp(pi{2, 1}, pi{3, 1}));\n  assert(SBT::range({4, 1}) == mp(pi{3, 1},\
    \ pi{1, 0}));\n  // child\n  assert(SBT::child({1, 1}) == mp(pi{1, 2}, pi{2, 1}));\n\
    \  assert(SBT::child({1, 2}) == mp(pi{1, 3}, pi{2, 3}));\n  assert(SBT::child({2,\
    \ 1}) == mp(pi{3, 2}, pi{3, 1}));\n  assert(SBT::child({1, 3}) == mp(pi{1, 4},\
    \ pi{2, 5}));\n  assert(SBT::child({2, 3}) == mp(pi{3, 5}, pi{3, 4}));\n  assert(SBT::child({3,\
    \ 2}) == mp(pi{4, 3}, pi{5, 3}));\n  assert(SBT::child({3, 1}) == mp(pi{5, 2},\
    \ pi{4, 1}));\n  // la\n  pi NG = {-1, -1};\n  assert(SBT::LA({1, 1}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({1, 1}, 1) == NG);\n  assert(SBT::LA({3, 4}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({3, 4}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 4},\
    \ 2) == pi({2, 3}));\n  assert(SBT::LA({3, 4}, 3) == pi({3, 4}));\n  assert(SBT::LA({3,\
    \ 4}, 4) == NG);\n  assert(SBT::LA({3, 5}, 0) == pi({1, 1}));\n  assert(SBT::LA({3,\
    \ 5}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 5}, 2) == pi({2, 3}));\n  assert(SBT::LA({3,\
    \ 5}, 3) == pi({3, 5}));\n  assert(SBT::LA({3, 5}, 4) == NG);\n\n  auto get_random\
    \ = [&]() -> pi {\n    while (1) {\n      ll x = RNG(1, 1LL << 60);\n      ll\
    \ y = RNG(1, 1LL << 60);\n      if (gcd(x, y) > 1) continue;\n      return {x,\
    \ y};\n    }\n  };\n\n  FOR(10000) {\n    pi x = get_random();\n    auto [l, r]\
    \ = SBT::range(x);\n    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);\n\
    \    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);\n    assert(l.fi + r.fi\
    \ == x.fi && l.se + r.se == x.se);\n    tie(l, r) = SBT::child(x);\n    assert(i128(x.fi)\
    \ * l.se - i128(x.se) * l.fi == 1);\n    assert(i128(r.fi) * x.se - i128(r.se)\
    \ * x.fi == 1);\n    auto P = SBT::get_path(x);\n    assert(SBT::from_path<ll>(P)\
    \ == x);\n    pi y = get_random();\n    pi z = SBT::LCA(x, y);\n    assert(SBT::in_subtree(x,\
    \ z));\n    assert(SBT::in_subtree(y, z));\n    tie(l, r) = SBT::child(z);\n \
    \   assert(!SBT::in_subtree(x, l) || !SBT::in_subtree(y, l));\n    assert(!SBT::in_subtree(x,\
    \ r) || !SBT::in_subtree(y, r));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n \
    \ solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"nt/stern_brocot_tree.hpp\"\n\nvoid\
    \ test() {\n  using SBT = Stern_Brocot_Tree;\n  // get_path\n  assert(SBT::get_path({1,\
    \ 1}) == vi());\n  assert(SBT::get_path({1, 2}) == vi({0, 1}));\n  assert(SBT::get_path({2,\
    \ 1}) == vi({1}));\n  assert(SBT::get_path({1, 3}) == vi({0, 2}));\n  assert(SBT::get_path({2,\
    \ 3}) == vi({0, 1, 1}));\n  assert(SBT::get_path({3, 2}) == vi({1, 1}));\n  assert(SBT::get_path({3,\
    \ 1}) == vi({2}));\n  assert(SBT::get_path({1, 4}) == vi({0, 3}));\n  assert(SBT::get_path({2,\
    \ 5}) == vi({0, 2, 1}));\n  assert(SBT::get_path({3, 5}) == vi({0, 1, 1, 1}));\n\
    \  assert(SBT::get_path({3, 4}) == vi({0, 1, 2}));\n  assert(SBT::get_path({4,\
    \ 3}) == vi({1, 2}));\n  assert(SBT::get_path({5, 3}) == vi({1, 1, 1}));\n  assert(SBT::get_path({5,\
    \ 2}) == vi({2, 1}));\n  assert(SBT::get_path({4, 1}) == vi({3}));\n  // range\n\
    \  assert(SBT::range({1, 1}) == mp(pi{0, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 2}) == mp(pi{0, 1}, pi{1, 1}));\n  assert(SBT::range({2, 1}) == mp(pi{1, 1},\
    \ pi{1, 0}));\n  assert(SBT::range({1, 3}) == mp(pi{0, 1}, pi{1, 2}));\n  assert(SBT::range({2,\
    \ 3}) == mp(pi{1, 2}, pi{1, 1}));\n  assert(SBT::range({3, 2}) == mp(pi{1, 1},\
    \ pi{2, 1}));\n  assert(SBT::range({3, 1}) == mp(pi{2, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 4}) == mp(pi{0, 1}, pi{1, 3}));\n  assert(SBT::range({2, 5}) == mp(pi{1, 3},\
    \ pi{1, 2}));\n  assert(SBT::range({3, 5}) == mp(pi{1, 2}, pi{2, 3}));\n  assert(SBT::range({3,\
    \ 4}) == mp(pi{2, 3}, pi{1, 1}));\n  assert(SBT::range({4, 3}) == mp(pi{1, 1},\
    \ pi{3, 2}));\n  assert(SBT::range({5, 3}) == mp(pi{3, 2}, pi{2, 1}));\n  assert(SBT::range({5,\
    \ 2}) == mp(pi{2, 1}, pi{3, 1}));\n  assert(SBT::range({4, 1}) == mp(pi{3, 1},\
    \ pi{1, 0}));\n  // child\n  assert(SBT::child({1, 1}) == mp(pi{1, 2}, pi{2, 1}));\n\
    \  assert(SBT::child({1, 2}) == mp(pi{1, 3}, pi{2, 3}));\n  assert(SBT::child({2,\
    \ 1}) == mp(pi{3, 2}, pi{3, 1}));\n  assert(SBT::child({1, 3}) == mp(pi{1, 4},\
    \ pi{2, 5}));\n  assert(SBT::child({2, 3}) == mp(pi{3, 5}, pi{3, 4}));\n  assert(SBT::child({3,\
    \ 2}) == mp(pi{4, 3}, pi{5, 3}));\n  assert(SBT::child({3, 1}) == mp(pi{5, 2},\
    \ pi{4, 1}));\n  // la\n  pi NG = {-1, -1};\n  assert(SBT::LA({1, 1}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({1, 1}, 1) == NG);\n  assert(SBT::LA({3, 4}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({3, 4}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 4},\
    \ 2) == pi({2, 3}));\n  assert(SBT::LA({3, 4}, 3) == pi({3, 4}));\n  assert(SBT::LA({3,\
    \ 4}, 4) == NG);\n  assert(SBT::LA({3, 5}, 0) == pi({1, 1}));\n  assert(SBT::LA({3,\
    \ 5}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 5}, 2) == pi({2, 3}));\n  assert(SBT::LA({3,\
    \ 5}, 3) == pi({3, 5}));\n  assert(SBT::LA({3, 5}, 4) == NG);\n\n  auto get_random\
    \ = [&]() -> pi {\n    while (1) {\n      ll x = RNG(1, 1LL << 60);\n      ll\
    \ y = RNG(1, 1LL << 60);\n      if (gcd(x, y) > 1) continue;\n      return {x,\
    \ y};\n    }\n  };\n\n  FOR(10000) {\n    pi x = get_random();\n    auto [l, r]\
    \ = SBT::range(x);\n    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);\n\
    \    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);\n    assert(l.fi + r.fi\
    \ == x.fi && l.se + r.se == x.se);\n    tie(l, r) = SBT::child(x);\n    assert(i128(x.fi)\
    \ * l.se - i128(x.se) * l.fi == 1);\n    assert(i128(r.fi) * x.se - i128(r.se)\
    \ * x.fi == 1);\n    auto P = SBT::get_path(x);\n    assert(SBT::from_path<ll>(P)\
    \ == x);\n    pi y = get_random();\n    pi z = SBT::LCA(x, y);\n    assert(SBT::in_subtree(x,\
    \ z));\n    assert(SBT::in_subtree(y, z));\n    tie(l, r) = SBT::child(z);\n \
    \   assert(!SBT::in_subtree(x, l) || !SBT::in_subtree(y, l));\n    assert(!SBT::in_subtree(x,\
    \ r) || !SBT::in_subtree(y, r));\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n \
    \ solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - nt/stern_brocot_tree.hpp
  isVerificationFile: true
  path: test/1_mytest/stern_brocot.test.cpp
  requiredBy: []
  timestamp: '2026-08-30 21:41:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/stern_brocot.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/stern_brocot.test.cpp
- /verify/test/1_mytest/stern_brocot.test.cpp.html
title: test/1_mytest/stern_brocot.test.cpp
---
