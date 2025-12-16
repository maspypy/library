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
    - https://atcoder.jp/contests/ajo2025-final/submissions/71727945
  bundledCode: "#line 1 \"other/optimize_2d.hpp\"\n\n// \u3069\u306E\u304F\u3089\u3044\
    \u4F7F\u3048\u308B\u3053\u3068\u304C\u3042\u308B\u306E\u304B\u4E0D\u660E\n// https://atcoder.jp/contests/ajo2025-final/submissions/71727945\n\
    // return: f(x,y),x,y\ntemplate <typename T, bool MINIMIZE, typename F>\ntuple<T,\
    \ ll, ll> optimize_2d(ll x1, ll x2, ll y1, ll y2, F f, int beam_width) {\n  assert(x1\
    \ < x2 && y1 < y2);\n\n  map<pi, T> MP;\n  auto eval = [&](ll x, ll y) -> T {\n\
    \    pi k = {x, y};\n    if (MP.count(k)) return MP[k];\n    T ans = f(x1 + x,\
    \ y1 + y);\n    if (!MINIMIZE) ans = -ans;\n    return MP[k] = ans;\n  };\n\n\
    \  vc<tuple<T, ll, ll>> cand;\n  cand.eb(eval(0, 0), 0, 0);\n\n  ll X = x2 - x1,\
    \ Y = y2 - y1;\n\n  // \u30B9\u30B1\u30FC\u30EB\u304C\u5168\u7136\u9055\u3046\u3068\
    \u304D\u306E\u5BFE\u7B56\u306E\u3064\u3082\u308A\n  ll KX = topbit(X) + 1;\n \
    \ ll KY = topbit(Y) + 1;\n\n  while (KX > 0 || KY > 0) {\n    vc<tuple<T, ll,\
    \ ll>> nxt = cand;\n    auto upd = [&](ll x, ll y) -> void {\n      if (0 <= x\
    \ && x < X && 0 <= y && y < Y) {\n        nxt.eb(eval(x, y), x, y);\n      }\n\
    \    };\n    ll dx = 0, dy = 0;\n    if (KX < KY) {\n      --KY, dy = 1LL << KY;\n\
    \    } else {\n      --KX, dx = 1LL << KX;\n    }\n    for (auto& [v, x, y] :\
    \ cand) {\n      upd(x - dx, y - dy), upd(x + dx, y + dy);\n    }\n    swap(cand,\
    \ nxt);\n    UNIQUE(cand);\n    while (len(cand) > beam_width) POP(cand);\n  }\n\
    \  auto [v, x, y] = cand[0];\n  if (!MINIMIZE) v = -v;\n  return {v, x1 + x, y1\
    \ + y};\n}\n"
  code: "\n// \u3069\u306E\u304F\u3089\u3044\u4F7F\u3048\u308B\u3053\u3068\u304C\u3042\
    \u308B\u306E\u304B\u4E0D\u660E\n// https://atcoder.jp/contests/ajo2025-final/submissions/71727945\n\
    // return: f(x,y),x,y\ntemplate <typename T, bool MINIMIZE, typename F>\ntuple<T,\
    \ ll, ll> optimize_2d(ll x1, ll x2, ll y1, ll y2, F f, int beam_width) {\n  assert(x1\
    \ < x2 && y1 < y2);\n\n  map<pi, T> MP;\n  auto eval = [&](ll x, ll y) -> T {\n\
    \    pi k = {x, y};\n    if (MP.count(k)) return MP[k];\n    T ans = f(x1 + x,\
    \ y1 + y);\n    if (!MINIMIZE) ans = -ans;\n    return MP[k] = ans;\n  };\n\n\
    \  vc<tuple<T, ll, ll>> cand;\n  cand.eb(eval(0, 0), 0, 0);\n\n  ll X = x2 - x1,\
    \ Y = y2 - y1;\n\n  // \u30B9\u30B1\u30FC\u30EB\u304C\u5168\u7136\u9055\u3046\u3068\
    \u304D\u306E\u5BFE\u7B56\u306E\u3064\u3082\u308A\n  ll KX = topbit(X) + 1;\n \
    \ ll KY = topbit(Y) + 1;\n\n  while (KX > 0 || KY > 0) {\n    vc<tuple<T, ll,\
    \ ll>> nxt = cand;\n    auto upd = [&](ll x, ll y) -> void {\n      if (0 <= x\
    \ && x < X && 0 <= y && y < Y) {\n        nxt.eb(eval(x, y), x, y);\n      }\n\
    \    };\n    ll dx = 0, dy = 0;\n    if (KX < KY) {\n      --KY, dy = 1LL << KY;\n\
    \    } else {\n      --KX, dx = 1LL << KX;\n    }\n    for (auto& [v, x, y] :\
    \ cand) {\n      upd(x - dx, y - dy), upd(x + dx, y + dy);\n    }\n    swap(cand,\
    \ nxt);\n    UNIQUE(cand);\n    while (len(cand) > beam_width) POP(cand);\n  }\n\
    \  auto [v, x, y] = cand[0];\n  if (!MINIMIZE) v = -v;\n  return {v, x1 + x, y1\
    \ + y};\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/optimize_2d.hpp
  requiredBy: []
  timestamp: '2025-12-16 20:51:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/optimize_2d.hpp
layout: document
redirect_from:
- /library/other/optimize_2d.hpp
- /library/other/optimize_2d.hpp.html
title: other/optimize_2d.hpp
---
