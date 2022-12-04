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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/pds/array.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/pds/array.hpp\"\r\n\r\nstruct PersistentUnionFind {\r\n  using\
    \ PA = PersistentArray<int>;\r\n  int n;\r\n  PA data; // root OR (-size)\r\n\
    \  using np = PA::np;\r\n\r\n  PersistentUnionFind(int n) : n(n) {}\r\n  np init()\
    \ {\r\n    np t = data.get_root();\r\n    FOR(i, n) data.destructive_set(t, i,\
    \ -1);\r\n    return t;\r\n  }\r\n\r\n  pair<bool, np> merge(np t, int x, int\
    \ y) {\r\n    x = root(t, x), y = root(t, y);\r\n    if (x == y) return {0, t};\r\
    \n    if (data.get(t, x) > data.get(t, y)) swap(x, y);\r\n    int new_sz = data.get(t,\
    \ x) + data.get(t, y);\r\n    np set_x_sz = data.set(t, x, new_sz);\r\n    np\
    \ set_y_par = data.set(set_x_sz, y, x);\r\n    return {1, set_y_par};\r\n  }\r\
    \n\r\n  int root(np t, int x) {\r\n    int par_or_sz = data.get(t, x);\r\n   \
    \ if (par_or_sz < 0) return x;\r\n    return root(t, par_or_sz);\r\n  }\r\n\r\n\
    \  bool same(np t, int x, int y) { return root(t, x) == root(t, y); }\r\n  int\
    \ size(np t, int x) { return -data.get(t, root(t, x)); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/persistent_unionfind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/persistent_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/persistent_unionfind.hpp
- /library/ds/unionfind/persistent_unionfind.hpp.html
title: ds/unionfind/persistent_unionfind.hpp
---
