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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fenwick.hpp\"\r\n\r\ntemplate <typename AbelGroup, typename\
    \ XY, bool SMALL_X = false>\r\nstruct Point_Add_Rectangle_Sum {\r\n  using G =\
    \ typename AbelGroup::value_type;\r\n  using Point = tuple<XY, XY, G>;\r\n  vector<Point>\
    \ point;\r\n  vector<tuple<XY, XY, XY, XY>> rect;\r\n\r\n  Point_Add_Rectangle_Sum()\
    \ {}\r\n\r\n  void add_query(XY x, XY y, G w) { point.eb(x, y, w); }\r\n  void\
    \ sum_query(XY xl, XY xr, XY yl, XY yr) { rect.eb(xl, xr, yl, yr); }\r\n\r\n \
    \ vector<G> calc() {\r\n    int N = point.size(), Q = rect.size();\r\n    if (N\
    \ == 0 || Q == 0) return vector<G>(Q, AbelGroup::unit());\r\n    // X \u65B9\u5411\
    \u306E\u5EA7\u5727\r\n    int NX = 0;\r\n    if (!SMALL_X) {\r\n      sort(all(point),\r\
    \n           [&](auto &x, auto &y) -> bool { return get<0>(x) < get<0>(y); });\r\
    \n      vc<XY> keyX;\r\n      keyX.reserve(N);\r\n      for (auto &&[a, b, c]:\
    \ point) {\r\n        if (len(keyX) == 0 || keyX.back() != a) { keyX.eb(a); }\r\
    \n        a = len(keyX) - 1;\r\n      }\r\n      keyX.shrink_to_fit();\r\n   \
    \   for (auto &&[xl, xr, yl, yr]: rect) {\r\n        xl = LB(keyX, xl);\r\n  \
    \      xr = LB(keyX, xr);\r\n      }\r\n      NX = len(keyX);\r\n    }\r\n   \
    \ if (SMALL_X) {\r\n      XY mx = numeric_limits<XY>::max();\r\n      for (auto\
    \ &&[x, y, g]: point) chmin(mx, x);\r\n      for (auto &&[x, y, g]: point) x -=\
    \ mx, chmax(NX, x + 1);\r\n      for (auto &&[xl, xr, yl, yr]: rect) {\r\n   \
    \     xl -= mx, xr -= mx;\r\n        xl = max(0, min<int>(xl, NX));\r\n      \
    \  xr = max(0, min<int>(xr, NX));\r\n      }\r\n    }\r\n\r\n    vc<tuple<XY,\
    \ int, int, int>> event(Q + Q);\r\n    FOR(q, Q) {\r\n      auto &[xl, xr, yl,\
    \ yr] = rect[q];\r\n      event[2 * q] = {yl, xl, xr, 2 * q};\r\n      event[2\
    \ * q + 1] = {yr, xl, xr, 2 * q + 1};\r\n    }\r\n    sort(all(point),\r\n   \
    \      [&](auto &x, auto &y) -> bool { return get<1>(x) < get<1>(y); });\r\n \
    \   sort(all(event),\r\n         [&](auto &x, auto &y) -> bool { return get<0>(x)\
    \ < get<0>(y); });\r\n\r\n    FenwickTree<AbelGroup> bit(NX);\r\n    vc<G> res(Q,\
    \ AbelGroup::unit());\r\n    int j = 0;\r\n    for (auto &&[y, xl, xr, qq]: event)\
    \ {\r\n      while (j < N && get<1>(point[j]) < y) {\r\n        bit.add(get<0>(point[j]),\
    \ get<2>(point[j]));\r\n        ++j;\r\n      }\r\n      G g = bit.sum(xl, xr);\r\
    \n      int q = qq / 2;\r\n      if (qq % 2 == 0) g = AbelGroup::inverse(g);\r\
    \n      res[q] = AbelGroup::op(res[q], g);\r\n    }\r\n    return res;\r\n  }\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/point_add_rectangle_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/point_add_rectangle_sum.hpp
layout: document
redirect_from:
- /library/ds/offline_query/point_add_rectangle_sum.hpp
- /library/ds/offline_query/point_add_rectangle_sum.hpp.html
title: ds/offline_query/point_add_rectangle_sum.hpp
---
