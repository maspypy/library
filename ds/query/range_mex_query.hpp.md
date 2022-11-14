---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree.hpp
    title: ds/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1436/problem/E
  bundledCode: "#line 1 \"ds/query/range_mex_query.hpp\"\n\r\n#line 2 \"ds/segtree.hpp\"\
    \n\ntemplate <class Monoid>\nstruct SegTree {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vector<X> dat;\n  int n, log, size;\n\n  SegTree()\
    \ : SegTree(0) {}\n  SegTree(int n) : SegTree(vector<X>(n, Monoid::unit())) {}\n\
    \  SegTree(vector<X> v) : n(v.size()) {\n    log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size\
    \ - 1; i >= 1; --i) update(i);\n  }\n\n  template <typename F>\n  SegTree(int\
    \ n, F f) : n(n) {\n    log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, Monoid::unit());\n    for (int i = 0;\
    \ i < n; ++i) dat[size + i] = f(i);\n    for (int i = size - 1; i >= 1; --i) update(i);\n\
    \  }\n\n  void reset() { fill(all(dat), Monoid::unit()); }\n\n  void set_all(const\
    \ vector<X>& v) {\n    dat.assign(size << 1, Monoid::unit());\n    for (int i\
    \ = 0; i < n; ++i) dat[size + i] = v[i];\n    for (int i = size - 1; i >= 1; --i)\
    \ update(i);\n  }\n\n  X operator[](int i) { return dat[size + i]; }\n\n  void\
    \ update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n\n  void\
    \ set(int i, const X& x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while\
    \ (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const X& x) {\n    assert(i\
    \ < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i], x);\n    while (i >>=\
    \ 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(L <= R);\n    assert(R\
    \ <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R +=\
    \ size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n\
    \      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n  \
    \  }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return dat[1]; }\n\
    \n  template <class F>\n  int max_right(F& check, int L) {\n    assert(0 <= L\
    \ && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n\
    \    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n   \
    \   if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n      \
    \    L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) {\n            sm\
    \ = Monoid::op(sm, dat[L]);\n            L++;\n          }\n        }\n      \
    \  return L - size;\n      }\n      sm = Monoid::op(sm, dat[L]);\n      L++;\n\
    \    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class F>\n  int\
    \ min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R], sm);\n\
    \            R--;\n          }\n        }\n        return R + 1 - size;\n    \
    \  }\n      sm = Monoid::op(dat[R], sm);\n    } while ((R & -R) != R);\n    return\
    \ 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001\
    prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n\
    \  X Xor_prod(int l, int r, int xor_val) {\n    assert(Monoid::commute);\n   \
    \ X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if (l\
    \ >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n\n  void debug() { print(\"segtree\", dat); }\n};\n#line 2 \"alg/monoid/min.hpp\"\
    \ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 4 \"ds/query/range_mex_query.hpp\"\n\r\n\
    // \u914D\u5217\u306F static\r\n// \u30AF\u30A8\u30EA\u3082\u5148\u8AAD\u307F\u3059\
    \u308B\r\n// example: https://codeforces.com/contest/1436/problem/E\r\ntemplate\
    \ <int BEGIN, typename T = ll>\r\nstruct RangeMexQuery {\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> query;\r\n\r\n  RangeMexQuery(vc<T>& A) : A(A) {}\r\n  void add(int l,\
    \ int r) { query.eb(l, r); }\r\n\r\n  vc<T> calc() {\r\n    int N = len(A);\r\n\
    \    // segtree, value -> last idx\r\n    using Mono = Monoid_Min<int>;\r\n  \
    \  vc<int> seg_raw(N + 2, -1);\r\n    SegTree<Mono> seg(seg_raw);\r\n\r\n    int\
    \ Q = len(query);\r\n    vc<T> ANS(Q);\r\n    vc<vc<int>> IDS(N + 1);\r\n    FOR(q,\
    \ Q) {\r\n      auto [L, R] = query[q];\r\n      IDS[R].eb(q);\r\n    }\r\n\r\n\
    \    FOR(i, N + 1) {\r\n      // solve query\r\n      for (auto&& q: IDS[i]) {\r\
    \n        int L = query[q].fi;\r\n        auto check = [&](int x) -> bool { return\
    \ x >= L; };\r\n        int mex = seg.max_right(check, BEGIN);\r\n        ANS[q]\
    \ = mex;\r\n      }\r\n      // update segtree\r\n      if (i < N && A[i] < N\
    \ + 2) seg.set(A[i], i);\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n"
  code: "\r\n#include \"ds/segtree.hpp\"\r\n#include \"alg/monoid/min.hpp\"\r\n\r\n\
    // \u914D\u5217\u306F static\r\n// \u30AF\u30A8\u30EA\u3082\u5148\u8AAD\u307F\u3059\
    \u308B\r\n// example: https://codeforces.com/contest/1436/problem/E\r\ntemplate\
    \ <int BEGIN, typename T = ll>\r\nstruct RangeMexQuery {\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> query;\r\n\r\n  RangeMexQuery(vc<T>& A) : A(A) {}\r\n  void add(int l,\
    \ int r) { query.eb(l, r); }\r\n\r\n  vc<T> calc() {\r\n    int N = len(A);\r\n\
    \    // segtree, value -> last idx\r\n    using Mono = Monoid_Min<int>;\r\n  \
    \  vc<int> seg_raw(N + 2, -1);\r\n    SegTree<Mono> seg(seg_raw);\r\n\r\n    int\
    \ Q = len(query);\r\n    vc<T> ANS(Q);\r\n    vc<vc<int>> IDS(N + 1);\r\n    FOR(q,\
    \ Q) {\r\n      auto [L, R] = query[q];\r\n      IDS[R].eb(q);\r\n    }\r\n\r\n\
    \    FOR(i, N + 1) {\r\n      // solve query\r\n      for (auto&& q: IDS[i]) {\r\
    \n        int L = query[q].fi;\r\n        auto check = [&](int x) -> bool { return\
    \ x >= L; };\r\n        int mex = seg.max_right(check, BEGIN);\r\n        ANS[q]\
    \ = mex;\r\n      }\r\n      // update segtree\r\n      if (i < N && A[i] < N\
    \ + 2) seg.set(A[i], i);\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/segtree.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: ds/query/range_mex_query.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/range_mex.test.cpp
documentation_of: ds/query/range_mex_query.hpp
layout: document
redirect_from:
- /library/ds/query/range_mex_query.hpp
- /library/ds/query/range_mex_query.hpp.html
title: ds/query/range_mex_query.hpp
---
