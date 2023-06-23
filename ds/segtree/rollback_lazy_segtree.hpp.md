---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/submission/114657
  bundledCode: "#line 2 \"ds/rollback_array.hpp\"\n\r\ntemplate <typename T>\r\nstruct\
    \ Rollback_Array {\r\n  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\
    \n\r\n  Rollback_Array() {}\r\n  Rollback_Array(vc<T> x) : N(len(x)), dat(x) {}\r\
    \n  Rollback_Array(int N) : N(N), dat(N) {}\r\n  template <typename F>\r\n  Rollback_Array(int\
    \ N, F f) : N(N) {\r\n    dat.reserve(N);\r\n    FOR(i, N) dat.eb(f(i));\r\n \
    \ }\r\n\r\n  int time() { return len(history); }\r\n  void rollback(int t) {\r\
    \n    FOR_R(i, t, time()) {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx]\
    \ = v;\r\n    }\r\n    history.resize(t);\r\n  }\r\n  T get(int idx) { return\
    \ dat[idx]; }\r\n  void set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\
    \n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T> res(N);\r\n\
    \    FOR(i, N) res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"\
    ds/segtree/rollback_lazy_segtree.hpp\"\n// verify? https://qoj.ac/submission/114657\n\
    template <typename ActedMonoid>\nstruct Rollback_Lazy_SegTree {\n  using AM =\
    \ ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n\
    \  using X = typename MX::value_type;\n  using A = typename MA::value_type;\n\
    \  int n, log, size;\n  Rollback_Array<X> dat;\n  Rollback_Array<A> laz;\n\n \
    \ Rollback_Lazy_SegTree() {}\n  Rollback_Lazy_SegTree(int n) { build(n); }\n \
    \ template <typename F>\n  Rollback_Lazy_SegTree(int n, F f) {\n    build(n, f);\n\
    \  }\n  Rollback_Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat = Rollback_Array<X>(vc<X>(size\
    \ << 1, MX::unit()));\n    laz = Rollback_Array<A>(vc<A>(size, MA::unit()));\n\
    \    FOR(i, n) dat.set(size + i, f(i));\n    FOR_R(i, 1, size) update(i);\n  }\n\
    \n  void update(int k) { dat.set(k, MX::op(dat.get(2 * k), dat.get(2 * k + 1)));\
    \ }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    dat.set(p, x);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const\
    \ X& x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat.set(p, MX::op(dat.get(p), x));\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat.get(p);\n  }\n\n  vc<X> get_all() {\n    auto tmp = dat.get_all();\n\
    \    FOR(k, 1, size) push(k);\n    return {tmp.begin() + size, tmp.begin() + size\
    \ + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    if (l == r) return MX::unit();\n    l += size, r += size;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl = MX::unit(),\
    \ xr = MX::unit();\n    while (l < r) {\n      if (l & 1) xl = MX::op(xl, dat.get(l++));\n\
    \      if (r & 1) xr = MX::op(dat.get(--r), xr);\n      l >>= 1, r >>= 1;\n  \
    \  }\n    return MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat.get(1); }\n\
    \n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    if (l == r) return;\n    l += size, r += size;\n    for (int i = log; i >=\
    \ 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l\
    \ < r) {\n      if (l & 1) apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n\
    \      l >>= 1, r >>= 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ F>\n  int max_right(const F check, int l) {\n    assert(0 <= l && l <= n);\n\
    \    assert(check(MX::unit()));\n    if (l == n) return n;\n    l += size;\n \
    \   for (int i = log; i >= 1; i--) push(l >> i);\n    X sm = MX::unit();\n   \
    \ do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm, dat.get(l))))\
    \ {\n        while (l < size) {\n          push(l);\n          l = (2 * l);\n\
    \          if (check(MX::op(sm, dat.get(l)))) { sm = MX::op(sm, dat.get(l++));\
    \ }\n        }\n        return l - size;\n      }\n      sm = MX::op(sm, dat.get(l++));\n\
    \    } while ((l & -l) != l);\n    return n;\n  }\n\n  template <typename F>\n\
    \  int min_left(const F check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(MX::unit()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = MX::unit();\n    do {\n      r--;\n      while\
    \ (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat.get(r), sm))) {\n \
    \       while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n \
    \         if (check(MX::op(dat.get(r), sm))) { sm = MX::op(dat.get(r--), sm);\
    \ }\n        }\n        return r + 1 - size;\n      }\n      sm = MX::op(dat.get(r),\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  pair<int, int> time()\
    \ { return {dat.time(), laz.time()}; }\n  void rollback(pair<int, int> t) { dat.rollback(t.fi),\
    \ laz.rollback(t.se); }\n\n  void push(int k) {\n    if (laz.get(k) == MA::unit())\
    \ return;\n    apply_at(2 * k, laz.get(k)), apply_at(2 * k + 1, laz.get(k));\n\
    \    laz.set(k, MA::unit());\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n\
    \    ll sz = 1 << (log - topbit(k));\n    dat.set(k, AM::act(dat.get(k), a, sz));\n\
    \    if (k < size) laz.set(k, MA::op(laz.get(k), a));\n  }\n};\n"
  code: "#include \"ds/rollback_array.hpp\"\n// verify? https://qoj.ac/submission/114657\n\
    template <typename ActedMonoid>\nstruct Rollback_Lazy_SegTree {\n  using AM =\
    \ ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n\
    \  using X = typename MX::value_type;\n  using A = typename MA::value_type;\n\
    \  int n, log, size;\n  Rollback_Array<X> dat;\n  Rollback_Array<A> laz;\n\n \
    \ Rollback_Lazy_SegTree() {}\n  Rollback_Lazy_SegTree(int n) { build(n); }\n \
    \ template <typename F>\n  Rollback_Lazy_SegTree(int n, F f) {\n    build(n, f);\n\
    \  }\n  Rollback_Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat = Rollback_Array<X>(vc<X>(size\
    \ << 1, MX::unit()));\n    laz = Rollback_Array<A>(vc<A>(size, MA::unit()));\n\
    \    FOR(i, n) dat.set(size + i, f(i));\n    FOR_R(i, 1, size) update(i);\n  }\n\
    \n  void update(int k) { dat.set(k, MX::op(dat.get(2 * k), dat.get(2 * k + 1)));\
    \ }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    dat.set(p, x);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const\
    \ X& x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat.set(p, MX::op(dat.get(p), x));\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat.get(p);\n  }\n\n  vc<X> get_all() {\n    auto tmp = dat.get_all();\n\
    \    FOR(k, 1, size) push(k);\n    return {tmp.begin() + size, tmp.begin() + size\
    \ + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    if (l == r) return MX::unit();\n    l += size, r += size;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl = MX::unit(),\
    \ xr = MX::unit();\n    while (l < r) {\n      if (l & 1) xl = MX::op(xl, dat.get(l++));\n\
    \      if (r & 1) xr = MX::op(dat.get(--r), xr);\n      l >>= 1, r >>= 1;\n  \
    \  }\n    return MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat.get(1); }\n\
    \n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    if (l == r) return;\n    l += size, r += size;\n    for (int i = log; i >=\
    \ 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l\
    \ < r) {\n      if (l & 1) apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n\
    \      l >>= 1, r >>= 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ F>\n  int max_right(const F check, int l) {\n    assert(0 <= l && l <= n);\n\
    \    assert(check(MX::unit()));\n    if (l == n) return n;\n    l += size;\n \
    \   for (int i = log; i >= 1; i--) push(l >> i);\n    X sm = MX::unit();\n   \
    \ do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm, dat.get(l))))\
    \ {\n        while (l < size) {\n          push(l);\n          l = (2 * l);\n\
    \          if (check(MX::op(sm, dat.get(l)))) { sm = MX::op(sm, dat.get(l++));\
    \ }\n        }\n        return l - size;\n      }\n      sm = MX::op(sm, dat.get(l++));\n\
    \    } while ((l & -l) != l);\n    return n;\n  }\n\n  template <typename F>\n\
    \  int min_left(const F check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(MX::unit()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = MX::unit();\n    do {\n      r--;\n      while\
    \ (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat.get(r), sm))) {\n \
    \       while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n \
    \         if (check(MX::op(dat.get(r), sm))) { sm = MX::op(dat.get(r--), sm);\
    \ }\n        }\n        return r + 1 - size;\n      }\n      sm = MX::op(dat.get(r),\
    \ sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\n  pair<int, int> time()\
    \ { return {dat.time(), laz.time()}; }\n  void rollback(pair<int, int> t) { dat.rollback(t.fi),\
    \ laz.rollback(t.se); }\n\n  void push(int k) {\n    if (laz.get(k) == MA::unit())\
    \ return;\n    apply_at(2 * k, laz.get(k)), apply_at(2 * k + 1, laz.get(k));\n\
    \    laz.set(k, MA::unit());\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n\
    \    ll sz = 1 << (log - topbit(k));\n    dat.set(k, AM::act(dat.get(k), a, sz));\n\
    \    if (k < size) laz.set(k, MA::op(laz.get(k), a));\n  }\n};"
  dependsOn:
  - ds/rollback_array.hpp
  isVerificationFile: false
  path: ds/segtree/rollback_lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-06-23 23:22:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/rollback_lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/rollback_lazy_segtree.hpp
- /library/ds/segtree/rollback_lazy_segtree.hpp.html
title: ds/segtree/rollback_lazy_segtree.hpp
---
