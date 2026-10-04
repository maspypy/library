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
    - https://codeforces.com/contest/154/problem/E
    - https://codeforces.com/contest/1984/problem/H
    - https://codeforces.com/contest/549/problem/E
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
  code: "#include \"geo/outcircle.hpp\"\n#include \"ds/fastset.hpp\"\n#include \"\
    random/shuffle.hpp\"\n\n// \u5EA7\u6A19\u306E 4 \u4E57\u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\n// return : array<int,3>, triangles\n\
    // https://codeforces.com/contest/154/problem/E\n// https://codeforces.com/contest/549/problem/E\n\
    // https://codeforces.com/contest/1984/problem/H\ntemplate <typename T>\nvc<array<int,\
    \ 3>> delaunay_triangulation_of_convex_polygon(vc<Point<T>> A, bool farthest)\
    \ {\n  int N = len(A);\n  if (N <= 2) return {};\n\n  FastSet FS(N);\n\n  vc<int>\
    \ I(N);\n  FOR(i, N) I[i] = i;\n  shuffle(I);\n\n  sort(I.end() - 3, I.end());\n\
    \n  struct E {\n    int a, b, nxt, rev;\n  };\n\n  int c = POP(I), b = POP(I),\
    \ a = POP(I);\n  vc<E> dat;\n  dat.eb(a, b, 1, -1);\n  dat.eb(b, c, 2, -1);\n\
    \  dat.eb(c, a, 0, -1);\n  vc<int> v_to_e(N, -1);\n  v_to_e[a] = 0, v_to_e[b]\
    \ = 1, v_to_e[c] = 2;\n  FS.insert(a), FS.insert(b), FS.insert(c);\n\n  auto dfs\
    \ = [&](auto& dfs, int i) -> void {\n    int j = dat[i].rev;\n    if (j == -1)\
    \ return;\n    int i1 = dat[i].nxt;\n    int i2 = dat[i1].nxt;\n    int j1 = dat[j].nxt;\n\
    \    int j2 = dat[j1].nxt;\n    int b = dat[i].a, c = dat[i1].a, a = dat[i2].a,\
    \ d = dat[j2].a;\n    int side = outcircle_side(A[a], A[b], A[c], A[d]);\n   \
    \ bool flip = (farthest ? (side == -1) : (side == 1));\n    if (!flip) return;\n\
    \    dat[i] = {d, a, i2, j};\n    dat[j] = {a, d, j2, i};\n    dat[i1].nxt = j,\
    \ dat[i2].nxt = j1, dat[j1].nxt = i, dat[j2].nxt = i1;\n    dfs(dfs, i1), dfs(dfs,\
    \ i2), dfs(dfs, j1), dfs(dfs, j2);\n  };\n\n  while (len(I)) {\n    int v = POP(I);\n\
    \    int l = FS.prev(v), r = FS.next(v);\n    if (l == -1) l = FS.prev(N);\n \
    \   if (r == N) r = FS.next(0);\n    FS.insert(v);\n    int k = v_to_e[l];\n \
    \   int s = len(dat);\n    v_to_e[l] = s + 1, v_to_e[v] = s + 2;\n    dat[k].rev\
    \ = s;\n    dat.eb(r, l, s + 1, k);\n    dat.eb(l, v, s + 2, -1);\n    dat.eb(v,\
    \ r, s, -1);\n    dfs(dfs, k);\n  }\n  vc<array<int, 3>> ANS;\n  FOR(i, len(dat))\
    \ {\n    int j = dat[i].nxt;\n    int k = dat[j].nxt;\n    if (i > j || i > k)\
    \ continue;\n    ANS.eb(array<int, 3>{dat[i].a, dat[j].a, dat[k].a});\n  }\n\n\
    \  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/delaunay_triangulation_of_convex_polygon.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/delaunay_triangulation_of_convex_polygon.hpp
layout: document
redirect_from:
- /library/geo/delaunay_triangulation_of_convex_polygon.hpp
- /library/geo/delaunay_triangulation_of_convex_polygon.hpp.html
title: geo/delaunay_triangulation_of_convex_polygon.hpp
---
