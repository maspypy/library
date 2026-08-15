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
  bundledCode: "#line 1 \"mod/range_freq_mod.hpp\"\n// count x in [L,R) such that\
    \ (x mod mod) in [lo,hi)\ntemplate <typename I>\nI range_freq_mod(I L, I R, I\
    \ lo, I hi, I mod) {\n  assert(0 <= lo && lo <= hi && hi <= mod);\n  auto f =\
    \ [&](I x) -> I {\n    auto [q, r] = divmod<I>(x, mod);\n    I a = max<I>(lo,\
    \ 0), b = min<I>(hi, r);\n    return q * (hi - lo) + max<I>(b - a, 0);\n  };\n\
    \  return f(R) - f(L);\n}\n"
  code: "// count x in [L,R) such that (x mod mod) in [lo,hi)\ntemplate <typename\
    \ I>\nI range_freq_mod(I L, I R, I lo, I hi, I mod) {\n  assert(0 <= lo && lo\
    \ <= hi && hi <= mod);\n  auto f = [&](I x) -> I {\n    auto [q, r] = divmod<I>(x,\
    \ mod);\n    I a = max<I>(lo, 0), b = min<I>(hi, r);\n    return q * (hi - lo)\
    \ + max<I>(b - a, 0);\n  };\n  return f(R) - f(L);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/range_freq_mod.hpp
  requiredBy: []
  timestamp: '2026-08-15 15:50:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/range_freq_mod.hpp
layout: document
redirect_from:
- /library/mod/range_freq_mod.hpp
- /library/mod/range_freq_mod.hpp.html
title: mod/range_freq_mod.hpp
---
