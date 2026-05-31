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
  bundledCode: "#line 1 \"convex/monge/alien.hpp\"\n// T \u306F\u6574\u6570\u578B\u3092\
    \u4EEE\u5B9A\n// solve(penalty, minimize_cnt)\n// lo: cnt > K, hi: cnt<=K\ntemplate\
    \ <typename T, typename F>\nT alien_trick(int K, T lo, T hi, F solve) {\n  while\
    \ (lo + 1 < hi) {\n    T mid = (lo + hi) / 2;\n    auto [val, cnt] = solve(mid,\
    \ true);\n    if (cnt <= K) {\n      hi = mid;\n    } else {\n      lo = mid;\n\
    \    }\n  }\n\n  auto [val, cnt] = solve(hi, true);\n  return val - hi * K;\n\
    }\n"
  code: "// T \u306F\u6574\u6570\u578B\u3092\u4EEE\u5B9A\n// solve(penalty, minimize_cnt)\n\
    // lo: cnt > K, hi: cnt<=K\ntemplate <typename T, typename F>\nT alien_trick(int\
    \ K, T lo, T hi, F solve) {\n  while (lo + 1 < hi) {\n    T mid = (lo + hi) /\
    \ 2;\n    auto [val, cnt] = solve(mid, true);\n    if (cnt <= K) {\n      hi =\
    \ mid;\n    } else {\n      lo = mid;\n    }\n  }\n\n  auto [val, cnt] = solve(hi,\
    \ true);\n  return val - hi * K;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/alien.hpp
  requiredBy: []
  timestamp: '2026-05-31 19:49:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/alien.hpp
layout: document
redirect_from:
- /library/convex/monge/alien.hpp
- /library/convex/monge/alien.hpp.html
title: convex/monge/alien.hpp
---
