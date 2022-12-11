// 非永続ならば、2 * 要素数 のノード数
template <int LOG, bool PERSISTENT, int NODES, typename UINT = u64,
          typename SIZE_TYPE = int>
struct Binary_Trie {
  using T = SIZE_TYPE;
  struct Node {
    int width;
    UINT val;
    T cnt;
    Node *l, *r;
  };

  Node *pool;
  int pid;
  using np = Node *;

  Binary_Trie() : pid(0) { pool = new Node[NODES]; }

  void reset() { pid = 0; }

  np new_node(int width, UINT val) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].width = width;
    pool[pid].val = val;
    pool[pid].cnt = 0;
    return &(pool[pid++]);
  }

  np copy_node(np c) {
    if (!c || !PERSISTENT) return c;
    np res = &(pool[pid++]);
    res->width = c->width, res->val = c->val;
    res->cnt = c->cnt, res->l = c->l, res->r = c->r;
    return res;
  }

  np add(np root, UINT val, T cnt = 1) {
    if (!root) root = new_node(0, 0);
    assert(0 <= val && val < (1LL << LOG));
    return add_rec(root, LOG, val, cnt);
  }

  vc<pair<UINT, T>> get_all(np root) {
    vc<pair<UINT, T>> res;
    auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void {
      if (ht == 0) {
        res.eb(val, root->cnt);
        return;
      }
      np c = root->l;
      if (c) { dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width)); }
      c = root->r;
      if (c) { dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width)); }
    };
    if (root) dfs(dfs, root, 0, LOG);
    return res;
  }

  UINT kth(np root, T k, UINT xor_val) {
    assert(root && 0 <= k && k < root->cnt);
    return kth_rec(root, 0, k, LOG, xor_val) ^ xor_val;
  }

  UINT min(np root, UINT xor_val) {
    assert(root && root->cnt);
    return kth(root, 0, xor_val);
  }

  UINT max(np root, UINT xor_val) {
    assert(root && root->cnt);
    return kth(root, (root->cnt) - 1, xor_val);
  }

private:
  inline UINT mask(int k) { return (UINT(1) << k) - 1; }

  np add_rec(np root, int ht, UINT val, T cnt) {
    root = copy_node(root);
    root->cnt += cnt;
    if (ht == 0) return root;

    bool go_r = (val >> (ht - 1)) & 1;
    np c = (go_r ? root->r : root->l);
    if (!c) {
      c = new_node(ht, val);
      c->cnt = cnt;
      if (!go_r) root->l = c;
      if (go_r) root->r = c;
      return root;
    }
    int w = c->width;
    if ((val >> (ht - w)) == c->val) {
      c = add_rec(c, ht - w, val & mask(ht - w), cnt);
      if (!go_r) root->l = c;
      if (go_r) root->r = c;
      return root;
    }
    int same = w - 1 - topbit((val >> (ht - w)) ^ (c->val));
    np n = new_node(same, (c->val) >> (w - same));
    n->cnt = c->cnt + cnt;
    c = copy_node(c);
    c->width = w - same;
    c->val = c->val & mask(w - same);
    if ((val >> (ht - same - 1)) & 1) {
      n->l = c;
      n->r = new_node(ht - same, val & mask(ht - same));
      n->r->cnt = cnt;
    } else {
      n->r = c;
      n->l = new_node(ht - same, val & mask(ht - same));
      n->l->cnt = cnt;
    }
    if (!go_r) root->l = n;
    if (go_r) root->r = n;
    return root;
  }

  UINT kth_rec(np root, UINT val, T k, int ht, UINT xor_val) {
    if (ht == 0) return val;
    np left = root->l, right = root->r;
    if ((xor_val >> (ht - 1)) & 1) swap(left, right);
    T sl = (left ? left->cnt : 0);
    np c;
    if (k < sl) { c = left; }
    if (k >= sl) { c = right, k -= sl; }
    int w = c->width;
    return kth_rec(c, val << w | (c->val), k, ht - w, xor_val);
  }
};
