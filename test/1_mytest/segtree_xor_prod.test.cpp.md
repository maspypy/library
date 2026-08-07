---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/segtree_xor_prod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(USE_PCH)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n//\
    \ \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\
    \u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"\
    avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include <cassert>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class>\nconstexpr\
    \ bool dependent_false = false;\n\ntemplate <class T>\nconstexpr T infty = []\
    \ {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\");\n  return\
    \ T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
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
    }\n#endif\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class\
    \ Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n\
    \  SegTree(int n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f)\
    \ {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size)\
    \ update(i);\n  }\n\n  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all()\
    \ const { return {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int\
    \ i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const\
    \ X& x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n   \
    \ while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R\
    \ & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return\
    \ Monoid::op(vl, vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n \
    \   while (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n\
    \      L >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n   \
    \ return I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class\
    \ F>\n  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n &&\
    \ check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n    X sm\
    \ = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm,\
    \ dat[L]))) {\n        while (L < size) {\n          L = 2 * L;\n          if\
    \ (check(Monoid::op(sm, dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n\
    \          }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >>\
    \ k) + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 6 \"test/1_mytest/segtree_xor_prod.test.cpp\"\
    \n\nvoid test() {\n  FOR(100) {\n    int n = RNG(0, 5);\n    int N = 1 << n;\n\
    \    using Mono = Monoid_Add<int>;\n    vc<int> A(N);\n    FOR(i, N) A[i] = RNG(0,\
    \ 10);\n    SegTree<Mono> seg(A);\n    FOR(100) {\n      int t = RNG(0, 2);\n\
    \      if (t == 0) {\n        int i = RNG(0, N);\n        int x = RNG(0, 10);\n\
    \        seg.set(i, x);\n        A[i] = x;\n      }\n      if (t == 1) {\n   \
    \     int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        int xor_val = RNG(0, N);\n        int sm = 0;\n \
    \       FOR(i, L, R) sm += A[i ^ xor_val];\n        assert(sm == seg.xor_prod(L,\
    \ R, xor_val));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n#include \"random/base.hpp\"\n#include \"ds/segtree/segtree.hpp\"\
    \n\nvoid test() {\n  FOR(100) {\n    int n = RNG(0, 5);\n    int N = 1 << n;\n\
    \    using Mono = Monoid_Add<int>;\n    vc<int> A(N);\n    FOR(i, N) A[i] = RNG(0,\
    \ 10);\n    SegTree<Mono> seg(A);\n    FOR(100) {\n      int t = RNG(0, 2);\n\
    \      if (t == 0) {\n        int i = RNG(0, N);\n        int x = RNG(0, 10);\n\
    \        seg.set(i, x);\n        A[i] = x;\n      }\n      if (t == 1) {\n   \
    \     int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        int xor_val = RNG(0, N);\n        int sm = 0;\n \
    \       FOR(i, L, R) sm += A[i ^ xor_val];\n        assert(sm == seg.xor_prod(L,\
    \ R, xor_val));\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/monoid/add.hpp
  - random/base.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: true
  path: test/1_mytest/segtree_xor_prod.test.cpp
  requiredBy: []
  timestamp: '2026-08-08 05:13:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/segtree_xor_prod.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/segtree_xor_prod.test.cpp
- /verify/test/1_mytest/segtree_xor_prod.test.cpp.html
title: test/1_mytest/segtree_xor_prod.test.cpp
---
