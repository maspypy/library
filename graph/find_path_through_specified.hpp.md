---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: nt/GF2.hpp
    title: nt/GF2.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1775.test.cpp
    title: test/3_yukicoder/1775.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1776.test.cpp
    title: test/3_yukicoder/1776.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"nt/GF2.hpp\"\n#include <emmintrin.h>\n#include\
    \ <smmintrin.h>\n#include <wmmintrin.h>\n\n__attribute__((target(\"pclmul\")))\
    \ inline __m128i myclmul(const __m128i &a,\n                                 \
    \                        const __m128i &b) {\n  return _mm_clmulepi64_si128(a,\
    \ b, 0);\n}\n\n// 2^n \u5143\u4F53\ntemplate <int K>\nstruct GF2 {\n  // https://oeis.org/A344141\n\
    \  // irreducible poly x^K + ...\n  static constexpr int POLY[65]\n      = {0,\
    \  0, 3,  3,   3,  5,   3,  3,  27,  3,  9,  5,   9, 27, 33, 3,   43,\n      \
    \   9,  9, 39, 9,   5,  3,   33, 27, 9,   27, 39, 3,   5, 3,  9,  141, 75,\n \
    \        27, 5, 53, 63,  99, 17,  57, 9,  39,  89, 33, 27,  3, 33, 45, 113, 29,\n\
    \         75, 9, 71, 125, 71, 149, 17, 99, 123, 3,  39, 105, 3, 27};\n\n  static\
    \ constexpr u64 mask() { return u64(-1) >> (64 - K); }\n\n  __attribute__((target(\"\
    sse4.2\"))) static u64 mul(u64 a, u64 b) {\n    static bool prepared = 0;\n  \
    \  static u64 MEMO[8][65536];\n    if (!prepared) {\n      prepared = 1;\n   \
    \   vc<u64> tmp(128);\n      tmp[0] = 1;\n      FOR(i, 127) {\n        tmp[i +\
    \ 1] = tmp[i] << 1;\n        if (tmp[i] >> (K - 1) & 1) {\n          tmp[i + 1]\
    \ ^= POLY[K];\n          tmp[i + 1] &= mask();\n        }\n      }\n      FOR(k,\
    \ 8) {\n        MEMO[k][0] = 0;\n        FOR(i, 16) {\n          FOR(s, 1 << i)\
    \ { MEMO[k][s | 1 << i] = MEMO[k][s] ^ tmp[16 * k + i]; }\n        }\n      }\n\
    \    }\n    const __m128i a_ = _mm_set_epi64x(0, a);\n    const __m128i b_ = _mm_set_epi64x(0,\
    \ b);\n    const __m128i c_ = myclmul(a_, b_);\n    u64 lo = _mm_extract_epi64(c_,\
    \ 0);\n    u64 hi = _mm_extract_epi64(c_, 1);\n    u64 x = 0;\n    x ^= MEMO[0][lo\
    \ & 65535];\n    x ^= MEMO[1][(lo >> 16) & 65535];\n    x ^= MEMO[2][(lo >> 32)\
    \ & 65535];\n    x ^= MEMO[3][(lo >> 48) & 65535];\n    x ^= MEMO[4][hi & 65535];\n\
    \    x ^= MEMO[5][(hi >> 16) & 65535];\n    x ^= MEMO[6][(hi >> 32) & 65535];\n\
    \    x ^= MEMO[7][(hi >> 48) & 65535];\n    return x;\n  }\n\n  u64 val;\n  constexpr\
    \ GF2(const u64 val = 0) noexcept : val(val & mask()) {}\n  bool operator<(const\
    \ GF2 &other) const {\n    return val < other.val;\n  } // To use std::map\n \
    \ GF2 &operator+=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator-=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator*=(const GF2 &p) {\n    val = mul(val, p.val);\n    return *this;\n\
    \  }\n\n  GF2 &operator/=(const GF2 &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  GF2 operator-() const { return GF2(-val); }\n  GF2 operator+(const\
    \ GF2 &p) const { return GF2(*this) += p; }\n  GF2 operator-(const GF2 &p) const\
    \ { return GF2(*this) -= p; }\n  GF2 operator*(const GF2 &p) const { return GF2(*this)\
    \ *= p; }\n  GF2 operator/(const GF2 &p) const { return GF2(*this) /= p; }\n \
    \ bool operator==(const GF2 &p) const { return val == p.val; }\n  bool operator!=(const\
    \ GF2 &p) const { return val != p.val; }\n  GF2 inverse() const { return pow((u64(1)\
    \ << K) - 2); }\n  GF2 pow(u64 n) const {\n    GF2 ret(1), mul(val);\n    while\
    \ (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n};\n\n#ifdef FASTIO\ntemplate <int K>\nvoid rd(GF2<K>\
    \ &x) {\n  fastio::rd(x.val);\n  x &= GF2<K>::mask;\n}\ntemplate <int K>\nvoid\
    \ wt(GF2<K> x) {\n  fastio::wt(x.val);\n}\n#endif\n#line 4 \"graph/find_path_through_specified.hpp\"\
    \n\n// (s,t) path \u3067\u3042\u3063\u3066 need \u3092\u3059\u3079\u3066\u901A\
    \u308B\u3082\u306E\u306E\u6700\u5C0F\u9577\u3055\u3092\u6C42\u3081\u308B.\n//\
    \ s=t \u3067\u3082\u3088\u3044. \u6700\u521D\u306E 1 \u6B69\u76EE\u3082\u6C42\u3081\
    \u308B.\n// {length, first v}. \u306A\u3051\u308C\u3070 {-1,-1}.\n// O(2^K(N+M)L),\
    \ L = shortest path length\ntemplate <typename GT>\npair<int, int> find_path_through_specified(GT&\
    \ G, int s, int t, vc<int> need) {\n  static_assert(!GT::is_directed);\n  int\
    \ N = G.N;\n  assert(0 <= s && s < N && 0 <= t && t < N);\n  using F = GF2<64>;\n\
    \  // frm, to, wt\n  vc<tuple<int, int, F>> edges;\n  vc<int> S, T;\n  for (auto&\
    \ e: G.edges) {\n    int a = e.frm, b = e.to;\n    if ((a == s && b == t) || (a\
    \ == t && b == s)) {\n      if (need.empty()) return {1, t};\n      continue;\n\
    \    }\n    if (a == s || b == s) { S.eb(a ^ b ^ s); }\n    if (a == t || b ==\
    \ t) { T.eb(a ^ b ^ t); }\n    if (a != s && a != t && b != s && b != t) {\n \
    \     F x = RNG_64();\n      edges.eb(a, b, x), edges.eb(b, a, x);\n    }\n  }\n\
    \  int K = len(need);\n  vc<int> get(N);\n  FOR(k, K) get[need[k]] = 1 << k;\n\
    \  int M = len(edges);\n\n  vv(F, dp_e, 1 << K, M);\n  vv(F, dp_v, 1 << K, N);\n\
    \  for (auto& v: T) dp_v[get[v]][v] = RNG_64();\n  FOR(L, 1, N) {\n    for (auto&\
    \ v: S) {\n      if (dp_v.back()[v] != F(0)) return {1 + L, v};\n    }\n    vv(F,\
    \ newdp_e, 1 << K, M);\n    vv(F, newdp_v, 1 << K, N);\n    FOR(s, 1 << K) {\n\
    \      FOR(m, M) {\n        auto [a, b, c] = edges[m];\n        int t = s | get[b];\n\
    \        if (get[b] && s == t) continue;\n        F x = (dp_v[s][a] + dp_e[s][m\
    \ ^ 1]) * c;\n        newdp_e[t][m] += x, newdp_v[t][b] += x;\n      }\n    }\n\
    \    swap(dp_v, newdp_v), swap(dp_e, newdp_e);\n  }\n  return {-1, -1};\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"random/base.hpp\"\n#include \"nt/GF2.hpp\"\
    \n\n// (s,t) path \u3067\u3042\u3063\u3066 need \u3092\u3059\u3079\u3066\u901A\
    \u308B\u3082\u306E\u306E\u6700\u5C0F\u9577\u3055\u3092\u6C42\u3081\u308B.\n//\
    \ s=t \u3067\u3082\u3088\u3044. \u6700\u521D\u306E 1 \u6B69\u76EE\u3082\u6C42\u3081\
    \u308B.\n// {length, first v}. \u306A\u3051\u308C\u3070 {-1,-1}.\n// O(2^K(N+M)L),\
    \ L = shortest path length\ntemplate <typename GT>\npair<int, int> find_path_through_specified(GT&\
    \ G, int s, int t, vc<int> need) {\n  static_assert(!GT::is_directed);\n  int\
    \ N = G.N;\n  assert(0 <= s && s < N && 0 <= t && t < N);\n  using F = GF2<64>;\n\
    \  // frm, to, wt\n  vc<tuple<int, int, F>> edges;\n  vc<int> S, T;\n  for (auto&\
    \ e: G.edges) {\n    int a = e.frm, b = e.to;\n    if ((a == s && b == t) || (a\
    \ == t && b == s)) {\n      if (need.empty()) return {1, t};\n      continue;\n\
    \    }\n    if (a == s || b == s) { S.eb(a ^ b ^ s); }\n    if (a == t || b ==\
    \ t) { T.eb(a ^ b ^ t); }\n    if (a != s && a != t && b != s && b != t) {\n \
    \     F x = RNG_64();\n      edges.eb(a, b, x), edges.eb(b, a, x);\n    }\n  }\n\
    \  int K = len(need);\n  vc<int> get(N);\n  FOR(k, K) get[need[k]] = 1 << k;\n\
    \  int M = len(edges);\n\n  vv(F, dp_e, 1 << K, M);\n  vv(F, dp_v, 1 << K, N);\n\
    \  for (auto& v: T) dp_v[get[v]][v] = RNG_64();\n  FOR(L, 1, N) {\n    for (auto&\
    \ v: S) {\n      if (dp_v.back()[v] != F(0)) return {1 + L, v};\n    }\n    vv(F,\
    \ newdp_e, 1 << K, M);\n    vv(F, newdp_v, 1 << K, N);\n    FOR(s, 1 << K) {\n\
    \      FOR(m, M) {\n        auto [a, b, c] = edges[m];\n        int t = s | get[b];\n\
    \        if (get[b] && s == t) continue;\n        F x = (dp_v[s][a] + dp_e[s][m\
    \ ^ 1]) * c;\n        newdp_e[t][m] += x, newdp_v[t][b] += x;\n      }\n    }\n\
    \    swap(dp_v, newdp_v), swap(dp_e, newdp_e);\n  }\n  return {-1, -1};\n}"
  dependsOn:
  - graph/base.hpp
  - random/base.hpp
  - nt/GF2.hpp
  isVerificationFile: false
  path: graph/find_path_through_specified.hpp
  requiredBy: []
  timestamp: '2024-10-18 02:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1776.test.cpp
  - test/3_yukicoder/1775.test.cpp
documentation_of: graph/find_path_through_specified.hpp
layout: document
redirect_from:
- /library/graph/find_path_through_specified.hpp
- /library/graph/find_path_through_specified.hpp.html
title: graph/find_path_through_specified.hpp
---
