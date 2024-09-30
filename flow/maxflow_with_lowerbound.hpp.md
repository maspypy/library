---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc285g.test.cpp
    title: test/5_atcoder/abc285g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow_with_lowerbound.hpp\"\n\ntemplate <typename\
    \ Cap>\nstruct MaxFlow_With_LowerBound {\n  int N, s, t, S, T;\n  Cap flow_ans;\n\
    \  bool prepared = 0;\n\n  struct Edge_raw {\n    int frm, to;\n    Cap lo, hi;\n\
    \    Edge_raw(int frm, int to, Cap lo, Cap hi) : frm(frm), to(to), lo(lo), hi(hi){};\n\
    \  };\n  vc<Edge_raw> dat;\n\n  MaxFlow_With_LowerBound(int N, int s, int t) :\
    \ N(N), s(s), t(t), S(N), T(N + 1), flow_ans(0) {\n    assert(0 <= s && s < N);\n\
    \    assert(0 <= t && t < N);\n  }\n  void add(int frm, int to, Cap lo, Cap hi)\
    \ {\n    assert(!prepared);\n    assert(0 <= frm && frm < N);\n    assert(0 <=\
    \ to && to < N);\n    assert(Cap(0) <= lo && lo <= hi);\n    dat.eb(Edge_raw(frm,\
    \ to, lo, hi));\n  }\n\n  struct Edge {\n    int rev, to;\n    Cap cap, flow;\n\
    \  };\n\n  vc<Edge> G;\n  vc<int> indptr;\n  vc<int> idx;\n  vc<int> level, que,\
    \ prog;\n\n  void debug() {\n    print(\"frm,to,lo,hi\");\n    for (auto& e: dat)\
    \ print(e.frm, e.to, e.lo, e.hi);\n  }\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = 1;\n    int M = len(dat);\n    idx.assign(6 * M, -1);\n    vc<int>\
    \ cnt(N + 2);\n    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n     \
    \ if (frm == to) continue;\n      if (lo < hi) cnt[frm]++, cnt[to]++;\n      if\
    \ (0 < lo) cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;\n    }\n    indptr = cumsum<int>(cnt);\n\
    \    int m = indptr.back();\n    G.resize(m);\n    vc<int> prog = indptr;\n  \
    \  auto add = [&](int i, int j, int a, int b, Cap c) -> void {\n      int p =\
    \ prog[a]++, q = prog[b]++;\n      idx[i] = p, idx[j] = q;\n      G[p] = {q, b,\
    \ c, 0};\n      G[q] = {p, a, 0, 0};\n    };\n    FOR(i, M) {\n      auto [frm,\
    \ to, lo, hi] = dat[i];\n      if (frm == to) continue;\n      if (lo < hi) add(6\
    \ * i + 0, 6 * i + 1, frm, to, hi - lo);\n      if (0 < lo) {\n        add(6 *\
    \ i + 2, 6 * i + 3, S, to, lo);\n        add(6 * i + 4, 6 * i + 5, frm, T, lo);\n\
    \        cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;\n      }\n    }\n  }\n\n \
    \ Cap flow() {\n    build();\n    Cap a = flow_st(S, T), b = flow_st(S, t), c\
    \ = flow_st(s, T), d = flow_st(s, t);\n    bool valid = 1;\n    int M = len(dat);\n\
    \    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n      if (lo > 0 &&\
    \ G[idx[6 * i + 2]].cap > 0) valid = 0;\n      if (lo > 0 && G[idx[6 * i + 4]].cap\
    \ > 0) valid = 0;\n    }\n    if (!valid) return flow_ans = -1;\n    assert(a\
    \ + b == a + c && c + d == b + d);\n    return flow_ans = c + d;\n  }\n\n  void\
    \ set_level(int s) {\n    level.assign(N + 2, infty<int>);\n    que.resize(N +\
    \ 2);\n    int ql = 0, qr = 0;\n    auto upd = [&](int v, int d) -> void {\n \
    \     if (chmin(level[v], d)) que[qr++] = v;\n    };\n    upd(s, 0);\n    while\
    \ (ql < qr) {\n      int v = que[ql++];\n      FOR(i, indptr[v], indptr[v + 1])\
    \ {\n        auto& e = G[i];\n        if (e.cap > 0) upd(e.to, level[v] + 1);\n\
    \      }\n    }\n  }\n\n  Cap flow_dfs(int s, int t) {\n    prog = indptr;\n \
    \   auto dfs = [&](auto& dfs, int v, Cap lim) -> Cap {\n      if (v == t) return\
    \ lim;\n      Cap res = 0;\n      for (int& i = prog[v]; i < indptr[v + 1]; ++i)\
    \ {\n        auto& e = G[i];\n        if (e.cap > 0 && level[e.to] == level[v]\
    \ + 1) {\n          Cap a = dfs(dfs, e.to, min(lim, e.cap));\n          if (a\
    \ == Cap(0)) continue;\n          e.cap -= a, e.flow += a;\n          G[e.rev].cap\
    \ += a, G[e.rev].flow -= a;\n          res += a, lim -= a;\n          if (lim\
    \ == Cap(0)) break;\n        }\n      }\n      return res;\n    };\n    return\
    \ dfs(dfs, s, infty<Cap>);\n  }\n\n  Cap flow_st(int s, int t) {\n    Cap ans\
    \ = 0;\n    while (1) {\n      set_level(s);\n      if (level[t] == infty<int>)\
    \ break;\n      ans += flow_dfs(s, t);\n    }\n    return ans;\n  }\n\n  // add\
    \ \u3057\u305F\u9806\u306B\u3072\u3068\u3068\u304A\u308A\n  vc<Cap> get_flow_result()\
    \ {\n    assert(flow_ans != Cap(-1));\n    int M = len(dat);\n    vc<Cap> res(M);\n\
    \    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n      Cap flow = (lo\
    \ < hi ? G[idx[6 * i + 1]].cap + lo : lo);\n      // print(frm, to, lo, hi, flow);\n\
    \      res[i] = flow;\n    }\n    return res;\n  }\n};\n"
  code: "\ntemplate <typename Cap>\nstruct MaxFlow_With_LowerBound {\n  int N, s,\
    \ t, S, T;\n  Cap flow_ans;\n  bool prepared = 0;\n\n  struct Edge_raw {\n   \
    \ int frm, to;\n    Cap lo, hi;\n    Edge_raw(int frm, int to, Cap lo, Cap hi)\
    \ : frm(frm), to(to), lo(lo), hi(hi){};\n  };\n  vc<Edge_raw> dat;\n\n  MaxFlow_With_LowerBound(int\
    \ N, int s, int t) : N(N), s(s), t(t), S(N), T(N + 1), flow_ans(0) {\n    assert(0\
    \ <= s && s < N);\n    assert(0 <= t && t < N);\n  }\n  void add(int frm, int\
    \ to, Cap lo, Cap hi) {\n    assert(!prepared);\n    assert(0 <= frm && frm <\
    \ N);\n    assert(0 <= to && to < N);\n    assert(Cap(0) <= lo && lo <= hi);\n\
    \    dat.eb(Edge_raw(frm, to, lo, hi));\n  }\n\n  struct Edge {\n    int rev,\
    \ to;\n    Cap cap, flow;\n  };\n\n  vc<Edge> G;\n  vc<int> indptr;\n  vc<int>\
    \ idx;\n  vc<int> level, que, prog;\n\n  void debug() {\n    print(\"frm,to,lo,hi\"\
    );\n    for (auto& e: dat) print(e.frm, e.to, e.lo, e.hi);\n  }\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = 1;\n    int M = len(dat);\n    idx.assign(6\
    \ * M, -1);\n    vc<int> cnt(N + 2);\n    FOR(i, M) {\n      auto [frm, to, lo,\
    \ hi] = dat[i];\n      if (frm == to) continue;\n      if (lo < hi) cnt[frm]++,\
    \ cnt[to]++;\n      if (0 < lo) cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;\n \
    \   }\n    indptr = cumsum<int>(cnt);\n    int m = indptr.back();\n    G.resize(m);\n\
    \    vc<int> prog = indptr;\n    auto add = [&](int i, int j, int a, int b, Cap\
    \ c) -> void {\n      int p = prog[a]++, q = prog[b]++;\n      idx[i] = p, idx[j]\
    \ = q;\n      G[p] = {q, b, c, 0};\n      G[q] = {p, a, 0, 0};\n    };\n    FOR(i,\
    \ M) {\n      auto [frm, to, lo, hi] = dat[i];\n      if (frm == to) continue;\n\
    \      if (lo < hi) add(6 * i + 0, 6 * i + 1, frm, to, hi - lo);\n      if (0\
    \ < lo) {\n        add(6 * i + 2, 6 * i + 3, S, to, lo);\n        add(6 * i +\
    \ 4, 6 * i + 5, frm, T, lo);\n        cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;\n\
    \      }\n    }\n  }\n\n  Cap flow() {\n    build();\n    Cap a = flow_st(S, T),\
    \ b = flow_st(S, t), c = flow_st(s, T), d = flow_st(s, t);\n    bool valid = 1;\n\
    \    int M = len(dat);\n    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n\
    \      if (lo > 0 && G[idx[6 * i + 2]].cap > 0) valid = 0;\n      if (lo > 0 &&\
    \ G[idx[6 * i + 4]].cap > 0) valid = 0;\n    }\n    if (!valid) return flow_ans\
    \ = -1;\n    assert(a + b == a + c && c + d == b + d);\n    return flow_ans =\
    \ c + d;\n  }\n\n  void set_level(int s) {\n    level.assign(N + 2, infty<int>);\n\
    \    que.resize(N + 2);\n    int ql = 0, qr = 0;\n    auto upd = [&](int v, int\
    \ d) -> void {\n      if (chmin(level[v], d)) que[qr++] = v;\n    };\n    upd(s,\
    \ 0);\n    while (ql < qr) {\n      int v = que[ql++];\n      FOR(i, indptr[v],\
    \ indptr[v + 1]) {\n        auto& e = G[i];\n        if (e.cap > 0) upd(e.to,\
    \ level[v] + 1);\n      }\n    }\n  }\n\n  Cap flow_dfs(int s, int t) {\n    prog\
    \ = indptr;\n    auto dfs = [&](auto& dfs, int v, Cap lim) -> Cap {\n      if\
    \ (v == t) return lim;\n      Cap res = 0;\n      for (int& i = prog[v]; i < indptr[v\
    \ + 1]; ++i) {\n        auto& e = G[i];\n        if (e.cap > 0 && level[e.to]\
    \ == level[v] + 1) {\n          Cap a = dfs(dfs, e.to, min(lim, e.cap));\n   \
    \       if (a == Cap(0)) continue;\n          e.cap -= a, e.flow += a;\n     \
    \     G[e.rev].cap += a, G[e.rev].flow -= a;\n          res += a, lim -= a;\n\
    \          if (lim == Cap(0)) break;\n        }\n      }\n      return res;\n\
    \    };\n    return dfs(dfs, s, infty<Cap>);\n  }\n\n  Cap flow_st(int s, int\
    \ t) {\n    Cap ans = 0;\n    while (1) {\n      set_level(s);\n      if (level[t]\
    \ == infty<int>) break;\n      ans += flow_dfs(s, t);\n    }\n    return ans;\n\
    \  }\n\n  // add \u3057\u305F\u9806\u306B\u3072\u3068\u3068\u304A\u308A\n  vc<Cap>\
    \ get_flow_result() {\n    assert(flow_ans != Cap(-1));\n    int M = len(dat);\n\
    \    vc<Cap> res(M);\n    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n\
    \      Cap flow = (lo < hi ? G[idx[6 * i + 1]].cap + lo : lo);\n      // print(frm,\
    \ to, lo, hi, flow);\n      res[i] = flow;\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow_with_lowerbound.hpp
  requiredBy: []
  timestamp: '2024-08-27 21:30:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/5_atcoder/abc285g.test.cpp
documentation_of: flow/maxflow_with_lowerbound.hpp
layout: document
redirect_from:
- /library/flow/maxflow_with_lowerbound.hpp
- /library/flow/maxflow_with_lowerbound.hpp.html
title: flow/maxflow_with_lowerbound.hpp
---
