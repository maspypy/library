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
  bundledCode: "#line 2 \"alg/monoid_cntmaxmaxcnt.hpp\"\n// \u5168\u4F53\u306E\u500B\
    \u6570\u3001\u6700\u5927\u5024\u3001\u6700\u5927\u5024\u306E\u500B\u6570\r\ntemplate\
    \ <ll INF>\r\nstruct Monoid_CntMaxMaxcnt {\r\n  using value_type = tuple<ll, ll,\
    \ ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xcnt,\
    \ xmax, xmaxcnt] = x;\r\n    auto [ycnt, ymax, ymaxcnt] = y;\r\n    if (xmax <\
    \ ymax) return {xcnt + ycnt, ymax, ymaxcnt};\r\n    if (xmax == ymax) return {xcnt\
    \ + ycnt, xmax, xmaxcnt + ymaxcnt};\r\n    return {xcnt + ycnt, xmax, xmaxcnt};\r\
    \n  }\r\n  static constexpr X unit() { return {0, -INF, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\n"
  code: "#pragma once\r\n// \u5168\u4F53\u306E\u500B\u6570\u3001\u6700\u5927\u5024\
    \u3001\u6700\u5927\u5024\u306E\u500B\u6570\r\ntemplate <ll INF>\r\nstruct Monoid_CntMaxMaxcnt\
    \ {\r\n  using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) {\r\n    auto [xcnt, xmax, xmaxcnt] = x;\r\n    auto\
    \ [ycnt, ymax, ymaxcnt] = y;\r\n    if (xmax < ymax) return {xcnt + ycnt, ymax,\
    \ ymaxcnt};\r\n    if (xmax == ymax) return {xcnt + ycnt, xmax, xmaxcnt + ymaxcnt};\r\
    \n    return {xcnt + ycnt, xmax, xmaxcnt};\r\n  }\r\n  static constexpr X unit()\
    \ { return {0, -INF, 0}; }\r\n  static constexpr bool commute = true;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_cntmaxmaxcnt.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_cntmaxmaxcnt.hpp
layout: document
redirect_from:
- /library/alg/monoid_cntmaxmaxcnt.hpp
- /library/alg/monoid_cntmaxmaxcnt.hpp.html
title: alg/monoid_cntmaxmaxcnt.hpp
---
