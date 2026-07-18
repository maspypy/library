---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/decremental_fastset.hpp
    title: ds/decremental_fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1053/E
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"ds/decremental_fastset.hpp\"\n\
    \n// amortized linear\n// MoFR \u306A\u3057\u3060\u3068 FastSet \u3088\u308A\u9045\
    \u304B\u3063\u305F\nstruct Decremental_FastSet {\n  struct Decremental_Neighbor_UF\
    \ {\n    int n;\n    UnionFind uf;\n    vc<int> L, R;\n    Decremental_Neighbor_UF(int\
    \ n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {\n      FOR(i, n + 2) L[i] = i, R[i]\
    \ = i;\n    }\n    void erase(int i) {\n      assert(0 <= i && i < n);\n     \
    \ ++i;\n      int l = L[uf[i - 1]], r = R[uf[i]];\n      uf.merge(i, i - 1);\n\
    \      L[uf[i]] = l, R[uf[i]] = r;\n    }\n    int prev(int i) {\n      assert(-1\
    \ <= i);\n      chmin(i, n - 1);\n      return L[uf[i + 1]] - 1;\n    }\n    int\
    \ next(int i) {\n      assert(i <= n);\n      chmax(i, 0);\n      return R[uf[i]];\n\
    \    }\n  };\n  int N, n;\n  vc<u64> dat;\n  Decremental_Neighbor_UF X;\n  Decremental_FastSet(int\
    \ N) : N(N), n((N + 63) / 64), X(n) {\n    dat.assign(n, u64(-1));\n    if (n)\
    \ dat.back() = u64(-1) >> (64 * n - N);\n  }\n\n  bool operator[](int i) { return\
    \ (dat[i / 64] >> (i & 63) & 1); }\n\n  void erase(int i) {\n    int a = i / 64,\
    \ b = i & 63;\n    if (!(dat[a] >> b & 1)) return;\n    dat[a] &= ~(u64(1) <<\
    \ b);\n    if (dat[a] == 0) {\n      X.erase(a);\n    }\n  }\n  int prev(int i)\
    \ {\n    assert(-1 <= i);\n    chmin(i, N - 1);\n    if (i == -1) return -1;\n\
    \    int a = i / 64, b = i & 63;\n    u64 x = dat[a] & (u64(-1) >> (63 - b));\n\
    \    if (x != 0) return 64 * a + topbit(x);\n    a = X.prev(a - 1);\n    return\
    \ (a == -1 ? -1 : 64 * a + topbit(dat[a]));\n  }\n  int next(int i) {\n    assert(i\
    \ <= N);\n    chmax(i, 0);\n    if (i == N) return N;\n    int a = i / 64, b =\
    \ i & 63;\n    u64 x = dat[a] >> b;\n    if (x != 0) return 64 * a + b + lowbit(x);\n\
    \    a = X.next(a + 1);\n    return (a == n ? N : 64 * a + lowbit(dat[a]));\n\
    \  }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int r, F&&\
    \ f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n  }\n\n  string\
    \ to_string() {\n    string S(N, '.');\n    FOR(i, N) S[i] = '0' + (dat[i / 64]\
    \ >> (i & 63) & 1);\n    return S;\n  }\n};\n#line 2 \"graph/restore_euler_tour.hpp\"\
    \n\n// \u672A\u77E5\u306E\u6728\u306E euler tour \u306E\u9802\u70B9\u5217\u304C\
    \ -1 \u8FBC\u307F\u3067\u4E0E\u3048\u3089\u308C\u308B\n// https://codeforces.com/problemset/problem/1053/E\n\
    // \u59CB\u70B9\u304C 0 \u3068\u306F\u9650\u308A\u307E\u305B\u3093\nvc<int> restore_euler_tour(int\
    \ N, vc<int> A) {\n  if (N == 1) return {0};\n  assert(len(A) == N + N - 1);\n\
    \  if (A[0] == -1) A[0] = A.back();\n  if (A.back() == -1) A.back() = A[0];\n\
    \  if (A[0] != -1 && A.back() != -1 && A[0] != A.back()) return {};\n\n  vc<int>\
    \ exist(N);\n  for (auto& x : A)\n    if (0 <= x) exist[x] = 1;\n  vc<int> other;\n\
    \  FOR(x, N) if (!exist[x]) other.eb(x);\n  FOR(N + N - 1) other.eb(N);\n  reverse(all(other));\n\
    \n  vc<int> nxt(N + N - 1, -1), pre(N + N - 1, -1);\n  {\n    vc<int> pos(N, -1);\n\
    \    FOR(i, N + N - 1) {\n      int x = A[i];\n      if (x == -1) continue;\n\
    \      if (pos[x] != -1) nxt[pos[x]] = i, pre[i] = pos[x];\n      pos[x] = i;\n\
    \    }\n  }\n\n  pq_min<tuple<int, int, int>> que;\n  FOR(i, N + N - 1) if (nxt[i]\
    \ != -1) que.emplace(nxt[i] - i, i, nxt[i]);\n  Decremental_FastSet FS(N + N -\
    \ 1);\n\n  auto rm = [&](int i) -> void {\n    assert(FS[i]);\n    FS.erase(i);\n\
    \    int a = pre[i], b = nxt[i];\n    if (a != -1) nxt[a] = b;\n    if (b != -1)\
    \ pre[b] = a;\n    if (a != -1 && b != -1) que.emplace(b - a, a, b);\n  };\n\n\
    \  auto solve_local = [&](vc<int>& A) -> void {\n    int N = len(A);\n    assert(N\
    \ >= 3 && A[0] == A[N - 1] && N % 2 == 1);\n    // r.....r\n    // \u9593\u306F\
    \ distinct \u3067\u7A2E\u985E\u6570\u306F\u5C11\u306A\u3044\u3068\u3057\u3066\u3088\
    \u3044\n    int n = 0;\n    FOR(i, 1, N - 1) n += (A[i] != -1);\n    if (n > N\
    \ / 2) return;\n    FOR(i, 1, N - 1) {\n      if (A[i] == -1 && n < N / 2) A[i]\
    \ = POP(other), ++n;\n    }\n\n    vc<int> I;\n    FOR(i, 1, N - 1) {\n      I.eb(i);\n\
    \      while (len(I) >= 3) {\n        int a = I[len(I) - 3];\n        int b =\
    \ I[len(I) - 2];\n        int c = I[len(I) - 1];\n        if (A[a] == -1 && A[b]\
    \ != -1 && A[c] != -1) {\n          A[a] = A[c];\n          POP(I), POP(I);\n\
    \        }\n        elif (A[a] != -1 && A[b] != -1 && A[c] == -1) {\n        \
    \  A[c] = A[a];\n          POP(I), POP(I);\n        }\n        else break;\n \
    \     }\n    }\n    if (MIN(A) >= 0) return;\n    for (auto& x : A)\n      if\
    \ (x == -1) x = A[0];\n  };\n\n  while (len(que)) {\n    auto [pri, L, R] = POP(que);\n\
    \    if (!FS[L] || !FS[R]) continue;\n    vc<int> I;\n    I.eb(L);\n    FS.enumerate(L\
    \ + 1, R, [&](int i) -> void { I.eb(i); });\n    I.eb(R);\n    vc<int> B = rearrange(A,\
    \ I);\n    if (len(B) % 2 == 0) return {};\n    solve_local(B);\n    FOR(i, len(B))\
    \ A[I[i]] = B[i];\n    FS.enumerate(L, R, [&](int i) -> void { rm(i); });\n  }\n\
    \n  auto solve_local_2 = [&](vc<int>& A) -> void {\n    int N = len(A);\n    assert(N\
    \ >= 3 && A[0] == A[N - 1] && N % 2 == 1 && A[0] == -1);\n    if (N == 3) {\n\
    \      A[0] = A[N - 1] = POP(other);\n      solve_local(A);\n      return;\n \
    \   }\n    // ?.....?\n    // \u9593\u306F distinct \u3067\u7A2E\u985E\u6570\u306F\
    \u5C11\u306A\u3044\u3068\u3057\u3066\u3088\u3044\n    int n = 0;\n    FOR(i, 1,\
    \ N - 1) n += (A[i] != -1);\n    if (n > 1 + N / 2) return;\n    if (n <= N /\
    \ 2) {\n      A[0] = A[N - 1] = POP(other);\n      solve_local(A);\n      return;\n\
    \    }\n    // .23.10. \u5168\u7A2E\u985E\u767B\u5834\u306F\u3057\u3066\u3044\u308B\
    \n    // \u3084\u3063\u3071\u308A\u3060\u3044\u305F\u3044\u540C\u3058\u3053\u3068\
    \u3092\u3084\u308C\u3070\u3088\u3044\n\n    vc<int> I;\n    FOR(i, 1, N - 1) {\n\
    \      I.eb(i);\n      while (len(I) >= 3) {\n        int a = I[len(I) - 3];\n\
    \        int b = I[len(I) - 2];\n        int c = I[len(I) - 1];\n        if (A[a]\
    \ == -1 && A[b] != -1 && A[c] != -1) {\n          A[a] = A[c];\n          POP(I),\
    \ POP(I);\n        }\n        elif (A[a] != -1 && A[b] != -1 && A[c] == -1) {\n\
    \          A[c] = A[a];\n          POP(I), POP(I);\n        }\n        else break;\n\
    \      }\n    }\n    assert(len(I) == 3);\n    A[0] = A[N - 1] = A[I[1]];\n  };\n\
    \n  if (A[0] == -1) {\n    vc<int> I;\n    FS.enumerate(0, len(A), [&](int i)\
    \ -> void { I.eb(i); });\n    vc<int> B = rearrange(A, I);\n    solve_local_2(B);\n\
    \    FOR(i, len(I)) A[I[i]] = B[i];\n  }\n\n  // check\n  if (MAX(A) >= N) return\
    \ {};\n  if (MIN(A) == -1) return {};\n  vc<int> vis(N);\n  vc<int> path = {A[0]};\n\
    \  FOR(i, 1, len(A)) {\n    int v = A[i];\n    if (len(path) >= 2 && path[len(path)\
    \ - 2] == v) {\n      POP(path);\n    } else {\n      if (vis[v]) return {};\n\
    \      path.eb(v);\n      vis[v] = 1;\n    }\n  }\n  if (len(path) != 1) return\
    \ {};\n  return A;\n}\n"
  code: "#include \"ds/decremental_fastset.hpp\"\n\n// \u672A\u77E5\u306E\u6728\u306E\
    \ euler tour \u306E\u9802\u70B9\u5217\u304C -1 \u8FBC\u307F\u3067\u4E0E\u3048\u3089\
    \u308C\u308B\n// https://codeforces.com/problemset/problem/1053/E\n// \u59CB\u70B9\
    \u304C 0 \u3068\u306F\u9650\u308A\u307E\u305B\u3093\nvc<int> restore_euler_tour(int\
    \ N, vc<int> A) {\n  if (N == 1) return {0};\n  assert(len(A) == N + N - 1);\n\
    \  if (A[0] == -1) A[0] = A.back();\n  if (A.back() == -1) A.back() = A[0];\n\
    \  if (A[0] != -1 && A.back() != -1 && A[0] != A.back()) return {};\n\n  vc<int>\
    \ exist(N);\n  for (auto& x : A)\n    if (0 <= x) exist[x] = 1;\n  vc<int> other;\n\
    \  FOR(x, N) if (!exist[x]) other.eb(x);\n  FOR(N + N - 1) other.eb(N);\n  reverse(all(other));\n\
    \n  vc<int> nxt(N + N - 1, -1), pre(N + N - 1, -1);\n  {\n    vc<int> pos(N, -1);\n\
    \    FOR(i, N + N - 1) {\n      int x = A[i];\n      if (x == -1) continue;\n\
    \      if (pos[x] != -1) nxt[pos[x]] = i, pre[i] = pos[x];\n      pos[x] = i;\n\
    \    }\n  }\n\n  pq_min<tuple<int, int, int>> que;\n  FOR(i, N + N - 1) if (nxt[i]\
    \ != -1) que.emplace(nxt[i] - i, i, nxt[i]);\n  Decremental_FastSet FS(N + N -\
    \ 1);\n\n  auto rm = [&](int i) -> void {\n    assert(FS[i]);\n    FS.erase(i);\n\
    \    int a = pre[i], b = nxt[i];\n    if (a != -1) nxt[a] = b;\n    if (b != -1)\
    \ pre[b] = a;\n    if (a != -1 && b != -1) que.emplace(b - a, a, b);\n  };\n\n\
    \  auto solve_local = [&](vc<int>& A) -> void {\n    int N = len(A);\n    assert(N\
    \ >= 3 && A[0] == A[N - 1] && N % 2 == 1);\n    // r.....r\n    // \u9593\u306F\
    \ distinct \u3067\u7A2E\u985E\u6570\u306F\u5C11\u306A\u3044\u3068\u3057\u3066\u3088\
    \u3044\n    int n = 0;\n    FOR(i, 1, N - 1) n += (A[i] != -1);\n    if (n > N\
    \ / 2) return;\n    FOR(i, 1, N - 1) {\n      if (A[i] == -1 && n < N / 2) A[i]\
    \ = POP(other), ++n;\n    }\n\n    vc<int> I;\n    FOR(i, 1, N - 1) {\n      I.eb(i);\n\
    \      while (len(I) >= 3) {\n        int a = I[len(I) - 3];\n        int b =\
    \ I[len(I) - 2];\n        int c = I[len(I) - 1];\n        if (A[a] == -1 && A[b]\
    \ != -1 && A[c] != -1) {\n          A[a] = A[c];\n          POP(I), POP(I);\n\
    \        }\n        elif (A[a] != -1 && A[b] != -1 && A[c] == -1) {\n        \
    \  A[c] = A[a];\n          POP(I), POP(I);\n        }\n        else break;\n \
    \     }\n    }\n    if (MIN(A) >= 0) return;\n    for (auto& x : A)\n      if\
    \ (x == -1) x = A[0];\n  };\n\n  while (len(que)) {\n    auto [pri, L, R] = POP(que);\n\
    \    if (!FS[L] || !FS[R]) continue;\n    vc<int> I;\n    I.eb(L);\n    FS.enumerate(L\
    \ + 1, R, [&](int i) -> void { I.eb(i); });\n    I.eb(R);\n    vc<int> B = rearrange(A,\
    \ I);\n    if (len(B) % 2 == 0) return {};\n    solve_local(B);\n    FOR(i, len(B))\
    \ A[I[i]] = B[i];\n    FS.enumerate(L, R, [&](int i) -> void { rm(i); });\n  }\n\
    \n  auto solve_local_2 = [&](vc<int>& A) -> void {\n    int N = len(A);\n    assert(N\
    \ >= 3 && A[0] == A[N - 1] && N % 2 == 1 && A[0] == -1);\n    if (N == 3) {\n\
    \      A[0] = A[N - 1] = POP(other);\n      solve_local(A);\n      return;\n \
    \   }\n    // ?.....?\n    // \u9593\u306F distinct \u3067\u7A2E\u985E\u6570\u306F\
    \u5C11\u306A\u3044\u3068\u3057\u3066\u3088\u3044\n    int n = 0;\n    FOR(i, 1,\
    \ N - 1) n += (A[i] != -1);\n    if (n > 1 + N / 2) return;\n    if (n <= N /\
    \ 2) {\n      A[0] = A[N - 1] = POP(other);\n      solve_local(A);\n      return;\n\
    \    }\n    // .23.10. \u5168\u7A2E\u985E\u767B\u5834\u306F\u3057\u3066\u3044\u308B\
    \n    // \u3084\u3063\u3071\u308A\u3060\u3044\u305F\u3044\u540C\u3058\u3053\u3068\
    \u3092\u3084\u308C\u3070\u3088\u3044\n\n    vc<int> I;\n    FOR(i, 1, N - 1) {\n\
    \      I.eb(i);\n      while (len(I) >= 3) {\n        int a = I[len(I) - 3];\n\
    \        int b = I[len(I) - 2];\n        int c = I[len(I) - 1];\n        if (A[a]\
    \ == -1 && A[b] != -1 && A[c] != -1) {\n          A[a] = A[c];\n          POP(I),\
    \ POP(I);\n        }\n        elif (A[a] != -1 && A[b] != -1 && A[c] == -1) {\n\
    \          A[c] = A[a];\n          POP(I), POP(I);\n        }\n        else break;\n\
    \      }\n    }\n    assert(len(I) == 3);\n    A[0] = A[N - 1] = A[I[1]];\n  };\n\
    \n  if (A[0] == -1) {\n    vc<int> I;\n    FS.enumerate(0, len(A), [&](int i)\
    \ -> void { I.eb(i); });\n    vc<int> B = rearrange(A, I);\n    solve_local_2(B);\n\
    \    FOR(i, len(I)) A[I[i]] = B[i];\n  }\n\n  // check\n  if (MAX(A) >= N) return\
    \ {};\n  if (MIN(A) == -1) return {};\n  vc<int> vis(N);\n  vc<int> path = {A[0]};\n\
    \  FOR(i, 1, len(A)) {\n    int v = A[i];\n    if (len(path) >= 2 && path[len(path)\
    \ - 2] == v) {\n      POP(path);\n    } else {\n      if (vis[v]) return {};\n\
    \      path.eb(v);\n      vis[v] = 1;\n    }\n  }\n  if (len(path) != 1) return\
    \ {};\n  return A;\n}\n"
  dependsOn:
  - ds/decremental_fastset.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/restore_euler_tour.hpp
  requiredBy: []
  timestamp: '2026-02-05 01:08:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/restore_euler_tour.hpp
layout: document
redirect_from:
- /library/graph/restore_euler_tour.hpp
- /library/graph/restore_euler_tour.hpp.html
title: graph/restore_euler_tour.hpp
---
