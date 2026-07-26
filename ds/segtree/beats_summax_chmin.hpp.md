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
  code: "#include \"ds/segtree/segtree_beats.hpp\"\ntemplate <typename T>\nstruct\
    \ Beats_SumMax_Chmin {\n  struct SumMax {\n    struct X {\n      T sum, max, maxc,\
    \ max2;\n      bool fail;\n    };\n    using value_type = X;\n    static X op(const\
    \ X& x, const X& y) {\n      if (x.max == -infty<T>) return y;\n      if (y.max\
    \ == -infty<T>) return x;\n      X z;\n      z.sum = x.sum + y.sum;\n\n      z.max\
    \ = max(x.max, y.max);\n      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max\
    \ == z.max ? y.maxc : 0);\n\n      z.max2 = -infty<T>;\n      if (z.max > x.max\
    \ && x.max > z.max2) z.max2 = x.max;\n      if (z.max > x.max2 && x.max2 > z.max2)\
    \ z.max2 = x.max2;\n      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;\n\
    \      if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\n\n      z.fail\
    \ = 0;\n      return z;\n    }\n    static constexpr X unit() { return {0, -infty<T>,\
    \ 0, -infty<T>, 0}; }\n    bool commute = true;\n  };\n  struct AddChmin {\n \
    \   using X = pair<T, T>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) {\n      auto [a, b] = x;\n      auto [d, e] = y;\n      a\
    \ += d, b += d, b = min(b, e);\n      return {a, b};\n    }\n    static constexpr\
    \ X unit() { return {0, infty<T>}; }\n    bool commute = false;\n  };\n  struct\
    \ Beats {\n    using Monoid_X = SumMax;\n    using Monoid_A = AddChmin;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& x, const A& a, int cnt) {\n      assert(!x.fail);\n     \
    \ if (x.max == -infty<T>) return x;\n      auto [add, mi] = a;\n      x.sum +=\
    \ cnt * add, x.max += add, x.max2 += add;\n\n      if (mi == infty<T>) return\
    \ x;\n\n      T before_max = x.max;\n      x.max = min(x.max, mi);\n      if (x.maxc\
    \ == cnt) { x.max2 = x.max, x.sum = cnt * x.max; }\n      elif (x.max2 < x.max)\
    \ { x.sum += (x.max - before_max) * x.maxc; }\n      else {\n        x.fail =\
    \ 1;\n      }\n      return x;\n    }\n  };\n  using X = typename SumMax::X;\n\
    \  SegTree_Beats<Beats> seg;\n  Beats_SumMax_Chmin(vc<T>& A) {\n    seg.build(len(A),\
    \ [&](int i) -> X { return from_element(A[i]); });\n  }\n  template <typename\
    \ F>\n  Beats_SumMax_Chmin(int n, F f) {\n    seg.build(n, [&](int i) -> X { return\
    \ from_element(f(i)); });\n  }\n\n  void set(int i, T x) { seg.set(i, from_element(x));\
    \ }\n\n  // (sum, max)\n  pair<T, T> prod(int l, int r) {\n    auto e = seg.prod(l,\
    \ r);\n    return {e.sum, e.max};\n  }\n  static X from_element(T x) { return\
    \ {x, x, 1, x}; }\n\n  void chmin(int l, int r, ll x) { seg.apply(l, r, {0, x});\
    \ }\n  void add(int l, int r, ll x) { seg.apply(l, r, {x, infty<T>}); }\n};\n"
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
