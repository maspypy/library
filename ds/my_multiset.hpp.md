---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc241d.test.cpp
    title: test_atcoder/abc241d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/my_multiset.hpp\"\n// \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3068\u3057\u3066\u4F5C\u3063\u3066\u304A\u304F\ntemplate <typename\
    \ T, typename CNT, typename SM, bool PERSISTENT, int NODES>\nstruct My_Multiset\
    \ {\n  struct Node {\n    T idx;\n    Node *l, *r;\n    CNT cnt, sub_cnt;\n  \
    \  SM sub_sm;\n    SM node_sum() { return SM(idx) * SM(cnt); }\n  };\n\n  const\
    \ T L0, R0;\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n  My_Multiset(T\
    \ L0 = -2 * infty<T>, T R0 = 2 * infty<T>)\n      : L0(L0), R0(R0), pid(0) {\n\
    \    pool = new Node[NODES];\n  }\n\n  np new_root() { return nullptr; }\n\n \
    \ np new_node(T idx, const CNT cnt) {\n    pool[pid].idx = idx;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].cnt = cnt, pool[pid].sub_cnt = cnt;\n\
    \    pool[pid].sub_sm = pool[pid].node_sum();\n    return &(pool[pid++]);\n  }\n\
    \n  // (cnt, sm)\n  pair<CNT, SM> get_range(np root, T l, T r) {\n    assert(L0\
    \ <= l && l <= r && r <= R0);\n    if (l == r) return {CNT(0), SM(0)};\n    CNT\
    \ cnt = 0;\n    SM sm = 0;\n    get_range_rec(root, L0, R0, l, r, cnt, sm);\n\
    \    return {cnt, sm};\n  }\n\n  // (cnt, sm)\n  pair<CNT, SM> get_all_range(np\
    \ root) {\n    if (!root) return {CNT(0), SM(0)};\n    return {root->sub_cnt,\
    \ root->sub_sm};\n  }\n\n  np add(np root, T x, CNT cnt) {\n    assert(L0 <= x\
    \ && x < R0);\n    return add_rec(root, L0, R0, x, cnt);\n  }\n\n  // k>=0 \u756A\
    \u76EE\u3068\u3001\u305D\u3053\u307E\u3067\u306E prefix sum\n  pair<T, SM> prefix_kth(np\
    \ root, CNT k) {\n    auto [cnt, sm] = get_all_range(root);\n    assert(k <= cnt);\n\
    \    return prefix_kth_rec(root, L0, R0, k);\n  }\n\n  // \u5927\u304D\u3044\u65B9\
    \u304B\u3089 k>=0 \u756A\u76EE\u3068\u3001\u305D\u3053\u307E\u3067\u306E suffix\
    \ sum\n  pair<T, SM> suffix_kth(np root, CNT k) {\n    auto [cnt, sm] = get_all_range(root);\n\
    \    assert(k <= cnt);\n    return suffix_kth_rec(root, L0, R0, k);\n  }\n\n \
    \ void reset() { pid = 0; }\n\n  // f(idx, cnt)\n  template <typename F>\n  void\
    \ enumerate(np root, F f, T l, T r) {\n    auto dfs = [&](auto &dfs, np c) ->\
    \ void {\n      if (!c) return;\n      dfs(dfs, c->l);\n      f(c->idx, c->cnt);\n\
    \      dfs(dfs, c->r);\n    };\n    dfs(dfs, root);\n  }\n\nprivate:\n  void update(np\
    \ c) {\n    c->sub_cnt = c->cnt, c->sub_sm = c->node_sum();\n    if (c->l) c->sub_cnt\
    \ += c->l->sub_cnt, c->sub_sm += c->l->sub_sm;\n    if (c->r) c->sub_cnt += c->r->sub_cnt,\
    \ c->sub_sm += c->r->sub_sm;\n  }\n\n  np copy_node(np c) {\n    if (!c || !PERSISTENT)\
    \ return c;\n    pool[pid].idx = c->idx;\n    pool[pid].l = c->l, pool[pid].r\
    \ = c->r;\n    pool[pid].cnt = c->cnt, pool[pid].sub_cnt = c->sub_cnt;\n    pool[pid].sub_sm\
    \ = c->sub_sm;\n    return &(pool[pid++]);\n  }\n\n  np add_rec(np c, T l, T r,\
    \ T i, CNT cnt) {\n    if (!c) {\n      c = new_node(i, cnt);\n      return c;\n\
    \    }\n    c = copy_node(c);\n    if (c->idx == i) {\n      c->cnt += cnt;\n\
    \      update(c);\n      return (c->sub_cnt == 0 ? nullptr : c);\n    }\n    T\
    \ m = (l + r) / 2;\n    if (i < m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->cnt,\
    \ cnt);\n      c->l = add_rec(c->l, l, m, i, cnt);\n    }\n    if (m <= i) {\n\
    \      if (i < c->idx) swap(c->idx, i), swap(c->cnt, cnt);\n      c->r = add_rec(c->r,\
    \ m, r, i, cnt);\n    }\n    update(c);\n    return c;\n  }\n\n  void get_range_rec(np\
    \ c, T l, T r, T ql, T qr, CNT &cnt, SM &sm) {\n    chmax(ql, l), chmin(qr, r);\n\
    \    if (ql >= qr || !c) return;\n    if (l == ql && r == qr) {\n      cnt +=\
    \ c->sub_cnt, sm += c->sub_sm;\n      return;\n    }\n    T m = (l + r) / 2;\n\
    \    get_range_rec(c->l, l, m, ql, qr, cnt, sm);\n    if (ql <= (c->idx) && (c->idx)\
    \ < qr) cnt += c->cnt, sm += c->node_sum();\n    get_range_rec(c->r, m, r, ql,\
    \ qr, cnt, sm);\n  }\n\n  pair<T, SM> prefix_kth_rec(np c, T l, T r, CNT k) {\n\
    \    if (!c) { return {R0, 0}; }\n    T m = (l + r) / 2;\n    CNT l_cnt = (c->l\
    \ ? c->l->sub_cnt : 0);\n    SM l_sm = (c->l ? c->l->sub_sm : 0);\n    if (k <\
    \ l_cnt) { return prefix_kth_rec(c->l, l, m, k); }\n    if (k < l_cnt + c->cnt)\
    \ {\n      return {c->idx, l_sm + SM(c->idx) * SM(k - l_cnt)};\n    }\n    pair<T,\
    \ SM> p = prefix_kth_rec(c->r, m, r, k - l_cnt - c->cnt);\n    return {p.fi, l_sm\
    \ + p.se};\n  }\n\n  pair<T, SM> suffix_kth_rec(np c, T l, T r, CNT k) {\n   \
    \ if (!c) { return {L0, 0}; }\n    T m = (l + r) / 2;\n    CNT r_cnt = (c->r ?\
    \ c->r->sub_cnt : 0);\n    SM r_sm = (c->r ? c->r->sub_sm : 0);\n    if (k < r_cnt)\
    \ { return suffix_kth_rec(c->r, m, r, k); }\n    if (k < r_cnt + c->cnt) {\n \
    \     return {c->idx, r_sm + SM(c->idx) * SM(k - r_cnt)};\n    }\n    pair<T,\
    \ SM> p = suffix_kth_rec(c->l, l, m, k - r_cnt - c->cnt);\n    return {p.fi, r_sm\
    \ + p.se};\n  }\n};\n"
  code: "// \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3068\u3057\u3066\u4F5C\
    \u3063\u3066\u304A\u304F\ntemplate <typename T, typename CNT, typename SM, bool\
    \ PERSISTENT, int NODES>\nstruct My_Multiset {\n  struct Node {\n    T idx;\n\
    \    Node *l, *r;\n    CNT cnt, sub_cnt;\n    SM sub_sm;\n    SM node_sum() {\
    \ return SM(idx) * SM(cnt); }\n  };\n\n  const T L0, R0;\n  Node *pool;\n  int\
    \ pid;\n  using np = Node *;\n\n  My_Multiset(T L0 = -2 * infty<T>, T R0 = 2 *\
    \ infty<T>)\n      : L0(L0), R0(R0), pid(0) {\n    pool = new Node[NODES];\n \
    \ }\n\n  np new_root() { return nullptr; }\n\n  np new_node(T idx, const CNT cnt)\
    \ {\n    pool[pid].idx = idx;\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].cnt\
    \ = cnt, pool[pid].sub_cnt = cnt;\n    pool[pid].sub_sm = pool[pid].node_sum();\n\
    \    return &(pool[pid++]);\n  }\n\n  // (cnt, sm)\n  pair<CNT, SM> get_range(np\
    \ root, T l, T r) {\n    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r)\
    \ return {CNT(0), SM(0)};\n    CNT cnt = 0;\n    SM sm = 0;\n    get_range_rec(root,\
    \ L0, R0, l, r, cnt, sm);\n    return {cnt, sm};\n  }\n\n  // (cnt, sm)\n  pair<CNT,\
    \ SM> get_all_range(np root) {\n    if (!root) return {CNT(0), SM(0)};\n    return\
    \ {root->sub_cnt, root->sub_sm};\n  }\n\n  np add(np root, T x, CNT cnt) {\n \
    \   assert(L0 <= x && x < R0);\n    return add_rec(root, L0, R0, x, cnt);\n  }\n\
    \n  // k>=0 \u756A\u76EE\u3068\u3001\u305D\u3053\u307E\u3067\u306E prefix sum\n\
    \  pair<T, SM> prefix_kth(np root, CNT k) {\n    auto [cnt, sm] = get_all_range(root);\n\
    \    assert(k <= cnt);\n    return prefix_kth_rec(root, L0, R0, k);\n  }\n\n \
    \ // \u5927\u304D\u3044\u65B9\u304B\u3089 k>=0 \u756A\u76EE\u3068\u3001\u305D\u3053\
    \u307E\u3067\u306E suffix sum\n  pair<T, SM> suffix_kth(np root, CNT k) {\n  \
    \  auto [cnt, sm] = get_all_range(root);\n    assert(k <= cnt);\n    return suffix_kth_rec(root,\
    \ L0, R0, k);\n  }\n\n  void reset() { pid = 0; }\n\n  // f(idx, cnt)\n  template\
    \ <typename F>\n  void enumerate(np root, F f, T l, T r) {\n    auto dfs = [&](auto\
    \ &dfs, np c) -> void {\n      if (!c) return;\n      dfs(dfs, c->l);\n      f(c->idx,\
    \ c->cnt);\n      dfs(dfs, c->r);\n    };\n    dfs(dfs, root);\n  }\n\nprivate:\n\
    \  void update(np c) {\n    c->sub_cnt = c->cnt, c->sub_sm = c->node_sum();\n\
    \    if (c->l) c->sub_cnt += c->l->sub_cnt, c->sub_sm += c->l->sub_sm;\n    if\
    \ (c->r) c->sub_cnt += c->r->sub_cnt, c->sub_sm += c->r->sub_sm;\n  }\n\n  np\
    \ copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    pool[pid].idx =\
    \ c->idx;\n    pool[pid].l = c->l, pool[pid].r = c->r;\n    pool[pid].cnt = c->cnt,\
    \ pool[pid].sub_cnt = c->sub_cnt;\n    pool[pid].sub_sm = c->sub_sm;\n    return\
    \ &(pool[pid++]);\n  }\n\n  np add_rec(np c, T l, T r, T i, CNT cnt) {\n    if\
    \ (!c) {\n      c = new_node(i, cnt);\n      return c;\n    }\n    c = copy_node(c);\n\
    \    if (c->idx == i) {\n      c->cnt += cnt;\n      update(c);\n      return\
    \ (c->sub_cnt == 0 ? nullptr : c);\n    }\n    T m = (l + r) / 2;\n    if (i <\
    \ m) {\n      if (c->idx < i) swap(c->idx, i), swap(c->cnt, cnt);\n      c->l\
    \ = add_rec(c->l, l, m, i, cnt);\n    }\n    if (m <= i) {\n      if (i < c->idx)\
    \ swap(c->idx, i), swap(c->cnt, cnt);\n      c->r = add_rec(c->r, m, r, i, cnt);\n\
    \    }\n    update(c);\n    return c;\n  }\n\n  void get_range_rec(np c, T l,\
    \ T r, T ql, T qr, CNT &cnt, SM &sm) {\n    chmax(ql, l), chmin(qr, r);\n    if\
    \ (ql >= qr || !c) return;\n    if (l == ql && r == qr) {\n      cnt += c->sub_cnt,\
    \ sm += c->sub_sm;\n      return;\n    }\n    T m = (l + r) / 2;\n    get_range_rec(c->l,\
    \ l, m, ql, qr, cnt, sm);\n    if (ql <= (c->idx) && (c->idx) < qr) cnt += c->cnt,\
    \ sm += c->node_sum();\n    get_range_rec(c->r, m, r, ql, qr, cnt, sm);\n  }\n\
    \n  pair<T, SM> prefix_kth_rec(np c, T l, T r, CNT k) {\n    if (!c) { return\
    \ {R0, 0}; }\n    T m = (l + r) / 2;\n    CNT l_cnt = (c->l ? c->l->sub_cnt :\
    \ 0);\n    SM l_sm = (c->l ? c->l->sub_sm : 0);\n    if (k < l_cnt) { return prefix_kth_rec(c->l,\
    \ l, m, k); }\n    if (k < l_cnt + c->cnt) {\n      return {c->idx, l_sm + SM(c->idx)\
    \ * SM(k - l_cnt)};\n    }\n    pair<T, SM> p = prefix_kth_rec(c->r, m, r, k -\
    \ l_cnt - c->cnt);\n    return {p.fi, l_sm + p.se};\n  }\n\n  pair<T, SM> suffix_kth_rec(np\
    \ c, T l, T r, CNT k) {\n    if (!c) { return {L0, 0}; }\n    T m = (l + r) /\
    \ 2;\n    CNT r_cnt = (c->r ? c->r->sub_cnt : 0);\n    SM r_sm = (c->r ? c->r->sub_sm\
    \ : 0);\n    if (k < r_cnt) { return suffix_kth_rec(c->r, m, r, k); }\n    if\
    \ (k < r_cnt + c->cnt) {\n      return {c->idx, r_sm + SM(c->idx) * SM(k - r_cnt)};\n\
    \    }\n    pair<T, SM> p = suffix_kth_rec(c->l, l, m, k - r_cnt - c->cnt);\n\
    \    return {p.fi, r_sm + p.se};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/my_multiset.hpp
  requiredBy: []
  timestamp: '2023-04-14 22:05:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc241d.test.cpp
documentation_of: ds/my_multiset.hpp
layout: document
redirect_from:
- /library/ds/my_multiset.hpp
- /library/ds/my_multiset.hpp.html
title: ds/my_multiset.hpp
---
