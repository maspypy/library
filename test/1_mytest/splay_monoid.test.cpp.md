---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_monoid.hpp
    title: ds/splaytree/splaytree_monoid.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/splay_monoid.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(x)\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parity(x) & 1 ? -1 : 1);\
    \ }\nint popcnt_sgn(u64 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 -\
    \ __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\
    \ [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return\
    \ ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 2 \"alg/monoid/assign.hpp\"\
    \n\r\ntemplate <typename X, int none_val>\r\nstruct Monoid_Assign {\r\n  using\
    \ value_type = X;\r\n  static X op(X x, X y) { return (y == X(none_val) ? x :\
    \ y); }\r\n  static constexpr X unit() { return X(none_val); }\r\n  static constexpr\
    \ bool commute = false;\r\n};\r\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1)\
    \ : mint(0)); }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"\
    mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr u32\
    \ umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n  static\
    \ modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr\
    \ modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr\
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x) : val(x % umod)\
    \ {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr\
    \ modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r \u306F\
    \ 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info() {\n\
    \    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 943718401) return {22, 663003469};\n    if (mod == 998244353) return {23,\
    \ 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if (mod == 1012924417)\
    \ return {21, 368093570};\n    return {-1, -1};\n  }\n  static constexpr bool\
    \ can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int\
    \ mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  //\
    \ assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"ds/splaytree/splaytree.hpp\"\n\
    \n/*\nupdate \u3067\u3061\u3083\u3093\u3068 prod \u304C\u8A08\u7B97\u3055\u308C\
    \u3066\u304F\u308C\u308C\u3070 prod \u306F op(lprod,x,rprod) \u3067\u306A\u304F\
    \u3066\u3082\u3088\u3044.\n*/\n\n// Node \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\
    \u3066\u4F7F\u3046\ntemplate <typename Node>\nstruct SplayTree {\n  Node *pool;\n\
    \  const int NODES;\n  int pid;\n  using np = Node *;\n  using X = typename Node::value_type;\n\
    \  using A = typename Node::operator_type;\n  vc<np> FREE;\n\n  SplayTree(int\
    \ NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n  ~SplayTree() {\
    \ delete[] pool; }\n\n  void free_subtree(np c) {\n    if (!c) return;\n    auto\
    \ dfs = [&](auto &dfs, np c) -> void {\n      if (c->l) dfs(dfs, c->l);\n    \
    \  if (c->r) dfs(dfs, c->r);\n      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\
    \n  void reset() {\n    pid = 0;\n    FREE.clear();\n  }\n\n  np new_root() {\
    \ return nullptr; }\n\n  np new_node(const X &x) {\n    assert(!FREE.empty() ||\
    \ pid < NODES);\n    np n = (FREE.empty() ? &(pool[pid++]) : POP(FREE));\n   \
    \ Node::new_node(n, x);\n    return n;\n  }\n\n  np new_node(const vc<X> &dat)\
    \ {\n    auto dfs = [&](auto &dfs, int l, int r) -> np {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      int m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1,\
    \ r);\n      np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n  \
    \    root->update();\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  u32 get_size(np root) { return (root ? root->size : 0); }\n\n  np merge(np\
    \ l_root, np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return\
    \ l_root;\n    assert((!l_root->p) && (!r_root->p));\n    splay_kth(r_root, 0);\
    \ // splay \u3057\u305F\u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n   \
    \ l_root->p = r_root;\n    r_root->update();\n    return r_root;\n  }\n  np merge3(np\
    \ a, np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np\
    \ c, np d) { return merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np\
    \ root, u32 k) {\n    assert(!root || !root->p);\n    if (k == 0) return {nullptr,\
    \ root};\n    if (k == (root->size)) return {root, nullptr};\n    splay_kth(root,\
    \ k - 1);\n    np right = root->r;\n    root->r = nullptr, right->p = nullptr;\n\
    \    root->update();\n    return {root, right};\n  }\n  tuple<np, np, np> split3(np\
    \ root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n\
    \    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np,\
    \ np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root,\
    \ d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a,\
    \ b, c, d};\n  }\n\n  // \u90E8\u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\
    \u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\
    \u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\
    \u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\
    \u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay\
    \ \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np\
    \ &root, u32 l, u32 r) {\n    if (l == 0 && r == root->size) return;\n    if (l\
    \ == 0) {\n      splay_kth(root, r);\n      root = root->l;\n      return;\n \
    \   }\n    if (r == root->size) {\n      splay_kth(root, l - 1);\n      root =\
    \ root->r;\n      return;\n    }\n    splay_kth(root, r);\n    np rp = root;\n\
    \    root = rp->l;\n    root->p = nullptr;\n    splay_kth(root, l - 1);\n    root->p\
    \ = rp;\n    rp->l = root;\n    rp->update();\n    root = root->r;\n  }\n\n  vc<X>\
    \ get_all(const np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np\
    \ root) -> void {\n      if (!root) return;\n      root->prop();\n      dfs(dfs,\
    \ root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n  \
    \  dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k) {\n    assert(root\
    \ == nullptr || !root->p);\n    splay_kth(root, k);\n    return root->get();\n\
    \  }\n\n  void set(np &root, u32 k, const X &x) {\n    assert(root != nullptr\
    \ && !root->p);\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np\
    \ &root, u32 k, const X &x) {\n    assert(root != nullptr && !root->p);\n    splay_kth(root,\
    \ k);\n    root->multiply(x);\n  }\n\n  X prod(np &root, u32 l, u32 r) {\n   \
    \ assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    if (l == r) return Mono::unit();\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    goto_between(root, l, r);\n    X res = root->prod;\n    splay(root, true);\n\
    \    return res;\n  }\n\n  X prod(np &root) {\n    assert(root == nullptr || !root->p);\n\
    \    using Mono = typename Node::Monoid_X;\n    return (root ? root->prod : Mono::unit());\n\
    \  }\n\n  void apply(np &root, u32 l, u32 r, const A &a) {\n    if (l == r) return;\n\
    \    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n\
    \    root->apply(a);\n    splay(root, true);\n  }\n  void apply(np &root, const\
    \ A &a) {\n    if (!root) return;\n    root->apply(a);\n  }\n\n  void reverse(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    if (l\
    \ == r) return;\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    root->reverse();\n    splay(root, true);\n  }\n  void reverse(np\
    \ root) {\n    if (!root) return;\n    root->reverse();\n  }\n\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update\
    \ \u306F rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r\
    \ = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n    \
    \  p->r = c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r\
    \ == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\
    \n  void prop_from_root(np c) {\n    if (!c->p) {\n      c->prop();\n      return;\n\
    \    }\n    prop_from_root(c->p);\n    c->prop();\n  }\n\n  void splay(Node *me,\
    \ bool prop_from_root_done) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\
    \u3067\u3001me \u306E\u7956\u5148\uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\
    \u306B prop \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\
    \u306B\u3001splay \u7D42\u4E86\u6642\u70B9\u3067 me \u306F upd / prop \u6E08\u3067\
    \u3042\u308B\n    if (!prop_from_root_done) prop_from_root(me);\n    me->prop();\n\
    \    while (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp)\
    \ {\n        rotate(me);\n        p->update();\n        break;\n      }\n    \
    \  bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n   \
    \   if (same) rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n\
    \      pp->update(), p->update();\n    }\n    // me \u306E update \u306F\u6700\
    \u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np\
    \ &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n\
    \      root->prop();\n      u32 sl = (root->l ? root->l->size : 0);\n      if\
    \ (k == sl) break;\n      if (k < sl)\n        root = root->l;\n      else {\n\
    \        k -= sl + 1;\n        root = root->r;\n      }\n    }\n    splay(root,\
    \ true);\n  }\n\n  // check(x), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\
    \u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template\
    \ <typename F>\n  pair<np, np> split_max_right(np root, F check) {\n    if (!root)\
    \ return {nullptr, nullptr};\n    assert(!root->p);\n    np c = find_max_right(root,\
    \ check);\n    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n\
    \    }\n    splay(c, true);\n    np right = c->r;\n    if (!right) return {c,\
    \ nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n\
    \    return {c, right};\n  }\n\n  // check(x, cnt), \u5DE6\u5074\u306E\u30CE\u30FC\
    \u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\
    \u308B\n  template <typename F>\n  pair<np, np> split_max_right_cnt(np root, F\
    \ check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_cnt(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right_prod(np root, F check) {\n    if (!root) return {nullptr,\
    \ nullptr};\n    assert(!root->p);\n    np c = find_max_right_prod(root, check);\n\
    \    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n    }\n\
    \    splay(c, true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_cnt(np\
    \ root, const F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok\
    \ \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok\
    \ = nullptr, last = nullptr;\n    ll n = 0;\n    while (root) {\n      last =\
    \ root;\n      root->prop();\n      ll ns = (root->l ? root->l->size : 0);\n \
    \     if (check(root->x, n + ns + 1)) {\n        last_ok = root;\n        n +=\
    \ ns + 1;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\n  template\
    \ <typename F>\n  np find_max_right_prod(np root, const F &check) {\n    using\
    \ Mono = typename Node::Monoid_X;\n    X prod = Mono::unit();\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->prop();\n      np tmp = root->r;\n      root->r\
    \ = nullptr;\n      root->update();\n      X lprod = Mono::op(prod, root->prod);\n\
    \      root->r = tmp;\n      root->update();\n      if (check(lprod)) {\n    \
    \    prod = lprod;\n        last_ok = root;\n        root = root->r;\n      }\
    \ else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n  \
    \  return last_ok;\n  }\n};\n#line 2 \"ds/splaytree/splaytree_monoid.hpp\"\n\n\
    namespace SplayTreeNodes {\ntemplate <typename Monoid>\nstruct Node_Monoid {\n\
    \  using Monoid_X = Monoid;\n  using X = typename Monoid::value_type;\n  using\
    \ value_type = X;\n  using operator_type = int; // \u5B9A\u7FA9\u3060\u3051\u3057\
    \u3066\u304A\u304F\n  using np = Node_Monoid *;\n\n  np p, l, r;\n  X x, prod,\
    \ rev_prod;\n  u32 size;\n  bool rev;\n\n  static void new_node(np n, const X\
    \ &x) {\n    n->p = n->l = n->r = nullptr;\n    n->x = n->prod = n->rev_prod =\
    \ x;\n    n->size = 1;\n    n->rev = 0;\n  }\n\n  void update() {\n    size =\
    \ 1;\n    prod = rev_prod = x;\n    if (l) {\n      size += l->size;\n      prod\
    \ = Monoid::op(l->prod, prod);\n      rev_prod = Monoid::op(rev_prod, l->rev_prod);\n\
    \    }\n    if (r) {\n      size += r->size;\n      prod = Monoid::op(prod, r->prod);\n\
    \      rev_prod = Monoid::op(r->rev_prod, rev_prod);\n    }\n  }\n\n  void prop()\
    \ {\n    if (rev) {\n      if (l) {\n        l->rev ^= 1;\n        swap(l->l,\
    \ l->r);\n        swap(l->prod, l->rev_prod);\n      }\n      if (r) {\n     \
    \   r->rev ^= 1;\n        swap(r->l, r->r);\n        swap(r->prod, r->rev_prod);\n\
    \      }\n      rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\
    \u3070\u308C\u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\
    \u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\
    \u304C\u3063\u3066\u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  X get()\
    \ { return x; }\n  void set(const X &xx) {\n    x = xx;\n    update();\n  }\n\
    \  void multiply(const X &xx) {\n    x = Monoid::op(x, xx);\n    update();\n \
    \ }\n  void reverse() {\n    swap(prod, rev_prod);\n    swap(l, r);\n    rev ^=\
    \ 1;\n  }\n};\ntemplate <typename Monoid>\nusing SplayTree_Monoid = SplayTree<Node_Monoid<Monoid>>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_Monoid;\n#line\
    \ 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/splay_monoid.test.cpp\"\n\nusing\
    \ mint = modint998;\n\nvoid test() {\n  using Mono = Monoid_Assign<int, -1>;\n\
    \n  FOR(1000) {\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vc<int>\
    \ A(N);\n    FOR(i, N) A[i] = RNG(0, 100);\n    SplayTree_Monoid<Mono> X(N);\n\
    \    auto root = X.new_node(A);\n\n    FOR(Q) {\n      vc<int> cand = {0, 1, 2,\
    \ 3, 4, 5};\n      int t = cand[RNG(0, len(cand))];\n      if (t == 0) {\n   \
    \     int i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n \
    \     if (t == 1) {\n        int i = RNG(0, N);\n        int x = RNG(0, 100);\n\
    \        X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n\
    \        int i = RNG(0, N);\n        int x = RNG(0, 100);\n        X.multiply(root,\
    \ i, x);\n        A[i] = Mono::op(A[i], x);\n      }\n      if (t == 3) {\n  \
    \      int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        vc<int> B = {A.begin() + L, A.begin() + R};\n   \
    \     assert(X.prod(root, L, R) == B.back());\n      }\n      if (t == 4) {\n\
    \        int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        X.reverse(root, L, R);\n        reverse(A.begin()\
    \ + L, A.begin() + R);\n      }\n      if (t == 5) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/monoid/assign.hpp\"\n#include \"mod/modint.hpp\"\n#include \"\
    ds/splaytree/splaytree_monoid.hpp\"\n#include \"random/base.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid test() {\n  using Mono = Monoid_Assign<int, -1>;\n\n  FOR(1000)\
    \ {\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vc<int> A(N);\n \
    \   FOR(i, N) A[i] = RNG(0, 100);\n    SplayTree_Monoid<Mono> X(N);\n    auto\
    \ root = X.new_node(A);\n\n    FOR(Q) {\n      vc<int> cand = {0, 1, 2, 3, 4,\
    \ 5};\n      int t = cand[RNG(0, len(cand))];\n      if (t == 0) {\n        int\
    \ i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n      if (t\
    \ == 1) {\n        int i = RNG(0, N);\n        int x = RNG(0, 100);\n        X.set(root,\
    \ i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n        int i = RNG(0,\
    \ N);\n        int x = RNG(0, 100);\n        X.multiply(root, i, x);\n       \
    \ A[i] = Mono::op(A[i], x);\n      }\n      if (t == 3) {\n        int L = RNG(0,\
    \ N);\n        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n\
    \        vc<int> B = {A.begin() + L, A.begin() + R};\n        assert(X.prod(root,\
    \ L, R) == B.back());\n      }\n      if (t == 4) {\n        int L = RNG(0, N);\n\
    \        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n  \
    \      X.reverse(root, L, R);\n        reverse(A.begin() + L, A.begin() + R);\n\
    \      }\n      if (t == 5) {\n        vc<int> B = X.get_all(root);\n        assert(A\
    \ == B);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - alg/monoid/assign.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - ds/splaytree/splaytree_monoid.hpp
  - ds/splaytree/splaytree.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/splay_monoid.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/splay_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/splay_monoid.test.cpp
- /verify/test/1_mytest/splay_monoid.test.cpp.html
title: test/1_mytest/splay_monoid.test.cpp
---
