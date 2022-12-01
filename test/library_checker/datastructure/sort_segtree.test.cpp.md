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
    \ = modint998;\n\nvoid solve() {\n  // \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u306A\
    \u3057\u306E\u65B9\n\n  using AFF = Monoid_Affine<mint>;\n  LL(N, Q);\n  vc<int>\
    \ key(N);\n  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) { read(key[i]), read(seg_raw[i]);\
    \ }\n\n  Sortable_SegTree<AFF> seg(1LL << 30, key, seg_raw);\n\n  int i, p, l,\
    \ r;\n  pair<mint, mint> f;\n  mint x;\n\n  FOR(Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      read(i), read(p), read(f);\n      seg.set(i, p, f);\n    }\n   \
    \ if (t == 1) {\n      read(l), read(r), read(x);\n      auto f = seg.prod(l,\
    \ r);\n      print(AFF::eval(f, x));\n    }\n    if (t == 2) {\n      read(l),\
    \ read(r);\n      seg.sort_inc(l, r);\n    }\n    if (t == 3) {\n      read(l),\
    \ read(r);\n      seg.sort_dec(l, r);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  FOR(T) solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/sort_segtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/sort_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/sort_segtree.test.cpp
- /verify/test/library_checker/datastructure/sort_segtree.test.cpp.html
title: test/library_checker/datastructure/sort_segtree.test.cpp
---
