---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_add.hpp
    title: alg/acted_monoid/min_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
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
  bundledCode: "#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n\
    \  using MA = typename AM::Monoid_A;\n  static_assert(MX::commute);\n  using X\
    \ = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n, log,\
    \ size;\n  vc<X> dat;\n  vc<A> laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int n, F f) {\n  \
    \  build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n \
    \   FOR(k, 1, size) { push(k); }\n    return {dat.begin() + size, dat.begin()\
    \ + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    if (l == r) return MX::unit();\n    l += size, r += size;\n  \
    \  for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >>\
    \ i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X x = MX::unit();\n\
    \    while (l < r) {\n      if (l & 1) x = MX::op(x, dat[l++]);\n      if (r &\
    \ 1) x = MX::op(x, dat[--r]);\n      l >>= 1, r >>= 1;\n    }\n    return x;\n\
    \  }\n\n  X prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n\
    \    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size,\
    \ r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i)\
    \ != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n \
    \   }\n    int l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++,\
    \ a);\n      if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n  \
    \  l = l2, r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i)\
    \ << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1)\
    \ >> i);\n    }\n  }\n\n  template <typename F>\n  int max_right(const F check,\
    \ int l) {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n  \
    \  if (l == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l\
    \ >> i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l >>= 1;\n\
    \      if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n       \
    \   push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
    \ { sm = MX::op(sm, dat[l++]); }\n        }\n        return l - size;\n      }\n\
    \      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n\
    \  }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>=\
    \ 1;\n      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n  \
    \        push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r],\
    \ sm))) { sm = MX::op(dat[r--], sm); }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r) != r);\n    return\
    \ 0;\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n    ll sz = 1 << (log -\
    \ topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k < size) laz[k]\
    \ = MA::op(laz[k], a);\n  }\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"alg/acted_monoid/min_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Min_Add {\r\n  using Monoid_X\
    \ = Monoid_Min<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    if (x == numeric_limits<E>::max())\
    \ return x;\r\n    return x + a;\r\n  }\r\n};\r\n#line 3 \"seq/common_interval_decomposition.hpp\"\
    \n\ntemplate <int NODES>\nstruct Common_Inverval_Decomposition {\n  struct Node\
    \ {\n    vc<Node*> ch;\n    bool inc, dec;\n    int l, r, lo, hi;\n  };\n\n  Node*\
    \ pool;\n  Node* root;\n  int pid;\n\n  Common_Inverval_Decomposition(vc<int>&\
    \ P) : pid(0) {\n    pool = new Node[NODES];\n    build(P);\n  }\n\n  Node* new_node(bool\
    \ inc, bool dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n \
    \   pool[pid].dec = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo\
    \ = lo;\n    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    Lazy_SegTree<ActedMonoid_Min_Add<int>> seg(vc<int>(N,\
    \ 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n    FOR(i, N)\
    \ {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n        int j = pick(mi);\n\
    \        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n      }\n      while (ma.back()\
    \ != -1 && P[i] > P[ma.back()]) {\n        int j = pick(ma);\n        seg.apply(ma.back()\
    \ + 1, j + 1, P[i] - P[j]);\n      }\n      mi.eb(i), ma.eb(i);\n\n      Node*\
    \ now = new_node(0, 0, i, i + 1, P[i], P[i] + 1);\n      while (len(st)) {\n \
    \       Node* n = st.back();\n        if (n->hi == now->lo) {\n          if (n->inc)\
    \ {\n            n->ch.eb(now);\n            n->r = now->r;\n            n->hi\
    \ = now->hi;\n            now = n;\n            st.pop_back();\n          } else\
    \ {\n            Node* p = new_node(1, 0, n->l, now->r, n->lo, now->hi);\n   \
    \         p->ch.eb(n);\n            p->ch.eb(now);\n            now = p;\n   \
    \         st.pop_back();\n          }\n          continue;\n        }\n      \
    \  if (n->lo == now->hi) {\n          if (n->dec) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->lo = now->lo;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(0,\
    \ 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        // prime supernode creation\n        if (seg.prod(0, now->l)\
    \ != 0) break;\n        Node* p = new_node(0, 0, now->l, now->r, now->lo, now->hi);\n\
    \        p->ch.eb(now);\n        now = p;\n        while (1) {\n          auto\
    \ c = pick(st);\n          now->l = c->l;\n          chmin(now->lo, c->lo);\n\
    \          chmax(now->hi, c->hi);\n          now->ch.eb(c);\n          if (now->r\
    \ - now->l == now->hi - now->lo) break;\n        }\n        reverse(all(now->ch));\n\
    \      }\n      st.eb(now);\n      seg.apply(0, i + 1, -1);\n    }\n    assert(len(st)\
    \ == 1);\n    root = pick(st);\n    return;\n  }\n\n  void debug() {\n    auto\
    \ dfs = [&](auto& dfs, Node* n) -> void {\n      print(\"l, r, lo, hi\", n->l,\
    \ n->r, n->lo, n->hi);\n      for (auto&& c: n->ch) dfs(dfs, c);\n    };\n   \
    \ dfs(dfs, root);\n  };\n};\n"
  code: "#include \"ds/segtree/lazy_segtree.hpp\"\n#include \"alg/acted_monoid/min_add.hpp\"\
    \n\ntemplate <int NODES>\nstruct Common_Inverval_Decomposition {\n  struct Node\
    \ {\n    vc<Node*> ch;\n    bool inc, dec;\n    int l, r, lo, hi;\n  };\n\n  Node*\
    \ pool;\n  Node* root;\n  int pid;\n\n  Common_Inverval_Decomposition(vc<int>&\
    \ P) : pid(0) {\n    pool = new Node[NODES];\n    build(P);\n  }\n\n  Node* new_node(bool\
    \ inc, bool dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n \
    \   pool[pid].dec = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo\
    \ = lo;\n    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    Lazy_SegTree<ActedMonoid_Min_Add<int>> seg(vc<int>(N,\
    \ 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n    FOR(i, N)\
    \ {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n        int j = pick(mi);\n\
    \        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n      }\n      while (ma.back()\
    \ != -1 && P[i] > P[ma.back()]) {\n        int j = pick(ma);\n        seg.apply(ma.back()\
    \ + 1, j + 1, P[i] - P[j]);\n      }\n      mi.eb(i), ma.eb(i);\n\n      Node*\
    \ now = new_node(0, 0, i, i + 1, P[i], P[i] + 1);\n      while (len(st)) {\n \
    \       Node* n = st.back();\n        if (n->hi == now->lo) {\n          if (n->inc)\
    \ {\n            n->ch.eb(now);\n            n->r = now->r;\n            n->hi\
    \ = now->hi;\n            now = n;\n            st.pop_back();\n          } else\
    \ {\n            Node* p = new_node(1, 0, n->l, now->r, n->lo, now->hi);\n   \
    \         p->ch.eb(n);\n            p->ch.eb(now);\n            now = p;\n   \
    \         st.pop_back();\n          }\n          continue;\n        }\n      \
    \  if (n->lo == now->hi) {\n          if (n->dec) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->lo = now->lo;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(0,\
    \ 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        // prime supernode creation\n        if (seg.prod(0, now->l)\
    \ != 0) break;\n        Node* p = new_node(0, 0, now->l, now->r, now->lo, now->hi);\n\
    \        p->ch.eb(now);\n        now = p;\n        while (1) {\n          auto\
    \ c = pick(st);\n          now->l = c->l;\n          chmin(now->lo, c->lo);\n\
    \          chmax(now->hi, c->hi);\n          now->ch.eb(c);\n          if (now->r\
    \ - now->l == now->hi - now->lo) break;\n        }\n        reverse(all(now->ch));\n\
    \      }\n      st.eb(now);\n      seg.apply(0, i + 1, -1);\n    }\n    assert(len(st)\
    \ == 1);\n    root = pick(st);\n    return;\n  }\n\n  void debug() {\n    auto\
    \ dfs = [&](auto& dfs, Node* n) -> void {\n      print(\"l, r, lo, hi\", n->l,\
    \ n->r, n->lo, n->hi);\n      for (auto&& c: n->ch) dfs(dfs, c);\n    };\n   \
    \ dfs(dfs, root);\n  };\n};\n"
  dependsOn:
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/min_add.hpp
  - alg/monoid/add.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: seq/common_interval_decomposition.hpp
  requiredBy: []
  timestamp: '2022-12-04 21:11:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1720.test.cpp
  - test/library_checker/graph/common_interval_decomposition.test.cpp
documentation_of: seq/common_interval_decomposition.hpp
layout: document
redirect_from:
- /library/seq/common_interval_decomposition.hpp
- /library/seq/common_interval_decomposition.hpp.html
title: seq/common_interval_decomposition.hpp
---
