---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/segtree/dynamic_segtree_sparse.hpp
    title: ds/segtree/dynamic_segtree_sparse.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/range_add_range_max.test.cpp
    title: test/1_mytest/range_add_range_max.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/542/problem/B
  bundledCode: "#line 2 \"ds/segtree/dynamic_segtree_sparse.hpp\"\n\n// \u5E38\u306B\
    \u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\u3042\u308B\u3053\
    \u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\u52D5\u7684\u30BB\
    \u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod \u306E\u985E\
    \u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\u4E00\u822C\
    \u306B\u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\u3068\u304D\
    \u30CE\u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\u308B\n\
    template <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse {\n\
    \  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node {\n\
    \    ll idx;\n    Node *l, *r;\n    X prod, x;\n  };\n  const int NODES;\n  const\
    \ ll L0, R0;\n  Node *pool;\n  int pid;\n  using np = Node *;\n  vc<np> FREE;\n\
    \n  Dynamic_SegTree_Sparse(int NODES, ll L0, ll R0) : NODES(NODES), L0(L0), R0(R0),\
    \ pid(0) { pool = new Node[NODES]; }\n  ~Dynamic_SegTree_Sparse() { delete[] pool;\
    \ }\n\n  // \u6728 dp \u306E\u30DE\u30FC\u30B8\u306E\u3068\u304D\u306A\u3069\u306B\
    \u4F7F\u7528\u3059\u308B\u3068 MLE \u56DE\u907F\u3067\u304D\u308B\u3053\u3068\u304C\
    \u3042\u308B\n  // https://codeforces.com/problemset/problem/671/D\n  void free_subtree(np\
    \ c) {\n    auto dfs = [&](auto &dfs, np c) -> void {\n      if (c->l) dfs(dfs,\
    \ c->l);\n      if (c->r) dfs(dfs, c->r);\n      FREE.eb(c);\n    };\n    dfs(dfs,\
    \ c);\n  }\n\n  np new_root() { return nullptr; }\n\n  np new_node(ll idx, const\
    \ X x) {\n    if (!FREE.empty()) {\n      np c = POP(FREE);\n      c->idx = idx,\
    \ c->l = c->r = nullptr;\n      c->prod = c->x = x;\n      return c;\n    }\n\
    \    assert(pid < NODES);\n    pool[pid].idx = idx;\n    pool[pid].l = pool[pid].r\
    \ = nullptr;\n    pool[pid].x = pool[pid].prod = x;\n    return &(pool[pid++]);\n\
    \  }\n\n  X prod(np root, ll l, ll r) {\n    assert(L0 <= l && l <= r && r <=\
    \ R0);\n    if (l == r) return MX::unit();\n    X x = MX::unit();\n    prod_rec(root,\
    \ L0, R0, l, r, x);\n    return x;\n  }\n\n  X prod_all(np root) { return prod(root,\
    \ L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(L0 <= i && i\
    \ < R0);\n    return set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np root,\
    \ ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename\
    \ F>\n  ll min_left(np root, F check, ll R) {\n    assert(L0 <= R && R <= R0 &&\
    \ check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root, check,\
    \ L0, R0, R, x);\n  }\n\n  void reset() {\n    pid = 0;\n    FREE.clear();\n \
    \ }\n\n  vc<pair<ll, X>> get_all(np root) {\n    vc<pair<ll, X>> res;\n    auto\
    \ dfs = [&](auto &dfs, np c) -> void {\n      if (!c) return;\n      dfs(dfs,\
    \ c->l);\n      res.eb(c->idx, c->x);\n      dfs(dfs, c->r);\n    };\n    dfs(dfs,\
    \ root);\n    return res;\n  }\n\n  X get(np root, ll idx) {\n    auto dfs = [&](auto\
    \ &dfs, np c) -> X {\n      if (!c) return Monoid::unit();\n      if (idx == c->idx)\
    \ return c->x;\n      if (idx < (c->idx)) return dfs(dfs, c->l);\n      return\
    \ dfs(dfs, c->r);\n    };\n    return dfs(dfs, root);\n  }\n\nprivate:\n  void\
    \ update(np c) {\n    c->prod = c->x;\n    if (c->l) c->prod = MX::op(c->l->prod,\
    \ c->prod);\n    if (c->r) c->prod = MX::op(c->prod, c->r->prod);\n  }\n\n  np\
    \ copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    assert(pid < NODES);\n\
    \    pool[pid].idx = c->idx;\n    pool[pid].l = c->l;\n    pool[pid].r = c->r;\n\
    \    pool[pid].x = c->x;\n    pool[pid].prod = c->prod;\n    return &(pool[pid++]);\n\
    \  }\n\n  np set_rec(np c, ll l, ll r, ll i, X x) {\n    if (!c) {\n      c =\
    \ new_node(i, x);\n      return c;\n    }\n    c = copy_node(c);\n    if (c->idx\
    \ == i) {\n      c->x = x;\n      update(c);\n      return c;\n    }\n    ll m\
    \ = (l + r) / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x,\
    \ x);\n      c->l = set_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n   \
    \   if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n      c->r = set_rec(c->r,\
    \ m, r, i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  np multiply_rec(np\
    \ c, ll l, ll r, ll i, X x) {\n    if (!c) {\n      c = new_node(i, x);\n    \
    \  return c;\n    }\n    c = copy_node(c);\n    if (c->idx == i) {\n      c->x\
    \ = MX::op(c->x, x);\n      update(c);\n      return c;\n    }\n    ll m = (l\
    \ + r) / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->x,\
    \ x);\n      c->l = multiply_rec(c->l, l, m, i, x);\n    }\n    if (m <= i) {\n\
    \      if (i < c->idx) swap(c->idx, i), swap(c->x, x);\n      c->r = multiply_rec(c->r,\
    \ m, r, i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  void prod_rec(np\
    \ c, ll l, ll r, ll ql, ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n\
    \    if (ql >= qr || !c) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x,\
    \ c->prod);\n      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(c->l,\
    \ l, m, ql, qr, x);\n    if (ql <= (c->idx) && (c->idx) < qr) x = MX::op(x, c->x);\n\
    \    prod_rec(c->r, m, r, ql, qr, x);\n  }\n\n  template <typename F>\n  ll max_right_rec(np\
    \ c, const F &check, ll l, ll r, ll ql, X &x) {\n    if (!c || r <= ql) return\
    \ R0;\n    if (check(MX::op(x, c->prod))) {\n      x = MX::op(x, c->prod);\n \
    \     return R0;\n    }\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l,\
    \ check, l, m, ql, x);\n    if (k != R0) return k;\n    if (ql <= (c->idx)) {\n\
    \      x = MX::op(x, c->x);\n      if (!check(x)) return c->idx;\n    }\n    return\
    \ max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n  template <typename F>\n \
    \ ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {\n    if (!c\
    \ || qr <= l) return L0;\n    if (check(MX::op(c->prod, x))) {\n      x = MX::op(c->prod,\
    \ x);\n      return L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (c->idx < qr) {\n \
    \     x = MX::op(c->x, x);\n      if (!check(x)) return c->idx + 1;\n    }\n \
    \   return min_left_rec(c->l, check, l, m, qr, x);\n  }\n};\n#line 2 \"ds/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n,\
    \ log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template <typename\
    \ F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v)\
    \ { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return\
    \ MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, MX::unit());\n    FOR(i, n) dat[size + i]\
    \ = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  X get(int i) { return dat[size\
    \ + i]; }\n  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size\
    \ + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 3 \"ds/segtree/range_add_range_max.hpp\"\n\n// INF+x==INF \u307F\
    \u305F\u3044\u306A\u51E6\u7406\u306F\u5165\u308C\u3066\u3044\u306A\u3044\n// N=Q=10^6\
    \ \u3067 lazysegtree \u3088\u308A 40% \u7A0B\u5EA6\u9AD8\u901F\ntemplate <typename\
    \ T> struct Range_Add_Range_Max {\n  struct Mono {\n    using value_type = pair<T,\
    \ T>;\n    using X = value_type;\n    static X op(X L, X R) { return {L.fi + R.fi,\
    \ max(L.se, L.fi + R.se)}; }\n    static constexpr X unit() { return {0, -infty<ll>};\
    \ }\n    static constexpr bool commute = false;\n  };\n  int n;\n  T lazy;\n \
    \ SegTree<Mono> seg;\n\n  Range_Add_Range_Max() {}\n  // (n) \u3060\u3051\u3060\
    \u3068 0 \u57CB\u3081\u3067\u521D\u671F\u5316\u3057\u307E\u3059\n  Range_Add_Range_Max(int\
    \ n) { build(n); }\n  template <typename F> Range_Add_Range_Max(int n, F f) {\
    \ build(n, f); }\n  Range_Add_Range_Max(const vc<T> &v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> T { return 0; });\n  }\n  void build(const\
    \ vc<T> &v) {\n    build(len(v), [&](int i) -> T { return v[i]; });\n  }\n  template\
    \ <typename F> void build(int m, F f) {\n    lazy = 0;\n    n = m;\n    T pre\
    \ = 0;\n    seg.build(n, [&](int i) -> pair<T, T> {\n      T t = f(i) - pre;\n\
    \      pre += t;\n      return {t, t};\n    });\n  }\n\n  T prod(int L, int R)\
    \ {\n    if (L == R)\n      return -infty<T>;\n    ll ans = seg.prod(L, R).se;\n\
    \    L += seg.size;\n    for (; L > 0; L /= 2) {\n      if (L & 1)\n        ans\
    \ += seg.dat[--L].fi;\n    }\n    return ans + lazy;\n  }\n\n  T prod_all() {\
    \ return prod(0, n); }\n\n  // \u57FA\u672C\u30C7\u30D0\u30C3\u30B0\u7528\u3068\
    \u3044\u3046\u3064\u3082\u308A\u3067\u3055\u307C\u308A O(NlogN) \u306B\u306A\u3063\
    \u3066\u3044\u308B\n  vc<T> get_all() {\n    vc<T> ANS(n);\n    FOR(i, n) ANS[i]\
    \ = prod(i, i + 1);\n    return ANS;\n  }\n\n  void apply(int L, int R, T x) {\
    \ apply_suffix(L, x), apply_suffix(R, -x); }\n\n  // [0,i)\n  void apply_prefix(int\
    \ i, T x) {\n    lazy += x;\n    apply_suffix(i, -x);\n  }\n\n  // [i,n)\n  void\
    \ apply_suffix(int i, T x) {\n    if (i == n)\n      return;\n    T t = seg.get(i).fi\
    \ + x;\n    seg.set(i, {t, t});\n  }\n  void apply_all(T x) { lazy += x; }\n};\n\
    \n// \u5EA7\u6A19\u306F long long. \u307B\u307C verify \u3055\u308C\u3066\u3044\
    \u306A\u3044\n// https://codeforces.com/contest/542/problem/B\ntemplate <typename\
    \ T> struct Dynamic_Range_Add_Range_Max {\n  struct Mono {\n    using value_type\
    \ = pair<T, T>;\n    using X = value_type;\n    static X op(X L, X R) { return\
    \ {L.fi + R.fi, max(L.se, L.fi + R.se)}; }\n    static constexpr X unit() { return\
    \ {0, 0}; }\n    static constexpr bool commute = false;\n  };\n  int n;\n  Dynamic_SegTree_Sparse<Mono,\
    \ false> seg;\n  T lazy;\n  using np = typename decltype(seg)::np;\n  np root;\n\
    \n  // range apply * 2 \u304F\u3089\u3044\u306E\u30CE\u30FC\u30C9\u6570\n  Dynamic_Range_Add_Range_Max(int\
    \ NODES, ll L, ll R)\n      : seg(NODES, L, R), lazy(0) {\n    root = seg.new_root();\n\
    \  }\n\n  T prod(ll L, ll R) {\n    if (L == R)\n      return -infty<T>;\n   \
    \ ll ans = seg.prod(root, L, R).se;\n    ans += seg.prod(root, seg.L0, L).fi;\n\
    \    return ans + lazy;\n  }\n\n  void apply(ll L, ll R, T x) { apply_suffix(L,\
    \ x), apply_suffix(R, -x); }\n\n  // [i,n)\n  void apply_suffix(ll i, T x) {\n\
    \    if (i == seg.R0)\n      return;\n    T t = seg.get(root, i).fi + x;\n   \
    \ root = seg.set(root, i, {t, t});\n  }\n  void apply_all(T x) { lazy += x; }\n\
    };\n"
  code: "#include \"ds/segtree/dynamic_segtree_sparse.hpp\"\n#include \"ds/segtree/segtree.hpp\"\
    \n\n// INF+x==INF \u307F\u305F\u3044\u306A\u51E6\u7406\u306F\u5165\u308C\u3066\
    \u3044\u306A\u3044\n// N=Q=10^6 \u3067 lazysegtree \u3088\u308A 40% \u7A0B\u5EA6\
    \u9AD8\u901F\ntemplate <typename T> struct Range_Add_Range_Max {\n  struct Mono\
    \ {\n    using value_type = pair<T, T>;\n    using X = value_type;\n    static\
    \ X op(X L, X R) { return {L.fi + R.fi, max(L.se, L.fi + R.se)}; }\n    static\
    \ constexpr X unit() { return {0, -infty<ll>}; }\n    static constexpr bool commute\
    \ = false;\n  };\n  int n;\n  T lazy;\n  SegTree<Mono> seg;\n\n  Range_Add_Range_Max()\
    \ {}\n  // (n) \u3060\u3051\u3060\u3068 0 \u57CB\u3081\u3067\u521D\u671F\u5316\
    \u3057\u307E\u3059\n  Range_Add_Range_Max(int n) { build(n); }\n  template <typename\
    \ F> Range_Add_Range_Max(int n, F f) { build(n, f); }\n  Range_Add_Range_Max(const\
    \ vc<T> &v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ T { return 0; });\n  }\n  void build(const vc<T> &v) {\n    build(len(v), [&](int\
    \ i) -> T { return v[i]; });\n  }\n  template <typename F> void build(int m, F\
    \ f) {\n    lazy = 0;\n    n = m;\n    T pre = 0;\n    seg.build(n, [&](int i)\
    \ -> pair<T, T> {\n      T t = f(i) - pre;\n      pre += t;\n      return {t,\
    \ t};\n    });\n  }\n\n  T prod(int L, int R) {\n    if (L == R)\n      return\
    \ -infty<T>;\n    ll ans = seg.prod(L, R).se;\n    L += seg.size;\n    for (;\
    \ L > 0; L /= 2) {\n      if (L & 1)\n        ans += seg.dat[--L].fi;\n    }\n\
    \    return ans + lazy;\n  }\n\n  T prod_all() { return prod(0, n); }\n\n  //\
    \ \u57FA\u672C\u30C7\u30D0\u30C3\u30B0\u7528\u3068\u3044\u3046\u3064\u3082\u308A\
    \u3067\u3055\u307C\u308A O(NlogN) \u306B\u306A\u3063\u3066\u3044\u308B\n  vc<T>\
    \ get_all() {\n    vc<T> ANS(n);\n    FOR(i, n) ANS[i] = prod(i, i + 1);\n   \
    \ return ANS;\n  }\n\n  void apply(int L, int R, T x) { apply_suffix(L, x), apply_suffix(R,\
    \ -x); }\n\n  // [0,i)\n  void apply_prefix(int i, T x) {\n    lazy += x;\n  \
    \  apply_suffix(i, -x);\n  }\n\n  // [i,n)\n  void apply_suffix(int i, T x) {\n\
    \    if (i == n)\n      return;\n    T t = seg.get(i).fi + x;\n    seg.set(i,\
    \ {t, t});\n  }\n  void apply_all(T x) { lazy += x; }\n};\n\n// \u5EA7\u6A19\u306F\
    \ long long. \u307B\u307C verify \u3055\u308C\u3066\u3044\u306A\u3044\n// https://codeforces.com/contest/542/problem/B\n\
    template <typename T> struct Dynamic_Range_Add_Range_Max {\n  struct Mono {\n\
    \    using value_type = pair<T, T>;\n    using X = value_type;\n    static X op(X\
    \ L, X R) { return {L.fi + R.fi, max(L.se, L.fi + R.se)}; }\n    static constexpr\
    \ X unit() { return {0, 0}; }\n    static constexpr bool commute = false;\n  };\n\
    \  int n;\n  Dynamic_SegTree_Sparse<Mono, false> seg;\n  T lazy;\n  using np =\
    \ typename decltype(seg)::np;\n  np root;\n\n  // range apply * 2 \u304F\u3089\
    \u3044\u306E\u30CE\u30FC\u30C9\u6570\n  Dynamic_Range_Add_Range_Max(int NODES,\
    \ ll L, ll R)\n      : seg(NODES, L, R), lazy(0) {\n    root = seg.new_root();\n\
    \  }\n\n  T prod(ll L, ll R) {\n    if (L == R)\n      return -infty<T>;\n   \
    \ ll ans = seg.prod(root, L, R).se;\n    ans += seg.prod(root, seg.L0, L).fi;\n\
    \    return ans + lazy;\n  }\n\n  void apply(ll L, ll R, T x) { apply_suffix(L,\
    \ x), apply_suffix(R, -x); }\n\n  // [i,n)\n  void apply_suffix(ll i, T x) {\n\
    \    if (i == seg.R0)\n      return;\n    T t = seg.get(root, i).fi + x;\n   \
    \ root = seg.set(root, i, {t, t});\n  }\n  void apply_all(T x) { lazy += x; }\n\
    };\n"
  dependsOn:
  - ds/segtree/dynamic_segtree_sparse.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: ds/segtree/range_add_range_max.hpp
  requiredBy: []
  timestamp: '2025-06-24 14:32:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/range_add_range_max.test.cpp
documentation_of: ds/segtree/range_add_range_max.hpp
layout: document
redirect_from:
- /library/ds/segtree/range_add_range_max.hpp
- /library/ds/segtree/range_add_range_max.hpp.html
title: ds/segtree/range_add_range_max.hpp
---
