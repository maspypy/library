---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/lazy/min_add.hpp
    title: alg/lazy/min_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/lazysegtree.hpp
    title: ds/lazysegtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/common_interval_decomposition.test.cpp
    title: test/library_checker/graph/common_interval_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1720.test.cpp
    title: test/yukicoder/1720.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/lazysegtree.hpp\"\n\ntemplate <typename Lazy>\nstruct\
    \ LazySegTree {\n  using Monoid_X = typename Lazy::X_structure;\n  using Monoid_A\
    \ = typename Lazy::A_structure;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  int n, log, size;\n  vc<X> dat;\n\
    \  vc<A> laz;\n\n  LazySegTree() : LazySegTree(0) {}\n  LazySegTree(int n) : LazySegTree(vc<X>(n,\
    \ Monoid_X::unit())) {}\n  LazySegTree(vc<X> v) : n(len(v)) {\n    log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, Monoid_X::unit());\n    laz.assign(size, Monoid_A::unit());\n    FOR(i,\
    \ n) dat[size + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  template\
    \ <typename F>\n  LazySegTree(int n, F f) : n(n) {\n    log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid_X::unit());\n\
    \    laz.assign(size, Monoid_A::unit());\n    FOR(i, n) dat[size + i] = f(i);\n\
    \    FOR3_R(i, 1, size) update(i);\n  }\n\n  void reset() {\n    fill(all(dat),\
    \ Monoid_X::unit());\n    fill(all(laz), Monoid_A::unit());\n  }\n\n  void reset(const\
    \ vc<X>& v) {\n    assert(len(v) == n);\n    reset();\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = Monoid_X::op(dat[2 * k], dat[2 * k + 1]); }\n\n  void all_apply(int\
    \ k, A a) {\n    dat[k] = Lazy::act(dat[k], a);\n    if (k < size) laz[k] = Monoid_A::op(laz[k],\
    \ a);\n  }\n\n  void push(int k) {\n    all_apply(2 * k, laz[k]);\n    all_apply(2\
    \ * k + 1, laz[k]);\n    laz[k] = Monoid_A::unit();\n  }\n\n  void set(int p,\
    \ X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n   \
    \ p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n\
    \  }\n\n  vc<X> get_all() {\n    FOR(i, size) push(i);\n    return {dat.begin()\
    \ + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return Monoid_X::unit();\n\n   \
    \ l += size;\n    r += size;\n\n    for (int i = log; i >= 1; i--) {\n      if\
    \ (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n    }\n\n    X xl = Monoid_X::unit(), xr = Monoid_X::unit();\n\
    \    while (l < r) {\n      if (l & 1) xl = Monoid_X::op(xl, dat[l++]);\n    \
    \  if (r & 1) xr = Monoid_X::op(dat[--r], xr);\n      l >>= 1;\n      r >>= 1;\n\
    \    }\n\n    return Monoid_X::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1];\
    \ }\n\n  void apply(int p, A a) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    dat[p] = Lazy::act(dat[p], a);\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <=\
    \ r && r <= n);\n    if (l == r) return;\n\n    l += size;\n    r += size;\n\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n\n    {\n\
    \      int l2 = l, r2 = r;\n      while (l < r) {\n        if (l & 1) all_apply(l++,\
    \ a);\n        if (r & 1) all_apply(--r, a);\n        l >>= 1;\n        r >>=\
    \ 1;\n      }\n      l = l2;\n      r = r2;\n    }\n\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ C>\n  int max_right(C& check, int l) {\n    assert(0 <= l && l <= n);\n    assert(check(Monoid_X::unit()));\n\
    \    if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--)\
    \ push(l >> i);\n    X sm = Monoid_X::unit();\n    do {\n      while (l % 2 ==\
    \ 0) l >>= 1;\n      if (!check(Monoid_X::op(sm, dat[l]))) {\n        while (l\
    \ < size) {\n          push(l);\n          l = (2 * l);\n          if (check(Monoid_X::op(sm,\
    \ dat[l]))) {\n            sm = Monoid_X::op(sm, dat[l]);\n            l++;\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = Monoid_X::op(sm,\
    \ dat[l]);\n      l++;\n    } while ((l & -l) != l);\n    return n;\n  }\n\n \
    \ template <typename C>\n  int min_left(C& check, int r) {\n    assert(0 <= r\
    \ && r <= n);\n    assert(check(Monoid_X::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = Monoid_X::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2))\
    \ r >>= 1;\n      if (!check(Monoid_X::op(dat[r], sm))) {\n        while (r <\
    \ size) {\n          push(r);\n          r = (2 * r + 1);\n          if (check(Monoid_X::op(dat[r],\
    \ sm))) {\n            sm = Monoid_X::op(dat[r], sm);\n            r--;\n    \
    \      }\n        }\n        return r + 1 - size;\n      }\n      sm = Monoid_X::op(dat[r],\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  void debug() { print(\"\
    lazysegtree getall:\", get_all()); }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\n\
    template <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\
    \n  static constexpr X unit() { return X(0); }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\ntemplate <class X>\r\nstruct\
    \ Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() {\
    \ return numeric_limits<X>::max(); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"alg/lazy/min_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Lazy_Min_Add {\r\n  using MX = Monoid_Min<E>;\r\n  using MA = Monoid_Add<E>;\r\
    \n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) {\r\n    if (x == numeric_limits<E>::max()) return\
    \ x;\r\n    return x + a;\r\n  }\r\n};\r\n#line 3 \"ds/common_interval_decomposition.hpp\"\
    \n\ntemplate <int NODES>\nstruct Common_Inverval_Decomposition {\n  struct Node\
    \ {\n    vc<Node*> ch;\n    bool inc, dec;\n    int l, r, lo, hi;\n  };\n\n  Node*\
    \ pool;\n  Node* root;\n  int pid;\n\n  Common_Inverval_Decomposition(vc<int>&\
    \ P) : pid(0) {\n    pool = new Node[NODES];\n    build(P);\n  }\n\n  Node* new_node(bool\
    \ inc, bool dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n \
    \   pool[pid].dec = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo\
    \ = lo;\n    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    using Lazy = Lazy_Min_Add<int>;\n    LazySegTree<Lazy>\
    \ seg(vc<int>(N, 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n\
    \    FOR(i, N) {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n   \
    \     int j = pick(mi);\n        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n\
    \      }\n      while (ma.back() != -1 && P[i] > P[ma.back()]) {\n        int\
    \ j = pick(ma);\n        seg.apply(ma.back() + 1, j + 1, P[i] - P[j]);\n     \
    \ }\n      mi.eb(i), ma.eb(i);\n\n      Node* now = new_node(0, 0, i, i + 1, P[i],\
    \ P[i] + 1);\n      while (len(st)) {\n        Node* n = st.back();\n        if\
    \ (n->hi == now->lo) {\n          if (n->inc) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->hi = now->hi;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(1,\
    \ 0, n->l, now->r, n->lo, now->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        if (n->lo == now->hi) {\n          if (n->dec) {\n       \
    \     n->ch.eb(now);\n            n->r = now->r;\n            n->lo = now->lo;\n\
    \            now = n;\n            st.pop_back();\n          } else {\n      \
    \      Node* p = new_node(0, 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n\
    \            p->ch.eb(now);\n            now = p;\n            st.pop_back();\n\
    \          }\n          continue;\n        }\n        // prime supernode creation\n\
    \        if (seg.prod(0, now->l) != 0) break;\n        Node* p = new_node(0, 0,\
    \ now->l, now->r, now->lo, now->hi);\n        p->ch.eb(now);\n        now = p;\n\
    \        while (1) {\n          auto c = pick(st);\n          now->l = c->l;\n\
    \          chmin(now->lo, c->lo);\n          chmax(now->hi, c->hi);\n        \
    \  now->ch.eb(c);\n          if (now->r - now->l == now->hi - now->lo) break;\n\
    \        }\n        reverse(all(now->ch));\n      }\n      st.eb(now);\n     \
    \ seg.apply(0, i + 1, -1);\n    }\n    assert(len(st) == 1);\n    root = pick(st);\n\
    \    return;\n  }\n\n  void debug() {\n    auto dfs = [&](auto& dfs, Node* n)\
    \ -> void {\n      print(\"l, r, lo, hi\", n->l, n->r, n->lo, n->hi);\n      for\
    \ (auto&& c: n->ch) dfs(dfs, c);\n    };\n    dfs(dfs, root);\n  };\n};\n"
  code: "#include \"ds/lazysegtree.hpp\"\n#include \"alg/lazy/min_add.hpp\"\n\ntemplate\
    \ <int NODES>\nstruct Common_Inverval_Decomposition {\n  struct Node {\n    vc<Node*>\
    \ ch;\n    bool inc, dec;\n    int l, r, lo, hi;\n  };\n\n  Node* pool;\n  Node*\
    \ root;\n  int pid;\n\n  Common_Inverval_Decomposition(vc<int>& P) : pid(0) {\n\
    \    pool = new Node[NODES];\n    build(P);\n  }\n\n  Node* new_node(bool inc,\
    \ bool dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n    pool[pid].dec\
    \ = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo = lo;\n\
    \    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    using Lazy = Lazy_Min_Add<int>;\n    LazySegTree<Lazy>\
    \ seg(vc<int>(N, 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n\
    \    FOR(i, N) {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n   \
    \     int j = pick(mi);\n        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n\
    \      }\n      while (ma.back() != -1 && P[i] > P[ma.back()]) {\n        int\
    \ j = pick(ma);\n        seg.apply(ma.back() + 1, j + 1, P[i] - P[j]);\n     \
    \ }\n      mi.eb(i), ma.eb(i);\n\n      Node* now = new_node(0, 0, i, i + 1, P[i],\
    \ P[i] + 1);\n      while (len(st)) {\n        Node* n = st.back();\n        if\
    \ (n->hi == now->lo) {\n          if (n->inc) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->hi = now->hi;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(1,\
    \ 0, n->l, now->r, n->lo, now->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        if (n->lo == now->hi) {\n          if (n->dec) {\n       \
    \     n->ch.eb(now);\n            n->r = now->r;\n            n->lo = now->lo;\n\
    \            now = n;\n            st.pop_back();\n          } else {\n      \
    \      Node* p = new_node(0, 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n\
    \            p->ch.eb(now);\n            now = p;\n            st.pop_back();\n\
    \          }\n          continue;\n        }\n        // prime supernode creation\n\
    \        if (seg.prod(0, now->l) != 0) break;\n        Node* p = new_node(0, 0,\
    \ now->l, now->r, now->lo, now->hi);\n        p->ch.eb(now);\n        now = p;\n\
    \        while (1) {\n          auto c = pick(st);\n          now->l = c->l;\n\
    \          chmin(now->lo, c->lo);\n          chmax(now->hi, c->hi);\n        \
    \  now->ch.eb(c);\n          if (now->r - now->l == now->hi - now->lo) break;\n\
    \        }\n        reverse(all(now->ch));\n      }\n      st.eb(now);\n     \
    \ seg.apply(0, i + 1, -1);\n    }\n    assert(len(st) == 1);\n    root = pick(st);\n\
    \    return;\n  }\n\n  void debug() {\n    auto dfs = [&](auto& dfs, Node* n)\
    \ -> void {\n      print(\"l, r, lo, hi\", n->l, n->r, n->lo, n->hi);\n      for\
    \ (auto&& c: n->ch) dfs(dfs, c);\n    };\n    dfs(dfs, root);\n  };\n};\n"
  dependsOn:
  - ds/lazysegtree.hpp
  - alg/lazy/min_add.hpp
  - alg/monoid/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: ds/common_interval_decomposition.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1720.test.cpp
  - test/library_checker/graph/common_interval_decomposition.test.cpp
documentation_of: ds/common_interval_decomposition.hpp
layout: document
redirect_from:
- /library/ds/common_interval_decomposition.hpp
- /library/ds/common_interval_decomposition.hpp.html
title: ds/common_interval_decomposition.hpp
---
