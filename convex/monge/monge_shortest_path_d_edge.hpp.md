---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: convex/alien.hpp
    title: convex/alien.hpp
  - icon: ':heavy_check_mark:'
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
    \ \"convex/alien.hpp\"\n\n// MINIMIZE \u306B\u5FDC\u3058\u3066\u3001base_score\
    \ + add * cnt \u3092\u6700\u5C0F\u5316 / \u6700\u5927\u5316\u3059\u308B\n// solve(add)\
    \ -> {val, cnt}\n// val \u306F add * cnt \u3092\u542B\u3080\u6700\u9069\u5024\n\
    // \u6700\u9069\u89E3\u304C\u8907\u6570\u3042\u308B\u5834\u5408\u3001cnt \u306F\
    \u305D\u306E\u3046\u3061\u3069\u308C\u3092\u8FD4\u3057\u3066\u3082\u3088\u3044\
    \n//\n// \u3042\u308B T \u578B\u306E\u6574\u6570 add \u306B\u5BFE\u3057\u3066\u3001\
    cnt = K \u306E\u89E3\u304C\u6700\u9069\u89E3\u306B\u542B\u307E\u308C\u308B\u3053\
    \u3068\u3001\n// \u304A\u3088\u3073\u63A2\u7D22\u30FBsolve \u5185\u306E\u3059\u3079\
    \u3066\u306E\u8A08\u7B97\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\
    \u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A\u3059\u308B\ntemplate <typename T,\
    \ bool MINIMIZE, typename F>\npair<T, T> alien_trick(int K, F solve) {\n  static_assert(is_same_v<T,\
    \ ll> || is_same_v<T, i128>);\n\n  if constexpr (!MINIMIZE) {\n    auto [val,\
    \ slope] = alien_trick<T, true>(K, [&](T pena) -> pair<T, int> {\n      auto [val,\
    \ cnt] = solve(-pena);\n      return {-val, cnt};\n    });\n    return {-val,\
    \ -slope};\n  }\n\n  auto [val_0, cnt_0] = solve(T(0));\n  if (cnt_0 == K) return\
    \ {val_0, T(0)};\n\n  T lo = 0, hi = 0;\n  T val_lo = val_0, val_hi = val_0;\n\
    \  int cnt_lo = cnt_0, cnt_hi = cnt_0;\n\n  if (cnt_0 < K) {\n    lo = T(-1);\n\
    \    tie(val_lo, cnt_lo) = solve(lo);\n\n    while (cnt_lo < K) {\n      assert(lo\
    \ < hi);\n      T d = hi - lo;\n\n      hi = lo;\n      tie(val_hi, cnt_hi) =\
    \ mp(val_lo, cnt_lo);\n\n      lo -= T(2) * d;\n      tie(val_lo, cnt_lo) = solve(lo);\n\
    \    }\n  } else {\n    hi = T(1);\n    tie(val_hi, cnt_hi) = solve(hi);\n\n \
    \   while (cnt_hi > K) {\n      T d = hi - lo;\n\n      lo = hi;\n      tie(val_lo,\
    \ cnt_lo) = mp(val_hi, cnt_hi);\n\n      hi += T(2) * d;\n      tie(val_hi, cnt_hi)\
    \ = solve(hi);\n    }\n  }\n\n  assert(cnt_lo >= K && cnt_hi <= K);\n\n  if (cnt_lo\
    \ == K) return {val_lo - lo * T(K), lo};\n  if (cnt_hi == K) return {val_hi -\
    \ hi * T(K), hi};\n\n  while (lo + T(1) < hi) {\n    T mid = lo + (hi - lo) /\
    \ T(2);\n    auto [val, cnt] = solve(mid);\n\n    if (cnt == K) return {val -\
    \ mid * T(K), mid};\n\n    if (cnt > K) {\n      lo = mid;\n      tie(val_lo,\
    \ cnt_lo) = mp(val, cnt);\n    } else {\n      hi = mid;\n      tie(val_hi, cnt_hi)\
    \ = mp(val, cnt);\n    }\n  }\n\n  T ans_lo = val_lo - lo * T(K);\n  T ans_hi\
    \ = val_hi - hi * T(K);\n\n  if (ans_lo >= ans_hi) return {ans_lo, lo};\n  return\
    \ {ans_hi, hi};\n}\n#line 2 \"convex/monge/monge_shortest_path.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Monge_Shortest_Path {\n  vc<T> dp;\n  vc<int> cnt, frm;\n\
    \n  template <typename F>\n  T solve(int N, F f, bool minimize_cnt = true) {\n\
    \    dp.assign(N + 1, infty<T>);\n    cnt.assign(N + 1, infty<int>);\n    frm.assign(N\
    \ + 1, 0);\n\n    dp[0] = 0;\n    cnt[0] = 0;\n\n    auto better_tie = [&](int\
    \ new_cnt, int old_cnt) -> bool {\n      return minimize_cnt ? new_cnt < old_cnt\
    \ : new_cnt > old_cnt;\n    };\n\n    auto check = [&](int r, int l) -> void {\n\
    \      T x = dp[l] + f(l, r);\n      int c = cnt[l] + 1;\n      if (dp[r] > x\
    \ || (dp[r] == x && better_tie(c, cnt[r]))) {\n        dp[r] = x;\n        cnt[r]\
    \ = c;\n        frm[r] = l;\n      }\n    };\n\n    // simple larsch, https://noshi91.hatenablog.com/entry/2023/02/18/005856\n\
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
    \ r);\n//   }\n//   return dp;\n// }\n#line 5 \"convex/monge/monge_shortest_path_d_edge.hpp\"\
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
  timestamp: '2026-07-28 17:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/monge/monge_shortest_path_d_edge.hpp
layout: document
redirect_from:
- /library/convex/monge/monge_shortest_path_d_edge.hpp
- /library/convex/monge/monge_shortest_path_d_edge.hpp.html
title: convex/monge/monge_shortest_path_d_edge.hpp
---
