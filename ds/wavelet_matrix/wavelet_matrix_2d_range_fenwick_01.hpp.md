---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/856/submission/263755707
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  int n;\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) : n(n) { dat.assign((n + 63) >> 5, {0, 0});\
    \ }\n  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n  void reset()\
    \ { fill(all(dat), pair<u32, u32>{0, 0}); }\n  void build() {\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\
    \u306E 1 \u306E\u500B\u6570\n  int count(int k, bool f) {\n    auto [a, b] = dat[k\
    \ >> 5];\n    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return\
    \ (f ? ret : k - ret);\n  }\n  int count(int L, int R, bool f) { return count(R,\
    \ f) - count(L, f); }\n  string to_string() {\n    string ans;\n    FOR(i, n)\
    \ ans += '0' + (dat[i / 32].fi >> (i % 32) & 1);\n    return ans;\n  }\n};\n#line\
    \ 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\n#line 2 \"alg/monoid/add.hpp\"\n\r\
    \ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\
    \n  static constexpr X unit() { return X(0); }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using E = typename G::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n  FenwickTree(int\
    \ n) { build(n); }\n  template <typename F>\n  FenwickTree(int n, F f) {\n   \
    \ build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total = G::unit();\n  }\n\
    \  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n\
    \    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n    FOR(i, n)\
    \ { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i\
    \ & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j - 1]);\n    }\n\
    \    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total; }\n  E sum_all()\
    \ { return total; }\n  E sum(int k) { return prefix_sum(k); }\n  E prod(int k)\
    \ { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k); }\n\
    \  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for (;\
    \ k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E\
    \ sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  vc<E> get_all() {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i,\
    \ i + 1);\n    return res;\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n\
    \  void multiply(int k, E x) {\n    static_assert(G::commute);\n    total = G::op(total,\
    \ x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n\
    \  }\n\n  template <class F>\n  int max_right(const F check, int L = 0) {\n  \
    \  assert(check(G::unit()));\n    E s = G::unit();\n    int i = L;\n    // 2^k\
    \ \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n   \
    \     if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n    \
    \    if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n \
    \       if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(t)) { return k; }\n        s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n     \
    \ if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k)\
    \ - 1]);\n        if (check(t)) { i += (1 << k), s = t; }\n      }\n    }\n  \
    \  return i;\n  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check, int L = 0) {\n    assert(check(L, G::unit()));\n    E s = G::unit();\n\
    \    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]()\
    \ {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) + 1; }\n        int\
    \ k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n\
    \        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n\
    \    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n     \
    \   E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t))\
    \ { i += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\
    \u308D\u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s))\
    \ {\n      s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n\
    \    }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n \
    \   // 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\
    \u6301\u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s,\
    \ G::inverse(dat[i + (1 << k) - 1]));\n      if (!check(t)) { i += (1 << k), s\
    \ = t; }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return\
    \ max_right([&k](E x) -> bool { return x <= k; }, L);\n  }\n};\n#line 4 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\nstruct FenwickTree_01 {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n\
    \    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }\n    bit.build(n, [&](int\
    \ i) -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return bit.sum_all();\
    \ }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int k) {\n \
    \   int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k / 64] & ((u64(1) << (k\
    \ % 64)) - 1));\n    return ans;\n  }\n  int sum(int L, int R) {\n    if (L ==\
    \ 0) return prefix_sum(R);\n    int ans = 0;\n    ans -= popcnt(dat[L / 64] &\
    \ ((u64(1) << (L % 64)) - 1));\n    ans += popcnt(dat[R / 64] & ((u64(1) << (R\
    \ % 64)) - 1));\n    ans += bit.sum(L / 64, R / 64);\n    return ans;\n  }\n\n\
    \  void add(int k, int x) {\n    if (x == 1) add(k);\n    if (x == -1) remove(k);\n\
    \  }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k\
    \ / 64, 1);\n  }\n  void remove(int k) {\n    dat[k / 64] &= ~(u64(1) << (k %\
    \ 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int k, int L = 0) {\n    if\
    \ (k >= sum_all()) return N;\n    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64))\
    \ - 1));\n    L /= 64;\n    int mid = 0;\n    auto check = [&](auto e) -> bool\
    \ {\n      if (e <= k) chmax(mid, e);\n      return e <= k;\n    };\n    int idx\
    \ = bit.max_right(check, L);\n    if (idx == n) return N;\n    k -= mid;\n   \
    \ u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p <= k) return N;\n    k\
    \ = binary_search([&](int n) -> bool { return (p - popcnt(x >> n)) <= k; },\n\
    \                      0, 64, 0);\n    return 64 * idx + k;\n  }\n\n  int next(int\
    \ k) {\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx] & ~((u64(1)\
    \ << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx\
    \ + 1);\n    if (idx == n || !dat[idx]) return N;\n    return 64 * idx + lowbit(dat[idx]);\n\
    \  }\n\n  int prev(int k) {\n    if (k == N) --k;\n    int idx = k / 64;\n   \
    \ k %= 64;\n    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1)) -\
    \ 1;\n    if (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto\
    \ e) -> bool { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n  \
    \  return 64 * idx + topbit(dat[idx]);\n  }\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix_2d_range_fenwick_01.hpp\"\
    \n\n// https://codeforces.com/contest/856/submission/263755707\ntemplate <typename\
    \ XY, bool SMALL_X, bool SMALL_Y>\nstruct Wavelet_Matrix_2D_Range_Fenwick_01 {\n\
    \  // \u70B9\u7FA4\u3092 Y \u6607\u9806\u306B\u4E26\u3079\u308B.\n  // X \u3092\
    \u6574\u6570\u306B\u306A\u304A\u3057\u3066 binary trie \u307F\u305F\u3044\u306B\
    \u632F\u308A\u5206\u3051\u308B\n  template <bool SMALL>\n  struct TO_IDX {\n \
    \   vc<XY> key;\n    XY mi, ma;\n    vc<int> dat;\n\n    void build(vc<XY>& X)\
    \ {\n      if constexpr (SMALL) {\n        mi = (X.empty() ? 0 : MIN(X));\n  \
    \      ma = (X.empty() ? 0 : MAX(X));\n        dat.assign(ma - mi + 2, 0);\n \
    \       for (auto& x: X) { dat[x - mi + 1]++; }\n        FOR(i, len(dat) - 1)\
    \ dat[i + 1] += dat[i];\n      } else {\n        key = X;\n        sort(all(key));\n\
    \      }\n    }\n    int operator()(XY x) {\n      if constexpr (SMALL) {\n  \
    \      return dat[clamp<XY>(x - mi, 0, ma - mi + 1)];\n      } else {\n      \
    \  return LB(key, x);\n      }\n    }\n  };\n\n  TO_IDX<SMALL_X> XtoI;\n  TO_IDX<SMALL_Y>\
    \ YtoI;\n\n  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vc<int>\
    \ new_idx;\n  vc<int> A;\n  // \u5404\u6BB5\u306B fenwick tree\n  vc<FenwickTree_01>\
    \ dat;\n\n  template <typename F>\n  Wavelet_Matrix_2D_Range_Fenwick_01(int N,\
    \ F f) {\n    build(N, f);\n  }\n\n  template <typename F>\n  void build(int N_,\
    \ F f) {\n    N = N_;\n    if (N == 0) {\n      lg = 0;\n      return;\n    }\n\
    \    vc<XY> tmp(N), Y(N);\n    vc<bool> S(N);\n    FOR(i, N) {\n      tuple<XY,\
    \ XY, bool> t = f(i);\n      tmp[i] = get<0>(t), Y[i] = get<1>(t), S[i] = get<2>(t);\n\
    \    }\n    auto I = argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y,\
    \ I), S = rearrange(S, I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n\
    \    FOR(i, N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\
    \n    lg = __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n\n\
    \    vc<XY> A0(N), A1(N);\n    vc<bool> S0(N), S1(N);\n    FOR_R(d, lg) {\n  \
    \    int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> bool {\
    \ return S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1 = XtoI(x1), x2\
    \ = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return count_inner(y1, y2,\
    \ x2) - count_inner(y1, y2, x1);\n  }\n\n  int prod(XY x1, XY x2, XY y1, XY y2)\
    \ { return sum(x1, x2, y1, y2); }\n  int sum(XY x1, XY x2, XY y1, XY y2) {\n \
    \   if (N == 0) return 0;\n    assert(x1 <= x2 && y1 <= y2);\n    x1 = XtoI(x1),\
    \ x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    int add = sum_inner(y1,\
    \ y2, x2);\n    int sub = sum_inner(y1, y2, x1);\n    return add - sub;\n  }\n\
    \n  int prefix_prod(XY x, XY y) { return prefix_sum(x, y); }\n  int prefix_sum(XY\
    \ x, XY y) {\n    if (N == 0) return 0;\n    return sum_inner(0, YtoI(y), XtoI(x));\n\
    \  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void\
    \ add(int i, int x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n   \
    \ int a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d]\
    \ + bv[d].count(i, 1);\n      } else {\n        i = bv[d].count(i, 0);\n     \
    \ }\n      dat[d].add(i, x);\n    }\n  }\n\nprivate:\n  int count_inner(int L,\
    \ int R, int x) {\n    int cnt = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0,\
    \ L += mid[d] - l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n\
    \      }\n    }\n    return cnt;\n  }\n\n  int sum_inner(int L, int R, int x)\
    \ {\n    if (x == 0) return 0;\n    int sm = 0;\n    FOR_R(d, lg) {\n      int\
    \ l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\n      if (x >> d & 1) {\n \
    \       sm += dat[d].sum(l0, r0);\n        L += mid[d] - l0, R += mid[d] - r0;\n\
    \      } else {\n        L = l0, R = r0;\n      }\n    }\n    return sm;\n  }\n\
    };\n"
  code: "#include \"ds/bit_vector.hpp\"\n#include \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\n// https://codeforces.com/contest/856/submission/263755707\ntemplate <typename\
    \ XY, bool SMALL_X, bool SMALL_Y>\nstruct Wavelet_Matrix_2D_Range_Fenwick_01 {\n\
    \  // \u70B9\u7FA4\u3092 Y \u6607\u9806\u306B\u4E26\u3079\u308B.\n  // X \u3092\
    \u6574\u6570\u306B\u306A\u304A\u3057\u3066 binary trie \u307F\u305F\u3044\u306B\
    \u632F\u308A\u5206\u3051\u308B\n  template <bool SMALL>\n  struct TO_IDX {\n \
    \   vc<XY> key;\n    XY mi, ma;\n    vc<int> dat;\n\n    void build(vc<XY>& X)\
    \ {\n      if constexpr (SMALL) {\n        mi = (X.empty() ? 0 : MIN(X));\n  \
    \      ma = (X.empty() ? 0 : MAX(X));\n        dat.assign(ma - mi + 2, 0);\n \
    \       for (auto& x: X) { dat[x - mi + 1]++; }\n        FOR(i, len(dat) - 1)\
    \ dat[i + 1] += dat[i];\n      } else {\n        key = X;\n        sort(all(key));\n\
    \      }\n    }\n    int operator()(XY x) {\n      if constexpr (SMALL) {\n  \
    \      return dat[clamp<XY>(x - mi, 0, ma - mi + 1)];\n      } else {\n      \
    \  return LB(key, x);\n      }\n    }\n  };\n\n  TO_IDX<SMALL_X> XtoI;\n  TO_IDX<SMALL_Y>\
    \ YtoI;\n\n  int N, lg;\n  vector<int> mid;\n  vector<Bit_Vector> bv;\n  vc<int>\
    \ new_idx;\n  vc<int> A;\n  // \u5404\u6BB5\u306B fenwick tree\n  vc<FenwickTree_01>\
    \ dat;\n\n  template <typename F>\n  Wavelet_Matrix_2D_Range_Fenwick_01(int N,\
    \ F f) {\n    build(N, f);\n  }\n\n  template <typename F>\n  void build(int N_,\
    \ F f) {\n    N = N_;\n    if (N == 0) {\n      lg = 0;\n      return;\n    }\n\
    \    vc<XY> tmp(N), Y(N);\n    vc<bool> S(N);\n    FOR(i, N) {\n      tuple<XY,\
    \ XY, bool> t = f(i);\n      tmp[i] = get<0>(t), Y[i] = get<1>(t), S[i] = get<2>(t);\n\
    \    }\n    auto I = argsort(Y);\n    tmp = rearrange(tmp, I), Y = rearrange(Y,\
    \ I), S = rearrange(S, I);\n    XtoI.build(tmp), YtoI.build(Y);\n    new_idx.resize(N);\n\
    \    FOR(i, N) new_idx[I[i]] = i;\n\n    // \u3042\u3068\u306F\u666E\u901A\u306B\
    \n    lg = __lg(XtoI(MAX(tmp) + 1)) + 1;\n    mid.resize(lg), bv.assign(lg, Bit_Vector(N));\n\
    \    dat.resize(lg);\n    A.resize(N);\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n\n\
    \    vc<XY> A0(N), A1(N);\n    vc<bool> S0(N), S1(N);\n    FOR_R(d, lg) {\n  \
    \    int p0 = 0, p1 = 0;\n      FOR(i, N) {\n        bool f = (A[i] >> d & 1);\n\
    \        if (!f) { S0[p0] = S[i], A0[p0] = A[i], p0++; }\n        if (f) { S1[p1]\
    \ = S[i], A1[p1] = A[i], bv[d].set(i), p1++; }\n      }\n      mid[d] = p0;\n\
    \      bv[d].build();\n      swap(A, A0), swap(S, S0);\n      FOR(i, p1) A[p0\
    \ + i] = A1[i], S[p0 + i] = S1[i];\n      dat[d].build(N, [&](int i) -> bool {\
    \ return S[i]; });\n    }\n    FOR(i, N) A[i] = XtoI(tmp[i]);\n  }\n\n  int count(XY\
    \ x1, XY x2, XY y1, XY y2) {\n    if (N == 0) return 0;\n    x1 = XtoI(x1), x2\
    \ = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    return count_inner(y1, y2,\
    \ x2) - count_inner(y1, y2, x1);\n  }\n\n  int prod(XY x1, XY x2, XY y1, XY y2)\
    \ { return sum(x1, x2, y1, y2); }\n  int sum(XY x1, XY x2, XY y1, XY y2) {\n \
    \   if (N == 0) return 0;\n    assert(x1 <= x2 && y1 <= y2);\n    x1 = XtoI(x1),\
    \ x2 = XtoI(x2);\n    y1 = YtoI(y1), y2 = YtoI(y2);\n    int add = sum_inner(y1,\
    \ y2, x2);\n    int sub = sum_inner(y1, y2, x1);\n    return add - sub;\n  }\n\
    \n  int prefix_prod(XY x, XY y) { return prefix_sum(x, y); }\n  int prefix_sum(XY\
    \ x, XY y) {\n    if (N == 0) return 0;\n    return sum_inner(0, YtoI(y), XtoI(x));\n\
    \  }\n\n  // \u6700\u521D\u306B\u4E0E\u3048\u305F\u70B9\u7FA4\u306E index\n  void\
    \ add(int i, int x) {\n    assert(0 <= i && i < N);\n    i = new_idx[i];\n   \
    \ int a = A[i];\n    FOR_R(d, lg) {\n      if (a >> d & 1) {\n        i = mid[d]\
    \ + bv[d].count(i, 1);\n      } else {\n        i = bv[d].count(i, 0);\n     \
    \ }\n      dat[d].add(i, x);\n    }\n  }\n\nprivate:\n  int count_inner(int L,\
    \ int R, int x) {\n    int cnt = 0;\n    FOR_R(d, lg) {\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\n      if (x >> d & 1) {\n        cnt += r0 - l0,\
    \ L += mid[d] - l0, R += mid[d] - r0;\n      } else {\n        L = l0, R = r0;\n\
    \      }\n    }\n    return cnt;\n  }\n\n  int sum_inner(int L, int R, int x)\
    \ {\n    if (x == 0) return 0;\n    int sm = 0;\n    FOR_R(d, lg) {\n      int\
    \ l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\n      if (x >> d & 1) {\n \
    \       sm += dat[d].sum(l0, r0);\n        L += mid[d] - l0, R += mid[d] - r0;\n\
    \      } else {\n        L = l0, R = r0;\n      }\n    }\n    return sm;\n  }\n\
    };\n"
  dependsOn:
  - ds/bit_vector.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/wavelet_matrix/wavelet_matrix_2d_range_fenwick_01.hpp
  requiredBy: []
  timestamp: '2024-07-18 19:11:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/wavelet_matrix/wavelet_matrix_2d_range_fenwick_01.hpp
layout: document
redirect_from:
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_fenwick_01.hpp
- /library/ds/wavelet_matrix/wavelet_matrix_2d_range_fenwick_01.hpp.html
title: ds/wavelet_matrix/wavelet_matrix_2d_range_fenwick_01.hpp
---
