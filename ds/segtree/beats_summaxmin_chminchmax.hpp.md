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
  code: "#include \"ds/segtree/lazysegtree_beats.hpp\"\r\n\r\nconstexpr ll Beats_INF\
    \ = 1LL << 40;\r\n\r\nstruct Beats_SumMaxMin_ChminChmax {\r\n  struct CntSumMinMax\
    \ {\r\n    struct X {\r\n      ll cnt, sum, min, max, minc, maxc, min2, max2;\r\
    \n      bool fail;\r\n    };\r\n    using value_type = X;\r\n    static X op(const\
    \ X& x, const X& y) {\r\n      if (x.min > x.max) return y;\r\n      if (y.min\
    \ > y.max) return x;\r\n      X z;\r\n      z.cnt = x.cnt + y.cnt, z.sum = x.sum\
    \ + y.sum;\r\n\r\n      z.min = min(x.min, y.min), z.max = max(x.max, y.max);\r\
    \n      z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\r\
    \n      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\r\
    \n\r\n      z.min2 = z.max;\r\n      if (z.min < x.min && x.min < z.min2) z.min2\
    \ = x.min;\r\n      if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\r\n\
    \      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\r\n      if (z.min\
    \ < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\r\n\r\n      z.max2 = z.min;\r\
    \n      if (z.max > x.max && x.max > z.max2) z.max2 = x.max;\r\n      if (z.max\
    \ > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\r\n      if (z.max > y.max &&\
    \ y.max > z.max2) z.max2 = y.max;\r\n      if (z.max > y.max2 && y.max2 > z.max2)\
    \ z.max2 = y.max2;\r\n\r\n      z.fail = 0;\r\n      return z;\r\n    }\r\n  \
    \  static constexpr X unit() {\r\n      return {0, 0, Beats_INF, -Beats_INF, 0,\
    \ 0, Beats_INF, -Beats_INF, 0};\r\n    }\r\n    bool commute = true;\r\n  };\r\
    \n  struct AddChminChmax {\r\n    using X = tuple<ll, ll, ll>;\r\n    using value_type\
    \ = X;\r\n    static constexpr X op(const X& x, const X& y) {\r\n      auto [a,\
    \ b, c] = x;\r\n      auto [d, e, f] = y;\r\n      a += d, b += d, c += d;\r\n\
    \      b = min(b, e), c = min(c, e);\r\n      c = max(c, f);\r\n      return {a,\
    \ b, c};\r\n    }\r\n    static constexpr X unit() { return {0, Beats_INF, -Beats_INF};\
    \ }\r\n    bool commute = false;\r\n  };\r\n  struct Lazy {\r\n    using MX =\
    \ CntSumMinMax;\r\n    using MA = AddChminChmax;\r\n    using X_structure = MX;\r\
    \n    using A_structure = MA;\r\n    using X = MX::value_type;\r\n    using A\
    \ = MA::value_type;\r\n    static X act(X& x, const A& a) {\r\n      assert(!x.fail);\r\
    \n      if (x.cnt == 0) return x;\r\n      auto [add, mi, ma] = a;\r\n      x.sum\
    \ += x.cnt * add;\r\n      x.min += add, x.max += add;\r\n      x.min2 += add,\
    \ x.max2 += add;\r\n\r\n      if (mi == Beats_INF && ma == -Beats_INF) return\
    \ x;\r\n\r\n      ll before_min = x.min, before_max = x.max;\r\n      x.min =\
    \ min(x.min, mi);\r\n      x.min = max(x.min, ma);\r\n      x.max = min(x.max,\
    \ mi);\r\n      x.max = max(x.max, ma);\r\n\r\n      if (x.min == x.max) {\r\n\
    \        x.sum = x.max * x.cnt;\r\n        x.max2 = x.min2 = x.max;\r\n      \
    \  x.maxc = x.minc = x.cnt;\r\n      }\r\n      elif (x.max2 <= x.min) {\r\n \
    \       x.max2 = x.min, x.min2 = x.max;\r\n        x.minc = x.cnt - x.maxc;\r\n\
    \        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min2\
    \ >= x.max) {\r\n        x.max2 = x.min, x.min2 = x.max;\r\n        x.maxc = x.cnt\
    \ - x.minc;\r\n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n\
    \      elif (x.min < x.min2 && x.max > x.max2) {\r\n        x.sum += (x.min -\
    \ before_min) * x.minc;\r\n        x.sum += (x.max - before_max) * x.maxc;\r\n\
    \      }\r\n      else {\r\n        x.fail = 1;\r\n      }\r\n      return x;\r\
    \n    }\r\n  };\r\n  LazySegTreeBeats<Lazy> seg;\r\n  Beats_SumMaxMin_ChminChmax(vc<ll>&\
    \ A) {\r\n    using X = Lazy::MX::value_type;\r\n    vc<X> seg_raw(len(A));\r\n\
    \    FOR(i, len(A)) {\r\n      ll x = A[i];\r\n      seg_raw[i] = {1, x, x, x,\
    \ 1, 1, x, x, 0};\r\n    }\r\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\r\n \
    \ }\r\n\r\n  void set(int i, ll x) { seg.set(i, {1, x, x, x, 1, 1, x, x, 0});\
    \ }\r\n\r\n  Lazy::MX::value_type prod(int l, int r) {\r\n    auto e = seg.prod(l,\
    \ r);\r\n    return e;\r\n  }\r\n\r\n  void chmin(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, x, -Beats_INF}); }\r\n\r\n  void chmax(int l, int r, ll x) { seg.apply(l,\
    \ r, {0, Beats_INF, x}); }\r\n\r\n  void add(int l, int r, ll x) { seg.apply(l,\
    \ r, {x, Beats_INF, -Beats_INF}); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/beats_summaxmin_chminchmax.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_summaxmin_chminchmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summaxmin_chminchmax.hpp
- /library/ds/segtree/beats_summaxmin_chminchmax.hpp.html
title: ds/segtree/beats_summaxmin_chminchmax.hpp
---
