---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/421.test.cpp
    title: test/3_yukicoder/421.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/421_2.test.cpp
    title: test/3_yukicoder/421_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1045/problem/A
    - https://codeforces.com/contest/786/problem/E
    - https://qoj.ac/problem/6308
  bundledCode: "#line 2 \"ds/my_bitset.hpp\"\n\n// https://codeforces.com/contest/914/problem/F\n\
    // https://yukicoder.me/problems/no/142\n// \u308F\u305A\u304B\u306B\u666E\u901A\
    \u306E bitset \u3088\u308A\u9045\u3044\u3068\u304D\u3082\u3042\u308B\u3088\u3046\
    \u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\u3057\u305F\u304F\u306A\u3044\u3068\
    \u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\u8981\u306A\u3068\u304D\u306B\u4F7F\
    \u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\
    \n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int N = 0, int x = 0) : N(N) {\n\
    \    assert(x == 0 || x == 1);\n    u64 v = (x == 0 ? 0 : -1);\n    dat.assign((N\
    \ + 63) >> 6, v);\n    if (N) dat.back() >>= (64 * len(dat) - N);\n  }\n\n  int\
    \ size() { return N; }\n\n  void resize(int size) {\n    dat.resize((size + 63)\
    \ >> 6);\n    int remainingBits = size & 63;\n    if (remainingBits != 0) {\n\
    \      u64 mask = (u64(1) << remainingBits) - 1;\n      dat.back() &= mask;\n\
    \    }\n    N = size;\n  }\n\n  static T from_string(string &S) {\n    int N =\
    \ len(S);\n    T ANS(N);\n    FOR(i, N) ANS[i] = (S[i] == '1');\n    return ANS;\n\
    \  }\n\n  // thanks to chatgpt!\n  class Proxy {\n  public:\n    Proxy(vc<u64>\
    \ &d, int i) : dat(d), index(i) {}\n    operator bool() const { return (dat[index\
    \ >> 6] >> (index & 63)) & 1; }\n\n    Proxy &operator=(u64 value) {\n      dat[index\
    \ >> 6] &= ~(u64(1) << (index & 63));\n      dat[index >> 6] |= (value & 1) <<\
    \ (index & 63);\n      return *this;\n    }\n    void flip() {\n      dat[index\
    \ >> 6] ^= (u64(1) << (index & 63)); // XOR to flip the bit\n    }\n\n  private:\n\
    \    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy operator[](int i) { return\
    \ Proxy(dat, i); }\n\n  bool operator==(const T &p) {\n    assert(N == p.N);\n\
    \    FOR(i, len(dat)) if (dat[i] != p.dat[i]) return false;\n    return true;\n\
    \  }\n\n  T &operator&=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ dat[i] &= p.dat[i];\n    return *this;\n  }\n  T &operator|=(const T &p) {\n\
    \    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] |= p.dat[i];\n    return *this;\n\
    \  }\n  T &operator^=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ dat[i] ^= p.dat[i];\n    return *this;\n  }\n  T operator&(const T &p) const\
    \ { return T(*this) &= p; }\n  T operator|(const T &p) const { return T(*this)\
    \ |= p; }\n  T operator^(const T &p) const { return T(*this) ^= p; }\n  T operator~()\
    \ const {\n    T p = (*this);\n    p.flip_range(0, N);\n    return p;\n  }\n\n\
    \  int count() {\n    int ans = 0;\n    for (u64 val: dat) ans += popcnt(val);\n\
    \    return ans;\n  }\n\n  int dot(T &p) {\n    assert(N == p.N);\n    int ans\
    \ = 0;\n    FOR(i, len(dat)) ans += popcnt(dat[i] & p.dat[i]);\n    return ans;\n\
    \  }\n\n  int dot_mod_2(T &p) {\n    assert(N == p.N);\n    int ans = 0;\n   \
    \ FOR(i, len(dat)) ans ^= popcnt_mod_2(dat[i] & p.dat[i]);\n    return ans;\n\
    \  }\n\n  int next(int i) {\n    chmax(i, 0);\n    if (i >= N) return N;\n   \
    \ int k = i >> 6;\n    {\n      u64 x = dat[k];\n      int s = i & 63;\n     \
    \ x = (x >> s) << s;\n      if (x) return (k << 6) | lowbit(x);\n    }\n    FOR(idx,\
    \ k + 1, len(dat)) {\n      if (dat[idx] == 0) continue;\n      return (idx <<\
    \ 6) | lowbit(dat[idx]);\n    }\n    return N;\n  }\n\n  int prev(int i) {\n \
    \   chmin(i, N - 1);\n    if (i <= -1) return -1;\n    int k = i >> 6;\n    if\
    \ ((i & 63) < 63) {\n      u64 x = dat[k];\n      x &= (u64(1) << ((i & 63) +\
    \ 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n      --k;\n    }\n   \
    \ FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n      return (idx <<\
    \ 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n  My_Bitset range(int\
    \ L, int R) {\n    assert(L <= R);\n    My_Bitset p(R - L);\n    int rm = (R -\
    \ L) & 63;\n    FOR(rm) {\n      p[R - L - 1] = bool((*this)[R - 1]);\n      --R;\n\
    \    }\n    int n = (R - L) >> 6;\n    int hi = L & 63;\n    int lo = 64 - hi;\n\
    \    int s = L >> 6;\n    if (hi == 0) {\n      FOR(i, n) { p.dat[i] ^= dat[s\
    \ + i]; }\n    } else {\n      FOR(i, n) { p.dat[i] ^= (dat[s + i] >> hi) ^ (dat[s\
    \ + i + 1] << lo); }\n    }\n    return p;\n  }\n\n  My_Bitset slice(int L, int\
    \ R) { return range(L, R); }\n\n  int count_range(int L, int R) {\n    assert(L\
    \ <= R);\n    int cnt = 0;\n    while ((L < R) && (L & 63)) cnt += (*this)[L++];\n\
    \    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r =\
    \ R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n \
    \ // [L,R) \u306B p \u3092\u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset\
    \ &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R\
    \ && (L & 63)) { (*this)[L++] = bool(p[a++]); }\n    while (L < R && (R & 63))\
    \ { (*this)[--R] = bool(p[--b]); }\n    // p[a:b] \u3092 [L:R] \u306B\n    int\
    \ l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n\
    \    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] = p.dat[s + i];\n    } else\
    \ {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l +\
    \ i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // [L,R)\
    \ \u306B p \u3092 xor\n  void xor_to_range(int L, int R, My_Bitset &p) {\n   \
    \ assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63))\
    \ {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n      ++a, ++L;\n    }\n   \
    \ while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >> 6] ^= u64(p[b])\
    \ << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6,\
    \ r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a\
    \ & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s + i];\n    } else {\n      int\
    \ hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] ^= (p.dat[s\
    \ + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // \u884C\u5217\u57FA\
    \u672C\u5909\u5F62\u3067\u4F7F\u3046\u3084\u3064\n  // p \u306F [i:N) \u306B\u3057\
    \u304B\u306A\u3044\u3068\u3057\u3066 p \u3092 xor \u3059\u308B\n  void xor_suffix(int\
    \ i, My_Bitset &p) {\n    assert(N == p.N && 0 <= i && i < N);\n    FOR(k, i /\
    \ 64, len(dat)) { dat[k] ^= p.dat[k]; }\n  }\n\n  // [L,R) \u306B p \u3092 and\n\
    \  void and_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n\
    \    int a = 0, b = p.N;\n    while (L < R && (L & 63)) {\n      if (!p[a]) (*this)[L]\
    \ = 0;\n      a++, L++;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n\
    \      if (!p[b]) (*this)[R] = 0;\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n\
    \    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n =\
    \ r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] &= p.dat[s + i];\n\
    \    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n)\
    \ dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\
    \n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int L, int R, My_Bitset &p)\
    \ {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L\
    \ & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n      ++a, ++L;\n   \
    \ }\n    while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >> 6] |= u64(p[b])\
    \ << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6,\
    \ r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a\
    \ & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s + i];\n    } else {\n      int\
    \ hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] |= (p.dat[s\
    \ + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n  // \u884C\u5217\u57FA\
    \u672C\u5909\u5F62\u3067\u4F7F\u3046\u3084\u3064\n  // p \u306F [i:N) \u306B\u3057\
    \u304B\u306A\u3044\u3068\u3057\u3066 p \u3092 or \u3059\u308B\n  void or_suffix(int\
    \ i, My_Bitset &p) {\n    assert(N == p.N && 0 <= i && i < N);\n    FOR(k, i /\
    \ 64, len(dat)) { dat[k] |= p.dat[k]; }\n  }\n\n  // [L,R) \u3092 1 \u306B\u5909\
    \u66F4\n  void set_range(int L, int R) {\n    while (L < R && (L & 63)) { set(L++);\
    \ }\n    while (L < R && (R & 63)) { set(--R); }\n    FOR(i, L >> 6, R >> 6) dat[i]\
    \ = u64(-1);\n  }\n\n  // [L,R) \u3092 1 \u306B\u5909\u66F4\n  void reset_range(int\
    \ L, int R) {\n    while (L < R && (L & 63)) { reset(L++); }\n    while (L < R\
    \ && (R & 63)) { reset(--R); }\n    FOR(i, L >> 6, R >> 6) dat[i] = u64(0);\n\
    \  }\n\n  // [L,R) \u3092 flip\n  void flip_range(int L, int R) {\n    while (L\
    \ < R && (L & 63)) { flip(L++); }\n    while (L < R && (R & 63)) { flip(--R);\
    \ }\n    FOR(i, L >> 6, R >> 6) dat[i] ^= u64(-1);\n  }\n\n  // bitset \u306B\u4ED5\
    \u69D8\u3092\u5408\u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1; }\n\
    \  void reset(int i) { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip();\
    \ }\n  void set() {\n    fill(all(dat), u64(-1));\n    resize(N);\n  }\n  void\
    \ reset() { fill(all(dat), 0); }\n  void flip() {\n    FOR(i, len(dat) - 1) {\
    \ dat[i] = u64(-1) ^ dat[i]; }\n    int i = len(dat) - 1;\n    FOR(k, 64) {\n\
    \      if (64 * i + k >= size()) break;\n      flip(64 * i + k);\n    }\n  }\n\
    \  bool any() {\n    FOR(i, len(dat)) {\n      if (dat[i]) return true;\n    }\n\
    \    return false;\n  }\n\n  bool ALL() {\n    dat.resize((N + 63) >> 6);\n  \
    \  int r = N & 63;\n    if (r != 0) {\n      u64 mask = (u64(1) << r) - 1;\n \
    \     if (dat.back() != mask) return 0;\n    }\n    for (int i = 0; i < N / 64;\
    \ ++i)\n      if (dat[i] != u64(-1)) return false;\n    return true;\n  }\n\n\
    \  int _Find_first() { return next(0); }\n  int _Find_next(int p) { return next(p\
    \ + 1); }\n\n  static string TO_STR[256];\n  string to_string() const {\n    if\
    \ (TO_STR[0].empty()) precompute();\n    string S;\n    for (auto &x: dat) { FOR(i,\
    \ 8) S += TO_STR[(x >> (8 * i) & 255)]; }\n    S.resize(N);\n    return S;\n \
    \ }\n\n  static void precompute() {\n    FOR(s, 256) {\n      string x;\n    \
    \  FOR(i, 8) x += '0' + (s >> i & 1);\n      TO_STR[s] = x;\n    }\n  }\n};\n\
    string My_Bitset::TO_STR[256];\n#line 2 \"flow/bipartite_dense.hpp\"\n\n// vc<bitset>\
    \ \u3067 biadj matrix \u3092\u6E21\u3059\n// N_1^2N_2/w.\n// (5000,5000) \u3067\
    \ 300ms \u7A0B\u5EA6\u3067\u52D5\u304F\u5834\u5408\u304C\u3042\u308B\n// https://qoj.ac/problem/6308\n\
    // (10000?, 5000) 655ms\n// https://codeforces.com/contest/1045/problem/A\n//\
    \ (10000, 20000) \u3067 3837ms\n// https://codeforces.com/contest/786/problem/E\n\
    // (10000, 10000) 6500ms TLE. row, col \u3068\u3082 shuffle \u3067 3000ms AC.\n\
    // bitset \u306E\u65B9\u304C My_Bitset \u3088\u308A\u9AD8\u901F\uFF1F(2024/05/27)\n\
    template <typename BS>\nstruct BipartiteMatching_Dense {\n  int N1, N2;\n  vc<BS>&\
    \ adj;\n  vc<int> match_1, match_2;\n  vc<int> que;\n  vc<int> prev;\n  BS vis;\n\
    \n  BipartiteMatching_Dense(vc<BS>& adj, int N1, int N2) : N1(N1), N2(N2), adj(adj),\
    \ match_1(N1, -1), match_2(N2, -1) {\n    if constexpr (is_same_v<BS, My_Bitset>)\
    \ vis.resize(N2);\n    FOR(s, N1) bfs(s);\n  }\n\n  void bfs(int s) {\n    if\
    \ (match_1[s] != -1) return;\n    que.resize(N1), prev.resize(N1);\n    int l\
    \ = 0, r = 0;\n    prev[s] = -1;\n    vis.set();\n\n    que[r++] = s;\n    while\
    \ (l < r) {\n      int u = que[l++];\n      BS cand = vis & adj[u];\n      for\
    \ (int v = cand._Find_first(); v < N2; v = cand._Find_next(v)) {\n        vis[v]\
    \ = 0;\n        if (match_2[v] != -1) {\n          que[r++] = match_2[v];\n  \
    \        prev[match_2[v]] = u;\n          continue;\n        }\n        int a\
    \ = u, b = v;\n        while (a != -1) {\n          int t = match_1[a];\n    \
    \      match_1[a] = b, match_2[b] = a, a = prev[a], b = t;\n        }\n      \
    \  return;\n      }\n    }\n    return;\n  }\n\n  vc<pair<int, int>> matching()\
    \ {\n    vc<pair<int, int>> res;\n    FOR(v, N1) if (match_1[v] != -1) res.eb(v,\
    \ match_1[v]);\n    return res;\n  }\n\n  pair<vc<int>, vc<int>> vertex_cover()\
    \ {\n    vc<int> que(N1);\n    int l = 0, r = 0;\n    vis.set();\n    vc<bool>\
    \ done(N1);\n    FOR(i, N1) {\n      if (match_1[i] == -1) done[i] = 1, que[r++]\
    \ = i;\n    }\n    while (l < r) {\n      int a = que[l++];\n      BS cand = adj[a]\
    \ & vis;\n      for (int b = cand._Find_first(); b < N2; b = cand._Find_next(b))\
    \ {\n        vis[b] = 0;\n        int to = match_2[b];\n        assert(to != -1);\n\
    \        if (!done[to]) done[to] = 1, que[r++] = to;\n      }\n    }\n    vc<int>\
    \ left, right;\n    FOR(i, N1) if (!done[i]) left.eb(i);\n    FOR(i, N2) if (!vis[i])\
    \ right.eb(i);\n    return {left, right};\n  }\n};\n"
  code: "#include \"ds/my_bitset.hpp\"\n\n// vc<bitset> \u3067 biadj matrix \u3092\
    \u6E21\u3059\n// N_1^2N_2/w.\n// (5000,5000) \u3067 300ms \u7A0B\u5EA6\u3067\u52D5\
    \u304F\u5834\u5408\u304C\u3042\u308B\n// https://qoj.ac/problem/6308\n// (10000?,\
    \ 5000) 655ms\n// https://codeforces.com/contest/1045/problem/A\n// (10000, 20000)\
    \ \u3067 3837ms\n// https://codeforces.com/contest/786/problem/E\n// (10000, 10000)\
    \ 6500ms TLE. row, col \u3068\u3082 shuffle \u3067 3000ms AC.\n// bitset \u306E\
    \u65B9\u304C My_Bitset \u3088\u308A\u9AD8\u901F\uFF1F(2024/05/27)\ntemplate <typename\
    \ BS>\nstruct BipartiteMatching_Dense {\n  int N1, N2;\n  vc<BS>& adj;\n  vc<int>\
    \ match_1, match_2;\n  vc<int> que;\n  vc<int> prev;\n  BS vis;\n\n  BipartiteMatching_Dense(vc<BS>&\
    \ adj, int N1, int N2) : N1(N1), N2(N2), adj(adj), match_1(N1, -1), match_2(N2,\
    \ -1) {\n    if constexpr (is_same_v<BS, My_Bitset>) vis.resize(N2);\n    FOR(s,\
    \ N1) bfs(s);\n  }\n\n  void bfs(int s) {\n    if (match_1[s] != -1) return;\n\
    \    que.resize(N1), prev.resize(N1);\n    int l = 0, r = 0;\n    prev[s] = -1;\n\
    \    vis.set();\n\n    que[r++] = s;\n    while (l < r) {\n      int u = que[l++];\n\
    \      BS cand = vis & adj[u];\n      for (int v = cand._Find_first(); v < N2;\
    \ v = cand._Find_next(v)) {\n        vis[v] = 0;\n        if (match_2[v] != -1)\
    \ {\n          que[r++] = match_2[v];\n          prev[match_2[v]] = u;\n     \
    \     continue;\n        }\n        int a = u, b = v;\n        while (a != -1)\
    \ {\n          int t = match_1[a];\n          match_1[a] = b, match_2[b] = a,\
    \ a = prev[a], b = t;\n        }\n        return;\n      }\n    }\n    return;\n\
    \  }\n\n  vc<pair<int, int>> matching() {\n    vc<pair<int, int>> res;\n    FOR(v,\
    \ N1) if (match_1[v] != -1) res.eb(v, match_1[v]);\n    return res;\n  }\n\n \
    \ pair<vc<int>, vc<int>> vertex_cover() {\n    vc<int> que(N1);\n    int l = 0,\
    \ r = 0;\n    vis.set();\n    vc<bool> done(N1);\n    FOR(i, N1) {\n      if (match_1[i]\
    \ == -1) done[i] = 1, que[r++] = i;\n    }\n    while (l < r) {\n      int a =\
    \ que[l++];\n      BS cand = adj[a] & vis;\n      for (int b = cand._Find_first();\
    \ b < N2; b = cand._Find_next(b)) {\n        vis[b] = 0;\n        int to = match_2[b];\n\
    \        assert(to != -1);\n        if (!done[to]) done[to] = 1, que[r++] = to;\n\
    \      }\n    }\n    vc<int> left, right;\n    FOR(i, N1) if (!done[i]) left.eb(i);\n\
    \    FOR(i, N2) if (!vis[i]) right.eb(i);\n    return {left, right};\n  }\n};"
  dependsOn:
  - ds/my_bitset.hpp
  isVerificationFile: false
  path: flow/bipartite_dense.hpp
  requiredBy: []
  timestamp: '2024-09-24 18:06:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/421_2.test.cpp
  - test/3_yukicoder/421.test.cpp
documentation_of: flow/bipartite_dense.hpp
layout: document
redirect_from:
- /library/flow/bipartite_dense.hpp
- /library/flow/bipartite_dense.hpp.html
title: flow/bipartite_dense.hpp
---
