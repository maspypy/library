/*
各 heavy path を head が左, tail が右となるように splay tree で持つ.
ユーザーが直接呼ぶ可能性があるものだけ int でも実装.
LCT 外で探索するときなど，push を忘れないように注意.
*/

template <typename Node>
struct Link_Cut_Tree {
  using np = Node *;
  int n;
  vc<Node> nodes;

  Link_Cut_Tree(int n = 0) : n(n), nodes(n) { FOR(i, n) nodes[i] = Node(i); }

  Node *operator[](int v) { return &nodes[v]; }

  // underlying tree の根
  Node *get_root(Node *c) {
    expose(c);
    c->push();
    while (c->l) {
      c = c->l;
      c->push();
    }
    splay(c);
    return c;
  }

  // underlying tree の根
  int get_root(int c) { return get_root(&nodes[c])->idx; }

  // parent(c)==p となるように link.
  void link(Node *c, Node *p) {
    evert(c);
    expose(p);
    p->push();
    // no edge -> heavy edge
    assert(!(c->p));
    assert(!(p->r));
    c->p = p;
    p->r = c;
    p->update();
  }

  // parent(c)==p となるように link.
  void link(int c, int p) { return link(&nodes[c], &nodes[p]); }

  void cut(Node *a, Node *b) {
    evert(a);
    expose(b);
    assert(!b->p);
    assert((b->l) == a);
    // heavy edge -> no edge
    b->l->p = nullptr;
    b->l = nullptr;
    b->update();
  }

  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]); }

  // c を underlying tree の根とする.
  // c は splay tree の根にもなる.
  // c は push 済になる
  void evert(Node *c) {
    expose(c);
    c->reverse();
    c->push();
  }

  // c を underlying tree の根とする.
  // c は splay tree の根にもなる.
  void evert(int c) { evert(&nodes[c]); }

  Node *lca(Node *u, Node *v) {
    assert(get_root(u) == get_root(v));
    expose(u);
    return expose(v);
  }

  int lca(int u, int v) { return lca(&nodes[u], &nodes[v])->idx; }

  // 辺の個数
  int dist(int u, int v) {
    evert(u), expose(v);
    return ((*this)[v]->size) - 1;
  }

  Node *jump(Node *u, Node *v, int k) {
    evert(v);
    expose(u);
    assert(0 <= k && k < (u->size));
    while (1) {
      u->push();
      int rs = (u->r ? u->r->size : 0);
      if (k < rs) {
        u = u->r;
        continue;
      }
      if (k == rs) { break; }
      k -= rs + 1;
      u = u->l;
    }
    splay(u);
    return u;
  }

  int jump(int u, int v, int k) {
    auto c = jump((*this)[u], (*this)[v], k);
    return c->idx;
  }

  // [root, c] がひとつの splay tree になるように変更する.
  // c が右端で splay tree の根という状態になる.
  // path query はこの状態で c の data を見る.
  // c は push 済になる
  virtual Node *expose(Node *c) {
    Node *now = c;
    Node *rp = nullptr; // 今まで作ったパス
    while (now) {
      splay(now);
      // heavy -> light, light -> heavy.
      if (now->r) { now->add_light(now->r); }
      if (rp) { now->erase_light(rp); }
      now->r = rp;
      now->update();
      rp = now;
      now = now->p;
    }
    splay(c);
    return rp;
  }

  // [root, c] がひとつの splay tree になるように変更する.
  // c が右端で splay tree の根という状態になる.
  // path query はこの状態で c の data を見る.
  int expose(int c) {
    Node *x = expose(&nodes[c]);
    if (!x) return -1;
    return x->idx;
  }

  Node *get_parent(Node *x) {
    expose(x);
    x->push();
    if (!x->l) return nullptr;
    x = x->l, x->push();
    while (x->r) x = x->r, x->push();
    return x;
  }

  int get_parent(int x) {
    Node *p = get_parent((*this)[x]);
    return (p ? p->idx : -1);
  }

  void set(Node *c, typename Node::VX x) {
    evert(c);
    c->set(x);
  }

  void set(int c, typename Node::VX x) { set((*this)[c], x); }

  typename Node::X prod_path(int a, int b) {
    evert(a), expose(b);
    return (*this)[b]->x;
  }

  // subtree 用の node を使う
  typename Node::X prod_subtree(int v, int root) {
    static_assert(Node::NODE_FOR_SUBTREE);
    if (v == root) {
      evert(root);
      return (*this)[root]->x;
    }
    root = jump(v, root, 1);
    cut(v, root);
    typename Node::X res = (*this)[v]->x;
    link(v, root);
    return res;
  }

  vc<int> collect_heavy_path(int v) {
    np c = (*this)[v];
    while (!is_root(c)) c = c->p;
    vc<int> res;
    auto dfs = [&](auto &dfs, np c, bool rev) -> void {
      if (!rev) {
        if (c->l) dfs(dfs, c->l, rev ^ c->rev);
        res.eb(c->idx);
        if (c->r) dfs(dfs, c->r, rev ^ c->rev);
      } else {
        if (c->r) dfs(dfs, c->r, rev ^ c->rev);
        res.eb(c->idx);
        if (c->l) dfs(dfs, c->l, rev ^ c->rev);
      }
    };
    dfs(dfs, c, false);
    return res;
  }

  void debug() {
    print("p, l, r, rev");
    auto f = [&](np c) -> int { return (c ? c->idx : -1); };
    FOR(i, len(nodes)) { print(i, ",", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r), (*this)[i]->rev); }
    FOR(i, len(nodes)) {
      np c = (*this)[i];
      if (c->l) assert(c->l->p == c);
      if (c->r) assert(c->r->p == c);
    }
  }

private:
  // splay tree 内で完結する操作. 特に heavy, light 構造は変わらない.
  // light pointer は rotate 内でケア
  // c は push 済になる
  void splay(Node *c) {
    c->push();
    while (!is_root(c)) {
      Node *p = c->p;
      Node *pp = (p ? p->p : nullptr);
      if (state(p) == 0) {
        p->push(), c->push();
        rotate(c);
      }
      elif (state(c) == state(p)) {
        pp->push(), p->push(), c->push();
        rotate(p);
        rotate(c);
      }
      else {
        pp->push(), p->push(), c->push();
        rotate(c);
        rotate(c);
      }
    }
  }

  // パスを表す splay tree の根になっているかどうか
  // underlying tree ではない
  bool is_root(Node *c) { return state(c) == 0; }

  // splay tree 内で完結する操作. 特に heavy, light 構造は変わらない.
  // light edge のポインタは変更されうる
  void rotate(Node *n) {
    // n を根に近づける
    Node *pp, *p, *c;
    p = n->p;
    pp = p->p;
    if (p->l == n) {
      c = n->r;
      n->r = p;
      p->l = c;
    } else {
      c = n->l;
      n->l = p;
      p->r = c;
    }
    p->update(), n->update();

    if (pp) {
      if (pp->l == p) pp->l = n;
      elif (pp->r == p) pp->r = n;
      else {
        // light edge pointer が (pp-p) から (pp-n) に変わる
        pp->change_light(p, n);
      }
    }
    n->p = pp;
    p->p = n;
    if (c) c->p = p;
  }

  inline int state(Node *n) {
    if (!n->p) return 0;
    if (n->p->l == n) return 1;
    if (n->p->r == n) return -1;
    return 0;
  }
};
