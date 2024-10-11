---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/sigma_0_sum.hpp
    title: nt/sigma_0_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/sigma_0_sum.test.cpp
    title: test/1_mytest/sigma_0_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc230e.test.cpp
    title: test/5_atcoder/abc230e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/contest/1195/problem/6188
  bundledCode: "#line 1 \"nt/convex_floor_sum.hpp\"\n\n// f: \u51F8, \u975E\u8CA0\
    , \u5358\u8ABF\u5897\u52A0\u3092\u4EEE\u5B9A\n// above(x,y) : y > f(x)\n// slope(x,a,b)\
    \ : f'(x) >= a/b\n// return : sum_[0,N) floor(f(x))\n// https://qoj.ac/contest/1195/problem/6188\n\
    template <typename U, typename ANS_TYPE, typename F1, typename F2>\nANS_TYPE convex_floor_sum(U\
    \ N, F1 above, F2 slope) {\n  if (N == 0) return 0;\n  auto check = [&](U x, U\
    \ y) -> bool { return x < N && above(x, y); };\n\n  using T = ANS_TYPE;\n  auto\
    \ max_add = [&](auto f, U& a, U& b, U c, U d) -> void {\n    auto dfs = [&](auto&\
    \ dfs, U c, U d) -> void {\n      if (!f(a + c, b + d)) return;\n      a += c,\
    \ b += d, dfs(dfs, c + c, d + d);\n      if (f(a + c, b + d)) a += c, b += d;\n\
    \    };\n    dfs(dfs, c, d);\n  };\n\n  assert(!above(0, 0));\n  U x = 0, y =\
    \ 0;\n  max_add([&](U x, U y) -> bool { return !above(x, y); }, x, y, 0, 1);\n\
    \  ++y;\n  T ANS = 2 * (y - 1); //  [0,1) x [1,y)\n\n  auto add_ANS = [&](U& x,\
    \ U& y, U a, U b) -> void {\n    U x0 = x, y0 = y;\n    max_add(check, x, y, a,\
    \ b);\n    U n = (x - x0) / a;\n    //  (x0,y0) to (x,y)\n    ANS += 2 * (y0 -\
    \ 1) * (x - x0);\n    ANS += (x - x0 + 1) * (y - y0 + 1) - (n + 1);\n  };\n\n\
    \  add_ANS(x, y, 1, 0);\n  vc<tuple<U, U, U, U>> SBT;\n  SBT.eb(1, 0, 0, 1);\n\
    \  while (x < N - 1) {\n    U a, b, c, d;\n    tie(a, b, c, d) = SBT.back();\n\
    \    if (!check(x + c, y + d)) {\n      POP(SBT);\n      continue;\n    }\n  \
    \  auto f = [&](u64 a, u64 b) -> bool {\n      if (x + a >= N) return 0;\n   \
    \   if (above(x + a, y + b)) return 0;\n      if (slope(x + a, d, c)) return 0;\n\
    \      return 1;\n    };\n    max_add(f, a, b, c, d);\n    if (check(x + a + c,\
    \ y + b + d)) {\n      max_add([&](U a, U b) -> bool { return check(x + a, y +\
    \ b); }, c, d, a, b);\n      SBT.eb(a, b, c, d);\n      continue;\n    }\n   \
    \ add_ANS(x, y, c, d);\n  }\n  ANS /= T(2);\n  return ANS;\n}\n"
  code: "\n// f: \u51F8, \u975E\u8CA0, \u5358\u8ABF\u5897\u52A0\u3092\u4EEE\u5B9A\n\
    // above(x,y) : y > f(x)\n// slope(x,a,b) : f'(x) >= a/b\n// return : sum_[0,N)\
    \ floor(f(x))\n// https://qoj.ac/contest/1195/problem/6188\ntemplate <typename\
    \ U, typename ANS_TYPE, typename F1, typename F2>\nANS_TYPE convex_floor_sum(U\
    \ N, F1 above, F2 slope) {\n  if (N == 0) return 0;\n  auto check = [&](U x, U\
    \ y) -> bool { return x < N && above(x, y); };\n\n  using T = ANS_TYPE;\n  auto\
    \ max_add = [&](auto f, U& a, U& b, U c, U d) -> void {\n    auto dfs = [&](auto&\
    \ dfs, U c, U d) -> void {\n      if (!f(a + c, b + d)) return;\n      a += c,\
    \ b += d, dfs(dfs, c + c, d + d);\n      if (f(a + c, b + d)) a += c, b += d;\n\
    \    };\n    dfs(dfs, c, d);\n  };\n\n  assert(!above(0, 0));\n  U x = 0, y =\
    \ 0;\n  max_add([&](U x, U y) -> bool { return !above(x, y); }, x, y, 0, 1);\n\
    \  ++y;\n  T ANS = 2 * (y - 1); //  [0,1) x [1,y)\n\n  auto add_ANS = [&](U& x,\
    \ U& y, U a, U b) -> void {\n    U x0 = x, y0 = y;\n    max_add(check, x, y, a,\
    \ b);\n    U n = (x - x0) / a;\n    //  (x0,y0) to (x,y)\n    ANS += 2 * (y0 -\
    \ 1) * (x - x0);\n    ANS += (x - x0 + 1) * (y - y0 + 1) - (n + 1);\n  };\n\n\
    \  add_ANS(x, y, 1, 0);\n  vc<tuple<U, U, U, U>> SBT;\n  SBT.eb(1, 0, 0, 1);\n\
    \  while (x < N - 1) {\n    U a, b, c, d;\n    tie(a, b, c, d) = SBT.back();\n\
    \    if (!check(x + c, y + d)) {\n      POP(SBT);\n      continue;\n    }\n  \
    \  auto f = [&](u64 a, u64 b) -> bool {\n      if (x + a >= N) return 0;\n   \
    \   if (above(x + a, y + b)) return 0;\n      if (slope(x + a, d, c)) return 0;\n\
    \      return 1;\n    };\n    max_add(f, a, b, c, d);\n    if (check(x + a + c,\
    \ y + b + d)) {\n      max_add([&](U a, U b) -> bool { return check(x + a, y +\
    \ b); }, c, d, a, b);\n      SBT.eb(a, b, c, d);\n      continue;\n    }\n   \
    \ add_ANS(x, y, c, d);\n  }\n  ANS /= T(2);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/convex_floor_sum.hpp
  requiredBy:
  - nt/sigma_0_sum.hpp
  timestamp: '2024-08-28 14:07:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/5_atcoder/abc230e.test.cpp
  - test/1_mytest/sigma_0_sum.test.cpp
documentation_of: nt/convex_floor_sum.hpp
layout: document
redirect_from:
- /library/nt/convex_floor_sum.hpp
- /library/nt/convex_floor_sum.hpp.html
title: nt/convex_floor_sum.hpp
---
