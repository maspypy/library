#include "ds/fastset.hpp"

// int 列を扱う. key の重複可.
template <int NODES>
struct Sortable_Array {
  const int N, KEY_MAX;

  struct Node {
    int size;
    Node *l, *r;
  };
  Node* pool;
  int pid;
  using np = Node*;

  FastSet ss;      // 区間の左端全体を表す fastset
  vector<np> root; // 区間の左端に、dynamic segtree の node を乗せる
  vector<bool> rev;

  Sortable_Array(int KEY_MAX, vector<int> key)
      : N(key.size()), KEY_MAX(KEY_MAX), pid(0), ss(key.size()) {
    pool = new Node[NODES];
    init(key);
  }

  void set(int i, int key) {
    assert(0 <= key && key < KEY_MAX);
    split_at(i), split_at(i + 1);
    rev[i] = 0, root[i] = new_node(0);
    set_rec(root[i], 0, KEY_MAX, key);
  }

  void sort_inc(int l, int r) {
    if (l == r) return;
    split_at(l), split_at(r);
    while (1) {
      if (pid > NODES * 0.9) rebuild();
      np c = root[l];
      int i = ss.next(l + 1);
      if (i == r) break;
      root[l] = merge(0, KEY_MAX, c, root[i]);
      ss.erase(i);
    }
    rev[l] = 0;
  };

  void sort_dec(int l, int r) {
    if (l == r) return;
    if (pid > NODES * 0.9) rebuild();
    sort_inc(l, r), rev[l] = 1;
  };

  vc<int> get_all() {
    vector<int> key;
    key.reserve(N);
    auto dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {
      if (!n || !n->size) return;
      if (r == l + 1) {
        FOR(n->size) key.eb(l);
        return;
      }
      int m = (l + r) / 2;
      if (!rev) { dfs(dfs, n->l, l, m, rev), dfs(dfs, n->r, m, r, rev); }
      if (rev) { dfs(dfs, n->r, m, r, rev), dfs(dfs, n->l, l, m, rev); }
    };
    for (int i = 0; i < N; ++i) {
      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);
    }
    return key;
  }

  int get(int idx) {
    auto dfs = [&](auto& dfs, np n, int l, int r, int k) -> int {
      if (r == l + 1) { return l; }
      int m = (l + r) / 2;
      int s = (n->l ? n->l->size : 0);
      if (k < s) return dfs(dfs, n->l, l, m, k);
      return dfs(dfs, n->r, m, r, k - s);
    };
    int i = ss.prev(idx);
    int k = idx - i;
    int s = root[i]->size;
    if (rev[i]) k = s - 1 - k;
    return dfs(dfs, root[i], 0, KEY_MAX, k);
  }

private:
  void init(vector<int>& key) {
    rev.assign(N, 0), root.clear(), root.reserve(N);
    for (int i = 0; i < N; ++i) {
      ss.insert(i);
      root.eb(new_node(0));
      assert(key[i] < KEY_MAX);
      set_rec(root[i], 0, KEY_MAX, key[i]);
    }
  }

  // x が左端になるようにする
  void split_at(int x) {
    if (x == N || ss[x]) return;
    int a = ss.prev(x), b = ss.next(a + 1);
    ss.insert(x);
    if (!rev[a]) {
      auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);
      root[a] = nl, root[x] = nr;
      rev[a] = rev[x] = 0;
    } else {
      auto [nl, nr] = split(root[a], 0, KEY_MAX, b - x);
      root[a] = nr, root[x] = nl;
      rev[a] = rev[x] = 1;
    }
  }

  void rebuild() {
    auto key = get_all();
    pid = 0;
    init(key);
  }

  np new_node(int size) {
    assert(pid < NODES);
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].size = size;
    return &(pool[pid++]);
  }

  pair<np, np> split(np n, int l, int r, int k) {
    if (k == 0) { return {nullptr, n}; }
    if (k == n->size) { return {n, nullptr}; }
    if (r == l + 1) {
      int s = n->size;
      n->size = k;
      Node* b = new_node(s - k);
      return {n, b};
    }
    int s = (n->l ? n->l->size : 0);
    Node* b = new_node(0);
    int m = (l + r) / 2;
    if (k <= s) {
      auto [nl, nr] = split(n->l, l, m, k);
      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;
    }
    if (k > s) {
      auto [nl, nr] = split(n->r, m, r, k - s);
      n->l = n->l, n->r = nl, b->l = nullptr, b->r = nr;
    }
    update(n), update(b);
    return {n, b};
  }

  np merge(int l, int r, np a, np b) {
    if (!a) return b;
    if (!b) return a;
    if (r == l + 1) {
      a->size += b->size;
      return a;
    }
    int m = (l + r) / 2;
    a->l = merge(l, m, a->l, b->l), a->r = merge(m, r, a->r, b->r);
    update(a);
    return a;
  }

  void update(np n) {
    if (!(n->l) && !(n->r)) { return; }
    if (!(n->l)) {
      n->size = n->r->size;
      return;
    }
    if (!(n->r)) {
      n->size = n->l->size;
      return;
    }
    n->size = n->l->size + n->r->size;
  }

  void set_rec(np n, int l, int r, int k) {
    if (r == l + 1) {
      n->size = 1;
      return;
    }
    int m = (l + r) / 2;
    if (k < m) {
      if (!(n->l)) n->l = new_node(0);
      set_rec(n->l, l, m, k);
    }
    if (m <= k) {
      if (!(n->r)) n->r = new_node(0);
      set_rec(n->r, m, r, k);
    }
    update(n);
  }
};
