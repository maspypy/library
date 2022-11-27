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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"alg/group/add.hpp\"\n\ntemplate <typename AbelGroup>\n\
    struct FenwickTree {\n  using E = typename AbelGroup::value_type;\n  int n;\n\
    \  vector<E> dat;\n  E total;\n\n  FenwickTree(int n = 0) : n(n) {\n    assert(AbelGroup::commute);\n\
    \    reset(n);\n  }\n  FenwickTree(const vector<E>& v) {\n    assert(AbelGroup::commute);\n\
    \    build(v);\n  }\n\n  void build(const vc<E>& v) {\n    n = len(v);\n    total\
    \ = AbelGroup::unit();\n    for (int i = 0; i < n; ++i) total = AbelGroup::op(total,\
    \ v[i]);\n    dat = v;\n    for (int i = 1; i <= n; ++i) {\n      int j = i +\
    \ (i & -i);\n      if (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n  }\n\n  void reset(int sz = 0) {\n    if (sz) n = sz;\n    total\
    \ = AbelGroup::unit();\n    dat.assign(n, AbelGroup::unit());\n  }\n\n  E prod(int\
    \ k) {\n    E ret = AbelGroup::unit();\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E prod(int L, int R) {\n    E pos =\
    \ AbelGroup::unit();\n    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R\
    \ - 1]);\n      R -= R & -R;\n    }\n    E neg = AbelGroup::unit();\n    while\
    \ (R < L) {\n      neg = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n\
    \    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n  }\n\n  E prod_all()\
    \ { return total; }\n\n  E sum(int k) { return prod(k); }\n\n  E sum(int L, int\
    \ R) { return prod(L, R); }\n\n  E sum_all() { return total; }\n\n  void multiply(int\
    \ k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <= n; k +=\
    \ k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  void add(int k,\
    \ E x) { multiply(k, x); }\n\n  template <class F>\n  int max_right(F& check)\
    \ {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n \
    \   int k = 1;\n    int N = dat.size() + 1;\n    while (2 * k < N) k *= 2;\n \
    \   while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwick.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwick.hpp
layout: document
redirect_from:
- /library/ds/fenwick.hpp
- /library/ds/fenwick.hpp.html
title: ds/fenwick.hpp
---
