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
    - https://codeforces.com/contest/1556/problem/H
    - https://page.math.tu-berlin.de/~felsner/Lehre/SemMatS/Literatur/Schrijver-41:MatIntersection.pdf
  bundledCode: "#line 1 \"matroid/matroid_intersection.hpp\"\n\n// https://codeforces.com/contest/1556/problem/H\n\
    // https://page.math.tu-berlin.de/~felsner/Lehre/SemMatS/Literatur/Schrijver-41:MatIntersection.pdf\n\
    // Matroid1: for_rm_add\n// Matroid2: for_add_rm\ntemplate <class Matroid1, class\
    \ Matroid2, typename WT>\nstruct Matroid_Intersection {\n  Matroid1 &M1;\n  Matroid2\
    \ &M2;\n  int N;\n  vc<WT> weight;\n\n  Matroid_Intersection(Matroid1 &M1, Matroid2\
    \ &M2, vc<WT> weight)\n      : M1(M1), M2(M2), weight(weight) {\n    N = M1.size();\n\
    \    assert(N == M2.size());\n    pot.assign(N, 0);\n  }\n\n  // \u30B5\u30A4\u30BA\
    \u3092\u5897\u3084\u305D\u3046\u3068\u3059\u308B\n  // \u5404\u30B5\u30A4\u30BA\
    \u306B\u5BFE\u3057\u3066\u305D\u306E\u30B5\u30A4\u30BA\u3067\u306E\u6700\u5927\
    \u91CD\u307F\u306B\u306A\u308B\uFF08\u5165\u529B\u3082\u305D\u3046\u3067\u3042\
    \u308B\u3053\u3068\u304C\u5FC5\u8981\uFF09\n  bool step(WT &wt, vc<bool> &I) {\n\
    \    WT x = augment(I);\n    wt += x;\n    return x > 0;\n  }\n\n private:\n \
    \ vc<WT> pot, dist;\n  vc<int> par;\n\n  WT augment(vc<bool> &I) {\n    assert(len(I)\
    \ == N);\n    M1.prepare(I), M2.prepare(I);\n    dist.assign(N, infty<WT>);  //\
    \ real_dist = pot + dist\n    par.assign(N, -1);\n    pq_min<pair<WT, int>> que;\n\
    \    FOR(v, N) if (!I[v] && M1.can_add(v)) {\n      dist[v] = -weight[v] - pot[v];\n\
    \      que.emplace(dist[v], v);\n    }\n    int t = -1;\n    WT best = infty<WT>;\n\
    \    while (len(que)) {\n      auto [pri, v] = POP(que);\n      if (pri != dist[v])\
    \ continue;\n      if (M2.can_add(v) && chmin(best, dist[v] + pot[v])) {\n   \
    \     t = v;\n      }\n      if (I[v]) {\n        M1.for_rm_add(v, [&](int w)\
    \ -> void {\n          WT x = -weight[w] + pot[v] - pot[w];\n          assert(x\
    \ >= 0);\n          if (chmin(dist[w], dist[v] + x)) par[w] = v, que.emplace(dist[w],\
    \ w);\n        });\n      } else {\n        M2.for_add_rm(v, [&](int w) -> void\
    \ {\n          WT x = weight[w] + pot[v] - pot[w];\n          assert(x >= 0);\n\
    \          if (chmin(dist[w], dist[v] + x)) par[w] = v, que.emplace(dist[w], w);\n\
    \        });\n      }\n    }\n    if (t == -1) return 0;\n    WT ans = -(pot[t]\
    \ + dist[t]);\n\n    FOR(v, N) if (dist[v] < infty<WT>) pot[v] += dist[v];\n \
    \   vc<WT> w1(N), w2(N);\n    FOR(v, N) {\n      if (I[v]) w1[v] = pot[v], w2[v]\
    \ = weight[v] - pot[v];\n      if (!I[v]) w1[v] = weight[v] + pot[v], w2[v] =\
    \ -pot[v];\n    }\n\n    for (int v = t; v != -1; v = par[v]) I[v] = !I[v];\n\
    \    FOR(v, N) { pot[v] = (I[v] ? w1[v] : -w2[v]); }\n    return ans;\n  }\n};\n"
  code: "\n// https://codeforces.com/contest/1556/problem/H\n// https://page.math.tu-berlin.de/~felsner/Lehre/SemMatS/Literatur/Schrijver-41:MatIntersection.pdf\n\
    // Matroid1: for_rm_add\n// Matroid2: for_add_rm\ntemplate <class Matroid1, class\
    \ Matroid2, typename WT>\nstruct Matroid_Intersection {\n  Matroid1 &M1;\n  Matroid2\
    \ &M2;\n  int N;\n  vc<WT> weight;\n\n  Matroid_Intersection(Matroid1 &M1, Matroid2\
    \ &M2, vc<WT> weight)\n      : M1(M1), M2(M2), weight(weight) {\n    N = M1.size();\n\
    \    assert(N == M2.size());\n    pot.assign(N, 0);\n  }\n\n  // \u30B5\u30A4\u30BA\
    \u3092\u5897\u3084\u305D\u3046\u3068\u3059\u308B\n  // \u5404\u30B5\u30A4\u30BA\
    \u306B\u5BFE\u3057\u3066\u305D\u306E\u30B5\u30A4\u30BA\u3067\u306E\u6700\u5927\
    \u91CD\u307F\u306B\u306A\u308B\uFF08\u5165\u529B\u3082\u305D\u3046\u3067\u3042\
    \u308B\u3053\u3068\u304C\u5FC5\u8981\uFF09\n  bool step(WT &wt, vc<bool> &I) {\n\
    \    WT x = augment(I);\n    wt += x;\n    return x > 0;\n  }\n\n private:\n \
    \ vc<WT> pot, dist;\n  vc<int> par;\n\n  WT augment(vc<bool> &I) {\n    assert(len(I)\
    \ == N);\n    M1.prepare(I), M2.prepare(I);\n    dist.assign(N, infty<WT>);  //\
    \ real_dist = pot + dist\n    par.assign(N, -1);\n    pq_min<pair<WT, int>> que;\n\
    \    FOR(v, N) if (!I[v] && M1.can_add(v)) {\n      dist[v] = -weight[v] - pot[v];\n\
    \      que.emplace(dist[v], v);\n    }\n    int t = -1;\n    WT best = infty<WT>;\n\
    \    while (len(que)) {\n      auto [pri, v] = POP(que);\n      if (pri != dist[v])\
    \ continue;\n      if (M2.can_add(v) && chmin(best, dist[v] + pot[v])) {\n   \
    \     t = v;\n      }\n      if (I[v]) {\n        M1.for_rm_add(v, [&](int w)\
    \ -> void {\n          WT x = -weight[w] + pot[v] - pot[w];\n          assert(x\
    \ >= 0);\n          if (chmin(dist[w], dist[v] + x)) par[w] = v, que.emplace(dist[w],\
    \ w);\n        });\n      } else {\n        M2.for_add_rm(v, [&](int w) -> void\
    \ {\n          WT x = weight[w] + pot[v] - pot[w];\n          assert(x >= 0);\n\
    \          if (chmin(dist[w], dist[v] + x)) par[w] = v, que.emplace(dist[w], w);\n\
    \        });\n      }\n    }\n    if (t == -1) return 0;\n    WT ans = -(pot[t]\
    \ + dist[t]);\n\n    FOR(v, N) if (dist[v] < infty<WT>) pot[v] += dist[v];\n \
    \   vc<WT> w1(N), w2(N);\n    FOR(v, N) {\n      if (I[v]) w1[v] = pot[v], w2[v]\
    \ = weight[v] - pot[v];\n      if (!I[v]) w1[v] = weight[v] + pot[v], w2[v] =\
    \ -pot[v];\n    }\n\n    for (int v = t; v != -1; v = par[v]) I[v] = !I[v];\n\
    \    FOR(v, N) { pot[v] = (I[v] ? w1[v] : -w2[v]); }\n    return ans;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: matroid/matroid_intersection.hpp
  requiredBy: []
  timestamp: '2025-10-13 18:56:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/matroid_intersection.hpp
layout: document
redirect_from:
- /library/matroid/matroid_intersection.hpp
- /library/matroid/matroid_intersection.hpp.html
title: matroid/matroid_intersection.hpp
---
