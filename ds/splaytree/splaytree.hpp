#pragma once
// Node 型を別に定義して使う
template <typename Node, int NODES = 1'000'000>
struct SplayTree {
  Node *pool;
  int pid;
  using np = Node *;
  using X = typename Node::value_type;
  using A = typename Node::operator_type;

  SplayTree() : pid(0) { pool = new Node[NODES]; }

  void reset() { pid = 0; }

  np new_node(const X &x) {
    np n = &(pool[pid++]);
    Node::new_node(n, x);
    return n;
  }

  np new_node(const vc<X> &dat) {
    auto dfs = [&](auto &dfs, int l, int r) -> np {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      int m = (l + r) / 2;
      np l_root = dfs(dfs, l, m);
      np r_root = dfs(dfs, m + 1, r);
      np root = new_node(dat[m]);
      root->l = l_root, root->r = r_root;
      if (l_root) l_root->p = root;
      if (r_root) r_root->p = root;
      root->update();
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  u32 get_size(np root) { return (root ? root->size : 0); }

  np merge(np l_root, np r_root) {
    if (!l_root) return r_root;
    if (!r_root) return l_root;
    splay_kth(r_root, 0); // splay したので prop 済
    r_root->l = l_root;
    l_root->p = r_root;
    r_root->update();
    return r_root;
  }
  np merge3(np a, np b, np c) { return merge(merge(a, b), c); }
  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a, b), c), d); }

  pair<np, np> split(np root, u32 k) {
    if (k == (root->size)) return {root, nullptr};
    if (k == 0) return {nullptr, root};
    splay_kth(root, k - 1);
    np right = root->r;
    root->r = nullptr, right->p = nullptr;
    root->update();
    return {root, right};
  }
  tuple<np, np, np> split3(np root, u32 l, u32 r) {
    np nm, nr;
    tie(root, nr) = split(root, r);
    tie(root, nm) = split(root, l);
    return {root, nm, nr};
  }
  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {
    np d;
    tie(root, d) = split(root, k);
    auto [a, b, c] = split3(root, i, j);
    return {a, b, c, d};
  }

  // 部分木が区間 [l,r) に対応するようなノードを作って返す
  // そのノードが root になるわけではないので、
  // このノードを参照した後にすぐに splay して根に持ち上げること
  void goto_between(np &root, u32 l, u32 r) {
    if (l == 0 && r == root->size) return;
    if (l == 0) {
      splay_kth(root, r);
      root = root->l;
      return;
    }
    if (r == root->size) {
      splay_kth(root, l - 1);
      root = root->r;
      return;
    }
    splay_kth(root, r);
    np rp = root;
    root = rp->l;
    root->p = nullptr;
    splay_kth(root, l - 1);
    root->p = rp;
    rp->l = root;
    rp->update();
    root = root->r;
  }

  vc<X> get_all(const np &root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, np root) -> void {
      if (!root) return;
      root->prop();
      dfs(dfs, root->l);
      res.eb(root->get());
      dfs(dfs, root->r);
    };
    dfs(dfs, root);
    return res;
  }

  X get(np &root, u32 k) {
    splay_kth(root, k);
    return root->get();
  }

  void set(np &root, u32 k, const X &x) {
    splay_kth(root, k);
    root->set(x);
  }

  void multiply(np &root, u32 k, const X &x) {
    splay_kth(root, k);
    root->multiply(x);
  }

  X prod(np &root, u32 l, u32 r) {
    assert(0 <= l && l < r && r <= root->size);
    goto_between(root, l, r);
    X res = root->prod;
    splay(root);
    return res;
  }

  void apply(np &root, u32 l, u32 r, const A &a) {
    assert(0 <= l && l < r && r <= root->size);
    goto_between(root, l, r);
    root->apply(a);
    splay(root);
  }
  void apply(np &root, const A &a) {
    if (!root) return;
    root->apply(a);
  }

  void reverse(np &root, u32 l, u32 r) {
    assert(0 <= l && l < r && r <= root->size);
    goto_between(root, l, r);
    root->reverse();
    splay(root);
  }
  void reverse(np root) {
    if (!root) return;
    root->reverse();
  }

  void rotate(Node *n) {
    // n を根に近づける。prop, update は rotate の外で行う。
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
    if (pp && pp->l == p) pp->l = n;
    if (pp && pp->r == p) pp->r = n;
    n->p = pp;
    p->p = n;
    if (c) c->p = p;
  }

  void splay(Node *me) {
    // これを呼ぶ時点で、me の祖先（me を除く）は既に prop 済であることを仮定
    // 特に、splay 終了時点で me は upd / prop 済である
    me->prop();
    while (me->p) {
      np p = me->p;
      np pp = p->p;
      if (!pp) {
        rotate(me);
        p->update();
        break;
      }
      bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);
      if (same) rotate(p), rotate(me);
      if (!same) rotate(me), rotate(me);
      pp->update(), p->update();
    }
    // me の update は最後だけでよい
    me->update();
  }

  void splay_kth(np &root, u32 k) {
    assert(0 <= k && k < (root->size));
    while (1) {
      u32 sl = (root->l ? root->l->size : 0);
      if (k == sl) break;
      root->prop();
      if (k < sl)
        root = root->l;
      else {
        k -= sl + 1;
        root = root->r;
      }
    }
    splay(root);
  }

  // check(x), 左側のノード全体が check を満たすように切る
  template <typename F>
  pair<np, np> split_max_right(np root, F check) {
    if (!root) return {nullptr, nullptr};
    np c = find_max_right(root, check);
    if (!c) {
      splay(root);
      return {nullptr, root};
    }
    splay(c);
    np right = c->r;
    if (!right) return {c, nullptr};
    right->p = nullptr;
    c->r = nullptr;
    c->update();
    return {c, right};
  }

  // 左側のノード全体の prod が check を満たすように切る
  template <typename F>
  pair<np, np> split_max_right_prod(np root, F check) {
    if (!root) return {nullptr, nullptr};
    np c = find_max_right_prod(root, check);
    if (!c) {
      splay(root);
      return {nullptr, root};
    }
    splay(c);
    np right = c->r;
    if (!right) return {c, nullptr};
    right->p = nullptr;
    c->r = nullptr;
    c->update();
    return {c, right};
  }

  template <typename F>
  np find_max_right(np root, const F &check) {
    // 最後に見つけた ok の点、最後に探索した点
    np last_ok = nullptr, last = nullptr;
    while (root) {
      last = root;
      root->prop();
      if (check(root->x)) {
        last_ok = root;
        root = root->r;
      } else {
        root = root->l;
      }
    }
    splay(last);
    return last_ok;
  }

  template <typename F>
  np find_max_right_prod(np root, const F &check) {
    using Mono = typename Node::Monoid_X;
    X prod = Mono::unit();
    // 最後に見つけた ok の点、最後に探索した点
    np last_ok = nullptr, last = nullptr;
    while (root) {
      last = root;
      root->prop();
      X lprod = prod;
      if (root->l) lprod = Mono::op(lprod, root->l->prod);
      lprod = Mono::op(lprod, root->x);
      if (check(lprod)) {
        prod = lprod;
        last_ok = root;
        root = root->r;
      } else {
        root = root->l;
      }
    }
    splay(last);
    return last_ok;
  }
};
