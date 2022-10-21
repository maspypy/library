---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/link_cut.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/link_cut.hpp\"\n\ntemplate <typename Node, int NODES>\n\
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
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/link_cut_subtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/link_cut_subtree.hpp
layout: document
redirect_from:
- /library/graph/ds/link_cut_subtree.hpp
- /library/graph/ds/link_cut_subtree.hpp.html
title: graph/ds/link_cut_subtree.hpp
---
