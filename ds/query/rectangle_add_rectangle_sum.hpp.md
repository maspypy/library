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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"ds/query/point_add_rectangle_sum.hpp\"\n\ntemplate\
    \ <typename AbelGroup, typename XY, bool SMALL_X = false>\nstruct Rectangle_Add_Rectangle_Sum\
    \ {\n  using WT = typename AbelGroup::value_type;\n  using WT4 = tuple<WT, WT,\
    \ WT, WT>;\n\n  struct G {\n    using X = WT4;\n    using value_type = X;\n  \
    \  static X op(const X &x, const X &y) {\n      auto &[ax, bx, cx, dx] = x;\n\
    \      auto &[ay, by, cy, dy] = y;\n      return {AbelGroup::op(ax, ay), AbelGroup::op(bx,\
    \ by),\n              AbelGroup::op(cx, cy), AbelGroup::op(dx, dy)};\n    }\n\
    \    static X inverse(const X &x) {\n      auto &[ax, bx, cx, dx] = x;\n     \
    \ return {AbelGroup::inverse(ax), AbelGroup::inverse(bx),\n              AbelGroup::inverse(cx),\
    \ AbelGroup::inverse(dx)};\n    }\n    static X power(const X &x, ll n) {\n  \
    \    auto &[ax, bx, cx, dx] = x;\n      return {AbelGroup::power(ax, n), AbelGroup::power(bx,\
    \ n),\n              AbelGroup::power(cx, n), AbelGroup::power(dx, n)};\n    }\n\
    \    static constexpr X unit() {\n      auto u = AbelGroup::unit();\n      return\
    \ {u, u, u, u};\n    }\n    static constexpr bool commute = true;\n  };\n\n  vector<tuple<XY,\
    \ XY, XY, XY>> query;\n  Point_Add_Rectangle_Sum<G, XY, SMALL_X> X;\n  XY min_x\
    \ = 0, min_y = 0;\n\n  void add_query(XY xl, XY xr, XY yl, XY yr, WT w) {\n  \
    \  assert(xl <= xr && yl <= yr);\n    min_x = min(min_x, xl);\n    min_y = min(min_y,\
    \ yl);\n    // (xl,yl) \u306B (x-xl)(y-yl) \u3092\u52A0\u7B97\n    auto nw = AbelGroup::inverse(w);\n\
    \    X.add_query(xl, yl,\n                {w, AbelGroup::power(w, -yl), AbelGroup::power(w,\
    \ -xl),\n                 AbelGroup::power(w, +ll(xl) * yl)});\n    // (xl,yr)\
    \ \u306B (x-xl)(y-yr) \u3092\u6E1B\u7B97\n    X.add_query(xl, yr,\n          \
    \      {nw, AbelGroup::power(w, +yr), AbelGroup::power(w, +xl),\n            \
    \     AbelGroup::power(w, -ll(xl) * yr)});\n    // (xr,yl) \u306B (x-xr)(y-yl)\
    \ \u3092\u6E1B\u7B97\n    X.add_query(xr, yl,\n                {nw, AbelGroup::power(w,\
    \ +yl), AbelGroup::power(w, +xr),\n                 AbelGroup::power(w, -ll(xr)\
    \ * yl)});\n    // (xr,yr) \u306B (x-xr)(y-yr) \u3092\u52A0\u7B97\n    X.add_query(xr,\
    \ yr,\n                {w, AbelGroup::power(w, -yr), AbelGroup::power(w, -xr),\n\
    \                 AbelGroup::power(w, +ll(xr) * yr)});\n  }\n\n  void sum_query(XY\
    \ xl, XY xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    query.emplace_back(xl,\
    \ xr, yl, yr);\n    X.sum_query(min_x, xl, min_y, yl);\n    X.sum_query(min_x,\
    \ xl, min_y, yr);\n    X.sum_query(min_x, xr, min_y, yl);\n    X.sum_query(min_x,\
    \ xr, min_y, yr);\n  }\n\n  vector<WT> calc() {\n    int Q = query.size();\n \
    \   vector<WT> ANS(Q);\n    auto tmp = X.calc();\n\n    for (int q = 0; q < Q;\
    \ ++q) {\n      auto [xl, xr, yl, yr] = query[q];\n      WT p = AbelGroup::unit(),\
    \ m = AbelGroup::unit();\n      {\n        auto [a, b, c, d] = tmp[4 * q + 0];\n\
    \        p = AbelGroup::op(p, AbelGroup::power(a, ll(xl) * yl));\n        p =\
    \ AbelGroup::op(p, AbelGroup::power(b, xl));\n        p = AbelGroup::op(p, AbelGroup::power(c,\
    \ yl));\n        p = AbelGroup::op(p, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 1];\n        m = AbelGroup::op(m, AbelGroup::power(a,\
    \ ll(xl) * yr));\n        m = AbelGroup::op(m, AbelGroup::power(b, xl));\n   \
    \     m = AbelGroup::op(m, AbelGroup::power(c, yr));\n        m = AbelGroup::op(m,\
    \ d);\n      }\n      {\n        auto [a, b, c, d] = tmp[4 * q + 2];\n       \
    \ m = AbelGroup::op(m, AbelGroup::power(a, ll(xr) * yl));\n        m = AbelGroup::op(m,\
    \ AbelGroup::power(b, xr));\n        m = AbelGroup::op(m, AbelGroup::power(c,\
    \ yl));\n        m = AbelGroup::op(m, d);\n      }\n      {\n        auto [a,\
    \ b, c, d] = tmp[4 * q + 3];\n        p = AbelGroup::op(p, AbelGroup::power(a,\
    \ ll(xr) * yr));\n        p = AbelGroup::op(p, AbelGroup::power(b, xr));\n   \
    \     p = AbelGroup::op(p, AbelGroup::power(c, yr));\n        p = AbelGroup::op(p,\
    \ d);\n      }\n      ANS[q] = AbelGroup::op(p, AbelGroup::inverse(m));\n    }\n\
    \    return ANS;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/rectangle_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/rectangle_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/query/rectangle_add_rectangle_sum.hpp
- /library/ds/query/rectangle_add_rectangle_sum.hpp.html
title: ds/query/rectangle_add_rectangle_sum.hpp
---
