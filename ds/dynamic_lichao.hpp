// x 座標は long long に限定している。
// 直線の係数 T は double や i128 も可能。
template <typename T, int NODES>
struct Dynamic_LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    Line() : Line(0, numeric_limits<T>::max()) {}
    T operator()(T x) const { return a * x + b; }
  };

  struct Node {
    Line f;
    Node *l, *r;
  };

  Node *pool;
  int pid;
  ll L, R;
  Node *root;

  Dynamic_LiChaoTree(ll L, ll R) : pid(0), L(L), R(R), root(nullptr) {
    pool = new Node[NODES];
  }

  Node *new_node() {
    pool[pid].f = Line();
    return &(pool[pid++]);
  }

  void add_segment(ll xl, ll xr, T a, T b) {
    constexpr T INF = numeric_limits<T>::max();
    if (a != 0) {
      ll xlim = (INF - abs(b)) / abs(a);
      assert(abs(xl) < xlim);
      assert(abs(xr) < xlim);
    }
    assert(L <= xl && xl < xr && xr <= R);
    Line f(a, b);
    if (!root) root = new_node();
    add_segment_rec(root, xl, xr, f, L, R);
  }

  void add_line(T a, T b) { add_segment(L, R, a, b); }

  T query(ll x) {
    assert(L <= x && x < R);
    if (!root) return numeric_limits<T>::max();
    return query_rec(root, x, L, R);
  }

private:
  void add_segment_rec(Node *c, ll xl, ll xr, const Line &f, ll node_l,
                       ll node_r) {
    chmax(xl, node_l);
    chmin(xr, node_r);
    if (xl >= xr) return;
    if (node_l < xl || xr < node_r) {
      ll node_m = (node_l + node_r) / 2;
      if (!c->l) c->l = new_node();
      if (!c->r) c->r = new_node();
      add_segment_rec(c->l, xl, xr, f, node_l, node_m);
      add_segment_rec(c->r, xl, xr, f, node_m, node_r);
      return;
    }
    add_line_rec(c, f, node_l, node_r);
  }

  void add_line_rec(Node *c, const Line &f, ll node_l, ll node_r) {
    T fl = f(node_l), fr = f(node_r - 1);
    Line g = c->f;
    T gl = g(node_l), gr = g(node_r - 1);
    if (fl <= gl && fr <= gr) {
      c->f = f;
      return;
    }
    if (fl >= gl && fr >= gr) { return; }
    ll node_m = (node_l + node_r) / 2;
    T fm = f(node_m), gm = g(node_m);
    if (fm <= gm) {
      c->f = f;
      if (fl < gl) {
        if (!c->r) c->r = new_node();
        add_line_rec(c->r, g, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        add_line_rec(c->l, g, node_l, node_m);
      }
    } else {
      if (gl < fl) {
        if (!c->r) c->r = new_node();
        add_line_rec(c->r, f, node_m, node_r);
      } else {
        if (!c->l) c->l = new_node();
        add_line_rec(c->l, f, node_l, node_m);
      }
    }
  }

  T query_rec(Node *c, ll x, ll node_l, ll node_r) {
    T res = c->f(x);
    ll node_m = (node_l + node_r) / 2;
    if (x < node_m && c->l) chmin(res, query_rec(c->l, x, node_l, node_m));
    if (x >= node_m && c->r) chmin(res, query_rec(c->r, x, node_m, node_r));
    return res;
  }
};