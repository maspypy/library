---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/extended_lichao.test.cpp
    title: test/1_mytest/extended_lichao.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/86731)
  bundledCode: "#line 1 \"convex/extended_lichao.hpp\"\n// https://codeforces.com/blog/entry/86731)\n\
    // chmin(A[x],ax+b), A[x]+=ax+b, get A[x]\ntemplate <bool PERSISTENT, bool MINIMIZE>\n\
    struct Extended_LiChao_Tree {\n  // \u5165\u51FA\u529B\u4EE5\u5916\u3067\u306F\
    \ minimize \u3057\u3066\u3044\u308B\n  struct F {\n    ll a, b;\n    F(ll a =\
    \ 0, ll b = 0) : a(a), b(b) {}\n    ll operator()(ll x) { return a * x + b; }\n\
    \    void add(F &other) {\n      if (b == infty<ll> || other.b == infty<ll>) {\n\
    \        a = 0, b = infty<ll>;\n      } else {\n        a += other.a, b += other.b;\n\
    \      }\n    }\n  };\n\n  vi X;\n  vc<F> dat, lazy;\n  int n, log, size;\n\n\
    \  Extended_LiChao_Tree(vi X_) : X(X_) {\n    UNIQUE(X);\n    n = len(X), log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, F(0, infty<ll>));\n    lazy.assign(size << 1, F(0, 0));\n  }\n\n  // O(logN).\
    \ f(x) := min(f(x), ax+b).\n  void chmin_line(ll a, ll b) {\n    static_assert(MINIMIZE);\n\
    \    chmin_line_rec(1, F(a, b), 0, n);\n  }\n\n  // O(logN). f(x) := max(f(x),\
    \ ax+b).\n  void chmax_line(ll a, ll b) {\n    static_assert(!MINIMIZE);\n   \
    \ chmin_line_rec(1, F(-a, -b), 0, n);\n  }\n\n  // O(log^2N). f(x) := min(f(x),\
    \ ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\
    \u56F2.\n  void chmin_segment(ll L, ll R, ll a, ll b) {\n    static_assert(MINIMIZE);\n\
    \    chmin_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  // O(log^2N).\
    \ f(x) := max(f(x), ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066\
    \ X[] \u306E\u7BC4\u56F2.\n  void chmax_setment(ll L, ll R, ll a, ll b) {\n  \
    \  static_assert(MINIMIZE);\n    chmin_segment_rec(1, LB(X, L), LB(X, R), F(a,\
    \ b), 0, n);\n  }\n\n  // O(1). f(x) := f(x)+ax+b.\n  void add_line(ll a, ll b)\
    \ {\n    if (!MINIMIZE) a = -a, b = -b;\n    add_segment_rec(1, 0, n, F(a, b),\
    \ 0, n);\n  }\n\n  // O(log^2N). f(x) := f(x)+ax+b for L<=x<R.\n  // index \u3067\
    \u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\u56F2.\n  void add_segment(ll L, ll\
    \ R, ll a, ll b) {\n    if (!MINIMIZE) a = -a, b = -b;\n    add_segment_rec(1,\
    \ LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  ll query(ll x) {\n    int idx\
    \ = LB(X, x);\n    assert(0 <= idx && idx < n && X[idx] == x);\n    return query_rec(1,\
    \ idx, 0, n, F(0, 0));\n  }\n\nprivate:\n  void push(int i) {\n    dat[2 * i +\
    \ 0].add(lazy[i]), lazy[2 * i + 0].add(lazy[i]);\n    dat[2 * i + 1].add(lazy[i]),\
    \ lazy[2 * i + 1].add(lazy[i]);\n    lazy[i] = F(0, 0);\n  }\n\n  void chmin_segment_rec(int\
    \ i, ll xl, ll xr, F f, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr,\
    \ node_r);\n    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n\
    \      ll node_m = (node_l + node_r) / 2;\n      push(i);\n      chmin_segment_rec(2\
    \ * i + 0, xl, xr, f, node_l, node_m);\n      chmin_segment_rec(2 * i + 1, xl,\
    \ xr, f, node_m, node_r);\n      return;\n    }\n    chmin_line_rec(i, f, node_l,\
    \ node_r);\n  }\n\n  void chmin_line_rec(int i, F f, ll node_l, ll node_r) {\n\
    \    F g = dat[i];\n    ll fl = f(X[node_l]), fr = f(X[node_r - 1]);\n    ll gl\
    \ = g(X[node_l]), gr = g(X[node_r - 1]);\n    if (fl <= gl && fr <= gr) {\n  \
    \    dat[i] = f;\n      return;\n    }\n    if (fl >= gl && fr >= gr) { return;\
    \ }\n    ll node_m = (node_l + node_r) / 2;\n    ll fm = f(X[node_m]), gm = g(X[node_m]);\n\
    \    push(i);\n    if (fm < gm && fl < gl) dat[i] = f, chmin_line_rec(2 * i +\
    \ 1, g, node_m, node_r);\n    elif (fm < gm && fl >= gl) dat[i] = f, chmin_line_rec(2\
    \ * i + 0, g, node_l, node_m);\n    elif (fm >= gm && gl < fl) chmin_line_rec(2\
    \ * i + 1, f, node_m, node_r);\n    elif (fm >= gm && gl >= fl) chmin_line_rec(2\
    \ * i + 0, f, node_l, node_m);\n  }\n\n  void add_segment_rec(int i, ll xl, ll\
    \ xr, F f, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n\
    \    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      push(i);\n      chmin_line_rec(2 * i + 0, dat[i],\
    \ node_l, node_m);\n      chmin_line_rec(2 * i + 1, dat[i], node_m, node_r);\n\
    \      dat[i] = F(0, infty<ll>);\n      add_segment_rec(2 * i + 0, xl, xr, f,\
    \ node_l, node_m);\n      add_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);\n\
    \      return;\n    }\n    dat[i].add(f), lazy[i].add(f);\n  }\n\n  ll query_rec(int\
    \ i, ll x, ll node_l, ll node_r, F laz) {\n    ll res = dat[i](X[x]);\n    if\
    \ (res < infty<ll>) res += laz(X[x]);\n    ll node_m = (node_l + node_r) / 2;\n\
    \    laz.add(lazy[i]);\n    if (node_r == node_l + 1) return res;\n    if (x <\
    \ node_m) { chmin(res, query_rec(2 * i + 0, x, node_l, node_m, laz)); }\n    if\
    \ (x >= node_m) { chmin(res, query_rec(2 * i + 1, x, node_m, node_r, laz)); }\n\
    \    return res;\n  }\n};\n"
  code: "// https://codeforces.com/blog/entry/86731)\n// chmin(A[x],ax+b), A[x]+=ax+b,\
    \ get A[x]\ntemplate <bool PERSISTENT, bool MINIMIZE>\nstruct Extended_LiChao_Tree\
    \ {\n  // \u5165\u51FA\u529B\u4EE5\u5916\u3067\u306F minimize \u3057\u3066\u3044\
    \u308B\n  struct F {\n    ll a, b;\n    F(ll a = 0, ll b = 0) : a(a), b(b) {}\n\
    \    ll operator()(ll x) { return a * x + b; }\n    void add(F &other) {\n   \
    \   if (b == infty<ll> || other.b == infty<ll>) {\n        a = 0, b = infty<ll>;\n\
    \      } else {\n        a += other.a, b += other.b;\n      }\n    }\n  };\n\n\
    \  vi X;\n  vc<F> dat, lazy;\n  int n, log, size;\n\n  Extended_LiChao_Tree(vi\
    \ X_) : X(X_) {\n    UNIQUE(X);\n    n = len(X), log = 1;\n    while ((1 << log)\
    \ < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, F(0, infty<ll>));\n\
    \    lazy.assign(size << 1, F(0, 0));\n  }\n\n  // O(logN). f(x) := min(f(x),\
    \ ax+b).\n  void chmin_line(ll a, ll b) {\n    static_assert(MINIMIZE);\n    chmin_line_rec(1,\
    \ F(a, b), 0, n);\n  }\n\n  // O(logN). f(x) := max(f(x), ax+b).\n  void chmax_line(ll\
    \ a, ll b) {\n    static_assert(!MINIMIZE);\n    chmin_line_rec(1, F(-a, -b),\
    \ 0, n);\n  }\n\n  // O(log^2N). f(x) := min(f(x), ax+b) for L<=x<R.\n  // index\
    \ \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\u56F2.\n  void chmin_segment(ll\
    \ L, ll R, ll a, ll b) {\n    static_assert(MINIMIZE);\n    chmin_segment_rec(1,\
    \ LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  // O(log^2N). f(x) := max(f(x),\
    \ ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\
    \u56F2.\n  void chmax_setment(ll L, ll R, ll a, ll b) {\n    static_assert(MINIMIZE);\n\
    \    chmin_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  // O(1).\
    \ f(x) := f(x)+ax+b.\n  void add_line(ll a, ll b) {\n    if (!MINIMIZE) a = -a,\
    \ b = -b;\n    add_segment_rec(1, 0, n, F(a, b), 0, n);\n  }\n\n  // O(log^2N).\
    \ f(x) := f(x)+ax+b for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[]\
    \ \u306E\u7BC4\u56F2.\n  void add_segment(ll L, ll R, ll a, ll b) {\n    if (!MINIMIZE)\
    \ a = -a, b = -b;\n    add_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);\n\
    \  }\n\n  ll query(ll x) {\n    int idx = LB(X, x);\n    assert(0 <= idx && idx\
    \ < n && X[idx] == x);\n    return query_rec(1, idx, 0, n, F(0, 0));\n  }\n\n\
    private:\n  void push(int i) {\n    dat[2 * i + 0].add(lazy[i]), lazy[2 * i +\
    \ 0].add(lazy[i]);\n    dat[2 * i + 1].add(lazy[i]), lazy[2 * i + 1].add(lazy[i]);\n\
    \    lazy[i] = F(0, 0);\n  }\n\n  void chmin_segment_rec(int i, ll xl, ll xr,\
    \ F f, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n  \
    \  if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      push(i);\n      chmin_segment_rec(2 * i + 0,\
    \ xl, xr, f, node_l, node_m);\n      chmin_segment_rec(2 * i + 1, xl, xr, f, node_m,\
    \ node_r);\n      return;\n    }\n    chmin_line_rec(i, f, node_l, node_r);\n\
    \  }\n\n  void chmin_line_rec(int i, F f, ll node_l, ll node_r) {\n    F g = dat[i];\n\
    \    ll fl = f(X[node_l]), fr = f(X[node_r - 1]);\n    ll gl = g(X[node_l]), gr\
    \ = g(X[node_r - 1]);\n    if (fl <= gl && fr <= gr) {\n      dat[i] = f;\n  \
    \    return;\n    }\n    if (fl >= gl && fr >= gr) { return; }\n    ll node_m\
    \ = (node_l + node_r) / 2;\n    ll fm = f(X[node_m]), gm = g(X[node_m]);\n   \
    \ push(i);\n    if (fm < gm && fl < gl) dat[i] = f, chmin_line_rec(2 * i + 1,\
    \ g, node_m, node_r);\n    elif (fm < gm && fl >= gl) dat[i] = f, chmin_line_rec(2\
    \ * i + 0, g, node_l, node_m);\n    elif (fm >= gm && gl < fl) chmin_line_rec(2\
    \ * i + 1, f, node_m, node_r);\n    elif (fm >= gm && gl >= fl) chmin_line_rec(2\
    \ * i + 0, f, node_l, node_m);\n  }\n\n  void add_segment_rec(int i, ll xl, ll\
    \ xr, F f, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n\
    \    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      push(i);\n      chmin_line_rec(2 * i + 0, dat[i],\
    \ node_l, node_m);\n      chmin_line_rec(2 * i + 1, dat[i], node_m, node_r);\n\
    \      dat[i] = F(0, infty<ll>);\n      add_segment_rec(2 * i + 0, xl, xr, f,\
    \ node_l, node_m);\n      add_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);\n\
    \      return;\n    }\n    dat[i].add(f), lazy[i].add(f);\n  }\n\n  ll query_rec(int\
    \ i, ll x, ll node_l, ll node_r, F laz) {\n    ll res = dat[i](X[x]);\n    if\
    \ (res < infty<ll>) res += laz(X[x]);\n    ll node_m = (node_l + node_r) / 2;\n\
    \    laz.add(lazy[i]);\n    if (node_r == node_l + 1) return res;\n    if (x <\
    \ node_m) { chmin(res, query_rec(2 * i + 0, x, node_l, node_m, laz)); }\n    if\
    \ (x >= node_m) { chmin(res, query_rec(2 * i + 1, x, node_m, node_r, laz)); }\n\
    \    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/extended_lichao.hpp
  requiredBy: []
  timestamp: '2025-01-09 20:26:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/extended_lichao.test.cpp
documentation_of: convex/extended_lichao.hpp
layout: document
redirect_from:
- /library/convex/extended_lichao.hpp
- /library/convex/extended_lichao.hpp.html
title: convex/extended_lichao.hpp
---
