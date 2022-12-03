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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/lazysegtree_beats.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/segtree/lazysegtree_beats.hpp\"\n\nconstexpr ll Beats_INF =\
    \ 1LL << 40;\n\nstruct Beats_SumMax_Chmin {\n  struct CntSumMinMax {\n    struct\
    \ X {\n      ll cnt, sum, max, maxc, max2;\n      bool fail;\n    };\n    using\
    \ value_type = X;\n    static X op(const X& x, const X& y) {\n      if (x.cnt\
    \ == 0) return y;\n      if (y.cnt == 0) return x;\n      X z;\n      z.cnt =\
    \ x.cnt + y.cnt, z.sum = x.sum + y.sum;\n\n      z.max = max(x.max, y.max);\n\
    \      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\n\
    \n      z.max2 = -Beats_INF;\n      if (z.max > x.max && x.max > z.max2) z.max2\
    \ = x.max;\n      if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\n  \
    \    if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\n      if (z.max > y.max2\
    \ && y.max2 > z.max2) z.max2 = y.max2;\n\n      z.fail = 0;\n      return z;\n\
    \    }\n    static constexpr X unit() { return {0, 0, 0, 0, 0, 0}; }\n    bool\
    \ commute = true;\n  };\n  struct AddChmin {\n    using X = pi;\n    using value_type\
    \ = X;\n    static constexpr X op(const X& x, const X& y) {\n      auto [a, b]\
    \ = x;\n      auto [d, e] = y;\n      a += d, b += d;\n      b = min(b, e);\n\
    \      return {a, b};\n    }\n    static constexpr X unit() { return {0, Beats_INF};\
    \ }\n    bool commute = false;\n  };\n  struct Lazy {\n    using MX = CntSumMinMax;\n\
    \    using MA = AddChmin;\n    using X_structure = MX;\n    using A_structure\
    \ = MA;\n    using X = MX::value_type;\n    using A = MA::value_type;\n    static\
    \ X act(X& x, const A& a) {\n      if (x.cnt == 0) return x;\n      assert(!x.fail);\n\
    \      auto [add, mi] = a;\n      x.sum += x.cnt * add;\n      x.max += add;\n\
    \      x.max2 += add;\n\n      if (mi == Beats_INF) return x;\n\n      ll before_max\
    \ = x.max;\n      x.max = min(x.max, mi);\n      if (x.maxc == x.cnt) {\n    \
    \    x.min2 = x.max;\n        x.sum = x.cnt * x.max;\n        return x;\n    \
    \  }\n      if (x.max2 < x.max) {\n        x.sum += (x.max - before_max) * x.maxc;\n\
    \      } else {\n        x.fail = 1;\n      }\n      return x;\n    }\n  };\n\
    \  LazySegTreeBeats<Lazy> seg;\n  Beats_SumMax_Chmin(vc<ll>& A) {\n    using X\
    \ = Lazy::MX::value_type;\n    vc<X> seg_raw(len(A));\n    FOR(i, len(A)) {\n\
    \      ll x = A[i];\n      seg_raw[i] = {1, x, x, 1, x};\n    }\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\n\
    \  }\n\n  template <typename F>\n  Beats_SumMax_Chmin(int N, F f) {\n    using\
    \ X = Lazy::MX::value_type;\n    vc<X> seg_raw(N);\n    FOR(i, N) {\n      ll\
    \ x = f(i);\n      seg_raw[i] = {1, x, x, 1, x};\n    }\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\n\
    \  }\n\n  void set(int i, ll x) { seg.set(i, {1, x, x, 1, x}); }\n\n  Lazy::MX::value_type\
    \ prod(int l, int r) {\n    auto e = seg.prod(l, r);\n    return e;\n  }\n\n \
    \ void chmin(int l, int r, ll x) { seg.apply(l, r, {0, x}); }\n\n  void add(int\
    \ l, int r, ll x) { seg.apply(l, r, {x, Beats_INF}); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/beats_summax_chmin.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_summax_chmin.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summax_chmin.hpp
- /library/ds/segtree/beats_summax_chmin.hpp.html
title: ds/segtree/beats_summax_chmin.hpp
---
