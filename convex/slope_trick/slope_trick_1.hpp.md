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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/double_end_queue_const_add.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"ds/double_end_queue_const_add.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n\nstruct Slope_Trick_1 {\n  struct FUNC {\n    // \u5B9A\u7FA9\u57DF\u306E\u4E21\
    \u7AEF\u306F que \u306B\u5165\u308C\u308B\u3053\u3068\u306B\u3057\u3066 que \u304C\
    \u7A7A\u3067\u306A\u3044\u72B6\u614B\u3092\u4FDD\u3064\n    Double_Ended_Queue_Const_Add<Monoid_Add<ll>>\
    \ que_l, que_r;\n    i128 min_f = 0;\n    int size() { return que_l.size() + que_r.size();\
    \ }\n  };\n\n  // O(|a|)\n  FUNC segment_func(ll L, ll R, ll a, ll b) {\n    FUNC\
    \ f;\n    if (a >= 0) {\n      f.min_f = i128(a) * L + b;\n      f.que_l.push(L);\n\
    \      FOR(a) f.que_r.push(L);\n      f.que_r.push(R);\n    } else {\n      f.min_f\
    \ = i128(a) * R + b;\n      f.que_r.push(R);\n      FOR(-a) f.que_l.push(R);\n\
    \      f.que_l.push(L);\n    }\n    return f;\n  }\n\n  pair<ll, ll> domain(FUNC\
    \ &f) { return {f.que_l.min(), f.que_r.max()}; }\n\n  // O(N)\n  i128 eval(FUNC\
    \ &f, ll x) {\n    auto [x0, x1] = domain(f);\n    assert(x0 <= x && x <= x1);\n\
    \    i128 ans = f.min_f;\n    f.que_l.enumerate_all([&](ll l) -> void { ans +=\
    \ max<ll>(l - x, 0); });\n    f.que_r.enumerate_all([&](ll r) -> void { ans +=\
    \ max<ll>(x - r, 0); });\n    return ans;\n  }\n\n  // \u3082\u3068\u306E min_f\
    \ \u3068\u5B9A\u7FA9\u57DF\u304C\u4EA4\u308F\u308B\u5834\u5408\u3060\u3051\u5B9F\
    \u88C5\u3057\u305F\n  FUNC restrict_domain(FUNC &f, ll L, ll R) {\n    auto [x0,\
    \ x1] = domain(f);\n    chmax(L, x0), chmin(R, x1);\n    while (!f.que_l.empty()\
    \ && f.que_l.min() <= L) { f.que_l.pop_min(); }\n    while (!f.que_r.empty() &&\
    \ f.que_r.max() >= R) { f.que_r.pop_max(); }\n    f.que_l.push(L);\n    f.que_r.push(R);\n\
    \    return f;\n  }\n\n  // +(ax+b), O(|a|*log)\n  FUNC add_linear(FUNC &f, ll\
    \ a, ll b) {\n    auto [x0, x1] = domain(f);\n    f.min_f += b;\n    while (a\
    \ > 0) {\n      f.min_f += f.que_l.pop_max();\n      f.que_r.push(f.que_l.pop_max());\n\
    \      if (f.que_l.empty()) f.que_l.push(x0);\n      --a;\n    }\n    while (a\
    \ < 0) {\n      f.min_f -= f.que_r.pop_min();\n      f.que_l.push(f.que_r.pop_min());\n\
    \      if (f.que_r.empty()) f.que_r.push(x0);\n      ++a;\n    }\n    return f;\n\
    \  }\n\n  // (a-x)+\n  FUNC add_a_minus_x(FUNC &f, ll a) {\n    auto [x0, x1]\
    \ = domain(f);\n    assert(x0 <= x1);\n    if (a <= x0) return f;\n    if (x1\
    \ <= a) return add_linear(f, -1, a);\n    ll x = f.que_r.min();\n    f.min_f +=\
    \ max<ll>(a - x, 0);\n    if (a <= x) {\n      f.que_l.push(a);\n    } else {\n\
    \      f.que_l.push(f.que_r.pop_min());\n      f.que_r.push(a);\n    }\n    return\
    \ f;\n  }\n\n  // (x-a)+\n  FUNC add_x_minus_a(FUNC &f, ll a) {\n    auto [x0,\
    \ x1] = domain(f);\n    assert(x0 <= x1);\n    if (a <= x0) return add_linear(f,\
    \ 1, -a);\n    if (x1 <= a) return f;\n    ll x = f.que_l.max();\n    f.min_f\
    \ += max<ll>(x - a, 0);\n    if (a >= x) {\n      f.que_r.push(a);\n    } else\
    \ {\n      f.que_r.push(f.que_l.pop_max());\n      f.que_l.push(a);\n    }\n \
    \   return f;\n  }\n\n  // (x-a)+\n  FUNC add_abs(FUNC &f, ll a) {\n    f = add_a_minus_x(f,\
    \ a);\n    f = add_x_minus_a(f, a);\n    return f;\n  }\n\n  FUNC clear_inc(FUNC\
    \ &f) {\n    auto [x0, x1] = domain(f);\n    f.que_r.clear();\n    f.que_r.push(x1);\n\
    \    return f;\n  }\n\n  FUNC add(FUNC &f, FUNC &g) {\n    auto [a0, a1] = domain(f);\n\
    \    auto [b0, b1] = domain(g);\n    ll x0 = max(a0, b0);\n    ll x1 = min(a1,\
    \ b1);\n    assert(x0 <= x1);\n    restrict_domain(f, x0, x1), restrict_domain(g,\
    \ x0, x1);\n    if (len(f) < len(g)) swap(f, g);\n    f.min_f += g.min_f;\n  \
    \  for (auto l: g.que_l.dat) {\n      l += g.que_l.add;\n      // (l-x)+\n   \
    \   if (l <= f.que_r.min()) {\n        f.que_l.push(l);\n      } else {\n    \
    \    f.que_l.push(f.que_r.pop_min());\n        f.que_r.push(l);\n      }\n   \
    \   ll x = f.que_r.min();\n      f.min_f += max<ll>(0, l - x);\n    }\n    return\
    \ f;\n  }\n\n  // FUNC sum_all(vc<FUNC> &funcs) {}\n\n  // FUNC shift(FUNC &f,\
    \ T add_x, T add_y) {\n  //   ST.apply(f.root, add_x);\n  //   f.x0 += add_x,\
    \ f.x1 += add_x, f.y0 += add_y;\n  //   return f;\n  // }\n\n  // h[z]=min(x+y==z)f(x)+g(y)\n\
    \  // FUNC convolve(FUNC &f, FUNC &g) {\n  //   if (f.x0 > f.x1 || g.x0 > g.x1)\
    \ { return {nullptr, infty<T>, -infty<T>, 0, 0}; }\n  //   if (len(f) < len(g))\
    \ swap(f, g);\n  //   shift(f, g.x0, g.y0), shift(g, -g.x0, -g.y0);\n  //   if\
    \ (len(g) == 0) { return convolve_segment(f, 0, g.x1, g.a0, 0); }\n  //   auto\
    \ tmp = ST.get_all(g.root);\n  //   ST.free_subtree(g.root);\n  //   f = convolve_segment(f,\
    \ 0, tmp[0].fi, g.a0, 0);\n  //   T a = g.a0;\n  //   FOR(i, len(tmp)) {\n  //\
    \     T nx = (i + 1 < len(tmp) ? tmp[i + 1].fi : g.x1);\n  //     a += tmp[i].se;\n\
    \  //     f = convolve_segment(f, 0, nx - tmp[i].fi, a, 0);\n  //     for (auto\
    \ &[x, a]: ST.get_all(f.root)) {\n  //       assert(f.x0 <= x && x <= f.x1);\n\
    \  //       if (f.root) assert(!f.root->p);\n  //     }\n  //   }\n  //   return\
    \ f;\n  // }\n\n  // [x0,x1], y=ax+b\n  // FUNC convolve_segment(FUNC &f, T x0,\
    \ T x1, T a, T b) {\n  //   assert(x0 <= x1);\n  //   if (f.x0 > f.x1) { return\
    \ {nullptr, infty<T>, -infty<T>, 0, 0}; }\n  //   f = shift(f, x0, a * x0 + b);\n\
    \  //   T d = x1 - x0;\n  //   if (d == 0) return f;\n  //   // (0,0) \u304B\u3089\
    \ (x1,ax1) \u3078\u306E\u7DDA\u5206\u3092\u3069\u3053\u304B\u306B\u633F\u5165\u3059\
    \u308B\n  //   // \u7279\u306B x0, y0 \u306F\u3053\u306E\u307E\u307E\u3067\u3088\
    \u3044\n  //   if (f.x0 == f.x1) { return {nullptr, f.x0, f.x0 + d, a, f.y0};\
    \ }\n  //   // \u5148\u982D\u306B\u633F\u5165\u3067\u304D\u308B\u5834\u5408\n\
    \  //   if (a <= f.a0) {\n  //     ST.apply(f.root, d);\n  //     f.root = ST.merge(ST.new_node({f.x0\
    \ + d, f.a0 - a}), f.root);\n  //     f.x1 += d, f.a0 = a;\n  //     return f;\n\
    \  //   }\n  //   // \u672B\u5C3E\u306B\u633F\u5165\u3067\u304D\u308B\u5834\u5408\
    \n  //   T a_last = f.a0 + ST.prod(f.root).fi;\n  //   if (a_last <= a) {\n  //\
    \     f.root = ST.merge(f.root, ST.new_node({f.x1, a - a_last}));\n  //     f.x1\
    \ += d;\n  //     return f;\n  //   }\n  //   // \u9593\u306E\u3069\u3053\u304B\
    \u306B\u633F\u5165\n  //   auto [l, r] = ST.split_max_right_prod(f.root, [&](auto\
    \ prod) -> bool { return f.a0 + prod.fi < a; });\n  //   T asum = ST.prod(l).fi;\n\
    \  //   T a1 = a - (asum + f.a0);\n  //   auto [xx, aa] = ST.get(r, 0);\n  //\
    \   ST.apply(r, d);\n  //   ST.set(r, 0, {xx + d, aa - a1});\n  //   f.root =\
    \ ST.merge3(l, ST.new_node({xx, a1}), r);\n  //   f.x1 += d;\n  //   return f;\n\
    \  // }\n\n  // fx,x\n  tuple<i128, ll, ll> get_min(FUNC &f) { return {f.min_f,\
    \ f.que_l.max(), f.que_r.min()}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/slope_trick/slope_trick_1.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convex/slope_trick/slope_trick_1.hpp
layout: document
redirect_from:
- /library/convex/slope_trick/slope_trick_1.hpp
- /library/convex/slope_trick/slope_trick_1.hpp.html
title: convex/slope_trick/slope_trick_1.hpp
---
