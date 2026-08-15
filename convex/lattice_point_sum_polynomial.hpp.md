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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/powertable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"convex/line_min_function.hpp\"\n#include \"mod/floor_sum_of_linear_polynomial.hpp\"\
    \n#include \"seq/famous/faulhaber.hpp\"\n\n// ax+by<=c \u3068\u3044\u3046\u534A\
    \u5E73\u9762\u305F\u3061. \u975E\u6709\u754C\u306F 0 \u57CB\u3081.\n// \u683C\u5B50\
    \u70B9 (x,y) \u306B\u5BFE\u3057\u3066 x^iy^j \u306E sum. i<=K1, j<=K2\ntemplate\
    \ <typename mint, int K1, int K2>\narray<array<mint, K2 + 1>, K1 + 1> lattice_point_sum_polynomial(vc<tuple<ll,\
    \ ll, ll>> LINE) {\n  ll L = -infty<ll>, R = infty<ll>;\n  vc<tuple<ll, ll, ll>>\
    \ LINE1, LINE2;\n  for (auto& [a, b, c]: LINE) {\n    if (b == 0) {\n      assert(a\
    \ != 0);\n      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }\n      elif (a <\
    \ 0) { chmax(L, ceil<ll>(-c, -a)); }\n    } else {\n      if (b > 0) { LINE2.eb(-a,\
    \ c, b); }\n      if (b < 0) { LINE1.eb(a, -c, -b); }\n    }\n  }\n  if (L >=\
    \ R) { return {}; }\n  if (LINE1.empty() || LINE2.empty()) return {};\n\n  auto\
    \ LOWER = line_max_function_rational(LINE1, L, R);\n  auto UPPER = line_min_function_rational(LINE2,\
    \ L, R);\n\n  array<array<mint, K2 + 2>, K1 + 1> S;\n  FOR(i, K1 + 1) FOR(j, K2\
    \ + 1) S[i][j] = 0;\n\n  bool bad = 0;\n  auto wk = [&](ll L, ll R, ll a1, ll\
    \ b1, ll c1, ll a2, ll b2, ll c2) -> void {\n    // \u4EA4\u70B9 t/s\n    i128\
    \ s = i128(a2) * c1 - i128(a1) * c2;\n    i128 t = i128(b1) * c2 - i128(b2) *\
    \ c1;\n    if (s == 0) {\n      if (t > 0) return;\n    }\n    if (s > 0) { chmax(L,\
    \ ceil<i128>(t, s)); }\n    if (s < 0) { chmin(R, floor<i128>(-t, -s) + 1); }\n\
    \    if (L >= R) return;\n    if (L == -infty<ll> || R == infty<ll>) {\n     \
    \ bad = 1;\n      return;\n    }\n    auto ADD = floor_sum_of_linear_polynomial<mint,\
    \ K1, K2 + 1, ll>(L, R, a2, b2, c2);\n    auto SUB = floor_sum_of_linear_polynomial<mint,\
    \ K1, K2 + 1, ll>(L, R, a1, b1 - 1, c1);\n    FOR(i, K1 + 1) FOR(j, K2 + 2) S[i][j]\
    \ += ADD[i][j] - SUB[i][j];\n  };\n\n  merge_58(LOWER, UPPER, wk);\n  array<array<mint,\
    \ K2 + 1>, K1 + 1> ANS{};\n  if (bad) return ANS;\n\n  static vvc<mint> CF;\n\
    \  if (CF.empty()) { CF = faulhaber_formula_2d<mint>(K2); }\n  FOR(i, K1 + 1)\
    \ {\n    FOR(j, K2 + 1) {\n      FOR(k, j + 2) { ANS[i][j] += CF[j][k] * S[i][k];\
    \ }\n    }\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/lattice_point_sum_polynomial.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/lattice_point_sum_polynomial.hpp
layout: document
redirect_from:
- /library/convex/lattice_point_sum_polynomial.hpp
- /library/convex/lattice_point_sum_polynomial.hpp.html
title: convex/lattice_point_sum_polynomial.hpp
---
