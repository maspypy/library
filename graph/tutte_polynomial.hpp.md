---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/bitwise_transform.hpp
    title: setfunc/bitwise_transform.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"setfunc/sps_exp.hpp\"\n\n#line\
    \ 2 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s);\
    \ }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const\
    \ { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end()\
    \ const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  UINT s;\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ?\
    \ -1ULL : (1ULL << n) - 1; }\n#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\n#line 2\
    \ \"setfunc/bitwise_transform.hpp\"\n\nnamespace bitwise {\n\nenum class trans_type\
    \ {\n  hadamard,\n  superset_zeta,\n  superset_mobius,\n  subset_zeta,\n  subset_mobius,\n\
    \  ranked_zeta,\n  ranked_mobius,\n  superset_zeta_or\n};\n\ntemplate <typename\
    \ ARR>\ninline void ranked_add(ARR& a, const ARR& b) {\n  for (int d = 0; d <\
    \ int(a.size()); ++d) a[d] += b[d];\n}\n\ntemplate <typename ARR>\ninline void\
    \ ranked_sub(ARR& a, const ARR& b) {\n  for (int d = 0; d < int(a.size()); ++d)\
    \ a[d] -= b[d];\n}\n\ntemplate <trans_type type, int N, typename T>\ninline void\
    \ bitwise_transform_fixed(T* a) {\n  static_assert(N >= 1 && (N & (N - 1)) ==\
    \ 0);\n  if constexpr (N == 1) {\n    return;\n  } else {\n    constexpr int H\
    \ = N / 2;\n    bitwise_transform_fixed<type, H>(a);\n    bitwise_transform_fixed<type,\
    \ H>(a + H);\n    if constexpr (type == trans_type::hadamard) {\n      for (int\
    \ i = 0; i < H; ++i) {\n        auto x = a[i], y = a[H + i];\n        a[i] = x\
    \ + y, a[H + i] = x - y;\n      }\n    }\n    if constexpr (type == trans_type::superset_zeta)\
    \ {\n      for (int i = 0; i < H; ++i) a[i] += a[H + i];\n    }\n    if constexpr\
    \ (type == trans_type::superset_mobius) {\n      for (int i = 0; i < H; ++i) a[i]\
    \ -= a[H + i];\n    }\n    if constexpr (type == trans_type::subset_zeta) {\n\
    \      for (int i = 0; i < H; ++i) a[H + i] += a[i];\n    }\n    if constexpr\
    \ (type == trans_type::subset_mobius) {\n      for (int i = 0; i < H; ++i) a[H\
    \ + i] -= a[i];\n    }\n    if constexpr (type == trans_type::ranked_zeta) {\n\
    \      for (int i = 0; i < H; ++i) ranked_add(a[H + i], a[i]);\n    }\n    if\
    \ constexpr (type == trans_type::ranked_mobius) {\n      for (int i = 0; i < H;\
    \ ++i) ranked_sub(a[H + i], a[i]);\n    }\n    if constexpr (type == trans_type::superset_zeta_or)\
    \ {\n      for (int i = 0; i < H; ++i) a[i] |= a[H + i];\n    }\n  }\n}\n\ntemplate\
    \ <trans_type type, int N, typename T>\ninline void bitwise_transform_dispatch(vc<T>&\
    \ a) {\n  if (len(a) == N) {\n    return bitwise_transform_fixed<type, N>(a.data());\n\
    \  }\n  if constexpr (N > 1) {\n    return bitwise_transform_dispatch<type, N\
    \ / 2>(a);\n  }\n}\n\ntemplate <trans_type type, typename T>\ninline void bitwise_transform(vc<T>&\
    \ a) {\n  int n = len(a);\n  assert(n >= 1);\n  assert((n & (n - 1)) == 0);\n\
    \  assert(n <= (1 << 25));\n  bitwise_transform_dispatch<type, 1 << 25>(a);\n\
    }\n}  // namespace bitwise\n#line 4 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate\
    \ <typename T, int LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\
    \n  int n = topbit(len(f));\r\n  assert(n <= LIM);\r\n  assert(len(f) == 1 <<\
    \ n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\n  for (int s = 0; s < (1 << n);\
    \ ++s) Rf[s][popcnt(s)] = f[s];\r\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_zeta>(Rf);\r\
    \n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T,\
    \ LIM + 1>>& Rf) {\r\n  bitwise::bitwise_transform<bitwise::trans_type::ranked_mobius>(Rf);\r\
    \n  vc<T> f(len(Rf));\r\n  for (int s = 0; s < len(f); ++s) f[s] = Rf[s][popcnt(s)];\r\
    \n  return f;\r\n}\n#line 4 \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename\
    \ T, int LIM = 20>\r\nvc<T> subset_convolution_square(const vc<T>& A) {\r\n  auto\
    \ RA = ranked_zeta<T, LIM>(A);\r\n  int n = topbit(len(RA));\r\n  FOR(s, len(RA))\
    \ {\r\n    auto& f = RA[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n   \
    \   FOR(i, d + 1) x += f[i] * f[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n\
    \  return ranked_mobius<T, LIM>(RA);\r\n}\r\n\r\ntemplate <typename T, int LIM\
    \ = 20>\r\nvc<T> subset_convolution(const vc<T>& A, const vc<T>& B) {\r\n  if\
    \ (A == B) return subset_convolution_square(A);\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\n  int n = topbit(len(RA));\r\
    \n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], &g = RB[s];\r\n    FOR_R(d, n +\
    \ 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x += f[i] * g[d - i];\r\n    \
    \  f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n#line\
    \ 4 \"setfunc/sps_exp.hpp\"\n\n// sum_i 1/i! s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_exp(vc<mint>& s) {\n  const int\
    \ N = topbit(len(s));\n  assert(len(s) == (1 << N) && s[0] == mint(0));\n  vc<mint>\
    \ dp(1 << N);\n  dp[0] = mint(1);\n  FOR(i, N) {\n    vc<mint> a = {s.begin()\
    \ + (1 << i), s.begin() + (2 << i)};\n    vc<mint> b = {dp.begin(), dp.begin()\
    \ + (1 << i)};\n    a = subset_convolution<mint, LIM>(a, b);\n    copy(all(a),\
    \ dp.begin() + (1 << i));\n  }\n  return dp;\n}\n#line 3 \"setfunc/sps_composition.hpp\"\
    \n\n// sum_i f_i/i! s^i, s^i is subset-convolution\ntemplate <typename mint, int\
    \ LIM>\nvc<mint> sps_composition_egf(vc<mint>& f, vc<mint>& s) {\n  const int\
    \ N = topbit(len(s));\n  assert(len(s) == (1 << N) && s[0] == mint(0));\n  if\
    \ (len(f) > N) f.resize(N + 1);\n  int D = len(f) - 1;\n  using ARR = array<mint,\
    \ LIM + 1>;\n  vvc<ARR> zs(N);\n  FOR(i, N) { zs[i] = ranked_zeta<mint, LIM>({s.begin()\
    \ + (1 << i), s.begin() + (2 << i)}); }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n\
    \  vc<mint> dp(1 << (N - D));\n  dp[0] = f[D];\n  FOR_R(d, D) {\n    vc<mint>\
    \ newdp(1 << (N - d));\n    newdp[0] = f[d];\n    vc<ARR> zdp = ranked_zeta<mint,\
    \ LIM>(dp);\n    FOR(i, N - d) {\n      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR>\
    \ znewdp(1 << i);\n      FOR(k, 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p\
    \ + 1) { znewdp[k][p + q] += zdp[k][p] * zs[i][k][q]; }\n      }\n      auto x\
    \ = ranked_mobius<mint, LIM>(znewdp);\n      copy(all(x), newdp.begin() + (1 <<\
    \ i));\n    }\n    swap(dp, newdp);\n  }\n  return dp;\n}\n\n// sum_i f_i s^i,\
    \ s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint> sps_composition_poly(vc<mint>\
    \ f, vc<mint> s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 <<\
    \ N));\n  if (f.empty()) return vc<mint>(1 << N, mint(0));\n  // convert to egf\
    \ problem\n  int D = min<int>(len(f) - 1, N);\n  vc<mint> g(D + 1);\n  mint c\
    \ = s[0];\n  s[0] = 0;\n  // (x+c)^i\n  vc<mint> pow(D + 1);\n  pow[0] = 1;\n\
    \  FOR(i, len(f)) {\n    FOR(j, D + 1) g[j] += f[i] * pow[j];\n    FOR_R(j, D\
    \ + 1) pow[j] = pow[j] * c + (j == 0 ? mint(0) : pow[j - 1]);\n  }\n  // to egf\n\
    \  mint factorial = 1;\n  FOR(j, D + 1) g[j] *= factorial, factorial *= mint(j\
    \ + 1);\n  return sps_composition_egf<mint, LIM>(g, s);\n}\n#line 4 \"graph/tutte_polynomial.hpp\"\
    \n\ntemplate <typename mint, int NMAX>\nmint Tutte_Polynomial_Eval_connected(Graph<int,\
    \ 0> G, mint X, mint Y) {\n  int N = G.N;\n  X -= 1, Y -= 1;\n  /*\n  V \u306E\
    \u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u8003\u3048\u308B\u3068,\n  \u5404\u90E8\
    \u5206\u96C6\u5408\u306B S \u306B\u5BFE\u3057\u3066, S \u3092 span \u3059\u308B\
    \ A \u306E\u9078\u3073\u65B9\u306B\u5BFE\u3059\u308B y^{cycle} \u306E sum \u3092\
    \ F[S] \u3068\u3057\u3066\n  c[n]F^n/n!, c[n] = X^{n-k(E)} \u3068\u3057\u3066\
    \ EGF composition \u3067\u3067\u304D\u308B.\n\n  F[S] \u306E\u8A08\u7B97\n  1\
    \ \u70B9\u305A\u3064\u8DB3\u3057\u3066\u3044\u304F\n  \u96C6\u5408\u306B\u8FBA\
    \u306E\u500B\u6570\u306B\u5FDC\u3058\u305F\u91CD\u307F\u3092\u3064\u3051\u3066\
    \ exp\n  \u91CD\u307F C(N,1) + C(N,2)Y + C(N,3)YY+...\n  */\n\n  vv(mint, bin,\
    \ N + 1, N + 1);\n  bin[0][0] = 1;\n  FOR(i, N) FOR(j, i + 1) bin[i + 1][j] +=\
    \ bin[i][j], bin[i + 1][j + 1] += bin[i][j];\n  vc<mint> wt(N + 1);\n  FOR(n,\
    \ 1, N + 1) {\n    mint pow = 1;\n    FOR(m, 1, n + 1) { wt[n] += bin[n][m] *\
    \ pow, pow *= Y; }\n  }\n  vc<mint> F(1 << N);\n  FOR(v, N) {\n    u32 nbd = 0;\n\
    \    for (auto& e: G[v]) nbd |= 1 << e.to;\n    vc<mint> f(1 << v);\n    FOR(s,\
    \ 1 << v) { f[s] = F[s] * wt[popcnt(s & nbd)]; }\n    f = sps_exp<mint, NMAX>(f);\n\
    \    FOR(s, 1 << v) { F[s | 1 << v] = f[s]; }\n  }\n  if (X == mint(0)) { return\
    \ F.back(); }\n\n  // X \u3067\u5272\u308C\u306A\u3044\u3068\u304D\u306F\u3053\
    \u3046\u3059\u308C\u3070\u52D5\u304F. \u4F55\u3082\u304B\u3082\u304C\u74B0\u3067\
    \u52D5\u4F5C\u3059\u308B.\n  // vc<mint> c(N + 1);\n  // mint pow = 1;\n  // FOR(n,\
    \ 1, N + 1) { c[n] = pow, pow *= X; }\n  // F = sps_composition_egf<mint, NMAX>(c,\
    \ F);\n  // return F.back();\n  FOR(s, 1 << N) F[s] *= X;\n  F = sps_exp<mint,\
    \ NMAX>(F);\n  return F.back() * X.inverse();\n}\n\n// QOJ 45\ntemplate <typename\
    \ mint, int NMAX>\nmint Tutte_Polynomial_Eval(Graph<int, 0> G, mint X, mint Y)\
    \ {\n  int N = G.N;\n  UnionFind uf(N);\n  for (auto& e: G.edges) uf.merge(e.frm,\
    \ e.to);\n  vvc<int> vs(N);\n  FOR(v, N) vs[uf[v]].eb(v);\n  mint ANS = 1;\n \
    \ for (auto& V: vs) {\n    if (V.empty()) continue;\n    Graph<int, 0> H = G.rearrange(V);\n\
    \    ANS *= Tutte_Polynomial_Eval_connected<mint, NMAX>(H, X, Y);\n  }\n  return\
    \ ANS;\n}\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n#include \"setfunc/sps_exp.hpp\"\
    \n#include \"setfunc/sps_composition.hpp\"\n\ntemplate <typename mint, int NMAX>\n\
    mint Tutte_Polynomial_Eval_connected(Graph<int, 0> G, mint X, mint Y) {\n  int\
    \ N = G.N;\n  X -= 1, Y -= 1;\n  /*\n  V \u306E\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u3092\u8003\u3048\u308B\u3068,\n  \u5404\u90E8\u5206\u96C6\u5408\u306B S \u306B\
    \u5BFE\u3057\u3066, S \u3092 span \u3059\u308B A \u306E\u9078\u3073\u65B9\u306B\
    \u5BFE\u3059\u308B y^{cycle} \u306E sum \u3092 F[S] \u3068\u3057\u3066\n  c[n]F^n/n!,\
    \ c[n] = X^{n-k(E)} \u3068\u3057\u3066 EGF composition \u3067\u3067\u304D\u308B\
    .\n\n  F[S] \u306E\u8A08\u7B97\n  1 \u70B9\u305A\u3064\u8DB3\u3057\u3066\u3044\
    \u304F\n  \u96C6\u5408\u306B\u8FBA\u306E\u500B\u6570\u306B\u5FDC\u3058\u305F\u91CD\
    \u307F\u3092\u3064\u3051\u3066 exp\n  \u91CD\u307F C(N,1) + C(N,2)Y + C(N,3)YY+...\n\
    \  */\n\n  vv(mint, bin, N + 1, N + 1);\n  bin[0][0] = 1;\n  FOR(i, N) FOR(j,\
    \ i + 1) bin[i + 1][j] += bin[i][j], bin[i + 1][j + 1] += bin[i][j];\n  vc<mint>\
    \ wt(N + 1);\n  FOR(n, 1, N + 1) {\n    mint pow = 1;\n    FOR(m, 1, n + 1) {\
    \ wt[n] += bin[n][m] * pow, pow *= Y; }\n  }\n  vc<mint> F(1 << N);\n  FOR(v,\
    \ N) {\n    u32 nbd = 0;\n    for (auto& e: G[v]) nbd |= 1 << e.to;\n    vc<mint>\
    \ f(1 << v);\n    FOR(s, 1 << v) { f[s] = F[s] * wt[popcnt(s & nbd)]; }\n    f\
    \ = sps_exp<mint, NMAX>(f);\n    FOR(s, 1 << v) { F[s | 1 << v] = f[s]; }\n  }\n\
    \  if (X == mint(0)) { return F.back(); }\n\n  // X \u3067\u5272\u308C\u306A\u3044\
    \u3068\u304D\u306F\u3053\u3046\u3059\u308C\u3070\u52D5\u304F. \u4F55\u3082\u304B\
    \u3082\u304C\u74B0\u3067\u52D5\u4F5C\u3059\u308B.\n  // vc<mint> c(N + 1);\n \
    \ // mint pow = 1;\n  // FOR(n, 1, N + 1) { c[n] = pow, pow *= X; }\n  // F =\
    \ sps_composition_egf<mint, NMAX>(c, F);\n  // return F.back();\n  FOR(s, 1 <<\
    \ N) F[s] *= X;\n  F = sps_exp<mint, NMAX>(F);\n  return F.back() * X.inverse();\n\
    }\n\n// QOJ 45\ntemplate <typename mint, int NMAX>\nmint Tutte_Polynomial_Eval(Graph<int,\
    \ 0> G, mint X, mint Y) {\n  int N = G.N;\n  UnionFind uf(N);\n  for (auto& e:\
    \ G.edges) uf.merge(e.frm, e.to);\n  vvc<int> vs(N);\n  FOR(v, N) vs[uf[v]].eb(v);\n\
    \  mint ANS = 1;\n  for (auto& V: vs) {\n    if (V.empty()) continue;\n    Graph<int,\
    \ 0> H = G.rearrange(V);\n    ANS *= Tutte_Polynomial_Eval_connected<mint, NMAX>(H,\
    \ X, Y);\n  }\n  return ANS;\n}\n"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  - setfunc/sps_exp.hpp
  - setfunc/subset_convolution.hpp
  - other/bit.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/bitwise_transform.hpp
  - setfunc/sps_composition.hpp
  isVerificationFile: false
  path: graph/tutte_polynomial.hpp
  requiredBy: []
  timestamp: '2026-07-26 21:01:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tutte_polynomial.hpp
layout: document
redirect_from:
- /library/graph/tutte_polynomial.hpp
- /library/graph/tutte_polynomial.hpp.html
title: graph/tutte_polynomial.hpp
---
