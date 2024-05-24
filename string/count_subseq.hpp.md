---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/string/number_of_subsequences.test.cpp
    title: test/library_checker/string/number_of_subsequences.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1493.test.cpp
    title: test/yukicoder/1493.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/26/135340
  bundledCode: "#line 1 \"string/count_subseq.hpp\"\n// https://noshi91.hatenablog.com/entry/2023/02/26/135340\n\
    template <typename mint, typename STRING>\nmint count_subseq(STRING& S) {\n  map<int,\
    \ mint> dp;\n  mint sm = 1;\n  for (auto&& x: S) {\n    auto it = dp.find(x);\n\
    \    if (it == dp.end()) {\n      dp[x] = sm;\n      sm += sm;\n    } else {\n\
    \      mint d = (*it).se;\n      (*it).se = sm;\n      sm += sm - d;\n    }\n\
    \  }\n  return sm;\n}\n"
  code: "// https://noshi91.hatenablog.com/entry/2023/02/26/135340\ntemplate <typename\
    \ mint, typename STRING>\nmint count_subseq(STRING& S) {\n  map<int, mint> dp;\n\
    \  mint sm = 1;\n  for (auto&& x: S) {\n    auto it = dp.find(x);\n    if (it\
    \ == dp.end()) {\n      dp[x] = sm;\n      sm += sm;\n    } else {\n      mint\
    \ d = (*it).se;\n      (*it).se = sm;\n      sm += sm - d;\n    }\n  }\n  return\
    \ sm;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/count_subseq.hpp
  requiredBy: []
  timestamp: '2023-10-17 19:59:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/string/number_of_subsequences.test.cpp
  - test/yukicoder/1493.test.cpp
documentation_of: string/count_subseq.hpp
layout: document
redirect_from:
- /library/string/count_subseq.hpp
- /library/string/count_subseq.hpp.html
title: string/count_subseq.hpp
---
