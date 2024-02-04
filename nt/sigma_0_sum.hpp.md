---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc230e.test.cpp
    title: test_atcoder/abc230e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/sigma_0_sum.hpp\"\n// sum_[1,N] sigma_0(n)\nll sigma_0_sum(ll\
    \ N) {\n  assert(N <= (1LL << 50));\n  ll sq = sqrtl(N);\n  ll ANS = 0;\n  for\
    \ (int d = 1; d <= sq; ++d) { ANS += ll(double(N) / d); }\n  return 2 * ANS -\
    \ sq * sq;\n}\n"
  code: "// sum_[1,N] sigma_0(n)\nll sigma_0_sum(ll N) {\n  assert(N <= (1LL << 50));\n\
    \  ll sq = sqrtl(N);\n  ll ANS = 0;\n  for (int d = 1; d <= sq; ++d) { ANS +=\
    \ ll(double(N) / d); }\n  return 2 * ANS - sq * sq;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/sigma_0_sum.hpp
  requiredBy: []
  timestamp: '2023-02-16 20:33:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc230e.test.cpp
documentation_of: nt/sigma_0_sum.hpp
layout: document
redirect_from:
- /library/nt/sigma_0_sum.hpp
- /library/nt/sigma_0_sum.hpp.html
title: nt/sigma_0_sum.hpp
---
