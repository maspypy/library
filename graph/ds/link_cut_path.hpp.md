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
  code: "#include \"graph/link_cut.hpp\"\ntemplate <typename Node, int NODES>\nstruct\
    \ LinkCutTree_Path_base : public LinkCutTree_base<Node, NODES> {\n  using X =\
    \ typename Node::X;\n\n  LinkCutTree_Path_base(int n) : LinkCutTree_base<Node,\
    \ NODES>(n) {}\n\n  LinkCutTree_Path_base(vc<X> dat) : LinkCutTree_base<Node,\
    \ NODES>(len(dat)) {\n    FOR(v, len(dat)) {\n      Node *c = (*this)[v];\n  \
    \    set(c, dat[v]);\n    }\n  }\n\n  template <typename F>\n  LinkCutTree_Path_base(int\
    \ n, F f) : LinkCutTree_base<Node, NODES>(n) {\n    FOR(v, n) {\n      X x = f(v);\n\
    \      Node *c = (*this)[v];\n      set(c, x);\n    }\n  }\n\n  void set(Node\
    \ *c, X x) {\n    this->evert(c);\n    c->x = x;\n    c->update();\n  }\n\n  void\
    \ set(int c, X x) { set((*this)[c], x); }\n\n  void multiply(Node *c, X x) { set(c,\
    \ Node::Mono::op(c->x, x)); }\n\n  void multiply(int c, X x) { multiply((*this)[c],\
    \ x); }\n\n  X prod_path(Node *a, Node *b) {\n    this->evert(a);\n    this->expose(b);\n\
    \    return b->prod;\n  }\n\n  X prod_path(int a, int b) { return prod_path((*this)[a],\
    \ (*this)[b]); }\n};\n\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n\
    \  using Mono = Monoid;\n  using X = typename Monoid::value_type;\n  LCT_Node_Monoid\
    \ *l, *r, *p;\n  int idx;\n  X x, prod, rev_prod;\n  bool rev;\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        x(Monoid::unit()),\n        prod(Monoid::unit()),\n    \
    \    rev_prod(Monoid::unit()) {}\n\n  void update() {\n    prod = rev_prod = x;\n\
    \    if (l) {\n      prod = Monoid::op(l->prod, prod);\n      rev_prod = Monoid::op(rev_prod,\
    \ l->rev_prod);\n    }\n    if (r) {\n      prod = Monoid::op(prod, r->prod);\n\
    \      rev_prod = Monoid::op(r->rev_prod, rev_prod);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n    swap(prod, rev_prod);\n  }\n\n  void debug() {\n    int li = (l ? l->idx\
    \ : -1);\n    int ri = (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n \
    \   print(\"idx\", idx, \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod,\n\
    \          \"rev_prod\", rev_prod);\n  }\n};\n\ntemplate <typename Monoid>\nstruct\
    \ LCT_Node_CommutativeMonoid {\n  using Mono = Monoid;\n  using X = typename Mono::value_type;\n\
    \  LCT_Node_CommutativeMonoid *l, *r, *p;\n  int idx;\n  X x, prod;\n  bool rev;\n\
    \  LCT_Node_CommutativeMonoid(int i = 0)\n      : l(nullptr),\n        r(nullptr),\n\
    \        p(nullptr),\n        idx(i),\n        x(Mono::unit()),\n        prod(Mono::unit())\
    \ {}\n\n  void update() {\n    prod = x;\n    if (l) { prod = Mono::op(l->prod,\
    \ prod); }\n    if (r) { prod = Mono::op(prod, r->prod); }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n  }\n\n  void debug() {\n    int li = (l ? l->idx : -1);\n    int ri =\
    \ (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n    print(\"idx\", idx,\
    \ \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod);\n  }\n};\n\ntemplate\
    \ <typename Monoid, int NODES>\nusing LinkCutTree_Path = LinkCutTree_Path_base<LCT_Node_Monoid<Monoid>,\
    \ NODES>;\n\ntemplate <typename Monoid, int NODES>\nusing LinkCutTree_Path_Commutative\n\
    \    = LinkCutTree_Path_base<LCT_Node_CommutativeMonoid<Monoid>, NODES>;\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/link_cut_path.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/link_cut_path.hpp
layout: document
redirect_from:
- /library/graph/ds/link_cut_path.hpp
- /library/graph/ds/link_cut_path.hpp.html
title: graph/ds/link_cut_path.hpp
---
