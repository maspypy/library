
// 常にほとんどの要素が unit であることが保証されるような動的セグ木
// したがって、default_prod の類は持たせられず、acted monoid も一般には扱えない
// 追加 N 回のときノード数 N 以下が保証される
template <typename Monoid, bool PERSISTENT>
struct Dynamic_SegTree_Sparse {
  using MX = Monoid;
  using X = typename MX::value_type;

  struct Node {
    int ch[2];
    ll idx;
    X prod, x;
  };
  const ll L0, R0;
  static constexpr int NIL = 0;
  vc<Node> node;
  vc<int> FREE;

  Dynamic_SegTree_Sparse(ll L0, ll R0) : L0(L0), R0(R0) { reset(); }
  void reserve(int n) { node.reserve(n + 1); }
  void reset() {
    node.clear(), FREE.clear();
    node.eb(Node{{NIL, NIL}, 0, MX::unit(), MX::unit()});  // NIL
  }

  // 木 dp のマージのときなどに使用すると MLE 回避できることがある
  // https://codeforces.com/problemset/problem/671/D
  void free_subtree(int c) {
    assert(c != NIL);
    auto dfs = [&](auto &dfs, int c) -> void {
      if (c == NIL) return;
      dfs(dfs, node[c].ch[0]), dfs(dfs, node[c].ch[1]);
      FREE.eb(c);
    };
    dfs(dfs, c);
  }

  inline int new_root() { return NIL; }

  inline int new_node(ll idx, const X x) {
    if (!FREE.empty()) {
      int id = POP(FREE);
      node[id].ch[0] = node[id].ch[1] = NIL;
      node[id].idx = idx, node[id].x = x, node[id].prod = x;
      return id;
    }
    node.eb(Node{{NIL, NIL}, idx, x, x});
    return int(node.size()) - 1;
  }
  inline Node operator[](int i) const { return node[i]; }

  X prod(int root, ll l, ll r) {
    assert(L0 <= l && l <= r && r <= R0);
    if (root == NIL || l == r) return MX::unit();
    X x = MX::unit();
    prod_rec(root, L0, R0, l, r, x);
    return x;
  }

  X prod_all(int root) { return (root == NIL ? MX::unit() : node[root].prod); }

  int set(int root, ll i, const X &x) {
    assert(L0 <= i && i < R0);
    return set_rec(root, L0, R0, i, x);
  }

  int multiply(int root, ll i, const X &x) {
    assert(L0 <= i && i < R0);
    return multiply_rec(root, L0, R0, i, x);
  }

  template <typename F>
  ll max_right(int root, F check, ll L) {
    assert(L0 <= L && L <= R0 && check(MX::unit()));
    X x = MX::unit();
    return max_right_rec(root, check, L0, R0, L, x);
  }

  template <typename F>
  ll min_left(int root, F check, ll R) {
    assert(L0 <= R && R <= R0 && check(MX::unit()));
    X x = MX::unit();
    return min_left_rec(root, check, L0, R0, R, x);
  }

  vc<pair<ll, X>> get_all(int root) {
    vc<pair<ll, X>> res;
    auto dfs = [&](auto &dfs, int c) -> void {
      if (c == NIL) return;
      dfs(dfs, node[c].ch[0]);
      res.eb(node[c].idx, node[c].x);
      dfs(dfs, node[c].ch[1]);
    };
    dfs(dfs, root);
    return res;
  }

  X get(int root, ll idx) {
    auto dfs = [&](auto &dfs, int c) -> X {
      if (c == NIL) return MX::unit();
      if (idx == node[c].idx) return node[c].x;
      return dfs(dfs, node[c].ch[idx > node[c].idx]);
    };
    return dfs(dfs, root);
  }

 private:
  inline void update(int c) {
    node[c].prod = node[c].x;
    node[c].prod = MX::op(node[node[c].ch[0]].prod, node[c].prod);
    node[c].prod = MX::op(node[c].prod, node[node[c].ch[1]].prod);
  }

  inline int copy_node(int c) {
    if constexpr (!PERSISTENT)
      return c;
    else {
      if (c == NIL) return c;
      node.eb(node[c]);
      return int(node.size()) - 1;
    }
  }

  int set_rec(int c, ll l, ll r, ll i, X x) {
    if (c == NIL) return new_node(i, x);
    c = copy_node(c);
    if (node[c].idx == i) {
      node[c].x = x;
      update(c);
      return c;
    }
    ll m = (l + r) / 2;
    if (i < m) {
      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x, x);
      node[c].ch[0] = set_rec(node[c].ch[0], l, m, i, x);
    }
    if (m <= i) {
      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x, x);
      node[c].ch[1] = set_rec(node[c].ch[1], m, r, i, x);
    }
    update(c);
    return c;
  }

  int multiply_rec(int c, ll l, ll r, ll i, X x) {
    if (c == NIL) return new_node(i, x);
    c = copy_node(c);
    if (node[c].idx == i) {
      node[c].x = MX::op(node[c].x, x);
      update(c);
      return c;
    }
    ll m = (l + r) / 2;
    if (i < m) {
      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x, x);
      node[c].ch[0] = multiply_rec(node[c].ch[0], l, m, i, x);
    }
    if (m <= i) {
      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x, x);
      node[c].ch[1] = multiply_rec(node[c].ch[1], m, r, i, x);
    }
    update(c);
    return c;
  }

  void prod_rec(int c, ll l, ll r, ll ql, ll qr, X &x) {
    chmax(ql, l);
    chmin(qr, r);
    if (ql >= qr || c == NIL) return;
    if (l == ql && r == qr) {
      x = MX::op(x, node[c].prod);
      return;
    }
    ll m = (l + r) / 2;
    prod_rec(node[c].ch[0], l, m, ql, qr, x);
    if (ql <= (node[c].idx) && (node[c].idx) < qr) x = MX::op(x, node[c].x);
    prod_rec(node[c].ch[1], m, r, ql, qr, x);
  }

  template <typename F>
  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X &x) {
    if (c == NIL || r <= ql) return R0;
    if (check(MX::op(x, node[c].prod))) {
      x = MX::op(x, node[c].prod);
      return R0;
    }
    ll m = (l + r) / 2;
    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);
    if (k != R0) return k;
    if (ql <= node[c].idx) {
      x = MX::op(x, node[c].x);
      if (!check(x)) return node[c].idx;
    }
    return max_right_rec(node[c].ch[1], check, m, r, ql, x);
  }

  template <typename F>
  ll min_left_rec(int c, const F &check, ll l, ll r, ll qr, X &x) {
    if (c == NIL || qr <= l) return L0;
    if (check(MX::op(node[c].prod, x))) {
      x = MX::op(node[c].prod, x);
      return L0;
    }
    ll m = (l + r) / 2;
    ll k = min_left_rec(node[c].ch[1], check, m, r, qr, x);
    if (k != L0) return k;
    if (node[c].idx < qr) {
      x = MX::op(node[c].x, x);
      if (!check(x)) return node[c].idx + 1;
    }
    return min_left_rec(node[c].ch[0], check, l, m, qr, x);
  }
};
