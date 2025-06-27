---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/number_of_subsequences.test.cpp
    title: test/2_library_checker/string/number_of_subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1493.test.cpp
    title: test/3_yukicoder/1493.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/26/135340
    - https://yukicoder.me/problems/no/2762
  bundledCode: "#line 1 \"string/count_subseq.hpp\"\n// https://noshi91.hatenablog.com/entry/2023/02/26/135340\n\
    // \u884C\u5217\u306B\u3059\u308B\u3068\u304D\u306F\u3001(mp[x]+1) \u306E\u5217\
    \u3092\u6301\u3064\u3068\u5C0F\u3055\u3044\u884C\u5217\u306B\u306A\u308B\u3053\
    \u3068\u304C\u3042\u308B.\n// https://yukicoder.me/problems/no/2762\ntemplate\
    \ <typename mint, typename STRING>\nmint count_subseq(STRING& S) {\n  map<int,\
    \ mint> dp;\n  mint sm = 1;\n  for (auto&& x: S) {\n    auto it = dp.find(x);\n\
    \    if (it == dp.end()) {\n      dp[x] = sm;\n      sm += sm;\n    } else {\n\
    \      mint d = (*it).se;\n      (*it).se = sm;\n      sm += sm - d;\n    }\n\
    \  }\n  return sm;\n}\n"
  code: "// https://noshi91.hatenablog.com/entry/2023/02/26/135340\n// \u884C\u5217\
    \u306B\u3059\u308B\u3068\u304D\u306F\u3001(mp[x]+1) \u306E\u5217\u3092\u6301\u3064\
    \u3068\u5C0F\u3055\u3044\u884C\u5217\u306B\u306A\u308B\u3053\u3068\u304C\u3042\
    \u308B.\n// https://yukicoder.me/problems/no/2762\ntemplate <typename mint, typename\
    \ STRING>\nmint count_subseq(STRING& S) {\n  map<int, mint> dp;\n  mint sm = 1;\n\
    \  for (auto&& x: S) {\n    auto it = dp.find(x);\n    if (it == dp.end()) {\n\
    \      dp[x] = sm;\n      sm += sm;\n    } else {\n      mint d = (*it).se;\n\
    \      (*it).se = sm;\n      sm += sm - d;\n    }\n  }\n  return sm;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/count_subseq.hpp
  requiredBy: []
  timestamp: '2024-06-11 19:43:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/string/number_of_subsequences.test.cpp
  - test/3_yukicoder/1493.test.cpp
documentation_of: string/count_subseq.hpp
layout: document
redirect_from:
- /library/string/count_subseq.hpp
- /library/string/count_subseq.hpp.html
title: string/count_subseq.hpp
---
