#include "ds/fastset.hpp"
#include "ds/segtree/segtree.hpp"

template <typename Monoid, int NODES>
struct Sortable_SegTree {
  using MX = Monoid;
  using X = typename MX::value_type;
  const int N, KEY_MAX;

  struct Node {
    X x, rev_x;
    int size;
    Node *l, *r;
  };
  Node* pool;
  int pid;
  using np = Node*;

  FastSet ss;      // 区間の左端全体を表す fastset
  SegTree<MX> seg; // 区間を集約した値を区間の左端にのせた segtree
  vector<np> root; // 区間の左端に、dynamic segtree の node を乗せる
  vector<bool> rev;

  Sortable_SegTree(int KEY_MAX, vector<int> key, vector<X> dat)
      : N(key.size()), KEY_MAX(KEY_MAX), pid(0), ss(key.size()), seg(dat) {
    pool = new Node[NODES];
    init(key, dat);
  }

  void set(int i, int key, const X& x) {
    assert(key < KEY_MAX);
    split_at(i), split_at(i + 1);
    rev[i] = 0, root[i] = new_node();
    set_rec(root[i], 0, KEY_MAX, key, x);
    seg.set(i, x);
  }

  X prod_all() { return seg.prod_all(); }

  X prod(int l, int r) {
    if (pid > NODES * 0.9) rebuild();
    split_at(l), split_at(r);
    return seg.prod(l, r);
  }

  void sort_inc(int l, int r) {
    split_at(l), split_at(r);
    while (1) {
      if (pid > NODES * 0.9) rebuild();
      np c = root[l];
      int i = ss.next(l + 1);
      if (i == r) break;
      root[l] = merge(c, root[i]);
      ss.erase(i), seg.set(i, MX::unit());
    }
    rev[l] = 0, seg.set(l, root[l]->x);
  };

  void sort_dec(int l, int r) {
    if (pid > NODES * 0.9) rebuild();
    sort_inc(l, r), rev[l] = 1;
    seg.set(l, root[l]->rev_x);
  };

private:
  void init(vector<int>& key, vector<X>& dat) {
    rev.assign(N, 0), root.clear(), root.reserve(N);
    seg.build(N, [&](int i) -> X { return dat[i]; });
    for (int i = 0; i < N; ++i) {
      ss.insert(i);
      root.eb(new_node(MX::unit()));
      assert(key[i] < KEY_MAX);
      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);
    }
  }

  // x が左端になるようにする
  void split_at(int x) {
    if (x == N || ss[x]) return;
    int a = ss.prev(x), b = ss.next(a + 1);
    ss.insert(x);
    if (!rev[a]) {
      auto [nl, nr] = split(root[a], x - a);
      root[a] = nl, root[x] = nr;
      rev[a] = rev[x] = 0;
      seg.set(a, root[a]->x), seg.set(x, root[x]->x);
    } else {
      auto [nl, nr] = split(root[a], b - x);
      root[a] = nr, root[x] = nl;
      rev[a] = rev[x] = 1;
      seg.set(a, root[a]->rev_x), seg.set(x, root[x]->rev_x);
    }
  }

  void rebuild() {
    vector<int> key;
    vector<X> dat;
    key.reserve(N);
    dat.reserve(N);
    auto dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {
      if (!n) return;
      if (r == l + 1) {
        key.eb(l), dat.eb(n->x);
        return;
      }
      int m = (l + r) / 2;
      if (!rev) { dfs(dfs, n->l, l, m, rev), dfs(dfs, n->r, m, r, rev); }
      if (rev) { dfs(dfs, n->r, m, r, rev), dfs(dfs, n->l, l, m, rev); }
    };
    for (int i = 0; i < N; ++i) {
      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);
    }
    assert(int(key.size()) == N);
    pid = 0;
    init(key, dat);
  }

  np new_node(X x = MX::unit()) {
    assert(pid < NODES);
    pool[pid].x = pool[pid].rev_x = x;
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].size = 1;
    return &(pool[pid++]);
  }

  pair<np, np> split(np n, int k) {
    if (k == 0) { return {nullptr, n}; }
    if (k == n->size) { return {n, nullptr}; }
    int s = (n->l ? n->l->size : 0);
    Node* b = new_node();
    if (k <= s) {
      auto [nl, nr] = split(n->l, k);
      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;
    }
    if (k > s) {
      auto [nl, nr] = split(n->r, k - s);
      n->l = n->l, n->r = nl, b->l = nullptr, b->r = nr;
    }
    update(n), update(b);
    return {n, b};
  }

  np merge(np a, np b) {
    if (!a) return b;
    if (!b) return a;
    a->l = merge(a->l, b->l), a->r = merge(a->r, b->r);
    update(a);
    return a;
  }

  void update(np n) {
    if (!(n->l) && !(n->r)) { return; }
    if (!(n->l)) {
      n->x = n->r->x, n->rev_x = n->r->rev_x, n->size = n->r->size;
      return;
    }
    if (!(n->r)) {
      n->x = n->l->x, n->rev_x = n->l->rev_x, n->size = n->l->size;
      return;
    }
    n->x = MX::op(n->l->x, n->r->x);
    n->rev_x = MX::op(n->r->rev_x, n->l->rev_x);
    n->size = n->l->size + n->r->size;
  }

  void set_rec(np n, int l, int r, int k, const X& x) {
    if (r == l + 1) {
      n->x = n->rev_x = x;
      return;
    }
    int m = (l + r) / 2;
    if (k < m) {
      if (!(n->l)) n->l = new_node();
      set_rec(n->l, l, m, k, x);
    }
    if (m <= k) {
      if (!(n->r)) n->r = new_node();
      set_rec(n->r, m, r, k, x);
    }
    update(n);
  }
};