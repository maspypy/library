#include "graph/ds/link_cut.hpp"

template <typename Node, int NODES>
struct LinkCutTree_SubTree : LinkCutTree_base<Node, NODES> {
  using Base = LinkCutTree_base<Node, NODES>;
  using MonoX = typename Node::MonoX;
  using X = typename Node::X;
  using MonoA = typename Node::MonoA;
  using A = typename Node::A;

  LinkCutTree_SubTree(int n = 0) : Base(n) {}

  LinkCutTree_SubTree(vc<X> dat) : Base(len(dat)) {
    FOR(i, len(dat))(*this)[i]->set(dat[i]);
  }

  void set(int i, X x) {
    Base::expose(i);
    (*this)[i]->set(x);
  }

  void add(int i, X x) {
    Base::expose(i);
    (*this)[i]->add(x);
  }

  X sum(int v) {
    int p = Base::get_parent(v);
    if (p == -1) { return (*this)[v]->sum(); }
    Base::cut(v, p);
    X x = (*this)[v]->sum();
    Base::link(v, p);
    return x;
  }

  void link(Node *c, Node *p) override {
    Base::evert(p);
    expose(c);
    c->p = p;
    c->cancel = p->added;
    p->r = c;
    p->update();
  }

  void link(int c, int p) override { return link((*this)[c], (*this)[p]); }

  // c と根までが繋がれている状態に変更して、根を return する
  Node *expose(Node *c) override {
    Node *now = c;
    Node *rp = nullptr; // 今まで作ったパス
    while (now) {
      Base::splay(now);
      if (now->r) {
        now->r->push();
        if (now->r) now->add_r(true);
      }
      now->r = rp;
      if (now->r) {
        now->r->push();
        now->add_r(false);
      }
      now->update();
      rp = now;
      now = now->p;
    }
    Base::splay(c);
    return rp;
  }

  int expose(int c) {
    Node *x = expose((*this)[c]);
    if (!x) return -1;
    return x->idx;
  }

  void rotate(Node *n) override {
    // n を根に近づける
    Node *pp, *p, *c;
    p = n->p;
    pp = p->p;

    if (p->l == n) {
      c = n->r;
      if (c) c->push();
      n->r = p;
      p->l = c;
    } else {
      c = n->l;
      if (c) c->push();
      n->l = p;
      p->r = c;
    }

    if (pp && pp->l == p) { pp->l = n; }
    if (pp && pp->r == p) { pp->r = n; }
    n->p = pp;
    p->p = n;
    n->cancel = (n->p ? n->p->added : MonoA::unit());
    p->cancel = (p->p ? p->p->added : MonoA::unit());
  }
};

template <typename AbelGroup>
struct LCT_Subtree_Sum_Node {
  using X = typename AbelGroup::value_type;
  LCT_Subtree_Sum_Node *l, *r, *p;
  X x, heavy_sum, light_sum;
  int idx;
  bool rev;
  LCT_Subtree_Sum_Node(int i = 0, X x = AbelGroup::unit())
      : l(nullptr),
        r(nullptr),
        p(nullptr),
        x(x),
        heavy_sum(x),
        light_sum(AbelGroup::unit()),
        idx(i) {}

  void set(X y) {
    x = y;
    update();
  }

  void add(X y) {
    x = AbelGroup::op(x, y);
    update();
  }

  X sum() { return AbelGroup::op(heavy_sum, light_sum); }

  void update() {
    heavy_sum = x;
    if (l) heavy_sum = AbelGroup::op(heavy_sum, l->sum());
    if (r) heavy_sum = AbelGroup::op(heavy_sum, r->sum());
  }

  void add_r(bool add) {
    if (!r) return;
    X x = r->sum();
    if (!add) x = AbelGroup::inverse(x);
    light_sum = AbelGroup::op(light_sum, x);
  }

  void push() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = 0;
    }
  }

  void reverse() {
    rev ^= 1;
    swap(l, r);
  }

  void debug() { print(idx, "x", x, "heavy", heavy_sum, "light", light_sum); }
};