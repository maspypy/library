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
    - https://codeforces.com/contest/60/problem/D
  bundledCode: "#line 1 \"nt/pytagorean_triple.hpp\"\n\n/*\nc <= LIM, (a,b,c) \u3068\
    \ (b,a,c) \u306F\u540C\u4E00\u8996, O(LIM) \u6642\u9593\n\u30FBLIM = 10^8\uFF1A\
    \u4E92\u3044\u306B\u7D20 1.59*10^7 \u500B, 0.13sec\n\u30FBLIM = 10^8\uFF1A\u5168\
    \u90E8 2.71*10^8 \u500B, 0.53sec\nhttps://codeforces.com/contest/60/problem/D\n\
    */\ntemplate <bool coprime_only, typename F>\nvoid enumerate_pytagorean_triple(int\
    \ LIM, F f) {\n  vc<tuple<int, int, int>> que;\n  auto add = [&](int a, int b,\
    \ int c) -> void {\n    if (c <= LIM) que.eb(a, b, c);\n  };\n  add(3, 4, 5);\n\
    \  while (len(que)) {\n    auto [a, b, c] = POP(que);\n    add(a - 2 * b + 2 *\
    \ c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c);\n    add(a + 2 * b + 2 * c, 2\
    \ * a + b + 2 * c, 2 * a + 2 * b + 3 * c);\n    add(-a + 2 * b + 2 * c, -2 * a\
    \ + b + 2 * c, -2 * a + 2 * b + 3 * c);\n    if constexpr (coprime_only) {\n \
    \     f(a, b, c);\n    } else {\n      int x = a, y = b, z = c;\n      while (z\
    \ <= LIM) {\n        f(x, y, z);\n        x += a, y += b, z += c;\n      }\n \
    \   }\n  }\n}\n"
  code: "\n/*\nc <= LIM, (a,b,c) \u3068 (b,a,c) \u306F\u540C\u4E00\u8996, O(LIM) \u6642\
    \u9593\n\u30FBLIM = 10^8\uFF1A\u4E92\u3044\u306B\u7D20 1.59*10^7 \u500B, 0.13sec\n\
    \u30FBLIM = 10^8\uFF1A\u5168\u90E8 2.71*10^8 \u500B, 0.53sec\nhttps://codeforces.com/contest/60/problem/D\n\
    */\ntemplate <bool coprime_only, typename F>\nvoid enumerate_pytagorean_triple(int\
    \ LIM, F f) {\n  vc<tuple<int, int, int>> que;\n  auto add = [&](int a, int b,\
    \ int c) -> void {\n    if (c <= LIM) que.eb(a, b, c);\n  };\n  add(3, 4, 5);\n\
    \  while (len(que)) {\n    auto [a, b, c] = POP(que);\n    add(a - 2 * b + 2 *\
    \ c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c);\n    add(a + 2 * b + 2 * c, 2\
    \ * a + b + 2 * c, 2 * a + 2 * b + 3 * c);\n    add(-a + 2 * b + 2 * c, -2 * a\
    \ + b + 2 * c, -2 * a + 2 * b + 3 * c);\n    if constexpr (coprime_only) {\n \
    \     f(a, b, c);\n    } else {\n      int x = a, y = b, z = c;\n      while (z\
    \ <= LIM) {\n        f(x, y, z);\n        x += a, y += b, z += c;\n      }\n \
    \   }\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/pytagorean_triple.hpp
  requiredBy: []
  timestamp: '2023-10-06 05:10:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/pytagorean_triple.hpp
layout: document
redirect_from:
- /library/nt/pytagorean_triple.hpp
- /library/nt/pytagorean_triple.hpp.html
title: nt/pytagorean_triple.hpp
---
