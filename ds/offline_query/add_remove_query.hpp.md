---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/add_remove_query.test.cpp
    title: test/2_library_checker/data_structure/add_remove_query.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/offline_query/add_remove_query.hpp\"\n/*\n\u30FB\u6642\
    \u523B t \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u30FB\u6642\u523B t \u306B\
    \ x \u3092\u524A\u9664\u3059\u308B\n\u304C\u3042\u308B\u3068\u304D\u306B,\n\u30FB\
    \u6642\u523B [l, r) \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u306B\u5909\u63DB\
    \u3059\u308B. \u540C\u3058\u30AD\u30FC\u304C\u8907\u6570\u56DE\u6765\u308B\u3068\
    \u56F0\u308B\u306E\u3067\u9069\u5F53\u306A\u30E9\u30D9\u30EB\u3092\u3064\u3051\
    \u3066\u304A\u3053\u3046.\n*/\ntemplate <typename X, bool monotone>\nstruct Add_Remove_Query\
    \ {\n  map<X, int> MP;\n  vc<tuple<int, int, X>> dat;\n  map<X, vc<int>> ADD;\n\
    \  map<X, vc<int>> RM;\n\n  void add(int time, X x) {\n    if (monotone) return\
    \ add_monotone(time, x);\n    ADD[x].eb(time);\n  }\n  void remove(int time, X\
    \ x) {\n    if (monotone) return remove_monotone(time, x);\n    RM[x].eb(time);\n\
    \  }\n\n  // \u3059\u3079\u3066\u306E\u30AF\u30A8\u30EA\u304C\u7D42\u308F\u3063\
    \u305F\u73FE\u5728\u6642\u523B\u3092\u6E21\u3059\n  vc<tuple<int, int, X>> calc(int\
    \ time) {\n    if (monotone) return calc_monotone(time);\n    vc<tuple<int, int,\
    \ X>> dat;\n    for (auto&& [x, A]: ADD) {\n      vc<int> B;\n      if (RM.count(x))\
    \ {\n        B = RM[x];\n        RM.erase(x);\n      }\n      if (len(B) < len(A))\
    \ B.eb(time);\n      assert(len(A) == len(B));\n\n      sort(all(A));\n      sort(all(B));\n\
    \      FOR(i, len(A)) {\n        assert(A[i] <= B[i]);\n        if (A[i] < B[i])\
    \ dat.eb(A[i], B[i], x);\n      }\n    }\n    assert(len(RM) == 0);\n    return\
    \ dat;\n  }\n\nprivate:\n  void add_monotone(int time, X x) {\n    assert(!MP.count(x));\n\
    \    MP[x] = time;\n  }\n  void remove_monotone(int time, X x) {\n    auto it\
    \ = MP.find(x);\n    assert(it != MP.end());\n    int t = (*it).se;\n    MP.erase(it);\n\
    \    if (t == time) return;\n    dat.eb(t, time, x);\n  }\n  vc<tuple<int, int,\
    \ X>> calc_monotone(int time) {\n    for (auto&& [x, t]: MP) {\n      if (t ==\
    \ time) continue;\n      dat.eb(t, time, x);\n    }\n    return dat;\n  }\n};\n"
  code: "/*\n\u30FB\u6642\u523B t \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u30FB\u6642\
    \u523B t \u306B x \u3092\u524A\u9664\u3059\u308B\n\u304C\u3042\u308B\u3068\u304D\
    \u306B,\n\u30FB\u6642\u523B [l, r) \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u306B\
    \u5909\u63DB\u3059\u308B. \u540C\u3058\u30AD\u30FC\u304C\u8907\u6570\u56DE\u6765\
    \u308B\u3068\u56F0\u308B\u306E\u3067\u9069\u5F53\u306A\u30E9\u30D9\u30EB\u3092\
    \u3064\u3051\u3066\u304A\u3053\u3046.\n*/\ntemplate <typename X, bool monotone>\n\
    struct Add_Remove_Query {\n  map<X, int> MP;\n  vc<tuple<int, int, X>> dat;\n\
    \  map<X, vc<int>> ADD;\n  map<X, vc<int>> RM;\n\n  void add(int time, X x) {\n\
    \    if (monotone) return add_monotone(time, x);\n    ADD[x].eb(time);\n  }\n\
    \  void remove(int time, X x) {\n    if (monotone) return remove_monotone(time,\
    \ x);\n    RM[x].eb(time);\n  }\n\n  // \u3059\u3079\u3066\u306E\u30AF\u30A8\u30EA\
    \u304C\u7D42\u308F\u3063\u305F\u73FE\u5728\u6642\u523B\u3092\u6E21\u3059\n  vc<tuple<int,\
    \ int, X>> calc(int time) {\n    if (monotone) return calc_monotone(time);\n \
    \   vc<tuple<int, int, X>> dat;\n    for (auto&& [x, A]: ADD) {\n      vc<int>\
    \ B;\n      if (RM.count(x)) {\n        B = RM[x];\n        RM.erase(x);\n   \
    \   }\n      if (len(B) < len(A)) B.eb(time);\n      assert(len(A) == len(B));\n\
    \n      sort(all(A));\n      sort(all(B));\n      FOR(i, len(A)) {\n        assert(A[i]\
    \ <= B[i]);\n        if (A[i] < B[i]) dat.eb(A[i], B[i], x);\n      }\n    }\n\
    \    assert(len(RM) == 0);\n    return dat;\n  }\n\nprivate:\n  void add_monotone(int\
    \ time, X x) {\n    assert(!MP.count(x));\n    MP[x] = time;\n  }\n  void remove_monotone(int\
    \ time, X x) {\n    auto it = MP.find(x);\n    assert(it != MP.end());\n    int\
    \ t = (*it).se;\n    MP.erase(it);\n    if (t == time) return;\n    dat.eb(t,\
    \ time, x);\n  }\n  vc<tuple<int, int, X>> calc_monotone(int time) {\n    for\
    \ (auto&& [x, t]: MP) {\n      if (t == time) continue;\n      dat.eb(t, time,\
    \ x);\n    }\n    return dat;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/add_remove_query.hpp
  requiredBy: []
  timestamp: '2023-12-29 11:33:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
  - test/2_library_checker/data_structure/add_remove_query.test.cpp
documentation_of: ds/offline_query/add_remove_query.hpp
layout: document
redirect_from:
- /library/ds/offline_query/add_remove_query.hpp
- /library/ds/offline_query/add_remove_query.hpp.html
title: ds/offline_query/add_remove_query.hpp
---
