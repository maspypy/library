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
    \ Beats_SumMin_Chmax {\n  struct SumMin {\n    struct X {\n      T sum, min, minc,\
    \ min2;\n      bool fail;\n    };\n    using value_type = X;\n    static X op(const\
    \ X& x, const X& y) {\n      if (x.min == infty<T>) return y;\n      if (y.min\
    \ == infty<T>) return x;\n      X z;\n      z.sum = x.sum + y.sum;\n\n      z.min\
    \ = min(x.min, y.min);\n      z.minc = (x.min == z.min ? x.minc : 0) + (y.min\
    \ == z.min ? y.minc : 0);\n\n      z.min2 = infty<T>;\n      if (z.min < x.min\
    \ && x.min < z.min2) z.min2 = x.min;\n      if (z.min < x.min2 && x.min2 < z.min2)\
    \ z.min2 = x.min2;\n      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;\n\
    \      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;\n\n      z.fail\
    \ = 0;\n      return z;\n    }\n    static constexpr X unit() { return {0, infty<T>,\
    \ 0, infty<T>, 0}; }\n    bool commute = true;\n  };\n  struct AddChmax {\n  \
    \  using X = pair<T, T>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) {\n      auto [a, c] = x;\n      auto [d, f] = y;\n      a\
    \ += d, c += d, c = max(c, f);\n      return {a, c};\n    }\n    static constexpr\
    \ X unit() { return {0, -infty<T>}; }\n    bool commute = false;\n  };\n  struct\
    \ Beats {\n    using Monoid_X = SumMin;\n    using Monoid_A = AddChmax;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& x, const A& a, int cnt) {\n      assert(!x.fail);\n     \
    \ if (x.min == infty<T>) return x;\n      auto [add, ma] = a;\n      x.sum +=\
    \ cnt * add, x.min += add, x.min2 += add;\n      if (ma == -infty<T>) return x;\n\
    \n      T before_min = x.min;\n      x.min = max(x.min, ma);\n      if (x.minc\
    \ == cnt) {\n        x.min2 = x.min, x.sum = cnt * x.min;\n      }\n      elif\
    \ (x.min2 > x.min) { x.sum += (x.min - before_min) * x.minc; }\n      else {\n\
    \        x.fail = 1;\n      }\n      return x;\n    }\n  };\n  using X = typename\
    \ SumMin::X;\n  SegTree_Beats<Beats> seg;\n  Beats_SumMin_Chmax() {}\n  Beats_SumMin_Chmax(vc<T>&\
    \ A) {\n    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });\n\
    \  }\n  template <typename F>\n  Beats_SumMin_Chmax(int n, F f) {\n    seg.build(n,\
    \ [&](int i) -> X { return from_element(f(i)); });\n  }\n\n  template <typename\
    \ F>\n  void build(int n, F f) {\n    seg.build(n, [&](int i) -> X { return from_element(f(i));\
    \ });\n  }\n\n  void set(int i, T x) { seg.set(i, from_element(x)); }\n\n  //\
    \ (sum, min)\n  pair<T, T> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n\
    \    return {e.sum, e.min};\n  }\n  static X from_element(T x) { return {x, x,\
    \ 1, x}; }\n\n  void chmax(int l, int r, T x) { seg.apply(l, r, {0, x}); }\n \
    \ void add(int l, int r, T x) { seg.apply(l, r, {x, -infty<T>}); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/beats_summin_chmax.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_summin_chmax.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_summin_chmax.hpp
- /library/ds/segtree/beats_summin_chmax.hpp.html
title: ds/segtree/beats_summin_chmax.hpp
---
