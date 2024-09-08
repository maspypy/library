
template <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>
struct Meldable_Heap {
  struct Node {
    Node *l, *r;
    VAL x;
    u32 size, dist; // dist: leaf までの距離
  };
  Node *pool;
  const int NODES;
  int pid;
  using np = Node *;

  Meldable_Heap(int NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }
  ~Meldable_Heap() { delete[] pool; }
  np new_root() { return nullptr; }
  np new_node(const VAL &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x, pool[pid].size = 1, pool[pid].dist = 1;
    return &(pool[pid++]);
  }
  np copy_node(np a) {
    if (!a || !PERSISTENT) return a;
    np b = new_node(a->x);
    b->l = a->l, b->r = a->r;
    b->size = a->size, b->dist = a->dist;
    return b;
  }
  np meld(np a, np b) {
    if (!a) return b;
    if (!b) return a;
    a = copy_node(a);
    b = copy_node(b);
    if constexpr (TOP_IS_MIN) {
      if ((a->x) > (b->x)) swap(a, b);
    } else {
      if ((a->x) < (b->x)) swap(a, b);
    }
    a->r = meld(a->r, b);
    if (!(a->l) || (a->l->dist < a->r->dist)) swap(a->l, a->r);
    a->dist = (a->r ? a->r->dist : 0) + 1;
    a->size = 1;
    if (a->l) a->size += a->l->size;
    if (a->r) a->size += a->r->size;
    return a;
  }
  np push(np a, VAL x) { return meld(a, new_node(x)); }
  np pop(np a) { return meld(a->l, a->r); }
  VAL top(np a) { return a->x; }
  vc<VAL> get_all(np a) {
    vc<VAL> A;
    auto dfs = [&](auto &dfs, np a) -> void {
      if (!a) return;
      A.eb(a->x), dfs(dfs, a->l), dfs(dfs, a->r);
    };
    dfs(dfs, a);
    sort(all(A));
    if (!TOP_IS_MIN) reverse(all(A));
    return A;
  }
};
