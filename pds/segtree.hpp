#pragma once
template <class Monoid, int NODES = 20000000>
struct PersistentSegTree {
  using X = typename Monoid::value_type;
  using value_type = X;

  struct Node {
    X x;
    Node *lch, *rch;
    Node() {}
    Node(const X &x) : x(x), lch(nullptr), rch(nullptr) {}
  };

  Node *pool;
  int pid;
  ll n;
  Node *nil;
  vc<Node *> roots;

  PersistentSegTree(int n) : pid(0), n(n), nil(nullptr) {
    pool = new Node[NODES];
    nil = new_node(Monoid::unit());
    nil->lch = nil->rch = nil;
    roots.reserve(1 << 18);
    roots.push_back(nil);
  }

private:
  Node *new_node(const X &x) {
    pool[pid].x = x;
    pool[pid].lch = pool[pid].rch = nil;
    return &(pool[pid++]);
  }

  Node *merge(Node *l, Node *r) {
    pool[pid].x = Monoid::op(l->x, r->x);
    pool[pid].lch = l;
    pool[pid].rch = r;
    return &(pool[pid++]);
  }

  Node *set(ll idx, const X &x, Node *n, ll l, ll r) {
    if (l + 1 == r) return new_node(x);
    ll m = (l + r) / 2;
    if (idx < m) return merge(set(idx, x, n->lch, l, m), n->rch);
    return merge(n->lch, set(idx, x, n->rch, m, r));
  }

  X prod(ll a, ll b, Node *n, ll l, ll r) {
    if (n == nil) return Monoid::unit();
    if (r <= a || b <= l) return Monoid::unit();
    if (a <= l && r <= b) return n->x;
    ll m = (l + r) / 2;
    return Monoid::op(prod(a, b, n->lch, l, m), prod(a, b, n->rch, m, r));
  }

public:
  int time() { return len(roots) - 1; }

  int set(int t, ll idx, const X &x) {
    Node *root = set(idx, x, roots[t], 0, n);
    roots.eb(root);
    return time();
  }

  X prod(int time, ll l, ll r) { return prod(l, r, roots[time], 0, n); }
};