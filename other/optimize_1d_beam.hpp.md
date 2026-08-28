---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/optimize_1d_beam.hpp\"\n\n// return: f(x), x\ntemplate\
    \ <typename T, bool MINIMIZE, typename F>\npair<T, ll> optimize_1d_beam(ll x1,\
    \ ll x2, F f, int beam_width) {\n  assert(x1 < x2);\n\n  auto eval = [&](ll x)\
    \ -> T {\n    T v = f(x);\n    if (!MINIMIZE) v = -v;\n    return v;\n  };\n\n\
    \  // (value, x, l, r), interval = [l, r)\n  using P = tuple<T, ll, ll, ll>;\n\
    \n  auto make = [&](ll l, ll r) -> P {\n    ll x = (l + r) / 2;\n    return {eval(x),\
    \ x, l, r};\n  };\n\n  vc<P> cand;\n  cand.eb(make(x1, x2));\n\n  P best = cand[0];\n\
    \n  while (1) {\n    vc<P> nxt;\n    bool done = true;\n\n    for (auto [v, x,\
    \ l, r] : cand) {\n      chmin(best, P{v, x, l, r});\n\n      if (r - l == 1)\
    \ continue;\n      done = false;\n      if (l < x) nxt.eb(make(l, x));\n     \
    \ if (x + 1 < r) nxt.eb(make(x + 1, r));\n    }\n\n    if (done || nxt.empty())\
    \ break;\n\n    if (len(nxt) > beam_width) {\n      nth_element(nxt.begin(), nxt.begin()\
    \ + beam_width, nxt.end());\n      nxt.resize(beam_width);\n    }\n    swap(cand,\
    \ nxt);\n  }\n\n  auto [v, x, l, r] = best;\n  if (!MINIMIZE) v = -v;\n  return\
    \ {v, x};\n}\n"
  code: "\n// return: f(x), x\ntemplate <typename T, bool MINIMIZE, typename F>\n\
    pair<T, ll> optimize_1d_beam(ll x1, ll x2, F f, int beam_width) {\n  assert(x1\
    \ < x2);\n\n  auto eval = [&](ll x) -> T {\n    T v = f(x);\n    if (!MINIMIZE)\
    \ v = -v;\n    return v;\n  };\n\n  // (value, x, l, r), interval = [l, r)\n \
    \ using P = tuple<T, ll, ll, ll>;\n\n  auto make = [&](ll l, ll r) -> P {\n  \
    \  ll x = (l + r) / 2;\n    return {eval(x), x, l, r};\n  };\n\n  vc<P> cand;\n\
    \  cand.eb(make(x1, x2));\n\n  P best = cand[0];\n\n  while (1) {\n    vc<P> nxt;\n\
    \    bool done = true;\n\n    for (auto [v, x, l, r] : cand) {\n      chmin(best,\
    \ P{v, x, l, r});\n\n      if (r - l == 1) continue;\n      done = false;\n  \
    \    if (l < x) nxt.eb(make(l, x));\n      if (x + 1 < r) nxt.eb(make(x + 1, r));\n\
    \    }\n\n    if (done || nxt.empty()) break;\n\n    if (len(nxt) > beam_width)\
    \ {\n      nth_element(nxt.begin(), nxt.begin() + beam_width, nxt.end());\n  \
    \    nxt.resize(beam_width);\n    }\n    swap(cand, nxt);\n  }\n\n  auto [v, x,\
    \ l, r] = best;\n  if (!MINIMIZE) v = -v;\n  return {v, x};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/optimize_1d_beam.hpp
  requiredBy: []
  timestamp: '2026-08-29 08:41:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/optimize_1d_beam.hpp
layout: document
redirect_from:
- /library/other/optimize_1d_beam.hpp
- /library/other/optimize_1d_beam.hpp.html
title: other/optimize_1d_beam.hpp
---
