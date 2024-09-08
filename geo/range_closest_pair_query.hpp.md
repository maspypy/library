---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_closest_pair.test.cpp
    title: test/1_mytest/range_closest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/gym/104172/attachments/download/18933/Hong_Kong_Tutorial.pdf
    - https://codeforces.com/problemset/problem/765/F
    - https://qoj.ac/problem/5463
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\
    \u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\
    \u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n   \
    \ used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size()\
    \ { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int\
    \ i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask)\
    \ {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if\
    \ (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 2 \"ds/segtree/dual_segtree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Dual_SegTree {\n  using MA = Monoid;\n\
    \  using A = typename MA::value_type;\n  int n, log, size;\n  vc<A> laz;\n\n \
    \ Dual_SegTree() : Dual_SegTree(0) {}\n  Dual_SegTree(int n) { build(n); }\n\n\
    \  void build(int m) {\n    n = m;\n    log = 1;\n    while ((1 << log) < n) ++log;\n\
    \    size = 1 << log;\n    laz.assign(size << 1, MA::unit());\n  }\n\n  A get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n \
    \   FOR(i, size) push(i);\n    return {laz.begin() + size, laz.begin() + size\
    \ + n};\n  }\n\n  void apply(int l, int r, const A& a) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n   \
    \ if (!MA::commute) {\n      for (int i = log; i >= 1; i--) {\n        if (((l\
    \ >> i) << i) != l) push(l >> i);\n        if (((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n      }\n    }\n    while (l < r) {\n      if (l & 1) all_apply(l++,\
    \ a);\n      if (r & 1) all_apply(--r, a);\n      l >>= 1, r >>= 1;\n    }\n \
    \ }\n\nprivate:\n  void push(int k) {\n    if (laz[k] == MA::unit()) return;\n\
    \    all_apply(2 * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n\
    \  }\n  void all_apply(int k, A a) { laz[k] = MA::op(laz[k], a); }\n};\n#line\
    \ 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\
    \n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 4 \"geo/range_closest_pair_query.hpp\"\n\n// \u70B9\u7FA4 {p_i | i in [l, r)}\
    \ \u306B\u5BFE\u3059\u308B\u6700\u8FD1\u70B9\u5BFE\u306E\u8A08\u7B97\u3092\u884C\
    \u3046\u30AF\u30A8\u30EA\n// O(KNlogKN + QlogN)\n// https://qoj.ac/problem/5463\n\
    // https://codeforces.com/gym/104172/attachments/download/18933/Hong_Kong_Tutorial.pdf\n\
    // \u70B9\u7FA4\u304C 1 \u6B21\u5143\uFF1Ahttps://codeforces.com/problemset/problem/765/F\n\
    struct Range_Closest_Pair_Query {\n  /*\n  \u30FBR \u3092\u5897\u3084\u3057\u306A\
    \u304C\u3089\u3001L \u3054\u3068\u306E\u7B54\u3092\u7BA1\u7406\u3059\u308B\n \
    \ \u30FB2^{k-1} <= ANS[L:R] < 2^{k} \u3068\u306A\u308B L \uFF1A\u30EC\u30D9\u30EB\
    \ k \uFF08\u30EC\u30D9\u30EB 0\uFF1A\u8DDD\u96E2 0\uFF09\n  \u30FB\u30EC\u30D9\
    \u30EB 0, 1, 2, ..., 29 \u306E\u30B0\u30EA\u30C3\u30C9\u3092\u7528\u610F\u3059\
    \u308B\n  \u3000\u30FB\u5E45\u306F 2^k\n\u3000  \u30FB\u4E00\u8FBA 1.99 \u306E\
    \u6B63\u65B9\u5F62\u5185\u3067\u70B9\u5BFE\u8DDD\u96E2\u304C 1 \u4EE5\u4E0A \u2192\
    \ 8 \u500B\u307E\u3067\u3042\u308A\u3046\u308B\n  \u30FB\u30EC\u30D9\u30EB 29,\
    \ 28, ..., 0 \u306E\u9806\u306B\u63A2\u7D22\u3059\u308B\uFF1A9 \u8FD1\u508D\n\
    \  \u3000\u30FB\u7B54\u304C\u898B\u3064\u304B\u3063\u305F\u3089\u30EC\u30D9\u30EB\
    \u3092\u4E0B\u3052\u308B\u3002\u5DE6\u5411\u304D\u306B\u4F1D\u642C\u3002\n  \u3000\
    \u30FB\u30EC\u30D9\u30EB\u306E\u6E1B\u5C11\u306F 30N \u56DE\u307E\u3067\u3057\u304B\
    \u8D77\u304D\u306A\u3044\n  */\n  const int LOG = 30;\n  vc<pair<int, int>> point;\n\
    \  vc<pair<int, int>> query;\n  void add_point(int x, int y) {\n    assert(0 <=\
    \ x && x < (1 << LOG));\n    assert(0 <= y && y < (1 << LOG));\n    point.eb(x,\
    \ y);\n  }\n  void add_query(int L, int R) {\n    assert(R - L >= 2);\n    query.eb(L,\
    \ R);\n  }\n  ll dist(int i, int j) {\n    ll dx = point[i].fi - point[j].fi;\n\
    \    ll dy = point[i].se - point[j].se;\n    return dx * dx + dy * dy;\n  }\n\n\
    \  vc<ll> calc() {\n    const int K = LOG;\n    const int N = len(point), Q =\
    \ len(query);\n    using A9 = array<int, 9>;\n    // \u305D\u308C\u305E\u308C\u306E\
    \u30EC\u30D9\u30EB\u306E\u3068\u304D\u306E\u30BB\u30EB\u756A\u53F7\n    vv(int,\
    \ IDX, K, N, -1);\n    // \u5404\u30BB\u30EB\u756A\u53F7\u306B\u5BFE\u3059\u308B\
    \u8FD1\u508D\n    vc<A9> nbd;\n    FOR(k, 1, K) {\n      HashMap<int> MP(N);\n\
    \      auto to_64 = [&](int x, int y) -> u64 { return u64(x) << 30 | y; };\n \
    \     int off = len(nbd);\n      int p = off;\n      FOR(i, N) {\n        int\
    \ x = point[i].fi >> (k);\n        int y = point[i].se >> (k);\n        u64 key\
    \ = to_64(x, y);\n        if (!MP.count(key)) { MP[key] = p++; }\n        IDX[k][i]\
    \ = MP[key];\n      }\n      nbd.resize(p);\n      FOR(i, N) {\n        int x\
    \ = point[i].fi >> (k);\n        int y = point[i].se >> (k);\n        int me =\
    \ MP[to_64(x, y)];\n        int s = 0;\n        FOR(dx, -1, 2) FOR(dy, -1, 2)\
    \ {\n          u64 key = to_64(x + dx, y + dy);\n          nbd[me][s++] = MP.get(key,\
    \ -1);\n        }\n      }\n    }\n\n    vc<array<int, 8>> dat(len(nbd), {-1,\
    \ -1, -1, -1, -1, -1, -1, -1});\n    auto add = [&](int k, int i) -> void {\n\
    \      int idx = IDX[k][i];\n      for (auto&& j: dat[idx]) {\n        if (j ==\
    \ -1) {\n          j = i;\n          return;\n        }\n      }\n    };\n   \
    \ auto rm = [&](int k, int i) -> void {\n      int idx = IDX[k][i];\n      for\
    \ (auto&& j: dat[idx]) {\n        if (j == i) {\n          j = -1;\n         \
    \ return;\n        }\n      }\n    };\n\n    auto solve_level = [&](int k, int\
    \ i) -> vc<pair<int, ll>> {\n      // \u30EC\u30D9\u30EB k \u306E\u70B9\u7FA4\u306B\
    \u5BFE\u3059\u308B\u7B54\u306E\u8A08\u7B97\n      vc<pair<int, ll>> res;\n   \
    \   int me = IDX[k][i];\n      for (auto&& idx: nbd[me]) {\n        if (idx ==\
    \ -1) continue;\n        for (auto&& j: dat[idx]) {\n          if (j == -1) continue;\n\
    \          res.eb(j, dist(i, j));\n        }\n      }\n      return res;\n   \
    \ };\n    Dual_SegTree<Monoid_Min<ll>> seg(N);\n    vc<int> LEVEL(N, -1);\n  \
    \  auto get_lv = [&](ll d) -> int {\n      if (d == 0) return 0;\n      return\
    \ topbit(d) / 2 + 1;\n    };\n\n    vc<int> left(Q);\n    vvc<int> query_at(N);\n\
    \    FOR(qid, Q) {\n      auto [L, R] = query[qid];\n      left[qid] = L;\n  \
    \    query_at[--R].eb(qid);\n    }\n\n    vi ANS(Q);\n\n    FOR(R, N) {\n    \
    \  // R \u756A\u76EE\u306E\u70B9\u3092\u7528\u3044\u305F\u7B54\u306E\u66F4\u65B0\
    \n      vc<pair<int, ll>> upd;\n      FOR(k, 1, K) {\n        auto res = solve_level(k,\
    \ R);\n        upd.insert(upd.end(), all(res));\n      }\n\n      for (auto [i,\
    \ d]: upd) {\n        int lv = get_lv(d);\n        if (seg.get(i) < d) continue;\n\
    \        // \u7B54\u3048\u306E\u66F4\u65B0\n        seg.apply(0, i + 1, d);\n\
    \        // \u30EC\u30D9\u30EB\u306E\u66F4\u65B0\n        while (i >= 0 && LEVEL[i]\
    \ > lv) {\n          rm(LEVEL[i], i);\n          LEVEL[i] = lv;\n          if\
    \ (lv) add(lv, i);\n          --i;\n        }\n      }\n      LEVEL[R] = K - 1;\n\
    \      add(K - 1, R);\n      for (auto&& qid: query_at[R]) { ANS[qid] = seg.get(left[qid]);\
    \ }\n    }\n    return ANS;\n  }\n};\n"
  code: "#include \"ds/hashmap.hpp\"\n#include \"ds/segtree/dual_segtree.hpp\"\n#include\
    \ \"alg/monoid/min.hpp\"\n\n// \u70B9\u7FA4 {p_i | i in [l, r)} \u306B\u5BFE\u3059\
    \u308B\u6700\u8FD1\u70B9\u5BFE\u306E\u8A08\u7B97\u3092\u884C\u3046\u30AF\u30A8\
    \u30EA\n// O(KNlogKN + QlogN)\n// https://qoj.ac/problem/5463\n// https://codeforces.com/gym/104172/attachments/download/18933/Hong_Kong_Tutorial.pdf\n\
    // \u70B9\u7FA4\u304C 1 \u6B21\u5143\uFF1Ahttps://codeforces.com/problemset/problem/765/F\n\
    struct Range_Closest_Pair_Query {\n  /*\n  \u30FBR \u3092\u5897\u3084\u3057\u306A\
    \u304C\u3089\u3001L \u3054\u3068\u306E\u7B54\u3092\u7BA1\u7406\u3059\u308B\n \
    \ \u30FB2^{k-1} <= ANS[L:R] < 2^{k} \u3068\u306A\u308B L \uFF1A\u30EC\u30D9\u30EB\
    \ k \uFF08\u30EC\u30D9\u30EB 0\uFF1A\u8DDD\u96E2 0\uFF09\n  \u30FB\u30EC\u30D9\
    \u30EB 0, 1, 2, ..., 29 \u306E\u30B0\u30EA\u30C3\u30C9\u3092\u7528\u610F\u3059\
    \u308B\n  \u3000\u30FB\u5E45\u306F 2^k\n\u3000  \u30FB\u4E00\u8FBA 1.99 \u306E\
    \u6B63\u65B9\u5F62\u5185\u3067\u70B9\u5BFE\u8DDD\u96E2\u304C 1 \u4EE5\u4E0A \u2192\
    \ 8 \u500B\u307E\u3067\u3042\u308A\u3046\u308B\n  \u30FB\u30EC\u30D9\u30EB 29,\
    \ 28, ..., 0 \u306E\u9806\u306B\u63A2\u7D22\u3059\u308B\uFF1A9 \u8FD1\u508D\n\
    \  \u3000\u30FB\u7B54\u304C\u898B\u3064\u304B\u3063\u305F\u3089\u30EC\u30D9\u30EB\
    \u3092\u4E0B\u3052\u308B\u3002\u5DE6\u5411\u304D\u306B\u4F1D\u642C\u3002\n  \u3000\
    \u30FB\u30EC\u30D9\u30EB\u306E\u6E1B\u5C11\u306F 30N \u56DE\u307E\u3067\u3057\u304B\
    \u8D77\u304D\u306A\u3044\n  */\n  const int LOG = 30;\n  vc<pair<int, int>> point;\n\
    \  vc<pair<int, int>> query;\n  void add_point(int x, int y) {\n    assert(0 <=\
    \ x && x < (1 << LOG));\n    assert(0 <= y && y < (1 << LOG));\n    point.eb(x,\
    \ y);\n  }\n  void add_query(int L, int R) {\n    assert(R - L >= 2);\n    query.eb(L,\
    \ R);\n  }\n  ll dist(int i, int j) {\n    ll dx = point[i].fi - point[j].fi;\n\
    \    ll dy = point[i].se - point[j].se;\n    return dx * dx + dy * dy;\n  }\n\n\
    \  vc<ll> calc() {\n    const int K = LOG;\n    const int N = len(point), Q =\
    \ len(query);\n    using A9 = array<int, 9>;\n    // \u305D\u308C\u305E\u308C\u306E\
    \u30EC\u30D9\u30EB\u306E\u3068\u304D\u306E\u30BB\u30EB\u756A\u53F7\n    vv(int,\
    \ IDX, K, N, -1);\n    // \u5404\u30BB\u30EB\u756A\u53F7\u306B\u5BFE\u3059\u308B\
    \u8FD1\u508D\n    vc<A9> nbd;\n    FOR(k, 1, K) {\n      HashMap<int> MP(N);\n\
    \      auto to_64 = [&](int x, int y) -> u64 { return u64(x) << 30 | y; };\n \
    \     int off = len(nbd);\n      int p = off;\n      FOR(i, N) {\n        int\
    \ x = point[i].fi >> (k);\n        int y = point[i].se >> (k);\n        u64 key\
    \ = to_64(x, y);\n        if (!MP.count(key)) { MP[key] = p++; }\n        IDX[k][i]\
    \ = MP[key];\n      }\n      nbd.resize(p);\n      FOR(i, N) {\n        int x\
    \ = point[i].fi >> (k);\n        int y = point[i].se >> (k);\n        int me =\
    \ MP[to_64(x, y)];\n        int s = 0;\n        FOR(dx, -1, 2) FOR(dy, -1, 2)\
    \ {\n          u64 key = to_64(x + dx, y + dy);\n          nbd[me][s++] = MP.get(key,\
    \ -1);\n        }\n      }\n    }\n\n    vc<array<int, 8>> dat(len(nbd), {-1,\
    \ -1, -1, -1, -1, -1, -1, -1});\n    auto add = [&](int k, int i) -> void {\n\
    \      int idx = IDX[k][i];\n      for (auto&& j: dat[idx]) {\n        if (j ==\
    \ -1) {\n          j = i;\n          return;\n        }\n      }\n    };\n   \
    \ auto rm = [&](int k, int i) -> void {\n      int idx = IDX[k][i];\n      for\
    \ (auto&& j: dat[idx]) {\n        if (j == i) {\n          j = -1;\n         \
    \ return;\n        }\n      }\n    };\n\n    auto solve_level = [&](int k, int\
    \ i) -> vc<pair<int, ll>> {\n      // \u30EC\u30D9\u30EB k \u306E\u70B9\u7FA4\u306B\
    \u5BFE\u3059\u308B\u7B54\u306E\u8A08\u7B97\n      vc<pair<int, ll>> res;\n   \
    \   int me = IDX[k][i];\n      for (auto&& idx: nbd[me]) {\n        if (idx ==\
    \ -1) continue;\n        for (auto&& j: dat[idx]) {\n          if (j == -1) continue;\n\
    \          res.eb(j, dist(i, j));\n        }\n      }\n      return res;\n   \
    \ };\n    Dual_SegTree<Monoid_Min<ll>> seg(N);\n    vc<int> LEVEL(N, -1);\n  \
    \  auto get_lv = [&](ll d) -> int {\n      if (d == 0) return 0;\n      return\
    \ topbit(d) / 2 + 1;\n    };\n\n    vc<int> left(Q);\n    vvc<int> query_at(N);\n\
    \    FOR(qid, Q) {\n      auto [L, R] = query[qid];\n      left[qid] = L;\n  \
    \    query_at[--R].eb(qid);\n    }\n\n    vi ANS(Q);\n\n    FOR(R, N) {\n    \
    \  // R \u756A\u76EE\u306E\u70B9\u3092\u7528\u3044\u305F\u7B54\u306E\u66F4\u65B0\
    \n      vc<pair<int, ll>> upd;\n      FOR(k, 1, K) {\n        auto res = solve_level(k,\
    \ R);\n        upd.insert(upd.end(), all(res));\n      }\n\n      for (auto [i,\
    \ d]: upd) {\n        int lv = get_lv(d);\n        if (seg.get(i) < d) continue;\n\
    \        // \u7B54\u3048\u306E\u66F4\u65B0\n        seg.apply(0, i + 1, d);\n\
    \        // \u30EC\u30D9\u30EB\u306E\u66F4\u65B0\n        while (i >= 0 && LEVEL[i]\
    \ > lv) {\n          rm(LEVEL[i], i);\n          LEVEL[i] = lv;\n          if\
    \ (lv) add(lv, i);\n          --i;\n        }\n      }\n      LEVEL[R] = K - 1;\n\
    \      add(K - 1, R);\n      for (auto&& qid: query_at[R]) { ANS[qid] = seg.get(left[qid]);\
    \ }\n    }\n    return ANS;\n  }\n};"
  dependsOn:
  - ds/hashmap.hpp
  - ds/segtree/dual_segtree.hpp
  - alg/monoid/min.hpp
  isVerificationFile: false
  path: geo/range_closest_pair_query.hpp
  requiredBy: []
  timestamp: '2024-08-26 01:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/range_closest_pair.test.cpp
documentation_of: geo/range_closest_pair_query.hpp
layout: document
redirect_from:
- /library/geo/range_closest_pair_query.hpp
- /library/geo/range_closest_pair_query.hpp.html
title: geo/range_closest_pair_query.hpp
---
