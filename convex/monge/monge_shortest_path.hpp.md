---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/monge_shortest_path.test.cpp
    title: test/1_mytest/monge_shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/705.test.cpp
    title: test/3_yukicoder/705.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/18/005856
  bundledCode: "#line 2 \"convex/monge/monge_shortest_path.hpp\"\n\n// dp[0] = 0\n\
    // dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n// return: {dp, frm}\n// minimize_cnt:\
    \ Alien \u306E\u5FA9\u5143\u306B\u4F7F\u3046\ntemplate <typename T, typename F>\n\
    pair<vc<T>, vc<int>> monge_shortest_path(int N, F f, bool minimize_cnt = true)\
    \ {\n  vc<T> dp(N + 1, infty<T>);\n  vc<int> frm(N + 1, 0);\n  vc<int> cnt(N +\
    \ 1, infty<int>);\n\n  dp[0] = 0;\n  cnt[0] = 0;\n\n  auto better_tie = [&](int\
    \ new_cnt, int old_cnt) -> bool {\n    return minimize_cnt ? new_cnt < old_cnt\
    \ : new_cnt > old_cnt;\n  };\n  auto check = [&](int r, int l) -> void {\n   \
    \ T x = dp[l] + f(l, r);\n    int c = cnt[l] + 1;\n    if (dp[r] > x || (dp[r]\
    \ == x && better_tie(c, cnt[r]))) {\n      dp[r] = x;\n      frm[r] = l;\n   \
    \   cnt[r] = c;\n    }\n  };\n\n  // simple larsch, https://noshi91.hatenablog.com/entry/2023/02/18/005856\n\
    \  auto dfs = [&](auto& dfs, int l, int r) -> void {\n    if (r - l == 1) return;\n\
    \    int m = (l + r) / 2;\n    FOR(k, frm[l], frm[r] + 1) check(m, k);\n    dfs(dfs,\
    \ l, m);\n    FOR(k, l + 1, m + 1) check(r, k);\n    dfs(dfs, m, r);\n  };\n\n\
    \  if (N > 0) {\n    check(N, 0), dfs(dfs, 0, N);\n  }\n  return {dp, frm};\n\
    }\n\n// #include \"convex/larsch.hpp\"\n// // dp[r] = min_{0 <= l < r} dp[l] +\
    \ f(l, r)\n// // \u9077\u79FB\u56DE\u6570\u3092\u554F\u308F\u306A\u3044\n// template\
    \ <typename T, typename F>\n// vc<T> monge_shortest_path_larsch(int N, F f) {\n\
    //   vc<T> dp(N + 1, infty<T>);\n//   dp[0] = 0;\n\n//   auto g = [&](int i, int\
    \ j) -> T {\n//     ++i;\n//     if (i <= j) return infty<T>;\n//     return dp[j]\
    \ + f(j, i);\n//   };\n\n//   LARSCH<T, decltype(g)> larsch(N, g);\n//   FOR(r,\
    \ 1, N + 1) {\n//     int l = larsch.get_argmin();\n//     dp[r] = dp[l] + f(l,\
    \ r);\n//   }\n//   return dp;\n// }\n"
  code: "#pragma once\n\n// dp[0] = 0\n// dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n\
    // return: {dp, frm}\n// minimize_cnt: Alien \u306E\u5FA9\u5143\u306B\u4F7F\u3046\
    \ntemplate <typename T, typename F>\npair<vc<T>, vc<int>> monge_shortest_path(int\
    \ N, F f, bool minimize_cnt = true) {\n  vc<T> dp(N + 1, infty<T>);\n  vc<int>\
    \ frm(N + 1, 0);\n  vc<int> cnt(N + 1, infty<int>);\n\n  dp[0] = 0;\n  cnt[0]\
    \ = 0;\n\n  auto better_tie = [&](int new_cnt, int old_cnt) -> bool {\n    return\
    \ minimize_cnt ? new_cnt < old_cnt : new_cnt > old_cnt;\n  };\n  auto check =\
    \ [&](int r, int l) -> void {\n    T x = dp[l] + f(l, r);\n    int c = cnt[l]\
    \ + 1;\n    if (dp[r] > x || (dp[r] == x && better_tie(c, cnt[r]))) {\n      dp[r]\
    \ = x;\n      frm[r] = l;\n      cnt[r] = c;\n    }\n  };\n\n  // simple larsch,\
    \ https://noshi91.hatenablog.com/entry/2023/02/18/005856\n  auto dfs = [&](auto&\
    \ dfs, int l, int r) -> void {\n    if (r - l == 1) return;\n    int m = (l +\
    \ r) / 2;\n    FOR(k, frm[l], frm[r] + 1) check(m, k);\n    dfs(dfs, l, m);\n\
    \    FOR(k, l + 1, m + 1) check(r, k);\n    dfs(dfs, m, r);\n  };\n\n  if (N >\
    \ 0) {\n    check(N, 0), dfs(dfs, 0, N);\n  }\n  return {dp, frm};\n}\n\n// #include\
    \ \"convex/larsch.hpp\"\n// // dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n// //\
    \ \u9077\u79FB\u56DE\u6570\u3092\u554F\u308F\u306A\u3044\n// template <typename\
    \ T, typename F>\n// vc<T> monge_shortest_path_larsch(int N, F f) {\n//   vc<T>\
    \ dp(N + 1, infty<T>);\n//   dp[0] = 0;\n\n//   auto g = [&](int i, int j) ->\
    \ T {\n//     ++i;\n//     if (i <= j) return infty<T>;\n//     return dp[j] +\
    \ f(j, i);\n//   };\n\n//   LARSCH<T, decltype(g)> larsch(N, g);\n//   FOR(r,\
    \ 1, N + 1) {\n//     int l = larsch.get_argmin();\n//     dp[r] = dp[l] + f(l,\
    \ r);\n//   }\n//   return dp;\n// }\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/monge/monge_shortest_path.hpp
  requiredBy: []
  timestamp: '2026-05-31 19:36:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
