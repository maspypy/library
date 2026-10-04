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
  code: "#include \"ds/segtree/segtree.hpp\"\n#include \"alg/monoid_pow.hpp\"\n#include\
    \ \"ds/fastset.hpp\"\n\ntemplate <typename Monoid>\nstruct Range_Assignment_SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  SegTree<MX>\
    \ seg;\n  FastSet cut;\n  vc<X> dat;\n\n  Range_Assignment_SegTree() {}\n  Range_Assignment_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Range_Assignment_SegTree(int n,\
    \ F f) {\n    build(n, f);\n  }\n  Range_Assignment_SegTree(const vc<X> &v) {\
    \ build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::id();\
    \ });\n  }\n  void build(const vc<X> &v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m;\n    seg.build(m, f), cut.build(n, [&](int i) -> int { return 1; });\n\
    \    dat = seg.get_all();\n  }\n\n  X prod(int l, int r) {\n    int a = cut.prev(l),\
    \ b = cut.next(l), c = cut.prev(r);\n    if (a == c) {\n      return monoid_pow<MX>(dat[a],\
    \ r - l);\n    };\n    assert(b <= c);\n    X x = monoid_pow<MX>(dat[a], b - l);\n\
    \    X y = seg.prod(b, c);\n    X z = monoid_pow<MX>(dat[c], r - c);\n    return\
    \ MX::op(MX::op(x, y), z);\n  }\n\n  X prod_all() { return seg.prod_all(); }\n\
    \n  void assign(int l, int r, X x) {\n    if (l == r) return;\n    int a = cut.prev(l),\
    \ b = cut.next(r);\n    if (a < l) seg.set(a, monoid_pow<MX>(dat[a], l - a));\n\
    \    if (r < b) {\n      X y = dat[cut.prev(r)];\n      dat[r] = y, cut.insert(r),\
    \ seg.set(r, monoid_pow<MX>(y, b - r));\n    }\n    cut.enumerate(l + 1, r,\n\
    \                  [&](int i) -> void { seg.set(i, MX::id()), cut.erase(i); });\n\
    \    dat[l] = x, cut.insert(l), seg.set(l, monoid_pow<MX>(x, r - l));\n  }\n\n\
    \  vc<X> get_all() {\n    vc<X> ANS(n);\n    int p = 0;\n    while (p < n) {\n\
    \      int q = cut.next(p + 1);\n      FOR(i, p, q) ANS[i] = dat[p];\n      p\
    \ = q;\n    }\n    return ANS;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/range_assignment_segtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/range_assignment_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_assignment_segtree.hpp
- /library/ds/segtree/range_assignment_segtree.hpp.html
title: ds/segtree/range_assignment_segtree.hpp
---
