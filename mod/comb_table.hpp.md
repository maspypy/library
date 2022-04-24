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
  bundledCode: "#line 1 \"mod/comb_table.hpp\"\n\ntemplate <typename T>\nvvc<T> comb_table(int\
    \ H, int W) {\n  vv(T, C, H + 1, W + 1);\n  C[0][0] = 1;\n  FOR(x, H) {\n    C[x\
    \ + 1] = C[x];\n    FOR(y, W) C[x + 1][y + 1] += C[x][y];\n  }\n  return C;\n\
    }\n"
  code: "\ntemplate <typename T>\nvvc<T> comb_table(int H, int W) {\n  vv(T, C, H\
    \ + 1, W + 1);\n  C[0][0] = 1;\n  FOR(x, H) {\n    C[x + 1] = C[x];\n    FOR(y,\
    \ W) C[x + 1][y + 1] += C[x][y];\n  }\n  return C;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/comb_table.hpp
  requiredBy: []
  timestamp: '2022-04-24 22:50:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/comb_table.hpp
layout: document
redirect_from:
- /library/mod/comb_table.hpp
- /library/mod/comb_table.hpp.html
title: mod/comb_table.hpp
---
