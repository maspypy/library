---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/alien.hpp
    title: convex/alien.hpp
  - icon: ':question:'
    path: convex/monge/monge_shortest_path.hpp
    title: convex/monge/monge_shortest_path.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/monge/monge_shortest_path_d_edge.hpp\"\n\n#line 2\
    \ \"convex/alien.hpp\"\n\n// T \u306F\u6574\u6570\u578B\u3092\u4EEE\u5B9A\n//\
    \ solve(penalty) -> {val, cnt}\n// lo: cnt > K, hi: cnt <= K\n// return: ans,\
    \ pena\ntemplate <typename T, typename F>\npair<T, T> alien_trick(int N, int K,\
    \ T lo, T hi, F solve) {\n  while (lo + 1 < hi) {\n    T mid = lo + (hi - lo)\
    \ / 2;\n    auto [val, cnt] = solve(mid);\n    (cnt <= K ? hi : lo) = mid;\n \
    \ }\n  auto [val, cnt] = solve(hi);\n  return {val - hi * K, hi};\n}\n\ntemplate\
    \ <typename T, typename F>\npair<T, T> alien_trick_auto_search_range(int N, int\
    \ K, F solve) {\n  T lo = 0, hi = 0;\n  int c0 = solve(0).se;\n  if (c0 <= K)\
    \ {\n    lo = -1, hi = 0;\n    while (solve(lo).se < K) {\n      T d = hi - lo;\n\
    \      lo -= 2 * d, hi -= d;\n    }\n  } else {\n    lo = 0, hi = 1;\n    while\
    \ (solve(hi).se > K) {\n      T d = hi - lo;\n      lo += d, hi += 2 * d;\n  \
    \  }\n  }\n  return alien_trick(N, K, lo, hi, solve);\n}\n#line 2 \"convex/monge/monge_shortest_path.hpp\"\
    \n\ntemplate <typename T>\nstruct Monge_Shortest_Path {\n  vc<T> dp;\n  vc<int>\
    \ cnt, frm;\n\n  template <typename F>\n  T solve(int N, F f, bool minimize_cnt\
    \ = true) {\n    dp.assign(N + 1, infty<T>);\n    cnt.assign(N + 1, infty<int>);\n\
    \    frm.assign(N + 1, 0);\n\n    dp[0] = 0;\n    cnt[0] = 0;\n\n    auto better_tie\
    \ = [&](int new_cnt, int old_cnt) -> bool {\n      return minimize_cnt ? new_cnt\
    \ < old_cnt : new_cnt > old_cnt;\n    };\n\n    auto check = [&](int r, int l)\
    \ -> void {\n      T x = dp[l] + f(l, r);\n      int c = cnt[l] + 1;\n      if\
    \ (dp[r] > x || (dp[r] == x && better_tie(c, cnt[r]))) {\n        dp[r] = x;\n\
    \        cnt[r] = c;\n        frm[r] = l;\n      }\n    };\n\n    // simple larsch,\
    \ https://noshi91.hatenablog.com/entry/2023/02/18/005856\n    auto dfs = [&](auto&\
    \ dfs, int l, int r) -> void {\n      if (r - l == 1) return;\n      int m = (l\
    \ + r) / 2;\n\n      FOR(k, frm[l], frm[r] + 1) check(m, k);\n      dfs(dfs, l,\
    \ m);\n\n      FOR(k, l + 1, m + 1) check(r, k);\n      dfs(dfs, m, r);\n    };\n\
    \n    if (N > 0) {\n      check(N, 0);\n      dfs(dfs, 0, N);\n    }\n\n    return\
    \ dp[N];\n  }\n\n  vc<int> restore_path() {\n    int N = len(dp) - 1;\n    vc<int>\
    \ path;\n    for (int v = N; v > 0; v = frm[v]) path.eb(v);\n    path.eb(0);\n\
    \    reverse(all(path));\n    return path;\n  }\n};\n\n// yuki705 \u3067\u306F\
    \ simple larsch \u3088\u308A\u4F4E\u901F\u3060\u3063\u305F\u3057\u4F7F\u308F\u306A\
    \u3044\u60F3\u5B9A\u3067\u3044\u304F\n// #include \"convex/larsch.hpp\"\n// //\
    \ dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n// // \u9077\u79FB\u56DE\u6570\u3092\
    \u554F\u308F\u306A\u3044\n// template <typename T, typename F>\n// vc<T> monge_shortest_path_larsch(int\
    \ N, F f) {\n//   vc<T> dp(N + 1, infty<T>);\n//   dp[0] = 0;\n\n//   auto g =\
    \ [&](int i, int j) -> T {\n//     ++i;\n//     if (i <= j) return infty<T>;\n\
    //     return dp[j] + f(j, i);\n//   };\n\n//   LARSCH<T, decltype(g)> larsch(N,\
    \ g);\n//   FOR(r, 1, N + 1) {\n//     int l = larsch.get_argmin();\n//     dp[r]\
    \ = dp[l] + f(l, r);\n//   }\n//   return dp;\n// }\n#line 5 \"convex/monge/monge_shortest_path_d_edge.hpp\"\
    \n\n// lo: penalty = lo \u3067\u306F cnt > d\n// hi: penalty = hi \u3067\u306F\
    \ cnt <= d\ntemplate <typename T, typename F>\nT monge_shortest_path_d_edge(int\
    \ N, int d, T lo, T hi, F f) {\n  Monge_Shortest_Path<T> solver(N);\n  auto solve\
    \ = [&](T pena) -> pair<T, int> {\n    return solver.solve([&](int l, int r) ->\
    \ T { return f(l, r) + penalty; });\n  };\n  return alien_trick<T>(N, d, lo, hi,\
    \ solve);\n}\n\ntemplate <typename T, typename F>\nT monge_shortest_path_d_edge_auto_search_range(int\
    \ N, int d, T lo, T hi, F f) {\n  Monge_Shortest_Path<T> solver(N);\n  auto solve\
    \ = [&](T pena) -> pair<T, int> {\n    return solver.solve([&](int l, int r) ->\
    \ T { return f(l, r) + penalty; });\n  };\n\n  return alien_trick_auto_search_range<T>(N,\
    \ d, solve);\n}\n"
  code: "#pragma once\n\n#include \"convex/alien.hpp\"\n#include \"convex/monge/monge_shortest_path.hpp\"\
    \n\n// lo: penalty = lo \u3067\u306F cnt > d\n// hi: penalty = hi \u3067\u306F\
    \ cnt <= d\ntemplate <typename T, typename F>\nT monge_shortest_path_d_edge(int\
    \ N, int d, T lo, T hi, F f) {\n  Monge_Shortest_Path<T> solver(N);\n  auto solve\
    \ = [&](T pena) -> pair<T, int> {\n    return solver.solve([&](int l, int r) ->\
    \ T { return f(l, r) + penalty; });\n  };\n  return alien_trick<T>(N, d, lo, hi,\
    \ solve);\n}\n\ntemplate <typename T, typename F>\nT monge_shortest_path_d_edge_auto_search_range(int\
    \ N, int d, T lo, T hi, F f) {\n  Monge_Shortest_Path<T> solver(N);\n  auto solve\
    \ = [&](T pena) -> pair<T, int> {\n    return solver.solve([&](int l, int r) ->\
    \ T { return f(l, r) + penalty; });\n  };\n\n  return alien_trick_auto_search_range<T>(N,\
    \ d, solve);\n}\n"
  dependsOn:
  - convex/alien.hpp
  - convex/monge/monge_shortest_path.hpp
  isVerificationFile: false
  path: convex/monge/monge_shortest_path_d_edge.hpp
  requiredBy: []
  timestamp: '2026-07-28 11:49:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/monge_shortest_path_d_edge.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_shortest_path_d_edge.hpp
- /library/convex/monge/monge_shortest_path_d_edge.hpp.html
title: convex/monge/monge_shortest_path_d_edge.hpp
---
