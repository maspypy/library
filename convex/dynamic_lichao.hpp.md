---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
    title: test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/segment_add_get_min.test.cpp
    title: test/2_library_checker/data_structure/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    auto\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  void reset() {\n    free_head = nullptr;\n    if (!chunks.empty()) {\n\
    \      cur = chunks[0].get();\n      cur_used = 0;\n    }\n  }\n\n private:\n\
    \  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 2 \"convex/dynamic_lichao.hpp\"\n\n/*\nstruct\
    \ F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\u5024\n  int\
    \ a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n*/\n\n// \u76F4\
    \u7DDA\u8FFD\u52A0\u304B\u3064\u975E\u6C38\u7D9A\u306A\u3089\u7A7A\u9593 Q \u3067\
    \u3088\u3044\u3002\n// \u95A2\u6570\u306F ll -> T\u3002[L, R) \u4E0A f \u304C\
    \ overflow \u3057\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u3002\n// evaluate\
    \ \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\u3001totally monotone \u306A\u95A2\
    \u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\ntemplate <typename FUNC, bool PERSISTENT,\
    \ int NODES, bool MINIMIZE>\nstruct Dynamic_LiChao_Tree {\n  using T = typename\
    \ FUNC::value_type;\n  vc<FUNC> funcs;\n\n  static inline T evaluate(FUNC &f,\
    \ ll x) { return f(x); }\n\n  struct Node {\n    int fid;\n    Node *l, *r;\n\
    \  };\n  Node_Pool<Node> pool;\n  ll L, R;\n\n  using np = Node *;\n\n  Dynamic_LiChao_Tree(ll\
    \ L, ll R) : L(L), R(R) {}\n\n  void reset() { funcs.clear(), pool.reset(); }\n\
    \n  np new_root() { return nullptr; }\n\n  np new_node() {\n    np c = pool.create();\n\
    \    c->fid = -1, c->l = c->r = nullptr;\n    return c;\n  }\n\n  np chmin_line(np\
    \ root, FUNC f) {\n    static_assert(MINIMIZE);\n    int fid = len(funcs);\n \
    \   funcs.eb(f);\n    if (!root) root = new_node();\n    return add_line_rec(root,\
    \ fid, L, R);\n  }\n  np chmax_line(np root, FUNC f) {\n    static_assert(!MINIMIZE);\n\
    \    int fid = len(funcs);\n    funcs.eb(f);\n    if (!root) root = new_node();\n\
    \    return add_line_rec(root, fid, L, R);\n  }\n\n  // [xl, xr)\n  np chmin_segment(np\
    \ root, ll xl, ll xr, FUNC f) {\n    static_assert(MINIMIZE);\n    int fid = len(funcs);\n\
    \    funcs.eb(f);\n    if (!root) root = new_node();\n    return add_segment_rec(root,\
    \ xl, xr, fid, L, R);\n  }\n  // [xl, xr)\n  np chmax_segment(np root, ll xl,\
    \ ll xr, FUNC f) {\n    static_assert(!MINIMIZE);\n    int fid = len(funcs);\n\
    \    funcs.eb(f);\n    if (!root) root = new_node();\n    return add_segment_rec(root,\
    \ xl, xr, fid, L, R);\n  }\n\n  // (\u5024\u30FB\u95A2\u6570\u756A\u53F7)\n  pair<T,\
    \ int> query(np root, ll x) {\n    assert(L <= x && x < R);\n    if (!root) {\n\
    \      if (MINIMIZE) return {infty<T>, -1};\n      if (!MINIMIZE) return {-infty<T>,\
    \ -1};\n    }\n    return query_rec(root, x, L, R);\n  }\n\n private:\n  np copy_node(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    np d = pool.create();\n    d->fid\
    \ = c->fid, d->l = c->l, d->r = c->r;\n    return d;\n  }\n\n  inline T evaluate_inner(int\
    \ fid, ll x) {\n    if (fid == -1) {\n      return (MINIMIZE ? infty<T> : -infty<T>);\n\
    \    };\n    return evaluate(funcs[fid], x);\n  }\n\n  np add_segment_rec(np c,\
    \ ll xl, ll xr, int fid, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr,\
    \ node_r);\n    if (xl >= xr) return c;\n    if (node_l < xl || xr < node_r) {\n\
    \      c = copy_node(c);\n      ll node_m = (node_l + node_r) / 2;\n      if (!c->l)\
    \ c->l = new_node();\n      if (!c->r) c->r = new_node();\n      c->l = add_segment_rec(c->l,\
    \ xl, xr, fid, node_l, node_m);\n      c->r = add_segment_rec(c->r, xl, xr, fid,\
    \ node_m, node_r);\n      return c;\n    }\n    return add_line_rec(c, fid, node_l,\
    \ node_r);\n  }\n\n  np add_line_rec(np c, int fid, ll node_l, ll node_r) {\n\
    \    int gid = c->fid;\n    T fl = evaluate_inner(fid, node_l), fr = evaluate_inner(fid,\
    \ node_r - 1);\n    T gl = evaluate_inner(gid, node_l), gr = evaluate_inner(gid,\
    \ node_r - 1);\n    bool bl = (MINIMIZE ? fl < gl : fl > gl);\n    bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n    if (bl && br) {\n      c = copy_node(c);\n      c->fid\
    \ = fid;\n      return c;\n    }\n    if (!bl && !br) {\n      return c;\n   \
    \ }\n\n    c = copy_node(c);\n    ll node_m = (node_l + node_r) / 2;\n    auto\
    \ fm = evaluate_inner(fid, node_m), gm = evaluate_inner(gid, node_m);\n    bool\
    \ bm = (MINIMIZE ? fm < gm : fm > gm);\n    if (bm) {\n      c->fid = fid;\n \
    \     if (bl) {\n        if (!c->r) c->r = new_node();\n        c->r = add_line_rec(c->r,\
    \ gid, node_m, node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n\
    \        c->l = add_line_rec(c->l, gid, node_l, node_m);\n      }\n    }\n   \
    \ if (!bm) {\n      if (!bl) {\n        if (!c->r) c->r = new_node();\n      \
    \  c->r = add_line_rec(c->r, fid, node_m, node_r);\n      } else {\n        if\
    \ (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l, fid, node_l, node_m);\n\
    \      }\n    }\n    return c;\n  }\n\n  pair<T, int> query_rec(np c, ll x, ll\
    \ node_l, ll node_r) {\n    int fid = c->fid;\n    pair<T, int> res = {evaluate_inner(fid,\
    \ x), fid};\n    ll node_m = (node_l + node_r) / 2;\n    if (x < node_m && c->l)\
    \ {\n      pair<T, int> res1 = query_rec(c->l, x, node_l, node_m);\n      res\
    \ = (MINIMIZE ? min(res, res1) : max(res, res1));\n    }\n    if (x >= node_m\
    \ && c->r) {\n      pair<T, int> res1 = query_rec(c->r, x, node_m, node_r);\n\
    \      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n    }\n    return\
    \ res;\n  }\n};\n"
  code: "#include \"ds/node_pool.hpp\"\n\n/*\nstruct F {\n  using value_type = ll;\
    \  // operator() \u306E\u623B\u308A\u5024\n  int a;\n  ll b;\n  ll operator()(ll\
    \ x) { return a * x + b; }\n};\n*/\n\n// \u76F4\u7DDA\u8FFD\u52A0\u304B\u3064\u975E\
    \u6C38\u7D9A\u306A\u3089\u7A7A\u9593 Q \u3067\u3088\u3044\u3002\n// \u95A2\u6570\
    \u306F ll -> T\u3002[L, R) \u4E0A f \u304C overflow \u3057\u306A\u3044\u3088\u3046\
    \u306B\u6CE8\u610F\u3002\n// evaluate \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\
    \u3001totally monotone \u306A\u95A2\u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\n\
    template <typename FUNC, bool PERSISTENT, int NODES, bool MINIMIZE>\nstruct Dynamic_LiChao_Tree\
    \ {\n  using T = typename FUNC::value_type;\n  vc<FUNC> funcs;\n\n  static inline\
    \ T evaluate(FUNC &f, ll x) { return f(x); }\n\n  struct Node {\n    int fid;\n\
    \    Node *l, *r;\n  };\n  Node_Pool<Node> pool;\n  ll L, R;\n\n  using np = Node\
    \ *;\n\n  Dynamic_LiChao_Tree(ll L, ll R) : L(L), R(R) {}\n\n  void reset() {\
    \ funcs.clear(), pool.reset(); }\n\n  np new_root() { return nullptr; }\n\n  np\
    \ new_node() {\n    np c = pool.create();\n    c->fid = -1, c->l = c->r = nullptr;\n\
    \    return c;\n  }\n\n  np chmin_line(np root, FUNC f) {\n    static_assert(MINIMIZE);\n\
    \    int fid = len(funcs);\n    funcs.eb(f);\n    if (!root) root = new_node();\n\
    \    return add_line_rec(root, fid, L, R);\n  }\n  np chmax_line(np root, FUNC\
    \ f) {\n    static_assert(!MINIMIZE);\n    int fid = len(funcs);\n    funcs.eb(f);\n\
    \    if (!root) root = new_node();\n    return add_line_rec(root, fid, L, R);\n\
    \  }\n\n  // [xl, xr)\n  np chmin_segment(np root, ll xl, ll xr, FUNC f) {\n \
    \   static_assert(MINIMIZE);\n    int fid = len(funcs);\n    funcs.eb(f);\n  \
    \  if (!root) root = new_node();\n    return add_segment_rec(root, xl, xr, fid,\
    \ L, R);\n  }\n  // [xl, xr)\n  np chmax_segment(np root, ll xl, ll xr, FUNC f)\
    \ {\n    static_assert(!MINIMIZE);\n    int fid = len(funcs);\n    funcs.eb(f);\n\
    \    if (!root) root = new_node();\n    return add_segment_rec(root, xl, xr, fid,\
    \ L, R);\n  }\n\n  // (\u5024\u30FB\u95A2\u6570\u756A\u53F7)\n  pair<T, int> query(np\
    \ root, ll x) {\n    assert(L <= x && x < R);\n    if (!root) {\n      if (MINIMIZE)\
    \ return {infty<T>, -1};\n      if (!MINIMIZE) return {-infty<T>, -1};\n    }\n\
    \    return query_rec(root, x, L, R);\n  }\n\n private:\n  np copy_node(np c)\
    \ {\n    if (!c || !PERSISTENT) return c;\n    np d = pool.create();\n    d->fid\
    \ = c->fid, d->l = c->l, d->r = c->r;\n    return d;\n  }\n\n  inline T evaluate_inner(int\
    \ fid, ll x) {\n    if (fid == -1) {\n      return (MINIMIZE ? infty<T> : -infty<T>);\n\
    \    };\n    return evaluate(funcs[fid], x);\n  }\n\n  np add_segment_rec(np c,\
    \ ll xl, ll xr, int fid, ll node_l, ll node_r) {\n    chmax(xl, node_l), chmin(xr,\
    \ node_r);\n    if (xl >= xr) return c;\n    if (node_l < xl || xr < node_r) {\n\
    \      c = copy_node(c);\n      ll node_m = (node_l + node_r) / 2;\n      if (!c->l)\
    \ c->l = new_node();\n      if (!c->r) c->r = new_node();\n      c->l = add_segment_rec(c->l,\
    \ xl, xr, fid, node_l, node_m);\n      c->r = add_segment_rec(c->r, xl, xr, fid,\
    \ node_m, node_r);\n      return c;\n    }\n    return add_line_rec(c, fid, node_l,\
    \ node_r);\n  }\n\n  np add_line_rec(np c, int fid, ll node_l, ll node_r) {\n\
    \    int gid = c->fid;\n    T fl = evaluate_inner(fid, node_l), fr = evaluate_inner(fid,\
    \ node_r - 1);\n    T gl = evaluate_inner(gid, node_l), gr = evaluate_inner(gid,\
    \ node_r - 1);\n    bool bl = (MINIMIZE ? fl < gl : fl > gl);\n    bool br = (MINIMIZE\
    \ ? fr < gr : fr > gr);\n    if (bl && br) {\n      c = copy_node(c);\n      c->fid\
    \ = fid;\n      return c;\n    }\n    if (!bl && !br) {\n      return c;\n   \
    \ }\n\n    c = copy_node(c);\n    ll node_m = (node_l + node_r) / 2;\n    auto\
    \ fm = evaluate_inner(fid, node_m), gm = evaluate_inner(gid, node_m);\n    bool\
    \ bm = (MINIMIZE ? fm < gm : fm > gm);\n    if (bm) {\n      c->fid = fid;\n \
    \     if (bl) {\n        if (!c->r) c->r = new_node();\n        c->r = add_line_rec(c->r,\
    \ gid, node_m, node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n\
    \        c->l = add_line_rec(c->l, gid, node_l, node_m);\n      }\n    }\n   \
    \ if (!bm) {\n      if (!bl) {\n        if (!c->r) c->r = new_node();\n      \
    \  c->r = add_line_rec(c->r, fid, node_m, node_r);\n      } else {\n        if\
    \ (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l, fid, node_l, node_m);\n\
    \      }\n    }\n    return c;\n  }\n\n  pair<T, int> query_rec(np c, ll x, ll\
    \ node_l, ll node_r) {\n    int fid = c->fid;\n    pair<T, int> res = {evaluate_inner(fid,\
    \ x), fid};\n    ll node_m = (node_l + node_r) / 2;\n    if (x < node_m && c->l)\
    \ {\n      pair<T, int> res1 = query_rec(c->l, x, node_l, node_m);\n      res\
    \ = (MINIMIZE ? min(res, res1) : max(res, res1));\n    }\n    if (x >= node_m\
    \ && c->r) {\n      pair<T, int> res1 = query_rec(c->r, x, node_m, node_r);\n\
    \      res = (MINIMIZE ? min(res, res1) : max(res, res1));\n    }\n    return\
    \ res;\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: convex/dynamic_lichao.hpp
  requiredBy: []
  timestamp: '2025-09-16 15:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
  - test/2_library_checker/data_structure/segment_add_get_min.test.cpp
documentation_of: convex/dynamic_lichao.hpp
layout: document
redirect_from:
- /library/convex/dynamic_lichao.hpp
- /library/convex/dynamic_lichao.hpp.html
title: convex/dynamic_lichao.hpp
---
