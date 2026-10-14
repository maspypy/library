---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
    title: test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/npcapc_2024/tasks/npcapc_2024_j
    - https://codeforces.com/blog/entry/111290
    - https://codeforces.com/gym/421334/problem/A
  bundledCode: "#line 1 \"seq/permutation_group_basis.hpp\"\n\n// https://codeforces.com/blog/entry/111290\n\
    // https://codeforces.com/gym/421334/problem/A\n// https://atcoder.jp/contests/npcapc_2024/tasks/npcapc_2024_j\n\
    template <int NMAX>\nstruct Permutation_Group_Basis {\n  using A = array<u8, NMAX>;\n\
    \  int n;\n  // Basis[i]: i \u672A\u6E80\u306F\u56FA\u5B9A\u3057\u3066 i \u3092\
    \u52D5\u304B\u3059\u90E8\u5206\n  // \u4F5C\u308C\u308B\u7FA4\uFF1Ag=g[0]g[1]...g[n-1]\n\
    \  // g[i]: i \u672A\u6E80\u3092\u56FA\u5B9A\u3057\u3066 i \u3092\u52D5\u304B\u3059\
    \u5199\u50CF\n  // g \u304B\u3089 g[i] \u3092\u5FA9\u5143\u3059\u308B\u306B\u306F\
    \uFF0C\u5C0F\u3055\u3044 i \u304B\u3089\u9806\u306B\u6C7A\u3081\u308B\n  vvc<A>\
    \ Basis;\n\n  // q := p\n  void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i]\
    \ = p[i]; }\n  // r := pq\n  void op(int lv, const A& p, A& q, A& r) { FOR(i,\
    \ lv, n) r[i] = p[q[i]]; }\n  // q := inv(p)\n  void inv(int lv, const A& p, A&\
    \ q) { FOR(i, lv, n) q[p[i]] = i; }\n\n  // N^2 \u500B\u4EE5\u4E0B\u751F\u6210\
    \u5143\u3092 sims filter \u3067\u7BA1\u7406\n  struct S {\n    int n, lv;\n  \
    \  A dat[NMAX][NMAX];\n    A idat[NMAX][NMAX];\n    bool exist[NMAX][NMAX];\n\
    \    S(int n, int lv) : n(n), lv(lv) { FOR(i, NMAX) FOR(j, NMAX) exist[i][j] =\
    \ 0; }\n    void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i] = p[i]; }\n\
    \    void op(int lv, const A& p, A& q, A& r) { FOR(i, lv, n) r[i] = p[q[i]]; }\n\
    \    void inv(int lv, const A& p, A& q) { FOR(i, lv, n) q[p[i]] = i; }\n    void\
    \ add(A& p) {\n      static A tmp;\n      FOR(i, lv, n) {\n        if (p[i] ==\
    \ i) continue;\n        if (!exist[i][p[i]]) {\n          cp(i, p, dat[i][p[i]]);\n\
    \          inv(i, p, idat[i][p[i]]);\n          exist[i][p[i]] = 1;\n        \
    \  break;\n        }\n        op(i, idat[i][p[i]], p, tmp);\n        cp(i, tmp,\
    \ p);\n      }\n    }\n    vc<A> get_all() {\n      vc<A> ANS;\n      FOR(i, lv,\
    \ n) {\n        FOR(j, i, n) {\n          if (!exist[i][j]) continue;\n      \
    \    A a = dat[i][j];\n          FOR(k, i) a[k] = k;\n          ANS.eb(a);\n \
    \       }\n      }\n      return ANS;\n    }\n  };\n\n  Permutation_Group_Basis(int\
    \ n, vvc<int> generator) : n(n), Basis(n) {\n    S gen(n, 0);\n    for (auto&\
    \ pp: generator) {\n      assert(len(pp) == n);\n      A a;\n      FOR(i, n) a[i]\
    \ = pp[i];\n      gen.add(a);\n    }\n    FOR(lv, n) gen = step(gen);\n  }\n\n\
    private:\n  S step(S gen) {\n    auto X = gen.get_all();\n    int lv = gen.lv;\n\
    \    vc<A> basis(n);\n    vc<A> ibasis(n);\n    vc<bool> vis(n);\n    auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n      auto& p = basis[v];\n      for (auto&\
    \ q: X) {\n        int w = q[v];\n        if (vis[w]) continue;\n        vis[w]\
    \ = 1;\n        op(lv, q, p, basis[w]);\n        inv(lv, basis[w], ibasis[w]);\n\
    \        dfs(dfs, w);\n      }\n    };\n    vis[lv] = 1;\n    FOR(i, n) basis[lv][i]\
    \ = ibasis[lv][i] = i;\n    dfs(dfs, lv);\n\n    S nxtgen(n, lv + 1);\n    static\
    \ A tmp, tmp2;\n    FOR(u, lv, n) {\n      if (!vis[u]) continue;\n      FOR(i,\
    \ lv) basis[u][i] = i;\n      Basis[lv].eb(basis[u]);\n      for (auto& s: X)\
    \ {\n        assert(vis[s[u]]);\n        op(lv, ibasis[s[u]], s, tmp);\n     \
    \   op(lv, tmp, basis[u], tmp2);\n        assert(tmp2[lv] == lv);\n        nxtgen.add(tmp2);\n\
    \      }\n    }\n    return nxtgen;\n  }\n};\n"
  code: "\n// https://codeforces.com/blog/entry/111290\n// https://codeforces.com/gym/421334/problem/A\n\
    // https://atcoder.jp/contests/npcapc_2024/tasks/npcapc_2024_j\ntemplate <int\
    \ NMAX>\nstruct Permutation_Group_Basis {\n  using A = array<u8, NMAX>;\n  int\
    \ n;\n  // Basis[i]: i \u672A\u6E80\u306F\u56FA\u5B9A\u3057\u3066 i \u3092\u52D5\
    \u304B\u3059\u90E8\u5206\n  // \u4F5C\u308C\u308B\u7FA4\uFF1Ag=g[0]g[1]...g[n-1]\n\
    \  // g[i]: i \u672A\u6E80\u3092\u56FA\u5B9A\u3057\u3066 i \u3092\u52D5\u304B\u3059\
    \u5199\u50CF\n  // g \u304B\u3089 g[i] \u3092\u5FA9\u5143\u3059\u308B\u306B\u306F\
    \uFF0C\u5C0F\u3055\u3044 i \u304B\u3089\u9806\u306B\u6C7A\u3081\u308B\n  vvc<A>\
    \ Basis;\n\n  // q := p\n  void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i]\
    \ = p[i]; }\n  // r := pq\n  void op(int lv, const A& p, A& q, A& r) { FOR(i,\
    \ lv, n) r[i] = p[q[i]]; }\n  // q := inv(p)\n  void inv(int lv, const A& p, A&\
    \ q) { FOR(i, lv, n) q[p[i]] = i; }\n\n  // N^2 \u500B\u4EE5\u4E0B\u751F\u6210\
    \u5143\u3092 sims filter \u3067\u7BA1\u7406\n  struct S {\n    int n, lv;\n  \
    \  A dat[NMAX][NMAX];\n    A idat[NMAX][NMAX];\n    bool exist[NMAX][NMAX];\n\
    \    S(int n, int lv) : n(n), lv(lv) { FOR(i, NMAX) FOR(j, NMAX) exist[i][j] =\
    \ 0; }\n    void cp(int lv, const A& p, A& q) { FOR(i, lv, n) q[i] = p[i]; }\n\
    \    void op(int lv, const A& p, A& q, A& r) { FOR(i, lv, n) r[i] = p[q[i]]; }\n\
    \    void inv(int lv, const A& p, A& q) { FOR(i, lv, n) q[p[i]] = i; }\n    void\
    \ add(A& p) {\n      static A tmp;\n      FOR(i, lv, n) {\n        if (p[i] ==\
    \ i) continue;\n        if (!exist[i][p[i]]) {\n          cp(i, p, dat[i][p[i]]);\n\
    \          inv(i, p, idat[i][p[i]]);\n          exist[i][p[i]] = 1;\n        \
    \  break;\n        }\n        op(i, idat[i][p[i]], p, tmp);\n        cp(i, tmp,\
    \ p);\n      }\n    }\n    vc<A> get_all() {\n      vc<A> ANS;\n      FOR(i, lv,\
    \ n) {\n        FOR(j, i, n) {\n          if (!exist[i][j]) continue;\n      \
    \    A a = dat[i][j];\n          FOR(k, i) a[k] = k;\n          ANS.eb(a);\n \
    \       }\n      }\n      return ANS;\n    }\n  };\n\n  Permutation_Group_Basis(int\
    \ n, vvc<int> generator) : n(n), Basis(n) {\n    S gen(n, 0);\n    for (auto&\
    \ pp: generator) {\n      assert(len(pp) == n);\n      A a;\n      FOR(i, n) a[i]\
    \ = pp[i];\n      gen.add(a);\n    }\n    FOR(lv, n) gen = step(gen);\n  }\n\n\
    private:\n  S step(S gen) {\n    auto X = gen.get_all();\n    int lv = gen.lv;\n\
    \    vc<A> basis(n);\n    vc<A> ibasis(n);\n    vc<bool> vis(n);\n    auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n      auto& p = basis[v];\n      for (auto&\
    \ q: X) {\n        int w = q[v];\n        if (vis[w]) continue;\n        vis[w]\
    \ = 1;\n        op(lv, q, p, basis[w]);\n        inv(lv, basis[w], ibasis[w]);\n\
    \        dfs(dfs, w);\n      }\n    };\n    vis[lv] = 1;\n    FOR(i, n) basis[lv][i]\
    \ = ibasis[lv][i] = i;\n    dfs(dfs, lv);\n\n    S nxtgen(n, lv + 1);\n    static\
    \ A tmp, tmp2;\n    FOR(u, lv, n) {\n      if (!vis[u]) continue;\n      FOR(i,\
    \ lv) basis[u][i] = i;\n      Basis[lv].eb(basis[u]);\n      for (auto& s: X)\
    \ {\n        assert(vis[s[u]]);\n        op(lv, ibasis[s[u]], s, tmp);\n     \
    \   op(lv, tmp, basis[u], tmp2);\n        assert(tmp2[lv] == lv);\n        nxtgen.add(tmp2);\n\
    \      }\n    }\n    return nxtgen;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/permutation_group_basis.hpp
  requiredBy: []
  timestamp: '2024-10-07 20:17:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/permtation_group_basis_npcapc2024j.test.cpp
documentation_of: seq/permutation_group_basis.hpp
layout: document
redirect_from:
- /library/seq/permutation_group_basis.hpp
- /library/seq/permutation_group_basis.hpp.html
title: seq/permutation_group_basis.hpp
---
