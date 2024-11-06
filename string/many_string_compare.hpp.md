---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':x:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1803/problem/9406
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct\
    \ SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
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
    \  }\n};\n#line 6 \"string/suffix_array.hpp\"\n\n// \u8F9E\u66F8\u9806 i \u756A\
    \u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\u59CB\u307E\u308A\u3067\u3042\u308B\
    \u3068\u304D\u3001\n// SA[i] = j, ISA[j] = i\n// |S|>0 \u3092\u524D\u63D0\uFF08\
    \u305D\u3046\u3067\u306A\u3044\u5834\u5408 dummy \u6587\u5B57\u3092\u8FFD\u52A0\
    \u3057\u3066\u5229\u7528\u305B\u3088\uFF09\ntemplate <bool USE_SPARSE_TABLE =\
    \ true>\nstruct Suffix_Array {\n  vc<int> SA;\n  vc<int> ISA;\n  vc<int> LCP;\n\
    \  using Mono = Monoid_Min<int>;\n  using SegType = conditional_t<USE_SPARSE_TABLE,\
    \ Sparse_Table<Mono>, SegTree<Mono> >;\n  SegType seg;\n  bool build_seg;\n\n\
    \  Suffix_Array() {}\n  Suffix_Array(string& s) {\n    build_seg = 0;\n    assert(len(s)\
    \ > 0);\n    char first = 127, last = 0;\n    for (auto&& c: s) {\n      chmin(first,\
    \ c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s, first, last);\n\
    \    calc_LCP(s);\n  }\n\n  Suffix_Array(vc<int>& s) {\n    build_seg = 0;\n \
    \   assert(len(s) > 0);\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\
    \n  // lcp(S[i:], S[j:])\n  int lcp(int i, int j) {\n    if (!build_seg) {\n \
    \     build_seg = true;\n      seg.build(LCP);\n    }\n    int n = len(SA);\n\
    \    if (i == n || j == n) return 0;\n    if (i == j) return n - i;\n    i = ISA[i],\
    \ j = ISA[j];\n    if (i > j) swap(i, j);\n    return seg.prod(i, j);\n  }\n\n\
    \  // S[i:] \u3068\u306E lcp \u304C n \u4EE5\u4E0A\u3067\u3042\u308B\u3088\u3046\
    \u306A\u534A\u958B\u533A\u9593\n  pair<int, int> lcp_range(int i, int n) {\n \
    \   if (!build_seg) {\n      build_seg = true;\n      seg.build(LCP);\n    }\n\
    \    i = ISA[i];\n    int a = seg.min_left([&](auto e) -> bool { return e >= n;\
    \ }, i);\n    int b = seg.max_right([&](auto e) -> bool { return e >= n; }, i);\n\
    \    return {a, b + 1};\n  }\n\n  // -1: S[L1:R1) < S[L2, R2)\n  //  0: S[L1:R1)\
    \ = S[L2, R2)\n  // +1: S[L1:R1) > S[L2, R2)\n  int compare(int L1, int R1, int\
    \ L2, int R2) {\n    int n1 = R1 - L1, n2 = R2 - L2;\n    int n = lcp(L1, L2);\n\
    \    if (n == n1 && n == n2) return 0;\n    if (n == n1) return -1;\n    if (n\
    \ == n2) return 1;\n    return (ISA[L1 + n] > ISA[L2 + n] ? 1 : -1);\n  }\n\n\
    private:\n  void induced_sort(const vc<int>& vect, int val_range, vc<int>& SA,\
    \ const vc<bool>& sl, const vc<int>& lms_idx) {\n    vc<int> l(val_range, 0),\
    \ r(val_range, 0);\n    for (int c: vect) {\n      if (c + 1 < val_range) ++l[c\
    \ + 1];\n      ++r[c];\n    }\n    partial_sum(l.begin(), l.end(), l.begin());\n\
    \    partial_sum(r.begin(), r.end(), r.begin());\n    fill(SA.begin(), SA.end(),\
    \ -1);\n    for (int i = (int)lms_idx.size() - 1; i >= 0; --i) SA[--r[vect[lms_idx[i]]]]\
    \ = lms_idx[i];\n    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    fill(r.begin(), r.end(), 0);\n    for (int c: vect) ++r[c];\n\
    \    partial_sum(r.begin(), r.end(), r.begin());\n    for (int k = (int)SA.size()\
    \ - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1 && !sl[i - 1]) { SA[--r[vect[i\
    \ - 1]]] = i - 1; }\n  }\n\n  vc<int> SA_IS(const vc<int>& vect, int val_range)\
    \ {\n    const int n = vect.size();\n    vc<int> SA(n), lms_idx;\n    vc<bool>\
    \ sl(n);\n    sl[n - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n   \
    \   sl[i] = (vect[i] > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n\
    \      if (sl[i] && !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    vc<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) { new_lms_idx[k++]\
    \ = SA[i]; }\n    int cur = 0;\n    SA[n - 1] = cur;\n    for (size_t k = 1; k\
    \ < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k - 1], j = new_lms_idx[k];\n\
    \      if (vect[i] != vect[j]) {\n        SA[j] = ++cur;\n        continue;\n\
    \      }\n      bool flag = false;\n      for (int a = i + 1, b = j + 1;; ++a,\
    \ ++b) {\n        if (vect[a] != vect[b]) {\n          flag = true;\n        \
    \  break;\n        }\n        if ((!sl[a] && sl[a - 1]) || (!sl[b] && sl[b - 1]))\
    \ {\n          flag = !((!sl[a] && sl[a - 1]) && (!sl[b] && sl[b - 1]));\n   \
    \       break;\n        }\n      }\n      SA[j] = (flag ? ++cur : cur);\n    }\n\
    \    for (size_t i = 0; i < lms_idx.size(); ++i) lms_vec[i] = SA[lms_idx[i]];\n\
    \    if (cur + 1 < (int)lms_idx.size()) {\n      auto lms_SA = SA_IS(lms_vec,\
    \ cur + 1);\n      for (size_t i = 0; i < lms_idx.size(); ++i) { new_lms_idx[i]\
    \ = lms_idx[lms_SA[i]]; }\n    }\n    induced_sort(vect, val_range, SA, sl, new_lms_idx);\n\
    \    return SA;\n  }\n\n  vc<int> calc_suffix_array(const string& s, const char\
    \ first = 'a', const char last = 'z') {\n    vc<int> vect(s.size() + 1);\n   \
    \ copy(begin(s), end(s), begin(vect));\n    for (auto& x: vect) x -= (int)first\
    \ - 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first\
    \ + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  vc<int> calc_suffix_array(const\
    \ vc<int>& s) {\n    vc<int> ss = s;\n    UNIQUE(ss);\n\n    vc<int> vect(s.size()\
    \ + 1);\n    copy(all(s), vect.begin());\n    for (auto& x: vect) x = LB(ss, x)\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, MAX(vect) + 2);\n   \
    \ ret.erase(ret.begin());\n    return ret;\n  }\n\n  template <typename STRING>\n\
    \  void calc_LCP(const STRING& s) {\n    int n = s.size(), k = 0;\n    ISA.resize(n);\n\
    \    LCP.resize(n);\n    for (int i = 0; i < n; i++) ISA[SA[i]] = i;\n    for\
    \ (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i] == n - 1) {\n     \
    \   k = 0;\n        continue;\n      }\n      int j = SA[ISA[i] + 1];\n      while\
    \ (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n      LCP[ISA[i]] = k;\n\
    \    }\n    LCP.resize(n - 1);\n  }\n};\n#line 2 \"string/many_string_compare.hpp\"\
    \n\n// https://qoj.ac/contest/1803/problem/9406\ntemplate <bool USE_SPARSE_TABLE>\n\
    struct Many_String_Compare {\n  int n;\n  string ALL;\n  vc<int> pos;\n  Suffix_Array<USE_SPARSE_TABLE>\
    \ X;\n\n  template <typename F>\n  Many_String_Compare(int n, F f) : n(n) {\n\
    \    pos = {0};\n    FOR(i, n) {\n      ALL += f(i);\n      pos.eb(len(ALL));\n\
    \    }\n    X = Suffix_Array<USE_SPARSE_TABLE>(ALL);\n  }\n\n  // S[a][la:lb),\
    \ S[b][lb:rb)\n  int lcp(int a, int la, int ra, int b, int lb, int rb) {\n   \
    \ assert(0 <= a && a < n && 0 <= b && b < n);\n    assert(0 <= la && la <= ra\
    \ && ra <= length(a));\n    assert(0 <= lb && lb <= rb && rb <= length(b));\n\
    \    int n = X.lcp(pos[a] + la, pos[b] + lb);\n    return min({n, ra - la, rb\
    \ - lb});\n  }\n\n  // [<]-1, [=]0, [>]1\n  int comp3(int a, int la, int ra, int\
    \ b, int lb, int rb) {\n    int na = ra - la, nb = rb - lb;\n    if (na > nb)\
    \ return -comp3(b, lb, rb, a, la, ra);\n    int n = lcp(a, la, ra, b, lb, rb);\n\
    \    if (n == na) { return (na == nb ? 0 : -1); }\n    return (ALL[pos[a] + la\
    \ + n] < ALL[pos[b] + lb + n] ? -1 : 1);\n  }\n\n  // [<]-1, [=]0, [>]1, (S+T)\
    \ vs (T+S)\n  int ST_TS_comp3(int a, int la, int ra, int b, int lb, int rb) {\n\
    \    int na = ra - la, nb = rb - lb;\n    if (na > nb) return -ST_TS_comp3(b,\
    \ lb, rb, a, la, ra);\n    int k = comp3(a, la, la + na, b, lb, lb + na);\n  \
    \  if (k != 0) return k;\n    k = comp3(b, lb, lb + nb - na, b, lb + na, rb);\n\
    \    if (k != 0) return k;\n    return comp3(b, lb + nb - na, rb, a, la, ra);\n\
    \  }\n\n  int length(int a) { return pos[a + 1] - pos[a]; }\n};\n"
  code: "#include \"string/suffix_array.hpp\"\n\n// https://qoj.ac/contest/1803/problem/9406\n\
    template <bool USE_SPARSE_TABLE>\nstruct Many_String_Compare {\n  int n;\n  string\
    \ ALL;\n  vc<int> pos;\n  Suffix_Array<USE_SPARSE_TABLE> X;\n\n  template <typename\
    \ F>\n  Many_String_Compare(int n, F f) : n(n) {\n    pos = {0};\n    FOR(i, n)\
    \ {\n      ALL += f(i);\n      pos.eb(len(ALL));\n    }\n    X = Suffix_Array<USE_SPARSE_TABLE>(ALL);\n\
    \  }\n\n  // S[a][la:lb), S[b][lb:rb)\n  int lcp(int a, int la, int ra, int b,\
    \ int lb, int rb) {\n    assert(0 <= a && a < n && 0 <= b && b < n);\n    assert(0\
    \ <= la && la <= ra && ra <= length(a));\n    assert(0 <= lb && lb <= rb && rb\
    \ <= length(b));\n    int n = X.lcp(pos[a] + la, pos[b] + lb);\n    return min({n,\
    \ ra - la, rb - lb});\n  }\n\n  // [<]-1, [=]0, [>]1\n  int comp3(int a, int la,\
    \ int ra, int b, int lb, int rb) {\n    int na = ra - la, nb = rb - lb;\n    if\
    \ (na > nb) return -comp3(b, lb, rb, a, la, ra);\n    int n = lcp(a, la, ra, b,\
    \ lb, rb);\n    if (n == na) { return (na == nb ? 0 : -1); }\n    return (ALL[pos[a]\
    \ + la + n] < ALL[pos[b] + lb + n] ? -1 : 1);\n  }\n\n  // [<]-1, [=]0, [>]1,\
    \ (S+T) vs (T+S)\n  int ST_TS_comp3(int a, int la, int ra, int b, int lb, int\
    \ rb) {\n    int na = ra - la, nb = rb - lb;\n    if (na > nb) return -ST_TS_comp3(b,\
    \ lb, rb, a, la, ra);\n    int k = comp3(a, la, la + na, b, lb, lb + na);\n  \
    \  if (k != 0) return k;\n    k = comp3(b, lb, lb + nb - na, b, lb + na, rb);\n\
    \    if (k != 0) return k;\n    return comp3(b, lb + nb - na, rb, a, la, ra);\n\
    \  }\n\n  int length(int a) { return pos[a + 1] - pos[a]; }\n};\n"
  dependsOn:
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: string/many_string_compare.hpp
  requiredBy: []
  timestamp: '2024-11-01 21:56:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/many_string_compare.hpp
layout: document
redirect_from:
- /library/string/many_string_compare.hpp
- /library/string/many_string_compare.hpp.html
title: string/many_string_compare.hpp
---