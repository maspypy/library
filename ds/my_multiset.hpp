// 動的セグメント木として作っておく
template <typename T, typename CNT, typename SM, bool PERSISTENT, int NODES>
struct My_Multiset {
  struct Node {
    T idx;
    Node *l, *r;
    CNT cnt, sub_cnt;
    SM sub_sm;
    SM node_sum() { return SM(idx) * SM(cnt); }
  };

  const T L0, R0;
  Node *pool;
  int pid;
  using np = Node *;

  My_Multiset(T L0 = -2 * infty<T>, T R0 = 2 * infty<T>)
      : L0(L0), R0(R0), pid(0) {
    pool = new Node[NODES];
  }

  np new_root() { return nullptr; }

  np new_node(T idx, const CNT cnt) {
    pool[pid].idx = idx;
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].cnt = cnt, pool[pid].sub_cnt = cnt;
    pool[pid].sub_sm = pool[pid].node_sum();
    return &(pool[pid++]);
  }

  // (cnt, sm)
  pair<CNT, SM> get_range(np root, T l, T r) {
    assert(L0 <= l && l <= r && r <= R0);
    if (l == r) return {CNT(0), SM(0)};
    CNT cnt = 0;
    SM sm = 0;
    get_range_rec(root, L0, R0, l, r, cnt, sm);
    return {cnt, sm};
  }

  // (cnt, sm)
  pair<CNT, SM> get_all_range(np root) {
    if (!root) return {CNT(0), SM(0)};
    return {root->sub_cnt, root->sub_sm};
  }

  np add(np root, T x, CNT cnt) {
    assert(L0 <= x && x < R0);
    return add_rec(root, L0, R0, x, cnt);
  }

  // k>=0 番目と、そこまでの prefix sum
  pair<T, SM> prefix_kth(np root, CNT k) {
    auto [cnt, sm] = get_all_range(root);
    assert(k <= cnt);
    return prefix_kth_rec(root, L0, R0, k);
  }

  // 大きい方から k>=0 番目と、そこまでの suffix sum
  pair<T, SM> suffix_kth(np root, CNT k) {
    auto [cnt, sm] = get_all_range(root);
    assert(k <= cnt);
    return suffix_kth_rec(root, L0, R0, k);
  }

  void reset() { pid = 0; }

  // f(idx, cnt)
  template <typename F>
  void enumerate(np root, F f, T l, T r) {
    auto dfs = [&](auto &dfs, np c) -> void {
      if (!c) return;
      dfs(dfs, c->l);
      f(c->idx, c->cnt);
      dfs(dfs, c->r);
    };
    dfs(dfs, root);
  }

private:
  void update(np c) {
    c->sub_cnt = c->cnt, c->sub_sm = c->node_sum();
    if (c->l) c->sub_cnt += c->l->sub_cnt, c->sub_sm += c->l->sub_sm;
    if (c->r) c->sub_cnt += c->r->sub_cnt, c->sub_sm += c->r->sub_sm;
  }

  np copy_node(np c) {
    if (!c || !PERSISTENT) return c;
    pool[pid].idx = c->idx;
    pool[pid].l = c->l, pool[pid].r = c->r;
    pool[pid].cnt = c->cnt, pool[pid].sub_cnt = c->sub_cnt;
    pool[pid].sub_sm = c->sub_sm;
    return &(pool[pid++]);
  }

  np add_rec(np c, T l, T r, T i, CNT cnt) {
    if (!c) {
      c = new_node(i, cnt);
      return c;
    }
    c = copy_node(c);
    if (c->idx == i) {
      c->cnt += cnt;
      update(c);
      return (c->sub_cnt == 0 ? nullptr : c);
    }
    T m = (l + r) / 2;
    if (i < m) {
      if (c->idx < i) swap(c->idx, i), swap(c->cnt, cnt);
      c->l = add_rec(c->l, l, m, i, cnt);
    }
    if (m <= i) {
      if (i < c->idx) swap(c->idx, i), swap(c->cnt, cnt);
      c->r = add_rec(c->r, m, r, i, cnt);
    }
    update(c);
    return c;
  }

  void get_range_rec(np c, T l, T r, T ql, T qr, CNT &cnt, SM &sm) {
    chmax(ql, l), chmin(qr, r);
    if (ql >= qr || !c) return;
    if (l == ql && r == qr) {
      cnt += c->sub_cnt, sm += c->sub_sm;
      return;
    }
    T m = (l + r) / 2;
    get_range_rec(c->l, l, m, ql, qr, cnt, sm);
    if (ql <= (c->idx) && (c->idx) < qr) cnt += c->cnt, sm += c->node_sum();
    get_range_rec(c->r, m, r, ql, qr, cnt, sm);
  }

  pair<T, SM> prefix_kth_rec(np c, T l, T r, CNT k) {
    if (!c) { return {R0, 0}; }
    T m = (l + r) / 2;
    CNT l_cnt = (c->l ? c->l->sub_cnt : 0);
    SM l_sm = (c->l ? c->l->sub_sm : 0);
    if (k < l_cnt) { return prefix_kth_rec(c->l, l, m, k); }
    if (k < l_cnt + c->cnt) {
      return {c->idx, l_sm + SM(c->idx) * SM(k - l_cnt)};
    }
    pair<T, SM> p = prefix_kth_rec(c->r, m, r, k - l_cnt - c->cnt);
    return {p.fi, l_sm + p.se};
  }

  pair<T, SM> suffix_kth_rec(np c, T l, T r, CNT k) {
    if (!c) { return {L0, 0}; }
    T m = (l + r) / 2;
    CNT r_cnt = (c->r ? c->r->sub_cnt : 0);
    SM r_sm = (c->r ? c->r->sub_sm : 0);
    if (k < r_cnt) { return suffix_kth_rec(c->r, m, r, k); }
    if (k < r_cnt + c->cnt) {
      return {c->idx, r_sm + SM(c->idx) * SM(k - r_cnt)};
    }
    pair<T, SM> p = suffix_kth_rec(c->l, l, m, k - r_cnt - c->cnt);
    return {p.fi, r_sm + p.se};
  }
};
