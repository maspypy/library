---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/default_prod.hpp
    title: alg/default_prod.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
    title: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1649.test.cpp
    title: test/3_yukicoder/1649.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826.test.cpp
    title: test/3_yukicoder/1826.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2935.test.cpp
    title: test/3_yukicoder/2935.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/789.test.cpp
    title: test/3_yukicoder/789.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/default_prod.hpp\"\ntemplate <class Monoid>\nstruct\
    \ DefaultUnitProd {\n  using X = typename Monoid::value_type;\n  static constexpr\
    \ bool unit_only = true;\n  X operator()(long long, long long) const { return\
    \ Monoid::unit(); }\n};\n#line 2 \"ds/segtree/dynamic_segtree.hpp\"\n\r\n/*\r\n\
    \u8981\u7D20\u6570\u306E\u7BA1\u7406\u304C\u9762\u5012\u306A\u306E\u3067, vector<int>\
    \ \u3092\u4F7F\u3046\u3088\u3046\u306B\u3057\u305F.\r\n\u53C2\u7167\u3092\u6301\
    \u3063\u3066\u3044\u308B\u3068\u304D\u306B eb \u304C\u5165\u308B\u3068\u7834\u58CA\
    \u3055\u308C\u308B\u3053\u3068\u306B\u6C17\u3092\u4ED8\u3051\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\uFF01\r\n*/\r\ntemplate <typename Monoid, bool PERSISTENT,\r\
    \n          class DefaultProd = DefaultUnitProd<Monoid>>\r\nstruct Dynamic_SegTree\
    \ {\r\n  using MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  struct\
    \ Node {\r\n    int ch[2];\r\n    X x;\r\n  };\r\n\r\n  const ll L0, R0;\r\n \
    \ DefaultProd default_prod;\r\n  vc<Node> node;\r\n  static constexpr int NIL\
    \ = 0;\r\n\r\n  Dynamic_SegTree(ll L0_, ll R0_, DefaultProd func = DefaultProd{})\r\
    \n      : L0(L0_), R0(L0_ == R0_ ? R0_ + 1 : R0_), default_prod(std::move(func))\
    \ {\r\n    reset();\r\n  }\r\n\r\n  void reserve(int n) { node.reserve(n + 1);\
    \ }\r\n  void reset() { node.clear(), node.eb(Node{NIL, NIL, MX::unit()}); }\r\
    \n\r\n  inline X get_prod(int i, ll l, ll r) {\r\n    if constexpr (kUnitOnly)\
    \ {\r\n      return node[i].x;\r\n    } else {\r\n      return (i == NIL ? default_prod(l,\
    \ r) : node[i].x);\r\n    }\r\n  }\r\n  void update(int i, ll l, ll r) {\r\n \
    \   assert(l + 1 < r);\r\n    ll m = (l + r) / 2;\r\n    int L = node[i].ch[0],\
    \ R = node[i].ch[1];\r\n    node[i].x = MX::op(get_prod(L, l, m), get_prod(R,\
    \ m, r));\r\n  }\r\n\r\n  inline int new_root() { return new_node(L0, R0); }\r\
    \n\r\n  inline int new_node(const X &x) {\r\n    node.emplace_back(Node{NIL, NIL,\
    \ x});\r\n    return int(node.size()) - 1;\r\n  }\r\n\r\n  inline int new_node(ll\
    \ l, ll r) { return new_node(default_prod(l, r)); }\r\n  inline int new_node()\
    \ { return new_node(L0, R0); }\r\n  inline Node operator[](int i) const { return\
    \ node[i]; }\r\n\r\n  int new_node_from_vector(const vc<X> &dat) {\r\n    assert(L0\
    \ == 0 && R0 == len(dat));\r\n    auto dfs = [&](auto &dfs, ll l, ll r) -> int\
    \ {\r\n      if (r == l + 1) return new_node(dat[l]);\r\n      ll m = (l + r)\
    \ / 2;\r\n      int l_root = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\r\n    \
    \  X x = MX::op(node[l_root].x, node[r_root].x);\r\n      node.eb(Node{l_root,\
    \ r_root, x});\r\n      return int(node.size()) - 1;\r\n    };\r\n    return dfs(dfs,\
    \ 0, len(dat));\r\n  }\r\n\r\n  X prod(int root, ll l, ll r) {\r\n    assert(root\
    \ != NIL && L0 <= l && l <= r && r <= R0);\r\n    if (l == r) return MX::unit();\r\
    \n    X x = MX::unit();\r\n    prod_rec(root, L0, R0, l, r, x);\r\n    return\
    \ x;\r\n  }\r\n\r\n  X prod_all(int root) { return node[root].x; }\r\n\r\n  int\
    \ set(int root, ll i, const X &x) {\r\n    assert(root != NIL && L0 <= i && i\
    \ < R0);\r\n    root = copy_node(root);\r\n    set_rec(root, L0, R0, i, x);\r\n\
    \    return root;\r\n  }\r\n\r\n  int multiply(int root, ll i, const X &x) {\r\
    \n    assert(root != NIL && L0 <= i && i < R0);\r\n    root = copy_node(root);\r\
    \n    multiply_rec(root, L0, R0, i, x);\r\n    return root;\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  ll max_right(int root, F check, ll L) {\r\n    assert(root\
    \ != NIL && L0 <= L && L <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\
    \n    return max_right_rec(root, check, L0, R0, L, x);\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  ll min_left(int root, F check, ll R) {\r\n    assert(root\
    \ != NIL && L0 <= R && R <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\
    \n    return min_left_rec(root, check, L0, R0, R, x);\r\n  }\r\n\r\n  // (idx,\
    \ val)\r\n  template <typename F>\r\n  void enumerate(int root, F f) {\r\n   \
    \ assert(root != NIL);\r\n    auto dfs = [&](auto &dfs, int c, ll l, ll r) ->\
    \ void {\r\n      if (c == NIL) return;\r\n      if (r - l == 1) {\r\n       \
    \ f(l, node[c].x);\r\n        return;\r\n      }\r\n      ll m = (l + r) / 2;\r\
    \n      dfs(dfs, node[c].ch[0], l, m), dfs(dfs, node[c].ch[1], m, r);\r\n    };\r\
    \n    dfs(dfs, root, L0, R0);\r\n  }\r\n\r\n private:\r\n  static constexpr bool\
    \ kUnitOnly =\r\n      std::is_same_v<DefaultProd, DefaultUnitProd<Monoid>>;\r\
    \n  int copy_node(int c) {\r\n    if constexpr (!PERSISTENT) return c;\r\n   \
    \ if (c == NIL) return c;\r\n    node.eb(node[c]);\r\n    return int(node.size())\
    \ - 1;\r\n  }\r\n\r\n  int touch_child(int c, ll l, ll r) {\r\n    if constexpr\
    \ (!PERSISTENT) {\r\n      return (c == NIL ? new_node(l, r) : c);\r\n    } else\
    \ {\r\n      return (c == NIL ? new_node(l, r) : copy_node(c));\r\n    }\r\n \
    \ }\r\n\r\n  void set_rec(int c, ll l, ll r, ll i, const X &x) {\r\n    assert(c\
    \ != NIL);\r\n    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\
    \u308B\r\n    if (r == l + 1) {\r\n      node[c].x = x;\r\n      return;\r\n \
    \   }\r\n    ll m = (l + r) / 2;\r\n    int b = (m <= i);\r\n    ll nl = (b ?\
    \ m : l), nr = (b ? r : m);\r\n    node[c].ch[b] = touch_child(node[c].ch[b],\
    \ nl, nr);\r\n    set_rec(node[c].ch[b], nl, nr, i, x);\r\n    update(c, l, r);\r\
    \n  }\r\n\r\n  void multiply_rec(int c, ll l, ll r, ll i, const X &x) {\r\n  \
    \  assert(c != NIL);\r\n    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\
    \u3042\u308B\r\n    if (r == l + 1) {\r\n      node[c].x = MX::op(node[c].x, x);\r\
    \n      return;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    int b = (m <= i);\r\
    \n    ll nl = (b ? m : l), nr = (b ? r : m);\r\n    node[c].ch[b] = touch_child(node[c].ch[b],\
    \ nl, nr);\r\n    multiply_rec(node[c].ch[b], nl, nr, i, x);\r\n    update(c,\
    \ l, r);\r\n  }\r\n\r\n  void prod_rec(int c, ll l, ll r, ll ql, ll qr, X &x)\
    \ {\r\n    chmax(ql, l), chmin(qr, r);\r\n    if (ql >= qr) return;\r\n    if\
    \ (c == NIL || (l == ql && r == qr)) {\r\n      x = MX::op(x, get_prod(c, ql,\
    \ qr));\r\n      return;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    prod_rec(node[c].ch[0],\
    \ l, m, ql, qr, x);\r\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\r\n  }\r\n\
    \r\n  template <typename F>\r\n  ll max_right_rec(int c, const F &check, ll l,\
    \ ll r, ll ql, X &x) {\r\n    if (r <= ql) return R0;\r\n    X myprod = get_prod(c,\
    \ l, r);\r\n    if (ql <= l && check(MX::op(x, myprod))) {\r\n      x = MX::op(x,\
    \ myprod);\r\n      return R0;\r\n    }\r\n    if (r == l + 1) return l;\r\n \
    \   ll m = (l + r) / 2;\r\n    ll k = max_right_rec(node[c].ch[0], check, l, m,\
    \ ql, x);\r\n    if (k != R0) return k;\r\n    return max_right_rec(node[c].ch[1],\
    \ check, m, r, ql, x);\r\n  }\r\n\r\n  // \u3053\u308C new node \u4F5C\u3063\u3066\
    \u308B\u306E\u306F\u3055\u307C\u308A\r\n  template <typename F>\r\n  ll min_left_rec(int\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\r\n    if (qr <= l) return L0;\r\
    \n    X myprod = get_prod(c, l, r);\r\n    if (r <= qr && check(MX::op(myprod,\
    \ x))) {\r\n      x = MX::op(x, myprod);\r\n      return L0;\r\n    }\r\n    if\
    \ (r == l + 1) return r;\r\n    ll m = (l + r) / 2;\r\n    ll k = min_left_rec(node[c].ch[1],\
    \ check, m, r, qr, x);\r\n    if (k != L0) return k;\r\n    return min_left_rec(node[c].ch[0],\
    \ check, l, m, qr, x);\r\n  }\r\n};\r\n"
  code: "#include \"alg/default_prod.hpp\"\r\n\r\n/*\r\n\u8981\u7D20\u6570\u306E\u7BA1\
    \u7406\u304C\u9762\u5012\u306A\u306E\u3067, vector<int> \u3092\u4F7F\u3046\u3088\
    \u3046\u306B\u3057\u305F.\r\n\u53C2\u7167\u3092\u6301\u3063\u3066\u3044\u308B\u3068\
    \u304D\u306B eb \u304C\u5165\u308B\u3068\u7834\u58CA\u3055\u308C\u308B\u3053\u3068\
    \u306B\u6C17\u3092\u4ED8\u3051\u308B\u5FC5\u8981\u304C\u3042\u308B\uFF01\r\n*/\r\
    \ntemplate <typename Monoid, bool PERSISTENT,\r\n          class DefaultProd =\
    \ DefaultUnitProd<Monoid>>\r\nstruct Dynamic_SegTree {\r\n  using MX = Monoid;\r\
    \n  using X = typename MX::value_type;\r\n  struct Node {\r\n    int ch[2];\r\n\
    \    X x;\r\n  };\r\n\r\n  const ll L0, R0;\r\n  DefaultProd default_prod;\r\n\
    \  vc<Node> node;\r\n  static constexpr int NIL = 0;\r\n\r\n  Dynamic_SegTree(ll\
    \ L0_, ll R0_, DefaultProd func = DefaultProd{})\r\n      : L0(L0_), R0(L0_ ==\
    \ R0_ ? R0_ + 1 : R0_), default_prod(std::move(func)) {\r\n    reset();\r\n  }\r\
    \n\r\n  void reserve(int n) { node.reserve(n + 1); }\r\n  void reset() { node.clear(),\
    \ node.eb(Node{NIL, NIL, MX::unit()}); }\r\n\r\n  inline X get_prod(int i, ll\
    \ l, ll r) {\r\n    if constexpr (kUnitOnly) {\r\n      return node[i].x;\r\n\
    \    } else {\r\n      return (i == NIL ? default_prod(l, r) : node[i].x);\r\n\
    \    }\r\n  }\r\n  void update(int i, ll l, ll r) {\r\n    assert(l + 1 < r);\r\
    \n    ll m = (l + r) / 2;\r\n    int L = node[i].ch[0], R = node[i].ch[1];\r\n\
    \    node[i].x = MX::op(get_prod(L, l, m), get_prod(R, m, r));\r\n  }\r\n\r\n\
    \  inline int new_root() { return new_node(L0, R0); }\r\n\r\n  inline int new_node(const\
    \ X &x) {\r\n    node.emplace_back(Node{NIL, NIL, x});\r\n    return int(node.size())\
    \ - 1;\r\n  }\r\n\r\n  inline int new_node(ll l, ll r) { return new_node(default_prod(l,\
    \ r)); }\r\n  inline int new_node() { return new_node(L0, R0); }\r\n  inline Node\
    \ operator[](int i) const { return node[i]; }\r\n\r\n  int new_node_from_vector(const\
    \ vc<X> &dat) {\r\n    assert(L0 == 0 && R0 == len(dat));\r\n    auto dfs = [&](auto\
    \ &dfs, ll l, ll r) -> int {\r\n      if (r == l + 1) return new_node(dat[l]);\r\
    \n      ll m = (l + r) / 2;\r\n      int l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\r\n      X x = MX::op(node[l_root].x, node[r_root].x);\r\n      node.eb(Node{l_root,\
    \ r_root, x});\r\n      return int(node.size()) - 1;\r\n    };\r\n    return dfs(dfs,\
    \ 0, len(dat));\r\n  }\r\n\r\n  X prod(int root, ll l, ll r) {\r\n    assert(root\
    \ != NIL && L0 <= l && l <= r && r <= R0);\r\n    if (l == r) return MX::unit();\r\
    \n    X x = MX::unit();\r\n    prod_rec(root, L0, R0, l, r, x);\r\n    return\
    \ x;\r\n  }\r\n\r\n  X prod_all(int root) { return node[root].x; }\r\n\r\n  int\
    \ set(int root, ll i, const X &x) {\r\n    assert(root != NIL && L0 <= i && i\
    \ < R0);\r\n    root = copy_node(root);\r\n    set_rec(root, L0, R0, i, x);\r\n\
    \    return root;\r\n  }\r\n\r\n  int multiply(int root, ll i, const X &x) {\r\
    \n    assert(root != NIL && L0 <= i && i < R0);\r\n    root = copy_node(root);\r\
    \n    multiply_rec(root, L0, R0, i, x);\r\n    return root;\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  ll max_right(int root, F check, ll L) {\r\n    assert(root\
    \ != NIL && L0 <= L && L <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\
    \n    return max_right_rec(root, check, L0, R0, L, x);\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  ll min_left(int root, F check, ll R) {\r\n    assert(root\
    \ != NIL && L0 <= R && R <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\
    \n    return min_left_rec(root, check, L0, R0, R, x);\r\n  }\r\n\r\n  // (idx,\
    \ val)\r\n  template <typename F>\r\n  void enumerate(int root, F f) {\r\n   \
    \ assert(root != NIL);\r\n    auto dfs = [&](auto &dfs, int c, ll l, ll r) ->\
    \ void {\r\n      if (c == NIL) return;\r\n      if (r - l == 1) {\r\n       \
    \ f(l, node[c].x);\r\n        return;\r\n      }\r\n      ll m = (l + r) / 2;\r\
    \n      dfs(dfs, node[c].ch[0], l, m), dfs(dfs, node[c].ch[1], m, r);\r\n    };\r\
    \n    dfs(dfs, root, L0, R0);\r\n  }\r\n\r\n private:\r\n  static constexpr bool\
    \ kUnitOnly =\r\n      std::is_same_v<DefaultProd, DefaultUnitProd<Monoid>>;\r\
    \n  int copy_node(int c) {\r\n    if constexpr (!PERSISTENT) return c;\r\n   \
    \ if (c == NIL) return c;\r\n    node.eb(node[c]);\r\n    return int(node.size())\
    \ - 1;\r\n  }\r\n\r\n  int touch_child(int c, ll l, ll r) {\r\n    if constexpr\
    \ (!PERSISTENT) {\r\n      return (c == NIL ? new_node(l, r) : c);\r\n    } else\
    \ {\r\n      return (c == NIL ? new_node(l, r) : copy_node(c));\r\n    }\r\n \
    \ }\r\n\r\n  void set_rec(int c, ll l, ll r, ll i, const X &x) {\r\n    assert(c\
    \ != NIL);\r\n    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\
    \u308B\r\n    if (r == l + 1) {\r\n      node[c].x = x;\r\n      return;\r\n \
    \   }\r\n    ll m = (l + r) / 2;\r\n    int b = (m <= i);\r\n    ll nl = (b ?\
    \ m : l), nr = (b ? r : m);\r\n    node[c].ch[b] = touch_child(node[c].ch[b],\
    \ nl, nr);\r\n    set_rec(node[c].ch[b], nl, nr, i, x);\r\n    update(c, l, r);\r\
    \n  }\r\n\r\n  void multiply_rec(int c, ll l, ll r, ll i, const X &x) {\r\n  \
    \  assert(c != NIL);\r\n    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\
    \u3042\u308B\r\n    if (r == l + 1) {\r\n      node[c].x = MX::op(node[c].x, x);\r\
    \n      return;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    int b = (m <= i);\r\
    \n    ll nl = (b ? m : l), nr = (b ? r : m);\r\n    node[c].ch[b] = touch_child(node[c].ch[b],\
    \ nl, nr);\r\n    multiply_rec(node[c].ch[b], nl, nr, i, x);\r\n    update(c,\
    \ l, r);\r\n  }\r\n\r\n  void prod_rec(int c, ll l, ll r, ll ql, ll qr, X &x)\
    \ {\r\n    chmax(ql, l), chmin(qr, r);\r\n    if (ql >= qr) return;\r\n    if\
    \ (c == NIL || (l == ql && r == qr)) {\r\n      x = MX::op(x, get_prod(c, ql,\
    \ qr));\r\n      return;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    prod_rec(node[c].ch[0],\
    \ l, m, ql, qr, x);\r\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\r\n  }\r\n\
    \r\n  template <typename F>\r\n  ll max_right_rec(int c, const F &check, ll l,\
    \ ll r, ll ql, X &x) {\r\n    if (r <= ql) return R0;\r\n    X myprod = get_prod(c,\
    \ l, r);\r\n    if (ql <= l && check(MX::op(x, myprod))) {\r\n      x = MX::op(x,\
    \ myprod);\r\n      return R0;\r\n    }\r\n    if (r == l + 1) return l;\r\n \
    \   ll m = (l + r) / 2;\r\n    ll k = max_right_rec(node[c].ch[0], check, l, m,\
    \ ql, x);\r\n    if (k != R0) return k;\r\n    return max_right_rec(node[c].ch[1],\
    \ check, m, r, ql, x);\r\n  }\r\n\r\n  // \u3053\u308C new node \u4F5C\u3063\u3066\
    \u308B\u306E\u306F\u3055\u307C\u308A\r\n  template <typename F>\r\n  ll min_left_rec(int\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\r\n    if (qr <= l) return L0;\r\
    \n    X myprod = get_prod(c, l, r);\r\n    if (r <= qr && check(MX::op(myprod,\
    \ x))) {\r\n      x = MX::op(x, myprod);\r\n      return L0;\r\n    }\r\n    if\
    \ (r == l + 1) return r;\r\n    ll m = (l + r) / 2;\r\n    ll k = min_left_rec(node[c].ch[1],\
    \ check, m, r, qr, x);\r\n    if (k != L0) return k;\r\n    return min_left_rec(node[c].ch[0],\
    \ check, l, m, qr, x);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/default_prod.hpp
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2025-09-02 00:55:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1649.test.cpp
  - test/3_yukicoder/789.test.cpp
  - test/3_yukicoder/2935.test.cpp
  - test/3_yukicoder/1826.test.cpp
  - test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
documentation_of: ds/segtree/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree.hpp
- /library/ds/segtree/dynamic_segtree.hpp.html
title: ds/segtree/dynamic_segtree.hpp
---
