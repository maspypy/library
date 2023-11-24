
template <typename VAL, bool PERSISTENT, int NODES, bool TOP_IS_MIN>
struct Meldable_Heap {
  struct Node {
    Node *l, *r;
    VAL x;
    int size;
  };
  Node *pool;
  int pid;
  using np = Node *;

  Meldable_Heap() : pid(0) { pool = new Node[NODES]; }

  np new_root() { return nullptr; }
  np new_node(const VAL &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].size = 1;
    return &(pool[pid++]);
  }
  np copy_node(np a) {
    if (!a || !PERSISTENT) return a;
    np b = new_node(a->x);
    b->size = a->size;
    b->l = a->l;
    b->r = a->r;
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
    swap(a->l, a->r);
    (a->size) = 1;
    if (a->l) a->size += a->l->size;
    if (a->r) a->size += a->r->size;
    return a;
  }
  np push(np a, VAL x) { return meld(a, new_node(x)); }
  np pop(np a) { return meld(a->l, a->r); }
  VAL top(np a) { return a->x; }

  // ソートとかはされない
  vc<VAL> get_all(np a) {
    vc<VAL> A;
    auto dfs = [&](auto &dfs, np a) -> void {
      if (!a) return;
      A.eb(a->x);
      dfs(dfs, a->l);
      dfs(dfs, a->r);
    };
    dfs(dfs, a);
    return A;
  }
};
