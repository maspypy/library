// Monoid_X の可換性を仮定している
template <typename Lazy, int NODES = 1'000'000>
struct SplayTree_Lazy {
  using Monoid_X = typename Lazy::Monoid_X;
  using Monoid_A = typename Lazy::Monoid_A;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;

  struct Node {
    Node *l, *r, *p;
    X x, prod;
    A a;
    int size;
    bool rev;
  };

  Node *pool;
  int pid;

  SplayTree_Lazy() : pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = pool[pid].p = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
    pool[pid].a = Monoid_A::unit();
    pool[pid].size = 1;
    pool[pid].rev = 0;
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
      if (l_root) l_root->p = root;
      if (r_root) r_root->p = root;
      update(root);
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  // k 番目が根に来るように splay する
  void get_kth(Node *&root, int k) {
    assert(root && 0 <= k && k < (root->size));
    while (1) {
      prop(root);
      int lsize = (root->l ? root->l->size : 0);
      if (k < lsize) root = root->l;
      if (k == lsize) { break; }
      if (k > lsize) {
        k -= lsize + 1;
        root = root->r;
      }
    }
    splay(root);
  }

  // 左に右をマージ
  void merge(Node *&root, Node *r_root) {
    if (!root) {
      root = r_root;
      return;
    }
    if (!r_root) return;
    get_kth(root, root->size - 1);
    root->r = r_root;
    r_root->p = root;
    update(root);
  }

  // 左右に分けて、root を左側に変更。右側を return する。
  Node *split(Node *&root, int l_size) {
    if (!root) { return nullptr; }
    assert(0 <= l_size && l_size <= root->size);
    if (l_size == 0) {
      Node *res = root;
      root = nullptr;
      return res;
    }
    if (l_size == root->size) return nullptr;
    get_kth(root, l_size - 1);
    Node *res = root->r;
    root->r = nullptr;
    res->p = nullptr;
    update(root);
    return res;
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
    swap(m_root->l, m_root->r);
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
    get_kth(root, k);
    Node *l_root = root->l;
    Node *r_root = root->r;
    if (l_root) l_root->p = nullptr;
    if (r_root) r_root->p = nullptr;
    root->l = nullptr;
    root->r = nullptr;
    root->prod = root->x;
    root->size = 1;
    merge(l_root, r_root);
    swap(root, l_root);
    return l_root;
  }

  void debug(Node *root) {
    print("splay tree");
    string s;
    auto dfs = [&](auto &dfs, Node *n) -> void {
      if (!n) return;
      if (n->l) assert(n->l->p == n);
      if (n->r) assert(n->r->p == n);
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
  void prop(Node *c) {
    A &a = c->a;
    if (a != Monoid_A::unit()) {
      if (c->l) {
        c->l->x = Lazy::act(c->l->x, a);
        c->l->prod = Lazy::act(c->l->prod, a);
        c->l->a = Monoid_A::op(c->l->a, a);
      }
      if (c->r) {
        c->r->x = Lazy::act(c->r->x, a);
        c->r->prod = Lazy::act(c->r->prod, a);
        c->r->a = Monoid_A::op(c->r->a, a);
      }
    }
    a = Monoid_A::unit();
    if (c->rev) {
      if (c->l) {
        c->l->rev ^= 1;
        swap(c->l->l, c->l->r);
      }
      if (c->r) {
        c->r->rev ^= 1;
        swap(c->r->l, c->r->r);
      }
    }
    c->rev = 0;
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

  void rotate(Node *n) {
    // n を根に近づける
    Node *pp, *p, *c;
    p = n->p;
    pp = p->p;

    if (p->l == n) {
      c = n->r;
      n->r = p;
      p->l = c;
    } else {
      c = n->l;
      n->l = p;
      p->r = c;
    }

    if (pp && pp->l == p) pp->l = n;
    if (pp && pp->r == p) pp->r = n;
    n->p = pp;
    p->p = n;
    if (c) c->p = p;
  }

  inline int state(Node *n) {
    if (!n->p) return 0;
    if (n->p->l == n) return 1;
    if (n->p->r == n) return -1;
    return 0;
  }

  void splay(Node *c) {
    while (c->p) {
      Node *p = c->p;
      Node *pp = (p ? p->p : nullptr);
      if (state(p) == 0) { rotate(c); }
      elif (state(c) == state(p)) {
        rotate(p);
        rotate(c);
      }
      else {
        rotate(c);
        rotate(c);
      }
      if (pp) update(pp);
      if (p) update(p);
    }
    update(c);
  }
};