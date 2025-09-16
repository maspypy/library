---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/slope_super.test.cpp
    title: test/1_mytest/slope_super.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/splaytree/splaytree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"ds/splaytree/splaytree.hpp\"\n#include \"alg/monoid/add_pair.hpp\"\
    \n\nnamespace SLOPE_TRICK_SUPER {\n/*\n\u50BE\u304D\u3068\u5EA7\u6A19\u304C\u5168\
    \u90E8 T.\n(x0,y0,a0) / \u50BE\u304D\u5909\u5316\u3092 splay tree \u3067\u6301\
    \u3064.\n\u672B\u5C3E\u306B\u306F\u5FC5\u305A infty \u304C\u5165\u3063\u3066\u3044\
    \u308B\u3088\u3046\u306B\u3059\u308B.\n(0,10),(1,6),(3,4),(6,7)\n->\n(x0,y0,a0)=(0,10,-4)\n\
    dat = ([1,3],[3,2])\n\nf(x) \u306E\u8A08\u7B97, (min,argmin) \u306E\u8A08\u7B97\
    \n\u52A0\u6CD5, \u7573\u307F\u8FBC\u307F\n\n\u52A0\u6CD5: easy\nf(x) \u306E\u8A08\
    \u7B97: sum(a), sum(xa) \u304C\u8981\u308B\n\u7573\u307F\u8FBC\u307F: x->x+c \u304C\
    \u8981\u308B\n*/\n\ntemplate <typename T>\nstruct Node {\n  using value_type =\
    \ pair<T, T>;\n  using operator_type = T;\n  using np = Node *;\n  using Monoid_X\
    \ = Monoid_Add_Pair<T>;\n\n  np p, l, r;\n  bool rev;\n  u32 size;\n  pair<T,\
    \ T> x;    // (x,a)\n  pair<T, T> prod; // (a sum, xa sum)\n  T add_x;\n\n  static\
    \ void new_node(np n, const pair<T, T> &x) {\n    n->p = n->l = n->r = nullptr,\
    \ n->rev = 0, n->size = 1;\n    n->x = x, n->prod = {x.se, x.fi * x.se}, n->add_x\
    \ = 0;\n  }\n\n  void update() {\n    size = 1;\n    if (l) { size += l->size;\
    \ }\n    if (r) { size += r->size; }\n    prod = {x.se, x.fi * x.se};\n    if\
    \ (l) prod = Monoid_X::op(prod, l->prod);\n    if (r) prod = Monoid_X::op(prod,\
    \ r->prod);\n  }\n\n  void prop() {\n    assert(!rev);\n    if (add_x == 0) return;\n\
    \    if (l) l->x.fi += add_x, l->prod.se += l->prod.fi * add_x, l->add_x += add_x;\n\
    \    if (r) r->x.fi += add_x, r->prod.se += r->prod.fi * add_x, r->add_x += add_x;\n\
    \    add_x = 0;\n  }\n\n  void apply(T a) { x.fi += a, prod.se += a * prod.fi,\
    \ add_x += a; }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\
    \u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\
    \u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\
    \u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  pair<T, T> get() { return\
    \ x; }\n  void set(const pair<T, T> &xx) {\n    x = xx;\n    update();\n  }\n\
    };\n\n// \u95A2\u6570\u306F\u7834\u58CA\u7684\u306A\u5909\u66F4\u306B\u3055\u308C\
    \u308B\ntemplate <typename T>\nstruct Slope_Trick_Super {\n  SplayTree<Node<T>>\
    \ ST;\n  using np = Node<T> *;\n\n  struct FUNC {\n    np root; // \u5B9A\u7FA9\
    \u57DF\u304C\u3053\u308F\u308C\u3066\u3044\u305F\u3089 root == empty\n    T x0,\
    \ x1, a0, y0;\n    int size() { return (root ? root->size : 0); }\n  };\n\n  Slope_Trick_Super(int\
    \ NODES) : ST(NODES) {}\n\n  // (L,R,a,b) : [L,R] \u3067 y=ax+b\n  FUNC segment_func(T\
    \ L, T R, T a, T b) { return {nullptr, L, R, a, a * L + b}; }\n  FUNC from_points(vc<pair<T,\
    \ T>> &point) {\n    return from_points(len(point), [&](int i) -> pair<T, T> {\
    \ return point[i]; });\n  }\n  template <typename F>\n  FUNC from_points(int N,\
    \ F f) {\n    vc<T> X(N), Y(N);\n    FOR(i, N) tie(X[i], Y[i]) = f(i);\n    if\
    \ (N == 1) return segment_func(X[0], X[0], 0, Y[0]);\n    T a0 = (Y[1] - Y[0])\
    \ / (X[1] - X[0]);\n    T x0 = X[0], x1 = X.back();\n    vc<pair<T, T>> dat;\n\
    \    T a = a0;\n    FOR(i, 1, N - 1) {\n      T a1 = (Y[i + 1] - Y[i]) / (X[i\
    \ + 1] - X[i]);\n      dat.eb(X[i], a1 - a), a = a1;\n    }\n    return FUNC{ST.new_node(dat),\
    \ x0, x1, a0, Y[0]};\n  }\n\n  pair<T, T> domain(FUNC &f) { return {f.x0, f.x1};\
    \ }\n  T eval(FUNC &f, T x) {\n    auto [x0, x1] = domain(f);\n    if (!(x0 <=\
    \ x && x <= x1)) return infty<T>;\n    auto [l, r] = ST.split_max_right(f.root,\
    \ [&](auto dat) -> bool { return dat.fi <= x; });\n    auto [a_sum, xa_sum] =\
    \ ST.prod(l);\n    f.root = ST.merge(l, r);\n    return f.y0 + f.a0 * (x - x0)\
    \ + a_sum * x - xa_sum;\n  }\n  FUNC restrict_domain(FUNC &f, T L, T R) {\n  \
    \  auto [x0, x1] = domain(f);\n    chmax(L, x0), chmin(R, x1);\n    if (L > R)\
    \ {\n      ST.free_subtree(f.root), f.root = nullptr;\n      f.root = nullptr;\n\
    \      f.x0 = infty<T>, f.x1 = -infty<T>;\n      return f;\n    }\n    // \u307E\
    \u305A\u306F\u53F3\u5074\u3092\u3061\u3062\u3081\u308B. R \u4EE5\u4E0A\u306E\u50BE\
    \u304D\u5909\u5316\u3092\u6D88\u3057\u3066\u3057\u307E\u3048\u3070\u3088\u3044\
    \n    auto [l, r] = ST.split_max_right(f.root, [&](auto dat) -> bool { return\
    \ dat.fi < R; });\n    ST.free_subtree(r);\n    // \u5DE6\u5074\u3092\u3061\u3062\
    \u3081\u308B.\n    tie(l, r) = ST.split_max_right(l, [&](auto dat) -> bool { return\
    \ dat.fi <= L; });\n    auto [a_sum, xa_sum] = ST.prod(l);\n    T new_a0 = f.a0\
    \ + a_sum;\n    T new_y0 = f.y0 + f.a0 * (L - x0) + a_sum * L - xa_sum;\n    ST.free_subtree(l);\n\
    \    f.root = r, f.x0 = L, f.x1 = R, f.a0 = new_a0, f.y0 = new_y0;\n    return\
    \ f;\n  }\n  FUNC add(FUNC &f, FUNC &g) {\n    T x0 = max(f.x0, g.x0);\n    T\
    \ x1 = min(f.x1, g.x1);\n    restrict_domain(f, x0, x1), restrict_domain(g, x0,\
    \ x1);\n    if (x0 > x1) return f;\n    T y0 = f.y0 + g.y0, a0 = f.a0 + g.a0;\n\
    \n    if (len(f) < len(g)) swap(f, g);\n    auto tmp = ST.get_all(g.root);\n \
    \   ST.free_subtree(g.root);\n    f.x0 = x0, f.x1 = x1, f.a0 = a0, f.y0 = y0;\n\
    \    if (!f.root) {\n      f.root = ST.new_node(tmp);\n      return f;\n    }\n\
    \    // \u3042\u3068\u306F\u5358\u306B tmp \u3092\u633F\u5165\u3057\u3066\u3044\
    \u3051\u3070\u3044\u3044\n    auto dfs = [&](auto &dfs, np root, int l, int r)\
    \ -> void {\n      if (l == r) return;\n      root->prop();\n      T x = root->x.fi;\n\
    \      // [l,m),[m,r)\n      int m = binary_search([&](int i) -> bool { return\
    \ tmp[i].fi >= x; }, r, l - 1, 0);\n      if (l < m) {\n        if (!root->l)\
    \ {\n          root->l = ST.new_node({tmp.begin() + l, tmp.begin() + m});\n  \
    \      } else {\n          dfs(dfs, root->l, l, m);\n        }\n        root->l->p\
    \ = root;\n      }\n      if (m < r) {\n        if (!root->r) {\n          root->r\
    \ = ST.new_node({tmp.begin() + m, tmp.begin() + r});\n        } else {\n     \
    \     dfs(dfs, root->r, m, r);\n        }\n        root->r->p = root;\n      }\n\
    \      root->update();\n    };\n    dfs(dfs, f.root, 0, len(tmp));\n    return\
    \ f;\n  }\n  FUNC sum_all(vc<FUNC> &funcs) {\n    assert(len(funcs) >= 1);\n \
    \   T x0 = funcs[0].x0, x1 = funcs[0].x1;\n    for (auto &g: funcs) chmax(x0,\
    \ g.x0), chmin(x1, g.x1);\n    if (x0 > x1) {\n      for (auto &f: funcs) { ST.free_subtree(f.root);\
    \ }\n      return {nullptr, infty<T>, -infty<T>, 0, 0};\n    }\n    for (auto\
    \ &f: funcs) f = restrict_domain(f, x0, x1);\n    int idx = 0;\n    FOR(i, 1,\
    \ len(funcs)) if (len(funcs[idx]) < len(funcs[i])) idx = i;\n    swap(funcs[idx],\
    \ funcs.back());\n    FUNC f = POP(funcs);\n    vc<pair<T, T>> dat;\n    for (auto\
    \ &g: funcs) {\n      f.y0 += g.y0, f.a0 += g.a0;\n      auto tmp = ST.get_all(g.root);\n\
    \      concat(dat, tmp);\n      ST.free_subtree(g.root);\n    }\n    sort(all(dat));\n\
    \    // \u3042\u3068\u306F\u5358\u306B dat \u3092\u633F\u5165\u3057\u3066\u3044\
    \u3051\u3070\u3044\u3044\n    if (!f.root) {\n      f.root = ST.new_node(dat);\n\
    \      return f;\n    }\n    auto dfs = [&](auto &dfs, np root, int l, int r)\
    \ -> void {\n      if (l == r) return;\n      root->prop();\n      T x = root->x.fi;\n\
    \      // [l,m),[m,r)\n      int m = binary_search([&](int i) -> bool { return\
    \ dat[i].fi >= x; }, r, l - 1, 0);\n      if (l < m) {\n        if (!root->l)\
    \ {\n          root->l = ST.new_node({dat.begin() + l, dat.begin() + m});\n  \
    \      } else {\n          dfs(dfs, root->l, l, m);\n        }\n        root->l->p\
    \ = root;\n      }\n      if (m < r) {\n        if (!root->r) {\n          root->r\
    \ = ST.new_node({dat.begin() + m, dat.begin() + r});\n        } else {\n     \
    \     dfs(dfs, root->r, m, r);\n        }\n        root->r->p = root;\n      }\n\
    \      root->update();\n    };\n    dfs(dfs, f.root, 0, len(dat));\n    return\
    \ f;\n  }\n\n  FUNC shift(FUNC &f, T add_x, T add_y) {\n    ST.apply(f.root, add_x);\n\
    \    f.x0 += add_x, f.x1 += add_x, f.y0 += add_y;\n    return f;\n  }\n\n  //\
    \ h[z]=min(x+y==z)f(x)+g(y)\n  FUNC convolve(FUNC &f, FUNC &g) {\n    if (f.x0\
    \ > f.x1 || g.x0 > g.x1) { return {nullptr, infty<T>, -infty<T>, 0, 0}; }\n  \
    \  if (len(f) < len(g)) swap(f, g);\n    shift(f, g.x0, g.y0), shift(g, -g.x0,\
    \ -g.y0);\n    if (len(g) == 0) { return convolve_segment(f, 0, g.x1, g.a0, 0);\
    \ }\n    auto tmp = ST.get_all(g.root);\n    ST.free_subtree(g.root);\n    f =\
    \ convolve_segment(f, 0, tmp[0].fi, g.a0, 0);\n    T a = g.a0;\n    FOR(i, len(tmp))\
    \ {\n      T nx = (i + 1 < len(tmp) ? tmp[i + 1].fi : g.x1);\n      a += tmp[i].se;\n\
    \      f = convolve_segment(f, 0, nx - tmp[i].fi, a, 0);\n      for (auto &[x,\
    \ a]: ST.get_all(f.root)) {\n        assert(f.x0 <= x && x <= f.x1);\n       \
    \ if (f.root) assert(!f.root->p);\n      }\n    }\n    return f;\n  }\n\n  //\
    \ [x0,x1], y=ax+b\n  FUNC convolve_segment(FUNC &f, T x0, T x1, T a, T b) {\n\
    \    assert(x0 <= x1);\n    if (f.x0 > f.x1) { return {nullptr, infty<T>, -infty<T>,\
    \ 0, 0}; }\n    f = shift(f, x0, a * x0 + b);\n    T d = x1 - x0;\n    if (d ==\
    \ 0) return f;\n    // (0,0) \u304B\u3089 (x1,ax1) \u3078\u306E\u7DDA\u5206\u3092\
    \u3069\u3053\u304B\u306B\u633F\u5165\u3059\u308B\n    // \u7279\u306B x0, y0 \u306F\
    \u3053\u306E\u307E\u307E\u3067\u3088\u3044\n    if (f.x0 == f.x1) { return {nullptr,\
    \ f.x0, f.x0 + d, a, f.y0}; }\n    // \u5148\u982D\u306B\u633F\u5165\u3067\u304D\
    \u308B\u5834\u5408\n    if (a <= f.a0) {\n      ST.apply(f.root, d);\n      f.root\
    \ = ST.merge(ST.new_node({f.x0 + d, f.a0 - a}), f.root);\n      f.x1 += d, f.a0\
    \ = a;\n      return f;\n    }\n    // \u672B\u5C3E\u306B\u633F\u5165\u3067\u304D\
    \u308B\u5834\u5408\n    T a_last = f.a0 + ST.prod(f.root).fi;\n    if (a_last\
    \ <= a) {\n      f.root = ST.merge(f.root, ST.new_node({f.x1, a - a_last}));\n\
    \      f.x1 += d;\n      return f;\n    }\n    // \u9593\u306E\u3069\u3053\u304B\
    \u306B\u633F\u5165\n    auto [l, r] = ST.split_max_right_prod(f.root, [&](auto\
    \ prod) -> bool { return f.a0 + prod.fi < a; });\n    T asum = ST.prod(l).fi;\n\
    \    T a1 = a - (asum + f.a0);\n    auto [xx, aa] = ST.get(r, 0);\n    ST.apply(r,\
    \ d);\n    ST.set(r, 0, {xx + d, aa - a1});\n    f.root = ST.merge3(l, ST.new_node({xx,\
    \ a1}), r);\n    f.x1 += d;\n    return f;\n  }\n\n  FUNC add_const(FUNC &f, T\
    \ a) {\n    f.y0 += a;\n    return f;\n  }\n\n  FUNC add_linear(FUNC &f, T a,\
    \ T b) {\n    f.y0 += a * f.x0 + b;\n    f.a0 += a;\n    return f;\n  }\n\n  //\
    \ (a-x)+\n  FUNC add_a_minus_x(FUNC &f, T a) {\n    auto [x0, x1] = domain(f);\n\
    \    if (x0 > x1) return f;\n    if (a <= x0) return f;\n    if (x1 <= a) return\
    \ add_linear(f, -1, a);\n    vc<pair<T, T>> point;\n    point.eb(x0, a - x0),\
    \ point.eb(a, 0), point.eb(x1, 0);\n    FUNC g = from_points(point);\n    return\
    \ add(f, g);\n  }\n\n  // (x-a)+\n  FUNC add_x_minus_a(FUNC &f, T a) {\n    auto\
    \ [x0, x1] = domain(f);\n    if (x0 > x1) return f;\n    if (a <= x0) return add_linear(f,\
    \ 1, -a);\n    if (x1 <= a) return f;\n    vc<pair<T, T>> point;\n    point.eb(x0,\
    \ 0), point.eb(a, 0), point.eb(x1, x1 - a);\n    FUNC g = from_points(point);\n\
    \    return add(f, g);\n  }\n\n  // |x-a|\n  FUNC add_abs(FUNC &f, T a) {\n  \
    \  f = add_a_minus_x(f, a);\n    f = add_x_minus_a(f, a);\n    return f;\n  }\n\
    \n  // fx,x\n  pair<T, T> get_min(FUNC &f) {\n    if (f.x0 > f.x1) return {infty<T>,\
    \ 0};\n    if (f.a0 >= 0) { return {f.y0, f.x0}; }\n    auto [l, r] = ST.split_max_right_prod(f.root,\
    \ [&](auto prod) -> bool { return f.a0 + prod.fi < 0; });\n    auto [asum, xasum]\
    \ = ST.prod(l);\n    T x = (r ? ST.get(r, 0).fi : f.x1);\n    f.root = ST.merge(l,\
    \ r);\n    T y = f.y0 + f.a0 * (x - f.x0) + x * asum - xasum;\n    return {y,\
    \ x};\n  }\n\n  FUNC clear_right(FUNC &f) {\n    if (f.a0 >= 0) {\n      ST.free_subtree(f.root),\
    \ f.root = nullptr, f.a0 = 0;\n      return f;\n    }\n    auto [l, r] = ST.split_max_right_prod(f.root,\
    \ [&](auto prod) -> bool { return f.a0 + prod.fi < 0; });\n    f.root = l;\n \
    \   if (!r) { return f; }\n    T x = ST.get(r, 0).fi;\n    ST.free_subtree(r);\n\
    \    f.root = ST.merge(f.root, ST.new_node({x, -(f.a0 + ST.prod(l).fi)}));\n \
    \   return f;\n  }\n  FUNC clear_left(FUNC &f) {\n    if (f.a0 >= 0) { return\
    \ f; }\n    auto [l, r] = ST.split_max_right_prod(f.root, [&](auto prod) -> bool\
    \ { return f.a0 + prod.fi < 0; });\n    auto [asum, xasum] = ST.prod(l);\n   \
    \ if (!r) {\n      // \u5B9A\u6570\u306B\u3059\u308B\n      T x = f.x1;\n    \
    \  T y = f.y0 + f.a0 * (x - f.x0) + x * asum - xasum;\n      ST.free_subtree(l);\n\
    \      f.root = nullptr;\n      f.y0 = y, f.a0 = 0;\n      return f;\n    }\n\
    \    T x = ST.get(f.root, 0).fi;\n    T y = f.y0 + f.a0 * (x - f.x0) + x * asum\
    \ - xasum;\n    T a = f.a0 + asum + ST.get(r, 0).se;\n    ST.free_subtree(l);\n\
    \    f.root = r;\n    ST.set(r, 0, {x, a});\n    f.y0 = y;\n    f.a0 = 0;\n  \
    \  return f;\n  }\n#ifdef FASTIO\n  void debug(FUNC &f) {\n    auto dat = ST.get_all(f.root);\n\
    \    SHOW(f.x0, f.x1, f.a0, f.y0);\n    SHOW(dat);\n  }\n#endif\n};\n} // namespace\
    \ SLOPE_TRICK_SUPER\nusing SLOPE_TRICK_SUPER::Slope_Trick_Super;\n"
  dependsOn:
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  - alg/monoid/add_pair.hpp
  isVerificationFile: false
  path: convex/slope_trick/slope_super.hpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/slope_super.test.cpp
documentation_of: convex/slope_trick/slope_super.hpp
layout: document
redirect_from:
- /library/convex/slope_trick/slope_super.hpp
- /library/convex/slope_trick/slope_super.hpp.html
title: convex/slope_trick/slope_super.hpp
---
