---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/ds/range_edge_connected_component_query.hpp
    title: graph/ds/range_edge_connected_component_query.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
    title: test/2_library_checker/tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/2_library_checker/tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2295.test.cpp
    title: test/3_yukicoder/2295.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2296.test.cpp
    title: test/3_yukicoder/2296.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/772.test.cpp
    title: test/3_yukicoder/772.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/902.test.cpp
    title: test/3_yukicoder/902.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc350_g.test.cpp
    title: test/5_atcoder/abc350_g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ds/link_cut_tree.hpp\"\n/*\n\u5404 heavy path \u3092\
    \ head \u304C\u5DE6, tail \u304C\u53F3\u3068\u306A\u308B\u3088\u3046\u306B splay\
    \ tree \u3067\u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\u304C\u76F4\u63A5\u547C\u3076\
    \u53EF\u80FD\u6027\u304C\u3042\u308B\u3082\u306E\u3060\u3051 int \u3067\u3082\u5B9F\
    \u88C5.\nLCT \u5916\u3067\u63A2\u7D22\u3059\u308B\u3068\u304D\u306A\u3069\uFF0C\
    push \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F.\n*/\n\ntemplate\
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
    \ n) return -1;\n    return 0;\n  }\n};\n"
  code: "/*\n\u5404 heavy path \u3092 head \u304C\u5DE6, tail \u304C\u53F3\u3068\u306A\
    \u308B\u3088\u3046\u306B splay tree \u3067\u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\
    \u304C\u76F4\u63A5\u547C\u3076\u53EF\u80FD\u6027\u304C\u3042\u308B\u3082\u306E\
    \u3060\u3051 int \u3067\u3082\u5B9F\u88C5.\nLCT \u5916\u3067\u63A2\u7D22\u3059\
    \u308B\u3068\u304D\u306A\u3069\uFF0Cpush \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\
    \u306B\u6CE8\u610F.\n*/\n\ntemplate <typename Node>\nstruct Link_Cut_Tree {\n\
    \  using np = Node *;\n  int n;\n  vc<Node> nodes;\n\n  Link_Cut_Tree(int n =\
    \ 0) : n(n), nodes(n) { FOR(i, n) nodes[i] = Node(i); }\n\n  Node *operator[](int\
    \ v) { return &nodes[v]; }\n\n  // underlying tree \u306E\u6839\n  Node *get_root(Node\
    \ *c) {\n    expose(c);\n    c->push();\n    while (c->l) {\n      c = c->l;\n\
    \      c->push();\n    }\n    splay(c);\n    return c;\n  }\n\n  // underlying\
    \ tree \u306E\u6839\n  int get_root(int c) { return get_root(&nodes[c])->idx;\
    \ }\n\n  // parent(c)==p \u3068\u306A\u308B\u3088\u3046\u306B link.\n  void link(Node\
    \ *c, Node *p) {\n    evert(c);\n    expose(p);\n    p->push();\n    // no edge\
    \ -> heavy edge\n    assert(!(c->p));\n    assert(!(p->r));\n    c->p = p;\n \
    \   p->r = c;\n    p->update();\n  }\n\n  // parent(c)==p \u3068\u306A\u308B\u3088\
    \u3046\u306B link.\n  void link(int c, int p) { return link(&nodes[c], &nodes[p]);\
    \ }\n\n  void cut(Node *a, Node *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n\
    \    assert((b->l) == a);\n    // heavy edge -> no edge\n    b->l->p = nullptr;\n\
    \    b->l = nullptr;\n    b->update();\n  }\n\n  void cut(int a, int b) { return\
    \ cut(&nodes[a], &nodes[b]); }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\
    \u3059\u308B.\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n\
    \  // c \u306F push \u6E08\u306B\u306A\u308B\n  void evert(Node *c) {\n    expose(c);\n\
    \    c->reverse();\n    c->push();\n  }\n\n  // c \u3092 underlying tree \u306E\
    \u6839\u3068\u3059\u308B.\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\
    \u308B.\n  void evert(int c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node\
    \ *v) {\n    assert(get_root(u) == get_root(v));\n    expose(u);\n    return expose(v);\n\
    \  }\n\n  int lca(int u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n\
    \  // \u8FBA\u306E\u500B\u6570\n  int dist(int u, int v) {\n    evert(u), expose(v);\n\
    \    return ((*this)[v]->size) - 1;\n  }\n\n  Node *jump(Node *u, Node *v, int\
    \ k) {\n    evert(v);\n    expose(u);\n    assert(0 <= k && k < (u->size));\n\
    \    while (1) {\n      u->push();\n      int rs = (u->r ? u->r->size : 0);\n\
    \      if (k < rs) {\n        u = u->r;\n        continue;\n      }\n      if\
    \ (k == rs) { break; }\n      k -= rs + 1;\n      u = u->l;\n    }\n    splay(u);\n\
    \    return u;\n  }\n\n  int jump(int u, int v, int k) {\n    auto c = jump((*this)[u],\
    \ (*this)[v], k);\n    return c->idx;\n  }\n\n  // [root, c] \u304C\u3072\u3068\
    \u3064\u306E splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\
    \u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\u3044\u3046\
    \u72B6\u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\u72B6\u614B\
    \u3067 c \u306E data \u3092\u898B\u308B.\n  // c \u306F push \u6E08\u306B\u306A\
    \u308B\n  virtual Node *expose(Node *c) {\n    Node *now = c;\n    Node *rp =\
    \ nullptr; // \u4ECA\u307E\u3067\u4F5C\u3063\u305F\u30D1\u30B9\n    while (now)\
    \ {\n      splay(now);\n      // heavy -> light, light -> heavy.\n      if (now->r)\
    \ { now->add_light(now->r); }\n      if (rp) { now->erase_light(rp); }\n     \
    \ now->r = rp;\n      now->update();\n      rp = now;\n      now = now->p;\n \
    \   }\n    splay(c);\n    return rp;\n  }\n\n  // [root, c] \u304C\u3072\u3068\
    \u3064\u306E splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\
    \u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\u3044\u3046\
    \u72B6\u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\u72B6\u614B\
    \u3067 c \u306E data \u3092\u898B\u308B.\n  int expose(int c) {\n    Node *x =\
    \ expose(&nodes[c]);\n    if (!x) return -1;\n    return x->idx;\n  }\n\n  Node\
    \ *get_parent(Node *x) {\n    expose(x);\n    x->push();\n    if (!x->l) return\
    \ nullptr;\n    x = x->l, x->push();\n    while (x->r) x = x->r, x->push();\n\
    \    return x;\n  }\n\n  int get_parent(int x) {\n    Node *p = get_parent((*this)[x]);\n\
    \    return (p ? p->idx : -1);\n  }\n\n  void set(Node *c, typename Node::VX x)\
    \ {\n    evert(c);\n    c->set(x);\n  }\n\n  void set(int c, typename Node::VX\
    \ x) { set((*this)[c], x); }\n\n  typename Node::X prod_path(int a, int b) {\n\
    \    evert(a), expose(b);\n    return (*this)[b]->x;\n  }\n\n  // subtree \u7528\
    \u306E node \u3092\u4F7F\u3046\n  typename Node::X prod_subtree(int v, int root)\
    \ {\n    static_assert(Node::NODE_FOR_SUBTREE);\n    if (v == root) {\n      evert(root);\n\
    \      return (*this)[root]->x;\n    }\n    root = jump(v, root, 1);\n    cut(v,\
    \ root);\n    typename Node::X res = (*this)[v]->x;\n    link(v, root);\n    return\
    \ res;\n  }\n\n  vc<int> collect_heavy_path(int v) {\n    np c = (*this)[v];\n\
    \    while (!is_root(c)) c = c->p;\n    vc<int> res;\n    auto dfs = [&](auto\
    \ &dfs, np c, bool rev) -> void {\n      if (!rev) {\n        if (c->l) dfs(dfs,\
    \ c->l, rev ^ c->rev);\n        res.eb(c->idx);\n        if (c->r) dfs(dfs, c->r,\
    \ rev ^ c->rev);\n      } else {\n        if (c->r) dfs(dfs, c->r, rev ^ c->rev);\n\
    \        res.eb(c->idx);\n        if (c->l) dfs(dfs, c->l, rev ^ c->rev);\n  \
    \    }\n    };\n    dfs(dfs, c, false);\n    return res;\n  }\n\n  void debug()\
    \ {\n    print(\"p, l, r, rev\");\n    auto f = [&](np c) -> int { return (c ?\
    \ c->idx : -1); };\n    FOR(i, len(nodes)) { print(i, \",\", f((*this)[i]->p),\
    \ f((*this)[i]->l), f((*this)[i]->r), (*this)[i]->rev); }\n    FOR(i, len(nodes))\
    \ {\n      np c = (*this)[i];\n      if (c->l) assert(c->l->p == c);\n      if\
    \ (c->r) assert(c->r->p == c);\n    }\n  }\n\nprivate:\n  // splay tree \u5185\
    \u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light \u69CB\u9020\
    \u306F\u5909\u308F\u3089\u306A\u3044.\n  // light pointer \u306F rotate \u5185\
    \u3067\u30B1\u30A2\n  // c \u306F push \u6E08\u306B\u306A\u308B\n  void splay(Node\
    \ *c) {\n    c->push();\n    while (!is_root(c)) {\n      Node *p = c->p;\n  \
    \    Node *pp = (p ? p->p : nullptr);\n      if (state(p) == 0) {\n        p->push(),\
    \ c->push();\n        rotate(c);\n      }\n      elif (state(c) == state(p)) {\n\
    \        pp->push(), p->push(), c->push();\n        rotate(p);\n        rotate(c);\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n      }\n    }\n  }\n\n  // \u30D1\u30B9\u3092\u8868\u3059\
    \ splay tree \u306E\u6839\u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3069\u3046\
    \u304B\n  // underlying tree \u3067\u306F\u306A\u3044\n  bool is_root(Node *c)\
    \ { return state(c) == 0; }\n\n  // splay tree \u5185\u3067\u5B8C\u7D50\u3059\u308B\
    \u64CD\u4F5C. \u7279\u306B heavy, light \u69CB\u9020\u306F\u5909\u308F\u3089\u306A\
    \u3044.\n  // light edge \u306E\u30DD\u30A4\u30F3\u30BF\u306F\u5909\u66F4\u3055\
    \u308C\u3046\u308B\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\
    \u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n   \
    \ if (p->l == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else\
    \ {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n    p->update(),\
    \ n->update();\n\n    if (pp) {\n      if (pp->l == p) pp->l = n;\n      elif\
    \ (pp->r == p) pp->r = n;\n      else {\n        // light edge pointer \u304C\
    \ (pp-p) \u304B\u3089 (pp-n) \u306B\u5909\u308F\u308B\n        pp->change_light(p,\
    \ n);\n      }\n    }\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n \
    \ }\n\n  inline int state(Node *n) {\n    if (!n->p) return 0;\n    if (n->p->l\
    \ == n) return 1;\n    if (n->p->r == n) return -1;\n    return 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/link_cut_tree.hpp
  requiredBy:
  - graph/ds/range_edge_connected_component_query.hpp
  timestamp: '2024-08-14 01:37:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - test/2_library_checker/tree/dynamic_tree_vertex_add_path_sum.test.cpp
  - test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
  - test/2_library_checker/tree/dynamic_tree_subtree_add_subtree_sum.test.cpp
  - test/3_yukicoder/2295.test.cpp
  - test/3_yukicoder/772.test.cpp
  - test/3_yukicoder/2296.test.cpp
  - test/3_yukicoder/902.test.cpp
  - test/5_atcoder/abc350_g.test.cpp
documentation_of: graph/ds/link_cut_tree.hpp
layout: document
redirect_from:
- /library/graph/ds/link_cut_tree.hpp
- /library/graph/ds/link_cut_tree.hpp.html
title: graph/ds/link_cut_tree.hpp
---
