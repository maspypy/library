---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc174f.test.cpp
    title: test/atcoder/abc174f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F& check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\
    \u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r} A[i xor x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"ds/offline_query/uniqueproductquery.hpp\"\n\r\n// [L, R) \u5185\
    \u306E\u8981\u7D20 (long long)\u3092 UNIQUE \u3057\u305F\u4E0A\u3067\u3001f(x)\u306E\
    \u7DCF\u7A4D\u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002\r\n//\
    \ \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\u30BB\u30B0\u6728\
    \r\n// \u30AF\u30A8\u30EA\u3092\u5168\u90E8 add(L,R) \u3059\u308B\r\n// calc(f)\
    \ \u3068\u3057\u3066\u547C\u3076\r\ntemplate <typename Mono>\r\nstruct UniqueProductQuery\
    \ {\r\n  using X = typename Mono::value_type;\r\n  int N;\r\n  vc<ll> key;\r\n\
    \  vc<pair<int, int>> query;\r\n\r\n  UniqueProductQuery(vc<ll>& key) : N(len(key)),\
    \ key(key) {}\r\n\r\n  void add(int L, int R) {\r\n    assert(0 <= L && L <= R\
    \ && R <= N);\r\n    query.eb(L, R);\r\n  }\r\n\r\n  template <typename F>\r\n\
    \  vc<X> calc(F f) {\r\n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n    vc<vc<int>>\
    \ IDS(N + 1);\r\n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono> seg(N);\r\
    \n\r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n\r\n    FOR(i,\
    \ N) {\r\n      ll x = key[i];\r\n      if (pos.count(x)) { seg.set(pos[x], Mono::unit());\
    \ }\r\n      pos[x] = i;\r\n      seg.set(i, f(key[i]));\r\n      for (auto&&\
    \ q: IDS[i + 1]) {\r\n        auto [L, R] = query[q];\r\n        ANS[q] = seg.prod(L,\
    \ R);\r\n      }\r\n    }\r\n    return ANS;\r\n  }\r\n\r\n  vc<X> calc() {\r\n\
    \    auto f = [&](ll k) -> X { return 1; };\r\n    return calc(f);\r\n  }\r\n\
    };\r\n"
  code: "#include \"ds/segtree/segtree.hpp\"\r\n\r\n// [L, R) \u5185\u306E\u8981\u7D20\
    \ (long long)\u3092 UNIQUE \u3057\u305F\u4E0A\u3067\u3001f(x)\u306E\u7DCF\u7A4D\
    \u3092\u3068\u3063\u305F\u3082\u306E\u3092\u8A08\u7B97\u3002\r\n// \u30AF\u30A8\
    \u30EA\u5148\u8AAD\u307F\u30BD\u30FC\u30C8\uFF0B\u30BB\u30B0\u6728\r\n// \u30AF\
    \u30A8\u30EA\u3092\u5168\u90E8 add(L,R) \u3059\u308B\r\n// calc(f) \u3068\u3057\
    \u3066\u547C\u3076\r\ntemplate <typename Mono>\r\nstruct UniqueProductQuery {\r\
    \n  using X = typename Mono::value_type;\r\n  int N;\r\n  vc<ll> key;\r\n  vc<pair<int,\
    \ int>> query;\r\n\r\n  UniqueProductQuery(vc<ll>& key) : N(len(key)), key(key)\
    \ {}\r\n\r\n  void add(int L, int R) {\r\n    assert(0 <= L && L <= R && R <=\
    \ N);\r\n    query.eb(L, R);\r\n  }\r\n\r\n  template <typename F>\r\n  vc<X>\
    \ calc(F f) {\r\n    ll Q = len(query);\r\n    vc<X> ANS(Q);\r\n    vc<vc<int>>\
    \ IDS(N + 1);\r\n    FOR(q, Q) IDS[query[q].se].eb(q);\r\n    SegTree<Mono> seg(N);\r\
    \n\r\n    unordered_map<ll, int> pos;\r\n    pos.reserve(N);\r\n\r\n    FOR(i,\
    \ N) {\r\n      ll x = key[i];\r\n      if (pos.count(x)) { seg.set(pos[x], Mono::unit());\
    \ }\r\n      pos[x] = i;\r\n      seg.set(i, f(key[i]));\r\n      for (auto&&\
    \ q: IDS[i + 1]) {\r\n        auto [L, R] = query[q];\r\n        ANS[q] = seg.prod(L,\
    \ R);\r\n      }\r\n    }\r\n    return ANS;\r\n  }\r\n\r\n  vc<X> calc() {\r\n\
    \    auto f = [&](ll k) -> X { return 1; };\r\n    return calc(f);\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: ds/offline_query/uniqueproductquery.hpp
  requiredBy: []
  timestamp: '2022-12-03 10:20:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc174f.test.cpp
documentation_of: ds/offline_query/uniqueproductquery.hpp
layout: document
redirect_from:
- /library/ds/offline_query/uniqueproductquery.hpp
- /library/ds/offline_query/uniqueproductquery.hpp.html
title: ds/offline_query/uniqueproductquery.hpp
---
