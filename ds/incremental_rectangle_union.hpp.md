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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"ds/fastset.hpp\"\n\n// [0, x] x [0, y] \u3092\u8FFD\u52A0 ->\
    \ \u548C\u96C6\u5408\u9762\u7A4D\u3092\u53D6\u5F97\ntemplate <typename XY, typename\
    \ AREA, bool SMALL_XY>\nstruct Incremental_Rectangle_Union {\n  FastSet ss;\n\
    \  vc<XY> ht;\n  map<XY, XY> MP; // right end -> height\n  AREA area;\n\n  Incremental_Rectangle_Union()\
    \ : area(AREA(0)) {\n    static_assert(!SMALL_XY);\n    MP[0] = infty<XY>, MP[infty<XY>]\
    \ = 0;\n  }\n\n  Incremental_Rectangle_Union(int LIM)\n      : ss(LIM + 1), ht(LIM\
    \ + 1), area(AREA(0)) {\n    static_assert(SMALL_XY);\n    ht[0] = infty<XY>,\
    \ ht[LIM] = 0, ss.insert(0), ss.insert(LIM);\n  }\n\n  AREA add(XY x, XY y) {\n\
    \    if constexpr (SMALL_XY) add_fast(x, y);\n    if constexpr (!SMALL_XY) add_MP(x,\
    \ y);\n    return area;\n  }\n\n  void reset() {\n    area = 0;\n    if constexpr\
    \ (SMALL_XY) {\n      int LIM = len(ss) - 1;\n      ss.enumerate(0, LIM + 1, [&](int\
    \ i) -> void { ss.erase(i); });\n      ht[0] = infty<XY>, ht[LIM] = 0, ss.insert(0),\
    \ ss.insert(LIM);\n    } else {\n      MP.clear(), MP[0] = infty<XY>, MP[infty<XY>]\
    \ = 0;\n    }\n  }\n\nprivate:\n  void add_MP(XY x, XY y) {\n    if (x == 0 ||\
    \ y == 0) return;\n    auto it = MP.lower_bound(x);\n    auto [rx, ry] = *it;\n\
    \    if (ry >= y) return;\n\n    // split\n    if (x < rx) MP[x] = ry;\n    it\
    \ = MP.find(x);\n    while (1) {\n      auto [x2, y2] = *it;\n      it = prev(MP.erase(it));\n\
    \      auto [x1, y1] = *it;\n      // [x1,x2]: y2 -> 0\n      area -= AREA(x2\
    \ - x1) * AREA(y2);\n      if (y1 >= y) break;\n    }\n    auto [x1, y1] = *it;\n\
    \    // [x1, x]: 0 -> y\n    MP[x] = y, area += AREA(x - x1) * AREA(y);\n    return;\n\
    \  }\n\n  void add_fast(XY x, XY y) {\n    if (x == 0 || y == 0) return;\n   \
    \ int rx = ss.next(x);\n    int ry = ht[rx];\n    if (ry >= y) return;\n\n   \
    \ // split\n    if (x < rx) ss.insert(x), ht[x] = ry;\n    int x2 = x;\n    while\
    \ (1) {\n      XY y2 = ht[x2];\n      ss.erase(x2);\n      int x1 = ss.prev(x2);\n\
    \      XY y1 = ht[x1];\n      // [x1,x2]: y2 -> 0\n      area -= AREA(x2 - x1)\
    \ * AREA(y2);\n      x2 = x1;\n      if (y1 >= y) break;\n    }\n    ss.insert(x),\
    \ ht[x] = y, area += AREA(x - x2) * AREA(y);\n    return;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/incremental_rectangle_union.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/incremental_rectangle_union.hpp
layout: document
redirect_from:
- /library/ds/incremental_rectangle_union.hpp
- /library/ds/incremental_rectangle_union.hpp.html
title: ds/incremental_rectangle_union.hpp
---
