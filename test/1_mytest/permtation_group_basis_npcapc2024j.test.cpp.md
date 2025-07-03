---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: seq/permutation_group_basis.hpp
    title: seq/permutation_group_basis.hpp
  - icon: ':x:'
    path: string/split.hpp
    title: string/split.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
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
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
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
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp\"\
    \n\n#line 1 \"seq/permutation_group_basis.hpp\"\n\n// https://codeforces.com/blog/entry/111290\n\
    // https://codeforces.com/gym/421334/problem/A\n// https://atcoder.jp/contests/npcapc_2024/tasks/npcapc_2024_j\n\
    template <int NMAX>\nstruct Permutation_Group_Basis {\n  using A = array<u8, NMAX>;\n\
    \  int n;\n  // Basis[i]: i \u672A\u6E80\u306F\u56FA\u5B9A\u3057\u3066 i \u3092\
    \u52D5\u304B\u3059\u90E8\u5206\n  // \u4F5C\u308C\u308B\u7FA4\uFF1Ag=g[0]g[1]...g[n-1]\n\
    \  // g[i]: i \u672A\u6E80\u3092\u56FA\u5B9A\u3057\u3066 i \u3092\u52D5\u304B\u3059\
    \u5199\u50CF\n  // g \u304B\u3089 g[i] \u3092\u5FA9\u5143\u3059\u308B\u306B\u306F\
    \uFF0C\u5C0F\u3055\u3044 i \u304B\u3089\u9806\u306B\u6C7A\u3081\u308B\n  vvc<A>\
    \ Basis;\n\n  // q := p\n  void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i]\
    \ = p[i]; }\n  // r := pq\n  void op(int lv, const A& p, A& q, A& r) { FOR(i,\
    \ lv, n) r[i] = p[q[i]]; }\n  // q := inv(p)\n  void inv(int lv, const A& p, A&\
    \ q) { FOR(i, lv, n) q[p[i]] = i; }\n\n  // N^2 \u500B\u4EE5\u4E0B\u751F\u6210\
    \u5143\u3092 sims filter \u3067\u7BA1\u7406\n  struct S {\n    int n, lv;\n  \
    \  A dat[NMAX][NMAX];\n    A idat[NMAX][NMAX];\n    bool exist[NMAX][NMAX];\n\
    \    S(int n, int lv) : n(n), lv(lv) { FOR(i, NMAX) FOR(j, NMAX) exist[i][j] =\
    \ 0; }\n    void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i] = p[i]; }\n\
    \    void op(int lv, const A& p, A& q, A& r) { FOR(i, lv, n) r[i] = p[q[i]]; }\n\
    \    void inv(int lv, const A& p, A& q) { FOR(i, lv, n) q[p[i]] = i; }\n    void\
    \ add(A& p) {\n      static A tmp;\n      FOR(i, lv, n) {\n        if (p[i] ==\
    \ i) continue;\n        if (!exist[i][p[i]]) {\n          cp(i, p, dat[i][p[i]]);\n\
    \          inv(i, p, idat[i][p[i]]);\n          exist[i][p[i]] = 1;\n        \
    \  break;\n        }\n        op(i, idat[i][p[i]], p, tmp);\n        cp(i, tmp,\
    \ p);\n      }\n    }\n    vc<A> get_all() {\n      vc<A> ANS;\n      FOR(i, lv,\
    \ n) {\n        FOR(j, i, n) {\n          if (!exist[i][j]) continue;\n      \
    \    A a = dat[i][j];\n          FOR(k, i) a[k] = k;\n          ANS.eb(a);\n \
    \       }\n      }\n      return ANS;\n    }\n  };\n\n  Permutation_Group_Basis(int\
    \ n, vvc<int> generator) : n(n), Basis(n) {\n    S gen(n, 0);\n    for (auto&\
    \ pp: generator) {\n      assert(len(pp) == n);\n      A a;\n      FOR(i, n) a[i]\
    \ = pp[i];\n      gen.add(a);\n    }\n    FOR(lv, n) gen = step(gen);\n  }\n\n\
    private:\n  S step(S gen) {\n    auto X = gen.get_all();\n    int lv = gen.lv;\n\
    \    vc<A> basis(n);\n    vc<A> ibasis(n);\n    vc<bool> vis(n);\n    auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n      auto& p = basis[v];\n      for (auto&\
    \ q: X) {\n        int w = q[v];\n        if (vis[w]) continue;\n        vis[w]\
    \ = 1;\n        op(lv, q, p, basis[w]);\n        inv(lv, basis[w], ibasis[w]);\n\
    \        dfs(dfs, w);\n      }\n    };\n    vis[lv] = 1;\n    FOR(i, n) basis[lv][i]\
    \ = ibasis[lv][i] = i;\n    dfs(dfs, lv);\n\n    S nxtgen(n, lv + 1);\n    static\
    \ A tmp, tmp2;\n    FOR(u, lv, n) {\n      if (!vis[u]) continue;\n      FOR(i,\
    \ lv) basis[u][i] = i;\n      Basis[lv].eb(basis[u]);\n      for (auto& s: X)\
    \ {\n        assert(vis[s[u]]);\n        op(lv, ibasis[s[u]], s, tmp);\n     \
    \   op(lv, tmp, basis[u], tmp2);\n        assert(tmp2[lv] == lv);\n        nxtgen.add(tmp2);\n\
    \      }\n    }\n    return nxtgen;\n  }\n};\n#line 2 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (len(dat) <= n) {\n    int k = len(dat);\n    int q = (mod + k - 1) /\
    \ k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n  }\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(0 <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <typename mint>\nmint fact_inv(int n) {\n  static vector<mint> dat\
    \ = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
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
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\
    \ return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large, dense>(n + d\
    \ - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod < u32(1) <<\
    \ 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n    x.val =\
    \ v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32\
    \ x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr\
    \ modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod)\
    \ < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n\
    \  bool operator<(const modint &other) const { return val < other.val; }\n  modint\
    \ &operator+=(const modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n\
    \    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if ((val\
    \ += umod - p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const\
    \ modint &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n \
    \ modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  modint operator-() const { return modint::raw(val ? mod - val\
    \ : u32(0)); }\n  modint operator+(const modint &p) const { return modint(*this)\
    \ += p; }\n  modint operator-(const modint &p) const { return modint(*this) -=\
    \ p; }\n  modint operator*(const modint &p) const { return modint(*this) *= p;\
    \ }\n  modint operator/(const modint &p) const { return modint(*this) /= p; }\n\
    \  bool operator==(const modint &p) const { return val == p.val; }\n  bool operator!=(const\
    \ modint &p) const { return val != p.val; }\n  modint inverse() const {\n    int\
    \ a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n\
    \      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n\
    \  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n \
    \   assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n     \
    \ if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 1 \"string/split.hpp\"\nvc<string>\
    \ split(string S, char sep = ',') {\r\n  vc<string> res = {\"\"};\r\n  for (auto&&\
    \ s: S) {\r\n    if (s == sep)\r\n      res.eb(\"\");\r\n    else\r\n      res.back()\
    \ += s;\r\n  }\r\n  return res;\r\n}\r\n\r\nvc<string> split(string S, string\
    \ seps = \" ,\") {\r\n  vc<string> res = {\"\"};\r\n  for (auto&& s: S) {\r\n\
    \    if (count(all(seps), s))\r\n      res.eb(\"\");\r\n    else\r\n      res.back()\
    \ += s;\r\n  }\r\n  return res;\r\n}\r\n#line 7 \"test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp\"\
    \n\nusing mint = modint998;\n\nmint mysolve(vvc<int> A) {\n  int N = len(A[0]),\
    \ M = len(A);\n  FOR(i, M) FOR(j, N)-- A[i][j];\n  Permutation_Group_Basis<30>\
    \ P(N, A);\n\n  mint ANS = 0;\n  // FOR(i, N) {\n  //   for (auto& X: P.Basis[i])\
    \ { SHOW(i, X); }\n  // }\n\n  FOR(a, N) {\n    // (a, a \u3088\u308A\u5927\u304D\
    \u3044\u8981\u7D20) \u306E\u5834\u6240\u3092\u8FFD\u8DE1\n    vv(mint, dp, N,\
    \ N);\n    FOR(b, a + 1, N) dp[a][b] = 1;\n    FOR_R(i, N) {\n      vv(mint, newdp,\
    \ N, N);\n      for (auto& X: P.Basis[i]) {\n        FOR(a, N) FOR(b, N) { newdp[X[a]][X[b]]\
    \ += dp[a][b]; }\n      }\n      swap(dp, newdp);\n    }\n    FOR(i, N) FOR(j,\
    \ i) ANS += dp[i][j];\n  }\n  return ANS;\n}\n\nvoid test_sample_1() {\n  vv(int,\
    \ A, 2, 3);\n  A[0] = {1, 2, 3};\n  A[1] = {2, 3, 1};\n  assert(mysolve(A) ==\
    \ mint(4));\n}\n\nvoid test_sample_2() {\n  vv(int, A, 2, 5);\n  A[0] = {3, 4,\
    \ 5, 1, 2};\n  A[1] = {1, 5, 4, 3, 2};\n  assert(mysolve(A) == mint(50));\n}\n\
    \nvoid test_sample_3() {\n  vv(int, A, 12, 30);\n  auto from_text = [&](string\
    \ txt) -> vc<int> {\n    vc<int> row;\n    for (auto& x: split(txt, \" \")) row.eb(stoi(x));\n\
    \    return row;\n  };\n  A[0] = from_text(\"1 2 9 4 5 6 7 8 3 10 11 12 19 14\
    \ 15 25 17 18 20 26 21 22 23 24 16 29 27 28 13 30\");\n  A[1] = from_text(\"9\
    \ 2 27 4 5 10 7 8 1 25 11 12 24 14 15 16 17 18 19 20 21 22 23 28 6 26 3 13 29\
    \ 30\");\n  A[2] = from_text(\"1 5 3 29 2 6 7 8 9 10 11 12 13 16 15 18 17 14 19\
    \ 20 21 22 28 27 25 26 24 23 4 30\");\n  A[3] = from_text(\"7 2 3 25 5 6 1 28\
    \ 21 15 11 12 13 14 10 17 16 18 19 20 9 22 23 24 4 26 27 8 29 30\");\n  A[4] =\
    \ from_text(\"1 2 5 4 16 6 7 8 9 11 10 3 13 14 15 12 17 23 19 20 21 29 18 24 25\
    \ 26 27 28 22 30\");\n  A[5] = from_text(\"19 24 3 4 1 6 7 8 9 10 11 12 13 21\
    \ 15 16 17 18 5 22 20 14 23 2 25 26 27 28 29 30\");\n  A[6] = from_text(\"1 2\
    \ 3 4 5 6 27 8 9 10 29 12 24 14 15 16 17 18 30 20 7 22 13 23 25 26 21 28 11 19\"\
    );\n  A[7] = from_text(\"1 2 25 4 5 6 7 8 9 20 23 12 13 14 15 16 17 18 19 10 29\
    \ 22 3 24 11 26 27 28 30 21\");\n  A[8] = from_text(\"1 2 16 4 5 6 3 8 9 10 11\
    \ 12 22 29 13 7 17 18 19 20 21 15 23 24 14 26 27 28 25 30\");\n  A[9] = from_text(\"\
    1 13 3 4 5 6 21 8 24 10 7 12 20 14 15 16 17 2 19 18 11 22 23 9 25 26 27 28 29\
    \ 30\");\n  A[10] = from_text(\"1 2 3 4 5 6 25 8 9 19 11 12 13 7 10 16 21 18 15\
    \ 20 17 22 23 24 28 26 27 14 29 30\");\n  A[11] = from_text(\"1 2 27 21 5 6 7\
    \ 8 9 10 18 24 13 14 15 16 17 12 19 11 4 22 23 20 25 26 3 28 29 30\");\n  assert(mysolve(A)\
    \ == mint(701414999));\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n \
    \ cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test_sample_1();\n  test_sample_2();\n\
    \  test_sample_3();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"seq/permutation_group_basis.hpp\"\n#include \"mod/modint.hpp\"\n\
    #include \"string/split.hpp\"\n\nusing mint = modint998;\n\nmint mysolve(vvc<int>\
    \ A) {\n  int N = len(A[0]), M = len(A);\n  FOR(i, M) FOR(j, N)-- A[i][j];\n \
    \ Permutation_Group_Basis<30> P(N, A);\n\n  mint ANS = 0;\n  // FOR(i, N) {\n\
    \  //   for (auto& X: P.Basis[i]) { SHOW(i, X); }\n  // }\n\n  FOR(a, N) {\n \
    \   // (a, a \u3088\u308A\u5927\u304D\u3044\u8981\u7D20) \u306E\u5834\u6240\u3092\
    \u8FFD\u8DE1\n    vv(mint, dp, N, N);\n    FOR(b, a + 1, N) dp[a][b] = 1;\n  \
    \  FOR_R(i, N) {\n      vv(mint, newdp, N, N);\n      for (auto& X: P.Basis[i])\
    \ {\n        FOR(a, N) FOR(b, N) { newdp[X[a]][X[b]] += dp[a][b]; }\n      }\n\
    \      swap(dp, newdp);\n    }\n    FOR(i, N) FOR(j, i) ANS += dp[i][j];\n  }\n\
    \  return ANS;\n}\n\nvoid test_sample_1() {\n  vv(int, A, 2, 3);\n  A[0] = {1,\
    \ 2, 3};\n  A[1] = {2, 3, 1};\n  assert(mysolve(A) == mint(4));\n}\n\nvoid test_sample_2()\
    \ {\n  vv(int, A, 2, 5);\n  A[0] = {3, 4, 5, 1, 2};\n  A[1] = {1, 5, 4, 3, 2};\n\
    \  assert(mysolve(A) == mint(50));\n}\n\nvoid test_sample_3() {\n  vv(int, A,\
    \ 12, 30);\n  auto from_text = [&](string txt) -> vc<int> {\n    vc<int> row;\n\
    \    for (auto& x: split(txt, \" \")) row.eb(stoi(x));\n    return row;\n  };\n\
    \  A[0] = from_text(\"1 2 9 4 5 6 7 8 3 10 11 12 19 14 15 25 17 18 20 26 21 22\
    \ 23 24 16 29 27 28 13 30\");\n  A[1] = from_text(\"9 2 27 4 5 10 7 8 1 25 11\
    \ 12 24 14 15 16 17 18 19 20 21 22 23 28 6 26 3 13 29 30\");\n  A[2] = from_text(\"\
    1 5 3 29 2 6 7 8 9 10 11 12 13 16 15 18 17 14 19 20 21 22 28 27 25 26 24 23 4\
    \ 30\");\n  A[3] = from_text(\"7 2 3 25 5 6 1 28 21 15 11 12 13 14 10 17 16 18\
    \ 19 20 9 22 23 24 4 26 27 8 29 30\");\n  A[4] = from_text(\"1 2 5 4 16 6 7 8\
    \ 9 11 10 3 13 14 15 12 17 23 19 20 21 29 18 24 25 26 27 28 22 30\");\n  A[5]\
    \ = from_text(\"19 24 3 4 1 6 7 8 9 10 11 12 13 21 15 16 17 18 5 22 20 14 23 2\
    \ 25 26 27 28 29 30\");\n  A[6] = from_text(\"1 2 3 4 5 6 27 8 9 10 29 12 24 14\
    \ 15 16 17 18 30 20 7 22 13 23 25 26 21 28 11 19\");\n  A[7] = from_text(\"1 2\
    \ 25 4 5 6 7 8 9 20 23 12 13 14 15 16 17 18 19 10 29 22 3 24 11 26 27 28 30 21\"\
    );\n  A[8] = from_text(\"1 2 16 4 5 6 3 8 9 10 11 12 22 29 13 7 17 18 19 20 21\
    \ 15 23 24 14 26 27 28 25 30\");\n  A[9] = from_text(\"1 13 3 4 5 6 21 8 24 10\
    \ 7 12 20 14 15 16 17 2 19 18 11 22 23 9 25 26 27 28 29 30\");\n  A[10] = from_text(\"\
    1 2 3 4 5 6 25 8 9 19 11 12 13 7 10 16 21 18 15 20 17 22 23 24 28 26 27 14 29\
    \ 30\");\n  A[11] = from_text(\"1 2 27 21 5 6 7 8 9 10 18 24 13 14 15 16 17 12\
    \ 19 11 4 22 23 20 25 26 3 28 29 30\");\n  assert(mysolve(A) == mint(701414999));\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_sample_1();\n  test_sample_2();\n  test_sample_3();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - seq/permutation_group_basis.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - string/split.hpp
  isVerificationFile: true
  path: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
- /verify/test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp.html
title: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
---
