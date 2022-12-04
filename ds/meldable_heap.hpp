
template <typename VAL, bool PERSISTENT, int NODES>
struct Meldable_Heap {
  struct Node {
    Node *l, *r;
    VAL x;
    int s;
  };
  Node *pool;
  int pid;
  using np = Node *;

  Meldable_Heap() : pid(0) { pool = new Node[NODES]; }

  np new_node(const VAL &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].s = 1;
    return &(pool[pid++]);
  }
  np copy_node(np a) {
    if (!a || !PERSISTENT) return a;
    np b = new_node(a->x);
    b->s = a->s;
    b->l = a->l;
    b->r = a->r;
    return b;
  }
  np meld(np a, np b) {
    if (!a) return b;
    if (!b) return a;
    a = copy_node(a);
    b = copy_node(b);
    if ((a->x) > (b->x)) swap(a, b);
    a->r = (a->r ? meld(a->r, b) : b);
    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l, a->r);
    a->s = (a->r ? a->r->s : 0) + 1;
    return a;
  }
  np push(np a, VAL x) { return meld(a, new_node(x)); }
  np pop(np a) { return meld(a->l, a->r); }
  VAL top(np a) { return a->x; }
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
