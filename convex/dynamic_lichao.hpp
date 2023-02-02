// 直線追加かつ非永続なら空間 Q でよい。
// 関数は ll -> T。[L, R) 上 f が overflow しないように注意。
// evaluate を書き変えると、totally monotone な関数群にも使える
template <typename T, bool PERSISTENT, int NODES, bool MINIMIZE>
struct Dynamic_LiChao_Tree {
  using FUNC = pair<T, T>;
  vc<FUNC> funcs;

  static inline T evaluate(FUNC &f, ll x) { return f.fi * x + f.se; }

  struct Node {
    int fid;
    Node *l, *r;
  };

  Node *pool;
  int pid;
  ll L, R;

  using np = Node *;

  Dynamic_LiChao_Tree(ll L, ll R) : pid(0), L(L), R(R) {
    pool = new Node[NODES];
  }

  void reset() {
    funcs.clear();
    pid = 0;
  }

  np new_root() { return nullptr; }

  np new_node() {
    pool[pid].fid = -1;
    pool[pid].l = nullptr, pool[pid].r = nullptr;
    return &(pool[pid++]);
  }

  np add_line(np root, FUNC f) {
    int fid = len(funcs);
    funcs.eb(f);
    if (!root) root = new_node();
    return add_line_rec(root, fid, L, R);
  }

  // [xl, xr)
  np add_segment(np root, ll xl, ll xr, FUNC f) {
    int fid = len(funcs);
    funcs.eb(f);
    if (!root) root = new_node();
    return add_segment_rec(root, xl, xr, fid, L, R);
  }

  // (値・関数番号)
  pair<T, int> query(np root, ll x) {
    assert(L <= x && x < R);
    if (!root) {
      if (MINIMIZE) return {infty<T>, -1};
      if (!MINIMIZE) return {-infty<T>, -1};
    }
    return query_rec(root, x, L, R);
  }

private:
  np copy_node(Node *c) {
    if (!c || !PERSISTENT) return c;
    pool[pid].fid = c->fid;
    pool[pid].l = c->l, pool[pid].r = c->r;
    return &(pool[pid++]);
  }

  inline T evaluate_inner(int fid, ll x) {
    if (fid == -1) { return (MINIMIZE ? infty<T> : -infty<T>); };
    return evaluate(funcs[fid], x);
  }

  np add_segment_rec(np c, ll xl, ll xr, int fid, ll node_l, ll node_r) {
    chmax(xl, node_l), chmin(xr, node_r);
    if (xl >= xr) return c;
    if (node_l < xl || xr < node_r) {
      c = copy_node(c);
      ll node_m = (node_l + node_r) / 2;
      if (!c->l) c->l = new_node();
      if (!c->r) c->r = new_node();
      c->l = add_segment_rec(c->l, xl, xr, fid, node_l, node_m);
      c->r = add_segment_rec(c->r, xl, xr, fid, node_m, node_r);
      return c;
    }
    return add_line_rec(c, fid, node_l, node_r);
  }

  np add_line_rec(np c, int fid, ll node_l, ll node_r) {
    int gid = c->fid;
    T fl = evaluate_inner(fid, node_l), fr = evaluate_inner(fid, node_r - 1);
    T gl = evaluate_inner(gid, node_l), gr = evaluate_inner(gid, node_r - 1);
    bool bl = (MINIMIZE ? fl < gl : fl > gl);
    bool br = (MINIMIZE ? fr < gr : fr > gr);
    if (bl && br) {
      c = copy_node(c);
      c->fid = fid;
      return c;
    }
    if (!bl && !br) { return c; }

    c = copy_node(c);
    ll node_m = (node_l + node_r) / 2;
    auto fm = evaluate_inner(fid, node_m), gm = evaluate_inner(gid, node_m);
    bool bm = (MINIMIZE ? fm < gm : fm > gm);
    if (bm) {
      c->fid = fid;
      if (bl) {
        if (!c->r) c->r = new_node();
        c->r = add_line_rec(c->r, gid, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        c->l = add_line_rec(c->l, gid, node_l, node_m);
      }
    }
    if (!bm) {
      if (!bl) {
        if (!c->r) c->r = new_node();
        c->r = add_line_rec(c->r, fid, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        c->l = add_line_rec(c->l, fid, node_l, node_m);
      }
    }
    return c;
  }

  pair<T, int> query_rec(np c, ll x, ll node_l, ll node_r) {
    int fid = c->fid;
    pair<T, int> res = {evaluate_inner(fid, x), fid};
    ll node_m = (node_l + node_r) / 2;
    if (x < node_m && c->l) {
      pair<T, int> res1 = query_rec(c->l, x, node_l, node_m);
      res = (MINIMIZE ? min(res, res1) : max(res, res1));
    }
    if (x >= node_m && c->r) {
      pair<T, int> res1 = query_rec(c->r, x, node_m, node_r);
      res = (MINIMIZE ? min(res, res1) : max(res, res1));
    }
    return res;
  }
};
