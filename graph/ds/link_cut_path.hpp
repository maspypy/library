#include "graph/link_cut.hpp"
template <typename Node, int NODES>
struct LinkCutTree_Path_base : public LinkCutTree_base<Node, NODES> {
  using X = typename Node::X;

  LinkCutTree_Path_base(int n) : LinkCutTree_base<Node, NODES>(n) {}

  LinkCutTree_Path_base(vc<X> dat) : LinkCutTree_base<Node, NODES>(len(dat)) {
    FOR(v, len(dat)) {
      Node *c = (*this)[v];
      set(c, dat[v]);
    }
  }

  template <typename F>
  LinkCutTree_Path_base(int n, F f) : LinkCutTree_base<Node, NODES>(n) {
    FOR(v, n) {
      X x = f(v);
      Node *c = (*this)[v];
      set(c, x);
    }
  }

  void set(Node *c, X x) {
    this->evert(c);
    c->x = x;
    c->update();
  }

  void set(int c, X x) { set((*this)[c], x); }

  void multiply(Node *c, X x) { set(c, Node::Mono::op(c->x, x)); }

  void multiply(int c, X x) { multiply((*this)[c], x); }

  X prod_path(Node *a, Node *b) {
    this->evert(a);
    this->expose(b);
    return b->prod;
  }

  X prod_path(int a, int b) { return prod_path((*this)[a], (*this)[b]); }
};

template <typename Monoid>
struct LCT_Node_Monoid {
  using Mono = Monoid;
  using X = typename Monoid::value_type;
  LCT_Node_Monoid *l, *r, *p;
  int idx;
  X x, prod, rev_prod;
  bool rev;
  LCT_Node_Monoid(int i = 0)
      : l(nullptr),
        r(nullptr),
        p(nullptr),
        idx(i),
        x(Monoid::unit()),
        prod(Monoid::unit()),
        rev_prod(Monoid::unit()) {}

  void update() {
    prod = rev_prod = x;
    if (l) {
      prod = Monoid::op(l->prod, prod);
      rev_prod = Monoid::op(rev_prod, l->rev_prod);
    }
    if (r) {
      prod = Monoid::op(prod, r->prod);
      rev_prod = Monoid::op(r->rev_prod, rev_prod);
    }
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
    swap(prod, rev_prod);
  }

  void debug() {
    int li = (l ? l->idx : -1);
    int ri = (r ? r->idx : -1);
    int pi = (p ? p->idx : -1);
    print("idx", idx, "l", li, "r", ri, "p", pi, "x", x, "prod", prod,
          "rev_prod", rev_prod);
  }
};

template <typename Monoid>
struct LCT_Node_CommutativeMonoid {
  using Mono = Monoid;
  using X = typename Mono::value_type;
  LCT_Node_CommutativeMonoid *l, *r, *p;
  int idx;
  X x, prod;
  bool rev;
  LCT_Node_CommutativeMonoid(int i = 0)
      : l(nullptr),
        r(nullptr),
        p(nullptr),
        idx(i),
        x(Mono::unit()),
        prod(Mono::unit()) {}

  void update() {
    prod = x;
    if (l) { prod = Mono::op(l->prod, prod); }
    if (r) { prod = Mono::op(prod, r->prod); }
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

  void debug() {
    int li = (l ? l->idx : -1);
    int ri = (r ? r->idx : -1);
    int pi = (p ? p->idx : -1);
    print("idx", idx, "l", li, "r", ri, "p", pi, "x", x, "prod", prod);
  }
};

template <typename Monoid, int NODES>
using LinkCutTree_Path = LinkCutTree_Path_base<LCT_Node_Monoid<Monoid>, NODES>;

template <typename Monoid, int NODES>
using LinkCutTree_Path_Commutative
    = LinkCutTree_Path_base<LCT_Node_CommutativeMonoid<Monoid>, NODES>;
