---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':question:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: pds/segtree.hpp
    title: pds/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/703/problem/D
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X>\r\nstruct Group_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ n * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"ds/segtree.hpp\"\n\ntemplate <class\
    \ Monoid>\nstruct SegTree {\n  using X = typename Monoid::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() : SegTree(0)\
    \ {}\n  SegTree(int n) : SegTree(vc<X>(n, Monoid::unit())) {}\n  SegTree(vc<X>\
    \ v) : n(len(v)) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n    FOR(i, n) dat[size\
    \ + i] = v[i];\n    FOR3_R(i, 1, size) update(i);\n  }\n\n  X operator[](int i)\
    \ { return dat[size + i]; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n\n  void set(int i, X x) {\n    assert(i < n);\n \
    \   dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L,\
    \ int R) {\n    assert(L <= R);\n    assert(R <= n);\n    X vl = Monoid::unit(),\
    \ vr = Monoid::unit();\n    L += size, R += size;\n    while (L < R) {\n     \
    \ if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R],\
    \ vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n\
    \  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int max_right(F\
    \ &check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n \
    \   if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) {\n            sm = Monoid::op(sm, dat[L]);\n            L++;\n  \
    \        }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L]);\n      L++;\n    } while ((L & -L) != L);\n    return n;\n  }\n\n \
    \ template <class F>\n  int min_left(F &check, int R) {\n    assert(0 <= R &&\
    \ R <= n && check(Monoid::unit()));\n    if (R == 0) return 0;\n    R += size;\n\
    \    X sm = Monoid::unit();\n    do {\n      --R;\n      while (R > 1 && (R %\
    \ 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R], sm))) {\n        while (R\
    \ < size) {\n          R = 2 * R + 1;\n          if (check(Monoid::op(dat[R],\
    \ sm))) {\n            sm = Monoid::op(dat[R], sm);\n            R--;\n      \
    \    }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\
    \u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n  X Xor_prod(int\
    \ l, int r, int xor_val) {\n    assert(Monoid::commute);\n    X x = Monoid::unit();\n\
    \    FOR(k, log + 1) {\n      if (l >= r) break;\n      if (l & 1) { x = Monoid::op(x,\
    \ dat[(size >> k) + ((l++) ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n\
    \    }\n    return x;\n  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n\
    #line 2 \"pds/segtree.hpp\"\ntemplate <class Monoid, int NODES = 20000000>\nstruct\
    \ PersistentSegTree {\n  using X = typename Monoid::value_type;\n  using value_type\
    \ = X;\n\n  struct Node {\n    X x;\n    Node *lch, *rch;\n    Node() {}\n   \
    \ Node(const X &x) : x(x), lch(nullptr), rch(nullptr) {}\n  };\n\n  Node *pool;\n\
    \  int pid;\n  ll n;\n  Node *nil;\n  vc<Node *> roots;\n\n  PersistentSegTree(int\
    \ n) : pid(0), n(n), nil(nullptr) {\n    pool = new Node[NODES];\n    nil = new_node(Monoid::unit());\n\
    \    nil->lch = nil->rch = nil;\n    roots.reserve(1 << 18);\n    roots.push_back(nil);\n\
    \  }\n\nprivate:\n  Node *new_node(const X &x) {\n    pool[pid].x = x;\n    pool[pid].lch\
    \ = pool[pid].rch = nil;\n    return &(pool[pid++]);\n  }\n\n  Node *merge(Node\
    \ *l, Node *r) {\n    pool[pid].x = Monoid::op(l->x, r->x);\n    pool[pid].lch\
    \ = l;\n    pool[pid].rch = r;\n    return &(pool[pid++]);\n  }\n\n  Node *set(ll\
    \ idx, const X &x, Node *n, ll l, ll r) {\n    if (l + 1 == r) return new_node(x);\n\
    \    ll m = (l + r) / 2;\n    if (idx < m) return merge(set(idx, x, n->lch, l,\
    \ m), n->rch);\n    return merge(n->lch, set(idx, x, n->rch, m, r));\n  }\n\n\
    \  X prod(ll a, ll b, Node *n, ll l, ll r) {\n    if (n == nil) return Monoid::unit();\n\
    \    if (r <= a || b <= l) return Monoid::unit();\n    if (a <= l && r <= b) return\
    \ n->x;\n    ll m = (l + r) / 2;\n    return Monoid::op(prod(a, b, n->lch, l,\
    \ m), prod(a, b, n->rch, m, r));\n  }\n\npublic:\n  int time() { return len(roots)\
    \ - 1; }\n\n  int set(int t, ll idx, const X &x) {\n    Node *root = set(idx,\
    \ x, roots[t], 0, n);\n    roots.eb(root);\n    return time();\n  }\n\n  X prod(int\
    \ time, ll l, ll r) { return prod(l, r, roots[time], 0, n); }\n};\n#line 4 \"\
    ds/uniqueproductquery.hpp\"\n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\
    \n// [L, R) \u5185\u306E\u8981\u7D20 (long long)\u3092 UNIQUE \u3057\u305F\u4E0A\
    \u3067\u3001f(x) \u306E\u7DCF\u7A4D\u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\
    \u7B97\u3002\r\n// \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\
    \u30BB\u30B0\u6728\r\n// \u30FB\u30AF\u30A8\u30EA\u3092\u5168\u90E8 add(L, R)\
    \ \u3059\u308B\r\n// \u30FBcalc(f) \u3068\u3057\u3066\u547C\u3076\r\ntemplate\
    \ <typename Mono=Group_Add<int>>\r\nstruct UniqueProductQuery {\r\n  using X =\
    \ typename Mono::value_type;\r\n  int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>>\
    \ query;\r\n \r\n  UniqueProductQuery(vc<ll>& key) : N(len(key)), key(key) {}\r\
    \n \r\n  void add(int L, int R) {\r\n    assert(0 <= L && L <= R && R <= N);\r\
    \n    query.eb(L, R);\r\n  }\r\n \r\n  template <typename F>\r\n  vc<X> calc(F\
    \ f) {\r\n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n    vc<vc<int>> IDS(N\
    \ + 1);\r\n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono> seg(N);\r\
    \n \r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n \r\n    FOR(i,\
    \ N) {\r\n      ll x = key[i];\r\n      if (pos.count(x)) {\r\n        seg.set(pos[x],\
    \ Mono::unit);\r\n      }\r\n      pos[x] = i;\r\n      seg.set(i, f(key[i]));\r\
    \n      for (auto&& q: IDS[i + 1]) {\r\n        auto [L, R] = query[q];\r\n  \
    \      ANS[q] = seg.prod(L, R);\r\n      }\r\n    }\r\n    return ANS;\r\n  }\r\
    \n \r\n  vc<X> calc() {\r\n    auto f = [&](ll k) -> X { return 1; };\r\n    return\
    \ calc(f);\r\n  }\r\n};\r\n\r\n\r\n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\
    \n// key = long long\r\n// [L, R) \u5185\u306E\u8981\u7D20 (long long) \u3092\
    \ UNIQUE \u3057\u305F\u4E0A\u3067\u3001\r\n// f(k),\u306E\u7DCF\u7A4D\u3092\u3068\
    \u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002 f: key -> Monoid value\r\n//\
    \ Online \u5316\u3057\u305F\u3082\u306E\u306E\u3001\u30E1\u30E2\u30EA\u5B9A\u6570\
    \u500D\u304C\u91CD\u3044\r\ntemplate <typename Monoid = Group_Add<int>>\r\nstruct\
    \ OnlineUniqueProductQuery {\r\n  using X = typename Monoid::value_type;\r\n \
    \ int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>> query;\r\n  vc<int> times;\r\
    \n  PersistentSegTree<Monoid> seg;\r\n\r\n  template <typename F>\r\n  OnlineUniqueProductQuery(vc<ll>&\
    \ key, F f) : N(len(key)), key(key), seg(N) {\r\n    times.eb(seg.time());\r\n\
    \    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n    FOR(i, N) {\r\n\
    \      ll x = key[i];\r\n      int t = seg.time();\r\n      if (pos.count(x))\
    \ { t = seg.set(t, pos[x], Monoid::unit); }\r\n      pos[x] = i;\r\n      t =\
    \ seg.set(t, i, f(key[i]));\r\n      times.eb(t);\r\n    }\r\n  }\r\n  \r\n  X\
    \ prod(int L, int R) {\r\n    int t = times[R];\r\n    return seg.prod(t, L, R);\r\
    \n  }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"ds/segtree.hpp\"\r\n#include\
    \ \"pds/segtree.hpp\"\r\n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\
    \n// [L, R) \u5185\u306E\u8981\u7D20 (long long)\u3092 UNIQUE \u3057\u305F\u4E0A\
    \u3067\u3001f(x) \u306E\u7DCF\u7A4D\u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\
    \u7B97\u3002\r\n// \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\
    \u30BB\u30B0\u6728\r\n// \u30FB\u30AF\u30A8\u30EA\u3092\u5168\u90E8 add(L, R)\
    \ \u3059\u308B\r\n// \u30FBcalc(f) \u3068\u3057\u3066\u547C\u3076\r\ntemplate\
    \ <typename Mono=Group_Add<int>>\r\nstruct UniqueProductQuery {\r\n  using X =\
    \ typename Mono::value_type;\r\n  int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>>\
    \ query;\r\n \r\n  UniqueProductQuery(vc<ll>& key) : N(len(key)), key(key) {}\r\
    \n \r\n  void add(int L, int R) {\r\n    assert(0 <= L && L <= R && R <= N);\r\
    \n    query.eb(L, R);\r\n  }\r\n \r\n  template <typename F>\r\n  vc<X> calc(F\
    \ f) {\r\n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n    vc<vc<int>> IDS(N\
    \ + 1);\r\n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono> seg(N);\r\
    \n \r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n \r\n    FOR(i,\
    \ N) {\r\n      ll x = key[i];\r\n      if (pos.count(x)) {\r\n        seg.set(pos[x],\
    \ Mono::unit);\r\n      }\r\n      pos[x] = i;\r\n      seg.set(i, f(key[i]));\r\
    \n      for (auto&& q: IDS[i + 1]) {\r\n        auto [L, R] = query[q];\r\n  \
    \      ANS[q] = seg.prod(L, R);\r\n      }\r\n    }\r\n    return ANS;\r\n  }\r\
    \n \r\n  vc<X> calc() {\r\n    auto f = [&](ll k) -> X { return 1; };\r\n    return\
    \ calc(f);\r\n  }\r\n};\r\n\r\n\r\n\r\n// sample\uFF1Ahttps://codeforces.com/contest/703/problem/D\r\
    \n// key = long long\r\n// [L, R) \u5185\u306E\u8981\u7D20 (long long) \u3092\
    \ UNIQUE \u3057\u305F\u4E0A\u3067\u3001\r\n// f(k),\u306E\u7DCF\u7A4D\u3092\u3068\
    \u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002 f: key -> Monoid value\r\n//\
    \ Online \u5316\u3057\u305F\u3082\u306E\u306E\u3001\u30E1\u30E2\u30EA\u5B9A\u6570\
    \u500D\u304C\u91CD\u3044\r\ntemplate <typename Monoid = Group_Add<int>>\r\nstruct\
    \ OnlineUniqueProductQuery {\r\n  using X = typename Monoid::value_type;\r\n \
    \ int N;\r\n  vc<ll> key;\r\n  vc<pair<int, int>> query;\r\n  vc<int> times;\r\
    \n  PersistentSegTree<Monoid> seg;\r\n\r\n  template <typename F>\r\n  OnlineUniqueProductQuery(vc<ll>&\
    \ key, F f) : N(len(key)), key(key), seg(N) {\r\n    times.eb(seg.time());\r\n\
    \    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n    FOR(i, N) {\r\n\
    \      ll x = key[i];\r\n      int t = seg.time();\r\n      if (pos.count(x))\
    \ { t = seg.set(t, pos[x], Monoid::unit); }\r\n      pos[x] = i;\r\n      t =\
    \ seg.set(t, i, f(key[i]));\r\n      times.eb(t);\r\n    }\r\n  }\r\n  \r\n  X\
    \ prod(int L, int R) {\r\n    int t = times[R];\r\n    return seg.prod(t, L, R);\r\
    \n  }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  - ds/segtree.hpp
  - pds/segtree.hpp
  isVerificationFile: false
  path: ds/uniqueproductquery.hpp
  requiredBy: []
  timestamp: '2022-04-24 23:28:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/uniqueproductquery.hpp
layout: document
redirect_from:
- /library/ds/uniqueproductquery.hpp
- /library/ds/uniqueproductquery.hpp.html
title: ds/uniqueproductquery.hpp
---
