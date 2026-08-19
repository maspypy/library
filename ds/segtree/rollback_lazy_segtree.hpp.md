---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/submission/114657
  bundledCode: "#line 1 \"ds/segtree/rollback_lazy_segtree.hpp\"\n\n#line 1 \"other/bit.hpp\"\
    \n\nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\nint popcnt_sgn(int\
    \ x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }\nint popcnt_sgn(u32\
    \ x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\nint popcnt_sgn(ll x) { return\
    \ (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x)\
    \ & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x == 0 ? -1\
    \ : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32 x) { return\
    \ (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate\
    \ <typename T>\nbool has_kth_bit(T x, int k) {\n  return x >> k & 1;\n}\n\ntemplate\
    \ <typename UINT>\nstruct all_bit {\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n\
    \  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s); }\n\
    \    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const {\
    \ return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset {\n \
    \ UINT s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n \
    \   bool done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return\
    \ n == 64 ? -1ULL : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x\
    \ & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x =\
    \ ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n \
    \ x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"ds/rollback_array.hpp\"\
    \n\ntemplate <typename T>\nstruct Rollback_Array {\n  int N;\n  vc<T> dat;\n \
    \ vc<pair<int, T>> history;\n\n  Rollback_Array() {}\n  Rollback_Array(vc<T> x)\
    \ : N(len(x)), dat(x) {}\n  Rollback_Array(int N) : N(N), dat(N) {}\n  template\
    \ <typename F>\n  Rollback_Array(int N, F f) : N(N) {\n    dat.reserve(N);\n \
    \   FOR(i, N) dat.eb(f(i));\n  }\n\n  int time() { return len(history); }\n  void\
    \ rollback(int t) {\n    FOR_R(i, t, time()) {\n      auto& [idx, v] = history[i];\n\
    \      dat[idx] = v;\n    }\n    history.resize(t);\n  }\n  T get(int idx) { return\
    \ dat[idx]; }\n  void set(int idx, T x) {\n    history.eb(idx, dat[idx]);\n  \
    \  dat[idx] = x;\n  }\n\n  vc<T> get_all() {\n    vc<T> res(N);\n    FOR(i, N)\
    \ res[i] = get(i);\n    return res;\n  }\n};\n#line 4 \"ds/segtree/rollback_lazy_segtree.hpp\"\
    \n// verify? https://qoj.ac/submission/114657\ntemplate <typename ActedMonoid>\n\
    struct Rollback_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n\
    \  using A = typename MA::value_type;\n  int n, log, size;\n  Rollback_Array<X>\
    \ dat;\n  Rollback_Array<A> laz;\n\n  Rollback_Lazy_SegTree() {}\n  Rollback_Lazy_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Rollback_Lazy_SegTree(int n, F\
    \ f) {\n    build(n, f);\n  }\n  Rollback_Lazy_SegTree(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n\
    \    dat = Rollback_Array<X>(vc<X>(size << 1, MX::unit()));\n    laz = Rollback_Array<A>(vc<A>(size,\
    \ MA::unit()));\n    FOR(i, n) dat.set(size + i, f(i));\n    FOR_R(i, 1, size)\
    \ update(i);\n  }\n\n  void update(int k) { dat.set(k, MX::op(dat.get(2 * k),\
    \ dat.get(2 * k + 1))); }\n  void set(int p, X x) {\n    assert(0 <= p && p <\
    \ n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat.set(p,\
    \ x);\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int\
    \ p, const X& x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat.set(p, MX::op(dat.get(p), x));\n\
    \    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    return dat.get(p);\n  }\n\n  vc<X> get_all() {\n    auto\
    \ tmp = dat.get_all();\n    FOR(k, 1, size) push(k);\n    return {tmp.begin()\
    \ + size, tmp.begin() + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return MX::unit();\n    l += size,\
    \ r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i)\
    \ != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n \
    \   }\n    X xl = MX::unit(), xr = MX::unit();\n    while (l < r) {\n      if\
    \ (l & 1) xl = MX::op(xl, dat.get(l++));\n      if (r & 1) xr = MX::op(dat.get(--r),\
    \ xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X\
    \ prod_all() { return dat.get(1); }\n\n  void apply(int l, int r, A a) {\n   \
    \ assert(0 <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size,\
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
    \      if (!check(MX::op(sm, dat.get(l)))) {\n        while (l < size) {\n   \
    \       push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat.get(l))))\
    \ {\n            sm = MX::op(sm, dat.get(l++));\n          }\n        }\n    \
    \    return l - size;\n      }\n      sm = MX::op(sm, dat.get(l++));\n    } while\
    \ ((l & -l) != l);\n    return n;\n  }\n\n  template <typename F>\n  int min_left(const\
    \ F check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(MX::unit()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = MX::unit();\n    do {\n      r--;\n      while\
    \ (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat.get(r), sm))) {\n \
    \       while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n \
    \         if (check(MX::op(dat.get(r), sm))) {\n            sm = MX::op(dat.get(r--),\
    \ sm);\n          }\n        }\n        return r + 1 - size;\n      }\n      sm\
    \ = MX::op(dat.get(r), sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\
    \n  pair<int, int> time() { return {dat.time(), laz.time()}; }\n  void rollback(pair<int,\
    \ int> t) { dat.rollback(t.fi), laz.rollback(t.se); }\n\n  void push(int k) {\n\
    \    if (laz.get(k) == MA::unit()) return;\n    apply_at(2 * k, laz.get(k)), apply_at(2\
    \ * k + 1, laz.get(k));\n    laz.set(k, MA::unit());\n  }\n\n private:\n  void\
    \ apply_at(int k, A a) {\n    ll sz = 1 << (log - topbit(k));\n    dat.set(k,\
    \ AM::act(dat.get(k), a, sz));\n    if (k < size) laz.set(k, MA::op(laz.get(k),\
    \ a));\n  }\n};\n"
  code: "\n#include \"other/bit.hpp\"\n#include \"ds/rollback_array.hpp\"\n// verify?\
    \ https://qoj.ac/submission/114657\ntemplate <typename ActedMonoid>\nstruct Rollback_Lazy_SegTree\
    \ {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA\
    \ = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n  using A =\
    \ typename MA::value_type;\n  int n, log, size;\n  Rollback_Array<X> dat;\n  Rollback_Array<A>\
    \ laz;\n\n  Rollback_Lazy_SegTree() {}\n  Rollback_Lazy_SegTree(int n) { build(n);\
    \ }\n  template <typename F>\n  Rollback_Lazy_SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Rollback_Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
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
    \          if (check(MX::op(sm, dat.get(l)))) {\n            sm = MX::op(sm, dat.get(l++));\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = MX::op(sm,\
    \ dat.get(l++));\n    } while ((l & -l) != l);\n    return n;\n  }\n\n  template\
    \ <typename F>\n  int min_left(const F check, int r) {\n    assert(0 <= r && r\
    \ <= n);\n    assert(check(MX::unit()));\n    if (r == 0) return 0;\n    r +=\
    \ size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X sm = MX::unit();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat.get(r),\
    \ sm))) {\n        while (r < size) {\n          push(r);\n          r = (2 *\
    \ r + 1);\n          if (check(MX::op(dat.get(r), sm))) {\n            sm = MX::op(dat.get(r--),\
    \ sm);\n          }\n        }\n        return r + 1 - size;\n      }\n      sm\
    \ = MX::op(dat.get(r), sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\
    \n  pair<int, int> time() { return {dat.time(), laz.time()}; }\n  void rollback(pair<int,\
    \ int> t) { dat.rollback(t.fi), laz.rollback(t.se); }\n\n  void push(int k) {\n\
    \    if (laz.get(k) == MA::unit()) return;\n    apply_at(2 * k, laz.get(k)), apply_at(2\
    \ * k + 1, laz.get(k));\n    laz.set(k, MA::unit());\n  }\n\n private:\n  void\
    \ apply_at(int k, A a) {\n    ll sz = 1 << (log - topbit(k));\n    dat.set(k,\
    \ AM::act(dat.get(k), a, sz));\n    if (k < size) laz.set(k, MA::op(laz.get(k),\
    \ a));\n  }\n};"
  dependsOn:
  - other/bit.hpp
  - ds/rollback_array.hpp
  isVerificationFile: false
  path: ds/segtree/rollback_lazy_segtree.hpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/rollback_lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/rollback_lazy_segtree.hpp
- /library/ds/segtree/rollback_lazy_segtree.hpp.html
title: ds/segtree/rollback_lazy_segtree.hpp
---
