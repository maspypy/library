---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':warning:'
    path: ds/piecewise_constant/piecewise_constant.hpp
    title: ds/piecewise_constant/piecewise_constant.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1023/problem/G
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(*x);  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u547C\u3073\u51FA\u3057\n  }\n\n  void destroy(np x) {\n  \
    \  if (!x) return;\n    x->~Node();\n    auto s = reinterpret_cast<Slot*>(x);\n\
    \    s->next = free_head;\n    free_head = s;\n  }\n\n  void reset() {\n    free_head\
    \ = nullptr;\n    if (!chunks.empty()) {\n      cur = chunks[0].get();\n     \
    \ cur_used = 0;\n    }\n  }\n\n private:\n  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 3 \"ds/splaytree/splaytree.hpp\"\n\n// Node\
    \ \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate <typename\
    \ Node>\nstruct SplayTree {\n  Node_Pool<Node> pool;\n  using np = Node *;\n \
    \ using X = typename Node::value_type;\n  using A = typename Node::operator_type;\n\
    \n  void free_subtree(np c) {\n    if (!c) return;\n    auto dfs = [&](auto &dfs,\
    \ np c) -> void {\n      if (c->l) dfs(dfs, c->l);\n      if (c->r) dfs(dfs, c->r);\n\
    \      c->p = c->l = c->r = nullptr;\n      pool.destroy(c);\n    };\n    dfs(dfs,\
    \ c);\n  }\n\n  void reset() { pool.reset(); }\n\n  np new_root() { return nullptr;\
    \ }\n\n  np new_node(const X &x) {\n    np n = pool.create();\n    Node::new_node(n,\
    \ x);\n    return n;\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs =\
    \ [&](auto &dfs, int l, int r) -> np {\n      if (l == r) return nullptr;\n  \
    \    if (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n  \
    \    np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n    \
    \  np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n  \
    \    if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n    \
    \  root->update();\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  u32 get_size(np root) { return (root ? root->size : 0); }\n\n  np merge(np\
    \ l_root, np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return\
    \ l_root;\n    assert((!l_root->p) && (!r_root->p));\n    splay_kth(r_root, 0);\
    \  // splay \u3057\u305F\u306E\u3067 push \u6E08\n    r_root->l = l_root;\n  \
    \  l_root->p = r_root;\n    r_root->update();\n    return r_root;\n  }\n  np merge3(np\
    \ a, np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np\
    \ c, np d) { return merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np\
    \ root, u32 k) {\n    assert(!root || !root->p);\n    if (k == 0) return {nullptr,\
    \ root};\n    if (k == (root->size)) return {root, nullptr};\n    splay_kth(root,\
    \ k - 1);\n    np right = root->r;\n    root->r = nullptr, right->p = nullptr;\n\
    \    root->update();\n    return {root, right};\n  }\n  tuple<np, np, np> split3(np\
    \ root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n\
    \    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np,\
    \ np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root,\
    \ d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a,\
    \ b, c, d};\n  }\n\n  tuple<np, np, np> split_L_root_R(np root) {\n    u32 s =\
    \ (root->l ? root->l->size : 0);\n    return split3(root, s, s + 1);\n  }\n\n\
    \  // \u90E8\u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\u5FDC\u3059\u308B\
    \u3088\u3046\u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\u8FD4\u3059\n  //\
    \ \u305D\u306E\u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\u308F\u3051\u3067\
    \u306F\u306A\u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\
    \u53C2\u7167\u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay \u3057\u3066\u6839\
    \u306B\u6301\u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np &root,\
    \ u32 l, u32 r) {\n    if (l == 0 && r == root->size) return;\n    if (l == 0)\
    \ {\n      splay_kth(root, r);\n      root = root->l;\n      return;\n    }\n\
    \    if (r == root->size) {\n      splay_kth(root, l - 1);\n      root = root->r;\n\
    \      return;\n    }\n    splay_kth(root, r);\n    np rp = root;\n    root =\
    \ rp->l;\n    root->p = nullptr;\n    splay_kth(root, l - 1);\n    root->p = rp;\n\
    \    rp->l = root;\n    rp->update();\n    root = root->r;\n  }\n\n  vc<X> get_all(const\
    \ np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np root) -> void\
    \ {\n      if (!root) return;\n      root->push();\n      dfs(dfs, root->l);\n\
    \      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n    dfs(dfs, root);\n\
    \    return res;\n  }\n\n  X get(np &root, u32 k) {\n    assert(root == nullptr\
    \ || !root->p);\n    splay_kth(root, k);\n    return root->get();\n  }\n\n  void\
    \ set(np &root, u32 k, const X &x) {\n    assert(root != nullptr && !root->p);\n\
    \    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np &root,\
    \ u32 k, const X &x) {\n    assert(root != nullptr && !root->p);\n    splay_kth(root,\
    \ k);\n    root->multiply(x);\n  }\n\n  X prod(np &root, u32 l, u32 r) {\n   \
    \ assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    if (l == r) return Mono::unit();\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    goto_between(root, l, r);\n    X res = root->prod;\n    splay(root, true);\n\
    \    return res;\n  }\n\n  X prod(np &root) {\n    assert(root == nullptr || !root->p);\n\
    \    using Mono = typename Node::Monoid_X;\n    return (root ? root->prod : Mono::unit());\n\
    \  }\n\n  void apply(np &root, u32 l, u32 r, const A &a) {\n    if (l == r) return;\n\
    \    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n\
    \    root->apply(a);\n    splay(root, true);\n  }\n  void apply(np &root, const\
    \ A &a) {\n    if (!root) return;\n    root->apply(a);\n  }\n\n  void reverse(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    if (l\
    \ == r) return;\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    root->reverse();\n    splay(root, true);\n  }\n  void reverse(np\
    \ root) {\n    if (!root) return;\n    root->reverse();\n  }\n\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002push, update\
    \ \u306F rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r\
    \ = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n    \
    \  p->r = c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r\
    \ == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\
    \n  void push_from_root(np c) {\n    if (!c->p) {\n      c->push();\n      return;\n\
    \    }\n    push_from_root(c->p);\n    c->push();\n  }\n\n  void splay(Node *me,\
    \ bool push_from_root_done) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\
    \u3067\u3001me \u306E\u7956\u5148\uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\
    \u306B push \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\
    \u306B\u3001splay \u7D42\u4E86\u6642\u70B9\u3067 me \u306F upd / push \u6E08\u3067\
    \u3042\u308B\n    if (!push_from_root_done) push_from_root(me);\n    me->push();\n\
    \    while (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp)\
    \ {\n        rotate(me);\n        p->update();\n        break;\n      }\n    \
    \  bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n   \
    \   if (same) rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n\
    \      pp->update(), p->update();\n    }\n    // me \u306E update \u306F\u6700\
    \u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np\
    \ &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n\
    \      root->push();\n      u32 s1 = (root->l ? root->l->size : 0);\n      u32\
    \ s2 = (root->size) - (root->r ? root->r->size : 0);\n      if (k < s1) root =\
    \ root->l;\n      elif (k < s2) { break; }\n      else {\n        k -= s2;\n \
    \       root = root->r;\n      }\n    }\n    splay(root, true);\n  }\n\n  // check(x),\
    \ \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\
    \u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np>\
    \ split_max_right(np root, F check) {\n    if (!root) return {nullptr, nullptr};\n\
    \    assert(!root->p);\n    np c = find_max_right(root, check);\n    if (!c) {\n\
    \      splay(root, true);\n      return {nullptr, root};\n    }\n    splay(c,\
    \ true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n    right->p\
    \ = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c, right};\n\
    \  }\n\n  // check(x, cnt), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C\
    \ check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename\
    \ F>\n  pair<np, np> split_max_right_cnt(np root, F check) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    assert(!root->p);\n    np c = find_max_right_cnt(root,\
    \ check);\n    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n\
    \    }\n    splay(c, true);\n    np right = c->r;\n    if (!right) return {c,\
    \ nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n\
    \    return {c, right};\n  }\n\n  // \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\
    \u4F53\u306E prod \u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\
    \u308B\n  template <typename F>\n  pair<np, np> split_max_right_prod(np root,\
    \ F check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_prod(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  template\
    \ <typename F>\n  np find_max_right(np root, const F &check) {\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->push();\n      if (check(root->x)) {\n  \
    \      last_ok = root;\n        root = root->r;\n      } else {\n        root\
    \ = root->l;\n      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\
    \n  template <typename F>\n  np find_max_right_cnt(np root, const F &check) {\n\
    \    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\
    \u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n\
    \    ll n = 0;\n    while (root) {\n      last = root;\n      root->push();\n\
    \      ll k = (root->size) - (root->r ? root->r->size : 0);\n      if (check(root->x,\
    \ n + k)) {\n        last_ok = root;\n        n += k;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_prod(np\
    \ root, const F &check) {\n    using Mono = typename Node::Monoid_X;\n    X prod\
    \ = Mono::unit();\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\
    \u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok =\
    \ nullptr, last = nullptr;\n    while (root) {\n      last = root;\n      root->push();\n\
    \      np tmp = root->r;\n      root->r = nullptr;\n      root->update();\n  \
    \    X lprod = Mono::op(prod, root->prod);\n      root->r = tmp;\n      root->update();\n\
    \      if (check(lprod)) {\n        prod = lprod;\n        last_ok = root;\n \
    \       root = root->r;\n      } else {\n        root = root->l;\n      }\n  \
    \  }\n    splay(last, true);\n    return last_ok;\n  }\n};\n#line 2 \"ds/piecewise_constant/piecewise_constant.hpp\"\
    \n\nenum Border_Type { inc, dec, l, r };\n\n// https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_b\n\
    // https://atcoder.jp/contests/arc174/tasks/arc174_f\ntemplate <typename Node>\n\
    struct Piecewise_Constant {\n  using Y = typename Node::Y_type;\n  SplayTree<Node>&\
    \ ST;\n  using np = Node*;\n  using S = typename Node::value_type;\n  using App\
    \ = typename Node::operator_type;\n  using BT = Border_Type;\n  np root;\n  using\
    \ QUE = pq_min<pair<ll, np>>;\n  QUE que_lo, que_hi;\n  array<ll, 4> add;\n  array<ll,\
    \ 2> domain;\n\n  vc<np> my_pool;\n  np new_node(S x) {\n    np c = ST.new_node(x);\n\
    \    my_pool.eb(c);\n    return c;\n  }\n  ~Piecewise_Constant() {\n    for (auto\
    \ c : my_pool) {\n      ST.pool.destroy(c);\n    }\n  }\n\n  void swap(Piecewise_Constant&\
    \ other) noexcept {\n    ::swap(root, other.root);\n    ::swap(que_lo, other.que_lo);\n\
    \    ::swap(que_hi, other.que_hi);\n    ::swap(add, other.add);\n    ::swap(domain,\
    \ other.domain);\n    ::swap(my_pool, other.my_pool);\n  }\n\n  int size() { return\
    \ len(my_pool); }\n\n  // f(i) = (x1,x2,y)\n  template <typename F>\n  Piecewise_Constant(SplayTree<Node>&\
    \ ST, int n, F f)\n      : ST(ST), root(nullptr), add{}, domain{} {\n    assert(n\
    \ > 0);\n    vc<S> dat;\n    FOR(i, n) {\n      auto [x1, x2, y] = f(i);\n   \
    \   if (i == 0) {\n        dat.eb(S{x1, x2, y, BT::l, BT::r});\n        continue;\n\
    \      }\n      assert(dat.back().x2 == x1);\n      if (dat.back().y == y) {\n\
    \        dat.back().x2 = x2;\n        continue;\n      }\n      BT c = (dat.back().y\
    \ < y ? BT::inc : BT::dec);\n      dat.back().c2 = c;\n      dat.eb(S{x1, x2,\
    \ y, c, BT::r});\n    }\n    root = nullptr;\n    FOR(i, len(dat)) {\n      np\
    \ c = new_node(dat[i]);\n      add_que(c);\n      root = ST.merge(root, c);\n\
    \    }\n    domain[0] = dat[0].x1, domain[1] = dat.back().x2;\n  }\n\n  void shift(ll\
    \ a) {\n    add[0] += a, add[1] += a, add[2] += a, add[3] += a;\n    if (domain[0]\
    \ != -infty<ll>) domain[0] += a;\n    if (domain[1] != infty<ll>) domain[1] +=\
    \ a;\n  }\n\n  // f(x) \u3092 g(x) \u306B\u5909\u66F4. g(x)=min_{x+a<=t<=x+b}\
    \ f(x).\n  void slide_min(ll a, ll b) { slide(BT::inc, BT::dec, a, b, que_hi);\
    \ }\n\n  // f(x) \u3092 g(x) \u306B\u5909\u66F4. g(x)=max_{x+a<=t<=x+b} f(x).\n\
    \  void slide_max(ll a, ll b) { slide(BT::dec, BT::inc, a, b, que_lo); }\n\n \
    \ vc<tuple<ll, ll, Y>> get_all() {\n    vc<tuple<ll, ll, Y>> ANS;\n    auto dfs\
    \ = [&](auto& dfs, np c) -> void {\n      auto [x1, x2] = position(c);\n     \
    \ c->push();\n      if (c->l) dfs(dfs, c->l);\n      ANS.eb(x1, x2, c->y());\n\
    \      if (c->r) dfs(dfs, c->r);\n    };\n    dfs(dfs, root);\n    return ANS;\n\
    \  }\n\n  // \u5B9A\u7FA9\u57DF\u306E\u5DE6\u7AEF\u304C x \u306B\u306A\u308B\u3088\
    \u3046\u306B\u62E1\u5F35, y \u3067\u57CB\u3081\u308B\n  void extend_domain_left(ll\
    \ x, Y y) {\n    if (x == domain[0]) return;\n    assert(x < domain[0]);\n   \
    \ ST.splay_kth(root, 0);\n    BT color = (y < root->y() ? BT::inc : BT::dec);\n\
    \    np c = new_node(S{x - add[BT::l], domain[0] - add[color], y, BT::l, color});\n\
    \    root->c1() = color, root->x1() = domain[0] - add[color];\n    add_que(root);\n\
    \    root = ST.merge(c, root);\n    domain[0] = x;\n  }\n\n  void apply(ll L,\
    \ ll R, App app) {\n    if (L == R) return;\n    auto [A, tmp] = split(root, L,\
    \ domain[0], domain[1]);\n    auto [B, C] = split(tmp, R, L, domain[1]);\n   \
    \ ST.apply(B, app);\n    if (A) {\n      ST.splay_kth(A, A->size - 1);\n     \
    \ ST.splay_kth(B, 0);\n      assert(position(A).se == L && position(B).fi == L);\n\
    \      BT color = (A->y() < B->y() ? BT::inc : BT::dec);\n      A->c2() = color,\
    \ A->x2() = L - add[color];\n      B->c1() = color, B->x1() = L - add[color];\n\
    \      add_que(A), add_que(B);\n    } else {\n      ST.splay_kth(B, 0);\n    \
    \  assert(position(B).fi == L);\n      B->c1() = BT::l, B->x1() = L - add[BT::l];\n\
    \    }\n    if (C) {\n      ST.splay_kth(B, B->size - 1);\n      ST.splay_kth(C,\
    \ 0);\n      assert(position(B).se == R && position(C).fi == R);\n      BT color\
    \ = (B->y() < C->y() ? BT::inc : BT::dec);\n      B->c2() = color, B->x2() = R\
    \ - add[color];\n      C->c1() = color, C->x1() = R - add[color];\n      add_que(B),\
    \ add_que(C);\n    } else {\n      ST.splay_kth(B, B->size - 1);\n      assert(position(B).se\
    \ == R);\n      B->c2() = BT::r, B->x2() = R - add[BT::r];\n    }\n    root =\
    \ ST.merge3(A, B, C);\n  }\n\n  Y get(ll x) {\n    assert(domain[0] <= x && x\
    \ < domain[1]);\n    root = ST.find_max_right(\n        root, [&](S s) -> bool\
    \ { return (s.x1 + add[s.c1] <= x); });\n    ST.splay(root, true);\n    return\
    \ root->y();\n  }\n\n  pair<np, np> split(np c, ll x, ll a, ll b) {\n    // c\
    \ \u306E\u5B9A\u7FA9\u57DF\u304C [a,b)\n    assert(a <= x && x <= b);\n    if\
    \ (a == x) return {nullptr, c};\n    if (b == x) return {c, nullptr};\n    c =\
    \ ST.find_max_right(c,\n                          [&](S s) -> bool { return (s.x1\
    \ + add[s.c1] <= x); });\n    ST.splay(c, true);\n    auto [x1, x2] = position(c);\n\
    \    if (x1 == x) {\n      np l = c->l;\n      if (l) l->p = nullptr, c->l = nullptr;\n\
    \      c->update();\n      return {l, c};\n    }\n    assert(x1 < x && x < x2);\n\
    \    np cr = new_node(S{x - add[BT::l], c->x2(), c->y(), BT::l, c->c2()});\n \
    \   c->c2() = BT::r, c->x2() = x - add[BT::r];\n    np r = c->r;\n    if (!r)\
    \ {\n      c->update(), cr->update();\n      return {c, cr};\n    }\n    c->r\
    \ = nullptr, cr->r = r, r->p = cr;\n    c->update(), cr->update();\n    return\
    \ {c, cr};\n  }\n\n private:\n  inline bool active(np c) { return (c->p != nullptr\
    \ || c == root); }\n\n  pi position(np c) {\n    ll x1 = c->x1(), x2 = c->x2();\n\
    \    if (x1 != -infty<ll>) x1 += add[c->c1()];\n    if (x2 != infty<ll>) x2 +=\
    \ add[c->c2()];\n    return {x1, x2};\n  }\n\n  void slide(BT stay, BT move, ll\
    \ a, ll b, QUE& que) {\n    assert(domain[0] < domain[1]);\n    shift(-a);\n \
    \   b -= a;\n    if (domain[1] != infty<ll>) domain[1] -= b;\n    while (1) {\n\
    \      while (len(que)) {\n        auto [pri, c] = que.top();\n        if (pri\
    \ + add[move] - add[stay] > b) {\n          break;\n        }\n        elif (!active(c))\
    \ { que.pop(); }\n        elif (c->c1() != stay || c->c2() != move) { que.pop();\
    \ }\n        elif (c->x2() - c->x1() != pri) { que.pop(); }\n        else {\n\
    \          auto [x1, x2] = position(c);\n          assert(x2 - x1 <= b);\n   \
    \       que.pop();\n          ST.splay(c, false);\n          // c is deleted\n\
    \          auto [A, mid, B] = ST.split3(c, c->lsize(), c->lsize() + 1);\n    \
    \      assert(mid == c);\n\n          ST.splay_kth(A, A->size - 1), ST.splay_kth(B,\
    \ 0);\n          BT color = (A->y() < B->y() ? BT::inc : BT::dec);\n         \
    \ if (color == stay) {\n            B->c1() = stay, B->x1() = x1 - add[stay];\n\
    \            add_que(B);\n          } else {\n            A->c2() = move, A->x2()\
    \ = x2 - add[move];\n            add_que(A);\n          }\n          root = ST.merge(A,\
    \ B);\n        }\n      }\n      ST.splay_kth(root, 0);\n      auto [x1, x2] =\
    \ position(root);\n      if (x2 - x1 <= b && root->c2() == move) {\n        auto\
    \ [left, B] = ST.split(root, 1);\n        ST.splay_kth(B, 0);\n        assert(left\
    \ == root);\n        B->c1() = BT::l, B->x1() = x1 - add[BT::l];\n        root\
    \ = B;\n        continue;\n      }\n      ST.splay_kth(root, root->size - 1);\n\
    \      tie(x1, x2) = position(root);\n      if (x2 - x1 <= b && root->c1() ==\
    \ stay) {\n        auto [A, right] = ST.split(root, root->size - 1);\n       \
    \ ST.splay_kth(A, A->size - 1);\n        assert(right == root);\n        A->c2()\
    \ = BT::r, A->x2() = x2 - add[BT::r];\n        root = A;\n        continue;\n\
    \      }\n      break;\n    }\n    add[move] -= b, add[BT::r] -= b;\n  }\n\n \
    \ void add_que(np c) {\n    ll d = c->x2() - c->x1();\n    if (c->c1() == BT::inc\
    \ && c->c2() == BT::dec) {\n      que_hi.emplace(d, c);\n    }\n    if (c->c1()\
    \ == BT::dec && c->c2() == BT::inc) {\n      que_lo.emplace(d, c);\n    }\n  }\n\
    };\n#line 2 \"ds/piecewise_constant/piecewise_constant_acted.hpp\"\n\n// https://codeforces.com/contest/1023/problem/G\n\
    template <typename AS>\nstruct Node_Piecewise_Constant_Acted {\n  using Y_type\
    \ = typename AS::S;\n  using A = typename AS::A;\n  using Monoid_A = typename\
    \ AS::Monoid_A;\n  struct S {\n    ll x1, x2;  // y on [x1,x2)\n    Y_type y;\n\
    \    Border_Type c1, c2;\n  };\n  using value_type = S;\n  using operator_type\
    \ = int;\n  using np = Node_Piecewise_Constant_Acted*;\n\n  np p, l, r;\n  bool\
    \ rev;\n  S x;\n  A lazy;\n  u32 size;\n  ll& x1() { return x.x1; }\n  ll& x2()\
    \ { return x.x2; }\n  Border_Type& c1() { return x.c1; }\n  Border_Type& c2()\
    \ { return x.c2; }\n  Y_type& y() { return x.y; }\n\n  int lsize() { return (l\
    \ ? l->size : 0); }\n  int rsize() { return (r ? r->size : 0); }\n\n  static void\
    \ new_node(np n, const S& x) {\n    n->p = n->l = n->r = nullptr;\n    n->x =\
    \ x, n->size = 1, n->rev = 0;\n  }\n\n  void update() { size = 1 + lsize() + rsize();\
    \ }\n  void apply(const A& a) {\n    x.y = AS::act(x.y, a);\n    lazy = AS::Monoid_A::op(lazy,\
    \ a);\n  }\n  void push() {\n    if (lazy != Monoid_A::unit()) {\n      if (l)\
    \ {\n        l->apply(lazy);\n      }\n      if (r) {\n        r->apply(lazy);\n\
    \      }\n      lazy = Monoid_A::unit();\n    }\n    if (rev) {\n      if (l)\
    \ {\n        l->rev ^= 1, swap(l->l, l->r);\n      }\n      if (r) {\n       \
    \ r->rev ^= 1, swap(r->l, r->r);\n      }\n      rev = 0;\n    }\n  }\n\n  //\
    \ update, push \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\u306E\u306F\u3001\
    splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\
    \u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\u305D\u306E\u6642\u70B9\
    \u3067 update, push \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\
    \u3066\u3088\u3044\u3002\n  S get() { return x; }\n  void set(const S& xx) {\n\
    \    x = xx;\n    update();\n  }\n  void reverse() {\n    swap(l, r);\n    rev\
    \ ^= 1;\n  }\n};\n"
  code: "#include \"ds/piecewise_constant/piecewise_constant.hpp\"\n\n// https://codeforces.com/contest/1023/problem/G\n\
    template <typename AS>\nstruct Node_Piecewise_Constant_Acted {\n  using Y_type\
    \ = typename AS::S;\n  using A = typename AS::A;\n  using Monoid_A = typename\
    \ AS::Monoid_A;\n  struct S {\n    ll x1, x2;  // y on [x1,x2)\n    Y_type y;\n\
    \    Border_Type c1, c2;\n  };\n  using value_type = S;\n  using operator_type\
    \ = int;\n  using np = Node_Piecewise_Constant_Acted*;\n\n  np p, l, r;\n  bool\
    \ rev;\n  S x;\n  A lazy;\n  u32 size;\n  ll& x1() { return x.x1; }\n  ll& x2()\
    \ { return x.x2; }\n  Border_Type& c1() { return x.c1; }\n  Border_Type& c2()\
    \ { return x.c2; }\n  Y_type& y() { return x.y; }\n\n  int lsize() { return (l\
    \ ? l->size : 0); }\n  int rsize() { return (r ? r->size : 0); }\n\n  static void\
    \ new_node(np n, const S& x) {\n    n->p = n->l = n->r = nullptr;\n    n->x =\
    \ x, n->size = 1, n->rev = 0;\n  }\n\n  void update() { size = 1 + lsize() + rsize();\
    \ }\n  void apply(const A& a) {\n    x.y = AS::act(x.y, a);\n    lazy = AS::Monoid_A::op(lazy,\
    \ a);\n  }\n  void push() {\n    if (lazy != Monoid_A::unit()) {\n      if (l)\
    \ {\n        l->apply(lazy);\n      }\n      if (r) {\n        r->apply(lazy);\n\
    \      }\n      lazy = Monoid_A::unit();\n    }\n    if (rev) {\n      if (l)\
    \ {\n        l->rev ^= 1, swap(l->l, l->r);\n      }\n      if (r) {\n       \
    \ r->rev ^= 1, swap(r->l, r->r);\n      }\n      rev = 0;\n    }\n  }\n\n  //\
    \ update, push \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\u306E\u306F\u3001\
    splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\
    \u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\u305D\u306E\u6642\u70B9\
    \u3067 update, push \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\
    \u3066\u3088\u3044\u3002\n  S get() { return x; }\n  void set(const S& xx) {\n\
    \    x = xx;\n    update();\n  }\n  void reverse() {\n    swap(l, r);\n    rev\
    \ ^= 1;\n  }\n};\n"
  dependsOn:
  - ds/piecewise_constant/piecewise_constant.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/piecewise_constant/piecewise_constant_acted.hpp
  requiredBy: []
  timestamp: '2025-09-18 21:29:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/piecewise_constant/piecewise_constant_acted.hpp
layout: document
redirect_from:
- /library/ds/piecewise_constant/piecewise_constant_acted.hpp
- /library/ds/piecewise_constant/piecewise_constant_acted.hpp.html
title: ds/piecewise_constant/piecewise_constant_acted.hpp
---
