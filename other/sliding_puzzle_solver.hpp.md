---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':x:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':x:'
    path: linalg/transpose.hpp
    title: linalg/transpose.hpp
  - icon: ':x:'
    path: seq/inversion.hpp
    title: seq/inversion.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/transpose.hpp\"\ntemplate <typename VC>\nvc<VC> transpose(const\
    \ vc<VC>& A, int H = -1, int W = -1) {\n  if (H == -1) { H = len(A), W = (len(A)\
    \ == 0 ? 0 : len(A[0])); }\n  if (H == 0) return {};\n  vc<VC> B(W, VC(H, A[0][0]));\n\
    \  FOR(x, H) FOR(y, W) B[y][x] = A[x][y];\n  return B;\n}\n#line 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int\
    \ k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    assert(k < sum_all());\n    return\
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
    \  return 64 * idx + topbit(dat[idx]);\n  }\n};\n#line 3 \"seq/inversion.hpp\"\
    \n\ntemplate <typename T>\nll inversion(vc<T> A) {\n  int N = len(A);\n  if (A.empty())\
    \ return 0;\n  ll ANS = 0;\n  FenwickTree_01 bit(N);\n  auto I = argsort(A);\n\
    \  for (auto& i: I) {\n    ANS += bit.sum_all() - bit.sum(i);\n    bit.add(i,\
    \ 1);\n  }\n  return ANS;\n}\n\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\
    \u306A\u308B\u3088\u3046\u306B rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\
    \u6570\ntemplate <typename T, bool SMALL = false>\nvi inversion_rotate(vc<T>&\
    \ A) {\n  const int N = len(A);\n  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n\
    \    for (auto&& x: A) x = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS =\
    \ 0;\n  FenwickTree<Monoid_Add<int>> bit(K);\n  for (auto&& x: A) {\n    ANS +=\
    \ bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n \
    \   res[i] = ANS;\n    ll x = A[i];\n    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);\n\
    \  }\n  return res;\n}\n\n// inv[i][j] = inversion A[i:j) \u3067\u3042\u308B\u3088\
    \u3046\u306A (N+1, N+1) \u30C6\u30FC\u30D6\u30EB\ntemplate <typename T>\nvvc<int>\
    \ all_range_inversion(vc<T>& A) {\n  int N = len(A);\n  vv(int, dp, N + 1, N +\
    \ 1);\n  FOR_R(L, N + 1) FOR(R, L + 2, N + 1) {\n    dp[L][R] = dp[L][R - 1] +\
    \ dp[L + 1][R] - dp[L + 1][R - 1];\n    if (A[L] > A[R - 1]) ++dp[L][R];\n  }\n\
    \  return dp;\n}\n\ntemplate <typename T>\nll inversion_between(vc<T> A, vc<T>\
    \ B) {\n  int N = len(A);\n  map<T, vc<int>> MP;\n  FOR(i, N) MP[B[i]].eb(i);\n\
    \  vc<int> TO(N);\n  FOR_R(i, N) {\n    auto& I = MP[A[i]];\n    if (I.empty())\
    \ return -1;\n    TO[i] = POP(I);\n  }\n  return inversion(TO);\n}\n#line 3 \"\
    other/sliding_puzzle_solver.hpp\"\n\n/*\nO(HW(H+W))\n\u7A7A\u30DE\u30B9\u306F\
    \ -1 (unique)\n\u540C\u3058\u5024\u304C\u8907\u6570\u3042\u3063\u3066\u3082\u3088\
    \u3044\n\u64CD\u4F5C\u56DE\u6570\u3092 K \u3068\u3057\u3066\u3001\u9577\u3055\
    \ K+1 \u306E\u7A7A\u30DE\u30B9\u306E\u5EA7\u6A19\u5217\u3092\u304B\u3048\u3059\
    \n*/\nstruct Slinding_Puzzle_Solver {\n  using P = pair<int, int>;\n  vc<P> solve(vvc<int>\
    \ A, vvc<int> B) {\n    int H = len(A), W = len(A[0]);\n    auto find = [&](vvc<int>&\
    \ A, int k) -> P {\n      FOR(x, H) FOR(y, W) if (A[x][y] == k) return {x, y};\n\
    \      assert(0);\n      return {0, 0};\n    };\n    auto [ax, ay] = find(A, -1);\n\
    \    auto [bx, by] = find(B, -1);\n    vc<P> ANS_1, ANS_2;\n    while (ax > 0)\
    \ { ANS_1.eb(ax, ay), swap(A[ax][ay], A[ax - 1][ay]), --ax; }\n    while (ay >\
    \ 0) { ANS_1.eb(ax, ay), swap(A[ax][ay], A[ax][ay - 1]), --ay; }\n    while (bx\
    \ > 0) { ANS_2.eb(bx, by), swap(B[bx][by], B[bx - 1][by]), --bx; }\n    while\
    \ (by > 0) { ANS_2.eb(bx, by), swap(B[bx][by], B[bx][by - 1]), --by; }\n    vc<P>\
    \ ANS = solve_00(A, B);\n    if (ANS.empty()) return {};\n    reverse(all(ANS_2));\n\
    \    return concat(ANS_1, ANS, ANS_2);\n  }\n\nprivate:\n  vc<P> solve_00(vvc<int>\
    \ A, vvc<int> B) {\n    assert(A[0][0] == -1 && B[0][0] == -1);\n    int H = len(A),\
    \ W = len(A[0]);\n    if (H == 1 || W == 1) {\n      if (A != B) return {};\n\
    \      vc<P> ANS;\n      ANS.eb(0, 0);\n      return ANS;\n    }\n    vc<P> XYA,\
    \ XYB;\n    FOR(x, H) FOR(y, W) XYA.eb(x, y), XYB.eb(x, y);\n    sort(all(XYA),\
    \ [&](auto& a, auto& b) -> bool { return A[a.fi][a.se] < A[b.fi][b.se]; });\n\
    \    sort(all(XYB), [&](auto& a, auto& b) -> bool { return B[a.fi][a.se] < B[b.fi][b.se];\
    \ });\n    auto check = [&]() -> bool {\n      vc<int> S, T;\n      FOR(i, H *\
    \ W) {\n        auto [x1, y1] = XYA[i];\n        auto [x2, y2] = XYB[i];\n   \
    \     if (A[x1][y1] != B[x2][y2]) return 0;\n        S.eb(W * x1 + y1);\n    \
    \    T.eb(W * x2 + y2);\n      }\n      ll x = inversion_between(S, T);\n    \
    \  return x % 2 == 0;\n    };\n    if (!check()) {\n      FOR(i, H * W - 1) {\n\
    \        auto [x1, y1] = XYA[i];\n        auto [x2, y2] = XYA[i + 1];\n      \
    \  if (A[x1][y1] != A[x2][y2]) continue;\n        swap(XYA[i], XYA[i + 1]);\n\
    \        break;\n      }\n      if (!check()) return {};\n    }\n    vv(P, X,\
    \ H, W);\n    FOR(i, H * W) {\n      auto [x1, y1] = XYA[i];\n      auto [x2,\
    \ y2] = XYB[i];\n      X[x1][y1] = {x2, y2};\n    }\n    vc<P> ANS;\n    ANS.eb(0,\
    \ 0);\n    solve_sort(X, ANS, false);\n    return ANS;\n  }\n\n  // \u79FB\u52D5\
    \u5148\u306E\u5EA7\u6A19\u306E\u5217\u3092\u4E26\u3079\u305F\u30B0\u30EA\u30C3\
    \u30C9\u3092\u4E0E\u3048\u308B.\n  // (0,0) \u304C\u7A7A\u30DE\u30B9\n  void solve_sort(vvc<pair<int,\
    \ int>>& A, vc<P>& ANS, bool tr) {\n    int H = len(A), W = len(A[0]);\n    vv(P,\
    \ pos, H, W);\n    FOR(x, H) FOR(y, W) {\n      P p = A[x][y];\n      pos[p.fi][p.se]\
    \ = {x, y};\n    }\n\n    auto [px, py] = pos[0][0];\n\n    auto ope = [&](int\
    \ x, int y) -> void {\n      assert(abs(px - x) + abs(py - y) == 1);\n      swap(A[px][py],\
    \ A[x][y]);\n      if (!tr) ANS.eb(x, y);\n      if (tr) ANS.eb(y, x);\n     \
    \ pos[A[px][py].fi][A[px][py].se] = {px, py};\n      px = x, py = y;\n      pos[A[px][py].fi][A[px][py].se]\
    \ = {px, py};\n    };\n    if (H == 2 && W == 2) {\n      auto check = [&]() ->\
    \ bool {\n        FOR(x, H) FOR(y, W) if (A[x][y].fi != x || A[x][y].se != y)\
    \ return 0;\n        return 1;\n      };\n      while (!check()) {\n        if\
    \ (px == 0 && py == 0) ope(1, 0);\n        if (px == 1 && py == 0) ope(1, 1);\n\
    \        if (px == 1 && py == 1) ope(0, 1);\n        if (px == 0 && py == 1) ope(0,\
    \ 0);\n      }\n      return;\n    }\n    if (H < W) {\n      FOR(x, H) FOR(y,\
    \ W) { swap(A[x][y].fi, A[x][y].se); }\n      A = transpose(A, H, W);\n      solve_sort(A,\
    \ ANS, !tr);\n      return;\n    }\n    assert(H >= 3 && W >= 2);\n    // \u6700\
    \u5F8C\u306E\u884C\u3092\u305D\u308D\u3048\u308B\n    FOR_R(y, 1, W) {\n     \
    \ auto& [tx, ty] = pos[H - 1][y];\n      if (px == H - 1) ope(px - 1, py);\n \
    \     while (px - 1 > tx) ope(px - 1, py), tie(tx, ty) = pos[H - 1][y];\n    \
    \  while (px + 1 < tx) ope(px + 1, py), tie(tx, ty) = pos[H - 1][y];\n      if\
    \ (px == tx) {\n        if (px == 0)\n          ope(px + 1, py);\n        else\n\
    \          ope(px - 1, py);\n      }\n      assert(abs(px - tx) == 1);\n     \
    \ while (py < ty) ope(px, py + 1);\n      while (py > ty) ope(px, py - 1);\n \
    \     if (px == tx + 1) ope(px - 1, py), tie(tx, ty) = pos[H - 1][y];\n      assert(px\
    \ == tx - 1 && py == ty);\n      while (ty < y) { ope(px, py + 1), ope(px + 1,\
    \ py), ope(px, py - 1), ope(px - 1, py), ope(px, py + 1); }\n      while (ty >\
    \ y) { ope(px, py - 1), ope(px + 1, py), ope(px, py + 1), ope(px - 1, py), ope(px,\
    \ py - 1); }\n      tie(tx, ty) = pos[H - 1][y];\n      while (tx < H - 1) {\n\
    \        ope(px, py - 1), ope(px + 1, py), ope(px + 1, py), ope(px, py + 1), ope(px\
    \ - 1, py);\n        tie(tx, ty) = pos[H - 1][y];\n      }\n      assert(A[H -\
    \ 1][y] == (pair<int, int>{H - 1, y}));\n    }\n    auto& [tx, ty] = pos[H - 1][0];\n\
    \    if (px == H - 1) ope(px - 1, py);\n    while (px - 1 > tx) ope(px - 1, py),\
    \ tie(tx, ty) = pos[H - 1][0];\n    while (px + 1 < tx) ope(px + 1, py), tie(tx,\
    \ ty) = pos[H - 1][0];\n    if (px == tx) {\n      if (px == 0)\n        ope(px\
    \ + 1, py);\n      else\n        ope(px - 1, py);\n    }\n    tie(tx, ty) = pos[H\
    \ - 1][0];\n    assert(abs(px - tx) == 1);\n    while (py < ty) ope(px, py + 1);\n\
    \    while (py > ty) ope(px, py - 1);\n    if (px == tx + 1) ope(px - 1, py);\n\
    \    tie(tx, ty) = pos[H - 1][0];\n    if (tx < H - 1) {\n      assert(px == tx\
    \ - 1 && py == ty);\n      while (ty > 0) { ope(px, py - 1), ope(px + 1, py),\
    \ ope(px, py + 1), ope(px - 1, py), ope(px, py - 1); }\n      tie(tx, ty) = pos[H\
    \ - 1][0];\n      while (tx < H - 2) { ope(px, py + 1), ope(px + 1, py), ope(px\
    \ + 1, py), ope(px, py - 1), ope(px - 1, py); }\n      ope(px + 1, py), ope(px\
    \ + 1, py), ope(px, py + 1);\n      ope(px - 1, py), ope(px, py - 1), ope(px -\
    \ 1, py);\n      ope(px, py + 1), ope(px + 1, py), ope(px + 1, py);\n      ope(px,\
    \ py - 1), ope(px - 1, py);\n    }\n    FOR(y, W) assert(A[H - 1][y] == (pair<int,\
    \ int>{H - 1, y}));\n    POP(A);\n    solve_sort(A, ANS, tr);\n  }\n};\n"
  code: "#include \"linalg/transpose.hpp\"\n#include \"seq/inversion.hpp\"\n\n/*\n\
    O(HW(H+W))\n\u7A7A\u30DE\u30B9\u306F -1 (unique)\n\u540C\u3058\u5024\u304C\u8907\
    \u6570\u3042\u3063\u3066\u3082\u3088\u3044\n\u64CD\u4F5C\u56DE\u6570\u3092 K \u3068\
    \u3057\u3066\u3001\u9577\u3055 K+1 \u306E\u7A7A\u30DE\u30B9\u306E\u5EA7\u6A19\u5217\
    \u3092\u304B\u3048\u3059\n*/\nstruct Slinding_Puzzle_Solver {\n  using P = pair<int,\
    \ int>;\n  vc<P> solve(vvc<int> A, vvc<int> B) {\n    int H = len(A), W = len(A[0]);\n\
    \    auto find = [&](vvc<int>& A, int k) -> P {\n      FOR(x, H) FOR(y, W) if\
    \ (A[x][y] == k) return {x, y};\n      assert(0);\n      return {0, 0};\n    };\n\
    \    auto [ax, ay] = find(A, -1);\n    auto [bx, by] = find(B, -1);\n    vc<P>\
    \ ANS_1, ANS_2;\n    while (ax > 0) { ANS_1.eb(ax, ay), swap(A[ax][ay], A[ax -\
    \ 1][ay]), --ax; }\n    while (ay > 0) { ANS_1.eb(ax, ay), swap(A[ax][ay], A[ax][ay\
    \ - 1]), --ay; }\n    while (bx > 0) { ANS_2.eb(bx, by), swap(B[bx][by], B[bx\
    \ - 1][by]), --bx; }\n    while (by > 0) { ANS_2.eb(bx, by), swap(B[bx][by], B[bx][by\
    \ - 1]), --by; }\n    vc<P> ANS = solve_00(A, B);\n    if (ANS.empty()) return\
    \ {};\n    reverse(all(ANS_2));\n    return concat(ANS_1, ANS, ANS_2);\n  }\n\n\
    private:\n  vc<P> solve_00(vvc<int> A, vvc<int> B) {\n    assert(A[0][0] == -1\
    \ && B[0][0] == -1);\n    int H = len(A), W = len(A[0]);\n    if (H == 1 || W\
    \ == 1) {\n      if (A != B) return {};\n      vc<P> ANS;\n      ANS.eb(0, 0);\n\
    \      return ANS;\n    }\n    vc<P> XYA, XYB;\n    FOR(x, H) FOR(y, W) XYA.eb(x,\
    \ y), XYB.eb(x, y);\n    sort(all(XYA), [&](auto& a, auto& b) -> bool { return\
    \ A[a.fi][a.se] < A[b.fi][b.se]; });\n    sort(all(XYB), [&](auto& a, auto& b)\
    \ -> bool { return B[a.fi][a.se] < B[b.fi][b.se]; });\n    auto check = [&]()\
    \ -> bool {\n      vc<int> S, T;\n      FOR(i, H * W) {\n        auto [x1, y1]\
    \ = XYA[i];\n        auto [x2, y2] = XYB[i];\n        if (A[x1][y1] != B[x2][y2])\
    \ return 0;\n        S.eb(W * x1 + y1);\n        T.eb(W * x2 + y2);\n      }\n\
    \      ll x = inversion_between(S, T);\n      return x % 2 == 0;\n    };\n   \
    \ if (!check()) {\n      FOR(i, H * W - 1) {\n        auto [x1, y1] = XYA[i];\n\
    \        auto [x2, y2] = XYA[i + 1];\n        if (A[x1][y1] != A[x2][y2]) continue;\n\
    \        swap(XYA[i], XYA[i + 1]);\n        break;\n      }\n      if (!check())\
    \ return {};\n    }\n    vv(P, X, H, W);\n    FOR(i, H * W) {\n      auto [x1,\
    \ y1] = XYA[i];\n      auto [x2, y2] = XYB[i];\n      X[x1][y1] = {x2, y2};\n\
    \    }\n    vc<P> ANS;\n    ANS.eb(0, 0);\n    solve_sort(X, ANS, false);\n  \
    \  return ANS;\n  }\n\n  // \u79FB\u52D5\u5148\u306E\u5EA7\u6A19\u306E\u5217\u3092\
    \u4E26\u3079\u305F\u30B0\u30EA\u30C3\u30C9\u3092\u4E0E\u3048\u308B.\n  // (0,0)\
    \ \u304C\u7A7A\u30DE\u30B9\n  void solve_sort(vvc<pair<int, int>>& A, vc<P>& ANS,\
    \ bool tr) {\n    int H = len(A), W = len(A[0]);\n    vv(P, pos, H, W);\n    FOR(x,\
    \ H) FOR(y, W) {\n      P p = A[x][y];\n      pos[p.fi][p.se] = {x, y};\n    }\n\
    \n    auto [px, py] = pos[0][0];\n\n    auto ope = [&](int x, int y) -> void {\n\
    \      assert(abs(px - x) + abs(py - y) == 1);\n      swap(A[px][py], A[x][y]);\n\
    \      if (!tr) ANS.eb(x, y);\n      if (tr) ANS.eb(y, x);\n      pos[A[px][py].fi][A[px][py].se]\
    \ = {px, py};\n      px = x, py = y;\n      pos[A[px][py].fi][A[px][py].se] =\
    \ {px, py};\n    };\n    if (H == 2 && W == 2) {\n      auto check = [&]() ->\
    \ bool {\n        FOR(x, H) FOR(y, W) if (A[x][y].fi != x || A[x][y].se != y)\
    \ return 0;\n        return 1;\n      };\n      while (!check()) {\n        if\
    \ (px == 0 && py == 0) ope(1, 0);\n        if (px == 1 && py == 0) ope(1, 1);\n\
    \        if (px == 1 && py == 1) ope(0, 1);\n        if (px == 0 && py == 1) ope(0,\
    \ 0);\n      }\n      return;\n    }\n    if (H < W) {\n      FOR(x, H) FOR(y,\
    \ W) { swap(A[x][y].fi, A[x][y].se); }\n      A = transpose(A, H, W);\n      solve_sort(A,\
    \ ANS, !tr);\n      return;\n    }\n    assert(H >= 3 && W >= 2);\n    // \u6700\
    \u5F8C\u306E\u884C\u3092\u305D\u308D\u3048\u308B\n    FOR_R(y, 1, W) {\n     \
    \ auto& [tx, ty] = pos[H - 1][y];\n      if (px == H - 1) ope(px - 1, py);\n \
    \     while (px - 1 > tx) ope(px - 1, py), tie(tx, ty) = pos[H - 1][y];\n    \
    \  while (px + 1 < tx) ope(px + 1, py), tie(tx, ty) = pos[H - 1][y];\n      if\
    \ (px == tx) {\n        if (px == 0)\n          ope(px + 1, py);\n        else\n\
    \          ope(px - 1, py);\n      }\n      assert(abs(px - tx) == 1);\n     \
    \ while (py < ty) ope(px, py + 1);\n      while (py > ty) ope(px, py - 1);\n \
    \     if (px == tx + 1) ope(px - 1, py), tie(tx, ty) = pos[H - 1][y];\n      assert(px\
    \ == tx - 1 && py == ty);\n      while (ty < y) { ope(px, py + 1), ope(px + 1,\
    \ py), ope(px, py - 1), ope(px - 1, py), ope(px, py + 1); }\n      while (ty >\
    \ y) { ope(px, py - 1), ope(px + 1, py), ope(px, py + 1), ope(px - 1, py), ope(px,\
    \ py - 1); }\n      tie(tx, ty) = pos[H - 1][y];\n      while (tx < H - 1) {\n\
    \        ope(px, py - 1), ope(px + 1, py), ope(px + 1, py), ope(px, py + 1), ope(px\
    \ - 1, py);\n        tie(tx, ty) = pos[H - 1][y];\n      }\n      assert(A[H -\
    \ 1][y] == (pair<int, int>{H - 1, y}));\n    }\n    auto& [tx, ty] = pos[H - 1][0];\n\
    \    if (px == H - 1) ope(px - 1, py);\n    while (px - 1 > tx) ope(px - 1, py),\
    \ tie(tx, ty) = pos[H - 1][0];\n    while (px + 1 < tx) ope(px + 1, py), tie(tx,\
    \ ty) = pos[H - 1][0];\n    if (px == tx) {\n      if (px == 0)\n        ope(px\
    \ + 1, py);\n      else\n        ope(px - 1, py);\n    }\n    tie(tx, ty) = pos[H\
    \ - 1][0];\n    assert(abs(px - tx) == 1);\n    while (py < ty) ope(px, py + 1);\n\
    \    while (py > ty) ope(px, py - 1);\n    if (px == tx + 1) ope(px - 1, py);\n\
    \    tie(tx, ty) = pos[H - 1][0];\n    if (tx < H - 1) {\n      assert(px == tx\
    \ - 1 && py == ty);\n      while (ty > 0) { ope(px, py - 1), ope(px + 1, py),\
    \ ope(px, py + 1), ope(px - 1, py), ope(px, py - 1); }\n      tie(tx, ty) = pos[H\
    \ - 1][0];\n      while (tx < H - 2) { ope(px, py + 1), ope(px + 1, py), ope(px\
    \ + 1, py), ope(px, py - 1), ope(px - 1, py); }\n      ope(px + 1, py), ope(px\
    \ + 1, py), ope(px, py + 1);\n      ope(px - 1, py), ope(px, py - 1), ope(px -\
    \ 1, py);\n      ope(px, py + 1), ope(px + 1, py), ope(px + 1, py);\n      ope(px,\
    \ py - 1), ope(px - 1, py);\n    }\n    FOR(y, W) assert(A[H - 1][y] == (pair<int,\
    \ int>{H - 1, y}));\n    POP(A);\n    solve_sort(A, ANS, tr);\n  }\n};\n"
  dependsOn:
  - linalg/transpose.hpp
  - seq/inversion.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: other/sliding_puzzle_solver.hpp
  requiredBy: []
  timestamp: '2024-11-12 23:21:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/sliding_puzzle_solver.hpp
layout: document
redirect_from:
- /library/other/sliding_puzzle_solver.hpp
- /library/other/sliding_puzzle_solver.hpp.html
title: other/sliding_puzzle_solver.hpp
---
