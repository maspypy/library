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
  code: "#include \"ds/segtree/segtree_beats.hpp\"\r\n\r\ntemplate <typename T>\r\n\
    struct Beats_SumMinMax_ChminChmax {\r\n  struct SumMinMax {\r\n    struct X {\r\
    \n      T sum, min, max, minc, maxc, min2, max2;\r\n      bool fail;\r\n    };\r\
    \n    using value_type = X;\r\n    static X op(const X& x, const X& y) {\r\n \
    \     if (x.min > x.max) return y;\r\n      if (y.min > y.max) return x;\r\n \
    \     X z;\r\n      z.sum = x.sum + y.sum;\r\n\r\n      z.min = min(x.min, y.min),\
    \ z.max = max(x.max, y.max);\r\n      z.minc = (x.min == z.min ? x.minc : 0) +\
    \ (y.min == z.min ? y.minc : 0);\r\n      z.maxc = (x.max == z.max ? x.maxc :\
    \ 0) + (y.max == z.max ? y.maxc : 0);\r\n\r\n      z.min2 = z.max;\r\n      if\
    \ (z.min < x.min && x.min < z.min2) z.min2 = x.min;\r\n      if (z.min < x.min2\
    \ && x.min2 < z.min2) z.min2 = x.min2;\r\n      if (z.min < y.min && y.min < z.min2)\
    \ z.min2 = y.min;\r\n      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\r\
    \n\r\n      z.max2 = z.min;\r\n      if (z.max > x.max && x.max > z.max2) z.max2\
    \ = x.max;\r\n      if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;\r\n\
    \      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\r\n      if (z.max\
    \ > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\r\n\r\n      z.fail = 0;\r\n \
    \     return z;\r\n    }\r\n    static constexpr X unit() {\r\n      return {0,\
    \ infty<T>, -infty<T>, 0, 0, infty<T>, -infty<T>, 0};\r\n    }\r\n    bool commute\
    \ = true;\r\n  };\r\n  struct AddChminChmax {\r\n    using X = tuple<T, T, T>;\r\
    \n    using value_type = X;\r\n    static constexpr X op(const X& x, const X&\
    \ y) {\r\n      auto [a, b, c] = x;\r\n      auto [d, e, f] = y;\r\n      a +=\
    \ d, b += d, c += d;\r\n      b = min(b, e), c = min(c, e), c = max(c, f);\r\n\
    \      return {a, b, c};\r\n    }\r\n    static constexpr X unit() { return {0,\
    \ infty<T>, -infty<T>}; }\r\n    bool commute = false;\r\n  };\r\n  struct Beats\
    \ {\r\n    using Monoid_X = SumMinMax;\r\n    using Monoid_A = AddChminChmax;\r\
    \n    using X = typename Monoid_X::value_type;\r\n    using A = typename Monoid_A::value_type;\r\
    \n    static X act(X& x, const A& a, int cnt) {\r\n      assert(!x.fail);\r\n\
    \      if (x.min > x.max) return x;\r\n      auto [add, mi, ma] = a;\r\n     \
    \ x.sum += cnt * add;\r\n      x.min += add, x.max += add, x.min2 += add, x.max2\
    \ += add;\r\n\r\n      if (mi == infty<T> && ma == -infty<T>) return x;\r\n\r\n\
    \      T before_min = x.min, before_max = x.max;\r\n      x.min = min(x.min, mi),\
    \ x.min = max(x.min, ma);\r\n      x.max = min(x.max, mi), x.max = max(x.max,\
    \ ma);\r\n\r\n      if (x.min == x.max) {\r\n        x.sum = x.max * cnt, x.max2\
    \ = x.min2 = x.max, x.maxc = x.minc = cnt;\r\n      }\r\n      elif (x.max2 <=\
    \ x.min) {\r\n        x.max2 = x.min, x.min2 = x.max, x.minc = cnt - x.maxc,\r\
    \n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min2\
    \ >= x.max) {\r\n        x.max2 = x.min, x.min2 = x.max, x.maxc = cnt - x.minc,\r\
    \n        x.sum = x.max * x.maxc + x.min * x.minc;\r\n      }\r\n      elif (x.min\
    \ < x.min2 && x.max > x.max2) {\r\n        x.sum += (x.min - before_min) * x.minc\
    \ + (x.max - before_max) * x.maxc;\r\n      }\r\n      else {\r\n        x.fail\
    \ = 1;\r\n      }\r\n      return x;\r\n    }\r\n  };\r\n\r\n  using X = typename\
    \ SumMinMax::X;\r\n  SegTree_Beats<Beats> seg;\r\n  Beats_SumMinMax_ChminChmax(vc<T>&\
    \ A) {\r\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\r\
    \n  }\r\n  template <typename F>\r\n  Beats_SumMinMax_ChminChmax(int n, F f) {\r\
    \n    seg.build(n, [&](int i) -> X { return from_element(f(i)); });\r\n  }\r\n\
    \  void set(int i, T x) { seg.set(i, from_element(x)); }\r\n\r\n  // (sum, max,\
    \ min)\r\n  tuple<T, T, T> prod(int l, int r) {\r\n    auto e = seg.prod(l, r);\r\
    \n    return {e.sum, e.min, e.max};\r\n  }\r\n  static X from_element(T x) { return\
    \ {x, x, x, 1, 1, x, x, 0}; }\r\n\r\n  void chmin(int l, int r, T x) { seg.apply(l,\
    \ r, {0, x, -infty<T>}); }\r\n  void chmax(int l, int r, T x) { seg.apply(l, r,\
    \ {0, infty<T>, x}); }\r\n  void add(int l, int r, T x) { seg.apply(l, r, {x,\
    \ infty<T>, -infty<T>}); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/beats_summinmax_chminchmax.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_summinmax_chminchmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summinmax_chminchmax.hpp
- /library/ds/segtree/beats_summinmax_chminchmax.hpp.html
title: ds/segtree/beats_summinmax_chminchmax.hpp
---
