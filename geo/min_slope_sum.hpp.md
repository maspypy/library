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
    - https://uoj.ac/contest/104/problem/1037
  bundledCode: "#line 1 \"geo/min_slope_sum.hpp\"\n\n// https://uoj.ac/contest/104/problem/1037\n\
    // A, B \u304C\u4E0B\u5074\u51F8\u5305\u306B\u306A\u3063\u3066\u3044\u3066 A[i]+B[j]\
    \ \u306E x \u5EA7\u6A19\u304C\u6B63\u3067\u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\
    \n// A[i]+B[j] \u306E min slope \u3092\u6C42\u3081\u308B. O(log N+log M)\ntemplate\
    \ <typename P>\nP min_slope_sum(vc<P>& A, vc<P>& B) {\n  int N = len(A), M = len(B);\n\
    \  ll NL = 0, NR = N;\n  ll ML = 0, MR = M;\n\n  auto better = [&](P p, P q) ->\
    \ bool { return p.y * q.x < q.y * p.x; };\n\n  while (NL + 1 < NR && ML + 1 <\
    \ MR) {\n    ll n = (NL + NR) / 2;\n    ll m = (ML + MR) / 2;\n    P p = A[n]\
    \ + B[m];\n    P pa = A[n] - A[n - 1];\n    P pb = B[m] - B[m - 1];\n    if (better(pa,\
    \ pb)) {\n      if (better(pb, p)) {\n        NL = n;\n      } else {\n      \
    \  MR = m;\n      }\n    } else {\n      if (better(pa, p)) {\n        ML = m;\n\
    \      } else {\n        NR = n;\n      }\n    }\n  }\n  while (ML + 1 < MR) {\n\
    \    ll n = NL, m = (ML + MR) / 2;\n    P p = A[n] + B[m];\n    (better(p, A[n]\
    \ + B[m - 1]) ? ML : MR) = m;\n  }\n  while (NL + 1 < NR) {\n    ll m = ML, n\
    \ = (NL + NR) / 2;\n    P p = A[n] + B[m];\n    (better(p, A[n - 1] + B[m]) ?\
    \ NL : NR) = n;\n  }\n  return A[NL] + B[ML];\n}\n"
  code: "\n// https://uoj.ac/contest/104/problem/1037\n// A, B \u304C\u4E0B\u5074\u51F8\
    \u5305\u306B\u306A\u3063\u3066\u3044\u3066 A[i]+B[j] \u306E x \u5EA7\u6A19\u304C\
    \u6B63\u3067\u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\n// A[i]+B[j] \u306E min\
    \ slope \u3092\u6C42\u3081\u308B. O(log N+log M)\ntemplate <typename P>\nP min_slope_sum(vc<P>&\
    \ A, vc<P>& B) {\n  int N = len(A), M = len(B);\n  ll NL = 0, NR = N;\n  ll ML\
    \ = 0, MR = M;\n\n  auto better = [&](P p, P q) -> bool { return p.y * q.x < q.y\
    \ * p.x; };\n\n  while (NL + 1 < NR && ML + 1 < MR) {\n    ll n = (NL + NR) /\
    \ 2;\n    ll m = (ML + MR) / 2;\n    P p = A[n] + B[m];\n    P pa = A[n] - A[n\
    \ - 1];\n    P pb = B[m] - B[m - 1];\n    if (better(pa, pb)) {\n      if (better(pb,\
    \ p)) {\n        NL = n;\n      } else {\n        MR = m;\n      }\n    } else\
    \ {\n      if (better(pa, p)) {\n        ML = m;\n      } else {\n        NR =\
    \ n;\n      }\n    }\n  }\n  while (ML + 1 < MR) {\n    ll n = NL, m = (ML + MR)\
    \ / 2;\n    P p = A[n] + B[m];\n    (better(p, A[n] + B[m - 1]) ? ML : MR) = m;\n\
    \  }\n  while (NL + 1 < NR) {\n    ll m = ML, n = (NL + NR) / 2;\n    P p = A[n]\
    \ + B[m];\n    (better(p, A[n - 1] + B[m]) ? NL : NR) = n;\n  }\n  return A[NL]\
    \ + B[ML];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/min_slope_sum.hpp
  requiredBy: []
  timestamp: '2026-02-03 22:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/min_slope_sum.hpp
layout: document
redirect_from:
- /library/geo/min_slope_sum.hpp
- /library/geo/min_slope_sum.hpp.html
title: geo/min_slope_sum.hpp
---
