#pragma once

// new_node(x) ： 1要素だけからなる木
// new_node(A) ： 列を木にする、先頭を根とする。
template <typename Monoid, int NODES = 5'000'000>
struct SplayTree_Monoid {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r, *p;
    X x;
    X prod;
    int size;
    Node()
        : l(nullptr),
          r(nullptr),
          p(nullptr),
          x(Monoid::unit()),
          prod(Monoid::unit()),
          size(1) {}
  };

  Node *pool;
  int pid;

  SplayTree_Monoid() : pid(0) { pool = new Node[NODES]; }

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

  X prod_all(Node *root) {
    if (!root) return Monoid::unit();
    return root->prod;
  }

  Node *new_node(const X &x) {
    pool[pid].l = pool[pid].r = pool[pid].p = nullptr;
    pool[pid].x = x;
    pool[pid].prod = x;
    pool[pid].size = 1;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    Node *root = nullptr;
    FOR_R(i, len(dat)) { insert(root, 0, new_node(dat[i])); }
    return root;
  }

  // k 番目が根に来るように splay する
  void get_kth(Node *&root, int k) {
    assert(0 <= k && k < (root->size));
    while (1) {
      int lsize = (root->l ? root->l->size : 0);
      if (k < lsize) root = root->l;
      if (k == lsize) {
        splay(root);
        break;
      }
      if (k > lsize) {
        k -= lsize + 1;
        root = root->r;
      }
    }
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
    update(root);
    merge(l_root, r_root);
    swap(root, l_root);
    return l_root;
  }

  void set(Node *&root, int k, const X &x) {
    get_kth(root, k);
    root->x = x;
    update(root);
  }

  void debug(Node *root) {
    print("splay tree");
    if (!root) { return print("nullptr"); }
    print("root_val", root->x);
    vc<X> dat;
    auto dfs = [&](auto &dfs, Node *n) -> void {
      if (n->l) dfs(dfs, n->l);
      dat.eb(n->x);
      if (n->r) dfs(dfs, n->r);
    };
    dfs(dfs, root);
    print("all", dat);
  }

private:
  void update(Node *n) {
    // n の情報を再計算
    n->size = 1;
    n->prod = n->x;
    if (n->l) n->size += n->l->size, n->prod = Monoid::op(n->l->prod, n->prod);
    if (n->r) n->size += n->r->size, n->prod = Monoid::op(n->prod, n->r->prod);
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

    update(p);
    update(n);
  }

  inline int state(Node *n) {
    if (!n->p) return 0;
    if (n->p->l == n) return 1;
    if (n->p->r == n) return -1;
    return 0;
  }

  void splay(Node *n) {
    while (n->p) {
      if (state(n->p) == 0) { rotate(n); }
      elif (state(n) == state(n->p)) {
        rotate(n->p);
        rotate(n);
      }
      else {
        rotate(n);
        rotate(n);
      }
    }
  }
};
