---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared && 0 <= frm && 0 <= to && to <\
    \ N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    FOR_(M) {\n      INT(a, b);\n      a -= off,\
    \ b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n\
    \        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n\
    \  void read_parent(int off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n     \
    \ p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n  void build() {\n\
    \    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 1 \"my_template.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n#define FOR_(n) for (ll _ = 0; (_) < (ll)(n);\
    \ ++(_))\n#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))\n#define FOR3(i,\
    \ m, n) for (ll i = (m); (i) < (ll)(n); ++(i))\n#define FOR_R(i, n) for (ll i\
    \ = (ll)(n)-1; (i) >= 0; --(i))\n#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1;\
    \ (i) >= (ll)(m); --(i))\n#define FOR_subset(t, s) for (ll t = s; t >= 0; t =\
    \ (t == 0 ? -1 : (t - 1) & s))\n#define all(x) x.begin(), x.end()\n#define len(x)\
    \ ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define fi first\n#define se second\n\n#define stoi stoll\n\
    \ntemplate <typename T>\nT SUM(vector<T> &A) {\n  T sum = T(0);\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x\
    \ == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename U>\nT ceil(T x, U\
    \ y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T,\
    \ typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n\
    }\n\ntemplate <typename T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q =\
    \ floor(x, y);\n  return {q, x - q * y};\n}\n\nll binary_search(function<bool(ll)>\
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    if (check(x))\n      ok = x;\n    else\n   \
    \   ng = x;\n  }\n  return ok;\n}\n\ntemplate <class T, class S>\ninline bool\
    \ chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b,\
    \ 1 : 0);\n}\n\nvi s_to_vi(const string& S, char first_char) {\n  vi A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T>\nvector<T> cumsum(vector<T> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  // stable\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(A);\n  assert(len(I) == n);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n\
    \  return B;\n}\n#line 4 \"graph/bipartite_coloring.hpp\"\n\npair<int, vi> bipartite_edge_coloring(Graph<ll>&\
    \ G) {\n  auto N = G.N;\n  vi deg(N);\n  vi ANS(G.M, -1);\n  FORIN(e, G.edges)\
    \ {\n    ++deg[e.frm];\n    ++deg[e.to];\n  }\n  ll C = MAX(deg);\n  // \u9802\
    \u70B9, \u8272 -> \u8FBA\u756A\u53F7\n  vv(int, TO, N, C, -1);\n\n  FOR(id, G.M)\
    \ {\n    auto const a = G.edges[id].frm, b = G.edges[id].to;\n    [&] {\n    \
    \  // a \u3067\u5B9F\u73FE\u3057\u3066\u3044\u306A\u3044\u8272 ca \u3068 b \u3067\
    \u5B9F\u73FE\u3057\u3066\u3044\u306A\u3044\u8272 cb \u3092\u3072\u3068\u3064\u3068\
    \u308B\u3002\n      int ca = -1, cb = -1;\n      FOR(c, C) if (TO[a][c] == -1)\
    \ {\n        ca = c;\n        break;\n      }\n      FOR(c, C) if (TO[b][c] ==\
    \ -1) {\n        cb = c;\n        break;\n      }\n      int v = a, w = b, eid\
    \ = id, cv = ca, cw = cb;\n      while (1) {\n        ANS[eid] = cv;\n       \
    \ TO[v][cv] = eid;\n        TO[w][cw] = -1;\n        if (TO[w][cv] == -1) {\n\
    \          TO[w][cv] = eid;\n          break;\n        }\n        swap(eid, TO[w][cv]);\n\
    \        auto const& e = G.edges[eid];\n        v = w;\n        w ^= e.frm ^ e.to;\n\
    \        swap(cv, cw);\n      }\n    }();\n  }\n  return {C, ANS};\n}\n"
  code: "#pragma once\n#include \"graph/base.hpp\"\n#include \"my_template.hpp\"\n\
    \npair<int, vi> bipartite_edge_coloring(Graph<ll>& G) {\n  auto N = G.N;\n  vi\
    \ deg(N);\n  vi ANS(G.M, -1);\n  FORIN(e, G.edges) {\n    ++deg[e.frm];\n    ++deg[e.to];\n\
    \  }\n  ll C = MAX(deg);\n  // \u9802\u70B9, \u8272 -> \u8FBA\u756A\u53F7\n  vv(int,\
    \ TO, N, C, -1);\n\n  FOR(id, G.M) {\n    auto const a = G.edges[id].frm, b =\
    \ G.edges[id].to;\n    [&] {\n      // a \u3067\u5B9F\u73FE\u3057\u3066\u3044\u306A\
    \u3044\u8272 ca \u3068 b \u3067\u5B9F\u73FE\u3057\u3066\u3044\u306A\u3044\u8272\
    \ cb \u3092\u3072\u3068\u3064\u3068\u308B\u3002\n      int ca = -1, cb = -1;\n\
    \      FOR(c, C) if (TO[a][c] == -1) {\n        ca = c;\n        break;\n    \
    \  }\n      FOR(c, C) if (TO[b][c] == -1) {\n        cb = c;\n        break;\n\
    \      }\n      int v = a, w = b, eid = id, cv = ca, cw = cb;\n      while (1)\
    \ {\n        ANS[eid] = cv;\n        TO[v][cv] = eid;\n        TO[w][cw] = -1;\n\
    \        if (TO[w][cv] == -1) {\n          TO[w][cv] = eid;\n          break;\n\
    \        }\n        swap(eid, TO[w][cv]);\n        auto const& e = G.edges[eid];\n\
    \        v = w;\n        w ^= e.frm ^ e.to;\n        swap(cv, cw);\n      }\n\
    \    }();\n  }\n  return {C, ANS};\n}"
  dependsOn:
  - graph/base.hpp
  - my_template.hpp
  isVerificationFile: false
  path: graph/bipartite_coloring.hpp
  requiredBy: []
  timestamp: '2022-04-29 17:32:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_coloring.hpp
layout: document
redirect_from:
- /library/graph/bipartite_coloring.hpp
- /library/graph/bipartite_coloring.hpp.html
title: graph/bipartite_coloring.hpp
---
