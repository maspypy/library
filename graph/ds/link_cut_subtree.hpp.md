---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/ds/link_cut.hpp
    title: graph/ds/link_cut.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/ds/link_cut.hpp\"\n\ntemplate <typename Node, int\
    \ NODES>\nstruct LinkCutTree_base {\n  int n;\n  Node *nodes;\n\n  LinkCutTree_base(int\
    \ n = 0) : n(n) {\n    nodes = new Node[NODES];\n    FOR(i, n) nodes[i] = Node(i);\n\
    \  }\n\n  Node *operator[](int v) { return &nodes[v]; }\n\n  // \u30D1\u30B9\u3092\
    \u8868\u3059 splay tree \u306E\u6839\u306B\u306A\u3063\u3066\u3044\u308B\u304B\
    \u3069\u3046\u304B\n  bool is_root(Node *c) { return state(c) == 0; }\n  bool\
    \ is_root(int c) { return state(&nodes[c]) == 0; }\n\n  Node *get_root(Node *c)\
    \ {\n    expose(c);\n    while (c->l) {\n      c->push();\n      c = c->l;\n \
    \   }\n    splay(c);\n    return c;\n  }\n\n  int get_root(int c) { return get_root(&nodes[c])->idx;\
    \ }\n\n  // c \u306E\u89AA\u3092 p \u306B\u3059\u308B\u3002\n  virtual void link(Node\
    \ *c, Node *p) {\n    evert(c);\n    expose(p);\n    c->p = p;\n    p->r = c;\n\
    \    p->update();\n  }\n\n  // c \u306E\u89AA\u3092 p \u306B\u3059\u308B\n  virtual\
    \ void link(int c, int p) { return link(&nodes[c], &nodes[p]); }\n\n  void cut(Node\
    \ *a, Node *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l)\
    \ == a);\n    b->l->p = nullptr;\n    b->l = nullptr;\n    b->update();\n  }\n\
    \n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]); }\n\n  void evert(Node\
    \ *c) {\n    expose(c);\n    c->reverse();\n    c->push();\n  }\n\n  void evert(int\
    \ c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node *v) {\n    assert(get_root(u)\
    \ == get_root(v));\n    expose(u);\n    return expose(v);\n  }\n\n  int lca(int\
    \ u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n  // c \u3068\u6839\u307E\
    \u3067\u304C\u7E4B\u304C\u308C\u3066\u3044\u308B\u72B6\u614B\u306B\u5909\u66F4\
    \u3057\u3066\u3001\u6839\u3092 return \u3059\u308B\n  virtual Node *expose(Node\
    \ *c) {\n    Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\
    \u3063\u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      now->r =\
    \ rp; // \u5B50\u65B9\u5411\u306E\u5909\u66F4\n      now->update();\n      rp\
    \ = now;\n      now = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n \
    \ int expose(int c) {\n    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n\
    \    return x->idx;\n  }\n\n  Node *get_parent(Node *x) {\n    expose(x);\n  \
    \  if (!x->l) return nullptr;\n    x = x->l;\n    while (x->r) x = x->r;\n   \
    \ return x;\n  }\n\n  int get_parent(int x) {\n    Node *p = get_parent((*this)[x]);\n\
    \    return (p ? p->idx : -1);\n  }\n\n  void debug() {\n    FOR(i, n) { nodes[i].debug();\
    \ }\n  }\n\n  virtual void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\
    \u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n \
    \   if (p->l == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    }\
    \ else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp\
    \ && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p =\
    \ pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n)\
    \ {\n    if (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r\
    \ == n) return -1;\n    return 0;\n  }\n\n  void splay(Node *c) {\n    c->push();\n\
    \    while (!is_root(c)) {\n      Node *p = c->p;\n      Node *pp = (p ? p->p\
    \ : nullptr);\n      if (state(p) == 0) {\n        p->push(), c->push();\n   \
    \     rotate(c);\n        if (p) p->update();\n      }\n      elif (state(c) ==\
    \ state(p)) {\n        pp->push(), p->push(), c->push();\n        rotate(p);\n\
    \        rotate(c);\n        if (pp) pp->update();\n        if (p) p->update();\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n        if (p) p->update();\n        if (pp) pp->update();\n\
    \      }\n    }\n    c->update();\n  }\n};\n\nstruct LCT_Node_base {\n  LCT_Node_base\
    \ *l, *r, *p;\n  int idx;\n  bool rev;\n  LCT_Node_base(int i = 0) : l(nullptr),\
    \ r(nullptr), p(nullptr), idx(i) {}\n\n  void update() {}\n\n  void push() {\n\
    \    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n    \
    \  rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n\
    \  }\n};\n\ntemplate <int NODES>\nusing LinkCutTree = LinkCutTree_base<LCT_Node_base,\
    \ NODES>;\n#line 2 \"graph/ds/link_cut_subtree.hpp\"\n\ntemplate <typename Node,\
    \ int NODES>\nstruct LinkCutTree_SubTree : LinkCutTree_base<Node, NODES> {\n \
    \ using Base = LinkCutTree_base<Node, NODES>;\n  using MonoX = typename Node::MonoX;\n\
    \  using X = typename Node::X;\n  using MonoA = typename Node::MonoA;\n  using\
    \ A = typename Node::A;\n\n  LinkCutTree_SubTree(int n = 0) : Base(n) {}\n\n \
    \ LinkCutTree_SubTree(vc<X> dat) : Base(len(dat)) {\n    FOR(i, len(dat))(*this)[i]->set(dat[i]);\n\
    \  }\n\n  void set(int i, X x) {\n    Base::expose(i);\n    (*this)[i]->set(x);\n\
    \  }\n\n  void add(int i, X x) {\n    Base::expose(i);\n    (*this)[i]->add(x);\n\
    \  }\n\n  X sum(int v) {\n    int p = Base::get_parent(v);\n    if (p == -1) {\
    \ return (*this)[v]->sum(); }\n    Base::cut(v, p);\n    X x = (*this)[v]->sum();\n\
    \    Base::link(v, p);\n    return x;\n  }\n\n  void link(Node *c, Node *p) override\
    \ {\n    Base::evert(p);\n    expose(c);\n    c->p = p;\n    c->cancel = p->added;\n\
    \    p->r = c;\n    p->update();\n  }\n\n  void link(int c, int p) override {\
    \ return link((*this)[c], (*this)[p]); }\n\n  // c \u3068\u6839\u307E\u3067\u304C\
    \u7E4B\u304C\u308C\u3066\u3044\u308B\u72B6\u614B\u306B\u5909\u66F4\u3057\u3066\
    \u3001\u6839\u3092 return \u3059\u308B\n  Node *expose(Node *c) override {\n \
    \   Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\u3063\u305F\
    \u30D1\u30B9\n    while (now) {\n      Base::splay(now);\n      if (now->r) {\n\
    \        now->r->push();\n        if (now->r) now->add_r(true);\n      }\n   \
    \   now->r = rp;\n      if (now->r) {\n        now->r->push();\n        now->add_r(false);\n\
    \      }\n      now->update();\n      rp = now;\n      now = now->p;\n    }\n\
    \    Base::splay(c);\n    return rp;\n  }\n\n  int expose(int c) {\n    Node *x\
    \ = expose((*this)[c]);\n    if (!x) return -1;\n    return x->idx;\n  }\n\n \
    \ void rotate(Node *n) override {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\
    \u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n    if (p->l ==\
    \ n) {\n      c = n->r;\n      if (c) c->push();\n      n->r = p;\n      p->l\
    \ = c;\n    } else {\n      c = n->l;\n      if (c) c->push();\n      n->l = p;\n\
    \      p->r = c;\n    }\n\n    if (pp && pp->l == p) { pp->l = n; }\n    if (pp\
    \ && pp->r == p) { pp->r = n; }\n    n->p = pp;\n    p->p = n;\n    n->cancel\
    \ = (n->p ? n->p->added : MonoA::unit());\n    p->cancel = (p->p ? p->p->added\
    \ : MonoA::unit());\n  }\n};\n\ntemplate <typename AbelGroup>\nstruct LCT_Subtree_Sum_Node\
    \ {\n  using X = typename AbelGroup::value_type;\n  LCT_Subtree_Sum_Node *l, *r,\
    \ *p;\n  X x, heavy_sum, light_sum;\n  int idx;\n  bool rev;\n  LCT_Subtree_Sum_Node(int\
    \ i = 0, X x = AbelGroup::unit())\n      : l(nullptr),\n        r(nullptr),\n\
    \        p(nullptr),\n        x(x),\n        heavy_sum(x),\n        light_sum(AbelGroup::unit()),\n\
    \        idx(i) {}\n\n  void set(X y) {\n    x = y;\n    update();\n  }\n\n  void\
    \ add(X y) {\n    x = AbelGroup::op(x, y);\n    update();\n  }\n\n  X sum() {\
    \ return AbelGroup::op(heavy_sum, light_sum); }\n\n  void update() {\n    heavy_sum\
    \ = x;\n    if (l) heavy_sum = AbelGroup::op(heavy_sum, l->sum());\n    if (r)\
    \ heavy_sum = AbelGroup::op(heavy_sum, r->sum());\n  }\n\n  void add_r(bool add)\
    \ {\n    if (!r) return;\n    X x = r->sum();\n    if (!add) x = AbelGroup::inverse(x);\n\
    \    light_sum = AbelGroup::op(light_sum, x);\n  }\n\n  void push() {\n    if\
    \ (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n      rev =\
    \ 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\n\
    \  void debug() { print(idx, \"x\", x, \"heavy\", heavy_sum, \"light\", light_sum);\
    \ }\n};\n"
  code: "#include \"graph/ds/link_cut.hpp\"\n\ntemplate <typename Node, int NODES>\n\
    struct LinkCutTree_SubTree : LinkCutTree_base<Node, NODES> {\n  using Base = LinkCutTree_base<Node,\
    \ NODES>;\n  using MonoX = typename Node::MonoX;\n  using X = typename Node::X;\n\
    \  using MonoA = typename Node::MonoA;\n  using A = typename Node::A;\n\n  LinkCutTree_SubTree(int\
    \ n = 0) : Base(n) {}\n\n  LinkCutTree_SubTree(vc<X> dat) : Base(len(dat)) {\n\
    \    FOR(i, len(dat))(*this)[i]->set(dat[i]);\n  }\n\n  void set(int i, X x) {\n\
    \    Base::expose(i);\n    (*this)[i]->set(x);\n  }\n\n  void add(int i, X x)\
    \ {\n    Base::expose(i);\n    (*this)[i]->add(x);\n  }\n\n  X sum(int v) {\n\
    \    int p = Base::get_parent(v);\n    if (p == -1) { return (*this)[v]->sum();\
    \ }\n    Base::cut(v, p);\n    X x = (*this)[v]->sum();\n    Base::link(v, p);\n\
    \    return x;\n  }\n\n  void link(Node *c, Node *p) override {\n    Base::evert(p);\n\
    \    expose(c);\n    c->p = p;\n    c->cancel = p->added;\n    p->r = c;\n   \
    \ p->update();\n  }\n\n  void link(int c, int p) override { return link((*this)[c],\
    \ (*this)[p]); }\n\n  // c \u3068\u6839\u307E\u3067\u304C\u7E4B\u304C\u308C\u3066\
    \u3044\u308B\u72B6\u614B\u306B\u5909\u66F4\u3057\u3066\u3001\u6839\u3092 return\
    \ \u3059\u308B\n  Node *expose(Node *c) override {\n    Node *now = c;\n    Node\
    \ *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\u3063\u305F\u30D1\u30B9\n    while\
    \ (now) {\n      Base::splay(now);\n      if (now->r) {\n        now->r->push();\n\
    \        if (now->r) now->add_r(true);\n      }\n      now->r = rp;\n      if\
    \ (now->r) {\n        now->r->push();\n        now->add_r(false);\n      }\n \
    \     now->update();\n      rp = now;\n      now = now->p;\n    }\n    Base::splay(c);\n\
    \    return rp;\n  }\n\n  int expose(int c) {\n    Node *x = expose((*this)[c]);\n\
    \    if (!x) return -1;\n    return x->idx;\n  }\n\n  void rotate(Node *n) override\
    \ {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n\n    if (p->l == n) {\n      c = n->r;\n    \
    \  if (c) c->push();\n      n->r = p;\n      p->l = c;\n    } else {\n      c\
    \ = n->l;\n      if (c) c->push();\n      n->l = p;\n      p->r = c;\n    }\n\n\
    \    if (pp && pp->l == p) { pp->l = n; }\n    if (pp && pp->r == p) { pp->r =\
    \ n; }\n    n->p = pp;\n    p->p = n;\n    n->cancel = (n->p ? n->p->added : MonoA::unit());\n\
    \    p->cancel = (p->p ? p->p->added : MonoA::unit());\n  }\n};\n\ntemplate <typename\
    \ AbelGroup>\nstruct LCT_Subtree_Sum_Node {\n  using X = typename AbelGroup::value_type;\n\
    \  LCT_Subtree_Sum_Node *l, *r, *p;\n  X x, heavy_sum, light_sum;\n  int idx;\n\
    \  bool rev;\n  LCT_Subtree_Sum_Node(int i = 0, X x = AbelGroup::unit())\n   \
    \   : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        x(x),\n \
    \       heavy_sum(x),\n        light_sum(AbelGroup::unit()),\n        idx(i) {}\n\
    \n  void set(X y) {\n    x = y;\n    update();\n  }\n\n  void add(X y) {\n   \
    \ x = AbelGroup::op(x, y);\n    update();\n  }\n\n  X sum() { return AbelGroup::op(heavy_sum,\
    \ light_sum); }\n\n  void update() {\n    heavy_sum = x;\n    if (l) heavy_sum\
    \ = AbelGroup::op(heavy_sum, l->sum());\n    if (r) heavy_sum = AbelGroup::op(heavy_sum,\
    \ r->sum());\n  }\n\n  void add_r(bool add) {\n    if (!r) return;\n    X x =\
    \ r->sum();\n    if (!add) x = AbelGroup::inverse(x);\n    light_sum = AbelGroup::op(light_sum,\
    \ x);\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n  \
    \    if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  void reverse() {\n\
    \    rev ^= 1;\n    swap(l, r);\n  }\n\n  void debug() { print(idx, \"x\", x,\
    \ \"heavy\", heavy_sum, \"light\", light_sum); }\n};"
  dependsOn:
  - graph/ds/link_cut.hpp
  isVerificationFile: false
  path: graph/ds/link_cut_subtree.hpp
  requiredBy: []
  timestamp: '2022-10-24 14:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/link_cut_subtree.hpp
layout: document
redirect_from:
- /library/graph/ds/link_cut_subtree.hpp
- /library/graph/ds/link_cut_subtree.hpp.html
title: graph/ds/link_cut_subtree.hpp
---
