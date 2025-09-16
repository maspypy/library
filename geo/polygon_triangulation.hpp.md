---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_basic.hpp
    title: ds/splaytree/splaytree_basic.hpp
  - icon: ':heavy_check_mark:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/planar_graph.hpp
    title: graph/planar_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/splaytree/splaytree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"geo/base.hpp\"\n#include \"ds/splaytree/splaytree_basic.hpp\"\n\
    #include \"graph/planar_graph.hpp\"\n\ntemplate <typename T>\nvc<tuple<int, int,\
    \ int>> monotone_polygon_triangulation(vc<Point<T>> point) {\n  int N = len(point);\n\
    \  int rot = min_element(all(point)) - point.begin();\n  rotate(point.begin(),\
    \ point.begin() + rot, point.end());\n  int n = max_element(all(point)) - point.begin();\n\
    \  FOR(i, n) assert(point[i] < point[i + 1]);\n  FOR(i, n, N) assert(point[(i\
    \ + 1) % N] < point[i]);\n  vc<tuple<int, int, int>> res;\n  auto side = [&](int\
    \ i) -> int {\n    assert(i != 0 && i != n);\n    return (i < n ? 0 : 1);\n  };\n\
    \  vc<int> I = argsort(point);\n  vc<int> stack = {I[0], I[1]};\n  int s = side(I[1]);\n\
    \  FOR(i, 2, N - 1) {\n    int v = I[i], t = side(v);\n    if (s == 0 && t ==\
    \ 0) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack) - 2]], point[stack[len(stack)\
    \ - 1]], point[v]) == 1) {\n        res.eb(stack[len(stack) - 2], stack[len(stack)\
    \ - 1], v), POP(stack);\n      }\n      stack.eb(v);\n    }\n    elif (s == 1\
    \ && t == 1) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack) - 2]],\
    \ point[stack[len(stack) - 1]], point[v]) == -1) {\n        res.eb(stack[len(stack)\
    \ - 2], v, stack[len(stack) - 1]), POP(stack);\n      }\n      stack.eb(v);\n\
    \    }\n    elif (s == 0 && t == 1) {\n      FOR(j, len(stack) - 1) res.eb(stack[j],\
    \ stack[j + 1], v);\n      stack = {stack.back(), v}, s = t;\n    }\n    elif\
    \ (s == 1 && t == 0) {\n      FOR(j, len(stack) - 1) res.eb(stack[j], v, stack[j\
    \ + 1]);\n      stack = {stack.back(), v}, s = t;\n    }\n  }\n  if (s == 0) {\
    \ FOR(j, len(stack) - 1) res.eb(stack[j], stack[j + 1], n); }\n  elif (s == 1)\
    \ { FOR(j, len(stack) - 1) res.eb(stack[j], n, stack[j + 1]); }\n  for (auto&\
    \ [a, b, c]: res) a = (a + rot) % N, b = (b + rot) % N, c = (c + rot) % N;\n \
    \ return res;\n}\n\n// (i,j,k), ccw\ntemplate <typename T>\nvc<tuple<int, int,\
    \ int>> polygon_triangulation(vc<Point<T>> point) {\n  using P = Point<T>;\n \
    \ int N = len(point);\n  enum vtype { MERGE, SPLIT, START, END, UPPER, LOWER };\n\
    \  auto pre = [&](int i) -> int { return (i > 0 ? i - 1 : N - 1); };\n  auto nxt\
    \ = [&](int i) -> int { return (i < N - 1 ? i + 1 : 0); };\n  auto get_vtype =\
    \ [&](int i) -> vtype {\n    int l = pre(i), r = nxt(i);\n    if (point[i] < point[l]\
    \ && point[i] < point[r]) { return (ccw(point[l], point[i], point[r]) == 1 ? START\
    \ : SPLIT); }\n    if (point[l] < point[i] && point[r] < point[i]) { return (ccw(point[l],\
    \ point[i], point[r]) == 1 ? END : MERGE); }\n    if (point[l] < point[i] && point[i]\
    \ < point[r]) return LOWER;\n    if (point[r] < point[i] && point[i] < point[l])\
    \ return UPPER;\n    assert(0);\n    return END;\n  };\n  SplayTree_Basic<int>\
    \ ST(N);\n  using np = decltype(ST)::np;\n  vc<np> nodes(N);\n  FOR(i, N) nodes[i]\
    \ = ST.new_node(i);\n  np S = ST.new_root();\n  auto comp = [&](int i, P p) ->\
    \ bool {\n    P A = point[i], B = point[nxt(i)];\n    return ccw(A, B, p) == -1;\n\
    \  };\n\n  vc<int> helper(N, -1);\n  vc<bool> merged(N);\n\n  Planar_Graph<T>\
    \ G(N, point);\n  FOR(i, N) G.add(i, nxt(i));\n\n  auto add_edge = [&](int v,\
    \ int w) -> void { merged[w] = 1, G.add(v, w); };\n\n  auto fix_up = [&](int v,\
    \ int e) -> void {\n    int w = helper[e];\n    if (get_vtype(w) == vtype::MERGE\
    \ && !merged[w]) { add_edge(v, w); }\n  };\n  auto I = argsort(point);\n  for\
    \ (auto& i: I) {\n    vtype t = get_vtype(i);\n    if (t == vtype::MERGE) {\n\
    \      ST.splay(nodes[i], 1), S = nodes[i];\n      int n = (nodes[i]->l ? nodes[i]->l->size\
    \ : 0);\n      auto [L, M, R] = ST.split3(S, n, n + 1);\n      int j = ST.get(R,\
    \ 0);\n      S = ST.merge(L, R);\n      fix_up(i, i), fix_up(i, j);\n      helper[j]\
    \ = i;\n    }\n    if (t == vtype::SPLIT) {\n      auto [L, R] = ST.split_max_right(S,\
    \ [&](int k) -> bool { return comp(k, point[i]); });\n      int j = ST.get(R,\
    \ 0);\n      add_edge(i, helper[j]);\n      helper[j] = i, helper[pre(i)] = i;\n\
    \      S = ST.merge3(L, nodes[pre(i)], R);\n    }\n    if (t == vtype::START)\
    \ {\n      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k,\
    \ point[i]); });\n      S = ST.merge3(L, nodes[pre(i)], R), helper[pre(i)] = i;\n\
    \    }\n    if (t == vtype::END) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n\
    \      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] =\
    \ ST.split3(S, n, n + 1);\n      S = ST.merge(L, R);\n      fix_up(i, i);\n  \
    \  }\n    if (t == vtype::UPPER) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n\
    \      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] =\
    \ ST.split3(S, n, n + 1);\n      S = ST.merge3(L, nodes[pre(i)], R);\n      fix_up(i,\
    \ i);\n      helper[pre(i)] = i;\n    }\n    if (t == vtype::LOWER) {\n      auto\
    \ [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k, point[i]);\
    \ });\n      int j = ST.get(R, 0);\n      S = ST.merge(L, R);\n      fix_up(i,\
    \ j);\n      helper[j] = i;\n    }\n  }\n  G.build();\n  vc<tuple<int, int, int>>\
    \ ANS;\n  FOR(f, 1, G.NF) {\n    auto [vs, es] = G.get_face_data(f);\n    POP(vs);\n\
    \    vc<P> sub = rearrange(point, vs);\n    for (auto& [a, b, c]: monotone_polygon_triangulation(sub))\
    \ ANS.eb(vs[a], vs[b], vs[c]);\n  }\n  return ANS;\n}"
  dependsOn:
  - geo/base.hpp
  - ds/splaytree/splaytree_basic.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  - graph/planar_graph.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - geo/angle_sort.hpp
  isVerificationFile: false
  path: geo/polygon_triangulation.hpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/polygon_triangulation.test.cpp
documentation_of: geo/polygon_triangulation.hpp
layout: document
redirect_from:
- /library/geo/polygon_triangulation.hpp
- /library/geo/polygon_triangulation.hpp.html
title: geo/polygon_triangulation.hpp
---
