---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/splay_cm.test.cpp
    title: test/1_mytest/splay_cm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_reverse_range_sum.test.cpp
    title: test/2_library_checker/data_structure/range_reverse_range_sum.test.cpp
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
    \ &cur[cur_used++];\n  }\n};\n#line 3 \"ds/splaytree/splaytree.hpp\"\n\n// Node\
    \ \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate <typename\
    \ Node>\nstruct SplayTree {\n  Node_Pool<Node> pool;\n  using np = Node *;\n \
    \ using X = typename Node::value_type;\n  using A = typename Node::operator_type;\n\
    \n  void free_subtree(np c) {\n    if (!c) return;\n    auto dfs = [&](auto &dfs,\
    \ np c) -> void {\n      if (c->l) dfs(dfs, c->l);\n      if (c->r) dfs(dfs, c->r);\n\
    \      pool.destroy(c);\n    };\n    dfs(dfs, c);\n  }\n\n  void reset() { pool.reset();\
    \ }\n\n  np new_root() { return nullptr; }\n\n  np new_node(const X &x) {\n  \
    \  np n = pool.create();\n    Node::new_node(n, x);\n    return n;\n  }\n\n  np\
    \ new_node(const vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int l, int r) ->\
    \ np {\n      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      int m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root\
    \ = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n      root->l = l_root,\
    \ root->r = r_root;\n      if (l_root) l_root->p = root;\n      if (r_root) r_root->p\
    \ = root;\n      root->update();\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  u32 get_size(np root) { return (root ? root->size :\
    \ 0); }\n\n  np merge(np l_root, np r_root) {\n    if (!l_root) return r_root;\n\
    \    if (!r_root) return l_root;\n    assert((!l_root->p) && (!r_root->p));\n\
    \    splay_kth(r_root, 0);  // splay \u3057\u305F\u306E\u3067 prop \u6E08\n  \
    \  r_root->l = l_root;\n    l_root->p = r_root;\n    r_root->update();\n    return\
    \ r_root;\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a, b), c);\
    \ }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c),\
    \ d); }\n\n  pair<np, np> split(np root, u32 k) {\n    assert(!root || !root->p);\n\
    \    if (k == 0) return {nullptr, root};\n    if (k == (root->size)) return {root,\
    \ nullptr};\n    splay_kth(root, k - 1);\n    np right = root->r;\n    root->r\
    \ = nullptr, right->p = nullptr;\n    root->update();\n    return {root, right};\n\
    \  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n  \
    \  tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n    return\
    \ {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32 i, u32 j,\
    \ u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto [a, b, c]\
    \ = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  tuple<np, np, np>\
    \ split_L_root_R(np root) {\n    u32 s = (root->l ? root->l->size : 0);\n    return\
    \ split3(root, s, s + 1);\n  }\n\n  // \u90E8\u5206\u6728\u304C\u533A\u9593 [l,r)\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\u30FC\u30C9\u3092\u4F5C\
    \u3063\u3066\u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\u30C9\u304C root \u306B\
    \u306A\u308B\u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\u3001\n  // \u3053\
    \u306E\u30CE\u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\u5F8C\u306B\u3059\u3050\
    \u306B splay \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\u3052\u308B\u3053\u3068\
    \n  void goto_between(np &root, u32 l, u32 r) {\n    if (l == 0 && r == root->size)\
    \ return;\n    if (l == 0) {\n      splay_kth(root, r);\n      root = root->l;\n\
    \      return;\n    }\n    if (r == root->size) {\n      splay_kth(root, l - 1);\n\
    \      root = root->r;\n      return;\n    }\n    splay_kth(root, r);\n    np\
    \ rp = root;\n    root = rp->l;\n    root->p = nullptr;\n    splay_kth(root, l\
    \ - 1);\n    root->p = rp;\n    rp->l = root;\n    rp->update();\n    root = root->r;\n\
    \  }\n\n  vc<X> get_all(const np &root) {\n    vc<X> res;\n    auto dfs = [&](auto\
    \ &dfs, np root) -> void {\n      if (!root) return;\n      root->prop();\n  \
    \    dfs(dfs, root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n\
    \    };\n    dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k)\
    \ {\n    assert(root == nullptr || !root->p);\n    splay_kth(root, k);\n    return\
    \ root->get();\n  }\n\n  void set(np &root, u32 k, const X &x) {\n    assert(root\
    \ != nullptr && !root->p);\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n\
    \  void multiply(np &root, u32 k, const X &x) {\n    assert(root != nullptr &&\
    \ !root->p);\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\n  X prod(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    using\
    \ Mono = typename Node::Monoid_X;\n    if (l == r) return Mono::unit();\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    X res\
    \ = root->prod;\n    splay(root, true);\n    return res;\n  }\n\n  X prod(np &root)\
    \ {\n    assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    return (root ? root->prod : Mono::unit());\n  }\n\n  void apply(np &root,\
    \ u32 l, u32 r, const A &a) {\n    if (l == r) return;\n    assert(0 <= l && l\
    \ < r && r <= root->size);\n    goto_between(root, l, r);\n    root->apply(a);\n\
    \    splay(root, true);\n  }\n  void apply(np &root, const A &a) {\n    if (!root)\
    \ return;\n    root->apply(a);\n  }\n\n  void reverse(np &root, u32 l, u32 r)\
    \ {\n    assert(root == nullptr || !root->p);\n    if (l == r) return;\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    root->reverse();\n\
    \    splay(root, true);\n  }\n  void reverse(np root) {\n    if (!root) return;\n\
    \    root->reverse();\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\u3002prop, update \u306F rotate \u306E\u5916\u3067\u884C\
    \u3046\u3002\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  void prop_from_root(np c) {\n    if\
    \ (!c->p) {\n      c->prop();\n      return;\n    }\n    prop_from_root(c->p);\n\
    \    c->prop();\n  }\n\n  void splay(Node *me, bool prop_from_root_done) {\n \
    \   // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\u7956\u5148\
    \uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\u3042\u308B\
    \u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\u4E86\u6642\
    \u70B9\u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    if (!prop_from_root_done)\
    \ prop_from_root(me);\n    me->prop();\n    while (me->p) {\n      np p = me->p;\n\
    \      np pp = p->p;\n      if (!pp) {\n        rotate(me);\n        p->update();\n\
    \        break;\n      }\n      bool same = (p->l == me && pp->l == p) || (p->r\
    \ == me && pp->r == p);\n      if (same) rotate(p), rotate(me);\n      if (!same)\
    \ rotate(me), rotate(me);\n      pp->update(), p->update();\n    }\n    // me\
    \ \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n\
    \  }\n\n  void splay_kth(np &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n\
    \    while (1) {\n      root->prop();\n      u32 s1 = (root->l ? root->l->size\
    \ : 0);\n      u32 s2 = (root->size) - (root->r ? root->r->size : 0);\n      if\
    \ (k < s1) root = root->l;\n      elif (k < s2) { break; }\n      else {\n   \
    \     k -= s2;\n        root = root->r;\n      }\n    }\n    splay(root, true);\n\
    \  }\n\n  // check(x), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C\
    \ check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename\
    \ F>\n  pair<np, np> split_max_right(np root, F check) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    assert(!root->p);\n    np c = find_max_right(root,\
    \ check);\n    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n\
    \    }\n    splay(c, true);\n    np right = c->r;\n    if (!right) return {c,\
    \ nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n\
    \    return {c, right};\n  }\n\n  // check(x, cnt), \u5DE6\u5074\u306E\u30CE\u30FC\
    \u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\
    \u308B\n  template <typename F>\n  pair<np, np> split_max_right_cnt(np root, F\
    \ check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_cnt(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right_prod(np root, F check) {\n    if (!root) return {nullptr,\
    \ nullptr};\n    assert(!root->p);\n    np c = find_max_right_prod(root, check);\n\
    \    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n    }\n\
    \    splay(c, true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_cnt(np\
    \ root, const F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok\
    \ \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok\
    \ = nullptr, last = nullptr;\n    ll n = 0;\n    while (root) {\n      last =\
    \ root;\n      root->prop();\n      ll k = (root->size) - (root->r ? root->r->size\
    \ : 0);\n      if (check(root->x, n + k)) {\n        last_ok = root;\n       \
    \ n += k;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\n  template\
    \ <typename F>\n  np find_max_right_prod(np root, const F &check) {\n    using\
    \ Mono = typename Node::Monoid_X;\n    X prod = Mono::unit();\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->prop();\n      np tmp = root->r;\n      root->r\
    \ = nullptr;\n      root->update();\n      X lprod = Mono::op(prod, root->prod);\n\
    \      root->r = tmp;\n      root->update();\n      if (check(lprod)) {\n    \
    \    prod = lprod;\n        last_ok = root;\n        root = root->r;\n      }\
    \ else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n  \
    \  return last_ok;\n  }\n};\n#line 2 \"ds/splaytree/splaytree_commutative_monoid.hpp\"\
    \n\nnamespace SplayTreeNodes {\ntemplate <typename Monoid>\nstruct Node_CM {\n\
    \  using Monoid_X = Monoid;\n  using X = typename Monoid::value_type;\n  using\
    \ value_type = X;\n  using operator_type = int; // \u5B9A\u7FA9\u3060\u3051\u3057\
    \u3066\u304A\u304F\n  using np = Node_CM *;\n\n  np p, l, r;\n  X x, prod;\n \
    \ u32 size;\n  bool rev;\n\n  static void new_node(np n, const X &x) {\n    n->p\
    \ = n->l = n->r = nullptr;\n    n->x = n->prod = x;\n    n->size = 1;\n    n->rev\
    \ = 0;\n  }\n\n  void update() {\n    size = 1;\n    prod = x;\n    if (l) {\n\
    \      size += l->size;\n      prod = Monoid::op(l->prod, prod);\n    }\n    if\
    \ (r) {\n      size += r->size;\n      prod = Monoid::op(prod, r->prod);\n   \
    \ }\n  }\n\n  void prop() {\n    if (rev) {\n      if (l) {\n        l->rev ^=\
    \ 1;\n        swap(l->l, l->r);\n      }\n      if (r) {\n        r->rev ^= 1;\n\
    \        swap(r->l, r->r);\n      }\n      rev = 0;\n    }\n  }\n\n  // update,\
    \ prop \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\u306E\u306F\u3001splay\
    \ \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\
    \u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\u305D\u306E\u6642\u70B9\u3067\
    \ update, prop \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\
    \u3088\u3044\u3002\n  X get() { return x; }\n  void set(const X &xx) {\n    x\
    \ = xx;\n    update();\n  }\n  void multiply(const X &xx) {\n    x = Monoid::op(x,\
    \ xx);\n    update();\n  }\n  void reverse() {\n    swap(l, r);\n    rev ^= 1;\n\
    \  }\n};\ntemplate <typename Monoid>\nusing SplayTree_Commutative_Monoid = SplayTree<Node_CM<Monoid>>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_Commutative_Monoid;\n"
  code: "#include \"ds/splaytree/splaytree.hpp\"\n\nnamespace SplayTreeNodes {\ntemplate\
    \ <typename Monoid>\nstruct Node_CM {\n  using Monoid_X = Monoid;\n  using X =\
    \ typename Monoid::value_type;\n  using value_type = X;\n  using operator_type\
    \ = int; // \u5B9A\u7FA9\u3060\u3051\u3057\u3066\u304A\u304F\n  using np = Node_CM\
    \ *;\n\n  np p, l, r;\n  X x, prod;\n  u32 size;\n  bool rev;\n\n  static void\
    \ new_node(np n, const X &x) {\n    n->p = n->l = n->r = nullptr;\n    n->x =\
    \ n->prod = x;\n    n->size = 1;\n    n->rev = 0;\n  }\n\n  void update() {\n\
    \    size = 1;\n    prod = x;\n    if (l) {\n      size += l->size;\n      prod\
    \ = Monoid::op(l->prod, prod);\n    }\n    if (r) {\n      size += r->size;\n\
    \      prod = Monoid::op(prod, r->prod);\n    }\n  }\n\n  void prop() {\n    if\
    \ (rev) {\n      if (l) {\n        l->rev ^= 1;\n        swap(l->l, l->r);\n \
    \     }\n      if (r) {\n        r->rev ^= 1;\n        swap(r->l, r->r);\n   \
    \   }\n      rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\
    \u3070\u308C\u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\
    \u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\
    \u304C\u3063\u3066\u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  X get()\
    \ { return x; }\n  void set(const X &xx) {\n    x = xx;\n    update();\n  }\n\
    \  void multiply(const X &xx) {\n    x = Monoid::op(x, xx);\n    update();\n \
    \ }\n  void reverse() {\n    swap(l, r);\n    rev ^= 1;\n  }\n};\ntemplate <typename\
    \ Monoid>\nusing SplayTree_Commutative_Monoid = SplayTree<Node_CM<Monoid>>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_Commutative_Monoid;"
  dependsOn:
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/splaytree/splaytree_commutative_monoid.hpp
  requiredBy: []
  timestamp: '2025-09-16 14:24:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/range_reverse_range_sum.test.cpp
  - test/1_mytest/splay_cm.test.cpp
documentation_of: ds/splaytree/splaytree_commutative_monoid.hpp
layout: document
redirect_from:
- /library/ds/splaytree/splaytree_commutative_monoid.hpp
- /library/ds/splaytree/splaytree_commutative_monoid.hpp.html
title: ds/splaytree/splaytree_commutative_monoid.hpp
---
