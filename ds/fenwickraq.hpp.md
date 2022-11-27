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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/fenwick.hpp\"\r\ntemplate <typename AbelGroup>\r\nstruct FenwickRAQ\
    \ {\r\n  using E = typename AbelGroup::value_type;\r\n  int n;\r\n  FenwickTree<AbelGroup>\
    \ bit0;\r\n  FenwickTree<AbelGroup> bit1;\r\n\r\n  FenwickRAQ() : FenwickRAQ(0)\
    \ {}\r\n  FenwickRAQ(int n) : n(n), bit0(n), bit1(n) {}\r\n  FenwickRAQ(vc<E>\
    \ v) : n(len(v)), bit0(v), bit1(len(v)) {}\r\n\r\n  void add(ll i, E val) { bit0.add(i,\
    \ val); }\r\n\r\n  void add(ll L, ll R, E val) {\r\n    bit0.add(L, AbelGroup::power(val,\
    \ -L));\r\n    bit0.add(R, AbelGroup::power(val, R));\r\n    bit1.add(L, val);\r\
    \n    bit1.add(R, AbelGroup::inverse(val));\r\n  }\r\n\r\n  E prod(ll L, ll R)\
    \ {\r\n    E prod_R = AbelGroup::op(AbelGroup::power(bit1.prod(R), R), bit0.prod(R));\r\
    \n    E prod_L = AbelGroup::op(AbelGroup::power(bit1.prod(L), L), bit0.prod(L));\r\
    \n    return AbelGroup::op(AbelGroup::inverse(prod_L), prod_R);\r\n  }\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwickraq.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwickraq.hpp
layout: document
redirect_from:
- /library/ds/fenwickraq.hpp
- /library/ds/fenwickraq.hpp.html
title: ds/fenwickraq.hpp
---
