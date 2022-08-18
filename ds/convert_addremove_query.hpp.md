---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/add_remove_query.test.cpp
    title: test/library_checker/add_remove_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/convert_addremove_query.hpp\"\n/*\n\u30FB\u6642\u523B\
    \ t \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u30FB\u6642\u523B t \u306B x \u3092\
    \u524A\u9664\u3059\u308B\n\u304C\u3042\u308B\u3068\u304D\u306B\u3001\n\u30FB\u6642\
    \u523B [l, r) \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u306B\u5909\u63DB\u3059\
    \u308B\n*/\ntemplate <typename X>\nstruct AddRemove_Query {\n  map<X, vc<int>>\
    \ ADD;\n  map<X, vc<int>> RM;\n\n  void add(int time, X x) { ADD[x].eb(time);\
    \ }\n  void remove(int time, X x) { RM[x].eb(time); }\n\n  // \u3059\u3079\u3066\
    \u306E\u30AF\u30A8\u30EA\u304C\u7D42\u308F\u3063\u305F\u73FE\u5728\u6642\u523B\
    \u3092\u6E21\u3059\n  vc<tuple<int, int, X>> calc(int time) {\n    vc<tuple<int,\
    \ int, X>> dat;\n    for (auto&& [x, A]: ADD) {\n      vc<int> B;\n      if (RM.count(x))\
    \ {\n        B = RM[x];\n        RM.erase(x);\n      }\n      if (len(B) < len(A))\
    \ B.eb(time);\n      assert(len(A) == len(B));\n\n      sort(all(A));\n      sort(all(B));\n\
    \      FOR(i, len(A)) {\n        assert(A[i] <= B[i]);\n        if (A[i] < B[i])\
    \ dat.eb(A[i], B[i], x);\n      }\n    }\n    assert(len(RM) == 0);\n    return\
    \ dat;\n  }\n};\n"
  code: "/*\n\u30FB\u6642\u523B t \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u30FB\u6642\
    \u523B t \u306B x \u3092\u524A\u9664\u3059\u308B\n\u304C\u3042\u308B\u3068\u304D\
    \u306B\u3001\n\u30FB\u6642\u523B [l, r) \u306B x \u3092\u8FFD\u52A0\u3059\u308B\
    \n\u306B\u5909\u63DB\u3059\u308B\n*/\ntemplate <typename X>\nstruct AddRemove_Query\
    \ {\n  map<X, vc<int>> ADD;\n  map<X, vc<int>> RM;\n\n  void add(int time, X x)\
    \ { ADD[x].eb(time); }\n  void remove(int time, X x) { RM[x].eb(time); }\n\n \
    \ // \u3059\u3079\u3066\u306E\u30AF\u30A8\u30EA\u304C\u7D42\u308F\u3063\u305F\u73FE\
    \u5728\u6642\u523B\u3092\u6E21\u3059\n  vc<tuple<int, int, X>> calc(int time)\
    \ {\n    vc<tuple<int, int, X>> dat;\n    for (auto&& [x, A]: ADD) {\n      vc<int>\
    \ B;\n      if (RM.count(x)) {\n        B = RM[x];\n        RM.erase(x);\n   \
    \   }\n      if (len(B) < len(A)) B.eb(time);\n      assert(len(A) == len(B));\n\
    \n      sort(all(A));\n      sort(all(B));\n      FOR(i, len(A)) {\n        assert(A[i]\
    \ <= B[i]);\n        if (A[i] < B[i]) dat.eb(A[i], B[i], x);\n      }\n    }\n\
    \    assert(len(RM) == 0);\n    return dat;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/convert_addremove_query.hpp
  requiredBy: []
  timestamp: '2022-08-18 21:11:08+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/add_remove_query.test.cpp
documentation_of: ds/convert_addremove_query.hpp
layout: document
redirect_from:
- /library/ds/convert_addremove_query.hpp
- /library/ds/convert_addremove_query.hpp.html
title: ds/convert_addremove_query.hpp
---
