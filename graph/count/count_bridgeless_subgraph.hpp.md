---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':warning:'
    path: graph/count/count_connected_subgraph.hpp
    title: graph/count/count_connected_subgraph.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  - icon: ':x:'
    path: setfunc/sps_composition.hpp
    title: setfunc/sps_composition.hpp
  - icon: ':x:'
    path: setfunc/sps_exp.hpp
    title: setfunc/sps_exp.hpp
  - icon: ':warning:'
    path: setfunc/sps_log.hpp
    title: setfunc/sps_log.hpp
  - icon: ':x:'
    path: setfunc/subset_convolution.hpp
    title: setfunc/subset_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://loj.ac/p/6730.
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\
    \u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\
    \u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n   \
    \ used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size()\
    \ { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int\
    \ i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask)\
    \ {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if\
    \ (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  static constexpr\
    \ bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n    print(\"Graph\");\n    if\
    \ (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
    \ T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
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
    \  if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr int get_mod()\
    \ { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr\
    \ pair<int, int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n\
    \    if (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return\
    \ {26, 30};\n    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841)\
    \ return {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if\
    \ (mod == 998244353) return {23, 31};\n    if (mod == 1004535809) return {21,\
    \ 582313106};\n    if (mod == 1012924417) return {21, 368093570};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int LIM>\r\nvc<array<T,\
    \ LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\n  assert(n\
    \ <= LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>> Rf(1 << n);\r\
    \n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\n  for (int\
    \ i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0; p < (1 <<\
    \ n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n        int\
    \ t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] += Rf[s][d];\r\
    \n      }\r\n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename T, int\
    \ LIM>\r\nvc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf) {\r\n  int n = topbit(len(Rf));\r\
    \n  assert(len(Rf) == 1 << n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int w\
    \ = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 * w) {\r\n      for (int\
    \ s = p; s < p + w; ++s) {\r\n        int t = s | 1 << i;\r\n        for (int\
    \ d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  vc<T>\
    \ f(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) f[s] = Rf[s][popcnt(s)];\r\
    \n  return f;\r\n}\n#line 3 \"setfunc/sps_composition.hpp\"\n\n// sum_i f_i/i!\
    \ s^i, s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_composition_egf(vc<mint>& f, vc<mint>& s) {\n  const int N = topbit(len(s));\n\
    \  assert(len(s) == (1 << N) && s[0] == mint(0));\n  if (len(f) > N) f.resize(N\
    \ + 1);\n  int D = len(f) - 1;\n  using ARR = array<mint, LIM + 1>;\n  vvc<ARR>\
    \ zs(N);\n  FOR(i, N) { zs[i] = ranked_zeta<mint, LIM>({s.begin() + (1 << i),\
    \ s.begin() + (2 << i)}); }\n\n  // dp : (d/dt)^df(s) (d=D,D-1,...)\n  vc<mint>\
    \ dp(1 << (N - D));\n  dp[0] = f[D];\n  FOR_R(d, D) {\n    vc<mint> newdp(1 <<\
    \ (N - d));\n    newdp[0] = f[d];\n    vc<ARR> zdp = ranked_zeta<mint, LIM>(dp);\n\
    \    FOR(i, N - d) {\n      // zs[1<<i:2<<i], zdp[0:1<<i]\n      vc<ARR> znewdp(1\
    \ << i);\n      FOR(k, 1 << i) {\n        FOR(p, i + 1) FOR(q, i - p + 1) { znewdp[k][p\
    \ + q] += zdp[k][p] * zs[i][k][q]; }\n      }\n      auto x = ranked_mobius<mint,\
    \ LIM>(znewdp);\n      copy(all(x), newdp.begin() + (1 << i));\n    }\n    swap(dp,\
    \ newdp);\n  }\n  return dp;\n}\n\n// sum_i f_i s^i, s^i is subset-convolution\n\
    template <typename mint, int LIM>\nvc<mint> sps_composition_poly(vc<mint> f, vc<mint>\
    \ s) {\n  const int N = topbit(len(s));\n  assert(len(s) == (1 << N));\n  if (f.empty())\
    \ return vc<mint>(1 << N, mint(0));\n  // convert to egf problem\n  int D = min<int>(len(f)\
    \ - 1, N);\n  vc<mint> g(D + 1);\n  mint c = s[0];\n  s[0] = 0;\n  // (x+c)^i\n\
    \  vc<mint> pow(D + 1);\n  pow[0] = 1;\n  FOR(i, len(f)) {\n    FOR(j, D + 1)\
    \ g[j] += f[i] * pow[j];\n    FOR_R(j, D + 1) pow[j] = pow[j] * c + (j == 0 ?\
    \ mint(0) : pow[j - 1]);\n  }\n  // to egf\n  mint factorial = 1;\n  FOR(j, D\
    \ + 1) g[j] *= factorial, factorial *= mint(j + 1);\n  return sps_composition_egf<mint,\
    \ LIM>(g, s);\n}\n#line 4 \"setfunc/sps_log.hpp\"\n\n// exp \u306E\u9006\u624B\
    \u9806\u3067\u8A08\u7B97\u3059\u308B\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_log(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n  assert(len(dp)\
    \ == (1 << N) && dp[0] == mint(1));\n  vc<mint> s(1 << N);\n  FOR_R(i, N) {\n\
    \    vc<mint> a = {dp.begin() + (1 << i), dp.begin() + (2 << i)};\n    vc<mint>\
    \ b = {dp.begin(), dp.begin() + (1 << i)};\n    auto RA = ranked_zeta<mint, LIM>(a);\n\
    \    auto RB = ranked_zeta<mint, LIM>(b);\n    FOR(s, 1 << i) {\n      auto &f\
    \ = RA[s], &g = RB[s];\n      // assert(g[0] == mint(1));\n      FOR(d, i + 1)\
    \ { FOR(i, d) f[d] -= f[i] * g[d - i]; }\n    }\n    a = ranked_mobius<mint, LIM>(RA);\n\
    \    copy(all(a), s.begin() + (1 << i));\n  }\n  return s;\n}\n#line 3 \"graph/count/count_connected_subgraph.hpp\"\
    \n\n// O(N^2 2^N)\ntemplate <typename T, int LIM>\nvc<T> count_connected_subgraph(Graph<int,\
    \ 0> G) {\n  int N = G.N;\n  assert(N <= LIM);\n  vc<T> pw(G.M + 1, 1);\n  FOR(i,\
    \ G.M) pw[i + 1] = pw[i] + pw[i];\n\n  // edge\n  vc<int> E(1 << N);\n  for (auto&\
    \ e: G.edges) { E[(1 << e.frm) | (1 << e.to)]++; }\n  FOR(i, N) FOR(s, 1 << N)\
    \ {\n    int t = s | 1 << i;\n    if (s < t) E[t] += E[s];\n  }\n\n  // any graph\n\
    \  vc<T> dp(1 << N);\n  FOR(s, 1 << N) dp[s] = pw[E[s]];\n\n  // connected\n \
    \ return sps_log<T, LIM>(dp);\n}\n#line 2 \"setfunc/subset_convolution.hpp\"\n\
    \r\n#line 4 \"setfunc/subset_convolution.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM = 20>\r\nvc<T> subset_convolution_square(const vc<T>& A) {\r\n  auto RA\
    \ = ranked_zeta<T, LIM>(A);\r\n  int n = topbit(len(RA));\r\n  FOR(s, len(RA))\
    \ {\r\n    auto& f = RA[s];\r\n    FOR_R(d, n + 1) {\r\n      T x = 0;\r\n   \
    \   FOR(i, d + 1) x += f[i] * f[d - i];\r\n      f[d] = x;\r\n    }\r\n  }\r\n\
    \  return ranked_mobius<T, LIM>(RA);\r\n}\r\n\r\ntemplate <typename T, int LIM\
    \ = 20>\r\nvc<T> subset_convolution(const vc<T>& A, const vc<T>& B) {\r\n  if\
    \ (A == B) return subset_convolution_square(A);\r\n  auto RA = ranked_zeta<T,\
    \ LIM>(A);\r\n  auto RB = ranked_zeta<T, LIM>(B);\r\n  int n = topbit(len(RA));\r\
    \n  FOR(s, len(RA)) {\r\n    auto &f = RA[s], &g = RB[s];\r\n    FOR_R(d, n +\
    \ 1) {\r\n      T x = 0;\r\n      FOR(i, d + 1) x += f[i] * g[d - i];\r\n    \
    \  f[d] = x;\r\n    }\r\n  }\r\n  return ranked_mobius<T, LIM>(RA);\r\n}\r\n#line\
    \ 2 \"setfunc/sps_exp.hpp\"\n\n#line 4 \"setfunc/sps_exp.hpp\"\n\n// sum_i 1/i!\
    \ s^i, s^i is subset-convolution\ntemplate <typename mint, int LIM>\nvc<mint>\
    \ sps_exp(vc<mint>& s) {\n  const int N = topbit(len(s));\n  assert(len(s) ==\
    \ (1 << N) && s[0] == mint(0));\n  vc<mint> dp(1 << N);\n  dp[0] = mint(1);\n\
    \  FOR(i, N) {\n    vc<mint> a = {s.begin() + (1 << i), s.begin() + (2 << i)};\n\
    \    vc<mint> b = {dp.begin(), dp.begin() + (1 << i)};\n    a = subset_convolution<mint,\
    \ LIM>(a, b);\n    copy(all(a), dp.begin() + (1 << i));\n  }\n  return dp;\n}\n\
    #line 4 \"graph/count/count_bridgeless_subgraph.hpp\"\n\n// O(N^3 2^N). https://loj.ac/p/6730.\n\
    template <typename T, int LIM>\nvc<T> count_bridgeless_subgraph(Graph<int, 0>\
    \ G, bool connected = true) {\n  int N = G.N;\n  auto dp = count_connected_subgraph<T,\
    \ LIM>(G);\n\n  FOR(r, 1, N) {\n    u32 nbd = 0;\n    for (auto& e: G[r])\n  \
    \    if (e.to < r) nbd |= 1 << e.to;\n\n    // before: [0,r) \u306B\u6A4B\u304C\
    \u306A\u3044\n    // after: [0,r] \u306B\u6A4B\u304C\u306A\u3044\n    vc<T> f(1\
    \ << (N - 1));\n    vc<T> g(1 << (N - 1));\n    FOR(L, 1 << r) {\n      FOR(R,\
    \ 1 << (N - 1 - r)) {\n        f[L | R << r] = dp[L | R << (1 + r)] * popcnt(L\
    \ & nbd);\n        g[L | R << r] = dp[L | R << (1 + r) | (1 << r)];\n      }\n\
    \    }\n\n    FOR(s, 1 << (N - 1)) f[s] = -f[s];\n    f = sps_exp<T, LIM - 1>(f);\n\
    \    g = subset_convolution<T, LIM - 1>(f, g);\n    FOR(L, 1 << r) {\n      FOR(R,\
    \ 1 << (N - 1 - r)) { dp[L | R << (1 + r) | (1 << r)] = g[L | R << r]; }\n   \
    \ }\n  }\n  if (!connected) dp = sps_exp<T, LIM>(dp);\n  return dp;\n}\n"
  code: "#include \"graph/count/count_connected_subgraph.hpp\"\n#include \"setfunc/subset_convolution.hpp\"\
    \n#include \"setfunc/sps_exp.hpp\"\n\n// O(N^3 2^N). https://loj.ac/p/6730.\n\
    template <typename T, int LIM>\nvc<T> count_bridgeless_subgraph(Graph<int, 0>\
    \ G, bool connected = true) {\n  int N = G.N;\n  auto dp = count_connected_subgraph<T,\
    \ LIM>(G);\n\n  FOR(r, 1, N) {\n    u32 nbd = 0;\n    for (auto& e: G[r])\n  \
    \    if (e.to < r) nbd |= 1 << e.to;\n\n    // before: [0,r) \u306B\u6A4B\u304C\
    \u306A\u3044\n    // after: [0,r] \u306B\u6A4B\u304C\u306A\u3044\n    vc<T> f(1\
    \ << (N - 1));\n    vc<T> g(1 << (N - 1));\n    FOR(L, 1 << r) {\n      FOR(R,\
    \ 1 << (N - 1 - r)) {\n        f[L | R << r] = dp[L | R << (1 + r)] * popcnt(L\
    \ & nbd);\n        g[L | R << r] = dp[L | R << (1 + r) | (1 << r)];\n      }\n\
    \    }\n\n    FOR(s, 1 << (N - 1)) f[s] = -f[s];\n    f = sps_exp<T, LIM - 1>(f);\n\
    \    g = subset_convolution<T, LIM - 1>(f, g);\n    FOR(L, 1 << r) {\n      FOR(R,\
    \ 1 << (N - 1 - r)) { dp[L | R << (1 + r) | (1 << r)] = g[L | R << r]; }\n   \
    \ }\n  }\n  if (!connected) dp = sps_exp<T, LIM>(dp);\n  return dp;\n}\n"
  dependsOn:
  - graph/count/count_connected_subgraph.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - setfunc/sps_log.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - setfunc/sps_composition.hpp
  - setfunc/ranked_zeta.hpp
  - setfunc/subset_convolution.hpp
  - setfunc/sps_exp.hpp
  isVerificationFile: false
  path: graph/count/count_bridgeless_subgraph.hpp
  requiredBy: []
  timestamp: '2025-05-25 23:45:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_bridgeless_subgraph.hpp
layout: document
redirect_from:
- /library/graph/count/count_bridgeless_subgraph.hpp
- /library/graph/count/count_bridgeless_subgraph.hpp.html
title: graph/count/count_bridgeless_subgraph.hpp
---
