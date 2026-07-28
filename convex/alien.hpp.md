---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: convex/monge/monge_shortest_path_d_edge.hpp
    title: convex/monge/monge_shortest_path_d_edge.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/alien.hpp\"\n\n// MINIMIZE \u306B\u5FDC\u3058\u3066\
    \u3001base_score + add * cnt \u3092\u6700\u5C0F\u5316 / \u6700\u5927\u5316\u3059\
    \u308B\n// solve(add) -> {val, cnt}\n// val \u306F add * cnt \u3092\u542B\u3080\
    \u6700\u9069\u5024\n// \u6700\u9069\u89E3\u304C\u8907\u6570\u3042\u308B\u5834\u5408\
    \u3001cnt \u306F\u305D\u306E\u3046\u3061\u3069\u308C\u3092\u8FD4\u3057\u3066\u3082\
    \u3088\u3044\n//\n// \u3042\u308B T \u578B\u306E\u6574\u6570 add \u306B\u5BFE\u3057\
    \u3066\u3001cnt = K \u306E\u89E3\u304C\u6700\u9069\u89E3\u306B\u542B\u307E\u308C\
    \u308B\u3053\u3068\u3001\n// \u304A\u3088\u3073\u63A2\u7D22\u30FBsolve \u5185\u306E\
    \u3059\u3079\u3066\u306E\u8A08\u7B97\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3057\u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A\u3059\u308B\ntemplate <typename\
    \ T, bool MINIMIZE, typename F>\npair<T, T> alien_trick(int K, F solve) {\n  static_assert(is_same_v<T,\
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
    \ {ans_hi, hi};\n}\n"
  code: "#pragma once\n\n// MINIMIZE \u306B\u5FDC\u3058\u3066\u3001base_score + add\
    \ * cnt \u3092\u6700\u5C0F\u5316 / \u6700\u5927\u5316\u3059\u308B\n// solve(add)\
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
    \ {ans_hi, hi};\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex/alien.hpp
  requiredBy:
  - convex/monge/monge_shortest_path_d_edge.hpp
  timestamp: '2026-07-28 17:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/alien.hpp
layout: document
redirect_from:
- /library/convex/alien.hpp
- /library/convex/alien.hpp.html
title: convex/alien.hpp
---
