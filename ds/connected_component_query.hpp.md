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
  bundledCode: "#line 1 \"ds/connected_component_query.hpp\"\ntemplate <typename Lazy>\n\
    struct Connected_Component_Query {\n  using Monoid_X = typename Lazy::X_structure;\n\
    \  using Monoid_A = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n\n  struct Node {\n    int l, r;\n\
    \    X prod;\n    A lazy; // \u305D\u306E\u9802\u70B9\u306B\u304A\u3051\u308B\
    \ prod \u306F lazy \u3092\u53CD\u6620\u6E08\n  };\n\n  const int N;\n  vc<int>\
    \ not_used;\n  vc<Node> nodes;\n  vc<int> history;\n  FastSet roots;\n\n  Connected_Component_Query(vc<X>\
    \ dat)\n      : N(len(dat)), nodes(N + N), roots(N + N) {\n    FOR(i, N, N + N)\
    \ not_used.eb(i);\n    FOR(i, N) roots.insert(i);\n    FOR(v, N) { nodes[v] =\
    \ Node{-1, -1, dat[v], Monoid_A::unit()}; }\n  }\n\n  int merge(int u, int v)\
    \ {\n    int w = pick(not_used);\n    roots.erase(u);\n    roots.erase(v);\n \
    \   roots.insert(w);\n    nodes[w].l = u;\n    nodes[w].r = v;\n    nodes[w].prod\
    \ = Monoid_X::op(nodes[u].prod, nodes[v].prod);\n    nodes[w].lazy = Monoid_A::unit();\n\
    \    history.eb(w);\n    return w;\n  }\n\n  void apply(int u, A a) {\n    //\
    \ print(\"merge\", u, \",\", a);\n    assert(roots[u]);\n    nodes[u].lazy = Monoid_A::op(nodes[u].lazy,\
    \ a);\n    nodes[u].prod = Lazy::act(nodes[u].prod, a);\n  }\n\n  X prod(int u)\
    \ {\n    assert(roots[u]);\n    return nodes[u].prod;\n  }\n\n  int time() { return\
    \ len(history); }\n\n  // merge \u3092\u89E3\u9664\u3002lazy \u306F\u6B8B\u308A\
    \u7D9A\u3051\u308B\u3053\u3068\u306B\u6CE8\u610F\u3059\u308B\u3002\n  void rollback(int\
    \ t) {\n    assert(len(history) >= t);\n    while (len(history) > t) {\n     \
    \ int w = pick(history);\n      int u = nodes[w].l;\n      int v = nodes[w].r;\n\
    \      roots.erase(w);\n      roots.insert(u);\n      roots.insert(v);\n     \
    \ apply(u, nodes[w].lazy);\n      apply(v, nodes[w].lazy);\n      not_used.eb(w);\n\
    \      // print(\"undo_merge\", u, v, w);\n    }\n  }\n};\n"
  code: "template <typename Lazy>\nstruct Connected_Component_Query {\n  using Monoid_X\
    \ = typename Lazy::X_structure;\n  using Monoid_A = typename Lazy::A_structure;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \n  struct Node {\n    int l, r;\n    X prod;\n    A lazy; // \u305D\u306E\u9802\
    \u70B9\u306B\u304A\u3051\u308B prod \u306F lazy \u3092\u53CD\u6620\u6E08\n  };\n\
    \n  const int N;\n  vc<int> not_used;\n  vc<Node> nodes;\n  vc<int> history;\n\
    \  FastSet roots;\n\n  Connected_Component_Query(vc<X> dat)\n      : N(len(dat)),\
    \ nodes(N + N), roots(N + N) {\n    FOR(i, N, N + N) not_used.eb(i);\n    FOR(i,\
    \ N) roots.insert(i);\n    FOR(v, N) { nodes[v] = Node{-1, -1, dat[v], Monoid_A::unit()};\
    \ }\n  }\n\n  int merge(int u, int v) {\n    int w = pick(not_used);\n    roots.erase(u);\n\
    \    roots.erase(v);\n    roots.insert(w);\n    nodes[w].l = u;\n    nodes[w].r\
    \ = v;\n    nodes[w].prod = Monoid_X::op(nodes[u].prod, nodes[v].prod);\n    nodes[w].lazy\
    \ = Monoid_A::unit();\n    history.eb(w);\n    return w;\n  }\n\n  void apply(int\
    \ u, A a) {\n    // print(\"merge\", u, \",\", a);\n    assert(roots[u]);\n  \
    \  nodes[u].lazy = Monoid_A::op(nodes[u].lazy, a);\n    nodes[u].prod = Lazy::act(nodes[u].prod,\
    \ a);\n  }\n\n  X prod(int u) {\n    assert(roots[u]);\n    return nodes[u].prod;\n\
    \  }\n\n  int time() { return len(history); }\n\n  // merge \u3092\u89E3\u9664\
    \u3002lazy \u306F\u6B8B\u308A\u7D9A\u3051\u308B\u3053\u3068\u306B\u6CE8\u610F\u3059\
    \u308B\u3002\n  void rollback(int t) {\n    assert(len(history) >= t);\n    while\
    \ (len(history) > t) {\n      int w = pick(history);\n      int u = nodes[w].l;\n\
    \      int v = nodes[w].r;\n      roots.erase(w);\n      roots.insert(u);\n  \
    \    roots.insert(v);\n      apply(u, nodes[w].lazy);\n      apply(v, nodes[w].lazy);\n\
    \      not_used.eb(w);\n      // print(\"undo_merge\", u, v, w);\n    }\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: ds/connected_component_query.hpp
  requiredBy: []
  timestamp: '2022-12-05 07:33:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/connected_component_query.hpp
layout: document
redirect_from:
- /library/ds/connected_component_query.hpp
- /library/ds/connected_component_query.hpp.html
title: ds/connected_component_query.hpp
---
