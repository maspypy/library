---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/extended_lichao_2.test.cpp
    title: test/1_mytest/extended_lichao_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/86731)
  bundledCode: "#line 1 \"convex/extended_lichao_2.hpp\"\n// https://codeforces.com/blog/entry/86731)\n\
    // chmin(A[x],ax+b), A[x]+=b, get range min\ntemplate <bool MINIMIZE>\nstruct\
    \ Extended_LiChao_Tree_2 {\n  // \u5165\u51FA\u529B\u4EE5\u5916\u3067\u306F minimize\
    \ \u3057\u3066\u3044\u308B\n  struct F {\n    ll a, b;\n    F(ll a = 0, ll b =\
    \ 0) : a(a), b(b) {}\n    ll operator()(ll x) { return a * x + b; }\n    void\
    \ add(ll c) {\n      if (b != infty<ll>) b += c;\n    }\n  };\n\n  vi X, lazy;\n\
    \  vc<F> dat;\n  vi val;\n  int n, log, size;\n\n  Extended_LiChao_Tree_2(vi X_)\
    \ : X(X_) {\n    UNIQUE(X);\n    n = len(X), log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, F(0, infty<ll>));\n\
    \    lazy.assign(size << 1, 0);\n    val.assign(size << 1, infty<ll>);\n  }\n\n\
    \  // O(logN). f(x) := min(f(x), ax+b).\n  void chmin_line(ll a, ll b) {\n   \
    \ static_assert(MINIMIZE);\n    chmin_line_rec(1, F(a, b), 0, n);\n  }\n\n  //\
    \ O(logN). f(x) := max(f(x), ax+b).\n  void chmax_line(ll a, ll b) {\n    static_assert(!MINIMIZE);\n\
    \    chmin_line_rec(1, F(-a, -b), 0, n);\n  }\n\n  // O(log^2N). f(x) := min(f(x),\
    \ ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\
    \u56F2.\n  void chmin_segment(ll L, ll R, ll a, ll b) {\n    static_assert(MINIMIZE);\n\
    \    chmin_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  // O(log^2N).\
    \ f(x) := max(f(x), ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066\
    \ X[] \u306E\u7BC4\u56F2.\n  void chmax_segment(ll L, ll R, ll a, ll b) {\n  \
    \  static_assert(!MINIMIZE);\n    chmin_segment_rec(1, LB(X, L), LB(X, R), F(-a,\
    \ -b), 0, n);\n  }\n\n  // O(1). f(x) := f(x)+b.\n  void add_line(ll b) {\n  \
    \  if (!MINIMIZE) b = -b;\n    add_segment_rec(1, 0, n, b, 0, n);\n  }\n\n  //\
    \ O(log^2N). f(x) := f(x)+b for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066\
    \ X[] \u306E\u7BC4\u56F2.\n  void add_segment(ll L, ll R, ll b) {\n    if (!MINIMIZE)\
    \ b = -b;\n    add_segment_rec(1, LB(X, L), LB(X, R), b, 0, n);\n  }\n\n  ll query(ll\
    \ L, ll R) {\n    ll ans = query_rec(1, LB(X, L), LB(X, R), 0, n, 0);\n    return\
    \ (MINIMIZE ? ans : -ans);\n  }\n\nprivate:\n  void push(int i) {\n    dat[2 *\
    \ i + 0].add(lazy[i]), lazy[2 * i + 0] += lazy[i];\n    dat[2 * i + 1].add(lazy[i]),\
    \ lazy[2 * i + 1] += lazy[i];\n    if (val[2 * i + 0] < infty<ll>) val[2 * i +\
    \ 0] += lazy[i];\n    if (val[2 * i + 1] < infty<ll>) val[2 * i + 1] += lazy[i];\n\
    \    lazy[i] = 0;\n  }\n\n  void chmin_segment_rec(int i, ll xl, ll xr, F f, ll\
    \ node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n    if (xl\
    \ >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m = (node_l\
    \ + node_r) / 2;\n      push(i);\n      chmin_segment_rec(2 * i + 0, xl, xr, f,\
    \ node_l, node_m);\n      chmin_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);\n\
    \      chmin(val[i], min(val[2 * i + 0], val[2 * i + 1]));\n      return;\n  \
    \  }\n    chmin_line_rec(i, f, node_l, node_r);\n  }\n\n  void chmin_line_rec(int\
    \ i, F f, ll node_l, ll node_r) {\n    F g = dat[i];\n    ll fl = f(X[node_l]),\
    \ fr = f(X[node_r - 1]);\n    ll gl = g(X[node_l]), gr = g(X[node_r - 1]);\n \
    \   chmin(val[i], min(fl, fr));\n    if (fl <= gl && fr <= gr) {\n      dat[i]\
    \ = f;\n      return;\n    }\n    if (fl >= gl && fr >= gr) { return; }\n    ll\
    \ node_m = (node_l + node_r) / 2;\n    ll fm = f(X[node_m]), gm = g(X[node_m]);\n\
    \    push(i);\n    if (fm < gm && fl < gl) dat[i] = f, chmin_line_rec(2 * i +\
    \ 1, g, node_m, node_r);\n    elif (fm < gm && fl >= gl) dat[i] = f, chmin_line_rec(2\
    \ * i + 0, g, node_l, node_m);\n    elif (fm >= gm && gl < fl) chmin_line_rec(2\
    \ * i + 1, f, node_m, node_r);\n    elif (fm >= gm && gl >= fl) chmin_line_rec(2\
    \ * i + 0, f, node_l, node_m);\n  }\n\n  void add_segment_rec(int i, ll xl, ll\
    \ xr, ll b, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n\
    \    if (xl >= xr) return;\n    if (node_l < xl || xr < node_r) {\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      push(i);\n      chmin_line_rec(2 * i + 0, dat[i],\
    \ node_l, node_m);\n      chmin_line_rec(2 * i + 1, dat[i], node_m, node_r);\n\
    \      dat[i] = F(0, infty<ll>);\n      add_segment_rec(2 * i + 0, xl, xr, b,\
    \ node_l, node_m);\n      add_segment_rec(2 * i + 1, xl, xr, b, node_m, node_r);\n\
    \      val[i] = min(val[2 * i + 0], val[2 * i + 1]);\n      chmin(val[i], dat[i](X[node_l]));\n\
    \      chmin(val[i], dat[i](X[node_r - 1]));\n      return;\n    }\n    dat[i].add(b),\
    \ lazy[i] += b;\n    if (val[i] < infty<ll>) val[i] += b;\n  }\n\n  ll query_rec(int\
    \ i, ll L, ll R, ll node_l, ll node_r, ll laz) {\n    chmax(L, node_l), chmin(R,\
    \ node_r);\n    if (L >= R) return infty<ll>;\n    if (node_l < L || R < node_r)\
    \ {\n      ll node_m = (node_l + node_r) / 2;\n      ll ans = infty<ll>;\n   \
    \   if (dat[i].b != infty<ll>) chmin(ans, min(dat[i](X[L]), dat[i](X[R - 1]))\
    \ + laz);\n      laz += lazy[i];\n      chmin(ans, query_rec(2 * i + 0, L, R,\
    \ node_l, node_m, laz));\n      chmin(ans, query_rec(2 * i + 1, L, R, node_m,\
    \ node_r, laz));\n      return ans;\n    }\n    return (val[i] == infty<ll> ?\
    \ infty<ll> : val[i] + laz);\n  }\n};\n"
  code: "// https://codeforces.com/blog/entry/86731)\n// chmin(A[x],ax+b), A[x]+=b,\
    \ get range min\ntemplate <bool MINIMIZE>\nstruct Extended_LiChao_Tree_2 {\n \
    \ // \u5165\u51FA\u529B\u4EE5\u5916\u3067\u306F minimize \u3057\u3066\u3044\u308B\
    \n  struct F {\n    ll a, b;\n    F(ll a = 0, ll b = 0) : a(a), b(b) {}\n    ll\
    \ operator()(ll x) { return a * x + b; }\n    void add(ll c) {\n      if (b !=\
    \ infty<ll>) b += c;\n    }\n  };\n\n  vi X, lazy;\n  vc<F> dat;\n  vi val;\n\
    \  int n, log, size;\n\n  Extended_LiChao_Tree_2(vi X_) : X(X_) {\n    UNIQUE(X);\n\
    \    n = len(X), log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 <<\
    \ log;\n    dat.assign(size << 1, F(0, infty<ll>));\n    lazy.assign(size << 1,\
    \ 0);\n    val.assign(size << 1, infty<ll>);\n  }\n\n  // O(logN). f(x) := min(f(x),\
    \ ax+b).\n  void chmin_line(ll a, ll b) {\n    static_assert(MINIMIZE);\n    chmin_line_rec(1,\
    \ F(a, b), 0, n);\n  }\n\n  // O(logN). f(x) := max(f(x), ax+b).\n  void chmax_line(ll\
    \ a, ll b) {\n    static_assert(!MINIMIZE);\n    chmin_line_rec(1, F(-a, -b),\
    \ 0, n);\n  }\n\n  // O(log^2N). f(x) := min(f(x), ax+b) for L<=x<R.\n  // index\
    \ \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\u56F2.\n  void chmin_segment(ll\
    \ L, ll R, ll a, ll b) {\n    static_assert(MINIMIZE);\n    chmin_segment_rec(1,\
    \ LB(X, L), LB(X, R), F(a, b), 0, n);\n  }\n\n  // O(log^2N). f(x) := max(f(x),\
    \ ax+b) for L<=x<R.\n  // index \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\
    \u56F2.\n  void chmax_segment(ll L, ll R, ll a, ll b) {\n    static_assert(!MINIMIZE);\n\
    \    chmin_segment_rec(1, LB(X, L), LB(X, R), F(-a, -b), 0, n);\n  }\n\n  // O(1).\
    \ f(x) := f(x)+b.\n  void add_line(ll b) {\n    if (!MINIMIZE) b = -b;\n    add_segment_rec(1,\
    \ 0, n, b, 0, n);\n  }\n\n  // O(log^2N). f(x) := f(x)+b for L<=x<R.\n  // index\
    \ \u3067\u306F\u306A\u304F\u3066 X[] \u306E\u7BC4\u56F2.\n  void add_segment(ll\
    \ L, ll R, ll b) {\n    if (!MINIMIZE) b = -b;\n    add_segment_rec(1, LB(X, L),\
    \ LB(X, R), b, 0, n);\n  }\n\n  ll query(ll L, ll R) {\n    ll ans = query_rec(1,\
    \ LB(X, L), LB(X, R), 0, n, 0);\n    return (MINIMIZE ? ans : -ans);\n  }\n\n\
    private:\n  void push(int i) {\n    dat[2 * i + 0].add(lazy[i]), lazy[2 * i +\
    \ 0] += lazy[i];\n    dat[2 * i + 1].add(lazy[i]), lazy[2 * i + 1] += lazy[i];\n\
    \    if (val[2 * i + 0] < infty<ll>) val[2 * i + 0] += lazy[i];\n    if (val[2\
    \ * i + 1] < infty<ll>) val[2 * i + 1] += lazy[i];\n    lazy[i] = 0;\n  }\n\n\
    \  void chmin_segment_rec(int i, ll xl, ll xr, F f, ll node_l, ll node_r) {\n\
    \    chmax(xl, node_l), chmin(xr, node_r);\n    if (xl >= xr) return;\n    if\
    \ (node_l < xl || xr < node_r) {\n      ll node_m = (node_l + node_r) / 2;\n \
    \     push(i);\n      chmin_segment_rec(2 * i + 0, xl, xr, f, node_l, node_m);\n\
    \      chmin_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);\n      chmin(val[i],\
    \ min(val[2 * i + 0], val[2 * i + 1]));\n      return;\n    }\n    chmin_line_rec(i,\
    \ f, node_l, node_r);\n  }\n\n  void chmin_line_rec(int i, F f, ll node_l, ll\
    \ node_r) {\n    F g = dat[i];\n    ll fl = f(X[node_l]), fr = f(X[node_r - 1]);\n\
    \    ll gl = g(X[node_l]), gr = g(X[node_r - 1]);\n    chmin(val[i], min(fl, fr));\n\
    \    if (fl <= gl && fr <= gr) {\n      dat[i] = f;\n      return;\n    }\n  \
    \  if (fl >= gl && fr >= gr) { return; }\n    ll node_m = (node_l + node_r) /\
    \ 2;\n    ll fm = f(X[node_m]), gm = g(X[node_m]);\n    push(i);\n    if (fm <\
    \ gm && fl < gl) dat[i] = f, chmin_line_rec(2 * i + 1, g, node_m, node_r);\n \
    \   elif (fm < gm && fl >= gl) dat[i] = f, chmin_line_rec(2 * i + 0, g, node_l,\
    \ node_m);\n    elif (fm >= gm && gl < fl) chmin_line_rec(2 * i + 1, f, node_m,\
    \ node_r);\n    elif (fm >= gm && gl >= fl) chmin_line_rec(2 * i + 0, f, node_l,\
    \ node_m);\n  }\n\n  void add_segment_rec(int i, ll xl, ll xr, ll b, ll node_l,\
    \ ll node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n    if (xl >= xr) return;\n\
    \    if (node_l < xl || xr < node_r) {\n      ll node_m = (node_l + node_r) /\
    \ 2;\n      push(i);\n      chmin_line_rec(2 * i + 0, dat[i], node_l, node_m);\n\
    \      chmin_line_rec(2 * i + 1, dat[i], node_m, node_r);\n      dat[i] = F(0,\
    \ infty<ll>);\n      add_segment_rec(2 * i + 0, xl, xr, b, node_l, node_m);\n\
    \      add_segment_rec(2 * i + 1, xl, xr, b, node_m, node_r);\n      val[i] =\
    \ min(val[2 * i + 0], val[2 * i + 1]);\n      chmin(val[i], dat[i](X[node_l]));\n\
    \      chmin(val[i], dat[i](X[node_r - 1]));\n      return;\n    }\n    dat[i].add(b),\
    \ lazy[i] += b;\n    if (val[i] < infty<ll>) val[i] += b;\n  }\n\n  ll query_rec(int\
    \ i, ll L, ll R, ll node_l, ll node_r, ll laz) {\n    chmax(L, node_l), chmin(R,\
    \ node_r);\n    if (L >= R) return infty<ll>;\n    if (node_l < L || R < node_r)\
    \ {\n      ll node_m = (node_l + node_r) / 2;\n      ll ans = infty<ll>;\n   \
    \   if (dat[i].b != infty<ll>) chmin(ans, min(dat[i](X[L]), dat[i](X[R - 1]))\
    \ + laz);\n      laz += lazy[i];\n      chmin(ans, query_rec(2 * i + 0, L, R,\
    \ node_l, node_m, laz));\n      chmin(ans, query_rec(2 * i + 1, L, R, node_m,\
    \ node_r, laz));\n      return ans;\n    }\n    return (val[i] == infty<ll> ?\
    \ infty<ll> : val[i] + laz);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/extended_lichao_2.hpp
  requiredBy: []
  timestamp: '2025-01-09 21:54:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/extended_lichao_2.test.cpp
documentation_of: convex/extended_lichao_2.hpp
layout: document
redirect_from:
- /library/convex/extended_lichao_2.hpp
- /library/convex/extended_lichao_2.hpp.html
title: convex/extended_lichao_2.hpp
---
