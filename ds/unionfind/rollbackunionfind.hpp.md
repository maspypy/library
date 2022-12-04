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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/pds/rollbackarray.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/pds/rollbackarray.hpp\"\r\n\r\nstruct RollbackUnionFind {\r\
    \n  RollbackArray<int> dat; // parent or size\r\n\r\n  RollbackUnionFind(int n)\
    \ : dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int v) {\r\n    while (dat.get(v)\
    \ >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\n\r\n  int size(int v) { return\
    \ -dat.get((*this)[v]); }\r\n  int time() { return dat.time(); }\r\n  void rollback(int\
    \ t) { dat.rollback(t); }\r\n\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a],\
    \ b = (*this)[b];\r\n    if (a == b) return false;\r\n    if (dat.get(a) > dat.get(b))\
    \ swap(a, b);\r\n    dat.set(a, dat.get(a) + dat.get(b));\r\n    dat.set(b, a);\r\
    \n    return true;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/rollbackunionfind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/rollbackunionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/rollbackunionfind.hpp
- /library/ds/unionfind/rollbackunionfind.hpp.html
title: ds/unionfind/rollbackunionfind.hpp
---
