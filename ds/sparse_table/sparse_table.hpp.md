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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#pragma once\n#include \"bit.hpp\"\n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002disjoint sparse table\
    \ \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\nstruct Sparse_Table\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n, log;\n\
    \  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) { build(n); }\n \
    \ template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n\
    \  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m,\
    \ [](int i) -> X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i, n) dat[0][i]\
    \ = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i]) - (1 <<\
    \ i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j],\
    \ dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int L, int R) const\
    \ {\n    if (L == R) return MX::unit();\n    if (R == L + 1) return dat[0][L];\n\
    \    int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R - (1 <<\
    \ k)]);\n  }\n\n  template <class F>\n  int max_right(const F check, int L) const\
    \ {\n    assert(0 <= L && L <= n && check(MX::unit()));\n    if (L == n) return\
    \ n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok\
    \ + ng) / 2;\n      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n    \
    \  if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) const {\n    assert(0 <= R && R <= n && check(MX::unit()));\n\
    \    if (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sparse_table/sparse_table.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sparse_table/sparse_table.hpp
layout: document
redirect_from:
- /library/ds/sparse_table/sparse_table.hpp
- /library/ds/sparse_table/sparse_table.hpp.html
title: ds/sparse_table/sparse_table.hpp
---
