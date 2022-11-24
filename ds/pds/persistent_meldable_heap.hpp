
template <typename VAL, int NODES = 5'000'000>
struct Persistent_Meldable_Heap {
  struct Node {
    Node *l, *r;
    VAL x;
    int s;
  };

  Node *pool;
  int pid;

  Persistent_Meldable_Heap() : pid(0) { pool = new Node[NODES]; }

  Node *new_node(const VAL &x) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    pool[pid].s = 1;
    return &(pool[pid++]);
  }

  Node *copy_node(Node *a) {
    if (!a) return a;
    Node *b = new_node(a->x);
    b->s = a->s;
    b->l = a->l;
    b->r = a->r;
    return b;
  }

  Node *meld(Node *a, Node *b) {
    a = copy_node(a);
    b = copy_node(b);
    if (!a) return b;
    if (!b) return a;
    if ((a->x) > (b->x)) swap(a, b);
    a->r = (a->r ? meld(a->r, b) : b);
    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l, a->r);
    a->s = (a->r ? a->r->s : 0) + 1;
    return a;
  }

  Node *push(Node *a, VAL x) { return meld(a, new_node(x)); }
  Node *pop(Node *a) { return meld(a->l, a->r); }
  VAL top(Node *a) { return a->x; }

  vc<VAL> collect(Node *a) {
    vc<VAL> A;
    auto dfs = [&](auto &dfs, Node *a) -> void {
      if (!a) return;
      A.eb(a->x);
      dfs(dfs, a->l);
      dfs(dfs, a->r);
    };
    dfs(dfs, a);
    return A;
  }
};
