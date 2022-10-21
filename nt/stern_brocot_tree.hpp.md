---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/stern_brocot.test.cpp
    title: test/mytest/stern_brocot.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/stern_brocot_tree.hpp\"\n\nstruct Stern_Brocot_Tree {\n\
    \  using PATH = vi; // \u306F\u3058\u3081\u306F R\n\n  static tuple<PATH, pi,\
    \ pi> get_path_and_range(pi x) {\n    PATH path;\n    pi l = {0, 1}, r = {1, 0};\n\
    \    pi m = {1, 1};\n    ll det_l = l.fi * x.se - l.se * x.fi;\n    ll det_r =\
    \ r.fi * x.se - r.se * x.fi;\n    ll det_m = det_l + det_r;\n    while (1) {\n\
    \      if (det_m == 0) break;\n      ll k = ceil(-det_m, det_r);\n      path.eb(k);\n\
    \      l = {l.fi + k * r.fi, l.se + k * r.se};\n      m = {l.fi + r.fi, l.se +\
    \ r.se};\n      det_l += k * det_r;\n      det_m += k * det_r;\n      if (det_m\
    \ == 0) break;\n      k = ceil(det_m, -det_l);\n      path.eb(k);\n      r = {r.fi\
    \ + k * l.fi, r.se + k * l.se};\n      m = {l.fi + r.fi, l.se + r.se};\n     \
    \ det_r += k * det_l;\n      det_m += k * det_l;\n    }\n    return {path, l,\
    \ r};\n  }\n\n  static PATH get_path(pi x) {\n    auto [path, l, r] = get_path_and_range(x);\n\
    \    return path;\n  }\n\n  static pair<pi, pi> range(pi x) {\n    auto [path,\
    \ l, r] = get_path_and_range(x);\n    return {l, r};\n  }\n\n  // x in range(y)\n\
    \  static bool in_subtree(pi x, pi y) {\n    auto [l, r] = range(y);\n    bool\
    \ ok_l = i128(x.fi) * l.se - i128(x.se) * l.fi > 0;\n    bool ok_r = i128(r.fi)\
    \ * x.se - i128(r.se) * x.fi > 0;\n    return ok_l && ok_r;\n  }\n\n  template\
    \ <typename T = ll>\n  static pair<T, T> from_path(PATH& p) {\n    using P = pair<T,\
    \ T>;\n    P l = {0, 1}, r = {1, 0};\n    FOR(i, len(p)) {\n      ll k = p[i];\n\
    \      if (i % 2 == 0) {\n        l.fi += T(k) * r.fi;\n        l.se += T(k) *\
    \ r.se;\n      }\n      if (i % 2 == 1) {\n        r.fi += T(k) * l.fi;\n    \
    \    r.se += T(k) * l.se;\n      }\n    }\n    return {l.fi + r.fi, l.se + r.se};\n\
    \  }\n\n  static pair<pi, pi> child(pi x) {\n    auto [l, r] = range(x);\n   \
    \ pi lc = {l.fi + x.fi, l.se + x.se};\n    pi rc = {x.fi + r.fi, x.se + r.se};\n\
    \    return {lc, rc};\n  }\n\n  static pi LCA(pi x, pi y) {\n    auto Px = get_path(x);\n\
    \    auto Py = get_path(y);\n    vi P;\n    FOR(i, min(len(Px), len(Py))) {\n\
    \      ll k = min(Px[i], Py[i]);\n      P.eb(k);\n      if (k < Px[i] || k < Py[i])\
    \ break;\n    }\n    return from_path(P);\n  }\n\n  static pi LA(pi x, ll dep)\
    \ {\n    pi l = {0, 1}, r = {1, 0};\n    pi m = {1, 1};\n    ll det_l = l.fi *\
    \ x.se - l.se * x.fi;\n    ll det_r = r.fi * x.se - r.se * x.fi;\n    ll det_m\
    \ = det_l + det_r;\n    while (1) {\n      if (det_m == 0 || dep == 0) break;\n\
    \      ll k = min(dep, ceil(-det_m, det_r));\n      l = {l.fi + k * r.fi, l.se\
    \ + k * r.se};\n      m = {l.fi + r.fi, l.se + r.se};\n      det_l += k * det_r;\n\
    \      det_m += k * det_r;\n      dep -= k;\n      if (det_m == 0 || dep == 0)\
    \ break;\n      k = min(dep, ceil(det_m, -det_l));\n      r = {r.fi + k * l.fi,\
    \ r.se + k * l.se};\n      m = {l.fi + r.fi, l.se + r.se};\n      det_r += k *\
    \ det_l;\n      det_m += k * det_l;\n      dep -= k;\n    }\n    if (dep == 0)\
    \ return m;\n    return {-1, -1};\n  }\n\n  static string to_string(PATH& p) {\n\
    \    string res;\n    char c = 'L';\n    for (auto&& x: p) {\n      c = 'L' +\
    \ 'R' - c;\n      if (x == 0) continue;\n      res += c;\n      res += \" \" +\
    \ std::to_string(x);\n    }\n    return res;\n  }\n};\n"
  code: "\nstruct Stern_Brocot_Tree {\n  using PATH = vi; // \u306F\u3058\u3081\u306F\
    \ R\n\n  static tuple<PATH, pi, pi> get_path_and_range(pi x) {\n    PATH path;\n\
    \    pi l = {0, 1}, r = {1, 0};\n    pi m = {1, 1};\n    ll det_l = l.fi * x.se\
    \ - l.se * x.fi;\n    ll det_r = r.fi * x.se - r.se * x.fi;\n    ll det_m = det_l\
    \ + det_r;\n    while (1) {\n      if (det_m == 0) break;\n      ll k = ceil(-det_m,\
    \ det_r);\n      path.eb(k);\n      l = {l.fi + k * r.fi, l.se + k * r.se};\n\
    \      m = {l.fi + r.fi, l.se + r.se};\n      det_l += k * det_r;\n      det_m\
    \ += k * det_r;\n      if (det_m == 0) break;\n      k = ceil(det_m, -det_l);\n\
    \      path.eb(k);\n      r = {r.fi + k * l.fi, r.se + k * l.se};\n      m = {l.fi\
    \ + r.fi, l.se + r.se};\n      det_r += k * det_l;\n      det_m += k * det_l;\n\
    \    }\n    return {path, l, r};\n  }\n\n  static PATH get_path(pi x) {\n    auto\
    \ [path, l, r] = get_path_and_range(x);\n    return path;\n  }\n\n  static pair<pi,\
    \ pi> range(pi x) {\n    auto [path, l, r] = get_path_and_range(x);\n    return\
    \ {l, r};\n  }\n\n  // x in range(y)\n  static bool in_subtree(pi x, pi y) {\n\
    \    auto [l, r] = range(y);\n    bool ok_l = i128(x.fi) * l.se - i128(x.se) *\
    \ l.fi > 0;\n    bool ok_r = i128(r.fi) * x.se - i128(r.se) * x.fi > 0;\n    return\
    \ ok_l && ok_r;\n  }\n\n  template <typename T = ll>\n  static pair<T, T> from_path(PATH&\
    \ p) {\n    using P = pair<T, T>;\n    P l = {0, 1}, r = {1, 0};\n    FOR(i, len(p))\
    \ {\n      ll k = p[i];\n      if (i % 2 == 0) {\n        l.fi += T(k) * r.fi;\n\
    \        l.se += T(k) * r.se;\n      }\n      if (i % 2 == 1) {\n        r.fi\
    \ += T(k) * l.fi;\n        r.se += T(k) * l.se;\n      }\n    }\n    return {l.fi\
    \ + r.fi, l.se + r.se};\n  }\n\n  static pair<pi, pi> child(pi x) {\n    auto\
    \ [l, r] = range(x);\n    pi lc = {l.fi + x.fi, l.se + x.se};\n    pi rc = {x.fi\
    \ + r.fi, x.se + r.se};\n    return {lc, rc};\n  }\n\n  static pi LCA(pi x, pi\
    \ y) {\n    auto Px = get_path(x);\n    auto Py = get_path(y);\n    vi P;\n  \
    \  FOR(i, min(len(Px), len(Py))) {\n      ll k = min(Px[i], Py[i]);\n      P.eb(k);\n\
    \      if (k < Px[i] || k < Py[i]) break;\n    }\n    return from_path(P);\n \
    \ }\n\n  static pi LA(pi x, ll dep) {\n    pi l = {0, 1}, r = {1, 0};\n    pi\
    \ m = {1, 1};\n    ll det_l = l.fi * x.se - l.se * x.fi;\n    ll det_r = r.fi\
    \ * x.se - r.se * x.fi;\n    ll det_m = det_l + det_r;\n    while (1) {\n    \
    \  if (det_m == 0 || dep == 0) break;\n      ll k = min(dep, ceil(-det_m, det_r));\n\
    \      l = {l.fi + k * r.fi, l.se + k * r.se};\n      m = {l.fi + r.fi, l.se +\
    \ r.se};\n      det_l += k * det_r;\n      det_m += k * det_r;\n      dep -= k;\n\
    \      if (det_m == 0 || dep == 0) break;\n      k = min(dep, ceil(det_m, -det_l));\n\
    \      r = {r.fi + k * l.fi, r.se + k * l.se};\n      m = {l.fi + r.fi, l.se +\
    \ r.se};\n      det_r += k * det_l;\n      det_m += k * det_l;\n      dep -= k;\n\
    \    }\n    if (dep == 0) return m;\n    return {-1, -1};\n  }\n\n  static string\
    \ to_string(PATH& p) {\n    string res;\n    char c = 'L';\n    for (auto&& x:\
    \ p) {\n      c = 'L' + 'R' - c;\n      if (x == 0) continue;\n      res += c;\n\
    \      res += \" \" + std::to_string(x);\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2022-10-16 14:15:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/stern_brocot.test.cpp
documentation_of: nt/stern_brocot_tree.hpp
layout: document
redirect_from:
- /library/nt/stern_brocot_tree.hpp
- /library/nt/stern_brocot_tree.hpp.html
title: nt/stern_brocot_tree.hpp
---
