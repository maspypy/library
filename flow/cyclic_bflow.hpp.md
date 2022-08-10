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
    - https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_4
  bundledCode: "#line 1 \"flow/cyclic_bflow.hpp\"\n/*\n\u5186\u74B0\u4E0A\u306E MCF\u3002\
    \ncost[i]\uFF1Ai \u2192 i+1 \u306E\u30B3\u30B9\u30C8\nhttps://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_4\n\
    */\ntemplate <typename CAP, typename COST>\nCOST cyclic_bflow(vc<CAP> supply,\
    \ vc<COST> cost) {\n  const int N = len(supply);\n  if (N == 0) return 0;\n  assert(SUM(supply)\
    \ == 0);\n  auto f = [&](ll x) -> ll {\n    // N-1 \u2192 0 \u306E\u79FB\u52D5\
    \u304C x\n    ll res = abs(x) * cost.back();\n    FOR(i, N - 1) {\n      // \u53F3\
    \u306B\u51FA\u308B\u91CF\u306F\uFF1F\n      x += supply[i];\n      res += abs(x)\
    \ * cost[i];\n    }\n    return res;\n  };\n\n  auto check = [&](ll x) -> bool\
    \ { return f(x) <= f(x + 1); };\n  ll LIM = 5;\n  for (auto&& x: supply) LIM +=\
    \ max<ll>(x, 0);\n  ll x = binary_search(check, LIM, -LIM);\n  return f(x);\n\
    }\n"
  code: "/*\n\u5186\u74B0\u4E0A\u306E MCF\u3002\ncost[i]\uFF1Ai \u2192 i+1 \u306E\u30B3\
    \u30B9\u30C8\nhttps://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_4\n\
    */\ntemplate <typename CAP, typename COST>\nCOST cyclic_bflow(vc<CAP> supply,\
    \ vc<COST> cost) {\n  const int N = len(supply);\n  if (N == 0) return 0;\n  assert(SUM(supply)\
    \ == 0);\n  auto f = [&](ll x) -> ll {\n    // N-1 \u2192 0 \u306E\u79FB\u52D5\
    \u304C x\n    ll res = abs(x) * cost.back();\n    FOR(i, N - 1) {\n      // \u53F3\
    \u306B\u51FA\u308B\u91CF\u306F\uFF1F\n      x += supply[i];\n      res += abs(x)\
    \ * cost[i];\n    }\n    return res;\n  };\n\n  auto check = [&](ll x) -> bool\
    \ { return f(x) <= f(x + 1); };\n  ll LIM = 5;\n  for (auto&& x: supply) LIM +=\
    \ max<ll>(x, 0);\n  ll x = binary_search(check, LIM, -LIM);\n  return f(x);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/cyclic_bflow.hpp
  requiredBy: []
  timestamp: '2022-08-11 02:13:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/cyclic_bflow.hpp
layout: document
redirect_from:
- /library/flow/cyclic_bflow.hpp
- /library/flow/cyclic_bflow.hpp.html
title: flow/cyclic_bflow.hpp
---
