---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1170_2.test.cpp
    title: test/3_yukicoder/1170_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"graph/blackbox/unionfind.hpp\"\
    \n\n// \u9802\u70B9\u3092\u524A\u9664\u3057\u306A\u304C\u3089\u3001\u9069\u5F53\
    \u306A\u30C7\u30FC\u30BF\u69CB\u9020\u306B\u3088\u308A\u6B21\u306E\u8FBA\u3092\
    \u63A2\u3059\u3002\n// \u4E2D\u8EAB\u306F\u305F\u3060\u306E bfs \u3057\u3066\u3044\
    \u308B\u306E\u3067\u300101 \u6700\u77ED\u8DEF\u306B\u3082\u6D41\u7528\u53EF\u80FD\
    \ntemplate <typename F1, typename F2>\nUnionFind blackbox_unionfind(int N, F1\
    \ set_used, F2 find_unused) {\n  UnionFind uf(N);\n  vc<bool> done(N);\n  deque<int>\
    \ que;\n  FOR(v, N) if (!done[v]) {\n    que.eb(v);\n    done[v] = 1;\n    set_used(v);\n\
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
    UnionFind blackbox_unionfind(int N, F1 set_used, F2 find_unused) {\n  UnionFind\
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
  path: graph/blackbox/unionfind.hpp
  requiredBy: []
  timestamp: '2024-03-10 03:27:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1170_2.test.cpp
documentation_of: graph/blackbox/unionfind.hpp
layout: document
redirect_from:
- /library/graph/blackbox/unionfind.hpp
- /library/graph/blackbox/unionfind.hpp.html
title: graph/blackbox/unionfind.hpp
---
