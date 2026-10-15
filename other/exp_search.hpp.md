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
    - https://github.com/maspypy/library/blob/main/other/exp_search.hpp
  bundledCode: "#line 1 \"other/exp_search.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/exp_search.hpp\n\
    // find max true\ntemplate <typename F>\nll exp_search(F&& check, ll ok) {\n \
    \ ll d = 1;\n  while (check(ok + d)) {\n    ok += d;\n    d += d;\n  }\n  ll ng\
    \ = ok + d;\n  while (ok + 1 < ng) {\n    ll x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/other/exp_search.hpp\n\
    // find max true\ntemplate <typename F>\nll exp_search(F&& check, ll ok) {\n \
    \ ll d = 1;\n  while (check(ok + d)) {\n    ok += d;\n    d += d;\n  }\n  ll ng\
    \ = ok + d;\n  while (ok + 1 < ng) {\n    ll x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/exp_search.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/exp_search.hpp
layout: document
redirect_from:
- /library/other/exp_search.hpp
- /library/other/exp_search.hpp.html
title: other/exp_search.hpp
---
