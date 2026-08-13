---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Min {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n   \
    \ while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R\
    \ & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return\
    \ Monoid::op(vl, vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n \
    \   while (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n\
    \      L >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n   \
    \ return I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class\
    \ F>\n  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n &&\
    \ check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n    X sm\
    \ = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm,\
    \ dat[L]))) {\n        while (L < size) {\n          L = 2 * L;\n          if\
    \ (check(Monoid::op(sm, dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n\
    \          }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >>\
    \ k) + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 3 \"ds/range_mex_change.hpp\"\n\n\
    // i, A[i] \u3092\u8FFD\u52A0 -> mex(A[j],...,A[i+1]) \u304C\u66F4\u65B0\n// \u3053\
    \u306E\u3068\u304D\u306E\u66F4\u65B0\u898F\u5247\u3092\u5F97\u308B\nstruct Range_Mex_Change\
    \ {\n  int N;\n  vc<int> last;\n  SegTree<Monoid_Min<int>> seg;\n  int nxt_i;\n\
    \  Range_Mex_Change(int N) : N(N), last(N + 1, -1), seg(last), nxt_i(0) {}\n\n\
    \  // F(l,r,x,y): [l,...,r) \u90E8\u5206\u304C x->y \u306B\u5909\u66F4\n  template\
    \ <typename F>\n  void add(int i, int x, F change) {\n    assert(i == nxt_i);\n\
    \    ++nxt_i;\n    chmin(x, N);\n    int p = last[x];\n    int R = (x == 0 ? i\
    \ + 1 : seg.prod(0, x) + 1);\n\n    last[x] = i;\n    seg.set(x, i);\n    while\
    \ (p + 1 < R) {\n      int y = seg.max_right([&](int v) -> bool { return v >=\
    \ R - 1; }, x + 1);\n      int L = max(p + 1, last[y] + 1);\n      change(L, R,\
    \ x, y);\n      R = L;\n    }\n  }\n};\n"
  code: "#include \"alg/monoid/min.hpp\"\n#include \"ds/segtree/segtree.hpp\"\n\n\
    // i, A[i] \u3092\u8FFD\u52A0 -> mex(A[j],...,A[i+1]) \u304C\u66F4\u65B0\n// \u3053\
    \u306E\u3068\u304D\u306E\u66F4\u65B0\u898F\u5247\u3092\u5F97\u308B\nstruct Range_Mex_Change\
    \ {\n  int N;\n  vc<int> last;\n  SegTree<Monoid_Min<int>> seg;\n  int nxt_i;\n\
    \  Range_Mex_Change(int N) : N(N), last(N + 1, -1), seg(last), nxt_i(0) {}\n\n\
    \  // F(l,r,x,y): [l,...,r) \u90E8\u5206\u304C x->y \u306B\u5909\u66F4\n  template\
    \ <typename F>\n  void add(int i, int x, F change) {\n    assert(i == nxt_i);\n\
    \    ++nxt_i;\n    chmin(x, N);\n    int p = last[x];\n    int R = (x == 0 ? i\
    \ + 1 : seg.prod(0, x) + 1);\n\n    last[x] = i;\n    seg.set(x, i);\n    while\
    \ (p + 1 < R) {\n      int y = seg.max_right([&](int v) -> bool { return v >=\
    \ R - 1; }, x + 1);\n      int L = max(p + 1, last[y] + 1);\n      change(L, R,\
    \ x, y);\n      R = L;\n    }\n  }\n};"
  dependsOn:
  - alg/monoid/min.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: ds/range_mex_change.hpp
  requiredBy: []
  timestamp: '2026-08-11 19:18:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/range_mex_change.hpp
layout: document
redirect_from:
- /library/ds/range_mex_change.hpp
- /library/ds/range_mex_change.hpp.html
title: ds/range_mex_change.hpp
---
