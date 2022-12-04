template <typename Lazy>
struct Connected_Component_Query {
  using Monoid_X = typename Lazy::X_structure;
  using Monoid_A = typename Lazy::A_structure;
  using X = typename Monoid_X::value_type;
  using A = typename Monoid_A::value_type;

  struct Node {
    int l, r;
    X prod;
    A lazy; // その頂点における prod は lazy を反映済
  };

  const int N;
  vc<int> not_used;
  vc<Node> nodes;
  vc<int> history;
  FastSet roots;

  Connected_Component_Query(vc<X> dat)
      : N(len(dat)), nodes(N + N), roots(N + N) {
    FOR(i, N, N + N) not_used.eb(i);
    FOR(i, N) roots.insert(i);
    FOR(v, N) { nodes[v] = Node{-1, -1, dat[v], Monoid_A::unit()}; }
  }

  int merge(int u, int v) {
    int w = pick(not_used);
    roots.erase(u);
    roots.erase(v);
    roots.insert(w);
    nodes[w].l = u;
    nodes[w].r = v;
    nodes[w].prod = Monoid_X::op(nodes[u].prod, nodes[v].prod);
    nodes[w].lazy = Monoid_A::unit();
    history.eb(w);
    return w;
  }

  void apply(int u, A a) {
    // print("merge", u, ",", a);
    assert(roots[u]);
    nodes[u].lazy = Monoid_A::op(nodes[u].lazy, a);
    nodes[u].prod = Lazy::act(nodes[u].prod, a);
  }

  X prod(int u) {
    assert(roots[u]);
    return nodes[u].prod;
  }

  int time() { return len(history); }

  // merge を解除。lazy は残り続けることに注意する。
  void rollback(int t) {
    assert(len(history) >= t);
    while (len(history) > t) {
      int w = pick(history);
      int u = nodes[w].l;
      int v = nodes[w].r;
      roots.erase(w);
      roots.insert(u);
      roots.insert(v);
      apply(u, nodes[w].lazy);
      apply(v, nodes[w].lazy);
      not_used.eb(w);
      // print("undo_merge", u, v, w);
    }
  }
};