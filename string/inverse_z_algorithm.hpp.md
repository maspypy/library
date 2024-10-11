---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_d
  bundledCode: "#line 1 \"string/inverse_z_algorithm.hpp\"\n\n// https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_d\n\
    // empty OR \u8F9E\u66F8\u9806\u6700\u5C0F\nvc<int> inverse_z_algorithm(vc<int>\
    \ Z) {\n  int N = len(Z);\n  if (Z[0] != N) return {};\n  UnionFind uf(N);\n \
    \ vvc<int> NEQ(N);\n  int i = 1, j = 0;\n  while (i < N) {\n    while (i + j <\
    \ N) {\n      if (Z[i] != j) {\n        uf.merge(j, i + j), ++j;\n      } else\
    \ {\n        NEQ[j].eb(i + j), NEQ[i + j].eb(j);\n        break;\n      }\n  \
    \  }\n    if (Z[i] != j) return {};\n    if (j == 0) {\n      ++i;\n      continue;\n\
    \    }\n    int k = 1;\n    while (i + k < N && k + Z[k] < j) {\n      if (Z[i\
    \ + k] != Z[k]) return {};\n      ++k;\n    }\n    i += k, j -= k;\n  }\n  vvc<int>\
    \ vs(N);\n  FOR(v, N) vs[uf[v]].eb(v);\n  vc<int> ANS(N, -1);\n  FOR(v, N) {\n\
    \    int r = uf[v];\n    if (ANS[r] != -1) continue;\n    vc<int> tmp;\n    for\
    \ (auto& w: vs[r]) {\n      for (auto& to: NEQ[w]) {\n        if (ANS[to] != -1)\
    \ tmp.eb(ANS[to]);\n      }\n    }\n    int x = mex(tmp);\n    for (auto& w: vs[r])\
    \ ANS[w] = x;\n  }\n  return ANS;\n}\n"
  code: "\n// https://atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_d\n\
    // empty OR \u8F9E\u66F8\u9806\u6700\u5C0F\nvc<int> inverse_z_algorithm(vc<int>\
    \ Z) {\n  int N = len(Z);\n  if (Z[0] != N) return {};\n  UnionFind uf(N);\n \
    \ vvc<int> NEQ(N);\n  int i = 1, j = 0;\n  while (i < N) {\n    while (i + j <\
    \ N) {\n      if (Z[i] != j) {\n        uf.merge(j, i + j), ++j;\n      } else\
    \ {\n        NEQ[j].eb(i + j), NEQ[i + j].eb(j);\n        break;\n      }\n  \
    \  }\n    if (Z[i] != j) return {};\n    if (j == 0) {\n      ++i;\n      continue;\n\
    \    }\n    int k = 1;\n    while (i + k < N && k + Z[k] < j) {\n      if (Z[i\
    \ + k] != Z[k]) return {};\n      ++k;\n    }\n    i += k, j -= k;\n  }\n  vvc<int>\
    \ vs(N);\n  FOR(v, N) vs[uf[v]].eb(v);\n  vc<int> ANS(N, -1);\n  FOR(v, N) {\n\
    \    int r = uf[v];\n    if (ANS[r] != -1) continue;\n    vc<int> tmp;\n    for\
    \ (auto& w: vs[r]) {\n      for (auto& to: NEQ[w]) {\n        if (ANS[to] != -1)\
    \ tmp.eb(ANS[to]);\n      }\n    }\n    int x = mex(tmp);\n    for (auto& w: vs[r])\
    \ ANS[w] = x;\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/inverse_z_algorithm.hpp
  requiredBy: []
  timestamp: '2024-10-11 20:53:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/inverse_z_algorithm.hpp
layout: document
redirect_from:
- /library/string/inverse_z_algorithm.hpp
- /library/string/inverse_z_algorithm.hpp.html
title: string/inverse_z_algorithm.hpp
---
