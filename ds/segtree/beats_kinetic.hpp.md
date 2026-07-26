---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d
    - https://codeforces.com/blog/entry/82094#comment-688448
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
  code: "#include \"ds/segtree/segtree_beats.hpp\"\n\n// (x[i],y[i]) \u304B\u3089\u306A\
    \u308B\u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\u306B y[i] := y[i] + ax[i] +\
    \ b\n// \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\u308B x \u306B\u306F\u5358\
    \u8ABF\u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1, y,sum(b):T2,\n// T1*T1<=T2.\
    \ https://codeforces.com/blog/entry/82094#comment-688448\n// https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\n\
    template <typename T1, typename T2>\nstruct Beats_Kinetic_Max {\n  struct Mono_X\
    \ {\n    struct X {\n      int idx;\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n\
    \      bool fail;\n    };\n    using value_type = X;\n    static X op(X L, X R)\
    \ {\n      X M;\n      if (L.y < R.y) {\n        swap(L, R);\n      }\n      M.idx\
    \ = L.idx, M.x = L.x, M.y = L.y;\n      M.nxt_change = min(L.nxt_change, R.nxt_change);\n\
    \      if (L.x < R.x) {\n        T2 t = floor<T2>(L.y - R.y, R.x - L.x);\n   \
    \     M.nxt_change = min<T2>(M.nxt_change, t + 1);\n      }\n      M.fail = 0;\n\
    \      return M;\n    }\n    static constexpr X unit() { return {-1, 0, -infty<T2>,\
    \ infty<T1>, 0}; }\n    bool commute = true;\n  };\n  struct Mono_A {\n    using\
    \ X = pair<T1, T2>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) {\n      return {x.fi + y.fi, x.se + y.se};\n    }\n    static\
    \ constexpr X unit() { return {0, 0}; }\n    bool commute = true;\n  };\n  struct\
    \ Beats {\n    using Monoid_X = Mono_X;\n    using Monoid_A = Mono_A;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& M, const A& a, int cnt) {\n      assert(!M.fail && a.fi >=\
    \ 0);\n      if (M.nxt_change <= a.fi) {\n        M.fail = 1;\n        return\
    \ M;\n      }\n      M.y += T2(a.fi) * M.x + a.se;\n      M.nxt_change -= a.fi;\n\
    \      return M;\n    }\n  };\n  using S = typename Mono_X::X;\n  SegTree_Beats<Beats>\
    \ seg;\n  Beats_Kinetic_Max(vc<T1>& X, vc<T2>& Y) {\n    seg.build(len(X),\n \
    \             [&](int i) -> S { return {i, X[i], Y[i], infty<T1>, 0}; });\n  }\n\
    \  template <typename F>\n  Beats_Kinetic_Max(int n, F f) {\n    seg.build(n,\
    \ [&](int i) -> S {\n      auto [x, y] = f(i);\n      return {i, x, y, infty<T1>,\
    \ 0};\n    });\n  }\n\n  void set(int i, T1 x, T2 y) { seg.set(i, {i, x, y, infty<T1>,\
    \ 0}); }\n\n  // (i,x,y)\n  tuple<int, T1, T2> prod(int l, int r) {\n    auto\
    \ e = seg.prod(l, r);\n    return {e.idx, e.x, e.y};\n  }\n  // (i,x,y)\n  tuple<int,\
    \ T1, T2> prod_all() {\n    auto e = seg.prod_all();\n    return {e.idx, e.x,\
    \ e.y};\n  }\n  // y[i] := y[i] + ax[i] + b\n  void apply(int l, int r, T1 a,\
    \ T2 b) { seg.apply(l, r, {a, b}); }\n};\n\n// (x[i],y[i]) \u304B\u3089\u306A\u308B\
    \u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\u306B y[i] := y[i] + ax[i] + b\n//\
    \ \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\u308B x \u306B\u306F\u5358\u8ABF\
    \u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1, y,sum(b):T2,\n// T1*T1<=T2.\
    \ https://codeforces.com/blog/entry/82094#comment-688448\n// https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\n\
    template <typename T1, typename T2>\nstruct Beats_Kinetic_Min {\n  struct Mono_X\
    \ {\n    struct X {\n      int idx;\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n\
    \      bool fail;\n    };\n    using value_type = X;\n    static X op(X L, X R)\
    \ {\n      X M;\n      if (L.y > R.y) {\n        swap(L, R);\n      }\n      M.idx\
    \ = L.idx, M.x = L.x, M.y = L.y;\n      M.nxt_change = min(L.nxt_change, R.nxt_change);\n\
    \      if (L.x > R.x) {\n        T2 t = floor<T2>(R.y - L.y, L.x - R.x);\n   \
    \     M.nxt_change = min<T2>(M.nxt_change, t + 1);\n      }\n      M.fail = 0;\n\
    \      return M;\n    }\n    static constexpr X unit() { return {-1, 0, infty<T2>,\
    \ infty<T1>, 0}; }\n    bool commute = true;\n  };\n  struct Mono_A {\n    using\
    \ X = pair<T1, T2>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) {\n      return {x.fi + y.fi, x.se + y.se};\n    }\n    static\
    \ constexpr X unit() { return {0, 0}; }\n    bool commute = true;\n  };\n  struct\
    \ Beats {\n    using Monoid_X = Mono_X;\n    using Monoid_A = Mono_A;\n    using\
    \ X = typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& M, const A& a, int cnt) {\n      assert(!M.fail && a.fi >=\
    \ 0);\n      if (M.nxt_change <= a.fi) {\n        M.fail = 1;\n        return\
    \ M;\n      }\n      M.y += T2(a.fi) * M.x + a.se;\n      M.nxt_change -= a.fi;\n\
    \      return M;\n    }\n  };\n  using S = typename Mono_X::X;\n  SegTree_Beats<Beats>\
    \ seg;\n  Beats_Kinetic_Min(vc<T1>& X, vc<T2>& Y) {\n    seg.build(len(X),\n \
    \             [&](int i) -> S { return {i, X[i], Y[i], infty<T1>, 0}; });\n  }\n\
    \  template <typename F>\n  Beats_Kinetic_Min(int n, F f) {\n    seg.build(n,\
    \ [&](int i) -> S {\n      auto [x, y] = f(i);\n      return {i, x, y, infty<T1>,\
    \ 0};\n    });\n  }\n\n  void set(int i, T1 x, T2 y) { seg.set(i, {i, x, y, infty<T1>,\
    \ 0}); }\n\n  // (i,x,y)\n  tuple<int, T1, T2> prod(int l, int r) {\n    auto\
    \ e = seg.prod(l, r);\n    return {e.idx, e.x, e.y};\n  }\n  tuple<int, T1, T2>\
    \ prod_all() {\n    auto e = seg.prod_all();\n    return {e.idx, e.x, e.y};\n\
    \  }\n\n  // y[i] := y[i] + ax[i] + b\n  void apply(int l, int r, T1 a, T2 b)\
    \ { seg.apply(l, r, {a, b}); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/beats_kinetic.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/beats_kinetic.hpp
layout: document
redirect_from:
- /library/ds/segtree/beats_kinetic.hpp
- /library/ds/segtree/beats_kinetic.hpp.html
title: ds/segtree/beats_kinetic.hpp
---
