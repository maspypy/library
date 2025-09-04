---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: seq/cartesian_tree.hpp
    title: seq/cartesian_tree.hpp
  - icon: ':question:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1098/F
    - https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g
  bundledCode: "#line 1 \"string/suffix_tree.hpp\"\n\n#line 2 \"string/suffix_array.hpp\"\
    \n\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Min\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 2 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002disjoint sparse table\
    \ \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\nstruct Sparse_Table\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n, log;\n\
    \  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) { build(n); }\n \
    \ template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n\
    \  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m,\
    \ [](int i) -> X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i, n) dat[0][i]\
    \ = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i]) - (1 <<\
    \ i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j],\
    \ dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int L, int R) {\n  \
    \  if (L == R) return MX::unit();\n    if (R == L + 1) return dat[0][L];\n   \
    \ int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R - (1 << k)]);\n\
    \  }\n\n  template <class F>\n  int max_right(const F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(MX::unit()));\n    if (L == n) return n;\n    int ok\
    \ = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok + ng) / 2;\n\
    \      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n      if (!bl) ng\
    \ = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int min_left(const\
    \ F check, int R) {\n    assert(0 <= R && R <= n && check(MX::unit()));\n    if\
    \ (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok) {\n  \
    \    int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if (bl)\
    \ ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n#line 2 \"\
    ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type = X;\n\
    \  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n);\
    \ }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n\
    \  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m,\
    \ [](int i) -> X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n  \
    \  FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
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
    \    calc_LCP(s);\n  }\n\n  Suffix_Array(vc<int> s) {\n    build_seg = 0;\n  \
    \  assert(len(s) > 0);\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\
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
    \    }\n    LCP.resize(n - 1);\n  }\n};\n#line 2 \"seq/cartesian_tree.hpp\"\n\
    /*\r\n\u8F9E\u66F8\u9806\u3067\u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\
    \u306B\u3057\u3066\u3044\u308B\u3002\r\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\u3067\u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\r\n*/\r\
    \ntemplate <typename T, bool IS_MIN>\r\nstruct CartesianTree {\r\n  int n;\r\n\
    \  vc<T>& A;\r\n  vc<pair<int, int>> range;\r\n  vc<int> lch, rch, par;\r\n  int\
    \ root;\r\n\r\n  CartesianTree(vc<T>& A) : n(len(A)), A(A) {\r\n    range.assign(n,\
    \ {-1, -1});\r\n    lch.assign(n, -1);\r\n    rch.assign(n, -1);\r\n    par.assign(n,\
    \ -1);\r\n    if (n == 1) {\r\n      range[0] = {0, 1};\r\n      root = 0;\r\n\
    \      return;\r\n    }\r\n    auto is_sm = [&](int i, int j) -> bool {\r\n  \
    \    if (IS_MIN) return (A[i] < A[j]) || (A[i] == A[j] && i < j);\r\n      return\
    \ (A[i] > A[j]) || (A[i] == A[j] && i < j);\r\n    };\r\n    vc<int> st;\r\n \
    \   FOR(i, n) {\r\n      while (!st.empty() && is_sm(i, st.back())) {\r\n    \
    \    lch[i] = st.back();\r\n        st.pop_back();\r\n      }\r\n      range[i].fi\
    \ = (st.empty() ? 0 : st.back() + 1);\r\n      st.eb(i);\r\n    }\r\n    st.clear();\r\
    \n    FOR_R(i, n) {\r\n      while (!st.empty() && is_sm(i, st.back())) {\r\n\
    \        rch[i] = st.back();\r\n        st.pop_back();\r\n      }\r\n      range[i].se\
    \ = (st.empty() ? n : st.back());\r\n      st.eb(i);\r\n    }\r\n    FOR(i, n)\
    \ if (lch[i] != -1) par[lch[i]] = i;\r\n    FOR(i, n) if (rch[i] != -1) par[rch[i]]\
    \ = i;\r\n    FOR(i, n) if (par[i] == -1) root = i;\r\n  }\r\n\r\n  // (l, r,\
    \ h)\r\n  tuple<int, int, T> maximum_rectangle(int i) {\r\n    auto [l, r] = range[i];\r\
    \n    return {l, r, A[i]};\r\n  }\r\n\r\n  // (l, r, h)\r\n  T max_rectangle_area()\
    \ {\r\n    assert(IS_MIN);\r\n    T res = 0;\r\n    FOR(i, n) {\r\n      auto\
    \ [l, r, h] = maximum_rectangle(i);\r\n      chmax(res, (r - l) * h);\r\n    }\r\
    \n    return res;\r\n  }\r\n\r\n  ll count_subrectangle(bool baseline) {\r\n \
    \   assert(IS_MIN);\r\n    ll res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r,\
    \ h] = maximum_rectangle(i);\r\n      ll x = (baseline ? h : h * (h + 1) / 2);\r\
    \n      res += x * (i - l + 1) * (r - i);\r\n    }\r\n    return res;\r\n  }\r\
    \n};\r\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\
    \nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\
    \u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32 n) {\r\
    \n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k\
    \ - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n\
    \  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\
    \u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used),\
    \ 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) /\
    \ 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i\
    \ = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\
    \n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\
    \n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i]\
    \ = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k,\
    \ Val default_value) {\r\n    int i = index(k);\r\n    return (used[i] ? val[i]\
    \ : default_value);\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i =\
    \ index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\
    \n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\
    \n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  static constexpr\
    \ bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n    print(\"Graph\");\n    if\
    \ (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct\
    \ FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\
    \n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  int size() { return\
    \ n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n, F f) {\r\n    build(n,\
    \ f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\n    n = m;\r\n\
    \    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n      m = (m +\
    \ B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n  }\r\n  template\
    \ <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\n    FOR(i, n)\
    \ { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log - 1) {\r\n    \
    \  FOR(i, len(seg[h])) { seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\
    \ }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const { return seg[0][i /\
    \ B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    assert(0 <= i && i < n);\r\
    \n    for (int h = 0; h < log; h++) { seg[h][i / B] |= u64(1) << (i % B), i /=\
    \ B; }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n\
    \    assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0; h < log;\
    \ h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B]\
    \ |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\
    \n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int\
    \ next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int h =\
    \ 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      u64\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int g =\
    \ h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // max\
    \ [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if (i >=\
    \ n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i == -1) break;\r\
    \n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d) {\r\n        i\
    \ = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  string to_string() {\r\n    string s(n, '?');\r\n    for (int i = 0; i < n;\
    \ ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n};\n#line 6\
    \ \"string/suffix_tree.hpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\ntemplate <typename STRING, typename SUFFIX>\n\
    struct Suffix_Tree {\n  STRING& S;\n  SUFFIX& X;\n  Suffix_Tree(STRING& S, SUFFIX&\
    \ X) : S(S), X(X) {}\n\n  pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> build()\
    \ {\n    auto& SA = X.SA;\n    auto& LCP = X.LCP;\n\n    vc<tuple<int, int, int,\
    \ int>> dat;\n    vc<tuple<int, int, int>> edges;\n\n    int N = len(SA);\n  \
    \  if (N == 1) {\n      Graph<int, 1> G(2);\n      G.add(0, 1);\n      G.build();\n\
    \      dat.eb(0, 1, 0, 1), dat.eb(0, 1, 1, 2);\n      return {G, dat};\n    }\n\
    \n    dat.eb(0, N, -1, 0);\n    CartesianTree<int, true> CT(LCP);\n\n    auto\
    \ dfs = [&](auto& dfs, int p, int idx, int h) -> void {\n      int L = CT.range[idx].fi;\n\
    \      int R = CT.range[idx].se + 1;\n      int hh = LCP[idx];\n      if (h <\
    \ hh) {\n        edges.eb(p, len(dat), hh - h);\n        p = len(dat);\n     \
    \   dat.eb(L, R, h, hh);\n      }\n      if (CT.lch[idx] == -1) {\n        if\
    \ (hh < N - SA[idx]) {\n          edges.eb(p, len(dat), N - SA[idx] - hh);\n \
    \         dat.eb(idx, idx + 1, hh, N - SA[idx]);\n        }\n      } else {\n\
    \        dfs(dfs, p, CT.lch[idx], hh);\n      }\n      if (CT.rch[idx] == -1)\
    \ {\n        if (hh < N - SA[idx + 1]) {\n          edges.eb(p, len(dat), N -\
    \ SA[idx + 1] - hh);\n          dat.eb(idx + 1, idx + 2, hh, N - SA[idx + 1]);\n\
    \        }\n      } else {\n        dfs(dfs, p, CT.rch[idx], hh);\n      }\n \
    \   };\n    int r = CT.root;\n    if (LCP[r] > 0) {\n      edges.eb(0, 1, LCP[r]);\n\
    \      dat.eb(0, N, 0, LCP[r]);\n      dfs(dfs, 1, r, LCP[r]);\n    } else {\n\
    \      dfs(dfs, 0, r, 0);\n    }\n    for (auto& [a, b, c, d]: dat) ++c, ++d;\n\
    \n    Graph<int, 1> G(len(dat));\n    for (auto&& [a, b, c]: edges) G.add(a, b,\
    \ c);\n    G.build();\n    return {G, dat};\n  }\n\n  // S[i:N) \u306B\u5BFE\u5FDC\
    \u3059\u308B\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059\n  // https://codeforces.com/problemset/problem/1098/F\n\
    \  vc<int> get_suffix_positions(Graph<int, 1>& G, vc<tuple<int, int, int, int>>&\
    \ dat) {\n    int N = len(S);\n    FastSet FS(N);\n    FOR(i, N) FS.insert(i);\n\
    \    vc<int> ANS(N);\n    FOR_R(v, len(dat)) {\n      auto [a, b, c, d] = dat[v];\n\
    \      FS.enumerate(a, b, [&](int i) -> void {\n        FS.erase(i);\n       \
    \ ANS[X.SA[i]] = v;\n      });\n    }\n    return ANS;\n  }\n\n  // trie \u306E\
    \u8981\u9818\u3067\u3059\u3059\u3080\uFF08failure link \u306F\u306A\u3044\uFF09\
    \n  // (node, length)\n  // \u884C\u304D\u904E\u304E\uFF1A(-1,0)\n  pair<int,\
    \ int> next(Graph<int, 1>& G, vc<tuple<int, int, int, int>>& dat, pair<int, int>\
    \ p, int ch) {\n    auto [node, length] = p;\n    if (node == -1) return {-1,\
    \ 0};\n    auto [l, r, a, b] = dat[node];\n    if (length + 1 < b) {\n      int\
    \ i = X.SA[l];\n      // S[i:i+length]\n      if (ch != S[i + length]) return\
    \ {-1, 0};\n      return {node, length + 1};\n    }\n    for (auto& e: G[node])\
    \ {\n      int n = e.to;\n      auto [l, r, a, b] = dat[n];\n      assert(a ==\
    \ length + 1);\n      int i = X.SA[l];\n      // S[i:i+length]\n      if (ch ==\
    \ S[i + length]) return {n, length + 1};\n    }\n    return {-1, 0};\n  }\n};\n"
  code: "\n#include \"string/suffix_array.hpp\"\n#include \"seq/cartesian_tree.hpp\"\
    \n#include \"graph/base.hpp\"\n#include \"ds/fastset.hpp\"\n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\ntemplate <typename STRING, typename SUFFIX>\n\
    struct Suffix_Tree {\n  STRING& S;\n  SUFFIX& X;\n  Suffix_Tree(STRING& S, SUFFIX&\
    \ X) : S(S), X(X) {}\n\n  pair<Graph<int, 1>, vc<tuple<int, int, int, int>>> build()\
    \ {\n    auto& SA = X.SA;\n    auto& LCP = X.LCP;\n\n    vc<tuple<int, int, int,\
    \ int>> dat;\n    vc<tuple<int, int, int>> edges;\n\n    int N = len(SA);\n  \
    \  if (N == 1) {\n      Graph<int, 1> G(2);\n      G.add(0, 1);\n      G.build();\n\
    \      dat.eb(0, 1, 0, 1), dat.eb(0, 1, 1, 2);\n      return {G, dat};\n    }\n\
    \n    dat.eb(0, N, -1, 0);\n    CartesianTree<int, true> CT(LCP);\n\n    auto\
    \ dfs = [&](auto& dfs, int p, int idx, int h) -> void {\n      int L = CT.range[idx].fi;\n\
    \      int R = CT.range[idx].se + 1;\n      int hh = LCP[idx];\n      if (h <\
    \ hh) {\n        edges.eb(p, len(dat), hh - h);\n        p = len(dat);\n     \
    \   dat.eb(L, R, h, hh);\n      }\n      if (CT.lch[idx] == -1) {\n        if\
    \ (hh < N - SA[idx]) {\n          edges.eb(p, len(dat), N - SA[idx] - hh);\n \
    \         dat.eb(idx, idx + 1, hh, N - SA[idx]);\n        }\n      } else {\n\
    \        dfs(dfs, p, CT.lch[idx], hh);\n      }\n      if (CT.rch[idx] == -1)\
    \ {\n        if (hh < N - SA[idx + 1]) {\n          edges.eb(p, len(dat), N -\
    \ SA[idx + 1] - hh);\n          dat.eb(idx + 1, idx + 2, hh, N - SA[idx + 1]);\n\
    \        }\n      } else {\n        dfs(dfs, p, CT.rch[idx], hh);\n      }\n \
    \   };\n    int r = CT.root;\n    if (LCP[r] > 0) {\n      edges.eb(0, 1, LCP[r]);\n\
    \      dat.eb(0, N, 0, LCP[r]);\n      dfs(dfs, 1, r, LCP[r]);\n    } else {\n\
    \      dfs(dfs, 0, r, 0);\n    }\n    for (auto& [a, b, c, d]: dat) ++c, ++d;\n\
    \n    Graph<int, 1> G(len(dat));\n    for (auto&& [a, b, c]: edges) G.add(a, b,\
    \ c);\n    G.build();\n    return {G, dat};\n  }\n\n  // S[i:N) \u306B\u5BFE\u5FDC\
    \u3059\u308B\u30CE\u30FC\u30C9\u756A\u53F7\u3092\u8FD4\u3059\n  // https://codeforces.com/problemset/problem/1098/F\n\
    \  vc<int> get_suffix_positions(Graph<int, 1>& G, vc<tuple<int, int, int, int>>&\
    \ dat) {\n    int N = len(S);\n    FastSet FS(N);\n    FOR(i, N) FS.insert(i);\n\
    \    vc<int> ANS(N);\n    FOR_R(v, len(dat)) {\n      auto [a, b, c, d] = dat[v];\n\
    \      FS.enumerate(a, b, [&](int i) -> void {\n        FS.erase(i);\n       \
    \ ANS[X.SA[i]] = v;\n      });\n    }\n    return ANS;\n  }\n\n  // trie \u306E\
    \u8981\u9818\u3067\u3059\u3059\u3080\uFF08failure link \u306F\u306A\u3044\uFF09\
    \n  // (node, length)\n  // \u884C\u304D\u904E\u304E\uFF1A(-1,0)\n  pair<int,\
    \ int> next(Graph<int, 1>& G, vc<tuple<int, int, int, int>>& dat, pair<int, int>\
    \ p, int ch) {\n    auto [node, length] = p;\n    if (node == -1) return {-1,\
    \ 0};\n    auto [l, r, a, b] = dat[node];\n    if (length + 1 < b) {\n      int\
    \ i = X.SA[l];\n      // S[i:i+length]\n      if (ch != S[i + length]) return\
    \ {-1, 0};\n      return {node, length + 1};\n    }\n    for (auto& e: G[node])\
    \ {\n      int n = e.to;\n      auto [l, r, a, b] = dat[n];\n      assert(a ==\
    \ length + 1);\n      int i = X.SA[l];\n      // S[i:i+length]\n      if (ch ==\
    \ S[i + length]) return {n, length + 1};\n    }\n    return {-1, 0};\n  }\n};\n"
  dependsOn:
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  - ds/segtree/segtree.hpp
  - seq/cartesian_tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: string/suffix_tree.hpp
  requiredBy: []
  timestamp: '2025-05-05 21:05:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2361.test.cpp
documentation_of: string/suffix_tree.hpp
layout: document
redirect_from:
- /library/string/suffix_tree.hpp
- /library/string/suffix_tree.hpp.html
title: string/suffix_tree.hpp
---
