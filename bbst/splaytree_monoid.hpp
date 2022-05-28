// reverse はとりあえず、Monoid の可換性を仮定している！
template <typename Monoid, int NODES = 1'000'000>
struct SplayTree_Monoid {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r, *p;
    X x, prod;
    int size;
    bool rev;
  };

  Node *pool;
  int pid;

  SplayTree_Monoid() : pid(0) { pool = new Node[NODES]; }

  void reset() { pid = 0; }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = pool[pid].p = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
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
    prop(root);
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
    prop(root);
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
    if (l == r) return Monoid::unit();
    Node *r_root = split(root, r);
    Node *m_root = split(root, l);
    X res = m_root->prod;
    merge(root, m_root);
    merge(root, r_root);
    return res;
  }

  void reverse(Node *&root, int l, int r) {
    assert(Monoid::commute);
    assert(0 <= l && l <= r && r <= root->size);
    if (r - l <= 1) return;
    Node *r_root = split(root, r);
    Node *m_root = split(root, l);
    m_root->rev ^= 1;
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

  void insert(Node *&root, int k, const X& x) {
    insert(root, k, new_node(x));
  }

  void set(Node *&root, int k, const X &x) {
    get_kth(root, k);
    root->x = x;
    update(root);
  }

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

  vc<X> get_all(Node *root){
    vc<X> res;
    auto dfs = [&](auto &dfs, Node *n) -> void {
      if (!n) return;
      dfs(dfs, n->l);
      res.eb(n->x);
      dfs(dfs, n->r);
    };
    dfs(dfs, root);
    return res;
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
      print(s, "size", n->size, "x", n->x, "prod", n->prod);
      s += "r";
      dfs(dfs, n->r);
      s.pop_back();
    };
    dfs(dfs, root);
  }

private:
  void prop(Node *c) {
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
      c->prod = Monoid::op(c->l->prod, c->prod);
    }
    if (c->r) {
      c->size += c->r->size;
      c->prod = Monoid::op(c->prod, c->r->prod);
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
    return -1;
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