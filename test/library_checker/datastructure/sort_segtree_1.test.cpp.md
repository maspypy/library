---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/sortable_segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/sortable_segtree.hpp\"\
    \n#include \"alg/monoid/affine.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  // \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u3059\
    \u308B\u65B9\n\n  using AFF = Monoid_Affine<mint>;\n  LL(N, Q);\n  vc<int> key(N);\n\
    \  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) { read(key[i]), read(seg_raw[i]);\
    \ }\n\n  vc<int> all_key = key;\n  using QT = tuple<int, int, int, int, int>;\n\
    \  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(i,\
    \ p, a, b);\n      query[q] = {t, i, p, a, b};\n      all_key.eb(p);\n    }\n\
    \    if (t == 1) {\n      LL(l, r, x);\n      query[q] = {t, l, r, x, 0};\n  \
    \  }\n    if (t == 2 || t == 3) {\n      LL(l, r);\n      query[q] = {t, l, r,\
    \ 0, 0};\n    }\n  }\n\n  UNIQUE(all_key);\n  for (auto&& k: key) k = LB(all_key,\
    \ k);\n\n  Sortable_SegTree<AFF> seg(len(all_key), key, seg_raw);\n\n  for (auto&&\
    \ [t, a, b, c, d]: query) {\n    if (t == 0) {\n      b = LB(all_key, b);\n  \
    \    seg.set(a, b, {mint(c), mint(d)});\n    }\n    if (t == 1) {\n      auto\
    \ f = seg.prod(a, b);\n      print(AFF::eval(f, c));\n    }\n    if (t == 2) {\
    \ seg.sort_inc(a, b); }\n    if (t == 3) { seg.sort_dec(a, b); }\n  }\n}\n\nsigned\
    \ main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  ll T = 1;\n  FOR(T) solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/sort_segtree_1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/sort_segtree_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/sort_segtree_1.test.cpp
- /verify/test/library_checker/datastructure/sort_segtree_1.test.cpp.html
title: test/library_checker/datastructure/sort_segtree_1.test.cpp
---
