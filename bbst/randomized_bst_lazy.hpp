
// reverse はとりあえず、Monoid_X の可換性を仮定している！
template <typename Lazy, int NODES = 1'000'000>
struct Randomized_BST_Lazy {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;

  struct Node {
    Node *l, *r;
    X x, prod;
    A a;
    int size;
    bool rev;
    bool propagated;
  };

  Node *pool;
  int pid;

  Randomized_BST_Lazy() : pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
    pool[pid].a = Monoid_A::unit();
    pool[pid].size = 1;
    pool[pid].rev = 0;
    pool[pid].propagated = 1;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      int m = (l + r) / 2;
      Node *l_root = dfs(dfs, l, m);
      Node *r_root = dfs(dfs, m + 1, r);
      Node *root = new_node(dat[m]);
      root->l = l_root, root->r = r_root;
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  // 左に右をマージ
  void merge(Node *&root, Node *r_root) {
    root = merge_rec(root, r_root);
    return;
  }

  // 左右に分けて、root を左側に変更。右側を return する。
  Node *split(Node *&root, int k) {
    if (!root) assert(k == 0);
    if (root) assert(0 <= k && k <= root->size);
    auto [nl, nr] = split_rec(root, k);
    root = nl;
    return nr;
  }

  X prod(Node *&root, int l, int r) {
    assert(0 <= l && l <= r && r <= root->size);
    if (l == r) return Monoid_X::unit();
    Node *r_root = split(root, r);
    Node *m_root = split(root, l);
    X res = m_root->prod;
    merge(root, m_root);
    merge(root, r_root);
    return res;
  }

  void reverse(Node *&root, int l, int r) {
    assert(Monoid_X::commute);
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return;
    Node *r_root = split(root, r);
    Node *m_root = split(root, l);
    m_root->rev ^= 1;
    prop(m_root);
    update(m_root);
    merge(root, m_root);
    merge(root, r_root);
  }

  void apply(Node *&root, int l, int r, const A &a) {
    assert(0 <= l && l <= r && r <= root->size);
    if (l == r) return;
    Node *r_root = split(root, r);
    Node *m_root = split(root, l);
    m_root->x = Lazy::act(m_root->x, a);
    m_root->prod = Lazy::act(m_root->prod, a);
    m_root->a = Monoid_A::op(m_root->a, a);
    m_root->propagated = 0;
    prop(m_root);
    update(m_root);
    merge(root, m_root);
    merge(root, r_root);
  }

  // root の k 番目に n を挿入する
  void insert(Node *&root, int k, Node *n) {
    if (!root) {
      assert(k == 0);
      root = n;
      return;
    }
    assert(0 <= k && k <= root->size);
    auto r_root = split(root, k);
    merge(root, n);
    merge(root, r_root);
  }

  void insert(Node *&root, int k, const X &x) { insert(root, k, new_node(x)); }

  // root から k 番目を削除。削除したノードをかえす
  Node *erase(Node *&root, int k) {
    assert(0 <= k && k < root->size);
    auto nr = split(root, k + 1);
    auto nm = split(root, k);
    merge(root, nr);
    return nm;
  }

  void debug(Node *root) {
    print("RBST");
    string s;
    auto dfs = [&](auto &dfs, Node *n) -> void {
      if (!n) return;
      s += "l";
      dfs(dfs, n->l);
      s.pop_back();
      print(s, "size", n->size, "x", n->x, "prod", n->prod, "apply", n->a);
      s += "r";
      dfs(dfs, n->r);
      s.pop_back();
    };
    dfs(dfs, root);
  }

private:
  inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }

  void prop(Node *c) {
    if (!c->propagated) {
      if (c->l) {
        c->l->x = Lazy::act(c->l->x, c->a);
        c->l->prod = Lazy::act(c->l->prod, c->a);
        c->l->a = Monoid_A::op(c->l->a, c->a);
        c->l->propagated = 0;
      }
      if (c->r) {
        c->r->x = Lazy::act(c->r->x, c->a);
        c->r->prod = Lazy::act(c->r->prod, c->a);
        c->r->a = Monoid_A::op(c->r->a, c->a);
        c->r->propagated = 0;
      }
      c->a = Monoid_A::unit();
      c->propagated = 1;
    }
    if (c->rev) {
      swap(c->l, c->r);
      if (c->l) c->l->rev ^= 1;
      if (c->r) c->r->rev ^= 1;
      c->rev = 0;
    }
  }

  void update(Node *c) {
    c->size = 1;
    c->prod = c->x;
    if (c->l) {
      c->size += c->l->size;
      c->prod = Monoid_X::op(c->l->prod, c->prod);
    }
    if (c->r) {
      c->size += c->r->size;
      c->prod = Monoid_X::op(c->prod, c->r->prod);
    }
  }

  Node *merge_rec(Node *l_root, Node *r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    int sl = l_root->size, sr = r_root->size;
    if (xor128() % (sl + sr) < sl) {
      prop(l_root);
      l_root->r = merge_rec(l_root->r, r_root);
      update(l_root);
      return l_root;
    }
    prop(r_root);
    r_root->l = merge_rec(l_root, r_root->l);
    update(r_root);
    return r_root;
  }

  pair<Node *, Node *> split_rec(Node *root, int k) {
    if (!root) return {nullptr, nullptr};
    prop(root);
    int ls = (root->l ? root->l->size : 0);
    if (k <= ls) {
      auto [nl, nr] = split_rec(root->l, k);
      root->l = nr;
      update(root);
      return {nl, root};
    }
    auto [nl, nr] = split_rec(root->r, k - (1 + ls));
    root->r = nl;
    update(root);
    return {root, nr};
  }
};
