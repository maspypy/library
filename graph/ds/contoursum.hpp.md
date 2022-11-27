---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/verted_add_contour_sum.test.cpp
    title: test/library_checker/graph/verted_add_contour_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\
    \n\ntemplate <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename\
    \ AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree(int\
    \ n = 0) : n(n) {\n    assert(AbelGroup::commute);\n    reset(n);\n  }\n  FenwickTree(const\
    \ vector<E>& v) {\n    assert(AbelGroup::commute);\n    build(v);\n  }\n\n  void\
    \ build(const vc<E>& v) {\n    n = len(v);\n    total = AbelGroup::unit();\n \
    \   for (int i = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);\n    dat =\
    \ v;\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i & -i);\n      if\
    \ (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n\
    \  void reset(int sz = 0) {\n    if (sz) n = sz;\n    total = AbelGroup::unit();\n\
    \    dat.assign(n, AbelGroup::unit());\n  }\n\n  E prod(int k) {\n    E ret =\
    \ AbelGroup::unit();\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E prod(int L, int R) {\n    E pos =\
    \ AbelGroup::unit();\n    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R\
    \ - 1]);\n      R -= R & -R;\n    }\n    E neg = AbelGroup::unit();\n    while\
    \ (R < L) {\n      neg = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n\
    \    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n  }\n\n  E prod_all()\
    \ { return total; }\n\n  E sum(int k) { return prod(k); }\n\n  E sum(int L, int\
    \ R) { return prod(L, R); }\n\n  E sum_all() { return total; }\n\n  void multiply(int\
    \ k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <= n; k +=\
    \ k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  void add(int k,\
    \ E x) { multiply(k, x); }\n\n  template <class F>\n  int max_right(F& check)\
    \ {\n    assert(check(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit();\n \
    \   int k = 1;\n    int N = dat.size() + 1;\n    while (2 * k < N) k *= 2;\n \
    \   while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth(E k) {\n    auto check\
    \ = [&](E x) -> bool { return x <= k; };\n    return max_right(check);\n  }\n\n\
    \  void debug() { print(\"fenwick\", dat); }\n};\n#line 2 \"graph/ds/contoursum.hpp\"\
    \n\n// \u70B9\u52A0\u7B97\u3001\u8DDD\u96E2\u533A\u9593\u3067\u306E\u548C\ntemplate\
    \ <typename GT, typename AbelGroup>\nstruct ContourSum {\n  int N;\n  GT& G;\n\
    \  using X = typename AbelGroup::value_type;\n  FenwickTree<AbelGroup> bit;\n\
    \  // centroid \u3054\u3068\u3001\u65B9\u5411\u3054\u3068\n  vvc<int> bit_range;\n\
    \  // \u65B9\u5411\u30E9\u30D9\u30EB\u3001\u91CD\u5FC3\u304B\u3089\u306E\u8DDD\
    \u96E2\u3001bit \u3067\u306Eindex\n  vvc<tuple<int, int, int>> dat;\n\n  ContourSum(GT&\
    \ G) : N(G.N), G(G) {\n    assert(!G.is_directed());\n    vc<X> v_vals(N, AbelGroup::unit());\n\
    \    build(v_vals);\n  }\n  ContourSum(GT& G, const vc<X>& v_vals) : N(G.N), G(G)\
    \ {\n    assert(!G.is_directed());\n    build(v_vals);\n  }\n\n  void add(int\
    \ v, X val) {\n    for (auto&& [k, x, i]: dat[v]) bit.add(i, val);\n  }\n\n  //\
    \ v \u3092\u4E2D\u5FC3\u3068\u3057\u3066\u3001\u8DDD\u96E2 [l, r) \u306E\u7BC4\
    \u56F2\u306E\u548C\n  X sum(int v, int l, int r) {\n    X sm = AbelGroup::unit();\n\
    \    for (auto [k, x, i]: dat[v]) {\n      int lo = l - x, hi = r - x;\n     \
    \ int K = k;\n      if (k < 0) { lo -= 2, hi -= 2, K = ~k; }\n      int n = len(bit_range[K])\
    \ - 2;\n      chmax(lo, 0);\n      chmin(hi, n + 1);\n      if (lo >= hi) continue;\n\
    \      int a = bit_range[K][lo], b = bit_range[K][hi];\n      X val = bit.prod(a,\
    \ b);\n      if (k < 0) { val = AbelGroup::inverse(val); }\n      sm = AbelGroup::op(sm,\
    \ val);\n    }\n    return sm;\n  }\n\n  void build(const vc<X>& v_vals) {\n \
    \   int nxt_bit_idx = 0;\n    vc<int> done(N, 0);\n    vc<int> sz(N, 0);\n   \
    \ vc<int> par(N, -1);\n    vc<int> dist(N, -1);\n    vc<pair<int, int>> st;\n\
    \    bit_range.resize(N);\n    dat.resize(N);\n    st.eb(0, N);\n\n    while (len(st))\
    \ {\n      int v0 = st.back().fi;\n      int n = st.back().se;\n      st.pop_back();\n\
    \      int c = -1;\n      {\n        auto dfs = [&](auto& dfs, int v) -> int {\n\
    \          sz[v] = 1;\n          for (auto&& e: G[v])\n            if (e.to !=\
    \ par[v] && !done[e.to]) {\n              par[e.to] = v;\n              sz[v]\
    \ += dfs(dfs, e.to);\n            }\n          if (c == -1 && n - sz[v] <= n /\
    \ 2) { c = v; }\n          return sz[v];\n        };\n        dfs(dfs, v0);\n\
    \      }\n      // center \u304B\u3089\u306E bfs\u3002\u90E8\u5206\u6728\u30B5\
    \u30A4\u30BA\u3082\u3068\u3063\u3066\u304A\u304F\u3002\n      done[c] = 1;\n \
    \     {\n        int off = nxt_bit_idx;\n        vc<int> que;\n        auto add\
    \ = [&](int v, int d, int p) -> void {\n          if (dist[v] != -1) return;\n\
    \          sz[v] = 1;\n          dist[v] = d;\n          par[v] = p;\n       \
    \   que.eb(v);\n        };\n        int p = 0;\n        add(c, 0, -1);\n     \
    \   while (p < len(que)) {\n          auto v = que[p++];\n          for (auto&&\
    \ e: G[v]) {\n            if (done[e.to]) continue;\n            add(e.to, dist[v]\
    \ + 1, v);\n          }\n        }\n        FOR_R(i, 1, len(que)) {\n        \
    \  int v = que[i];\n          sz[par[v]] += sz[v];\n        }\n        // \u8DDD\
    \u96E2\u3054\u3068\u306E\u30AB\u30A6\u30F3\u30C8\n        int max_d = dist[que.back()];\n\
    \        vc<int> count(max_d + 1);\n        // \u91CD\u5FC3\u3001\u65B9\u5411\u30E9\
    \u30D9\u30EB\u3001\u91CD\u5FC3\u304B\u3089\u306E\u8DDD\u96E2\u3001bit \u3067\u306E\
    index\n        for (auto&& v: que) {\n          dat[v].eb(c, dist[v], nxt_bit_idx++);\n\
    \          count[dist[v]]++;\n          par[v] = -1;\n          dist[v] = -1;\n\
    \        }\n        bit_range[c] = cumsum<int, int>(count);\n        for (auto&&\
    \ x: bit_range[c]) x += off;\n      }\n      // \u65B9\u5411\u3054\u3068\u306E\
    \ bfs\n      for (auto&& e: G[c]) {\n        int off = nxt_bit_idx;\n        int\
    \ nbd = e.to;\n        if (done[nbd]) continue;\n        int K = len(bit_range);\n\
    \        vc<int> que;\n        auto add = [&](int v, int d) -> void {\n      \
    \    if (dist[v] != -1 || v == c) return;\n          dist[v] = d;\n          que.eb(v);\n\
    \        };\n        int p = 0;\n        add(nbd, 0);\n        while (p < len(que))\
    \ {\n          auto v = que[p++];\n          for (auto&& e: G[v]) {\n        \
    \    if (done[e.to]) continue;\n            add(e.to, dist[v] + 1);\n        \
    \  }\n        }\n        // \u8DDD\u96E2\u3054\u3068\u306E\u30AB\u30A6\u30F3\u30C8\
    \n        int max_d = dist[que.back()];\n        vc<int> count(max_d + 1);\n \
    \       // \u91CD\u5FC3\u3001\u65B9\u5411\u30E9\u30D9\u30EB\u3001\u91CD\u5FC3\u304B\
    \u3089\u306E\u8DDD\u96E2\u3001bit \u3067\u306Eindex\n        for (auto&& v: que)\
    \ {\n          dat[v].eb(~K, dist[v], nxt_bit_idx++);\n          count[dist[v]]++;\n\
    \          par[v] = -1;\n          dist[v] = -1;\n        }\n        bit_range.eb(cumsum<int>(count));\n\
    \        for (auto&& x: bit_range[K]) x += off;\n        st.eb(nbd, sz[nbd]);\n\
    \      }\n    }\n    // FenwickTree\n    vc<X> bit_raw(nxt_bit_idx);\n    FOR(v,\
    \ N) {\n      for (auto&& [k, x, i]: dat[v]) { bit_raw[i] = v_vals[v]; }\n   \
    \ }\n    bit.build(bit_raw);\n  }\n};\n"
  code: "#include \"ds/fenwick.hpp\"\n\n// \u70B9\u52A0\u7B97\u3001\u8DDD\u96E2\u533A\
    \u9593\u3067\u306E\u548C\ntemplate <typename GT, typename AbelGroup>\nstruct ContourSum\
    \ {\n  int N;\n  GT& G;\n  using X = typename AbelGroup::value_type;\n  FenwickTree<AbelGroup>\
    \ bit;\n  // centroid \u3054\u3068\u3001\u65B9\u5411\u3054\u3068\n  vvc<int> bit_range;\n\
    \  // \u65B9\u5411\u30E9\u30D9\u30EB\u3001\u91CD\u5FC3\u304B\u3089\u306E\u8DDD\
    \u96E2\u3001bit \u3067\u306Eindex\n  vvc<tuple<int, int, int>> dat;\n\n  ContourSum(GT&\
    \ G) : N(G.N), G(G) {\n    assert(!G.is_directed());\n    vc<X> v_vals(N, AbelGroup::unit());\n\
    \    build(v_vals);\n  }\n  ContourSum(GT& G, const vc<X>& v_vals) : N(G.N), G(G)\
    \ {\n    assert(!G.is_directed());\n    build(v_vals);\n  }\n\n  void add(int\
    \ v, X val) {\n    for (auto&& [k, x, i]: dat[v]) bit.add(i, val);\n  }\n\n  //\
    \ v \u3092\u4E2D\u5FC3\u3068\u3057\u3066\u3001\u8DDD\u96E2 [l, r) \u306E\u7BC4\
    \u56F2\u306E\u548C\n  X sum(int v, int l, int r) {\n    X sm = AbelGroup::unit();\n\
    \    for (auto [k, x, i]: dat[v]) {\n      int lo = l - x, hi = r - x;\n     \
    \ int K = k;\n      if (k < 0) { lo -= 2, hi -= 2, K = ~k; }\n      int n = len(bit_range[K])\
    \ - 2;\n      chmax(lo, 0);\n      chmin(hi, n + 1);\n      if (lo >= hi) continue;\n\
    \      int a = bit_range[K][lo], b = bit_range[K][hi];\n      X val = bit.prod(a,\
    \ b);\n      if (k < 0) { val = AbelGroup::inverse(val); }\n      sm = AbelGroup::op(sm,\
    \ val);\n    }\n    return sm;\n  }\n\n  void build(const vc<X>& v_vals) {\n \
    \   int nxt_bit_idx = 0;\n    vc<int> done(N, 0);\n    vc<int> sz(N, 0);\n   \
    \ vc<int> par(N, -1);\n    vc<int> dist(N, -1);\n    vc<pair<int, int>> st;\n\
    \    bit_range.resize(N);\n    dat.resize(N);\n    st.eb(0, N);\n\n    while (len(st))\
    \ {\n      int v0 = st.back().fi;\n      int n = st.back().se;\n      st.pop_back();\n\
    \      int c = -1;\n      {\n        auto dfs = [&](auto& dfs, int v) -> int {\n\
    \          sz[v] = 1;\n          for (auto&& e: G[v])\n            if (e.to !=\
    \ par[v] && !done[e.to]) {\n              par[e.to] = v;\n              sz[v]\
    \ += dfs(dfs, e.to);\n            }\n          if (c == -1 && n - sz[v] <= n /\
    \ 2) { c = v; }\n          return sz[v];\n        };\n        dfs(dfs, v0);\n\
    \      }\n      // center \u304B\u3089\u306E bfs\u3002\u90E8\u5206\u6728\u30B5\
    \u30A4\u30BA\u3082\u3068\u3063\u3066\u304A\u304F\u3002\n      done[c] = 1;\n \
    \     {\n        int off = nxt_bit_idx;\n        vc<int> que;\n        auto add\
    \ = [&](int v, int d, int p) -> void {\n          if (dist[v] != -1) return;\n\
    \          sz[v] = 1;\n          dist[v] = d;\n          par[v] = p;\n       \
    \   que.eb(v);\n        };\n        int p = 0;\n        add(c, 0, -1);\n     \
    \   while (p < len(que)) {\n          auto v = que[p++];\n          for (auto&&\
    \ e: G[v]) {\n            if (done[e.to]) continue;\n            add(e.to, dist[v]\
    \ + 1, v);\n          }\n        }\n        FOR_R(i, 1, len(que)) {\n        \
    \  int v = que[i];\n          sz[par[v]] += sz[v];\n        }\n        // \u8DDD\
    \u96E2\u3054\u3068\u306E\u30AB\u30A6\u30F3\u30C8\n        int max_d = dist[que.back()];\n\
    \        vc<int> count(max_d + 1);\n        // \u91CD\u5FC3\u3001\u65B9\u5411\u30E9\
    \u30D9\u30EB\u3001\u91CD\u5FC3\u304B\u3089\u306E\u8DDD\u96E2\u3001bit \u3067\u306E\
    index\n        for (auto&& v: que) {\n          dat[v].eb(c, dist[v], nxt_bit_idx++);\n\
    \          count[dist[v]]++;\n          par[v] = -1;\n          dist[v] = -1;\n\
    \        }\n        bit_range[c] = cumsum<int, int>(count);\n        for (auto&&\
    \ x: bit_range[c]) x += off;\n      }\n      // \u65B9\u5411\u3054\u3068\u306E\
    \ bfs\n      for (auto&& e: G[c]) {\n        int off = nxt_bit_idx;\n        int\
    \ nbd = e.to;\n        if (done[nbd]) continue;\n        int K = len(bit_range);\n\
    \        vc<int> que;\n        auto add = [&](int v, int d) -> void {\n      \
    \    if (dist[v] != -1 || v == c) return;\n          dist[v] = d;\n          que.eb(v);\n\
    \        };\n        int p = 0;\n        add(nbd, 0);\n        while (p < len(que))\
    \ {\n          auto v = que[p++];\n          for (auto&& e: G[v]) {\n        \
    \    if (done[e.to]) continue;\n            add(e.to, dist[v] + 1);\n        \
    \  }\n        }\n        // \u8DDD\u96E2\u3054\u3068\u306E\u30AB\u30A6\u30F3\u30C8\
    \n        int max_d = dist[que.back()];\n        vc<int> count(max_d + 1);\n \
    \       // \u91CD\u5FC3\u3001\u65B9\u5411\u30E9\u30D9\u30EB\u3001\u91CD\u5FC3\u304B\
    \u3089\u306E\u8DDD\u96E2\u3001bit \u3067\u306Eindex\n        for (auto&& v: que)\
    \ {\n          dat[v].eb(~K, dist[v], nxt_bit_idx++);\n          count[dist[v]]++;\n\
    \          par[v] = -1;\n          dist[v] = -1;\n        }\n        bit_range.eb(cumsum<int>(count));\n\
    \        for (auto&& x: bit_range[K]) x += off;\n        st.eb(nbd, sz[nbd]);\n\
    \      }\n    }\n    // FenwickTree\n    vc<X> bit_raw(nxt_bit_idx);\n    FOR(v,\
    \ N) {\n      for (auto&& [k, x, i]: dat[v]) { bit_raw[i] = v_vals[v]; }\n   \
    \ }\n    bit.build(bit_raw);\n  }\n};\n"
  dependsOn:
  - ds/fenwick.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: graph/ds/contoursum.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:09:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/verted_add_contour_sum.test.cpp
documentation_of: graph/ds/contoursum.hpp
layout: document
redirect_from:
- /library/graph/ds/contoursum.hpp
- /library/graph/ds/contoursum.hpp.html
title: graph/ds/contoursum.hpp
---
