---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/path_cycle.hpp
    title: graph/path_cycle.hpp
  - icon: ':x:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':x:'
    path: poly/convolution_karatsuba.hpp
    title: poly/convolution_karatsuba.hpp
  - icon: ':x:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':x:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/count_indep_set.test.cpp
    title: test/mytest/count_indep_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 2 \"graph/path_cycle.hpp\"\n\n// \u3069\u306E\u70B9\u306E\u6B21\
    \u6570\u3082 2 \u4EE5\u4E0B\u306E\u30B0\u30E9\u30D5\u304C\u3042\u308B\u3068\u304D\
    \u306B\u3001\n// \u30D1\u30B9\u306E\u9802\u70B9\u5217, \u30B5\u30A4\u30AF\u30EB\
    \u306E\u9802\u70B9\u5217\n// \u306B\u5206\u89E3\u3059\u308B\ntemplate <typename\
    \ Graph>\npair<vvc<int>, vvc<int>> path_cycle(Graph& G) {\n  int N = G.N;\n  auto\
    \ deg = G.deg_array();\n  assert(MAX(deg) <= 2);\n  assert(!G.is_directed());\n\
    \n  vc<bool> done(N);\n  auto calc_frm = [&](int v) -> vc<int> {\n    vc<int>\
    \ P = {v};\n    done[v] = 1;\n    while (1) {\n      bool ok = 0;\n      for (auto&&\
    \ e: G[P.back()]) {\n        if (done[e.to]) continue;\n        P.eb(e.to);\n\
    \        done[e.to] = 1;\n        ok = 1;\n        break;\n      }\n      if (!ok)\
    \ break;\n    }\n    return P;\n  };\n  vvc<int> paths, cycs;\n  FOR(v, N) {\n\
    \    if (deg[v] == 0) {\n      done[v] = 1;\n      paths.eb(vc<int>({int(v)}));\n\
    \    }\n    if (done[v] || deg[v] != 1) continue;\n    paths.eb(calc_frm(v));\n\
    \  }\n  FOR(v, N) {\n    if (done[v]) continue;\n    cycs.eb(calc_frm(v));\n \
    \ }\n  return {paths, cycs};\n}\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return\
    \ mint(0);\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint, class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail)\
    \ {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n \
    \ if (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n \
    \ mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\ntemplate <typename mint, bool large\
    \ = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n\
    \  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1) : mint(0));\
    \ }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\
    \n\ntemplate <u32 mod>\nstruct modint {\n  static_assert(mod < (u32(1) << 31));\n\
    \  u32 val;\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x\
    \ % mod) {}\n  constexpr modint(u64 x) : val(x % mod) {}\n  constexpr modint(int\
    \ x) : val((x %= int(mod)) < 0 ? x + int(mod) : x){};\n  constexpr modint(ll x)\
    \ : val((x %= int(mod)) < 0 ? x + int(mod) : x){};\n  bool operator<(const modint\
    \ &other) const { return val < other.val; }\n  modint &operator+=(const modint\
    \ &p) {\n    if ((val += p.val) >= mod) val -= mod;\n    return *this;\n  }\n\
    \  modint &operator-=(const modint &p) {\n    if ((val += mod - p.val) >= mod)\
    \ val -= mod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n\
    \    val = u64(val) * p.val % mod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint(mod - val); }\n  modint operator+(const modint &p) const\
    \ { return modint(*this) += p; }\n  modint operator-(const modint &p) const {\
    \ return modint(*this) -= p; }\n  modint operator*(const modint &p) const { return\
    \ modint(*this) *= p; }\n  modint operator/(const modint &p) const { return modint(*this)\
    \ /= p; }\n  bool operator==(const modint &p) const { return val == p.val; }\n\
    \  bool operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    assert(n >= 0);\n  \
    \  modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n\
    \  void write() { fastio::printer.write(val); }\n  void read() {\n    fastio::scanner.read(val);\n\
    \    val %= mod;\n  }\n#endif\n  static constexpr u32 get_mod() { return mod;\
    \ }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int,\
    \ int> ntt_info() {\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 998244353) return\
    \ {23, 31};\n    if (mod == 1045430273) return {20, 363};\n    if (mod == 1051721729)\
    \ return {20, 330};\n    if (mod == 1053818881) return {20, 2789};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\r\n// (val\
    \ * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\u3059\r\n\
    ll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod = abs(mod);\r\
    \n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b = mod, u = 1,\
    \ v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return u;\r\n}\r\n\
    #line 2 \"poly/convolution_naive.hpp\"\ntemplate <class T>\r\nvector<T> convolution_naive(const\
    \ vector<T>& a, const vector<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\
    \n  if (n == 0 || m == 0) return {};\r\n  vector<T> ans(n + m - 1);\r\n  if (n\
    \ < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\n  } else {\r\
    \n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\n  }\r\n  return ans;\r\
    \n}\r\n#line 2 \"poly/convolution_karatsuba.hpp\"\n\n// \u4EFB\u610F\u306E\u74B0\
    \u3067\u3067\u304D\u308B\ntemplate <typename T>\nvc<T> convolution_karatsuba(const\
    \ vc<T>& f, const vc<T>& g) {\n  const int thresh = 30;\n  if (min(len(f), len(g))\
    \ <= thresh) return convolution_naive(f, g);\n  int n = max(len(f), len(g));\n\
    \  int m = ceil(n, 2);\n  vc<T> f1, f2, g1, g2;\n  if (len(f) < m) f1 = f;\n \
    \ if (len(f) >= m) f1 = {f.begin(), f.begin() + m};\n  if (len(f) >= m) f2 = {f.begin()\
    \ + m, f.end()};\n  if (len(g) < m) g1 = g;\n  if (len(g) >= m) g1 = {g.begin(),\
    \ g.begin() + m};\n  if (len(g) >= m) g2 = {g.begin() + m, g.end()};\n  vc<T>\
    \ a = convolution_karatsuba(f1, g1);\n  vc<T> b = convolution_karatsuba(f2, g2);\n\
    \  FOR(i, len(f2)) f1[i] += f2[i];\n  FOR(i, len(g2)) g1[i] += g2[i];\n  vc<T>\
    \ c = convolution_karatsuba(f1, g1);\n  vc<T> F(len(f) + len(g) - 1);\n  assert(2\
    \ * m + len(b) <= len(F));\n  FOR(i, len(a)) F[i] += a[i], c[i] -= a[i];\n  FOR(i,\
    \ len(b)) F[2 * m + i] += b[i], c[i] -= b[i];\n  if (c.back() == T(0)) c.pop_back();\n\
    \  FOR(i, len(c)) if (c[i] != T(0)) F[m + i] += c[i];\n  return F;\n}\n#line 2\
    \ \"poly/ntt.hpp\"\n\r\ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool\
    \ inverse) {\r\n  assert(mint::can_ntt());\r\n  const int rank2 = mint::ntt_info().fi;\r\
    \n  const int mod = mint::get_mod();\r\n  static array<mint, 30> root, iroot;\r\
    \n  static array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\
    \n\r\n  static bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\
    \n    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\
    \n    FOR_R(i, rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n    \
    \  iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod\
    \ = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i\
    \ + 2] * prod;\r\n      irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i\
    \ + 2];\r\n      iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] *\
    \ prod;\r\n      irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i +\
    \ 3];\r\n      iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\
    \n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 1 \"poly/fft.hpp\"\nnamespace CFFT {\r\nusing real\
    \ = double;\r\n\r\nstruct C {\r\n  real x, y;\r\n\r\n  C() : x(0), y(0) {}\r\n\
    \r\n  C(real x, real y) : x(x), y(y) {}\r\n  inline C operator+(const C& c) const\
    \ { return C(x + c.x, y + c.y); }\r\n  inline C operator-(const C& c) const {\
    \ return C(x - c.x, y - c.y); }\r\n  inline C operator*(const C& c) const {\r\n\
    \    return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n  }\r\n\r\n  inline C\
    \ conj() const { return C(x, -y); }\r\n};\r\n\r\nconst real PI = acosl(-1);\r\n\
    int base = 1;\r\nvector<C> rts = {{0, 0}, {1, 0}};\r\nvector<int> rev = {0, 1};\r\
    \n\r\nvoid ensure_base(int nbase) {\r\n  if (nbase <= base) return;\r\n  rev.resize(1\
    \ << nbase);\r\n  rts.resize(1 << nbase);\r\n  for (int i = 0; i < (1 << nbase);\
    \ i++) {\r\n    rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\r\n  }\r\
    \n  while (base < nbase) {\r\n    real angle = PI * 2.0 / (1 << (base + 1));\r\
    \n    for (int i = 1 << (base - 1); i < (1 << base); i++) {\r\n      rts[i <<\
    \ 1] = rts[i];\r\n      real angle_i = angle * (2 * i + 1 - (1 << base));\r\n\
    \      rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));\r\n    }\r\n    ++base;\r\
    \n  }\r\n}\r\n\r\nvoid fft(vector<C>& a, int n) {\r\n  assert((n & (n - 1)) ==\
    \ 0);\r\n  int zeros = __builtin_ctz(n);\r\n  ensure_base(zeros);\r\n  int shift\
    \ = base - zeros;\r\n  for (int i = 0; i < n; i++) {\r\n    if (i < (rev[i] >>\
    \ shift)) { swap(a[i], a[rev[i] >> shift]); }\r\n  }\r\n  for (int k = 1; k <\
    \ n; k <<= 1) {\r\n    for (int i = 0; i < n; i += 2 * k) {\r\n      for (int\
    \ j = 0; j < k; j++) {\r\n        C z = a[i + j + k] * rts[j + k];\r\n       \
    \ a[i + j + k] = a[i + j] - z;\r\n        a[i + j] = a[i + j] + z;\r\n      }\r\
    \n    }\r\n  }\r\n}\r\n} // namespace CFFT\n#line 8 \"poly/convolution.hpp\"\n\
    \r\ntemplate <class mint>\r\nvector<mint> convolution_ntt(vector<mint> a, vector<mint>\
    \ b) {\r\n  if (a.empty() || b.empty()) return {};\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  int sz = 1;\r\n  while (sz < n + m - 1) sz *= 2;\r\n\
    \r\n  // sz = 2^k \u306E\u3068\u304D\u306E\u9AD8\u901F\u5316\u3002\u5206\u5272\
    \u7D71\u6CBB\u7684\u306A\u3084\u3064\u3067\u640D\u3057\u307E\u304F\u308B\u306E\
    \u3067\u3002\r\n  if ((n + m - 3) <= sz / 2) {\r\n    auto a_last = a.back(),\
    \ b_last = b.back();\r\n    a.pop_back(), b.pop_back();\r\n    auto c = convolution(a,\
    \ b);\r\n    c.resize(n + m - 1);\r\n    c[n + m - 2] = a_last * b_last;\r\n \
    \   FOR(i, len(a)) c[i + len(b)] += a[i] * b_last;\r\n    FOR(i, len(b)) c[i +\
    \ len(a)] += b[i] * a_last;\r\n    return c;\r\n  }\r\n\r\n  a.resize(sz), b.resize(sz);\r\
    \n  bool same = a == b;\r\n  ntt(a, 0);\r\n  if (same) {\r\n    b = a;\r\n  }\
    \ else {\r\n    ntt(b, 0);\r\n  }\r\n  FOR(i, sz) a[i] *= b[i];\r\n  ntt(a, 1);\r\
    \n  a.resize(n + m - 1);\r\n  return a;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nvector<mint> convolution_garner(const vector<mint>& a, const vector<mint>& b)\
    \ {\r\n  int n = len(a), m = len(b);\r\n  if (!n || !m) return {};\r\n  static\
    \ const long long nttprimes[] = {754974721, 167772161, 469762049};\r\n  using\
    \ mint0 = modint<754974721>;\r\n  using mint1 = modint<167772161>;\r\n  using\
    \ mint2 = modint<469762049>;\r\n  vc<mint0> a0(n), b0(m);\r\n  vc<mint1> a1(n),\
    \ b1(m);\r\n  vc<mint2> a2(n), b2(m);\r\n  FOR(i, n) a0[i] = a[i].val, a1[i] =\
    \ a[i].val, a2[i] = a[i].val;\r\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val,\
    \ b2[i] = b[i].val;\r\n  auto c0 = convolution_ntt<mint0>(a0, b0);\r\n  auto c1\
    \ = convolution_ntt<mint1>(a1, b1);\r\n  auto c2 = convolution_ntt<mint2>(a2,\
    \ b2);\r\n  static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];\r\n\
    \  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\r\n \
    \ static const long long m01_inv_m2 = mint2(m01).inverse().val;\r\n  const int\
    \ mod = mint::get_mod();\r\n  auto garner = [&](mint0 x0, mint1 x1, mint2 x2)\
    \ -> mint {\r\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\r\n    int v1 =\
    \ (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\r\n    auto v2 = (mint2(r2)\
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
    \ {};\r\n  if (min(n, m) <= 2500) return convolution_naive(a, b);\r\n  ll abs_sum_a\
    \ = 0, abs_sum_b = 0;\r\n  ll LIM = 1e15;\r\n  FOR(i, n) abs_sum_a = min(LIM,\
    \ abs_sum_a + abs(a[i]));\r\n  FOR(i, m) abs_sum_b = min(LIM, abs_sum_b + abs(b[i]));\r\
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
    \nvc<mint> convolution(const vc<mint>& a, const vc<mint>& b) {\r\n  int n = len(a),\
    \ m = len(b);\r\n  if (!n || !m) return {};\r\n  if (mint::can_ntt()) {\r\n  \
    \  if (min(n, m) <= 50) return convolution_karatsuba<mint>(a, b);\r\n    return\
    \ convolution_ntt(a, b);\r\n  }\r\n  if (min(n, m) <= 200) return convolution_karatsuba<mint>(a,\
    \ b);\r\n  return convolution_garner(a, b);\r\n}\r\n#line 3 \"graph/count/count_independent_set.hpp\"\
    \n\n// \u72EC\u7ACB\u96C6\u5408\u6570\u3048\u4E0A\u3052\u3002\u7A7A\u96C6\u5408\
    \u3082\u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\u5EA6\u3002\ntemplate <typename\
    \ GT>\nu64 count_independent_set(GT& G) {\n  using U = u64;\n  const int N = G.N;\n\
    \  assert(N < 64);\n  if (N == 0) return 1;\n  vc<U> nbd(N);\n  FOR(v, N) for\
    \ (auto&& e: G[v]) nbd[v] |= U(1) << e.to;\n\n  vc<U> dp_path(N + 1), dp_cyc(N\
    \ + 1);\n  dp_path[0] = 1, dp_path[1] = 2;\n  FOR(i, 2, N + 1) dp_path[i] = dp_path[i\
    \ - 1] + dp_path[i - 2];\n  FOR(i, 3, N + 1) dp_cyc[i] = dp_path[i - 1] + dp_path[i\
    \ - 3];\n\n  auto dfs = [&](auto& dfs, U s) -> U {\n    int deg0 = 0;\n    pair<int,\
    \ int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s >> v & 1) {\n      int d =\
    \ popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi = v;\n      if (d == 0)\
    \ {\n        ++deg0;\n        s &= ~(U(1) << v);\n      }\n    }\n    if (s ==\
    \ 0) return U(1) << deg0;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &=\
    \ ~(U(1) << v);\n      return (dfs(dfs, s) + dfs(dfs, s & ~nbd[v])) << deg0;\n\
    \    }\n    // d <= 2, path \u3068 cycle \u306E\u307F\n    vc<int> V;\n    FOR(v,\
    \ N) if (s >> v & 1) V.eb(v);\n    int n = len(V);\n    Graph<bool, 0> G(n);\n\
    \    FOR(i, n) {\n      U x = nbd[V[i]] & s;\n      while (x) {\n        int v\
    \ = topbit(x);\n        x ^= U(1) << v;\n        int j = LB(V, v);\n        if\
    \ (i < j) G.add(i, j);\n      }\n    }\n    G.build();\n    auto [paths, cycs]\
    \ = path_cycle(G);\n    U res = 1;\n    for (auto&& P: paths) res *= dp_path[len(P)];\n\
    \    for (auto&& C: cycs) res *= dp_cyc[len(C)];\n    return res << deg0;\n  };\n\
    \  return dfs(dfs, (U(1) << N) - 1);\n}\n\n// \u72EC\u7ACB\u96C6\u5408\u6570\u3048\
    \u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\
    \u5EA6\u3002\ntemplate <typename GT>\nvc<u64> count_independent_set_by_size(GT&\
    \ G) {\n  using U = u64;\n  const int N = G.N;\n  assert(N < 64);\n  if (N ==\
    \ 0) return {1};\n  vc<U> nbd(N);\n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |=\
    \ U(1) << e.to;\n\n  vvc<U> dp_path(N + 1), dp_cyc(N + 1);\n  dp_path[0] = {1},\
    \ dp_path[1] = {1, 1};\n  FOR(i, 2, N + 1) {\n    dp_path[i] = dp_path[i - 1];\n\
    \    dp_path[i].resize(ceil(i, 2) + 1);\n    FOR(k, len(dp_path[i - 2])) { dp_path[i][k\
    \ + 1] += dp_path[i - 2][k]; }\n  }\n  FOR(i, 3, N + 1) {\n    dp_cyc[i] = dp_path[i\
    \ - 1];\n    FOR(k, len(dp_path[i - 3])) dp_cyc[i][k + 1] += dp_path[i - 3][k];\n\
    \  }\n\n  auto dfs = [&](auto& dfs, U s) -> vc<U> {\n    vc<U> res = {1};\n  \
    \  pair<int, int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s >> v & 1) {\n \
    \     int d = popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi = v;\n     \
    \ if (d == 0) {\n        res.eb(0);\n        FOR_R(i, len(res) - 1) res[i + 1]\
    \ += res[i];\n        s &= ~(U(1) << v);\n      }\n    }\n    if (s == 0) return\
    \ res;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &= ~(U(1) << v);\n  \
    \    auto f = dfs(dfs, s), g = dfs(dfs, s & ~nbd[v]);\n      if (len(f) < len(g)\
    \ + 1) f.resize(len(g) + 1);\n      FOR(i, len(g)) f[i + 1] += g[i];\n      return\
    \ convolution_naive(f, res);\n    }\n    // d <= 2, path \u3068 cycle \u306E\u307F\
    \n    vc<int> V;\n    FOR(v, N) if (s >> v & 1) V.eb(v);\n    int n = len(V);\n\
    \    Graph<bool, 0> G(n);\n    FOR(i, n) {\n      U x = nbd[V[i]] & s;\n     \
    \ while (x) {\n        int v = topbit(x);\n        x ^= U(1) << v;\n        int\
    \ j = LB(V, v);\n        if (i < j) G.add(i, j);\n      }\n    }\n    G.build();\n\
    \    auto [paths, cycs] = path_cycle(G);\n    for (auto&& P: paths) res = convolution_naive(res,\
    \ dp_path[len(P)]);\n    for (auto&& C: cycs) res = convolution_naive(res, dp_cyc[len(C)]);\n\
    \    return res;\n  };\n  auto res = dfs(dfs, (U(1) << N) - 1);\n  res.resize(N\
    \ + 1);\n  return res;\n}\n"
  code: "#include \"graph/path_cycle.hpp\"\n#include \"poly/convolution.hpp\"\n\n\
    // \u72EC\u7ACB\u96C6\u5408\u6570\u3048\u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\
    \u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\u5EA6\u3002\ntemplate <typename GT>\n\
    u64 count_independent_set(GT& G) {\n  using U = u64;\n  const int N = G.N;\n \
    \ assert(N < 64);\n  if (N == 0) return 1;\n  vc<U> nbd(N);\n  FOR(v, N) for (auto&&\
    \ e: G[v]) nbd[v] |= U(1) << e.to;\n\n  vc<U> dp_path(N + 1), dp_cyc(N + 1);\n\
    \  dp_path[0] = 1, dp_path[1] = 2;\n  FOR(i, 2, N + 1) dp_path[i] = dp_path[i\
    \ - 1] + dp_path[i - 2];\n  FOR(i, 3, N + 1) dp_cyc[i] = dp_path[i - 1] + dp_path[i\
    \ - 3];\n\n  auto dfs = [&](auto& dfs, U s) -> U {\n    int deg0 = 0;\n    pair<int,\
    \ int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s >> v & 1) {\n      int d =\
    \ popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi = v;\n      if (d == 0)\
    \ {\n        ++deg0;\n        s &= ~(U(1) << v);\n      }\n    }\n    if (s ==\
    \ 0) return U(1) << deg0;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &=\
    \ ~(U(1) << v);\n      return (dfs(dfs, s) + dfs(dfs, s & ~nbd[v])) << deg0;\n\
    \    }\n    // d <= 2, path \u3068 cycle \u306E\u307F\n    vc<int> V;\n    FOR(v,\
    \ N) if (s >> v & 1) V.eb(v);\n    int n = len(V);\n    Graph<bool, 0> G(n);\n\
    \    FOR(i, n) {\n      U x = nbd[V[i]] & s;\n      while (x) {\n        int v\
    \ = topbit(x);\n        x ^= U(1) << v;\n        int j = LB(V, v);\n        if\
    \ (i < j) G.add(i, j);\n      }\n    }\n    G.build();\n    auto [paths, cycs]\
    \ = path_cycle(G);\n    U res = 1;\n    for (auto&& P: paths) res *= dp_path[len(P)];\n\
    \    for (auto&& C: cycs) res *= dp_cyc[len(C)];\n    return res << deg0;\n  };\n\
    \  return dfs(dfs, (U(1) << N) - 1);\n}\n\n// \u72EC\u7ACB\u96C6\u5408\u6570\u3048\
    \u4E0A\u3052\u3002\u7A7A\u96C6\u5408\u3082\u8A8D\u3081\u308B\u3002N 1.381^N \u7A0B\
    \u5EA6\u3002\ntemplate <typename GT>\nvc<u64> count_independent_set_by_size(GT&\
    \ G) {\n  using U = u64;\n  const int N = G.N;\n  assert(N < 64);\n  if (N ==\
    \ 0) return {1};\n  vc<U> nbd(N);\n  FOR(v, N) for (auto&& e: G[v]) nbd[v] |=\
    \ U(1) << e.to;\n\n  vvc<U> dp_path(N + 1), dp_cyc(N + 1);\n  dp_path[0] = {1},\
    \ dp_path[1] = {1, 1};\n  FOR(i, 2, N + 1) {\n    dp_path[i] = dp_path[i - 1];\n\
    \    dp_path[i].resize(ceil(i, 2) + 1);\n    FOR(k, len(dp_path[i - 2])) { dp_path[i][k\
    \ + 1] += dp_path[i - 2][k]; }\n  }\n  FOR(i, 3, N + 1) {\n    dp_cyc[i] = dp_path[i\
    \ - 1];\n    FOR(k, len(dp_path[i - 3])) dp_cyc[i][k + 1] += dp_path[i - 3][k];\n\
    \  }\n\n  auto dfs = [&](auto& dfs, U s) -> vc<U> {\n    vc<U> res = {1};\n  \
    \  pair<int, int> p = {-1, -1}; // (v, d)\n    FOR(v, N) if (s >> v & 1) {\n \
    \     int d = popcnt(nbd[v] & s);\n      if (chmax(p.se, d)) p.fi = v;\n     \
    \ if (d == 0) {\n        res.eb(0);\n        FOR_R(i, len(res) - 1) res[i + 1]\
    \ += res[i];\n        s &= ~(U(1) << v);\n      }\n    }\n    if (s == 0) return\
    \ res;\n    int v = p.fi;\n    if (p.se >= 3) {\n      s &= ~(U(1) << v);\n  \
    \    auto f = dfs(dfs, s), g = dfs(dfs, s & ~nbd[v]);\n      if (len(f) < len(g)\
    \ + 1) f.resize(len(g) + 1);\n      FOR(i, len(g)) f[i + 1] += g[i];\n      return\
    \ convolution_naive(f, res);\n    }\n    // d <= 2, path \u3068 cycle \u306E\u307F\
    \n    vc<int> V;\n    FOR(v, N) if (s >> v & 1) V.eb(v);\n    int n = len(V);\n\
    \    Graph<bool, 0> G(n);\n    FOR(i, n) {\n      U x = nbd[V[i]] & s;\n     \
    \ while (x) {\n        int v = topbit(x);\n        x ^= U(1) << v;\n        int\
    \ j = LB(V, v);\n        if (i < j) G.add(i, j);\n      }\n    }\n    G.build();\n\
    \    auto [paths, cycs] = path_cycle(G);\n    for (auto&& P: paths) res = convolution_naive(res,\
    \ dp_path[len(P)]);\n    for (auto&& C: cycs) res = convolution_naive(res, dp_cyc[len(C)]);\n\
    \    return res;\n  };\n  auto res = dfs(dfs, (U(1) << N) - 1);\n  res.resize(N\
    \ + 1);\n  return res;\n}"
  dependsOn:
  - graph/path_cycle.hpp
  - graph/base.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/convolution_karatsuba.hpp
  - poly/ntt.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: graph/count/count_independent_set.hpp
  requiredBy: []
  timestamp: '2023-08-06 23:25:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/count_indep_set.test.cpp
documentation_of: graph/count/count_independent_set.hpp
layout: document
redirect_from:
- /library/graph/count/count_independent_set.hpp
- /library/graph/count/count_independent_set.hpp.html
title: graph/count/count_independent_set.hpp
---
