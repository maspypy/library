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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/lazysegtree_beats.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/lazysegtree_beats.hpp\"\n\nconstexpr ll Beats_INF = 1LL <<\
    \ 40;\n\nstruct Beats_SumMin_Chmax {\n  struct CntSumMin {\n    struct X {\n \
    \     ll cnt, sum, min, minc, min2;\n      bool fail;\n    };\n    using value_type\
    \ = X;\n    static X op(const X& x, const X& y) {\n      if (x.cnt == 0) return\
    \ y;\n      if (y.cnt == 0) return x;\n      X z;\n      z.cnt = x.cnt + y.cnt,\
    \ z.sum = x.sum + y.sum;\n\n      z.min = min(x.min, y.min);\n      z.minc = (x.min\
    \ == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\n\n      z.min2 = Beats_INF;\n\
    \      if (z.min < x.min && x.min < z.min2) z.min2 = x.min;\n      if (z.min <\
    \ x.min2 && x.min2 < z.min2) z.min2 = x.min2;\n      if (z.min < y.min && y.min\
    \ < z.min2) z.min2 = y.min;\n      if (z.min < y.min2 && y.min2 < z.min2) z.min2\
    \ = y.min2;\n\n      z.fail = 0;\n      return z;\n    }\n    static constexpr\
    \ X unit() { return {0, 0, 0, 0, 0, 0}; }\n    bool commute = true;\n  };\n  struct\
    \ AddChmax {\n    using X = pi;\n    using value_type = X;\n    static constexpr\
    \ X op(const X& x, const X& y) {\n      auto [a, c] = x;\n      auto [d, f] =\
    \ y;\n      a += d, c += d;\n      c = max(c, f);\n      return {a, c};\n    }\n\
    \    static constexpr X unit() { return {0, -Beats_INF}; }\n    bool commute =\
    \ false;\n  };\n  struct Lazy {\n    using MX = CntSumMin;\n    using MA = AddChmax;\n\
    \    using X_structure = MX;\n    using A_structure = MA;\n    using X = MX::value_type;\n\
    \    using A = MA::value_type;\n    static X act(X& x, const A& a) {\n      if\
    \ (x.cnt == 0) return x;\n      assert(!x.fail);\n      auto [add, ma] = a;\n\
    \      x.sum += x.cnt * add;\n      x.min += add, x.min2 += add;\n      if (ma\
    \ == -Beats_INF) return x;\n\n      ll before_min = x.min;\n      x.min = max(x.min,\
    \ ma);\n      if (x.minc == x.cnt) {\n        x.min2 = x.min;\n        x.sum =\
    \ x.cnt * x.min;\n        return x;\n      }\n      if (x.min2 > x.min) {\n  \
    \      x.sum += (x.min - before_min) * x.minc;\n      } else {\n        x.fail\
    \ = 1;\n      }\n      return x;\n    }\n  };\n  LazySegTreeBeats<Lazy> seg;\n\
    \  Beats_SumMin_Chmax(vc<ll>& A) {\n    using X = Lazy::MX::value_type;\n    vc<X>\
    \ seg_raw(len(A));\n    FOR(i, len(A)) {\n      ll x = A[i];\n      seg_raw[i]\
    \ = {1, x, x, 1, x};\n    }\n    seg = LazySegTreeBeats<Lazy>(seg_raw);\n  }\n\
    \n  void set(int i, ll x) { seg.set(i, {1, x, x, 1, x}); }\n\n  Lazy::MX::value_type\
    \ prod(int l, int r) {\n    auto e = seg.prod(l, r);\n    return e;\n  }\n\n \
    \ void chmax(int l, int r, ll x) { seg.apply(l, r, {0, x}); }\n\n  void add(int\
    \ l, int r, ll x) { seg.apply(l, r, {x, -Beats_INF}); }\n\n  void apply(int l,\
    \ int r, pi addchmax) { seg.apply(l, r, addchmax); }\n};\n"
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
