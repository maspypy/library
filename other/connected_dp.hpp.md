---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/yuki1561_dp.test.cpp
    title: test/mytest/yuki1561_dp.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/connected_dp.hpp\"\n// pair<\u65B0\u3057\u3044\u72B6\
    \u614B\u3001\u4ECA\u306E\u6210\u5206 \u2192 \u65B0\u3057\u3044\u6210\u5206>\n\
    vc<pair<vc<int>, vc<int>>> connected_dp_next_states(vc<int> now) {\n  int N =\
    \ len(now);\n  vc<pair<vc<int>, vc<int>>> res;\n  FOR(s, 1 << N) {\n    vc<int>\
    \ par(N + N);\n    FOR(i, N) par[i] = (s & 1 << i ? i : -1);\n    FOR(i, N) par[N\
    \ + i] = (now[i] == -1 ? -1 : now[i] + N);\n    auto find = [&](int x) -> int\
    \ {\n      while (par[x] != x) { x = par[x] = par[par[x]]; }\n      return x;\n\
    \    };\n    auto merge = [&](int a, int b) -> void {\n      a = find(a), b =\
    \ find(b);\n      if (a == b) return;\n      if (a > b) swap(a, b);\n      par[b]\
    \ = a;\n    };\n\n    FOR(i, N - 1) if (par[i] != -1 && par[i + 1] != -1) merge(i,\
    \ i + 1);\n    FOR(i, N) if (par[i] != -1 && par[N + i] != -1) merge(i, N + i);\n\
    \    FOR(i, N + N) if (par[i] != -1) par[i] = find(i);\n    FOR(i, N, N + N) if\
    \ (par[i] >= N) par[i] = -1;\n    res.eb(vc<int>(par.begin(), par.begin() + N),\n\
    \           vc<int>(par.begin() + N, par.end()));\n  }\n  return res;\n}\n"
  code: "// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\u4ECA\u306E\u6210\u5206 \u2192\
    \ \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>, vc<int>>> connected_dp_next_states(vc<int>\
    \ now) {\n  int N = len(now);\n  vc<pair<vc<int>, vc<int>>> res;\n  FOR(s, 1 <<\
    \ N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i] = (s & 1 << i ? i : -1);\n\
    \    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i] + N);\n    auto find =\
    \ [&](int x) -> int {\n      while (par[x] != x) { x = par[x] = par[par[x]]; }\n\
    \      return x;\n    };\n    auto merge = [&](int a, int b) -> void {\n     \
    \ a = find(a), b = find(b);\n      if (a == b) return;\n      if (a > b) swap(a,\
    \ b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1) if (par[i] != -1 && par[i\
    \ + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i] != -1 && par[N + i] !=\
    \ -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] != -1) par[i] = find(i);\n\
    \    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n    res.eb(vc<int>(par.begin(),\
    \ par.begin() + N),\n           vc<int>(par.begin() + N, par.end()));\n  }\n \
    \ return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/connected_dp.hpp
  requiredBy: []
  timestamp: '2022-10-24 17:16:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/yuki1561_dp.test.cpp
documentation_of: other/connected_dp.hpp
layout: document
redirect_from:
- /library/other/connected_dp.hpp
- /library/other/connected_dp.hpp.html
title: other/connected_dp.hpp
---
