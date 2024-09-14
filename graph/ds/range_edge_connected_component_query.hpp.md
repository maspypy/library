---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/lct_node_commutative_monoid.hpp
    title: graph/ds/lct_node_commutative_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut_tree.hpp
    title: graph/ds/link_cut_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1386/C
  bundledCode: "#line 1 \"graph/ds/range_edge_connected_component_query.hpp\"\n\n\
    #line 1 \"graph/ds/link_cut_tree.hpp\"\n/*\n\u5404 heavy path \u3092 head \u304C\
    \u5DE6, tail \u304C\u53F3\u3068\u306A\u308B\u3088\u3046\u306B splay tree \u3067\
    \u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\u304C\u76F4\u63A5\u547C\u3076\u53EF\u80FD\
    \u6027\u304C\u3042\u308B\u3082\u306E\u3060\u3051 int \u3067\u3082\u5B9F\u88C5\
    .\nLCT \u5916\u3067\u63A2\u7D22\u3059\u308B\u3068\u304D\u306A\u3069\uFF0Cpush\
    \ \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F.\n*/\n\ntemplate\
    \ <typename Node>\nstruct Link_Cut_Tree {\n  using np = Node *;\n  int n;\n  vc<Node>\
    \ nodes;\n\n  Link_Cut_Tree(int n = 0) : n(n), nodes(n) { FOR(i, n) nodes[i] =\
    \ Node(i); }\n\n  Node *operator[](int v) { return &nodes[v]; }\n\n  // underlying\
    \ tree \u306E\u6839\n  Node *get_root(Node *c) {\n    expose(c);\n    c->push();\n\
    \    while (c->l) {\n      c = c->l;\n      c->push();\n    }\n    splay(c);\n\
    \    return c;\n  }\n\n  // underlying tree \u306E\u6839\n  int get_root(int c)\
    \ { return get_root(&nodes[c])->idx; }\n\n  // parent(c)==p \u3068\u306A\u308B\
    \u3088\u3046\u306B link.\n  void link(Node *c, Node *p) {\n    evert(c);\n   \
    \ expose(p);\n    p->push();\n    // no edge -> heavy edge\n    assert(!(c->p));\n\
    \    assert(!(p->r));\n    c->p = p;\n    p->r = c;\n    p->update();\n  }\n\n\
    \  // parent(c)==p \u3068\u306A\u308B\u3088\u3046\u306B link.\n  void link(int\
    \ c, int p) { return link(&nodes[c], &nodes[p]); }\n\n  void cut(Node *a, Node\
    \ *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l)\
    \ == a);\n    // heavy edge -> no edge\n    b->l->p = nullptr;\n    b->l = nullptr;\n\
    \    b->update();\n  }\n\n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]);\
    \ }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B.\n  // c \u306F\
    \ splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  // c \u306F push \u6E08\u306B\
    \u306A\u308B\n  void evert(Node *c) {\n    expose(c);\n    c->reverse();\n   \
    \ c->push();\n  }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B\
    .\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  void evert(int\
    \ c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node *v) {\n    assert(get_root(u)\
    \ == get_root(v));\n    expose(u);\n    return expose(v);\n  }\n\n  int lca(int\
    \ u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n  // \u8FBA\u306E\u500B\
    \u6570\n  int dist(int u, int v) {\n    evert(u), expose(v);\n    return ((*this)[v]->size)\
    \ - 1;\n  }\n\n  Node *jump(Node *u, Node *v, int k) {\n    evert(v);\n    expose(u);\n\
    \    assert(0 <= k && k < (u->size));\n    while (1) {\n      u->push();\n   \
    \   int rs = (u->r ? u->r->size : 0);\n      if (k < rs) {\n        u = u->r;\n\
    \        continue;\n      }\n      if (k == rs) { break; }\n      k -= rs + 1;\n\
    \      u = u->l;\n    }\n    splay(u);\n    return u;\n  }\n\n  int jump(int u,\
    \ int v, int k) {\n    auto c = jump((*this)[u], (*this)[v], k);\n    return c->idx;\n\
    \  }\n\n  // [root, c] \u304C\u3072\u3068\u3064\u306E splay tree \u306B\u306A\u308B\
    \u3088\u3046\u306B\u5909\u66F4\u3059\u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay\
    \ tree \u306E\u6839\u3068\u3044\u3046\u72B6\u614B\u306B\u306A\u308B.\n  // path\
    \ query \u306F\u3053\u306E\u72B6\u614B\u3067 c \u306E data \u3092\u898B\u308B\
    .\n  // c \u306F push \u6E08\u306B\u306A\u308B\n  virtual Node *expose(Node *c)\
    \ {\n    Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\u3063\
    \u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      // heavy -> light,\
    \ light -> heavy.\n      if (now->r) { now->add_light(now->r); }\n      if (rp)\
    \ { now->erase_light(rp); }\n      now->r = rp;\n      now->update();\n      rp\
    \ = now;\n      now = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n \
    \ // [root, c] \u304C\u3072\u3068\u3064\u306E splay tree \u306B\u306A\u308B\u3088\
    \u3046\u306B\u5909\u66F4\u3059\u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree\
    \ \u306E\u6839\u3068\u3044\u3046\u72B6\u614B\u306B\u306A\u308B.\n  // path query\
    \ \u306F\u3053\u306E\u72B6\u614B\u3067 c \u306E data \u3092\u898B\u308B.\n  int\
    \ expose(int c) {\n    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n\
    \    return x->idx;\n  }\n\n  Node *get_parent(Node *x) {\n    expose(x);\n  \
    \  x->push();\n    if (!x->l) return nullptr;\n    x = x->l, x->push();\n    while\
    \ (x->r) x = x->r, x->push();\n    return x;\n  }\n\n  int get_parent(int x) {\n\
    \    Node *p = get_parent((*this)[x]);\n    return (p ? p->idx : -1);\n  }\n\n\
    \  void set(Node *c, typename Node::VX x) {\n    evert(c);\n    c->set(x);\n \
    \ }\n\n  void set(int c, typename Node::VX x) { set((*this)[c], x); }\n\n  typename\
    \ Node::X prod_path(int a, int b) {\n    evert(a), expose(b);\n    return (*this)[b]->x;\n\
    \  }\n\n  // subtree \u7528\u306E node \u3092\u4F7F\u3046\n  typename Node::X\
    \ prod_subtree(int v, int root) {\n    static_assert(Node::NODE_FOR_SUBTREE);\n\
    \    if (v == root) {\n      evert(root);\n      return (*this)[root]->x;\n  \
    \  }\n    root = jump(v, root, 1);\n    cut(v, root);\n    typename Node::X res\
    \ = (*this)[v]->x;\n    link(v, root);\n    return res;\n  }\n\n  vc<int> collect_heavy_path(int\
    \ v) {\n    np c = (*this)[v];\n    while (!is_root(c)) c = c->p;\n    vc<int>\
    \ res;\n    auto dfs = [&](auto &dfs, np c, bool rev) -> void {\n      if (!rev)\
    \ {\n        if (c->l) dfs(dfs, c->l, rev ^ c->rev);\n        res.eb(c->idx);\n\
    \        if (c->r) dfs(dfs, c->r, rev ^ c->rev);\n      } else {\n        if (c->r)\
    \ dfs(dfs, c->r, rev ^ c->rev);\n        res.eb(c->idx);\n        if (c->l) dfs(dfs,\
    \ c->l, rev ^ c->rev);\n      }\n    };\n    dfs(dfs, c, false);\n    return res;\n\
    \  }\n\n  void debug() {\n    print(\"p, l, r, rev\");\n    auto f = [&](np c)\
    \ -> int { return (c ? c->idx : -1); };\n    FOR(i, len(nodes)) { print(i, \"\
    ,\", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r), (*this)[i]->rev); }\n\
    \    FOR(i, len(nodes)) {\n      np c = (*this)[i];\n      if (c->l) assert(c->l->p\
    \ == c);\n      if (c->r) assert(c->r->p == c);\n    }\n  }\n\nprivate:\n  //\
    \ splay tree \u5185\u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy,\
    \ light \u69CB\u9020\u306F\u5909\u308F\u3089\u306A\u3044.\n  // light pointer\
    \ \u306F rotate \u5185\u3067\u30B1\u30A2\n  // c \u306F push \u6E08\u306B\u306A\
    \u308B\n  void splay(Node *c) {\n    c->push();\n    while (!is_root(c)) {\n \
    \     Node *p = c->p;\n      Node *pp = (p ? p->p : nullptr);\n      if (state(p)\
    \ == 0) {\n        p->push(), c->push();\n        rotate(c);\n      }\n      elif\
    \ (state(c) == state(p)) {\n        pp->push(), p->push(), c->push();\n      \
    \  rotate(p);\n        rotate(c);\n      }\n      else {\n        pp->push(),\
    \ p->push(), c->push();\n        rotate(c);\n        rotate(c);\n      }\n   \
    \ }\n  }\n\n  // \u30D1\u30B9\u3092\u8868\u3059 splay tree \u306E\u6839\u306B\u306A\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n  // underlying tree \u3067\u306F\
    \u306A\u3044\n  bool is_root(Node *c) { return state(c) == 0; }\n\n  // splay\
    \ tree \u5185\u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light\
    \ \u69CB\u9020\u306F\u5909\u308F\u3089\u306A\u3044.\n  // light edge \u306E\u30DD\
    \u30A4\u30F3\u30BF\u306F\u5909\u66F4\u3055\u308C\u3046\u308B\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\n    Node *pp, *p,\
    \ *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n\
    \      n->r = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l =\
    \ p;\n      p->r = c;\n    }\n    p->update(), n->update();\n\n    if (pp) {\n\
    \      if (pp->l == p) pp->l = n;\n      elif (pp->r == p) pp->r = n;\n      else\
    \ {\n        // light edge pointer \u304C (pp-p) \u304B\u3089 (pp-n) \u306B\u5909\
    \u308F\u308B\n        pp->change_light(p, n);\n      }\n    }\n    n->p = pp;\n\
    \    p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n \
    \   if (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r ==\
    \ n) return -1;\n    return 0;\n  }\n};\n#line 1 \"graph/ds/lct_node_commutative_monoid.hpp\"\
    \n\n// SUBTREE : cluster \u304C subtree \u60C5\u5831\u3092\u6301\u3064\u5834\u5408\
    \ntemplate <typename Monoid, bool SUBTREE = false>\nstruct LCT_Node_Commutative_Monoid\
    \ {\n  static_assert(Monoid::commute);\n  static constexpr bool NODE_FOR_SUBTREE\
    \ = SUBTREE;\n  using np = LCT_Node_Commutative_Monoid *;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\
    \u3059\u308B.\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ VX = X;\n  X x, vx, mid;\n\n  LCT_Node_Commutative_Monoid(int i = 0)\n     \
    \ : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        idx(i),\n \
    \       size(1),\n        rev(0),\n        x(MX::unit()),\n        vx(MX::unit()),\n\
    \        mid(MX::unit()) {}\n\n  void update() {\n    size = 1;\n    x = vx;\n\
    \    if constexpr (SUBTREE) x = MX::op(x, mid);\n    if (l) { size += l->size,\
    \ x = Monoid::op(l->x, x); }\n    if (r) { size += r->size, x = Monoid::op(x,\
    \ r->x); }\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n\
    \      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  // data \u306E reverse\
    \ \u3082\u884C\u3046\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\
    \n  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, c->x);\n  }\n  void erase_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, MX::inverse(c->x));\n  }\n\
    \n  // b->x \u306B subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void\
    \ change_light(np a, np b) {}\n};\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename\
    \ T = int, bool directed = false>\nstruct Graph {\n  static constexpr bool is_directed\
    \ = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n\
    \  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n\
    \  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges\
    \ {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l),\
    \ r(r) {}\n\n    const edge_type* begin() const {\n      if (l == r) { return\
    \ 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type* end() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n\
    \  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
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
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return max_right([&k](E x) ->\
    \ bool { return x <= k; }, L);\n  }\n};\n#line 4 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\nstruct FenwickTree_01 {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n\
    \    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }\n    bit.build(n, [&](int\
    \ i) -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return bit.sum_all();\
    \ }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int k) {\n \
    \   int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k / 64] & ((u64(1) << (k\
    \ % 64)) - 1));\n    return ans;\n  }\n  int sum(int L, int R) {\n    if (L ==\
    \ 0) return prefix_sum(R);\n    int ans = 0;\n    ans -= popcnt(dat[L / 64] &\
    \ ((u64(1) << (L % 64)) - 1));\n    ans += popcnt(dat[R / 64] & ((u64(1) << (R\
    \ % 64)) - 1));\n    ans += bit.sum(L / 64, R / 64);\n    return ans;\n  }\n\n\
    \  void add(int k, int x) {\n    if (x == 1) add(k);\n    if (x == -1) remove(k);\n\
    \  }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k\
    \ / 64, 1);\n  }\n  void remove(int k) {\n    dat[k / 64] &= ~(u64(1) << (k %\
    \ 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int k, int L = 0) {\n    if\
    \ (k >= sum_all()) return N;\n    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64))\
    \ - 1));\n    L /= 64;\n    int mid = 0;\n    auto check = [&](auto e) -> bool\
    \ {\n      if (e <= k) chmax(mid, e);\n      return e <= k;\n    };\n    int idx\
    \ = bit.max_right(check, L);\n    if (idx == n) return N;\n    k -= mid;\n   \
    \ u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p <= k) return N;\n    k\
    \ = binary_search([&](int n) -> bool { return (p - popcnt(x >> n)) <= k; },\n\
    \                      0, 64, 0);\n    return 64 * idx + k;\n  }\n\n  int next(int\
    \ k) {\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx] & ~((u64(1)\
    \ << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx\
    \ + 1);\n    if (idx == n || !dat[idx]) return N;\n    return 64 * idx + lowbit(dat[idx]);\n\
    \  }\n\n  int prev(int k) {\n    if (k == N) --k;\n    int idx = k / 64;\n   \
    \ k %= 64;\n    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1)) -\
    \ 1;\n    if (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto\
    \ e) -> bool { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n  \
    \  return 64 * idx + topbit(dat[idx]);\n  }\n};\n#line 7 \"graph/ds/range_edge_connected_component_query.hpp\"\
    \n\n// https://codeforces.com/problemset/problem/1386/C (TLE)\n// query(L,R) =\
    \ # of component if edge L,...,R-1 are used.\nstruct Range_Edge_Conneced_Component_Query\
    \ {\n  Graph<int, 0>& G;\n  vc<pair<int, int>> query;\n\n  Range_Edge_Conneced_Component_Query(Graph<int,\
    \ 0>& G) : G(G) {}\n\n  void add_query(int l, int r) { query.eb(l, r); }\n\n \
    \ using Mono = Monoid_Min<int>;\n  using Node = LCT_Node_Commutative_Monoid<Mono>;\n\
    \n  vc<int> calc() {\n    int N = G.N, M = G.M;\n    Link_Cut_Tree<Node> LCT(N\
    \ + M);\n    int Q = len(query);\n    vc<int> ANS(Q);\n    vvc<int> QID(M);\n\
    \    FOR(q, Q) {\n      auto [l, r] = query[q];\n      assert(0 <= l && l <= r\
    \ && r <= M);\n      if (r) QID[r - 1].eb(q);\n    }\n\n    FenwickTree_01 bit(M);\n\
    \    FOR(i, M) {\n      int a = G.edges[i].frm, b = G.edges[i].to;\n      if (a\
    \ != b && LCT.get_root(a) == LCT.get_root(b)) {\n        int k = LCT.prod_path(a,\
    \ b);\n        int c = G.edges[k].frm, d = G.edges[k].to;\n        bit.add(k,\
    \ -1);\n        LCT.cut(c, N + k), LCT.cut(d, N + k);\n      }\n      if (a !=\
    \ b) {\n        LCT.set(N + i, i);\n        LCT.link(a, N + i), LCT.link(b, N\
    \ + i);\n        bit.add(i, 1);\n      }\n      for (auto& q: QID[i]) {\n    \
    \    auto [l, r] = query[q];\n        ANS[q] = N - bit.sum(l, r);\n      }\n \
    \   }\n    return ANS;\n  }\n};\n"
  code: "\n#include \"graph/ds/link_cut_tree.hpp\"\n#include \"graph/ds/lct_node_commutative_monoid.hpp\"\
    \n#include \"alg/monoid/min.hpp\"\n#include \"graph/base.hpp\"\n#include \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\n// https://codeforces.com/problemset/problem/1386/C (TLE)\n// query(L,R) =\
    \ # of component if edge L,...,R-1 are used.\nstruct Range_Edge_Conneced_Component_Query\
    \ {\n  Graph<int, 0>& G;\n  vc<pair<int, int>> query;\n\n  Range_Edge_Conneced_Component_Query(Graph<int,\
    \ 0>& G) : G(G) {}\n\n  void add_query(int l, int r) { query.eb(l, r); }\n\n \
    \ using Mono = Monoid_Min<int>;\n  using Node = LCT_Node_Commutative_Monoid<Mono>;\n\
    \n  vc<int> calc() {\n    int N = G.N, M = G.M;\n    Link_Cut_Tree<Node> LCT(N\
    \ + M);\n    int Q = len(query);\n    vc<int> ANS(Q);\n    vvc<int> QID(M);\n\
    \    FOR(q, Q) {\n      auto [l, r] = query[q];\n      assert(0 <= l && l <= r\
    \ && r <= M);\n      if (r) QID[r - 1].eb(q);\n    }\n\n    FenwickTree_01 bit(M);\n\
    \    FOR(i, M) {\n      int a = G.edges[i].frm, b = G.edges[i].to;\n      if (a\
    \ != b && LCT.get_root(a) == LCT.get_root(b)) {\n        int k = LCT.prod_path(a,\
    \ b);\n        int c = G.edges[k].frm, d = G.edges[k].to;\n        bit.add(k,\
    \ -1);\n        LCT.cut(c, N + k), LCT.cut(d, N + k);\n      }\n      if (a !=\
    \ b) {\n        LCT.set(N + i, i);\n        LCT.link(a, N + i), LCT.link(b, N\
    \ + i);\n        bit.add(i, 1);\n      }\n      for (auto& q: QID[i]) {\n    \
    \    auto [l, r] = query[q];\n        ANS[q] = N - bit.sum(l, r);\n      }\n \
    \   }\n    return ANS;\n  }\n};"
  dependsOn:
  - graph/ds/link_cut_tree.hpp
  - graph/ds/lct_node_commutative_monoid.hpp
  - alg/monoid/min.hpp
  - graph/base.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: graph/ds/range_edge_connected_component_query.hpp
  requiredBy: []
  timestamp: '2024-08-14 01:37:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/range_edge_connected_component_query.hpp
layout: document
redirect_from:
- /library/graph/ds/range_edge_connected_component_query.hpp
- /library/graph/ds/range_edge_connected_component_query.hpp.html
title: graph/ds/range_edge_connected_component_query.hpp
---
