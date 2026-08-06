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
  bundledCode: "#line 1 \"ds/unionfind/dual_unionfind.hpp\"\n// component apply, point\
    \ get, O(log N)\ntemplate <typename Monoid>\nstruct Dual_UnionFind {\n  using\
    \ MA = Monoid;\n  using A = typename MA::value_type;\n\n  int N, n_comp;\n  vc<int>\
    \ dat;  // parent or (-size)\n  vc<A> val;\n\n  Dual_UnionFind(int N = 0) { build(N);\
    \ }\n\n  void build(int n) {\n    N = n;\n    n_comp = N;\n    dat.assign(N, -1);\n\
    \    val.assign(N, MA::unit());\n    dat.reserve(2 * N);\n    val.reserve(2 *\
    \ N);\n  }\n\n  vc<int> buf;\n  int root(int x) {\n    buf.clear();\n    int r\
    \ = x;\n    while (dat[r] >= 0) {\n      buf.eb(r);\n      r = dat[r];\n    }\n\
    \n    A prod = MA::unit();\n    FOR_R(i, len(buf)) {\n      int v = buf[i];\n\
    \      prod = val[v] = MA::op(val[v], prod);\n      dat[v] = r;\n    }\n    return\
    \ r;\n  }\n\n  int operator[](int x) { return root(x); }\n\n  bool same(int x,\
    \ int y) { return root(x) == root(y); }\n\n  int size(int x) {\n    x = root(x);\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = root(x), y\
    \ = root(y);\n    if (x == y) return false;\n\n    int z = len(dat);\n    int\
    \ sz = -dat[x] - dat[y];\n\n    dat[x] = z, dat[y] = z;\n    dat.eb(-sz);\n  \
    \  val.eb(MA::unit());\n    --n_comp;\n    return true;\n  }\n\n  void apply(int\
    \ x, const A& a) {\n    x = root(x);\n    val[x] = MA::op(val[x], a);\n  }\n\n\
    \  A get(int x) {\n    int r = root(x);\n    if (x == r) return val[r];\n    return\
    \ MA::op(val[x], val[r]);\n  }\n};\n"
  code: "// component apply, point get, O(log N)\ntemplate <typename Monoid>\nstruct\
    \ Dual_UnionFind {\n  using MA = Monoid;\n  using A = typename MA::value_type;\n\
    \n  int N, n_comp;\n  vc<int> dat;  // parent or (-size)\n  vc<A> val;\n\n  Dual_UnionFind(int\
    \ N = 0) { build(N); }\n\n  void build(int n) {\n    N = n;\n    n_comp = N;\n\
    \    dat.assign(N, -1);\n    val.assign(N, MA::unit());\n    dat.reserve(2 * N);\n\
    \    val.reserve(2 * N);\n  }\n\n  vc<int> buf;\n  int root(int x) {\n    buf.clear();\n\
    \    int r = x;\n    while (dat[r] >= 0) {\n      buf.eb(r);\n      r = dat[r];\n\
    \    }\n\n    A prod = MA::unit();\n    FOR_R(i, len(buf)) {\n      int v = buf[i];\n\
    \      prod = val[v] = MA::op(val[v], prod);\n      dat[v] = r;\n    }\n    return\
    \ r;\n  }\n\n  int operator[](int x) { return root(x); }\n\n  bool same(int x,\
    \ int y) { return root(x) == root(y); }\n\n  int size(int x) {\n    x = root(x);\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = root(x), y\
    \ = root(y);\n    if (x == y) return false;\n\n    int z = len(dat);\n    int\
    \ sz = -dat[x] - dat[y];\n\n    dat[x] = z, dat[y] = z;\n    dat.eb(-sz);\n  \
    \  val.eb(MA::unit());\n    --n_comp;\n    return true;\n  }\n\n  void apply(int\
    \ x, const A& a) {\n    x = root(x);\n    val[x] = MA::op(val[x], a);\n  }\n\n\
    \  A get(int x) {\n    int r = root(x);\n    if (x == r) return val[r];\n    return\
    \ MA::op(val[x], val[r]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/dual_unionfind.hpp
  requiredBy: []
  timestamp: '2026-08-06 23:33:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/dual_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/dual_unionfind.hpp
- /library/ds/unionfind/dual_unionfind.hpp.html
title: ds/unionfind/dual_unionfind.hpp
---
