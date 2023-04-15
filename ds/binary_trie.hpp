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

  np new_root() { return nullptr; }

  np add(np root, UINT val, T cnt = 1) {
    if (!root) root = new_node(0, 0);
    assert(0 <= val && val < (1LL << LOG));
    return add_rec(root, LOG, val, cnt);
  }

  // f(val, cnt)
  template <typename F>
  void enumerate(np root, F f) {
    auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void {
      if (ht == 0) {
        f(val, root->cnt);
        return;
      }
      np c = root->l;
      if (c) { dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width)); }
      c = root->r;
      if (c) { dfs(dfs, c, val << (c->width) | (c->val), ht - (c->width)); }
    };
    if (root) dfs(dfs, root, 0, LOG);
  }

  // xor_val したあとの値で昇順 k 番目
  UINT kth(np root, T k, UINT xor_val) {
    assert(root && 0 <= k && k < root->cnt);
    return kth_rec(root, 0, k, LOG, xor_val) ^ xor_val;
  }

  // xor_val したあとの値で最小値
  UINT min(np root, UINT xor_val) {
    assert(root && root->cnt);
    return kth(root, 0, xor_val);
  }

  // xor_val したあとの値で最大値
  UINT max(np root, UINT xor_val) {
    assert(root && root->cnt);
    return kth(root, (root->cnt) - 1, xor_val);
  }

  // xor_val したあとの値で [0, upper) 内に入るものの個数
  T prefix_count(np root, UINT upper, UINT xor_val) {
    if (!root) return 0;
    return prefix_count_rec(root, LOG, upper, xor_val, 0);
  }

  // xor_val したあとの値で [lo, hi) 内に入るものの個数
  T count(np root, UINT lo, UINT hi, UINT xor_val) {
    return prefix_count(root, hi, xor_val) - prefix_count(root, lo, xor_val);
  }

private:
  inline UINT mask(int k) { return (UINT(1) << k) - 1; }

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

  T prefix_count_rec(np root, int ht, UINT LIM, UINT xor_val, UINT val) {
    UINT now = (val << ht) ^ (xor_val);
    if ((LIM >> ht) > (now >> ht)) return root->cnt;
    if (ht == 0 || (LIM >> ht) < (now >> ht)) return 0;
    T res = 0;
    FOR(k, 2) {
      np c = (k == 0 ? root->l : root->r);
      if (c) {
        int w = c->width;
        res += prefix_count_rec(c, ht - w, LIM, xor_val, val << w | c->val);
      }
    }
    return res;
  }
};
