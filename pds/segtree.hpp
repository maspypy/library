template <typename Monoid, int NODES>
struct Persistent_SegTree {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r;
    X x;
  };

  using np = Node *;

  const int n;
  Node *pool;
  int pid;

  Persistent_SegTree(int n) : n(n), pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X x = Monoid::unit()) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    assert(len(dat) == n);
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      int m = (l + r) / 2;
      Node *l_root = dfs(dfs, l, m);
      Node *r_root = dfs(dfs, m, r);
      X x = Monoid::op(l_root->x, r_root->x);
      Node *root = new_node(x);
      root->l = l_root, root->r = r_root;
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(Node *root, int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    X x = Monoid::unit();
    prod_rec(root, 0, n, l, r, x);
    return x;
  }

  Node *set(Node *root, int i, const X &x) {
    assert(0 <= i && i < n);
    return set_rec(root, 0, n, i, x);
  }

  vc<X> restore(Node *root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, Node *c, int node_l, int node_r) -> void {
      if (node_r - node_l == 1) {
        res.eb(c->x);
        return;
      }
      int node_m = (node_l + node_r) / 2;
      prop(c);
      dfs(dfs, c->l, node_l, node_m);
      dfs(dfs, c->r, node_m, node_r);
    };
    dfs(dfs, root, 0, n);
    return res;
  }

  void reset() { pid = 0; }

private:
  Node *copy_node(Node *n) {
    if (!n) return nullptr;
    pool[pid].l = n->l;
    pool[pid].r = n->r;
    pool[pid].x = n->x;
    return &(pool[pid++]);
  }

  Node *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {
    if (node_r == node_l + 1) { return new_node(x); }
    if(!c) c = new_node();
    int node_m = (node_l + node_r) / 2;
    c = copy_node(c);
    if (i < node_m) {
      c->l = set_rec(c->l, node_l, node_m, i, x);
    } else {
      c->r = set_rec(c->r, node_m, node_r, i, x);
    }
    X xl = (c->l ? c->l->x : Monoid::unit());
    X xr = (c->r ? c->r->x : Monoid::unit());
    c->x = Monoid::op(xl, xr);
    return c;
  }

  void prod_rec(Node *c, int node_l, int node_r, int l, int r, X &x) {
    if(!c) return;
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return;
    if (l == node_l && r == node_r) {
      x = Monoid::op(x, c->x);
      return;
    }
    int node_m = (node_l + node_r) / 2;
    prod_rec(c->l, node_l, node_m, l, r, x);
    prod_rec(c->r, node_m, node_r, l, r, x);
  }
};