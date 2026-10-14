---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convex/monge/monge_shortest_path_d_edge.hpp
    title: convex/monge/monge_shortest_path_d_edge.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/monge_shortest_path.test.cpp
    title: test/1_mytest/monge_shortest_path.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/705.test.cpp
    title: test/3_yukicoder/705.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/18/005856
  bundledCode: "#line 1 \"convex/monge/monge_shortest_path.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Monge_Shortest_Path {\n  vc<T> dp;\n  vc<int> cnt, frm;\n\n  template\
    \ <typename F>\n  T solve(int N, F f, bool minimize_cnt = true) {\n    dp.assign(N\
    \ + 1, infty<T>);\n    cnt.assign(N + 1, infty<int>);\n    frm.assign(N + 1, 0);\n\
    \n    dp[0] = 0;\n    cnt[0] = 0;\n\n    auto better_tie = [&](int new_cnt, int\
    \ old_cnt) -> bool {\n      return minimize_cnt ? new_cnt < old_cnt : new_cnt\
    \ > old_cnt;\n    };\n\n    auto check = [&](int r, int l) -> void {\n      T\
    \ x = dp[l] + f(l, r);\n      int c = cnt[l] + 1;\n      if (dp[r] > x || (dp[r]\
    \ == x && better_tie(c, cnt[r]))) {\n        dp[r] = x;\n        cnt[r] = c;\n\
    \        frm[r] = l;\n      }\n    };\n\n    // simple larsch, https://noshi91.hatenablog.com/entry/2023/02/18/005856\n\
    \    auto dfs = [&](auto& dfs, int l, int r) -> void {\n      if (r - l == 1)\
    \ return;\n      int m = (l + r) / 2;\n\n      FOR(k, frm[l], frm[r] + 1) check(m,\
    \ k);\n      dfs(dfs, l, m);\n\n      FOR(k, l + 1, m + 1) check(r, k);\n    \
    \  dfs(dfs, m, r);\n    };\n\n    if (N > 0) {\n      check(N, 0);\n      dfs(dfs,\
    \ 0, N);\n    }\n\n    return dp[N];\n  }\n\n  vc<int> restore_path() {\n    int\
    \ N = len(dp) - 1;\n    vc<int> path;\n    for (int v = N; v > 0; v = frm[v])\
    \ path.eb(v);\n    path.eb(0);\n    reverse(all(path));\n    return path;\n  }\n\
    };\n\n// yuki705 \u3067\u306F simple larsch \u3088\u308A\u4F4E\u901F\u3060\u3063\
    \u305F\u3057\u4F7F\u308F\u306A\u3044\u60F3\u5B9A\u3067\u3044\u304F\n// #include\
    \ \"convex/larsch.hpp\"\n// // dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n// //\
    \ \u9077\u79FB\u56DE\u6570\u3092\u554F\u308F\u306A\u3044\n// template <typename\
    \ T, typename F>\n// vc<T> monge_shortest_path_larsch(int N, F f) {\n//   vc<T>\
    \ dp(N + 1, infty<T>);\n//   dp[0] = 0;\n\n//   auto g = [&](int i, int j) ->\
    \ T {\n//     ++i;\n//     if (i <= j) return infty<T>;\n//     return dp[j] +\
    \ f(j, i);\n//   };\n\n//   LARSCH<T, decltype(g)> larsch(N, g);\n//   FOR(r,\
    \ 1, N + 1) {\n//     int l = larsch.get_argmin();\n//     dp[r] = dp[l] + f(l,\
    \ r);\n//   }\n//   return dp;\n// }\n"
  code: "\ntemplate <typename T>\nstruct Monge_Shortest_Path {\n  vc<T> dp;\n  vc<int>\
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
    \ = dp[l] + f(l, r);\n//   }\n//   return dp;\n// }\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/monge_shortest_path.hpp
  requiredBy:
  - convex/monge/monge_shortest_path_d_edge.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/monge_shortest_path.test.cpp
  - test/3_yukicoder/705.test.cpp
documentation_of: convex/monge/monge_shortest_path.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_shortest_path.hpp
- /library/convex/monge/monge_shortest_path.hpp.html
title: convex/monge/monge_shortest_path.hpp
---
