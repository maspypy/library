---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/centroid.hpp
    title: graph/centroid.hpp
  - icon: ':question:'
    path: mod/factorial.hpp
    title: mod/factorial.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to &&\
    \ to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int v\
    \ = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n    }\n\
    \    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared =\
    \ true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/centroid.hpp\"\
    \n\r\ntemplate <typename GT>\r\npair<int, int> find_centroids(GT& G) {\r\n  int\
    \ N = G.N;\r\n  vc<int> par(N, -1);\r\n  vc<int> V(N);\r\n  vc<int> sz(N);\r\n\
    \  int l = 0, r = 0;\r\n  V[r++] = 0;\r\n  while (l < r) {\r\n    int v = V[l++];\r\
    \n    for (auto&& e: G[v])\r\n      if (e.to != par[v]) {\r\n        par[e.to]\
    \ = v;\r\n        V[r++] = e.to;\r\n      }\r\n  }\r\n  FOR_R(i, N) {\r\n    int\
    \ v = V[i];\r\n    sz[v] += 1;\r\n    int p = par[v];\r\n    if (p != -1) sz[p]\
    \ += sz[v];\r\n  }\r\n\r\n  int M = N / 2;\r\n  auto check = [&](int v) -> bool\
    \ {\r\n    if (N - sz[v] > M) return false;\r\n    for (auto&& e: G[v]) {\r\n\
    \      if (e.to != par[v] && sz[e.to] > M) return false;\r\n    }\r\n    return\
    \ true;\r\n  };\r\n  pair<int, int> ANS = {-1, -1};\r\n  FOR(v, N) if (check(v))\
    \ {\r\n    if (ANS.fi != -1) {\r\n      ANS.se = v;\r\n    } else {\r\n      ANS.fi\
    \ = v;\r\n    }\r\n  }\r\n  return ANS;\r\n}\r\n\r\ntemplate <typename GT>\r\n\
    struct Centroid_Decomposition {\r\n  using edge_type = typename GT::edge_type;\r\
    \n  GT& G;\r\n  int N;\r\n  vc<int> sz;\r\n  vc<int> par;\r\n  vector<int> cdep;\
    \ // depth in centroid tree\r\n  bool calculated;\r\n\r\n  Centroid_Decomposition(GT&\
    \ G)\r\n      : G(G), N(G.N), sz(G.N), par(G.N), cdep(G.N, -1) {\r\n    calculated\
    \ = 0;\r\n    build();\r\n  }\r\n\r\nprivate:\r\n  int find(int v) {\r\n    vc<int>\
    \ V = {v};\r\n    par[v] = -1;\r\n    int p = 0;\r\n    while (p < len(V)) {\r\
    \n      int v = V[p++];\r\n      sz[v] = 0;\r\n      for (auto&& e: G[v]) {\r\n\
    \        if (e.to == par[v] || cdep[e.to] != -1) continue;\r\n        par[e.to]\
    \ = v;\r\n        V.eb(e.to);\r\n      }\r\n    }\r\n    while (len(V)) {\r\n\
    \      int v = V.back();\r\n      V.pop_back();\r\n      sz[v] += 1;\r\n     \
    \ if (p - sz[v] <= p / 2) return v;\r\n      sz[par[v]] += sz[v];\r\n    }\r\n\
    \    return -1;\r\n  }\r\n  void build() {\r\n    assert(G.is_prepared());\r\n\
    \    assert(!G.is_directed());\r\n    assert(!calculated);\r\n    calculated =\
    \ 1;\r\n\r\n    vc<pair<int, int>> st;\r\n    st.eb(0, 0);\r\n    while (!st.empty())\
    \ {\r\n      auto [lv, v] = st.back();\r\n      st.pop_back();\r\n      auto c\
    \ = find(v);\r\n      cdep[c] = lv;\r\n      for (auto&& e: G[c]) {\r\n      \
    \  if (cdep[e.to] == -1) { st.eb(lv + 1, e.to); }\r\n      }\r\n    }\r\n  }\r\
    \n\r\npublic:\r\n  /*\r\n  root \u3092\u91CD\u5FC3\u3068\u3059\u308B\u6728\u306B\
    \u304A\u3044\u3066\u3001(v, path data v) \u306E vector\r\n  \u3092\u3001\u65B9\
    \u5411\u3054\u3068\u306B\u96C6\u3081\u3066\u8FD4\u3059 \u30FB0 \u756A\u76EE\uFF1A\
    root \u304B\u3089\u306E\u30D1\u30B9\u3059\u3079\u3066\uFF08root \u3092\u542B\u3080\
    \uFF09\r\n  \u30FBi\u756A\u76EE\uFF1Ai \u756A\u76EE\u306E\u65B9\u5411\r\n  f:\
    \ E x edge -> E\r\n  */\r\n  template <typename E, typename F>\r\n  vc<vc<pair<int,\
    \ E>>> collect(int root, E root_val, F f) {\r\n    vc<vc<pair<int, E>>> res =\
    \ {{{root, root_val}}};\r\n    for (auto&& e: G[root]) {\r\n      int nxt = e.to;\r\
    \n      if (cdep[nxt] < cdep[root]) continue;\r\n      vc<pair<int, E>> dat;\r\
    \n      int p = 0;\r\n      dat.eb(nxt, f(root_val, e));\r\n      par[nxt] = root;\r\
    \n      while (p < len(dat)) {\r\n        auto [v, val] = dat[p++];\r\n      \
    \  for (auto&& e: G[v]) {\r\n          if (e.to == par[v]) continue;\r\n     \
    \     if (cdep[e.to] < cdep[root]) continue;\r\n          par[e.to] = v;\r\n \
    \         dat.eb(e.to, f(val, e));\r\n        }\r\n      }\r\n      res.eb(dat);\r\
    \n      res[0].insert(res[0].end(), all(dat));\r\n    }\r\n    return res;\r\n\
    \  }\r\n\r\n  vc<vc<pair<int, int>>> collect_dist(int root) {\r\n    auto f =\
    \ [&](int x, auto e) -> int { return x + 1; };\r\n    return collect(root, 0,\
    \ f);\r\n  }\r\n\r\n  // (V, H), V[i] \u306F\u3001H \u306B\u304A\u3051\u308B\u9802\
    \u70B9 i \u306E G \u306B\u304A\u3051\u308B\u756A\u53F7\r\n  // \u9802\u70B9\u306F\
    \ EulerTour \u9806\u306B\u4E26\u3076\u3001V \u306F sort \u3055\u308C\u3066\u3044\
    \u308B\u3068\u306F\u9650\u3089\u306A\u3044\r\n  pair<vc<int>, Graph<typename GT::cost_type,\
    \ true>> get_subgraph(int root) {\r\n    static vc<int> conv;\r\n    while (len(conv)\
    \ < N) conv.eb(-1);\r\n\r\n    vc<int> V;\r\n    using cost_type = typename GT::cost_type;\r\
    \n    vc<tuple<int, int, cost_type>> edges;\r\n\r\n    auto dfs = [&](auto& dfs,\
    \ int v, int p) -> void {\r\n      conv[v] = len(V);\r\n      V.eb(v);\r\n   \
    \   for (auto&& e: G[v]) {\r\n        int to = e.to;\r\n        if (to == p) continue;\r\
    \n        if (cdep[to] < cdep[root]) continue;\r\n        dfs(dfs, to, v);\r\n\
    \        edges.eb(conv[v], conv[to], e.cost);\r\n      }\r\n    };\r\n    dfs(dfs,\
    \ root, -1);\r\n    int n = len(V);\r\n    Graph<typename GT::cost_type, true>\
    \ H(n);\r\n    for (auto&& [a, b, c]: edges) H.add(a, b, c);\r\n    H.build();\r\
    \n    for (auto&& v: V) conv[v] = -1;\r\n    return {V, H};\r\n  }\r\n};\r\n#line\
    \ 1 \"mod/factorial.hpp\"\n\ntemplate <typename mint>\nmint inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0\
    \ <= n);\n  if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  assert(-1 <=\
    \ n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (n == -1) return mint(0);\n\
    \  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return\
    \ dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n\
    \  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint,\
    \ class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n\
    \  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\
    \ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint> C;\n\
    \  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if\
    \ (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ?\
    \ C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k\
    \ + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k +\
    \ 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n   \
    \   C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H =\
    \ n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool large = false,\
    \ bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 ||\
    \ n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n  if (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\n\
    struct modint {\n  int val;\n  constexpr modint(const ll val = 0) noexcept\n \
    \     : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -=\
    \ mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if\
    \ ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n};\n\nstruct ArbitraryModInt {\n  static\
    \ constexpr bool is_modint = true;\n  int val;\n  ArbitraryModInt() : val(0) {}\n\
    \  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n          \
    \         : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ ArbitraryModInt &other) const {\n    return val < other.val;\n  } // To use\
    \ std::map<ArbitraryModInt, T>\n  static int &get_mod() {\n    static int mod\
    \ = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod() = md;\
    \ }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val +=\
    \ p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((val += get_mod() - p.val)\
    \ >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    long long a = (long long)val * p.val;\n    int xh\
    \ = (int)(a >> 32), xl = (int)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d),\
    \ \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n   \
    \ *this *= p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-()\
    \ const { return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    assert(n >= 0);\n    ArbitraryModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ pair<int, int> ntt_info() { return {-1, -1}; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\nusing amint = ArbitraryModInt;\n\nstruct\
    \ has_mod_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\r\n\
    ll mod_inv(ll val, ll mod) {\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\n\
    \  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\
    \n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\
    \n  return u;\r\n}\r\n#line 1 \"poly/convolution_naive.hpp\"\ntemplate <class\
    \ T>\r\nvector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {\r\
    \n  int n = int(a.size()), m = int(b.size());\r\n  vector<T> ans(n + m - 1);\r\
    \n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\n  }\
    \ else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  }\r\n  return\
    \ ans;\r\n}\r\n#line 2 \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>&\
    \ a, bool inverse) {\r\n  static constexpr int rank2 = mint::ntt_info().fi;\r\n\
    \  static constexpr int mod = mint::get_mod();\r\n  static_assert(rank2 != -1);\r\
    \n  static array<mint, rank2 + 1> root;\r\n  static array<mint, rank2 + 1> iroot;\r\
    \n  static array<mint, max(0, rank2 - 1)> rate2, irate2;\r\n  static array<mint,\
    \ max(0, rank2 - 2)> rate3, irate3;\r\n  static bool prepared = 0;\r\n  if (!prepared)\
    \ {\r\n    prepared = 1;\r\n    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2]\
    \ = mint(1) / root[rank2];\r\n    FOR_R(i, rank2) {\r\n      root[i] = root[i\
    \ + 1] * root[i + 1];\r\n      iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n   \
    \ }\r\n    mint prod = 1, iprod = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++)\
    \ {\r\n      rate2[i] = root[i + 2] * prod;\r\n      irate2[i] = iroot[i + 2]\
    \ * iprod;\r\n      prod *= iroot[i + 2];\r\n      iprod *= root[i + 2];\r\n \
    \   }\r\n    prod = 1, iprod = 1;\r\n    for (int i = 0; i <= rank2 - 3; i++)\
    \ {\r\n      rate3[i] = root[i + 3] * prod;\r\n      irate3[i] = iroot[i + 3]\
    \ * iprod;\r\n      prod *= iroot[i + 3];\r\n      iprod *= root[i + 3];\r\n \
    \   }\r\n  }\r\n\r\n  int n = int(a.size());\r\n  int h = topbit(n);\r\n  assert(n\
    \ == 1 << h);\r\n  if (!inverse) {\r\n    int len = 0;\r\n    while (len < h)\
    \ {\r\n      if (h - len == 1) {\r\n        int p = 1 << (h - len - 1);\r\n  \
    \      mint rot = 1;\r\n        FOR(s, 1 << len) {\r\n          int offset = s\
    \ << (h - len);\r\n          FOR(i, p) {\r\n            auto l = a[i + offset];\r\
    \n            auto r = a[i + offset + p] * rot;\r\n            a[i + offset] =\
    \ l + r;\r\n            a[i + offset + p] = l - r;\r\n          }\r\n        \
    \  rot *= rate2[topbit(~s & -~s)];\r\n        }\r\n        len++;\r\n      } else\
    \ {\r\n        int p = 1 << (h - len - 2);\r\n        mint rot = 1, imag = root[2];\r\
    \n        for (int s = 0; s < (1 << len); s++) {\r\n          mint rot2 = rot\
    \ * rot;\r\n          mint rot3 = rot2 * rot;\r\n          int offset = s << (h\
    \ - len);\r\n          for (int i = 0; i < p; i++) {\r\n            u64 mod2 =\
    \ u64(mod) * mod;\r\n            u64 a0 = a[i + offset].val;\r\n            u64\
    \ a1 = u64(a[i + offset + p].val) * rot.val;\r\n            u64 a2 = u64(a[i +\
    \ offset + 2 * p].val) * rot2.val;\r\n            u64 a3 = u64(a[i + offset +\
    \ 3 * p].val) * rot3.val;\r\n            u64 a1na3imag = (a1 + mod2 - a3) % mod\
    \ * imag.val;\r\n            u64 na2 = mod2 - a2;\r\n            a[i + offset]\
    \ = a0 + a2 + a1 + a3;\r\n            a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\r\n            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n            a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\r\n     \
    \     }\r\n          rot *= rate3[topbit(~s & -~s)];\r\n        }\r\n        len\
    \ += 2;\r\n      }\r\n    }\r\n  } else {\r\n    mint coef = mint(1) / mint(len(a));\r\
    \n    FOR(i, len(a)) a[i] *= coef;\r\n    int len = h;\r\n    while (len) {\r\n\
    \      if (len == 1) {\r\n        int p = 1 << (h - len);\r\n        mint irot\
    \ = 1;\r\n        FOR(s, 1 << (len - 1)) {\r\n          int offset = s << (h -\
    \ len + 1);\r\n          FOR(i, p) {\r\n            u64 l = a[i + offset].val;\r\
    \n            u64 r = a[i + offset + p].val;\r\n            a[i + offset] = l\
    \ + r;\r\n            a[i + offset + p] = (mod + l - r) * irot.val;\r\n      \
    \    }\r\n          irot *= irate2[topbit(~s & -~s)];\r\n        }\r\n       \
    \ len--;\r\n      } else {\r\n        int p = 1 << (h - len);\r\n        mint\
    \ irot = 1, iimag = iroot[2];\r\n        FOR(s, (1 << (len - 2))) {\r\n      \
    \    mint irot2 = irot * irot;\r\n          mint irot3 = irot2 * irot;\r\n   \
    \       int offset = s << (h - len + 2);\r\n          for (int i = 0; i < p; i++)\
    \ {\r\n            u64 a0 = a[i + offset + 0 * p].val;\r\n            u64 a1 =\
    \ a[i + offset + 1 * p].val;\r\n            u64 a2 = a[i + offset + 2 * p].val;\r\
    \n            u64 a3 = a[i + offset + 3 * p].val;\r\n            u64 x = (mod\
    \ + a2 - a3) * iimag.val % mod;\r\n            a[i + offset] = a0 + a1 + a2 +\
    \ a3;\r\n            a[i + offset + 1 * p] = (a0 + mod - a1 + x) * irot.val;\r\
    \n            a[i + offset + 2 * p] = (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\
    \n            a[i + offset + 3 * p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n\
    \          }\r\n          irot *= irate3[topbit(~s & -~s)];\r\n        }\r\n \
    \       len -= 2;\r\n      }\r\n    }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\n\
    namespace CFFT {\r\nusing real = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\
    \r\n  C() : x(0), y(0) {}\r\n\r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline\
    \ C operator+(const C& c) const { return C(x + c.x, y + c.y); }\r\n  inline C\
    \ operator-(const C& c) const { return C(x - c.x, y - c.y); }\r\n  inline C operator*(const\
    \ C& c) const {\r\n    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\
    \n\r\n  inline C conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI\
    \ = acosl(-1);\r\nint base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int>\
    \ rev = {0, 1};\r\n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\
    \n  rev.resize(1 << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0;\
    \ i < (1 << nbase); i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase\
    \ - 1));\r\n  }\r\n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1\
    \ << (base + 1));\r\n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\
    \n      rts[i << 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1\
    \ << base));\r\n      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n \
    \   }\r\n    ++base;\r\n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n\
    \ & (n - 1)) == 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\
    \n  int shift = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i\
    \ < (rev[i] >> shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int\
    \ k = 1; k < n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n   \
    \   for (int j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\
    \n        a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n\
    \      }\r\n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 7 \"poly/convolution.hpp\"\
    \n\r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  int sz = 1;\r\n  while\
    \ (sz < n + m - 1) sz *= 2;\r\n\r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\
    \u901F\u5316\u3002\u5206\u5272\u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\
    \u3057\u307E\u304F\u308B\u306E\u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\
    \n    auto a_last = a.back(), b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\
    \n    auto c = convolution(a, b);\r\n    c.resize(n + m - 1);\r\n    c[n + m -\
    \ 2] = a_last * b_last;\r\n    FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\
    \n    FOR(i, len(b)) c[i + len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\
    \n\r\n  a.resize(sz), b.resize(sz);\r\n  bool same = a == b;\r\n  ntt(a, 0);\r\
    \n  if (same) {\r\n    b = a;\r\n  } else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i,\
    \ sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\n  a.resize(n + m - 1);\r\n  return a;\r\
    \n}\r\n\r\ntemplate <typename mint>\r\nvector<mint> convolution_garner(const vector<mint>&\
    \ a, const vector<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n ||\
    \ !m) return {};\r\n  static const long long nttprimes[] = {754974721, 167772161,\
    \ 469762049};\r\n  using mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\
    \n  using mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1>\
    \ a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val,\
    \ a1[i] = a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] =\
    \ b[i].val, b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\
    \n  auto c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  static const\
    \ int mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2\
    \ x2) -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
    \ - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\r\n    return mint(r0\
    \ + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val);\r\n  };\r\n  vc<mint> c(len(c0));\r\
    \n  FOR(i, len(c)) c[i] = garner(c0[i], c1[i], c2[i]);\r\n  return c;\r\n}\r\n\
    \r\ntemplate <typename R>\r\nvc<double> convolution_fft(const vc<R>& a, const\
    \ vc<R>& b) {\r\n  using C = CFFT::C;\r\n  int need = (int)a.size() + (int)b.size()\
    \ - 1;\r\n  int nbase = 1;\r\n  while ((1 << nbase) < need) nbase++;\r\n  CFFT::ensure_base(nbase);\r\
    \n  int sz = 1 << nbase;\r\n  vector<C> fa(sz);\r\n  for (int i = 0; i < sz; i++)\
    \ {\r\n    int x = (i < (int)a.size() ? a[i] : 0);\r\n    int y = (i < (int)b.size()\
    \ ? b[i] : 0);\r\n    fa[i] = C(x, y);\r\n  }\r\n  CFFT::fft(fa, sz);\r\n  C r(0,\
    \ -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\r\n  for (int i = 0; i <= (sz >> 1);\
    \ i++) {\r\n    int j = (sz - i) & (sz - 1);\r\n    C z = (fa[j] * fa[j] - (fa[i]\
    \ * fa[i]).conj()) * r;\r\n    fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj())\
    \ * r;\r\n    fa[i] = z;\r\n  }\r\n  for (int i = 0; i < (sz >> 1); i++) {\r\n\
    \    C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;\r\n    C A1 = (fa[i] - fa[i + (sz\
    \ >> 1)]) * t * CFFT::rts[(sz >> 1) + i];\r\n    fa[i] = A0 + A1 * s;\r\n  }\r\
    \n  CFFT::fft(fa, sz >> 1);\r\n  vector<double> ret(need);\r\n  for (int i = 0;\
    \ i < need; i++) {\r\n    ret[i] = (i & 1 ? fa[i >> 1].y : fa[i >> 1].x);\r\n\
    \  }\r\n  return ret;\r\n}\r\n\r\nvector<ll> convolution(const vector<ll>& a,\
    \ const vector<ll>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return\
    \ {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, n) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
    \n  if (i128(abs_sum_a) * abs_sum_b < 1e15) {\r\n    vc<double> c = convolution_fft<ll>(a,\
    \ b);\r\n    vc<ll> res(len(c));\r\n    FOR(i, len(c)) res[i] = ll(floor(c[i]\
    \ + .5));\r\n    return res;\r\n  }\r\n\r\n  static constexpr unsigned long long\
    \ MOD1 = 754974721; // 2^24\r\n  static constexpr unsigned long long MOD2 = 167772161;\
    \ // 2^25\r\n  static constexpr unsigned long long MOD3 = 469762049; // 2^26\r\
    \n  static constexpr unsigned long long M2M3 = MOD2 * MOD3;\r\n  static constexpr\
    \ unsigned long long M1M3 = MOD1 * MOD3;\r\n  static constexpr unsigned long long\
    \ M1M2 = MOD1 * MOD2;\r\n  static constexpr unsigned long long M1M2M3 = MOD1 *\
    \ MOD2 * MOD3;\r\n\r\n  static const unsigned long long i1 = mod_inv(MOD2 * MOD3,\
    \ MOD1);\r\n  static const unsigned long long i2 = mod_inv(MOD1 * MOD3, MOD2);\r\
    \n  static const unsigned long long i3 = mod_inv(MOD1 * MOD2, MOD3);\r\n\r\n \
    \ using mint1 = modint<MOD1>;\r\n  using mint2 = modint<MOD2>;\r\n  using mint3\
    \ = modint<MOD3>;\r\n\r\n  vc<mint1> a1(n), b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\
    \n  vc<mint3> a3(n), b3(m);\r\n  FOR(i, n) a1[i] = a[i], a2[i] = a[i], a3[i] =\
    \ a[i];\r\n  FOR(i, m) b1[i] = b[i], b2[i] = b[i], b3[i] = b[i];\r\n\r\n  auto\
    \ c1 = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  auto c3 = convolution_ntt<mint3>(a3, b3);\r\n\r\n  vc<ll> c(n + m\
    \ - 1);\r\n  FOR(i, n + m - 1) {\r\n    u64 x = 0;\r\n    x += (c1[i].val * i1)\
    \ % MOD1 * M2M3;\r\n    x += (c2[i].val * i2) % MOD2 * M1M3;\r\n    x += (c3[i].val\
    \ * i3) % MOD3 * M1M2;\r\n    ll diff = c1[i].val - ((long long)(x) % (long long)(MOD1));\r\
    \n    if (diff < 0) diff += MOD1;\r\n    static constexpr unsigned long long offset[5]\r\
    \n        = {0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\r\n    x -= offset[diff %\
    \ 5];\r\n    c[i] = x;\r\n  }\r\n  return c;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nenable_if_t<is_same<mint, modint998>::value, vc<mint>> convolution(\r\n    const\
    \ vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n\
    \ || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a, b);\r\
    \n  return convolution_ntt(a, b);\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> convolution(\r\n    const vc<mint>& a, const vc<mint>&\
    \ b) {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  if\
    \ (min(n, m) <= 60) return convolution_naive(a, b);\r\n  return convolution_garner(a,\
    \ b);\r\n}\r\n#line 3 \"graph/tree_all_distances.hpp\"\n\r\n// frequency table\
    \ of distance of all directed pairs.\r\n// sum of result array = N^2\r\ntemplate\
    \ <typename Graph>\r\nvi tree_all_distances(Graph& G) {\r\n  assert(G.is_prepared());\r\
    \n  assert(!G.is_directed());\r\n  Centroid_Decomposition CD(G);\r\n\r\n  ll N\
    \ = G.N;\r\n  vi ANS(N);\r\n  FOR(root, N) {\r\n    auto data = CD.collect_dist(root);\r\
    \n    FOR(i, len(data)) {\r\n      int n = 0;\r\n      FOR(j, len(data[i])) chmax(n,\
    \ data[i][j].se + 1);\r\n      vi A(n);\r\n      FOR(j, len(data[i])) A[data[i][j].se]++;\r\
    \n      auto B = convolution(A, A);\r\n      FOR(j, min(N, len(B))) ANS[j] +=\
    \ (i == 0 ? B[j] : -B[j]);\r\n    }\r\n  }\r\n  return ANS;\r\n}\n"
  code: "#include \"graph/centroid.hpp\"\r\n#include \"poly/convolution.hpp\"\r\n\r\
    \n// frequency table of distance of all directed pairs.\r\n// sum of result array\
    \ = N^2\r\ntemplate <typename Graph>\r\nvi tree_all_distances(Graph& G) {\r\n\
    \  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\n  Centroid_Decomposition\
    \ CD(G);\r\n\r\n  ll N = G.N;\r\n  vi ANS(N);\r\n  FOR(root, N) {\r\n    auto\
    \ data = CD.collect_dist(root);\r\n    FOR(i, len(data)) {\r\n      int n = 0;\r\
    \n      FOR(j, len(data[i])) chmax(n, data[i][j].se + 1);\r\n      vi A(n);\r\n\
    \      FOR(j, len(data[i])) A[data[i][j].se]++;\r\n      auto B = convolution(A,\
    \ A);\r\n      FOR(j, min(N, len(B))) ANS[j] += (i == 0 ? B[j] : -B[j]);\r\n \
    \   }\r\n  }\r\n  return ANS;\r\n}"
  dependsOn:
  - graph/centroid.hpp
  - graph/base.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/factorial.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: graph/tree_all_distances.hpp
  requiredBy: []
  timestamp: '2023-02-28 19:13:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/tree/frequency_table_of_tree_distance.test.cpp
documentation_of: graph/tree_all_distances.hpp
layout: document
redirect_from:
- /library/graph/tree_all_distances.hpp
- /library/graph/tree_all_distances.hpp.html
title: graph/tree_all_distances.hpp
---
