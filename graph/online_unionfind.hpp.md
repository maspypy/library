---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1170_2.test.cpp
    title: test/yukicoder/1170_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n;\n  int n_comp;\n  std::vector<int> size, par;\n  UnionFind(int n) : n(n),\
    \ n_comp(n), size(n, 1), par(n) {\n    std::iota(par.begin(), par.end(), 0);\n\
    \  }\n  int find(int x) {\n    assert(0 <= x && x < n);\n    while (par[x] !=\
    \ x) { x = par[x] = par[par[x]]; }\n    return x;\n  }\n\n  int operator[](int\
    \ x) { return find(x); }\n\n  bool merge(int x, int y) {\n    x = find(x);\n \
    \   y = find(y);\n    if (x == y) { return false; }\n    n_comp--;\n    if (size[x]\
    \ < size[y]) std::swap(x, y);\n    size[x] += size[y];\n    size[y] = 0;\n   \
    \ par[y] = x;\n    return true;\n  }\n\n  std::vector<int> find_all() {\n    std::vector<int>\
    \ A(n);\n    for (int i = 0; i < n; ++i) A[i] = find(i);\n    return A;\n  }\n\
    \n  void reset() {\n    n_comp = n;\n    size.assign(n, 1);\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n};\n#line 2 \"graph/online_unionfind.hpp\"\n\n// \u9802\
    \u70B9\u3092\u524A\u9664\u3057\u306A\u304C\u3089\u3001\u9069\u5F53\u306A\u30C7\
    \u30FC\u30BF\u69CB\u9020\u306B\u3088\u308A\u6B21\u306E\u8FBA\u3092\u63A2\u3059\
    \u3002\n// \u4E2D\u8EAB\u306F\u305F\u3060\u306E bfs \u3057\u3066\u3044\u308B\u306E\
    \u3067\u300101 \u6700\u77ED\u8DEF\u306B\u3082\u6D41\u7528\u53EF\u80FD\ntemplate\
    \ <typename F1, typename F2>\nUnionFind online_unionfind(int N, F1 set_used, F2\
    \ find_unused) {\n  UnionFind uf(N);\n  vc<bool> done(N);\n  deque<int> que;\n\
    \  FOR(v, N) if (!done[v]) {\n    que.eb(v);\n    done[v] = 1;\n    set_used(v);\n\
    \    while (!que.empty()) {\n      int x = que.front();\n      que.pop_front();\n\
    \      set_used(x);\n      done[x] = 1;\n      while (1) {\n        int to = find_unused(x);\n\
    \        if (to == -1) break;\n        uf.merge(v, to);\n        que.eb(to);\n\
    \        done[to] = 1;\n        set_used(to);\n      }\n    }\n  }\n  return uf;\n\
    }\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// \u9802\u70B9\u3092\u524A\u9664\
    \u3057\u306A\u304C\u3089\u3001\u9069\u5F53\u306A\u30C7\u30FC\u30BF\u69CB\u9020\
    \u306B\u3088\u308A\u6B21\u306E\u8FBA\u3092\u63A2\u3059\u3002\n// \u4E2D\u8EAB\u306F\
    \u305F\u3060\u306E bfs \u3057\u3066\u3044\u308B\u306E\u3067\u300101 \u6700\u77ED\
    \u8DEF\u306B\u3082\u6D41\u7528\u53EF\u80FD\ntemplate <typename F1, typename F2>\n\
    UnionFind online_unionfind(int N, F1 set_used, F2 find_unused) {\n  UnionFind\
    \ uf(N);\n  vc<bool> done(N);\n  deque<int> que;\n  FOR(v, N) if (!done[v]) {\n\
    \    que.eb(v);\n    done[v] = 1;\n    set_used(v);\n    while (!que.empty())\
    \ {\n      int x = que.front();\n      que.pop_front();\n      set_used(x);\n\
    \      done[x] = 1;\n      while (1) {\n        int to = find_unused(x);\n   \
    \     if (to == -1) break;\n        uf.merge(v, to);\n        que.eb(to);\n  \
    \      done[to] = 1;\n        set_used(to);\n      }\n    }\n  }\n  return uf;\n\
    }"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/online_unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-02 19:13:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1170_2.test.cpp
documentation_of: graph/online_unionfind.hpp
layout: document
redirect_from:
- /library/graph/online_unionfind.hpp
- /library/graph/online_unionfind.hpp.html
title: graph/online_unionfind.hpp
---
