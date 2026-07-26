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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#include \"other/bit.hpp\"\n#include \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u69CB\u7BC9 O(N), \u30AF\u30A8\u30EA O(1)\n// static_range_product \u3088\
    \u308A\u9045\u3044\u3063\u307D\u3044\u306E\u3067\u4F7F\u3046\u3053\u3068\u306F\
    \u306A\u3055\u305D\u3046\u3060\ntemplate <typename Monoid>\nstruct Static_RMQ\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  static constexpr\
    \ int LOG = 4;\n  int N, b_num;\n  vc<X> A, pre, suf;  // inclusive\n  Sparse_Table<Monoid>\
    \ ST;\n\n  using u16 = unsigned short;\n  vc<u16> dat;\n\n  Static_RMQ() {}\n\
    \  template <typename F>\n  Static_RMQ(int n, F f) {\n    build(n, f);\n  }\n\
    \  Static_RMQ(const vc<X>& v) { build(v); }\n\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    N = m;\n    b_num = N >> LOG;\n    A.resize(N);\n\
    \    FOR(i, N) A[i] = f(i);\n    pre = A, suf = A;\n    FOR(i, 1, N) {\n     \
    \ if (i & 15) pre[i] = MX::op(pre[i - 1], A[i]);\n    }\n    FOR_R(i, 1, N) {\n\
    \      if (i & 15) suf[i - 1] = MX::op(A[i - 1], suf[i]);\n    }\n    ST.build(b_num,\
    \ [&](int i) -> X { return suf[i << LOG]; });\n    // \u9577\u3055 16 \u4EE5\u4E0B\
    \u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\u305F\u3081\u306E\u524D\
    \u8A08\u7B97\n    // [i,i+16) \u5185\u3067 i+j \u304C [i,i+j] \u3067\u306E\u6700\
    \u5C0F\u5024\u3068\u306A\u308B\u5834\u5408\u306B j-th bit \u3092\u7ACB\u3066\u308B\
    \n    dat.resize(N);\n    u32 stack = 0;\n    FOR_R(i, N) {\n      stack = (stack\
    \ << 1) & 65535;\n      while (stack) {\n        int k = lowbit(stack);\n    \
    \    if (MX::op(A[i], A[i + k]) != A[i]) break;\n        stack &= ~(u32(1) <<\
    \ k);\n      }\n      stack |= u32(1);\n      dat[i] = stack;\n    }\n  }\n\n\
    \  X prod(int L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n    if (L\
    \ == R) return MX::unit();\n    if (R - L <= 16) {\n      u32 d = dat[L] & ((u32(1)\
    \ << (R - L)) - 1);\n      return A[L + topbit(d)];\n    }\n    --R;\n    int\
    \ a = L >> LOG, b = R >> LOG;\n    X x = ST.prod(a + 1, b);\n    x = MX::op(suf[L],\
    \ x);\n    x = MX::op(x, pre[R]);\n    return x;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/rmq/static_rmq.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/rmq/static_rmq.hpp
layout: document
redirect_from:
- /library/ds/rmq/static_rmq.hpp
- /library/ds/rmq/static_rmq.hpp.html
title: ds/rmq/static_rmq.hpp
---
